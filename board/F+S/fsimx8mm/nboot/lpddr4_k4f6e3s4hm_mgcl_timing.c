/*
 * Copyright 2019 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Generated code from MX8M_DDR_tool
 *
 * Align with uboot version:
 * imx_v2019.04_5.4.x and above version
 * For imx_v2018.03_4.14.78_1.0.0_ga ~ imx_v2018.04_4.19.35_1.1.0_ga:
 * please replace #include <asm/arch/ddr.h> with #include <asm/arch/imx8m_ddr.h>
 */

#include <linux/kernel.h>
#include <asm/arch/ddr.h>

static struct dram_cfg_param ddr_ddrc_cfg[] = {
	/** Initialize DDRC registers **/
	{ 0x3d400304, 0x1 },
	{ 0x3d400030, 0x1 },
	{ 0x3d400000, 0xa1080020 },
	{ 0x3d400020, 0x203 },
	{ 0x3d400024, 0x3a980 },
	{ 0x3d400064, 0x5b00d2 },
	{ 0x3d4000d0, 0xc00305ba },
	{ 0x3d4000d4, 0x940000 },
	{ 0x3d4000dc, 0xd4002d },
	{ 0x3d4000e0, 0x310000 },
	{ 0x3d4000e8, 0x66004d },
	{ 0x3d4000ec, 0x16004d },
	{ 0x3d400100, 0x191e1920 },
	{ 0x3d400104, 0x60630 },
	{ 0x3d40010c, 0xb0b000 },
	{ 0x3d400110, 0xe04080e },
	{ 0x3d400114, 0x2040c0c },
	{ 0x3d400118, 0x1010007 },
	{ 0x3d40011c, 0x401 },
	{ 0x3d400130, 0x20600 },
	{ 0x3d400134, 0xc100002 },
	{ 0x3d400138, 0xd8 },
	{ 0x3d400144, 0x96004b },
	{ 0x3d400180, 0x2ee0017 },
	{ 0x3d400184, 0x2605b8e },
	{ 0x3d400188, 0x0 },
	{ 0x3d400190, 0x497820a },
	{ 0x3d400194, 0x80303 },
	{ 0x3d4001b4, 0x170a },
	{ 0x3d4001a0, 0xe0400018 },
	{ 0x3d4001a4, 0xdf00e4 },
	{ 0x3d4001a8, 0x80000000 },
	{ 0x3d4001b0, 0x11 },
	{ 0x3d4001c0, 0x1 },
	{ 0x3d4001c4, 0x1 },
	{ 0x3d4000f4, 0xc99 },
	{ 0x3d400108, 0x70e1617 },
	{ 0x3d400200, 0x1f },
	{ 0x3d40020c, 0x0 },
	{ 0x3d400210, 0x1f1f },
	{ 0x3d400204, 0x80808 },
	{ 0x3d400214, 0x7070707 },
	{ 0x3d400218, 0x7070707 },
	{ 0x3d40021c, 0xf0f },
	{ 0x3d400250, 0x29001701 },
	{ 0x3d400254, 0x2c },
	{ 0x3d40025c, 0x4000030 },
	{ 0x3d400264, 0x900093e7 },
	{ 0x3d40026c, 0x2005574 },
	{ 0x3d400400, 0x111 },
	{ 0x3d400408, 0x72ff },
	{ 0x3d400494, 0x2100e07 },
	{ 0x3d400498, 0x620096 },
	{ 0x3d40049c, 0x1100e07 },
	{ 0x3d4004a0, 0xc8012c },
	{ 0x3d402020, 0x1 },
	{ 0x3d402024, 0x7d00 },
	{ 0x3d402050, 0x20d040 },
	{ 0x3d402064, 0xc001c },
	{ 0x3d4020dc, 0x840000 },
	{ 0x3d4020e0, 0x310000 },
	{ 0x3d4020e8, 0x66004d },
	{ 0x3d4020ec, 0x16004d },
	{ 0x3d402100, 0xa040305 },
	{ 0x3d402104, 0x30407 },
	{ 0x3d402108, 0x203060b },
	{ 0x3d40210c, 0x505000 },
	{ 0x3d402110, 0x2040202 },
	{ 0x3d402114, 0x2030202 },
	{ 0x3d402118, 0x1010004 },
	{ 0x3d40211c, 0x301 },
	{ 0x3d402130, 0x20300 },
	{ 0x3d402134, 0xa100002 },
	{ 0x3d402138, 0x1d },
	{ 0x3d402144, 0x14000a },
	{ 0x3d402180, 0x640004 },
	{ 0x3d402190, 0x3818200 },
	{ 0x3d402194, 0x80303 },
	{ 0x3d4021b4, 0x100 },
	{ 0x3d4020f4, 0xc99 },
	{ 0x3d403020, 0x1 },
	{ 0x3d403024, 0x1f40 },
	{ 0x3d403050, 0x20d040 },
	{ 0x3d403064, 0x30007 },
	{ 0x3d4030dc, 0x840000 },
	{ 0x3d4030e0, 0x310000 },
	{ 0x3d4030e8, 0x66004d },
	{ 0x3d4030ec, 0x16004d },
	{ 0x3d403100, 0xa010102 },
	{ 0x3d403104, 0x30404 },
	{ 0x3d403108, 0x203060b },
	{ 0x3d40310c, 0x505000 },
	{ 0x3d403110, 0x2040202 },
	{ 0x3d403114, 0x2030202 },
	{ 0x3d403118, 0x1010004 },
	{ 0x3d40311c, 0x301 },
	{ 0x3d403130, 0x20300 },
	{ 0x3d403134, 0xa100002 },
	{ 0x3d403138, 0x8 },
	{ 0x3d403144, 0x50003 },
	{ 0x3d403180, 0x190004 },
	{ 0x3d403190, 0x3818200 },
	{ 0x3d403194, 0x80303 },
	{ 0x3d4031b4, 0x100 },
	{ 0x3d4030f4, 0xc99 },
	{ 0x3d400028, 0x0 },
};

