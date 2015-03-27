/*
 * Copyright (C) 2015 F&S Elektronik Systeme GmbH
 *
 * Configuration settings for all F&S boards based on S5PV210. This is
 * armStoneA8 (and its predecessor EASYsom1), PicoMOD7A and NetDCU14.
 *
 * Activate with one of the following targets:
 *   make fss5pv210_config      Configure for S5PV210 boards
 *   make fss5pv210             Configure for S5PV210 boards and build
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * The following addresses are given as offsets of the device.
 *
 * NAND flash layout (Block size 16KB) (64MB)
 * -------------------------------------------------------------------------
 * 0x0000_0000 - 0x0000_7FFF: NBoot: NBoot image (32KB)
 * 0x0000_8000 - 0x0007_7FFF: UBoot: U-Boot image (448KB)
 * 0x0007_8000 - 0x0007_FFFF: UBootEnv: U-Boot environment (32KB)
 * 0x0008_0000 - 0x000F_FFFF: UserDef: User defined data (512KB)
 * 0x0010_0000 - 0x003F_FFFF: Kernel: Linux Kernel zImage (3MB)
 * 0x0040_0000 - 0x03FF_FFFF: TargetFS: Root filesystem (60MB)
 *
 * NAND flash layout (Block size 128KB) (128MB, 1GB)
 * -------------------------------------------------------------------------
 * 0x0000_0000 - 0x0003_FFFF: NBoot: NBoot image (256KB)
 * 0x0004_0000 - 0x000B_FFFF: UBoot: U-Boot image (512KB)
 * 0x000C_0000 - 0x000F_FFFF: UBootEnv: U-Boot environment (256KB)
 * 0x0010_0000 - 0x004F_FFFF: UserDef: User defined data (4MB)
 * 0x0050_0000 - 0x007F_FFFF: Kernel: Linux Kernel zImage (3MB)
 * 0x0080_0000 - 0x07FF_FFFF: TargetFS: Root filesystem (120MB if 128MB)
 * 0x0080_0000 - 0x3FFF_FFFF: TargetFS: Root filesystem (1016MB if 1GB)
 *
 * Remark:
 * All partition sizes have been chosen to allow for at least one bad block in
 * addition to the required size of the partition. E.g. UBoot is 384KB, but
 * the UBoot partition is 512KB to allow for one bad block (128KB) in this
 * memory region.
 *
 * In case of a UBIONLY environment, the Kernel partition is dropped and the
 * space for it is added to the TargetFS.
 *
 * RAM layout
 * (RAM starts at 0x40000000 with 256MB and 0x30000000 with 512MB)
 * -------------------------------------------------------------------------
 * 0x0000_0000 - 0x0000_00FF: Free RAM
 * 0x0000_0100 - 0x0000_7FFF: bi_boot_params
 * 0x0000_8000 - 0x007F_FFFF: Linux zImage
 * 0x0080_0000 - 0x00FF_FFFF: Linux BSS (decompressed kernel)
 * 0x0100_0000 - 0x0FFF_FFFF: Free RAM + U-Boot (if 256MB)
 * 0x0100_0000 - 0x1FFF_FFFF: Free RAM + U-Boot (if 512MB)
 *
 * Remark:
 * Actually the lower RAM bank starts at 0x20000000. But as it is only 256MB,
 * it is mirrored at 0x30000000. When using the region starting at 0x30000000
 * instead, we get a continuous memory region of 512MB without gap.
 *
 * NBoot loads U-Boot to a rather low RAM address. Then U-Boot computes its
 * final size and relocates itself to the end of RAM. This new ARM specific
 * loader scheme was introduced in u-boot-2010.12. It only requires to set
 * gd->ram_base correctly and to privide a board-specific function dram_init()
 * that sets gd->ram_size to the actually available RAM. For more details see
 * arch/arm/lib/board.c.
 *
 * Memory layout within U-Boot (from top to bottom, starting at
 * RAM-Top = gd->ram_base + gd->ram_size)
 *
 * Addr          Size                      Comment
 * -------------------------------------------------------------------------
 * RAM-Top       CONFIG_SYS_MEM_TOP_HIDE   Hidden memory (unused)
 *               LOGBUFF_RESERVE           Linux kernel logbuffer (unused)
 *               getenv("pram") (in KB)    Protected RAM set in env (unused)
 * gd->tlb_addr  16KB (16KB aligned)       MMU page tables (TLB)
 * gd->fb_base   lcd_setmen()              LCD framebuffer (unused?)
 *               gd->monlen (4KB aligned)  U-boot code, data and bss
 *               TOTAL_MALLOC_LEN          malloc heap
 * bd            sizeof(bd_t)              Board info struct
 * gd->irq_sp    sizeof(gd_t)              Global data
 *               CONFIG_STACKSIZE_IRQ      IRQ stack
 *               CONFIG_STACKSIZE_FIQ      FIQ stack
 *               12 (8-byte aligned)       Abort-stack
 *
 * Remark: TOTAL_MALLOC_LEN depends on CONFIG_SYS_MALLOC_LEN and CONFIG_ENV_SIZE
 *
 */

