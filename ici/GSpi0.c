/*------------------------------------------------------------------------------
* Copyright (c) 2013 - Factory “KyivPrylad”
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
* File Name       : GSpi0.c
* Description     : Definition of AT91SAM9G45-BS characteristics, 
                    AT91SAM9G45-dependant PIOs and external components
					interfacing.
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  21/12/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "../rce/spi1.h"
#include "../LibG45/boards/bs_g45/board.h"
#include <intrinsics.h>
#include "../LibG45/peripherals/pio/pio.h"
#include "../LibG45/peripherals/spi/spi.h"
#include "../LibG45/peripherals/irq/irq.h"
#include "../LibG45/peripherals/pmc/pmc.h"
#include "../LibG45/memories/spi-flash/spid.h"
#include "../rce/at25.h"
#include <string.h>
#include "lpu.h"
#include "GSpi0.h"
#include "GSpi.h"
#include "gdma.h"
#define PIN_SPI0_MISO  {1 << 0, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
/// SPI0 MOSI pin definition.
#define PIN_SPI0_MOSI  {1 << 1, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI0 SPCK pin definition.
#define PIN_SPI0_SPCK  {1 << 2, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
/// List of SPI0 pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI0      PIN_SPI0_MISO, PIN_SPI0_MOSI, PIN_SPI0_SPCK
/// SPI0 chip select 0 pin definition.
#define PIN_SPI0_NPCS0 {1 << 3, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}


static const Pin pinsSPI0[]  = {PINS_SPI0 , PIN_SPI0_NPCS0};

extern unsigned char chEntry_Spi0;


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
/*
#define SIZE_LPDU_CNL_1 200

#define SIZE_LPDU_CNL_DOUBLE_ACCESS_MEMORY  512

#define SIZE_LPDU_CNL_HSU7 100

#define SIZE_LPDU_CNL_U3   60

#define SIZE_LPDU_CNL_HSU1 100
#define SIZE_LPDU_CNL_SPI 100

#define SIZE_LPDU_CNL_SPI  512

#define SIZE_LPDU_CNL_SPI 100//USART


#define SIZE_LPCI_FLD_CNL_1    1
#define SIZE_LDC_FLD_CNL_1     1
#define SIZE_CS_FLD_CNL_1      1

#define SIZE_LPCI_FLD_CNL_HSU7    1
#define SIZE_LDC_FLD_CNL_HSU7     1
#define SIZE_CS_FLD_CNL_HSU7      1

#define HDR_MODE_CNL_1      ((1<<7)|(1<<1))
*/
#define BUFFER_SIZE         1
#define MAX_BPS             500
const Pin pinsSpi0[] = {PINS_SPI0 , PIN_SPI0_NPCS0};
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
unsigned char chHdwErorSpi0;
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_SPI_BUF (SIZE_LPDU_CNL_SPI<<1)
/* SPI device handles */
long spidevSS0 = 0;//uartdevU2 = 0;
// INT_32 hsuartdev = 0;
//.static unsigned char txbuff_U2 [512], rxbuff_U2 [512];
//.volatile  long txsize_U2 = 0, rxsize_U2 = 0;
//.
//. long txfill_U2  = 0;
//. long rxget_U2   = 0; 
//. long txget_U2   = 0;
//. long rxfill_U2  = 0;
#pragma data_alignment=4
 static unsigned char spi0_txbuff [SIZE_SPI_BUF+16] @ "Fast_variable";//  @  "DMA_BUFFERS";
#pragma data_alignment=4 
 static unsigned char spi0_rxbuff [SIZE_SPI_BUF] @ "Fast_variable";
volatile  long spi0_txsize, spi0_rxsize;
long spi0_txfill = 0;
long spi0_rxget  = 0;
long spi0_txget  = 0;
long spi0_rxfill = 0;
 
 long lSpi0HdwState = 0;
char chLogicSpi0HdwError = 0; 
 
 long rv_SPI_RCR_Val = 0, rv_SPI_RNCR_Val = 0;
StatePdcDsc InitSpi0RVStatePdcDsc = {
0,
1,
(SIZE_LPDU_CNL_SPI>>1),
(SIZE_LPDU_CNL_SPI>>1),
((long) &(spi0_rxbuff[0]))+0, 
((long) &(spi0_rxbuff[0]))+(SIZE_LPDU_CNL_SPI>>1),
0
};
StatePdcDsc InitSpi0TRStatePdcDsc = {
0,
1,
(SIZE_LPDU_CNL_SPI>>1),
(SIZE_LPDU_CNL_SPI>>1),
((long) &(spi0_txbuff[0]))+0, 
((long) &(spi0_txbuff[0]))+(SIZE_LPDU_CNL_SPI>>1),
0
};

char chNumPacetInBufSS0 = 0; 
unsigned char *Prxbuff_Spi0 = spi0_rxbuff;
long lNssRise = 0;long lNssSet = 0;long lTcr_Tncr_Set = 0;
void StartSetPDC(void);
//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
#define AT91C_SPI_UNDES (0x1 <<  9)
//------------------------------------------------------------------------------
/// Interrupt handler for SPI. Increments the number of bytes received in the
/// current second and starts another transfer if the desired bps has not been
/// met yet.
//------------------------------------------------------------------------------
void SPI0_IrqHandler(void)  @ "Fastest_function" //Fast_function"
{
register    unsigned long status;
	__istate_t s;
StatePdcDsc ValStatePdcDsc;	// AT91C_BASE_PIOD->PIO_SODR = (0x2);
AT91C_BASE_PIOD->PIO_SODR = (0x4);
s = __get_interrupt_state();__disable_interrupt();	//DisblGSpiInt();
    // Read SPI status
    status = AT91C_BASE_SPI0->SPI_SR;
	if(chEntry_Spi0==221)//Select source of interrupt
	{
		if (status &((AT91C_SPI_NSSR| AT91C_SPI_RDRF|AT91C_SPI_TDRE)))//May be careful when need fix End or Start SPI Exchange
		{
			AT91C_BASE_SPI0->SPI_IDR =  AT91C_SPI_RDRF|AT91C_SPI_NSSR;
			//Reinit Receive & Transmit channels
			ValStatePdcDsc.chAux            = 0;
			ValStatePdcDsc.chActivatePDC    = 1;
			ValStatePdcDsc.shCtrPR          = (SIZE_LPDU_CNL_SPI>>1)-1;//(SIZE_LPDU_CNL_SPI>>1)+ Select Receive And SendCb
			ValStatePdcDsc.shCtrNPR         = (SIZE_LPDU_CNL_SPI>>1);
			ValStatePdcDsc.lPR              = ((long) &(spi0_rxbuff[0]))+0; 
			ValStatePdcDsc.lNPR             = ((long) &(spi0_rxbuff[0]))+SIZE_LPDU_CNL_SPI;
			ValStatePdcDsc.lCS_SR           = 0;
			IciSpi_ReadBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0);
			ValStatePdcDsc.lPR              = ((long) &(spi0_txbuff[0]))+0; 
			ValStatePdcDsc.lNPR             = ((long) &(spi0_txbuff[0]))+SIZE_LPDU_CNL_SPI;
			ValStatePdcDsc.lCS_SR           = 0;
			IciSpi_WriteBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0); 
				chEntry_Spi0--;
		}
	}
	if (status &(AT91C_SPI_NSSR))
	{
		lNssRise++;//status++;if(chEntry_Spi0>0)
		lNssSet++;//status++;
		goto CheckError;//status++;
	}	
	if (status & (AT91C_SPI_ENDRX|AT91C_SPI_RXBUFF))//(AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT) ) 
	{
		if (status & (AT91C_SPI_TXBUFE|AT91C_SPI_ENDTX))
		//Read Data
		spi0_recv_cb();
		else 
		{
			chLogicSpi0HdwError++;
            #ifdef  BS_G45_FL_RL
			__asm volatile("BKPT 4");
			#endif 
                        ReInitSpi0Param();//Fix Hardware Error
			goto CheckError;
		}
		 status = AT91C_BASE_SPI0->SPI_SR;
		
	}
	if (status & (AT91C_SPI_TXBUFE|AT91C_SPI_ENDTX))//(AT91C_US_ENDTX|AT91C_US_TXBUFE) )
	{
		//Clear Interrupt
		//Send Msg If Need
		//AT91C_BASE_SPI0->US_IDR = 0;//AT91C_US_ENDTX|AT91C_US_TXBUFE;
		spi0_send_cb();status = AT91C_BASE_SPI0->SPI_SR;
	}
CheckError:	
	if (status & (AT91C_SPI_MODF|AT91C_SPI_OVRES|AT91C_SPI_UNDES))//(AT91C_US_RXBRK|AT91C_US_OVRE|AT91C_US_FRAME|AT91C_US_PARE) )
	{
	    spi0_error_cb();
	}//Enable Int __enable_irq()
	if(chEntry_Spi0<3)
    {		;//AT91C_BASE_AIC->AIC_IECR = 1 << (AT91C_ID_SPI0);//source;
		status = AT91C_BASE_TC1->TC_SR;//AT91C_TC_CLKSTA
		if(status &(AT91C_TC_CLKSTA))
		{
			status = ((AT91S_TC*)AT91C_BASE_TC2)->TC_RC;
			status -= (((AT91S_TC*)AT91C_BASE_TC1)->TC_CV);
			if (status>(650))
			{
				((AT91S_TC*)AT91C_BASE_TC2)->TC_RC  = 350;
			}
			//else
			//	((AT91S_TC*)AT91C_BASE_TC2)->TC_RC  = 6500;//sLV.uChIdxByte 
		}
		
		
	}
	else
	{
		//Mask Interrupt
		DisblGSpiInt(); uchAmtSend = uchAmtReceive = 0;
		//LogicError
	   chLogicSpi0HdwError++;AT91C_BASE_SPI0->SPI_PTCR = (AT91C_PDC_TXTDIS) | (AT91C_PDC_RXTDIS) ;//Dis PDC
        #ifdef  BS_G45_FL_RL
		__asm volatile("BKPT 4");
		#endif 
	}
	
