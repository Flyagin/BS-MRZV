/*------------------------------------------------------------------------------
* Created (c) 2014 - Factory “KyivPrylad”
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
* File Name       : Tc_g45.c
* Description     : Functions and Data for service Timer Interrupt Functions
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  22/05/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include "../LibG45/peripherals/pio/pio.h"
//.#include "../LibG45/peripherals/usart/usart.h"
#include "../LibG45/peripherals/irq/irq.h"
#include "../LibG45/peripherals/pmc/pmc.h"
#include "../LibG45/boards/bs_g45/at91sam9g45/AT91SAM9G45.h"
#include <intrinsics.h>
//.#include "lpu.h"
//.#include "GU2.h"
//.#include "GU0.h"
//.#include "GU.h"

#include "../LibG45/peripherals/tc/tc.h"
#include "TC_G45.h"
static long lCtrIntr;
char chGErorLedInfo = 0;//Ok 1-Fatal Error;2 -Diagn Info Evt



long lInInt = 0;
void TC_irq_handler ( void ) @ "Fastest_function" //Fast_function"
{
	register long i,j,k;
	register void* pv;
//AT91C_BASE_PIOD->PIO_SODR = (0x2);
	lInInt++;
//Process there Interrupts from timers
	pv = (void*)&TCIrqData;
	//((AT91S_TC*)pv)->TC_CCR
	i = ((AT91TC_IrqData_Dsc*)pv)->chAmountUseTimers;
	//((AT91TC_IrqData_Dsc*)pv)->chIdxProcessTimer = i;
	if(i ==0)//This part of Program activate when Interrupt rise while process Unregister Function
	{
	//State ReSort arChRefNum
	//Find Source of Interrupt
		for (i = 0; i < 7; i++)
		{
			k = (long)((AT91TC_IrqData_Dsc*)pv)->arAT91TC_BASE_Pointers[i];
			if( k && (((AT91S_TC*)k)->TC_IMR) )
			{
			     j = ((AT91S_TC*)k)->TC_SR;
				((AT91TC_IrqData_Dsc*)pv)->arStatusReg[i] = j;
				if(j)
				{
				    k = (long)((AT91TC_IrqData_Dsc*)pv)->arPF_TC_irq_handlers[i];
				    if (k)
				    {
				    	(((AT91TC_IrqData_Dsc*)pv)->arPF_TC_irq_handlers[j])();//Call Interrupt
				    }	
				}
			}
		
		}
	}
	while(i)//chAmountUseTimers)
	{
		j = ((AT91TC_IrqData_Dsc*)pv)->arChRefNum[8-i];//Id Timer
		if(j<8)
		{
			k = (long)((AT91TC_IrqData_Dsc*)pv)->arAT91TC_BASE_Pointers[j];
			if( k && (((AT91S_TC*)k)->TC_IMR) )// fOR ADDITIONAL Controls 
			{
				((AT91TC_IrqData_Dsc*)pv)->arStatusReg[j] = (((AT91S_TC*)k)->TC_SR);//Need for transmit Int Hndlr for Processs
				k = (long)((AT91TC_IrqData_Dsc*)pv)->arPF_TC_irq_handlers[j];
				if (k)
				{
					
					(((AT91TC_IrqData_Dsc*)pv)->arPF_TC_irq_handlers[j])();//Call Interrupt
				}	
			}
		}
		i--;
	}
//TC1_irq_handler();

lCtrIntr++;
i = chGErorLedInfo;
if(lCtrIntr>=10000)
{
 
  AT91C_BASE_PIOD->PIO_SODR = (1<<21);
//  if(chGErorLedInfo)
	i &=3;//if((chGErorLedInfo&1) == 0)
	if(i)
     AT91C_BASE_PIOD->PIO_SODR = (1<<20);//Red
  if (lCtrIntr>20000)
    lCtrIntr = 0;
  
  
}
else {
	AT91C_BASE_PIOD->PIO_CODR = (1<<21);
	i &= 1;//if((chGErorLedInfo&1) == 0)
	if(i == 0)
	AT91C_BASE_PIOD->PIO_CODR = (1<<20);//Red
}
lInInt--;
//AT91C_BASE_PIOD->PIO_CODR = (0x2);
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

AT91TC_IrqData_Dsc  TCIrqData = {
0,0,0,0,
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10},
{0,0,0,0,0,0,0,0}
};


#include "Tc1_g45.c"




/* EOF */






