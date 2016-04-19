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
* Processor       : Lpc_3240
* File Name       : ici_api.c
* Description     : Functions and Data for API,
                    interprocessor communication

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  13/08/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include "ici_api.h"
#include "ici_ef.h"
#include "GU2.h"
#include "GU0.h"

#include    "lpu.h"
#include    "ApCn.h"
#include    "CTpu.h"
#include    "MnPrStng.h"
#include    "srvUO.h"


#include <intrinsics.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../LibG45/peripherals/tc/tc.h"
#include "../LibG45/boards/bs_g45/at91sam9g45/AT91SAM9G45.h"
#include "TC_G45.h"
#include "../LibG45/peripherals/pio/pio.h"


extern long outU3(unsigned char*dat, int bytes);
extern long outU7(unsigned char*dat, int bytes);
//extern long outU2(unsigned char*dat, int bytes);


extern int txfill, txsize, txget;
extern int rxsize, rxget,  rxfill;

unsigned char chEntry_U2;
unsigned char chEntry_U0;
unsigned char chEntry_UDbg;
unsigned char chEntry_Spi0@ "Fast_variable"; 
unsigned char chEntry_Hs7 = 0;
extern int hs7_txsize,hs7_txfill,hs7_txget;
extern int hs7_rxsize,hs7_rxget, hs7_rxfill;
unsigned char chEOI_U2  @  "DMA_BUFFERS";







//...long outU7(UNS_8 *dat, int bytes);
char testbuff [512];
char *DemoStr =  "Hello world";

void Scan_Ici_Event_Req(void);
void Scan_Ici_Entry_Data(void);

unsigned long samples_data_rdy;

unsigned char meas_data_rdy;

long Samples_Ready_Handler(void* pv);


long Meas_Ready_Handler   (void* pv);

static char chStateExec = 0;
long Samples_Ready_Handler(void* pv)  @ "Fast_function"
{
register long i=0;
//ArTenPerStateDsc locArTenPerState;
//TotMeasStateDsc locTotMeasStateDsc;
SettingsStateDsc locSettingsStateDsc;
	if (samples_data_rdy & 0x200)
	{
		samples_data_rdy = 0;
		//i = outU3((unsigned char*)DemoStr, 11);
		//i = outU7((unsigned char*)DemoStr, 2);
		//---TestSetup_SrcSamples_ForTransmit();//
		//TestActivateTransport();return 0;
		//ActivateProxyTenPerSamples();
		/*
		if ( chStateExec == 0)
		{
			i =  ReqArTenPerData(1,&locArTenPerState);
			if (i != ERROR_EXEC)
			{
				chStateExec = 1;//Start Execution
			}
			else chStateExec = 0;
		}
		if (chStateExec == 1 )
		{
			i =  ReqArTenPerData(0,&locArTenPerState);
			switch(i)
			{
				case SUCCESS_EXEC:
				chStateExec = SUCCESS_EXEC;
				break;
				case ERROR_EXEC:
				i =  ReqArTenPerData(1,&locArTenPerState);
				if (i== ERROR_EXEC)
				chStateExec = 0;
				else
				chStateExec = 1;
				break;
				
				default:
				;
			
			}
			
		
		}
		if (chStateExec == SUCCESS_EXEC)
		{
			;//See data
		}*/
	//outU2(DemoStr,5);
		//..TestSetup_LpduHSU7_ForTransmit();
		//..ProcessTransmitLpduHSU7();
		/*if ( chStateExec == 0)
		{
			i =  ReqTotMeasData(1,&locTotMeasStateDsc);
			if (i != ERROR_EXEC)
			{
				chStateExec = 1;//Start Execution
			}
			else chStateExec = 0;
		}
		if (chStateExec == 1 )
		{
			i =  ReqTotMeasData(0,&locTotMeasStateDsc);
			switch(i)
			{
				case SUCCESS_EXEC:
				chStateExec = SUCCESS_EXEC;
				break;
				case ERROR_EXEC:
				i =  ReqTotMeasData(1,&locTotMeasStateDsc);
				if (i== ERROR_EXEC)
				chStateExec = 0;
				else
				chStateExec = 1;
				break;
				
				default:
				;
			
			}
			
		
		}
		if (chStateExec == SUCCESS_EXEC)
		{
			;//See data
		}*/ 
		if ( chStateExec == 0)
		{
			locSettingsStateDsc.size_current_settings = testSettigsState.size_current_settings;
			locSettingsStateDsc.p_current_settings    = testSettigsState.p_current_settings;
			i =   ReqSendSettingsBM(1,&locSettingsStateDsc);//ReqGetSettingsBM
			if (i != ERROR_EXEC)
			{
				chStateExec = 1;//Start Execution
			}
			else chStateExec = 0;
		}
		if (chStateExec == 1 )
		{
			i =   ReqSendSettingsBM(0,&locSettingsStateDsc);//ReqGetSettingsBM
			switch(i)
			{
				case SUCCESS_EXEC:
				chStateExec = SUCCESS_EXEC;
				break;
				case ERROR_EXEC:
				i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
				if (i== ERROR_EXEC)
				chStateExec = 0;
				else
				chStateExec = 1;
				break;
				
				default:
				;
			
			}
			
		
		}
		if (chStateExec == SUCCESS_EXEC)
		{
			;//See data
		}
		
		

		
	}	
	//PrepDecompouseSrcSamplesUnit();- Move to Another function
return 0;
}



