
/*------------------------------------------------------------------------------
* Created (c) 2015 - Factory “KyivPrylad”
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
* File Name       : gdma.h
* Description     : support for the gdma.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/03/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#ifndef GDMA_h
#define GDMA_h
/*
__no_init volatile union
{
	unsigned short mwctl2;
	struct
	{
	unsigned short edr: 1;
	unsigned short edw: 1;
	unsigned short lee: 2;
	unsigned short lemd: 2;
	unsigned short lepl: 2;
	} mwctl2bit;
} @ 0x1000;*/
typedef void (*PFV)();
__no_init volatile union 
{
	unsigned long HDMA_CH_0_CTRLA_REG;
	struct
	{
		unsigned long BTSIZE   : 16;
		unsigned long SCSIZE   : 3;
		unsigned long reserv1  : 1;
		unsigned long DCSIZE   : 3;
		unsigned long reserv2  : 1;
		unsigned long SRC_WIDTH: 2;
		unsigned long reserv3  : 2;
		unsigned long DST_WIDTH: 2;
		unsigned long reserv4  : 1;
		unsigned long DONE     : 1;
	} HDMA_CH_0_CTRLA_FIELD;
//HDMA_CH_0_CTRLA_UNN
}  @ (0xFFFFEC48);

//DMAC_CTRLBx [x = 0..7]

	
	
	
__no_init volatile union 
{
	unsigned long HDMA_CH_0_CTRLB_REG;
	struct
	{
		unsigned long  SIF          : 02;
		unsigned long  Reserv1      : 02;
		unsigned long  DIF          : 02;
		unsigned long  Reserv2      : 02;
		unsigned long  SRC_PIP      : 01;
		unsigned long  Reserv3      : 03;
		unsigned long  DST_PIP      : 01;
		unsigned long  Reserv4      : 03;
		unsigned long  SRC_DSCR     : 1;
		unsigned long  Reserv5      : 03;
		unsigned long  DST_DSCR     : 1;
		unsigned long  FC           : 03;
		unsigned long  SRC_INCR     : 02;
		unsigned long  Reserv6      : 02;
		unsigned long  DST_INCR     : 02;
		unsigned long  IEN          : 01;
		unsigned long  AUTO         : 01;
	} HDMA_CH_0_CTRLB_FIELD;
//HDMA_CH_0_CTRLB_UNN
}  @ (0xFFFFEC4C);

__no_init volatile union 
{
	unsigned long HDMA_CH_0_CFG_REG;
	struct
	{
		unsigned long  SRC_PER          : 04;
		unsigned long  DST_PER          : 04;
		unsigned long   SRC_REP         : 01;
		unsigned long   SRC_H2SEL       : 01;
		unsigned long  Reserv1          : 02;
		unsigned long  DST_REP          : 01;
		unsigned long  DST_H2SEL        : 01;
		unsigned long  Reserv2          : 02;
		unsigned long  SOD              : 01;
		unsigned long  Reserv3          : 03;
		unsigned long  LOCK_IF          : 01;
		unsigned long  LOCK_B           : 01;
		unsigned long  LOCK_IF_L        : 01;
		unsigned long  Reserv4          : 01;
		unsigned long  AHB_PROT     : 03;
		unsigned long  Reserv5      : 01;
		unsigned long  FIFOCFG      : 02;
		unsigned long  Reserv6      : 02;
		
	} HDMA_CH_0_CFG_FIELD;
//HDMA_CH_0_CFG_UNN
}  @ (0xFFFFEC50);

__no_init volatile union 
{
	unsigned long HDMA_CH_1_CTRLA_REG;
	struct
	{
		unsigned long BTSIZE   : 16;
		unsigned long SCSIZE   : 3;
		unsigned long reserv1  : 1;
		unsigned long DCSIZE   : 3;
		unsigned long reserv2  : 1;
		unsigned long SRC_WIDTH: 2;
		unsigned long reserv3  : 2;
		unsigned long DST_WIDTH: 2;
		unsigned long reserv4  : 1;
		unsigned long DONE     : 1;
	} HDMA_CH_1_CTRLA_FIELD;
//HDMA_CH_1_CTRLA_UNN
}  @ (0xFFFFEC70);

//DMAC_CTRLBx [x = 0..7]

	
	
	
__no_init volatile union 
{
	unsigned long HDMA_CH_1_CTRLB_REG;
	struct
	{
		unsigned long  SIF          : 02;
		unsigned long  Reserv1      : 02;
		unsigned long  DIF          : 02;
		unsigned long  Reserv2      : 02;
		unsigned long  SRC_PIP      : 01;
		unsigned long  Reserv3      : 03;
		unsigned long  DST_PIP      : 01;
		unsigned long  Reserv4      : 03;
		unsigned long  SRC_DSCR     : 1;
		unsigned long  Reserv5      : 03;
		unsigned long  DST_DSCR     : 1;
		unsigned long  FC           : 03;
		unsigned long  SRC_INCR     : 02;
		unsigned long  Reserv6      : 02;
		unsigned long  DST_INCR     : 02;
		unsigned long  IEN          : 01;
		unsigned long  AUTO         : 01;
	} HDMA_CH_1_CTRLB_FIELD;
//HDMA_CH_1_CTRLB_UNN
}  @ (0xFFFFEC74);

__no_init volatile union 
{
	unsigned long HDMA_CH_1_CFG_REG;
	struct
	{
		unsigned long  SRC_PER          : 04;
		unsigned long  DST_PER          : 04;
		unsigned long   SRC_REP         : 01;
		unsigned long   SRC_H2SEL       : 01;
		unsigned long  Reserv1          : 02;
		unsigned long  DST_REP          : 01;
		unsigned long  DST_H2SEL        : 01;
		unsigned long  Reserv2          : 02;
		unsigned long  SOD              : 01;
		unsigned long  Reserv3          : 03;
		unsigned long  LOCK_IF          : 01;
		unsigned long  LOCK_B           : 01;
		unsigned long  LOCK_IF_L        : 01;
		unsigned long  Reserv4          : 01;
		unsigned long  AHB_PROT     : 03;
		unsigned long  Reserv5      : 01;
		unsigned long  FIFOCFG      : 02;
		unsigned long  Reserv6      : 02;
		
	} HDMA_CH_1_CFG_FIELD;
//HDMA_CH_1_CFG_UNN
}  @ (0xFFFFEC78);







//- Write PMC register
#define WRITE_PMC(pPmc, regName, value) pPmc->regName = (value)

//- Enable Peripheral
#define PERIPHERAL_ENABLE(Id)   WRITE_PMC(AT91C_BASE_PMC, PMC_PCER, (1 << Id))
//- Disable  Peripheral
#define PERIPHERAL_DISABLE(Id)  WRITE_PMC(AT91C_BASE_PMC, PMC_PCDR, (1 << Id))

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//.extern void ActivateServTrApCnTeleMechsCTpuUnitSpi(void);
//.extern  void TerminateServiceApCnTeleMechs(void);
extern StatePdcDsc InitSpi0TRStatePdcDsc;
extern StatePdcDsc InitSpi0RVStatePdcDsc; 

extern void ConfigureGDmaSpi0(void);
void ConfigureGDmaSpi0_(void);
long ReInit2DmacChnl(void)  @ "Fast_function_nc";
void SPI0_DMA_Enable(void);
extern void DMAD_Handler();

long Dma_free_channel(long ch);
long Dma_alloc_channel(long ch, PFV cb);
long Dma_init(void);
void Dmac_spi0_recv_cb(void);
void Dmac_spi0_send_cb(void);
long ReInitDmacChnl01(void);

#endif // GDMA_h

