/*
 * fsimx8mp.c
 *
 * (C) Copyright 2021
 * Patrik Jakob, F&S Elektronik Systeme GmbH, jakob@fs-net.de
 * Anatol Derksen, F&S Elektronik Systeme GmbH, derksen@fs-net.de
 * Philipp Gerbach, F&S Elektronik Systeme GmbH, gerbach@fs-net.de
 *
 * Board specific functions for F&S boards based on Freescale i.MX8MP CPU
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <errno.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm-generic/gpio.h>
#include <asm/arch/imx8mp_pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/arch/clock.h>
#include <spl.h>
#include <asm/mach-imx/dma.h>
#include <power/pmic.h>
#include "../../freescale/common/tcpc.h"
#include <usb.h>
#include <dwc3-uboot.h>
#include <mmc.h>
#include "../common/fs_fdt_common.h"	/* fs_fdt_set_val(), ... */
#include "../common/fs_board_common.h"	/* fs_board_*() */
#include "../common/fs_eth_common.h"	/* fs_eth_*() */
#include <imx_thermal.h> /* for temp ranges */

DECLARE_GLOBAL_DATA_PTR;

#define BT_PICOCOREMX8MP 	0

#define FEAT_ETH_A 	(1<<0)	/* 0: no LAN0,  1: has LAN0 */
#define FEAT_ETH_B	(1<<1)	/* 0: no LAN1,  1: has LAN1 */
#define FEAT_DISP_A	(1<<2)	/* 0: MIPI-DSI, 1: LVDS lanes 0-3 */
#define FEAT_DISP_B	(1<<3)	/* 0: HDMI,     1: LVDS lanes 0-4 or (4-7 if DISP_A=1) */
#define FEAT_AUDIO 	(1<<4)	/* 0: no Audio, 1: Analog Audio Codec */
#define FEAT_EXT_RTC	(1<<5)	/* 0: internal RTC, 1: external RTC */

#define FEAT_ETH_MASK 	(FEAT_ETH_A | FEAT_ETH_B)

#define WDOG_PAD_CTRL	(PAD_CTL_DSE6 | PAD_CTL_ODE | PAD_CTL_PUE | PAD_CTL_PE)

#define INSTALL_RAM "ram@43800000"
#if defined(CONFIG_MMC) && defined(CONFIG_USB_STORAGE) && defined(CONFIG_FS_FAT)
#define UPDATE_DEF "mmc,usb"
#define INSTALL_DEF INSTALL_RAM "," UPDATE_DEF
#elif defined(CONFIG_MMC) && defined(CONFIG_FS_FAT)
#define UPDATE_DEF "mmc"
#define INSTALL_DEF INSTALL_RAM "," UPDATE_DEF
#elif defined(CONFIG_USB_STORAGE) && defined(CONFIG_FS_FAT)
#define UPDATE_DEF "usb"
#define INSTALL_DEF INSTALL_RAM "," UPDATE_DEF
#else
#define UPDATE_DEF NULL
#define INSTALL_DEF INSTALL_RAM
#endif

#ifdef CONFIG_ENV_IS_IN_MMC
#define ROOTFS ".rootfs_mmc"
#define KERNEL ".kernel_mmc"
#define FDT ".fdt_mmc"
#define SET_ROOTFS ".set_rootfs_mmc"
#define SELECTOR ".selector_mmc"
#define BOOT_PARTITION ".boot_partition_mmc"
#define ROOTFS_PARTITION ".rootfs_partition_mmc"
#endif

const struct fs_board_info board_info[] = {
	{	/* 0 (BT_PICOCOREMX8MP) */
		.name = "PicoCoreMX8MP",
		.bootdelay = "3",
		.updatecheck = UPDATE_DEF,
		.installcheck = INSTALL_DEF,
		.recovercheck = UPDATE_DEF,
		.console = ".console_serial",
		.login = ".login_serial",
		.mtdparts = ".mtdparts_std",
		.network = ".network_off",
		.init = ".init_init",
		.rootfs = ROOTFS,
		.kernel = KERNEL,
		.fdt = FDT,
#ifdef CONFIG_FS_UPDATE_SUPPORT
		.set_rootfs = SET_ROOTFS,
		.selector = SELECTOR,
		.boot_partition = BOOT_PARTITION,
		.rootfs_partition = ROOTFS_PARTITION
#endif
	},
};

