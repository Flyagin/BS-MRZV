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
* File Name       : GU2.c
* Description     : Definition of AT91SAM9G45-BS characteristics, 
                    AT91SAM9G45-dependant PIOs and external components
					interfacing.
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  16/10/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
//#include <pio/pio.h>
//#include <usart/usart.h>
#include "../LibG45/peripherals/pio/pio.h"
#include "../LibG45/peripherals/usart/usart.h"
#include "../LibG45/peripherals/irq/irq.h"
#include "../LibG45/peripherals/pmc/pmc.h"
#include "../LibG45/boards/bs_g45/at91sam9g45/AT91SAM9G45.h"
#include <intrinsics.h>
#include "lpu.h"
#include "GU2.h"
#include "GU0.h"
#include "GU.h"
#include <string.h>
#include <stdio.h>

extern unsigned char chEntry_U2;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
/*
#define SIZE_LPDU_CNL_1 200

#define SIZE_LPDU_CNL_DOUBLE_ACCESS_MEMORY  512

#define SIZE_LPDU_CNL_HSU7 100

#define SIZE_LPDU_CNL_U3   60

#define SIZE_LPDU_CNL_HSU1 100
#define SIZE_LPDU_CNL_HSU2 100

#define SIZE_LPDU_CNL_SPI  512

#define SIZE_LPDU_CNL_HSU2 100//USART


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
const Pin pins[] = {
    PIN_USART2_RXD,//BOARD_PIN_USART_RXD,
    PIN_USART2_TXD//BOARD_PIN_USART_TXD,
    //PIN_USART2_CTS,//BOARD_PIN_USART_CTS,
    //PIN_USART2_RTS//BOARD_PIN_USART_RTS
};
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
unsigned char chHdwErorU2;
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
extern unsigned char chEOI_U2;
/* UART device handles */
long uartdevU2 = 0; volatile  long txsize_U2 @ "DMA_BUFFERS";
// INT_32 hsuartdev = 0;DMA_BUFFERS
static unsigned char txbuff_U2 [512] @ "Fast_variable", rxbuff_U2 [512]  @ "Fast_variable";
volatile  long txsize_U2 = 0  , rxsize_U2 = 0;
 long txfill_U2 @ "DMA_BUFFERS";
 long txfill_U2  = 0;
 long rxget_U2   = 0; 
 long txget_U2   = 0;
 long rxfill_U2  = 0;

 long rx_US_RCR_Val = 0, rx_US_RNCR_Val = 0;
StatePdcDsc InitRVStatePdcDsc = {
0,
1,
SIZE_LPDU_CNL_HSU2,
SIZE_LPDU_CNL_HSU2,
((long) &(rxbuff_U2[0]))+0, 
((long) &(rxbuff_U2[0]))+SIZE_LPDU_CNL_HSU2,
0
};
StatePdcDsc InitTRStatePdcDsc = {
0,
1,
SIZE_LPDU_CNL_HSU2,
SIZE_LPDU_CNL_HSU2,
((long) &(txbuff_U2[0]))+0, 
((long) &(txbuff_U2[0]))+SIZE_LPDU_CNL_HSU2,
0
};

char chNumPacetInBuf = 0; 
unsigned char *Prxbuff_U2 = rxbuff_U2;
//.PIN_USART1_RXD
//.PIN_USART1_TXD
//.PIN_USART1_CTS
//.PIN_USART1_RTS
//.AT91C_BASE_US1
//.AT91C_ID_US1
volatile unsigned int bytesReceived = 0;

/// Receive buffer.
unsigned char pBuffer[BUFFER_SIZE];

