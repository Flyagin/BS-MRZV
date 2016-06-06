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
* File Name       : AppCn.c
* Description     : Functions and Data application Layer
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
//#include    "./inc/header.h"
#include    "../inc/const_BS_BL.h" 
#include    "../inc/type_definition_BS.h"
#include    "../inc/type_definition_BL.h" 
#include    "ApCn.h"
#include    "CTpu.h"
#include    "lpu.h"
#include    "ici_ef.h"
#include    "MnPrStng.h"
#include    "MnPrPrt.h"
long lActualPrTrObj;
#include    "hv_df.h"//"../inc/stngctrl/hv_df.h"
#include    "SmpWrp.h"
#include "../LibG45/peripherals/pio/pio.h"

long timerWaitReqSpi = (0); long timerWaitU0 = (0);

int TestReqTransmitT1;
int TestReqReceiveT1;

SrcSamplesUnitDsc  holderSrcSamplesUnit = {
{0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,
0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46, 
0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46, 
0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46,0x46 


}
};

//long(*PFL_VL)(void* pv, long lV);
long InitProxyTenPerSamples (void* pv, long lV);
long WorkProxyTenPerSamples (void* pv, long lV);
long ResetProxyTenPerSamples (void* pv, long lV);
long ExecCmdProxyTenPerSamples (void* pv, long lV);
ProxyTenPerSamplesUnitDsc  holderProxyTenPerSamplesUnit = {
{
ID_TEN_PERIOD_SAMPLES_UNIT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
InitProxyTenPerSamples,ResetProxyTenPerSamples,WorkProxyTenPerSamples,ExecCmdProxyTenPerSamples
},

// arUchExecCmd[4] = {
                   {0,0,0,0},
///arUchRvParamCmd[32] = {
{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } 
};
int TestReqTransmitTenPerSamples;
int TestReqReceiveTenPerSamples;
//TenPerSamplesUnitDsc holderTenPerSamplesUnitDsc; 
ArTenPerSamplesUnitDsc   holderArTenPerSamplesUnit;
char chStateAr10PerData = 0;
int TestReqTransmitArTenPerSamples;
int TestReqReceiveArTenPerSamples;

ProxyTotMeasUnitDsc  holderProxyTotMeasUnit = {
{
ID_TOTAL_MEAS_UNIT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
InitProxyTotMeas,ResetProxyTotMeas,WorkProxyTotMeas,ExecCmdProxyTotMeas
},

// arUchExecCmd[4] = {
                   {0,0,0,0},
///arUchRvParamCmd[32] = {
{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } 
};
int TestReqTransmitTotMeas;
int TestReqReceiveTotMeas;



//.ArTenPerSamplesUnitDsc   holderArTenPerSamplesUnit;
#ifndef __TYPE_DEFINITION_BS_H
#define SIZE_TOTAL_MEASUREMENT 0X1000
#endif 
#ifdef __TYPE_DEFINITION_BS_H
#define SIZE_TOTAL_MEASUREMENT ( ((sizeof(__TOTAL_MEASUREMENT )>>2)<<2) + 4*(1&&(sizeof(__TOTAL_MEASUREMENT ))&3) )
#endif
/*
union 
{
	    	char   chArTotMeas [SIZE_TOTAL_MEASUREMENT];
	    	long   lArTotMeas  [SIZE_TOTAL_MEASUREMENT>>2];
#ifdef __TYPE_DEFINITION__
			__TOTAL_MEASUREMENT total_measurement;
#endif
            
}TotMeasStructholder holderTotMeas;*/
TotMeasHldDsc holderTotMeas = {

//{},
{SIZE_TOTAL_MEASUREMENT}
};
//holderTotMeas.lSizeOf_total_measurement = sizeof(__TOTAL_MEASUREMENT);
long lSizeOf_total_measurement = sizeof(__TOTAL_MEASUREMENT);
char chStateArTotMeasData = 0;
int TestReqTransmitArTotMeas;
int TestReqReceiveArTotMeas;