/* PHY Initialize Configuration */
static struct dram_cfg_param ddr_ddrphy_cfg[] = {
	{ 0x100a0, 0x0 },
	{ 0x100a1, 0x1 },
	{ 0x100a2, 0x3 },
	{ 0x100a3, 0x2 },
	{ 0x100a4, 0x5 },
	{ 0x100a5, 0x4 },
	{ 0x100a6, 0x7 },
	{ 0x100a7, 0x6 },
	{ 0x110a0, 0x0 },
	{ 0x110a1, 0x1 },
	{ 0x110a2, 0x2 },
	{ 0x110a3, 0x3 },
	{ 0x110a4, 0x4 },
	{ 0x110a5, 0x5 },
	{ 0x110a6, 0x6 },
	{ 0x110a7, 0x7 },
	{ 0x120a0, 0x0 },
	{ 0x120a1, 0x1 },
	{ 0x120a2, 0x2 },
	{ 0x120a3, 0x3 },
	{ 0x120a4, 0x4 },
	{ 0x120a5, 0x5 },
	{ 0x120a6, 0x6 },
	{ 0x120a7, 0x7 },
	{ 0x130a0, 0x0 },
	{ 0x130a1, 0x1 },
	{ 0x130a2, 0x3 },
	{ 0x130a3, 0x4 },
	{ 0x130a4, 0x5 },
	{ 0x130a5, 0x2 },
	{ 0x130a6, 0x6 },
	{ 0x130a7, 0x7 },
	{ 0x1005f, 0x1ff },
	{ 0x1015f, 0x1ff },
	{ 0x1105f, 0x1ff },
	{ 0x1115f, 0x1ff },
	{ 0x1205f, 0x1ff },
	{ 0x1215f, 0x1ff },
	{ 0x1305f, 0x1ff },
	{ 0x1315f, 0x1ff },
	{ 0x11005f, 0x1ff },
	{ 0x11015f, 0x1ff },
	{ 0x11105f, 0x1ff },
	{ 0x11115f, 0x1ff },
	{ 0x11205f, 0x1ff },
	{ 0x11215f, 0x1ff },
	{ 0x11305f, 0x1ff },
	{ 0x11315f, 0x1ff },
	{ 0x21005f, 0x1ff },
	{ 0x21015f, 0x1ff },
	{ 0x21105f, 0x1ff },
	{ 0x21115f, 0x1ff },
	{ 0x21205f, 0x1ff },
	{ 0x21215f, 0x1ff },
	{ 0x21305f, 0x1ff },
	{ 0x21315f, 0x1ff },
	{ 0x55, 0x1ff },
	{ 0x1055, 0x1ff },
	{ 0x2055, 0x1ff },
	{ 0x3055, 0x1ff },
	{ 0x4055, 0x1ff },
	{ 0x5055, 0x1ff },
	{ 0x6055, 0x1ff },
	{ 0x7055, 0x1ff },
	{ 0x8055, 0x1ff },
	{ 0x9055, 0x1ff },
	{ 0x200c5, 0x19 },
	{ 0x1200c5, 0x7 },
	{ 0x2200c5, 0x7 },
	{ 0x2002e, 0x2 },
	{ 0x12002e, 0x2 },
	{ 0x22002e, 0x2 },
	{ 0x90204, 0x0 },
	{ 0x190204, 0x0 },
	{ 0x290204, 0x0 },
	{ 0x20024, 0x1ab },
	{ 0x2003a, 0x0 },
	{ 0x120024, 0x1ab },
	{ 0x2003a, 0x0 },
	{ 0x220024, 0x1ab },
	{ 0x2003a, 0x0 },
	{ 0x20056, 0x3 },
	{ 0x120056, 0x3 },
	{ 0x220056, 0x3 },
	{ 0x1004d, 0xe00 },
	{ 0x1014d, 0xe00 },
	{ 0x1104d, 0xe00 },
	{ 0x1114d, 0xe00 },
	{ 0x1204d, 0xe00 },
	{ 0x1214d, 0xe00 },
	{ 0x1304d, 0xe00 },
	{ 0x1314d, 0xe00 },
	{ 0x11004d, 0xe00 },
	{ 0x11014d, 0xe00 },
	{ 0x11104d, 0xe00 },
	{ 0x11114d, 0xe00 },
	{ 0x11204d, 0xe00 },
	{ 0x11214d, 0xe00 },
	{ 0x11304d, 0xe00 },
	{ 0x11314d, 0xe00 },
	{ 0x21004d, 0xe00 },
	{ 0x21014d, 0xe00 },
	{ 0x21104d, 0xe00 },
	{ 0x21114d, 0xe00 },
	{ 0x21204d, 0xe00 },
	{ 0x21214d, 0xe00 },
	{ 0x21304d, 0xe00 },
	{ 0x21314d, 0xe00 },
	{ 0x10049, 0xeba },
	{ 0x10149, 0xeba },
	{ 0x11049, 0xeba },
	{ 0x11149, 0xeba },
	{ 0x12049, 0xeba },
	{ 0x12149, 0xeba },
	{ 0x13049, 0xeba },
	{ 0x13149, 0xeba },
	{ 0x110049, 0xeba },
	{ 0x110149, 0xeba },
	{ 0x111049, 0xeba },
	{ 0x111149, 0xeba },
	{ 0x112049, 0xeba },
	{ 0x112149, 0xeba },
	{ 0x113049, 0xeba },
	{ 0x113149, 0xeba },
	{ 0x210049, 0xeba },
	{ 0x210149, 0xeba },
	{ 0x211049, 0xeba },
	{ 0x211149, 0xeba },
	{ 0x212049, 0xeba },
	{ 0x212149, 0xeba },
	{ 0x213049, 0xeba },
	{ 0x213149, 0xeba },
	{ 0x43, 0x63 },
	{ 0x1043, 0x63 },
	{ 0x2043, 0x63 },
	{ 0x3043, 0x63 },
	{ 0x4043, 0x63 },
	{ 0x5043, 0x63 },
	{ 0x6043, 0x63 },
	{ 0x7043, 0x63 },
	{ 0x8043, 0x63 },
	{ 0x9043, 0x63 },
	{ 0x20018, 0x3 },
	{ 0x20075, 0x4 },
	{ 0x20050, 0x0 },
	{ 0x20008, 0x2ee },
	{ 0x120008, 0x64 },
	{ 0x220008, 0x19 },
	{ 0x20088, 0x9 },
	{ 0x200b2, 0xdc },
	{ 0x10043, 0x5a1 },
	{ 0x10143, 0x5a1 },
	{ 0x11043, 0x5a1 },
	{ 0x11143, 0x5a1 },
	{ 0x12043, 0x5a1 },
	{ 0x12143, 0x5a1 },
	{ 0x13043, 0x5a1 },
	{ 0x13143, 0x5a1 },
	{ 0x1200b2, 0xdc },
	{ 0x110043, 0x5a1 },
	{ 0x110143, 0x5a1 },
	{ 0x111043, 0x5a1 },
	{ 0x111143, 0x5a1 },
	{ 0x112043, 0x5a1 },
	{ 0x112143, 0x5a1 },
	{ 0x113043, 0x5a1 },
	{ 0x113143, 0x5a1 },
	{ 0x2200b2, 0xdc },
	{ 0x210043, 0x5a1 },
	{ 0x210143, 0x5a1 },
	{ 0x211043, 0x5a1 },
	{ 0x211143, 0x5a1 },
	{ 0x212043, 0x5a1 },
	{ 0x212143, 0x5a1 },
	{ 0x213043, 0x5a1 },
	{ 0x213143, 0x5a1 },
	{ 0x200fa, 0x1 },
	{ 0x1200fa, 0x1 },
	{ 0x2200fa, 0x1 },
	{ 0x20019, 0x1 },
	{ 0x120019, 0x1 },
	{ 0x220019, 0x1 },
	{ 0x200f0, 0x660 },
	{ 0x200f1, 0x0 },
	{ 0x200f2, 0x4444 },
	{ 0x200f3, 0x8888 },
	{ 0x200f4, 0x5665 },
	{ 0x200f5, 0x0 },
	{ 0x200f6, 0x0 },
	{ 0x200f7, 0xf000 },
	{ 0x20025, 0x0 },
	{ 0x2002d, 0x0 },
	{ 0x12002d, 0x0 },
	{ 0x22002d, 0x0 },
	{ 0x200c7, 0x21 },
	{ 0x1200c7, 0x21 },
	{ 0x2200c7, 0x21 },
	{ 0x200ca, 0x24 },
	{ 0x1200ca, 0x24 },
	{ 0x2200ca, 0x24 },
};