#ifndef __FSS5PV210_CONFIG_H
#define __FSS5PV210_CONFIG_H

/************************************************************************
 * High Level Configuration Options
 ************************************************************************/
#define CONFIG_IDENT_STRING " for F&S"	/* We are on an F&S board */

/* CPU, family and board defines */
#define CONFIG_SAMSUNG		1	/* SAMSUNG core... */
#define CONFIG_S5P		1	/* ...in S5P family... */
#define CONFIG_S5PV210		1	/* ...an S5PV210 SoC... */
#define CONFIG_FSS5PV210	1	/* ...on an F&S S5PV210 board */
#undef CONIFG_MP			/* No multi processor support */

/* The machine IDs are already set in include/asm/mach-types.h, but we may
   need some additional settings */
#define MACH_TYPE_PICOMOD7A	MACH_TYPE_PICOMOD7   /* Use same as PicoMOD7 */ 
#define MACH_TYPE_QBLISSA8B	MACH_TYPE_ARMSTONEA8 /* ###TODO, if ever */
#define MACH_TYPE_EASYSOM1	MACH_TYPE_ARMSTONEA8 /* no extra number */

#define CONFIG_ARCH_CPU_INIT		/* Set CPU type rather early */
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
#undef CONFIG_OF_LIBFDT			/* No device tree (fdt) support yet */

/* The load address of U-Boot is now independent from the size. Just load it
   at some rather low address in RAM. It will relocate itself to the end of
   RAM automatically when executed. */
#define CONFIG_SYS_PHY_UBOOT_BASE	0x40f00000
#define CONFIG_SYS_UBOOT_BASE		CONFIG_SYS_PHY_UBOOT_BASE
#define CONFIG_UBOOTNB0_SIZE    384	/* Size of uboot.nb0 (in kB) */
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
/* Physical RAM addresses; however we compute the base address in function
   checkboard() */
#define CONFIG_NR_DRAM_BANKS	2	        /* We use 2 banks of DRAM */
#define PHYS_SDRAM_0		0x20000000	/* SDRAM Bank #0 */
#define PHYS_SDRAM_1		0x40000000	/* SDRAM Bank #1 */

/* S5PV210 has 96KB internal SRAM (IRAM) mapped from 0xD0020000-0xD0037FFF */
#define CONFIG_SYS_INIT_RAM_ADDR	0xD0020000
#define CONFIG_SYS_INIT_RAM_SIZE	0x00018000

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
//#define CONFIG_PRAM		2048

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
#define CONFIG_SYS_CLK_FREQ	12000000  /* 12MHz (only on Rev 1.0) */

/* The PWM Timer 4 uses a prescaler of 16 and a divider of 2 for PCLK; this
   results in the following value for PCLK=66.7MHz */
#define CONFIG_SYS_HZ		2084375


