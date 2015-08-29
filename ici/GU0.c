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
* File Name       : GU0.c
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
#include "GU0.h"
#include "GU.h"
extern unsigned char chEntry_U0;
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
const Pin pinsU0[] = {
    PIN_USART0_RXD,//BOARD_PIN_USART_RXD,
    PIN_USART0_TXD,//BOARD_PIN_USART_TXD,
    PIN_USART0_CTS,//BOARD_PIN_USART_CTS,
    PIN_USART0_RTS//BOARD_PIN_USART_RTS
};
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
unsigned char chHdwErorU0;
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

/* UART device handles */
long uartdevU0 = 0;
// INT_32 hsuartdev = 0;
static unsigned char txbuff_U0 [512], rxbuff_U0 [512] @ "Fast_variable";
volatile  long txsize_U0 = 0, rxsize_U0 = 0;

 long txfill_U0  = 0;
 long rxget_U0   = 0; 
 long txget_U0   = 0;
 long rxfill_U0  = 0;

 long rx_US0_RCR_Val = 0, rx_US0_RNCR_Val = 0;
StatePdcDsc InitU0RVStatePdcDsc = {
0,
1,
SIZE_LPDU_CNL_U0,
SIZE_LPDU_CNL_U0,
((long) &(rxbuff_U0[0]))+0, 
((long) &(rxbuff_U0[0]))+SIZE_LPDU_CNL_U0,
0
};
StatePdcDsc InitU0TRStatePdcDsc = {
0,
1,
SIZE_LPDU_CNL_U0,
SIZE_LPDU_CNL_U0,
((long) &(txbuff_U0[0]))+0, 
((long) &(txbuff_U0[0]))+SIZE_LPDU_CNL_U0,
0
};

char chNumPacetInBufU0 = 0; 
unsigned char *Prxbuff_U0 = rxbuff_U0;
//.PIN_USART1_RXD
//.PIN_USART1_TXD
//.PIN_USART1_CTS
//.PIN_USART1_RTS
//.AT91C_BASE_US1
//.AT91C_ID_US1
volatile unsigned int bytesReceivedU0 = 0;