static iomux_v3_cfg_t const wdog_pads[] = {
	MX8MP_PAD_GPIO1_IO02__WDOG1_WDOG_B  | MUX_PAD_CTRL(WDOG_PAD_CTRL),
};

int board_early_init_f(void)
{
	struct wdog_regs *wdog = (struct wdog_regs *)WDOG1_BASE_ADDR;

	imx_iomux_v3_setup_multiple_pads(wdog_pads, ARRAY_SIZE(wdog_pads));

	set_wdog_reset(wdog);

	return 0;
}

#ifdef CONFIG_OF_BOARD_SETUP
#define FDT_LDB_LVDS0	"ldb/lvds-channel@0"
#define FDT_LDB_LVDS1	"ldb/lvds-channel@1"
#define FDT_TEMP_ALERT	"/thermal-zones/cpu-thermal/trips/trip0"
#define FDT_TEMP_CRIT	"/thermal-zones/cpu-thermal/trips/trip1"
/* Do any additional board-specific modifications on Linux device tree */
int ft_board_setup(void *fdt, bd_t *bd)
{
	int offs;
	unsigned int features = fs_board_get_features();
	int minc, maxc;
	int id = 0;
	uint32_t temp_range;

	/* get CPU temp grade from the fuses */
	temp_range = get_cpu_temp_grade(&minc, &maxc);

	if(temp_range == TEMP_COMMERCIAL){
		/* no wlan abailable */
		fs_fdt_enable(fdt, "wlan-reset", 0);
		/* no eeprom available */
		fs_fdt_enable(fdt, "eeprom", 0);
		/* no MIPI_CSI2 availble */
		fs_fdt_enable(fdt, "mipi_csi_1", 0);
		/* disable image sensing interface for MIPI_CSI2 */
		fs_fdt_enable(fdt, "isi_1", 0);
		/* no VPU */
		fs_fdt_enable(fdt, "vpu_g1", 0);
		fs_fdt_enable(fdt, "vpu_g2", 0);
		fs_fdt_enable(fdt, "vpu_vc8000e", 0);
		/* no ISP */
		fs_fdt_enable(fdt, "isp_0", 0);
		fs_fdt_enable(fdt, "isp_1", 0);
		/* no NPU */
		fs_fdt_enable(fdt, "vipsi", 0);
	}

	/* Disable fec node if it is not availale */
	if (!(features & FEAT_ETH_A)) {
		fs_fdt_enable(fdt, "ethernet0", 0);
	}

	/* Disable eqos node if it is not availale */
	if (!(features & FEAT_ETH_B)) {
		fs_fdt_enable(fdt, "ethernet1", 0);
	}

	/* Display A/B options */
	/* -------------------------------------
	 *                 |    0      |   1   |
	 * -------------------------------------
	 * DISP_A (DSI_A): | MIPI_DSI1 | LVDS0 |
	 * -------------------------------------
	 * DISP_B (DSI_B): |   HDMI    | LVDS1 |
	 * -------------------------------------
	 * */

	if (!(features & FEAT_DISP_A)) {
		/* enable mipi_dsi1 */
		fs_fdt_enable(fdt, "mipi_dsi", 1);
		fs_fdt_enable(fdt, "lcdif1", 1);
	}else{
		/* disable mipi_dsi1 */
		fs_fdt_enable(fdt, "mipi_dsi", 0);

		/* enable LVDS0 */
		fs_fdt_enable(fdt, "lcdif2", 1);
		fs_fdt_enable(fdt, "ldb_phy", 1);
		fs_fdt_enable(fdt, "ldb", 1);
		/* TODO: use default LVDS1.
		 * 8 lanes mode is currently not working
		 * */
		//fs_fdt_enable(fdt, FDT_LDB_LVDS0, 0);
	}

	if (!(features & FEAT_DISP_B)) {
		/* enable HDMI */
		fs_fdt_enable(fdt, "irqsteer_hdmi", 1);
		fs_fdt_enable(fdt, "hdmimix_clk", 1);
		fs_fdt_enable(fdt, "hdmimix_reset", 1);
		fs_fdt_enable(fdt, "hdmi_pavi", 1);
		fs_fdt_enable(fdt, "hdmi", 1);
		fs_fdt_enable(fdt, "hdmiphy", 1);
		fs_fdt_enable(fdt, "lcdif3", 1);
		/* disable LVDS1 */
		if(!(features & FEAT_DISP_A)) {
			fs_fdt_enable(fdt, "ldb_phy", 0);
			fs_fdt_enable(fdt, "ldb", 0);
		}
	}else{
		/* disble HDMI */
		fs_fdt_enable(fdt, "irqsteer_hdmi", 0);
		fs_fdt_enable(fdt, "hdmimix_clk", 0);
		fs_fdt_enable(fdt, "hdmimix_reset", 0);
		fs_fdt_enable(fdt, "hdmi_pavi", 0);
		fs_fdt_enable(fdt, "hdmi", 0);
		fs_fdt_enable(fdt, "hdmiphy", 0);
		fs_fdt_enable(fdt, "lcdif3", 0);
		/* enable LVDS1 */
		fs_fdt_enable(fdt, "lcdif2", 1);
		fs_fdt_enable(fdt, "ldb_phy", 1);
		fs_fdt_enable(fdt, "ldb", 1);
		fs_fdt_enable(fdt, FDT_LDB_LVDS1, 1);
	}

	/* Disable SGTL5000 if it is not available */
	if (!(features & FEAT_AUDIO)) {
		/* disable all sgtl5000 regulators */
		fs_fdt_enable(fdt, "/regulators/reg_sgtl5000_vdda", 0);
		fs_fdt_enable(fdt, "/regulators/reg_sgtl5000_vddio", 0);
		fs_fdt_enable(fdt, "/regulators/reg_sgtl5000_vddd", 0);
		/* disable i2c sgtl5000 */
		fs_fdt_enable(fdt, "sgtl5000", 0);
		/* disable sgtl5000 platform driver */
		fs_fdt_enable(fdt, "sound-sgtl5000", 0);
	}

	/* The following stuff is only set in Linux device tree */
	/* Disable RTC85263 if it is not available */
	if (!(features & FEAT_EXT_RTC)) {
		fs_fdt_enable(fdt, "rtcpcf85263", 0);
		/* enable internal RTC */
		fs_fdt_enable(fdt, "snvs_rtc", 1);
	}else {
		/* enable external RTC */
		fs_fdt_enable(fdt, "rtcpcf85263", 1);
		/* disable internal RTC */
		fs_fdt_enable(fdt, "snvs_rtc", 0);
	}

	/* Set bdinfo entries */
	offs = fs_fdt_path_offset(fdt, "/bdinfo");
	if (offs >= 0) {
		/* Set common bdinfo entries */
		fs_fdt_set_bdinfo(fdt, offs);

		/* MAC addresses */
		if (features & FEAT_ETH_A)
			fs_fdt_set_macaddr(fdt, offs, id++);
		if (features & FEAT_ETH_B)
			fs_fdt_set_macaddr(fdt, offs, id++);
	}

	/* Sanity check for get_cpu_temp_grade() */
	if ((minc > -500) && maxc < 500) {
		fdt32_t tmp_val[1];

		tmp_val[0]=cpu_to_fdt32((maxc-10)*1000);
		offs = fs_fdt_path_offset(fdt, FDT_TEMP_ALERT);
		if (fdt_get_property(fdt, offs, "no-uboot-override", NULL) == NULL) {
			fs_fdt_set_val(fdt, offs, "temperature",tmp_val , sizeof(tmp_val), 1);
		}
		tmp_val[0]=cpu_to_fdt32(maxc*1000);
		offs = fs_fdt_path_offset(fdt, FDT_TEMP_CRIT);
		if (fdt_get_property(fdt, offs, "no-uboot-override", NULL) == NULL) {
			fs_fdt_set_val(fdt, offs, "temperature", tmp_val, sizeof(tmp_val), 1);
		}
	} else {
		printf("## Wrong cpu temp grade values read! Keeping defaults from device tree\n");
	}

	return 0;
}
#endif