//ExitInt:	
__set_interrupt_state(s);//	AT91C_BASE_PIOD->PIO_CODR = (0x2);
AT91C_BASE_PIOD->PIO_CODR = (0x4);

}
//------------------------------------------------------------------------------
/// Configures SPI0 in hardware 
/// 
//------------------------------------------------------------------------------
void ConfigureSpi0(void)  @ "Fast_function"
{
    unsigned int mode;
	
//mode	= AT91C_US_USMODE_HWHSH
//                        | AT91C_US_CLKS_CLOCK
//                        | AT91C_US_CHRL_8_BITS
//                        | AT91C_US_PAR_NONE
//                        | AT91C_US_NBSTOP_1_BIT
//                        | AT91C_US_CHMODE_NORMAL;

    // Enable the peripheral clock in the PMC
    //PMC_EnablePeripheral(AT91C_ID_US2);//
	mode  = AT91C_SPI_MODFDIS ;

    // Configure 
    //USART_Configure(AT91C_BASE_SPI0, mode, 921600, BOARD_MCK);//
	SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,mode);
	mode  = AT91C_SPI_CPOL|AT91C_SPI_BITS_16;
	SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,mode);

    // Configure the RXBUFF interrupt
    IRQ_ConfigureIT(AT91C_ID_SPI0,AT91C_AIC_PRIOR_HIGHEST-1,SPI0_IrqHandler);//IRQ_ConfigureIT(AT91C_ID_US2, 0, USART2_IrqHandler);
    IRQ_EnableIT(AT91C_ID_SPI0);//IRQ_EnableIT(AT91C_ID_US2);

    // Enable receiver & transmitter
    //USART_SetReceiverEnabled(AT91C_BASE_SPI0,1);//
//	 Spi0Init();
	SPI_Enable(AT91C_BASE_SPI0);
}




void spi0_hdw_init(void)  @ "Fast_function"
{

StatePdcDsc ValStatePdcDsc;
 //~~~Rst_LpduHSU2_TpCnState();
// Def in At91..h ->#define AT91C_ID_PIOA   ( 2) // Parallel IO Controller A
// Def in At91..h ->#define AT91C_ID_PIOB   ( 3) // Parallel IO Controller B
// Def in At91..h ->#define AT91C_ID_PIOC   ( 4) // Parallel IO Controller C
// Def in At91..h ->#define AT91C_ID_PIOD_E ( 5) // Parallel IO Controller D and E 
 
 
PIO_Configure(pinsSPI0, PIO_LISTSIZE(pinsSPI0));
 PIO_CfgInput (AT91C_BASE_PIOA,(1<<04),1,1);  //PA4
 PIO_CfgOutput(AT91C_BASE_PIOA,(1<<05),1,0,1);//PA5
 PIO_CfgOutput(AT91C_BASE_PIOA,(1<<25),1,0,1);//P25
 PIO_CfgInput (AT91C_BASE_PIOA,(1<<26),1,1);  //P26
  PIO_CfgInput (AT91C_BASE_PIOC,(1<< 8 ),1,1);  //PC08
 PIO_CfgOutput(AT91C_BASE_PIOB,(1<<11),1,0,1);//PB11
 AT91C_BASE_PIOB->PIO_SODR = (1 << 11);//Signal Ready
 PIO_CfgOutput(AT91C_BASE_PIOD,(1<<29),1,0,1);//PD29
 PIO_CfgInput (AT91C_BASE_PIOE,(1<<31),1,1);  //PE31
 
 
AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOA)| ( 1 << AT91C_ID_PIOC) |  (1 << AT91C_ID_PIOB)|(1<<AT91C_ID_PIOD_E);
    AT91C_BASE_PIOA->PIO_ISR;
    AT91C_BASE_PIOA->PIO_IDR = 0xFFFFFFFF;
    IRQ_ConfigureIT(AT91C_ID_PIOA, (AT91C_AIC_PRIOR_HIGHEST), PIOA4_IrqHandler);//(1<<5)|
    IRQ_EnableIT(AT91C_ID_PIOA);
	AT91C_BASE_PIOA->PIO_IER = 1<<4;

    AT91C_BASE_PIOC->PIO_IDR = 0xFFFFFFFF;
    IRQ_ConfigureIT(AT91C_ID_PIOC, (AT91C_AIC_PRIOR_HIGHEST),  PIOC8_IrqHandler);//(1<<5)|
    IRQ_EnableIT(AT91C_ID_PIOC);
	AT91C_BASE_PIOC->PIO_IER = 1<<8;

	 AT91C_BASE_PIOE->PIO_IDR = 0xFFFFFFFF;
    IRQ_ConfigureIT( AT91C_ID_PIOD_E, (AT91C_AIC_PRIOR_HIGHEST), PIOE31_IrqHandler);//(1<<5)|
    IRQ_EnableIT( AT91C_ID_PIOD_E);
	AT91C_BASE_PIOE->PIO_IER = 1<<31;	
	
   // Configure USART and display startup trace
   rv_SPI_RNCR_Val = 40;//rx_US_RCR_Val=40;
   AT91C_BASE_SPI0->SPI_IDR = 0xffffffff;
   AT91C_BASE_SPI0->SPI_TDR = 0;
   	AT91C_BASE_SPI0->SPI_RPR  = (unsigned int)& spi0_rxbuff[0];//AT91C_BASE_US2->US_RPR = (unsigned int)&(rxbuff_U2[0]);
    AT91C_BASE_SPI0->SPI_RCR  = 2; //AT91C_BASE_US2->US_RCR = 17;
	AT91C_BASE_SPI0->SPI_RNPR = (unsigned int)& spi0_rxbuff[0];//AT91C_BASE_US2->US_RNPR = (unsigned int) &(rxbuff_U2[0]);
    AT91C_BASE_SPI0->SPI_RNCR = 2; //AT91C_BASE_US2->US_RNCR = 30;
	 
	//USART_WriteBuffer(AT91C_BASE_US2, (void*)&(txbuff_U2[0]), 10);
	
	AT91C_BASE_SPI0->SPI_TPR = (unsigned int)&spi0_rxbuff[0];;//AT91C_BASE_US2->US_TPR = (unsigned int)&(rxbuff_U2[0]);
    AT91C_BASE_SPI0->SPI_TCR = 10;//AT91C_BASE_US2->US_TCR = 10;
	//AT91C_BASE_US2->US_RTOR = 0x14;//0xfa;//0x64
	
	 // Start receiving data and start timer
    ValStatePdcDsc.chAux            = 0;
	ValStatePdcDsc.chActivatePDC    = 0;
	ValStatePdcDsc.shCtrPR          = 2;//SIZE_LPDU_CNL_SPI;
	ValStatePdcDsc.shCtrNPR         = 2;//SIZE_LPDU_CNL_SPI;
	ValStatePdcDsc.lPR              = ((long) &(spi0_rxbuff[0]))+0; 
	ValStatePdcDsc.lNPR             = ((long) &(spi0_rxbuff[0]))+4;//SIZE_LPDU_CNL_SPI;
	ValStatePdcDsc.lCS_SR           = 0;
	rv_SPI_RNCR_Val = 20; //rx_US_RCR_Val = 20;//ValStatePdcDsc.shCtrPR;
	//USART_ReadBuffer(AT91C_BASE_US2, (void*)&(rxbuff_U2[0]), rx_US_RCR_Val);
	 IciSpi_ReadBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0);
	ValStatePdcDsc.lPR              = ((long) &(spi0_txbuff[0]))+0; 
	ValStatePdcDsc.lNPR             = ((long) &(spi0_txbuff[0]))+4;//SIZE_LPDU_CNL_SPI;
	ValStatePdcDsc.lCS_SR           = 0;
	 IciSpi_WriteBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0);
	
	
    ConfigureSpi0();//ConfigureUsart();
	Spi0HdwRstAndDmac();
   Rst_LpduSpi_TpCnState();
   StartUPInitTotVerInfo();
    // Spi0Init();
    //AT91C_BASE_SPI0->US_IER = AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT;
	//Enable Syncronizator
	
	
}
static short shPrev = 0;
long Spi0_Syncro1(void)
{
register long i = 0;
long count = 2;
StatePdcDsc ValStatePdcDsc;
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
		
AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTDIS;
AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS;		
//Look Receive Buff
unnV1.uchAr [0] = spi0_rxbuff[0];
unnV1.uchAr [1] = spi0_rxbuff[1];		
unnV1.uchAr [2] = spi0_rxbuff[2];
unnV1.uchAr [3] = spi0_rxbuff[3];

if(unnV1.ushAr [0] == 0x2875)
{
	if( ((unnV1.ushAr [0]+1) == unnV1.ushAr[1]) &&(spi0_rxbuff[4] == 0x77 ) )
	{
	//Data in Buff Syncro Ready
	//Init Channels & Interrupt System Etc.
		AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTDIS;
		AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS;
		ValStatePdcDsc.chAux            = 0;
		ValStatePdcDsc.chActivatePDC    = 0;
		ValStatePdcDsc.shCtrPR          = 1;//(SIZE_LPDU_CNL_SPI>>1)+ Select Receive And SendCb
		ValStatePdcDsc.shCtrNPR         = (SIZE_LPDU_CNL_SPI>>1);
		ValStatePdcDsc.lPR              = ((long) &(spi0_rxbuff[0]))+0; 
		ValStatePdcDsc.lNPR             = ((long) &(spi0_rxbuff[0]))+SIZE_LPDU_CNL_SPI;
		ValStatePdcDsc.lCS_SR           = 0;
	 IciSpi_ReadBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0);
		ValStatePdcDsc.lPR              = ((long) &(spi0_txbuff[0]))+0; 
		ValStatePdcDsc.lNPR             = ((long) &(spi0_txbuff[0]))+SIZE_LPDU_CNL_SPI;
		ValStatePdcDsc.lCS_SR           = 0;
	 IciSpi_WriteBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0); 
	 i = AT91C_SPI_MODF | AT91C_SPI_OVRES|AT91C_SPI_ENDRX|
	 AT91C_SPI_ENDTX|AT91C_SPI_RXBUFF|AT91C_SPI_TXBUFE;//|AT91C_SPI_NSSR;
	 
	 AT91C_BASE_SPI0->SPI_IER = i;
	
	AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTEN;
	AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTEN;
	lSpi0HdwState |= 4;
	//Wait & Detect Out Word or Not And Correct Selections
	return  _NO_ERROR_GSPI;	
		
		
	
	}
}

AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTDIS;
AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS;
unnV1.ushAr [0] = count=0x9483;
//Clear In OUT Buf;
for(i = 0; i < 4; i+=2)
{
spi0_rxbuff[i] = 0;
spi0_rxbuff[i+1] = 0;
}
for(i = 0; i < 6; i+= 2)
{//unnV1.ushAr [0] = count++; 
spi0_txbuff[i]   = unnV1.uchAr [0];
spi0_txbuff[i+1] = unnV1.uchAr [1];unnV1.ushAr [0] = unnV1.ushAr [0]+1;
}
//.ValStatePdcDsc.chAux            = 0;
//.	ValStatePdcDsc.chActivatePDC    = 0;
//.	ValStatePdcDsc.shCtrPR          = 2;//SIZE_LPDU_CNL_SPI;
//.	ValStatePdcDsc.shCtrNPR         = 1;//SIZE_LPDU_CNL_SPI;
//.	ValStatePdcDsc.lPR              = ((long) &(spi0_rxbuff[0]))+0; 
//.	ValStatePdcDsc.lNPR             = ((long) &(spi0_rxbuff[0]))+3;//SIZE_LPDU_CNL_SPI;
//.	ValStatePdcDsc.lCS_SR           = 0;
//.	 IciSpi_ReadBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0);
//.	ValStatePdcDsc.lPR              = ((long) &(spi0_txbuff[0]))+0; 
//.	ValStatePdcDsc.lNPR             = ((long) &(spi0_txbuff[0]))+3;//SIZE_LPDU_CNL_SPI;
//.	ValStatePdcDsc.lCS_SR           = 0;
//.	 IciSpi_WriteBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0); 
//.	  
//.AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTEN;
//.AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTEN;
if (shPrev == (short)0x9483)
{
count = 2;i= 1;
}
else
{
count = 3;i= 0;
}
	while ( count--)
	{
		unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
		spi0_rxbuff[i] = unnV1.uchAr [0];
		spi0_rxbuff[i+1] = unnV1.uchAr [1];
		if( (unnV1.ushAr [0]== 0x2875) && (i==0))
		ValStatePdcDsc.chAux            = 1;
		else
		{
			
			if((unnV1.ushAr [0]>>4)!= 0x287)
			{
				//Lost syncro Try Reset Spi
				AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIDIS;
				AT91C_BASE_SPI0->SPI_CR =  AT91C_SPI_SWRST;
				//Do Total Reinit
				SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,AT91C_SPI_MODFDIS );
				SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,AT91C_SPI_CPOL|AT91C_SPI_BITS_16);
				//
				AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;return 1;
			}
			
		
		}
		//unnV1.ushAr [0] = 0;
		unnV1.uchAr [2] = spi0_txbuff[i];
		unnV1.uchAr [3] = spi0_txbuff[i+1];
		if( (unnV1.ushAr [0]== 0x2876) && (i==2))
		ValStatePdcDsc.chAux            = 2;
		if((i==1)&&(unnV1.ushAr [0]!= 0x2876))
		unnV1.ushAr[1] = ValStatePdcDsc.chAux ;
		if( (unnV1.ushAr [0]== 0x2877) && (i==4))
		ValStatePdcDsc.chAux            = 3;
		//else
		//unnV1.ushAr[1] = ValStatePdcDsc.chAux ;
		if(unnV1.ushAr [0] == 0x2875)
		{
			ValStatePdcDsc.chAux            = 0;
		}
		//else
		//;
		//unnV1.ushAr [0] = 0;
		//unnV1.uchAr [2] = spi0_txbuff[i];
		//unnV1.uchAr [3] = spi0_txbuff[i+1];
		shPrev = unnV1.ushAr[1];
		//unnV1.ushAr[1] = //0x9483;
		SPI_Write(AT91C_BASE_SPI0,(unsigned int) 0,(unsigned short)unnV1.ushAr[1]);
		i +=2;
		//unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
		//spi0_rxbuff[i] = unnV1.uchAr [0];
		//spi0_rxbuff[i+1] = unnV1.uchAr [1];
	}
	unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
	if (unnV1.ushAr [0])
	ValStatePdcDsc.chAux            = 0;
	return (long)ValStatePdcDsc.chAux ;
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outSpi0(unsigned char *dat, long bytes)  @ "Fastest_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:  Send some data on the terminal interface                         ~~~
//~~~ Processing: Place data into the TX ring buffer and start UART transmission ~~~
//~~~        ~~~
//~~~  dat   : Data to send                                                      ~~~
//~~~  bytes : Number of bytes to send                                           ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes: Will block until all bytes are sent                                  ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================

long outSpi0(unsigned char *dat, long bytes)  @ "Fastest_function" //Fast_function"
{
 
  if ((spi0_txfill == spi0_txget)&&(spi0_txsize == 0))
  spi0_txget = spi0_txfill = 0;//.!!!

  while (bytes > 0)
  {
    while ((bytes > 0) && (spi0_txsize < (100)))//SIZE_SPI_BUF
    {
      spi0_txbuff[spi0_txfill] = *dat;
      spi0_txfill++;
      if (spi0_txfill >= (SIZE_SPI_BUF))
      {
        spi0_txfill = 0;
      }
      dat++;
      bytes--;
      //.int_disable(IRQ_UART_IIR2);
//?	  __disable_interrupt();//IRQ_DisableIT(AT91C_ID_SPI0);
      spi0_txsize++;
      //.int_enable(IRQ_UART_IIR2);
//?	  __enable_interrupt();//IRQ_EnableIT(AT91C_ID_SPI0);
    }

    bytes = 0;//.int_disable(IRQ_UART_IIR2);
//?	__disable_interrupt();//IRQ_DisableIT(AT91C_ID_SPI0);
    //...term_dat_send_cb();
	//.hs2_send_cb();
	spi0_send_cb();
    //.int_enable(IRQ_UART_IIR2);
//?	__enable_interrupt();//IRQ_EnableIT(AT91C_ID_SPI0);
  }
  return 0;
}
//---------------------------------------------------------------------------------
//-extern INT_32 hs2uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inSpi0(unsigned char *buff, int long)  @ "Fastest_function"; //Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from the terminal interface                        ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long inSpi0(unsigned char *buff, long bytes)  @ "Fastest_function" //Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (spi0_rxsize > 0))
  {
    *buff = spi0_rxbuff[spi0_rxget];
    buff++;
    spi0_rxget++;
    if (spi0_rxget >= (SIZE_SPI_BUF))
    {
      spi0_rxget = 0;
    }
    bytes--;
    bread++;
    //.int_disable(IRQ_UART_IIR2);
	__disable_interrupt();
	//.IRQ_DisableIT(AT91C_ID_SPI0);
    spi0_rxsize--;
    //.int_enable(IRQ_UART_IIR2);
	//..IRQ_EnableIT(AT91C_ID_SPI0);
	__enable_interrupt();
  }
  if (spi0_rxfill == spi0_rxget)
  {
	//.int_disable(IRQ_UART_IIR2);
	__disable_interrupt();//..IRQ_DisableIT(AT91C_ID_SPI0);
	spi0_rxfill = spi0_rxget = 0;
	//.int_enable(IRQ_UART_IIR2);
	//..IRQ_EnableIT(AT91C_ID_SPI0);
	__enable_interrupt();
  }
  if(chHdwErorSpi0)
  {
    //.int_disable(IRQ_UART_IIR2);
	//..IRQ_DisableIT(AT91C_ID_SPI0);
	//__disable_interrupt();
    //.int_clear(IRQ_UART_IIR2);
	spi0_recover_cb();
	//,chHdwErorHSU2 = 0;
    //,bytes = hs_uart_recover(hs2uartdev);
	
  }
//
//.int_enable(IRQ_UART_IIR2);
    //..IRQ_EnableIT(AT91C_ID_SPI0);
//__enable_interrupt();
  return bread;
	
	
}

