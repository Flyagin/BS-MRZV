/*------------------------------------------------------------------------------
* 
* 
* Permission to use, copy, modify, and distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.
* 
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
* 
*------------------------------------------------------------------------------
*
* Processor       : at91sam9g45
* File Name       : g45_TCM.c
* Description     : Definition of AT91SAM9G45-BS characteristics, 
                    .
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
*
*000  NEW  18/03/2004    MAS             Creation
*001  NEW  10/06/14   Markovsky A       Modify
*----------------------------------------------------------------------------*/


//#include <stdio.h>
//#include <string.h>
//#include "AT91TCM.h"
//#include "lib_AT91SAM9264.h"
#include "g45_TCM.h"
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
extern inline __arm void AT91F_WriteITCMRegionRegister1(unsigned int);
extern inline __arm void AT91F_WriteDTCMRegionRegister1(unsigned int);
extern inline __arm long AT91F_GetStatusTCMRegister1(void);
extern inline __arm long AT91F_GetStatusTCMRegister2(void);

extern inline __arm long AT91F_GetStatusTCMInstructionRegionRegister(void);
extern inline __arm long AT91F_GetStatusTCMDataRegionRegister(void);

extern void AT91F_WriteDTCMRegionRegister(unsigned int);
extern void AT91F_WriteITCMRegionRegister_SWI(unsigned int);
extern void AT91F_WriteDTCMRegionRegister_SWI(unsigned int);

//..//***********************************************************
//..// Import AT91F_DBGU_Printk in init.c
//..//***********************************************************
//..extern void AT91F_DBGU_Printk(char *);

//*----------------------------------------------------------------------------
//* \fn    AT91F_MATRIX_Set_TCM_Size
//* \brief Enable one or more TCM block
//*----------------------------------------------------------------------------
//..__inline void AT91F_MATRIX_Set_TCM_Size (
//..        AT91PS_CCFG pCCFG,
//..        unsigned int tcm_size)
//..{
//..    pCCFG->CCFG_TCMR = tcm_size;
//..}
inline  __arm void AT91F_MATRIX_Set_TCM_Size (
        AT91PS_MATRIX pCCFG,
        unsigned int tcm_size)
{
    pCCFG->MATRIX_TCMR = AT91C_ITCM_SIZE_32KB|AT91C_TCM_NWS_ONE_WS|AT91C_DTCM_SIZE_32KB;//tcm_size;
}

//*************************************************************
// Fill TCM structure that holds all the information about
// a TCM unit (data or instruction).
//*************************************************************

inline void AT91F_SetTCMDevice(AT91PS_TCMDevice	ptr_tcm_struct,
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
             
 __arm void AT91F_ITCM_MAP(unsigned int itcm_size,
					unsigned int map_addr,
					unsigned int swi)
{
	unsigned int ctl_reg = 0x0;
	
	ctl_reg = itcm_size | map_addr | TCM_ENABLE;
	
	if(swi == WITHOUT_SWI)
		AT91F_WriteITCMRegionRegister1(ctl_reg);//AT91F_WriteITCMRegionRegister(ctl_reg);
		
//.	if(swi == WITH_SWI)
//.		AT91F_WriteITCMRegionRegister_SWI(ctl_reg);
		
}
	
//************************************************************
// Function         : AT91F_DTCM_MAP
// Treatments       : Maps DTCM region register
// Operations       : Maps the DTCM to enable the core to 
//					  directly access (without going through 
//					  AHB) it
//************************************************************

 __arm void AT91F_DTCM_MAP(unsigned int dtcm_size,
					unsigned int map_addr,
					unsigned int swi)
{
	unsigned int ctl_reg = 0x0;
	
	ctl_reg = dtcm_size | map_addr | TCM_ENABLE;
	
	
	if(swi == WITHOUT_SWI)
		AT91F_WriteDTCMRegionRegister1(ctl_reg);
//.	if(swi == WITH_SWI)
//.		AT91F_WriteDTCMRegionRegister_SWI(ctl_reg);
}
	


//************************************************************
// Main function : TCM init
//************************************************************

 __arm int tcm_init()
{
	long i;
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

	i = AT91F_GetStatusTCMRegister1();
	// Map both ITCM and DTCM, using CP15 TCM region register, 
	// to enable the core to have direct access to them (without using AHB). 
	// We are in SYS mode so we don't use SWI method.
	AT91F_DTCM_MAP(Dtcm.tcm_size_hex << CP15_TCM_SIZE_OFFSET,(unsigned int)Dtcm.tcm_addr_ptr,WITHOUT_SWI);
	AT91F_ITCM_MAP(Itcm.tcm_size_hex << CP15_TCM_SIZE_OFFSET,(unsigned int)Itcm.tcm_addr_ptr,WITHOUT_SWI);

// AT91C_MATRIX_TCMR
	// Configure TCMs' sizes in HMATRIX register through MATRIX_TCMR
	AT91F_MATRIX_Set_TCM_Size( AT91C_BASE_MATRIX,//AT91C_BASE_CCFG,
							  (Itcm.tcm_size_hex << MATRIX_TCR_ITCM_OFFSET) 
							  //|(Dtcm.tcm_size_hex << MATRIX_TCR_DTCM_OFFSET)
							  );
							  	
	i = AT91F_GetStatusTCMDataRegionRegister();
	i = AT91F_GetStatusTCMInstructionRegionRegister();
	i = AT91F_GetStatusTCMRegister1();
	//
	return 0;
}
inline __arm void AT91F_WriteITCMRegionRegister1(unsigned int ctl)
{
 	//__asm("MCR p15, 0, ctl, c9, c1, 1");
	__asm("	mcr      p15, 0, %[Rd], c9, c1, 1"
	:[Rd]"+r"(ctl)
	);
	//MCR	p15,0,r0,c9,c1,1
}
inline __arm void AT91F_WriteDTCMRegionRegister1(unsigned int ctl)
{
 	//__asm("MCR p15, 0, ctl, c9, c1, 1");
	__asm("	mcr      p15, 0, %[Rd], c9, c1, 0"
	:[Rd]"+r"(ctl)
	);
	//MCR	p15,0,r0,c9,c1,1
}
inline __arm long AT91F_GetStatusTCMRegister1(void)
{
 	long lV;
	
	__asm("	mrc      p15, 0, %[Rd], c0, c0, 2"
	:[Rd]"=r"(lV)
	);
	//MCR	p15,0,r0,c9,c1,1
	return lV;
}
inline __arm long AT91F_GetStatusTCMDataRegionRegister(void)
{
 	long lV;
	
	__asm("	mrc      p15, 0, %[Rd], c9, c1, 0"
	:[Rd]"+r"(lV)
	);
	//MCR	p15,0,r0,c9,c1,1
	return lV;
}
inline __arm long AT91F_GetStatusTCMInstructionRegionRegister(void)
{
 	long lV;
	
	__asm("	mrc      p15, 0, %[Rd], c9, c1, 1"
	:[Rd]"+r"(lV)
	);
	//MCR	p15,0,r0,c9,c1,1
	return lV;
}


