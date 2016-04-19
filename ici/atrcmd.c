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
// /*
//////////////////////////////////////////////////////////////////////////////////////////
//========================================================================================
//````````````````````````````````````````````````````````````````````````````````````````
// Start Exec Point                                          
//........................................................................................
//========================================================================================

void PrepDecompouseAtrCmdUnitSpiSecure(void)   @  "Fast_function"
{
	
	//ExecSafeConnector((void*)&hldrConState);
	
	ExecIteration((void*)&hldrConState);
//	if(hldrConState.shExecConState&2)
//	PrepDecompouseStableAtrCmdUnitSpi();
}
//-----------------------------------------------------------------------------
static char chAppReqTransmitAtrCmd;

SecureExecStateDsc hldrConState = {
0,// shExecConState
 0,0,0,0,
 0x30,
0,0,0,0,
0,0,//RV,TR Base
2,22,0x2000,0x30 
};
long  ControlState(void* pvConState)    @  "Fast_function"//@ "Fastest_function"
{
   
	register long i,j;
	struct 
	{
		unsigned char uChIdxBit ;

		PFL_VL pfl_vl;
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

void  ExecIteration(void* pv)    @  "Fast_function"//@ "Fastest_function"
{
//	register long i;
	register long lV;//
	struct 
		{
			char chIterationCange;
			char chPhasechange,	chStepChange, chSaveRec;		
		}sLCodeSelector;
	union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;	
//Check Phase 
//Check Step 
	if( ((((SecureExecStateDsc*)pv)-> shExecConState)&1) == 0)
	return;
	
	sLCodeSelector.chIterationCange = sLCodeSelector.chPhasechange =
	sLCodeSelector.chStepChange = sLCodeSelector.chSaveRec = 0;
	//i = ((SecureExecStateDsc*)pv)-> lOrderNumIteration;
	lV = ((SecureExecStateDsc*)pv)-> lIdxStepExec;
	if( (lV>1) && (lV< TERMINATE_PART))
	lV = 2;
	switch (lV)//Detect posibility ;//	 pch[0] = i;
 	{

		case  0:  
		chAppReqTransmitAtrCmd =1;
		PrepDecompouseStableAtrCmdUnitSpi();//Start Transmittion
		case  1://Init Part
		//Check State
		//UNNlV.ulVal = ((SecureExecStateDsc*)pv)->ushEvtField;
		//if()
		sLCodeSelector.chIterationCange = 1;
		sLCodeSelector.chStepChange = 1;
		break;
		
		case 2:
		case TRANSMIT_PART:
			BaseTransmitOperation(pv);
			UNNlV.ulVal = ((SecureExecStateDsc*)pv)->ushEvtField;
			//Chech Return
			switch(UNNlV.uchAr[1])
			{
				case 0://Time Out// Should Stop 
				((SecureExecStateDsc*)pv)-> lIdxStepExec = TERMINATE_PART;
				break;
				case 1://Wait Answer
				sLCodeSelector.chIterationCange = 1;//sLCodeSelector.chStepChange = 0;
				
				break;
				default:
				sLCodeSelector.chIterationCange = 1;
				sLCodeSelector.chStepChange = 1;
			}
			if( ((SecureExecStateDsc*)pv)-> shExecConState&2 )
			 PrepDecompouseStableAtrCmdUnitSpi();//Put Packet in Queue
			 
		break;
		
		
		case TERMINATE_PART:
			((SecureExecStateDsc*)pv)->shExecConState = 0;AppReqTransmitAtrCmd = 0;
		break;
		
				

 	default:
	;
	}
//	
//ExitStateExecIteration:
//Ceck Iteration
//Check Phase&Step
	if(sLCodeSelector.chStepChange == 1){
		lV = ((SecureExecStateDsc*)pv)-> lIdxStepExec;
		lV++;
		if(lV<(((SecureExecStateDsc*)pv)->ushAmtStep) )
		((SecureExecStateDsc*)pv)-> lIdxStepExec = lV;
		else{
		//Activate Terminate Part
		}
	}
//ChangeIteration:	
	if(sLCodeSelector.chIterationCange == 1){
		//Control Iteration
		lV = ((SecureExecStateDsc*)pv)-> lOrderNumIteration;
		lV++;
		if(lV<(((SecureExecStateDsc*)pv)->ushAmtIteration) )
		((SecureExecStateDsc*)pv)-> lOrderNumIteration = lV;
		else{
			//Activate Terminate Part
		}
	}




}
//Confirmation
//acknowledgment
//reaffirmation
//affirmation



ReliableCmnDsc hldReliableCmnAtrcmd = {
{0,0,0,(char *)0,(char*)0},
0,
0,0,0,0,
0,
{0,0,0,(char *)0,(char*)0}
};

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
	
	UNNlV.ulVal = 0;
	
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
			((SecureExecStateDsc*)pv)->ushEvtField &= 0xff;//Ret 0
			((SecureExecStateDsc*)pv)->ushEvtField |= 1;//Error TimeOut
			return;//Error ->Out of Possiblity
		}
		else
		{
			lV--;
			((SecureExecStateDsc*)pv)->lCtrCes = lV;
			//Repeat Iteration
			;
			//Repeat Retransmit Fragment
			//	RepeatTrFrame(lV);
			((SecureExecStateDsc*)pv)->ushEvtField &= 0xff;
			((SecureExecStateDsc*)pv)->ushEvtField |= 1<<8;//Wait
			return;//goto ChangeIteration;
		}
	}
	
	//Check then Previous Pack Decomposing(ReqTransmitStngPrTpt==0)&&//TestReqTransmit ==0 //Out From Queue Ses Leyer
	UNNlV.uchAr[3] = ((SecureExecStateDsc*)pv)-> shExecConState&2;//Decompose Call
	
	//Check data Out from Phys -- Transmition through Phys chanel
	//Check Ack State
	UNNlV.uchAr[2] = (hldReliableCmnAtrcmd.chStateReciveStngAck&1);//UNNlV.uchAr[3]&&
	//UNNlV.uchAr[1] = (hldReliableCmnAtrcmd.chStateReciveStngAck == 0) && 
	//(((SecureExecStateDsc*)pv)-> lIdxStepExec == 2);
	//&&(hldReliableCmnAtrcmd.chTerminateSes==0);//Ses terminate success
	if(UNNlV.uchAr[2])//-ok
	{
		lV = ((SecureExecStateDsc*)pv)->ushTrCount;
		if((unsigned long)lV >= ( ((SecureExecStateDsc*)pv)->ushTrTotal ) )	{
		
			((SecureExecStateDsc*)pv)->ushEvtField &= 0xff;
			//((SecureExecStateDsc*)pv)->ushEvtField |= ;//(TERMINATE_PART)<<8;Fix End
			goto ExitBaseTransmitOperation;
		}
		else{
			UNNlV.ushAr [0] = holderTRAtrCmdSOCTpuUnit.TrCnHldr.SizeAppObj;
			if(UNNlV.ushAr [0]>3)
			UNNlV.ushAr [0] -= 3;
			lV += UNNlV.ushAr [0];
			((SecureExecStateDsc*)pv)->ushTrCount = lV;
			if((unsigned long)lV >= ( ((SecureExecStateDsc*)pv)->ushTrTotal ) ){
				((SecureExecStateDsc*)pv)->ushEvtField = (1<<8)|0xff;//Success Field
				((SecureExecStateDsc*)pv)->pUchRV = ((SecureExecStateDsc*)pv)->pUchTR;//<-Mean Succesful Termination
				goto ExitBaseTransmitOperation;//Preterminate Loop
			}
		}
	
	}
	else{
		//return ((SecureExecStateDsc*)pv)-> lOrderNumIteration;//Wait Answer on Current Iteration
		((SecureExecStateDsc*)pv)->ushEvtField &= 0xff;//Wait
		((SecureExecStateDsc*)pv)->ushEvtField |= 1<<8;//The work of the lower-layer protocols
		goto ExitBaseTransmitOperation;// --   Here you Wait Answer from HR Step should Not change
	}	
	if(hldReliableCmnAtrcmd.chStateReciveStngAck&1){//ReciveStngAckGood
		hldReliableCmnAtrcmd.TrFrgAtrCmd.IdTRFrgCmd =  ID_TPT_CMD_TR_FRAGMENT;
		//Activate `True` Ses Part
		((SecureExecStateDsc*)pv)-> shExecConState |= 2;
		//hldrTpCnState.uchTpState_CNL_HSU2  = 1;//Select Channel
		hldReliableCmnAtrcmd.lAtrCmdOrderNumTrFragment++;
		hldReliableCmnAtrcmd.chStateReciveStngAck = 0;
		(((SecureExecStateDsc*)pv)->ulLifeCtrEct) = ((SecureExecStateDsc*)pv)->ushDefaultTimeOutVal;
		
	}