long Meas_Ready_Handler   (void* pv)  @ "Fast_function"
{

return 0;
}
long lCtrErrOvr = 0;



static unsigned long ulIciCallCounterCopy;
long lTmrDisableHSU2   @  "DMA_BUFFERS";// = 0
long lTmpCmpVal    = 40;//20  ;//8;
extern unsigned long ulIciCallCounter;
extern unsigned long ulReqIciCall;
void Scan_Ici_Entry_Data(void)  @ "Fastest_function" //Fast_function"
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
	if(PflData.shR == 3)
	{
		sLV.locPflMdlRcd.Id_Module = 0;
		CreatePflrMdlRcd(1,((AT91S_TC*)AT91C_BASE_TC2)->TC_CV,(void*)&(sLV.locPflMdlRcd) );
		sLV.locPflMdlRcd.IciCallCounterVal = ulIciCallCounter;
	}
//Detect Input Data on HSUART7
	if (chEntry_Hs7)
	{
		//i = inU7(testbuff,11);
		chEntry_Hs7 = 0;
		ProcessReceiveLpduHSU7();
		
	}
	if(PflData.shR == 3)
	{
	sLV.locPflMdlRcd.Cv_End = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
	sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
	PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
	}
	
	//Detect Input Data on SPI 
if(chEntry_Spi0>=2)
	{
	   i = chEntry_Spi0;//StubForSpiChanel1();
	   AT91C_BASE_PIOD->PIO_SODR = (0x2);
		if( (chLogicSpi0HdwError) ||(chEntry_Spi0 !=2) )
		ReInitSpi0Param();
		else
		{
			if(chEntry_Spi0!=2) 
			#ifdef BS_G45_FL_RL
			lCtrErrOvr++;
			#else
			for(;;);
			#endif
			ProcessReceiveLpduSpi();
			if(chEntry_Spi0!=2)
			#ifdef BS_G45_FL_RL
			lCtrErrOvr++;
			#else
			for(;;);
			#endif
				
			chEntry_Spi0 -= 2; //-SPI0_DMA_Enable(); 
			//-//
			//-AT91C_BASE_PIOD->PIO_CODR = (0x2);
		}
		if ( ((((AT91S_TC*)AT91C_BASE_TC2)->TC_CV) >1200 )&& (chHdwErorU0 || chHdwErorU2 || chEntry_U2 || chEntry_U0))
		{
			ulReqIciCall++;
			return;
		}
	}
	if (chEntry_U0)
	{
		//i = inU7(testbuff,11);
		//chEntry_U0 = 0;
		//ProcessReceiveQueueU0_V0();//<- Risk for speed
		//ProcessReceiveQueueU0();//ProcessReceiveLpduU0_T();
		
	}
	//if(PflData.shR == 3)
	//{
	//sLV.locPflMdlRcd.Cv_End = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
	//sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
	//PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
	//}
	 #ifdef USE_PIO_SYNC
	if (lEndU2Tr)
	{
	#endif
		if(chEntry_U2)//
		{
			ProcessReceiveLpduU2_T();//ProcessReceiveLpduU2();chEntry_U2 = 0;
			i = 0;
			//The end of Extract Data from Buf
			if(!chHdwErorU2)
			{
			lEndU2Tr = i = 1;
			
			}
		}
	#ifdef USE_PIO_SYNC	
		lEndU2Tr--;
		if((i == 1) || (lEndU2Tr==0))
		{
			AT91C_BASE_PIOB->PIO_SODR = (1 << 11);//PB11 Set
			lClrCtr++;//lSetCtr++;
		}
    
	}
	if(lEndU2Tr == 0 ) 
	{
	i = AT91C_BASE_PIOB->PIO_ODSR;
	if(i&(1 << 11))
	;
	else
	;//AT91C_BASE_PIOB->PIO_SODR = (1 << 11);//PB11 Set <--Unexpected Situation
	}
	#endif
	
    if(chHdwErorU2)
	{
		AT91C_BASE_PIOB->PIO_CODR = (1 << 11);//PB11 Set
	 u2_recover_cb();
	 if(lEndU2Tr <=  1 )
	 {
	 lEndU2Tr = 0;
	 AT91C_BASE_PIOB->PIO_SODR = (1 << 11);//PB11 Set;//PB11 Set
	 
	 }
	 
	}
    if(chHdwErorU0)
	{
	 u0_recover_cb();//u0_recover_cb
	}
	if (chEOI_U2&0x41)//Start and End 
	{
		if (ulIciCallCounterCopy != ulIciCallCounter)
		{
			lTmrDisableHSU2 ++;
			ulIciCallCounterCopy = ulIciCallCounter;
			if(lTmrDisableHSU2 >= lTmpCmpVal)
			{
				if(hldrHSU2LpduTRUnit.uchLpuHSU2State)
				{
					hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;//En tr
					chEOI_U2 = 0;
					
					
					lTmrDisableHSU2  = 0;
				}
			}
		}
	}
	if(PflData.shR == 3)
    {
	sLV.locPflMdlRcd.Cv_End = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
	sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
//	PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
    }
