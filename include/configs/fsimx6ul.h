/*
 * Copyright (C) 2015 F&S Elektronik Systeme GmbH
 *
 * Configuration settings for all F&S boards based on i.MX6 UL. This is
 * efusA7UL.
 *
 * Activate with one of the following targets:
 *   make fsimx6ul_config     Configure for i.MX6 UL boards
 *   make                     Build uboot.nb0
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * The following addresses are given as offsets of the device.
 *
 * NAND flash layout with separate Kernel/FDT MTD partition 
 * -------------------------------------------------------------------------
 * 0x0000_0000 - 0x0001_FFFF: NBoot: NBoot image, primary copy (128KB)
 * 0x0002_0000 - 0x0003_FFFF: NBoot: NBoot image, secondary copy (128KB)
 * 0x0004_0000 - 0x000F_FFFF: UserDef: User defined data (768KB)
 * 0x0010_0000 - 0x0013_FFFF: Refresh: Swap blocks for refreshing (256KB)
 * 0x0014_0000 - 0x001F_FFFF: UBoot: U-Boot image (768KB)
 * 0x0020_0000 - 0x0023_FFFF: UBootEnv: U-Boot environment (256KB)
 * 0x0024_0000 - 0x00A3_FFFF: Kernel: Linux Kernel uImage (8MB)
 * 0x00A4_0000 - 0x00BF_FFFF: FDT: Flat Device Tree(s) (1792KB)
 * 0x00C0_0000 -         END: TargetFS: Root filesystem (Size - 12MB)
 *
 * NAND flash layout with UBI only, Kernel/FDT in rootfs or kernel volume
 * -------------------------------------------------------------------------
 * 0x0000_0000 - 0x0001_FFFF: NBoot: NBoot image, primary copy (128KB)
 * 0x0002_0000 - 0x0003_FFFF: NBoot: NBoot image, secondary copy (128KB)
 * 0x0004_0000 - 0x000F_FFFF: UserDef: User defined data (768KB)
 * 0x0010_0000 - 0x0013_FFFF: Refresh: Swap blocks for refreshing (256KB)
 * 0x0014_0000 - 0x001F_FFFF: UBoot: U-Boot image (768KB)
 * 0x0020_0000 - 0x0023_FFFF: UBootEnv: U-Boot environment (256KB)
 * 0x0024_0000 -         END: TargetFS: Root filesystem (Size - 2.25MB)
 *
 * END: 0x07FF_FFFF for 128MB, 0x0FFF_FFFF for 256MB, 0x3FFF_FFFF for 1GB
 *
 * Remark:
 * Block size is 128KB. All partition sizes have been chosen to allow for at
 * least one bad block in addition to the required size of the partition. E.g.
 * UBoot is 512KB, but the UBoot partition is 768KB to allow for two bad blocks
 * (256KB) in this memory region.
 */

#ifndef __FSIMX6UL_CONFIG_H
#define __FSIMX6UL_CONFIG_H

/************************************************************************
 * High Level Configuration Options
 ************************************************************************/
#define CONFIG_IDENT_STRING " for F&S"	/* We are on an F&S board */

/* CPU, family and board defines */
#define CONFIG_MX6			/* Freescale i.MX6 CPU... */
#define CONFIG_MX6UL			/* ...UL... */
#define CONFIG_FSIMX6UL			/* ...on an F&S i.MX6 board */
#undef CONFIG_MP			/* No multi processor support */

#define CONFIG_SYS_L2CACHE_OFF
#ifndef CONFIG_SYS_L2CACHE_OFF
#define CONFIG_SYS_L2_PL310
#define CONFIG_SYS_PL310_BASE	L2_PL310_BASE
#endif

/* The ARMv7 cache code (arch/arm/lib/cache-cp15.c) and the i.MX6 init code
   (arch/arm/cpu/armv7/mx6/soc.c) now also allow to set the data cache mode to
   write-back. Unfortunately this is now the default, but (at least) i.MX6
   SDHC does not work with write-back yet. So set back to write-through. */
#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

//#define CONFIG_ARM_ERRATA_743622
//#define CONFIG_ARM_ERRATA_751472
//#define CONFIG_ARM_ERRATA_794072
//#define CONFIG_ARM_ERRATA_761320

#include <asm/arch/imx-regs.h>		/* IRAM_BASE_ADDR, IRAM_SIZE */