//SetNormalExitBaseTransmitOperation:
	((SecureExecStateDsc*)pv)->ushEvtField &= 0xff;
	((SecureExecStateDsc*)pv)->ushEvtField |= (((SecureExecStateDsc*)pv)-> lIdxStepExec)<<8;//
	
ExitBaseTransmitOperation:		
	return;// lV;//Normal Execution;
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
	if(chAppReqTransmitAtrCmd)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = 4+SIZE_ATR_CMD;//
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (chAppReqTransmitAtrCmd==START)
			{
				ActivateServTrApCnStableAtrCmdCTpuUnitSpi();
				chAppReqTransmitAtrCmd = EXEC;
			}
			//ProcessTransmit Obj
			if(chAppReqTransmitAtrCmd==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRAtrCmdSOCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					chAppReqTransmitAtrCmd = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<5))//channel Full
				{
					
				}

				if (chAppReqTransmitAtrCmd==TERM)
				{
					TerminateServiceApCnStableAtrCmd();
					chAppReqTransmitAtrCmd = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


void ActivateServTrApCnStableAtrCmdCTpuUnitSpi(void)
{
register long i,j;
register char *pch;
register void* pv;
	union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//
		unsigned long   ulVal;
		void* pv;
	}UNNlV;
/*
pv = hldAtrCmdWrp.p_AtrCmd;
	if(chAppReqTransmitAtrCmd==EXEC)
	{
		
		//
		//
		hldAtrCmdWrp.statistics.lErrors++;
		hldAtrCmdWrp.statistics.lTotalBadChange++;
		
		//,!! Reinit Transmittion???
	}
	hldAtrCmdWrp.size_AtrCmd = 0;
//Copy

holderAtrCmdIciCopy.UNAtrCmd = holderAtrCmd.UNAtrCmd;
hldAtrCmdWrp.size_AtrCmd     = SIZE_ATR_CMD;
*/
	pv  = (void*)& hldrConState;
	pch = (char *)((SecureExecStateDsc*)pv)->pUchTR;
	i = ((SecureExecStateDsc*)pv)-> ushTrCount;
	j = ((SecureExecStateDsc*)pv)-> ushTrTotal;
	j -= i;
	pch += i;//Addr Of Transmition
	UNNlV.pv = (void*)pch;
	pch  = (char*)& hldReliableCmnAtrcmd;
	((ReliableCmnDsc*)pch)-> TrFrgAtrCmd.pSrc = UNNlV.pv;
	((ReliableCmnDsc*)pch)-> TrFrgAtrCmd.pDst = (char*)&(holderTRAtrCmdSOCTpuUnit.arUchTR[0]);
	
  //Reset Connect State
    pv  = (void*)& (holderTRAtrCmdSOCTpuUnit.TrCnHldr);
   
    ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
    ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   
    if( (j+3) > SIZE_TPDU_ATR_CMD_CNL_SPI   ){
		j = SIZE_TPDU_ATR_CMD_CNL_SPI - 2;
		j -= 3;//Hdr size sizeof(char) + sizeof(short);
    }
    else
	i++;//Debug Code for Logic Error Detection
	((ReliableCmnDsc*)pch)-> TrFrgAtrCmd.IdTRFrgCmd = ID_TPT_CMD_TR_FRAGMENT;
	((ReliableCmnDsc*)pch)-> TrFrgAtrCmd.uchTR_C = j;
	((ReliableCmnDsc*)pch)-> lAtrCmdOrderNumTrFragment = 
	((ReliableCmnDsc*)pch)-> lAtrCmdOrderNumTrFragment + 1;
	((ReliableCmnDsc*)pch)-> TrFrgAtrCmd.uShOrderNumFrg = 
	((ReliableCmnDsc*)pch)-> lAtrCmdOrderNumTrFragment;
	
	i = CreateTRFragment((void*)&(((ReliableCmnDsc*)pch)-> TrFrgAtrCmd));
   
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_ATR_CMD_CNL_SPI;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = i;
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_ATR_CMD_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = 
   (unsigned char*)((ReliableCmnDsc*)pch)-> TrFrgAtrCmd.pDst; 
   
}