void fs_ethaddr_init(void)
{
	unsigned int features2 = fs_board_get_nboot_args()->chFeatures2;
	int eth_id = 0;

	/* Set MAC addresses as environment variables */
	switch (fs_board_get_type())
	{
	case BT_PICOCOREMX8MP:
		if (features2 & FEAT_ETH_A) {
			fs_eth_set_ethaddr(eth_id++);
		}
		if (features2 & FEAT_ETH_B) {
			fs_eth_set_ethaddr(eth_id++);
		}
		break;
	default:
		break;
	}
}

/* Check board type */
int checkboard(void)
{
	unsigned int board_type = fs_board_get_type();
	unsigned int board_rev = fs_board_get_rev();
	unsigned int features = fs_board_get_features();
	int minc, maxc;
	uint32_t temp_range = get_cpu_temp_grade(&minc, &maxc);

	printf ("Board: %s Rev %u.%02u (", board_info[board_type].name,
		board_rev / 100, board_rev % 100);
	if ((features & FEAT_ETH_MASK) == FEAT_ETH_MASK)
		puts ("2x ");
	if (features & FEAT_ETH_MASK)
		puts ("LAN, ");
	if (temp_range != TEMP_COMMERCIAL)
		puts ("WLAN, ");

	puts ("eMMC, ");
	printf ("%dx DRAM)\n", fs_board_get_nboot_args()->dwNumDram);

	return 0;
}

