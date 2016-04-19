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
* File Name       : Ctpu.c
* Description     : Functions and Data for Transport Leyer
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "ApCn.h"
#include    "CTpu.h"
#include    "lpu.h"
//#include    "lpu.h"
#include    "ApMeasG.h"
#include    "SmpWrp.h"
#include    "Apcs.h"
#include    "GoosA.h"
#include    "ici_ef.h"
#include    "MnPrStng.h"
#include    "MnPrPrt.h"
#include    "Tlmc.h"


TRSrcSamplesCTpuUnitDsc holderTRSrcSamplesCTpuUnit;

RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit;
TR10PeriodCTpuUnitDsc  holderTR10PeriodCTpuUnit;
RV10PeriodCTpuUnitDsc  holderRV10PeriodCTpuUnit;

TRTotMeasCTpuUnitDsc holderTRTotMeasCTpuUnit;
RVTotMeasCTpuUnitDsc  holderRVTotMeasCTpuUnit;

TRTotMeasGSOCTpuUnitDsc holderTRTotMeasGSOCTpuUnit = {
{'R','e','q','u','e','s','t',' ','M','e','a','s','u','r','e',' '},
{0,0,0,0,SIZE_TPDU_TOT_MEASG_CNL_HSU2,0,0,0,(void*)&holderTRTotMeasGSOCTpuUnit.arUchTR}
};
RVTotMeasGSOCTpuUnitDsc holderRVTotMeasGSOCTpuUnit = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,SIZE_TPDU_TOT_MEASG_CNL_HSU2,0,0,(void*)&holderTotMeasG.UNTotMeas.chArTotMeas[0]}
};
RVRawSamplSOCTpuUnitDsc  holderRVRawSamplSOCTpuUnit= {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,SIZE_TPDU_RAW_SAMPLES_CNL_HSU2,0,0,(void*)&holderRawSampl.UNRawSampl.chArSmpl[0]}
};


TRSettingsCTpuUnitDsc holderTRSettingsCTpuUnit;
RVSettingsCTpuUnitDsc holderRVSettingsCTpuUnit;
TRStngPrMngCTpuUnitDsc hldrTRStngPrMngCTpuUnit;
RVStngPrMngCTpuUnitDsc hldrRVStngPrMngCTpuUnit;
TRStngTransportCTpuUnitDsc hldrTRStngTransportCTpuUnit;
RVStngTransportCTpuUnitDsc hldrRVStngTransportCTpuUnit;


TRYustCTpuUnitDsc holderTRYustCTpuUnit;
RVYustCTpuUnitDsc holderRVYustCTpuUnit;

TRYustPrMngCTpuUnitDsc     hldrTRYustPrMngCTpuUnit;
RVYustPrMngCTpuUnitDsc     hldrRVYustPrMngCTpuUnit;
TRYustTransportCTpuUnitDsc hldrTRYustTransportCTpuUnit;
RVYustTransportCTpuUnitDsc hldrRVYustTransportCTpuUnit;

TRApcsSOCTpuUnitDsc  holderTRApcsSOCTpuUnit;
RVApcsSOCTpuUnitDsc  holderRVApcsSOCTpuUnit = {
 {0,0,0,0},//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0, SIZE_TPDU_APCS_CNL_SPI,0,0,(void*)&holderApcs.UNApcs.chArApcs[0]}
 };
 

#define DEFAULT_SIZE_PR_TBL_MSG 1 
TRPrtTblPrMngCTpuUnitDsc hldrTRPrtTblPrMngCTpuUnit = {
{'P','r','t','T','b','l','T','r'},//{'S','t','a','r','t',' ','I','n','i','t','','D','a','t','a',' '},
{ID_CNL_SPI,ID_CNL_SPI,0,0,SIZE_TPDU_PRT_PR_MNG_CNL_SPI,DEFAULT_SIZE_PR_TBL_MSG,ID_PRT_PR_MNG,0,hldrTRPrtTblPrMngCTpuUnit.arUchTR}
}; 
RVPrtTblPrMngCTpuUnitDsc hldrRVPrtTblPrMngCTpuUnit = {
{'P','r','t','T','b','l','R','V'},
{ID_CNL_SPI,0, SIZE_TPDU_PRT_PR_MNG_CNL_SPI,0,0,(unsigned char*)&(hldrRVPrtTblPrMngCTpuUnit.arUchRV)}
}; 
 
TRPrtTblTransportCTpuUnitDsc hldrTRPrtTblTransportCTpuUnit; 
RVPrtTblTransportCTpuUnitDsc hldrRVPrtTblTransportCTpuUnit = {
 {0,0,0,0},//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0, SIZE_TPDU_TRANSPORT_PRT_CNL_SPI,0,0,(void*)&holderPrtTbl.UNPrtTbl.chArPrt[0]}
 }; 
 

RVTeleMechsSOCTpuUnitDsc  holderRVTeleMechsSOCTpuUnit = {
 {0,0,0,0},//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,0,SIZE_TPDU_TELE_MECHS_CNL_SPI,0,0,(void*)&holderTeleMechs.UNTeleMechs.lArTeleMechs[0]}
 };
 
 #define DEFAULT_SIZE_FCOIL_MSG 10
 TRFCoilSOCTpuUnitDsc  holderTRFCoilSOCTpuUnit = {
 {'C','o','i','l',' ',' ','T','r'},
 {ID_CNL_SPI,ID_CNL_SPI,0,0,SIZE_TPDU_FCOIL_CNL_SPI,DEFAULT_SIZE_FCOIL_MSG,ID_FCOIL_UNIT,0,holderTRFCoilSOCTpuUnit.arUchTR}
 }; 

 #define DEFAULT_SIZE_DATE_TIME_MSG 10
TRDateTimeSOCTpuUnitDsc  holderTRDateTimeSOCTpuUnit = {
{'D','a','t','e','t','i','m','e'},
{ID_CNL_SPI,ID_CNL_SPI,0,0,SIZE_TPDU_DATE_TIME_CNL_SPI,DEFAULT_SIZE_DATE_TIME_MSG,ID_DATE_TIME_UNIT,0,holderTRDateTimeSOCTpuUnit.arUchTR}
};

#define DEFAULT_SIZE_ATR_CMD_MSG 36
TRAtrCmdSOCTpuUnitDsc  holderTRAtrCmdSOCTpuUnit = {
{'A','t','r',' ','C','m','d',' '},
{ID_CNL_SPI,ID_CNL_SPI,0,0,SIZE_TPDU_ATR_CMD_CNL_SPI,DEFAULT_SIZE_ATR_CMD_MSG,ID_ATR_CMD_UNIT,0,holderTRAtrCmdSOCTpuUnit.arUchTR}
};
RVAtrCmdSOCTpuUnitDsc  holderRVAtrCmdSOCTpuUnit = {
 {0,0,0,0},
 {0,0,SIZE_TPDU_ATR_CMD_CNL_SPI,0,0,(void*)&(holderRVAtrCmdSOCTpuUnit.arUchRV)}//holderAtrCmdReally?
 };