//Detect Input Data on HSUART2
//Detect Input Data on HSUART1

//Detect Input Data on UART3


	if(PflData.shR == 3)
	{
	sLV.locPflMdlRcd.Cv_End = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
	sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
//	PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
	}
	ProcessReceiveEvt();
	UpdateAppData();

	//if(PflData.shR == 3)
    //{
	//sLV.locPflMdlRcd.Cv_End = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
	//sLV.locPflMdlRcd.Id_Module =  PflData.shOrderNumProcessingRecord++;
	//PutPflrMdlRcd((void*)&(sLV.locPflMdlRcd) ,1);
    //}

}
void Scan_Ici_Event_Req(void)  @ "Fastest_function" //Fast_function"
{
long lDbglV = 0;
void* pv = (void*)&hldPrMngSettings;
	if(0)//samples_data_rdy)
    {
      //Handle  instant samplas values Ready 
      Samples_Ready_Handler((void*)0);
    }
    if(0)//meas_data_rdy)
    {
      //Handle Measuring system data Ready
      Meas_Ready_Handler((void*)0);
    }
	DbgModifyPrMng(pv,lDbglV);
	lDbglV = ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV;
//	if( (((AT91S_TC*)AT91C_BASE_TC2)->TC_CV) > 300) //if(lDbglV>100)
//	__asm volatile("BKPT 4");
	//Transmit Data
	ProcessTransmitEvt();
	//if(( ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV) >2000)
	//__asm volatile("BKPT 5");
	ExecProxy();
	//if(( ((AT91S_TC*)AT91C_BASE_TC2)->TC_CV) >5000)
	//__asm volatile("BKPT 6");
//Activate Hdw connect SPI	
	if((lSpi0HdwState&4) == 0)
	{
		//lDbglV = CheckSpi0State(0xfffff);
		if (lDbglV )
		lSpi0HdwState |= 2;
		else
		{
			//Fix Error SPi State channel
		}
		//Spi0_Syncro1();
		//if(lSpi0HdwState &=(2))
		Spi0_Syncro4();//Spi0_Syncro3();
	}

	ServiceBsTrUrgObjStates();
	if((lSpi0HdwState&0x4) == 4)
	{
		//~~~StubForSpiChanel();
		if(chLogicSpi0HdwError)
		{
			
			chLogicSpi0HdwError = 0;
		}	
	}	
}

