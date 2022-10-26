/*
 * Copyright 2019 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Generated code from MX8M_DDR_tool
 * Align with uboot version:
 * imx_v2018.03_4.14.78_1.0.0_ga ~ imx_v2018.04_4.19.35_1.1.0_ga
 */

#include <linux/kernel.h>
#include <asm/arch/ddr.h>

struct dram_cfg_param ddr_ddrc_cfg[] = {
	/** Initialize DDRC registers **/
	{ 0x3d400304, 0x1 },
	{ 0x3d400030, 0x20 },
	{ 0x3d400000, 0xa1040001 },
	{ 0x3d400064, 0x610040 },
	{ 0x3d4000d0, 0xc00200c5 },
	{ 0x3d4000d4, 0x1000b },
	{ 0x3d4000dc, 0x1d700004 },
	{ 0x3d4000e0, 0x180000 },
	{ 0x3d4000e4, 0x90000 },
	{ 0x3d4000f0, 0x0 },
	{ 0x3d4000f4, 0xee5 },
	{ 0x3d400100, 0xc101b0e },
	{ 0x3d400104, 0x30314 },
	{ 0x3d400108, 0x4060509 },
	{ 0x3d40010c, 0x2006 },
	{ 0x3d400110, 0x6020306 },
	{ 0x3d400114, 0x4040302 },
	{ 0x3d400120, 0x909 },
	{ 0x3d400180, 0x40800020 },
	{ 0x3d400184, 0xc350 },
	{ 0x3d400190, 0x3868203 },
	{ 0x3d400194, 0x20303 },
	{ 0x3d4001b4, 0x603 },
	{ 0x3d400198, 0x7000000 },
	{ 0x3d4001b0, 0x11 },
	{ 0x3d4001a0, 0x400018 },
	{ 0x3d4001a4, 0x5003c },
	{ 0x3d4001a8, 0x80000000 },
	{ 0x3d4001c4, 0x0 },
	{ 0x3d400200, 0x1f },
	{ 0x3d400204, 0x80808 },
	{ 0x3d400208, 0x0 },
	{ 0x3d40020c, 0x0 },
	{ 0x3d400210, 0x1f1f },
	{ 0x3d400214, 0x7070707 },
	{ 0x3d400218, 0xf0f0707 },
	{ 0x3d400240, 0x600060c },
	{ 0x3d400244, 0x1323 },
	{ 0x3d400400, 0x100 },
	{ 0x3d400250, 0x7ab50b07 },
	{ 0x3d400254, 0x22 },
	{ 0x3d40025c, 0x7b00665e },
	{ 0x3d400264, 0xb0000040 },
	{ 0x3d40026c, 0x50000a0c },
	{ 0x3d400300, 0x17 },
	{ 0x3d40036c, 0x10000 },
	{ 0x3d400404, 0x3051 },
	{ 0x3d400408, 0x61d2 },
	{ 0x3d400494, 0xe00 },
	{ 0x3d400498, 0x7ff },
	{ 0x3d40049c, 0xe00 },
	{ 0x3d4004a0, 0x7ff },
	{ 0x3d402064, 0x28001b },
	{ 0x3d4020dc, 0x12200004 },
	{ 0x3d4020e0, 0x0 },
	{ 0x3d402100, 0x7090b07 },
	{ 0x3d402104, 0x20209 },
	{ 0x3d402108, 0x3030407 },
	{ 0x3d40210c, 0x2006 },
	{ 0x3d402110, 0x3020203 },
	{ 0x3d402114, 0x3030202 },
	{ 0x3d402120, 0x909 },
	{ 0x3d402180, 0x40800020 },
	{ 0x3d402190, 0x3818200 },
	{ 0x3d402194, 0x20303 },
	{ 0x3d4021b4, 0x100 },
	{ 0x3d402240, 0x6000604 },
	{ 0x3d4020f4, 0xee5 },
	{ 0x3d400028, 0x1 },
};

