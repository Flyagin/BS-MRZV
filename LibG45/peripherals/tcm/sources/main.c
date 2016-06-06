//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : main.c
//* Object              : main application written in C
//* Creation            : ODi   06/26/2002
//*
//*----------------------------------------------------------------------------
#include <stdio.h>
#include "AT91SAM9264.h"
#include "lib_AT91SAM9264.h"
#include "mmu.h"
#define AT91C_CLEAR_SCREEN		"\033[2J"
extern void AT91F_DBGU_Printk(char *);


//*----------------------------------------------------------------------------
//* Function Name       : core
//*----------------------------------------------------------------------------
void main(void){


	AT91F_DBGU_Printk(AT91C_CLEAR_SCREEN);

	AT91F_DBGU_Printk("# TCM Init for AT91SAM9G45/M10\n\r");
	AT91F_DBGU_Printk("# Core direct acces to 32Kbytes ITCM @ 0x1000000\n\r");
	AT91F_DBGU_Printk("# Core direct acces to 32Kbytes DTCM @ 0x2000000\n\r");
	AT91F_DBGU_Printk("# You can now load your code in TCM.\n\r");
	AT91F_DBGU_Printk("# ITCM and DTCM are @ 0x100000 and 0x200000 respectively through AHB\n\r");

	tcm_init();

	while(1);

}


