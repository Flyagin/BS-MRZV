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
* File Name       : mTotG.c
* Description     : support for the AppCn.
                    
					
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/12/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "ApMeasG.h"

TotMeasGHldDsc holderTotMeasG = {

{0,0,0,0}
};

__TOTAL_MEASUREMENT  tot_meas;

TotMeasGWrpDsc hldTotMeasGWrp = {

#ifdef __TYPE_DEFINITION_BS_H
sizeof(__TOTAL_MEASUREMENT ),	(void*)&holderTotMeasG.UNTotMeas.total_measurement,//	&total_measurement,		
#endif
#ifndef __TYPE_DEFINITION_BS_H
0,	(void*)	0,
#endif
{0,0,0,0}

};

int AppReqTransmitTotMeasG;
int AppReqReceiveTotMeasG;

long UpdateRVTotMeasGCTpuUnit(void* pvLDC, long lID)
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
pv  = (void*)&holderRVTotMeasGSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	
	//Clear All Ses Data
	pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
	i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
	((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
	//((LDCIDsc*)pvLDC)-> statistics.
	i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
	((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
	holderRVTotMeasGSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	holderRVTotMeasGSOCTpuUnit.RvCnHldr.NumComSes        = 0;
	holderRVTotMeasGSOCTpuUnit.RvCnHldr.ConState         = 0;
	holderRVTotMeasGSOCTpuUnit.RvCnHldr.ulRvCount        = lID;
	 sLV.chNeedClrSesData++;
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVTotMeasGSOCTpuUnit.RvCnHldr;
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
			if( i<= (long)(SIZE_TOTAL_MEASUREMENT))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_TOTAL_MEASUREMENT) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVTotMeasGSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVTotMeasGSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_TOTAL_MEASUREMENT))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_TOTAL_MEASUREMENT))
				{
					//Activate App Func
					AppReqReceiveTotMeasG++;
					i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					hldTotMeasGWrp.size_total_measurement = 0;//AppReqReceiveTotMeasG = 0;
					 hldTotMeasGWrp.p_total_measurement =
					  (void*)&(holderTotMeasG.UNTotMeas.total_measurement);
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
						((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
			((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVTotMeasGSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


void TotMeasGRvServCTpuApCnUnit(void)
{
hldTotMeasGWrp.size_total_measurement = 0;
AppReqReceiveTotMeasG = 0;
 hldTotMeasGWrp.p_total_measurement =
 (void*)&holderTotMeasG.UNTotMeas.total_measurement;
//Req Copy Operation
tot_meas = holderTotMeasG.UNTotMeas.total_measurement;
hldTotMeasGWrp.p_total_measurement = (void*)	&tot_meas;
hldTotMeasGWrp.size_total_measurement =  sizeof( __TOTAL_MEASUREMENT );

}
#define ERROR 4
#define OK    3

long GetTotMeas(void *pvMeasAddr)
{
register  __TOTAL_MEASUREMENT *pMPrtData;
register long lR = 0;	
	if (pvMeasAddr == 0)
	{	
		lR = ERROR;
		goto ExitGetMeasPrt;
	}
	
	//..Control correctness Pointers
	pMPrtData =  (__TOTAL_MEASUREMENT *)pvMeasAddr;
	//
	if( (hldTotMeasGWrp.size_total_measurement == 0)
	//
	)
	{
		*pMPrtData =  holderTotMeasG.UNTotMeas.total_measurement;
		lR = OK;
	}
	else
	{
		*pMPrtData =  tot_meas;
		lR = OK;
	}
	
ExitGetMeasPrt:

	return lR;
}