//###???#undef CONFIG_ARCH_CPU_INIT
//###FIXME### Can we activate CONFIG_SKIP_LOWLEVEL_INIT?
#undef CONFIG_SKIP_LOWLEVEL_INIT
#undef CONFIG_BOARD_EARLY_INIT_F	/* No early board specific stuff */
#define CONFIG_BOARD_LATE_INIT		/* Init board-specific environment */
#define CONFIG_DISPLAY_CPUINFO		/* Show CPU type and speed */
#define CONFIG_DISPLAY_BOARDINFO	/* Show board information */
#define CONFIG_ZERO_BOOTDELAY_CHECK	/* Allow entering U-Boot even if boot
					   delay is zero */
#undef CONFIG_USE_IRQ			/* No blinking LEDs yet */
#define CONFIG_SYS_LONGHELP		/* Undef to save memory */
#undef CONFIG_LOGBUFFER			/* No support for log files */
#define CONFIG_OF_LIBFDT		/* Use device trees (fdt) */

/* The load address of U-Boot is now independent from the size. Just load it
   at some rather low address in RAM. It will relocate itself to the end of
   RAM automatically when executed. */
#define CONFIG_SYS_TEXT_BASE 0x80100000	/* Where NBoot loads U-Boot */
#define CONFIG_UBOOTNB0_SIZE 0x80000	/* Size of uboot.nb0 */
#undef CONFIG_SYS_THUMB_BUILD		/* Build U-Boot in ARM mode */

/* For the default load address, use an offset of 8MB. The final kernel (after
   decompressing the zImage) must be at offset 0x8000. But if we load the
   zImage there, the loader code will move it away to make room for the
   uncompressed image at this position. So we'll load it directly to a higher
   address to avoid this additional copying. */
#define CONFIG_SYS_LOAD_OFFS 0x00800000


/************************************************************************
 * Memory Layout
 ************************************************************************/
/* Physical addresses of DDR and CPU-internal SRAM */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM		MMDC0_ARB_BASE_ADDR
//####define PHYS_SDRAM_SIZE		(1u * CONFIG_DDR_MB * 1024 * 1024)

#define CONFIG_SYS_SDRAM_BASE	PHYS_SDRAM

/* MX6UL has 128KB SRAM, mapped from 0x00900000-0x0091FFFF */
#define CONFIG_SYS_INIT_RAM_ADDR	(IRAM_BASE_ADDR)
#define CONFIG_SYS_INIT_RAM_SIZE	(0x20000/*###IRAM_SIZE###*/)

/* Init value for stack pointer, set at end of internal SRAM, keep room for
   global data behind stack. */
#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* Size of malloc() pool (heap). Command "ubi part" needs quite a large heap
   if the source MTD partition is large. The size should be large enough to
   also contain a copy of the environment. */
#define CONFIG_SYS_MALLOC_LEN	(2 * 1024 * 1024)

/* Allocate 2048KB protected RAM at end of RAM (Framebuffers, etc.) */
#define CONFIG_PRAM		2048

/* Alignment mask for MMU pagetable: 16kB */
#define CONFIG_SYS_TLB_ALIGN	0xFFFFC000

/* The final stack sizes are set up in board.c using the settings below */
#define CONFIG_SYS_STACK_SIZE	(128*1024)
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)
#define CONFIG_STACKSIZE_FIQ	(128)
#endif

/* Memory test checks all RAM before U-Boot (i.e. leaves last MB with U-Boot
   untested) ### If not set, test from beginning of RAM to before stack. */
//####define CONFIG_SYS_MEMTEST_START CONFIG_SYS_SDRAM_BASE
//####define CONFIG_SYS_MEMTEST_END	(CONFIG_SYS_SDRAM_BASE + OUR_UBOOT_OFFS)


/************************************************************************
 * Clock Settings and Timers
 ************************************************************************/
/* Basic input clocks */
#define CONFIG_SYS_MX6_HCLK	24000000

#define CONFIG_SYS_HZ		1000


/************************************************************************
 * GPIO
 ************************************************************************/
#define CONFIG_MXC_GPIO


/************************************************************************
 * OTP Memory (Fuses)
 ************************************************************************/
#define CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP


/************************************************************************
 * Serial Console (UART)
 ************************************************************************/