RVDiagnBsBmSOCTpuUnitDsc  holderRVDiagnBsBmSOCTpuUnit = {
{'D','i','a','g','n',' ','R','V'},
{ID_CNL_HSU2,0, SIZE_TPDU_DIAGN_BS_CNL_HSU2,0,0,(unsigned char*)&(holderRVDiagnBsBmSOCTpuUnit.arUchRV)}
}; 
 


#define DEFAULT_SIZE_DIAGN_MSG 16 
TRDiagnBsBrSOCTpuUnitDsc  holderTRDiagnBsBrSOCTpuUnit = {
{'D','i','a','g','n',' ','B','s'},
{ID_CNL_SPI,ID_CNL_SPI,0,0,SIZE_TPDU_DIAGN_BS_CNL_SPI,DEFAULT_SIZE_DIAGN_MSG,ID_DIAGN_BS_UNIT,0,holderTRDiagnBsBrSOCTpuUnit.arUchTR}
};
 

RVDiagnBsBrSOCTpuUnitDsc  holderRVDiagnBsBrSOCTpuUnit = { 
{'D','i','a','g','n',' ','B','s'},
{ID_CNL_SPI,0, SIZE_TPDU_DIAGN_BS_CNL_SPI,0,0,(unsigned char*)&(holderRVDiagnBsBrSOCTpuUnit.arUchRV)}
}; 

RVTotVerInfoBmSOCTpuUnitDsc  holderRVTotVerInfoBmSOCTpuUnit = {
{'T','o','t','V','e','r','I','n','f','o'},
{ID_CNL_HSU2,0, SIZE_TPDU_VER_INFO_BM_CNL_HSU2,0,0,(unsigned char*)&(holderRVTotVerInfoBmSOCTpuUnit.arUchRV)}
}; 
 
RVTotVerInfoBrSOCTpuUnitDsc  holderRVTotVerInfoBrSOCTpuUnit = {
{'T','o','t','V','e','r','I','n','f','o','B','r'},
{ID_CNL_SPI,0, SIZE_TPDU_VER_INFO_BR_CNL_SPI,0,0,(unsigned char*)&(holderRVTotVerInfoBrSOCTpuUnit.arUchRV)}
}; 
 
 #define DEFAULT_SIZE_UNN_ABS_NUMERTRS 9
TRAbsNumeratorUnnSOCTpuUnitDsc holderTRAbsNumeratorUnnSOCTpuUnit = {
{'N','u','n','e','r','a','t','r'},
{ID_CNL_SPI,ID_CNL_SPI,0,0,
SIZE_TPDU_UNN_ABS_NUMERTRS_BR_CNL_SPI, DEFAULT_SIZE_UNN_ABS_NUMERTRS ,
ID_UNN_ABS_NUMERTRS_UNIT,0,
 holderTRAbsNumeratorUnnSOCTpuUnit.arUchTR}

};

RVUN_ArecSOCTpuUnitDsc  holderRVUN_ArecSOCTpuUnit  = { 
{'G','U','s','t'},
{ID_CNL_SPI,0, SIZE_TPDU_ANL_RECORD_BR_CNL_SPI,0,0,(unsigned char*)&(holderRVUN_ArecSOCTpuUnit.arUchRV)}
}; 

TRGoosASOCTpuUnitDsc  holderTRGoosASOCTpuUnit;
RVGoosASOCTpuUnitDsc  holderRVGoosASOCTpuUnit = {
 {0,0,0,0},
 {ID_CNL_SPI,0, SIZE_TPDU_GOOS_A_CNL_SPI,0,0,(void*)&holderGoosA.UNGoosA.chArGoosA[0]}
};

TRGoosBSOCTpuUnitDsc  holderTRGoosBSOCTpuUnit; 
RVGoosBSOCTpuUnitDsc  holderRVGoosBSOCTpuUnit;  
 
 
 
StateTpCnDsc hldrTpCnState;
StateTpCnDsc  hldrRVTpCnState;


















void ActivateServTrApCnSamplesCTpuUnit(void);

void ActivateServiceTrApCn(void* pvD,long IdObj)
{
//register long i,j;
//register char *pch;
////Copy
//  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
//  for (i = 0; i < sizeof(SrcSamplesUnitDsc); i++)
//  {
//    pch[i] = ((char*)pvD)[i];
//  }
//
	ActivateServTrApCnSamplesCTpuUnit();
	TestReqTransmitT1 = EXEC;
}

void ActivateServTrApCnSamplesCTpuUnit(void)  @ "Fast_function"
{
register long i,j;
register char *pch;
register void* pv;
//Copy
  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  pv  = (void*)& holderSrcSamplesUnit;
  j = sizeof(SrcSamplesUnitDsc);
  for (i = 0; i < j; i++)
  {
    pch[i] = ((char*)pv)[i];
  }
  //Reset Connect State
   pv  = (void*)& (holderTRSrcSamplesCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU7;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU7;// Logic can ctrl
   
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SRC_SAMPLES_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void ActivateServTrApCnSamplesCTpuUnitHSU2(void)  @ "Fast_function"
{
register long i,j;
register char *pch;
register void* pv;
//Copy
  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  pv  = (void*)& holderSrcSamplesUnit;
  j = sizeof(SrcSamplesUnitDsc);
  for (i = 0; i < j; i++)
  {
    pch[i] = ((char*)pv)[i];
  }
  //Reset Connect State
   pv  = (void*)& (holderTRSrcSamplesCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SRC_SAMPLES_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void ServiceTRApCn(void* pvD,long IdObj)
{
//register long i,j;
//Detect Type Desirable  Cannel

}
/*
int ServiceTRApCn1(void* pvCTpuTR,void* pvStateTpCnDsc )
{
register long i,j;
register void *pv;
struct 
	{
		//short         shCountCmd;  
		//unsigned char uChIdxByte ;
		//unsigned char uChIdxBit ;
		//short shErr;
		char ch1,ch2,ch3,ch4;
		unsigned short ConState;
		unsigned short ushTrCount;
		unsigned short ushCapicity;
		unsigned short ushSizeLDC;
	    //.unsigned char *pUchTR;//
		void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
	
//Save pointers
sLV.pOriginTR     = pvCTpuTR;
sLV.pOriginTpCn   = pvStateTpCnDsc;
	j = ((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1;
	i = ((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1;
	
	if (i<4 && j )
	return 1;//Capicity full
	//-sLV.ConState    = 0;sLV.ushTrCount  = 0;	sLV.ushCapicity = 0;
	sLV.ushSizeLDC  = 0;
	//Detect State 	CTpuTR side
	sLV.ch1 = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchBaseTransport;
	sLV.ch2 = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchUsedTransport;
	sLV.ch3 = i = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ConState;
	if ((i&0xf) == SUCCESS_EXEC)
	{
		
		return 0;
	}
	i = sLV.ch3;//Connection state
	if (i&(MODE_LDC))
	goto ttt;
	
	
	
	
	//Detect state TpCn side
	sLV.Capicity = j = ((StateTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL_1;
	sLV.ushTrCount = i = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount;
	if (j>i)
	{
		//Put Total
	}
	else
	{
		//Detect Avail Part 
		i = sLV.Capicity - 4;
		sLV.ushTrCount = i;
		j = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount;
		((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount = j - i;//
		
		i = sLV.Capicity - sLV.ushTrCount
		((StateTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL_1  = i;
		((StateTpCnDsc*)pvStateTpCnDsc)->uchTpState_CNL_1 = 1;
		pv = (void*)(((StateTpCnDsc*)pvStateTpCnDsc)->pUchLpuTR_CNL_1);
	}
	
//Prepea transmision data


//Put 	transmision data
AsemblyLDC:


	
	
	
//((EmrEventDsc*)p_out_param)->EvtField	
}
*/

long SetCnlStatetoRun(long lID_Cnl,void* pvStateTpCnDsc)
{

return 0;
}
long CutCnlCapicity(long lID_Cnl,void* pvStateTpCnDsc)
{

return 0;
} 

long SetStateCnlTpCn(long lID_Cnl,void* pvStateTpCnDsc, void* pvTpCn)  @ "Fast_function"
{
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		  
		
		 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1 =  
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_CNL_1) = 
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1 =
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		   
		//.(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_1) = 		
		//.((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL;
		break;
	case ID_CNL_HSU7:
		
		
		  
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU7 =
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		   
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_HSU7) =
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_HSU7 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_HSU7 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL;
		
		 
		//.(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_HSU7) = 
		//.((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL ;	
		
		break;
 	case ID_CNL_HSU2:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU2 =
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		   
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_HSU2) =
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_HSU2 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_HSU2 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL;
		
 		break;
    case ID_CNL_U2:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_U2 =
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		   
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_U2) =
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_U2 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_U2 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL;
		
 		break;
     case ID_CNL_U0:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_U0 =
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		   
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_U0) =
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_U0 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_U0 = 
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL;
		
 		break;
	case ID_CNL_DBGU:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_DBGU =
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		   
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_DBGU) =
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_DBGU = 
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_DBGU = 
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL;
		
 		break;
	case ID_CNL_SPI:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_Spi =
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL;
		   
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_Spi) =
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU;
		   
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_Spi = 
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL;
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_Spi = 
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL;
		
 		break;	
		