//---------------------------------------------------------------------------------
__arm long InSpi0(unsigned char *buff, int long)  @ "Fast_function"; //Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from the terminal interface                        ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
__arm long InSpi0(unsigned  char *buff, long bytes)  @ "Fast_function" //Fast_function"
{

int bread = 0;
__disable_interrupt();
	if (bytes>spi0_rxsize)
	   bread = spi0_rxsize;
	else 
	bread = bytes;
	



//.  while ((bytes > 0) && (spi0_rxsize > 0))
//.  {
//.    *buff = spi0_rxbuff[spi0_rxget];
//.    buff++;
//.    spi0_rxget++;
//.    if (spi0_rxget >= (SIZE_SPI_BUF))
//.    {
//.      spi0_rxget = 0;
//.    }
//.    bytes--;
//.    bread++;
//.
//.
//.    spi0_rxsize--;
//.
//.  }
	memcpy(buff,spi0_rxbuff+spi0_rxget,bread);

	spi0_rxget += bytes;
	if (spi0_rxget >= (SIZE_SPI_BUF))
    {
      spi0_rxget -= SIZE_SPI_BUF;
    }
	spi0_rxsize -= bread; 
__enable_interrupt();  

  if (spi0_rxfill == spi0_rxget)
  {

	__disable_interrupt();//..
	spi0_rxfill = spi0_rxget = 0;

	__enable_interrupt();
  }
  if(chHdwErorSpi0)
  {


	spi0_recover_cb();
	//,chHdwErorHSU2 = 0;
	
  }


  return bread;
	
	
}

//---------------------------------------------------------------------------------