#define CONFIG_MXC_UART			/* Use MXC uart driver */
#define CONFIG_SYS_UART_PORT	1	/* Default UART port; however we
					   always take the port from NBoot */
#define CONFIG_CONS_INDEX       (CONFIG_SYS_UART_PORT)
#undef CONFIG_CONSOLE_MUX		/* Just one console at a time */
#define CONFIG_SYS_SERCON_NAME "ttymxc"	/* Base name for serial devices */
#define CONFIG_BAUDRATE		115200	/* Default baudrate */
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}


/************************************************************************
 * I2C
 ************************************************************************/
/* No I2C used in U-Boot on F&S i.MX6 UL boards */


/************************************************************************
 * LEDs
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * PMIC
 ************************************************************************/
/* No PMIC on F&S i.MX6 UL boards */


/************************************************************************
 * Real Time Clock (RTC)
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * Ethernet
 ************************************************************************/
#define CONFIG_FEC_MXC

/* PHY */
#define CONFIG_PHYLIB
#define CONFIG_PHY_MICREL		/* Micrel KSZ8081 */
#define CONFIG_SYS_DISCOVER_PHY
#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN

#undef CONFIG_ID_EEPROM			/* No EEPROM for ethernet MAC */


/************************************************************************
 * USB Host
 ************************************************************************/
/* Use USB1 as host */
#define CONFIG_USB_EHCI			/* Use EHCI driver (USB2.0) */
#define CONFIG_USB_EHCI_MX6		/* This is MX6 EHCI */
#define CONFIG_MXC_USB_PORTSC (PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS 0
#define CONFIG_USB_MAX_CONTROLLER_COUNT 2
//####define CONFIG_EHCI_HCD_INIT_AFTER_RESET
#define CONFIG_EHCI_IS_TDI		/* TDI version with USBMODE register */

#define CONFIG_USB_STORAGE


/************************************************************************
 * USB Device
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * Keyboard
 ************************************************************************/
#if 0 //###
#define CONFIG_USB_KEYBOARD
#define CONFIG_SYS_DEVICE_DEREGISTER	/* Required for CONFIG_USB_KEYBOARD */
#endif //0###


/************************************************************************
 * SD/MMC Card
 ************************************************************************/
#define CONFIG_MMC			  /* SD/MMC support */
#define CONFIG_GENERIC_MMC		  /* with the generic driver model, */
#define CONFIG_FSL_ESDHC		  /* use Freescale ESDHC driver */
#define CONFIG_FSL_USDHC		  /* with USDHC modifications */
#define CONFIG_SYS_FSL_ESDHC_ADDR 0	  /* Not used */
#define CONFIG_SYS_FSL_USDHC_NUM       1

//#define CONFIG_SYS_FSL_ERRATUM_ESDHC135
//#define CONFIG_SYS_FSL_ERRATUM_ESDHC111
//#define CONFIG_SYS_FSL_ERRATUM_ESDHC_A001


/************************************************************************
 * EMMC
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * NOR Flash
 ************************************************************************/
/* No NOR flash on F&S i.MX6 boards */
#define CONFIG_SYS_NO_FLASH


/************************************************************************
 * SPI Flash
 ************************************************************************/
/* No QSPI flash on F&S i.MX6 boards */


/************************************************************************
 * NAND Flash
 ************************************************************************/
/* Use F&S implementation of GPMI NFC NAND Flash Driver (MXS) */
#define CONFIG_NAND_MXS_FUS
#define CONFIG_SYS_NAND_BASE	0x40000000

/* DMA stuff, needed for GPMI/MXS NAND support */
#define CONFIG_APBH_DMA
#define CONFIG_APBH_DMA_BURST
#define CONFIG_APBH_DMA_BURST8

/* Use our own initialization code */
#define CONFIG_SYS_NAND_SELF_INIT

/* To avoid that NBoot is erased inadvertently, we define a skip region in the
   first NAND device that can not be written and always reads as 0xFF. However
   if value CONFIG_SYS_MAX_NAND_DEVICE is set to 2, the NBoot region is shown
   as a second NAND device with just that size. This makes it easier to have a
   different ECC strategy and software write protection for NBoot. */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
//#define CONFIG_SYS_MAX_NAND_DEVICE	2

/* Chips per device; all chips must be the same type; if different types
   are necessary, they must be implemented as different NAND devices */
#define CONFIG_SYS_NAND_MAX_CHIPS	1