//.	case 6:
//.	
//.		break;
	default:
	lID_Cnl =0;
	}	

return lID_Cnl;
}
long GetStateCnlTpCn(long lID_Cnl,void* pvStateTpCnDsc, void* pvTpCn)  @ "Fast_function"
{
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_CNL_1);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_1);		
		//.j = ((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1;
	    //.i = ((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1;
		//.sLV.IdxLpuBuf = (((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_CNL_1)
		//.- (((StateTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL_1);
		//.sLV.pUchTR = (((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_1);
		break;
	case ID_CNL_HSU7:
		
		//.j = ((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU7;
	    //.i = ((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_HSU7;
		//.sLV.IdxLpuBuf = (((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_HSU7)
		//.- (((StateTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL_HSU7);
		//.sLV.pUchTR = (((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_HSU7);
		((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU7;
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_HSU7;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_HSU7);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_HSU7;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_HSU7);	
		
		break;
	case ID_CNL_HSU2:
	    ((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU2;
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_HSU2;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_HSU2);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_HSU2;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_HSU2);	
		
		break;
    case ID_CNL_U2:
	    ((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_U2;
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_U2;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_U2);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_U2;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_U2);	
		
		break;
    case ID_CNL_U0:
	    ((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_U0;
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_U0;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_U0);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_U0;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_U0);	
		
		break;
     case ID_CNL_DBGU:
	    ((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_DBGU;
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_DBGU;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_DBGU);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_DBGU;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_DBGU);	
		
		break;
	case ID_CNL_SPI:
	    ((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_Spi;
		((StateCnlTRTpCnDsc*)pvTpCn)->chTotalLDC_CNL = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL_Spi;
		
		((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_Spi);
		((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_Spi;
		((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_Spi);	
		
		break;	
	
//.	case 6:
//.	
//.		break;
	default:
	lID_Cnl =0;
	}	

return lID_Cnl;
}
long SetFld_TpState_CNL(long lID_Cnl,void* pvStateTpCnDsc,long lV);
long GetFld_TpState_CNL(long lID_Cnl);
int ServiceTRApCn2(void* pvCTpuTR,void* pvStateTpCnDsc )  @ "Fast_function"
{
register long i,j;
register void *pv;
struct 
	{

		char chFld1,chFld2,chFld3,chFld4;
		char AuxSesFldWeight,chRetCode;
		char  chIDCNL;
		unsigned short ConState,IdxLpuBuf;
		unsigned short ushTrCount;
		unsigned short ushCapicity;
		unsigned short ushSizeLDC;
	    unsigned char *pUchTR;//
		void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
	
    union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;
LDCIDsc hldLDCI;
StateCnlTRTpCnDsc hldStateCnlTRTpCnDsc;	
//Save pointers
sLV.pOriginTR     = pvCTpuTR;
sLV.pOriginTpCn   = pvStateTpCnDsc;
//sLV.pUchTR  = ((StateTpCnDsc*)pvStateTpCnDsc)->pUchLpuTR_CNL_HSU7;
//Detect channell
    i = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchUsedTransport;
	sLV.chIDCNL = i;
	sLV.chRetCode = 0;
    GetStateCnlTpCn(i,pvStateTpCnDsc,(void*)&hldStateCnlTRTpCnDsc );
	
	
	pvStateTpCnDsc = (void*)&hldStateCnlTRTpCnDsc;
	sLV.IdxLpuBuf = (((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> shPayloadLPDU);
	sLV.pUchTR  = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL;
	//.(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL);
	//((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL;
    //...j = ((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1;
	//...i = ((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1;
    j = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL;
	i = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL;
	
	sLV.chRetCode = 0;sLV.chFld2 = 0;
	if (i<4 && j )
		{
		sLV.chRetCode |= (1<<7);
		return sLV.chRetCode;//Capicity full
	}	
	//-sLV.ConState    = 0;sLV.ushTrCount  = 0;	sLV.ushCapicity = 0;
	sLV.ushSizeLDC  = 0;
	sLV.ushCapicity = i;sLV.chFld4 = j;
	sLV.AuxSesFldWeight = SIZE_WLDC_FLD;//.!!! Insert Control using sLV.chIDCNL 
	//Detect State 	CTpuTR side
	//..sLV.ch1 = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchBaseTransport;
	//..sLV.ch2 = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchUsedTransport;
	//..sLV.ch3 = i = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ConState;
	i = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj;
	sLV. ushTrCount = j = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount;
	if(i>j)
	;
	else
	{
		//Terminate Transport
	}

	//Detect state TpCn side
	//if (sLV. ushTrCount)
	if (j==0)
	{
		//Start Sesion
		i = sLV.ushCapicity - sLV.AuxSesFldWeight;
		if (i >(((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchSizeCTpuBuf)) 
		{
			i = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchSizeCTpuBuf);
			i -= sLV.AuxSesFldWeight;
		}	
		if (i>(((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj))
		{
			pv = (void*)&hldLDCI;
			((LDCIDsc*)pv)->uchConMode     = 0;
			((LDCIDsc*)pv)->uchStartSesion = 1;
			((LDCIDsc*)pv)->uchTR_C        = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj);//Size
			((LDCIDsc*)pv)->NumComSes      = 0;
			((LDCIDsc*)pv)->IdConObj       = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->IdConObj;
			((LDCIDsc*)pv)->pSrc           = (char*)(((TRBaseCTpuUnitDsc*)pvCTpuTR)->pUchTR);
			//...j = (((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_CNL_1)
			//...- (((StateTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL_1);//Actual Index lpu buf
			j =((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> shPayloadLPDU;
			//-((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL;
			sLV.IdxLpuBuf = j;
			
			((LDCIDsc*)pv)->pDst           = (char*)(j +sLV.pUchTR);//(SIZE_LPDU_CNL1)
			//...(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_1));//+ ((LDCIDsc*)pv)->uchTR_C -old 
			;
			//Call Assembly Routine
			sLV.ushSizeLDC  =  AsemblyLDC(&hldLDCI);
			//Reset Var need for Transmit
			((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount = 0;
			((TRBaseCTpuUnitDsc*)pvCTpuTR)->ConState  = 0;//SUCCESS_EXEC???
			
			//...j =((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1;j++;
			//...((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1 = j;
			//..j = SetCnlStatetoRun(sLV.chIDCNL,sLV.pOriginTpCn,pvStateTpCnDsc);//
			j =((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL;j++;
			((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL = j;
			
			
			
			j = ((LDCIDsc*)pv)->uchTR_C;j = sLV.ushSizeLDC;// + sLV.AuxSesFldWeight;
			//...((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1 -= j;
			//...CutCnlCapicity(sLV.chIDCNL);
			((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL -= j+(SIZE_WLDC_FLD);
			(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> shPayloadLPDU) += j+(SIZE_WLDC_FLD);
			(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL) += 1;
			unnV1.ulVal = SetStateCnlTpCn(sLV.chIDCNL,sLV.pOriginTpCn,pvStateTpCnDsc);
			//Terminate Session Curr Obj
			sLV.chRetCode |= (1<<6);
		}
		else
		{
			i = sLV.ushCapicity - sLV.AuxSesFldWeight;
			i -= (SIZE_ID_COM_SES + SIZE_NUM_COM_SES ); //+ SIZE_TR_C
			if (i> 4)//-Minimal Size LDC((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj
			{
			
				if (i >(((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchSizeCTpuBuf)) 
				{
					i = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchSizeCTpuBuf);
					i -= sLV.AuxSesFldWeight+(SIZE_ID_COM_SES + SIZE_NUM_COM_SES );
				}	
				//Cut Obj
				pv = (void*)&hldLDCI;
				((LDCIDsc*)pv)->IdConObj       = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->IdConObj;
				((LDCIDsc*)pv)->pSrc           = (char*)(((TRBaseCTpuUnitDsc*)pvCTpuTR)->pUchTR);
				
				((LDCIDsc*)pv)->uchConMode     = 1;
				((LDCIDsc*)pv)->uchStartSesion = 1;
				((LDCIDsc*)pv)->uchTR_C        =  i;//(((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj);//Size
				j = ((LDCIDsc*)pv)->NumComSes;j++;
				if(j>=16) j=1;
				((LDCIDsc*)pv)->NumComSes      = j;
				
				//.j = (((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_CNL_1)
				//.- (((StateTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL_1);//Actual Index lpu buf
			    j = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->shPayloadLPDU;
				sLV.IdxLpuBuf = j;//-1;
				
				((LDCIDsc*)pv)->pDst           = (char*)(j +//
				((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->pUchLpuTR_CNL);
				
				sLV.ushSizeLDC  =  AsemblyLDC(&hldLDCI);
				
				((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount = ((LDCIDsc*)pv)->uchTR_C;//sLV.ushSizeLDC;
			    ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ConState  = 1;//
				((TRBaseCTpuUnitDsc*)pvCTpuTR)->NumComSes = ((LDCIDsc*)pv)->NumComSes;
				sLV.chFld2 = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL;
				j = 0x7f&sLV.chFld2; j++;sLV.chFld2 &=0x80;//j =((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL;j++;
				((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL = j|sLV.chFld2;//((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL = j;
				j = ((LDCIDsc*)pv)->uchTR_C;j = sLV.ushSizeLDC;// + sLV.AuxSesFldWeight;
				
				((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL -= j+(SIZE_WLDC_FLD);
				(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> shPayloadLPDU) += j+(SIZE_WLDC_FLD);
				(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL) += 1;
				unnV1.ulVal = SetStateCnlTpCn(sLV.chIDCNL,sLV.pOriginTpCn,pvStateTpCnDsc);
				sLV.chRetCode |= (1<<5);//Start Sesion
			
			}
			else
			{
				;//Terminate Transport
				((LDCIDsc*)pv)->uchConMode     = 0;
				sLV.chRetCode |= (1<<7);
			}
			
		}	
	}
	else
	{ 
		i = sLV.ushCapicity - sLV.AuxSesFldWeight;
		i -= (SIZE_ID_COM_SES + SIZE_NUM_COM_SES ); //+ SIZE_TR_C
		if (i> 4)//-Minimal Size LDC((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj
		{
			if (i >(((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchSizeCTpuBuf)) 
			{
				i = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->uchSizeCTpuBuf);
				i -= sLV.AuxSesFldWeight + (SIZE_ID_COM_SES + SIZE_NUM_COM_SES );
			}	
			unnV1.ushAr [0] = i;//
			i = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj);
			j = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount);
			if( j <i)
			{
				//sLV.AuxSesFldWeight = SIZE_WLDC_FLD  +  SIZE_ID_COM_SES  + SIZE_NUM_COM_SES;
				//i = unnV1.ushAr [0];//Actual Capicity
				unnV1.ushAr [1]  = i- j;
				if (unnV1.ushAr [1]<unnV1.ushAr [0])
				{
					sLV.ushTrCount = unnV1.ushAr [1];//Last Transmision
					//((LDCIDsc*)pv)->uchConMode     = 1;//
					sLV.chFld1 = 1;//end of Session
				}
				else
				{
					sLV.ushTrCount = unnV1.ushAr [0];//Order Transmision
					//sLV.ushTrCount += unnV1.ushAr [0];
					sLV.chFld1 = 0;
				}
				pv = (void*)&hldLDCI;
				((LDCIDsc*)pv)->uchConMode     =  1;//
				((LDCIDsc*)pv)->uchStartSesion = 0;
				((LDCIDsc*)pv)->uchTR_C        = sLV.ushTrCount;//unnV1.ushAr [0];//Size curr portion
				((LDCIDsc*)pv)->NumComSes      = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->NumComSes;
				((LDCIDsc*)pv)->IdConObj       = ((TRBaseCTpuUnitDsc*)pvCTpuTR)->IdConObj;
				((LDCIDsc*)pv)->pSrc           = (char*)(
				(((TRBaseCTpuUnitDsc*)pvCTpuTR)->pUchTR ) + j);
				
				//...sLV.IdxLpuBuf = (((StateTpCnDsc*)pvStateTpCnDsc)-> PayloadLPDU_CNL_1)
				//...- (((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1);
				sLV.IdxLpuBuf = (((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> shPayloadLPDU);
				
				
				//...((LDCIDsc*)pv)->pDst           = (char*)((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_1
				//...+ sLV.IdxLpuBuf;
				((LDCIDsc*)pv)->pDst           = (char*)((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL
				+ sLV.IdxLpuBuf;
				sLV.ushSizeLDC  =  AsemblyLDC(&hldLDCI);
				
				j = (((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount);
				((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount = sLV.ushTrCount + j;
				//(((TRBaseCTpuUnitDsc*)pvCTpuTR)->ulTrCount) == (((TRBaseCTpuUnitDsc*)pvCTpuTR)->SizeAppObj)
				if ( sLV.chFld1 == 1)//sLV.chFld4||
				{
					((TRBaseCTpuUnitDsc*)pvCTpuTR)->ConState  = 0;//;//close session
					sLV.chRetCode |= (1<<6);//Terminate Session Curr Obj Activate timeOut prepea transmit
					sLV.chFld2 = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->uchTpState_CNL;
					j = 0x7f&sLV.chFld2; j++;sLV.chFld2 &=0x80;
					((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->uchTpState_CNL = j|(sLV.chFld2);
					//Activate Timer
				}
				else ((TRBaseCTpuUnitDsc*)pvCTpuTR)->ConState  = 1;//
				
				sLV.chFld2 = ((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL;
				j = 0x7f&sLV.chFld2; j++;sLV.chFld2 &=0x80;
				((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL = j|sLV.chFld2;
				j = ((LDCIDsc*)pv)->uchTR_C;j = sLV.ushSizeLDC;// + sLV.AuxSesFldWeight;
				
				((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL -= j+(SIZE_WLDC_FLD);
				(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> shPayloadLPDU) += j+(SIZE_WLDC_FLD);
				(((StateCnlTRTpCnDsc*)pvStateTpCnDsc)-> chTotalLDC_CNL) += 1;
				unnV1.ulVal = SetStateCnlTpCn(sLV.chIDCNL,sLV.pOriginTpCn,pvStateTpCnDsc);
				sLV.chRetCode |= (1<<5);//Continiue Sesion
			}
			else
			{
				sLV.chRetCode |= (1<<6);;//Terminate Session Curr Obj
			}
			
			
		}
		else
		{
			sLV.chRetCode |= (1<<7);;//Terminate Transport
		}
		
	
	
	}
	
//Prepea transmision data


//Put 	transmision data
//AsemblyLDC:

	if( (((StateCnlTRTpCnDsc*)pvStateTpCnDsc)->lCapicity_CNL) < 4)
	{
		sLV.chRetCode |= (1<<7);
		j =  GetFld_TpState_CNL(sLV.chIDCNL);
		SetFld_TpState_CNL(sLV.chIDCNL,sLV.pOriginTpCn,j|(1<<7));
	}	

	
	return sLV.chRetCode ;
	
//((EmrEventDsc*)p_out_param)->EvtField	
}
#define SIZE_WLDC_FLD     1
#define SIZE_ID_COM_SES   2
#define SIZE_NUM_COM_SES  1
#define SIZE_TR_C         1


#define HDR_IDX_SIZE_LDC        0
#define HDR_IDX_ID_COM_SES      HDR_IDX_SIZE_LDC    + SIZE_WLDC_FLD
#define HDR_IDX_NUM_COM_SES     HDR_IDX_ID_COM_SES  + SIZE_ID_COM_SES
#define HDR_IDX_TR_C            HDR_IDX_NUM_COM_SES + SIZE_NUM_COM_SES

int AsemblyLDC(void *pvLDCInfo)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
struct 
	{
		unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		//unsigned char uChIdxBit ;
		//short shErr;
		unsigned short ushSizeLDC;
		
	    //.unsigned char *pUchTR;//
		
		
	} sLV;
union 
    {
    	unsigned char   uchAr [4];
    	unsigned short  ushAr [2];
        unsigned long   ulVal;
    }unnV1;
	
	sLV.ushSizeLDC = 0;
	sLV.uChIdxByte = SIZE_WLDC_FLD;//Pointer In LDC Buf
	pSrc = (char*) ((LDCIDsc*)pvLDCInfo)->pSrc;
	pDst = (char*) ((LDCIDsc*)pvLDCInfo)->pDst;
	i = ((LDCIDsc*)pvLDCInfo)->IdConObj; 
	if( ((LDCIDsc*)pvLDCInfo)->uchConMode == 0)
	{
		unnV1.ushAr [0] = (unsigned short)i<<1;
		pDst[HDR_IDX_ID_COM_SES]	 = unnV1.uchAr[0];
		pDst[(HDR_IDX_ID_COM_SES)+1] = unnV1.uchAr[1];
		sLV.uChIdxByte += SIZE_ID_COM_SES;
		sLV.ushSizeLDC += SIZE_ID_COM_SES;
	
	}
	else
	{
		unnV1.ushAr [0] = (unsigned short) (i<<1)|1;
		pDst[HDR_IDX_ID_COM_SES]	 = unnV1.uchAr[0];
		pDst[(HDR_IDX_ID_COM_SES)+1] = unnV1.uchAr[1];
 
		sLV.uChIdxByte += SIZE_ID_COM_SES;
		sLV.ushSizeLDC += SIZE_ID_COM_SES;
		i = ((LDCIDsc*)pvLDCInfo)-> NumComSes;
		i <<= 4;
		if (((LDCIDsc*)pvLDCInfo)->uchStartSesion )
		{
			pDst[HDR_IDX_NUM_COM_SES] = i | (1<<START_SES_FLD_ONB);
		}
		else
		{
			pDst[HDR_IDX_NUM_COM_SES] = i;
		}
		sLV.uChIdxByte += SIZE_NUM_COM_SES;
		sLV.ushSizeLDC += SIZE_NUM_COM_SES;
		//((LDCIDsc*)pvLDCInfo)-> 
	}
	sLV.uchTR_C = ((LDCIDsc*)pvLDCInfo)-> uchTR_C;//size
	j = sLV.uChIdxByte;
	for (i = 0;i< (sLV.uchTR_C);i++)
	{
		pDst[i+j] = pSrc[i];
	}   
	
	sLV.ushSizeLDC += sLV.uchTR_C;
	pDst[HDR_IDX_SIZE_LDC] = (char)sLV.ushSizeLDC;//Put Size LDC
	
return (int)sLV.ushSizeLDC;
}
int ScanCn1(void *pLpuCn1 )  @ "Fast_function"
{
register long i,j;
register void *pv;
union 
{
	unsigned char   uchAr [4];
	unsigned short  ushAr [2];
    unsigned long   ulVal;
}unnV1;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char AuxSesFldWeight,chRetCode;
		char IdxLpuBuf,chTotalLDC;
		//unsigned short ConState;
		unsigned short ushSzCurrLDC;//ushRvCount;
		//unsigned short ushCapicity;
		unsigned short ushSizeLDC;
	    unsigned char *pUchRV;//
		void  *pOriginLpu;//, *pOriginTpCn;
		
	} sLV;
LDCIDsc hldLDCI;
	//
	sLV.pOriginLpu  = pLpuCn1;
	sLV.chTotalLDC  = 0;
	sLV.ushSizeLDC  =  ((RVStateLpuCn1Dsc*)pLpuCn1)->ushSizeLDC;
	//Find Idx
	i = ((RVStateLpuCn1Dsc*)pLpuCn1)->uchCI;
	switch (i )
	{
		case 0:
			sLV.IdxLpuBuf = 1;
		break;
		case 1:
			sLV.IdxLpuBuf = 2;
		break;
		case 2://
			sLV.IdxLpuBuf = 3;
		break;
	 default:
		sLV.IdxLpuBuf = 2;
	}
	j = sLV.IdxLpuBuf;//Skip Aux Data In Buf
	sLV.pUchRV = &(((RVStateLpuCn1Dsc*)pLpuCn1)->arUch[j]);//! Be Carefull!!!/
	pLpuCn1 = (void*)&hldLDCI;
	while (sLV.ushSizeLDC)
	{
		;//Get Size curr LDC
		j = sLV.IdxLpuBuf;
		pv = (void*)(sLV.pUchRV+j);
		unnV1.uchAr[0] = *((char*)pv);
		((LDCIDsc*)pLpuCn1)-> uchTR_C = unnV1.uchAr[0];
		sLV.ushSzCurrLDC = unnV1.uchAr[0];//
		
		j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf;
		pv = (void*)(sLV.pUchRV + j);
		unnV1.uchAr[2] = (unsigned char) *((char*)pv);
		unnV1.uchAr[3] = (unsigned char) *((char*)pv+1);
		i = unnV1.ushAr[1];
		((LDCIDsc*)pLpuCn1)->uchConMode = i&1;
		((LDCIDsc*)pLpuCn1)->IdConObj   = i>>1;
		if( ((LDCIDsc*)pLpuCn1)->uchConMode == 0)
		{
			((LDCIDsc*)pLpuCn1)-> uchTR_C = sLV.ushSzCurrLDC - ((SIZE_ID_COM_SES));
			j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf+(SIZE_ID_COM_SES);
			((LDCIDsc*)pLpuCn1)->pSrc = (char*)(sLV.pUchRV + j);
			((LDCIDsc*)pLpuCn1)->pDst = (char*)0;
			ExtractLdc((void*)&hldLDCI);
			
		}
		else
		{
			j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf+(SIZE_ID_COM_SES);
			pv = (void*)(sLV.pUchRV+j);
			unnV1.uchAr[0] = *((char*)pv);
			i = unnV1.uchAr[0];
			((LDCIDsc*)pLpuCn1)-> NumComSes = i;
				if ( i & (1<<START_SES_FLD_ONB))
			{
				((LDCIDsc*)pLpuCn1)-> uchStartSesion = i & (1<<START_SES_FLD_ONB);
			}
			else
			((LDCIDsc*)pLpuCn1)-> uchStartSesion = 0;

			//((LDCIDsc*)pLpuCn1)-> uchTR_C = sLV.ushSzCurrLDC - ((SIZE_ID_COM_SES));
			//j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf+(SIZE_ID_COM_SES);
			//((LDCIDsc*)pLpuCn1)->pSrc = (char*)(sLV.pUchRV + j)
			//((LDCIDsc*)pLpuCn1)->pDst = (char*)0;
			ExtractLdc((void*)&hldLDCI);
		
		}	

	}
	
return 0;
}
long GetRVStateLpuCnl(long lID_Cnl,void* pvHolderRVStateLpuCnl, void* pvRVStateLpuCnl)  @ "Fast_function"
{
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		//.((StateCnlTRTpCnDsc*)pvTpCn)->uchTpState_CNL = 
		//.((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1;
		//.
		//.((StateCnlTRTpCnDsc*)pvTpCn)->shPayloadLPDU  = 
		//.(((StateTpCnDsc*)pvStateTpCnDsc)->PayloadLPDU_CNL_1);
		//.((StateCnlTRTpCnDsc*)pvTpCn)->lCapicity_CNL  = 
		//.((StateTpCnDsc*)pvStateTpCnDsc)-> lCapicity_CNL_1;
		//.((StateCnlTRTpCnDsc*)pvTpCn)->pUchLpuTR_CNL  = 
		//.(((StateTpCnDsc*)pvStateTpCnDsc)-> pUchLpuTR_CNL_1);		
		
		break;
	case ID_CNL_HSU7:
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCapicity = 
		((RVStateLpuHSU7Dsc*)pvHolderRVStateLpuCnl)-> lCapicity;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->pUch = &
		(((RVStateLpuHSU7Dsc*)pvHolderRVStateLpuCnl)->  arUch[0]);
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchLpuCn1State = 
		((RVStateLpuHSU7Dsc*)pvHolderRVStateLpuCnl)-> uchLpuHSU7State;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchCI = 
		((RVStateLpuHSU7Dsc*)pvHolderRVStateLpuCnl)-> uchCI;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->ushSizeLDC = 
		((RVStateLpuHSU7Dsc*)pvHolderRVStateLpuCnl)-> ushSizeLDC;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCs = 
		((RVStateLpuHSU7Dsc*)pvHolderRVStateLpuCnl)-> lCs;
		
		break;
 	case ID_CNL_HSU2:
 		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCapicity = 
		((RVStateLpuHSU2Dsc*)pvHolderRVStateLpuCnl)-> lCapicity;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->pUch = &
		(((RVStateLpuHSU2Dsc*)pvHolderRVStateLpuCnl)->  arUch[0]);
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchLpuCn1State = 
		((RVStateLpuHSU2Dsc*)pvHolderRVStateLpuCnl)-> uchLpuHSU2State;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchCI = 
		((RVStateLpuHSU2Dsc*)pvHolderRVStateLpuCnl)-> uchCI;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->ushSizeLDC = 
		((RVStateLpuHSU2Dsc*)pvHolderRVStateLpuCnl)-> ushSizeLDC;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCs = 
		((RVStateLpuHSU2Dsc*)pvHolderRVStateLpuCnl)-> lCs;
 		break;
     case ID_CNL_U2:
 		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCapicity = 
		((RVStateLpuU2Dsc*)pvHolderRVStateLpuCnl)-> lCapicity;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->pUch = &
		(((RVStateLpuU2Dsc*)pvHolderRVStateLpuCnl)->  arUch[0]);
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchLpuCn1State = 
		((RVStateLpuU2Dsc*)pvHolderRVStateLpuCnl)-> uchLpuU2State;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchCI = 
		((RVStateLpuU2Dsc*)pvHolderRVStateLpuCnl)-> uchCI;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->ushSizeLDC = 
		((RVStateLpuU2Dsc*)pvHolderRVStateLpuCnl)-> ushSizeLDC;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCs = 
		((RVStateLpuU2Dsc*)pvHolderRVStateLpuCnl)-> lCs;
 		break;
     case ID_CNL_U0:
 		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCapicity = 
		((RVStateLpuU0Dsc*)pvHolderRVStateLpuCnl)-> lCapicity;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->pUch = &
		(((RVStateLpuU0Dsc*)pvHolderRVStateLpuCnl)->  arUch[0]);
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchLpuCn1State = 
		((RVStateLpuU0Dsc*)pvHolderRVStateLpuCnl)-> uchLpuU0State;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchCI = 
		((RVStateLpuU0Dsc*)pvHolderRVStateLpuCnl)-> uchCI;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->ushSizeLDC = 
		((RVStateLpuU0Dsc*)pvHolderRVStateLpuCnl)-> ushSizeLDC;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCs = 
		((RVStateLpuU0Dsc*)pvHolderRVStateLpuCnl)-> lCs;
 		break;
     case ID_CNL_DBGU:
 		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCapicity = 
		((RVStateLpuDbguDsc*)pvHolderRVStateLpuCnl)-> lCapicity;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->pUch = &
		(((RVStateLpuDbguDsc*)pvHolderRVStateLpuCnl)->  arUch[0]);
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchLpuCn1State = 
		((RVStateLpuDbguDsc*)pvHolderRVStateLpuCnl)->uchLpuDbguState;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchCI = 
		((RVStateLpuDbguDsc*)pvHolderRVStateLpuCnl)-> uchCI;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->ushSizeLDC = 
		((RVStateLpuDbguDsc*)pvHolderRVStateLpuCnl)-> ushSizeLDC;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCs = 
		((RVStateLpuDbguDsc*)pvHolderRVStateLpuCnl)-> lCs;
 		break;
	case ID_CNL_SPI:
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCapicity = 
		((RVStateLpuSpiDsc*)pvHolderRVStateLpuCnl)-> lCapicity;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->pUch = &
		(((RVStateLpuSpiDsc*)pvHolderRVStateLpuCnl)->  arUch[0]);
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchLpuCn1State = 
		((RVStateLpuSpiDsc*)pvHolderRVStateLpuCnl)-> uchLpuSpiState;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->uchCI = 
		((RVStateLpuSpiDsc*)pvHolderRVStateLpuCnl)-> uchCI;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->ushSizeLDC = 
		((RVStateLpuSpiDsc*)pvHolderRVStateLpuCnl)-> ushSizeLDC;
		
		((RVStateLpuCnlDsc*)pvRVStateLpuCnl)->lCs = 
		((RVStateLpuSpiDsc*)pvHolderRVStateLpuCnl)-> lCs;
	
		break;
//.	case 6:
//.	
//.		break;
	default:
	lID_Cnl =0;
	}	

return lID_Cnl;
}
void* GetLpduAddr(long ID_Cnl)  @ "Fast_function"
{
struct 
	{
		void  *pLpu;
	} sLV;
switch (ID_Cnl )
	{
		case ID_CNL_HSU7:
			sLV.pLpu = (void*)&hldrHSU7LpduUnit;
		break;
		case ID_CNL_TEST1:
			sLV.pLpu = (void*)&hldrCn1LpduUnit;
		break;
		case ID_CNL_HSU2://
			sLV.pLpu = (void*)&hldrHSU2LpduUnit;
		break;
		case ID_CNL_U2://
			sLV.pLpu = (void*)&hldrU2LpduRvUnit;
		break;
		case ID_CNL_U0://
			sLV.pLpu = (void*)&hldrU0LpduRvUnit;
		break;
		case ID_CNL_DBGU://
			sLV.pLpu = (void*)&hldrDBGULpduRvUnit;
		break;
		case ID_CNL_SPI://
			sLV.pLpu = (void*)&hldrSpiLpduUnit;
		break;
		
	 default:
		sLV.pLpu = (void*)0;
	}	
return sLV.pLpu;
} 
int ScanCnl(long lIDr)  @ "Fastest_function" //void *pLpuCnl ) 
{
register long i,j;
register void *pv;
register void *pLpuCnl;
union 
{
	unsigned char   uchAr [4];
	unsigned short  ushAr [2];
    unsigned long   ulVal;
}unnV1;
struct 
	{

		//char chFld1,chFld2,chFld3,chFld4;
		char AuxSesFldWeight,chRetCode;
		char chTotalLDC;
		char chIDCNL;
		//unsigned short ConState;
		unsigned short  IdxLpuBuf,ushSzCurrLDC;//ushRvCount;
		//unsigned short ushCapicity;
		unsigned short ushSizeLDC;
	    unsigned char *pUchRV;//
		void  *pOriginLpu;//, *pOriginTpCn;
		
	} sLV;
LDCIDsc hldLDCI;
RVStateLpuCnlDsc hldRVStateLpuCnlDsc;	
unnV1.uchAr[0] = 0x0;
	sLV.chIDCNL = lIDr;
	//Detect Id + addr
	pLpuCnl = GetLpduAddr( lIDr);
	sLV.pOriginLpu  = pLpuCnl;
	//(long lID_Cnl,void* pvHolderRVStateLpuCnl, void* pvRVStateLpuCnl)
	//``````````````````````````````````````````````
	//-- Insert Error after return from func end exit from func whith Error
	GetRVStateLpuCnl( lIDr,pLpuCnl,(void*)&hldRVStateLpuCnlDsc);
	//j = GetRVStateLpuCnl();
	//if j==0
	//sLV.chRetCode = -x; Erroneus retCode
	//goto ExitFromScanCnl; 
	//............................................................
	pLpuCnl = (void*)&hldRVStateLpuCnlDsc;
	sLV.chTotalLDC  = 0;
	
		
	//sLV.ushSizeLDC  = ((RVStateLpuCnlDsc*)pLpuCnl)->pUch[1];//ushSizeLDC;
	//Find Idx
	i = ((RVStateLpuCnlDsc*)pLpuCnl)->pUch[0];//uchCI;
	i &= 0xf;i>>=1;
	switch (i )
	{
		case 0:
			sLV.IdxLpuBuf = 1;
		break;
		case 1:
			sLV.IdxLpuBuf = 2;
		break;
		case 2://
			sLV.IdxLpuBuf = 3;
		break;
	 default:
		sLV.IdxLpuBuf = 2;
	}
	j = sLV.IdxLpuBuf;//Skip Aux Data In Buf
	// &(((RVStateLpuCn1Dsc*)pLpuCnl)->arUch[j]);//! Be Carefull!!!/
	sLV.ushSizeLDC  = ((RVStateLpuCnlDsc*)pLpuCnl)->pUch[j];//Count LDC
		if( (sLV.ushSizeLDC>0) && (sLV.ushSizeLDC<10))
	{
	
	}
	else
	return 0xfe;
	sLV.pUchRV = ((RVStateLpuCnlDsc*)pLpuCnl)->pUch;
	j++;
	sLV.IdxLpuBuf = j;
	pLpuCnl = (void*)&hldLDCI;
	while (sLV.ushSizeLDC--)
	{
		;//Get Size curr LDC
		j = sLV.IdxLpuBuf;
		pv = (void*)(sLV.pUchRV+j);
		unnV1.uchAr[0] = *((char*)pv);
		((LDCIDsc*)pLpuCnl)-> uchTR_C = unnV1.uchAr[0];
		sLV.ushSzCurrLDC = unnV1.uchAr[0];//
		
		j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf;
		pv = (void*)(sLV.pUchRV + j);
		unnV1.uchAr[2] = (unsigned char) *((char*)pv);
		unnV1.uchAr[3] = (unsigned char) *((char*)pv+1);
		i = unnV1.ushAr[1];
		((LDCIDsc*)pLpuCnl)->uchConMode = i&1;
		((LDCIDsc*)pLpuCnl)->IdConObj   = i>>1;
		if( ((LDCIDsc*)pLpuCnl)->uchConMode == 0)
		{
			((LDCIDsc*)pLpuCnl)-> uchTR_C = sLV.ushSzCurrLDC - ((SIZE_ID_COM_SES));
			j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf+(SIZE_ID_COM_SES);
			((LDCIDsc*)pLpuCnl)->pSrc = (char*)(sLV.pUchRV + j);
			((LDCIDsc*)pLpuCnl)->pDst = (char*)0;
			ExtractLdc((void*)&hldLDCI);
			sLV.IdxLpuBuf += sLV.ushSzCurrLDC+(SIZE_WLDC_FLD);
			//sLV.chRetCode = -x; Erroneus retCode
			//goto ExitFromScanCnl; 
		}
		else
		{
			j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf+(SIZE_ID_COM_SES);
			pv = (void*)(sLV.pUchRV+j);
			unnV1.uchAr[0] = *((char*)pv);
			i = unnV1.uchAr[0];
			((LDCIDsc*)pLpuCnl)-> NumComSes = i;
			if ( i & (1<<START_SES_FLD_ONB))
			{
				((LDCIDsc*)pLpuCnl)-> uchStartSesion = i & (1<<START_SES_FLD_ONB);
			}
			else
			((LDCIDsc*)pLpuCnl)-> uchStartSesion = 0;
			((LDCIDsc*)pLpuCnl)-> uchTR_C = sLV.ushSzCurrLDC - ((SIZE_NUM_COM_SES)+(SIZE_ID_COM_SES));
			j = (SIZE_WLDC_FLD) + sLV.IdxLpuBuf+(SIZE_ID_COM_SES)+(SIZE_NUM_COM_SES);
			((LDCIDsc*)pLpuCnl)->pSrc = (char*)(sLV.pUchRV + j);
			((LDCIDsc*)pLpuCnl)->pDst = (char*)0;
			ExtractLdc((void*)&hldLDCI);
			sLV.IdxLpuBuf += sLV.ushSzCurrLDC+(SIZE_WLDC_FLD);
			//if j==0
			//sLV.chRetCode = -x; Erroneus retCode
		    //goto ExitFromScanCnl; 
		}	

	}
	//Extract URGENT_DATA
	ExtractUrgentData(lIDr,(void*)(sLV.pUchRV+sLV.IdxLpuBuf));
	unnV1.uchAr[0] = sLV.ushSizeLDC;
	
	
return unnV1.uchAr[0];
}

void* GetAddrObj(long IdObj);
void ExtractLdc(void *pLDC)  @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;

struct 
	{
		unsigned char  uchConMode;
		unsigned char uchRV_C;
		unsigned char uChIdxByte ;
		//unsigned char uChIdxBit ;
		//short shErr;
		unsigned short ushSizeLDC;
		unsigned short IdConObj;
		void *pOriginLDC;
		PFL_VL pfl_vl;
	} sLV;
//    union 
//	    {
//	    	unsigned char   uchAr [4];
//	    	unsigned short  ushAr [2];
//            unsigned long   ulVal;
//	    }unnV1;	
sLV.uchConMode  = ((LDCIDsc*)pLDC)->uchConMode;
sLV.IdConObj    = ((LDCIDsc*)pLDC)->IdConObj;
sLV.pOriginLDC  = pLDC;
/*		
pSrc = (char*)pLDC;
sLV.ushSizeLDC   = (unsigned short)pSrc[HDR_IDX_SIZE_LDC];
unnV1.uchAr [0] = pSrc[HDR_IDX_ID_COM_SES];
unnV1.uchAr [1] = pSrc[HDR_IDX_ID_COM_SES+1];
i = unnV1.ushAr [0];
sLV.uchConMode = i&1;
sLV.IdConObj    = (unsigned short )(i>>1);
*/
if(sLV.uchConMode )
	{
		
		//sLV.uChIdxByte += SIZE_ID_COM_SES;
		//sLV.ushSizeLDC += SIZE_ID_COM_SES;
	
	}
	else
	{
		//sLV.uChIdxByte += SIZE_ID_COM_SES;
		//sLV.ushSizeLDC += SIZE_ID_COM_SES;
		sLV.uchRV_C =  ((LDCIDsc*)pLDC)-> uchTR_C;//size
		//pSrc = (char*) ((LDCIDsc*)pLDC)->pSrc;
		//pLDC = GetAddrObj();
		
	}
		sLV.pfl_vl = (PFL_VL) GetAddrPFL_VL(sLV.IdConObj);
	if(sLV.pfl_vl)
	i = sLV.pfl_vl(pLDC,sLV.IdConObj);
	else 
	{
		return;//Hundle Error Now
	}
}

void TerminateServiceTrApCn(void* pvD,long IdObj)
{
//-long i,j;
//
TestReqTransmitT1 = 0;

}

extern void ExtractUrgentDataBr2Bs(void* pv);

void ExtractUrgentData(long lID_Cnl,void* pvD)    @ "Fast_function"
{
switch (lID_Cnl )
	{
		// case ID_CNL_HSU7:
		// 	sLV.pLpu = (void*)&hldrHSU7LpduUnit;
		// break;
		// case ID_CNL_TEST1:
		// 	sLV.pLpu = (void*)&hldrCn1LpduUnit;
		// break;
		// case ID_CNL_HSU2://
		// 	sLV.pLpu = (void*)&hldrHSU2LpduUnit;
		// break;
		// case ID_CNL_U2://
		// 	sLV.pLpu = (void*)&hldrU2LpduRvUnit;
		// break;
		// case ID_CNL_U0://
		// 	sLV.pLpu = (void*)&hldrU0LpduRvUnit;
		// break;
		// case ID_CNL_DBGU://
		// 	sLV.pLpu = (void*)&hldrDBGULpduRvUnit;
		// break;
		case ID_CNL_SPI://
			ExtractUrgentDataBr2Bs(pvD);
		break;
		
	 default:
		;
	}


}



#include    "tpuRT.c"