void TerminateServiceApCnStableAtrCmd(void)
{
//register void *pv;
//register long i;

//   hldAtrCmdWrp.statistics.lTotalGoodChange++;
//   hldAtrCmdWrp.statistics.lTotalChange++;
	//Terminate Session Layer
	hldrConState.shExecConState &= ~2;
}

void RepeatTrFrameAtrCmd(long lV)  
{
	chAppReqTransmitAtrCmd =  START;
	hldReliableCmnAtrcmd.TrFrgAtrCmd.IdTRFrgCmd = ID_TPT_CMD_TR_FRAGMENT;
	//hldrTpCnState.uchTpState_CNL_HSU2  = 1;//Select Channel
	hldReliableCmnAtrcmd.chStateReciveStngAck = 0;
	hldrConState.ulLifeCtrEct = hldrConState.ushDefaultTimeOutVal>>(5 - lV);//May be Shift

}

long UpdateRvAtrCmd(void* pvLDC, long lID)
{
	register long i;
	register char *pSrc;
	void* pv;
	TRFrgDsc frg = {
	0,0,0,(char*)0,(char*)0
	};

	struct{
		//char chNeedActivateProxyTpt;
		char chNeedClrSesData;
		char chACKGood;
		void *pOriginLDC;
		long ReqReceiveFrg; 
	} sLV;
	union{
	  	unsigned char   uchAr [4];
	   	unsigned short  ushAr [2];
        unsigned long   ulVal;
	}unnV1;	

	//`````````````````````````````````````````````````````````````````````
	//``Init Ack control  part
	sLV.ReqReceiveFrg = sLV.chACKGood =   0; sLV.pOriginLDC = pvLDC;
    sLV.chNeedClrSesData = 0;
	//`` 
	//.....................................................................
   
	unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
	unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
	unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
	unnV1.uchAr[3] = 0;
	if (unnV1.uchAr[0]== 0){
		pv  = (void*)holderRVAtrCmdSOCTpuUnit.arUchRV;
		i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
		lID = ((LDCIDsc*)pvLDC)->uchTR_C;
		if( lID > (long)(SIZE_TPDU_ATR_CMD_CNL_SPI ))
		lID = (long)(SIZE_TPDU_ATR_CMD_CNL_SPI );
		pvLDC = (void*)i;
		//MoveData: 
		for (i = 0; i < lID; i++)
		{
		((char*)pv)[i] = ((char*)pvLDC)[i];
		}
		//Activate App For
		sLV.ReqReceiveFrg ++;//Activate Decoder Analise
		holderRVAtrCmdSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
		holderRVAtrCmdSOCTpuUnit.RvCnHldr.NumComSes        = 0;
		holderRVAtrCmdSOCTpuUnit.RvCnHldr.ConState         = 0;
	    holderRVAtrCmdSOCTpuUnit.RvCnHldr.ulRvCount        = lID;
	}
	else{
		//-Analize Sesion state Etc.
		pv  = (void*)&holderRVAtrCmdSOCTpuUnit.RvCnHldr;
		
		if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1){
			((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;
			((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&holderRVAtrCmdSOCTpuUnit.arUchRV; 
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
		}
		i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		sLV.chNeedClrSesData = 0;
		if ( i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) ){
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_TPDU_ATR_CMD_CNL_SPI -2))
				lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
				lID = (SIZE_TPDU_ATR_CMD_CNL_SPI -2) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			pvLDC = (void*)i;
			i = (long)holderRVAtrCmdSOCTpuUnit.arUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
				((char*)pv)[i] = ((char*)pvLDC)[i];
			pv  = (void*)&holderRVAtrCmdSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_TPDU_ATR_CMD_CNL_SPI-2 )){
				if (lID == (long)(SIZE_TPDU_ATR_CMD_CNL_SPI-2 )){
					//Activate App Func
					sLV.ReqReceiveFrg ++;//Activate Decoder Analise
					holderRVAtrCmdSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
					holderRVAtrCmdSOCTpuUnit.RvCnHldr.NumComSes        = 0;
					holderRVAtrCmdSOCTpuUnit.RvCnHldr.ConState         = 0;
					holderRVAtrCmdSOCTpuUnit.RvCnHldr.ulRvCount        = lID;
				}
				else{
					sLV.chNeedClrSesData++;
				}
			}

			
		}
		else//Error Sesion
				sLV.chNeedClrSesData++;
				
		if(sLV.chNeedClrSesData){
			holderRVAtrCmdSOCTpuUnit.RvCnHldr.uchUsedTransport = 0;
			holderRVAtrCmdSOCTpuUnit.RvCnHldr.NumComSes        = 0;
			holderRVAtrCmdSOCTpuUnit.RvCnHldr.ConState         = 0;
			holderRVAtrCmdSOCTpuUnit.RvCnHldr.ulRvCount        = lID;

		}
	
	}
	
	if(sLV.ReqReceiveFrg){
		//Primary analize ses frame
		pvLDC  = sLV.pOriginLDC;
		pv  = (void*)holderRVAtrCmdSOCTpuUnit.arUchRV;
		i =  frg.IdTRFrgCmd = ((char*)pv)[0];
		unnV1.uchAr[0] = ((char*)pv)[1];
		unnV1.uchAr[1] = ((char*)pv)[2];
		unnV1.uchAr[2] = ((char*)pv)[3];//Size Rv Data
		frg.uShOrderNumFrg =  unnV1.ushAr [0];// 
		pSrc = (char*)&hldReliableCmnAtrcmd;
		//Detect Ack Or Data
		switch (i ){
			case ID_TPT_CMD_ACK_RV_FRAGMENT:
				//Cmp OrderNumFrg & Size
				if( ((ReliableCmnDsc*)pSrc) ->TrFrgAtrCmd.uchTR_C == unnV1.uchAr[2] )
				sLV.chACKGood ++;
				if( ((ReliableCmnDsc*)pSrc)->TrFrgAtrCmd.uShOrderNumFrg == frg.uShOrderNumFrg)
				sLV.chACKGood ++;
				
				if( sLV.chACKGood >= 2)
				((ReliableCmnDsc*)pSrc)->chStateReciveStngAck = 1;
			break;
			case ID_TPT_CMD_TR_FRAGMENT:
				//holderRVAtrCmdSOCTpuUnit.RvCnHldr.ulRvCount -= 3;
				//((ReliableCmnDsc*)pSrc)->RvFrgAtrCmd.IdTRFrgCmd = i;
				//((ReliableCmnDsc*)pSrc)->RvFrgAtrCmd.uShOrderNumFrg =  frg.uShOrderNumFrg;
				//((ReliableCmnDsc*)pSrc)->RvFrgAtrCmd.uchTR_C = 
				//hldrRVStngTransportCTpuUnit.RvCnHldr.ulRvCount;
				//Activate Create and transmit Ack Pac in Executor 
			break;
			default:
     		;//Error
			
		}
		
		
		
		
	}
	return lID;//

}
//*/

