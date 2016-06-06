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
* Processor       : Lpc_3240
* File Name       : gdma.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/03/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#include "../LibG45/peripherals/pio/pio.h"
#include "../LibG45/peripherals/spi/spi.h"
#include "../LibG45/peripherals/irq/irq.h"
#include "../LibG45/peripherals/pmc/pmc.h"
#include "../LibG45/peripherals/dma/dma.h"
#include "../LibG45/drivers/dmad/dmad.h"
#include <intrinsics.h>
#include "GSpi0.h"
#include "GSpi.h"
#include "lpu.h"
//#include <dma/dma.h>
//#include <drivers/dmad/dmad.h>
#include <string.h>
#include    "gdma.h"


typedef struct DmaTransfer_tag {
    // / Buffer transfer status.
    volatile unsigned char status;
    // / Transfer buffer size in byte.
    unsigned int bufSize;
    // / Total transfer size to byte.
    volatile unsigned int transferSize;
    // / Optional callback function.
    DmaCallback callback;
} SDmaTransfer;

void DMAD_IrqHandler(void);
void HDMA_IrqHandler(void);
extern void GetDmadAddr(void** ppDmad);
//-* DMA driver control structure *-/
typedef struct
{
  char chInit;     // <- Initial State
  char  chNum_alloc_ch;    //-* Number of allocated channels *-/
  
  long  ulAlloc_ch;// <-[DMA_MAX_CHANNELS];
  PFV     cb [8];  // <- DMA_MAX_CHANNELS
  void *pDmadTransfer;
} GDMA_DRV_DATA_T;

//-* DMAC driver data *-/
static GDMA_DRV_DATA_T gdmadrv_dat;

//void ConfigureGDmaSpi0(void)  @ "Fast_function"



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long Dma_init(void)  ;
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~         Initial DMA controller and driver                            ~~~
//~~~ Processing:
//~~~  This function sets up the DMA controller as initially disabled.     ~~~
//~~~  All DMA channels used by the driver are unallocated.                ~~~
//~~~ Parameters: 
//~~~             None                                                     ~~~
//~~~ Outputs:
//~~~             None                                                     ~~~
//~~~ Returns:                                                             ~~
//~~~          _ERROR if the device was already initialized, otherside _NO_ERROR
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                         ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long Dma_init(void)
{
unsigned long status;
long lResult;
 lResult = 0;
//``````````````````````````````````````````````````````````````````````````````````
//```Only continue if driver has not been previously initialized 
//..................................................................................
	if (gdmadrv_dat.chInit != 1)
	{
		gdmadrv_dat.chInit = 1;//First Init
		gdmadrv_dat.chNum_alloc_ch = 0;
		gdmadrv_dat.pDmadTransfer = (void*)0;
		GetDmadAddr((void*)&gdmadrv_dat.pDmadTransfer);
		//gdmadrv_dat.pDmadTransfer = (void*)
		//`````````````````````````````````````````````````````````````````````
		//`` Enable clock to DMA controller (for now)Enable DMA Peripheral
		//..................................................................... 
		AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_HDMA;//PERIPH_ENABLE(AT91C_ID_HDMA);
		
        //`````````````````````````````````````````````````````````````````````
		//`` Make sure DMA controller and all channels are disabled.
		//`` Controller is in little-endian mode. Disable  signals
		//..................................................................... 
		 // Free status
		AT91C_BASE_HDMA->HDMA_EBCIDR = (0xFFFFFFFF);//DMA_DisableIt(0xFFFFFFFF);
		status = ( AT91C_BASE_HDMA->HDMA_CHSR);//DMA_GetChannelStatus();
		status = (AT91C_BASE_HDMA->HDMA_EBCISR);//DMA_GetStatus();<-Return DMA Interrupt Status
		DMA_DisableChannels(0xff);//(1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
        //`````````````````````````````````````````````````````````````````````
		//`` Clear interrupt and error statuses
		//.....................................................................  
		 
        //`````````````````````````````````````````````````````````````````````
		//`` All DMA channels are initially disabled and unallocated
		//.....................................................................  
		gdmadrv_dat.ulAlloc_ch = 0;
		for(int i = 0; i < 8; i++)
		{
			gdmadrv_dat. cb[i] =  NULL;
		}
	}
	else
		 lResult = 5;
return  lResult;
}

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long Dma_alloc_channel(long ch,
                         PFV cb);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~         Allocate a channel for DMA                                     ~~~