/************************************************************************
 * GPIO
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * OTP Memory (Fuses)
 ************************************************************************/
/* No OTP memory available on S5PV210 */


/************************************************************************
 * Serial Console (UART)
 ************************************************************************/
#define CONFIG_SYS_UART_PORT    0	/* Default UART port; however we
					   always take the port from NBoot */
#undef CONFIG_CONSOLE_MUX		/* Just one console at a time */
#define CONFIG_SYS_SERCON_NAME "ttySAC"	/* Base name for serial devices */
#define CONFIG_BAUDRATE		38400	/* Default baudrate */
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}


/************************************************************************
 * I2C
 ************************************************************************/
/* No I2C used in U-Boot on F&S S5PV210 boards */


/************************************************************************
 * LEDs
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * PMIC
 ************************************************************************/
/* No PMIC present on F&S S5PV210 boards */


/************************************************************************
 * Real Time Clock (RTC)
 ************************************************************************/
#define CONFIG_RTC_S5P	1


/************************************************************************
 * Ethernet
 ************************************************************************/
/* This board has one or two NE2000 compatible AX88769B ethernet chips */
#define CONFIG_DRIVER_NE2000
#define CONFIG_DRIVER_NE2000_BASE	0x80000000
#define CONFIG_DRIVER_NE2000_BASE2	0x88000000
#define CONFIG_DRIVER_NE2000_SOFTMAC
#define CONFIG_DRIVER_AX88796L
#define CONFIG_HAS_ETH1

#undef CONFIG_ID_EEPROM			/* No EEPROM for ethernet MAC */


/************************************************************************
 * USB Host
 ************************************************************************/
/* Define one of the following two lines to select the USB host driver */
#undef CONFIG_USB_OHCI_NEW		  /* Use OHCI (only USB 1.1) */
#define CONFIG_USB_EHCI			  /* Use EHCI (USB 2.0 capable) */

/* Settings for OHCI driver */
#ifdef CONFIG_USB_OHCI_NEW
#define CONFIG_USB_S5P			  /* Include S5P specific stuff */
#define CONFIG_SYS_USB_OHCI_REGS_BASE samsung_get_base_ohci()
#define CONFIG_SYS_USB_OHCI_CPU_INIT	  /* Call S5P specific stuff */
#define CONFIG_SYS_USB_OHCI_SLOT_NAME "s5p"
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS 2
#endif

/* Settings for EHCI driver */
#ifdef CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_S5P		  /* Use S5P driver for EHCI */
#endif

/* In both cases activate storage devices */
#define CONFIG_USB_STORAGE


/************************************************************************
 * USB Device
 ************************************************************************/
/* No support for special USB device download on this board */
#undef CONFIG_S3C_USBD
//#define USBD_DOWN_ADDR		0xc0000000


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
#define CONFIG_MMC			/* SD/MMC support */
#define CONFIG_GENERIC_MMC		/* with the generic driver model */
#define CONFIG_SDHCI			/* use SDHCI driver */
#define CONFIG_S5P_SDHCI		/* with support for S5P */
#define CONFIG_MMC_SDMA			/* use SDMA mode */


/************************************************************************
 * OneNAND Flash
 ************************************************************************/
/* No OneNAND on F&S S5PV210 boards */
#undef CONFIG_ONENAND
#define CONFIG_SYS_MAX_ONENAND_DEVICE	0
#define CONFIG_SYS_ONENAND_BASE 	(0x70100000)


/************************************************************************
 * MoviNAND Flash
 ************************************************************************/
/* No MoviNAND on F&S S5PV210 boards */
#undef CONFIG_MOVINAND


/************************************************************************
 * NOR Flash
 ************************************************************************/
/* No NOR flash on F&S S5PV210 boards */
#define CONFIG_SYS_NO_FLASH


/************************************************************************
 * SPI Flash
 ************************************************************************/
/* No SPI flash on F&S S5PV210 boards */


/************************************************************************
 * NAND Flash
 ************************************************************************/