long ActivateTrAtrCmdExec(void* pvAdrAtrCmd,long lSize) 
{
register long i;
register void *pv;

	pv = (void*) &hldrConState;
	i = ((SecureExecStateDsc*)pv)-> shExecConState;
	if(i&1) //Busy
	return i;
	if(i == 0)
	{
		((SecureExecStateDsc*)pv)-> shExecConState = 1;
		((SecureExecStateDsc*)pv)->lOrderNumIteration = i;
		((SecureExecStateDsc*)pv)->lIdxStepExec       = i;
		((SecureExecStateDsc*)pv)->lCtrCes            = i;
		((SecureExecStateDsc*)pv)->ushEvtField        = i;
		((SecureExecStateDsc*)pv)->ulLifeCtrEct       =  0x30;
		((SecureExecStateDsc*)pv)->ushRvCount = 0;
		((SecureExecStateDsc*)pv)->ushTrCount = 0;//Size
		((SecureExecStateDsc*)pv)->ushRvTotal = 0;//((SecureExecStateDsc*)pv1)->ushRvTotal;
		((SecureExecStateDsc*)pv)->ushTrTotal = lSize;
		((SecureExecStateDsc*)pv)->pUchRV     = (void*)0;
		((SecureExecStateDsc*)pv)->pUchTR     = pvAdrAtrCmd;
		((SecureExecStateDsc*)pv)->ushAmtPhases         = 2;
		((SecureExecStateDsc*)pv)->ushAmtStep           = 22;
		((SecureExecStateDsc*)pv)->ushAmtIteration      = 0x2000;
		((SecureExecStateDsc*)pv)->ushDefaultTimeOutVal = 0x30;
		pv = (void*) &hldReliableCmnAtrcmd;
		((ReliableCmnDsc*)pv)-> TrFrgAtrCmd.IdTRFrgCmd = ID_TPT_CMD_TR_FRAGMENT;
		((ReliableCmnDsc*)pv)-> TrFrgAtrCmd.uchTR_C = 0;
		
		((ReliableCmnDsc*)pv)-> TrFrgAtrCmd.uShOrderNumFrg = 0;
		((ReliableCmnDsc*)pv)-> lAtrCmdOrderNumTrFragment  = 0;
		((ReliableCmnDsc*)pv)-> lAtrCmdOrderNumRvFragment  = 0;
		((ReliableCmnDsc*)pv)-> chStateReciveStngAck       = 0;
		//((ReliableCmnDsc*)pv)-> 
		//((ReliableCmnDsc*)pv)-> 
	}
	return (-1);

}
extern const char arAtrs_f_IN_Cmd_f [] ;