/* Define if you want to support nand chips that comply to ONFI spec */
#define CONFIG_SYS_NAND_ONFI_DETECTION

/* Actually perform block refresh if pages degrade too much. Use the given
   blocks in decreasing order. */
#define CONFIG_NAND_REFRESH
#define CONFIG_SYS_NAND_BACKUP_START_BLOCK	9
#define CONFIG_SYS_NAND_BACKUP_END_BLOCK	8


/************************************************************************
 * Command Line Editor (Shell)
 ************************************************************************/
#define CONFIG_SYS_HUSH_PARSER		/* Use "hush" command parser */
#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

/* Allow editing (scroll between commands, etc.) */
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

/* Input and print buffer sizes */
#define CONFIG_SYS_CBSIZE	512	/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE	640	/* Print Buffer Size */
#define CONFIG_SYS_MAXARGS	16	/* max number of command args */
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE /* Boot Arg Buffer Size */


/************************************************************************
 * Command Definition
 ************************************************************************/
/* We don't include
     #include <config_cmd_default.h>
   but instead we define all the commands that we want ourselves. However
   <config_cmd_defaults.h> (note the s) is always included nonetheless. This
   always sets the following defines: CONFIG_CMD_BOOTM, CONFIG_CMD_CRC32,
   CONFIG_CMD_GO, CONFIG_CMD_EXPORTENV, CONFIG_CMD_IMPORTENV. */
