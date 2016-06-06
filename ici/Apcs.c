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
* Processor       : Lpc_3240
* File Name       : Apcs.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BS BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include <string.h>
#include    "Apcs.h"
ApcsHldDsc holderApcs = {
{0},//Header
{0,0}//Body
};

ApcsHldDsc holderApcsIciCopy = {
{0},
{0,0}

};

ObjDataMgrDsc hldApcsDataMgr;

//#include "constants.h"
//#include "type_definition.h"
//extern __TOTAL_MEASUREMENT total_measurement; 

//.-````TotMeasRWrpDsc hldTotMeasRWrp = {
//.-````
//.-````#ifdef __TYPE_DEFINITION__
//.-````sizeof(__MEASUREMENT_TO_PROTECTION ),	(void*)	&meas_protection,		
//.-````#endif
//.-````#ifndef __TYPE_DEFINITION__
//.-````0,	(void*)	0,
//.-````#endif
//.-````{0,0,0,0}
//.-````
//.-````};

ApcsWrpDsc hldApcsWrp = {

#ifdef __TYPE_DEFINITION__
sizeof(SIZE_APCS ),	(void*)	&holderApcs,		
#endif
#ifndef __TYPE_DEFINITION__
0,	(void*)	0,
#endif
{0,0,0,0}

};

int AppReqTransmitApcs;
int AppReqReceiveApcs ; //int AppReqReceiveTotMeasG;
/*
void ActivateServTrApCnApcsCTpuUnitSpi(void)
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldApcsWrp.p_Apcs;
	if(AppReqTransmitApcs==EXEC)
	{
		
		//((Dsc*)(hldApcsWrp.p_Apcs))->statistics.lErrors++;
		//((Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalBadChange++;//In This ver try to start work with Wrapers Obj 
		hldApcsWrp.statistics.lErrors++;
		hldApcsWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldApcsWrp.size_Apcs = 0;
//Copy
//hldApcsWrp.UNApcs.lArApcs[0] = 0;//meas_protection;
holderApcsIciCopy.UNApcs = holderApcs.UNApcs;
hldApcsWrp.size_Apcs = SIZE_APCS;
  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRApcsSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldApcsWrp.size_Apcs;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_APCS_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderApcsIciCopy.UNApcs.lArApcs[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnApcs(void)
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalChange++;
   hldApcsWrp.statistics.lTotalGoodChange++;
   hldApcsWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseApcsUnitSpi(void)
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
	if(AppReqTransmitApcs)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitApcs==START)
			{
				ActivateServTrApCnApcsCTpuUnitSpi();
				AppReqTransmitApcs = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitApcs==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRApcsSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitApcs = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitApcs==TERM)
				{
					TerminateServiceApCnApcs();
					AppReqTransmitApcs = 0;
				}
			}
		}
		//Try another???
		
	}
	

}
*/

long UpdateRVApcsCTpuUnit(void* pvLDC, long lID)  @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
		ObjDataMgrDsc *phldApcsDataMgr;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
