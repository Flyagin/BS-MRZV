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
* File Name       : GoosA.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "../inc/const_BS_BL.h" 
#include    "../inc/type_definition_BS.h"
#include    "../inc/type_definition_BL.h" 


#include    "GoosA.h"
GoosAHldDsc holderGoosA = {
{'a','b','c','d','e','g','h','j'},
{0,0,0,0}
};

GoosAHldDsc holderGoosAIciCopy = {

{0,0,0,0}
};

//-#include "constants.h"
//-#include "type_definition.h"
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

GoosAWrpDsc hldGoosAWrp = {

#ifdef __TYPE_DEFINITION__
SIZE_GOOS_A,	(void*)	&holderGoosA.UNGoosA.lArGoosA[0],		
#endif
#ifndef __TYPE_DEFINITION__
0,	(void*)	0,
#endif
{0,0,0,0}

};

int AppReqTransmitGoosA;
int AppReqReceiveGoosA ; //int AppReqReceiveTotMeasG;

void ActivateServTrApCnGoosACTpuUnitSpi(void)  @ "Fast_function"
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldGoosAWrp.p_GoosA;
	if(AppReqTransmitGoosA==EXEC)
	{
		
		//((Dsc*)(hldGoosAWrp.p_GoosA))->statistics.lErrors++;
		//((Dsc*)(hldGoosAWrp.p_GoosA))->statistics.lTotalBadChange++;//In This ver try to start work with Wrapers Obj 
		hldGoosAWrp.statistics.lErrors++;
		hldGoosAWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldGoosAWrp.size_GoosA = 0;
//Copy
//hldGoosAWrp.UNGoosA.lArGoosA[0] = 0;//meas_protection;
holderGoosAIciCopy.UNGoosA = holderGoosA.UNGoosA;
hldGoosAWrp.size_GoosA = SIZE_GOOS_A;
  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRGoosASOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_GOOS_A_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldGoosAWrp.size_GoosA;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_GOOS_A_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderGoosAIciCopy.UNGoosA.lArGoosA[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnGoosA(void)  @ "Fast_function"
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldGoosAWrp.p_GoosA))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldGoosAWrp.p_GoosA))->statistics.lTotalChange++;
   hldGoosAWrp.statistics.lTotalGoodChange++;
   hldGoosAWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseGoosAUnitSpi(void)  @ "Fast_function"
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
	if(AppReqTransmitGoosA)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitGoosA==START)
			{
				ActivateServTrApCnGoosACTpuUnitSpi();
				AppReqTransmitGoosA = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitGoosA==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRGoosASOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitGoosA = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitGoosA==TERM)
				{
					TerminateServiceApCnGoosA();
					AppReqTransmitGoosA = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

long UpdateRVGoosACTpuUnit(void* pvLDC, long lID)  @ "Fast_function"
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
pv  = (void*)&holderRVGoosASOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_GOOS_A))
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_GOOS_A);// - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	
	pvLDC = (void*)i;
	i = (long)holderRVGoosASOCTpuUnit.RvCnHldr.pUchRV;
	//i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
	pv  = (void*)i;
	for (i = 0; i < lID; i++)
	{
	((char*)pv)[i] = ((char*)pvLDC)[i];
	}

  //Activate App For
    //..  TestReqReceiveT1++;
  //Clear All Ses Data
       i = 0;
	AppReqReceiveGoosA++;
	
	
	//Clear All Ses Data
	/*
	pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
	i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors;i++;
	((TotMeasRHldDsc*)pvLDC)-> statistics.lErrors = i;
	//((LDCIDsc*)pvLDC)-> statistics.
	i = ((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
	((TotMeasRHldDsc*)pvLDC)-> statistics.lTotalChange = i;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.NumComSes        = 0;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.ConState         = 0;
	holderRVTotMeasRSOCTpuUnit.RvCnHldr.ulRvCount        = lID;
	 sLV.chNeedClrSesData++;
	*/ 
	 
	 
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVGoosASOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVGoosASOCTpuUnit
		//(unsigned char*)&holderRVTotMeasCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_GOOS_A))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_GOOS_A) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVGoosASOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVGoosASOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_GOOS_A))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((GoosAHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((GoosAHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_GOOS_A))
				{
					//Activate App Func
					AppReqReceiveGoosA++;
					i = ((GoosAHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((GoosAHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((GoosAHldDsc*)pvLDC)-> statistics.lErrors;i++;
						((GoosAHldDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((GoosAHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((GoosAHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((GoosAHldDsc*)pvLDC)-> statistics.lErrors;i++;
			((GoosAHldDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((GoosAHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((GoosAHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((GoosAHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((GoosAHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVGoosASOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}

void GoosARvServCTpuApCnUnit(void)
{

AppReqReceiveGoosA = 0;

}