#undef CONFIG_CMD_AMBAPP	/* No support to show AMBA plug&play devices */
#define CONFIG_CMD_ASKENV	/* Ask user for variable */
#define CONFIG_CMD_BDI		/* Board information (bdinfo) */
#undef CONFIG_CMD_BEDBUG	/* No PPC bedbug debugging support */
#undef CONFIG_CMD_BLINK		/* No support for blinking LEDs */
#undef CONFIG_CMD_BMP		/* No old BMP, use new display support */
#define CONFIG_CMD_BOOTD	/* Boot default target */
#undef CONFIG_CMD_BOOTLDR	/* No ldr support for blackfin */
#undef CONFIG_CMD_BOOTSTAGE	/* No bootstage command */
#define CONFIG_CMD_BOOTZ	/* Boot zImage */
#define CONFIG_CMD_CACHE	/* Switch cache on and off */
#undef CONFIG_CMD_CBFS		/* No support for coreboot filesystem */
#undef CONFIG_CMD_CDP		/* No support for CISCOs CDP network config */
#define CONFIG_CMD_CONSOLE	/* Console information (coninfo) */
#undef CONFIG_CMD_CPLBINFO	/* No display of PPC CPLB tables */
#undef CONFIG_CMD_CRAMFS	/* No support for CRAMFS filesystem */
#undef CONFIG_CMD_DATE		/* No date command */
#undef CONFIG_CMD_DFU		/* No support for device firmware update */ 
#define CONFIG_CMD_DHCP		/* Support TFTP boot after DHCP request */
#undef CONFIG_CMD_DIAG		/* No support for board selftest */
#undef CONFIG_CMD_DNS		/* No lookup of IP via a DNS name server */
#undef CONFIG_CMD_DTT		/* No digital thermometer and thermostat */
#define CONFIG_CMD_ECHO		/* Have echo command */
#define CONFIG_CMD_EDITENV	/* Allow editing of environment variables */
#undef CONFIG_CMD_EEPROM	/* No EEPROM support */
#undef CONFIG_CMD_ELF		/* No support to boot ELF images */
#define CONFIG_CMD_EXT2		/* Support for EXT2 commands */
#define CONFIG_CMD_EXT4		/* Support for EXT4 commands */
#define CONFIG_CMD_FAT		/* Support for FAT commands */
#undef CONFIG_CMD_FDC		/* No floppy disc controller */
#undef CONFIG_CMD_FDOS		/* No support for DOS from floppy disc */
#undef CONFIG_CMD_FITUPD	/* No update from FIT image */
#undef CONFIG_CMD_FLASH		/* No NOR flash (flinfo, erase, protect) */
#undef CONFIG_CMD_FPGA		/* No FPGA configuration support */
#define CONFIG_CMD_FS_GENERIC	/* Filesystem-independent ls and load */
#define CONFIG_CMD_GETTIME	/* Have gettime command */
#undef CONFIG_CMD_GPIO		/* No support to set GPIO pins */
#undef CONFIG_CMD_GPT		/* No support for GPT partition tables */
#undef CONFIG_CMD_GREPENV	/* No support to search in environment */
#undef CONFIG_CMD_HASH		/* No hash command */
#undef CONFIG_CMD_HWFLOW	/* No switching of serial flow control */
#undef CONFIG_CMD_I2C		/* No I2C support */
#undef CONFIG_CMD_IDE		/* No IDE disk support */
#define CONFIG_CMD_IMI		/* Image information (iminfo) */
#undef CONFIG_CMD_IMLS		/* No support to list all found images */
#undef CONFIG_CMD_IMMAP		/* No support for PPC immap table */
#define CONFIG_CMD_INI		/* Support INI files to init environment */
#undef CONFIG_CMD_IO		/* No I/O space commands iod and iow */
#undef CONFIG_CMD_IRQ		/* No interrupt support */
#define CONFIG_CMD_ITEST	/* Integer (and string) test */
#undef CONFIG_CMD_JFFS2		/* No support for JFFS2 filesystem */
#undef CONFIG_CMD_LDRINFO	/* No ldr support for blackfin */
#undef CONFIG_CMD_LED		/* No LED support */
#undef CONFIG_CMD_LICENSE	/* No support to show GPL license */
#undef CONFIG_CMD_LOADB		/* No serial load of binaries (loadb) */
#undef CONFIG_CMD_LOADS		/* No serial load of s-records (loads) */
#undef CONFIG_CMD_MD5SUM	/* No support for md5sum checksums */
#define CONFIG_CMD_MEMORY	/* md mm nm mw cp cmp crc base loop mtest */
#undef CONFIG_CMD_MFSL		/* No support for Microblaze FSL */
#define CONFIG_CMD_MII		/* Support for listing MDIO busses */
#define CONFIG_CMD_MISC		/* Miscellaneous commands (sleep) */
#define CONFIG_CMD_MMC		/* Support for SD/MMC cards */
#undef CONFIG_CMD_MMC_SPI	/* No access of MMC cards in SPI mode */
#undef CONFIG_CMD_MOVI		/* No support for MOVI NAND flash memories */
#define CONFIG_CMD_MTDPARTS	/* Support MTD partitions (mtdparts, chpart) */
#define CONFIG_CMD_NAND		/* Support for common NAND flash memories */
#define CONFIG_CMD_NET		/* Support BOOTP and TFTP (bootp, tftpboot) */
#define CONFIG_CMD_NFS		/* Support download via NFS */
#undef CONFIG_CMD_ONENAND	/* No support for ONENAND flash memories */
#undef CONFIG_CMD_OTP		/* No support for one-time-programmable mem */
#undef CONFIG_CMD_PART		/* No support for partition info */
#undef CONFIG_CMD_PCI		/* No PCI support */
#undef CONFIG_CMD_PCMCIA	/* No support for PCMCIA cards */
#define CONFIG_CMD_PING		/* Support ping command */
#undef CONFIG_CMD_PORTIO	/* No port commands (in, out) */
#undef CONFIG_CMD_PXE		/* No support for PXE files from pxelinux */
#undef CONFIG_CMD_RARP		/* No support for booting via RARP */
#define CONFIG_CMD_READ		/* Raw read from media without filesystem */
#undef CONFIG_CMD_REGINFO	/* No register support on ARM, only PPC */
#undef CONFIG_CMD_REISER	/* No support for reiserfs filesystem */
#define CONFIG_CMD_RUN		/* Run command in env variable */
#undef CONFIG_CMD_SATA		/* No support for SATA disks */
#define CONFIG_CMD_SAVEENV	/* Allow saving environment to NAND */
#undef CONFIG_CMD_SAVES		/* No support for serial uploads (saving) */
#undef CONFIG_CMD_SCSI		/* No support for SCSI disks */
#undef CONFIG_CMD_SDRAM		/* Support SDRAM chips via I2C */
#define CONFIG_CMD_SETEXPR	/* Set variable by evaluating an expression */
#undef CONFIG_CMD_SETGETDCR	/* No support for PPC DCR register */
#undef CONFIG_CMD_SF		/* No support for serial SPI flashs */
#undef CONFIG_CMD_SHA1SUM	/* No support for sha1sum checksums */
#undef CONFIG_CMD_SNTP		/* No synchronizing of RTC via network */
#undef CONFIG_CMD_SOUND		/* No sound command */
#define CONFIG_CMD_SOURCE	/* Source support (was autoscr)	*/
#undef CONFIG_CMD_SPI		/* No SPI support */
#undef CONFIG_CMD_SPIBOOTLDR	/* No ldr support over SPI for blackfin */
#undef CONFIG_CMD_SPL		/* No SPL support (kernel parameter images) */
#undef CONFIG_CMD_STRINGS	/* No support to show strings */
#undef CONFIG_CMD_TERMINAL	/* No terminal emulator */
#undef CONFIG_CMD_TFTPPUT	/* No sending of TFTP files (tftpput) */
#undef CONFIG_CMD_TFTPSRV	/* No acting as TFTP server (tftpsrv) */
#undef CONFIG_CMD_TIME		/* No support to time command execution */
#define CONFIG_CMD_TIMER	/* Support system timer access */
#undef CONFIG_CMD_TPM		/* No support for TPM */
#undef CONFIG_CMD_TSI148	/* No support for Turndra Tsi148 */
#define CONFIG_CMD_UBI		/* Support for unsorted block images (UBI) */
#define CONFIG_CMD_UBIFS	/* Support for UBIFS filesystem */
#undef CONFIG_CMD_UNIVERSE	/* No support for Turndra Universe */
#define CONFIG_CMD_UNZIP	/* Have unzip command */
#define CONFIG_CMD_UPDATE	/* Support automatic update/install */
#define CONFIG_CMD_USB		/* USB host support */
#define CONFIG_CMD_XIMG		/* Load part of Multi Image */
#undef CONFIG_CMD_ZFS		/* No support for ZFS filesystem */
#undef CONFIG_CMD_ZIP		/* No support to zip memory region */


