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

//-#include "lpu.h"
//-#include "GU2.h"
#include "GU.h"
extern unsigned char chEntry_U2;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long IciUsart_ReadBuf(AT91S_USART *usart,void *buffer,long size) @ "Fastest_function";
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
long IciUsart_ReadBuf(AT91S_USART *usart,
                                      void *buffer,
                                      long size) @ "Fastest_function"
{
register long i;    

	i =  ((StatePdcDsc*)buffer)->chActivatePDC;
	//i = size;
	if (i!=1)
	{
	    
		usart->US_RPR  = (unsigned int) ((StatePdcDsc*)buffer)->lPR;
		usart->US_RCR  = ((StatePdcDsc*)buffer)->shCtrPR;//size;
		usart->US_RNPR = (unsigned int) ((StatePdcDsc*)buffer)->lNPR;
		usart->US_RNCR = ((StatePdcDsc*)buffer)->shCtrNPR;
	    //usart->US_PTCR = AT91C_PDC_RXTEN;
		if (size==0)
		usart->US_PTCR = AT91C_PDC_RXTDIS;
		((StatePdcDsc*)buffer)->lCS_SR	= 	usart->US_PTSR;
	}
	else
	{
		//Stop Previous Receiving
		usart->US_PTCR =  AT91C_PDC_RXTDIS;
		//Reset to Default Val
		usart->US_RPR  = (unsigned int) ((StatePdcDsc*)buffer)->lPR;
		usart->US_RCR  = ((StatePdcDsc*)buffer)->shCtrPR;//size;
		usart->US_RNPR = (unsigned int) ((StatePdcDsc*)buffer)->lNPR;
		usart->US_RNCR = ((StatePdcDsc*)buffer)->shCtrNPR;
		usart->US_PTCR = AT91C_PDC_RXTEN;
		((StatePdcDsc*)buffer)->lCS_SR	= 	usart->US_PTSR;
	}
	
	
//.	// Check if the first PDC bank is free
//.    if ((usart->US_RCR == 0) && (usart->US_RNCR == 0)) {
//.
//.        usart->US_RPR = (unsigned int) buffer;
//.        usart->US_RCR = size;
//.        usart->US_PTCR = AT91C_PDC_RXTEN;
//.
//.        return 1;
//.    }
//.    // Check if the second PDC bank is free
//.    else if (usart->US_RNCR == 0) {
//.
//.        usart->US_RNPR = (unsigned int) buffer;
//.        usart->US_RNCR = size;
//.
//.        return 1;
//.    }
//.    else {
//.
//.        return 0;
//.    }
	
	return _NO_ERROR_GU;
}

//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long IciUsart_WriteBuf(AT91S_USART *usart,void *buffer,long size);
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
long IciUsart_WriteBuf(
    AT91S_USART *usart,
    void *buffer,
    long size) @ "Fast_function"
{
register long i;    

	i =  ((StatePdcDsc*)buffer)->chActivatePDC;
	//i = size;
	if (i!=1)
	{
	    usart->US_TPR  = (unsigned int) ((StatePdcDsc*)buffer)->lPR;
		usart->US_TCR  = ((StatePdcDsc*)buffer)->shCtrPR;//size;
		usart->US_TNPR = (unsigned int) ((StatePdcDsc*)buffer)->lNPR;
		usart->US_TNCR = ((StatePdcDsc*)buffer)->shCtrNPR;
	    //usart->US_PTCR = AT91C_PDC_RXTEN;
		if (size==0)
		usart->US_PTCR = AT91C_PDC_TXTDIS;
		((StatePdcDsc*)buffer)->lCS_SR	= 	usart->US_PTSR;
	
	}
	else
	{
	    //Stop Previous Receiving
		usart->US_PTCR =  AT91C_PDC_TXTDIS;
		//Reset to Default Val
		usart->US_TPR  = (unsigned int) ((StatePdcDsc*)buffer)->lPR;
		usart->US_TCR  = ((StatePdcDsc*)buffer)->shCtrPR;//size;
		usart->US_TNPR = (unsigned int) ((StatePdcDsc*)buffer)->lNPR;
		usart->US_TNCR = ((StatePdcDsc*)buffer)->shCtrNPR;
		usart->US_PTCR = AT91C_PDC_TXTEN;
	    ((StatePdcDsc*)buffer)->lCS_SR	= 	usart->US_PTSR;
	}
	
    return _NO_ERROR_GU;
	

}


//---------------------------------------------------------------------------------




/* EOF */

