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
* File Name       : tpuRT.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  03/10/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/


void* GetAddrObj(long IdObj)
{
register void* pv;

pv = (void*)0;

switch (IdObj)
	{
	case ID_SRC_SAMPLES_UNIT:
		pv  = &holderRVSrcSamplesCTpuUnit;
		break;
	case ID_SRC_APCS_UNIT:
		
		pv  = (void*)0;
		
		break;
	case ID_SRC_TEST1_UNIT:
	    
		pv  = (void*)0;
		
	break;
	case ID_TEN_PERIOD_SAMPLES_UNIT:
	
	pv  = (void*)&holderRV10PeriodCTpuUnit;
	
	break;
	
	default:
	pv = (void*)0;
	}



	return pv;
}

long UpdateRVSrcSamplesCTpuUnit(void* pvLDC, long lID)
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
//struct 
//	{
//		void *pOriginLDC;
//	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

//sLV.pOriginLDC = pvLDC;
//


unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;

pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
//((RVSrcSamplesCTpuUnitDsc*)pv )->
i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
 lID = ((LDCIDsc*)pvLDC)->uchTR_C;
 pvLDC = (void*)i;
  
 
  for (i = 0; i < lID; i++)
  {
    ((char*)pv)[i] = ((char*)pvLDC)[i];
  }
  unnV1.uchAr[3] = lID;//Save amount Extract Data
  //Activate App For
  TestReqReceiveT1++;
  //Clear All Ses Data
  i = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.uchUsedTransport = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.NumComSes        = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.ConState         = 0;
  holderRVSrcSamplesCTpuUnit.RvCnHldr.ulRvCount        = 0;
  //Indicator data Transmit to Application
  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//unnV1.uchAr[3];
}


#define SIZE_TPDU_10PER_CNL_HSU2_MDR1_ 30
long UpdateRVProxyTenPerSamplesCTpuUnit(void* pvLDC, long lID) @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
//		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

//sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
//
if (unnV1.uchAr[0]== 0)
{
	pv  = (void*)&holderRV10PeriodCTpuUnit.arUchRV;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//  unnV1.uchAr[3] = lID;//Save amount Extract Data
	
	//Activate App For
	TestReqReceiveTenPerSamples++;
	TestReqReceiveArTenPerSamples++; //<-On this var possible count real amt tpu frames ??
	//Use it as information only
	//Clear All Ses Data
	
	holderRV10PeriodCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	holderRV10PeriodCTpuUnit.RvCnHldr.NumComSes        = 0;
	holderRV10PeriodCTpuUnit.RvCnHldr.ConState         = 0;
	holderRV10PeriodCTpuUnit.RvCnHldr.ulRvCount        = lID;
	
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRV10PeriodCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&holderRV10PeriodCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	
		if ( i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			//;
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_TPDU_10PER_CNL_HSU2_MDR1_))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_TPDU_10PER_CNL_HSU2_MDR1_) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
		
			pvLDC = (void*)i;
			i = (long)&holderRV10PeriodCTpuUnit.arUchRV;
		
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRV10PeriodCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_TPDU_10PER_CNL_HSU2_MDR1_))
			{
				// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				// i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
					if (lID == (long)(SIZE_TPDU_10PER_CNL_HSU2_MDR1_))
					{
						//Activate App Func
						TestReqReceiveTenPerSamples++;TestReqReceiveArTenPerSamples++;
						//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
						//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					}
					else{
							//pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
							//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
							//((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
							//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
							//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
							sLV.chNeedClrSesData++;
					}
					
				
				
				
			}
//			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
//			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
//			pvLDC = (void*)i;
//			i = (long)&holderRV10PeriodCTpuUnit.arUchRV;
//			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
//			pv  = (void*)i;
//			for (i = 0; i < lID; i++)
//			{
//			((char*)pv)[i] = ((char*)pvLDC)[i];
//			}
			
			
		}
		else
		{
					;//Error Sesion
		// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				
		 sLV.chNeedClrSesData++;
			
		}
	if(sLV.chNeedClrSesData)
	{

		;//Error Sesion
			pv  = (void*)&holderRV10PeriodCTpuUnit.RvCnHldr;
		
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
	}

	if(TestReqReceiveTenPerSamples)	
	{
		i = holderProxyTenPerSamplesUnit.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
		{
			pv  = (void*)& holderProxyTenPerSamplesUnit;
			i = ((ProxyTenPerSamplesUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
			if(i< 0xff)
			((ProxyTenPerSamplesUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] |= 0x100;
		}
		else
		{
			TestReqReceiveTenPerSamples = 0;
		
		}
	}	
}


//((RV10PeriodCTpuUnitDsc*)pv )->

  

  //Indicator data Transmit to Application
  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//unnV1.uchAr[3];
}


#define SIZE_TPDU_TOT_MEAS_CNL_HSU2_ 30
long UpdateRVProxyTotMeasCTpuUnit(void* pvLDC, long lID) @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
//		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

//sLV.pOriginLDC = pvLDC;
 sLV.chNeedClrSesData = 0;

unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
//
if (unnV1.uchAr[0]== 0)
{
	pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//  unnV1.uchAr[3] = lID;//Save amount Extract Data
	
	//Activate App For
	//TestReqReceiveTenPerSamples++;TestReqReceiveArTenPerSamples++; //?????
	TestReqReceiveTotMeas++;
	//Clear All Ses Data
	
	holderRVTotMeasCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	holderRVTotMeasCTpuUnit.RvCnHldr.NumComSes        = 0;
	holderRVTotMeasCTpuUnit.RvCnHldr.ConState         = 0;
	holderRVTotMeasCTpuUnit.RvCnHldr.ulRvCount        = lID;
	
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVTotMeasCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&holderRVTotMeasCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	
	if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes))
	{
		//;
		i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
		if( i<= (long)(SIZE_TPDU_TOT_MEAS_CNL_HSU2_))
		lID = ((LDCIDsc*)pvLDC)->uchTR_C;
		else
		lID = (SIZE_TPDU_TOT_MEAS_CNL_HSU2_) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
		unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
		i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
		
		pvLDC = (void*)i;
		i = (long)&holderRVTotMeasCTpuUnit.arUchRV;
		//i = (long)holderRVTotMeasGSOCTpuUnit.RvCnHldr.pUchRV; ???
		i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		pv  = (void*)i;
		for (i = 0; i < lID; i++)
		{
		((char*)pv)[i] = ((char*)pvLDC)[i];
		}
		//Update Rv
		pv  = (void*)&holderRVTotMeasCTpuUnit.RvCnHldr;
		lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
		if (lID >= (long)(SIZE_TPDU_TOT_MEAS_CNL_HSU2_))
		{
			// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			// i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			//Sucess Terminate Session
				if (lID == (long)(SIZE_TPDU_TOT_MEAS_CNL_HSU2_))
				{
					//Activate App Func
					TestReqReceiveTotMeas++;
					//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
						//((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
						//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						sLV.chNeedClrSesData++;
				}
				 
			
			
			
		}
//		i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
//		lID = ((LDCIDsc*)pvLDC)->uchTR_C;
//		pvLDC = (void*)i;
//		i = (long)&holderRVTotMeasCTpuUnit.arUchRV;
//		i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
//		pv  = (void*)i;
//		for (i = 0; i < lID; i++)
//		{
//		((char*)pv)[i] = ((char*)pvLDC)[i];
//		}
		
		
	}
	else
	{
		;//Error Sesion
		// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				
		 sLV.chNeedClrSesData++;
	}
	if(sLV.chNeedClrSesData)
	{

		
		pv  = (void*)&holderRVTotMeasCTpuUnit.RvCnHldr;
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
	}
}


