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
* File Name       : GoosB.c
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

#include    "GoosB.h"
GoosBHldDsc holderGoosB = {
 {"GoosB Message from HS Processor"}
//{0,0,0,0}
};

GoosBHldDsc holderGoosBIciCopy = {

{0,0,0,0}
};


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

GoosBWrpDsc hldGoosBWrp = {

#ifdef __TYPE_DEFINITION__
sizeof(SIZE_GOOS_B ),	(void*)	&holderGoosB.UNGoosB.lArGoosB[0],		
#endif
#ifndef __TYPE_DEFINITION__
0,	(void*)	0,
#endif
{0,0,0,0}

};

int AppReqTransmitGoosB;
int AppReqReceiveGoosB ; //int AppReqReceiveTotMeasG;

void ActivateServTrApCnGoosBCTpuUnitSpi(void)  @ "Fast_function"
{
register long i;//,j;
//register char *pch;
register void* pv;
pv = hldGoosBWrp.p_GoosB;
	if(AppReqTransmitGoosB==EXEC)
	{
		
		//((Dsc*)(hldGoosBWrp.p_GoosB))->statistics.lErrors++;
		//((Dsc*)(hldGoosBWrp.p_GoosB))->statistics.lTotalBadChange++;//In This ver try to start work with Wrapers Obj 
		hldGoosBWrp.statistics.lErrors++;
		hldGoosBWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldGoosBWrp.size_GoosB = 0;
//Copy
//hldGoosBWrp.UNGoosB.lArGoosB[0] = 0;//meas_protection;
holderGoosBIciCopy.UNGoosB = holderGoosB.UNGoosB;
hldGoosBWrp.size_GoosB = SIZE_GOOS_B;
//Calc CheckSum
	i = CalcGoosBHldCs((void*)&holderGoosBIciCopy);
	//Set up if need another field BigObjCMUnitDsc
  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRGoosBSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_GOOS_B_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldGoosBWrp.size_GoosB + sizeof(BigObjCMUnitDsc);//hldGoosBWrp.size_GoosB;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_GOOS_B_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderGoosBIciCopy.UNGoosB.lArGoosB[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnGoosB(void)  @ "Fast_function"
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldGoosBWrp.p_GoosB))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldGoosBWrp.p_GoosB))->statistics.lTotalChange++;
   hldGoosBWrp.statistics.lTotalGoodChange++;
   hldGoosBWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseGoosBUnitSpi(void)  @ "Fast_function"
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
	if(AppReqTransmitGoosB)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4;//SIZE_TPDU_TOT_MEASG_CNL_HSU2;
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitGoosB==START)
			{
				ActivateServTrApCnGoosBCTpuUnitSpi();
				AppReqTransmitGoosB = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitGoosB==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRGoosBSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitGoosB = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitGoosB==TERM)
				{
					TerminateServiceApCnGoosB();
					AppReqTransmitGoosB = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

long UpdateRVGoosBCTpuUnit(void* pvLDC, long lID)  @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
struct 
	{
		char chNeedClrSesData;
		short shSizeAppObj;
		void *pOriginLDC;
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	
//RVBaseCTpuUnitDsc locRVBaseCTpuUnit;
sLV.pOriginLDC = pvLDC;
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;unnV1.ulVal = 0;
 sLV.shSizeAppObj = SIZE_GOOS_B + sizeof(BigObjCMUnitDsc);

 
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVGoosBSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_TPDU_GOOS_B_CNL_SPI))//SIZE_GOOS_B
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_GOOS_B);//SIZE_GOOS_B - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	
	pvLDC = (void*)i;
	i = (long)holderRVGoosBSOCTpuUnit.RvCnHldr.pUchRV;
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
	AppReqReceiveGoosB++;
	
	
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
	pv  = (void*)&holderRVGoosBSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVGoosBSOCTpuUnit
		//(unsigned char*)&holderRVTotMeasCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(sLV.shSizeAppObj))//SIZE_GOOS_B))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (sLV.shSizeAppObj) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVGoosBSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVGoosBSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(sLV.shSizeAppObj)) //SIZE_GOOS_B))
			{
				 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((GoosBHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((GoosBHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//CHeck CheckSum
				i = CheckGoosBHldCs(pvLDC);
				//Sucess Terminate Session
				if ( (lID == (long)(sLV.shSizeAppObj))&&i)//SIZE_GOOS_B))
				{
					//Activate App Func
					AppReqReceiveGoosB++;
					i = ((GoosBHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((GoosBHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((GoosBHldDsc*)pvLDC)-> statistics.lErrors;i++;
						((GoosBHldDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((GoosBHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((GoosBHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((GoosBHldDsc*)pvLDC)-> statistics.lErrors;i++;
			((GoosBHldDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((GoosBHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((GoosBHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((GoosBHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((GoosBHldDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVGoosBSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}

long CheckGoosBHldCs( void* pGoosBHldDsc)  @ "Fast_function" //void*)&holderGoosBIciCopy);
{
register long i;
//struct 
//	{
//		char chN;
//		short shSizeAppObj;
//		void *pOriginLDC;
//		lCsAppObj;
//	} sLV;
	

i = Eval_CS( (char*)&(((GoosBHldDsc*)pGoosBHldDsc)->UNGoosB.lArGoosB[0]), SIZE_GOOS_B  );

	if (i !=
			( ((GoosBHldDsc*)pGoosBHldDsc)->hldGoosBObjConMode.lCsAppObj )
		)
		i = 0;

return i;
}
long CalcGoosBHldCs( void* pGoosBHldDsc)  @ "Fast_function" //void*)&holderGoosBIciCopy);
{
register long i;

i = Eval_CS( (char*)&(((GoosBHldDsc*)pGoosBHldDsc)->UNGoosB.lArGoosB[0]), SIZE_GOOS_B  );

	if (i != 0
			
		)
		( ((GoosBHldDsc*)pGoosBHldDsc)->hldGoosBObjConMode.lCsAppObj ) = i;// = 0;

return i;

}
unsigned char chGoosB_Data_Rdy = 0;
long lCtrSuccRvPack = 0;
long lTresholdSuccRvPack = 0x300;

 long GoosB_Rdy_Handler   (void* pv)  @ "Fast_function"
 {
	AppReqTransmitGoosB++;
	return 0;
 }
 void GossBRvPackActivator(void)  @ "Fast_function"
 {
	if (lCtrSuccRvPack >= lTresholdSuccRvPack)
	{
		lCtrSuccRvPack = 0;
		chGoosB_Data_Rdy++;
	}	
	else
		lCtrSuccRvPack++;
		
	if(chGoosB_Data_Rdy)
	{
		GoosB_Rdy_Handler((void*)&holderGoosB);
		chGoosB_Data_Rdy = 0; 
	}	
	
 }
 