/* PHY Initialize Configuration */
struct dram_cfg_param ddr_ddrphy_cfg[] = {
	{ 0x1005f, 0x3ff },
	{ 0x1015f, 0x3ff },
	{ 0x1105f, 0x3ff },
	{ 0x1115f, 0x3ff },
	{ 0x11005f, 0x3ff },
	{ 0x11015f, 0x3ff },
	{ 0x11105f, 0x3ff },
	{ 0x11115f, 0x3ff },
	{ 0x55, 0x3ff },
	{ 0x1055, 0x3ff },
	{ 0x2055, 0x3ff },
	{ 0x3055, 0x3ff },
	{ 0x4055, 0xff },
	{ 0x5055, 0xff },
	{ 0x6055, 0x3ff },
	{ 0x7055, 0x3ff },
	{ 0x8055, 0x3ff },
	{ 0x9055, 0x3ff },
	{ 0x200c5, 0xb },
	{ 0x1200c5, 0x7 },
	{ 0x2002e, 0x1 },
	{ 0x12002e, 0x1 },
	{ 0x20024, 0x0 },
	{ 0x2003a, 0x0 },
	{ 0x120024, 0x0 },
	{ 0x2003a, 0x0 },
	{ 0x20056, 0xa },
	{ 0x120056, 0xa },
	{ 0x1004d, 0x208 },
	{ 0x1014d, 0x208 },
	{ 0x1104d, 0x208 },
	{ 0x1114d, 0x208 },
	{ 0x11004d, 0x208 },
	{ 0x11014d, 0x208 },
	{ 0x11104d, 0x208 },
	{ 0x11114d, 0x208 },
	{ 0x10049, 0xe38 },
	{ 0x10149, 0xe38 },
	{ 0x11049, 0xe38 },
	{ 0x11149, 0xe38 },
	{ 0x110049, 0xe38 },
	{ 0x110149, 0xe38 },
	{ 0x111049, 0xe38 },
	{ 0x111149, 0xe38 },
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
	{ 0x20018, 0x1 },
	{ 0x20075, 0x0 },
	{ 0x20050, 0x0 },
	{ 0x20008, 0x190 },
	{ 0x120008, 0xa7 },
	{ 0x20088, 0x9 },
	{ 0x200b2, 0x32c },
	{ 0x10043, 0x581 },
	{ 0x10143, 0x581 },
	{ 0x11043, 0x581 },
	{ 0x11143, 0x581 },
	{ 0x1200b2, 0x32c },
	{ 0x110043, 0x581 },
	{ 0x110143, 0x581 },
	{ 0x111043, 0x581 },
	{ 0x111143, 0x581 },
	{ 0x200fa, 0x1 },
	{ 0x1200fa, 0x1 },
	{ 0x20019, 0x5 },
	{ 0x120019, 0x5 },
	{ 0x200f0, 0x5555 },
	{ 0x200f1, 0x5555 },
	{ 0x200f2, 0x5555 },
	{ 0x200f3, 0x5555 },
	{ 0x200f4, 0x5555 },
	{ 0x200f5, 0x5555 },
	{ 0x200f6, 0x5555 },
	{ 0x200f7, 0xf000 },
	{ 0x20025, 0x0 },
	{ 0x2007d, 0x212 },
	{ 0x12007d, 0x212 },
	{ 0x2007c, 0x61 },
	{ 0x12007c, 0x61 },
	{ 0x1004a, 0x500 },
	{ 0x1104a, 0x500 },
	{ 0x2002c, 0x0 },
};

/* P0 message block paremeter for training firmware */
struct dram_cfg_param ddr_fsp0_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54003, 0x640 },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x283c },
	{ 0x54006, 0x140 },
	{ 0x54007, 0x1000 },
	{ 0x54008, 0x101 },
	{ 0x5400b, 0x31f },
	{ 0x5400c, 0xc8 },
	{ 0x54012, 0x1 },
	{ 0x5402f, 0x1d70 },
	{ 0x54030, 0x4 },
	{ 0x54031, 0x18 },
	{ 0x5403a, 0x1323 },
	{ 0xd0000, 0x1 },
};


/* P1 message block paremeter for training firmware */
struct dram_cfg_param ddr_fsp1_cfg[] = {
	{ 0xd0000, 0x0 },
	{ 0x54002, 0x1 },
	{ 0x54003, 0x29c },
	{ 0x54004, 0x2 },
	{ 0x54005, 0x283c },
	{ 0x54006, 0x140 },
	{ 0x54007, 0x1000 },
	{ 0x54008, 0x101 },
	{ 0x5400b, 0x21f },
	{ 0x5400c, 0xc8 },
	{ 0x54012, 0x1 },
	{ 0x5402f, 0x1220 },
	{ 0x54030, 0x4 },
	{ 0x5403a, 0x1323 },
	{ 0xd0000, 0x1 },
};