//((RV10PeriodCTpuUnitDsc*)pv )->

  

  //Indicator data Transmit to Application
  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//unnV1.uchAr[3];
}
extern long PassSettingsPrMngRvMsg(void* pvLDC, long lID);
extern long UpdateRVPrTptStng(void* pvLDC, long lID);
extern long UpdateRVPrTptYust(void* pvLDC, long lID);
extern long PassYustPrMngRvMsg(void* pvLDC, long lID);
extern long UpdateRVTotMeasGCTpuUnit(void* pvLDC, long lID);
extern long UpdateRVRawSamplCTpuUnit(void* pvLDC, long lID);
extern long UpdateRVApcsCTpuUnit(void* pvLDC, long lID);
extern long UpdateRVGoosACTpuUnit(void* pvLDC, long lID);
extern long UpdateRVGoosBCTpuUnit(void* pvLDC, long lID);
extern long UpdateRVPrTptPrtTbl(void* pvLDC, long lID);
extern long PassPrtTblPrMngRvMsg(void* pvLDC, long lID);
extern long UpdateRVTotTeleMechsTpuUnit(void* pvLDC, long lID);

extern long UpdateRVDiagnBmBsTpuUnit(void* pvLDC, long lID);
extern long UpdateRVDiagnBrBsTpuUnit(void* pvLDC, long lID);
extern long UpdateRVTotVerInfoBmTpuUnit(void* pvLDC, long lID);
extern long UpdateRVTotVerInfoBrTpuUnit(void* pvLDC, long lID);
extern long UpdateRVARecDataBsTpuUnit(void* pvLDC, long lID);
extern long UpdateRVARecMainDataBsTpuUnit(void* pvLDC, long lID);
extern long UpdateRvAtrCmd(void* pvLDC, long lID);

short shIdxRvLpduUnit = 0;
extern RVStateLpuU2Dsc  hldrU2LpduRvUnit;
extern RVStateLpuU2Dsc  arrHSU2LpduRVUnit[200];