//~~~ Processing:
//~~~ If the passed channel is (-1), then a search loop is used to           ~~~
//~~~ find the first unallocated channel. The channel value is saved         ~~~
//~~~ and then checked to make sure it is unallocated. If it is              ~~~
//~~~ already allocated or not allocatable, then an error si return to       ~~~
//~~~ the caller. If the channel is not allocated, the channel is            ~~~
//~~~ marked as allocated and the channel ID is returned to the caller.      ~~~
//~~~ If at leasxt one channel is active, the DMA clock is enabled.          ~~~
//~~~       ~~~
//~~~ Parameters: 
//~~~ ch : Must be 0 (highest priority) to 7, or -1 for auto-allocation     ~~~
//~~~ cb : Pointer to user callback function when an interrupt occurs       ~~~
//~~~                                                                  ~~~
//~~~ Outputs:
//~~~             None                                                     ~~~
//~~~ Returns:                                                             ~~
//~~~       The channel index, or _ERROR if a channel wasn't allocated   
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long Dma_alloc_channel(long ch,
                         PFV cb)  @ "Fast_function_nc"
{
  long challoc = ch;
	//`````````````````````````````````````````````````````````````````````
	//`` If auto-allocate is used, find the first available channel
	//`` starting with the highest priority first 
	//..................................................................... 
    if (ch == -1)
    {
        ch = 0;
        challoc = (-1);//_ERROR;
        while (ch < 8)//DMA_MAX_CHANNELS
        {
            if ( (gdmadrv_dat.ulAlloc_ch & (1<<ch)) == 0)//FALSE
            {
              //`````````````````````````````````````````````````````````````````````
              //`` Channel is free, use it
              //..................................................................... 
              challoc = ch;
              ch = 8;//DMA_MAX_CHANNELS;
            }
            else
            {
              //`````````````````````````````````````````````````````````````````````
              //`` Try next channel
              //.....................................................................
              ch++;
            }
        }
    }
     //`````````````````````````````````````````````````````````````````````
     //``  Only continue if channel is ok
     //..................................................................... 
   if ( challoc != (-1) )//_ERROR
    {    
        //`````````````````````````````````````````````````````````````````````
        //`` If the current channel is allocated already, then return an error instead 
        //.....................................................................
        if ((gdmadrv_dat.ulAlloc_ch & (1<<(challoc))) == 0)//FALSE
        { 
             //`````````````````````````````````````````````````````````````````````
             //`` Channel is free, so use it
             //.....................................................................
             gdmadrv_dat.ulAlloc_ch |= 1<<challoc;// = TRUE;
             gdmadrv_dat.cb [challoc] = cb;
             gdmadrv_dat.chNum_alloc_ch++; 
             //`````````````````````````````````````````````````````````````````````
             //`` Enable DMA clock if at least 1 DMA channel is used
             //`` Enable DMA controller
             //`` Install DMA interrupt handler in interrupt controller
             //`` and enable DMA interrupt
		     //.....................................................................
			if(gdmadrv_dat.chNum_alloc_ch == 1)
			{
				// Enable DMA
				AT91C_BASE_HDMA->HDMA_EN = AT91C_HDMA_ENABLE;//DMA_Enable();
				IRQ_ConfigureIT(AT91C_ID_HDMA, AT91C_AIC_PRIOR_HIGHEST, DMAD_IrqHandler);
				 IRQ_EnableIT(AT91C_ID_HDMA);
			 }
		
		}
		else{
		
		//`````````````````````````````````````````````````````````````````````
		//`` Selected channel is allocated, return an error
		//.....................................................................
		 challoc = (-1);//_ERROR;
		}
    }
	
	return challoc;
}


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long Dma_free_channel(long ch);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~         Return (free) an allocated DMA channel                             ~~~
//~~~ Processing:
//~~~ If the channel has been previously allocated, then deallocate              ~~~
//~~~ the channel and disable the channel in the DMA controller. If              ~~~
//~~~ no other DMA channels are enabled, the disable the DMA controller          ~~~
//~~~ along with the controller clock and DMA interrupts.                        ~~~
//~~~ Parameters: 
//~~~ ch : Must be 0 (highest priority) to 7                                    ~~~
//~~~ Outputs:
//~~~             None                                                     ~~~
//~~~ Returns:                                                             ~~
//~~~       The channel index, or _ERROR if a channel wasn't allocated   
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long Dma_free_channel(long ch)  @ "Fast_function_nc"
{
    long status = (-1); //_ERROR;
	//`````````````````````````````````````````````````````````````````````
	//`` 
	//`` 
	//..................................................................... 
    if ( (gdmadrv_dat.ulAlloc_ch & (1<<ch)) != 0)//TRUE
    {

         //`````````````````````````````````````````````````````````````````````
         //`` Deallocate channel 
         //..................................................................... 
         gdmadrv_dat.ulAlloc_ch &= ~(1<<ch);//FALSE;
         gdmadrv_dat.chNum_alloc_ch --;
        //`````````````````````````````````````````````````````````````````````
		//`` Try Shut down channel
		//.....................................................................
              
            
		
    }
	//`````````````````````````````````````````````````````````````````````
	//``  Only continue if channel is ok
	//..................................................................... 
	
	
	return status; 
}