/* Use S5PV210 NAND driver */
#define CONFIG_NAND_S5P		1

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

/* Use hardware ECC */
#define CONFIG_SYS_S5P_NAND_HWECC


/************************************************************************
 * Command Line Editor (Shell)
 ************************************************************************/
#define CONFIG_SYS_HUSH_PARSER		/* Use "hush" command parser */
#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

/* Allow editing (scroll between commands, etc.) */
#define CONFIG_CMDLINE_EDITING
#undef CONFIG_AUTO_COMPLETE

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
#define CONFIG_CMD_DATE		/* Have date command */
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
#undef CONFIG_CMD_IRQ		/* No interrupt support */
#define CONFIG_CMD_ITEST	/* Integer (and string) test */
#undef CONFIG_CMD_JFFS2		/* No support for JFFS2 filesystem */
#undef CONFIG_CMD_LDRINFO	/* No ldr support for blackfin */
#undef CONFIG_CMD_LED		/* No LED support */
#undef CONFIG_CMD_LOADB		/* No serial load of binaries (loadb) */
#undef CONFIG_CMD_LOADS		/* No serial load of s-records (loads) */
#undef CONFIG_CMD_MD5SUM	/* No support for md5sum checksums */
#define CONFIG_CMD_MEMORY	/* md mm nm mw cp cmp crc base loop mtest */
#undef CONFIG_CMD_MFSL		/* No support for Microblaze FSL */
#undef CONFIG_CMD_MII		/* No support for listing MDIO busses */
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
#undef CONFIG_CMD_PCI		/* No PCI support */
#undef CONFIG_CMD_PCMCIA	/* No support for PCMCIA cards */
#define CONFIG_CMD_PING		/* Support ping command */
#undef CONFIG_CMD_PORTIO	/* No port commands (in, out) */
#undef CONFIG_CMD_PXE		/* No support for PXE files from pxelinux */
#undef CONFIG_CMD_RARP		/* No support for booting via RARP */
#undef CONFIG_CMD_REGINFO	/* No register support on ARM, only PPC */
#undef CONFIG_CMD_REISER	/* No support for reiserfs filesystem */
#define CONFIG_CMD_RUN		/* Run command in env variable	*/
#undef CONFIG_CMD_SATA		/* No support for SATA disks */
#define CONFIG_CMD_SAVEENV	/* Allow saving environment to NAND */
#undef CONFIG_CMD_SAVES		/* No support for serial uploads (saving) */
#undef CONFIG_CMD_SCSI		/* No support for SCSI disks */
#undef CONFIG_CMD_SDRAM		/* Support SDRAM chips via I2C */
#define CONFIG_CMD_SETEXPR	/* Set variable by evaluating an expression */
#undef CONFIG_CMD_SETGETDCR	/* No support for PPC DCR register */
#undef CONFIG_CMD_SF		/* No support for serial SPI flashs */
#undef CONFIG_CMD_SHA1SUM	/* No support for sha1sum checksums */
#define CONFIG_CMD_SNTP		/* Allow synchronizing RTC via network */
#define CONFIG_CMD_SOURCE	/* Source support (was autoscr)	*/
#undef CONFIG_CMD_SPI		/* No SPI support */
#undef CONFIG_CMD_SPIBOOTLDR	/* No ldr support over SPI for blackfin */
#undef CONFIG_CMD_SPL		/* No SPL support (kernel parameter images) */
#undef CONFIG_CMD_STRINGS	/* No support to show strings */
#undef CONFIG_CMD_TERMINAL	/* No terminal emulator */
#undef CONFIG_CMD_TFTPPUT	/* No sending of TFTP files (tftpput) */
#undef CONFIG_CMD_TFTPSRV	/* No acting as TFTP server (tftpsrv) */
#undef CONFIG_CMD_TIME		/* No support to time command execution */
#undef CONFIG_CMD_TPM		/* No support for TPM */
#undef CONFIG_CMD_TSI148	/* No support for Turndra Tsi148 */
#define CONFIG_CMD_UBI		/* Support for unsorted block images (UBI) */
#undef CONFIG_CMD_UBIFS		/* No support for UBIFS filesystem */
#undef CONFIG_CMD_UNIVERSE	/* No support for Turndra Universe */
#define CONFIG_CMD_UNZIP	/* Have unzip command */
#define CONFIG_CMD_UPDATE	/* Support automatic update/install */
#define CONFIG_CMD_USB		/* USB host support */
#undef CONFIG_CMD_XIMG		/* No support to load part of Multi Image */