/////////////////////////Proxy ///////////////////////////////////////
ProxySettingsUnitDsc holderProxySettingsUnit = {
{
ID_SETTINGS_UNIT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//InitProxy,ResetProxy,WorkProxy,ExecCmdProxy
InitProxySettings,ResetProxySettings,WorkProxySettings, ExecCmdProxySettings
},
{0,(void*)0},
// arUchExecCmd[4] = {
                   {0,0,0,0},
///arUchRvParamCmd[32] = {
{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 } 
};
int TestReqTransmitTotMeas;
int TestReqReceiveTotMeas;
//?#ifndef __TYPE_DEFINITION_BS_H
//?#define SIZE_SETTINGS 0X100
//?#endif 
//?#ifdef __TYPE_DEFINITION_BS_H
//?#define SIZE_SETTINGS ( ((sizeof(__SETTINGS )>>2)<<2) + 4*(1&&(sizeof(__SETTINGS ))&3) )
//?#endif
SettingsHldDsc holderSettings = {

//{},
{SIZE_SETTINGS_ICI}
};
//
long lSizeOf_Settings = SIZE_SETTINGS_ICI;//sizeof(__SETTINGS);
char chStateArSettingsData = 0;
int TestReqTransmitSettings;
int TestReqReceiveSettings;

YustHldDsc holderYust = {

//{},
{SIZE_YUST}
};
//
long lSizeOf_Yust = sizeof(SIZE_YUST);
char chStateArYustData = 0;
int TestReqTransmitArYust;
int TestReqReceiveArYust;


int TestReqTransmitT2;
int TestReqReceiveT2;
SrcAPCSUnitDsc   holderSrcAPCSUnit;


int TestReqTransmitT3;
int TestReqReceiveT3;

SrcTest1UnitDsc holderSrcTest1Unit;
 long lCtrCallsTrLpduHSU2 = 0;
 long lStopVal = 1000;