char chReqKeyCallAtrCmd = 0;
short shStateQueueAtrCmd =0;
//char chSizeQueueHldAtrCmd = 0;
//AtrCmdHldDsc arHldAtrCmd[SIZE_QUEUE_ATR_CMD];
void PutAtrCmdData(void *p_in_param,void *pOut)
{
register I32 i,j;
register void *pvL; 		
			//Clr AtrCmd
	for (i = 0,pvL = (void*)pOut;//&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]);
	i<(long)SIZE_ATR_CMD;i++)
	((char*)pvL)[i] = 0;
	pvL = (void*) arAtrs_f_IN_Cmd_f;
	for (i = 0; i < RESERV_MAX_F_EPRF_ONB; i++){
		j = ((char*)pvL)[i];
		RecodeBit(
					(char*)p_in_param,
					(char*)pOut,//&holderAtrCmd.UNAtrCmd.chArAtrCmd[0],
					i,
					j
				);
	}
	
		
}

//////////////////////////////////////////////////////////////////////////////////////////
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern long SetCmdHVPS(void *p_in_param, int nID_Activation);
                                        //unsigned short* p_out_param);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция генерации команд                                             ~~~~~
//~~~     возврат 2 - обслуживается предыдущий запрос                          ~~~~~
//~~~     возврат 3 - команда выполнена успешно                                ~~~~~
//~~~     возврат 4 - возникла  ошибка                                         ~~~~~
//~~~     p_in_param -> 32 bita                                                ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~   p_in_param должен указывать на область памяти команд  4  байта         ~~~~~
//~~~    //значения младших бит должны располагаться по мл. адресам памяти     ~~~~~
//~~~       p_in_param+0 -> 0-7;                                               ~~~~~
//~~~   	p_in_param+1 -> 8-15;                                              ~~~~~
//~~~   	p_in_param+2 -> 16 -24;                                            ~~~~~
//~~~   	p_in_param+3 -> 25 - 31;                                           ~~~~~
//~~~   	p_in_param+3 -> 32 - 39;                                           ~~~~~
//~~~   	p_in_param+3 -> 40 - 47;                                           ~~~~~
//~~~   	p_in_param+3 -> 48 - 55;                                           ~~~~~
//~~~   	p_in_param+3 -> 56 - 63;                                           ~~~~~
//~~~                                                       ~~~~~
//~~~    Длительность  всех команд в этом случае равна 10 миллисекунд          ~~~~~
//~~~    Команды будут стоять в таком положении вне зависимости                ~~~~~
//~~~    от работы   системы защит и автоматики                                ~~~~~
//~~~                                                                          ~~~~~
//~~~     Перечень команд и их положение в битовом  массиве                   ~~~~~
//~~~     определено в файле "epr_f.h" enum ENMEpr_F_Key_f 
//``````````````````````````````````````````````````````````````````````````````````
//~~~      int nID_Activation - константа определяется в файле  \inc\ici_ef.h   ~~~~
//~~~      можно поставить любое целое число от 1 до 8                         ~~~~~
//~~~      по ней функция SetCmdHVPS определяет есть ли место в очереди команд  ~~~~~
//~~~       если есть то возвращается  3 - команда выполнена успешно           ~~~~~
//~~~      иначе возврат 4 - возникла  ошибка т.е. очредь заполнена             ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//==================================================================================
//Body func                                                              
//==================================================================================
long SetCmdHVPS(void *p_in_param, int nID_Activation)
{
	
	if ( (nID_Activation>0) && (nID_Activation<8)){
		nID_Activation--;
		//if(shStateQueueAtrCmd&(1<<nID_Activation))
		// return ERROR_EXEC;
		//else{
		//	shStateQueueAtrCmd |= (1<<nID_Activation);
			//Registeration Code try this if really will be need
			//Clr AtrCmd

			if(AppReqTransmitAtrCmd==0){
				PutAtrCmdData(p_in_param,(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0])); 
				nID_Activation = ActivateTrAtrCmdExec((void*)&holderAtrCmd,(SIZE_ATR_CMD ));
				if(nID_Activation==(-1))
					AppReqTransmitAtrCmd ++;
				else
					return ERROR_EXEC;
			}
			
		//}
	}
	else
		return ERROR_EXEC;
	

    return SUCCESS_EXEC;
}
//-------------------------------------------------------------------------------
char arChTmrActivation [6] = {
20,20,20,20,  20,20};