/* P0 message block paremeter for training firmware */
static struct dram_cfg_param ddr_fsp0_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54003, 0xbb8 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x11 },
	{ 0x54008, 0x131f },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x54012, 0x110 },
	{ 0x54019, 0x2dd4 },
	{ 0x5401a, 0x31 },
	{ 0x5401b, 0x4d66 },
	{ 0x5401c, 0x4d00 },
	{ 0x5401e, 0x16 },
	{ 0x5401f, 0x2dd4 },
	{ 0x54020, 0x31 },
	{ 0x54021, 0x4d66 },
	{ 0x54022, 0x4d00 },
	{ 0x54024, 0x16 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x1 },
	{ 0x54032, 0xd400 },
	{ 0x54033, 0x312d },
	{ 0x54034, 0x6600 },
	{ 0x54035, 0x4d },
	{ 0x54036, 0x4d },
	{ 0x54037, 0x1600 },
	{ 0x54038, 0xd400 },
	{ 0x54039, 0x312d },
	{ 0x5403a, 0x6600 },
	{ 0x5403b, 0x4d },
	{ 0x5403c, 0x4d },
	{ 0x5403d, 0x1600 },
	{ 0xd0000, 0x1 },
};


/* P1 message block paremeter for training firmware */
static struct dram_cfg_param ddr_fsp1_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54002, 0x101 },
	{ 0x54003, 0x190 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x11 },
	{ 0x54008, 0x121f },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x54012, 0x110 },
	{ 0x54019, 0x84 },
	{ 0x5401a, 0x31 },
	{ 0x5401b, 0x4d66 },
	{ 0x5401c, 0x4d00 },
	{ 0x5401e, 0x16 },
	{ 0x5401f, 0x84 },
	{ 0x54020, 0x31 },
	{ 0x54021, 0x4d66 },
	{ 0x54022, 0x4d00 },
	{ 0x54024, 0x16 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x1 },
	{ 0x54032, 0x8400 },
	{ 0x54033, 0x3100 },
	{ 0x54034, 0x6600 },
	{ 0x54035, 0x4d },
	{ 0x54036, 0x4d },
	{ 0x54037, 0x1600 },
	{ 0x54038, 0x8400 },
	{ 0x54039, 0x3100 },
	{ 0x5403a, 0x6600 },
	{ 0x5403b, 0x4d },
	{ 0x5403c, 0x4d },
	{ 0x5403d, 0x1600 },
	{ 0xd0000, 0x1 },
};