/************************************************************************
 * Display Commands (LCD)
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * Network Options
 ************************************************************************/
#define CONFIG_BOOTP_SUBNETMASK
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_DNS		/* Configurable parts of CMD_DHCP */
#define CONFIG_BOOTP_DNS2
#define CONFIG_BOOTP_SEND_HOSTNAME
#define CONFIG_NET_RETRY_COUNT	5
#define CONFIG_ARP_TIMEOUT	2000UL
#define CONFIG_MII			/* Required in net/eth.c */


/************************************************************************
 * Filesystem Support
 ************************************************************************/
/* FAT */
#define CONFIG_FS_FAT			/* Support FAT... */
#define CONFIG_SUPPORT_VFAT		/* ...with VFAT */
#define CONFIG_DOS_PARTITION

/* EXT4 */
#define CONFIG_FS_EXT4			/* Support EXT2/3/4 */

/* JFFS2 */
#define CONFIG_JFFS2_NAND		/* Support JFFS2 in NAND */

/* YAFFS */
#undef CONFIG_CMD_NAND_YAFFS		/* No nand read/write.yaffs */
#undef CONFIG_YAFFS2			/* No support for YAFFS2 commands */

/* UBI/UBIFS */
#define CONFIG_RBTREE			/* Required for UBI */
#define CONFIG_LZO			/* Required for UBI */


/************************************************************************
 * Generic MTD Settings
 ************************************************************************/
#define CONFIG_MTD_DEVICE		/* Create MTD device */
#define CONFIG_MTD_PARTITIONS		/* Required for UBI */

/* Define MTD partition info */
#if CONFIG_SYS_MAX_NAND_DEVICE > 1
#define MTDIDS_DEFAULT		"nand0=gpmi-nand0,nand1=gpmi-nand1"
#define MTDPART_DEFAULT		"nand0,0"
#define MTDPARTS_PART1		"fsnand1:256k(NBoot)ro\\\\;fsnand0:768k@256k(UserDef)"
#else
#define MTDIDS_DEFAULT		"nand0=gpmi-nand"
#define MTDPART_DEFAULT		"nand0,1"
#define MTDPARTS_PART1		"gpmi-nand:256k(NBoot)ro,768k(UserDef)"
#endif
#define MTDPARTS_PART2		"256k(Refresh)ro,768k(UBoot)ro,256k(UBootEnv)ro"
#define MTDPARTS_PART3		"8m(Kernel)ro,1792k(FDT)ro"
#define MTDPARTS_PART4		"-(TargetFS)"
#define MTDPARTS_STD		"setenv mtdparts mtdparts=" MTDPARTS_PART1 "," MTDPARTS_PART2 "," MTDPARTS_PART3 "," MTDPARTS_PART4
#define MTDPARTS_UBIONLY	"setenv mtdparts mtdparts=" MTDPARTS_PART1 "," MTDPARTS_PART2 "," MTDPARTS_PART4