/// Receive buffer.
unsigned char pBufferU0[BUFFER_SIZE];
extern long lSpi0HdwState;
/// String buffer.
char pStringU0[24];
//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Interrupt handler for USART. Increments the number of bytes received in the
/// current second and starts another transfer if the desired bps has not been
/// met yet.
//------------------------------------------------------------------------------
void USART0_IrqHandler(void)   @ "Fastest_function"
{
    unsigned long status;
//AT91C_BASE_PIOD->PIO_SODR = (0x4);
    // Read USART status
    status = AT91C_BASE_US0->US_CSR;
	//RX_TRIG_INT || RX_TIMEOUT_INT
	if (status & (AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT) ) 
	{
		//Read Data
		u0_recv_cb1();
		if (status & AT91C_US_TIMEOUT)
		{
			u0_eof_cb();
		}
		
	}
	if (status & (AT91C_US_ENDTX|AT91C_US_TXBUFE) )
	{
		//Clear Interrupt
		//Send Msg If Need
		AT91C_BASE_US0->US_IDR = AT91C_US_ENDTX|AT91C_US_TXBUFE;
		u0_send_cb();
	}
	if (status & (AT91C_US_RXBRK|AT91C_US_OVRE|AT91C_US_FRAME|AT91C_US_PARE) )
	{
	    u0_error_cb();
	}
//	AT91C_BASE_PIOD->PIO_CODR = (0x4);
    // Receive buffer is full
  /*  if ((status & AT91C_US_RXBUFF) == AT91C_US_RXBUFF) {

        bytesReceivedU0 += BUFFER_SIZE;

        // Restart transfer if BPS is not high enough
        if (bytesReceivedU0 < MAX_BPS) {

            USART_ReadBuffer(AT91C_BASE_US0, pBufferU0, BUFFER_SIZE);
        }
        // Otherwise disable interrupt
        else {

            AT91C_BASE_US0->US_IDR = AT91C_US_RXBUFF;
        }
    }*/
}
//------------------------------------------------------------------------------
/// Configures USART in hardware handshaking mode, asynchronous, 8 bits, 1 stop
/// bit, no parity, 115200 bauds and enables its transmitter and receiver.
//------------------------------------------------------------------------------
void ConfigureUsart0(void)
{
    unsigned int mode = AT91C_US_USMODE_HWHSH
                        | AT91C_US_CLKS_CLOCK
                        | AT91C_US_CHRL_8_BITS
                        | AT91C_US_PAR_NONE
                        | AT91C_US_NBSTOP_1_BIT
                        | AT91C_US_CHMODE_NORMAL;

    // Enable the peripheral clock in the PMC
    PMC_EnablePeripheral(AT91C_ID_US0);//BOARD_ID_USART);

    // Configure the USART in the desired mode @115200 bauds
    USART_Configure(AT91C_BASE_US0, mode, 921600, BOARD_MCK);//BOARD_USART_BASE, mode, 115200, BOARD_MCK);

    // Configure the RXBUFF interrupt
    IRQ_ConfigureIT(AT91C_ID_US0, (AT91C_AIC_PRIOR_HIGHEST-2), USART0_IrqHandler);//BOARD_ID_USART, 0, USART1_IrqHandler);
    IRQ_EnableIT(AT91C_ID_US0);//BOARD_ID_USART);

    // Enable receiver & transmitter
    //USART_SetTransmitterEnabled(AT91C_BASE_US0,1);//BOARD_USART_BASE, 1);
    USART_SetReceiverEnabled(AT91C_BASE_US0,1);//BOARD_USART_BASE, 1);
}
void u0_hdw_init(void)
{

StatePdcDsc ValStatePdcDsc;
 Rst_LpduHSU0_TpCnState();
PIO_Configure(pinsU0, PIO_LISTSIZE(pinsU0));

   // Configure USART and display startup trace
   rx_US0_RCR_Val=40;
   AT91C_BASE_US0->US_IDR = 0xffffffff;
    ConfigureUsart0();//  ConfigureUsart();
   	 AT91C_BASE_US0->US_RPR = (unsigned int)&(rxbuff_U0[0]);
     AT91C_BASE_US0->US_RCR = 17;
	 AT91C_BASE_US0->US_RNPR = (unsigned int) &(rxbuff_U0[0]);
     AT91C_BASE_US0->US_RNCR = 30;
	//USART_WriteBuffer(AT91C_BASE_US0, (void*)&(txbuff_U0[0]), 10);
	AT91C_BASE_US0->US_TPR = (unsigned int)&(rxbuff_U0[0]);
    AT91C_BASE_US0->US_TCR = 10;
	AT91C_BASE_US0->US_RTOR = 0x14;//0xfa;//0x64
	
	 // Start receiving data and start timer
    ValStatePdcDsc.chAux            = 0;
	ValStatePdcDsc.chActivatePDC    = 1;
	ValStatePdcDsc.shCtrPR          = SIZE_LPDU_CNL_U0;
	ValStatePdcDsc.shCtrNPR         = SIZE_LPDU_CNL_U0;
	ValStatePdcDsc.lPR              = ((long) &(rxbuff_U0[0]))+0; 
	ValStatePdcDsc.lNPR             = ((long) &(rxbuff_U0[0]))+SIZE_LPDU_CNL_U0;
	ValStatePdcDsc.lCS_SR           = 0;
	rx_US0_RCR_Val = 20;//ValStatePdcDsc.shCtrPR;
	//USART_ReadBuffer(AT91C_BASE_US0, (void*)&(rxbuff_U0[0]), rx_US_RCR_Val);
	IciUsart_ReadBuf(AT91C_BASE_US0,( void *)&ValStatePdcDsc,1);
	ValStatePdcDsc.lPR              = ((long) &(txbuff_U0[0]))+0; 
	ValStatePdcDsc.lNPR             = ((long) &(txbuff_U0[0]))+SIZE_LPDU_CNL_U0;
	ValStatePdcDsc.lCS_SR           = 0;
	IciUsart_WriteBuf(AT91C_BASE_US0,( void *)&ValStatePdcDsc,1);
	
	
    //ConfigureUsart0();
   

 //spi0_hdw_init();
    AT91C_BASE_US0->US_IER = AT91C_US_RXBUFF|AT91C_US_ENDRX|AT91C_US_TIMEOUT;
	//|(AT91C_US_ENDTX|AT91C_US_TXBUFE);
	//|(AT91C_US_RXBRK|AT91C_US_OVRE|AT91C_US_FRAME|AT91C_US_PARE);
}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long outU0(unsigned char *dat, long bytes)  @ "Fast_function";
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