/* P2 message block paremeter for training firmware */
static struct dram_cfg_param ddr_fsp2_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54002, 0x102 },
	{ 0x54003, 0x64 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x11 },
	{ 0x54008, 0x121f },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x54012, 0x110 },
	{ 0x54019, 0x84 },
	{ 0x5401a, 0x31 },
	{ 0x5401b, 0x4d66 },
	{ 0x5401c, 0x4d00 },
	{ 0x5401e, 0x16 },
	{ 0x5401f, 0x84 },
	{ 0x54020, 0x31 },
	{ 0x54021, 0x4d66 },
	{ 0x54022, 0x4d00 },
	{ 0x54024, 0x16 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x1 },
	{ 0x54032, 0x8400 },
	{ 0x54033, 0x3100 },
	{ 0x54034, 0x6600 },
	{ 0x54035, 0x4d },
	{ 0x54036, 0x4d },
	{ 0x54037, 0x1600 },
	{ 0x54038, 0x8400 },
	{ 0x54039, 0x3100 },
	{ 0x5403a, 0x6600 },
	{ 0x5403b, 0x4d },
	{ 0x5403c, 0x4d },
	{ 0x5403d, 0x1600 },
	{ 0xd0000, 0x1 },
};


/* P0 2D message block paremeter for training firmware */
static struct dram_cfg_param ddr_fsp0_2d_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54003, 0xbb8 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x2228 },
	{ 0x54006, 0x11 },
	{ 0x54008, 0x61 },
	{ 0x54009, 0xc8 },
	{ 0x5400b, 0x2 },
	{ 0x5400f, 0x100 },
	{ 0x54010, 0x1f7f },
	{ 0x54012, 0x110 },
	{ 0x54019, 0x2dd4 },
	{ 0x5401a, 0x31 },
	{ 0x5401b, 0x4d66 },
	{ 0x5401c, 0x4d00 },
	{ 0x5401e, 0x16 },
	{ 0x5401f, 0x2dd4 },
	{ 0x54020, 0x31 },
	{ 0x54021, 0x4d66 },
	{ 0x54022, 0x4d00 },
	{ 0x54024, 0x16 },
	{ 0x5402b, 0x1000 },
	{ 0x5402c, 0x1 },
	{ 0x54032, 0xd400 },
	{ 0x54033, 0x312d },
	{ 0x54034, 0x6600 },
	{ 0x54035, 0x4d },
	{ 0x54036, 0x4d },
	{ 0x54037, 0x1600 },
	{ 0x54038, 0xd400 },
	{ 0x54039, 0x312d },
	{ 0x5403a, 0x6600 },
	{ 0x5403b, 0x4d },
	{ 0x5403c, 0x4d },
	{ 0x5403d, 0x1600 },
	{ 0xd0000, 0x1 },
};