/************************************************************************
 * Display Commands (LCD)
 ************************************************************************/
#if 0 //###TODO###
#define CONFIG_CMD_LCD			/* Support lcd settings command */
//#define CONFIG_CMD_WIN		/* Window layers, alpha blending */
//#define CONFIG_CMD_CMAP		/* Support CLUT pixel formats */
#define CONFIG_CMD_DRAW			/* Support draw command */
//#define CONFIG_CMD_ADRAW		/* Support alpha draw commands */
//#define CONFIG_CMD_BMINFO		/* Provide bminfo command */
//#define CONFIG_XLCD_PNG		/* Support for PNG bitmaps */
#define CONFIG_XLCD_BMP			/* Support for BMP bitmaps */
//#define CONFIG_XLCD_JPG		/* Support for JPG bitmaps */
#define CONFIG_XLCD_EXPR		/* Allow expressions in coordinates */
#define CONFIG_XLCD_CONSOLE		/* Support console on LCD */
#define CONFIG_XLCD_CONSOLE_MULTI	/* Define a console on each window */
#define CONFIG_XLCD_FBSIZE 0x00100000	/* 1 MB default framebuffer pool */
#define CONFIG_S3C64XX_XLCD		/* Use S3C64XX lcd driver */
#define CONFIG_S3C64XX_XLCD_PWM 1	/* Use PWM1 for backlight */

/* Supported draw commands (see inlcude/cmd_xlcd.h) */
#define CONFIG_XLCD_DRAW \
	(XLCD_DRAW_PIXEL | XLCD_DRAW_LINE | XLCD_DRAW_RECT	\
	 | /*XLCD_DRAW_CIRC | XLCD_DRAW_TURTLE |*/ XLCD_DRAW_FILL	\
	 | XLCD_DRAW_TEXT | XLCD_DRAW_BITMAP | XLCD_DRAW_PROG	\
	 | XLCD_DRAW_TEST)

/* Supported test images (see include/cmd_xlcd.h) */
#define CONFIG_XLCD_TEST \
	(XLCD_TEST_GRID /*| XLCD_TEST_COLORS | XLCD_TEST_D2B | XLCD_TEST_GRAD*/)
#endif //0###


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
#define CONFIG_NET_RETRY_COUNT	10
#define CONFIG_ARP_TIMEOUT	200UL


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
#define MTDIDS_DEFAULT		"nand0=fsnand0,nand1=fsnand1"
#define MTDPART_DEFAULT		"nand0,2"
#define MTDPARTS_PART1_SMALL	"fsnand1:32k(NBoot)ro\\\\;fsnand0:448k@32k(UBoot)ro"
#define MTDPARTS_PART1_LARGE	"fsnand1:256k(NBoot)ro\\\\;fsnand0:512k@256k(UBoot)ro"
#else
#define MTDIDS_DEFAULT		"nand0=fsnand0"
#define MTDPART_DEFAULT		"nand0,3"
#define MTDPARTS_PART1_SMALL	"fsnand0:32k(NBoot)ro,448k(UBoot)ro"
#define MTDPARTS_PART1_LARGE	"fsnand0:256k(NBoot)ro,512k(UBoot)ro"
#endif
#define MTDPARTS_PART2_SMALL	"32k(UBootEnv)ro,512k(UserDef)"
#define MTDPARTS_PART2_LARGE	"256k(UBootEnv)ro,4m(UserDef)"
#define MTDPARTS_PART3		"3m(Kernel)ro"
#define MTDPARTS_PART4		"-(TargetFS)"
#define MTDPARTS_STD_SMALL	"setenv mtdparts mtdparts=" MTDPARTS_PART1_SMALL "," MTDPARTS_PART2_SMALL "," MTDPARTS_PART3 "," MTDPARTS_PART4
#define MTDPARTS_STD_LARGE	"setenv mtdparts mtdparts=" MTDPARTS_PART1_LARGE "," MTDPARTS_PART2_LARGE "," MTDPARTS_PART3 "," MTDPARTS_PART4
#define MTDPARTS_UBIONLY_SMALL	"setenv mtdparts mtdparts=" MTDPARTS_PART1_SMALL "," MTDPARTS_PART2_SMALL "," MTDPARTS_PART4
#define MTDPARTS_UBIONLY_LARGE	"setenv mtdparts mtdparts=" MTDPARTS_PART1_LARGE "," MTDPARTS_PART2_LARGE "," MTDPARTS_PART4


