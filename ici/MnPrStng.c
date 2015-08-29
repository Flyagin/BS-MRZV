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
* File Name       : MnPrStng.c
* Description     : Functions and Data for Manage All operations with Settings
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "MnPrStng.h"

#include    "StngIci.h"
CmmMsgDsc hldCmmMsg;


char chUsehldCmmMsgRV = 0;
CmmMsgDsc hldCmmMsgRV,hldCmmMsgTR;

































long ActivatePrMngSettings(void)
{
	register long i;
	void* pv;
	i = ID_SETTING_PR_MNG;
	
	i = hldPrMngSettings.shPrMngConState;
	if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
	return 0;
	 pv = (void*)&hldPrMngSettings;
	i =  ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
	 i |= (PM_STT_USING_OCS_MSK)|(PM_STT_START_OCS_MSK);
	((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
	hldrTRStngPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;//???
	(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = (unsigned long)(-1);
	
//
//  ((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderSettings.UNSettings.chArSettings[0];//
//

	//Set Transport
	return i;
}	
long WorkProxyManager (void* pv, long lV)//State control & Definions
{
register long i = 0;
//register long j;
    if(lV == PM_STT_START_OCS_ONB)
    {
        //Do SomeSing! for Init
		//((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[0] = 1;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = ACTIVATE_FILL_DATA;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = RECIVE_FILL_DATA;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = ACTIVATE_TRANSMIT_DATA;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[4] = TRANSMIT_FILL_DATA;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[5] = FREE_FILL_DATA;
		//i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		//i |= STT_WORK_OCS_MSK;
		//((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		i |= PM_STT_WORK_OCS_MSK;
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
		//Now it is all cmd
    	//i = ExecCmdProxySettings(pv,ACTIVATE_FILL_DATA);
		
    }
	if(lV == PM_STT_WORK_OCS_ONB)
    {
       
//.	   i = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0];//Pointer to Active Cmd
//.	   if (i==0)
//.	   return lV--;// ! Error
//.	   if (i<TOTAL_CMD)//Now Treshold for this Executor
//.	   {
//.	      j = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[i];//Load Command
//.		  //...((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;
//.	      lV = ExecCmdProxySettings(pv,j);
//.		  if (lV==0)//Ok
//.		  ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = ++i;
//.	   }
//.	   else{
//.	   ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;//Terminate Exec
//.	   }
		//Control Correctnes Executing State & Process
		//~i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		//~if(i&PM_STT_ERROR_OCS_MSK)
		//~{
		//~
		//~}
		//~else
		//~;
		//j = (long) ((ProxyMangerStateDsc*)pv)->pf_ExecCmd;
		//if(j) sLV.pfl_vl = (PFL_VL)j;i = sLV.pfl_vl(pvProxy,sLV.uChIdxBit);
		i = ExecCmdPrMng(pv,lV);// i = ExecTargetProxyManager(pv,lV);

    }
	if(lV == PM_STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init
		// ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;//1;
		// ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = 0;//ACTIVATE_FILL_DATA;
		// ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = 0;//RECIVE_FILL_DATA;
		// ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = 0;//ACTIVATE_TRANSMIT_DATA;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[4] = 0;//TRANSMIT_FILL_DATA;
		//((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[5] = 0;//FREE_FILL_DATA;
		//i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		//i = 0;//AUX_OCS_MSK;//Reset State
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[0] = 0;	
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[1] = 0;
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[2] = 0;
		((ProxyMangerStateDsc*)pv)->arUchStateCmd[3] = 0;
		((ProxyMangerStateDsc*)pv)->arUchCounterChangeStateCmd[0] = 0;
		((ProxyMangerStateDsc*)pv)->arUchCounterChangeStateCmd[1] = 0;
		((ProxyMangerStateDsc*)pv)->arUchCounterChangeStateCmd[2] = 0;
		//Now it is all cmd
    	//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[0] = 0;
		//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[1] = 0;
		//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[2] = 0;
		//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[3] = 0;
		i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		i = 0;
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
		((ProxyMangerStateDsc*)pv)-> chCmdReq =((ProxyMangerStateDsc*)pv)-> chCmdAnswer =((ProxyMangerStateDsc*)pv)-> ulStateProxyManger = i;
    }

return i;
}
//long ResetProxySettings (void* pv, long lV)
//{
//return 0;
//}


long ExecCmdProxySettings1 (void* pv, long lV)
{
//register long i;
//register void* pv;
    
	if(lV == ACTIVATE_FILL_DATA)
    {
        
    }
	if(lV == RECIVE_FILL_DATA )
    {
        
    }
	
	if(lV == ACTIVATE_TRANSMIT_DATA )
    {
       
		return 0;//Exex Action for Taras Array
    }
	
	if(lV == TRANSMIT_FILL_DATA )
    {
        
	   	 return 1;//Exex Action for Taras Array
    }
	if(lV == FREE_FILL_DATA)
    {
      
	   return 0;//Exex Action for Taras Array
    }
	
	
return 0;
}
long ExecTargetProxyManager (void* pv, long lV)
{
register void *pvPrxMngState;
struct 
	{
		//char chRetCode;
		//unsigned char UchStateCmd,UchCounterChangeState;
		//char chCmdReq,chCmdAnswer,chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		PFL_VL pfl_vl;
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	//Common PreInit If need
sLV.UNNlV.ulVal = 0;
//Select TypeTask
switch (sLV.UNStateProxyManger.uchAr[2])
	{
	case TGT_TR_DATA_T1_COBJ_HM_HS: //
	//Process Task  Data
		sLV.UNNlV.ulVal = ExecTgtTrDataT1_1(pv, lV);//ExecTgtTrDataT1 ExecTgtTrDataT1_1
		//Lool Result 
		
		break;
	case TGT_HM_DATA_T1_COBJ_OOBJ_HM_HS: //TASK_REQ_REMOUTE_WR_EEPROM: //
		
		break;
	case TGT_HM_CMP_DATA_T1_COBJ_OOBJ_HS: //TASK_REQ_REMOUTE_CMP_TABLE: //
	  
		break;
	case TGT_ICI_RV_DATA_T1_HM_OOBJ_HS: //TASK_REQ_SEND_DATA_T1: //
	  
		break;
	
	default:
		{
			//Do this common part Work for service Executing Proxy Manager
			//Try activate Work
		
			//Detect Current Partner State In T1
			//Do this common part Work for service Executing Proxy Manager
			if(sLV.UNStateProxyManger.uchAr[2] == 0)	//Task==0)
			{
				;//Start Init 
				sLV.UNStateProxyManger.uchAr[2] = TGT_TR_DATA_T1_COBJ_HM_HS; //TASK_TR_DATA_T1;
				sLV.UNStateProxyManger.uchAr[3] = 0;//Init Part of Phase;
				sLV.UNStateProxyManger.ushAr[0] = 0;//Clear State Manager
				//
				((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = sLV.UNStateProxyManger.ulVal;
				((ProxyMangerStateDsc*)pvPrxMngState)->chCmdAnswer   = 0;
				((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq      = 0;
				//((ProxyMangerStateDsc*)pvPrxMngState)->chIdxStateCmd = 0;
				
			}
			else{
				;//Control Change State
				sLV.UNStateProxyManger.uchAr[1] =  T1_PHASE_OVERRUN_LIMIT_INIT+5;//Simoly
				//for Fix and handling error state of PrMng
				
				
			}
			
			if(sLV.UNNlV.uchAr[3] == 0)//Ok
			{
				//Detect Next Task Update Apropriate ProxyManger State
			}
			else
			{//Error
			//Handle Error
				;
				//Select Next Apropriate ProxyManger State
				
				//Count Amount Errorrs
				//if Number More then threshold 
				//Deactivate Proxy
				//Select Next Apropriate ProxyManger State

				
			}
				
				
		}
	}
//Process Task  Data
//Lool Result
	if(sLV.UNNlV.uchAr[1] != 0)//Ok
	{//Error
			//Handle Error
				;
				//Select Next Apropriate ProxyManger State
				
				//Count Amount Errorrs
				//if Number More then threshold 
				//Deactivate Proxy
				//Select Next Apropriate ProxyManger State
				lV = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
				lV |= PM_STT_STOP_OCS_MSK ;
				((ProxyMangerStateDsc*)pv)-> shPrMngConState = lV;
				
				pv  = (void*)& hldPrTrptSettings;
				sLV.pfl_vl = (PFL_VL)((BaseAcpuCMUnitDsc*)pv)-> pf_Rst;
				//Clear Apropriate Transport 
				lV = sLV.pfl_vl(pv,0);
	}
	
	
	
	
	
	return sLV.UNStateProxyManger.ulVal;
}

long ExecTgtTrDataT1 (void* pv, long lV)//TASK_TR_DATA_T1
{
//Detect Appropriate Phase
register void *pvPrxMngState;
struct 
	{
//		char chRetCode;
//		unsigned char UchStateCmd,UchCounterChangeState;
//		char chCmdReq,chCmdAnswer,chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	sLV.UNNlV.ulVal = 0;
switch (sLV.UNStateProxyManger.uchAr[3])
	{
	case T1_PHASE_REQ_TR_DATA: //
	//Process Task  Data
		sLV.UNNlV.ulVal = ExecT1PhaseReqTrData(pv, lV);//
		//Lool Result 
		
		break;
	case T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1: //
		;//sLV.UNNlV.ulVal = ExecT1
		break;
	case T1_PHASE_REQ_T1_TANSPORT_RESULT: //
	    ;//sLV.UNNlV.ulVal = ExecT1
		break;
	case T1_PHASE_WAIT_ANSW_T1_TRANSPORT_RESULT: //
	  ;//sLV.UNNlV.ulVal = ExecT1
		break;
	
	default:
		//Do this common part Work for service Executing Proxy Manager
		//Try activate Work
	
		//Detect Current Partner State In T1
		//Do this common part Work for service Executing Proxy Manager
		if(sLV.UNStateProxyManger.uchAr[3] == 0)	//Task==0)
		{
			;//Start Init 
			//.sLV.UNStateProxyManger.uchAr[2] = TASK_TR_DATA_T1;
			sLV.UNStateProxyManger.uchAr[3] = T1_PHASE_REQ_TR_DATA;//Init Part of Phase;
			//.sLV.UNStateProxyManger.ushAr[0] = 0;//Clear State Manager
			//
			((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = sLV.UNStateProxyManger.ulVal;
			((ProxyMangerStateDsc*)pvPrxMngState)->chCmdAnswer   = 0;
			((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq      = 0;
			//((ProxyMangerStateDsc*)pvPrxMngState)->chIdxStateCmd = 0;
			
		}
		else{
			;//Control Change State
			
			
			
		}
		
	}
	return sLV.UNStateProxyManger.ulVal;

}
long ExecT1PhaseReqTrData (void* pv, long lV)//T1_PHASE_REQ_TR_DATA
{
register void *pvPrxMngState;
struct 
	{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	

	sLV.chSelStateCmd = ORD_SEL_T1_PHASE_REQ_TR_DATA;//((ProxyMangerStateDsc*)pvPrxMngState)->chSelectorStateCmd; It must be addequite T1_PHASE_REQ_TR_DATA
	//Now Detect from Phase
	sLV.UchCounterChangeState =  ((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[(sLV.chSelStateCmd)];
//Control Self DeadLock
	if(sLV.UchCounterChangeState>= 3)//Init State??/ Init no more then 3 ones
	{
		sLV.UNStateProxyManger.uchAr[1] = T1_PHASE_OVERRUN_LIMIT_INIT_T1_PHASE_REQ_TR_DATA;//Ischrpan  Limit Starta
		//((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
		goto RetStateProxyManger;
	}
//Control Self LifeTimer
//---//-----
//Control Self State
// ----// ----

//Control chCmdReq
//sLV.chCmdReq = ((ProxyMangerStateDsc*)pvPrxMngState)->arUchStateCmd[sLV.chSelStateCmd];//Now
sLV.chCmdReq = CMD_REQ_T1_TR_DATA;//Comman for Transmittig

	
//Control chCmdAnswer
sLV.chCmdAnswer = 0;//Simply clear
//----//----

//Select Next State Try Realize it???
	if (
	(sLV.chCmdReq == CMD_REQ_T1_TR_DATA)&&
	(sLV.UchCounterChangeState<3)
	//&&() Self Timer
	//&&() Self Etc.
	)
	{
		sLV.UNStateProxyManger.uchAr[3] = T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1;//Change Phase
		((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq = sLV.chCmdReq;
		((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[ORD_SEL_T1_PHASE_REQ_TR_DATA] =
		sLV.UchCounterChangeState +1;
		//SendPrMngMsg
		pv = (void*)&hldCmmMsg;
		((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0] = sLV.chCmdReq;
		
		//Activate Queue
		if(ReqTransmitSettingsPrMng<EXEC)
		ReqTransmitSettingsPrMng = START;//Control you Permit Activate 
		//else Error Activation
	}
//Desigion Point
RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)

}

long ExecT1PhaseWaitAnswRdyTransport (void* pv, long lV)//T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1
{
register void *pvPrxMngState;
struct 
		{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	
sLV.chSelStateCmd = ORD_SEL_T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1;
//Control Self DeadLock
sLV.UchCounterChangeState =  ((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[(sLV.chSelStateCmd)];
	if(sLV.UchCounterChangeState>= 3)//Init State??/ Init no more then 3 ones
	{
		sLV.UNStateProxyManger.uchAr[1] =  T1_PHASE_OVERRUN_LIMIT_INIT;//Ischrpan  Limit Starta
		//((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
		goto RetStateProxyManger;
	}
//Control Self LifeTimer
//sLV.UNNlV.ulVal = GetLifeCtr(ID_SETTIGS_PROXY_MANEGER_UNIT,T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1);//arU32LifeCtr
//For Detect Need 2 param long - Id Conteiner long Phase & Target
	if(sLV.UNNlV.ulVal != 0)
	{
		;//Ok Can Wait
	}
	else
	{
		;//Time Out
	}
//Control Self State
//----//-----

//Control chCmdAnswer
sLV.chCmdAnswer = 0;
sLV.chCmdAnswer = ((ProxyMangerStateDsc*)pvPrxMngState)-> chCmdAnswer;
	if(sLV.chCmdAnswer == ANSW_RDY_RV_DATA_TASK_TR_DATA_T1)
	{
	
	
	
	}
//Control chCmdReq


//Select Next State Try Realize it???
RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)
}
long ExecTgtTrDataT1_1 (void* pv, long lV)//TASK_TR_DATA_T1
{
//Detect Appropriate Phase
register void *pvPrxMngState;
struct 
	{
//		char chRetCode;
//		unsigned char UchStateCmd,UchCounterChangeState;
//		char chCmdReq,chCmdAnswer,chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	sLV.UNNlV.ulVal = 0;
switch (sLV.UNStateProxyManger.uchAr[3])
	{
	case TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS: //
	//Process Task  Data
		sLV.UNNlV.ulVal = ExecT1HsPhs1(pv, lV);//
		//Lool Result 
		break;
	case TGT_T1_PHS_WAIT_CMM_MSG:	
	case TGT_T1_PHS_WAIT_ANSW__RSP_RDY_RV_STNG_OBJ__HS: //
		sLV.UNNlV.ulVal = ExecT1HsPhsWaitCmmMsg(pv, lV);//ExecT1HsPhs2(pv, lV);
		break;
	case TGT_T1_PHS__RQ_TRANSPORT_RESULT_TR__OBJ_HS: //
	    sLV.UNNlV.ulVal = ExecT1HsPhs3(pv, lV);
		 
		break;
	case TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS: //
	case TGT_T1_PHS_WAIT_ANSW__TRANSPORT_RESULT_TR__OBJ_HS:
	    sLV.UNNlV.ulVal = ExecT1HsPhs4(pv, lV);
		//if OK- Select Next Target Error - Stop Exec ???
		break;
	default:
		//Do this common part Work for service Executing Proxy Manager
		//Try activate Work
	
		//Detect Current Partner State In T1
		//Do this common part Work for service Executing Proxy Manager
		if(sLV.UNStateProxyManger.uchAr[3] == 0)	//Task==0)
		{
			;//Start Init 
			//.sLV.UNStateProxyManger.uchAr[2] = TASK_TR_DATA_T1;
			sLV.UNStateProxyManger.uchAr[3] = TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS;//Init Part of Phase;
			//.sLV.UNStateProxyManger.ushAr[0] = 0;//Clear State Manager
			//
			((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = sLV.UNStateProxyManger.ulVal;
			((ProxyMangerStateDsc*)pvPrxMngState)->chCmdAnswer   = 0;
			((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq      = 0;
			//((ProxyMangerStateDsc*)pvPrxMngState)->chIdxStateCmd = 0;
			hldCmmMsgRV.UNNHdrMsg.ulAr[0] = 0;
		}
		else{
			;//Control Change State
			//State if
			
			
		}
		
	}sLV.UNStateProxyManger.ulVal = sLV.UNNlV.ulVal;
	return sLV.UNStateProxyManger.ulVal;

}

long ExecT1HsPhs1 (void* pv, long lV)//TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS
{
register void *pvPrxMngState;
struct 
	{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	sLV.UNNlV.ulVal = 0;

	sLV.chSelStateCmd = ORD_SEL_TGT_T1_HS_PHS_1;//
	//Now Detect from Phase
	sLV.UchCounterChangeState =  ((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[(sLV.chSelStateCmd)];
//Control Self DeadLock
	if(sLV.UchCounterChangeState>= 3)//Init State??/ Init no more then 3 ones
	{
		sLV.UNStateProxyManger.uchAr[1] = ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS;//Ischrpan  Limit Starta
		//((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
		goto RetStateProxyManger;
	}
	else
	{
		sLV.UchCounterChangeState++;
		 ((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[(sLV.chSelStateCmd)]
		 = sLV.UchCounterChangeState;
	}
//Control Self LifeTimer
//---//-----
//Control Self State
// ----// ----

//Control chCmdReq
//sLV.chCmdReq = ((ProxyMangerStateDsc*)pvPrxMngState)->arUchStateCmd[sLV.chSelStateCmd];//Now
sLV.chCmdReq = CMM_TR_COBJ_HS_TO_HM;//Comman for Transmittig

	
//Control chCmdAnswer
sLV.chCmdAnswer = 0;//Simply clear
//----//----

//Select Next State Try Realize it???
//	if (
//	(sLV.chCmdReq == CMM_TR_COBJ_HS_TO_HM)&&
//	(sLV.UchCounterChangeState<3)
//	//&&() Self Timer
//	//&&() Self Etc.
//	)
	{
		sLV.UNStateProxyManger.uchAr[3] = TGT_T1_PHS_WAIT_ANSW__RSP_RDY_RV_STNG_OBJ__HS;//Change Phase
		((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq = sLV.chCmdReq;
		((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[ORD_SEL_TGT_T1_HS_PHS_1] =
		sLV.UchCounterChangeState +1;
		//SendPrMngMsg
		pv = (void*)&hldCmmMsg;
		((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0] = sLV.chCmdReq;
		 lPhsLifeCtr = 1000000;//1000;//
		//Activate Queue
		if(ReqTransmitSettingsPrMng<EXEC)
		ReqTransmitSettingsPrMng = START;//Control you Permit Activate 
		//else Error Activation
	}
//Desigion Point
RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)

}
long ExecT1HsPhs2 (void* pv, long lV)//T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1
{
register void *pvPrxMngState;
struct 
		{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	

//Control Self LifeTimer
//sLV.UNNlV.ulVal = GetLifeCtr(ID_SETTIGS_PROXY_MANEGER_UNIT,T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1);//arU32LifeCtr
sLV.UNNlV.ulVal = lPhsLifeCtr;
//For Detect Need 2 param long - Id Conteiner long Phase & Target
	if(sLV.UNNlV.ulVal != 0)
	{
		;//Ok Can Wait
	}
	else
	{
		;//Time Out
		lPhsLifeCtr = 0;sLV.UNStateProxyManger.uchAr[1] = sLV.UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;
		goto RetStateProxyManger;
	}
//Control Self State
//----//-----

//Control chCmdAnswer
//Control chCmdReq
sLV.chCmdReq = 0;//Command for Transmittig
//Control chCmdAnswer
sLV.chCmdAnswer = 0;//Simply clear

	if (chUsehldCmmMsgRV==0)
	{
		sLV.chCmdAnswer =  hldCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if (lPhsLifeCtr) lPhsLifeCtr--;//Waiting State
		sLV.UNNlV.ulVal    =  ChangeState(pvPrxMngState,sLV.chCmdAnswer);
		if(sLV.UNNlV.ulVal == sLV.UNStateProxyManger.ulVal) 
		goto RetStateProxyManger;//Operation fail
		//Activate Tpt
		lV = ActivateTRStngPrTpt((void*)&testSettigsState,0);
		sLV.chCmdReq = lV; 
		//+ Look Result Activation
		
		
		//If Activation OK change Phase
		sLV.UNStateProxyManger.ulVal = sLV.UNNlV.ulVal;
		((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = sLV.UNStateProxyManger.ulVal;
	}
	else
	{
		goto RetStateProxyManger;//Busy Input Msg
		
	}

//Select Next State Try Realize it???
//	if (
//	(sLV.chCmdReq == CMD_REQ_T1_TR_DATA)&&
//	(sLV.UchCounterChangeState<3)
//	//&&() Self Timer
//	//&&() Self Etc.
//	)
	{
		
		
		sLV.UNStateProxyManger.uchAr[3] = sLV.UNNlV.ulVal;//?? Change Phase
		((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq = sLV.chCmdReq;
		//((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[ORD_SEL_TGT_T1_HS_PHS_1] =	sLV.UchCounterChangeState +1;
		//.sLV.chSelStateCmd = ORD_SEL_TGT_T1_HS_PHS_2;
		//.//Control Self DeadLock
		//.sLV.UchCounterChangeState =  ((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[(sLV.chSelStateCmd)];
		//.//if(sLV.UchCounterChangeState>= 3)//Init State??/ Init no more then 3 ones
		//.{
		//.	sLV.UNStateProxyManger.uchAr[1] =  ERR__BAD_TGT_CODE;//T1_PHASE_OVERRUN_LIMIT_INIT;//Ischrpan  Limit Starta
		//.	//((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
		//.	goto RetStateProxyManger;
		//.}
		
		
		
		//SendPrMngMsg
		pv = (void*)&hldCmmMsg;
		((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0] = sLV.chCmdReq;
		
		//Activate Queue
		if(ReqTransmitSettingsPrMng<EXEC)
		ReqTransmitSettingsPrMng = START;//Control you Permit Activate 
		//else Error Activation
	}


RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)
}

// long ExecT1PhaseReqT1TranportResult (void* pv, long lV)//T1_PHASE_REQ_T1_TANSPORT_RESULT
// {
// //Control Self DeadLock
// //Control Self LifeTimer
// //Control Self State
// //Control chCmdReq
// //Control chCmdAnswer
// 
// //Select Next State Try Realize it???
// }
// 
// long ExecT1PhaseWaitAnswT1TranportResult (void* pv, long lV)//T1_PHASE_WAIT_ANSW_T1_TRANSPORT_RESULT
// {
// //Control Self DeadLock
// //Control Self LifeTimer
// //Control Self State
// //Control chCmdReq
// //Control chCmdAnswer
// 
// //Select Next State Try Realize it???
// }
// 
// long ExecT1PhaseExit (void* pv, long lV)//Select Next Target Or Stop
// {
// //Control Self DeadLock
// //Control Self LifeTimer
// //Control Self State
// //Control chCmdReq
// //Control chCmdAnswer
// 
// //Select Next State Try Realize it???
// }



// long ExecPhaseXXYYProxyManager (void* pv, long lV)
// {
// //Control Self DeadLock
// //Control Self LifeTimer
// //Control Self State
// //Control chCmdReq
// //Control chCmdAnswer
// 
// //Select Next State Try Realize it???
// }

long lPhsLifeCtr = (-1);
 int  ReqTransmitSettingsPrMng;
 int  ReqReceiveSettingsPrMng;
 
#define ID_SETTING_PR_MNG 0X10
ProxyMangerStateDsc  hldPrMngSettings = {
ID_SETTING_PR_MNG,
0,
WorkProxyManager,ExecCmdPrMng,
{0,0,0,0,0,0,0,0, 0,0 }, 
{0,0,0,0,0,0,0,0, 0,0 },
0,0,0
};

//Settings Input Param
ObjParamDsc hldTestSettigsParam = {
SIZE_SETTINGS_ICI,//sizeof(__SETTINGS),
(void*)&holderSettings//(void*)&current_settings_DBG
};


long SelectorCmd(void* pv) @ "Fast_function"
{
register long i = 0;
register long j;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;
       //Do SomeSing! for Init
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[0] = j =0;
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[1] = EXEC_TRANSMIT_FILL_DATA;
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[2] = EXEC_RECIVE_FILL_DATA  ;
	//.((ProxySettingsUnitDsc*)pv)-> arUchExecCmd[3] = EXEC_FREE_FILL_DATA    ;
	UNNlV.uchAr[0] = j  = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0];//Previous State
	UNNlV.uchAr[1] = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[j];//Detect type Command
	i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//UNNlV.uchAr[2] = ((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[j];//State command
	if ( (i&(TR_MODE_OCS_MSK)) 
	&& (((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[1]== 0)
	)//Ok
	{
		UNNlV.uchAr[3] = 1;//Index EXEC_TRANSMIT_FILL_DATA;
		//  j = TR_MODE_OCS_ONB;//
		if (UNNlV.uchAr[1]!=EXEC_TRANSMIT_FILL_DATA)
		{
			//Get Priority
			goto FixCmd;
		}	
	}
	//You could be insert in this place something for analises errors etc.
	//and change path of executing	
	
	if ( (i&(RV_MODE_OCS_MSK))
	&&(((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2]== 0)
	)//Ok
	{
		UNNlV.uchAr[3] = 2;//Index EXEC_RECIVE_FILL_DATA;
		//  j = TR_MODE_OCS_ONB;//
		if (UNNlV.uchAr[1]!=EXEC_RECIVE_FILL_DATA)
		{
			//Get Priority
			goto FixCmd;
		}	   
	  
	 }
	if(UNNlV.uchAr[3]==0) 
	{
	//Need Termination Proxy i.e. All Cmd Executed
		if (((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[3]== 0)
		{
			UNNlV.uchAr[3] = 3;//EXEC_FREE_FILL_DATA
		}
		else
		{
			;//Detect Error
		}
	}
	 
FixCmd:
	 
	return UNNlV.uchAr[3];//Index Load Cmd
}


long WorkProxyTransport (void* pv, long lV) @ "Fast_function"
{
register long i = 0;
register long j;
if(lV == STT_START_OCS_ONB)
    {
        ((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[2] = 0;//ResetProxyTransport(pv, lV);
		//Do SomeSing! for Init
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = j =0;
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = EXEC_TRANSMIT_FILL_DATA;
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = EXEC_RECIVE_FILL_DATA  ;
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = EXEC_FREE_FILL_DATA    ;
		j = SelectorCmd(pv);//What Exec Next	
		
		((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = j;//Selector Cmd

		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i |= STT_WORK_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		
		//Now it is all cmd
    	//i = ExecCmdProxyTransport(pv,ACTIVATE_TRANSMIT_RQ_DATA);
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 2;
	
		//return i;
    }
	if(lV == STT_WORK_OCS_ONB)
    {
       
	   i = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0];//Pointer to Active Cmd
	   if (i==0)
	   return lV--;// ! Error
	   if (i<EXEC_TOTAL_CMD)//Now Treshold for this Executor
	   {
	      j = ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[i];//Load Command
		  
		  
		  //...((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;
	      lV = ExecCmdProxyTransport(pv,j);
		  if (lV==0)//Ok
		  {
			//Look you have right for stop exec all Cmd
			j = SelectorCmd(pv);
			((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = j;//++i;
		  }
	   }
	   else{
	   ((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;//Terminate Exec
	   }
	   //return i;
    }
	if(lV == STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[0] = 0;//1;
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = 0;//
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = 0;//
		//((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = 0;//
		//
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		
		i &= USING_OCS_MSK;//??? Wait Reset from Maneger AUX_OCS_MSK;//Reset State
		//Manager must detect result Execution have error or OK what type Error of transport
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		((BaseAcpuCMUnitDsc*)pv)-> ulRvCount  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulTrCount  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> pUchRV     = 0;
		((BaseAcpuCMUnitDsc*)pv)-> pUchTR     = 0;
		//Now it is all cmd
    	lV = 0;
		if( ((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[2] == 1 )
		lV |= 1;
		if( ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] == 1
		)
		lV |= 2;//Transmit Coimplete
		//Check success execute & stop if needed
		if(lV == 3)
		{
			//Clear Proxy State
			if(hldPrMngSettings.ulLifeCtrEct)
			hldPrMngSettings.ulLifeCtrEct = 3;
		}
    }

return i;

}

extern TRFrgDsc TrFrgStng;
extern  int ReqTransmitStngPrTpt;

long lReciveStngAckGood = 0;
RVFrgDsc RvFrgStng = {
0,ID_TPT_CMD_ACK_RV_FRAGMENT,0,(char*)0,(char*)0
};
void ActivateStngSendAck(void)
{
 ReqTransmitStngPrTpt = START;//Activate Sesion
 if(hldrTpCnState.uchTpState_CNL_HSU2 == 0 )
  hldrTpCnState.uchTpState_CNL_HSU2 ++;//Select Channel
  TrFrgStng.IdTRFrgCmd = ID_TPT_CMD_ACK_RV_FRAGMENT;
}
//long lStngOrderNumFragment = 0;

long lStngOrderNumTrFragment = 0;
long lStngOrderNumRvFragment = 0;


void RepeatTrFrame(long lV)  @ "Fast_function"
{


ReqTransmitStngPrTpt = START;//Activate Sesion
TrFrgStng.IdTRFrgCmd = ID_TPT_CMD_TR_FRAGMENT;//
hldrTpCnState.uchTpState_CNL_HSU2  = 1;//Select Channel
//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = VAL_TRANSPORT_TRANSMIT>>(4-lV);
hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = VAL_TRANSPORT_TRANSMIT>>(6-lV);
lReciveStngAckGood = 0;


}



extern int txsize_U2;
long ExecCmdProxyTransport (void* pv, long lV) @ "Fast_function"
{
register long i,j;
register char *pch;
struct 
	{
		char chRetCode;//,
		unsigned short ushSizePacket;//
		
	} sLV;
	sLV.chRetCode = 0;
if(lV == EXEC_RECIVE_FILL_DATA)
    {
		lV = ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		lV--; ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = lV;
		if (lV ==0)
		{
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_TRANSPORT_WAITING_DATA;
			//Try Reset Whith Error Proxy Obj
			return 0;//Error
		}
		//else
		//{
		//    return 1;
		//}
		//
if(ReqReceiveStngPrTpt==0 ) return 1;
ReqReceiveStngPrTpt--;
        sLV.ushSizePacket = sLV.chRetCode = 0;
		if(RvFrgStng.uShOrderNumFrg>= lStngOrderNumRvFragment)
		{
		    if(RvFrgStng.uShOrderNumFrg>= lStngOrderNumRvFragment)
			{
				j = RvFrgStng.uShOrderNumFrg - lStngOrderNumRvFragment;
				if(j == 1)
				{
					sLV.ushSizePacket = 1;
					lStngOrderNumRvFragment = RvFrgStng.uShOrderNumFrg;
				}
				if(j == 0 )//Repeat Old Packet when lost Ack From here
				{
					sLV.ushSizePacket = 0;//Skip moving
					lV = sLV.chRetCode = 1;
				}
			}
		}
	if(sLV.ushSizePacket)
	{
		pch = (char *)&(hldrRVStngTransportCTpuUnit.RvCnHldr);//holderRVSettingsCTpuUnit);//?
		sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pch)->ulRvCount;
		pch = (char *)&(hldrRVStngTransportCTpuUnit.arUchRV); //RvCnHldr.pUchRV);
		pch += 3;//Skip Header
		 j = ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;//
		j += sLV.ushSizePacket;
		if ((unsigned long)j<(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal))
		{
			
			j = sLV.ushSizePacket;
			sLV.chRetCode = 1;
			
		}
		else
		{
			if ( j ==(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal)   )
			{
				//(((BaseAcpuCMUnitDsc*)pv)->ulRvCount)		    
				j = sLV.ushSizePacket;
				
				sLV.chRetCode = 2;
			}
			else
			{
				//It is a error -- Bad assembly array !!
				// You must signal that Assembly Bad!
				j = 0;
				sLV.chRetCode = 0;
				
			}
			
		}
		i = (long) ((BaseAcpuCMUnitDsc*)pv)->pUchRV;
		 //i = (long) &holderTotMeas.UNTotMeas.chArTotMeas[0];
		i+= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;//sLV.uVl;
		lV = i;
	
		for (i = 0; i < j; i++)
		{
			((char*)lV)[i] = pch[i];
		}
	}	
		
		switch (sLV.chRetCode )
		{
		case 1:
			i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
			i += j;
			((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
			if (j || (sLV.chRetCode == lV))
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT>>1;
			ActivateStngSendAck();
			
			break;
			
		case 2://
			i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
			i += j;
			((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 1;
			//Call function That Set apropriate data
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] += 1;//??? OK
			//Signal of the End Conection 
			sLV.chRetCode = 0;
		    ActivateStngSendAck();
			//Activate on 10ms check Operation
			//-i = Eval_CS((char*)testSettigsState.p_current_settings,//&holderSettings,
			//-testSettigsState.size_current_settings-sizeof(long)//sizeof(SettingsHldDsc)-sizeof( holderSettings.lCheckSum)
			//-);
			//-pch = (char *)testSettigsState.p_current_settings;
			//-if(i ==( ((StngIciTblDsc*)pch)->lCheckSum ) )//holderSettings.lCheckSum)
			//-{
			//-
			//-}
			break;
			
		case 0://
		
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 1;
			//Call function That fix Error state Proxy and array Data
			i = ((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2];
			if (i==0 || i>0x80)
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_OBJECT_RECEIVE_SIZE;
			break;
		default:
			;
		}
		
		
		return sLV.chRetCode;
		
		
    }
	if(lV == EXEC_TRANSMIT_FILL_DATA )
    {
        lV = ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING];
		lV--; ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = lV;
		if (lV ==0)
		{
		     lV = ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_REPEAT];
			if(lV == 0) 
			{
				((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[1] = ERR_TRANSPORT_WAITING_DATA;
				//Error
				((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;
				return 0;//Stop Transmittion
			}
			else
			{
				lV--; ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_REPEAT] = lV;
				//Repeat Retransmit Fragment
				RepeatTrFrame(lV);
				return 1;
			}
		}
 		//else
 		//{
 		//    //Control Transmitting
 		//	return 1;
 		//
 		//	
 		//}
		if(
				(ReqTransmitStngPrTpt==0)&&//TestReqTransmit ==0 //Out From Queue Ses Leyer
				(txsize_U2==0)&&lReciveStngAckGood&& //Transmition through Phys canel
				(hldrHSU2LpduTRUnit.uchLpuHSU2State== 0)//Data out from Link Leyer
		)
		{
			if ( ulCtrDecompouseStngTptUnitHSU2 ==  ulCtrTransmitLpduHSU2
			)//This need when last part split  on session frame transmited
			 return 1;
			//pv  = (void*)& holderProxyTotMeasUnit;
			lV = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;
			if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
			{
				((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[1] = 1;//
				((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = 2;
				return 0;//Stop Transmittion 
			}
			else 
			{
     			//ID_TEN_PERIOD_SAMPLES_UNIT;
				j = hldrTRStngTransportCTpuUnit.TrCnHldr.SizeAppObj;
				if(j>3)//SizeOf Header
				j -= 3;
				lV += j;
			
				((BaseAcpuCMUnitDsc*)pv)->ulTrCount = lV;
				if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
				return 1;

			}
			 //Look Ack
			if(lReciveStngAckGood)
			{
			    ReqTransmitStngPrTpt = START;//Activate Sesion
				TrFrgStng.IdTRFrgCmd = ID_TPT_CMD_TR_FRAGMENT;//
				hldrTpCnState.uchTpState_CNL_HSU2  = 1;//Select Channel
				((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = VAL_TRANSPORT_TRANSMIT;
				((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_REPEAT] = 3;
				lReciveStngAckGood = 0;lStngOrderNumTrFragment++;
			}	
		
		}
		return 1;
    }

	if(lV == EXEC_FREE_FILL_DATA)
    {
       
//. 	   pv  = (void*)& holderProxySettingsUnit;
//.	   //Control Correctnes Receive Data
//.	   //compare Total &  actual Receive data
//.	   if ( (((RVBaseCTpuUnitDsc*)pv)->ulRvCount) ==(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal)   )
//.	   chStateArSettingsData = SUCCESS_EXEC;
//.	   else 
//.	   chStateArSettingsData = ERROR_EXEC;
//.	   
//.		((BaseAcpuCMUnitDsc*)pv)->pUchTR = 0;//Base Addr Obj
//.		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
//.		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
//.		//,((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
 		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
 		lV |= STT_STOP_OCS_MSK; 
 		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[0] = 0;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[1] = 0;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[2] = 0;
//.		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[3] = 0;
//.		//Clear Tran
//.		TestReqTransmitSettings=0;

//Master Must Set Flags and Call Init Proxy Transport
//Muster Must then peridicaly look state Proxy Transport
//detect Ok,errorrs then clear  Proxy Transport State	

	   return 0;//Exex Action for Taras Array
    }
	return sLV.chRetCode;
}


long InitProxyTransport (void* pv, long lV)
{
return 0; 
}


long ResetProxyTransport (void* pv, long lV)
{
((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
    ((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
    ((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 0;
    ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
    ((BaseAcpuCMUnitDsc*)pv)->pUchRV    = (unsigned char*)0;
    ((BaseAcpuCMUnitDsc*)pv)->pUchTR    = (unsigned char*)0;
	for (lV = 0; lV < 4; lV++)
	{
		((ProxyTransportStateDsc*)pv)->arUchExecCmd      [lV] = 0;
		((ProxyTransportStateDsc*)pv)->arU32LifeCtr      [lV] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[lV] = 0;
	}
	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
	return 0;
}

#define ID_SETTING_PR_TRANSPORT 0X11
ProxyTransportStateDsc hldPrTrptSettings = {
ID_SETTING_PR_TRANSPORT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
//InitPrTrptSettings,ResetPrTrptSettings,WorkPrTrptSettings,ExecCmdPrTrptSettings
InitProxyTransport,ResetProxyTransport,WorkProxyTransport,ExecCmdProxyTransport,


// arUchExecCmd[4] = {
                   {0,0,0,0}, {0,0,0,0}, {0,0,0,0}
//{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 }
};

int  ReqTransmitStngPrTpt;
int  ReqReceiveStngPrTpt;

long lStngOrderNumFragment;

TRFrgDsc TrFrgStng = {
0,ID_TPT_CMD_TR_FRAGMENT,0,(char*)0,(char*)0
};




ProxyRvInParamDsc hldSettigsRvInParam = {
&(holderRVSettingsCTpuUnit.RvCnHldr),
(unsigned char*)&(holderSettings.UNSettings.chArSettings[0]),
&(hldPrTrptSettings.hldrAcpuCMUnitState),
(unsigned long *)&(hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA]),
&hldTestSettigsParam
};
//Settings TransptRvInParam;
ProxyTrParamDsc   hldSettigsTrParam = { 
&(holderTRSettingsCTpuUnit.TrCnHldr),
(unsigned char*)&(holderSettings.UNSettings.chArSettings[0]),
&(hldPrTrptSettings.hldrAcpuCMUnitState),
(unsigned long *)&(hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING]),
&hldTestSettigsParam
};


long ClrTrModeProxyTransport (void* pv, long lV)
{
register long i;
//lV Could be store Possible State
	if (lV)
	{
		
		
		
		switch (lV)
		{
			case TR_MODE_OCS_ONB:
				{
					((BaseAcpuCMUnitDsc*)pv)->pUchTR    = 0;//Base Addr Obj
					((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
					((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
					i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
					i&=~(TR_MODE_OCS_MSK);
					((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
					if(i&(RV_MODE_OCS_MSK))
					goto FullClr;
				}
			break;
			case RV_MODE_OCS_ONB:
				{
					((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
					((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 0;
					((BaseAcpuCMUnitDsc*)pv)->pUchRV  = 0;
					i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
					i&=~(RV_MODE_OCS_MSK);
					((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
					if(i&(TR_MODE_OCS_MSK))
					goto FullClr;
				}
			break;
			
		default:
		goto FullClr;//
		
		}	
	
	}
	else
	{
FullClr:		
		//Full Clear
		((BaseAcpuCMUnitDsc*)pv)->pUchTR = 0;//Base Addr Obj
		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 0;
		((BaseAcpuCMUnitDsc*)pv)->pUchRV  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
	
	
	// 		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	// 		lV |= STT_STOP_OCS_MSK;
	// 		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[0] = 0;
		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[1] = 0;
		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[2] = 0;
		((ProxyTransportStateDsc*)pv)->arU32LifeCtr[3] = 0;
		
		((ProxyTransportStateDsc*)pv)->arUchExecCmd[0] = 0;
		((ProxyTransportStateDsc*)pv)->arUchExecCmd[1] = 0;
		((ProxyTransportStateDsc*)pv)->arUchExecCmd[2] = 0;
		((ProxyTransportStateDsc*)pv)->arUchExecCmd[3] = 0;
		
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[0] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[2] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[3] = 0;
	//i = 0;
	}

return 0; 
}









void ActivateServTrApCnStngTptUnitFragmentHSU2(void)  @ "Fast_function"
{

register long i,j;
register char *pch;
register void* pv;
//-//Copy
//-  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
//-  pv  = (void*)& holderSrcSamplesUnit;
//-  j = sizeof(SrcSamplesUnitDsc);
//-  for (i = 0; i < j; i++)
//-  {
//-    pch[i] = ((char*)pv)[i];
//-  }hldTestSettigsParam.p_ObjEntity
pv  = (void*)&hldPrTrptSettings.hldrAcpuCMUnitState;//& holderProxySettingsUnit;
//testSettigsState
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
	 TrFrgStng.pSrc = pch;
	 TrFrgStng.pDst = &(hldrTRStngTransportCTpuUnit.arUchTR[0]);

  //Reset Connect State
   pv  = (void*)& (hldrTRStngTransportCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
   if( (j+3)> SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1)
   {
		j = SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1-2;
		j -= sizeof(char) + sizeof(short);
    }
   else
   {
	i++;//Debug Code for Logic Error Detection
   }
    TrFrgStng.uchTR_C = j;//
    TrFrgStng.uShOrderNumFrg = lStngOrderNumTrFragment;
   i = CreateTRFragment((void*)& TrFrgStng);
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf  = SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1;
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = i;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SETTING_PR_TRANSPORT;//
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)TrFrgStng.pDst;// pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void ActivateServTrApCnStngTptUnitAckHSU2(void)  @ "Fast_function"
{
register long i,j;
register char *pch;
register void* pv;

//-//Copy
//-  pch = (char *)&(holderTRSrcSamplesCTpuUnit.arUchTR);
//-  pv  = (void*)& holderSrcSamplesUnit;
//-  j = sizeof(SrcSamplesUnitDsc);
//-  for (i = 0; i < j; i++)
//-  {
//-    pch[i] = ((char*)pv)[i];
//-  }hldTestSettigsParam.p_ObjEntity
	pch   = (char*) &(hldrTRStngTransportCTpuUnit.arUchTR[0]);
	pch [0] = ID_TPT_CMD_ACK_RV_FRAGMENT;//((TRFrgDsc*)pvTRFrgDsc)->IdTRFrgCmd;
	//unnV1.ushAr[0] = ((TRFrgDsc*)pvTRFrgDsc)->uShOrderNumFrg;
	pch[1] = (RvFrgStng.uShOrderNumFrg)&0xff;//unnV1.uchAr[0];
	pch[2] = (RvFrgStng.uShOrderNumFrg)>>8;//unnV1.uchAr[1];
	pch[3] = RvFrgStng.uchTR_C;//Last Fragment




  //Reset Connect State
   pv  = (void*)& (hldrTRStngTransportCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   

   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf  =  SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1;
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = 4;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SETTING_PR_TRANSPORT;//
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch; //TrF
}
unsigned long ulCtrDecompouseStngTptUnitHSU2 = 10;//TransmitLpduHSU2 <-<-Need for stop transmit in one paket 2 part of one obj 1)One as last part Sesion 2)simply part of Obj Frame
//chtob ne poluchilos tak chto snachala peredali chast rascheplennogo ses urovnya i escho celii frame
void ActivateServTrApCnStngTptUnitHSU2(void)  @ "Fast_function"
{
if (TrFrgStng.IdTRFrgCmd == ID_TPT_CMD_ACK_RV_FRAGMENT)
ActivateServTrApCnStngTptUnitAckHSU2();
else
ActivateServTrApCnStngTptUnitFragmentHSU2();

}
void TerminateServiceApCnPrStngTptFragment(void)
{

  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  hldrTRStngTransportCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;

}
void TerminateServiceApCnPrStngTptAck(void)
{

  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  hldrTRStngTransportCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;

}

void TerminateServiceApCnPrStngTpt(void)  @ "Fast_function"
{

if (TrFrgStng.IdTRFrgCmd == ID_TPT_CMD_ACK_RV_FRAGMENT)
TerminateServiceApCnPrStngTptAck();
else
TerminateServiceApCnPrStngTptFragment();
  if (ulCtrDecompouseStngTptUnitHSU2 != ulCtrTransmitLpduHSU2)
	  ulCtrDecompouseStngTptUnitHSU2 =  ulCtrTransmitLpduHSU2;
}
void PrepDecompouseStngTptUnitHSU2(void) @ "Fast_function"
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
	if(ReqTransmitStngPrTpt)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2>>4;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitStngPrTpt==START)
			{
				ActivateServTrApCnStngTptUnitHSU2();
				ReqTransmitStngPrTpt = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitStngPrTpt==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRStngTransportCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitStngPrTpt = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitStngPrTpt = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitStngPrTpt==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnPrStngTpt();
					ReqTransmitStngPrTpt = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

//Settings TransptTRParam
long SendPrMngMsg(void* pvPrMng,void* pvCmmMsg)
{
//Detect Type Msg
//Detect Size 
//Put  Data on appopriate ses
return 0;
}

long PassPrMngMsg(void* pvPrMng,void* pvCmmMsg)
{
return 0;
}


long SendPrMngCmmMsg_(void* pvPrMng,void* pvCmmMsg)
{
//register void *pv;

//Detect Type Msg
//	pv = (void*)&hldCmmMsg;
	return 0;
	
	
//Detect Size 
//Put  Data on appopriate ses
}
void ActivateServTrApCnSettingsPrMngHSU2(void) @ "Fast_function"
{

register long i,j;
register char *pch;
register void* pv;

pv = (void*)&hldCmmMsg;j = 0;
i =  ((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0];

//Detect Type Msg
	switch (i)
 	{
 	
	case CMD_REQ_REMOUT_RST         :
	case CMD_REQ_CUR_TASK_PHASE     :
	case CMD_REQ_SELECT_TASK_PHASE  :
	case CMD_REQ_T1_TR_DATA         :
	case CMD_REQ_T1_TANSPORT_RESULT :
	case CMM_GET_STNG_OBJ_FROM_HM :
	pch = (char *)&(hldrTRStngPrMngCTpuUnit.arUchTR);
	 pch[0] = i;
 	break;
 	//case 2:
 	//    pDst = (char*)&(((TRStateLpuU2Dsc*)pv)->arUch[j+1]);
 	//	*((short*)pDst) = ((TRStateLpuU2Dsc*)pv)->ushSizeLDC;
 	//	j = 2;
 	//	break;
 	
 	default:
 	i++;
 	} 

	if(j)//Copy if really need transmit Obj
	{
		//Copy
		pch = (char *)&(hldrTRStngPrMngCTpuUnit.arUchTR);
		pv  = ((CmmMsgDsc*)pv)->p_ObjEntity; //(void*)& holderSrcSamplesUnit;
		j = ((CmmMsgDsc*)pv)->size_Obj;//sizeof(SrcSamplesUnitDsc);
		for (i = 0; i < j; i++)
		{
			pch[i] = ((char*)pv)[i];
		}
	}
	else j = 1;//One Byte


  //Reset Connect State
   pv  = (void*)& ( hldrTRStngPrMngCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   //j = //Size Msg
   if( j> SIZE_TPDU_SETTINGS_PR_MNG_CNL_HSU2)
   j = SIZE_TPDU_SETTINGS_PR_MNG_CNL_HSU2;//Don`t Send Very Big Msg
    ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf  = SIZE_TPDU_SETTINGS_PR_MNG_CNL_HSU2;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SETTING_PR_MNG;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
  
   
   
}
void TerminateServiceApCnSettingsPrMng(void)
{
//register void *pv;
//register long i;

  hldrTRStngPrMngCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  hldrTpCnState.uchTpState_CNL_HSU2 += 2;//For Debug Pupouses only 

}
void PrepDecompouseSettingsPrMngHSU2(void) @ "Fast_function"
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
	if(ReqTransmitSettingsPrMng)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_SETTINGS_PR_MNG_CNL_HSU2;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitSettingsPrMng==START)
			{
				ActivateServTrApCnSettingsPrMngHSU2();
				ReqTransmitSettingsPrMng = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitSettingsPrMng==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRStngPrMngCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitSettingsPrMng = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitSettingsPrMng = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitSettingsPrMng==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnSettingsPrMng();
					ReqTransmitSettingsPrMng = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

long PassSettingsPrMngRvMsgOrigin(void);
long PassSettingsPrMngRvMsg(void* pvLDC, long lID) @ "Fast_function"
{
register long i;
register void* pv;	
//pv  = (void*)hldrRVStngPrMngCTpuUnit.RvCnHldr;	
//pch = (char *)&( hldrRVStngPrMngCTpuUnit.arUchRV);	
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	hldrRVStngPrMngCTpuUnit.RvCnHldr.ulRvCount  = lID;
	//lID = 3?;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;
	pv  = (void*)& ( hldrRVStngPrMngCTpuUnit.arUchRV);
	
	for (i = 0; i < lID; i++)
	{
		((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	
	return PassSettingsPrMngRvMsgOrigin();
}
long PassSettingsPrMngRvMsgOrigin(void) @ "Fast_function"
{
register long i,j;
register char *pch;
register void* pv;
struct 
	{
		//short         shCountCmd;  
		unsigned char uChIdxByte ;
		unsigned char uChIdxBit ;
		//short shErr;
		//char ch1,ch2,ch3,ch4;
		void *pvPrMng,*pvCmmMsg;

		
	} sLV;
	sLV.pvPrMng  = (void*)& hldPrMngSettings;
	sLV.pvCmmMsg = (void*)& hldrRVStngPrMngCTpuUnit;
	sLV.uChIdxBit = 0;sLV.uChIdxByte = 0;
	//Detect connection State
	pv = sLV.pvPrMng;
	i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
	//j = ((i&PM_STT_WORK_OCS_MSK)== 0 )&& (i&(PM_STT_START_OCS_MSK));
	//j = (i&(PM_STT_WORK_OCS_MSK));
	//j |= (i&(PM_STT_START_OCS_MSK));
	//if (j)
	//sLV.uChIdxBit =  PM_STT_START_OCS_ONB;
	j =  (i&(PM_STT_WORK_OCS_MSK)) && ((i&( PM_STT_STOP_OCS_MSK ))==0);
	if (j)
	sLV.uChIdxBit =  PM_STT_WORK_OCS_ONB;
	
	j = (i&(PM_STT_STOP_OCS_MSK));
	if (j)
	sLV.uChIdxBit =  PM_STT_STOP_OCS_ONB;
	
	j = (i&(PM_STT_USING_OCS_MSK)); 
	if (j==0)
	 sLV.uChIdxBit =  PM_STT_START_OCS_ONB;//Activation 

	switch (sLV.uChIdxBit)
 	{
		case  PM_STT_WORK_OCS_ONB:
			sLV.uChIdxByte ++;//	 pch[0] = i;
		break;
		case  PM_STT_STOP_OCS_ONB:
		;//	 Do nothing Now
		break;
		case  PM_STT_START_OCS_ONB:
			//First Init Proxy
			j = i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK);
			if(j==0)
			{
				i =  ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
				i |= (PM_STT_USING_OCS_MSK)|(PM_STT_START_OCS_MSK);
				((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
			
			}
			sLV.uChIdxByte++;		
		;//	 pch[0] = i;
		break;
		 	
 	default:
	;
	}	
	//
	if (sLV.uChIdxByte)
	{
	
		//Put Msg
		if( chUsehldCmmMsgRV == 0)
		{
			
			pv  = (void*)& hldrRVStngPrMngCTpuUnit.RvCnHldr;
			j = ((RVBaseCTpuUnitDsc*)pv)-> ulRvCount;//Size of Message
			
			pv  = (void*)& hldCmmMsgRV.UNNHdrMsg;//Prepea for hundling 
			 pch = (char *)&( hldrRVStngPrMngCTpuUnit.arUchRV);
			
			for (i = 0; i < j; i++)
			{
				((char*)pv)[i] = pch[i];
			}
			//?? What about size_Obj *p_ObjEntity ???
		}
		else
		{
			//.!! Here Poit Fix a lose data 
		
		}
	}
	hldrRVStngPrMngCTpuUnit.RvCnHldr.ulRvCount = 0;//
	
//ExitPassSettingsPrMngRvMsgOrigin:
return sLV.uChIdxByte;
}
//This is function for Change state Execution after receive Ext Msg  
long ChangeState (void* pv, long lV)//lV Input Command pv PrMng Or United Proxy
{
register void *pvPrxMngState;
struct 
	{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
sLV.chCmdAnswer = 0;	sLV.chCmdReq = 0; sLV.UchStateCmd = 0;
sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	

switch (lV)// sLV.chCmdReq)
 	{
		case  CMM_RDY_RV_OBJ_HM:
			//Detect posibility ;//	 pch[0] = i;
			 sLV.chSelStateCmd = TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS;
			//After controlinga correctnosti prinyatoy commandi 
			
			//Prosto Set New State if not Errors
			sLV.UNStateProxyManger.uchAr[3] = TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS;
			//sLV.UNStateProxyManger.uchAr[2]
			//sLV.UNStateProxyManger.
			
			sLV.chCmdAnswer++;
			//Go to that State
			sLV.UchStateCmd = sLV.chSelStateCmd; 
			//state look self corectnes and Take right decisions
			
		break;
		case  CMM_TRANSPORT_RV_OBJ_OK_HM :
		;//	 Do nothing Now
		break;

 	default:
	;
	}
	if(sLV.chCmdAnswer)
	hldCmmMsgRV.UNNHdrMsg. ulAr  [1] = 0;//Need Clear Receive Msg
return sLV.UNStateProxyManger.ulVal;
}

long ActivateTRStngPrTpt(void* pObjParam, long lV)
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptSettings;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptSettings.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateTRStngPrTpt;
	}	
	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|TR_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVStngTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchTR = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//

//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = (-1);
//.((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = VAL_TRANSMITTING;
//.holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj = 0;
hldrTRStngTransportCTpuUnit.TrCnHldr.SizeAppObj  = 0;

RetActivateTRStngPrTpt:

return lV;//

}

void TestActivateTransport(void)
{
ActivateTRStngPrTpt((void*)&testSettigsState,0);
}

long UpdateRVPrTptStng(void* pvLDC, long lID) @ "Fast_function"
{
register long i;//,j;
register char *pSrc;//,*pDst;
void* pv;
TRFrgDsc frg = {
0,0,0,(char*)0,(char*)0
};

struct 
	{
		char chNeedActivateProxyTpt;
		char chNeedClrSesData;
		char chACKGood;
		void *pOriginLDC;
		long ReqReceiveStngPrTpt; 
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	
RVBaseCTpuUnitDsc locRVBaseCTpuUnit;

 //`````````````````````````````````````````````````````````````````````
 //``Init Ack control  part
 sLV.ReqReceiveStngPrTpt    = ReqReceiveStngPrTpt;
 sLV.chACKGood =  sLV.chNeedActivateProxyTpt = 0;
 sLV.pOriginLDC             = pvLDC;
   sLV.chNeedClrSesData = 0;
//`` 
//.....................................................................
 
if (ReqReceiveStngPrTpt>=1)//This part of code need as as previous buf need iteretivly  move to proxy
{
//~locRVBaseCTpuUnit = hldrRVStngTransportCTpuUnit.RvCnHldr;
//~locRVBaseCTpuUnit.pUchRV = (hldrRVStngTransportCTpuUnit.arUchRV);//Buffer Addr
//~i = MoveCTputoAppObj((void*)&hldPrTrptStng.hldrAcpuCMUnitState,
//~(void*)&locRVBaseCTpuUnit);
//~//if i == 0 //Error Fix!
//~ReqReceivePrtTblPrTpt = 0;//Now i think another number  is error
}


unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0; 
if (unnV1.uchAr[0]== 0)
{
	pv  = (void*)&hldrRVStngTransportCTpuUnit.arUchRV;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	if( lID > (long)(SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1 ))
	lID = (long)(SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1 );
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//  unnV1.uchAr[3] = lID;//Save amount Extract Data
	
	//Activate App For
	sLV.ReqReceiveStngPrTpt ++;//Activate Decoder Analice
	//Clear All Ses Data
	hldrRVStngTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	hldrRVStngTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
	hldrRVStngTransportCTpuUnit.RvCnHldr.ConState         = 0;
	hldrRVStngTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;//
	
} 
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&hldrRVStngTransportCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&hldrRVStngTransportCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	 sLV.chNeedClrSesData = 0;
		if ( i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			//;
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1 -2))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1-2 ) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
		
			pvLDC = (void*)i;
			i = (long)&hldrRVStngTransportCTpuUnit.arUchRV;
		
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&hldrRVStngTransportCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1-2 ))
			{
				// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				// i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
					if (lID == (long)(SIZE_TPDU_TRANSPORT_SETTINGS_CNL_HSU2_MDR1-2 ))
					{
						//Activate App Func
						sLV.ReqReceiveStngPrTpt ++;//Activate Decoder Analice
						hldrRVStngTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
						hldrRVStngTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
						hldrRVStngTransportCTpuUnit.RvCnHldr.ConState         = 0;
						hldrRVStngTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;
						//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
						//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					}
					else{
							//pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
							//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
							//((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
							//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
							//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
							sLV.chNeedClrSesData++;
					}
					
				
				
				
			}
//			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
//			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
//			pvLDC = (void*)i;
//			i = (long)&holderRV10PeriodCTpuUnit.arUchRV;
//			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
//			pv  = (void*)i;
//			for (i = 0; i < lID; i++)
//			{
//			((char*)pv)[i] = ((char*)pvLDC)[i];
//			}
			
			
		}
		else
		{
					;//Error Sesion
		// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lErrors = i;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalBadChange = i;
		//i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
		//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				
		 sLV.chNeedClrSesData++;
			
		}
	if(sLV.chNeedClrSesData)
	{

		;//Error Sesion
			pv  = (void*)&hldrRVStngTransportCTpuUnit.RvCnHldr;
		
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
	}		
		
}

if(sLV.ReqReceiveStngPrTpt)
{


     pvLDC  = sLV.pOriginLDC ;
     //frg.uchTR_C        = ((LDCIDsc*)pvLDC)->uchTR_C;
     pv  = (void*)&hldrRVStngTransportCTpuUnit.arUchRV;
     
    i =  frg.IdTRFrgCmd = ((char*)pv)[0];
     unnV1.uchAr[0] = ((char*)pv)[1];
     unnV1.uchAr[1] = ((char*)pv)[2];
     unnV1.uchAr[2] = ((char*)pv)[3];//Size Rv Data
     
     frg.uShOrderNumFrg =  unnV1.ushAr [0];// 
     //Detect Ack Or Data
     	switch (i )
     	{
     		case ID_TPT_CMD_ACK_RV_FRAGMENT:
     			//Cmp OrderNumFrg & Size
     			if(TrFrgStng.uchTR_C== unnV1.uchAr[2])
     			sLV.chACKGood++;
     			if(TrFrgStng.uShOrderNumFrg == frg.uShOrderNumFrg)
     			sLV.chACKGood++;
				
				if (sLV.chACKGood>= 2)
				lReciveStngAckGood++;//Inform Proxy ACK Good
				
     		break;
     		case ID_TPT_CMD_TR_FRAGMENT:
     			//Inform Proxy About Req Data
				hldrRVStngTransportCTpuUnit.RvCnHldr.ulRvCount -= 3;//Size of Header
				RvFrgStng .IdTRFrgCmd = i;
				RvFrgStng .uShOrderNumFrg =  frg.uShOrderNumFrg;
				RvFrgStng .uchTR_C = hldrRVStngTransportCTpuUnit.RvCnHldr.ulRvCount ;
				
				//Activate Create and transmit Ack Pac
				ReqReceiveStngPrTpt++;
				
				sLV.chNeedActivateProxyTpt++;
     		break;
     		//case 2://
     		//	sLV.IdxLpuBuf = 3;
     		//break;
     	 default:
     		;//Error
     	}
     	//Skip Aux Data In Buf

}
	if (sLV.chNeedActivateProxyTpt)
	{
		//Check where data should be put
		//testSettigsState
		if(testSettigsState.size_current_settings>= SIZE_SETTINGS_ICI)
		{
			unnV1.ulVal = (long)testSettigsState.p_current_settings;
			if( (unnV1.ulVal&((long)sLV.pOriginLDC))
			|| (unnV1.ulVal&0x777fffff)
			)
			{
				sLV.chNeedActivateProxyTpt= 8;
			}
			
			
			
		}
		if(sLV.chNeedActivateProxyTpt==8)
			i = ActivateRvStngPrTpt((void*)&testSettigsState,ID_UPDATE_RV_PR_TPT_STNG_CALL);
		else
		//Try activate Proxy Transport if not activated 
		i = ActivateRvStngPrTpt((void*)&hldTestSettigsParam ,ID_UPDATE_RV_PR_TPT_STNG_CALL);
	}
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
	
return lID;//

}


long ExecT1HsPhs4 (void* pv, long lV)//T1_PHASE_WAIT_ANSW_RDY_TRANSPORT_T1
{
register void *pvPrxMngState;
struct 
		{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	
sLV.UNNlV.ulVal = 0;sLV.UchStateCmd = 0;sLV.chCmdReq = 0;sLV.chCmdAnswer = 0;
//Control Self LifeTimer
if (lPhsLifeCtr) lPhsLifeCtr--; sLV.UNNlV.ulVal = lPhsLifeCtr;
//For Detect Need 2 param long - Id Conteiner long Phase & Target
	if(sLV.UNNlV.ulVal != 0)
	{
		;//Ok Can Wait
	}
	else
	{
		;//Time Out
		lPhsLifeCtr = 0;sLV.UNStateProxyManger.uchAr[1] = sLV.UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;
		goto RetStateProxyManger;
	}	
//Control Input Queue
	if (chUsehldCmmMsgRV==0)
	{
		sLV.chCmdReq =  hldCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.chCmdReq!=0) 
		{sLV.UNNlV.ulVal = sLV.UNStateProxyManger.ulVal;
			sLV.UNNlV.ulVal    =  DPTgtT1PhsWaitCmmMsg(pvPrxMngState,sLV.chCmdReq);
			if (sLV.UNNlV.ulVal != sLV.UNStateProxyManger.ulVal)
			lPhsLifeCtr = 100000;
		}
	}

//Control Self State
//----//-----

//Look Transport State
//Poluchi sostoyanie obiecta i posmotri on ostanovilsya ili Net
	pv = (void *)&hldPrTrptSettings.hldrAcpuCMUnitState;//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//if ( (lV & USING_OCS_MSK))
	//sLV.chCmdAnswer ++;//Good
	
	sLV.UNNlV.ushAr[0] = lV & (TR_MODE_OCS_MSK|USING_OCS_MSK); //| STT_STOP_OCS_MSK);
	if (sLV.UNNlV.ushAr[0])
	sLV.chCmdAnswer ++;
	
	sLV.UNNlV.ushAr[1] = sLV.UNNlV.ushAr[0] ^ (TR_MODE_OCS_MSK|USING_OCS_MSK);//| STT_STOP_OCS_MSK);
	
	//.TR_MODE_OCS_MSK 	USING_OCS_MSK 	STT_START_OCS_MSK     STT_WORK_OCS_MSK     STT_STOP_OCS_MSK 
	if( ((BaseAcpuCMUnitDsc*)pv)->ulTrCount == 0) goto RetStateProxyManger;
	//..((ProxyTransportStateDsc*)pv)-> arUchExecCmd[1] = EXEC_TRANSMIT_FILL_DATA;
	//..((ProxyTransportStateDsc*)pv)-> arUchExecCmd[2] = EXEC_RECIVE_FILL_DATA  ;
	//..((ProxyTransportStateDsc*)pv)-> arUchExecCmd[3] = EXEC_FREE_FILL_DATA    ;
	sLV.chSelStateCmd = 1;	//Idx EXEC_TRANSMIT_FILL_DATA
	//Look |Result executing
	lV = ((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[sLV.chSelStateCmd];
	sLV.chCmdReq = lV;
	if ((lV>0) && (lV<0x80))
	sLV.chCmdAnswer ++;
	if (sLV.chCmdAnswer== 2)//Transmit Ok
	{
		sLV.UNNlV.ulVal = sLV.UNStateProxyManger.ulVal;
		lV = ClrTrModeProxyTransport(pv,sLV.UchStateCmd);//Now Total Clr
		sLV.UNNlV.uchAr[3] = TGT_T1_PHS__RQ_TRANSPORT_RESULT_TR__OBJ_HS;
		
		//If Activation OK change Phase
		
		//((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = sLV.UNStateProxyManger.ulVal;
	}
	else
	{
		sLV.chCmdAnswer = 0;
		//Analis Error
		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		sLV.UNNlV.ushAr[0] = lV & (TR_MODE_OCS_MSK|STT_STOP_OCS_MSK); 
		if(sLV.UNNlV.ushAr[0] == 0)
		goto RetStateProxyManger;//Don`t active
		lV = ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING];
		//if((unsigned long)lV >= VAL_TRANSPORT_TRANSMIT) goto RetStateProxyManger;
		if(
		//(lV <= VAL_TRANSPORT_TRANSMIT) && 
		(lV >0)
		)
		goto RetStateProxyManger;
		//if(sLV.UNNlV.ushAr[0]== ((TR_MODE_OCS_MSK|STT_STOP_OCS_MSK)))
		//sLV.chCmdAnswer++;//Stop Life Counter???
		//And Transmition Fhase
		lV = ((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[sLV.chSelStateCmd];
		if (lV == 0) goto RetStateProxyManger;
		if (lV > 0x80)
		sLV.chCmdAnswer++;
		if(sLV.chCmdAnswer>0)
		{
			sLV.UNNlV.uchAr[1] = ERR__OVERRUN_FAIL_TRANSPORT__TGT_T1_PHS4;
			sLV.UNStateProxyManger.uchAr[1] = ERR__OVERRUN_FAIL_TRANSPORT__TGT_T1_PHS4;
			lV = ClrTrModeProxyTransport(pv,TR_MODE_OCS_ONB);
		}
		else
		goto RetStateProxyManger;//Busy Input Msg
		
	}

//Select Next State Try Realize it???
//	if (
//	(sLV.chCmdReq == CMD_REQ_T1_TR_DATA)&&
//	(sLV.UchCounterChangeState<3)
//	//&&() Self Timer
//	//&&() Self Etc.
//	)
	{

		sLV.UNStateProxyManger.ulVal = sLV.UNNlV.ulVal;//?? Change Phase
		

	}




RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)
}

long ExecT1HsPhs3 (void* pv, long lV)//Ok
{
register void *pvPrxMngState;
struct 
	{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	

	sLV.chSelStateCmd = ORD_SEL_TGT_T1_HS_PHS_3;//
	//Now Detect from Phase
	sLV.UchCounterChangeState =  ((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[(sLV.chSelStateCmd)];
//Control Self DeadLock
	if(sLV.UchCounterChangeState>= 3)//Init State??/ Init no more then 3 ones
	{
		sLV.UNStateProxyManger.uchAr[1] = ERR__OVERRUN_LIMIT_INIT__TGT_T1_PHS;//Ischrpan  Limit Starta
		//((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
		goto RetStateProxyManger;
	}
//Control Self LifeTimer
//---//-----
//Control Self State
// ----// ----

//Control chCmdReq
//sLV.chCmdReq = ((ProxyMangerStateDsc*)pvPrxMngState)->arUchStateCmd[sLV.chSelStateCmd];//Now
sLV.chCmdReq = CMM_GET_TRANSPORT_TR_COBJ_HS_FROM_HM;//Comman for Transmittig

	
//Control chCmdAnswer
sLV.chCmdAnswer = 0;//Simply clear
//----//----

//Select Next State Try Realize it???
//	if (
//	(sLV.chCmdReq == CMM_TR_COBJ_HS_TO_HM)&&
//	(sLV.UchCounterChangeState<3)
//	//&&() Self Timer
//	//&&() Self Etc.
//	)
	{
		sLV.UNStateProxyManger.uchAr[3] = TGT_T1_PHS_WAIT_CMM_MSG;
		//TGT_T1_PHS_WAIT_ANSW__TRANSPORT_RESULT__HS;//Change Phase
		((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq = sLV.chCmdReq;
		((ProxyMangerStateDsc*)pvPrxMngState)->arUchCounterChangeStateCmd[ORD_SEL_TGT_T1_HS_PHS_3] =
		sLV.UchCounterChangeState +1;
		//SendPrMngMsg
		pv = (void*)&hldCmmMsg;
		((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0] = sLV.chCmdReq;
		
		//Activate Queue
		if(ReqTransmitSettingsPrMng<EXEC)
		ReqTransmitSettingsPrMng = START;//Control you Permit Activate 
		//else Error Activation
	}
//Desigion Point
RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)

}

long GetLifeCtrPrMngStng(long idTgt, long idPhs)
{
	return lPhsLifeCtr;
}
	
long DPTgtT1PhsWaitCmmMsg  (void* pv, long lV) @ "Fast_function" //lV Input Command pv PrMng Or United Proxy
{
register void *pvPrxMngState;

struct 
	{
		char  chNeedClrMsg;
		//unsigned char UchStateCmd,UchCounterChangeState;
		//char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		short shV;
		long lV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger;//,UNNlV;
// /sLV.chCmdAnswer = 0;	sLV.chCmdReq = 0;
sLV.pOriginProxyManagerUnitDsc = pv;//
pvPrxMngState = pv;
	//pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	
	sLV.chNeedClrMsg = sLV.shV = 0; //UNNlV.ulVal = lV;
	//sLV.UchStateCmd = 0;




//Modify Self State if only allowed 	

//Else Modify 
switch (lV)//Detect posibility ;//	 pch[0] = i;
 	{
		case  CMM_RDY_RV_OBJ_HM: //EQU if (TGT == xx && phase == yy && cmd == CCC )
			sLV.chNeedClrMsg++;
			// sLV.chSelStateCmd = TGT_T1_PHS_WAIT_CMD_HM;//TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS;
			//Activate Proxy
			//pv  = &(hldPrTrptSettings.hldrAcpuCMUnitState);
			//lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
			lV = ActivateTRStngPrTpt((void*)&testSettigsState,0);
			 
			//Prosto Set New State if not Errors
			UNStateProxyManger.uchAr[3] = TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS;//TGT_T1_PHS_CTRL_TPT__TR_STNG_OBJ__HS;
			//Activate Queue
			//if(ReqTransmitStngPrTpt<EXEC)
			//ReqTransmitStngPrTpt = START;//Control you Permit Activate 
			
		break;
		case  CMM_TRANSPORT_RV_OBJ_OK_HM:
			sLV.chNeedClrMsg++;
			UNStateProxyManger.uchAr[3] = 0;//TGT_T2_PHS_TR__RQ_WRITE_COBJ_OOBJ__HS;
			UNStateProxyManger.uchAr[2] = TGT_HM_DATA_T1_COBJ_OOBJ_HM_HS;
			
		break;
		case  CMM_TRANSPORT_RV_OBJ_ERR_HM:
			sLV.chNeedClrMsg++;
			UNStateProxyManger.uchAr[3] = TGT_T1_PHS_TR__RQ_TR_STNG_OBJ__HS ;
		break;
		
//		case   CMM_SET_TGT_2_HM_HS:
//			sLV.chNeedClrMsg++;
//			UNStateProxyManger.uchAr[2] = TGT_WR_DATA_T1_COBJ_OOBJ_HM;
//			UNStateProxyManger.uchAr[3] = 0;//Init State
//		break;
		

 	default:
	;
	}
	if(sLV.chNeedClrMsg)
	hldCmmMsgRV.UNNHdrMsg. ulAr  [0] = 0;//Need Clear Receive Msg
return UNStateProxyManger.ulVal;
}
//This Function for Control Receive Ext Msg and possible  change state
long ExecT1HsPhsWaitCmmMsg(void* pv, long lV)//
{
register void *pvPrxMngState;
struct 
	{
		//char chRetCode;
		unsigned char UchStateCmd,UchCounterChangeState;
		char chCmdReq,chCmdAnswer,chSelStateCmd;//chIdxStateCmd;
		union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
	sLV.pOriginProxyManagerUnitDsc = pv;//
	pvPrxMngState = &(((UnitedProxyUnitDsc*)pv)->hldPrMng);
	sLV.UNStateProxyManger.ulVal = ((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger;
	
//Control Self DeadLock

//Control Self LifeTimer
if (lPhsLifeCtr) lPhsLifeCtr--; sLV.UNNlV.ulVal = lPhsLifeCtr;
//For Detect Need 2 param long - Id Conteiner long Phase & Target
	if(sLV.UNNlV.ulVal != 0)
	{
		;//Ok Can Wait
	}
	else
	{
		;//Time Out
		lPhsLifeCtr = 0;sLV.UNStateProxyManger.uchAr[1] = sLV.UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;
		goto RetStateProxyManger;
	}	

//



	if (chUsehldCmmMsgRV==0)
	{
		sLV.chCmdReq =  hldCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.chCmdReq==0) 
		goto RetStateProxyManger;//Look Input Cmd
		sLV.UNNlV.ulVal = sLV.UNStateProxyManger.ulVal;
		sLV.UNNlV.ulVal    =  DPTgtT1PhsWaitCmmMsg(pvPrxMngState,sLV.chCmdReq);
		if (sLV.UNNlV.ulVal != sLV.UNStateProxyManger.ulVal)
		lPhsLifeCtr = 100000;
		
	}
	else
	{
		goto RetStateProxyManger;//Busy Input Msg
		
	}
	
//Control Self State
	
//Control chCmdAnswer
//Activate Answer

//Select Next State Try Realize it???
//	if (
//	(sLV.chCmdReq == CMD_REQ_T1_TR_DATA)&&
//	(sLV.UchCounterChangeState<3)
//	//&&() Self Timer
//	//&&() Self Etc.
//	)
	{
		sLV.UNStateProxyManger.ulVal = sLV.UNNlV.ulVal;//?? Change Phase
		//((ProxyMangerStateDsc*)pvPrxMngState)->chCmdReq = sLV.chCmdReq;
		//
		//sLV.UchCounterChangeState +=1; Now don`t control amount Change
		//((ProxyMangerStateDsc*)pvPrxMngState)->
		//arUchCounterChangeStateCmd[ORD_SEL_TGT_T1_HS_PHS_2] = sLV.UchCounterChangeState
		

	}
	
//Desigion Point
RetStateProxyManger:
	((ProxyMangerStateDsc*)pvPrxMngState)->ulStateProxyManger = 
	sLV.UNStateProxyManger.ulVal;
	return sLV.UNStateProxyManger.ulVal;//State and Desigion(solution)  
	

}


//Function for Modification Proxy state & exec

long TrySetSendStngEct  (void* pv, long lV)
{
//Simply Control Is Transmition Work?
return  lV = ECT_SEND_STNG_FROM_HM;
//And Other Param Allowed or Not allowed Transmittion

}
long SetSendReqTrStngEct(void* pv, long lV) @ "Fast_function"
{
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
if ((UNNlV.uchAr[3] == ECT_WAIT_CMD_HS)
|| UNNlV.uchAr[3] == 0
)//Control Posibility for change state
{
//SendPrMngMsg
		//pv = (void*)&hldCmmMsg;
		//((CmmMsgDsc*)pv)->
		hldCmmMsg.UNNHdrMsg.uchAr[0] = CMM_GET_STNG_OBJ_FROM_HM;//CMM_TR_COBJ_HM_TO_HS;//
		
		//Activate Queue
		if(ReqTransmitSettingsPrMng<EXEC)
		ReqTransmitSettingsPrMng = START;//Control you Permit Activate 
		
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
		UNNlV.uchAr[3] = ECT_CREATE_CMM_TR_COBJ_HM_TO_HS;
		//lV = UNNlV.uchAr[0];
		//lV = ~(RV_CMD_DIS_MSK);
		//UNNlV.uchAr[0] = lV;
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
		lV  = UNNlV.ulVal;//Save Exec State
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
		
		//if(UNNlV.uchAr[3] < 0xff)
		UNNlV.ushAr[1] = 0;//    //Tis code I should insert as once i've stall App Lyer
		UNNlV.ushAr[0] = 0xffff; // hldrTpCnState.uchLpuHSU2State get in 1 and Interrupt never clear T uchLpuHSU2State.
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal; //Thus ProxyManeger reach block State. It was surprize.?.
	UNNlV.ulVal = lV;//Restore Exec State
}

	return UNNlV.uchAr[3];
}

//////////////////////////////////////////////////////////////////
long DpcsPrMngMsg  (void* pv, long lV) @ "Fast_function"
{
struct 
	{
		char  chNeedClrMsg;
		short shV;
		//long lV;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0;	
sLV.chNeedClrMsg = sLV.shV =  0;
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);

	switch (lV)//Detect posibility ;//	 pch[0] = i;
 	{

		case  CMM_ :  //CMM_GET_STNG_OBJ_FROM_HM: Stub Now
			sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
			lV =  TrySetSendStngEct(pv,sLV.shV); // ECT_SEND_STNG_FROM_HM  Activate Transport from 
			// UNNlV.uchAr[3] = lV;
		break;
		//case  CMM_TR_COBJ_HM_TO_HS: //ECT_SEND_REQ_TR_STNG_FROM_HS  :  //ECT_REQ_ACTIVATE_RV
		////case  ECT_CREATE_CMM_TR_COBJ_HM_TO_HS:
		//	sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
		//	lV =   SetSendReqTrStngEct(pv,sLV.shV); //  Activate Transport from 
		//	// UNNlV.uchAr[3] = lV;
		//break;
		
		

 	default:
	;
	}
	//Change Stste
	if ( lV )
	{
		if (lV != UNNlV.uchAr[3])
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
			
	if(sLV.chNeedClrMsg)
	hldCmmMsgRV.UNNHdrMsg. ulAr  [0] = 0;//Need Clear Receive Msg
return UNNlV.ulVal;


}


#define RV_CMD_DIS_MSK    (1<<0)
//ExecTargetProxyManager(pv,lV)
long ExecCmdPrMng (void* pv, long lV) @ "Fast_function"
{
//register long j;
struct 
	{
		short  shVl;
		char   chRes;
		//void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		//PFL_VL pfl_vl;
		//void *pvPrMng,*pvCmmMsg;
	} sLV;
union 
	{
		unsigned char   uchAr [4];//Bit Field
		unsigned short  ushAr [2];//Task & Phase
		unsigned long   ulVal;
	}UNNlV;
	UNNlV.ulVal = 0; sLV.shVl = 0;sLV.chRes = 0;
	
//Dec Life Counter
//Control Self LifeTimer
UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
	if (UNNlV.ulVal != 0)
	//if(sLV.UNNlV.ulVal != 0)// UNNlV.ulVal; UNNlV.ulVal = lPhsLifeCtr;
	{
		if(UNNlV.uchAr[3] < 0xff)
		UNNlV.ulVal--;//Ok Can Wait
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
	}
	else
	{
		;//Time Out
		lV = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		lV |= (PM_STT_STOP_OCS_MSK | PM_STT_ERROR_OCS_MSK);
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = lV;
		UNNlV.ulVal = ((ProxyMangerStateDsc*)pv)-> ulStateProxyManger;
		UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;
		((ProxyMangerStateDsc*)pv)-> ulStateProxyManger = UNNlV.ulVal;
		goto RetStateProxyManger;
	}	




lV = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	if ( (chUsehldCmmMsgRV==0) && ((lV&RV_CMD_DIS_MSK)== 0) )
	{
		sLV.shVl =  hldCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.shVl !=0)//Hndl Inp Msg
		{
			UNNlV.ulVal = DpcsPrMngMsg(pv,sLV.shVl);//Desigion Point Change State
			 //;
			if (UNNlV.ulVal != lV)//(((ProxyMangerStateDsc*)pv)->ulStateProxyManger)
			{
							
				sLV.chRes = UNNlV.uchAr[3];//Fix Change State
			}
		
		}

		
	}
	//else
	//{
	//	goto RetStateProxyManger;//Busy Input Msg
	//	
	//}
	UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	switch (UNNlV.uchAr[3])
 	{
		case  ECT_WAIT_CMD_HS: // ECT  Execute
			//Call Hundler
			WaitCmdHmEct(pv,sLV.shVl);
		break;
		//case  ECT_WRITE_COBJ_OOBJ_HM:
		//;//	 Do nothing Now
		//break;
		//case  ECT_CMP_COBJ_OOBJ_HM:  // Diagnostic Result 
		//	//First Init Proxy       //
		//			
		//;//	
		//break;
		//.case  ECT_SEND_STNG_FROM_HM:  // Diagnostic Result
		//.	//First Init Proxy
		//.	lV = SetSendStngEct(pv,0);//Activate Transport	
		//.	UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
		//.	lV = UNNlV.uchAr[0];
		//.	lV = ~(RV_CMD_DIS_MSK);
		//.	UNNlV.uchAr[0] = lV;
		//.	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
		//.
		break;
		case  ECT_SEND_REQ_TR_STNG_FROM_HS: //You must be sure that req hundled
			 sLV.shVl = hldrTRStngPrMngCTpuUnit.TrCnHldr.SizeAppObj;
			if ((ReqTransmitSettingsPrMng<EXEC) && sLV.shVl)//Succesful Send
			{
				hldrTRStngPrMngCTpuUnit.TrCnHldr.SizeAppObj  = 0;//Clear Size Msg
				lV = ActivateRvStngPrTpt((void*)&testSettigsState,ID_EXEC_CMD_PR_MNG_CALL);
				UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
				lV = UNNlV.uchAr[0];
				lV &= ~(RV_CMD_DIS_MSK);
				UNNlV.uchAr[0] = lV;
				(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal; 
				UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
				UNNlV.ushAr[1] = 0x0;
				//UNNlV.uchAr[1] &=0x8;
				(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
		    }
		break;



		 	
 	default:
		 UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger) ;
	UNNlV.uchAr[3] = ECT_WAIT_CMD_HM;//?
	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
	
RetStateProxyManger:

	return  sLV.chRes;
}

long  WaitCmdHmEct(void* pv, long lV)
{
// Insert Wait Phase
	return lV;
}
long SetSendStngEct(void* pv, long lV)
{
// Insert Activation Function
	return lV;
}


long ActivateRvStngPrTpt(void* pObjParam, long lV)
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptSettings;
	;
	//Detect Self
	;
	//If Possible change State
	;
		
	if(lV == ID_UPDATE_RV_PR_TPT_STNG_CALL)
	{
		if (
		(((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] == 1)
		|| (
		(((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] > 0)&&
		(((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] > 0x80)
		)
		)
		{
		lV = 0;
		goto RetActivateRvStngPrTpt;//try activate when transport success terminate
		}
		
	}
	//Look Transport
	pv  = (void*)& hldPrTrptSettings.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateRvStngPrTpt;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateRvStngPrTpt;
	}

	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|RV_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVStngTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchRV = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//
	((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
    ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT;
lStngOrderNumRvFragment = 0;

//hldrTRStngPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;

RetActivateRvStngPrTpt:

return lV;//

}
long ActivateTrStngPrTpt(void* pObjParam, long lV)
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptSettings;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptSettings.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateTrStngPrTpt;
	}
	
	if(lV&(TR_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateTrStngPrTpt;
	}	
	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|TR_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVStngTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchTR = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//

//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = (-1);
 lStngOrderNumTrFragment = 0;lReciveStngAckGood = 1;
hldrTRStngTransportCTpuUnit.TrCnHldr.SizeAppObj  = 0;
RetActivateTrStngPrTpt:

return lV;//

}
long ActivateTransmitStngObj(void)	
{

 return ActivateTRStngPrTpt((void*)&testSettigsState,0);

}
long ActivateTransmitYustObj(void)
{

 return SendYustTbl();
}


long ActivateReceiveStngObj(void)
{

 return 0;
}
long GetStngTbl(void)
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptSettings;
	//Look Transport
	pv  = (void*)& hldPrTrptSettings.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtGetStngTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtGetStngTbl;
	}
//Prepea Transport
//Control State transport

//Activate Proxy
    lV = ActivatePrMngSettings();
pv = (void*)&hldPrMngSettings;
//Put Request in queue
if (lV)
// hldCmmMsgRV.UNNHdrMsg.uchAr[0] = ECT_REQ_ACTIVATE_RV;
 lV =  SetSendReqTrStngEct(pv,ECT_CREATE_CMM_TR_COBJ_HM_TO_HS);
if (lV)
{
 hldPrTrptSettings.arUchResultExecCmd[2] = 0; 
 hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 0;
 }
//Control Ok or Error
//Call Func Control State PrMng + Pr Tpt
//Return Val 1-OK 2-Error 0- No Data
//
RetPtGetStngTbl:
 return lV;
}

long ActivateReceiveYustObj(void)
{

 return GetYustTbl();
}
long SendStngTbl(void)
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptSettings;
	//Look Transport
	pv  = (void*)& hldPrTrptSettings.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtSendStngTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtSendStngTbl;
	}
//Prepea Transport
//Control State transport
//ActivateTransmitStngObj();
 lV =  ActivateTrStngPrTpt((void*)&testSettigsState,0);


RetPtSendStngTbl:
 return lV;

}

void DbgModifyPrMng(void* pv, long lV)
{
struct 
	{
		//char chRetCode;
		ProxyMangerStateDsc* pProxyMangerStateDsc;
		
		void  *pOriginProxyManagerUnitDsc;//, *pOriginTpCn;
		
	} sLV;
union 
		{
			unsigned char   uchAr [4];//Bit Field
			unsigned short  ushAr [2];//Task & Phase
			unsigned long   ulVal;
		}UNStateProxyManger,UNNlV;
	sLV.pOriginProxyManagerUnitDsc = pv;
	sLV.pProxyMangerStateDsc       = pv;
	if( (pv==0) || (lV==0))
	return;
	UNNlV.ulVal = lV;
	if(UNNlV.uchAr[0]&1)
	{
		UNStateProxyManger.ulVal = sLV.pProxyMangerStateDsc ->ulStateProxyManger;
		UNStateProxyManger.uchAr[1] = 0;//Clear ERror State
		sLV.pProxyMangerStateDsc ->ulStateProxyManger = UNStateProxyManger.ulVal;
	}
	
	switch(UNNlV.uchAr[1])
	{
		case ID__ACTIVATEPRMNGSETTINGS:
			ActivatePrMngSettings();
		break;
		case ID_PASSSETTINGSPRMNGRVMSGORIGIN :
			PassSettingsPrMngRvMsgOrigin();
		break;
		case ID__ACTIVATE_TRANSMIT_SETTINGS :
			ActivateTransmitStngObj();
		break;
		case ID_ACTIVATE_TRANSMIT_YUST  :
			ActivateTransmitYustObj();
		break;
		case ID__ACTIVATE_RECEIVE_SETTINGS:
			ActivateReceiveStngObj();
		break;
		case ID__ACTIVATE_RECEIVE_YUST :
			ActivateReceiveYustObj();
		break;
		case ID__GET_STNG_TBL:
			GetStngTbl();//7
		break;
		case ID__SEND_STNG_TBL:
			SendStngTbl();//8
		break;
		
		case ID__GET_STNG_TBL_EXAMPLE:
			ReqGetSettingsBMExample();//9
		break;
		case ID__SEND_STNG_TBL_EXAMPLE:
			ReqSendSettingsBMExample();//10
		break;
		case ID__GET_YUST_TBL_EXAMPLE:
		    ReqGetYustBMExample();    //11
		break;
		case ID__SEND_YUST_TBL_EXAMPLE:
		    ReqSendYustBMExample();  //12
		break;
		case ID__GET_PRT_TBL_EXAMPLE:
		    ReqGetPrtTblBRExample(); //13
		break;
		case ID__SEND_PRT_TBL_EXAMPLE:
		    ReqSendPrtTblBRExample();  //14
		break;
		
	
		default:
		;
	}


}

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqGetSettingsBM(long lActivation, void* pSettingsStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса на получение  настроек с BM            ~~~~~
//~~~                                                                  ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pSettingsStateDsc  - По данному адресу в случае успеха будет помещен указатель
//~~~   на структуру _ описыввающую                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//==================================================================================
//Body func                                      
//==================================================================================
char   ReqGetSettingsBM(long lActivation, void* pSettingsStateDsc)
{
    register long i;
	register long j;
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pSettingsStateDsc == 0) 
	return ERROR_EXEC;

	if (lActivation == 1)
	{
		//`````````````````````````````````````````````````````````````````````
		//`` Check adress correctnes 
		//`` check size corectness
		//..................................................................... 
		//i = ((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings ;
		if( (((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings) < (SIZE_SETTINGS_ICI))
		return  ERROR_EXEC;
		j = (long)((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings;
		//unnV1.ulVal = (long)testSettigsState.p_current_settings;
		if( (j&((long)pSettingsStateDsc))
		|| (j&0x777fffff)
		)
		{
			i = 1;
		}
		else
		return ERROR_EXEC;
	
		j = 0;
		//Control State Proxy Mng
		i = hldPrMngSettings.shPrMngConState;
		if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
		{
			i = hldPrMngSettings.ulStateProxyManger; i >>= 24;
			if( (i == 0) || (i == ECT_SEND_REQ_TR_STNG_FROM_HS) )//Phase where data not send from HS
			j++;//State Exec
		}
		//Control State transport
		//i = hldPrTrptSettings.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
		i = hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = 0;
			((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = (void*)0;
			j++;
			
		}
		if(j)
		i = STATE_EXEC;
		else
		{
		    //((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = 0;
			//((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = (long*)0;
			//.holderProxySettingsUnit.hldObjParam.size_Obj = ((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings; 
			//.holderProxySettingsUnit.hldObjParam.p_ObjEntity = 
			//.((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings;
			testSettigsState.size_current_settings = ((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings;
			testSettigsState.p_current_settings    = ((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings;
			i =  GetStngTbl();//ActivateProxySettings();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		// i = hldPrTrptSettings.hldrAcpuCMUnitState.AppObjConState;
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
		i = hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    j = 0;
			((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = //lSizeOf_Settings;
			testSettigsState.size_current_settings;
			((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = 
			//(long*)&holderSettings.UNSettings.chArSettings[0];
			testSettigsState.p_current_settings;
			i = hldPrTrptSettings.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		    if(i>10)
	        {
		    	((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = 0;
		    	((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = (void*)0;
		    	j++;
		    	
		    }
			i = hldPrTrptSettings.hldrAcpuCMUnitState.AppObjConState;
			if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK) )
			  j++; 
			  
			i = hldPrMngSettings.shPrMngConState;
			if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
			{
			     i = hldPrMngSettings.ulStateProxyManger; i >>= 24;
			     if( (i == 0) || (i == ECT_SEND_REQ_TR_STNG_FROM_HS) )//Phase where data not send from HS
			     j++;//State Exec
			}
			if(hldPrMngSettings.ulLifeCtrEct)
			j++;
			
			
		    if(j)
		    {
			i = STATE_EXEC;
			return i;
			}
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArSettingsData;
			if( (hldPrTrptSettings. arUchResultExecCmd[2] >0)
				&&(hldPrTrptSettings. arUchResultExecCmd[2]<0x80)
			)
			{
				
				//Check CheckSum
				i =  SUCCESS_EXEC;
				
			}
			else
			i  = ERROR_EXEC;
			
		}
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqSendSettingsBM(long lActivation, void* pSettingsStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса на получение  настроек с BM            ~~~~~
//~~~                                                                  ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pSettingsStateDsc  - По данному адресу в случае успеха будет помещен указатель
//~~~   на структуру _total_measurement описыввающую                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                          ~~~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                       ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//==================================================================================
//Body func                                      
//==================================================================================
char   ReqSendSettingsBM(long lActivation, void* pSettingsStateDsc)
{
    register long i;
	
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pSettingsStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		i = hldPrTrptSettings.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
	    {
			((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = 0;
			((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = (void*)0;
			
			i = STATE_EXEC;
		}
		else
		{
		    //((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = 0;
			//((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = (long*)0;
			//.holderProxySettingsUnit.hldObjParam.size_Obj = ((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings; 
			//.holderProxySettingsUnit.hldObjParam.p_ObjEntity = 
			//.((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings;
			testSettigsState.size_current_settings = ((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings;
			testSettigsState.p_current_settings    = ((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings;
			i =  SendStngTbl();//ActivateProxySettings();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		 i = hldPrTrptSettings.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((SettingsStateDsc*)pSettingsStateDsc)-> size_current_settings      = //lSizeOf_Settings;
			testSettigsState.size_current_settings;
			((SettingsStateDsc*)pSettingsStateDsc)-> p_current_settings = 
			//(long*)&holderSettings.UNSettings.chArSettings[0];
			testSettigsState.p_current_settings;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArSettingsData;
			if( (hldPrTrptSettings. arUchResultExecCmd[1] >0)
				&&(hldPrTrptSettings. arUchResultExecCmd[1]<0x80)
			)
			{
				i =  SUCCESS_EXEC;
			}
			
		}
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

static char chStateExecReqGetSettings = 0;
long ReqGetSettingsBMExample(void)  
{
	register long i=0;
	SettingsStateDsc locSettingsStateDsc;
if ( chStateExecReqGetSettings == 0)
	{
		locSettingsStateDsc.size_current_settings = SIZE_SETTINGS_ICI;//testSettigsState.size_current_settings;
		locSettingsStateDsc.p_current_settings    = (void*)&hldStngIciTbl;//testSettigsState.p_current_settings;
		i =   ReqGetSettingsBM(1,&locSettingsStateDsc);//
		if (i != ERROR_EXEC)
		{
			chStateExecReqGetSettings = 1;//Start Execution
		}
		else chStateExecReqGetSettings = 0;
	}
	if (chStateExecReqGetSettings == 1 )
	{
		i =   ReqGetSettingsBM(0,&locSettingsStateDsc);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateExecReqGetSettings = SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
			if (i== ERROR_EXEC)
			chStateExecReqGetSettings = 0;
			else
			chStateExecReqGetSettings = 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateExecReqGetSettings == SUCCESS_EXEC)
	{
		;//See data
	}


return chStateExecReqGetSettings;

}

static char chStateReqSendSettings = 0;
long ReqSendSettingsBMExample(void)  
{
	register long i=0;
	SettingsStateDsc locSettingsStateDsc;
if ( chStateReqSendSettings == 0)
	{
		locSettingsStateDsc.size_current_settings = testSettigsState.size_current_settings;
		locSettingsStateDsc.p_current_settings    = testSettigsState.p_current_settings;
		i =   ReqSendSettingsBM(1,&locSettingsStateDsc);//ReqGetSettingsBM
		if (i != ERROR_EXEC)
		{
			chStateReqSendSettings = 1;//Start Execution
		}
		else chStateReqSendSettings = 0;
	}
	if (chStateReqSendSettings == 1 )
	{
		i =   ReqSendSettingsBM(0,&locSettingsStateDsc);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateReqSendSettings = SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqSendSettingsBM(1,&locSettingsStateDsc);
			if (i== ERROR_EXEC)
			chStateReqSendSettings = 0;
			else
			chStateReqSendSettings = 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateReqSendSettings == SUCCESS_EXEC)
	{
		;//See data
	}



	return chStateReqSendSettings;


}

/*


if ( chStateExec == 0)
		{
			locSettingsStateDsc.size_current_settings = testSettigsState.size_current_settings;
			locSettingsStateDsc.p_current_settings    = testSettigsState.p_current_settings;
			i =  ReqGetSettingsBM(1,&locSettingsStateDsc);
			if (i != ERROR_EXEC)
			{
				chStateExec = 1;//Start Execution
			}
			else chStateExec = 0;
		}
		if (chStateExec == 1 )
		{
			i =  ReqGetSettingsBM(0,&locSettingsStateDsc);
			switch(i)
			{
				case SUCCESS_EXEC:
				chStateExec = SUCCESS_EXEC;
				break;
				case ERROR_EXEC:
				i =  ReqGetSettingsBM(1,&locSettingsStateDsc);
				if (i== ERROR_EXEC)
				chStateExec = 0;
				else
				chStateExec = 1;
				break;
				
				default:
				;
			
			}
			
		
		}
		if (chStateExec == SUCCESS_EXEC)
		{
			;//See data
		}



*/
/*





*/