/* DRAM PHY init engine image */
static struct dram_cfg_param ddr_phy_pie[] = {
	{ 0xd0000, 0x0 },
	{ 0x90000, 0x10 },
	{ 0x90001, 0x400 },
	{ 0x90002, 0x10e },
	{ 0x90003, 0x0 },
	{ 0x90004, 0x0 },
	{ 0x90005, 0x8 },
	{ 0x90029, 0xb },
	{ 0x9002a, 0x480 },
	{ 0x9002b, 0x109 },
	{ 0x9002c, 0x8 },
	{ 0x9002d, 0x448 },
	{ 0x9002e, 0x139 },
	{ 0x9002f, 0x8 },
	{ 0x90030, 0x478 },
	{ 0x90031, 0x109 },
	{ 0x90032, 0x0 },
	{ 0x90033, 0xe8 },
	{ 0x90034, 0x109 },
	{ 0x90035, 0x2 },
	{ 0x90036, 0x10 },
	{ 0x90037, 0x139 },
	{ 0x90038, 0xf },
	{ 0x90039, 0x7c0 },
	{ 0x9003a, 0x139 },
	{ 0x9003b, 0x44 },
	{ 0x9003c, 0x630 },
	{ 0x9003d, 0x159 },
	{ 0x9003e, 0x14f },
	{ 0x9003f, 0x630 },
	{ 0x90040, 0x159 },
	{ 0x90041, 0x47 },
	{ 0x90042, 0x630 },
	{ 0x90043, 0x149 },
	{ 0x90044, 0x4f },
	{ 0x90045, 0x630 },
	{ 0x90046, 0x179 },
	{ 0x90047, 0x8 },
	{ 0x90048, 0xe0 },
	{ 0x90049, 0x109 },
	{ 0x9004a, 0x0 },
	{ 0x9004b, 0x7c8 },
	{ 0x9004c, 0x109 },
	{ 0x9004d, 0x0 },
	{ 0x9004e, 0x1 },
	{ 0x9004f, 0x8 },
	{ 0x90050, 0x0 },
	{ 0x90051, 0x45a },
	{ 0x90052, 0x9 },
	{ 0x90053, 0x0 },
	{ 0x90054, 0x448 },
	{ 0x90055, 0x109 },
	{ 0x90056, 0x40 },
	{ 0x90057, 0x630 },
	{ 0x90058, 0x179 },
	{ 0x90059, 0x1 },
	{ 0x9005a, 0x618 },
	{ 0x9005b, 0x109 },
	{ 0x9005c, 0x40c0 },
	{ 0x9005d, 0x630 },
	{ 0x9005e, 0x149 },
	{ 0x9005f, 0x8 },
	{ 0x90060, 0x4 },
	{ 0x90061, 0x48 },
	{ 0x90062, 0x4040 },
	{ 0x90063, 0x630 },
	{ 0x90064, 0x149 },
	{ 0x90065, 0x0 },
	{ 0x90066, 0x4 },
	{ 0x90067, 0x48 },
	{ 0x90068, 0x40 },
	{ 0x90069, 0x630 },
	{ 0x9006a, 0x149 },
	{ 0x9006b, 0x10 },
	{ 0x9006c, 0x4 },
	{ 0x9006d, 0x18 },
	{ 0x9006e, 0x0 },
	{ 0x9006f, 0x4 },
	{ 0x90070, 0x78 },
	{ 0x90071, 0x549 },
	{ 0x90072, 0x630 },
	{ 0x90073, 0x159 },
	{ 0x90074, 0xd49 },
	{ 0x90075, 0x630 },
	{ 0x90076, 0x159 },
	{ 0x90077, 0x94a },
	{ 0x90078, 0x630 },
	{ 0x90079, 0x159 },
	{ 0x9007a, 0x441 },
	{ 0x9007b, 0x630 },
	{ 0x9007c, 0x149 },
	{ 0x9007d, 0x42 },
	{ 0x9007e, 0x630 },
	{ 0x9007f, 0x149 },
	{ 0x90080, 0x1 },
	{ 0x90081, 0x630 },
	{ 0x90082, 0x149 },
	{ 0x90083, 0x0 },
	{ 0x90084, 0xe0 },
	{ 0x90085, 0x109 },
	{ 0x90086, 0xa },
	{ 0x90087, 0x10 },
	{ 0x90088, 0x109 },
	{ 0x90089, 0x9 },
	{ 0x9008a, 0x3c0 },
	{ 0x9008b, 0x149 },
	{ 0x9008c, 0x9 },
	{ 0x9008d, 0x3c0 },
	{ 0x9008e, 0x159 },
	{ 0x9008f, 0x18 },
	{ 0x90090, 0x10 },
	{ 0x90091, 0x109 },
	{ 0x90092, 0x0 },
	{ 0x90093, 0x3c0 },
	{ 0x90094, 0x109 },
	{ 0x90095, 0x18 },
	{ 0x90096, 0x4 },
	{ 0x90097, 0x48 },
	{ 0x90098, 0x18 },
	{ 0x90099, 0x4 },
	{ 0x9009a, 0x58 },
	{ 0x9009b, 0xa },
	{ 0x9009c, 0x10 },
	{ 0x9009d, 0x109 },
	{ 0x9009e, 0x2 },
	{ 0x9009f, 0x10 },
	{ 0x900a0, 0x109 },
	{ 0x900a1, 0x5 },
	{ 0x900a2, 0x7c0 },
	{ 0x900a3, 0x109 },
	{ 0x900a4, 0x10 },
	{ 0x900a5, 0x10 },
	{ 0x900a6, 0x109 },
	{ 0x40000, 0x811 },
	{ 0x40020, 0x880 },
	{ 0x40040, 0x0 },
	{ 0x40060, 0x0 },
	{ 0x40001, 0x4008 },
	{ 0x40021, 0x83 },
	{ 0x40041, 0x4f },
	{ 0x40061, 0x0 },
	{ 0x40002, 0x4040 },
	{ 0x40022, 0x83 },
	{ 0x40042, 0x51 },
	{ 0x40062, 0x0 },
	{ 0x40003, 0x811 },
	{ 0x40023, 0x880 },
	{ 0x40043, 0x0 },
	{ 0x40063, 0x0 },
	{ 0x40004, 0x720 },
	{ 0x40024, 0xf },
	{ 0x40044, 0x1740 },
	{ 0x40064, 0x0 },
	{ 0x40005, 0x16 },
	{ 0x40025, 0x83 },
	{ 0x40045, 0x4b },
	{ 0x40065, 0x0 },
	{ 0x40006, 0x716 },
	{ 0x40026, 0xf },
	{ 0x40046, 0x2001 },
	{ 0x40066, 0x0 },
	{ 0x40007, 0x716 },
	{ 0x40027, 0xf },
	{ 0x40047, 0x2800 },
	{ 0x40067, 0x0 },
	{ 0x40008, 0x716 },
	{ 0x40028, 0xf },
	{ 0x40048, 0xf00 },
	{ 0x40068, 0x0 },
	{ 0x40009, 0x720 },
	{ 0x40029, 0xf },
	{ 0x40049, 0x1400 },
	{ 0x40069, 0x0 },
	{ 0x4000a, 0xe08 },
	{ 0x4002a, 0xc15 },
	{ 0x4004a, 0x0 },
	{ 0x4006a, 0x0 },
	{ 0x4000b, 0x623 },
	{ 0x4002b, 0x15 },
	{ 0x4004b, 0x0 },
	{ 0x4006b, 0x0 },
	{ 0x4000c, 0x4028 },
	{ 0x4002c, 0x80 },
	{ 0x4004c, 0x0 },
	{ 0x4006c, 0x0 },
	{ 0x4000d, 0xe08 },
	{ 0x4002d, 0xc1a },
	{ 0x4004d, 0x0 },
	{ 0x4006d, 0x0 },
	{ 0x4000e, 0x623 },
	{ 0x4002e, 0x1a },
	{ 0x4004e, 0x0 },
	{ 0x4006e, 0x0 },
	{ 0x4000f, 0x4040 },
	{ 0x4002f, 0x80 },
	{ 0x4004f, 0x0 },
	{ 0x4006f, 0x0 },
	{ 0x40010, 0x2604 },
	{ 0x40030, 0x15 },
	{ 0x40050, 0x0 },
	{ 0x40070, 0x0 },
	{ 0x40011, 0x708 },
	{ 0x40031, 0x5 },
	{ 0x40051, 0x0 },
	{ 0x40071, 0x2002 },
	{ 0x40012, 0x8 },
	{ 0x40032, 0x80 },
	{ 0x40052, 0x0 },
	{ 0x40072, 0x0 },
	{ 0x40013, 0x2604 },
	{ 0x40033, 0x1a },
	{ 0x40053, 0x0 },
	{ 0x40073, 0x0 },
	{ 0x40014, 0x708 },
	{ 0x40034, 0xa },
	{ 0x40054, 0x0 },
	{ 0x40074, 0x2002 },
	{ 0x40015, 0x4040 },
	{ 0x40035, 0x80 },
	{ 0x40055, 0x0 },
	{ 0x40075, 0x0 },
	{ 0x40016, 0x60a },
	{ 0x40036, 0x15 },
	{ 0x40056, 0x1200 },
	{ 0x40076, 0x0 },
	{ 0x40017, 0x61a },
	{ 0x40037, 0x15 },
	{ 0x40057, 0x1300 },
	{ 0x40077, 0x0 },
	{ 0x40018, 0x60a },
	{ 0x40038, 0x1a },
	{ 0x40058, 0x1200 },
	{ 0x40078, 0x0 },
	{ 0x40019, 0x642 },
	{ 0x40039, 0x1a },
	{ 0x40059, 0x1300 },
	{ 0x40079, 0x0 },
	{ 0x4001a, 0x4808 },
	{ 0x4003a, 0x880 },
	{ 0x4005a, 0x0 },
	{ 0x4007a, 0x0 },
	{ 0x900a7, 0x0 },
	{ 0x900a8, 0x790 },
	{ 0x900a9, 0x11a },
	{ 0x900aa, 0x8 },
	{ 0x900ab, 0x7aa },
	{ 0x900ac, 0x2a },
	{ 0x900ad, 0x10 },
	{ 0x900ae, 0x7b2 },
	{ 0x900af, 0x2a },
	{ 0x900b0, 0x0 },
	{ 0x900b1, 0x7c8 },
	{ 0x900b2, 0x109 },
	{ 0x900b3, 0x10 },
	{ 0x900b4, 0x2a8 },
	{ 0x900b5, 0x129 },
	{ 0x900b6, 0x8 },
	{ 0x900b7, 0x370 },
	{ 0x900b8, 0x129 },
	{ 0x900b9, 0xa },
	{ 0x900ba, 0x3c8 },
	{ 0x900bb, 0x1a9 },
	{ 0x900bc, 0xc },
	{ 0x900bd, 0x408 },
	{ 0x900be, 0x199 },
	{ 0x900bf, 0x14 },
	{ 0x900c0, 0x790 },
	{ 0x900c1, 0x11a },
	{ 0x900c2, 0x8 },
	{ 0x900c3, 0x4 },
	{ 0x900c4, 0x18 },
	{ 0x900c5, 0xe },
	{ 0x900c6, 0x408 },
	{ 0x900c7, 0x199 },
	{ 0x900c8, 0x8 },
	{ 0x900c9, 0x8568 },
	{ 0x900ca, 0x108 },
	{ 0x900cb, 0x18 },
	{ 0x900cc, 0x790 },
	{ 0x900cd, 0x16a },
	{ 0x900ce, 0x8 },
	{ 0x900cf, 0x1d8 },
	{ 0x900d0, 0x169 },
	{ 0x900d1, 0x10 },
	{ 0x900d2, 0x8558 },
	{ 0x900d3, 0x168 },
	{ 0x900d4, 0x70 },
	{ 0x900d5, 0x788 },
	{ 0x900d6, 0x16a },
	{ 0x900d7, 0x1ff8 },
	{ 0x900d8, 0x85a8 },
	{ 0x900d9, 0x1e8 },
	{ 0x900da, 0x50 },
	{ 0x900db, 0x798 },
	{ 0x900dc, 0x16a },
	{ 0x900dd, 0x60 },
	{ 0x900de, 0x7a0 },
	{ 0x900df, 0x16a },
	{ 0x900e0, 0x8 },
	{ 0x900e1, 0x8310 },
	{ 0x900e2, 0x168 },
	{ 0x900e3, 0x8 },
	{ 0x900e4, 0xa310 },
	{ 0x900e5, 0x168 },
	{ 0x900e6, 0xa },
	{ 0x900e7, 0x408 },
	{ 0x900e8, 0x169 },
	{ 0x900e9, 0x6e },
	{ 0x900ea, 0x0 },
	{ 0x900eb, 0x68 },
	{ 0x900ec, 0x0 },
	{ 0x900ed, 0x408 },
	{ 0x900ee, 0x169 },
	{ 0x900ef, 0x0 },
	{ 0x900f0, 0x8310 },
	{ 0x900f1, 0x168 },
	{ 0x900f2, 0x0 },
	{ 0x900f3, 0xa310 },
	{ 0x900f4, 0x168 },
	{ 0x900f5, 0x1ff8 },
	{ 0x900f6, 0x85a8 },
	{ 0x900f7, 0x1e8 },
	{ 0x900f8, 0x68 },
	{ 0x900f9, 0x798 },
	{ 0x900fa, 0x16a },
	{ 0x900fb, 0x78 },
	{ 0x900fc, 0x7a0 },
	{ 0x900fd, 0x16a },
	{ 0x900fe, 0x68 },
	{ 0x900ff, 0x790 },
	{ 0x90100, 0x16a },
	{ 0x90101, 0x8 },
	{ 0x90102, 0x8b10 },
	{ 0x90103, 0x168 },
	{ 0x90104, 0x8 },
	{ 0x90105, 0xab10 },
	{ 0x90106, 0x168 },
	{ 0x90107, 0xa },
	{ 0x90108, 0x408 },
	{ 0x90109, 0x169 },
	{ 0x9010a, 0x58 },
	{ 0x9010b, 0x0 },
	{ 0x9010c, 0x68 },
	{ 0x9010d, 0x0 },
	{ 0x9010e, 0x408 },
	{ 0x9010f, 0x169 },
	{ 0x90110, 0x0 },
	{ 0x90111, 0x8b10 },
	{ 0x90112, 0x168 },
	{ 0x90113, 0x0 },
	{ 0x90114, 0xab10 },
	{ 0x90115, 0x168 },
	{ 0x90116, 0x0 },
	{ 0x90117, 0x1d8 },
	{ 0x90118, 0x169 },
	{ 0x90119, 0x80 },
	{ 0x9011a, 0x790 },
	{ 0x9011b, 0x16a },
	{ 0x9011c, 0x18 },
	{ 0x9011d, 0x7aa },
	{ 0x9011e, 0x6a },
	{ 0x9011f, 0xa },
	{ 0x90120, 0x0 },
	{ 0x90121, 0x1e9 },
	{ 0x90122, 0x8 },
	{ 0x90123, 0x8080 },
	{ 0x90124, 0x108 },
	{ 0x90125, 0xf },
	{ 0x90126, 0x408 },
	{ 0x90127, 0x169 },
	{ 0x90128, 0xc },
	{ 0x90129, 0x0 },
	{ 0x9012a, 0x68 },
	{ 0x9012b, 0x9 },
	{ 0x9012c, 0x0 },
	{ 0x9012d, 0x1a9 },
	{ 0x9012e, 0x0 },
	{ 0x9012f, 0x408 },
	{ 0x90130, 0x169 },
	{ 0x90131, 0x0 },
	{ 0x90132, 0x8080 },
	{ 0x90133, 0x108 },
	{ 0x90134, 0x8 },
	{ 0x90135, 0x7aa },
	{ 0x90136, 0x6a },
	{ 0x90137, 0x0 },
	{ 0x90138, 0x8568 },
	{ 0x90139, 0x108 },
	{ 0x9013a, 0xb7 },
	{ 0x9013b, 0x790 },
	{ 0x9013c, 0x16a },
	{ 0x9013d, 0x1f },
	{ 0x9013e, 0x0 },
	{ 0x9013f, 0x68 },
	{ 0x90140, 0x8 },
	{ 0x90141, 0x8558 },
	{ 0x90142, 0x168 },
	{ 0x90143, 0xf },
	{ 0x90144, 0x408 },
	{ 0x90145, 0x169 },
	{ 0x90146, 0xc },
	{ 0x90147, 0x0 },
	{ 0x90148, 0x68 },
	{ 0x90149, 0x0 },
	{ 0x9014a, 0x408 },
	{ 0x9014b, 0x169 },
	{ 0x9014c, 0x0 },
	{ 0x9014d, 0x8558 },
	{ 0x9014e, 0x168 },
	{ 0x9014f, 0x8 },
	{ 0x90150, 0x3c8 },
	{ 0x90151, 0x1a9 },
	{ 0x90152, 0x3 },
	{ 0x90153, 0x370 },
	{ 0x90154, 0x129 },
	{ 0x90155, 0x20 },
	{ 0x90156, 0x2aa },
	{ 0x90157, 0x9 },
	{ 0x90158, 0x0 },
	{ 0x90159, 0x400 },
	{ 0x9015a, 0x10e },
	{ 0x9015b, 0x8 },
	{ 0x9015c, 0xe8 },
	{ 0x9015d, 0x109 },
	{ 0x9015e, 0x0 },
	{ 0x9015f, 0x8140 },
	{ 0x90160, 0x10c },
	{ 0x90161, 0x10 },
	{ 0x90162, 0x8138 },
	{ 0x90163, 0x10c },
	{ 0x90164, 0x8 },
	{ 0x90165, 0x7c8 },
	{ 0x90166, 0x101 },
	{ 0x90167, 0x8 },
	{ 0x90168, 0x0 },
	{ 0x90169, 0x8 },
	{ 0x9016a, 0x8 },
	{ 0x9016b, 0x448 },
	{ 0x9016c, 0x109 },
	{ 0x9016d, 0xf },
	{ 0x9016e, 0x7c0 },
	{ 0x9016f, 0x109 },
	{ 0x90170, 0x0 },
	{ 0x90171, 0xe8 },
	{ 0x90172, 0x109 },
	{ 0x90173, 0x47 },
	{ 0x90174, 0x630 },
	{ 0x90175, 0x109 },
	{ 0x90176, 0x8 },
	{ 0x90177, 0x618 },
	{ 0x90178, 0x109 },
	{ 0x90179, 0x8 },
	{ 0x9017a, 0xe0 },
	{ 0x9017b, 0x109 },
	{ 0x9017c, 0x0 },
	{ 0x9017d, 0x7c8 },
	{ 0x9017e, 0x109 },
	{ 0x9017f, 0x8 },
	{ 0x90180, 0x8140 },
	{ 0x90181, 0x10c },
	{ 0x90182, 0x0 },
	{ 0x90183, 0x1 },
	{ 0x90184, 0x8 },
	{ 0x90185, 0x8 },
	{ 0x90186, 0x4 },
	{ 0x90187, 0x8 },
	{ 0x90188, 0x8 },
	{ 0x90189, 0x7c8 },
	{ 0x9018a, 0x101 },
	{ 0x90006, 0x0 },
	{ 0x90007, 0x0 },
	{ 0x90008, 0x8 },
	{ 0x90009, 0x0 },
	{ 0x9000a, 0x0 },
	{ 0x9000b, 0x0 },
	{ 0xd00e7, 0x400 },
	{ 0x90017, 0x0 },
	{ 0x9001f, 0x2a },
	{ 0x90026, 0x6a },
	{ 0x400d0, 0x0 },
	{ 0x400d1, 0x101 },
	{ 0x400d2, 0x105 },
	{ 0x400d3, 0x107 },
	{ 0x400d4, 0x10f },
	{ 0x400d5, 0x202 },
	{ 0x400d6, 0x20a },
	{ 0x400d7, 0x20b },
	{ 0x2003a, 0x2 },
	{ 0x2000b, 0x34b },
	{ 0x2000c, 0xbb },
	{ 0x2000d, 0x753 },
	{ 0x2000e, 0x2c },
	{ 0x12000b, 0x70 },
	{ 0x12000c, 0x19 },
	{ 0x12000d, 0xfa },
	{ 0x12000e, 0x10 },
	{ 0x22000b, 0x1c },
	{ 0x22000c, 0x6 },
	{ 0x22000d, 0x3e },
	{ 0x22000e, 0x10 },
	{ 0x9000c, 0x0 },
	{ 0x9000d, 0x173 },
	{ 0x9000e, 0x60 },
	{ 0x9000f, 0x6110 },
	{ 0x90010, 0x2152 },
	{ 0x90011, 0xdfbd },
	{ 0x90012, 0x60 },
	{ 0x90013, 0x6152 },
	{ 0x20010, 0x5a },
	{ 0x20011, 0x3 },
	{ 0x120010, 0x5a },
	{ 0x120011, 0x3 },
	{ 0x220010, 0x5a },
	{ 0x220011, 0x3 },
	{ 0x40080, 0xe0 },
	{ 0x40081, 0x12 },
	{ 0x40082, 0xe0 },
	{ 0x40083, 0x12 },
	{ 0x40084, 0xe0 },
	{ 0x40085, 0x12 },
	{ 0x140080, 0xe0 },
	{ 0x140081, 0x12 },
	{ 0x140082, 0xe0 },
	{ 0x140083, 0x12 },
	{ 0x140084, 0xe0 },
	{ 0x140085, 0x12 },
	{ 0x240080, 0xe0 },
	{ 0x240081, 0x12 },
	{ 0x240082, 0xe0 },
	{ 0x240083, 0x12 },
	{ 0x240084, 0xe0 },
	{ 0x240085, 0x12 },
	{ 0x400fd, 0xf },
	{ 0x10011, 0x1 },
	{ 0x10012, 0x1 },
	{ 0x10013, 0x180 },
	{ 0x10018, 0x1 },
	{ 0x10002, 0x6209 },
	{ 0x100b2, 0x1 },
	{ 0x101b4, 0x1 },
	{ 0x102b4, 0x1 },
	{ 0x103b4, 0x1 },
	{ 0x104b4, 0x1 },
	{ 0x105b4, 0x1 },
	{ 0x106b4, 0x1 },
	{ 0x107b4, 0x1 },
	{ 0x108b4, 0x1 },
	{ 0x11011, 0x1 },
	{ 0x11012, 0x1 },
	{ 0x11013, 0x180 },
	{ 0x11018, 0x1 },
	{ 0x11002, 0x6209 },
	{ 0x110b2, 0x1 },
	{ 0x111b4, 0x1 },
	{ 0x112b4, 0x1 },
	{ 0x113b4, 0x1 },
	{ 0x114b4, 0x1 },
	{ 0x115b4, 0x1 },
	{ 0x116b4, 0x1 },
	{ 0x117b4, 0x1 },
	{ 0x118b4, 0x1 },
	{ 0x12011, 0x1 },
	{ 0x12012, 0x1 },
	{ 0x12013, 0x180 },
	{ 0x12018, 0x1 },
	{ 0x12002, 0x6209 },
	{ 0x120b2, 0x1 },
	{ 0x121b4, 0x1 },
	{ 0x122b4, 0x1 },
	{ 0x123b4, 0x1 },
	{ 0x124b4, 0x1 },
	{ 0x125b4, 0x1 },
	{ 0x126b4, 0x1 },
	{ 0x127b4, 0x1 },
	{ 0x128b4, 0x1 },
	{ 0x13011, 0x1 },
	{ 0x13012, 0x1 },
	{ 0x13013, 0x180 },
	{ 0x13018, 0x1 },
	{ 0x13002, 0x6209 },
	{ 0x130b2, 0x1 },
	{ 0x131b4, 0x1 },
	{ 0x132b4, 0x1 },
	{ 0x133b4, 0x1 },
	{ 0x134b4, 0x1 },
	{ 0x135b4, 0x1 },
	{ 0x136b4, 0x1 },
	{ 0x137b4, 0x1 },
	{ 0x138b4, 0x1 },
	{ 0x2003a, 0x2 },
	{ 0xc0080, 0x2 },
	{ 0xd0000, 0x1 }
};

