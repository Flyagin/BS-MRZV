/*------------------------------------------------------------------------------
* Copyright (c) 2013 - 
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
* File Name       : SmpWrp.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  14/12/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#include    "SmpWrp.h"

RawSamplHldDsc holderRawSampl = {

{0,0,0,0,0}
};

RawSamplWrpDsc  hldRawSamplWrp = {

#ifdef __TYPE_DEFINITION_X_
//sizeof(__TOTAL_MEASUREMENT ),	(void*)	&total_measurement,		
#endif
#ifndef __TYPE_DEFINITION_X_
SIZE_RAW_SAMPLES,	(void*)&(holderRawSampl.UNRawSampl.chArSmpl[0])	,
#endif
{0,0,0,0}

};
//int AppReqTransmitRawSampl;
int AppReqReceiveRawSampl; 
long UpdateRVRawSamplCTpuUnit(void* pvLDC, long lID)
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		void *pOriginLDC;
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
//pv  = (void*)&holderRVRawSamplSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	
	pv  = (void*)holderRVRawSamplSOCTpuUnit.RvCnHldr.pUchRV;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	for (i = 0; i < lID; i++)
	{
		((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	unnV1.uchAr[3] = lID;
	
	//Clear All Ses Data
	//pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
	AppReqReceiveRawSampl++;
	i = ((RawSamplHldDsc*)pv)-> statistics.lTotalGoodChange;i++;
	((RawSamplHldDsc*)pv)-> statistics.lTotalGoodChange = i;
	//((LDCIDsc*)pvLDC)-> statistics.
	i = ((RawSamplHldDsc*)pv)-> statistics.lTotalChange;i++;
	((RawSamplHldDsc*)pv)-> statistics.lTotalChange = i;
	holderRVRawSamplSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	holderRVRawSamplSOCTpuUnit.RvCnHldr.NumComSes        = 0;
	holderRVRawSamplSOCTpuUnit.RvCnHldr.ConState         = 0;
	holderRVRawSamplSOCTpuUnit.RvCnHldr.ulRvCount        = lID;
	 //sLV.chNeedClrSesData++;
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVRawSamplSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVRawSamplSOCTpuUnit
		//(unsigned char*)&holderRVTotMeasCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_RAW_SAMPLES))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_RAW_SAMPLES) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVRawSamplSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVRawSamplSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_RAW_SAMPLES))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((RawSamplHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((RawSamplHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_TOTAL_MEASUREMENT))
				{
					//Activate App Func
					AppReqReceiveRawSampl++;
					i = ((RawSamplHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((RawSamplHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((RawSamplHldDsc*)pvLDC)-> statistics.lErrors;i++;
						((RawSamplHldDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((RawSamplHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((RawSamplHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((RawSamplHldDsc*)pvLDC)-> statistics.lErrors;i++;
			((RawSamplHldDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((RawSamplHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((RawSamplHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((RawSamplHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((RawSamplHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVRawSamplSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}