void ReInitInBufParamSpi0(void)
{
IRQ_DisableIT(AT91C_ID_SPI0);
spi0_rxsize = spi0_rxfill = spi0_rxget = 0;
Prxbuff_Spi0 = spi0_rxbuff; 
IRQ_EnableIT(AT91C_ID_SPI0);
}
 unsigned char uchAmtSend, uchAmtReceive = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void  spi0_send_cb(void) @ "Fastest_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void  spi0_send_cb(void) @ "Fastest_function"
{
long bwrite, tosend = (SIZE_SPI_BUF) -  spi0_txget;
  //HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hsuartdev;
  //AT91S_USART *usart = AT91C_BASE_US2;
void *pv = (void*)&InitSpi0TRStatePdcDsc;   uchAmtSend++;
  if (tosend > spi0_txsize)
  {
    tosend = spi0_txsize;
	//#ifdef  BS_G45_FL_RL   
	//if (tosend != 0x100 )
	//{
	//	__asm volatile("BKPT 4"); <- At the first Time put in this place
	//}
	//#endif 
  }
  if (tosend == 0)
  {
    //
	//.AT91C_BASE_US2->US_CR = AT91C_US_TXDIS;
	//.AT91C_BASE_US2->US_IDR = AT91C_US_ENDTX|AT91C_US_TXBUFE;
	//?AT91C_BASE_SPI0->SPI_IDR = AT91C_SPI_ENDTX|AT91C_SPI_TXBUFE;
	IciSpi_WriteBuf(AT91C_BASE_SPI0,pv,1); chEntry_Spi0++;//Is really Correct??? You should inform that data transmitting ended!
	return;
  }
  else
  {
    //.AT91C_BASE_US2->US_IER |= (AT91C_US_ENDTX|AT91C_US_TXBUFE);
	AT91C_BASE_SPI0->SPI_IER = AT91C_SPI_ENDTX|AT91C_SPI_TXBUFE;
	//IciSpi_WriteBuf(AT91C_BASE_SPI0,( void *)&pv,0); 
  }

  /* Write data */
  //bwrite = hs_uart_write(hsuartdev, &hs7_txbuff[ txget_U2], tosend);
  //USART_WriteBuffer(AT91C_BASE_US2,(void*)&txbuff_U2[txget_U2],tosend);
  ((StatePdcDsc*)pv)->chActivatePDC = 1;
  ((StatePdcDsc*)pv)->shCtrPR = tosend>>1;//May be put Constant in this place
  //((StatePdcDsc*)pv)->shCtrNPR = 0;
  //.bwrite = IciUsart_WriteBuf(AT91C_BASE_US2,pv,1);
  bwrite = IciSpi_WriteBuf(AT91C_BASE_SPI0,pv,1); 
  if (bwrite==_NO_ERROR_GSPI)
  {
       bwrite = tosend;
	   //Activate Writing!!!
	   //.AT91C_BASE_US2->US_CR = AT91C_US_TXEN;
  }
  else
  {
      bwrite = 0;
	  
  }
   spi0_txsize = spi0_txsize - bwrite;
   spi0_txget  =  spi0_txget + bwrite;
  if ( spi0_txget >= (SIZE_SPI_BUF))
  {
     spi0_txget = 0;
  }
	if(chEntry_Spi0<3)
	chEntry_Spi0++;
	else
	for(;;);
}
//---------------------------------------------------------------------------------
char chNumPacetInBufSpi0 = 0;
long bytesReceivedSpi0 = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void spi0_recv_cb(void) @ "Fastest_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void spi0_recv_cb(void) @ "Fastest_function"
{
register long bread;//, toreadmax = 512 - rxfill_U2;
//StatePdcDsc ValStatePdcDsc;

void *pv = (void*)&InitSpi0RVStatePdcDsc;//InitRVStatePdcDsc;
  /* Read data */
 uchAmtReceive++;
	//
	
	bread = ((StatePdcDsc*)pv)->shCtrPR;
	bread += (((StatePdcDsc*)pv)->shCtrNPR) - (AT91C_BASE_SPI0->SPI_RCR);
	bread <<= 1;
  spi0_rxsize = spi0_rxsize + bread;
  spi0_rxfill = spi0_rxfill + bread;
  if (spi0_rxfill >= SIZE_SPI_BUF)
  {
    spi0_rxfill = 0;
  }
	//Reinit PDC
	IciSpi_ReadBuf(AT91C_BASE_SPI0,pv,1);
	
	//Clear Flags & Activate Analis
	if(chEntry_Spi0<3)
	chEntry_Spi0++;
	else
	for(;;);

}
//---------------------------------------------------------------------------------


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void spi0_error_cb(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void spi0_error_cb(void) @ "Fast_function"
{
  //~AT91C_BASE_US2->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
  //~chHdwErorU2++;
	
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void spi0_eof_cb(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void spi0_eof_cb(void) @ "Fast_function"
{
void *pv = (void*)&InitSpi0RVStatePdcDsc;//InitRVStatePdcDsc;
//if need Start Process of Analises
/*	
	//This ->US_RCR==200 Var Analog Must Signaled that have more then One Packet
	if((rx_US_RCR_Val == 200)&&(chNumPacetInBuf>=2)) //bytesReceived== (SIZE_LPDU_CNL_SPI)
	{
		
		//bytesReceived += (SIZE_LPDU_CNL_SPI)-(AT91C_BASE_US2->US_RCR);//Na samom dele na 1 menshe
          rx_US_RCR_Val += (SIZE_LPDU_CNL_SPI)-(AT91C_BASE_US2->US_RCR);//Sho popalo dlya obrobki 
	}	
	else
	chNumPacetInBuf++;
	
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US2,pv,1);
	
	AT91C_BASE_US2->US_CR = AT91C_US_STTTO;
	chEntry_U2++;
	if(chEntry_U2 >= 2)
	while(1);//Lose Packet*/
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void spi0_recover_cb(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void spi0_recover_cb(void) @ "Fast_function"
{
void *pv = (void*)&InitSpi0RVStatePdcDsc;//InitRVStatePdcDsc;

	//..AT91C_BASE_US2->US_CR = AT91C_US_RSTRX | AT91C_US_RSTTX | AT91C_US_RXDIS | AT91C_US_TXDIS;
	//..AT91C_BASE_US2->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
	//..chHdwErorU2 = 0;
	//..//.((StatePdcDsc*)pv)->chActivatePDC = 0;
	//..IciUsart_ReadBuf(AT91C_BASE_US2,pv,1);
	//..
	//..//AT91C_BASE_US2->US_CR = AT91C_US_STTTO;
	//..//chEntry_U2++;
	//..if(chEntry_U2 >= 2)
	//..chEntry_U2 = 0;//while(1);//Error Fix Point
	//..USART_SetReceiverEnabled(AT91C_BASE_US2,1);
}
//---------------------------------------------------------------------------------
void StartSetPDC(void)
{
	register long i;
	StatePdcDsc ValStatePdcDsc;
	AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTDIS;
		AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS;
		ValStatePdcDsc.chAux            = 0;
		ValStatePdcDsc.chActivatePDC    = 0;
		ValStatePdcDsc.shCtrPR          = (SIZE_LPDU_CNL_SPI>>1);//+ Select Receive And SendCb
		ValStatePdcDsc.shCtrNPR         = (SIZE_LPDU_CNL_SPI>>1);
		ValStatePdcDsc.lPR              = ((long) &(spi0_rxbuff[0]))+0; 
		ValStatePdcDsc.lNPR             = ((long) &(spi0_rxbuff[0]))+SIZE_LPDU_CNL_SPI;
		ValStatePdcDsc.lCS_SR           = 0;
	 IciSpi_ReadBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0);
		ValStatePdcDsc.lPR              = ((long) &(spi0_txbuff[0]))+1; 
		ValStatePdcDsc.lNPR             = ((long) &(spi0_txbuff[0]))+SIZE_LPDU_CNL_SPI;
		ValStatePdcDsc.lCS_SR           = 0;
	 IciSpi_WriteBuf(AT91C_BASE_SPI0,( void *)&ValStatePdcDsc,0); 
	  i = 0; spi0_txbuff[i] = i+3;i++; spi0_txbuff[i] = i+3;i++;spi0_txbuff[i] = i+3;i++;spi0_txbuff[i] = i+3;i++;
	 i = AT91C_SPI_MODF | AT91C_SPI_OVRES|//AT91C_SPI_ENDRX| <-Modify 26_02_15
	 AT91C_SPI_ENDTX|AT91C_SPI_RXBUFF|AT91C_SPI_TXBUFE;//|AT91C_SPI_NSSR;
	 AT91C_BASE_SPI0->SPI_IER = i;
	
	//AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTEN;<- This Row select Use or not PDC
	//AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTEN;<- This Row select Use or not PDC
}
static long  lStartCheckCnl = 0; 
static long  lInitStateCnl = 0; 
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Spi0_Syncro2(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void Spi0_Syncro2(void) @ "Fast_function"
{
register long i;
register void *pv;
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
struct 
	{
		unsigned char uchError;
		unsigned char uchHdwrError;
		//unsigned char uChIdxByte ;
		unsigned short ushReceiveCmd;
		unsigned short ushSendAnswerCmd;
		//unsigned char *pUchRV;
		
		
	} sLV;

i = 0;sLV.uchHdwrError =  sLV.uchError = sLV.ushReceiveCmd = sLV.ushSendAnswerCmd =0;
	//if((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_RDRF) == 0)
	//return;
	//Read Cmd 
	unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
	sLV.ushReceiveCmd = unnV1.ushAr [0];
	//Control correctness Input Data
	if(((sLV.ushReceiveCmd) >>4)!= 0x287)
	{
		//Lost syncro Try Reset Spi
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIDIS;
		AT91C_BASE_SPI0->SPI_CR =  AT91C_SPI_SWRST;
		//Do Total Reinit
		SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,AT91C_SPI_MODFDIS );
		SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,AT91C_SPI_CPOL|AT91C_SPI_BITS_16);
		//
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;
		sLV.uchHdwrError++;
		goto HardwareError;//return 1;
	}
	unnV1. uchAr [3] = 0;
	//Detect Type Cmd
	switch(sLV.ushReceiveCmd )
	{
		case 0x2875:
		//Look Curr state
		if (lInitStateCnl <= 2)
		{
			sLV.ushSendAnswerCmd = 0x9483;//State 2
			lInitStateCnl = 2;
		}
		else 
		{
			if(lInitStateCnl == 3)
			sLV.ushSendAnswerCmd = 0x9484;//Send Current State
			if(lInitStateCnl == 4)
			sLV.ushSendAnswerCmd = 0x9485;//Send Current State
			
		}
		//unnV1. uchAr [3] = lInitStateCnl;
		break;
		case 0x2876:
		if ((lInitStateCnl <= 3)&&(lInitStateCnl>1))
		{
			sLV.ushSendAnswerCmd = 0x9484;//State 2
			lInitStateCnl = 3;
		}
		else 
		{
			if(lInitStateCnl == 2)
			sLV.ushSendAnswerCmd = 0x9484;//Send Current State
			if(lInitStateCnl == 4)
			sLV.ushSendAnswerCmd = 0x9485;//Send Current State
			if (lInitStateCnl <= 1)
			sLV.ushSendAnswerCmd = 0x9483;
		}
		//unnV1. uchAr [3] = lInitStateCnl;
		break;
		case 0x2877:
		if ((lInitStateCnl <= 4)&&(lInitStateCnl>2))
		{
			if(lInitStateCnl == 4)
			{
				//unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
				//End  of Syncro
				lSpi0HdwState |= 4;
				lSpi0HdwState &= ~(2);//Clr First Bit
				// Send Aux data 
				while ((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_TXEMPTY) == 0);
				AT91C_BASE_SPI0->SPI_TDR = 0x9485 | SPI_PCS(0);
				//ReInit for Use PDC
				 StartSetPDC();
				return;
			}	
			sLV.ushSendAnswerCmd = 0x9485;//State 2
			lInitStateCnl = 4;
		}
		else
		{
			//sLV.uchError++;//Not Adecvate Sequence Cmd
			if (lInitStateCnl <= 1)
			sLV.ushSendAnswerCmd = 0x9483;
			if(lInitStateCnl == 2)
			sLV.ushSendAnswerCmd = 0x9484;//Send Current State
		
		}
		//unnV1. uchAr [3] = lInitStateCnl;
		break;
		
		default: 
		sLV.ushSendAnswerCmd = 0x9484;//Reset State
		//unnV1. uchAr [3] = 1;//Error state start Init
	}
	unnV1. uchAr [3] = lInitStateCnl;
	if(sLV.uchHdwrError)
	{
HardwareError:	
	sLV.ushSendAnswerCmd = 0x9483;
		lInitStateCnl = 0;
	}
	if(sLV.uchError)
	{
		sLV.ushSendAnswerCmd = 0x9483;
		lInitStateCnl = 0;
	}
	
/*	
	//Write answer
	if((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_TXEMPTY) == 0)
	return;
	if((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_TDRE) == 0)
	return;
	AT91C_BASE_SPI0->SPI_TDR = (((unsigned short)sLV.ushSendAnswerCmd) | (SPI_PCS(0)));
	*/
	SPI_Write(AT91C_BASE_SPI0,(unsigned int) 0,(unsigned short)sLV.ushSendAnswerCmd);//unnV1.ushAr[1]
	
}
//---------------------------------------------------------------------------------
void SPI_Write1(AT91S_SPI *spi, unsigned int npcs, unsigned short data) @  "Fast_function_nc"; //"CODE_NO_CACHE";
//=================================================================================
//Body func                                                                  
//=================================================================================
unsigned long SPI_Read_Ici(AT91S_SPI *spi,long lCounter)  @ "CODE_NO_CACHE"
{
    while ( ((spi->SPI_SR & AT91C_SPI_RDRF) == 0) && lCounter)
	lCounter--;
    return (spi->SPI_RDR & 0xFFFF)|(lCounter<<16);
}
//---------------------------------------------------------------------------------
unsigned long CheckSpi0State(long lWaitTime)
{
return SPI_Read_Ici(AT91C_BASE_SPI0,lWaitTime);
}

// ./ Sends data through a SPI peripheral. If the SPI is configured to use a fixed
// ./ peripheral select, the npcs value is meaningless. Otherwise, it identifies
// ./ the component which shall be addressed.
// ./ \param spi  Pointer to an AT91S_SPI instance.
// ./ \param npcs  Chip select of the component to address (1, 2, 3 or 4).
// ./ \param data  Word of data to send.
//------------------------------------------------------------------------------
long SPI_Write_Ici(AT91S_SPI *spi, unsigned int npcs, unsigned short data, long lCounter) @ "CODE_NO_CACHE"
{
    // Discard contents of RDR register
    //volatile unsigned int discard = spi->SPI_RDR;

    // Send data
    while( ((spi->SPI_SR & AT91C_SPI_TXEMPTY) == 0)&& lCounter)
	lCounter--;
	if(lCounter)
    spi->SPI_TDR = data | SPI_PCS(npcs);
	else
	return lCounter;
    while ( ((spi->SPI_SR & AT91C_SPI_TDRE) == 0) && lCounter)
	lCounter--;
	return lCounter;
}
static char chCounterRepeatRQ = 0; 
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Spi0_Syncro2(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void Spi0_Syncro3(void) @ "Fast_function_nc"
{
register long i;
register void *pv;
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
struct 
	{
		unsigned char uchError;
		unsigned char uchHdwrError;
		//unsigned char uChIdxByte ;
		unsigned short ushReceiveCmd;
		unsigned short ushSendAnswerCmd;
		//unsigned char *pUchRV;
		
		
	} sLV;

i = 0;sLV.uchHdwrError =  sLV.uchError = sLV.ushReceiveCmd = sLV.ushSendAnswerCmd =0;
	//if((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_RDRF) == 0)
	//return;
	//Read Cmd 
	//unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
	unnV1.ulVal  = SPI_Read_Ici(AT91C_BASE_SPI0,0xfffff);
	if(unnV1.ushAr [1]==0)
	{
		sLV.uchHdwrError++;
		//goto HardwareError;//return 1;
		return;
	}	
	sLV.ushReceiveCmd = unnV1.ushAr [0];
	//Control correctness Input Data
	if(((sLV.ushReceiveCmd) >>4)!= 0x287)
	{
		//Lost syncro Try Reset Spi
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIDIS;
		AT91C_BASE_SPI0->SPI_CR =  AT91C_SPI_SWRST;
		//Do Total Reinit
		SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,AT91C_SPI_MODFDIS );
		SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,AT91C_SPI_CPOL|AT91C_SPI_BITS_16);
		AT91C_BASE_SPI0->SPI_TDR = 0; //
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;
		sLV.uchHdwrError++;
		goto HardwareError;//return 1;
	}
	unnV1. uchAr [3] = 0;sLV.ushSendAnswerCmd = 0x9483;
	//Detect Type Cmd
	switch(sLV.ushReceiveCmd )
	{
		case 0x2875:
		//Look Curr state
		if (lInitStateCnl <= 2)
		{
			sLV.ushSendAnswerCmd = 0x9483;//State 2
			lInitStateCnl = 2;
		}
		else 
		{
			if(lInitStateCnl == 3)
			sLV.ushSendAnswerCmd = 0x9484;//Send Current State
			if(lInitStateCnl == 4)
			sLV.ushSendAnswerCmd = 0x9487;//Send Current State
			chCounterRepeatRQ++;
			if (chCounterRepeatRQ>4&& lInitStateCnl>0) 
			{
			chCounterRepeatRQ = 0;lInitStateCnl = 1;
			
			}
		}
		//unnV1. uchAr [3] = lInitStateCnl;
		break;
		case 0x2876:
		if ((lInitStateCnl <= 3)&&(lInitStateCnl>1))
		{
			sLV.ushSendAnswerCmd = 0x9484;//State 2
			lInitStateCnl = 3;
		}
		else 
		{
			if(lInitStateCnl == 2)
			sLV.ushSendAnswerCmd = 0x9484;//Send Current State
			if(lInitStateCnl == 4)
			sLV.ushSendAnswerCmd = 0x9489;//Send Current State
			if (lInitStateCnl <= 1)
			{
			sLV.ushSendAnswerCmd = 0x9483;
			chCounterRepeatRQ++;
			}
			
			if (chCounterRepeatRQ>4&& lInitStateCnl== 0) 
			{
			chCounterRepeatRQ = 0;lInitStateCnl = 1;
			
			}
		}
		//unnV1. uchAr [3] = lInitStateCnl;
		break;
		case 0x2877:
		if ((lInitStateCnl <= 4)&&(lInitStateCnl>2))
		{
			if(lInitStateCnl == 4)
			{
				//unnV1.ushAr [0] = SPI_Read(AT91C_BASE_SPI0);
				//End  of Syncro
				lSpi0HdwState |= 4;
				lSpi0HdwState &= ~(2);//Clr First Bit
				// Send Aux data 
				while ((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_TXEMPTY) == 0);
				AT91C_BASE_SPI0->SPI_TDR = 0x9486 | SPI_PCS(0);
				//ReInit for Use PDC
				 StartSetPDC();
				return;
			}	
			sLV.ushSendAnswerCmd = 0x9485;//State 2
			lInitStateCnl = 4;//lStartCheckCnl
		}
		else
		{
			//sLV.uchError++;//Not Adecvate Sequence Cmd
			if (lInitStateCnl <= 1)
			sLV.ushSendAnswerCmd = 0x9483;
			if(lInitStateCnl == 2)
			sLV.ushSendAnswerCmd = 0x9484;//Send Current State
		
		}
		//unnV1. uchAr [3] = lInitStateCnl;
		break;
		
		default: 
		sLV.ushSendAnswerCmd = 0x9484;//Reset State
		//unnV1. uchAr [3] = 1;//Error state start Init
	}
	unnV1. uchAr [3] = lInitStateCnl;
	if(sLV.uchHdwrError)
	{
HardwareError:	
	sLV.ushSendAnswerCmd = 0x9483;
		lInitStateCnl = 0;
	}
	if(sLV.uchError)
	{
		sLV.ushSendAnswerCmd = 0x9483;
		lInitStateCnl = 0;
	}
	SPI_Write1(AT91C_BASE_SPI0,(unsigned int) 0,(unsigned short)sLV.ushSendAnswerCmd);//unnV1.ushAr[1]
/*	
	
	
	
	unnV1.ulVal  = SPI_Write_Ici(AT91C_BASE_SPI0,(unsigned int) 0,
	(unsigned short)sLV.ushSendAnswerCmd,0xfffffff);
	if(unnV1.ushAr [1]==0)
	{
		lInitStateCnl = 0;
	}
	else
	lInitStateCnl = 1;*/
	
}
//---------------------------------------------------------------------------------


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Spi0_Rst(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void Spi0_Rst(void) @ "Fast_function"
{
//.register long i;
//.register void *pv;
//.    union 
//.	    {
//.	    	unsigned char   uchAr [4];
//.	    	unsigned short  ushAr [2];
//.            unsigned long   ulVal;
//.	    }unnV1;
//.struct 
//.	{
//.		unsigned char uchError;
//.		unsigned char uchHdwrError;
//.		//unsigned char uChIdxByte ;
//.		unsigned short ushReceiveCmd;
//.		unsigned short ushSendAnswerCmd;
//.		//unsigned char *pUchRV;
//.		
//.		
//.	} sLV;

		//Lost syncro Try Reset Spi
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIDIS;
		AT91C_BASE_SPI0->SPI_CR =  AT91C_SPI_SWRST;
		//Do Total Reinit
		SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,AT91C_SPI_MODFDIS );
		SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,AT91C_SPI_CPOL|AT91C_SPI_BITS_16);
		//
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;
	lInitStateCnl = 0;
	spi0_txsize = 0;
    spi0_rxsize = 0;
    spi0_txfill = 0;
    spi0_rxget  = 0;
    spi0_txget  = 0;
    spi0_rxfill = 0;

    lSpi0HdwState = 0;
 lNssRise = 0;
}
//---------------------------------------------------------------------------------


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long OutSpi0(unsigned char *dat, long bytes)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:  Second Generation OutSpi only for speed optimization purpose                       ~~~
//~~~ Processing: Place data into the TX ring buffer and start UART transmission ~~~
//~~~        ~~~Fastest_function
//~~~  dat   : Data to send                                                      ~~~
//~~~  bytes : Number of bytes to send                                           ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes: Will block until all bytes are sent                                  ~~
//~~~     Have Errors  Not correct Hudled goig thogh                              ~~ 
//~~~       SIZE_SPI_BUF barier                                                   ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================

__arm long OutSpi0(unsigned char *dat, long bytes)  @ "Fast_function"
{
register long bsend; 
  if ((spi0_txfill == spi0_txget)&&(spi0_txsize == 0))
  spi0_txget = spi0_txfill = 0;//.!!!
  if (bytes>SIZE_SPI_BUF)
  bytes = SIZE_SPI_BUF;//correctness Control
__disable_interrupt();

	if (bytes+spi0_txfill>SIZE_SPI_BUF)
	bytes = SIZE_SPI_BUF- spi0_txfill;
	else
	bsend = bytes;
	
	//i = spi0_txsize + bytes;
	//if (i>= (SIZE_SPI_BUF))
	if ((spi0_txsize + bytes)>= (SIZE_SPI_BUF))
	bsend = SIZE_SPI_BUF - spi0_txsize;
	else
	bsend = bytes;
	
	memcpy(spi0_txbuff+spi0_txfill,dat,bsend);
	spi0_txsize += bsend; 
	//if (bsend)

	spi0_txfill+= bsend;
    if (spi0_txfill >= (SIZE_SPI_BUF))
    {
      spi0_txfill -= SIZE_SPI_BUF;
    }

	


//.   while (bytes > 0)
//.   {
//.     while ((bytes > 0) && (spi0_txsize < (SIZE_SPI_BUF)))//
//.     {
//.       spi0_txbuff[spi0_txfill] = *dat;
//.       spi0_txfill++;
//.       if (spi0_txfill >= (SIZE_SPI_BUF))
//.       {
//.         spi0_txfill = 0;
//.       }
//.       dat++;
//.       bytes--;
//.       //.int_disable(IRQ_UART_IIR2);
//. //?	  __disable_interrupt();//IRQ_DisableIT(AT91C_ID_SPI0);
//.       spi0_txsize++;
//.       //.int_enable(IRQ_UART_IIR2);
//. //?	  __enable_interrupt();//IRQ_EnableIT(AT91C_ID_SPI0);
//.     }
//.     bytes = 0;//.int_disable(IRQ_UART_IIR2);
//. //?	__disable_interrupt();//IRQ_DisableIT(AT91C_ID_SPI0);
//. 	spi0_send_cb();
//.   }
	__enable_interrupt();//IRQ_EnableIT(AT91C_ID_SPI0);  
	lTcr_Tncr_Set++;
	AT91C_BASE_PIOA->PIO_SODR = (1 << 05);//Syncro Answer AT91C_BASE_PIOA->PIO_CODR = (1 << 05);
  return bsend;
}
//---------------------------------------------------------------------------------
//













void EnblGSpiInt(void)   @ "Fast_function"
{
register long i;
 i = AT91C_SPI_MODF | AT91C_SPI_OVRES|//AT91C_SPI_ENDRX|
	 AT91C_SPI_ENDTX|AT91C_SPI_RXBUFF|AT91C_SPI_TXBUFE;//|AT91C_SPI_NSSR;
	 AT91C_BASE_SPI0->SPI_IER = i;
	// AT91C_BASE_AIC->AIC_IECR = 1 << (AT91C_ID_SPI0);//source;
}
void DisblGSpiInt(void)   @ "Fast_function"
{
//register long i;
    AT91C_BASE_SPI0->SPI_IDR = 0xffffffff;
	//AT91C_BASE_AIC->AIC_IDCR = 1 << (AT91C_ID_SPI0);
	//AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTEN;
	//AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTEN;
	 
	
}

//void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
//The function copies the array of char beginning at the address s2 to 
//the array of char beginning at the address s1 (both of size n).
// It returns s1. The elements of the arrays can be accessed and stored in any order.


void SPI_Write1(AT91S_SPI *spi, unsigned int npcs, unsigned short data) @ "Fast_function_nc" //"CODE_NO_CACHE"
{
    // Discard contents of RDR register
    //volatile unsigned int discard = spi->SPI_RDR;

    // Send data
    while ((spi->SPI_SR & AT91C_SPI_TXEMPTY) == 0);
    spi->SPI_TDR = data | SPI_PCS(npcs);
    while ((spi->SPI_SR & AT91C_SPI_TDRE) == 0);
}
static char chReInitEnterCounter = 0;
void ReInitSpiPDC(void)  @ "Fast_function_nc"
{
register void *pv_Rv;// = (void*)&InitSpi0RVStatePdcDsc;
register void *pv_Tr;// = (void*)&InitSpi0TRStatePdcDsc; 
register long i;
struct 
	{
		unsigned char uchError;
//		unsigned char uchHdwrError;
		//unsigned char uChIdxByte ;
		long lVal_1,lVal_2;
	} sLV;
pv_Rv = (void*)&InitSpi0RVStatePdcDsc;
pv_Tr = (void*)&InitSpi0TRStatePdcDsc; 
    chReInitEnterCounter ++;
    if(chReInitEnterCounter ==1)
    {
    //AT91C_BASE_SPI0->SPI_PTCR = 
    	//ReInit PDC
    	//Wait 10 mks
    	//if not change - Ok
    	//If Change
		IciSpi_ReadBuf (AT91C_BASE_SPI0,pv_Rv,1);
		IciSpi_WriteBuf(AT91C_BASE_SPI0,pv_Tr,1);
		AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTEN | AT91C_PDC_RXTEN;
	//AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTEN;
		 i = AT91C_SPI_MODF | AT91C_SPI_OVRES|//AT91C_SPI_ENDRX|
		AT91C_SPI_ENDTX|AT91C_SPI_RXBUFF|AT91C_SPI_TXBUFE;//|AT91C_SPI_NSSR;
		AT91C_BASE_SPI0->SPI_IER = i;
	
	
    }
    if(chReInitEnterCounter ==5 ) 
    {
		sLV.lVal_1 =( ( (((StatePdcDsc*)pv_Rv)->lPR) == (AT91C_BASE_SPI0->SPI_RPR) )
			&& ((((StatePdcDsc*)pv_Rv)->shCtrPR) ==(AT91C_BASE_SPI0->SPI_RCR) ) );
		sLV.lVal_2 =( ( (((StatePdcDsc*)pv_Tr)->lPR) == (AT91C_BASE_SPI0->SPI_TPR) )
			&& ((((StatePdcDsc*)pv_Tr)->shCtrPR) ==(AT91C_BASE_SPI0->SPI_TCR) ) );
			;
		//Control
		if(sLV.lVal_1&&sLV.lVal_2)
		{
			
			
			;
		}
    
    }
    if(chReInitEnterCounter >=10)
    {
        chReInitEnterCounter = 0;
		;
		;
    }

}






//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void Spi0HdwRst(void)  @ "Fast_function_nc";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void Spi0HdwRst(void)  @ "Fast_function_nc"
{

AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIDIS;
		AT91C_BASE_SPI0->SPI_CR =  AT91C_SPI_SWRST;
		//Do Total Reinit
		SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,AT91C_SPI_MODFDIS );
		SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,AT91C_SPI_CPOL|AT91C_SPI_BITS_16);
		AT91C_BASE_SPI0->SPI_TDR = 0; //
		//ReInitSpiPDC
		StartSetPDC();
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void Spi0HdwRstAndDmac(void)  @ "Fast_function_nc";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void  Spi0HdwRstAndDmac(void)  @ "Fast_function_nc"
{

AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIDIS;
		AT91C_BASE_SPI0->SPI_CR =  AT91C_SPI_SWRST;
		//Do Total Reinit
		SPI_Configure(AT91C_BASE_SPI0,AT91C_ID_SPI0,AT91C_SPI_MODFDIS );
		SPI_ConfigureNPCS(AT91C_BASE_SPI0,0,AT91C_SPI_CPOL|AT91C_SPI_BITS_16);
		AT91C_BASE_SPI0->SPI_TDR = 0; //
		//Disable PDC
		AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTDIS;
		AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS;
		ConfigureGDmaSpi0();
		
		AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---    
extern void ReInitSpi0Param(void)  @ "Fast_function_nc";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO      ~~~
//~~~ OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     ~~~
//~~~        ~~~
//==================================================================================
//Body func                                                 
//==================================================================================
void ReInitSpi0Param(void)  @ "Fast_function_nc"
{
	Spi0HdwRst();
	spi0_txsize = 0;
    spi0_rxsize = 0;
    spi0_txfill = 0;
    spi0_rxget  = 0;
    spi0_txget  = 0;
    spi0_rxfill = 0;

    //lSpi0HdwState = 0;
	chEntry_Spi0 = 0;
	chLogicSpi0HdwError = 0;


}


void Spi0_Syncro4(void) @ "Fast_function_nc"
{
lSpi0HdwState |= 4;
	lSpi0HdwState &= ~(2);//Clr First Bit
 StartSetPDC();
				return;



}



void PIO_CfgInput(
    AT91S_PIO *pio,
    unsigned int mask,
    unsigned char enablePullUp,
    unsigned char enableFilter)
{
    // Disable interrupts
    pio->PIO_IDR = mask;

    // Enable pull-up(s) if necessary
    if (enablePullUp) {
    
        pio->PIO_PPUER = mask;
    }
    else {
    
        pio->PIO_PPUDR = mask;
    }

    // Enable filter(s) if necessary
    if (enableFilter) {
    
        pio->PIO_IFER = mask;
    }
    else {
    
        pio->PIO_IFDR = mask;
    }

    // Configure pin as input
    pio->PIO_ODR = mask;
    pio->PIO_PER = mask;
}


void PIO_CfgOutput(
    AT91S_PIO *pio,
    unsigned int mask,
    unsigned char defaultValue,
    unsigned char enableMultiDrive,
    unsigned char enablePullUp)
{
    // Disable interrupts
    pio->PIO_IDR = mask;

    // Enable pull-up(s) if necessary
    if (enablePullUp) {
    
        pio->PIO_PPUER = mask;
    }
    else {
    
        pio->PIO_PPUDR = mask;
    }

    // Enable multi-drive if necessary
    if (enableMultiDrive) {
    
        pio->PIO_MDER = mask;
    }
    else {
    
        pio->PIO_MDDR = mask;
    }

    // Set default value
    if (defaultValue) {

        pio->PIO_SODR = mask;
    }
    else {

        pio->PIO_CODR = mask;
    }

    // Configure pin(s) as output(s)
    pio->PIO_OER = mask;
    pio->PIO_PER = mask;
}


#define ERR_CH_ENTRY_SPI0      0
#define ERR_TCR     1
#define ERR_TNCR    2
#define ERR_RCR     3
#define ERR_RNCR    4
//#define SIZE_LDC_FLD_CNL_1     5
//#define SIZE_CS_FLD_CNL_1      6

long lForceReInit = 0;
void PIOA4_IrqHandler(void) @ "Fast_function_nc"//@ "Fastest_function"
{
    unsigned int status;
    unsigned int i;
StatePdcDsc ValStatePdcRv;
StatePdcDsc ValStatePdcTr;
//struct 
//	{
//		//unsigned char uchTR_C;
//		unsigned char uChError ;
//		unsigned short ushSizeLDC;
//		//unsigned char *pUchRV;
//		
//		
//	} sLV;	

    // Read PIO controller status
    status = AT91C_BASE_PIOA->PIO_ISR;
    status &= AT91C_BASE_PIOA->PIO_IMR;
	if(status &= (1<<4))//
	{
	;	
		if((AT91C_BASE_PIOA->PIO_PDSR) & (1<<4) )
		{
			i = 0;
			//.if (chEntry_Spi0<2)
			//.{
			//.//i |= 1<<ERR_CH_ENTRY_SPI0;//Look End Of SPI Int sLV.uChError |= 
			//.status = chEntry_Spi0;
			//.}
			//Check Dmac State
			//i = ReInit2DmacChnl();
			//Check Rdy 
			//If not
			//ReInitSpi0Param();
			if(i)//I-Error
				{
					//Check chEntry_Spi0
					
		
					//__asm volatile("BKPT 4");
				}
				else
				{
					//ConfigureGDmaSpi0();
				}
			
			//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);//Syncro Answer
			AT91C_BASE_PIOA->PIO_CODR = (1 << 05);//
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 25);
		//
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 25);
		
		}		
	}
	
}
void PIOA4_IrqHandler_O(void) @ "Fast_function_nc"//@ "Fastest_function"
{
    unsigned int status;
    unsigned int i;
StatePdcDsc ValStatePdcRv;
StatePdcDsc ValStatePdcTr;
//struct 
//	{
//		//unsigned char uchTR_C;
//		unsigned char uChError ;
//		unsigned short ushSizeLDC;
//		//unsigned char *pUchRV;
//		
//		
//	} sLV;	

    // Read PIO controller status
    status = AT91C_BASE_PIOA->PIO_ISR;
    status &= AT91C_BASE_PIOA->PIO_IMR;
	if(status &= (1<<4))//
	{
	;	
		if((AT91C_BASE_PIOA->PIO_PDSR) & (1<<4) )
		{
			i = 0;
			//.if (chEntry_Spi0<2)
			//.{
			//.//i |= 1<<ERR_CH_ENTRY_SPI0;//Look End Of SPI Int sLV.uChError |= 
			//.status = chEntry_Spi0;
			//.}
			//Check PDC State
			
			if ( AT91C_BASE_SPI0->SPI_RNCR != (SIZE_LPDU_CNL_SPI>>1) )
			i |= 1<<ERR_RNCR;//Look End Of SPI Int
			
			if ( AT91C_BASE_SPI0->SPI_RCR != (SIZE_LPDU_CNL_SPI>>1) )
			i |= 1<< ERR_RCR ;//Look End Of SPI Int
			
			if ( AT91C_BASE_SPI0->SPI_TNCR != (SIZE_LPDU_CNL_SPI>>1) )
			i |= 1<< ERR_TNCR;//Look End Of SPI Int
			
			if ( AT91C_BASE_SPI0->SPI_TCR != (SIZE_LPDU_CNL_SPI>>1) )
			{
				if ( AT91C_BASE_SPI0->SPI_TCR != ((SIZE_LPDU_CNL_SPI>>1)-1) )
				i |= 1<< ERR_TCR ;//Look End Of SPI Int
			}
			//Check Rdy 
			//If not
			//ReInitSpi0Param();
			if(i)
				{
					//Check chEntry_Spi0
					i = (unsigned int) &ValStatePdcRv;
					// 
					((StatePdcDsc*)i)->lPR      =(unsigned int)  AT91C_BASE_SPI0->SPI_RPR ;
					((StatePdcDsc*)i)->shCtrPR  =                AT91C_BASE_SPI0->SPI_RCR ;
					((StatePdcDsc*)i)->lNPR     =(unsigned int)  AT91C_BASE_SPI0->SPI_RNPR;
					((StatePdcDsc*)i)->shCtrNPR =                AT91C_BASE_SPI0->SPI_RNCR;
					i = (unsigned int) &ValStatePdcTr;
					((StatePdcDsc*)i)->lPR      =(unsigned int)  AT91C_BASE_SPI0->SPI_TPR ;
					((StatePdcDsc*)i)->shCtrPR  =                AT91C_BASE_SPI0->SPI_TCR ;
					((StatePdcDsc*)i)->lNPR     =(unsigned int)  AT91C_BASE_SPI0->SPI_TNPR;
					((StatePdcDsc*)i)->shCtrNPR =                AT91C_BASE_SPI0->SPI_TNCR;
					status ++	;
						AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTDIS;
						AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTDIS;
						
 						AT91C_BASE_SPI0->SPI_RNCR = (SIZE_LPDU_CNL_SPI>>1);//+ Select Receive And SendCb
 						AT91C_BASE_SPI0->SPI_RCR  = (SIZE_LPDU_CNL_SPI>>1);
 						AT91C_BASE_SPI0->SPI_RPR  = ((long) &(spi0_rxbuff[0]))+0; 
 						AT91C_BASE_SPI0->SPI_RNPR = ((long) &(spi0_rxbuff[0]))+SIZE_LPDU_CNL_SPI;
						
						AT91C_BASE_SPI0->SPI_TPR  = ((long) &(spi0_txbuff[0]));// +1 ???;
						AT91C_BASE_SPI0->SPI_TCR  = (SIZE_LPDU_CNL_SPI>>1); 
						AT91C_BASE_SPI0->SPI_TNPR = ((long) &(spi0_txbuff[0]))+SIZE_LPDU_CNL_SPI; 
						AT91C_BASE_SPI0->SPI_TNCR =  (SIZE_LPDU_CNL_SPI>>1);
						lForceReInit++;
						
						
						
						AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_TXTEN;
						AT91C_BASE_SPI0->SPI_PTCR = AT91C_PDC_RXTEN;	
						#ifdef  BS_G45_FL_RL
						__asm volatile("BKPT 4");
                        
						#endif 
					//__asm volatile("BKPT 4");
				}
				else
				{
					ConfigureGDmaSpi0();
				}
			
			//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);//Syncro Answer
			AT91C_BASE_PIOA->PIO_CODR = (1 << 05);//
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 25);
		//
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 25);
		
		}		
	}
	
}
long lEndU2Tr = 0;
long lSetCtr  = 0;
long lClrCtr  = 0;
void PIOC8_IrqHandler(void) @ "Fast_function_nc"//@ "Fastest_function"
{
    unsigned int status;
    unsigned int i;
StatePdcDsc ValStatePdcRv;
StatePdcDsc ValStatePdcTr;
//struct 
//	{
//		//unsigned char uchTR_C;
//		unsigned char uChError ;
//		unsigned short ushSizeLDC;
//		//unsigned char *pUchRV;
//		
//		
//	} sLV;	

    // Read PIO controller status
    status = AT91C_BASE_PIOC->PIO_ISR;
    status &= AT91C_BASE_PIOC->PIO_IMR;
	if(status &= (1<<8))//
	{
	;	
		if((AT91C_BASE_PIOC->PIO_PDSR) & (1<<8) )
		{
			i = 0;
			//.if (chEntry_Spi0<2)
			//.{
			//.//i |= 1<<ERR_CH_ENTRY_SPI0;//Look End Of SPI Int sLV.uChError |= 
			//.status = chEntry_Spi0;
			//.}
			//Check Dmac State
			//i = ReInit2DmacChnl();
			//Check Rdy 
			//If not
			//ReInitSpi0Param();
			if(i)//I-Error
				{
					//Check chEntry_Spi0
					
		
					//__asm volatile("BKPT 4");
				}
				else
				{
					#ifdef USE_PIO_SYNC
					AT91C_BASE_PIOB->PIO_CODR = (1 << 11);//ConfigureGDmaSpi0();
					 lEndU2Tr = 5000;
					#endif
					lSetCtr++;
				}
			
			//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);//Syncro Answer
		//	AT91C_BASE_PIOC->PIO_CODR = (1 << 05);//
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 25);
		//
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 25);
		
		}		
	}
	
}
void PIOE31_IrqHandler(void) @ "Fast_function_nc"//@ "Fastest_function"
{
    unsigned int status;
    unsigned int i;
StatePdcDsc ValStatePdcRv;
StatePdcDsc ValStatePdcTr;
//struct 
//	{
//		//unsigned char uchTR_C;
//		unsigned char uChError ;
//		unsigned short ushSizeLDC;
//		//unsigned char *pUchRV;
//		
//		
//	} sLV;	

    // Read PIO controller status
    status = AT91C_BASE_PIOE->PIO_ISR;
    status &= AT91C_BASE_PIOE->PIO_IMR;
	if(status &= (1<<31))//
	{
	;	
		if((AT91C_BASE_PIOE->PIO_PDSR) & (1<<31) )
		{
			i = 0;
			//.if (chEntry_Spi0<2)
			//.{
			//.//i |= 1<<ERR_CH_ENTRY_SPI0;//Look End Of SPI Int sLV.uChError |= 
			//.status = chEntry_Spi0;
			//.}
			//Check Dmac State
			//i = ReInit2DmacChnl();
			//Check Rdy 
			//If not
			//ReInitSpi0Param();
			if(i)//I-Error
				{
					//Check chEntry_Spi0
					
		
					//__asm volatile("BKPT 4");
				}
				else
				{
					//ConfigureGDmaSpi0();
				}
			
			//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);//Syncro Answer
		//	AT91C_BASE_PIOC->PIO_CODR = (1 << 05);//
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_SODR = (1 << 25);
		//
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 05);
		//AT91C_BASE_PIOA->PIO_CODR = (1 << 25);
		
		}		
	}
	
}