void ConfigureGDmaSpi0_v0(void)  @ "Fast_function"
{
	unsigned int dmaStatus;
	ConfigureGDmaSpi0_();
	return;
	    // Enable DMA Peripheral
     AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_HDMA;//PERIPH_ENABLE(AT91C_ID_HDMA);
    // Enable DMA
    AT91C_BASE_HDMA->HDMA_EN = AT91C_HDMA_ENABLE;//DMA_Enable();
	
	 // Free status
    AT91C_BASE_HDMA->HDMA_EBCIDR = (0xFFFFFFFF);//DMA_DisableIt(0xFFFFFFFF);
    dmaStatus = ( AT91C_BASE_HDMA->HDMA_CHSR);//DMA_GetChannelStatus();
    dmaStatus = (AT91C_BASE_HDMA->HDMA_EBCISR);//DMA_GetStatus();<-Return DMA Interrupt Status
    DMA_DisableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_SADDR = (unsigned int)&(AT91C_BASE_SPI0->SPI_RDR);
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR = InitSpi0RVStatePdcDsc.lPR;
	//((long) &(spi0_rxbuff[0]))+0;
	
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR = InitSpi0TRStatePdcDsc.lPR;
	//((long) &(spi0_txbuff[0]))+0;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_DADDR = (unsigned int)&(AT91C_BASE_SPI0->SPI_TDR);
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA;
    dmaStatus &= ~(AT91C_HDMA_DONE); //
	dmaStatus |= (SIZE_LPDU_CNL_SPI>>1);
	dmaStatus |= AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD;
	dmaStatus |= (unsigned)AT91C_HDMA_DONE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA = dmaStatus;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB;
    dmaStatus &= 0;
	dmaStatus |= AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
	dmaStatus |= AT91C_HDMA_FC_PER2MEM;//AT91C_HDMA_FC_MEM2PER
	dmaStatus |= AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR;
	//AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR 
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB = dmaStatus ;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA;
    dmaStatus &= ~(AT91C_HDMA_DONE); //
	dmaStatus |= (SIZE_LPDU_CNL_SPI>>1);
	dmaStatus |= AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD;
	dmaStatus |= (unsigned)AT91C_HDMA_DONE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA = dmaStatus;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB;
    dmaStatus &= 0;
	dmaStatus |= AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
	dmaStatus |= AT91C_HDMA_FC_MEM2PER;//AT91C_HDMA_FC_PER2MEM;//
	dmaStatus |= AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR;
	// AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB = dmaStatus ;
	
	
    // RX channel 0
    DMA_SetConfiguration(DMA_CHANNEL_0,
                          AT91C_HDMA_SRC_PER_2
                       // | AT91C_HDMA_DST_PER_0
                        | AT91C_HDMA_SRC_H2SEL_HW
                        | AT91C_HDMA_DST_H2SEL_SW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );

    // TX channel 1
    DMA_SetConfiguration(DMA_CHANNEL_1,
                          AT91C_HDMA_SRC_PER_1
                        | AT91C_HDMA_DST_PER_1
                        | AT91C_HDMA_SRC_H2SEL_SW
                        | AT91C_HDMA_DST_H2SEL_HW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );
	
	IRQ_ConfigureIT(AT91C_ID_HDMA, 0, HDMA_IrqHandler);
	
	IRQ_EnableIT(AT91C_ID_HDMA);

	// Enable the SPI TX & RX
    //WRITE_SPI(pSpiHw, SPI_CR, AT91C_SPI_SPIEN);

    // Start DMA 0(RX) && 1(TX)
    DMA_EnableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));

    // Enable DMA Interrupts
    DMA_EnableIt(  (DMA_CBTC << DMA_CHANNEL_0)
                 | (DMA_CBTC << DMA_CHANNEL_1));
	


}