#ifdef CONFIG_FEC_MXC
static int setup_fec(void)
{
	struct iomuxc_gpr_base_regs *gpr =
		(struct iomuxc_gpr_base_regs *)IOMUXC_GPR_BASE_ADDR;

	/* Enable RGMII TX clk output */
	setbits_le32(&gpr->gpr[1], BIT(22));

	return 0;
}
#endif

#ifdef CONFIG_DWC_ETH_QOS
static int setup_eqos(void)
{
	struct iomuxc_gpr_base_regs *gpr =
		(struct iomuxc_gpr_base_regs *)IOMUXC_GPR_BASE_ADDR;

	/* set INTF as RGMII, enable RGMII TXC clock */
	clrsetbits_le32(&gpr->gpr[1],
			IOMUXC_GPR_GPR1_GPR_ENET_QOS_INTF_SEL_MASK, BIT(16));
	setbits_le32(&gpr->gpr[1], BIT(19) | BIT(21));

	return set_clk_eqos(ENET_125MHZ);
}
#endif

#if defined(CONFIG_FEC_MXC) || defined(CONFIG_DWC_ETH_QOS)
int board_phy_config(struct phy_device *phydev)
{
	if (phydev->drv->config)
		phydev->drv->config(phydev);
	return 0;
}
#endif

#ifdef CONFIG_USB_TCPC
struct tcpc_port port1;

static int setup_pd_switch(uint8_t i2c_bus, uint8_t addr)
{
	struct udevice *bus;
	struct udevice *i2c_dev = NULL;
	int ret;
	uint8_t valb;

	ret = uclass_get_device_by_seq(UCLASS_I2C, i2c_bus, &bus);
	if (ret) {
		printf("%s: Can't find bus\n", __func__);
		return -EINVAL;
	}

	ret = dm_i2c_probe(bus, addr, 0, &i2c_dev);
	if (ret) {
		printf("%s: Can't find device id=0x%x\n",
			__func__, addr);
		return -ENODEV;
	}

	ret = dm_i2c_read(i2c_dev, 0xB, &valb, 1);
	if (ret) {
		printf("%s dm_i2c_read failed, err %d\n", __func__, ret);
		return -EIO;
	}
	valb |= 0x4; /* Set DB_EXIT to exit dead battery mode */
	ret = dm_i2c_write(i2c_dev, 0xB, (const uint8_t *)&valb, 1);
	if (ret) {
		printf("%s dm_i2c_write failed, err %d\n", __func__, ret);
		return -EIO;
	}

	/* Set OVP threshold to 23V */
	valb = 0x6;
	ret = dm_i2c_write(i2c_dev, 0x8, (const uint8_t *)&valb, 1);
	if (ret) {
		printf("%s dm_i2c_write failed, err %d\n", __func__, ret);
		return -EIO;
	}

	return 0;
}

int pd_switch_snk_enable(struct tcpc_port *port)
{
	if (port == &port1) {
		return setup_pd_switch(port->cfg.i2c_bus, port->cfg.addr);
	} else
		return -EINVAL;
}