/************************************************************************
 * Environment
 ************************************************************************/
#define CONFIG_ENV_IS_IN_NAND		/* Environment is in NAND flash */
#define CONFIG_ENV_OVERWRITE		/* Allow overwriting serial/ethaddr */
#define CONFIG_SYS_CONSOLE_IS_IN_ENV	/* Console can be saved in env */

/* Environment settings for large blocks (128KB). The environment is held in
   the heap, so keep the real env size small to not waste malloc space. */
#define ENV_SIZE_DEF_LARGE   0x00004000	/* 16KB */
#define ENV_RANGE_DEF_LARGE  0x00040000 /* 2 blocks = 256KB */
#define ENV_OFFSET_DEF_LARGE 0x00200000 /* See NAND layout above */

/* When saving the environment, we usually have a short period of time between
   erasing the NAND region and writing the new data where no valid environment
   is available. To avoid this time, we can save the environment alternatively
   to two different locations in the NAND flash. Then at least one of the
   environments is always valid. Currently we don't use this feature. */
//#define CONFIG_SYS_ENV_OFFSET_REDUND   0x001C0000

#define CONFIG_ETHADDR_BASE	00:05:51:07:55:83
#define CONFIG_ETHPRIME		"FEC0"
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		10.0.0.252
#define CONFIG_SERVERIP		10.0.0.122
#define CONFIG_GATEWAYIP	10.0.0.5
#define CONFIG_BOOTFILE		"uImage"
#define CONFIG_ROOTPATH		"/rootfs"
#define CONFIG_MODE		"ro"
#define CONFIG_BOOTDELAY	undef
#define CONFIG_PREBOOT
#define CONFIG_BOOTARGS		"undef"
#define CONFIG_BOOTCOMMAND	"run set_bootargs; run kernel; run fdt"

/* Add some variables that are not predefined in U-Boot. All entries with
   content "undef" will be updated with a board-specific value in
   board_late_init().

   We use ${...} here to access variable names because this will work with the
   simple command line parser, who accepts $(...) and ${...}, and also the
   hush parser, who accepts ${...} and plain $... without any separator.

   If a variable is meant to be called with "run" and wants to set an
   environment variable that contains a ';', we can either enclose the whole
   string to set in (escaped) double quotes, or we have to escape the ';' with
   a backslash. However when U-Boot imports the environment from NAND into its
   hash table in RAM, it interprets escape sequences, which will remove a
   single backslash. So we actually need an escaped backslash, i.e. two
   backslashes. Which finally results in having to type four backslashes here,
   as each backslash must also be escaped with a backslash in C. */
#ifdef CONFIG_CMD_UBI
#ifdef CONFIG_CMD_UBIFS
#define EXTRA_UBIFS \
	".kernel_ubifs=setenv kernel ubi part TargetFS\\\\; ubifsmount ubi0:rootfs\\\\; ubifsload . /boot/${bootfile}\0"
#else
#define EXTRA_UBIFS
#endif
#define EXTRA_UBI EXTRA_UBIFS \
	".mtdparts_ubionly=" MTDPARTS_UBIONLY "\0" \
	".rootfs_ubifs=setenv rootfs rootfstype=ubifs ubi.mtd=TargetFS root=ubi0:rootfs\0" \
	".kernel_ubi=setenv kernel ubi part TargetFS\\\\; ubi read . kernel\0" \
	".ubivol_std=ubi part TargetFS; ubi create rootfs\0" \
	".ubivol_ubi=ubi part TargetFS; ubi create kernel 5c0000 s; ubi create rootfs\0"
#else
#define EXTRA_UBI
#endif

