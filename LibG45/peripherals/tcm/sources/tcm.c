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
//* Creation            : MAS   18/03/2004
//*
//*----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "AT91TCM.h"
#include "lib_AT91SAM9264.h"

// Different types of TCM accesses. There are two actually, direct and 
// through AHB
#define	DIRECT_ACCESS	3
#define AHB_ACCESS		4

// Whether to choose SWI or not
#define	WITH_SWI		7
#define	WITHOUT_SWI		8


// ITCM  pointer
void (*START_PTR)(void *);
void (*END_PTR)(void *);
//***********************************************************
// Import ASM functions in "TCM_functions.s"
//***********************************************************

extern void AT91F_WriteITCMRegionRegister(unsigned int);
extern void AT91F_WriteDTCMRegionRegister(unsigned int);
extern void AT91F_WriteITCMRegionRegister_SWI(unsigned int);
extern void AT91F_WriteDTCMRegionRegister_SWI(unsigned int);

//***********************************************************
// Import AT91F_DBGU_Printk in init.c
//***********************************************************
extern void AT91F_DBGU_Printk(char *);

//*----------------------------------------------------------------------------
//* \fn    AT91F_MATRIX_Set_TCM_Size
//* \brief Enable one or more TCM block
//*----------------------------------------------------------------------------
__inline void AT91F_MATRIX_Set_TCM_Size (
        AT91PS_CCFG pCCFG,
        unsigned int tcm_size)
{
    pCCFG->CCFG_TCMR = tcm_size;
}

//*************************************************************
// Fill TCM structure that holds all the information about
// a TCM unit (data or instruction).
//*************************************************************

__inline void AT91F_SetTCMDevice(AT91PS_TCMDevice	ptr_tcm_struct,
								 int 		  *tcm_addr_ptr,
								 int		  *ahb_tcm_addr_ptr,
								 unsigned int tcm_size,
							   	 unsigned int tcm_size_hex,
							   	 unsigned int tcm_block_size,
							   	 unsigned int nb_tcm_blocks)
{
	ptr_tcm_struct->tcm_addr_ptr	    = tcm_addr_ptr;
	ptr_tcm_struct->ahb_tcm_addr_ptr	= ahb_tcm_addr_ptr;
	ptr_tcm_struct->tcm_size		    = tcm_size;
	ptr_tcm_struct->tcm_size_hex	    = tcm_size_hex;
	ptr_tcm_struct->tcm_block_size	    = tcm_block_size;
	ptr_tcm_struct->nb_tcm_blocks	    = nb_tcm_blocks;
}

//************************************************************
// Function         : AT91F_ITCM_MAP
// Treatments       : Maps ITCM region register
// Operations       : Maps the ITCM to enable the core to directly access 
// 					  (without going through AHB) it
//************************************************************
             
void AT91F_ITCM_MAP(unsigned int itcm_size,
					unsigned int map_addr,
					unsigned int swi)
{
	unsigned int ctl_reg = 0x0;
	
	ctl_reg = itcm_size | map_addr | TCM_ENABLE;
	
	if(swi == WITHOUT_SWI)
		AT91F_WriteITCMRegionRegister(ctl_reg);
	if(swi == WITH_SWI)
		AT91F_WriteITCMRegionRegister_SWI(ctl_reg);
		
}
	
//************************************************************
// Function         : AT91F_DTCM_MAP
// Treatments       : Maps DTCM region register
// Operations       : Maps the DTCM to enable the core to 
//					  directly access (without going through 
//					  AHB) it
//************************************************************

void AT91F_DTCM_MAP(unsigned int dtcm_size,
					unsigned int map_addr,
					unsigned int swi)
{
	unsigned int ctl_reg = 0x0;
	
	ctl_reg = dtcm_size | map_addr | TCM_ENABLE;
	
	
	if(swi == WITHOUT_SWI)
		AT91F_WriteDTCMRegionRegister(ctl_reg);
	if(swi == WITH_SWI)
		AT91F_WriteDTCMRegionRegister_SWI(ctl_reg);
}
	


//************************************************************
// Main function : TCM init
//************************************************************

int tcm_init()
{
	char 			empty_pattern = 0x0;
	//int 			index, jndex;
	AT91S_TCMDevice Dtcm, Itcm;
	//AT91S_BENCHDATA BenchStruct;
									  
	
	// Set structure fields for Itcm, Dtcm and BenchStruct
	AT91F_SetTCMDevice(&Dtcm,
			   		   	(int *)DTCM_MAPPING_ADDR,
			   		   	(int *)AHB_DTCM_ADDR,
			   		   	TCM_SIZE_32K,
			   			TCM_SIZE_Hex32K,
			   			TCM_BLOCK_SIZE,
			   			NB_TCM_BLOCKS);

	AT91F_SetTCMDevice(&Itcm,
			   			(int *)ITCM_MAPPING_ADDR,
			   			(int *)AHB_ITCM_ADDR,
			   			TCM_SIZE_32K,
			   			TCM_SIZE_Hex32K,
			   			TCM_BLOCK_SIZE,
			   			NB_TCM_BLOCKS);

	
	// Map both ITCM and DTCM, using CP15 TCM region register, 
	// to enable the core to have direct access to them (without using AHB). 
	// We are in SYS mode so we don't use SWI method.
	AT91F_DTCM_MAP(Dtcm.tcm_size_hex << CP15_TCM_SIZE_OFFSET,(unsigned int)Dtcm.tcm_addr_ptr,WITHOUT_SWI);
	AT91F_ITCM_MAP(Itcm.tcm_size_hex << CP15_TCM_SIZE_OFFSET,(unsigned int)Itcm.tcm_addr_ptr,WITHOUT_SWI);


	// Configure TCMs' sizes in HMATRIX register through MATRIX_TCMR
	AT91F_MATRIX_Set_TCM_Size(AT91C_BASE_CCFG,
							  (Itcm.tcm_size_hex << MATRIX_TCR_ITCM_OFFSET) |
							  (Dtcm.tcm_size_hex << MATRIX_TCR_DTCM_OFFSET));
							  	
	
	//
	return 0;
}
