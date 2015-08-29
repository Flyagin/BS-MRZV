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
* File Name       : atrcmd.c
* Description     : Functions and Data for Extract from Transport to Application
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  20/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "atrcmd.h"
AtrCmdHldDsc holderAtrCmd = {

{0,0,0,0}
};
// This Obj Use for Transmittion
 AtrCmdHldDsc holderAtrCmdIciCopy = {

{0,0,0,0}
};

AtrCmdWrpDsc  hldAtrCmdWrp = {

#ifdef __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__
(SIZE_ATR_CMD ),	(void*)	&holderAtrCmd.UNAtrCmd.chArAtrCmd[0],		
#endif
#ifndef __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__
0,	(void*)	0,
#endif
{0,0,0,0}

};


int AppReqTransmitAtrCmd;
//int AppReqReceiveAtrCmd ; //


void ActivateServTrApCnAtrCmdCTpuUnitSpi(void)
{
//register long i,j;
//register char *pch;
register void* pv;
pv = hldAtrCmdWrp.p_AtrCmd;
	if(AppReqTransmitAtrCmd==EXEC)
	{
		
		//
		//
		hldAtrCmdWrp.statistics.lErrors++;
		hldAtrCmdWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldAtrCmdWrp.size_AtrCmd = 0;
//Copy
//hldApcsWrp.UNApcs.lArApcs[0] = 0;//meas_protection;
holderAtrCmdIciCopy.UNAtrCmd = holderAtrCmd.UNAtrCmd;
hldAtrCmdWrp.size_AtrCmd     = SIZE_ATR_CMD;

  //pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
  //pv  = (void*)& holderSrcSamplesUnit;
  //j = sizeof(SrcSamplesUnitDsc);
  //for (i = 0; i < j; i++)
  //{
  //  pch[i] = ((char*)pv)[i];
  //}
  //Reset Connect State
   pv  = (void*)& (holderTRAtrCmdSOCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_ATR_CMD_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = hldAtrCmdWrp.size_AtrCmd;//sizeof(SrcSamplesUnitDsc);
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_ATR_CMD_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderAtrCmdIciCopy.UNAtrCmd.chArAtrCmd[0]; //holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnAtrCmd(void)
{
//register void *pv;
//register long i;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalGoodChange++;
   //(( Dsc*)(hldApcsWrp.p_Apcs))->statistics.lTotalChange++;
   hldAtrCmdWrp.statistics.lTotalGoodChange++;
   hldAtrCmdWrp.statistics.lTotalChange++;
   
}
//PrepDecompouseTotMeasGUnitHSU2();

void PrepDecompouseAtrCmdUnitSpi(void)
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
	if(AppReqTransmitAtrCmd)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_ATR_CMD;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (AppReqTransmitAtrCmd==START)
			{
				ActivateServTrApCnAtrCmdCTpuUnitSpi();
				AppReqTransmitAtrCmd = EXEC;
			}
			//ProcessTransmit Obj
			if(AppReqTransmitAtrCmd==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRAtrCmdSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					AppReqTransmitAtrCmd = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (AppReqTransmitAtrCmd==TERM)
				{
					TerminateServiceApCnAtrCmd();
					AppReqTransmitAtrCmd = 0;
				}
			}
		}
		//Try another???
		
	}
	

}







/* EOF */