struct tcpc_port_config port1_config = {
	.i2c_bus = 2, /*i2c3*/
	.addr = 0x52,
	.port_type = TYPEC_PORT_UFP,
	.max_snk_mv = 20000,
	.max_snk_ma = 3000,
	.max_snk_mw = 45000,
	.op_snk_mv = 15000,
	.switch_setup_func = &pd_switch_snk_enable,
	.disable_pd = true,
};

#define USB_TYPEC_SEL IMX_GPIO_NR(1, 9)
#define USB_TYPEC_EN IMX_GPIO_NR(1, 5)

static iomux_v3_cfg_t ss_mux_gpio[] = {
	MX8MP_PAD_GPIO1_IO09__GPIO1_IO09 | MUX_PAD_CTRL(NO_PAD_CTRL),
	MX8MP_PAD_GPIO1_IO05__GPIO1_IO05 | MUX_PAD_CTRL(NO_PAD_CTRL),
};

void ss_mux_select(enum typec_cc_polarity pol)
{
	if (pol == TYPEC_POLARITY_CC1)
		gpio_direction_output(USB_TYPEC_SEL, 0);
	else
		gpio_direction_output(USB_TYPEC_SEL, 1);
}

static int setup_typec(void)
{
	int ret;

	imx_iomux_v3_setup_multiple_pads(ss_mux_gpio, ARRAY_SIZE(ss_mux_gpio));
	gpio_request(USB_TYPEC_SEL, "typec_sel");
	gpio_request(USB_TYPEC_EN, "typec_en");
	gpio_direction_output(USB_TYPEC_EN, 0);

	ret = tcpc_init(&port1, port1_config, &ss_mux_select);
	if (ret) {
		printf("%s: tcpc port init failed, err=%d\n",
		       __func__, ret);
	} else {
		return ret;
	}

	return ret;
}
#endif

#ifdef CONFIG_USB_DWC3

#define USB_PHY_CTRL0			0xF0040
#define USB_PHY_CTRL0_REF_SSP_EN	BIT(2)

#define USB_PHY_CTRL1			0xF0044
#define USB_PHY_CTRL1_RESET		BIT(0)
#define USB_PHY_CTRL1_COMMONONN		BIT(1)
#define USB_PHY_CTRL1_ATERESET		BIT(3)
#define USB_PHY_CTRL1_VDATSRCENB0	BIT(19)
#define USB_PHY_CTRL1_VDATDETENB0	BIT(20)

#define USB_PHY_CTRL2			0xF0048
#define USB_PHY_CTRL2_TXENABLEN0	BIT(8)

#define USB_PHY_CTRL6			0xF0058

#define HSIO_GPR_BASE                               (0x32F10000U)
#define HSIO_GPR_REG_0                              (HSIO_GPR_BASE)
#define HSIO_GPR_REG_0_USB_CLOCK_MODULE_EN_SHIFT    (1)
#define HSIO_GPR_REG_0_USB_CLOCK_MODULE_EN          (0x1U << HSIO_GPR_REG_0_USB_CLOCK_MODULE_EN_SHIFT)


static struct dwc3_device dwc3_device_data = {
#ifdef CONFIG_SPL_BUILD
	.maximum_speed = USB_SPEED_HIGH,
#else
	.maximum_speed = USB_SPEED_SUPER,
#endif
	.base = USB2_BASE_ADDR,
	.dr_mode = USB_DR_MODE_PERIPHERAL,
	.index = 1,
	.power_down_scale = 2,
};

int usb_gadget_handle_interrupts(int index)
{
	dwc3_uboot_handle_interrupt(index);
	return 0;
}