sLV.phldApcsDataMgr = &hldApcsDataMgr;
pv  = (void*)&holderRVApcsSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	
	pv = (void*)sLV.phldApcsDataMgr;
	i = ((ObjDataMgrDsc*)pv) ->chIsExec;i++;((ObjDataMgrDsc*)pv) ->chIsExec = i;
	if(((ObjDataMgrDsc*)pv)->shCurCopyUser)
	((ObjDataMgrDsc*)pv)->shCopyWasCorrupted |= ((ObjDataMgrDsc*)pv)->shCurCopyUser;
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_APCS))
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_APCS);// - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	
	pvLDC = (void*)i;
	i = (long)holderRVApcsSOCTpuUnit.RvCnHldr.pUchRV;
	//i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
	pv  = (void*)i;
	for (i = 0; i < lID; i++)
	{
	((char*)pv)[i] = ((char*)pvLDC)[i];
	}

  //Activate App For
       i = 0;
	//AppReqReceiveTotMeasR++;
	AppReqReceiveApcs++;
	pv = (void*)sLV.phldApcsDataMgr;
	((ObjDataMgrDsc*)pv)->chDataWasCorrupted = 0;
	i = ((ObjDataMgrDsc*)pv)->chIsExec;i--;
	((ObjDataMgrDsc*)pv)->chIsExec = i;
	//Clear All Ses Data
	// sLV.chNeedClrSesData++;
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVApcsSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasGSOCTpuUnit
		//(unsigned char*)&holderRVTotMeasCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_APCS))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_APCS) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVApcsSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVApcsSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_APCS))
			{
				// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				// i = ((ApcsHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				//((ApcsHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_APCS))
				{
					//Activate App Func
					AppReqReceiveApcs++;
					//i = ((ApcsHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					//((ApcsHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						//i = ((ApcsHldDsc*)pvLDC)-> statistics.lErrors;i++;
						//((ApcsHldDsc*)pvLDC)-> statistics.lErrors = i;
						//i = ((ApcsHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						//((ApcsHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			//i = ((ApcsHldDsc*)pvLDC)-> statistics.lErrors;i++;
			//((ApcsHldDsc*)pvLDC)-> statistics.lErrors = i;
			//i = ((ApcsHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			//((ApcsHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			//i = ((ApcsHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			//((ApcsHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVApcsSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


void ApcsRvServCTpuApCnUnit(void)
{

AppReqReceiveApcs = 0;
memcpy((void*)&holderApcsIciCopy,
(const void*)&holderRVApcsSOCTpuUnit.RvCnHldr.pUchRV,
 SIZE_APCS);
////Inform Other

// ,
}




///////////////////////////////////////////////////////////////////////////////////////
//..................................................................................///
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   функция получения данных о ресурсе ВВ
extern long GetHvpBrOnCalcInfo(void* pHvpBrOnCalcInfoData);
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
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//static long lUserKeyApcs = 0;
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=============================================================================
//Body func
//=============================================================================
long GetHvpBrOnCalcInfo(void* pHvpBrOnCalcInfoData){
 register long i;
 register long lUsrKey;

 ObjDataMgrDsc *pApcsDataMgr = &hldApcsDataMgr;
 ApcsHldDsc loc_hldApcs;
 
	if(pApcsDataMgr->chDataWasCorrupted)
	return ERROR_EXEC;//May be return copy?
	lUsrKey = GetUserKeyIciSmallObjMgrData(pApcsDataMgr);
	if(lUsrKey == 0)
		return ERROR_EXEC;//Error Exit
	lUsrKey--;
	if (pApcsDataMgr-> chIsExec){
		ReturnUserKeyIciSmallObjMgrData(lUsrKey,pApcsDataMgr  );
		return STATE_EXEC;
	}	
//	if (pApcsDataMgr-> chDataWasCorrupted)
//	return  ERROR_EXEC;	//???
	i=3;
	do{
		(pApcsDataMgr->shCopyWasCorrupted) &= ~(1<< lUsrKey);
	pApcsDataMgr->shCurCopyUser |= 1<< lUsrKey;
		memcpy((void*)&loc_hldApcs,(const void*)&holderApcs,
		SIZE_APCS );
		pApcsDataMgr->shCurCopyUser &= ~(1<< lUsrKey);
		//i = (pApcsDataMgr->shCopyWasCorrupted)&(1<<lUsrKey);
		i--;
	}while( i&&( (pApcsDataMgr->shCopyWasCorrupted)&(1<<lUsrKey)) );
	ReturnUserKeyIciSmallObjMgrData(lUsrKey,pApcsDataMgr  );
	if( i==0 &&
	((pApcsDataMgr->shCopyWasCorrupted)&(1<<lUsrKey)) )
	return ERROR_EXEC ;
	memcpy(pHvpBrOnCalcInfoData,(const void*)holderApcs.UNApcs.chArApcs[0],SIZE_BODY_APCS);


	
	return SUCCESS_EXEC;
}
//-----------------------------------------------------------------------------


//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=============================================================================
//Body func                                                                  
//=============================================================================
long GetUserKeyHvpBrOnCalcInfo(void)  @ "Fast_function"
{

	return  GetUserKeyIciSmallObjMgrData(&hldApcsDataMgr);
}
//-----------------------------------------------------------------------------





