void CallKeyAtrCmd(void)
{
register long i;
	if(chReqKeyCallAtrCmd &(1<<0)){ //F1
		i = arChTmrActivation[0];//Ctr
		
		if(i == 0 && AppReqTransmitAtrCmd==0){
			PutAtrCmdData((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[0]),
			(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]));
			
			i = ActivateTrAtrCmdExec((void*)&holderAtrCmd,(SIZE_ATR_CMD ));
			if(i==(-1)){
				chReqKeyCallAtrCmd &= ~(1<<0);
				AppReqTransmitAtrCmd ++;
			}
			i = 21;
		}
		arChTmrActivation[0] = --i;
	}
	
	if(chReqKeyCallAtrCmd &(1<<1)){ //F2
		i = arChTmrActivation[1];//Ctr
		if(i== 0 && AppReqTransmitAtrCmd==0){
			PutAtrCmdData((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[1*AMOUNT_BYTE_FOR_KEPRF]),
			(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]));
			
			i = ActivateTrAtrCmdExec((void*)&holderAtrCmd,(SIZE_ATR_CMD ));
			if(i==(-1)){
				chReqKeyCallAtrCmd &= ~(1<<1);
				AppReqTransmitAtrCmd ++;
			}	
			i = 21;
		}
		arChTmrActivation[1] = --i;
	}

	
	if(chReqKeyCallAtrCmd &(1<<2)){ //F3
		if(AppReqTransmitAtrCmd==0){
			PutAtrCmdData((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[2*AMOUNT_BYTE_FOR_KEPRF]),
			(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]));
			AppReqTransmitAtrCmd ++;
			chReqKeyCallAtrCmd &= ~(1<<2);
		}
	}

	