static void dwc3_nxp_usb_phy_init(struct dwc3_device *dwc3)
{
	u32 RegData;

	/* enable usb clock via hsio gpr */
	RegData = readl(HSIO_GPR_REG_0);
	RegData |= HSIO_GPR_REG_0_USB_CLOCK_MODULE_EN;
	writel(RegData, HSIO_GPR_REG_0);

	/* USB3.0 PHY signal fsel for 100M ref */
	RegData = readl(dwc3->base + USB_PHY_CTRL0);
	RegData = (RegData & 0xfffff81f) | (0x2a<<5);
	writel(RegData, dwc3->base + USB_PHY_CTRL0);

	RegData = readl(dwc3->base + USB_PHY_CTRL6);
	RegData &=~0x1;
	writel(RegData, dwc3->base + USB_PHY_CTRL6);

	RegData = readl(dwc3->base + USB_PHY_CTRL1);
	RegData &= ~(USB_PHY_CTRL1_VDATSRCENB0 | USB_PHY_CTRL1_VDATDETENB0 |
			USB_PHY_CTRL1_COMMONONN);
	RegData |= USB_PHY_CTRL1_RESET | USB_PHY_CTRL1_ATERESET;
	writel(RegData, dwc3->base + USB_PHY_CTRL1);

	RegData = readl(dwc3->base + USB_PHY_CTRL0);
	RegData |= USB_PHY_CTRL0_REF_SSP_EN;
	writel(RegData, dwc3->base + USB_PHY_CTRL0);

	RegData = readl(dwc3->base + USB_PHY_CTRL2);
	RegData |= USB_PHY_CTRL2_TXENABLEN0;
	writel(RegData, dwc3->base + USB_PHY_CTRL2);

	RegData = readl(dwc3->base + USB_PHY_CTRL1);
	RegData &= ~(USB_PHY_CTRL1_RESET | USB_PHY_CTRL1_ATERESET);
	writel(RegData, dwc3->base + USB_PHY_CTRL1);
}
#endif

#if defined(CONFIG_USB_DWC3) || defined(CONFIG_USB_XHCI_IMX8M)
#define USB1_PWR_EN IMX_GPIO_NR(1, 12)
//#define USB2_PWR_EN IMX_GPIO_NR(1, 14)
int board_usb_init(int index, enum usb_init_type init)
{
	int ret = 0;

	debug("USB%d: %s init.\n", index, (init)?"otg":"host");

	if (index == 0 && init == USB_INIT_DEVICE)
		/* usb host only */
		return 0;

	imx8m_usb_power(index, true);

	if (index == 1 && init == USB_INIT_DEVICE) {
#ifdef CONFIG_USB_TCPC
		ret = tcpc_setup_ufp_mode(&port1);
		if (ret)
			return ret;
#endif
		dwc3_nxp_usb_phy_init(&dwc3_device_data);
		return dwc3_uboot_init(&dwc3_device_data);
	} else if (index == 1 && init == USB_INIT_HOST) {
#ifdef CONFIG_USB_TCPC
		ret = tcpc_setup_dfp_mode(&port1);
#endif
		return ret;
	} else if (index == 0 && init == USB_INIT_HOST) {
		/* Enable host power */
		gpio_request(USB1_PWR_EN, "usb1_pwr");
		gpio_direction_output(USB1_PWR_EN, 1);
	}

	return 0;
}

int board_usb_cleanup(int index, enum usb_init_type init)
{
	int ret = 0;

	if (index == 0 && init == USB_INIT_DEVICE)
		/* usb host only */
		return 0;

	debug("USB%d: %s cleanup.\n", index, (init)?"otg":"host");
	if (index == 1 && init == USB_INIT_DEVICE) {
		dwc3_uboot_exit(index);
	} else if (index == 1 && init == USB_INIT_HOST) {
#ifdef CONFIG_USB_TCPC
		ret = tcpc_disable_src_vbus(&port1);
#endif
	} else if (index == 0 && init == USB_INIT_HOST) {
		/* Disable host power */
		gpio_direction_output(USB1_PWR_EN, 0);
	}

	imx8m_usb_power(index, false);

	return ret;
}

#ifdef CONFIG_USB_TCPC
/* Not used so far */
int board_typec_get_mode(int index)
{
	int ret = 0;
	enum typec_cc_polarity pol;
	enum typec_cc_state state;

	if (index == 1) {
		tcpc_setup_ufp_mode(&port1);

		ret = tcpc_get_cc_status(&port1, &pol, &state);
		if (!ret) {
			if (state == TYPEC_STATE_SRC_RD_RA || state == TYPEC_STATE_SRC_RD)
				return USB_INIT_HOST;
		}

		return USB_INIT_DEVICE;
	} else {
		return USB_INIT_HOST;
	}
}
#endif
#endif

#ifdef CONFIG_DM_VIDEO
#define FSL_SIP_GPC			0xC2000000
#define FSL_SIP_CONFIG_GPC_PM_DOMAIN	0x3
#define DISPMIX				13
#define MIPI				15
#endif

