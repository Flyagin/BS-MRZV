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
* File Name       : MnPrYust.c
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
#include    "MnPrYust.h"



char chUsehldYustCmmMsgRV = 0;

CmmMsgDsc hldYustCmmMsgRV,hldYustCmmMsgTR;






extern char chStateArYustData ;
extern int TestReqTransmitArYust;
extern int TestReqReceiveArYust;


extern long lSizeOf_Yust ;
extern YustHldDsc holderYust;

YustStateDsc testYustState = {
sizeof(YustHldDsc),
(void*)&holderYust
};



int  ReqTransmitYustPrMng;
int  ReqReceiveYustPrMng;



long ActivateYustPrMng(void)
{
	register long i;
	void* pv;
	i = ID_YUST_PR_MNG;
	
	i = hldPrMngYust.shPrMngConState;
	if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
	return 0;
	 pv = (void*)&hldPrMngYust;
	i =  ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
	 i |= (PM_STT_USING_OCS_MSK)|(PM_STT_START_OCS_MSK);
	((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
	hldrTRYustPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;//???
	(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = (unsigned long)(-1);
	
//
//  ((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderSettings.UNSettings.chArSettings[0];//
//

	//Set Transport
	return i;
}	
long WorkYustPrMng (void* pv, long lV) @ "Fast_function" //State control & Definions
{
register long i = 0;
//register long j;
    if(lV == PM_STT_START_OCS_ONB)
    {
       
		i = ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
		i |= PM_STT_WORK_OCS_MSK;
		((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
		//Now it is all cmd
    	//i = ExecCmdProxySettings(pv,ACTIVATE_FILL_DATA);
		
    }
	if(lV == PM_STT_WORK_OCS_ONB)
    {
       

		i =  ExecYustCmdPrMng (pv,lV);// i = ExecTargetProxyManager(pv,lV);ExecCmdYustPrTpt

    }
	if(lV == PM_STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init

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
//
 int  ReqTransmitYustPrMng;
 int  ReqReceiveYustPrMng;
#define ID_YUST_PR_MNG 0X12
ProxyMangerStateDsc  hldPrMngYust = {
ID_YUST_PR_MNG,
0,
WorkYustPrMng,ExecYustCmdPrMng,
{0,0,0,0,0,0,0,0, 0,0 }, 
{0,0,0,0,0,0,0,0, 0,0 },
0,0,0
};
//Settings Input Param
ObjParamDsc hldTestYustParam = {
sizeof(holderYust),
(void*)&holderYust
};
extern TRFrgDsc TrFrg;

long lReciveAckGood = 0;
RVFrgDsc RvFrg = {
0,ID_TPT_CMD_ACK_RV_FRAGMENT,0,(char*)0,(char*)0
};
void ActivateSendAck(void)
{
 ReqTransmitYustPrTpt = START;//Activate Sesion
 if(hldrTpCnState.uchTpState_CNL_HSU2 == 0 )
  hldrTpCnState.uchTpState_CNL_HSU2 ++;//Select Channel
  TrFrg.IdTRFrgCmd = ID_TPT_CMD_ACK_RV_FRAGMENT;
}
extern int txsize_U2;
long ExecCmdYustPrTpt (void* pv, long lV) @ "Fast_function"
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
if(ReqReceiveYustPrTpt==0 ) return 1;
ReqReceiveYustPrTpt--;
        sLV.chRetCode = 0;
		pch = (char *)&(hldrRVYustTransportCTpuUnit.RvCnHldr);//holderRVSettingsCTpuUnit);//?
		sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pch)->ulRvCount;
		pch = (char *)&(hldrRVYustTransportCTpuUnit.arUchRV); //RvCnHldr.pUchRV);
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
		
		switch (sLV.chRetCode )
		{
		case 1:
			i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
			i += j;
			((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
			if (j)
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT;
			ActivateSendAck();//Activate ACK
			
			break;
		case 2://
			i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
			i += j;
			((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 1;
			//Call function That Set apropriate data
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = 1;//??? OK
			//Signal of the End Conection 
			sLV.chRetCode = 0;
		ActivateSendAck();//Activate ACK
		
			break;
			
		case 0://
		
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 3;
			//Call function That fix Error state Proxy and array Data
			((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[2] = ERR_OBJECT_RECEIVE_SIZE;
			if(hldPrMngYust.ulLifeCtrEct)
			hldPrMngYust.ulLifeCtrEct = 5;
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
		    ((ProxyTransportStateDsc*)pv)-> arUchResultExecCmd[1] = ERR_TRANSPORT_WAITING_DATA;
			//Error
			((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;
			return 0;//Stop Transmittion
		}
 		//else
 		//{
 		//    //Control Transmitting
 		//	return 1;
 		//
 		//	
 		//}
		if(
				(ReqTransmitYustPrTpt==0)&&//TestReqTransmit ==0 //Out From Queue Ses Leyer
				(txsize_U2==0)&&lReciveAckGood&& //Transmition through Phys canel
				(hldrHSU2LpduTRUnit.uchLpuHSU2State== 0)//Data out from Link Leyer
		)
		{
			if ( ulCtrDecompouseYustTptUnitHSU2 ==  ulCtrTransmitLpduHSU2
			)
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
				j = hldrTRYustTransportCTpuUnit.TrCnHldr.SizeAppObj;
				if(j>3)//SizeOf Header
				j -= 3;
				lV += j;
			
				((BaseAcpuCMUnitDsc*)pv)->ulTrCount = lV;
				if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
				return 1;

			}
			 //Look Ack
			if(lReciveAckGood)
			{
			 ReqTransmitYustPrTpt = START;//Activate Sesion
			 TrFrg.IdTRFrgCmd = ID_TPT_CMD_TR_FRAGMENT;//
			 hldrTpCnState.uchTpState_CNL_HSU2  = 1;//Select Channel
			 ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = VAL_TRANSPORT_TRANSMIT;
			lReciveAckGood = 0;
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
long WorkYustPrTpt (void* pv, long lV) @ "Fast_function"
{
register long i = 0;
register long j;
PFL_VL pfl_vl;
if(lV == STT_START_OCS_ONB)
    {
        ((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[2] = 0;
		//ResetProxyTransport(pv, lV); or Clr State CMD + Res + TMRS
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
		  
		 
		  //lV = ExecCmdProxyTransport(pv,j);
		   pfl_vl = ((BaseAcpuCMUnitDsc*)pv)-> pf_ExecCmd;i = (long)pfl_vl;
		   if (i)
		   lV = pfl_vl(pv,j);
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
		//lV = 0;
		//if( ((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[1] == 1 )
		//lV |= 1;
		//if( ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] == 2
		//)
		//lV |= 2;//Transmit Coimplete
		lV = 0;
		if( ((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[2] == 1 )
		lV |= 1;
		if( ((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] == 1
		)
		lV |= 2;//Transmit Coimplete
		//Receive Complete
		
    	//Check success execute & stop if needed
		if(lV == 3)
		{
			//Clear Proxy State
			if(hldPrMngYust.ulLifeCtrEct)
			hldPrMngYust.ulLifeCtrEct = 3;
		}
		
    }

return i;

}

#define ID_YUST_PR_TRANSPORT 0X13
ProxyTransportStateDsc hldPrTrptYust = {
ID_YUST_PR_TRANSPORT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
//InitProxyTransport,ResetProxyTransport,WorkProxyTransport,ExecCmdProxyTransport,
InitProxyTransport,ResetProxyTransport,WorkYustPrTpt,ExecCmdYustPrTpt,


// arUchExecCmd[4] = {
                   {0,0,0,0}, {0,0,0,0}, {0,0,0,0}
//{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 }
};
int  ReqTransmitYustPrTpt;
int  ReqReceiveYustPrTpt;

long lOrderNumFragment;

TRFrgDsc TrFrg = {
0,ID_TPT_CMD_TR_FRAGMENT,0,(char*)0,(char*)0
};

void ActivateServTrApCnYustTptUnitFragmentHSU2(void)
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



pv  = (void*)&hldPrTrptYust.hldrAcpuCMUnitState;//& holderProxySettingsUnit;
//testSettigsState
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
	 TrFrg.pSrc = pch;
	 TrFrg.pDst = &(hldrTRYustTransportCTpuUnit.arUchTR[0]);

  //Reset Connect State
   pv  = (void*)& (hldrTRYustTransportCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
  // j +=  sizeof(char) + sizeof(short);//Cmd  + OrdNumFrame <-Aux Info Fragment
   
   if( (j+3) > SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1)
    {
		j = SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1-2;
		j -= sizeof(char) + sizeof(short);
    }
   
    TrFrg.uchTR_C = j;//
    TrFrg.uShOrderNumFrg = ++lOrderNumFragment;
   i = CreateTRFragment((void*)& TrFrg);
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf  =  SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1;
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = i;//j
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_YUST_PR_TRANSPORT;//
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*) TrFrg.pDst;//pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void TerminateServiceApCnPrYustTptFragment(void)
{
//register void *pv;
//register long i;
  //pv  = (void*)& (holderTR10PeriodCTpuUnit.TrCnHldr);
  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  hldrTRYustTransportCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  //holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj = 
}
void ActivateServTrApCnYustTptUnitHSU2Ack(void)
{

//register long i,j;
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
	pch   = (char*) &(hldrTRYustTransportCTpuUnit.arUchTR[0]);
	pch [0] = ID_TPT_CMD_ACK_RV_FRAGMENT;//((TRFrgDsc*)pvTRFrgDsc)->IdTRFrgCmd;
	//unnV1.ushAr[0] = ((TRFrgDsc*)pvTRFrgDsc)->uShOrderNumFrg;
	pch[1] = (RvFrg.uShOrderNumFrg)&0xff;//unnV1.uchAr[0];
	pch[2] = (RvFrg.uShOrderNumFrg)>>8;//unnV1.uchAr[1];
	pch[3] = RvFrg.uchTR_C;//Last Fragment




  //Reset Connect State
   pv  = (void*)& (hldrTRYustTransportCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   

   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf  =  SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1;
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = 4;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_YUST_PR_TRANSPORT;//
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch; //TrFrg.pDst;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}

void TerminateServiceApCnPrYustTptAck(void)
{
//register void *pv;
//register long i;
  //pv  = (void*)& (holderTR10PeriodCTpuUnit.TrCnHldr);
  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  hldrTRYustTransportCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  //holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj = 
}
unsigned long ulCtrDecompouseYustTptUnitHSU2 = 10;//TransmitLpduHSU2
void ActivateServTrApCnYustTptUnitHSU2(void)
{



if (TrFrg.IdTRFrgCmd == ID_TPT_CMD_ACK_RV_FRAGMENT)
ActivateServTrApCnYustTptUnitHSU2Ack();
else
ActivateServTrApCnYustTptUnitFragmentHSU2();



   
}

void TerminateServiceApCnPrYustTpt(void)
{
if (TrFrg.IdTRFrgCmd == ID_TPT_CMD_ACK_RV_FRAGMENT)
TerminateServiceApCnPrYustTptAck();
else
TerminateServiceApCnPrYustTptFragment();
if (ulCtrDecompouseYustTptUnitHSU2 != ulCtrTransmitLpduHSU2)
	  ulCtrDecompouseYustTptUnitHSU2 =  ulCtrTransmitLpduHSU2;
}



void PrepDecompouseYustTptUnitHSU2(void) @ "Fast_function"
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
	if(ReqTransmitYustPrTpt)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2>>4;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitYustPrTpt==START)
			{
				ActivateServTrApCnYustTptUnitHSU2();
				ReqTransmitYustPrTpt = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitYustPrTpt==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRYustTransportCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitYustPrTpt = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitYustPrTpt = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitYustPrTpt==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnPrYustTpt();
					ReqTransmitYustPrTpt = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

void ActivateServTrApCnYustPrMngHSU2(void) @ "Fast_function"
{

register long i,j;
register char *pch;
register void* pv;

pv = (void*)&hldYustCmmMsgTR;j = 0;
i =  ((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0];

//Detect Type Msg
	switch (i)
 	{
 	
	case CMD_REQ_REMOUT_RST         :

	case CMM_GET_YUST_OBJ_FROM_HM : //
	pch = (char *)&(hldrTRYustPrMngCTpuUnit.arUchTR);
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
		pch = (char *)&(hldrTRYustPrMngCTpuUnit.arUchTR);
		pv  = ((CmmMsgDsc*)pv)->p_ObjEntity; //(void*)& holderSrcSamplesUnit;
		j = ((CmmMsgDsc*)pv)->size_Obj;//sizeof(SrcSamplesUnitDsc);
		for (i = 0; i < j; i++)
		{
			pch[i] = ((char*)pv)[i];
		}
	}
	else j = 1;//One Byte


  //Reset Connect State
   pv  = (void*)& ( hldrTRYustPrMngCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf  =  SIZE_TPDU_YUST_PR_MNG_CNL_HSU2;
   if( j> SIZE_TPDU_YUST_PR_MNG_CNL_HSU2)
   j = SIZE_TPDU_YUST_PR_MNG_CNL_HSU2;//Don`t Send Very Big Msg
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_YUST_PR_MNG;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
  
   
   
}
void TerminateServiceApCnYustPrMng(void)
{
//register void *pv;
//register long i;

  hldrTRYustPrMngCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  hldrTpCnState.uchTpState_CNL_HSU2 += 2;//For Debug Pupouses only 

}
void PrepDecompouseYustPrMngHSU2(void) @ "Fast_function"
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
	if(ReqTransmitYustPrMng)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_YUST_PR_MNG_CNL_HSU2;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitYustPrMng==START)
			{
				ActivateServTrApCnYustPrMngHSU2();
				ReqTransmitYustPrMng = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitYustPrMng==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRYustPrMngCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitYustPrMng = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitYustPrMng = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitYustPrMng==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnYustPrMng();
					ReqTransmitYustPrMng = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


long PassYustPrMngRvMsgOrigin(void);
long PassYustPrMngRvMsg(void* pvLDC, long lID) @ "Fast_function"
{
register long i;
register void* pv;	
//pv  = (void*)hldrRVStngPrMngCTpuUnit.RvCnHldr;	
//pch = (char *)&( hldrRVStngPrMngCTpuUnit.arUchRV);	
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	hldrRVYustPrMngCTpuUnit.RvCnHldr.ulRvCount  = lID;
	//lID = 3?;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;
	pv  = (void*)& ( hldrRVYustPrMngCTpuUnit.arUchRV);
	
	for (i = 0; i < lID; i++)
	{
		((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	
	return PassYustPrMngRvMsgOrigin();
}
long PassYustPrMngRvMsgOrigin(void) @ "Fast_function"
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
	sLV.pvPrMng  = (void*)& hldPrMngYust;
	sLV.pvCmmMsg = (void*)& hldrRVYustPrMngCTpuUnit;
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
			
			pv  = (void*)& hldrRVYustPrMngCTpuUnit.RvCnHldr;
			j = ((RVBaseCTpuUnitDsc*)pv)-> ulRvCount;//Size of Message
			
			pv  = (void*)& hldYustCmmMsgRV.UNNHdrMsg;//Prepea for hundling 
			 pch = (char *)&( hldrRVYustPrMngCTpuUnit.arUchRV);
			
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
	hldrRVYustPrMngCTpuUnit.RvCnHldr.ulRvCount = 0;//
	
//ExitPassSettingsPrMngRvMsgOrigin:
return sLV.uChIdxByte;
}



























//Function for Modification Proxy state & exec

long TryYustSetSendEct  (void* pv, long lV)
{
//Simply Control Is Transmition Work?
return   ECT_SEND_YUST_FROM_HS;
//And Other Param Allowed or Not allowed Transmittion

}
long SetYustSendEct(void* pv, long lV) @ "Fast_function"
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
		hldYustCmmMsgTR.UNNHdrMsg.uchAr[0] = CMM_GET_YUST_OBJ_FROM_HM;//CMM_TR_COBJ_HM_TO_HS;//
		
		//Activate Queue
		if(ReqTransmitYustPrMng<EXEC)
		ReqTransmitYustPrMng = START;//Control you Permit Activate 
		
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
		UNNlV.uchAr[3] = ECT_SEND_REQ_TR_YUST_FROM_HS;
		//lV = UNNlV.uchAr[0];
		//lV = ~(RV_CMD_DIS_MSK);
		//UNNlV.uchAr[0] = lV;
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
}

	return UNNlV.uchAr[3];
}

//////////////////////////////////////////////////////////////////
long DpcsYustPrMngMsg   (void* pv, long lV) @ "Fast_function"
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

		case  CMM_GET_YUST_OBJ_FROM_HM :  //CMM_GET_STNG_OBJ_FROM_HM: Stub Now
			sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
			lV =  TryYustSetSendEct(pv,sLV.shV); //   Activate Transport from 
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
	hldYustCmmMsgRV.UNNHdrMsg. ulAr  [0] = 0;//Need Clear Receive Msg
return UNNlV.ulVal;


}




#define RV_CMD_DIS_MSK    (1<<0)
//
long ExecYustCmdPrMng  (void* pv, long lV) @ "Fast_function"
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
		UNNlV.uchAr[1] = ERR__TIMEOUT__TGT_T1_PHS2;//???
		((ProxyMangerStateDsc*)pv)-> ulStateProxyManger = UNNlV.ulVal;
		goto RetStateProxyManger; 
	}	




lV = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
	if ( (chUsehldCmmMsgRV==0) && ((lV&RV_CMD_DIS_MSK)== 0) )
	{
		sLV.shVl =  hldYustCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.shVl !=0)//Hndl Inp Msg
		{
			UNNlV.ulVal = DpcsYustPrMngMsg(pv,sLV.shVl);//Desigion Point Change State
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
			 WaitYustCmdHmEct(pv,sLV.shVl);
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
		case  ECT_SEND_REQ_TR_YUST_FROM_HS: //You must be sure that req hundled
			 sLV.shVl = hldrTRYustPrMngCTpuUnit.TrCnHldr.SizeAppObj;
			if ((ReqTransmitYustPrMng<EXEC) && sLV.shVl)//Succesful Send ReqTransmitSettingsPrMng
			{
				hldrTRYustPrMngCTpuUnit.TrCnHldr.SizeAppObj  = 0;//Clear Size Msg
				lV = ActivateYustRvPrTpt((void*)&testYustState,0); 
				UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
				lV = UNNlV.uchAr[0];
				lV = ~(RV_CMD_DIS_MSK);
				UNNlV.uchAr[0] = lV;
				(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal; 
				UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulLifeCtrEct);
				UNNlV.ushAr[1] = 0x1;(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = UNNlV.ulVal;
		    }
		break;



		 	
 	default:
		 UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger) ;
	UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;//ECT_WAIT_CMD_HM;//???
	(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
	
RetStateProxyManger:

	return  sLV.chRes;
}

long  WaitYustCmdHmEct (void* pv, long lV)
{
// Insert Wait Phase May be remake
	return lV;
}
//long SetYustSendStngEct(void* pv, long lV)
//{
//// Insert Activation Function
//	return lV;
//}















long ActivateYustRvPrTpt(void* pObjParam, long lV) @ "Fast_function"
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptYust;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptYust.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateRvYustPrTpt;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateRvYustPrTpt;
	}

	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|RV_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVYustTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchRV = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//
	((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
    ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT;
//

//hldrTRYustPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;

RetActivateRvYustPrTpt:

return lV;//

}
long ActivateYustTrPrTpt(void* pObjParam, long lV) @ "Fast_function"
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptYust;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptYust.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateTrYustPrTpt;
	}
	
	if(lV&(TR_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateTrYustPrTpt;
	}	
	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|TR_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVYustTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchTR = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//
	lOrderNumFragment = 0;
	lReciveAckGood = 1;//Permit Send First Pacet whithOut Ack
	
//((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = (-1);

hldrTRYustTransportCTpuUnit.TrCnHldr.SizeAppObj  = 0;
RetActivateTrYustPrTpt:

return lV;//

}

#define SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 40
long UpdateRVPrTptYust(void* pvLDC, long lID) @ "Fast_function"
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
		long ReqReceiveYustPrTpt; 
	} sLV;
union 
	    {
	    	unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;
	    }unnV1;	
RVBaseCTpuUnitDsc locRVBaseCTpuUnit;

	
	
   sLV.chNeedClrSesData = 0;	 
 //`````````````````````````````````````````````````````````````````````
 //``Init Ack control  part
 sLV.ReqReceiveYustPrTpt    = ReqReceiveYustPrTpt;
 sLV.chACKGood =  sLV.chNeedActivateProxyTpt = 0;
 sLV.pOriginLDC             = pvLDC;
 sLV.ReqReceiveYustPrTpt = ReqReceiveYustPrTpt;
//`` 
//.....................................................................
 
if (ReqReceiveYustPrTpt>=1)//This part of code need as as previous buf need iteretivly  move to proxy
{
//~locRVBaseCTpuUnit = hldrRVYustTransportCTpuUnit.RvCnHldr;
//~locRVBaseCTpuUnit.pUchRV = (hldrRVYustTransportCTpuUnit.arUchRV);//Buffer Addr
//~i = MoveCTputoAppObj((void*)&hldPrTrptYust.hldrAcpuCMUnitState,
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
	pv  = (void*)&hldrRVYustTransportCTpuUnit.arUchRV;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	if( lID > (long)(SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 ))
	lID = (long)(SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 );
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//  unnV1.uchAr[3] = lID;//Save amount Extract Data
	
	//Activate App For
	sLV.ReqReceiveYustPrTpt ++;//Activate Decoder Analice
	//Clear All Ses Data
	hldrRVYustTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	hldrRVYustTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
	hldrRVYustTransportCTpuUnit.RvCnHldr.ConState         = 0;
	hldrRVYustTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;//ReqReceiveYustPrTpt++;
	
} 
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&hldrRVYustTransportCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&hldrRVYustTransportCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	
		if ( i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			//;
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 -2))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 -2) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
		
			pvLDC = (void*)i;
			i = (long)&hldrRVYustTransportCTpuUnit.arUchRV;
		
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&hldrRVYustTransportCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 -2))
			{
				// pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				// i = ((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange;i++;
				//((TotMeasGHldDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
					if (lID == (long)(SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 -2))
					{
						//Activate App Func
						sLV.ReqReceiveYustPrTpt ++;//Activate Decoder Analice
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
			pv  = (void*)&hldrRVYustTransportCTpuUnit.RvCnHldr;
		
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
	}		
		
}

if(sLV.ReqReceiveYustPrTpt)
{


     pvLDC  = sLV.pOriginLDC ;
     //frg.uchTR_C        = ((LDCIDsc*)pvLDC)->uchTR_C;
     pv  = (void*)&hldrRVYustTransportCTpuUnit.arUchRV;
     
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
     			if(TrFrg.uchTR_C== unnV1.uchAr[2])
     			sLV.chACKGood++;
     			if(TrFrg.uShOrderNumFrg == frg.uShOrderNumFrg)
     			sLV.chACKGood++;
				
				if (sLV.chACKGood>= 2)
				lReciveAckGood++;//Inform Proxy ACK Good
				
     		break;
     		case ID_TPT_CMD_TR_FRAGMENT:
     			//Inform Proxy About Req Data
				hldrRVYustTransportCTpuUnit.RvCnHldr.ulRvCount -= 3;//Size of Header
				RvFrg.IdTRFrgCmd = i;
				RvFrg.uShOrderNumFrg =  frg.uShOrderNumFrg;
				RvFrg.uchTR_C = hldrRVYustTransportCTpuUnit.RvCnHldr.ulRvCount ;
				
				//Activate Create and transmit Ack Pac
				ReqReceiveYustPrTpt++;
				
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
		//Try activate Proxy Transport if not activated
		i = ActivateYustRvPrTpt((void*)&testYustState ,0);
	}
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;

return lID;//

}




long GetYustTbl(void) @ "Fast_function"
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptYust;
	//Look Transport
	pv  = (void*)& hldPrTrptYust.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtGetYustTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtGetYustTbl;
	}
//Prepea Transport
//Control State transport

//Activate Proxy
    lV = ActivateYustPrMng();
pv = (void*)&hldPrMngYust;
//Put Request in queue
if (lV)
// hldCmmMsgRV.UNNHdrMsg.uchAr[0] = ECT_REQ_ACTIVATE_RV;
 lV =  SetYustSendEct(pv,ECT_CREATE_CMM_TR_COBJ_HM_TO_HS);
//Control Ok or Error
//Call Func Control State PrMng + Pr Tpt
//Return Val 1-OK 2-Error 0- No Data
//
RetPtGetYustTbl:
 return lV;
}


long SendYustTbl(void) @ "Fast_function"
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptYust;
	//Look Transport
	pv  = (void*)& hldPrTrptYust.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtSendYustTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtSendYustTbl;
	}
//Prepea Transport
//Control State transport
//ActivateTransmitStngObj();
 lV =  ActivateYustTrPrTpt((void*)&testYustState,0);


RetPtSendYustTbl:
 return lV;

}




//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqGetYustBM(long lActivation, void* pYustStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса на получение  юстировочных чисел  с BM            ~~~~~
//~~~                                                                          ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pYustStateDsc  - По данному адресу в случае успеха будет помещен указатель
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
char   ReqGetYustBM(long lActivation, void* pYustStateDsc) @ "Fast_function"
{
    register long i;
	register long j;
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pYustStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		j = 0;
		//Control State Proxy Mng
		i = hldPrMngYust.shPrMngConState;
		if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
		{
			i = hldPrMngYust.ulStateProxyManger; i >>= 24;
			if( (i == 0) || (i == ECT_SEND_YUST_FROM_HS) )//Phase where data not send from HS
			j++;//State Exec
		}
		//Control State transport
		//i = hldPrTrptYust.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
		i = hldPrTrptYust.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS      = 0;
			((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS = (void*)0;
			j++;
			
		}
		if(j)
		i = STATE_EXEC;
		else
		{
		    //((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS      = 0;
			//((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS = (long*)0;
			//.holderProxyYustUnit.hldObjParam.size_Obj = ((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS; 
			//.holderProxyYustUnit.hldObjParam.p_ObjEntity = 
			//.((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS;
			testYustState.size_ustuvannja_BS = ((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS;
			testYustState.p_ustuvannja_BS    = ((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS;
			i =  GetYustTbl();//ActivateProxyYust();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		// i = hldPrTrptYust.hldrAcpuCMUnitState.AppObjConState;
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
		j = 0;
		i = hldPrTrptYust.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			j++;
			
		}
		if(hldPrMngYust.ulLifeCtrEct)
			j++;
			
		
		if(j)
		    {
			i = STATE_EXEC;
			//return i;
			}
		else
		{
		    
			((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS      = //lSizeOf_Yust;
			testYustState.size_ustuvannja_BS;
			((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS = 
			//(long*)&holderYust.UNYust.chArYust[0];
			testYustState.p_ustuvannja_BS;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArYustData;
			if( (hldPrTrptYust. arUchResultExecCmd[2] >0)
				&&(hldPrTrptYust. arUchResultExecCmd[2]<0x80)
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



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqSendYustBM(long lActivation, void* pYustStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса на отправку  юстировочных чисел на  BM            ~~~~~
//~~~                                                                        ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pYustStateDsc  - По данному адресу в случае успеха будет помещен указатель
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
char   ReqSendYustBM(long lActivation, void* pYustStateDsc) @ "Fast_function"
{
    register long i;
	
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pYustStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		i = hldPrTrptYust.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
	    {
			((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS      = 0;
			((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS = (void*)0;
			
			i = STATE_EXEC;
		}
		else
		{
		    //((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS      = 0;
			//((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS = (long*)0;
			//.holderProxyYustUnit.hldObjParam.size_Obj = ((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS; 
			//.holderProxyYustUnit.hldObjParam.p_ObjEntity = 
			//.((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS;
			testYustState.size_ustuvannja_BS = ((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS;
			testYustState.p_ustuvannja_BS    = ((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS;
			i =  SendYustTbl();//ActivateProxyYust();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		 i = hldPrTrptYust.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((YustStateDsc*)pYustStateDsc)-> size_ustuvannja_BS      = //lSizeOf_Yust;
			testYustState.size_ustuvannja_BS;
			((YustStateDsc*)pYustStateDsc)-> p_ustuvannja_BS = 
			//(long*)&holderYust.UNYust.chArYust[0];
			testYustState.p_ustuvannja_BS;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArYustData;
			if( (hldPrTrptYust. arUchResultExecCmd[1] >0)
				&&(hldPrTrptYust. arUchResultExecCmd[1]<0x80)
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

static char chStateExecReqGetYust= 0;
long ReqGetYustBMExample(void)  
{
	register long i=0;
	YustStateDsc locYustState;
if ( chStateExecReqGetYust== 0)
	{
		locYustState.size_ustuvannja_BS = testYustState.size_ustuvannja_BS;
		locYustState. p_ustuvannja_BS   = testYustState.p_ustuvannja_BS  ;
		i =   ReqGetYustBM(1,&locYustState);//
		if (i != ERROR_EXEC)
		{
			chStateExecReqGetYust= 1;//Start Execution
		}
		else chStateExecReqGetYust= 0;
	}
	if (chStateExecReqGetYust== 1 )
	{
		i =   ReqGetYustBM(0,&locYustState);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateExecReqGetYust= SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqGetYustBM(1,&locYustState);
			if (i== ERROR_EXEC)
			chStateExecReqGetYust= 0;
			else
			chStateExecReqGetYust= 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateExecReqGetYust== SUCCESS_EXEC)
	{
		;//See data
	}


return chStateExecReqGetYust;

}

static char chStateReqSendYust= 0;
long ReqSendYustBMExample(void)  
{
	register long i=0;
	YustStateDsc locYustState;
if ( chStateReqSendYust== 0)
	{
		locYustState.size_ustuvannja_BS = testYustState.size_ustuvannja_BS;
		locYustState. p_ustuvannja_BS   = testYustState.p_ustuvannja_BS;   
		i =   ReqSendYustBM(1,&locYustState);//ReqGetSettingsBM
		if (i != ERROR_EXEC)
		{
			chStateReqSendYust= 1;//Start Execution
		}
		else chStateReqSendYust= 0;
	}
	if (chStateReqSendYust== 1 )
	{
		i =   ReqSendYustBM(0,&locYustState);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateReqSendYust= SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqSendYustBM(1,&locYustState);
			if (i== ERROR_EXEC)
			chStateReqSendYust= 0;
			else
			chStateReqSendYust= 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateReqSendYust== SUCCESS_EXEC)
	{
		chStateReqSendYust = 0;//See data
	}
	else chStateReqSendYust = 0;



	return chStateReqSendYust;


}



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long CreateTRFragment(void* pvTRFrgDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:   
//~~~         Put in SesBuf Transmittion Fragment = Data + Description Wrap                          
//~~~      
//~~~ Processing:
//~~~ Take           ~~~
//~~~           ~~~
//~~~           ~~~
//~~~           ~~~
//~~~ 
//~~~                                     ~~~
//~~~ Outputs:
//~~~             None                                                     ~~~
//~~~ Returns:                                                             ~~
//~~~       Size Processing Data  
//``````````````````````````````````````````````````````````````````````````````````
//~~~ Notes:                                 ~~
//~~~    None                                                                     ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long CreateTRFragment(void* pvTRFrgDsc)  @ "Fast_function"
{
register long i,j;
register char *pSrc,*pDst;
struct 
	{
		unsigned char uchTR_C;
		unsigned char uChIdxByte ;
		//unsigned char uChIdxBit ;
		//short shErr;
		unsigned short ushSizeTrFragm;
		
	    //.unsigned char *pUchTR;//
		
		
	} sLV;
union 
    {
    	unsigned char   uchAr [4];
    	unsigned short  ushAr [2];
        unsigned long   ulVal;
    }unnV1;
	
	sLV.ushSizeTrFragm = 0;
	//long status = (-1); //_ERROR;
	pSrc = (char*) ((TRFrgDsc*)pvTRFrgDsc)->pSrc;
	pDst = (char*) ((TRFrgDsc*)pvTRFrgDsc)->pDst;
	//`````````````````````````````````````````````````````````````````````
	//`` Put Header  
	//`` Fragmenta
	//..................................................................... 
	pDst[0] = ((TRFrgDsc*)pvTRFrgDsc)->IdTRFrgCmd;
	unnV1.ushAr[0] = ((TRFrgDsc*)pvTRFrgDsc)->uShOrderNumFrg;
	pDst[1] = unnV1.uchAr[0];
	pDst[2] = unnV1.uchAr[1];
	
	sLV.uChIdxByte     += 3;
	sLV.ushSizeTrFragm += 3; 
	j = ((TRFrgDsc*)pvTRFrgDsc)->uchTR_C; 
	//`````````````````````````````````````````````````````````````````````
	//`` 
	//`` 
	//..................................................................... 
   	for (i = 0;i< (j);i++)
    {

         //`````````````````````````````````````````````````````````````````````
         //`` 
         //..................................................................... 
        
        //`````````````````````````````````````````````````````````````````````
		//`` 
		//.....................................................................
         pDst[3+i] = pSrc[i];     
            
		
    }
	//`````````````````````````````````````````````````````````````````````
	//``  Only continue if channel is ok
	//..................................................................... 
	
	
	return sLV.ushSizeTrFragm+j; 
}
//---------------------------------------------------------------------------------






