void ProcessTransmitEvt(void)  @ "Fast_function"
{
register long i;
register void *pv;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char chTrCnl1,chTrHSU0,chTrHSU2,chTrHSU7;//chFld2,chFld3,chFld4;
		char chTrM2m,chTrSpi;
		char chRetCode,chBusyChnl;
		unsigned short ushIdObj;
	    //.unsigned char *pUchTR;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
sLV.chBusyChnl = 0;sLV.chTrHSU7 = 0;sLV.chTrHSU0 = 0;sLV.chTrHSU2 = 0; sLV.chTrM2m = 0;sLV.chTrSpi = 0;
	pv = (void*)&hldrTpCnState;
	i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_1;
	//Control then All Channels Full
	if(i<4)
	{
		sLV.chBusyChnl |= 1; 
	}
	//Insert HSU7
	//.i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_2;
	//.if(i<4)
	//.{
	//.	sLV.chBusyChnl |= 2; 
	//.}
	//Add here additional Logic for control another Layer state
	if((sLV.chBusyChnl&3) == 3 )
	goto DecomposeDataCnl2;//return;
	//Transmit on Phys Leyer
	
	
DecomposeDataCnl2:	
	//outU2((unsigned char *)&(holderSrcSamplesUnit),5);
	
if (hldrHSU2LpduTRUnit.uchLpuHSU2State==0)
{
	//	PrepDecompouseSrcSamplesUnitHSU2();
	PrepDecompouse10PeriodUnitHSU2();
	PrepDecompouseTotMeasUnitHSU2();
	//PrepDecompouseSettingsUnitHSU2();
	PrepDecompouseSettingsPrMngHSU2();
	PrepDecompouseYustPrMngHSU2();
	PrepDecompouseStngTptUnitHSU2();
	PrepDecompouseYustTptUnitHSU2();
	//PrepDecompouse Xxx Test1Unit
	//i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU2;
	//	i +=2;((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU2 = i;
	if (i)
	{
	    if (i&(1<<7))//Channel Full
	    {
		    sLV.chTrHSU2 = 2;//Transmition should start
		}
		else
		{
		    if(i>1)//Any Obj Full his data
			{
			    sLV.chTrHSU2 = 1;//Transmition should start
			}
		}
		
	
	}
	else
	goto EndBlockHSU2State;//DecomposeDataCnl1;//return;
	// Transmition data on HSU7
	if(sLV.chTrHSU2)
	{
	    
		//if(lCtrCallsTrLpduHSU2< lStopVal)//if(timeout == 0)         (samples_data_rdy!= oldstate) Control timeOut
		{
		// AT91C_BASE_PIOD->PIO_SODR = (0x2);
		 lCtrCallsTrLpduHSU2++;
		ProcessTransmitLpduHSU2();
		}
		//else
		//AT91C_BASE_PIOD->PIO_CODR = (0x1);
	}
EndBlockHSU2State:
;
}

	
//DecomposeDataCnl1:
	
//DecomposeDataCnl7:	
if(0)// hldrU0LpduTRUnit.uchLpuU0State==0)
	{
		//	PrepDecompouseApcsUnitSpi();
		PrepDecompouseSrcSamplesUnitHSU0();
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_U0;//
		if (i)
		{
			if (i&(1<<7))//Channel Full  StateTpCnDsc
			{
				sLV.chTrSpi = 2;//Transmition should start
				
			}
			else
			{
				if(i>=1)//Any Obj Full his data. And you should control TimeOut Wait for Req
				{
					if(timerWaitU0&0xfffffff8) timerWaitU0  = 5;//This Temporary Code for Permit Usual Tranmitting
					
					if(timerWaitU0>0)//timerWaitReq
					timerWaitU0--;
					if(timerWaitU0==0)//timerWaitReq==0|| timerWaitReq>= 2000<-Max time waiting Req )
					{
						sLV.chTrSpi = 1;//Transmition should start
					}	
				}
			}
			
		
		}
		else
		goto EndBlockHSU0State;//DecomposeDataCnl1;//return;
		// Transmition data on HSU7
		if(sLV.chTrSpi)
		{
			//StartTrasmit:
			//if(lTmrDisableSpi>lDelta)
			ProcessTransmitLpduU0();
			//lTmrDisableSpi = 0;//lTmrSpiVal = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;	
			timerWaitU0 = (-1);//This do for permit start after Curr Samples Ready Now Reset this Timer after first Req RDY
			
		}
EndBlockHSU0State:
		 //ProcessTransmitStubSeqSpi();
;	
	}	
/*	PrepDecompouseSrcSamplesUnit();
	
	
	//PrepDecompouse Xxx Test1Unit
	i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU7;
	if (i)
	{
	    if (i&(1<<7))//Channel Full
	    {
		    sLV.chTrHSU7 = 1;//Transmition should start
		}
		else
		{
		    if(i>1)//Any Obj Full his data
			{
			    sLV.chTrHSU7 = 1;//Transmition should start
			}
		}
		
	
	}
	else
	return;
	// Transmition data on HSU7
	if(sLV.chTrHSU7)
	{
	    ProcessTransmitLpduHSU7();
	
	}
	*/
	
	if( hldrSpiLpduTRUnit.uchLpuSpiState==0)
	{
		//	PrepDecompouseApcsUnitSpi();
		//~PrepDecompouseGoosBUnitSpi();
		//~PrepDecompousePrtTblPrMngSpi();
		PrepDecompousePrtTblTptUnitSpi();
		//~PrepDecompouseGoosBUnitSpi();
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_Spi;
		if (i)
		{
			if (i&(1<<7))//Channel Full
			{
				sLV.chTrSpi = 2;//Transmition should start
				
			}
			else
			{
				if(i>=1)//Any Obj Full his data. And you should control TimeOut Wait for Req
				{
					if(timerWaitReqSpi&0xfffffff8) timerWaitReqSpi  = 5;//This Temporary Code for Permit Usual Tranmitting
					
					if(timerWaitReqSpi>0)//timerWaitReq
					timerWaitReqSpi--;
					if(timerWaitReqSpi==0)//timerWaitReq==0|| timerWaitReq>= 2000<-Max time waiting Req )
					{
						sLV.chTrSpi = 1;//Transmition should start
					}	
				}
			}
			
		
		}
		else
		goto EndBlockSpiState;//DecomposeDataCnl1;//return;
		// Transmition data on HSU7
		if(sLV.chTrSpi)
		{
			//StartTrasmit:
			//if(lTmrDisableSpi>lDelta)
			 ProcessTransmitStubSeqSpi(); //ProcessTransmitLpduSpi();
			//lTmrDisableSpi = 0;//lTmrSpiVal = ((TIMER_CNTR_REGS_T *)TIMER_CNTR0)-> tc;	
			timerWaitReqSpi = (-1);//This do for permit start after Curr Samples Ready Now Reset this Timer after first Req RDY
			
		}
EndBlockSpiState:
		 ProcessTransmitStubSeqSpi();
;	
	}	
ExitProcessTransmitEvt:	
return;
}
//void ProcessTransmitEvt1(void)
//{
//register long i;
//	//Control then All Channels Full
//	if()
//	{
//	
//	}
//	//Control State Obj if Need Transmit
//	//Process
//	if()
//	{
//		//Control State Channel
//		//If busy - Try another
//		if()
//		{
//			//ProcessTransmit Obj
//			if()
//			{
//				
//			}
//		}
//		//Try another
//		
//	}
//	
//
//}
void PrepDecompouseSrcSamplesUnit(void)  @ "Fast_function"
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
	//Control then All Channels Full
	//.if()
	//.{
	//.
	//.}
	//Control State Obj if Need Transmit
	//Process
	if(TestReqTransmitT1)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU7;j = sizeof(SrcSamplesUnitDsc)>>2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitT1==START)
			{
				ActivateServTrApCnSamplesCTpuUnit();
				TestReqTransmitT1 = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitT1==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRSrcSamplesCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitT1 = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				TestReqTransmitT1 = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitT1==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TestReqTransmitT1 = 0;
				}
			}
		}
		//Try another???
		
	}
	

}
void PrepDecompouseSrcSamplesUnitHSU2(void)  @ "Fast_function"
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
	//Control then All Channels Full
	//.if()
	//.{
	//.
	//.}
	//Control State Obj if Need Transmit
	//Process
	if(TestReqTransmitT1)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = sizeof(SrcSamplesUnitDsc)>>2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitT1==START)
			{
				ActivateServTrApCnSamplesCTpuUnitHSU2();
				TestReqTransmitT1 = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitT1==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRSrcSamplesCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitT1 = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				TestReqTransmitT1 = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitT1==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TestReqTransmitT1 = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


/*
void ProcessTransmitEvt1(void)
{
register long i;
	
	//	//Control then All Channels Full
 	if()
 	{
		return;
 	}
	//Select Obj
	i = SelectObj();
	//Handle Selected Obj
	HBgnTrSrcSamplesUnit();
	
}

long SelectObj(void)
{
register long i,j;
register void *pv;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char chRetCode;
		unsigned short ushIdObj;
	    //.unsigned char *pUchTR;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
union 
    {
    	unsigned char   uchAr [4];
    	unsigned short  ushAr [2];
        unsigned long   ulVal;
    }unnV1;
//Look Param SrcSamplesUnit
	sLV.ushIdObj = 0;
//Look Param SrcTest1Unit
	
	return sLV.ushIdObj;
}
long PrepareDecompouseTrEvt(long lIdObj)
{

	return 0;//Return Handle Data 
}

*/
long lAmtScanChnlSpiErrors = 0;
long lAmtScanChnlU2Errors = 0;

void ProcessReceiveEvt(void)  @ "Fastest_function" //Fast_function"
{
register long i;
register void *pv;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char chRetCode,chBusyChnl;
		unsigned short ushIdObj;
	    //.unsigned char *pUchTR;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
sLV.chBusyChnl = 0;i = 0;

//	pv = (void*)&hldrHSU7LpduUnit;
//	if( ((RVStateLpuHSU7Dsc*)pv)->uchLpuHSU7State == 1 )
//	i = ScanCnl(ID_CNL_HSU7);
//	if (i==0 || i==0xff )
//	((RVStateLpuHSU7Dsc*)pv)->uchLpuHSU7State = 0;
//	else
//	{
//		;//Handle Error !!!!!!!!!
//	}
	
 	pv = (void*)&hldrU2LpduRvUnit;
 	if( ((RVStateLpuU2Dsc*)pv)->uchLpuU2State == 1 )
 	i = ScanCnl(ID_CNL_U2);
 	if (i==0 || i==0xff )
 	((RVStateLpuU2Dsc*)pv)->uchLpuU2State = 0;
 	else
 	{
 		lAmtScanChnlU2Errors++;//Handle Error !!!!!!!!!
		((RVStateLpuSpiDsc*)pv)->uchLpuSpiState = 0;
 	}
	pv = (void*)&hldrSpiLpduUnit;
	if( ((RVStateLpuSpiDsc*)pv)->uchLpuSpiState == 1 )
	i = ScanCnl(ID_CNL_SPI);
	if (i==0 || i==0xff )
	((RVStateLpuSpiDsc*)pv)->uchLpuSpiState = 0;
	else
	{
		 lAmtScanChnlSpiErrors++;//Handle Error !!!!!!!!!
		((RVStateLpuSpiDsc*)pv)->uchLpuSpiState = 0;
	}
//	pv = (void*)&hldrU0LpduRvUnit;
//	if( ((RVStateLpuU0Dsc*)pv)->uchLpuU0State == 1 )
//	i = ScanCnl(ID_CNL_U0);
//	if (i==0 || i==0xff )
//	((RVStateLpuU0Dsc*)pv)->uchLpuU0State = 0;
//	else
//	{
//		;//Handle Error !!!!!!!!! 
//	}
	
	
	
	//Control Process Receive Object Verification



}

void SamplesRvServCTpuApCnUnit(void);

void UpdateAppData(void)  @ "Fast_function"
{
//Hundle here All Ses Fix Msg 
	if (TestReqReceiveT1)
	{
		SamplesRvServCTpuApCnUnit();
		
	}
	if (TestReqReceiveTenPerSamples)
	{
		TenPerSamplesRvServCTpuApCnUnit();
		//Call Proxy Back Service???
	}
	if (TestReqReceiveTotMeas)
	{
		TotMeasRvServCTpuApCnUnit();
		//Call Proxy Back Service???
	}
	if (AppReqReceiveTotMeasG)
	{
		//TotMeasGRvServCTpuApCnUnit();
		//Call Proxy Back Service???   Activator Raw DATA
	}
	if (AppReqReceiveRawSampl)
	{
		AppReqReceiveRawSampl--;//TotMeasGRvServCTpuApCnUnit();
		//Call Proxy Back Service???
	}
	
	
}

void SamplesRvServCTpuApCnUnit(void)  @ "Fast_function"
{
register long i,j;
register char *pch;
register void* pv;
//Detect if Data Not Used Update


//Copy
  pch = (char *)&( holderRVSrcSamplesCTpuUnit.arUchRV);
  
  pv  = (void*)& holderSrcSamplesUnit;
  j = sizeof(SrcSamplesUnitDsc);
  for (i = 0; i < j; i++)
  {
     ((char*)pv)[i] = pch[i];
  }
  //Reset Connect State
//   pv  = (void*)& (holderTRSrcSamplesCTpuUnit.TrCnHldr);
   
//.   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU7;// If need change
//.   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU7;// Logic can ctrl
//.   
//.  
//.   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
//.   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(SrcSamplesUnitDsc);
//.   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SRC_SAMPLES_UNIT;
//.   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
//.   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   TestReqReceiveT1 = 0;
   //Set Addition data for Use Data
   
}



void TestSetup_SrcSamples_ForTransmit(void)
{
 TestReqTransmitT1 = START;

//.hldrTpCnState.uchTpState_CNL_HSU7  = 1;
//.hldrTpCnState.PayloadLPDU_HSU7     = //SIZE_LPDU_CNL_HSU7
//.0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
//.hldrTpCnState.lCapicity_CNL_HSU7   = SIZE_LPDU_CNL_HSU7
//.-(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7+SIZE_CS_FLD_CNL_HSU7+SIZE_TOTAL_LDC );
//.hldrTpCnState.pUchLpuTR_CNL_HSU7   = (unsigned char*)&hldrHSU7LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7+SIZE_TOTAL_LDC];//DemoStr;
//.
//.
//.
//.
//.hldrHSU7LpduTRUnit.uchLpuHSU7State = 0;
//.//
//.
//.	
//.hldrHSU7LpduTRUnit.lCapicity  = 0;//
//.hldrHSU7LpduTRUnit.uchCI      = 0;
//.hldrHSU7LpduTRUnit.ushSizeLDC = 0;
//.hldrHSU7LpduTRUnit.lCs        = 0;

hldrTpCnState.uchTpState_CNL_HSU2  = 1;
hldrTpCnState.PayloadLPDU_HSU2     = //SIZE_LPDU_CNL_HSU7
0;//(SIZE_LPCI_FLD_CNL_HSU7+SIZE_LDC_FLD_CNL_HSU7);
hldrTpCnState.lCapicity_CNL_HSU2   = SIZE_LPDU_CNL_HSU2
-(SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_CS_FLD_CNL_HSU2+SIZE_TOTAL_LDC );
hldrTpCnState.pUchLpuTR_CNL_HSU2   = (unsigned char*)&hldrHSU2LpduTRUnit.arUch[SIZE_LPCI_FLD_CNL_HSU2+SIZE_LDC_FLD_CNL_HSU2+SIZE_TOTAL_LDC];//DemoStr;




hldrHSU2LpduTRUnit.uchLpuHSU2State = 0;
//	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
hldrHSU2LpduTRUnit.lCapicity  = 0;//
hldrHSU2LpduTRUnit.uchCI      = 0;
hldrHSU2LpduTRUnit.ushSizeLDC = 0;
hldrHSU2LpduTRUnit.lCs        = 0;



}

void ExecProxyTps(void)  @ "Fast_function"
{
    register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = 0;
	
	
	pv = (void*)&holderProxyTenPerSamplesUnit;
	i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	
	j = (i&(USING_OCS_MSK)); 
	if (j==0) return;
	{
		j = ((i&STT_WORK_OCS_MSK)== 0 )&& (i&(STT_START_OCS_MSK));
		j = (i&(STT_WORK_OCS_MSK));
		j = (i&(STT_START_OCS_MSK));
		if (j)
		sLV.uChIdxBit =  STT_START_OCS_ONB;
		j =  (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);
		if (j)
		sLV.uChIdxBit =  STT_WORK_OCS_ONB;
		j = (i&(STT_STOP_OCS_MSK));
		if (j)
		sLV.uChIdxBit =  STT_STOP_OCS_ONB;
		
		if(sLV.uChIdxBit)
		{
			i = (long)((BaseAcpuCMUnitDsc*)pv)-> pf_Work;
			if(i)
			{
				sLV.pfl_vl = (PFL_VL)i;
				i = sLV.pfl_vl(pv,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
			}	
		}
	}
	
}
void ExecProxyTotMeas(void)  @ "Fast_function"
{
    register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = 0;
	
	pv = (void*)&holderProxyTotMeasUnit;
	i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	
	j = (i&(USING_OCS_MSK)); 
	if (j==0) return;
	{
		j = ((i&STT_WORK_OCS_MSK)== 0 )&& (i&(STT_START_OCS_MSK));
		j = (i&(STT_WORK_OCS_MSK));
		j = (i&(STT_START_OCS_MSK));
		if (j)
		sLV.uChIdxBit =  STT_START_OCS_ONB;
		j =  (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);
		if (j)
		sLV.uChIdxBit =  STT_WORK_OCS_ONB;
		j = (i&(STT_STOP_OCS_MSK));
		if (j)
		sLV.uChIdxBit =  STT_STOP_OCS_ONB;
		
		if(sLV.uChIdxBit)
		{
			i = (long)((BaseAcpuCMUnitDsc*)pv)-> pf_Work;
			if(i)
			{
				sLV.pfl_vl = (PFL_VL)i;
				i = sLV.pfl_vl(pv,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
			}	
		}
	}

}
long lCtrAmtExecProxy = 0;
long  ExecExistProxy(void* pvProxy)    @ "Fastest_function" //@ "Fast_function"
{
    //register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = i = 0;
	
	
	//pv = (void*)&holderProxyTenPerSamplesUnit;
	i = ((BaseAcpuCMUnitDsc*)pvProxy)-> AppObjConState;
	
	j = (i&(USING_OCS_MSK)); 
	if (j==0) return 0 ;
	
	j = ((i&STT_WORK_OCS_MSK)== 0 )&& (i&(STT_START_OCS_MSK));
	j = (i&(STT_WORK_OCS_MSK));
	j = (i&(STT_START_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  STT_START_OCS_ONB;
	j =  (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);
	if (j)
	sLV.uChIdxBit =  STT_WORK_OCS_ONB;
	j = (i&(STT_STOP_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  STT_STOP_OCS_ONB;
	 
	if(sLV.uChIdxBit)
	{
	    i = (long)((BaseAcpuCMUnitDsc*)pvProxy)-> pf_Work;
		if(i)
		{
			sLV.pfl_vl = (PFL_VL)i;
			i = sLV.pfl_vl(pvProxy,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
			lCtrAmtExecProxy++;
		}	
	}
	else
	{
		i = 0;
	}
	
return i;


}


long ExecExistProxyManager(void* pvPrMng)  @ "Fast_function"
{
    //register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = i = 0;
	
	
	//pv = (void*)&holderProxyTenPerSamplesUnit;
	i = ((ProxyMangerStateDsc*)pvPrMng)-> shPrMngConState;
	
	j = (i&(PM_STT_USING_OCS_MSK)); 
	if (j==0) return 0;
	
	j = ((i&PM_STT_WORK_OCS_MSK)== 0 )&& (i&(PM_STT_START_OCS_MSK));
	j = (i&(PM_STT_WORK_OCS_MSK));
	j = (i&(PM_STT_START_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  PM_STT_START_OCS_ONB;
	j =  (i&(PM_STT_WORK_OCS_MSK)) && ((i&( PM_STT_STOP_OCS_MSK ))==0);
	if (j)
	sLV.uChIdxBit =  PM_STT_WORK_OCS_ONB;
	j = (i&(PM_STT_STOP_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  PM_STT_STOP_OCS_ONB;
	 
	if(sLV.uChIdxBit)
	{
	    i = (long)((ProxyMangerStateDsc*)pvPrMng)-> pf_Work;
		if(i)
		{
			sLV.pfl_vl = (PFL_VL)i;
			i = sLV.pfl_vl(pvPrMng,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
			
		}	
	}
	else
	{
		i = 0;
	}
	

return i; 

}


extern unsigned long ulReqIciCall;

void ExecProxy(void)  @ "Fastest_function" //Fast_function"
{
    register void* pv;
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;
		//short shErr;
		//unsigned short ushSizeLDC;
		//unsigned short IdConObj;
		//void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
	//PFL_VL pfl_vl;
	sLV.uChIdxBit = 0;
	
	
/*
	
	pv = (void*)&hldPrMngSettings;
	j = ExecExistProxyManager(pv);
	
	pv = (void*)&hldPrTrptSettings;
	j = ExecExistProxy(pv);
	if (i||j)
	goto ExitExecProxy;
	
/*	pv = (void*)&hldPrMngYust;
	i = ExecExistProxyManager(pv);
	
	pv = (void*)&hldPrTrptYust;
	j = ExecExistProxy(pv);
	if (i||j)
	goto ExitExecProxy;
	*/
	pv = (void*)&hldPrMngPrtTbl;//`hldPrMngYust;
	i = ExecExistProxyManager(pv);
	
	pv = (void*)&hldPrTrptPrtTbl; //` hldPrTrptYust;
	j = ExecExistProxy(pv);
	if (i||j)
	goto ExitExecProxy;
	
		pv = (void*)&holderProxyTenPerSamplesUnit;
	i = ExecExistProxy(pv);
	if (i)
	{
		//if (lCtrAmtExecProxy<2) 
		//ulReqIciCall++;//goto ExitExecProxy;
		//else 
		//ulReqIciCall = 2;
		//goto ExitExecProxy;
	}	
	
	pv = (void*)&holderProxyTotMeasUnit;
	j = ExecExistProxy(pv);
	if (j)
	goto ExitExecProxy;
	
	pv = (void*)&holderProxySettingsUnit;
	i = ExecExistProxy(pv);
ExitExecProxy: 	
	lCtrAmtExecProxy = 0;
return;
}

void PrepDecompouseSrcSamplesUnitHSU0(void)  @ "Fast_function"
{
register long i,j;
register void *pv;
	pv = (void*)&hldrTpCnState;
	//Control then All Channels Full
	//.if()
	//.{
	//.
	//.}
	//Control State Obj if Need Transmit
	//Process
	if(TestReqTransmitT1)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_U0;j = sizeof(SrcSamplesUnitDsc)>>2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitT1==START)
			{
				ActivateServTrApCnSamplesCTpuUnitHSU2();
				TestReqTransmitT1 = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitT1==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRSrcSamplesCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitT1 = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				TestReqTransmitT1 = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitT1==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TestReqTransmitT1 = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


void Ici10msRing(void)
{
	if (AppReqReceiveTotMeasG)
	{
		TotMeasGRvServCTpuApCnUnit();
		//Call Proxy Back Service???   Activator Raw DATA
	}


}





#include    "proxy4.c"
#include    "mTotprx.c"
#include    "mTotG.c"
#include    "SmpWrp.c"

#include    "Stngprx.c"
#include    "Apcs.c"
#include    "MnPrPrt.c"
#include    "GoosB.c"
#include    "GoosA.c"
#include    "Tlmc.c"