void HDMA_IrqHandler(void)  @ "Fast_function_nc"
{
 register       unsigned int dmaStatus;
 __istate_t s;
s = __get_interrupt_state();__disable_interrupt();	
dmaStatus = DMA_GetStatus();

    if ((dmaStatus & AT91C_CBTC) == 0)
        HDMA_CH_0_CTRLA_FIELD.reserv1 = 0;//return;

    if ((dmaStatus & (DMA_CBTC << DMA_CHANNEL_0)) == 0)
        HDMA_CH_0_CTRLB_FIELD.Reserv1 = 0;//return;
	//Detect channel Active Channell and Call Apopriate Hundler 
	
		
    // Disable the SPI TX & RX
   // WRITE_SPI(pSpiHw, SPI_CR, AT91C_SPI_SPIDIS);
    // Disable the SPI Peripheral
   // PERIPH_DISABLE(pSpid->spiId);
chEntry_Spi0 = 2;
    // Disable DMA
//    DMA_Disable();
    // Disable DMA Peripheral
   // PERIPH_DISABLE(AT91C_ID_HDMA);
    HDMA_CH_0_CTRLA_FIELD.reserv1 = 0;
	HDMA_CH_0_CTRLB_FIELD.Reserv1 = 0;
	HDMA_CH_0_CFG_FIELD.Reserv1   = 0;
	HDMA_CH_1_CTRLA_FIELD.reserv1 = 0;
	HDMA_CH_1_CTRLB_FIELD.Reserv1 = 0;
	HDMA_CH_1_CFG_FIELD.Reserv1   = 0;
	//ReInit2DmacChnl();
__set_interrupt_state(s);
}
long ReInit2DmacChnl(void)  @ "Fast_function_nc"
{
	unsigned long dmaStatus;
	long  i;
	i = AT91C_BASE_HDMA->HDMA_EBCISR;
	i = ( AT91C_BASE_HDMA->HDMA_CHSR);//DMA_GetChannelStatus();
	DMA_DisableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_SADDR =
	(unsigned int)&(AT91C_BASE_SPI0->SPI_RDR);
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR = 
	InitSpi0RVStatePdcDsc.lPR;
	//((long) &(spi0_rxbuff[0]))+0;
	
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR =
	InitSpi0TRStatePdcDsc.lPR;
	//((long) &(spi0_txbuff[0]))+0;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_DADDR =
	(unsigned int)&(AT91C_BASE_SPI0->SPI_TDR);
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA;
    dmaStatus &= ~(AT91C_HDMA_DONE); //
	dmaStatus |= (SIZE_LPDU_CNL_SPI>>1);
	dmaStatus |= AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD;
	dmaStatus |= (unsigned)AT91C_HDMA_DONE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA = dmaStatus;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB;
    dmaStatus &= 0;
	dmaStatus |= AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
	dmaStatus |= AT91C_HDMA_FC_PER2MEM;//AT91C_HDMA_FC_MEM2PER
	dmaStatus |= AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR;
	//AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR 
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB = dmaStatus ;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA;
    dmaStatus &= ~(AT91C_HDMA_DONE); //
	dmaStatus |= (SIZE_LPDU_CNL_SPI>>1);
	dmaStatus |= AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD;
	dmaStatus |= (unsigned)AT91C_HDMA_DONE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA = dmaStatus;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB;
    dmaStatus &= 0;
	dmaStatus |= AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
	dmaStatus |= AT91C_HDMA_FC_MEM2PER;//AT91C_HDMA_FC_PER2MEM;//
	dmaStatus |= AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR;
	// AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB = dmaStatus ;
	
	
    // RX channel 0
    DMA_SetConfiguration(DMA_CHANNEL_0,
                          AT91C_HDMA_SRC_PER_2
                       // | AT91C_HDMA_DST_PER_0
                        | AT91C_HDMA_SRC_H2SEL_HW
                        | AT91C_HDMA_DST_H2SEL_SW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );

    // TX channel 1
    DMA_SetConfiguration(DMA_CHANNEL_1,
                          AT91C_HDMA_SRC_PER_1
                        | AT91C_HDMA_DST_PER_1
                        | AT91C_HDMA_SRC_H2SEL_SW
                        | AT91C_HDMA_DST_H2SEL_HW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );


//AT91C_BASE_HDMA->HDMA_EN = AT91C_HDMA_ENABLE;
 // Enable DMA Interrupts
    DMA_EnableIt(  (DMA_CBTC << DMA_CHANNEL_0)
                 | (DMA_CBTC << DMA_CHANNEL_1));
	
		return 0;				
}
void SPI0_DMA_Enable(void)   @ "Fast_function_nc"
{
	if ((gdmadrv_dat.ulAlloc_ch&3) && gdmadrv_dat.chNum_alloc_ch)
	{
		//DMA_EnableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
		AT91C_BASE_HDMA->HDMA_CHER = ((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	}

}
void ConfigureGDmaSpi0_old(void)  @ "Fast_function"
{
	unsigned int dmaStatus;
	    // Enable DMA Peripheral
     AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_HDMA;//PERIPH_ENABLE(AT91C_ID_HDMA);
    // Enable DMA
    AT91C_BASE_HDMA->HDMA_EN = AT91C_HDMA_ENABLE;//DMA_Enable();
	
	 // Free status
    AT91C_BASE_HDMA->HDMA_EBCIDR = (0xFFFFFFFF);//DMA_DisableIt(0xFFFFFFFF);
    dmaStatus = ( AT91C_BASE_HDMA->HDMA_CHSR);//DMA_GetChannelStatus();
    dmaStatus = (AT91C_BASE_HDMA->HDMA_EBCISR);//DMA_GetStatus();<-Return DMA Interrupt Status
    DMA_DisableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_SADDR = (unsigned int)&(AT91C_BASE_SPI0->SPI_RDR);
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR = InitSpi0RVStatePdcDsc.lPR;
	//((long) &(spi0_rxbuff[0]))+0;
	
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR = InitSpi0TRStatePdcDsc.lPR;
	//((long) &(spi0_txbuff[0]))+0;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_DADDR = (unsigned int)&(AT91C_BASE_SPI0->SPI_TDR);
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA;
    dmaStatus &= ~(AT91C_HDMA_DONE); //
	dmaStatus |= (SIZE_LPDU_CNL_SPI>>1);
	dmaStatus |= AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD;
	dmaStatus |= (unsigned)AT91C_HDMA_DONE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA = dmaStatus;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB;
    dmaStatus &= 0;
	dmaStatus |= AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
	dmaStatus |= AT91C_HDMA_FC_PER2MEM;//AT91C_HDMA_FC_MEM2PER
	dmaStatus |= AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR;
	//AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR 
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB = dmaStatus ;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA;
    dmaStatus &= ~(AT91C_HDMA_DONE); //
	dmaStatus |= (SIZE_LPDU_CNL_SPI>>1);
	dmaStatus |= AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD;
	dmaStatus |= (unsigned)AT91C_HDMA_DONE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA = dmaStatus;
	
	dmaStatus = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB;
    dmaStatus &= 0;
	dmaStatus |= AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
	dmaStatus |= AT91C_HDMA_FC_MEM2PER;//AT91C_HDMA_FC_PER2MEM;//
	dmaStatus |= AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR;
	// AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB = dmaStatus ;
	
	
    // RX channel 0
    DMA_SetConfiguration(DMA_CHANNEL_0,
                          AT91C_HDMA_SRC_PER_2
                       // | AT91C_HDMA_DST_PER_0
                        | AT91C_HDMA_SRC_H2SEL_HW
                        | AT91C_HDMA_DST_H2SEL_SW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );

    // TX channel 1
    DMA_SetConfiguration(DMA_CHANNEL_1,
                          AT91C_HDMA_SRC_PER_1
                        | AT91C_HDMA_DST_PER_1
                        | AT91C_HDMA_SRC_H2SEL_SW
                        | AT91C_HDMA_DST_H2SEL_HW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );
	
	IRQ_ConfigureIT(AT91C_ID_HDMA, 0, HDMA_IrqHandler);
	
	IRQ_EnableIT(AT91C_ID_HDMA);

	// Enable the SPI TX & RX
    //WRITE_SPI(pSpiHw, SPI_CR, AT91C_SPI_SPIEN);

    // Start DMA 0(RX) && 1(TX)
    DMA_EnableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));

    // Enable DMA Interrupts
    DMA_EnableIt(  (DMA_CBTC << DMA_CHANNEL_0)
                 | (DMA_CBTC << DMA_CHANNEL_1));
	


}
//send callback

