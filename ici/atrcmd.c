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

#pragma default_function_attributes = @ "Fast_function"  
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


//////////////////////////////////////////////////////////////////////////////////////////
//========================================================================================
//````````````````````````````````````````````````````````````````````````````````````````
//    Secure with Ack Exchange                                      
//........................................................................................
//========================================================================================
//////////////////////////////////////////////////////////////////////////////////////////



/*
Transmit Obj 
Have           Pointer_Data & size_of_Data & potental sizeof_cutting
Possible       & maximum amount_of_Phases & maximum amtStep_per_Phases

Need struct_of_jornal
1)Order number - Order Number Iteration
2)Counter current elementary step <<-- It means step can`t be repeated more then 3 times 
3)Ord_Num_of_Step_Transmit/Ord_Num_of_Step_Receive
4)Info_Transmit/Info_Receive

*/
 /*
//////////////////////////////////////////////////////////////////////////////////////////
//========================================================================================
//````````````````````````````````````````````````````````````````````````````````````````
// Start Exec Point                                          
//........................................................................................
//========================================================================================

void PrepDecompouseAtrCmdUnitSpiSecure(void)
{
	
	//ExecSafeConnector((void*)&hldrConState);

	ExecIteration((void*)&hldrConState);
//	if(hldrConState.shExecConState&2)
//	PrepDecompouseStableAtrCmdUnitSpi();
}
//-----------------------------------------------------------------------------

long  ControlState(void* pvConState)    @  "Fast_function"//@ "Fastest_function"
{
   
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;

//		PFL_VL pfl_vl;
	} sLV;

	sLV.uChIdxBit = i = 0;
	
	
	
	//i = ((BaseAcpuCMUnitDsc*)pvProxy)-> AppObjConState;
	i = ((SecureExecStateDsc*)pvConState)-> shExecConState;
	
	j = (i&(USING_OCS_MSK)); 
	if (j==0) return 0 ;
	
	j = ((i&STT_WORK_OCS_MSK)== 0 )&& (i&(STT_START_OCS_MSK));
	j = (i&(STT_WORK_OCS_MSK));
	j = (i&(STT_START_OCS_MSK));
	if (j)
	{
		sLV.uChIdxBit =  STT_START_OCS_ONB;
		//Init Point
	}	
	j =  (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);
	if (j)
	{
		sLV.uChIdxBit =  STT_WORK_OCS_ONB;
		//Exec Point
		ExecIteration(pvConState);
		i = ((SecureExecStateDsc*)pvConState)-> lOrderNumIteration;
		i++;
		if(i<(((SecureExecStateDsc*)pvConState)->ushAmtIteration) )
		((SecureExecStateDsc*)pvConState)-> lOrderNumIteration = i;

	}
	j = (i&(STT_STOP_OCS_MSK));
	if (j)
	{
		sLV.uChIdxBit =  STT_STOP_OCS_ONB;
		//Terminate Point
	}
	
//	if(sLV.uChIdxBit)
//	{
//	    i = (long)((BaseAcpuCMUnitDsc*)pvProxy)-> pf_Work;
//		if(i)
//		{
//			sLV.pfl_vl = (PFL_VL)i;
//			i = sLV.pfl_vl(pvProxy,sLV.uChIdxBit);//sLV.IdConObj);Mow Only One Cmd
//			lCtrAmtExecProxy++;
//		}	
//	}
//	else
//	{
//		i = 0;
//	}
	


	
return i;


}

//-----------------------------------------------------------------------------

long  ExecIteration(void* pv)    @  "Fast_function"//@ "Fastest_function"
{
register long i;
//Check Phase 
//Check Step 
register long lV;//Is really need Check Phase & Step  
i = ((SecureExecStateDsc*)pv)-> lOrderNumIteration;
	switch (lV)//Detect posibility ;//	 pch[0] = i;
 	{

		case  0:  
		case  1://Init Part
		
		break;
		
		case 2:
		case TRANSMIT_PART:
			BaseTransmitOperation(pv);
			if( ((SecureExecStateDsc*)pv)-> shExecConState&2 )
			 PrepDecompouseStableAtrCmdUnitSpi();//Put Packet in Queue
		break;
		
		
		case TERMINATE_PART:
			;
		break;
		
				

 	default:
	;
	}
	
RetStateExecIteration:

	return  i;

}
ReliableCmnDsc hldReliableCmnAtrcmd;

void BaseTransmitOperation(void* pv)    @  "Fast_function"//
{
register long lV;
//	struct 
//	{
//		short  shVl;
//		char   chRes;
//		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
//		//PFL_VL pfl_vl;
//		//void *pvPrMng,*pvCmmMsg;
//	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	
	UNNlV.ulVal = 0; sLV.shVl = 0;lV = sLV.chRes = 0;
	
//Dec Life Counter
//Control Self LifeTimer
UNNlV.ulVal = (((SecureExecStateDsc*)pv)->ulLifeCtrEct);
	if (UNNlV.ulVal != 0)
	{
		if(UNNlV.uchAr[3] < 0xff)
		UNNlV.ulVal--;//Ok Can Wait
		(((SecureExecStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
	}
	else
	{
		;//Time Out
		//Check Counter current elementary step
		lV = ((SecureExecStateDsc*)pv)->lCtrCes;
		if(lV == 0) 
		{
			//Put Info in Log
			;//
			return 0;//Error ->Out of Possiblity
		}
		else
		{
			lV--;
			((SecureExecStateDsc*)pv)->lCtrCes = lV;
			//Repeat Iteration
			;
			//Repeat Retransmit Fragment
			//	RepeatTrFrame(lV);
			goto ChangeIteration;
		}
	}
	
	//Check then Previous Pack Decomposing(ReqTransmitStngPrTpt==0)&&//TestReqTransmit ==0 //Out From Queue Ses Leyer
	UNNlV.uchAr[3] = ((SecureExecStateDsc*)pv)-> shExecConState&2;//Decompose Call
	
	//Check data Out from Phys -- Transmition through Phys chanel
	//Check Ack State
	UNNlV.uchAr[2] = UNNlV.uchAr[3]&&(hldReliableCmnAtrcmd.chStateReciveStngAck&1);
	//&&(hldReliableCmnAtrcmd.chTerminateSes==0);//Ses terminate success
	if(UNNlV.uchAr[2])//-ok
	{
		lV = ((SecureExecStateDsc*)pv)->ushTrCount;
		if((unsigned long)lV >= ( ((SecureExecStateDsc*)pv)->ushTrTotal ) )	{
		
			goto ChangeIteration;//May be Next Iteration
		}
		else{
			UNNlV.ushAr [0] = holderTRAtrCmdSOCTpuUnit.TrCnHldr.SizeAppObj;
			if(UNNlV.ushAr [0]>3)
			UNNlV.ushAr [0] -= 3;
			lV += UNNlV.ushAr [0];
			((SecureExecStateDsc*)pv)->ushTrCount = lV;
			if((unsigned long)lV >= ( ((SecureExecStateDsc*)pv)->ushTrTotal ) )
			goto ChangeIteration;//
		}
	
	}
	else
	return ((SecureExecStateDsc*)pv)-> lOrderNumIteration;//Wait Answer on Current Iteration
	if(hldReliableCmnAtrcmd.chStateReciveStngAck&1){//ReciveStngAckGood
		hldReliableCmnAtrcmd.TrFrgAtrCmd.IdTRFrgCmd =  ID_TPT_CMD_TR_FRAGMENT;
		//Activate `True` Ses Part
		((SecureExecStateDsc*)pv)-> shExecConState |= 2;
		//hldrTpCnState.uchTpState_CNL_HSU2  = 1;//Select Channel
		hldReliableCmnAtrcmd.lAtrCmdOrderNumTrFragment++;
		hldReliableCmnAtrcmd.chStateReciveStngAck = 0;
		(((SecureExecStateDsc*)pv)->ulLifeCtrEct) = ((SecureExecStateDsc*)pv)->ushDefaultTimeOutVal;
		
	}
ChangeIteration:	
	//Change Iteration
	lV = ((SecureExecStateDsc*)pv)-> lOrderNumIteration;
	lV++;
	if(lV<(((SecureExecStateDsc*)pv)->ushAmtIteration) )
	((SecureExecStateDsc*)pv)-> lOrderNumIteration = lV;
		
	return lV;//Normal Execution;
}
void PrepDecompouseStableAtrCmdUnitSpi(void)
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

*/









#pragma default_function_attributes = 




/* EOF */