int board_init(void)
{
	unsigned int board_type = fs_board_get_type();

	/* Copy NBoot args to variables and prepare command prompt string */
	fs_board_init_common(&board_info[board_type]);


#ifdef CONFIG_USB_TCPC
	setup_typec();
#endif

#ifdef CONFIG_FEC_MXC
	setup_fec();
#endif

#ifdef CONFIG_DWC_ETH_QOS
	/* clock, pin, gpr */
	setup_eqos();
#endif

#if defined(CONFIG_USB_DWC3) || defined(CONFIG_USB_XHCI_IMX8M)
	init_usb_clk();
#endif

#ifdef CONFIG_DM_VIDEO
	/* enable the dispmix & mipi phy power domain */
	call_imx_sip(FSL_SIP_GPC, FSL_SIP_CONFIG_GPC_PM_DOMAIN, DISPMIX, true, 0);
	call_imx_sip(FSL_SIP_GPC, FSL_SIP_CONFIG_GPC_PM_DOMAIN, MIPI, true, 0);
#endif

	return 0;
}

/*TODO: video support is not available for now.
 * first disable bl_on and vlcd_on
 * */
#define BL_ON_PAD IMX_GPIO_NR(5, 3)
static iomux_v3_cfg_t const bl_on_pads[] = {
	MX8MP_PAD_SPDIF_TX__GPIO5_IO03 | MUX_PAD_CTRL(NO_PAD_CTRL),
};

#define VLCD_ON_PAD IMX_GPIO_NR(5, 2)
static iomux_v3_cfg_t const vlcd_on_pads[] = {
	MX8MP_PAD_SAI3_MCLK__GPIO5_IO02 | MUX_PAD_CTRL(NO_PAD_CTRL),
};

int board_late_init(void)
{

	if (fs_board_get_type() == BT_PICOCOREMX8MP)
	{
		env_set("platform", "picocoremx8mp");
		/* TODO: porting to F&S boot process */
		env_set("sercon", "ttymxc1");
	}
	/* Set up all board specific variables */
	fs_board_late_init_common("ttymxc");

	/* Set mac addresses for corresponding boards */
	fs_ethaddr_init();

	/*TODO: video support is not available for now. */
	imx_iomux_v3_setup_multiple_pads (bl_on_pads, ARRAY_SIZE (bl_on_pads));
	/* backlight off */
	gpio_request (BL_ON_PAD, "BL_ON");
	gpio_direction_output (BL_ON_PAD, 0);

	imx_iomux_v3_setup_multiple_pads (vlcd_on_pads, ARRAY_SIZE (vlcd_on_pads));
	/* vlcd_on off */
	gpio_request (VLCD_ON_PAD, "VLCD_ON");
	gpio_direction_output (VLCD_ON_PAD, 0);

	return 0;
}

#ifdef CONFIG_IMX_BOOTAUX
ulong board_get_usable_ram_top(ulong total_size)
{
	/* Reserve 16M memory used by M core vring/buffer, which begins at 16MB before optee */
	if (rom_pointer[1])
		return gd->ram_top - SZ_16M;

	return gd->ram_top;
}
#endif

#ifdef CONFIG_FSL_FASTBOOT
#ifdef CONFIG_ANDROID_RECOVERY
int is_recovery_key_pressing(void)
{
	return 0; /*TODO*/
}
#endif /*CONFIG_ANDROID_RECOVERY*/
#endif /*CONFIG_FSL_FASTBOOT*/

#ifdef CONFIG_ANDROID_SUPPORT
bool is_power_key_pressed(void) {
	return (bool)(!!(readl(SNVS_HPSR) & (0x1 << 6)));
}
#endif

#ifdef CONFIG_SPL_MMC_SUPPORT

#define UBOOT_RAW_SECTOR_OFFSET 0x40
unsigned long spl_mmc_get_uboot_raw_sector(struct mmc *mmc)
{
	u32 boot_dev = spl_boot_device();
	switch (boot_dev) {
		case BOOT_DEVICE_MMC2:
			return CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR - UBOOT_RAW_SECTOR_OFFSET;
		default:
			return CONFIG_SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR;
	}
}
#endif