void* GetAddrPFL_VL(long IdObj) @ "Fast_function"
{
//register void* pv;
register PFL_VL pfl_vl;
//pfl_vl = (void*)0;

switch (IdObj)
	{
	case ID_SRC_SAMPLES_UNIT:
		pfl_vl  = UpdateRVSrcSamplesCTpuUnit;
		break;
	case ID_SRC_APCS_UNIT:
		
		//pfl_vl  = (void*)0;
		
		break;
	case ID_SRC_TEST1_UNIT:
	    
		pfl_vl  = UpdateRVRawSamplCTpuUnit;//(void*)0;
		
		break;
	case ID_TEN_PERIOD_SAMPLES_UNIT:
	
	pfl_vl  = UpdateRVProxyTenPerSamplesCTpuUnit;//(void*)0;
	
	break;
	case ID_TOTAL_MEAS_UNIT:
	
	pfl_vl  = UpdateRVProxyTotMeasCTpuUnit;//(void*)0;
	
	break;
	case ID_TOTAL_MEASG_UNIT:
	
	pfl_vl  = UpdateRVTotMeasGCTpuUnit;//(void*)0;
	
	break;
	case ID_SETTING_PR_MNG:
	    
		pfl_vl  = PassSettingsPrMngRvMsg;//(void*)0;
		
	break;
	case ID_SETTING_PR_TRANSPORT:
	    
		pfl_vl  = UpdateRVPrTptStng;  //ActivateRVProxyTransport;//(void*)0;
		arrHSU2LpduRVUnit[shIdxRvLpduUnit++] = hldrU2LpduRvUnit;
		 if (shIdxRvLpduUnit >= 200)
		 shIdxRvLpduUnit = 0;
	break;
		case ID_YUST_PR_MNG:
	    
		pfl_vl  = PassYustPrMngRvMsg;//(void*)0;
		
		break;
	case ID_YUST_PR_TRANSPORT:
	    
		pfl_vl  = UpdateRVPrTptYust;//(void*)0;
		
		break;	
	case ID_APCS_UNIT:
	    
		pfl_vl  = UpdateRVApcsCTpuUnit;//(void*)0;
		
		break;
     case ID_PRT_PR_MNG :
	      pfl_vl  = PassPrtTblPrMngRvMsg;
     case ID_PRT_PR_TRANSPORT:
	    pfl_vl  = UpdateRVPrTptPrtTbl;
	 break;
	 case ID_GOOS_A_UNIT:
	    pfl_vl  = UpdateRVGoosACTpuUnit;
	 break;
	 case ID_GOOS_B_UNIT:
	    pfl_vl  = UpdateRVGoosBCTpuUnit;
	 break;
	case ID_TELE_MECHS_UNIT :
	    pfl_vl  = UpdateRVTotTeleMechsTpuUnit;
	 break;
	case ID_DIAGN_BM_UNIT :
	    pfl_vl  = UpdateRVDiagnBmBsTpuUnit;
	 break;
	case ID_DIAGN_BR_UNIT :
	    pfl_vl  = UpdateRVDiagnBrBsTpuUnit;
	 break;
	case ID_VER_INFO_BM_UNIT :
	    pfl_vl  = UpdateRVTotVerInfoBmTpuUnit;
	 break;
	case ID_VER_INFO_BR_UNIT :
	    pfl_vl  = UpdateRVTotVerInfoBrTpuUnit;
	 break;
	case ID_ANL_RECORD_UNIT :
	    pfl_vl  =  UpdateRVARecDataBsTpuUnit;
	 break;
	case ID_MAIN_ANL_RECORD_UNIT :
	    pfl_vl  =  UpdateRVARecMainDataBsTpuUnit;
	 break;
	case ID_ATR_CMD_UNIT:
	    pfl_vl  = UpdateRvAtrCmd;//(void*)0;UpdateRVTotAtrCmdTpuUnit
		
	break; 
	default:
	pfl_vl = (void*)0;
	}



	return (void*)pfl_vl;
}

long SetFld_TpState_CNL(long lID_Cnl,void* pvStateTpCnDsc,long lV)  @ "Fast_function"
{
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_1 =   lV;
		break;
	case ID_CNL_HSU7:
		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU7 = lV;
		break;
 	case ID_CNL_HSU2:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_HSU2 = lV;
 		break;
 	case ID_CNL_SPI:
 		((StateTpCnDsc*)pvStateTpCnDsc)-> uchTpState_CNL_Spi = lV;
 		break;
		

//.	case 6:
//.	
//.		break;
	default:
	lID_Cnl =0;
	}	
return lID_Cnl;
}
long GetFld_TpState_CNL(long lID_Cnl)  @ "Fast_function"
{
register long i;
register void *pv;
pv = (void*)&hldrTpCnState;//StateTpCnDsc
switch (lID_Cnl)
	{
	case ID_CNL_TEST1:
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_1;
		break;
	case ID_CNL_HSU7:
		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU7;
		break;
 	case ID_CNL_HSU2:
 		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_HSU2;
 		break;
 	case ID_CNL_SPI:
 		i = ((StateTpCnDsc*)pv)-> uchTpState_CNL_Spi;
 		break;
		

//.	case 6:
//.	
//.		break;
	default:
	i = lID_Cnl =0;
	}	
return i;
}