long outU0(unsigned char *dat, long bytes)  @ "Fast_function"
{
  //if ((hs2_txfill == hs2_txget)&&(hs2_txsize==0))
  //hs2_txget = hs2_txfill = 0;//.!!!
  if ((txfill_U0 == txget_U0)&&(txsize_U0 == 0))
  txget_U0 = txfill_U0 = 0;//.!!!
//-void IRQ_EnableIT(unsigned int source)  
//-void IRQ_DisableIT(unsigned int source)  
  while (bytes > 0)
  {
    while ((bytes > 0) && (txsize_U0 < 512))
    {
      txbuff_U0[txfill_U0] = *dat;
      txfill_U0++;
      if (txfill_U0 >= 512)
      {
        txfill_U0 = 0;
      }
      dat++;
      bytes--;
      //.int_disable(IRQ_UART_IIR2);
	  IRQ_DisableIT(AT91C_ID_US0);
      txsize_U0++;
      //.int_enable(IRQ_UART_IIR2);
	  IRQ_EnableIT(AT91C_ID_US0);
    }

    //.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US0);
    //...term_dat_send_cb();
	//.hs2_send_cb();
	u0_send_cb();
    //.int_enable(IRQ_UART_IIR2);
	IRQ_EnableIT(AT91C_ID_US0);
  }
  return 0;
}
//---------------------------------------------------------------------------------
//-extern INT_32 hs2uartdev;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long inU0(unsigned char *buff, int long)  @ "Fast_function";
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
long inU0(unsigned char *buff, long bytes)  @ "Fast_function"
{

int bread = 0;

  while ((bytes > 0) && (rxsize_U0 > 0))
  {
    *buff = rxbuff_U0[rxget_U0];
    buff++;
    rxget_U0++;
    if (rxget_U0 >= 512)
    {
      rxget_U0 = 0;
    }
    bytes--;
    bread++;
    //.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US0);
    rxsize_U0--;
    //.int_enable(IRQ_UART_IIR2);
	IRQ_EnableIT(AT91C_ID_US0);
  }
  if (rxfill_U0 == rxget_U0)
  {
	//.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US0);
	rxfill_U0 = rxget_U0 = 0;
	//.int_enable(IRQ_UART_IIR2);
	IRQ_EnableIT(AT91C_ID_US0);
  }
  if(chHdwErorU0)
  {
    //.int_disable(IRQ_UART_IIR2);
	IRQ_DisableIT(AT91C_ID_US0);
    //.int_clear(IRQ_UART_IIR2);
	u0_recover_cb();
	//,chHdwErorHSU0 = 0;
    //,bytes = hs_uart_recover(hs2uartdev);
	
  }
//
//.int_enable(IRQ_UART_IIR2);
IRQ_EnableIT(AT91C_ID_US0);
  return bread;
	
	
}
//---------------------------------------------------------------------------------
void ReInitInBufParamU0(void)
{
IRQ_DisableIT(AT91C_ID_US0);
rxsize_U0 = rxfill_U0 = rxget_U0 = 0;
Prxbuff_U0 = rxbuff_U0; 
IRQ_EnableIT(AT91C_ID_US0);
}

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u0_send_cb(void) @ "Fast_function";
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
void u0_send_cb(void) @ "Fast_function"
{
long bwrite, tosend = 512 -  txget_U0;
  //HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hsuartdev;
  //AT91S_USART *usart = AT91C_BASE_US0;
void *pv = (void*)&InitU0TRStatePdcDsc;  
  if (tosend > txsize_U0)
  {
    tosend = txsize_U0;
  }
  if (tosend == 0)
  {
    //phsuart->regptr->ctrl &= ~HSU_TX_INT_EN;
	AT91C_BASE_US0->US_CR = AT91C_US_TXDIS;
	AT91C_BASE_US0->US_IDR = AT91C_US_ENDTX|AT91C_US_TXBUFE;
	
	return;
  }
  else
  {
    //phsuart->regptr->ctrl |= HSU_TX_INT_EN;
	 AT91C_BASE_US0->US_IER |= (AT91C_US_ENDTX|AT91C_US_TXBUFE);
  }

  /* Write data */
  //bwrite = hs_uart_write(hsuartdev, &hs7_txbuff[ txget_U0], tosend);
  //USART_WriteBuffer(AT91C_BASE_US0,(void*)&txbuff_U0[txget_U0],tosend);
  ((StatePdcDsc*)pv)->chActivatePDC = 1;
  ((StatePdcDsc*)pv)->shCtrPR = tosend;
  ((StatePdcDsc*)pv)->shCtrNPR = 0;
  bwrite = IciUsart_WriteBuf(AT91C_BASE_US0,pv,1);
  
  if (bwrite==_NO_ERROR_GU)
  {
       bwrite = tosend;
	   //Activate Writing!!!
	   AT91C_BASE_US0->US_CR = AT91C_US_TXEN;
  }
  else
  {
      bwrite = 0;
	  
  }
  txsize_U0 = txsize_U0 - bwrite;
   txget_U0  =  txget_U0 + bwrite;
  if ( txget_U0 >= 512)
  {
     txget_U0 = 0;
  }

}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u0_recv_cb(void) @ "Fast_function";
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
void u0_recv_cb(void) @ "Fast_function"
{
register long bread;//, toreadmax = 512 - rxfill_U0;
//StatePdcDsc ValStatePdcDsc;

void *pv = (void*)&InitU0RVStatePdcDsc;
  /* Read data */
  
  //bread = hs_uart_read(hsuartdev, &hs7_rxbuff[hs7_rxfill], toreadmax);
  //.bread = rx_US_RCR_Val - (AT91C_BASE_US0->US_RCR);
  //.if( ((unsigned long)bread)>rx_US_RCR_Val) bread = rx_US_RCR_Val;
  
  bread = ((StatePdcDsc*)pv)->shCtrPR;
  bread -= AT91C_BASE_US0->US_RCR;
//  if(bread>64)//
// 	{
//		AT91C_BASE_US0->US_CR = AT91C_US_RXDIS;
//		InitTRStatePdcDsc.lPR = AT91C_BASE_US0->US_RCR;
//		InitTRStatePdcDsc.lNPR = AT91C_BASE_US0->US_RNCR;
//		//while(1);//Debug Code
//	}
//	 if( ((AT91C_BASE_US0->US_RNCR)==0))
//	{
//		AT91C_BASE_US0->US_CR = AT91C_US_RXDIS;
//		while(1);
//	} 
  rxsize_U0 = rxsize_U0 + bread;
  if( ((AT91C_BASE_US0->US_RNCR)==0))// &&((AT91C_BASE_US0->US_RNCR) != (SIZE_LPDU_CNL_U0)) )
	{
		//.AT91C_BASE_US0->US_CR = AT91C_US_RXDIS;
		chNumPacetInBufU0 += 2;//Scan 2 packet
		bytesReceivedU0 = (SIZE_LPDU_CNL_U0);// - (AT91C_BASE_US0->US_RCR);
		AT91C_BASE_US0->US_RNCR = 1; //For Block Repeat Entrance
		//bytesReceivedU0 += 
		//bytesReceivedU0 += bread;//-!!!  bread in this situation have fictiv Val
		bread = SIZE_LPDU_CNL_U0-4;// This is Only for correct Pacet analis in Time Out Int
		rxsize_U0 =  bread;
		//while(1);//Debug Code
	}
	
  rxfill_U0 = rxfill_U0 + bread;
  if (rxfill_U0 >= 512)
  {
    rxfill_U0 = 0;
	
  }
  
  
  if (rxsize_U0>= (SIZE_LPDU_CNL_U0-2))//In this Place start OverLoading UART DATA thinck about what to do?
  {
    bytesReceivedU0 += (SIZE_LPDU_CNL_U0)-(AT91C_BASE_US0->US_RCR);
	rx_US0_RCR_Val = 200;
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US0,pv,1);//( void *)&ValStatePdcDsc,0);
	
	//chEntry_U0++; jundled TimeOuts
  }
  else
  {
    //Look Start Byte
	
	//Then Detect size 
	
	//If Size == rxsize_U0+1 Start Hundle Packet
	
	rx_US0_RCR_Val=20;//
     //Save Changed field
     //.ValStatePdcDsc.shCtrPR = ((StatePdcDsc*)pv)->lNPR
     //.rx_US_RCR_Val;//Changed 
     
     //USART_ReadBuffer(AT91C_BASE_US0, (void*)&(rxbuff_U0[rxsize_U0]), rx_US_RCR_Val);
     //IciUsart_ReadBuf(AT91C_BASE_US0,( void *)&ValStatePdcDsc,0);
     //AT91C_BASE_US0->US_RPR  = &(rxbuff_U0[rxsize_U0])
	 
     //---AT91C_BASE_US0->US_RCR  = rx_US_RCR_Val;
  
  
  }

}
//---------------------------------------------------------------------------------


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u0_error_cb(void) @ "Fast_function";
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
void u0_error_cb(void) @ "Fast_function"
{
  AT91C_BASE_US0->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
  chHdwErorU0++;
	
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u0_eof_cb(void) @ "Fastest_function";
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
void u0_eof_cb(void) @ "Fastest_function" //Fast_function"
{
void *pv = (void*)&InitU0RVStatePdcDsc;
//.HSUART_CFG_T *phsuart = (HSUART_CFG_T *) hsuartdev;

//if need Start Process of Analises

//hs7_rxfill = hs7_rxget = hs7_rxsize = 0;
	//chEntry_Hs7++;
	//This ->US_RCR==200 Var Analog Must Signaled that have more then One Packet
	if((rx_US0_RCR_Val == 200)&&(chNumPacetInBufU0>=2)) //bytesReceivedU0== (SIZE_LPDU_CNL_U0)
	{
		
		//bytesReceivedU0 += (SIZE_LPDU_CNL_U0)-(AT91C_BASE_US0->US_RCR);//Na samom dele na 1 menshe
          rx_US0_RCR_Val += (SIZE_LPDU_CNL_U0)-(AT91C_BASE_US0->US_RCR);//Sho popalo dlya obrobki 
	}	
	else
	chNumPacetInBufU0++;
	
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US0,pv,1);
	
	AT91C_BASE_US0->US_CR = AT91C_US_STTTO;
	chEntry_U0++;
	if(chEntry_U0 >= 2)
	{
		
		if (lSpi0HdwState)//if (chNumPacetInBufU0)
		u0_recover_cb(); return;//u2_error_cb();
		__disable_irq();//else
		while(1);
                if (chNumPacetInBufU0)
		u0_eof_cb();
	
		__enable_irq();
	}
}
//---------------------------------------------------------------------------------
long ulAmountReinitU0 = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u0_recover_cb(void) @ "Fast_function";
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
void u0_recover_cb(void) @ "Fast_function"
{
void *pv = (void*)&InitU0RVStatePdcDsc;

	AT91C_BASE_US0->US_CR = AT91C_US_RSTRX | AT91C_US_RSTTX | AT91C_US_RXDIS | AT91C_US_TXDIS;
	AT91C_BASE_US0->US_CR = AT91C_US_RSTSTA|AT91C_US_RSTRX;
	chHdwErorU0 = 0;
	//.((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US0,pv,1);
	ReInitInBufParam();
	//AT91C_BASE_US0->US_CR = AT91C_US_STTTO;
	//chEntry_U0++;
	if(chEntry_U0 >= 2)
	chEntry_U0 = 0;//while(1);//Error Fix Point
	ulAmountReinitU0++;
	USART_SetReceiverEnabled(AT91C_BASE_US0,1);
}
//---------------------------------------------------------------------------------




















