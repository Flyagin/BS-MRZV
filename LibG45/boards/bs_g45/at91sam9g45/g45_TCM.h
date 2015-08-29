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
* File Name       : g45_TCM.h
* Description     : Definition of AT91SAM9G45-BS characteristics, 
                    .
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
*
*000  NEW  31/03/04    MAS             Creation
*000  NEW  10/06/14   Markovsky A       Modify
*----------------------------------------------------------------------------*/

#ifndef _AT91TCM_H
#define	_AT91TCM_H

//#include "AT91SAM9264.h"
#include "AT91SAM9G45.h"//../LibG45/boards/bs_g45/at91sam9g45/

// Base addresses for TCMs and HMATRIX
#define ITCM_MAPPING_ADDR	0x01000000
#define DTCM_MAPPING_ADDR	0x02000000
#define AHB_ITCM_ADDR		0x00100000
#define AHB_DTCM_ADDR		0x00200000
#define AHB_RAMC_ADDR		0x00300000
#define SDRAM_ADDR			0x20000000

// TCM block sizes
#define TCM_BLOCK_SIZE	16384//4096
#define	NO_TCM_MEMORY	0
#define TCM_SIZE_4K		4096
#define	TCM_SIZE_8K		8192
#define	TCM_SIZE_16K	16384
#define	TCM_SIZE_32K	32768
#define	TCM_SIZE_64K	65536
#define	TCM_SIZE_128K	131072
#define NB_TCM_BLOCKS	4


// TCM Enable Flag
#define	TCM_ENABLE		0x1

// Authorised sizes for ITCM and DTCM
#define	TCM_SIZE_Hex4K		0x3
#define	TCM_SIZE_Hex8K		0x4
#define	TCM_SIZE_Hex16K		0x5
#define	TCM_SIZE_Hex32K		0x6
#define	TCM_SIZE_Hex64K		0x7
#define	TCM_SIZE_Hex128K	0x8

// ITCM_SIZE and DTCM_SIZE Offsets for HMATRIX_SFR0 
// and for CP15
#define	MATRIX_TCR_ITCM_OFFSET	0
#define	MATRIX_TCR_DTCM_OFFSET	4
#define	CP15_TCM_SIZE_OFFSET		2

// Flag returned when data is bigger than TCM memory size
#define TCM_MEM_OUT				-1
#define TCM_TRANSFER_CORRUPTED	-2
#define TCM_TRANSFER_OK			 0


// ARM926EJ-S AHB clock ratio
#define	CLOCK_RATIO_0		0x0
#define CLOCK_RATIO_1		0x1
#define CLOCK_RATIO_2		0x2
#define CLOCK_RATIO_3		0x3



// ARM926EJ-S AHB clock ratio offset
#define HMATRIX_SFR0_CLOCK_RATIO_OFFSET		8

/*---------------------------------------------*/
/* Global TCM Descriptor Structure Definition   */
/*---------------------------------------------*/
typedef struct _AT91S_TCMDevice
{
	int 			*tcm_addr_ptr;
    int             *ahb_tcm_addr_ptr;
	unsigned int	tcm_size;
	unsigned int	tcm_size_hex;
	unsigned int	tcm_block_size;
	unsigned int	nb_tcm_blocks;
} AT91S_TCMDevice, *AT91PS_TCMDevice;
	 
#endif