extern long ReInitDmacChnl01_M(long lA);
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long V1OutSpi0(unsigned char *dat, long bytes)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:  Second Generation OutSpi only for speed optimization purpose                       ~~~
//~~~ Processing: Place data into the TX ring buffer and start UART transmission ~~~
//~~~        ~~~Fastest_function
//~~~  dat   : Data to send                                                      ~~~
//~~~  bytes : Number of bytes to send                                           ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes: Will block until all bytes are sent                                  ~~
//~~~     Have Errors  Not correct Hudled goig thogh                              ~~ 
//~~~       SIZE_SPI_BUF barier                                                   ~~
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================

__arm long V1OutSpi0(unsigned char *dat, long bytes)  @ "Fast_function"
{
register long bsend; 
  if ((spi0_txfill == spi0_txget)&&(spi0_txsize == 0))
  spi0_txget = spi0_txfill = 0;//.!!!
  if (bytes>SIZE_SPI_BUF)
  bytes = SIZE_SPI_BUF;//correctness Control
__disable_interrupt();

	if (bytes+spi0_txfill>SIZE_SPI_BUF)
	bytes = SIZE_SPI_BUF- spi0_txfill;
	else
	bsend = bytes;
	
	//i = spi0_txsize + bytes;
	//if (i>= (SIZE_SPI_BUF))
	if ((spi0_txsize + bytes)>= (SIZE_SPI_BUF))
	bsend = SIZE_SPI_BUF - spi0_txsize;
	else
	bsend = bytes;
	
//	memcpy(spi0_txbuff+spi0_txfill,dat,bsend);
	spi0_txsize += bsend; 
	//if (bsend)

	spi0_txfill+= bsend;
    if (spi0_txfill >= (SIZE_SPI_BUF))
    {
      spi0_txfill -= SIZE_SPI_BUF;
    }

	
	__enable_interrupt();//IRQ_EnableIT(AT91C_ID_SPI0);  
	lTcr_Tncr_Set++;
	
	
	AT91C_BASE_PIOA->PIO_SODR = (1 << 05);//Syncro Answer AT91C_BASE_PIOA->PIO_CODR = (1 << 05);
	ReInitDmacChnl01_M((long) dat);
  return bsend;
}
//---------------------------------------------------------------------------------
//


/* 


*/




/* EOF */