//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void u0_recv_cb1(void) @ "Fastest_function";
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
void u0_recv_cb1(void) @ "Fastest_function" //Fast_function"
{
register long bread;//, toreadmax = 512 - rxfill_U0;
//StatePdcDsc ValStatePdcDsc;

void *pv = (void*)&InitU0RVStatePdcDsc;
  /* Read data */
  

  
  bread = ((StatePdcDsc*)pv)->shCtrPR;
  bread -= AT91C_BASE_US0->US_RCR;

  
  if( ((AT91C_BASE_US0->US_RNCR)==0))//
	{
		//OverLoading Packet Size
		AT91C_BASE_US0->US_RNCR = 1; //For Block Repeat Entrance
		bread = ((StatePdcDsc*)pv)->shCtrPR;//SIZE_LPDU_CNL_U0;
		//bread = SIZE_LPDU_CNL_U0-4;// This is Only for correct Pacet analis in Time Out Int
		if( ((AT91C_BASE_US0->US_RCR)==0))
		bread += ((StatePdcDsc*)pv)->shCtrNPR;//SIZE_LPDU_CNL_U0;
		else
		bread += ( ((StatePdcDsc*)pv)->shCtrNPR) - (AT91C_BASE_US0->US_RCR);
	}
	
	rxsize_U0 = rxsize_U0 + bread;
	if(rxsize_U0 >= 512)//Size_of_Buf
	{
		rxsize_U0 -= 512;
	}
    rxfill_U0 = rxfill_U0 + bread;
    if (rxfill_U0 >= 512)
    {
      rxfill_U0 -= 512;
  	
    }
	
  
  
  if (rxsize_U0>= (SIZE_LPDU_CNL_U0-2))//In this Place start OverLoading UART DATA thinck about what to do?
  {
    bytesReceivedU0 += (SIZE_LPDU_CNL_U0)-(AT91C_BASE_US0->US_RCR);//Only Demo Value
	
	((StatePdcDsc*)pv)->chActivatePDC = 0;
	IciUsart_ReadBuf(AT91C_BASE_US0,pv,1);//( void *)&ValStatePdcDsc,0);
	
	//chEntry_U0++; jundled TimeOuts
  }
  else
  {

  
  }

}
//---------------------------------------------------------------------------------


/* EOF */



