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
* File Name       : GSpi0.h
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

#ifndef GSpi0_h
#define GSpi0_h

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~        ~~~
/* NO_ERROR macro */
//#define _NO_ERROR_GSPI           (long)(0)
/* ERROR macro */
//#define _ERROR_GSPI              (long)(-1)
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
//typedef struct StatePdcDsc_tag
//{
//	char   chAux;
//	char   chActivatePDC;
//	short      shCtrPR;
//	short      shCtrNPR;
//	long   lPR;
//	long   lNPR;
//	long   lCS_SR;
//}StatePdcDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern unsigned char chHdwErorSpi0;
extern unsigned char chEntry_Spi0;
extern long lNssRise;
extern  unsigned char uchAmtSend, uchAmtReceive;
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void spi0_hdw_init(void);

unsigned long SPI_Read_Ici(AT91S_SPI *spi,long lCounter);
unsigned long CheckSpi0State(long lWaitTime);


long outSpi0(unsigned char *dat, long bytes)  @ "Fastest_function";
long  inSpi0(unsigned char *buff,long bytes)  @ "Fastest_function";

__arm long InSpi0(unsigned char *buff, int long)  @ "Fast_function"; 
__arm long OutSpi0(unsigned char *dat, long bytes)  @ "Fast_function";

void spi0_send_cb(void)  ;//@ "Fast_function";
void spi0_recv_cb(void)  ;//@ "Fast_function";
void spi0_error_cb(void) ;//@ "Fast_function";
void spi0_eof_cb(void)   ;//@ "Fast_function";
void spi0_recover_cb(void) @ "Fast_function";
void Spi0_Rst(void) @ "Fast_function";
void DisblGSpiInt(void)  @ "Fast_function";
void EnblGSpiInt(void)  @ "Fast_function";
extern void ReInitSpi0Param(void)  @ "Fast_function_nc";
extern void Spi0HdwRstAndDmac(void)   @ "Fast_function_nc";


void ReInitInBufParamSpi0(void);

 void Spi0Init(void);
extern  void PIO_CfgInput(
    AT91S_PIO *pio,
    unsigned int mask,
    unsigned char enablePullUp,
    unsigned char enableFilter);
extern void PIO_CfgOutput(
    AT91S_PIO *pio,
    unsigned int mask,
    unsigned char defaultValue,
    unsigned char enableMultiDrive,
    unsigned char enablePullUp);


	
extern void PIOA4_IrqHandler(void);
extern void PIOC8_IrqHandler(void);
extern void PIOE31_IrqHandler(void);

	
	
#endif 
/* GSpi0_h */