/// String buffer.
char pString[24];
//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Interrupt handler for USART. Increments the number of bytes received in the
/// current second and starts another transfer if the desired bps has not been
/// met yet.
//------------------------------------------------------------------------------
void USART2_IrqHandler(void) @ "Fast_function"
{
    unsigned long status;

    // Read USART status
    status = AT91C_BASE_US2->US_CSR;
	//RX_TRIG_INT || RX_TIMEOUT_INT
	if (status & (AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT) ) 
	{
		//Read Data
		u2_recv_cb();
		if (status & AT91C_US_TIMEOUT)
		{
			u2_eof_cb();
		}
		AT91C_BASE_PIOB->PIO_CODR = (1 << 11);//?
	}
	if (status & (AT91C_US_ENDTX|AT91C_US_TXBUFE) )
	{
		//Clear Interrupt
		//Send Msg If Need
		AT91C_BASE_US2->US_IDR = AT91C_US_ENDTX|AT91C_US_TXBUFE;
		u2_send_cb();
	}
	if (status & (AT91C_US_RXBRK|AT91C_US_OVRE|AT91C_US_FRAME|AT91C_US_PARE) )
	{
	    u2_error_cb();
	}
	
    // Receive buffer is full
  /*  if ((status & AT91C_US_RXBUFF) == AT91C_US_RXBUFF) {

        bytesReceived += BUFFER_SIZE;

        // Restart transfer if BPS is not high enough
        if (bytesReceived < MAX_BPS) {

            USART_ReadBuffer(AT91C_BASE_US2, pBuffer, BUFFER_SIZE);
        }
        // Otherwise disable interrupt
        else {

            AT91C_BASE_US2->US_IDR = AT91C_US_RXBUFF;
        }
    }*/
}
//------------------------------------------------------------------------------
/// Configures USART in hardware handshaking mode, asynchronous, 8 bits, 1 stop
/// bit, no parity, 115200 bauds and enables its transmitter and receiver.
//------------------------------------------------------------------------------
void ConfigureUsart(void)
{
    unsigned int mode = AT91C_US_USMODE_NORMAL
                        | AT91C_US_CLKS_CLOCK
                        | AT91C_US_CHRL_8_BITS
                        | AT91C_US_PAR_NONE
                        | AT91C_US_NBSTOP_1_BIT
                        | AT91C_US_CHMODE_NORMAL;

    // Enable the peripheral clock in the PMC
    PMC_EnablePeripheral(AT91C_ID_US2);//BOARD_ID_USART);

    // Configure the USART in the desired mode @115200 bauds
    USART_Configure(AT91C_BASE_US2, mode, 921600, BOARD_MCK);//BOARD_USART_BASE, mode, 115200, BOARD_MCK);

    // Configure the RXBUFF interrupt
    IRQ_ConfigureIT(AT91C_ID_US2, (AT91C_AIC_PRIOR_HIGHEST-2), USART2_IrqHandler);//BOARD_ID_USART, 0, USART1_IrqHandler);
    IRQ_EnableIT(AT91C_ID_US2);//BOARD_ID_USART);

    // Enable receiver & transmitter
    //USART_SetTransmitterEnabled(AT91C_BASE_US2,1);//BOARD_USART_BASE, 1);
    USART_SetReceiverEnabled(AT91C_BASE_US2,1);//BOARD_USART_BASE, 1);
}
void u2_hdw_init(void)
{

StatePdcDsc ValStatePdcDsc;
 Rst_LpduHSU2_TpCnState();
PIO_Configure(pins, PIO_LISTSIZE(pins));

   // Configure USART and display startup trace
   rx_US_RCR_Val=40;
   AT91C_BASE_US2->US_IDR = 0xffffffff;
      ConfigureUsart();
   	 AT91C_BASE_US2->US_RPR = (unsigned int)&(rxbuff_U2[0]);
     AT91C_BASE_US2->US_RCR = 17;
	 AT91C_BASE_US2->US_RNPR = (unsigned int) &(rxbuff_U2[0]);
     AT91C_BASE_US2->US_RNCR = 30;
	//USART_WriteBuffer(AT91C_BASE_US2, (void*)&(txbuff_U2[0]), 10);
	AT91C_BASE_US2->US_TPR = (unsigned int)&(rxbuff_U2[0]);
    AT91C_BASE_US2->US_TCR = 10;
	AT91C_BASE_US2->US_RTOR = 0x14;//0xfa;//0x64
	
	 // Start receiving data and start timer
    ValStatePdcDsc.chAux            = 0;
	ValStatePdcDsc.chActivatePDC    = 1;
	ValStatePdcDsc.shCtrPR          = SIZE_LPDU_CNL_HSU2;
	ValStatePdcDsc.shCtrNPR         = SIZE_LPDU_CNL_HSU2;
	ValStatePdcDsc.lPR              = ((long) &(rxbuff_U2[0]))+0; 
	ValStatePdcDsc.lNPR             = ((long) &(rxbuff_U2[0]))+SIZE_LPDU_CNL_HSU2;
	ValStatePdcDsc.lCS_SR           = 0;
	rx_US_RCR_Val = 20;//ValStatePdcDsc.shCtrPR;
	//USART_ReadBuffer(AT91C_BASE_US2, (void*)&(rxbuff_U2[0]), rx_US_RCR_Val);
	IciUsart_ReadBuf(AT91C_BASE_US2,( void *)&ValStatePdcDsc,1);
	ValStatePdcDsc.lPR              = ((long) &(txbuff_U2[0]))+0; 
	ValStatePdcDsc.lNPR             = ((long) &(txbuff_U2[0]))+SIZE_LPDU_CNL_HSU2;
	ValStatePdcDsc.lCS_SR           = 0;
	IciUsart_WriteBuf(AT91C_BASE_US2,( void *)&ValStatePdcDsc,1);
	
	
    //ConfigureUsart();
   

spi0_hdw_init();
    AT91C_BASE_US2->US_IER = AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT;
	//|(AT91C_US_ENDTX|AT91C_US_TXBUFE);
	//|(AT91C_US_RXBRK|AT91C_US_OVRE|AT91C_US_FRAME|AT91C_US_PARE);
//	u0_hdw_init();
    TC1Init ();
	TC2Init ();                                            // Init
	//((AT91S_TC*)AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKDIS; // for Dbg Only
	((AT91S_TC*)AT91C_BASE_TC2)->TC_SR;                    // 
	
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outU2(unsigned char *dat, long bytes)  @ "Fast_function";
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

long outU2(unsigned char *dat, long bytes)  @ "Fast_function"
{
__istate_t s;
long ltxsize_U2;
	if(bytes == 0) return 1;
	if (txget_U2 != txfill_U2) while(1);// //long lMask;
//lMask = AT91C_BASE_US2->US_IMR;//The 1 - Enable
//lMask &=  AT91C_US_ENDTX|AT91C_US_TXBUFE;
  //if ((hs2_txfill == hs2_txget)&&(hs2_txsize==0))
  //hs2_txget = hs2_txfill = 0;//.!!!
  if ((txfill_U2 == txget_U2)&&(txsize_U2 == 0))
  txget_U2 = txfill_U2 = 0;//.!!!
//-void IRQ_EnableIT(unsigned int source)  
//-void IRQ_DisableIT(unsigned int source)  
//AT91C_BASE_US2->US_IDR = AT91C_US_ENDTX|AT91C_US_TXBUFE;
//AT91C_BASE_US2->US_IER = lMask;
	ltxsize_U2 = txsize_U2;	// 
	#ifdef USE_PIO_SYNC	
		AT91C_BASE_PIOD->PIO_CODR = (1 << 29);
	#endif	
		// 
		// 
  while (bytes > 0)
  {
    while ((bytes > 0) && (txsize_U2 < 512))
    {
      txbuff_U2[txfill_U2] = *dat;
      txfill_U2++;
      if (txfill_U2 >= 512)
      {
        txfill_U2 = 0;
      }
      dat++;
      bytes--;
      //.int_disable(IRQ_UART_IIR2);
	  //``IRQ_DisableIT(AT91C_ID_US2);
	  ltxsize_U2++;//txsize_U2++;
     
	  //AT91C_US_ENDTX|AT91C_US_TXBUFE;
      //``int_enable(IRQ_UART_IIR2);
	  //.IRQ_EnableIT(AT91C_ID_US2);
    }
   }
//AT91C_BASE_US2->US_IER = lMask;
    //.int_disable(IRQ_UART_IIR2);
	//IRQ_DisableIT(AT91C_ID_US2);
	
    //...term_dat_send_cb();
	//.hs2_send_cb();
	s = __get_interrupt_state();__disable_interrupt();txsize_U2 = ltxsize_U2;
	u2_send_cb();
    //.int_enable(IRQ_UART_IIR2);
	//IRQ_EnableIT(AT91C_ID_US2);
	if (txget_U2 != txfill_U2) while(1);//
  __set_interrupt_state(s);
  AT91C_BASE_US2->US_IER |= (AT91C_US_ENDTX|AT91C_US_TXBUFE);
  return 0;
}
//---------------------------------------------------------------------------------
//-extern INT_32 hs2uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inU2(unsigned char *buff, int long)  @ "Fast_function";
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
long inU2(unsigned char *buff, long bytes)  @ "Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (rxsize_U2 > 0))
  {
    *buff = rxbuff_U2[rxget_U2];
    buff++;
    rxget_U2++;
    if (rxget_U2 >= 512)
    {
      rxget_U2 = 0;
    }
    bytes--;
    bread++;
    //.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US2);
    rxsize_U2--;
    //.int_enable(IRQ_UART_IIR2);
	IRQ_EnableIT(AT91C_ID_US2);
  }
  if (rxfill_U2 == rxget_U2)
  {
	//.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US2);
	rxfill_U2 = rxget_U2 = 0;
	//.int_enable(IRQ_UART_IIR2);
	IRQ_EnableIT(AT91C_ID_US2);
  }
  if(chHdwErorU2)
  {
    //.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US2);
    //.int_clear(IRQ_UART_IIR2);
	u2_recover_cb();
	//,chHdwErorHSU2 = 0;
    //,bytes = hs_uart_recover(hs2uartdev);
	
  }
//
//.int_enable(IRQ_UART_IIR2);
IRQ_EnableIT(AT91C_ID_US2);
  return bread;
	
	
}
//---------------------------------------------------------------------------------
void ReInitInBufParam(void)
{
IRQ_DisableIT(AT91C_ID_US2);
rxsize_U2 = rxfill_U2 = rxget_U2 = 0;
Prxbuff_U2 = rxbuff_U2; 
IRQ_EnableIT(AT91C_ID_US2);
}

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u2_send_cb(void) @ "Fast_function";
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
void u2_send_cb(void) @ "Fast_function"
{
long bwrite, tosend = 512 -  txget_U2;
  //HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hsuartdev;
  //AT91S_USART *usart = AT91C_BASE_US2;
void *pv = (void*)&InitTRStatePdcDsc;  
  if (tosend > txsize_U2)
  {
    tosend = txsize_U2;
  }
  if (tosend == 0)
  {
    //phsuart->regptr->ctrl &= ~HSU_TX_INT_EN;
	//	AT91C_BASE_US2->US_CR = AT91C_US_STTBRK;
	//AT91C_BASE_US2->US_CR = AT91C_US_STPBRK ;
	if((AT91C_BASE_US2->US_PTSR)&(AT91C_PDC_TXTEN))
	{
	chEOI_U2 |= 0x1;//chEOI_U2++;//TimeOut On Send
	#ifdef USE_PIO_SYNC	
		AT91C_BASE_PIOD->PIO_SODR = (1 << 29);
	#endif
	}
    AT91C_BASE_US2->US_CR = AT91C_US_TXDIS;//|AT91C_US_RSTTX
	AT91C_BASE_US2->US_IDR = AT91C_US_ENDTX|AT91C_US_TXBUFE;
	AT91C_BASE_US2->US_PTCR = AT91C_PDC_TXTDIS;
	//AT91C_BASE_US2->US_CR = AT91C_US_RSTTX

	
	return;
  }
  else
  {
    //phsuart->regptr->ctrl |= HSU_TX_INT_EN;
	 //AT91C_BASE_US2->US_IER |= (AT91C_US_ENDTX|AT91C_US_TXBUFE);
  }

  /* Write data */
  //bwrite = hs_uart_write(hsuartdev, &hs7_txbuff[ txget_U2], tosend);
  //USART_WriteBuffer(AT91C_BASE_US2,(void*)&txbuff_U2[txget_U2],tosend);
  ((StatePdcDsc*)pv)->chActivatePDC = 1;
  ((StatePdcDsc*)pv)->shCtrPR = tosend;
  chEOI_U2 = 0x40;
  if(tosend>50) 
  __asm volatile("BKPT 4");
  ((StatePdcDsc*)pv)->shCtrNPR = 0;
  bwrite = IciUsart_WriteBuf(AT91C_BASE_US2,pv,1);
  
  if (bwrite==_NO_ERROR_GU)
  {
       bwrite = tosend;
	   //Activate Writing!!!
	   AT91C_BASE_US2->US_CR = AT91C_US_TXEN;
  }
  else
  {
      bwrite = 0;
	  
  }
  txsize_U2 = txsize_U2 - bwrite;
   txget_U2  =  txget_U2 + bwrite;
  if ( txget_U2 >= 512)
  {
     txget_U2 = 0;
  }
   //AT91C_BASE_US2->US_IER |= (AT91C_US_ENDTX|AT91C_US_TXBUFE);
	if (txget_U2 != txfill_U2) while(1);//
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u2_recv_cb(void) @ "Fast_function";
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
void u2_recv_cb(void) @ "Fast_function"
{
register long bread;//, toreadmax = 512 - rxfill_U2;
//StatePdcDsc ValStatePdcDsc;

void *pv = (void*)&InitRVStatePdcDsc;
  /* Read data */
  
  //bread = hs_uart_read(hsuartdev, &hs7_rxbuff[hs7_rxfill], toreadmax);
  //.bread = rx_US_RCR_Val - (AT91C_BASE_US2->US_RCR);
  //.if( ((unsigned long)bread)>rx_US_RCR_Val) bread = rx_US_RCR_Val;
    if(chEntry_U2 >= 1)
	ulAmountReinitU2++;
  bread = ((StatePdcDsc*)pv)->shCtrPR;
  bread -= AT91C_BASE_US2->US_RCR;
//  if(bread>64)//
// 	{
//		AT91C_BASE_US2->US_CR = AT91C_US_RXDIS;
//		InitTRStatePdcDsc.lPR = AT91C_BASE_US2->US_RCR;
//		InitTRStatePdcDsc.lNPR = AT91C_BASE_US2->US_RNCR;
//		//while(1);//Debug Code
//	}
//	 if( ((AT91C_BASE_US2->US_RNCR)==0))
//	{
//		AT91C_BASE_US2->US_CR = AT91C_US_RXDIS;
//		while(1);
//	} 
  rxsize_U2 = rxsize_U2 + bread;
  if( ((AT91C_BASE_US2->US_RNCR)==0))// &&((AT91C_BASE_US2->US_RNCR) != (SIZE_LPDU_CNL_HSU2)) )
	{
		//.AT91C_BASE_US2->US_CR = AT91C_US_RXDIS;
		chNumPacetInBuf += 2;//Scan 2 packet
		bytesReceived = (SIZE_LPDU_CNL_HSU2);// - (AT91C_BASE_US2->US_RCR);
		AT91C_BASE_US2->US_RNCR = 1; //For Block Repeat Entrance
		//bytesReceived += 
		//bytesReceived += bread;//-!!!  bread in this situation have fictiv Val
		bread = SIZE_LPDU_CNL_HSU2-4;// This is Only for correct Pacet analis in Time Out Int
		rxsize_U2 =  bread;
		//while(1);//Debug Code
	}
	
  rxfill_U2 = rxfill_U2 + bread;
  if (rxfill_U2 >= 512)
  {
    rxfill_U2 = 0;
  }

  
  if (rxsize_U2>= (SIZE_LPDU_CNL_HSU2-2))
  {
    bytesReceived += (SIZE_LPDU_CNL_HSU2)-(AT91C_BASE_US2->US_RCR);
	rx_US_RCR_Val = 200;
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US2,pv,1);//( void *)&ValStatePdcDsc,0);
	
	//chEntry_U2++; jundled TimeOuts
  }
  else
  {
    //Look Start Byte
	
	//Then Detect size 
	
	//If Size == rxsize_U2+1 Start Hundle Packet
	
	rx_US_RCR_Val=20;//
     //Save Changed field
     //.ValStatePdcDsc.shCtrPR = ((StatePdcDsc*)pv)->lNPR
     //.rx_US_RCR_Val;//Changed 
     
     //USART_ReadBuffer(AT91C_BASE_US2, (void*)&(rxbuff_U2[rxsize_U2]), rx_US_RCR_Val);
     //IciUsart_ReadBuf(AT91C_BASE_US2,( void *)&ValStatePdcDsc,0);
     //AT91C_BASE_US2->US_RPR  = &(rxbuff_U2[rxsize_U2])
	 
     //---AT91C_BASE_US2->US_RCR  = rx_US_RCR_Val;
  
  
  }

}
//---------------------------------------------------------------------------------


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u2_error_cb(void) @ "Fast_function";
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
void u2_error_cb(void) @ "Fast_function"
{
  AT91C_BASE_US2->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
  chHdwErorU2++;
	AT91C_BASE_PIOB->PIO_CODR = (1 << 11);
}
//---------------------------------------------------------------------------------
unsigned long ulIciPrevCallCounter = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u2_eof_cb(void) @ "Fast_function";
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
void u2_eof_cb(void) @ "Fast_function"
{
void *pv = (void*)&InitRVStatePdcDsc;
//.HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hsuartdev;

//if need Start Process of Analises

//hs7_rxfill = hs7_rxget = hs7_rxsize = 0;
	//chEntry_Hs7++;
	//This ->US_RCR==200 Var Analog Must Signaled that have more then One Packet
	if((rx_US_RCR_Val == 200)&&(chNumPacetInBuf>=2)) //bytesReceived== (SIZE_LPDU_CNL_HSU2)
	{
		
		//bytesReceived += (SIZE_LPDU_CNL_HSU2)-(AT91C_BASE_US2->US_RCR);//Na samom dele na 1 menshe
          rx_US_RCR_Val += (SIZE_LPDU_CNL_HSU2)-(AT91C_BASE_US2->US_RCR);//Sho popalo dlya obrobki 
	}	
	else
	chNumPacetInBuf++;
	
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US2,pv,1);
	
	AT91C_BASE_US2->US_CR = AT91C_US_STTTO;
	chEntry_U2++;lEndU2Tr++;
	if(chEntry_U2 >= 2)
	{
		if(ulIciPrevCallCounter < ulIciCallCounter)
		{
			ulIciPrevCallCounter = ulIciCallCounter - ulIciPrevCallCounter;
		}
		else
		{
			
			if(ulIciPrevCallCounter > ulIciCallCounter)
			{
				ulIciPrevCallCounter = 0xffffffff-ulIciPrevCallCounter;
				ulIciPrevCallCounter = (1+ulIciCallCounter) - ulIciPrevCallCounter;
			}
			else
			{
			//Situation when on USART2  send phisically pacet size more then 2 TDPU
			}
			
		}
		if(ulIciPrevCallCounter>2)
		chEntry_U2++;//possible out of resources Else OverLoading or Bad TimeOut Situation
		u2_recover_cb();return;
		__disable_irq();
		//if (chNumPacetInBuf)
		//u2_error_cb();
		//else
		while(1);
                if (chNumPacetInBuf)
		u2_error_cb();
	
		__enable_irq();
	}
	ulIciPrevCallCounter = ulIciCallCounter;
}
//---------------------------------------------------------------------------------
long ulAmountReinitU2 = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u2_recover_cb(void) @ "Fast_function";
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
void u2_recover_cb(void) @ "Fast_function"
{
void *pv = (void*)&InitRVStatePdcDsc;

	//AT91C_BASE_US2->US_CR = AT91C_US_RSTRX | AT91C_US_RSTTX | AT91C_US_RXDIS | AT91C_US_TXDIS;
	//AT91C_BASE_US2->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
	AT91C_BASE_US2->US_CR = AT91C_US_RSTRX |  AT91C_US_RXDIS ;
	AT91C_BASE_US2->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
	chNumPacetInBuf = chHdwErorU2 = 0;
	//.((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US2,pv,1);
	ReInitInBufParam();
	//AT91C_BASE_US2->US_CR = AT91C_US_STTTO;
	//chEntry_U2++;
	if (hldrHSU2LpduTRUnit.uchLpuHSU2State )
	hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
	if(chEntry_U2 >= 2)
	chEntry_U2 = 1;//while(1);//Error Fix Point
	ulAmountReinitU2++;
	USART_SetReceiverEnabled(AT91C_BASE_US2,1);
	AT91C_BASE_PIOB->PIO_SODR = (1 << 11);//PB11 Set;//PB11 Set
	 
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u2_recv_cb1(void) @ "Fastest_function";
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
void u2_recv_cb1(void) @ "Fastest_function" //Fast_function"
{
register long bread;//, toreadmax = 512 - rxfill_U0;
//StatePdcDsc ValStatePdcDsc;

void *pv = (void*)&InitRVStatePdcDsc;//void *pv = (void*)&InitU0RVStatePdcDsc;
  /* Read data */
  

  
  bread = ((StatePdcDsc*)pv)->shCtrPR;
  bread -= AT91C_BASE_US2->US_RCR;

  
  if( ((AT91C_BASE_US2->US_RNCR)==0))//
	{
		//OverLoading Packet Size
		AT91C_BASE_US2->US_RNCR = 1; //For Block Repeat Entrance
		bread = ((StatePdcDsc*)pv)->shCtrPR;//SIZE_LPDU_CNL_U;
		//bread = SIZE_LPDU_CNL_U0-4;// This is Only for correct Pacet analis in Time Out Int
		if( ((AT91C_BASE_US2->US_RCR)==0))
		bread += ((StatePdcDsc*)pv)->shCtrNPR;//SIZE_LPDU_CNL_U;
		else
		bread += ( ((StatePdcDsc*)pv)->shCtrNPR) - (AT91C_BASE_US2->US_RCR);
	}
	
	rxsize_U2 = rxsize_U2 + bread;
	if(rxsize_U2 >= 512)//Size_of_Buf
	{
		rxsize_U2 -= 512;
	}
    rxfill_U2 = rxfill_U2 + bread;
    if (rxfill_U2 >= 512)
    {
      rxfill_U2 -= 512;
  	
    }
	
  
  
  if (rxsize_U2>= (SIZE_LPDU_CNL_U2-2))//In this Place start OverLoading UART DATA thinck about what to do?
  {
    //bytesReceivedU2 += (SIZE_LPDU_CNL_U2)-(AT91C_BASE_US2->US_RCR);//Only Demo Value
	bytesReceived += (SIZE_LPDU_CNL_HSU2)-(AT91C_BASE_US2->US_RCR);
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US2,pv,1);//( void *)&ValStatePdcDsc,0);
	
	//chEntry_U2++; jundled TimeOuts
  }
  else
  {

  
  }

}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long OutU2(unsigned char *dat, long bytes)  @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:  Send some data on the terminal interface                         ~~~
//~~~ Processing: Place data into the TX ring buffer and start UART transmission ~~~
//~~~        ~~~
//~~~  dat   : Data to send                                                      ~~~
//~~~  bytes : Number of bytes to send                                           ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~          ~~
//~~~          ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
__arm long OutU2(unsigned char *dat, long bytes) 
{
register long bsend; 
  if ((txfill_U2 == txget_U2)&&(txsize_U2 == 0))
  txget_U2 = txfill_U2 = 0;//.!!!
  if (bytes>512)
  bytes = 512;//SIZE_U2_BUF;//correctness Control
	
////__disable_interrupt();
if ((bytes+txfill_U2) > 512)
	bytes = 512- txfill_U2;
	else
	bsend = bytes;
	
	if ((txsize_U2 + bytes)>= (512))
	bsend = 512 - txsize_U2;
	else
	bsend = bytes;
	memcpy(txbuff_U2+txfill_U2,dat,bsend);
	u2_send_cb();
	//txsize_U2 += bsend; <-Modify in u2_send_cb
	//if (bsend)

	txfill_U2+= bsend;
    if (txfill_U2 >= (512))
    {
      txfill_U2 -= 512;
    }
	

	
	
//__enable_interrupt();//
  return bsend;
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long InU2(unsigned char *buff, int long)  @ "Fast_function"; //Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose: Read some data from U2  ring buffer                              ~~~
//~~~ Processing: Move data from the ring buffer to the passed buffer            ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Returns: Number of bytes actually read                                      ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
__arm long InU2(unsigned char *buff, int long bytes)
{
int bread = 0;
long lMask;
	
//__disable_interrupt();
AT91C_BASE_US2->US_IDR = (AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT);
	if ( bytes > rxsize_U2)
	   bread = rxsize_U2;
	else 
	bread = bytes;
	if (bread >= (512))
    {
      bread -= 512;
    }
	
	if((rxget_U2+bread)>512)
	{
		memcpy(buff,rxbuff_U2+rxget_U2,512- rxget_U2);
		memcpy(buff+(512- rxget_U2),rxbuff_U2+0,bread-(512- rxget_U2));
	}
	else
	{
		memcpy(buff,rxbuff_U2+rxget_U2,bread);
	}
	
	rxget_U2 += bread;//bytes;
	if (rxget_U2 >= (512))
    {
      rxget_U2 -= 512;
    }
	
	rxsize_U2 -= bread; 
	
	if (rxfill_U2 == rxget_U2)
	{
		//```IRQ_DisableIT(AT91C_ID_US2);
		//AT91C_BASE_US2->US_IDR = (AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT);
		rxfill_U2 = rxget_U2 = 0;
		//```IRQ_EnableIT(AT91C_ID_US2);
		lMask = AT91C_BASE_US2->US_IMR;//The 1 - Enable
		lMask |=  (AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT);
		AT91C_BASE_US2->US_IER |= lMask;
	}
	if(chHdwErorU2)
	{
		//AT91C_BASE_US2->US_IDR = 0xffffffff;
		 IRQ_DisableIT(AT91C_ID_US2);
		u2_recover_cb();
		//AT91C_BASE_US2->US_IER = AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT;
		 IRQ_EnableIT(AT91C_ID_US2);
	}	
	 return bread;
}	
//Late move this vars&func to Lpu.c file it's part protocol not uart
long lBlockHSU2Ctr = 0x1ffff;
void HSU2StallHundler(void)
{
//Try reset HSU Link Leyer
lBlockHSU2Ctr = 0x1ffff;
//chHdwErorU2++;
//Rst_LpduHSU2_TpCnState();
hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
}

FILE * pFileOutU2;
char chFileOutU2State = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
__arm long outU2File(unsigned char *dat, long bytes)  @ "Fast_function";
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
__arm long outU2File(unsigned char *dat, long bytes)  @ "Fast_function"
{
register long bsend; 
  if ((txfill_U2 == txget_U2)&&(txsize_U2 == 0))
  txget_U2 = txfill_U2 = 0;//.!!!
  if (bytes>512)
  bytes = 512;//SIZE_U2_BUF;//correctness Control
	
////__disable_interrupt();
if ((bytes+txfill_U2) > 512)
	bytes = 512- txfill_U2;
	else
	bsend = bytes;
	
	if ((txsize_U2 + bytes)>= (512))
	bsend = 512 - txsize_U2;
	else
	bsend = bytes;
	memcpy(txbuff_U2+txfill_U2,dat,bsend);
	//u2_send_cb();
	pFileOutU2 = fopen ("BsOutU2.txt","w+" );//  ab     if( (chFileOutU2State&1)==0)
	if(pFileOutU2!=NULL)
	{
	bsend = fseek(pFileOutU2,0,SEEK_SET);
	bsend = fwrite(txbuff_U2,sizeof(char),txsize_U2,pFileOutU2);
	fclose(pFileOutU2);
	}

	//txsize_U2 += bsend; <-Modify in u2_send_cb
	//if (bsend)

	txfill_U2+= bsend;
    if (txfill_U2 >= (512))
    {
      txfill_U2 -= 512;
    }
	

	
	
//__enable_interrupt();//
  return bsend;
}




/*
#include "../LibG45/peripherals/tc/tc.h"
static long lCtrIntr;


void TC_irq_handler ( void );
void TC1_irq_handler ( void );
long RegisterTC1 ( void );
long UnRegisterTC1 ( void );
extern AT91TC_IrqData_Dsc  TCIrqData;
long lInInt = 0;
void TC_irq_handler ( void ) @ "Fast_function"
{
//lInInt++;
//Process there Interrupts from timers
TC1_irq_handler();

lCtrIntr++;
if(lCtrIntr>=10000)
{
  AT91C_BASE_PIOD->PIO_SODR = (0x1);
  if (lCtrIntr>20000)
    lCtrIntr = 0;
  
  
}
else 
AT91C_BASE_PIOD->PIO_CODR = (0x1);
//lInInt--;
}

void TC1_irq_handler ( void ) @ "Fast_function"
{
register long i;
  i = AT91C_BASE_TC1->TC_SR;//Clear Status
//   lInInt++;
  TC_Stop(AT91C_BASE_TC1);//TC0Stop();
  //i = WrFaulttoFlash4();
  //if(i ==0)  
  //TC0Start();
  Scan_Ici_Event_Req(); //
  Scan_Ici_Entry_Data();//
  TC_Start(AT91C_BASE_TC1);
//lInInt--;
}

void TC_Init(void *pInitAT91TCDsc)
{
    register void *pv = ((InitAT91TCDsc*)pInitAT91TCDsc)->pTC;
	register unsigned long rV = 0;
	// Disable TC clock
    //pTc->TC_CCR = AT91C_TC_CLKDIS;
((AT91S_TC*)pv)->TC_CCR = AT91C_TC_CLKDIS;
rV = ((InitAT91TCDsc*)pInitAT91TCDsc)->at91c_id_tc_Val;
//rV = AT91C_ID_TC;

	AT91C_BASE_PMC->PMC_PCER =   (1 << rV);
	 
    // Disable interrupts
    //pTc->TC_IDR   = 0xFFFFFFFF;
	((AT91S_TC*)pv)->TC_IDR   = 0xFFFFFFFF;
    //pTc->->TC_RC  =  
	((AT91S_TC*)pv)->TC_RC  =  ((InitAT91TCDsc*)pInitAT91TCDsc)->ul_RC_Val;
	//pTc->->TC_CMR = AT91C_TC_CLKS_TIMER_DIV2_CLOCK  | AT91C_TC_CPCTRG;
	((AT91S_TC*)pv)->TC_CMR  =   ((InitAT91TCDsc*)pInitAT91TCDsc)->ul_CMR_Val;
	//IRQ_DisableIT(AT91C_ID_TC2);
    //IRQ_ConfigureIT(AT91C_ID_TC2, (AT91C_AIC_PRIOR_LOWEST+1), TC2_fiq_handler);
    // IRQ_EnableIT(AT91C_ID_TC2);
    IRQ_DisableIT(rV);
    IRQ_ConfigureIT(rV, 
	(((InitAT91TCDsc*)pInitAT91TCDsc)->ul_Prior_Val), TC_irq_handler );
	//(void (*)(void))((InitAT91TCDsc*)pInitAT91TCDsc)->pf_TC_irq_handler);
     IRQ_EnableIT(rV);
    
	
	pv = ((InitAT91TCDsc*)pInitAT91TCDsc)->pTC;
  //AT91C_BASE_TC2->TC_CCR = AT91C_TC_CLKEN;//Enable Clock
  //AT91C_BASE_TC2->TC_IER = AT91C_TC_CPCS;
 
  ((AT91S_TC*)pv)->TC_IER = AT91C_TC_CPCS;
   ((AT91S_TC*)pv)->TC_CCR = AT91C_TC_CLKEN;//Enable Clock

}

void TC1Init ( void ) @ "Fast_function"
{
  unsigned long  i;//,j;
  InitAT91TCDsc locAT91_TC1_Cfg = {
  AT91C_ID_TC, //..unsigned long at91c_id_tc_Val;
  AT91C_TC_CLKS_TIMER_DIV1_CLOCK  | AT91C_TC_CPCTRG,//..unsigned long ul_CMR_Val;//Mode of Timer
  (AT91C_AIC_PRIOR_LOWEST+1),                       //..unsigned long ul_Prior_Val;//PRIOR for AIC
  6500,//..unsigned long ul_RC_Val;
  (void*)TC1_irq_handler,//..void* pf_TC_irq_handler;
  AT91C_BASE_TC1,//..void *pTC;
  };
  
  if ( (TCIrqData.uChActiveTimers==0) )
  {
		//Init Timer
		 TC_Init((void *)&locAT91_TC1_Cfg);
		//That means Timer!
		i = RegisterTC1();
		TC_Start(AT91C_BASE_TC1);
  
  }
  else
  {
	//Change Configuration
		//Unregister &Stop Timer
		TC_Stop(AT91C_BASE_TC1);
		//i =  UnRegisterTC1(); Need for Clear All Info About Timer 1
		//TC_ConfiG()//Same Func as TC_Init but set only Timer Periph Only
		//TC_Start(AT91C_BASE_TC1);
	
  }
  

  
}


long RegisterTC1 ( void ) @ "Fast_function"
{
  int i = 0;
  if( ((TCIrqData.uChActiveTimers&2)==0) && ((TCIrqData.uChShadowActiveTimers &2) == 0) )
  {
	TCIrqData.arPF_TC_irq_handlers   [1]   = TC1_irq_handler;
	TCIrqData.arAT91TC_BASE_Pointers [1]   = AT91C_BASE_TC1;
	 TCIrqData.uChActiveTimers      |= 2;
    TCIrqData.uChShadowActiveTimers |= 2; 
	i = TCIrqData.uChActiveTimers;
  }
  //else
  return i;
}
/*
long UnRegisterTC1 ( void ) @ "Fast_function"
{
  if( (TCIrqData.uChActiveTimers&2) == (TCIrqData.uChShadowActiveTimers &2) )
  {
	TCIrqData.arPF_TC_irq_handlers   [1]   = TC1_irq_handler;
	TCIrqData.arAT91TC_BASE_Pointers [1]   = AT91C_BASE_TC1;
	 TCIrqData.uChActiveTimers      |= 2;
    TCIrqData.uChShadowActiveTimers |= 2; 
  }
}
/

AT91TC_IrqData_Dsc  TCIrqData = {
0,0,0,0,
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}

};
*/





/* EOF */