#define BOOT_WITH_FDT "\\\\; bootm ${loadaddr} - 81000000\0"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=undef\0" \
	".console_none=setenv console\0" \
	".console_serial=setenv console console=${sercon},${baudrate}\0" \
	".console_display=setenv console console=tty1\0" \
	"login=undef\0" \
	".login_none=setenv login login_tty=null\0" \
	".login_serial=setenv login login_tty=${sercon},${baudrate}\0" \
	".login_display=setenv login login_tty=tty1\0" \
	"mtdparts=undef\0" \
	".mtdparts_std=" MTDPARTS_STD "\0" \
	".network_off=setenv network\0"					\
	".network_on=setenv network ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}:${netdev}\0" \
	".network_dhcp=setenv network ip=dhcp\0" \
	"rootfs=undef\0" \
	".rootfs_nfs=setenv rootfs root=/dev/nfs nfsroot=${rootpath}\0" \
	".rootfs_mmc=setenv rootfs root=/dev/mmcblk0p1 rootwait\0" \
	".rootfs_usb=setenv rootfs root=/dev/sda1 rootwait\0" \
	"kernel=undef\0" \
	".kernel_nand=setenv kernel nboot Kernel\0" \
	".kernel_tftp=setenv kernel tftpboot . ${bootfile}\0" \
	".kernel_nfs=setenv kernel nfs . ${serverip}:${rootpath}/${bootfile}\0" \
	".kernel_mmc=setenv kernel mmc rescan\\\\; load mmc 0 . ${bootfile}\0" \
	".kernel_usb=setenv kernel usb start\\\\; load usb 0 . ${bootfile}\0" \
        "fdt=undef\0" \
        ".fdt_none=setenv fdt bootm\0" \
        ".fdt_nand=setenv fdt nand read 81000000 FDT" BOOT_WITH_FDT \
        ".fdt_tftp=setenv fdt tftpboot 81000000 ${bootfdt}" BOOT_WITH_FDT \
        ".fdt_nfs=setenv fdt nfs 81000000 ${serverip}:${rootpath}/${bootfdt}" BOOT_WITH_FDT \
        ".fdt_mmc=setenv fdt mmc rescan\\\\; load mmc 0 81000000 ${bootftd}" BOOT_WITH_FDT \
        ".fdt_mmc=setenv fdt usb start\\\\; load usb 0 81000000 ${bootftd}" BOOT_WITH_FDT \
	EXTRA_UBI \
	"mode=undef\0" \
	".mode_rw=setenv mode rw\0" \
	".mode_ro=setenv mode ro\0" \
	"netdev=eth0\0" \
	"init=undef\0" \
	".init_init=setenv init\0" \
	".init_linuxrc=setenv init init=linuxrc\0" \
	"sercon=undef\0" \
	"installcheck=undef\0" \
	"updatecheck=undef\0" \
	"recovercheck=undef\0" \
	"earlyusbinit=undef\0" \
	"platform=undef\0" \
	"arch=fsimx6ul\0" \
	"bootfdt=fdt.dtb\0" \
	"set_bootargs=setenv bootargs ${console} ${login} ${mtdparts} ${network} ${rootfs} ${mode} ${init} ${extra}\0"


/************************************************************************
 * DFU (USB Device Firmware Update, requires USB device support)
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * Linux and Android Support
 ************************************************************************/
#define CONFIG_ZIMAGE_BOOT
#define CONFIG_IMAGE_BOOT
#define CONFIG_ANDROID_BOOT_IMAGE

/* Try to patch serial debug port in image within first 16KB of zImage */
#define CONFIG_SYS_PATCH_TTY	0x4000

/* ATAGs passed to Linux */
#define CONFIG_SETUP_MEMORY_TAGS	/* Memory setup */
#define CONFIG_CMDLINE_TAG		/* Command line */
#undef CONFIG_INITRD_TAG		/* No initrd */
#define CONFIG_REVISION_TAG		/* Board revision */
#define CONFIG_FSHWCONFIG_TAG		/* Hardware config (NBoot-Args) */
#define CONFIG_FSM4CONFIG_TAG		/* M4 image and config (M4-Args) */


/************************************************************************
 * Tools
 ************************************************************************/
#define CONFIG_ADDFSHEADER


/************************************************************************
 * Libraries
 ************************************************************************/
//#define USE_PRIVATE_LIBGCC
#define CONFIG_SYS_64BIT_VSPRINTF	/* Needed for nand_util.c */
#define CONFIG_USE_ARCH_MEMCPY
#define CONFIG_USE_ARCH_MEMMOVE
#define CONFIG_USE_ARCH_MEMSET
#define CONFIG_USE_ARCH_MEMSET32

#endif /* !__FSIMX6UL_CONFIG_H */