//	if(chReqKeyCallAtrCmd &(1<<3)){ //F4
//		if(AppReqTransmitAtrCmd==0){
//			PutAtrCmdData((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[3*AMOUNT_BYTE_FOR_KEPRF]),
//			(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]));
//			AppReqTransmitAtrCmd ++;
//			chReqKeyCallAtrCmd &= ~(1<<3);
//		}
//	}
//
//	
//	if(chReqKeyCallAtrCmd &(1<<4)){ //F5
//		if(AppReqTransmitAtrCmd==0){
//			PutAtrCmdData((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[4*AMOUNT_BYTE_FOR_KEPRF]),
//			(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]));
//			AppReqTransmitAtrCmd ++;
//			chReqKeyCallAtrCmd &= ~(1<<4);
//		}
//	}
//
//	
//	if(chReqKeyCallAtrCmd &(1<<5)){ //F6
//		if(AppReqTransmitAtrCmd==0){
//			PutAtrCmdData((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[5*AMOUNT_BYTE_FOR_KEPRF]),
//			(void*)&(holderAtrCmd.UNAtrCmd.chArAtrCmd[0]));
//			AppReqTransmitAtrCmd ++;
//			chReqKeyCallAtrCmd &= ~(1<<5);
//		}
//	}

	
	
	
}

void CheckQueueAtrCmd(void)
{


}
	
const char arAtrs_f_IN_Cmd_f [] = { 
HVSW_ON_DI_ATRFG_ONB   ,//HVSW_ON_DI_F_EPRF_ONB                 ,// Вкл. ВВ 
HVSW_OFF_DI_ATRFG_ONB  ,//HVSW_OFF_DI_F_EPRF_ONB                ,// Откл. ВВ 
RESET_SIGOUT_DI_ATRFG_ONB     ,//RESET_SIGOUT_DI_F_EPRF_ONB            ,// Сброс Реле
RESET_LED_DI_ATRFG_ONB        ,//RESET_LED_DI_F_EPRF_ONB               ,// Сброс индикаци
//
EDF01_DI_ATRFG_ONB   ,//EDF01_DI_F_EPRF_ONB                   ,// Вх Оф 01  
EDF02_DI_ATRFG_ONB   ,//EDF02_DI_F_EPRF_ONB                   ,// Вх Оф 02 
EDF03_DI_ATRFG_ONB   ,//EDF03_DI_F_EPRF_ONB                   ,// Вх Оф 03 
EDF04_DI_ATRFG_ONB   ,//EDF04_DI_F_EPRF_ONB                   ,// Вх Оф 04 
EDF05_DI_ATRFG_ONB   ,//EDF05_DI_F_EPRF_ONB                   ,// Вх Оф 05 
EDF06_DI_ATRFG_ONB   ,//EDF06_DI_F_EPRF_ONB                   ,// Вх Оф 06 
EDF07_DI_ATRFG_ONB   ,//EDF07_DI_F_EPRF_ONB                   ,// Вх Оф 07 
EDF08_DI_ATRFG_ONB   ,//EDF08_DI_F_EPRF_ONB                   ,// Вх Оф 08 
EDF09_DI_ATRFG_ONB   ,//EDF09_DI_F_EPRF_ONB                   ,// Вх Оф 09 
EDF10_DI_ATRFG_ONB   ,//EDF10_DI_F_EPRF_ONB                   ,// Вх Оф 10 
EDF11_DI_ATRFG_ONB   ,//EDF11_DI_F_EPRF_ONB                   ,// Вх Оф 11 
EDF12_DI_ATRFG_ONB   ,//EDF12_DI_F_EPRF_ONB                   ,// Вх Оф 12 
EDF13_DI_ATRFG_ONB   ,//EDF13_DI_F_EPRF_ONB                   ,// Вх Оф 13 
EDF14_DI_ATRFG_ONB   ,//EDF14_DI_F_EPRF_ONB                   ,// Вх Оф 14 
EDF15_DI_ATRFG_ONB   ,//EDF15_DI_F_EPRF_ONB                   ,// Вх Оф 15 
EDF16_DI_ATRFG_ONB   ,//EDF16_DI_F_EPRF_ONB                   ,// Вх Оф 16 
//
SET_OT1_DI_ATRFG_ONB    ,//SET_OT1_DI_F_EPRF_ONB                 ,//Вх Уст   От1 
RESET_OT1_DI_ATRFG_ONB  ,//RESET_OT1_DI_F_EPRF_ONB               ,//Вх Сброс От1 
SET_OT2_DI_ATRFG_ONB    ,//SET_OT2_DI_F_EPRF_ONB                 ,//Вх   Уст От2   
RESET_OT2_DI_ATRFG_ONB  ,//RESET_OT2_DI_F_EPRF_ONB               ,//Вх Сброс От2 
SET_OT3_DI_ATRFG_ONB    ,//SET_OT3_DI_F_EPRF_ONB                 ,//Вх   Уст От3   
RESET_OT3_DI_ATRFG_ONB  ,//RESET_OT3_DI_F_EPRF_ONB               ,//Вх Сброс От3 
SET_OT4_DI_ATRFG_ONB    ,//SET_OT4_DI_F_EPRF_ONB                 ,//Вх   Уст От4   
RESET_OT4_DI_ATRFG_ONB  ,//RESET_OT4_DI_F_EPRF_ONB               ,//Вх Сброс От4 
SET_OT5_DI_ATRFG_ONB    ,//SET_OT5_DI_F_EPRF_ONB                 ,//Вх Уст   От5 
RESET_OT5_DI_ATRFG_ONB  ,//RESET_OT5_DI_F_EPRF_ONB               ,//Вх Сброс От5 
SET_OT6_DI_ATRFG_ONB    ,//SET_OT6_DI_F_EPRF_ONB                 ,//Вх Уст   От6   
RESET_OT6_DI_ATRFG_ONB  ,//RESET_OT6_DI_F_EPRF_ONB               ,//Вх Сброс От6 
SET_OT7_DI_ATRFG_ONB    ,//SET_OT7_DI_F_EPRF_ONB                 ,//Вх   Уст От7   
RESET_OT7_DI_ATRFG_ONB  ,//RESET_OT7_DI_F_EPRF_ONB               ,//Вх Сброс От7 
SET_OT8_DI_ATRFG_ONB    ,//SET_OT8_DI_F_EPRF_ONB                 ,//Вх   Уст От8   
RESET_OT8_DI_ATRFG_ONB  ,//RESET_OT8_DI_F_EPRF_ONB               ,//Вх Сброс От8 



};