extern int spi1_rxsize;
void StubForSpiChanel(void)
{
register long i;

char ArTstData[600];
for( i = 0; i<560; i++)
ArTstData[i] = i+10;
//return; if i comment numbers change to ???
if (lSpi0HdwState & 4) 
{
return;
}
else
{

}
//while(1)
if(chEntry_Spi0)
{
i = inSpi0((unsigned char*)ArTstData, 16);
ArTstData[550] = 30;
i=  outSpi0((unsigned char*)ArTstData+100, 16);//512);//300
}


ArTstData[550] = 20;
i = 0;
//``while (spi1_rxsize <= 511)
//``i++;i*=10;
//``while(i--);
lSpi0HdwState |= 4;
}

void StubForSpiChanel1(void)
{
register long i;

char ArTstData[600];

//return; if i comment numbers change to ???

if(chEntry_Spi0)
{
i = inSpi0((unsigned char*)ArTstData, 512);//First Load Data from Buff
ArTstData[550] = 30;
for( i = 0; i<560; i++)
ArTstData[i] = i+10;
//Move data in Buf for Sending
i=  outSpi0((unsigned char*)ArTstData, 512);//512);//300
}




lSpi0HdwState |= 4;
}
#include "../../peripherals/pmc/pmc.h"
#include "../../peripherals/pio/pio.h"
//.#include "../../peripherals/usart/usart.h"
#include "../../peripherals/irq/irq.h"
#include "../../peripherals/cp15/cp15.h"
//G:\HVP_pj\Hvps\hvps01_03_13\HS1_0100_00_i670\LibG45\boards\bs_g45\at91sam9g45\AT91SAM9G45.h
#include "./at91sam9g45/AT91SAM9G45.h"










 long lTestVal   = 0;
short shTestVal  = 0;
char  chTestChar = 0;


//long lInInt = 0;

__arm void Test_Loop(void)  //@ "Fastest_function"
{
//register long i;
//register void *pv;
//register char *pCh;
	while(1)
	{
		AT91C_BASE_PIOD->PIO_SODR = (0x2);
		//lTestVal++;
		// shTestVal++;
		// chTestChar++;
		AT91C_BASE_PIOD->PIO_CODR = (0x2);
	
	}

}

long Test_Init(void)
{

//ReInit EBI
AT91C_BASE_SMC->SMC_SETUP1 = ((AT91C_SMC_NWESETUP & (0 <<0))
                                 |(AT91C_SMC_NCSSETUPWR & (0 <<8))
                                 |(AT91C_SMC_NRDSETUP & (0 <<16))
                                 |(AT91C_SMC_NCSSETUPRD & (0 <<24)));

    AT91C_BASE_SMC->SMC_PULSE1 = ((AT91C_SMC_NWEPULSE & (3 <<0))
                                 |(AT91C_SMC_NCSPULSEWR & (3 <<8))
                                 |(AT91C_SMC_NRDPULSE & (3 <<16))
                                 |(AT91C_SMC_NCSPULSERD & (3 <<24)));

    AT91C_BASE_SMC->SMC_CYCLE1 = ((AT91C_SMC_NWECYCLE & (5 <<0))
                                 |(AT91C_SMC_NRDCYCLE & (4 <<16)));
    
    AT91C_BASE_SMC->SMC_CTRL1 = ( (AT91C_SMC_READMODE & (1<<0))
                                | (AT91C_SMC_WRITEMODE & (1<<1))
                                | (AT91C_SMC_NWAITM_NWAIT_DISABLE     )
                                | (AT91C_SMC_BAT_BYTE_SELECT          )
                                | (AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS)
                                | (AT91C_SMC_TDF & (0<<16))
                                | (AT91C_SMC_TDFEN & (0<<20))
                                | (AT91C_SMC_PMEN & (0<<24))
                                | (AT91C_SMC_PS & (0<<24)));			
//Remap CMD

//Init Bus Matrix

//Init Cash Code

//Init Cash Data

//Activate Tightly coupled Memory






	return 0;
}


























/* EOF */
