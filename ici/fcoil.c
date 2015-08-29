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
* File Name       : fcoil.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  20/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "fcoil.h"
FCoilHldDsc holderFCoil = {

{0,0,0,0}
};
// This Obj Use for Transmittion
 FCoilHldDsc holderFCoilIciCopy = {

{0,0,0,0}
};

FCoilWrpDsc  hldFCoilWrp = {

#ifdef __TYPE_DEFINITION_FCOIL_BS_TO_BR__
(SIZE_FCOIL ),	(void*)	&holderFCoil.UNFCoil.chArFCoil[0],		
#endif
#ifndef __TYPE_DEFINITION_FCOIL_BS_TO_BR__
0,	(void*)	0,
#endif
{0,0,0,0}

};


int AppReqTransmitFCoil;
//int AppReqReceiveFCoil ; //


void ActivateServTrApCnFCoilCTpuUnitSpi(void)
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldFCoilWrp.p_FCoil;
	if(AppReqTransmitFCoil==EXEC)
	{
		
		//
		//
		hldFCoilWrp.statistics.lErrors++;
		hldFCoilWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldFCoilWrp.size_FCoil = 0;
//Copy
//hldApcsWrp.UNApcs.lArApcs[0] = 0;//meas_protection;
holderFCoilIciCopy.UNFCoil = holderFCoil.UNFCoil;
hldFCoilWrp.size_FCoil     = SIZE_FCOIL;

  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRFCoilSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_FCOIL_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldFCoilWrp.size_FCoil;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_FCOIL_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderFCoilIciCopy.UNFCoil.chArFCoil[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnFCoil(void)
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalChange++;
   hldFCoilWrp.statistics.lTotalGoodChange++;
   hldFCoilWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseFCoilUnitSpi(void)
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
	if(AppReqTransmitFCoil)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_FCOIL;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitFCoil==START)
			{
				ActivateServTrApCnFCoilCTpuUnitSpi();
				AppReqTransmitFCoil = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitFCoil==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRFCoilSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitFCoil = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitFCoil==TERM)
				{
					TerminateServiceApCnFCoil();
					AppReqTransmitFCoil = 0;
				}
			}
		}
		//Try another???
		
	}
	

}







/* EOF */