static struct dram_fsp_msg ddr_dram_fsp_msg[] = {
	{
		/* P0 3000mts 1D */
		.drate = 3000,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp0_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp0_cfg),
	},
	{
		/* P1 400mts 1D */
		.drate = 400,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp1_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp1_cfg),
	},
	{
		/* P2 100mts 1D */
		.drate = 100,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp2_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp2_cfg),
	},
	{
		/* P0 3000mts 2D */
		.drate = 3000,
		.fw_type = FW_2D_IMAGE,
		.fsp_cfg = ddr_fsp0_2d_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp0_2d_cfg),
	},
};

/* ddr timing config params */
struct dram_timing_info dram_timing = {
	.ddrc_cfg = ddr_ddrc_cfg,
	.ddrc_cfg_num = ARRAY_SIZE(ddr_ddrc_cfg),
	.ddrphy_cfg = ddr_ddrphy_cfg,
	.ddrphy_cfg_num = ARRAY_SIZE(ddr_ddrphy_cfg),
	.fsp_msg = ddr_dram_fsp_msg,
	.fsp_msg_num = ARRAY_SIZE(ddr_dram_fsp_msg),
	.ddrphy_trained_csr = NULL,
	.ddrphy_trained_csr_num = 0,
	.ddrphy_pie = ddr_phy_pie,
	.ddrphy_pie_num = ARRAY_SIZE(ddr_phy_pie),
	.fsp_table = { 3000, 400, 100, },
};