//Receive callback

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void DMAD_IrqHandler(void);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~         DMA controller interrupt handler                                   ~~~
//~~~ Processing:
//~~~  This function is called when a DMA interrupt occurs. It looks at          ~~~
//~~~  the DMA statuses and calls the user defined callback function             ~~~
//~~~  for the active DMA channel if it exists. If a callback function           ~~~
//~~~  doesn't exist, then interrupt support for the DMA channel is              ~~~
//~~~  disabled.                                                                 ~~~
//~~~                                                                            ~~~
//~~~ Parameters: 
//~~~  None     ~~~
//~~~                                                                  ~~~
//~~~ Outputs:
//~~~             None                                                     ~~~
//~~~ Returns:                                                             ~~
//~~~       The channel index, or _ERROR if a channel wasn't allocated   
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================

void DMAD_IrqHandler(void)  @ "Fast_function"
{
    unsigned long status;
register    long lch;
register    SDmaTransfer *pTransfer;
	void* pv;
    status = (AT91C_BASE_HDMA->HDMA_EBCISR);//DMA_GetStatus();//Get DMA statuses 
	
    // Check if the buffer transfer completed is set.
    if(status & AT91C_BTC)
	{
		pv =  gdmadrv_dat.pDmadTransfer;
		pTransfer =(SDmaTransfer*) pv;//gdmadrv_dat.pDmadTransfer;
		// Scan each channel status.
		for(lch = 0; lch < 8; lch++) {
            if(!(status & (DMA_BTC << lch))){
                continue;
            }
			
			if(gdmadrv_dat.cb[lch])
			gdmadrv_dat.cb[lch]();
		    pTransfer[lch].transferSize -= pTransfer[lch].bufSize;
		    // if next buffer is to be the last buffer in the transfer, then clear the automatic mode bit.
            if( pTransfer[lch].transferSize <=  pTransfer[lch].bufSize) {
                DMA_ClearAutoMode(lch);
            } 
		
            // Transfer finished
            if(pTransfer[lch].transferSize == 0) {
			
                //
				pTransfer += lch;
				//pTransfer = &(pTransfer.transfers[lch]);
				if(pTransfer->callback != NULL)
                pTransfer->callback();
                 AT91C_BASE_HDMA->HDMA_EBCIDR = (1 << lch);;//DMA_DisableIt(DMA_BTC << lch); 
                AT91C_BASE_HDMA->HDMA_CHDR |= 1 << lch;//DMA_DisableChannel(lch);
				pTransfer =(SDmaTransfer*) pv;
				
            }
            else
            {
                // Write the KEEPON field to clear the STALL states.
                DMA_KeeponChannel(lch);
            }
			
		
	    }
	}

}

