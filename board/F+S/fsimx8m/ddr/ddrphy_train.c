/*
 * Copyright 2017 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Generated code from MX8M_DDR_tool
 * Align with uboot-imx_v2017.03_4.9.51_imx8m_ga
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/ddr.h>
#include "ddr.h"

extern void wait_ddrphy_training_complete(void);
void ddr_cfg_phy(void) {
	unsigned int tmp, tmp_t;

	//Init DDRPHY register...
	reg32_write(0x3c080440,0x2);
	reg32_write(0x3c080444,0x3);
	reg32_write(0x3c080448,0x4);
	reg32_write(0x3c08044c,0x5);
	reg32_write(0x3c080450,0x0);
	reg32_write(0x3c080454,0x1);
	reg32_write(0x3c04017c,0x1ff);
	reg32_write(0x3c04057c,0x1ff);
	reg32_write(0x3c04417c,0x1ff);
	reg32_write(0x3c04457c,0x1ff);
	reg32_write(0x3c04817c,0x1ff);
	reg32_write(0x3c04857c,0x1ff);
	reg32_write(0x3c04c17c,0x1ff);
	reg32_write(0x3c04c57c,0x1ff);
	reg32_write(0x3c44017c,0x1ff);
	reg32_write(0x3c44057c,0x1ff);
	reg32_write(0x3c44417c,0x1ff);
	reg32_write(0x3c44457c,0x1ff);
	reg32_write(0x3c44817c,0x1ff);
	reg32_write(0x3c44857c,0x1ff);
	reg32_write(0x3c44c17c,0x1ff);
	reg32_write(0x3c44c57c,0x1ff);
	reg32_write(0x3c000154,0x1ff);
	reg32_write(0x3c004154,0x1ff);
	reg32_write(0x3c008154,0x1ff);
	reg32_write(0x3c00c154,0x1ff);
	reg32_write(0x3c010154,0x1ff);
	reg32_write(0x3c014154,0x1ff);
	reg32_write(0x3c018154,0x1ff);
	reg32_write(0x3c01c154,0x1ff);
	reg32_write(0x3c020154,0x1ff);
	reg32_write(0x3c024154,0x1ff);
	reg32_write(0x3c080314,0x19);
	reg32_write(0x3c480314,0x7);
	reg32_write(0x3c0800b8,0x2);
	reg32_write(0x3c4800b8,0x1);
	reg32_write(0x3c240810,0x0);
	reg32_write(0x3c640810,0x0);
	reg32_write(0x3c080090,0x1ab);
	reg32_write(0x3c0800e8,0x0);
	reg32_write(0x3c480090,0x1ab);
	reg32_write(0x3c0800e8,0x0);
	reg32_write(0x3c080158,0x3);
	reg32_write(0x3c480158,0xa);
	reg32_write(0x3c040134,0xe00);
	reg32_write(0x3c040534,0xe00);
	reg32_write(0x3c044134,0xe00);
	reg32_write(0x3c044534,0xe00);
	reg32_write(0x3c048134,0xe00);
	reg32_write(0x3c048534,0xe00);
	reg32_write(0x3c04c134,0xe00);
	reg32_write(0x3c04c534,0xe00);
	reg32_write(0x3c440134,0xe00);
	reg32_write(0x3c440534,0xe00);
	reg32_write(0x3c444134,0xe00);
	reg32_write(0x3c444534,0xe00);
	reg32_write(0x3c448134,0xe00);
	reg32_write(0x3c448534,0xe00);
	reg32_write(0x3c44c134,0xe00);
	reg32_write(0x3c44c534,0xe00);
	reg32_write(0x3c040124,0xeba);
	reg32_write(0x3c040524,0xeba);
	reg32_write(0x3c044124,0xeba);
	reg32_write(0x3c044524,0xeba);
	reg32_write(0x3c048124,0xeba);
	reg32_write(0x3c048524,0xeba);
	reg32_write(0x3c04c124,0xeba);
	reg32_write(0x3c04c524,0xeba);
	reg32_write(0x3c440124,0xeba);
	reg32_write(0x3c440524,0xeba);
	reg32_write(0x3c444124,0xeba);
	reg32_write(0x3c444524,0xeba);
	reg32_write(0x3c448124,0xeba);
	reg32_write(0x3c448524,0xeba);
	reg32_write(0x3c44c124,0xeba);
	reg32_write(0x3c44c524,0xeba);
	reg32_write(0x3c00010c,0x63);
	reg32_write(0x3c00410c,0x63);
	reg32_write(0x3c00810c,0x63);
	reg32_write(0x3c00c10c,0x63);
	reg32_write(0x3c01010c,0x63);
	reg32_write(0x3c01410c,0x63);
	reg32_write(0x3c01810c,0x63);
	reg32_write(0x3c01c10c,0x63);
	reg32_write(0x3c02010c,0x63);
	reg32_write(0x3c02410c,0x63);
	reg32_write(0x3c080060,0x3);
	reg32_write(0x3c0801d4,0x4);
	reg32_write(0x3c080140,0x0);
	reg32_write(0x3c080020,0x320);
	reg32_write(0x3c480020,0xa7);
	reg32_write(0x3c080220,0x9);
	reg32_write(0x3c0802c8,0xdc);
	reg32_write(0x3c04010c,0x5a1);
	reg32_write(0x3c04050c,0x5a1);
	reg32_write(0x3c04410c,0x5a1);
	reg32_write(0x3c04450c,0x5a1);
	reg32_write(0x3c04810c,0x5a1);
	reg32_write(0x3c04850c,0x5a1);
	reg32_write(0x3c04c10c,0x5a1);
	reg32_write(0x3c04c50c,0x5a1);
	reg32_write(0x3c4802c8,0xdc);
	reg32_write(0x3c44010c,0x5a1);
	reg32_write(0x3c44050c,0x5a1);
	reg32_write(0x3c44410c,0x5a1);
	reg32_write(0x3c44450c,0x5a1);
	reg32_write(0x3c44810c,0x5a1);
	reg32_write(0x3c44850c,0x5a1);
	reg32_write(0x3c44c10c,0x5a1);
	reg32_write(0x3c44c50c,0x5a1);
	reg32_write(0x3c0803e8,0x1);
	reg32_write(0x3c4803e8,0x1);
	reg32_write(0x3c080064,0x1);
	reg32_write(0x3c480064,0x1);
	reg32_write(0x3c0803c0,0x0);
	reg32_write(0x3c0803c4,0x0);
	reg32_write(0x3c0803c8,0x4444);
	reg32_write(0x3c0803cc,0x8888);
	reg32_write(0x3c0803d0,0x5555);
	reg32_write(0x3c0803d4,0x0);
	reg32_write(0x3c0803d8,0x0);
	reg32_write(0x3c0803dc,0xf000);
	reg32_write(0x3c080094,0x0);
	reg32_write(0x3c0800b4,0x0);
	reg32_write(0x3c4800b4,0x0);
	reg32_write(0x3c08031c,0x80);
	reg32_write(0x3c48031c,0x80);
	reg32_write(0x3c080328,0x106);
	reg32_write(0x3c480328,0x106);

	//enable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x0);
	//load the 1D training image
	ddr_load_train_code(FW_1D_IMAGE);

	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54003,0xc80);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54004,0x2);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54005,0x2228);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54006,0x11);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54008,0x131f);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54009,0xc8);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5400b,0x2);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5400d,0x100);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54012,0x110);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54019,0x2dd4);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401a,0x31);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401b,0x4a66);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401c,0x4a08);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401e,0x16);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401f,0x2dd4);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54020,0x31);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54021,0x4a66);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54022,0x4a08);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54024,0x16);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5402b,0x1000);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5402c,0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54032,0xd400);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54033,0x312d);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54034,0x6600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54035,0x84a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54036,0x4a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54037,0x1600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54038,0xd400);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54039,0x312d);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403a,0x6600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403b,0x84a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403c,0x4a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403d,0x1600);

	//disable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x1);
	//Reset MPU and run
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x9);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x0);
	wait_ddrphy_training_complete();

	//configure DDRPHY-FW DMEM structure @clock1...
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x1);

	//set the PHY input clock to the desired frequency for pstate 1
	reg32_write(0x3038a088,0x7070000);
	reg32_write(0x3038a084,0x4030000);
	reg32_write(0x303a00ec,0xffff);
	tmp=reg32_read(0x303a00f8);
	tmp |= 0x20;
	reg32_write(0x303a00f8,tmp);
	reg32_write(0x30360068,0xf5a406);
	tmp=reg32_read(0x30360060);
	tmp &= ~0x80;
	reg32_write(0x30360060,tmp);
	tmp=reg32_read(0x30360060);
	tmp |= 0x200;
	reg32_write(0x30360060,tmp);
	tmp=reg32_read(0x30360060);
	tmp &= ~0x20;
	reg32_write(0x30360060,tmp);
	tmp=reg32_read(0x30360060);
	tmp &= ~0x10;
	reg32_write(0x30360060,tmp);
	do{
		tmp=reg32_read(0x30360060);
		if(tmp&0x80000000) break;
	}while(1);
	reg32_write(0x30389808,0x1000000);

	//enable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x0);
	//load the 1D training image
	ddr_load_train_code(FW_1D_IMAGE);

	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54002,0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54003,0x29c);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54004,0x2);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54005,0x2228);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54006,0x11);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54008,0x121f);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54009,0xc8);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5400b,0x2);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5400d,0x100);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54012,0x110);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54019,0x994);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401a,0x31);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401b,0x4a66);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401c,0x4a08);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401e,0x16);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401f,0x994);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54020,0x31);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54021,0x4a66);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54022,0x4a08);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54024,0x16);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5402b,0x1000);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5402c,0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54032,0x9400);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54033,0x3109);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54034,0x6600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54035,0x84a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54036,0x4a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54037,0x1600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54038,0x9400);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54039,0x3109);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403a,0x6600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403b,0x84a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403c,0x4a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403d,0x1600);

	//disable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x1);
	//Reset MPU and run
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x9);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x0);
	wait_ddrphy_training_complete();

	//set the PHY input clock to the desired frequency for pstate 0
	reg32_write(0x3038a088,0x7070000);
	reg32_write(0x3038a084,0x4030000);
	reg32_write(0x303a00ec,0xffff);
	tmp=reg32_read(0x303a00f8);
	tmp |= 0x20;
	reg32_write(0x303a00f8,tmp);
	reg32_write(0x30360068,0xece580);
	tmp=reg32_read(0x30360060);
	tmp &= ~0x80;
	reg32_write(0x30360060,tmp);
	tmp=reg32_read(0x30360060);
	tmp |= 0x200;
	reg32_write(0x30360060,tmp);
	tmp=reg32_read(0x30360060);
	tmp &= ~0x20;
	reg32_write(0x30360060,tmp);
	tmp=reg32_read(0x30360060);
	tmp &= ~0x10;
	reg32_write(0x30360060,tmp);
	do{
		tmp=reg32_read(0x30360060);
		if(tmp&0x80000000) break;
	}while(1);
	reg32_write(0x30389808,0x1000000);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x1);


	//enable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x0);
	//load the 2D training image
	ddr_load_train_code(FW_2D_IMAGE);

	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54003,0xc80);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54004,0x2);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54005,0x2228);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54006,0x11);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54008,0x61);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54009,0xc8);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5400b,0x2);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5400f,0x100);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54010,0x1f7f);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54012,0x110);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54019,0x2dd4);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401a,0x31);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401b,0x4a66);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401c,0x4a08);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401e,0x16);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5401f,0x2dd4);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54020,0x31);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54021,0x4a66);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54022,0x4a08);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54024,0x16);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5402b,0x1000);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5402c,0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54032,0xd400);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54033,0x312d);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54034,0x6600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54035,0x84a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54036,0x4a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54037,0x1600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54038,0xd400);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x54039,0x312d);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403a,0x6600);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403b,0x84a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403c,0x4a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x5403d,0x1600);

	//disable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x1);
	//Reset MPU and run
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x9);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x1);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x0);
	wait_ddrphy_training_complete();

	//Halt MPU
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0099, 0x1);
	//enable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x0);

	//Load firmware PIE image
	reg32_write(0x3c240000,0x10);
	reg32_write(0x3c240004,0x400);
	reg32_write(0x3c240008,0x10e);
	reg32_write(0x3c24000c,0x0);
	reg32_write(0x3c240010,0x0);
	reg32_write(0x3c240014,0x8);
	reg32_write(0x3c2400a4,0xb);
	reg32_write(0x3c2400a8,0x480);
	reg32_write(0x3c2400ac,0x109);
	reg32_write(0x3c2400b0,0x8);
	reg32_write(0x3c2400b4,0x448);
	reg32_write(0x3c2400b8,0x139);
	reg32_write(0x3c2400bc,0x8);
	reg32_write(0x3c2400c0,0x478);
	reg32_write(0x3c2400c4,0x109);
	reg32_write(0x3c2400c8,0x0);
	reg32_write(0x3c2400cc,0xe8);
	reg32_write(0x3c2400d0,0x109);
	reg32_write(0x3c2400d4,0x2);
	reg32_write(0x3c2400d8,0x10);
	reg32_write(0x3c2400dc,0x139);
	reg32_write(0x3c2400e0,0xf);
	reg32_write(0x3c2400e4,0x7c0);
	reg32_write(0x3c2400e8,0x139);
	reg32_write(0x3c2400ec,0x44);
	reg32_write(0x3c2400f0,0x630);
	reg32_write(0x3c2400f4,0x159);
	reg32_write(0x3c2400f8,0x14f);
	reg32_write(0x3c2400fc,0x630);
	reg32_write(0x3c240100,0x159);
	reg32_write(0x3c240104,0x47);
	reg32_write(0x3c240108,0x630);
	reg32_write(0x3c24010c,0x149);
	reg32_write(0x3c240110,0x4f);
	reg32_write(0x3c240114,0x630);
	reg32_write(0x3c240118,0x179);
	reg32_write(0x3c24011c,0x8);
	reg32_write(0x3c240120,0xe0);
	reg32_write(0x3c240124,0x109);
	reg32_write(0x3c240128,0x0);
	reg32_write(0x3c24012c,0x7c8);
	reg32_write(0x3c240130,0x109);
	reg32_write(0x3c240134,0x0);
	reg32_write(0x3c240138,0x1);
	reg32_write(0x3c24013c,0x8);
	reg32_write(0x3c240140,0x0);
	reg32_write(0x3c240144,0x45a);
	reg32_write(0x3c240148,0x9);
	reg32_write(0x3c24014c,0x0);
	reg32_write(0x3c240150,0x448);
	reg32_write(0x3c240154,0x109);
	reg32_write(0x3c240158,0x40);
	reg32_write(0x3c24015c,0x630);
	reg32_write(0x3c240160,0x179);
	reg32_write(0x3c240164,0x1);
	reg32_write(0x3c240168,0x618);
	reg32_write(0x3c24016c,0x109);
	reg32_write(0x3c240170,0x40c0);
	reg32_write(0x3c240174,0x630);
	reg32_write(0x3c240178,0x149);
	reg32_write(0x3c24017c,0x8);
	reg32_write(0x3c240180,0x4);
	reg32_write(0x3c240184,0x48);
	reg32_write(0x3c240188,0x4040);
	reg32_write(0x3c24018c,0x630);
	reg32_write(0x3c240190,0x149);
	reg32_write(0x3c240194,0x0);
	reg32_write(0x3c240198,0x4);
	reg32_write(0x3c24019c,0x48);
	reg32_write(0x3c2401a0,0x40);
	reg32_write(0x3c2401a4,0x630);
	reg32_write(0x3c2401a8,0x149);
	reg32_write(0x3c2401ac,0x10);
	reg32_write(0x3c2401b0,0x4);
	reg32_write(0x3c2401b4,0x18);
	reg32_write(0x3c2401b8,0x0);
	reg32_write(0x3c2401bc,0x4);
	reg32_write(0x3c2401c0,0x78);
	reg32_write(0x3c2401c4,0x549);
	reg32_write(0x3c2401c8,0x630);
	reg32_write(0x3c2401cc,0x159);
	reg32_write(0x3c2401d0,0xd49);
	reg32_write(0x3c2401d4,0x630);
	reg32_write(0x3c2401d8,0x159);
	reg32_write(0x3c2401dc,0x94a);
	reg32_write(0x3c2401e0,0x630);
	reg32_write(0x3c2401e4,0x159);
	reg32_write(0x3c2401e8,0x441);
	reg32_write(0x3c2401ec,0x630);
	reg32_write(0x3c2401f0,0x149);
	reg32_write(0x3c2401f4,0x42);
	reg32_write(0x3c2401f8,0x630);
	reg32_write(0x3c2401fc,0x149);
	reg32_write(0x3c240200,0x1);
	reg32_write(0x3c240204,0x630);
	reg32_write(0x3c240208,0x149);
	reg32_write(0x3c24020c,0x0);
	reg32_write(0x3c240210,0xe0);
	reg32_write(0x3c240214,0x109);
	reg32_write(0x3c240218,0xa);
	reg32_write(0x3c24021c,0x10);
	reg32_write(0x3c240220,0x109);
	reg32_write(0x3c240224,0x9);
	reg32_write(0x3c240228,0x3c0);
	reg32_write(0x3c24022c,0x149);
	reg32_write(0x3c240230,0x9);
	reg32_write(0x3c240234,0x3c0);
	reg32_write(0x3c240238,0x159);
	reg32_write(0x3c24023c,0x18);
	reg32_write(0x3c240240,0x10);
	reg32_write(0x3c240244,0x109);
	reg32_write(0x3c240248,0x0);
	reg32_write(0x3c24024c,0x3c0);
	reg32_write(0x3c240250,0x109);
	reg32_write(0x3c240254,0x18);
	reg32_write(0x3c240258,0x4);
	reg32_write(0x3c24025c,0x48);
	reg32_write(0x3c240260,0x18);
	reg32_write(0x3c240264,0x4);
	reg32_write(0x3c240268,0x58);
	reg32_write(0x3c24026c,0xa);
	reg32_write(0x3c240270,0x10);
	reg32_write(0x3c240274,0x109);
	reg32_write(0x3c240278,0x2);
	reg32_write(0x3c24027c,0x10);
	reg32_write(0x3c240280,0x109);
	reg32_write(0x3c240284,0x5);
	reg32_write(0x3c240288,0x7c0);
	reg32_write(0x3c24028c,0x109);
	reg32_write(0x3c240290,0x10);
	reg32_write(0x3c240294,0x10);
	reg32_write(0x3c240298,0x109);
	reg32_write(0x3c100000,0x811);
	reg32_write(0x3c100080,0x880);
	reg32_write(0x3c100100,0x0);
	reg32_write(0x3c100180,0x0);
	reg32_write(0x3c100004,0x4008);
	reg32_write(0x3c100084,0x83);
	reg32_write(0x3c100104,0x4f);
	reg32_write(0x3c100184,0x0);
	reg32_write(0x3c100008,0x4040);
	reg32_write(0x3c100088,0x83);
	reg32_write(0x3c100108,0x51);
	reg32_write(0x3c100188,0x0);
	reg32_write(0x3c10000c,0x811);
	reg32_write(0x3c10008c,0x880);
	reg32_write(0x3c10010c,0x0);
	reg32_write(0x3c10018c,0x0);
	reg32_write(0x3c100010,0x720);
	reg32_write(0x3c100090,0xf);
	reg32_write(0x3c100110,0x1740);
	reg32_write(0x3c100190,0x0);
	reg32_write(0x3c100014,0x16);
	reg32_write(0x3c100094,0x83);
	reg32_write(0x3c100114,0x4b);
	reg32_write(0x3c100194,0x0);
	reg32_write(0x3c100018,0x716);
	reg32_write(0x3c100098,0xf);
	reg32_write(0x3c100118,0x2001);
	reg32_write(0x3c100198,0x0);
	reg32_write(0x3c10001c,0x716);
	reg32_write(0x3c10009c,0xf);
	reg32_write(0x3c10011c,0x2800);
	reg32_write(0x3c10019c,0x0);
	reg32_write(0x3c100020,0x716);
	reg32_write(0x3c1000a0,0xf);
	reg32_write(0x3c100120,0xf00);
	reg32_write(0x3c1001a0,0x0);
	reg32_write(0x3c100024,0x720);
	reg32_write(0x3c1000a4,0xf);
	reg32_write(0x3c100124,0x1400);
	reg32_write(0x3c1001a4,0x0);
	reg32_write(0x3c100028,0xe08);
	reg32_write(0x3c1000a8,0xc15);
	reg32_write(0x3c100128,0x0);
	reg32_write(0x3c1001a8,0x0);
	reg32_write(0x3c10002c,0x623);
	reg32_write(0x3c1000ac,0x15);
	reg32_write(0x3c10012c,0x0);
	reg32_write(0x3c1001ac,0x0);
	reg32_write(0x3c100030,0x4028);
	reg32_write(0x3c1000b0,0x80);
	reg32_write(0x3c100130,0x0);
	reg32_write(0x3c1001b0,0x0);
	reg32_write(0x3c100034,0xe08);
	reg32_write(0x3c1000b4,0xc1a);
	reg32_write(0x3c100134,0x0);
	reg32_write(0x3c1001b4,0x0);
	reg32_write(0x3c100038,0x623);
	reg32_write(0x3c1000b8,0x1a);
	reg32_write(0x3c100138,0x0);
	reg32_write(0x3c1001b8,0x0);
	reg32_write(0x3c10003c,0x4040);
	reg32_write(0x3c1000bc,0x80);
	reg32_write(0x3c10013c,0x0);
	reg32_write(0x3c1001bc,0x0);
	reg32_write(0x3c100040,0x2604);
	reg32_write(0x3c1000c0,0x15);
	reg32_write(0x3c100140,0x0);
	reg32_write(0x3c1001c0,0x0);
	reg32_write(0x3c100044,0x708);
	reg32_write(0x3c1000c4,0x5);
	reg32_write(0x3c100144,0x0);
	reg32_write(0x3c1001c4,0x2002);
	reg32_write(0x3c100048,0x8);
	reg32_write(0x3c1000c8,0x80);
	reg32_write(0x3c100148,0x0);
	reg32_write(0x3c1001c8,0x0);
	reg32_write(0x3c10004c,0x2604);
	reg32_write(0x3c1000cc,0x1a);
	reg32_write(0x3c10014c,0x0);
	reg32_write(0x3c1001cc,0x0);
	reg32_write(0x3c100050,0x708);
	reg32_write(0x3c1000d0,0xa);
	reg32_write(0x3c100150,0x0);
	reg32_write(0x3c1001d0,0x2002);
	reg32_write(0x3c100054,0x4040);
	reg32_write(0x3c1000d4,0x80);
	reg32_write(0x3c100154,0x0);
	reg32_write(0x3c1001d4,0x0);
	reg32_write(0x3c100058,0x60a);
	reg32_write(0x3c1000d8,0x15);
	reg32_write(0x3c100158,0x1200);
	reg32_write(0x3c1001d8,0x0);
	reg32_write(0x3c10005c,0x61a);
	reg32_write(0x3c1000dc,0x15);
	reg32_write(0x3c10015c,0x1300);
	reg32_write(0x3c1001dc,0x0);
	reg32_write(0x3c100060,0x60a);
	reg32_write(0x3c1000e0,0x1a);
	reg32_write(0x3c100160,0x1200);
	reg32_write(0x3c1001e0,0x0);
	reg32_write(0x3c100064,0x642);
	reg32_write(0x3c1000e4,0x1a);
	reg32_write(0x3c100164,0x1300);
	reg32_write(0x3c1001e4,0x0);
	reg32_write(0x3c100068,0x4808);
	reg32_write(0x3c1000e8,0x880);
	reg32_write(0x3c100168,0x0);
	reg32_write(0x3c1001e8,0x0);
	reg32_write(0x3c24029c,0x0);
	reg32_write(0x3c2402a0,0x790);
	reg32_write(0x3c2402a4,0x11a);
	reg32_write(0x3c2402a8,0x8);
	reg32_write(0x3c2402ac,0x7aa);
	reg32_write(0x3c2402b0,0x2a);
	reg32_write(0x3c2402b4,0x10);
	reg32_write(0x3c2402b8,0x7b2);
	reg32_write(0x3c2402bc,0x2a);
	reg32_write(0x3c2402c0,0x0);
	reg32_write(0x3c2402c4,0x7c8);
	reg32_write(0x3c2402c8,0x109);
	reg32_write(0x3c2402cc,0x10);
	reg32_write(0x3c2402d0,0x2a8);
	reg32_write(0x3c2402d4,0x129);
	reg32_write(0x3c2402d8,0x8);
	reg32_write(0x3c2402dc,0x370);
	reg32_write(0x3c2402e0,0x129);
	reg32_write(0x3c2402e4,0xa);
	reg32_write(0x3c2402e8,0x3c8);
	reg32_write(0x3c2402ec,0x1a9);
	reg32_write(0x3c2402f0,0xc);
	reg32_write(0x3c2402f4,0x408);
	reg32_write(0x3c2402f8,0x199);
	reg32_write(0x3c2402fc,0x14);
	reg32_write(0x3c240300,0x790);
	reg32_write(0x3c240304,0x11a);
	reg32_write(0x3c240308,0x8);
	reg32_write(0x3c24030c,0x4);
	reg32_write(0x3c240310,0x18);
	reg32_write(0x3c240314,0xe);
	reg32_write(0x3c240318,0x408);
	reg32_write(0x3c24031c,0x199);
	reg32_write(0x3c240320,0x8);
	reg32_write(0x3c240324,0x8568);
	reg32_write(0x3c240328,0x108);
	reg32_write(0x3c24032c,0x18);
	reg32_write(0x3c240330,0x790);
	reg32_write(0x3c240334,0x16a);
	reg32_write(0x3c240338,0x8);
	reg32_write(0x3c24033c,0x1d8);
	reg32_write(0x3c240340,0x169);
	reg32_write(0x3c240344,0x10);
	reg32_write(0x3c240348,0x8558);
	reg32_write(0x3c24034c,0x168);
	reg32_write(0x3c240350,0x70);
	reg32_write(0x3c240354,0x788);
	reg32_write(0x3c240358,0x16a);
	reg32_write(0x3c24035c,0x1ff8);
	reg32_write(0x3c240360,0x85a8);
	reg32_write(0x3c240364,0x1e8);
	reg32_write(0x3c240368,0x50);
	reg32_write(0x3c24036c,0x798);
	reg32_write(0x3c240370,0x16a);
	reg32_write(0x3c240374,0x60);
	reg32_write(0x3c240378,0x7a0);
	reg32_write(0x3c24037c,0x16a);
	reg32_write(0x3c240380,0x8);
	reg32_write(0x3c240384,0x8310);
	reg32_write(0x3c240388,0x168);
	reg32_write(0x3c24038c,0x8);
	reg32_write(0x3c240390,0xa310);
	reg32_write(0x3c240394,0x168);
	reg32_write(0x3c240398,0xa);
	reg32_write(0x3c24039c,0x408);
	reg32_write(0x3c2403a0,0x169);
	reg32_write(0x3c2403a4,0x6e);
	reg32_write(0x3c2403a8,0x0);
	reg32_write(0x3c2403ac,0x68);
	reg32_write(0x3c2403b0,0x0);
	reg32_write(0x3c2403b4,0x408);
	reg32_write(0x3c2403b8,0x169);
	reg32_write(0x3c2403bc,0x0);
	reg32_write(0x3c2403c0,0x8310);
	reg32_write(0x3c2403c4,0x168);
	reg32_write(0x3c2403c8,0x0);
	reg32_write(0x3c2403cc,0xa310);
	reg32_write(0x3c2403d0,0x168);
	reg32_write(0x3c2403d4,0x1ff8);
	reg32_write(0x3c2403d8,0x85a8);
	reg32_write(0x3c2403dc,0x1e8);
	reg32_write(0x3c2403e0,0x68);
	reg32_write(0x3c2403e4,0x798);
	reg32_write(0x3c2403e8,0x16a);
	reg32_write(0x3c2403ec,0x78);
	reg32_write(0x3c2403f0,0x7a0);
	reg32_write(0x3c2403f4,0x16a);
	reg32_write(0x3c2403f8,0x68);
	reg32_write(0x3c2403fc,0x790);
	reg32_write(0x3c240400,0x16a);
	reg32_write(0x3c240404,0x8);
	reg32_write(0x3c240408,0x8b10);
	reg32_write(0x3c24040c,0x168);
	reg32_write(0x3c240410,0x8);
	reg32_write(0x3c240414,0xab10);
	reg32_write(0x3c240418,0x168);
	reg32_write(0x3c24041c,0xa);
	reg32_write(0x3c240420,0x408);
	reg32_write(0x3c240424,0x169);
	reg32_write(0x3c240428,0x58);
	reg32_write(0x3c24042c,0x0);
	reg32_write(0x3c240430,0x68);
	reg32_write(0x3c240434,0x0);
	reg32_write(0x3c240438,0x408);
	reg32_write(0x3c24043c,0x169);
	reg32_write(0x3c240440,0x0);
	reg32_write(0x3c240444,0x8b10);
	reg32_write(0x3c240448,0x168);
	reg32_write(0x3c24044c,0x0);
	reg32_write(0x3c240450,0xab10);
	reg32_write(0x3c240454,0x168);
	reg32_write(0x3c240458,0x0);
	reg32_write(0x3c24045c,0x1d8);
	reg32_write(0x3c240460,0x169);
	reg32_write(0x3c240464,0x80);
	reg32_write(0x3c240468,0x790);
	reg32_write(0x3c24046c,0x16a);
	reg32_write(0x3c240470,0x18);
	reg32_write(0x3c240474,0x7aa);
	reg32_write(0x3c240478,0x6a);
	reg32_write(0x3c24047c,0xa);
	reg32_write(0x3c240480,0x0);
	reg32_write(0x3c240484,0x1e9);
	reg32_write(0x3c240488,0x8);
	reg32_write(0x3c24048c,0x8080);
	reg32_write(0x3c240490,0x108);
	reg32_write(0x3c240494,0xf);
	reg32_write(0x3c240498,0x408);
	reg32_write(0x3c24049c,0x169);
	reg32_write(0x3c2404a0,0xc);
	reg32_write(0x3c2404a4,0x0);
	reg32_write(0x3c2404a8,0x68);
	reg32_write(0x3c2404ac,0x9);
	reg32_write(0x3c2404b0,0x0);
	reg32_write(0x3c2404b4,0x1a9);
	reg32_write(0x3c2404b8,0x0);
	reg32_write(0x3c2404bc,0x408);
	reg32_write(0x3c2404c0,0x169);
	reg32_write(0x3c2404c4,0x0);
	reg32_write(0x3c2404c8,0x8080);
	reg32_write(0x3c2404cc,0x108);
	reg32_write(0x3c2404d0,0x8);
	reg32_write(0x3c2404d4,0x7aa);
	reg32_write(0x3c2404d8,0x6a);
	reg32_write(0x3c2404dc,0x0);
	reg32_write(0x3c2404e0,0x8568);
	reg32_write(0x3c2404e4,0x108);
	reg32_write(0x3c2404e8,0xb7);
	reg32_write(0x3c2404ec,0x790);
	reg32_write(0x3c2404f0,0x16a);
	reg32_write(0x3c2404f4,0x1f);
	reg32_write(0x3c2404f8,0x0);
	reg32_write(0x3c2404fc,0x68);
	reg32_write(0x3c240500,0x8);
	reg32_write(0x3c240504,0x8558);
	reg32_write(0x3c240508,0x168);
	reg32_write(0x3c24050c,0xf);
	reg32_write(0x3c240510,0x408);
	reg32_write(0x3c240514,0x169);
	reg32_write(0x3c240518,0xc);
	reg32_write(0x3c24051c,0x0);
	reg32_write(0x3c240520,0x68);
	reg32_write(0x3c240524,0x0);
	reg32_write(0x3c240528,0x408);
	reg32_write(0x3c24052c,0x169);
	reg32_write(0x3c240530,0x0);
	reg32_write(0x3c240534,0x8558);
	reg32_write(0x3c240538,0x168);
	reg32_write(0x3c24053c,0x8);
	reg32_write(0x3c240540,0x3c8);
	reg32_write(0x3c240544,0x1a9);
	reg32_write(0x3c240548,0x3);
	reg32_write(0x3c24054c,0x370);
	reg32_write(0x3c240550,0x129);
	reg32_write(0x3c240554,0x20);
	reg32_write(0x3c240558,0x2aa);
	reg32_write(0x3c24055c,0x9);
	reg32_write(0x3c240560,0x0);
	reg32_write(0x3c240564,0x400);
	reg32_write(0x3c240568,0x10e);
	reg32_write(0x3c24056c,0x8);
	reg32_write(0x3c240570,0xe8);
	reg32_write(0x3c240574,0x109);
	reg32_write(0x3c240578,0x0);
	reg32_write(0x3c24057c,0x8140);
	reg32_write(0x3c240580,0x10c);
	reg32_write(0x3c240584,0x10);
	reg32_write(0x3c240588,0x8138);
	reg32_write(0x3c24058c,0x10c);
	reg32_write(0x3c240590,0x8);
	reg32_write(0x3c240594,0x7c8);
	reg32_write(0x3c240598,0x101);
	reg32_write(0x3c24059c,0x8);
	reg32_write(0x3c2405a0,0x0);
	reg32_write(0x3c2405a4,0x8);
	reg32_write(0x3c2405a8,0x8);
	reg32_write(0x3c2405ac,0x448);
	reg32_write(0x3c2405b0,0x109);
	reg32_write(0x3c2405b4,0xf);
	reg32_write(0x3c2405b8,0x7c0);
	reg32_write(0x3c2405bc,0x109);
	reg32_write(0x3c2405c0,0x0);
	reg32_write(0x3c2405c4,0xe8);
	reg32_write(0x3c2405c8,0x109);
	reg32_write(0x3c2405cc,0x47);
	reg32_write(0x3c2405d0,0x630);
	reg32_write(0x3c2405d4,0x109);
	reg32_write(0x3c2405d8,0x8);
	reg32_write(0x3c2405dc,0x618);
	reg32_write(0x3c2405e0,0x109);
	reg32_write(0x3c2405e4,0x8);
	reg32_write(0x3c2405e8,0xe0);
	reg32_write(0x3c2405ec,0x109);
	reg32_write(0x3c2405f0,0x0);
	reg32_write(0x3c2405f4,0x7c8);
	reg32_write(0x3c2405f8,0x109);
	reg32_write(0x3c2405fc,0x8);
	reg32_write(0x3c240600,0x8140);
	reg32_write(0x3c240604,0x10c);
	reg32_write(0x3c240608,0x0);
	reg32_write(0x3c24060c,0x1);
	reg32_write(0x3c240610,0x8);
	reg32_write(0x3c240614,0x8);
	reg32_write(0x3c240618,0x4);
	reg32_write(0x3c24061c,0x8);
	reg32_write(0x3c240620,0x8);
	reg32_write(0x3c240624,0x7c8);
	reg32_write(0x3c240628,0x101);
	reg32_write(0x3c240018,0x0);
	reg32_write(0x3c24001c,0x0);
	reg32_write(0x3c240020,0x8);
	reg32_write(0x3c240024,0x0);
	reg32_write(0x3c240028,0x0);
	reg32_write(0x3c24002c,0x0);
	reg32_write(0x3c34039c,0x400);
	reg32_write(0x3c24005c,0x0);
	reg32_write(0x3c24007c,0x2a);
	reg32_write(0x3c240098,0x6a);
	reg32_write(0x3c100340,0x0);
	reg32_write(0x3c100344,0x101);
	reg32_write(0x3c100348,0x105);
	reg32_write(0x3c10034c,0x107);
	reg32_write(0x3c100350,0x10f);
	reg32_write(0x3c100354,0x202);
	reg32_write(0x3c100358,0x20a);
	reg32_write(0x3c10035c,0x20b);
	reg32_write(0x3c0800e8,0x2);
	reg32_write(0x3c08002c,0x64);
	reg32_write(0x3c080030,0xc8);
	reg32_write(0x3c080034,0x7d0);
	reg32_write(0x3c080038,0x2c);
	reg32_write(0x3c48002c,0x14);
	reg32_write(0x3c480030,0x29);
	reg32_write(0x3c480034,0x1a1);
	reg32_write(0x3c480038,0x10);
	reg32_write(0x3c240030,0x0);
	reg32_write(0x3c240034,0x173);
	reg32_write(0x3c240038,0x60);
	reg32_write(0x3c24003c,0x6110);
	reg32_write(0x3c240040,0x2152);
	reg32_write(0x3c240044,0xdfbd);
	reg32_write(0x3c240048,0x60);
	reg32_write(0x3c24004c,0x6152);
	reg32_write(0x3c080040,0x5a);
	reg32_write(0x3c080044,0x3);
	reg32_write(0x3c480040,0x5a);
	reg32_write(0x3c480044,0x3);
	reg32_write(0x3c100200,0xe0);
	reg32_write(0x3c100204,0x12);
	reg32_write(0x3c100208,0xe0);
	reg32_write(0x3c10020c,0x12);
	reg32_write(0x3c100210,0xe0);
	reg32_write(0x3c100214,0x12);
	reg32_write(0x3c500200,0xe0);
	reg32_write(0x3c500204,0x12);
	reg32_write(0x3c500208,0xe0);
	reg32_write(0x3c50020c,0x12);
	reg32_write(0x3c500210,0xe0);
	reg32_write(0x3c500214,0x12);
	reg32_write(0x3c1003f4,0xf);
	reg32_write(0x3c040044,0x1);
	reg32_write(0x3c040048,0x1);
	reg32_write(0x3c04004c,0x180);
	reg32_write(0x3c040060,0x1);
	reg32_write(0x3c040008,0x6209);
	reg32_write(0x3c0402c8,0x1);
	reg32_write(0x3c0406d0,0x1);
	reg32_write(0x3c040ad0,0x1);
	reg32_write(0x3c040ed0,0x1);
	reg32_write(0x3c0412d0,0x1);
	reg32_write(0x3c0416d0,0x1);
	reg32_write(0x3c041ad0,0x1);
	reg32_write(0x3c041ed0,0x1);
	reg32_write(0x3c0422d0,0x1);
	reg32_write(0x3c044044,0x1);
	reg32_write(0x3c044048,0x1);
	reg32_write(0x3c04404c,0x180);
	reg32_write(0x3c044060,0x1);
	reg32_write(0x3c044008,0x6209);
	reg32_write(0x3c0442c8,0x1);
	reg32_write(0x3c0446d0,0x1);
	reg32_write(0x3c044ad0,0x1);
	reg32_write(0x3c044ed0,0x1);
	reg32_write(0x3c0452d0,0x1);
	reg32_write(0x3c0456d0,0x1);
	reg32_write(0x3c045ad0,0x1);
	reg32_write(0x3c045ed0,0x1);
	reg32_write(0x3c0462d0,0x1);
	reg32_write(0x3c048044,0x1);
	reg32_write(0x3c048048,0x1);
	reg32_write(0x3c04804c,0x180);
	reg32_write(0x3c048060,0x1);
	reg32_write(0x3c048008,0x6209);
	reg32_write(0x3c0482c8,0x1);
	reg32_write(0x3c0486d0,0x1);
	reg32_write(0x3c048ad0,0x1);
	reg32_write(0x3c048ed0,0x1);
	reg32_write(0x3c0492d0,0x1);
	reg32_write(0x3c0496d0,0x1);
	reg32_write(0x3c049ad0,0x1);
	reg32_write(0x3c049ed0,0x1);
	reg32_write(0x3c04a2d0,0x1);
	reg32_write(0x3c04c044,0x1);
	reg32_write(0x3c04c048,0x1);
	reg32_write(0x3c04c04c,0x180);
	reg32_write(0x3c04c060,0x1);
	reg32_write(0x3c04c008,0x6209);
	reg32_write(0x3c04c2c8,0x1);
	reg32_write(0x3c04c6d0,0x1);
	reg32_write(0x3c04cad0,0x1);
	reg32_write(0x3c04ced0,0x1);
	reg32_write(0x3c04d2d0,0x1);
	reg32_write(0x3c04d6d0,0x1);
	reg32_write(0x3c04dad0,0x1);
	reg32_write(0x3c04ded0,0x1);
	reg32_write(0x3c04e2d0,0x1);
	reg32_write(0x3c0800e8,0x2);
	reg32_write(0x3c300200,0x2);
	//customer Post Train
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x00020010, 0x0000006a);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x0002001d, 0x00000001);
	/*
	 * CalBusy.0 =1, indicates the calibrator is actively calibrating.
	 * Wait Calibrating done.
	 */
	tmp_t = 1;
	while(tmp_t) {
		tmp = reg32_read(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x20097);
		tmp_t = tmp & 0x01;
	}
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x0);
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0x2006e, 0x0);
	//disable APB bus to access DDRPHY RAM
	reg32_write(IP2APB_DDRPHY_IPS_BASE_ADDR(0) + 4 * 0xd0000, 0x1);
}