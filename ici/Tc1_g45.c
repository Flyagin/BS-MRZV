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
* File Name       : Tc1_g45.c
* Description     : Functions and Data for service Timer! Interrupt Functions
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  22/05/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include <assert.h>
#include <stdio.h>
#include <string.h>




unsigned long ulIciCallCounter = 0;
unsigned long ulReqIciCall     = 1;






//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
void TC1_irq_handler ( void ) @ "Fastest_function"; //Fast_function"
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:  Handle ici on Bs                         ~~~
//~~~ Processing:  ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes: Will block until all bytes are sent                                  ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
void TC1_irq_handler ( void ) @ "Fastest_function" //Fast_function"
{
register long i;
struct 
	{
		//unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		unsigned short ushSize;
		//unsigned char *pUchRV;
		PflMdlRcdDsc locPflMdlRcd;
		
	} sLV;

  i = AT91C_BASE_TC1->TC_SR;//Clear Status
//   lInInt++;
  AT91C_BASE_TC1->TC_CCR = AT91C_TC_CLKDIS; //...TC_Stop(AT91C_BASE_TC1);//TC0Stop();
 do
  {
	
	if(PflData.shR == 3)
	{
		//...PflData.IdxWrPflrMdlRcd = 0;
		//...PflData.lAmtPflrMdlRcd  = 1;
		//shOrderNumProcessingRecord
		//(AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKEN | AT91C_TC_SWTRG;//TC_Start
		
		TC2_Start();
		//i = WrFaulttoFlash4();
		//if(i ==0)  
		//TC0Start();
		sLV.locPflMdlRcd.Id_Module = 0;
		CreatePflrMdlRcd(1,((AT91S_TC*)AT91C_BASE_TC2)->TC_CV,(void*)&(sLV.locPflMdlRcd) );
		sLV.locPflMdlRcd.IciCallCounterVal = ulIciCallCounter;
		//locPflMdlRcd.Id_Module
		//~PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
	}
	//Put Text Msg
	//,, InsertDscMsg(__FILE__,__LINE__,  sLV.locPflMdlRcd.Id_Module,__func__,"1");
  
	Scan_Ici_Event_Req(); //
	if(PflData.shR == 3)
	{
		sLV.locPflMdlRcd.Cv_End = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
		sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
//		PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
	}
	//
	//
	Scan_Ici_Entry_Data();//
	
	ulIciCallCounter++;
  
    if(PflData.shR == 3)
    {
  
		((AT91S_TC*)AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKDIS;//TC Stop
		i = ((AT91S_TC*)AT91C_BASE_TC2)->TC_SR;
		i = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
		sLV.locPflMdlRcd.Cv_End = i;
		sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
//		PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
		if (i>(CRITICAL_TIME_EXEC_INT))
		{
//			SaveCurrIciCallSlises();
			sLV.uChIdxByte = ulReqIciCall;
			ulReqIciCall = 1;
			((AT91S_TC*)AT91C_BASE_TC2)->TC_RC  = 650;
		
		}
		else
			((AT91S_TC*)AT91C_BASE_TC2)->TC_RC  = 6500;//sLV.uChIdxByte = 0;
		//Put Text Msg
//		 InsertDscMsg(__FILE__,__LINE__,  sLV.locPflMdlRcd.Id_Module,__func__,"EoInt");
//		if (PflData.IdxFillRcd == 6) 
//		OutTerminalCurrPflrData((void*)&PflData);
//		if (PflDataSaveBig.IdxFillRcd == 7) 
//		OutTerminalCurrPflrData((void*)&PflDataSaveBig);
		
		PflData.shOrderNumProcessingRecord = 0;
    }
	
	//Control SPI Point Ready or Not
	//If Time MoreOver Fix that data discard and louse then increase (appropriate)corresponding variables
  } while(--ulReqIciCall);
  
  AT91C_BASE_TC1->TC_CCR = AT91C_TC_CLKEN | AT91C_TC_SWTRG;//TC_Start(AT91C_BASE_TC1);
 ulReqIciCall = 1;

//lInInt--;
}
/*
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
*/
void TC1Init ( void ) @ "Fast_function"
{
  unsigned long  i;//,j;
  InitAT91TCDsc locAT91_TC1_Cfg = {
  AT91C_ID_TC, //..unsigned long at91c_id_tc_Val;
  AT91C_TC_CLKS_TIMER_DIV1_CLOCK  | AT91C_TC_CPCTRG,//..unsigned long ul_CMR_Val;//Mode of Timer
  (AT91C_AIC_PRIOR_HIGHEST-3),                       //..unsigned long ul_Prior_Val;//PRIOR for AIC
  6500,//..unsigned long ul_RC_Val;
  (void*)TC1_irq_handler,//..void* pf_TC_irq_handler;
  AT91C_BASE_TC1,//..void *pTC;
  };
  
  if ( (TCIrqData.uChActiveTimers==0) )
  {
		
		//That means Timer!
		i = RegisterTC1();
		if (i)
		{
		    //Init Timer
		    TC_Init((void *)&locAT91_TC1_Cfg);
		    TC_Start(AT91C_BASE_TC1);
		}
  
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
void TC2Init ( void ) @ "Fast_function"
{
  unsigned long  i;//,j;
  register void *pv;
  InitAT91TCDsc locAT91_TC2_Cfg = {
  AT91C_ID_TC, //..unsigned long at91c_id_tc_Val;
  AT91C_TC_CLKS_TIMER_DIV2_CLOCK,//..unsigned long ul_CMR_Val;//Mode of Timer
  (AT91C_AIC_PRIOR_LOWEST),                       //..unsigned long ul_Prior_Val;//PRIOR for AIC
  0xffff,//..unsigned long ul_RC_Val;
  (void*)0,//..void* pf_TC_irq_handler;
  AT91C_BASE_TC2,//..void *pTC;
  };
  PflData.shR = 2;
  if ( (TCIrqData.uChActiveTimers==0) )
  {
		
		//That means Timer!
		//.i = RegisterTC2();
		//.if (i)
		{
		    //Init Timer
		    TC_Init((void *)&locAT91_TC2_Cfg);
		    //TC_Start(AT91C_BASE_TC1);
		}
  
  }
  else
  {
	//Change Configuration
		//Unregister &Stop Timer
		TC_Stop(AT91C_BASE_TC2);
		//i =  UnRegisterTC1(); Need for Clear All Info About Timer 1
		//TC_ConfiG()//Same Func as TC_Init but set only Timer Periph Only
		//TC_Start(AT91C_BASE_TC1);
	
  }
pv = locAT91_TC2_Cfg.pTC; // ((InitAT91TCDsc*)pInitAT91TCDsc)->pTC;
  ((AT91S_TC*)pv)->TC_CCR = AT91C_TC_CLKDIS;
  ((AT91S_TC*)pv)->TC_IDR   = 0xFFFFFFFF;
  ((AT91S_TC*)pv)->TC_RC  =  locAT91_TC2_Cfg.ul_RC_Val;//((InitAT91TCDsc*)pInitAT91TCDsc)->ul_RC_Val;
  ((AT91S_TC*)pv)->TC_CMR  = locAT91_TC2_Cfg.ul_CMR_Val;//  ((InitAT91TCDsc*)pInitAT91TCDsc)->ul_CMR_Val;
  
   (AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKEN | AT91C_TC_SWTRG;
((AT91S_TC*)AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKDIS; // for Dbg Only
	PflData.IdxWrPflrMdlRcd = 0;
	PflData.lAmtPflrMdlRcd  = 1;
  PflData.shR = 3;

}



//First Enable Active Timers
//Set Hundler
//Set Addr 
//Set CrossRef
//Change Amount Use timers
//Enable Shadow Timers



#define IDX_TC1 1
long RegisterTC1 ( void ) @ "Fast_function"
{
  long i = 1;//Index TC1
  register void *pv;
  //register 
    pv = (void*)& TCIrqData;

   
    if( 
	( (((AT91TC_IrqData_Dsc*)pv)->uChActiveTimers       &(1<<IDX_TC1))== 0 ) && 
	( (((AT91TC_IrqData_Dsc*)pv)->uChShadowActiveTimers &(1<<IDX_TC1)) == 0 )
	)
    {
  
        ((AT91TC_IrqData_Dsc*)pv)->uChActiveTimers |= (1<<IDX_TC1);//TC1 Activate
		i = (((AT91TC_IrqData_Dsc*)pv)->	chAmountUseTimers);
		if(
		  i < 6
		)
		{
		    
			((AT91TC_IrqData_Dsc*)pv)->	arPF_TC_irq_handlers   [IDX_TC1]   = TC1_irq_handler;
			((AT91TC_IrqData_Dsc*)pv)->	arAT91TC_BASE_Pointers [IDX_TC1]   = AT91C_BASE_TC1;
			i++;
			((AT91TC_IrqData_Dsc*)pv)->	arChRefNum[8 - i] = IDX_TC1;
			 //TCIrqData.uChActiveTimers      |= 2;
			 //TCIrqData.uChShadowActiveTimers |= 2; 
			((AT91TC_IrqData_Dsc*)pv)->	uChShadowActiveTimers  |= (1<<IDX_TC1);//TC1 Activate
			
			((AT91TC_IrqData_Dsc*)pv)->	chAmountUseTimers +=1;
             return 1;		
		}	
		else 
		     goto ExitRegisterZero;//return 0;

    }
    else
    {
        goto ExitRegisterZero;
    }
  //Enable CrossRef
  //Enable Field Bit
ExitRegisterZero:   
  return 0;
  
}

//Disable Shadow Timers
//Disable Hundler
//Disable Addr
//Disable Crossref
//Change Amount Use timers
//Disable Active Timers

long UnRegisterTC1 ( void ) @ "Fast_function"
{
  long i = 1;//Index TC1
  register void *pv;
  register long j;
  char chRest,chCounterProcessTimer;
  chRest = chCounterProcessTimer = 0;
    pv = (void*)& TCIrqData;
if( 
	( (((AT91TC_IrqData_Dsc*)pv)->uChActiveTimers       &(1<<IDX_TC1)) != 0 ) && 
	( (((AT91TC_IrqData_Dsc*)pv)->uChShadowActiveTimers &(1<<IDX_TC1)) != 0 )
	)
    {
	    ((AT91TC_IrqData_Dsc*)pv)->uChActiveTimers &= ~(1<<IDX_TC1);//TC1 Activate
		i = (((AT91TC_IrqData_Dsc*)pv)->	chAmountUseTimers);
		if(
		  i < 6
		)
		{
		    ((AT91TC_IrqData_Dsc*)pv)->	arAT91TC_BASE_Pointers [IDX_TC1]   = 0;//AT91C_BASE_TC1;
			((AT91TC_IrqData_Dsc*)pv)->	arPF_TC_irq_handlers   [IDX_TC1]   = 0;
			((AT91TC_IrqData_Dsc*)pv)->chIdxProcessTimer  = ((AT91TC_IrqData_Dsc*)pv)->chAmountUseTimers;
			//Find
			while(i)
			{
				j = ((AT91TC_IrqData_Dsc*)pv)->arChRefNum[8-i];
				if (j == IDX_TC1)
				{
					chRest = ((AT91TC_IrqData_Dsc*)pv)->chIdxProcessTimer - chCounterProcessTimer;//Total Register - AmountScan Timers 
					for (j = 0; j < chRest; j++)
					{
					     ((AT91TC_IrqData_Dsc*)pv)->arChRefNum[ 8-i-j] = 
						  ((AT91TC_IrqData_Dsc*)pv)->arChRefNum[8-i-j -1];
					}
					break;
				}
				i--;
				chCounterProcessTimer++;
			}
			//Disable
			 ((AT91TC_IrqData_Dsc*)pv)->chAmountUseTimers = 0;
			//ReSort
			((AT91TC_IrqData_Dsc*)pv)->	uChShadowActiveTimers  &= ~(1<<IDX_TC1);
			((AT91TC_IrqData_Dsc*)pv)->	chAmountUseTimers -=1;
		
		}
		else
		     goto ExitUnRegisterZero;
	}
	else
    {
        goto ExitUnRegisterZero;
    }
  //Enable CrossRef
  //Enable Field Bit
ExitUnRegisterZero:   
  return 0;
  
}

void TC2_Start(void)
{
//Init clobal strin Identifier
PflData.shOrderNumProcessingRecord  = ID_1;//??
(AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKEN | AT91C_TC_SWTRG;
}

long TC2_Stop(void)
{
//TC_Stop(AT91C_BASE_TC2);
((AT91S_TC*)AT91C_BASE_TC2)->TC_CCR = AT91C_TC_CLKDIS;
return ((AT91S_TC*)AT91C_BASE_TC2)->TC_SR; 
}

long CreatePflrMdlRcd(long lId_Mod, long lCv,void* pvRcd)
{

	if (((PflMdlRcdDsc*)pvRcd)-> Id_Module ==0)
	{
		((PflMdlRcdDsc*)pvRcd)-> Id_Module = 
		PflData.shOrderNumProcessingRecord ;
	}
	else
	((PflMdlRcdDsc*)pvRcd)-> Id_Module = lId_Mod;
	
	((PflMdlRcdDsc*)pvRcd)-> Cv_Start = lCv;
	((PflMdlRcdDsc*)pvRcd)->  Cv_End = 0;
	((PflMdlRcdDsc*)pvRcd)-> IciCallCounterVal = 0;

return (((PflMdlRcdDsc*)pvRcd)-> Id_Module);
}




int InsertDscMsg(char const *file, int line,int lIdxMsg,//IDPflrMdlRcd,
 char const *func, char const * msg)
{
register long i,j;
register void *pv;
char *pCh;
char arCh[10];

pv                   = (void*)&PflData;//sLV.pPflDataDsc;
//char *strncpy(char *restrict s1, const char *restrict s2, size_t n);
pCh = (char*)((PflDataDsc*)pv)->arNamePflMdlRcd[lIdxMsg];
//size_t strlen(const char *s);
j = strlen(file);
if (j>80 ) j = 80;
pCh = strncpy(pCh,file,j);
pCh += j;
//int vsprintf( char *buffer, char *format, va_list arg_ptr );
i =   sprintf(arCh,": %d :",line);
pCh = strncpy(pCh,arCh,7);
pCh += 7;
i = strlen(func);
if (i>80 ) i = 80;
pCh = strncpy(pCh,func,i);
pCh += i;
*pCh++ = ' ';
*pCh++ = ':';
*pCh++ = ' ';
i = strlen( msg);
if (i>40 ) i = 40;
pCh = strncpy(pCh, msg,i);


return 0;
/*
void display_Time(int hours, int minutes, int seconds)
{
 char buf [12];

 sprintf(buf,"%02d:%02d:%02d", hours, minutes, seconds);
 display_Write(3, 9, buf);
}


*/


}

long PutPflrMdlRcd(void* pvRcd,long lAmt)
{
register long i;
register void *pv;
struct 
	{
		//PflMdlRcdDsc locPflMdlRcd;
		short shCtr;
		long lIdxWrPflrMdlRcd;
		PflDataDsc   *pPflDataDsc;
		PflMdlRcdDsc *pPflrMdlRcd;
	} sLV;
sLV.pPflDataDsc = &PflData;
pv                   = (void*)sLV.pPflDataDsc;
sLV.shCtr            = lAmt;

i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd;i++;
			if (i >= (TOT_AMT_PFL_RECORD))
			{
				sLV.shCtr            = lAmt;//Debug code for stop System
			}

while (sLV.shCtr )
	{
	
		sLV.lIdxWrPflrMdlRcd = i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd; 
		
		sLV.pPflrMdlRcd = &(((PflDataDsc*)pv)->arPflMdlRcd[i]);//Select Addr Record
		
		pv                   = (void*)(sLV.pPflrMdlRcd);
		*((PflMdlRcdDsc*) pv) = *((PflMdlRcdDsc*)pvRcd);
		
		if(((PflMdlRcdDsc*)pvRcd)->Id_Module == 0)
		{
			i = ((PflDataDsc*)(sLV.pPflDataDsc))->shOrderNumProcessingRecord;//ID Field
		
			((PflMdlRcdDsc*)pv)-> Id_Module = i;
			((PflMdlRcdDsc*)pvRcd)-> Id_Module = i;
		}
		else
		{
			;
			i = ((PflMdlRcdDsc*)pvRcd)-> Id_Module;
			((PflMdlRcdDsc*)pv)-> Id_Module = i;
		}
			//Increment IdxWrPflrMdlRcd
			pv                   = (void*)sLV.pPflDataDsc;
			i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd;
			 i++;
			if (i >= TOT_AMT_PFL_RECORD) 
				{
					i = 0;
					((PflDataDsc*)pv)->IdxFillRcd = 5;
				}	
			//else
			
			((PflDataDsc*)pv)->IdxWrPflrMdlRcd = i;	
			i  = ((PflDataDsc*)pv)->lAmtPflrMdlRcd;
			 i++;
			if (i > TOT_AMT_PFL_RECORD) 
				{
					i = TOT_AMT_PFL_RECORD;
					
				}	
			//else
			// i++;
			 ((PflDataDsc*)pv)->lAmtPflrMdlRcd = i;
	
		sLV.shCtr --;
		if(sLV.shCtr)//Increment
		{
			
			//Increment Idx PflMdlRcd
			i =  (long)pvRcd;
			i+= sizeof(PflMdlRcdDsc);
			pvRcd = (void*)i;
	
			if ( ((PflMdlRcdDsc*)pvRcd)-> Id_Module == 0 )
			{
				pv                   = (void*)sLV.pPflDataDsc;
				//Increment OrderNumProcessingRecord
				i = ((PflDataDsc*)(pv))->shOrderNumProcessingRecord;//ID Field
				i++;
				((PflDataDsc*)(pv))->shOrderNumProcessingRecord = i;//Change Global Val
			}	
		
			
		
		}
		else
		{
		
		}
		//Increase Pointer
		//i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd;
		
	}

return i;
}

long PutPflrMdlRcd_1(void* pvRcd,long lAmt)
{
register long i;
register void *pv;
struct 
	{
		//PflMdlRcdDsc locPflMdlRcd;
		short shCtr;
		long lIdxWrPflrMdlRcd;
		PflDataDsc   *pPflDataDsc;
		PflMdlRcdDsc *pPflrMdlRcd;
	} sLV;
sLV.pPflDataDsc = &PflDataSaveBig;
pv                   = (void*)sLV.pPflDataDsc;
sLV.shCtr            = lAmt;

i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd;i++;
			if (i >= (TOT_AMT_PFL_RECORD))
			{
				sLV.shCtr            = lAmt;//Debug code for stop System
			}

while (sLV.shCtr )
	{
	
		sLV.lIdxWrPflrMdlRcd = i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd; 
		
		sLV.pPflrMdlRcd = &(((PflDataDsc*)pv)->arPflMdlRcd[i]);//Select Addr Record
		
		pv                   = (void*)(sLV.pPflrMdlRcd);
		*((PflMdlRcdDsc*) pv) = *((PflMdlRcdDsc*)pvRcd);
		
		if(((PflMdlRcdDsc*)pvRcd)->Id_Module == 0)
		{
			i = ((PflDataDsc*)(sLV.pPflDataDsc))->shOrderNumProcessingRecord;//ID Field
		
			((PflMdlRcdDsc*)pv)-> Id_Module = i;
			((PflMdlRcdDsc*)pvRcd)-> Id_Module = i;
		}
		else
		{
			;
			i = ((PflMdlRcdDsc*)pvRcd)-> Id_Module;
			((PflMdlRcdDsc*)pv)-> Id_Module = i;
		}
			//Increment IdxWrPflrMdlRcd
			pv                   = (void*)sLV.pPflDataDsc;
			i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd;
			 i++;
			if (i >= TOT_AMT_PFL_RECORD) 
				{
					i = 0;
					((PflDataDsc*)pv)->IdxFillRcd = 5;
				}	
			//else
			
			((PflDataDsc*)pv)->IdxWrPflrMdlRcd = i;	
			i  = ((PflDataDsc*)pv)->lAmtPflrMdlRcd;
			 i++;
			if (i > TOT_AMT_PFL_RECORD) 
				{
					i = TOT_AMT_PFL_RECORD;
					
				}	
			//else
			// i++;
			 ((PflDataDsc*)pv)->lAmtPflrMdlRcd = i;
	
		sLV.shCtr --;
		if(sLV.shCtr)//Increment
		{
			
			//Increment Idx PflMdlRcd
			i =  (long)pvRcd;
			i+= sizeof(PflMdlRcdDsc);
			pvRcd = (void*)i;
	
			if ( ((PflMdlRcdDsc*)pvRcd)-> Id_Module == 0 )
			{
				pv                   = (void*)sLV.pPflDataDsc;
				//Increment OrderNumProcessingRecord
				i = ((PflDataDsc*)(pv))->shOrderNumProcessingRecord;//ID Field
				i++;
				((PflDataDsc*)(pv))->shOrderNumProcessingRecord = i;//Change Global Val
			}	
		
			
		
		}
		else
		{
		
		}
		//Increase Pointer
		//i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd;
		
	}

return i;
}

void OutTerminalCurrPflrData(void *pFlrData)
{
register long i;
register void *pv;
register char* pCh;
struct 
	{
		short shStartOutElem;
		short shEndOutElem;
		short shCtr;
		long Id_Module;
		
	} sLV;
//sLV.pPflDataDsc = &PflData;
pv                   = pFlrData;//(void*)sLV.pPflDataDsc;
 //lAmtPflrMdlRcd
sLV.shCtr = (((PflDataDsc*)pv)->lAmtPflrMdlRcd);
sLV.shStartOutElem = 0;
sLV.shEndOutElem    =100;

	for (i = sLV.shStartOutElem; i< sLV.shEndOutElem; i++)
	{
		sLV.Id_Module = ((PflDataDsc*)pv)->arPflMdlRcd[i].Id_Module;
		printf( "%ld; %6d; %6d; %8jd;- ",
		((PflDataDsc*)pv)->arPflMdlRcd[i].Id_Module, 
		((PflDataDsc*)pv)->arPflMdlRcd[i].Cv_Start, 
		((PflDataDsc*)pv)->arPflMdlRcd[i].Cv_End,
		((PflDataDsc*)pv)->arPflMdlRcd[i].IciCallCounterVal
		
		);
		printf( "%ld;",i);
		printf( " -- \n", pCh);
		/*
		pCh = (char*) &(((PflDataDsc*)pv)->arNamePflMdlRcd[0]);
		pCh += 48;// Cut G:\HVP_pj\Hvps\hvps29_07_14\HS1_0100_00_i670\ici\. 
		printf( "%s -- \n", pCh);
		//printf( "%s -- Execution passed\n", &(((PflDataDsc*)pv)->arNamePflMdlRcd[0]));
		*/
	
	
	}

((PflDataDsc*)pv)->IdxFillRcd = 0;
//printf( "%s:%d %s %s -- Execution passed\n", file, line, func,msg );

}

void SaveCurrIciCallSlises(void )
{
register long i,j;
register void *pv;
register char* pCh;
struct 
	{
		short shCtr;
		long Id_Module;
		long lIdxWrPflrMdlRcd;
		PflMdlRcdDsc *pPflrMdlRcd;
	} sLV;
	
pv                   = (void*)  &PflData;
//pvAdd 	            = (void*)  &PflDataSaveBig;

	i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd; 
	if (i == 0) 
		i = TOT_AMT_PFL_RECORD - 1;
	else 
		i--;
	sLV.lIdxWrPflrMdlRcd = i;//Last Wr Elem
	
	
	sLV.pPflrMdlRcd = &(((PflDataDsc*)pv)->arPflMdlRcd[i]);
	pCh = (char*)sLV.pPflrMdlRcd;
	sLV.shCtr = ((PflMdlRcdDsc*)pCh)-> Id_Module;
	//sLV.shCtr -= ID_1;//TotAmt
	if(sLV.shCtr == 0)
		return;
	i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd; 
		if(i>=sLV.shCtr)
			sLV.lIdxWrPflrMdlRcd = i - sLV.shCtr;
		else
		{
			sLV.lIdxWrPflrMdlRcd = (TOT_AMT_PFL_RECORD-1) +i;
			sLV.lIdxWrPflrMdlRcd -= sLV.shCtr;
		
		}
	//sLV.shCtr++;
	do
	{
		i = sLV.lIdxWrPflrMdlRcd;
		sLV.pPflrMdlRcd = &(((PflDataDsc*)pv)->arPflMdlRcd[i]);
		pCh = (char*)sLV.pPflrMdlRcd;
	
		 PutPflrMdlRcd_1((void*)sLV.pPflrMdlRcd ,1);//(void*)&(sLV.locPflMdlRcd)
		
		i  = sLV.lIdxWrPflrMdlRcd;
		 i++;
			if (i >= TOT_AMT_PFL_RECORD) 
				{
					i = 0;
		
				}	
			//else
		sLV.lIdxWrPflrMdlRcd = i;	
			
//		 i  = ((PflDataDsc*)pv)->IdxWrPflrMdlRcd; 
//			if (i == 0) 
//				i = TOT_AMT_PFL_RECORD - 1;
//			else 
//				i--;
//			sLV.lIdxWrPflrMdlRcd = i;
		 
		 
		 
	}while(--sLV.shCtr);
	

}



PflDataDsc PflData @ "DDR2_Bank1_2_variables";
PflDataDsc PflDataSaveBig @ "DDR2_Bank1_2_variables";


/* EOF */