extern volatile  long spi0_txsize;
extern volatile  long spi0_rxsize;
extern long spi0_txfill ;
extern long spi0_rxget  ;
extern long spi0_txget  ;
extern long spi0_rxfill ;
extern DmaLinkList chnl_Lst1,chnl_Lst2;

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void  Dmac_spi0_send_cb(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void  Dmac_spi0_send_cb(void) @ "Fast_function"
{
register long bwrite;
	//bwrite =  (AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA);//SIZE_LPDU_CNL_SPI;
	//bwrite &= AT91C_HDMA_BTSIZE;bwrite <<= 1;
	bwrite = (AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR)
	-  (chnl_Lst2.sourceAddress) ;
    if(spi0_txsize>=bwrite)
	{
    spi0_txsize = spi0_txsize - bwrite;
	spi0_txget  =  spi0_txget + bwrite;
	}
   else 
   {
   spi0_txget = spi0_txfill;spi0_txsize = 0;//It`s noncens but unfortunately possible
   }

	if(chEntry_Spi0<3)
	chEntry_Spi0++;
	else
	for(;;);
}
//---------------------------------------------------------------------------------
#define SIZE_SPI_BUF (SIZE_LPDU_CNL_SPI<<1)
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void Dmac_spi0_recv_cb(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void Dmac_spi0_recv_cb(void) @ "Fast_function"
{
register long bread;//
	
	//bread = ((StatePdcDsc*)pv)->shCtrPR;
	//bread += (((StatePdcDsc*)pv)->shCtrNPR) - (AT91C_BASE_SPI0->SPI_RCR);
	bread = AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR;
	bread -= chnl_Lst1.destAddress;//SIZE_LPDU_CNL_SPI;
	
  spi0_rxsize = spi0_rxsize + bread;
  spi0_rxfill = spi0_rxfill + bread;
  if (spi0_rxfill >= SIZE_SPI_BUF)
  {
    spi0_rxfill = 0;
  }

	
	//Clear Flags & Activate Analis
	if(chEntry_Spi0<3)
	chEntry_Spi0++;
	else
	for(;;);

}
//---------------------------------------------------------------------------------
DmaLinkList chnl_Lst1,chnl_Lst2;
void ConfigureGDmaSpi0(void) @ "Fast_function_nc"
{
unsigned int dmaStatus;

SDmaTransfer  DmaTransfer_Lst1, DmaTransfer_Lst2;
	 dmaStatus = Dma_init();
	//Set 
	 dmaStatus = Dma_alloc_channel(0,Dmac_spi0_recv_cb);
	 chnl_Lst1.sourceAddress = (unsigned int)&(AT91C_BASE_SPI0->SPI_RDR);
     chnl_Lst1.destAddress   = InitSpi0RVStatePdcDsc.lPR;
     chnl_Lst1.controlA      = AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD |
	 (SIZE_LPDU_CNL_SPI>>1)|(unsigned)AT91C_HDMA_DONE;
     chnl_Lst1.controlB      = AT91C_HDMA_FC_PER2MEM 
	 | AT91C_HDMA_SRC_ADDRESS_MODE_FIXED | AT91C_HDMA_DST_ADDRESS_MODE_INCR
	 | AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
     chnl_Lst1.descriptor    = 0;
	 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_SADDR = chnl_Lst1.sourceAddress;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR = chnl_Lst1.destAddress ;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA = chnl_Lst1.controlA; 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB = chnl_Lst1.controlB; 
	 
	 dmaStatus = Dma_alloc_channel(1,Dmac_spi0_send_cb);
	 chnl_Lst2.sourceAddress = InitSpi0TRStatePdcDsc.lPR;
     chnl_Lst2.destAddress   = (unsigned int)&(AT91C_BASE_SPI0->SPI_TDR);
     chnl_Lst2.controlA      = AT91C_HDMA_SRC_WIDTH_HALFWORD|AT91C_HDMA_DST_WIDTH_HALFWORD
	 |(SIZE_LPDU_CNL_SPI>>1)|(unsigned)AT91C_HDMA_DONE;
     chnl_Lst2.controlB      = AT91C_HDMA_FC_MEM2PER
	 |  AT91C_HDMA_DST_ADDRESS_MODE_FIXED | AT91C_HDMA_SRC_ADDRESS_MODE_INCR
	 | AT91C_HDMA_SRC_DSCR | AT91C_HDMA_DST_DSCR;
     chnl_Lst2.descriptor    = 0;
	 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR = chnl_Lst2.sourceAddress;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_DADDR = chnl_Lst2.destAddress ;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA = chnl_Lst2.controlA; 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB = chnl_Lst2.controlB; 
	 
	    // RX channel 0
    DMA_SetConfiguration(DMA_CHANNEL_0,
                          AT91C_HDMA_SRC_PER_2
                       // | AT91C_HDMA_DST_PER_0
                        | AT91C_HDMA_SRC_H2SEL_HW
                        | AT91C_HDMA_DST_H2SEL_SW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );

    // TX channel 1
    DMA_SetConfiguration(DMA_CHANNEL_1,
                         // AT91C_HDMA_SRC_PER_1 |
                         AT91C_HDMA_DST_PER_1
                        | AT91C_HDMA_SRC_H2SEL_SW
                        | AT91C_HDMA_DST_H2SEL_HW
                        | AT91C_HDMA_SOD_ENABLE
                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
                        );
	   // Start DMA 0(RX) && 1(TX)
    DMA_EnableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));

    // Enable DMA Interrupts
    DMA_EnableIt(  (DMA_CBTC << DMA_CHANNEL_0)
                 | (DMA_CBTC << DMA_CHANNEL_1));
	

}

