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
* File Name       : dt_tm.c
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

#include    "dt_tm.h"
DateTimeHldDsc holderDateTime = {

{0,0,0,0}
};
// This Obj Use for Transmittion
 DateTimeHldDsc holderDateTimeIciCopy = {

{0,0,0,0}
};

DateTimeWrpDsc  hldDateTimeWrp = {

#ifdef __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__
(SIZE_DATE_TIME ),	(void*)	&holderDateTime.UNDateTime.chArDateTime[0],		
#endif
#ifndef __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__
0,	(void*)	0,
#endif
{0,0,0,0}

};

#pragma default_function_attributes = @ "Fast_function"  
int AppReqTransmitDateTime;
//int AppReqReceiveDateTime ; //


void ActivateServTrApCnDateTimeCTpuUnitSpi(void)
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldDateTimeWrp.p_DateTime;
	if(AppReqTransmitDateTime==EXEC)
	{
		
		//
		//
		hldDateTimeWrp.statistics.lErrors++;
		hldDateTimeWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldDateTimeWrp.size_DateTime = 0;
//Copy
//hldApcsWrp.UNApcs.lArApcs[0] = 0;//meas_protection;
holderDateTimeIciCopy.UNDateTime = holderDateTime.UNDateTime;
hldDateTimeWrp.size_DateTime     = SIZE_DATE_TIME;

  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRDateTimeSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_DATE_TIME_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldDateTimeWrp.size_DateTime;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_DATE_TIME_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderDateTimeIciCopy.UNDateTime.chArDateTime[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnDateTime(void)
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalChange++;
   hldDateTimeWrp.statistics.lTotalGoodChange++;
   hldDateTimeWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseDateTimeUnitSpi(void)
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
	if(AppReqTransmitDateTime)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_DATE_TIME;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitDateTime==START)
			{
				ActivateServTrApCnDateTimeCTpuUnitSpi();
				AppReqTransmitDateTime = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitDateTime==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRDateTimeSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitDateTime = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitDateTime==TERM)
				{
					TerminateServiceApCnDateTime();
					AppReqTransmitDateTime = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


#pragma default_function_attributes = 




/* EOF */