/* DRAM PHY init engine image */
struct dram_cfg_param ddr_phy_pie[] = {
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
	{ 0x90032, 0x2 },
	{ 0x90033, 0x10 },
	{ 0x90034, 0x139 },
	{ 0x90035, 0xb },
	{ 0x90036, 0x7c0 },
	{ 0x90037, 0x139 },
	{ 0x90038, 0x44 },
	{ 0x90039, 0x633 },
	{ 0x9003a, 0x159 },
	{ 0x9003b, 0x14f },
	{ 0x9003c, 0x630 },
	{ 0x9003d, 0x159 },
	{ 0x9003e, 0x47 },
	{ 0x9003f, 0x633 },
	{ 0x90040, 0x149 },
	{ 0x90041, 0x4f },
	{ 0x90042, 0x633 },
	{ 0x90043, 0x179 },
	{ 0x90044, 0x8 },
	{ 0x90045, 0xe0 },
	{ 0x90046, 0x109 },
	{ 0x90047, 0x0 },
	{ 0x90048, 0x7c8 },
	{ 0x90049, 0x109 },
	{ 0x9004a, 0x0 },
	{ 0x9004b, 0x1 },
	{ 0x9004c, 0x8 },
	{ 0x9004d, 0x0 },
	{ 0x9004e, 0x45a },
	{ 0x9004f, 0x9 },
	{ 0x90050, 0x0 },
	{ 0x90051, 0x448 },
	{ 0x90052, 0x109 },
	{ 0x90053, 0x40 },
	{ 0x90054, 0x633 },
	{ 0x90055, 0x179 },
	{ 0x90056, 0x1 },
	{ 0x90057, 0x618 },
	{ 0x90058, 0x109 },
	{ 0x90059, 0x40c0 },
	{ 0x9005a, 0x633 },
	{ 0x9005b, 0x149 },
	{ 0x9005c, 0x8 },
	{ 0x9005d, 0x4 },
	{ 0x9005e, 0x48 },
	{ 0x9005f, 0x4040 },
	{ 0x90060, 0x633 },
	{ 0x90061, 0x149 },
	{ 0x90062, 0x0 },
	{ 0x90063, 0x4 },
	{ 0x90064, 0x48 },
	{ 0x90065, 0x40 },
	{ 0x90066, 0x633 },
	{ 0x90067, 0x149 },
	{ 0x90068, 0x10 },
	{ 0x90069, 0x4 },
	{ 0x9006a, 0x18 },
	{ 0x9006b, 0x0 },
	{ 0x9006c, 0x4 },
	{ 0x9006d, 0x78 },
	{ 0x9006e, 0x549 },
	{ 0x9006f, 0x633 },
	{ 0x90070, 0x159 },
	{ 0x90071, 0xd49 },
	{ 0x90072, 0x633 },
	{ 0x90073, 0x159 },
	{ 0x90074, 0x94a },
	{ 0x90075, 0x633 },
	{ 0x90076, 0x159 },
	{ 0x90077, 0x441 },
	{ 0x90078, 0x633 },
	{ 0x90079, 0x149 },
	{ 0x9007a, 0x42 },
	{ 0x9007b, 0x633 },
	{ 0x9007c, 0x149 },
	{ 0x9007d, 0x1 },
	{ 0x9007e, 0x633 },
	{ 0x9007f, 0x149 },
	{ 0x90080, 0x0 },
	{ 0x90081, 0xe0 },
	{ 0x90082, 0x109 },
	{ 0x90083, 0xa },
	{ 0x90084, 0x10 },
	{ 0x90085, 0x109 },
	{ 0x90086, 0x9 },
	{ 0x90087, 0x3c0 },
	{ 0x90088, 0x149 },
	{ 0x90089, 0x9 },
	{ 0x9008a, 0x3c0 },
	{ 0x9008b, 0x159 },
	{ 0x9008c, 0x18 },
	{ 0x9008d, 0x10 },
	{ 0x9008e, 0x109 },
	{ 0x9008f, 0x0 },
	{ 0x90090, 0x3c0 },
	{ 0x90091, 0x109 },
	{ 0x90092, 0x18 },
	{ 0x90093, 0x4 },
	{ 0x90094, 0x48 },
	{ 0x90095, 0x18 },
	{ 0x90096, 0x4 },
	{ 0x90097, 0x58 },
	{ 0x90098, 0xb },
	{ 0x90099, 0x10 },
	{ 0x9009a, 0x109 },
	{ 0x9009b, 0x1 },
	{ 0x9009c, 0x10 },
	{ 0x9009d, 0x109 },
	{ 0x9009e, 0x5 },
	{ 0x9009f, 0x7c0 },
	{ 0x900a0, 0x109 },
	{ 0x900a1, 0x0 },
	{ 0x900a2, 0x8140 },
	{ 0x900a3, 0x10c },
	{ 0x900a4, 0x10 },
	{ 0x900a5, 0x8138 },
	{ 0x900a6, 0x10c },
	{ 0x900a7, 0x8 },
	{ 0x900a8, 0x7c8 },
	{ 0x900a9, 0x101 },
	{ 0x900aa, 0x8 },
	{ 0x900ab, 0x448 },
	{ 0x900ac, 0x109 },
	{ 0x900ad, 0xf },
	{ 0x900ae, 0x7c0 },
	{ 0x900af, 0x109 },
	{ 0x900b0, 0x47 },
	{ 0x900b1, 0x630 },
	{ 0x900b2, 0x109 },
	{ 0x900b3, 0x8 },
	{ 0x900b4, 0x618 },
	{ 0x900b5, 0x109 },
	{ 0x900b6, 0x8 },
	{ 0x900b7, 0xe0 },
	{ 0x900b8, 0x109 },
	{ 0x900b9, 0x0 },
	{ 0x900ba, 0x7c8 },
	{ 0x900bb, 0x109 },
	{ 0x900bc, 0x8 },
	{ 0x900bd, 0x8140 },
	{ 0x900be, 0x10c },
	{ 0x900bf, 0x0 },
	{ 0x900c0, 0x1 },
	{ 0x900c1, 0x8 },
	{ 0x900c2, 0x8 },
	{ 0x900c3, 0x4 },
	{ 0x900c4, 0x8 },
	{ 0x900c5, 0x8 },
	{ 0x900c6, 0x7c8 },
	{ 0x900c7, 0x101 },
	{ 0x90006, 0x0 },
	{ 0x90007, 0x0 },
	{ 0x90008, 0x8 },
	{ 0x90009, 0x0 },
	{ 0x9000a, 0x0 },
	{ 0x9000b, 0x0 },
	{ 0xd00e7, 0x400 },
	{ 0x90017, 0x0 },
	{ 0x90026, 0x2b },
	{ 0x2000b, 0x32 },
	{ 0x2000c, 0x64 },
	{ 0x2000d, 0x3e8 },
	{ 0x2000e, 0x2c },
	{ 0x12000b, 0x14 },
	{ 0x12000c, 0x26 },
	{ 0x12000d, 0x1a1 },
	{ 0x12000e, 0x10 },
	{ 0x9000c, 0x0 },
	{ 0x9000d, 0x173 },
	{ 0x9000e, 0x60 },
	{ 0x9000f, 0x6110 },
	{ 0x90010, 0x2152 },
	{ 0x90011, 0xdfbd },
	{ 0x90012, 0xffff },
	{ 0x90013, 0x6152 },
	{ 0x20089, 0x1 },
	{ 0x20088, 0x19 },
	{ 0xc0080, 0x0 },
	{ 0xd0000, 0x1 }
};

struct dram_fsp_msg ddr_dram_fsp_msg[] = {
	{
		/* P0 1600mts 1D */
		.drate = 1600,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp0_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp0_cfg),
	},
	{
		/* P1 667mts 1D */
		.drate = 667,
		.fw_type = FW_1D_IMAGE,
		.fsp_cfg = ddr_fsp1_cfg,
		.fsp_cfg_num = ARRAY_SIZE(ddr_fsp1_cfg),
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
	.fsp_table = { 1600, 667, },
};