//=================================================================
//--------                           ------------------
//=================================================================
//.............                           .........................
void RecodeBit(char *pRamBitArr, char* pLgrBitArr,long nOnbIn,long nOnbOut)
{

  //-register I32 i,j;
  struct 
	{
		//short         shCountCmd;  
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		unsigned short uShOnbIn  ;
		unsigned short uShOnbOut ;
	} sLV;
	sLV.uShOnbIn  = nOnbIn; //Save Start Contain Order Number Bit
	sLV.uShOnbOut = nOnbOut;//Save Start Contain Order Number Bit
	//Extract Data
	sLV.uChIdxByte = nOnbIn>>3;sLV.uChIdxBit = nOnbIn - sLV.uChIdxByte*8;
	nOnbIn = pRamBitArr[sLV.uChIdxByte] &(1<< (sLV.uChIdxBit));
	//Put Data
	if ( nOnbIn)//
	{//SEt
		sLV.uChIdxByte = (nOnbOut >>3);//Int of divisiob
		sLV.uChIdxBit = nOnbOut - (sLV.uChIdxByte<<3);
		nOnbOut = *( (unsigned char*)(pLgrBitArr) + sLV.uChIdxByte);
		nOnbOut |= 1 << (sLV.uChIdxBit);
		*( (unsigned char*)(pLgrBitArr) + sLV.uChIdxByte) = nOnbOut;
	}

}
//------------------------------------------------------------------
//=================================================================
//--------                           ------------------
//=================================================================
//.............                           .........................
void Conv32Bfld1ToBfld2(void *pConvParam)// Conv32Bit Field1 To Bit Field2
{
register I32 i,j;
register void *pvL;
struct 
	{
		//short         shCountCmd;  
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		//-short shVal;
		unsigned short ushBeg,ushEnd;
		
	} sLV;
	//
	sLV.ushBeg = (((ConvParamDsc*)pConvParam)->shStartNumBit );
	sLV.ushEnd = sLV.ushBeg + 32;
	for (i = sLV.ushBeg; i < sLV.ushEnd; i++)
	{ 
	    pvL = (void*)(((ConvParamDsc*)pConvParam)->pOnbVal );//[i];
		//sLV.shVal = 
		j = *((char *)((char*)pvL+i));
		j = ((ConvParamDsc*)pConvParam)->pOnbVal[i];
		if (j!=0xff)
		{
			RecodeBit(((ConvParamDsc*)pConvParam)->pI8In ,
			((ConvParamDsc*)pConvParam)->pI8Out ,i,j);
		}
	}

}
//----------------------------------------------------------------------------------------

extern CfgTblDsc eeprom_prt_tbl;

void SetAtrCmd(void){
	SetCmdHVPS((void*)&(eeprom_prt_tbl.uc_ar_key_rank_cfg[0]),1);
}


#pragma default_function_attributes = 




/* EOF */