/************************************************************************
 * Environment
 ************************************************************************/
#define CONFIG_ENV_IS_IN_NAND		/* Environment is in NAND flash */
#define CONFIG_ENV_OVERWRITE		/* Allow overwriting serial/ethaddr */
#define CONFIG_SYS_CONSOLE_IS_IN_ENV	/* Console can be saved in env */

/* Environment settings for small blocks (16KB) */
#define ENV_SIZE_DEF_SMALL   0x00004000	  /* 1 block = 16KB */
#define ENV_RANGE_DEF_SMALL  0x00008000   /* 2 blocks = 32KB */
#define ENV_OFFSET_DEF_SMALL 0x00078000	  /* See NAND layout above */

/* Environment settings for large blocks (128KB); we keep the size as more
   just wastes malloc space (the environment is held in the heap) */
#define ENV_SIZE_DEF_LARGE   0x00004000	  /* Also 16KB */
#define ENV_RANGE_DEF_LARGE  0x00040000   /* 2 blocks = 256KB */
#define ENV_OFFSET_DEF_LARGE 0x000C0000	  /* See NAND layout above */

/* When saving the environment, we usually have a short period of time between
   erasing the NAND region and writing the new data where no valid environment
   is available. To avoid this time, we can save the environment alternatively
   to two different locations in the NAND flash. Then at least one of the
   environments is always valid. Currently we don't use this feature. */
//#define CONFIG_SYS_ENV_OFFSET_REDUND   0x0007c000

//#define CONFIG_ETHADDR_BASE	00:05:51:05:2a:73
#define CONFIG_ETHADDR		00:05:51:05:2a:73
#define CONFIG_ETH1ADDR		00:05:51:05:2a:74
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		10.0.0.252
#define CONFIG_SERVERIP		10.0.0.122
#define CONFIG_GATEWAYIP	10.0.0.5
#define CONFIG_BOOTFILE		"zImage"
#define CONFIG_ROOTPATH		"/rootfs"
#define CONFIG_MODE		"ro"
#define CONFIG_BOOTDELAY	undef
#define CONFIG_PREBOOT
#define CONFIG_BOOTARGS		"undef"
#define CONFIG_BOOTCOMMAND	"run set_bootargs; run kernel; bootz"

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
	"_kernel_ubifs=setenv kernel ubi part TargetFS\\\\; ubifsmount rootfs\\\\; ubifsload . /boot/${bootfile}\\\\; bootz\0"
#else
#define EXTRA_UBIFS
#endif
#define EXTRA_UBI EXTRA_UBIFS \
	"_mtdparts_ubionly=undef\0" \
	"_rootfs_ubifs=setenv rootfs rootfstype=ubifs ubi.mtd=TargetFS root=ubi0:rootfs\0" \
	"_kernel_ubi=setenv kernel ubi part TargetFS\\\\; ubi read . kernel\0" \
	"_ubivol_std=ubi part TargetFS; ubi create rootfs\0" \
	"_ubivol_ubi=ubi part TargetFS; ubi create kernel 400000 s; ubi create rootfs\0"