long ReInitDmacChnl01(void) @ "Fast_function_nc"
{
	unsigned long dmaStatus;
	long  i;
	dmaStatus = 0;
	if ( (gdmadrv_dat.ulAlloc_ch&3) && gdmadrv_dat.chNum_alloc_ch)
	{
	dmaStatus = AT91C_BASE_HDMA->HDMA_EBCISR;
	i = ( AT91C_BASE_HDMA->HDMA_CHSR);//DMA_GetChannelStatus();
	//``DMA_DisableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	AT91C_BASE_HDMA->HDMA_CHDR = ((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	//Set 

	 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_SADDR = chnl_Lst1.sourceAddress;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR = chnl_Lst1.destAddress ;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA = chnl_Lst1.controlA; 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB = chnl_Lst1.controlB; 
	 

	 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR = chnl_Lst2.sourceAddress;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_DADDR = chnl_Lst2.destAddress ;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA = chnl_Lst2.controlA; 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB = chnl_Lst2.controlB; 
	 
	    // RX channel 0
		i = AT91C_HDMA_SRC_PER_2              
   | AT91C_HDMA_SRC_H2SEL_HW			   
   | AT91C_HDMA_DST_H2SEL_SW			   
   | AT91C_HDMA_SOD_ENABLE			   
   | AT91C_HDMA_FIFOCFG_ENOUGHSPACE; 	
   AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CFG = i;
//`    DMA_SetConfiguration(DMA_CHANNEL_0,
//`                          AT91C_HDMA_SRC_PER_2
//`                       // | AT91C_HDMA_DST_PER_0
//`                        | AT91C_HDMA_SRC_H2SEL_HW
//`                        | AT91C_HDMA_DST_H2SEL_SW
//`                        | AT91C_HDMA_SOD_ENABLE
//`                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
//`                        );

    // TX channel 1
	i =    //AT91C_HDMA_SRC_PER_1 |
  AT91C_HDMA_DST_PER_1
 | AT91C_HDMA_SRC_H2SEL_SW
 | AT91C_HDMA_DST_H2SEL_HW
 | AT91C_HDMA_SOD_ENABLE
 | AT91C_HDMA_FIFOCFG_ENOUGHSPACE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CFG = i;
   //` DMA_SetConfiguration(DMA_CHANNEL_1,
   //`                       AT91C_HDMA_SRC_PER_1
   //`                     | AT91C_HDMA_DST_PER_1
   //`                     | AT91C_HDMA_SRC_H2SEL_SW
   //`                     | AT91C_HDMA_DST_H2SEL_HW
   //`                     | AT91C_HDMA_SOD_ENABLE
   //`                     | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
   //`                     );
		   // Start DMA 0(RX) && 1(TX)
    //DMA_EnableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	//~AT91C_BASE_HDMA->HDMA_CHER = ((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));


	 // Enable DMA Interrupts
    //`DMA_EnableIt(  (DMA_CBTC << DMA_CHANNEL_0)
    //`             | (DMA_CBTC << DMA_CHANNEL_1));
	AT91C_BASE_HDMA->HDMA_EBCIER = 	(  (DMA_CBTC << DMA_CHANNEL_0)
                 | (DMA_CBTC << DMA_CHANNEL_1));	
				 
	}			 
	return dmaStatus;
}
long ReInitDmacChnl01_M(long lA) @ "Fast_function_nc"
{
	unsigned long dmaStatus;
	long  i;
	dmaStatus = 0;
	if ( (gdmadrv_dat.ulAlloc_ch&3) && gdmadrv_dat.chNum_alloc_ch)
	{
	dmaStatus = AT91C_BASE_HDMA->HDMA_EBCISR;
	i = ( AT91C_BASE_HDMA->HDMA_CHSR);//DMA_GetChannelStatus();
	//``DMA_DisableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	AT91C_BASE_HDMA->HDMA_CHDR = ((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	//Set 

	 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_SADDR = chnl_Lst1.sourceAddress;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_DADDR = chnl_Lst1.destAddress ;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLA = chnl_Lst1.controlA; 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CTRLB = chnl_Lst1.controlB; 
	 

	 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_SADDR = lA;//chnl_Lst2.sourceAddress;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_DADDR = chnl_Lst2.destAddress ;
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLA = chnl_Lst2.controlA; 
	 AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CTRLB = chnl_Lst2.controlB; 
	 
	    // RX channel 0
		i = AT91C_HDMA_SRC_PER_2              
   | AT91C_HDMA_SRC_H2SEL_HW			   
   | AT91C_HDMA_DST_H2SEL_SW			   
   | AT91C_HDMA_SOD_ENABLE			   
   | AT91C_HDMA_FIFOCFG_ENOUGHSPACE; 	
   AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_0].HDMA_CFG = i;
//`    DMA_SetConfiguration(DMA_CHANNEL_0,
//`                          AT91C_HDMA_SRC_PER_2
//`                       // | AT91C_HDMA_DST_PER_0
//`                        | AT91C_HDMA_SRC_H2SEL_HW
//`                        | AT91C_HDMA_DST_H2SEL_SW
//`                        | AT91C_HDMA_SOD_ENABLE
//`                        | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
//`                        );

    // TX channel 1
	i =    //AT91C_HDMA_SRC_PER_1 |
  AT91C_HDMA_DST_PER_1
 | AT91C_HDMA_SRC_H2SEL_SW
 | AT91C_HDMA_DST_H2SEL_HW
 | AT91C_HDMA_SOD_ENABLE
 | AT91C_HDMA_FIFOCFG_ENOUGHSPACE;
	AT91C_BASE_HDMA->HDMA_CH[DMA_CHANNEL_1].HDMA_CFG = i;
   //` DMA_SetConfiguration(DMA_CHANNEL_1,
   //`                       AT91C_HDMA_SRC_PER_1
   //`                     | AT91C_HDMA_DST_PER_1
   //`                     | AT91C_HDMA_SRC_H2SEL_SW
   //`                     | AT91C_HDMA_DST_H2SEL_HW
   //`                     | AT91C_HDMA_SOD_ENABLE
   //`                     | AT91C_HDMA_FIFOCFG_ENOUGHSPACE//AT91C_HDMA_FIFOCFG_LARGESTBURST
   //`                     );
		   // Start DMA 0(RX) && 1(TX)
    //DMA_EnableChannels((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));
	//~AT91C_BASE_HDMA->HDMA_CHER = ((1 << DMA_CHANNEL_0) | (1 << DMA_CHANNEL_1));


	 // Enable DMA Interrupts
    //`DMA_EnableIt(  (DMA_CBTC << DMA_CHANNEL_0)
    //`             | (DMA_CBTC << DMA_CHANNEL_1));
	AT91C_BASE_HDMA->HDMA_EBCIER = 	(  (DMA_CBTC << DMA_CHANNEL_0)
                 | (DMA_CBTC << DMA_CHANNEL_1));	
				 
	}			 
	return dmaStatus;
}




/* EOF */
