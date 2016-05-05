/*------------------------------------------------------------------------------
* Created (c) 2015 - Factory “KyivPrylad”
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
* File Name       : AbnD.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include <string.h>
#include    "AbnD.h"


#define AMOUNT_RECORDS_ANALOG_WITH_CMD 100
#define MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD   ((AMOUNT_RECORDS_ANALOG_WITH_CMD>>1)+(AMOUNT_RECORDS_ANALOG_WITH_CMD>>2))

long l_IdxAWthCmdBuf = 0;
//long  arAnallogWthCmdBuf_L[((SIZE_ANALOG_DATA + SIZE_COMMAND_DATA)*(AMOUNT_RECORDS_ANALOG_WITH_CMD))];
//Primary buf for ARec data
//DDR2_B1_2_DATA
//PflDataDsc PflData @ "DDR2_Bank1_2_variables";
ARecDataDsc arArecDataBS[AMOUNT_RECORDS_ANALOG_WITH_CMD] @ "DDR2_Bank1_2_variables";

AbsNumeratorUnnDsc holderAbsNumerator;

AbsNumeratorUnnDsc hldAbsNumertrs,hldRQ1AbsNumertrs,hldRQ2AbsNumertrs;//,hldRQ2AbsNumertrs;
long lRQ1AbsNumertrs, lRQ2AbsNumertrs;
long l1AbsNumertrs = 0,l2AbsNumertrs = 0;

long lCtrRQ;
//ARecDataDsc arArecDataBS[AMOUNT_RECORDS_ANALOG_WITH_CMD] @ "DDR2_Bank1_2_variables";
AbsNumersIdxBufBsDsc arAbsNumersIdxBufBs[2];
long lBitActiveElemInarAbsNumersIdxBufBs = 0;
//char arChNumIdxElemInarAbsNumersIdxBufBs[2];

int AppReqTransmitAbsNumerator;
int AppReqTransmitbsNumeratorRQ;



AbsNumersIdxBufBsDsc ZeroAbsNumersIdxBufBs = {
0,0,0,0, 0,0,0,0, 0,0,0,0
};





void ActivateServTrApCnAbsNumeratorCTpuUnitSPI(void*pvO)   @ "Fast_function"
{

register void* pv;

//holderDiagnBmBs.UNN_Sdfe.mRamErrEvt = hldrErrEvt;
 
  //Reset Connect State
   pv  = (void*)& (holderTRAbsNumeratorUnnSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    =SIZE_TPDU_UNN_ABS_NUMERTRS_BR_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj =  SIZE_ABS_NUMERATOR;
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_UNN_ABS_NUMERTRS_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pvO;//& holderAbsNumerator.UNNAbsNumtrs.chArNums[0]; //
   
}

void TerminateServiceApCnAbsNumerator(void)
{
if(hldrTpCnState.uchTpState_CNL_Spi == 0)
	{
		hldrTpCnState.uchTpState_CNL_Spi++;
	}
//uchTpState_CNL_Spi   
}
//Pr
void PrepDecompouseAbsNumeratorsUnitSPI(void)   @ "Fast_function"
{
register long i,j;
register void *pv, *pvO;
	pv = (void*)&hldrTpCnState;
	if((AppReqTransmitbsNumeratorRQ & 1) && (AppReqTransmitbsNumerator==0) )
	{
		AppReqTransmitbsNumerator=START;
		AppReqTransmitbsNumeratorRQ &= ~1;
		pvO = (void*)&hldAbsNumertrs;
		goto ProcessPrepDecompouseAbsNumeratorsUnitSPI;
	
	}
	if((AppReqTransmitbsNumeratorRQ & 2)&& (AppReqTransmitbsNumerator==0))
	{
		AppReqTransmitbsNumerator=START;
		AppReqTransmitbsNumeratorRQ &= ~2;
		pvO = (void*)&hldRQ1AbsNumertrs;
		goto ProcessPrepDecompouseAbsNumeratorsUnitSPI;
	
	}
	if((AppReqTransmitbsNumeratorRQ & 4)&& (AppReqTransmitbsNumerator==0))
	{
		AppReqTransmitbsNumerator=START;
		AppReqTransmitbsNumeratorRQ &= ~4;
		pvO = (void*)&hldRQ2AbsNumertrs;
		goto ProcessPrepDecompouseAbsNumeratorsUnitSPI;
	
	}
	
	//Control then All Channels Full
	//.if()
	//.{
	//.
	//.}
	//Control State Obj if Need Transmit
ProcessPrepDecompouseAbsNumeratorsUnitSPI:	
	//Process
	if(AppReqTransmitbsNumerator)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_ABS_NUMERATOR;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitbsNumerator==START)
			{
				ActivateServTrApCnAbsNumeratorCTpuUnitSPI(pvO );
				AppReqTransmitbsNumerator = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitbsNumerator==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRAbsNumeratorUnnSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitbsNumerator = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitbsNumerator==TERM)
				{
					TerminateServiceApCnAbsNumerator();
					AppReqTransmitbsNumerator = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

int AppReqReceiveARecDataBs;
ARecDataDsc hld1ARecData,hld2ARecData;

long UpdateRVARecDataBsTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chDetect_arAbsNumersIdxBufBs;
		char chNeedClrSesData;
		void *pOriginLDC;
		long lTrSize;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

sLV.pOriginLDC = pvLDC;
sLV.chDetect_arAbsNumersIdxBufBs = 0;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;

unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;

pv  = (void*)&holderRVUN_ArecSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	//pv  = (void*)	&holderDiagnBrBs.UNN_Sdfe.chArSDFE[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	sLV. lTrSize = lID;
	pvLDC = (void*)i;
	
	memcpy((void*)&unnV1,
	(const void*)&(((ARecDataDsc*)pvLDC)->UN_ArecDataBS.sArecBrWrp.chAbnNum[0]),
	4);
	if((unnV1. ulVal == arAbsNumersIdxBufBs[0].lSelectedAbsNumertr)&&
	(lBitActiveElemInarAbsNumersIdxBufBs&1))
	{
		sLV.chDetect_arAbsNumersIdxBufBs = 1;
		//sLV.chNeedClrSesData = 0;
		pv  = (void*)&arAbsNumersIdxBufBs[0];
		if( ((AbsNumersIdxBufBsDsc*)pv)->lFirstSize != 0 )
		{
			lID = ((AbsNumersIdxBufBsDsc*)pv)->lFirstStartIdx 
			+((AbsNumersIdxBufBsDsc*)pv)->lFirstIdx;
			//arArecDataBS[lID]
			((AbsNumersIdxBufBsDsc*)pv)->lFirstSize--;
			((AbsNumersIdxBufBsDsc*)pv)->lFirstIdx++;
		}
		else
		{
			if( ((AbsNumersIdxBufBsDsc*)pv)->lSecondSize != 0 )
			{
				lID = ((AbsNumersIdxBufBsDsc*)pv)->lSecondStartIdx 
			+((AbsNumersIdxBufBsDsc*)pv)->lSecondIdx;
			((AbsNumersIdxBufBsDsc*)pv)->lSecondIdx++;
			//arArecDataBS[lID]
			((AbsNumersIdxBufBsDsc*)pv)->lSecondSize--;
			}
			
		}
		((AbsNumersIdxBufBsDsc*)pv)->lCtrRvAbsNumertrs++;
		i = ((AbsNumersIdxBufBsDsc*)pv)->lSelectedAbsNumertr;
		i++;
		if(i < 0x7fffffff) 
		;
		else 
		i = 0;
		((AbsNumersIdxBufBsDsc*)pv)->lSelectedAbsNumertr = i;
		//if (i == (((AbsNumersIdxBufBsDsc*)pv)->l1AbsNumertrs))
		;
		if( (((AbsNumersIdxBufBsDsc*)pv)->lFirstSize) == 0 )
			sLV.chNeedClrSesData |= 1;
		if( (((AbsNumersIdxBufBsDsc*)pv)->lSecondSize) == 0 )
			sLV.chNeedClrSesData |= 2;
		//((AbsNumersIdxBufBsDsc*)pv)->lCtrRvAbsNumertrs++;	
			
		if(sLV.chNeedClrSesData >= 3) 
		//Insert addres InBuf
		{
		memcpy((void*)&arAbsNumersIdxBufBs[0],(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumersIdxBufBsDsc));//Stop 
			lBitActiveElemInarAbsNumersIdxBufBs &= ~1;
		
			
		}
		else		
		{
			pv = (void*)&hldRQ1AbsNumertrs.UNNAbsNumtrs.chArNums[0];
			memcpy((void*)pv,(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumeratorUnnDsc));
			//memcpy((void*)pvL,(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumersIdxBufBsDsc) );
			
			AppReqTransmitbsNumeratorRQ|= 2	;//Activated
			memcpy((void*)&
			((AbsNumeratorUnnDsc*)pv)->UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum1[0],
			(const void*)&arAbsNumersIdxBufBs[0].lSelectedAbsNumertr,4);//. ((AbsNumersIdxBufBsDsc*)pvL)->lSelectedAbsNumertr
			lBitActiveElemInarAbsNumersIdxBufBs |= 1;
			((AbsNumeratorUnnDsc*)pv)->UNNAbsNumtrs.sBsAbsNumeratorWrp.chBitFld = 0x11;
		}
		if(lID>AMOUNT_RECORDS_ANALOG_WITH_CMD)
		lID = AMOUNT_RECORDS_ANALOG_WITH_CMD-1;
		pv  = (void*)&arArecDataBS[lID];
		lID = sLV.lTrSize;
		if(lID > ((long) sizeof(ARecDataDsc)) )
		lID = (sizeof(ARecDataDsc));
		//MoveData: 
		for (i = 0; i < lID; i++)
		{
		((char*)pv)[i] = ((char*)pvLDC)[i];
		}
	}
	if(unnV1. ulVal == arAbsNumersIdxBufBs[1].lSelectedAbsNumertr
	&& (lBitActiveElemInarAbsNumersIdxBufBs&2))
	{
		sLV.chDetect_arAbsNumersIdxBufBs = 2;
		//pv  = (void*)&
	}
	if(sLV.chDetect_arAbsNumersIdxBufBs)
	{
		
	}
//	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
//	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
//	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	 
//.!~	//Check if the Last Key in Range AbsNumersIdxBufBsDsc-->long l1AbsNumertrs,l2AbsNumertrs;

//AppReqReceiveARecDataBs++;
//.!~	//Check Possible Stop when lSelectedAbsNumertr
//.!~	//still in Diapazon i.e. distance between global l1AbsNumertrs+ 
//.!~	//end lSelectedAbsNumertr > MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD

//.!~	//This Check in void ExtractUrgentDataBr2Bs(void* pv) function
	
	
}








return lID;//unnV1.uchAr[3];
}

//ARecDataDsc
ARecDataDsc hldCurrARecData;
 int AppReqTransmitbsNumerator;
 int AppReqTransmitbsNumeratorRQ;
 
 
void ExtractUrgentDataBr2Bs(void* pv)   @ "Fast_function"
{
register long i,j;
register void* pvL;
//register char *pSrc,*pDst;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
	struct 
	{
		long lFirstStart,lFirstSize;
		long lSecondStart, lSecondSize;
		long lDeltaAbsNumertrs;
		long lCurrLastNumerators, lLastIdxNum;
		long lNeedReceive;
	} sLV;
	j = (long) pv;
  	sLV. lDeltaAbsNumertrs = sLV.lNeedReceive = 0;

	i = j+4;
	unnV1. uchAr [0] = *( (char*) pv+0);
	unnV1. uchAr [1] = *( (char*) pv+1);
	unnV1. uchAr [2] = *( (char*) pv+2);
	unnV1. uchAr [3] = *( (char*) pv+3);
	//Extact ulCtrTrLpduSpi
	 //arArecDataBS[l_IdxAWthCmdBuf] = *( (ARecDataDsc*) (i));
	// memcpy((void*)&arArecDataBS[l_IdxAWthCmdBuf],(const void*)i,sizeof(hldCurrARecData) );
	//hld2AbsNumertrs =  hld1AbsNumertrs;
	//hldAbsNumertrs.
	pv = (void*)(j+4);
	i = ((ARecDataDsc*)pv)->UN_ArecDataBS.sArecBrWrp.chArAnlg[SIZE_ANALOG_DATA-1];
	if(i==0xff)
	sLV. lDeltaAbsNumertrs++;
	i = ((ARecDataDsc*)pv)->UN_ArecDataBS.sArecBrWrp.chArWrp[SIZE_WRP_LOG_DATA-1];
	if(i==0xff)
	sLV. lDeltaAbsNumertrs++;
	i = ((ARecDataDsc*)pv)->UN_ArecDataBS.sArecBrWrp.chAbnNum[SIZE_ABN_NUMERATOR-1];
	if(i==0xff)
	sLV. lDeltaAbsNumertrs++;
	
	if(sLV. lDeltaAbsNumertrs)
	return;//Bad Data
	l2AbsNumertrs = l1AbsNumertrs;
	
	memcpy((void*)&hldCurrARecData,(const void*)pv,sizeof(hldCurrARecData) );
	//hld1AbsNumertrs = ((ARecDataDsc*)pv)->UN_ArecDataBS.sArecBrWrp.chAbnNum
	//memcpy((void*)&unnV1. uchAr [0],(const void*)& (((ARecDataDsc*)pv)->UN_ArecDataBS->sArecBrWrp->chAbnNum),4);
	//l1AbsNumertrs = unnV1.ulVal;
	   unnV1. uchAr [0] = hldCurrARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [0]; 
	   unnV1. uchAr [1] = hldCurrARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [1]; 
	   unnV1. uchAr [2] = hldCurrARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [2]; 
	   unnV1. uchAr [3] = hldCurrARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [3]; 
	 l1AbsNumertrs = unnV1.ulVal;
	//Check State
	if(lBitActiveElemInarAbsNumersIdxBufBs)
		{
			//Chek and exclude Possible Req Session
			if(lBitActiveElemInarAbsNumersIdxBufBs&1)
			{
				CheckActiveElemInArAbs((void*)&arAbsNumersIdxBufBs[0]);
				if(arAbsNumersIdxBufBs[0].lState&(1<<2))
				{
				memcpy((void*)&arAbsNumersIdxBufBs[0],(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumersIdxBufBsDsc));
				lBitActiveElemInarAbsNumersIdxBufBs &=~1;
				}
			}
			if(lBitActiveElemInarAbsNumersIdxBufBs&2)
			{
				//Check & Activete Req
				CheckActiveElemInArAbs((void*)&arAbsNumersIdxBufBs[1]);
			}
		}	
	//
	//Detect Diff 
	i = (l2AbsNumertrs+1);
	
	if(i == l1AbsNumertrs)
	{

		memcpy((void*)&arArecDataBS[l_IdxAWthCmdBuf],(const void*)&hldCurrARecData,sizeof(hldCurrARecData) );
		//
		memcpy((void*)&(hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum1[0]),(const void*)&l1AbsNumertrs,4); 
		memcpy((void*)&(hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum2[0]),(const void*)&l2AbsNumertrs,4); 
		hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chBitFld = 0;
		 AppReqTransmitbsNumeratorRQ |= 1;sLV. lDeltaAbsNumertrs = 1;
//		i = l_IdxAWthCmdBuf+sLV.lDeltaAbsNumertrs;                   //Comment for check Feeling
//		if(i < AMOUNT_RECORDS_ANALOG_WITH_CMD) l_IdxAWthCmdBuf = i;  //Comment for check Feeling
//		else                                                         //Comment for check Feeling
//		l_IdxAWthCmdBuf = i - AMOUNT_RECORDS_ANALOG_WITH_CMD;        //Comment for check Feeling
	
	}
	else
	{

		
		if(l2AbsNumertrs<= l1AbsNumertrs)
		{
			i = l1AbsNumertrs - l2AbsNumertrs;
		}	
		else
		{
			i = 0x7fffffff-l2AbsNumertrs;
			if(i==0)
			{
				if(l1AbsNumertrs==0)
				{
					memcpy((void*)&arArecDataBS[l_IdxAWthCmdBuf],(const void*)&hldCurrARecData,sizeof(hldCurrARecData) );
					//
					memcpy((void*)&(hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum1[0]),(const void*)&l1AbsNumertrs,4); 
					memcpy((void*)&(hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum2[0]),(const void*)&l2AbsNumertrs,4); 
					hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chBitFld = 0;
					AppReqTransmitbsNumeratorRQ |= 1;sLV. lDeltaAbsNumertrs = 1;
					goto IncrIdxBuf;
				}
			}
			i++;//<- skip 0x8000 0000
			i +=   l1AbsNumertrs;
			
		}	
		
		if (i>AMOUNT_RECORDS_ANALOG_WITH_CMD)//? счет- то ведется не поєтой константе
		{
			i = MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD;
			//sLV.lDeltaAbsNumertrs = MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD;
			//Change If Need L2
			
			if(l1AbsNumertrs> (MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD))
			l2AbsNumertrs = l1AbsNumertrs - MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD;
			else
			{
				//j = 0x7fffffff- l2AbsNumertrs;
				j = (MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD)-l1AbsNumertrs;
				l2AbsNumertrs = 0x7fffffff- j;
				
			}
			
		
		}
		if(i==0)
		{
			//Explicit Exeptiton or Error
			goto IncrIdxBuf;
		}
		i--;
		sLV.lDeltaAbsNumertrs = i;
		
		   //Calc Possible fact val l_IdxAWthCmdBuf
		j = l_IdxAWthCmdBuf + i;   
		if(j<AMOUNT_RECORDS_ANALOG_WITH_CMD ) 
		{   
				l_IdxAWthCmdBuf = j;
			}
		else 
		l_IdxAWthCmdBuf = j - AMOUNT_RECORDS_ANALOG_WITH_CMD;
		sLV.lCurrLastNumerators = l_IdxAWthCmdBuf;//Save l_IdxAWthCmdBuf
		
		 memcpy((void*)&arArecDataBS[l_IdxAWthCmdBuf],(const void*)&hldCurrARecData,sizeof(hldCurrARecData) );
		//
		memcpy((void*)&(hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum1[0]),(const void*)&l1AbsNumertrs,4); 
		memcpy((void*)&(hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum2[0]),(const void*)&l2AbsNumertrs,4); 
		hldAbsNumertrs.UNNAbsNumtrs.sBsAbsNumeratorWrp.chBitFld = 0;
		 AppReqTransmitbsNumeratorRQ |= 1;//sLV. lDeltaAbsNumertrs = 1;
		i = l_IdxAWthCmdBuf+sLV.lDeltaAbsNumertrs;
//		if(i < AMOUNT_RECORDS_ANALOG_WITH_CMD) l_IdxAWthCmdBuf = i;
//		else 
//		l_IdxAWthCmdBuf = i - AMOUNT_RECORDS_ANALOG_WITH_CMD;
			
		   //Fierst Put Data in Last
		   
		lCtrRQ++;
		
		if(lBitActiveElemInarAbsNumersIdxBufBs)
		{
			//Chek and exclude Possible Req Session
			if(lBitActiveElemInarAbsNumersIdxBufBs&1)
			{
				//Check & Activete Req
				j = arAbsNumersIdxBufBs[0].l1AbsNumertrs;
				if(j > l1AbsNumertrs)
				j -= l1AbsNumertrs;//Detec Minimal difference
				else
				j += (0x7fffffff -l1AbsNumertrs);
				sLV.lNeedReceive = arAbsNumersIdxBufBs[0].lSecondSize -  arAbsNumersIdxBufBs[0].lSecondIdx;
				sLV.lNeedReceive += arAbsNumersIdxBufBs[0].lFirstSize -  arAbsNumersIdxBufBs[0].lFirstIdx;
				
				if(j<(sLV.lNeedReceive + 1))// <- Possible Change One o n const AmountARecDataDsc in SPi pacet
				{
				arAbsNumersIdxBufBs[0].lState = 1<<2;//Stop Req;//Exit fr
				//Proces Stop Req
				memcpy((void*)&arAbsNumersIdxBufBs[0],(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumersIdxBufBsDsc));//Stop 
				lBitActiveElemInarAbsNumersIdxBufBs &= ~1;
				}
				
			}
			//Chek and exclude Possible Req Session
			if(lBitActiveElemInarAbsNumersIdxBufBs&2)
			{
				//Check & Activete Req
				;
				
				
			}
		}
//		else
//		{
//			;
//
//		
//		}

		   i = sLV.lDeltaAbsNumertrs;
		
		   
			j = l_IdxAWthCmdBuf;
			
			if(j>i)
				{
					sLV.lFirstSize       = i;
					sLV.lFirstStart   = j-i;
					sLV.lSecondStart  = 0;
					sLV.lSecondSize   = 0;
				
				}
				else
				{
					sLV.lFirstSize       = i-j+1;
					sLV.lSecondSize      = j;
					sLV.lSecondStart  = 0;
					sLV.lFirstStart   = j+(AMOUNT_RECORDS_ANALOG_WITH_CMD-1)-i;
				
				}
		 
		
		
		
	
		//^hldCurrARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [3] |= 0x80;//Mark as Bad Numerator
		//Detect Diapazones
		pvL = (void*)&arArecDataBS[sLV.lFirstStart].UN_ArecDataBS.sArecBrWrp.chAbnNum[3];
		//Insert Data
		if(sLV.lFirstSize>3)
		sLV.lLastIdxNum = sLV.lFirstSize - 3;
		else
		sLV.lLastIdxNum = 0;
		for(i = sLV.lLastIdxNum; i<sLV.lFirstSize; i++) 
		{
			
			
			*((char*)pvL+(i*sizeof(ARecDataDsc))) |= 0x80;//Mark as Bad Numerator
			//j = sLV.lFirstStart + i;
			//memcpy((void*)&arArecDataBS[j],(const void*)&hldCurrARecData,sizeof(hldCurrARecData) );
			
		}
		pvL = (void*)&arArecDataBS[ sLV.lSecondStart].UN_ArecDataBS.sArecBrWrp.chAbnNum[3];
		if(sLV.lSecondSize>3)
		sLV.lLastIdxNum = sLV.lSecondSize - 3;
		else
		sLV.lLastIdxNum = 0;
		for(i = sLV.lLastIdxNum; i<sLV.lSecondSize ; i++) 
		{
			
			*((char*)pvL+(i*sizeof(ARecDataDsc))) |= 0x80;//Mark as Bad Numerator
			//j = sLV.lSecondStart +i;
			//memcpy((void*)&arArecDataBS[j],(const void*)&hldCurrARecData,sizeof(hldCurrARecData) );
			
		}
			//Try Activated
		//if( (lBitActiveElemInarAbsNumersIdxBufBs&1) == 0)
		{
			//START Init Requsts
			pvL = (void*)&arAbsNumersIdxBufBs[0];
			
			((AbsNumersIdxBufBsDsc*)pvL)->l1AbsNumertrs    = l1AbsNumertrs;
			((AbsNumersIdxBufBsDsc*)pvL)->l2AbsNumertrs    = l2AbsNumertrs;
			((AbsNumersIdxBufBsDsc*)pvL)->lCtrRvAbsNumertrs = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lDeltaAbsNumertrs = sLV.lDeltaAbsNumertrs;
			 if(l2AbsNumertrs < 0x7fffffff)
			 ((AbsNumersIdxBufBsDsc*)pvL)->lSelectedAbsNumertr = l2AbsNumertrs+1;
			else 
			
			((AbsNumersIdxBufBsDsc*)pvL)->lSelectedAbsNumertr = 0;
			
			((AbsNumersIdxBufBsDsc*)pvL)->lFirstStartIdx   = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lSecondStartIdx  = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lFirstIdx        = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lSecondIdx       = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lFirstSize       = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lSecondSize      = 0;
			((AbsNumersIdxBufBsDsc*)pvL)->lState           = 1;//Activated
			if(l2AbsNumertrs > l1AbsNumertrs)
			{
				i = 0x7fffffff-l2AbsNumertrs;
				i+= l1AbsNumertrs;//+1
				j = l_IdxAWthCmdBuf;
				
				
				
			
			}
			else
			{
				i = sLV.lDeltaAbsNumertrs;
				j = l_IdxAWthCmdBuf;
				
	
			}
			if(j>i)
				{
					((AbsNumersIdxBufBsDsc*)pvL)->lFirstSize       = i;//
					((AbsNumersIdxBufBsDsc*)pvL)->lFirstStartIdx   = j-i;
				
				}
				else
				{
					((AbsNumersIdxBufBsDsc*)pvL)->lFirstSize       = i-j+1;
					((AbsNumersIdxBufBsDsc*)pvL)->lSecondSize      = j;
					((AbsNumersIdxBufBsDsc*)pvL)->lSecondStartIdx  = 0;
					((AbsNumersIdxBufBsDsc*)pvL)->lFirstStartIdx   = j+(AMOUNT_RECORDS_ANALOG_WITH_CMD-1)-i;
					//((AbsNumersIdxBufBsDsc*)pvL)->lSelectedAbsNumertr = l2AbsNumertrs;
				
				}
	
			((AbsNumersIdxBufBsDsc*)pvL)->lState           = 1;//Activated
			pv = (void*)&hldRQ1AbsNumertrs.UNNAbsNumtrs.chArNums[0];
			memcpy((void*)pv,(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumeratorUnnDsc));
			//memcpy((void*)pvL,(const void*)&ZeroAbsNumersIdxBufBs,sizeof(AbsNumersIdxBufBsDsc) );
			
			AppReqTransmitbsNumeratorRQ|= 2	;//Activated
			memcpy((void*)&
			((AbsNumeratorUnnDsc*)pv)->UNNAbsNumtrs.sBsAbsNumeratorWrp.chArNum1[0],
			(const void*)&((AbsNumersIdxBufBsDsc*)pvL)->lSelectedAbsNumertr,4);
			lBitActiveElemInarAbsNumersIdxBufBs |= 1;
			((AbsNumeratorUnnDsc*)pv)->UNNAbsNumtrs.sBsAbsNumeratorWrp.chBitFld = 0x11;
		
		
		}
		if( (lBitActiveElemInarAbsNumersIdxBufBs&2) == 0)
		{
			//START Init Requsts
			
		}
//^		i = l_IdxAWthCmdBuf+sLV.lDeltaAbsNumertrs+1;
//^		if(i < AMOUNT_RECORDS_ANALOG_WITH_CMD) l_IdxAWthCmdBuf = i;
//^		else 
//^		l_IdxAWthCmdBuf = i - AMOUNT_RECORDS_ANALOG_WITH_CMD;
		
	
	}

	//Chek and exclude Possible Req Session
	if(lBitActiveElemInarAbsNumersIdxBufBs&2)
	{
		//Check & Activete Req
		;
		
		
	}
	
	
IncrIdxBuf:	
	i = l_IdxAWthCmdBuf+1;//+sLV.lDeltaAbsNumertrs
 	if(i < AMOUNT_RECORDS_ANALOG_WITH_CMD) l_IdxAWthCmdBuf = i;
   else 
 	l_IdxAWthCmdBuf = i - AMOUNT_RECORDS_ANALOG_WITH_CMD;

	if(chEnableCheck)
	{
		EvalCSTl();
	}
}

long  CheckActiveElemInArAbs(void* pv)   @ "Fast_function"
{
register long i,j;
//register void* pvL;

	i = 0;
	
	j = ((AbsNumersIdxBufBsDsc*)pv)->l1AbsNumertrs;
	if(j > l1AbsNumertrs)
	j -= l1AbsNumertrs;//Detec Minimal difference
	else
	j += (0x7fffffff -l1AbsNumertrs);
	i = ((AbsNumersIdxBufBsDsc*)pv)->lSecondSize -  ((AbsNumersIdxBufBsDsc*)pv)->lSecondIdx;
	i += ((AbsNumersIdxBufBsDsc*)pv)->lFirstSize -  ((AbsNumersIdxBufBsDsc*)pv)->lFirstIdx;
				
	if(j<(i + MAX_VAL_REQ_RECORDS_ANALOG_WITH_CMD))
	{
		i = ERROR;
		((AbsNumersIdxBufBsDsc*)pv)->lState = 1<<2;//Stop Req;//Exit
		
	}
	else
	i = OK;
	

	return i;
}

char chEnableCheck = 0;
char chActivateCheck = 0;

long lCSFirstStartIdx, lCsFirstIdx, lCsFirstSize;
long lCSSecondStartIdx,lCsSecondIdx,lCsSecondSize;
 unsigned long ulCs;
//unsigned long ;	
ARecDataDsc  hldTestARecData  @ "DDR2_Bank1_2_variables";

void EvalCSTl(void)   @ "Fast_function"
{
register long i,j,rlVal;
register void* pvL;
//register char *pSrc,*pDst;
union 
	{
		unsigned char   uchAr [4];
		unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;
	struct 
	{
		long lFirstStart,lFirstSize;
		long lSecondStart, lSecondSize;
		long lDeltaAbsNumertrs;
		long lCurrLastNumerators, lLastIdxNum;
		long l1AbsNumertrs,l2AbsNumertrs;
		long lNeedReceive;
	} sLV;


	//j = l_IdxAWthCmdBuf;
	j = l_IdxAWthCmdBuf ;   
		if(j>1 ) 
		{   
				sLV.lCurrLastNumerators = j - 1;//l_IdxAWthCmdBuf = j;
			}
		else 
		sLV.lCurrLastNumerators = AMOUNT_RECORDS_ANALOG_WITH_CMD - 1;
	
memcpy((void*)&unnV1.ulVal,(const void*)&arArecDataBS[l_IdxAWthCmdBuf].UN_ArecDataBS.sArecBrWrp.chAbnNum[0],4 );
//memcpy((void*)&hldTestARecData,(const void*)&arArecDataBS[l_IdxAWthCmdBuf],sizeof(hldCurrARecData) );
// unnV1. uchAr [0] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [0]; 
// unnV1. uchAr [1] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [1]; 
// unnV1. uchAr [2] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [2]; 
// unnV1. uchAr [3] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [3]; 

 sLV.l1AbsNumertrs  = unnV1.ulVal;
 j = sLV.lCurrLastNumerators;

memcpy((void*)&unnV1.ulVal,(const void*)&arArecDataBS[j].UN_ArecDataBS.sArecBrWrp.chAbnNum[0],4 ); 
// memcpy((void*)&hldTestARecData,(const void*)&arArecDataBS[j],sizeof(hldCurrARecData) );
// unnV1. uchAr [0] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [0]; 
// unnV1. uchAr [1] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [1]; 
// unnV1. uchAr [2] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [2]; 
// unnV1. uchAr [3] = hldTestARecData.UN_ArecDataBS.sArecBrWrp.chAbnNum [3]; 

 
 sLV.l2AbsNumertrs = unnV1.ulVal;
 sLV.lNeedReceive = 0;
 if(sLV.l1AbsNumertrs < (0x7fffffff - AMOUNT_RECORDS_ANALOG_WITH_CMD))
 {
	;//Classical Variant
	
	 sLV.lFirstSize    = l_IdxAWthCmdBuf ;   
     sLV.lFirstStart   = 0;
     sLV.lSecondStart  = l_IdxAWthCmdBuf;
     sLV.lSecondSize   =   AMOUNT_RECORDS_ANALOG_WITH_CMD;
		rlVal = 0;			
//Detect Diapazones
	pvL = (void*)&arArecDataBS[sLV.lFirstStart].UN_ArecDataBS.sArecBrWrp.chAbnNum[0];
	//Insert Data
	sLV.lLastIdxNum = sLV.lFirstStart;
	//```if(sLV.lFirstSize>3)
	//```sLV.lLastIdxNum = sLV.lFirstSize - 3;
	//```else
	//sLV.lLastIdxNum = 0;
	j = 1;
	for(i = sLV.lLastIdxNum; i<sLV.lFirstSize; i++) 
	{
		//*((char*)pvL+(i*sizeof(ARecDataDsc))) |= 0x80;//Mark as Bad Numerator
		//
		memcpy((void*)&unnV1.ulVal,(const void*)((char*) pvL+(i*sizeof(ARecDataDsc)) ),4 );
		if (i==0)
		{
			sLV.lDeltaAbsNumertrs = unnV1.ulVal;
			rlVal = unnV1.ulVal;
		}	
		if(unnV1.uchAr [3]&0x80)
		{
			sLV.lNeedReceive++;//Fix Potential Error
			unnV1.uchAr [3]&=0x7f;
		}
		j += unnV1.ulVal- rlVal;
		rlVal = unnV1.ulVal;
		
		
	}
	lCsFirstSize = j;
	pvL = (void*)&arArecDataBS[ 0].UN_ArecDataBS.sArecBrWrp.chAbnNum[0];
	sLV.lLastIdxNum = sLV.lSecondStart;
	//```if(sLV.lSecondSize>3)
	//```sLV.lLastIdxNum = sLV.lSecondSize - 3;
	//```else
	//sLV.lLastIdxNum = 0;
	j = 1;
	for(i = sLV.lLastIdxNum; i<sLV.lSecondSize ; i++) 
	{
		//*((char*)pvL+(i*sizeof(ARecDataDsc))) |= 0x80;//Mark as Bad Numerator
		//
		memcpy((void*)&unnV1.ulVal,(const void*)( (char*)pvL+(i*sizeof(ARecDataDsc)) ),4 );
		if (i==sLV.lLastIdxNum)
		{
			sLV.lDeltaAbsNumertrs = unnV1.ulVal;
			rlVal = unnV1.ulVal;
		}	
		if(unnV1.uchAr [3]&0x80)
		{
			sLV.lNeedReceive++;//Fix Potential Error
			unnV1.uchAr [3]&=0x7f;
		}
		j += unnV1.ulVal- rlVal;
		rlVal = unnV1.ulVal;
	}
	lCsSecondSize = j;
	i = j+ lCsFirstSize;
	ulCs = 1+i;
 }
 else
 {
	 ;//Non Classical Variant
	 pvL = (void*)&arArecDataBS[0].UN_ArecDataBS.sArecBrWrp.chAbnNum[0];
 unnV1.ulVal = 0;
	memcpy((void*)&sLV.l2AbsNumertrs,(const void*)(  pvL ),4 );
	i = sLV.l2AbsNumertrs;
	rlVal = i;
	j = i = 0;
	sLV.lNeedReceive = 0;
	while ((unnV1.ulVal< 0x7fffffff) &&(i< AMOUNT_RECORDS_ANALOG_WITH_CMD))
	{
		
		memcpy((void*)&unnV1.ulVal,(const void*)((char*) pvL+(i*sizeof(ARecDataDsc)) ),4 );
		if(unnV1.uchAr [3]&0x80)
		{
			sLV.lNeedReceive++;//Fix Potential Error
			unnV1.uchAr [3]&=0x7f;
		}
		j += unnV1.ulVal- rlVal;
		rlVal = unnV1.ulVal;
		i++;
	
	}
	sLV.l2AbsNumertrs = j;
	
	 memcpy((void*)&unnV1.ulVal,(const void*)((char*) pvL+(i*sizeof(ARecDataDsc)) ),4 );
	
	if(unnV1.ulVal==0x7fffffff)
	{
		j++;
	
	}
		i++;
	 pvL = (void*)&arArecDataBS[AMOUNT_RECORDS_ANALOG_WITH_CMD-1].UN_ArecDataBS.sArecBrWrp.chAbnNum[0];
 
	memcpy((void*)&sLV.l1AbsNumertrs,(const void*)(  pvL ),4 );	
	unnV1.ulVal = 0;
	while ((unnV1.ulVal< (unsigned long)sLV.l1AbsNumertrs) &&(i< AMOUNT_RECORDS_ANALOG_WITH_CMD))
	{
		
		memcpy((void*)&unnV1.ulVal,(const void*)((char*) pvL+(i*sizeof(ARecDataDsc)) ),4 );
		if(unnV1.uchAr [3]&0x80)
		{
			sLV.lNeedReceive++;//Fix Potential Error
			unnV1.uchAr [3]&=0x7f;
		}
		j += unnV1.ulVal- rlVal;
		rlVal = unnV1.ulVal;
		i++;
	
	}
	//Look Check Sum & sLV.lNeedReceive
	
	
	
 }
 
 
 
 

					
}

long UpdateRVARecMainDataBsTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
//struct 
//	{
//		char chDetect_arAbsNumersIdxBufBs;
//		char chNeedClrSesData;
//		void *pOriginLDC;
//		long lTrSize;
//	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	

//sLV.pOriginLDC = pvLDC;
//sLV.chDetect_arAbsNumersIdxBufBs = 0;
////RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
// sLV.chNeedClrSesData = 0;

unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
if (unnV1.uchAr[0]== 0)
{
	
	lID = (long) (((LDCIDsc*)pvLDC)-> pSrc);
	pv = (void*)(lID-4);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	//sLV. lTrSize = lID;
	//pvLDC = (void*)i;

 ExtractUrgentDataBr2Bs(pv);

}
return  lID;

}





/* EOF */