#else
#define EXTRA_UBI
#endif

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=undef\0" \
	"_console_none=setenv console\0" \
	"_console_serial=setenv console console=${sercon},${baudrate}\0" \
	"_console_display=setenv console console=/dev/tty1\0" \
	"login=undef\0" \
	"_login_none=setenv login login_tty=null\0" \
	"_login_serial=setenv login login_tty=${sercon},${baudrate}\0" \
	"_login_display=setenv login login_tty=/dev/tty1\0" \
	"mtdparts=undef\0" \
	"_mtdparts_std=undef\0" \
	"_network_off=setenv network\0"					\
	"_network_on=setenv network ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}:${netdev}\0" \
	"_network_dhcp=setenv network ip=dhcp\0" \
	"rootfs=undef\0" \
	"_rootfs_nfs=setenv rootfs root=/dev/nfs nfsroot=${rootpath}\0" \
	"_rootfs_mmc=setenv rootfs root=/dev/mmcblk0p1\0" \
	"_rootfs_usb=setenv rootfs root=/dev/sda1\0" \
	"fsload=undef\0" \
	"_fsload_fat=setenv fsload fatload\0" \
	"_fsload_ext2=setenv fsload ext2load\0" \
	"kernel=undef\0" \
	"_kernel_nand=setenv kernel nboot Kernel\0" \
	"_kernel_tftp=setenv kernel tftpboot . ${bootfile}\0" \
	"_kernel_nfs=setenv kernel nfs . ${serverip}:${rootpath}/${bootfile}\0" \
	"_kernel_mmc=setenv kernel mmc rescan\\\\; ${fsload} mmc 0 . ${bootfile}\0" \
	"_kernel_usb=setenv kernel usb start\\\\; ${fsload} usb 0 . ${bootfile}\0" \
	EXTRA_UBI \
	"mode=undef\0" \
	"_mode_rw=setenv mode rw\0" \
	"_mode_ro=setenv mode ro\0" \
	"netdev=eth0\0" \
	"init=undef\0" \
	"_init_init=setenv init\0" \
	"_init_linuxrc=setenv init init=linuxrc\0" \
	"sercon=undef\0" \
	"installcheck=undef\0" \
	"updatecheck=undef\0" \
	"recovercheck=undef\0" \
	"platform=undef\0" \
	"arch=fss5pv210\0" \
	"set_bootargs=setenv bootargs ${console} ${login} ${mtdparts} ${network} ${rootfs} ${mode} ${init}\0"


/************************************************************************
 * DFU (USB Device Firmware Update, requires USB device support)
 ************************************************************************/
/* ###TODO### */


/************************************************************************
 * Linux Support
 ************************************************************************/
#define CONFIG_ZIMAGE_BOOT
#define CONFIG_IMAGE_BOOT

/* Try to patch serial debug port in image within first 16KB of zImage */
#define CONFIG_SYS_PATCH_TTY	0x4000

/* ATAGs passed to Linux */
#define CONFIG_SETUP_MEMORY_TAGS	/* Memory setup */
#define CONFIG_CMDLINE_TAG		/* Command line */
#undef CONFIG_INITRD_TAG		/* No initrd */


/************************************************************************
 * Tools
 ************************************************************************/
#define CONFIG_ADDFSHEADER


/************************************************************************
 * Libraries
 ************************************************************************/
//#define USE_PRIVATE_LIBGCC
#define CONFIG_SYS_64BIT_VSPRINTF	  /* needed for nand_util.c */
#define CONFIG_USE_ARCH_MEMCPY
#define CONFIG_USE_ARCH_MEMMOVE
#define CONFIG_USE_ARCH_MEMSET
#define CONFIG_USE_ARCH_MEMSET32

#endif /* !__FSS5PV210_CONFIG_H */