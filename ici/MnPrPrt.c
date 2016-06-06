/*------------------------------------------------------------------------------
* Created (c) 2013 - Factory “KyivPrylad”
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
* File Name       : MnPrPrt.c
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
#include    "MnPrPrt.h"



char chUsehldPrtTblCmmMsgRV = 0;

CmmMsgDsc hldPrtTblCmmMsgRV,hldPrtTblCmmMsgTR;




PrtTblHldDsc holderPrtTbl = {

 {"Prt Tbl HS Processor"}
//{SIZE_PRT}
};

//holderPrtTbl.UNPrtTbl.PrtTbl = {0x4444};


//
long lSizeOf_PrtTbl = sizeof(SIZE_PRT);



extern char chStateArPrtTblData ;
extern int TestReqTransmitArPrtTbl;
extern int TestReqReceiveArPrtTbl;


extern long lSizeOf_PrtTbl ;
extern PrtTblHldDsc holderPrtTbl;

PrtTblStateDsc testPrtTblState = {
sizeof(PrtTblHldDsc),
(void*)&holderPrtTbl
};



int  ReqTransmitPrtTblPrMng;
int  ReqReceivePrtTblPrMng;

















long ActivatePrtTblPrMng(void)  @ "Fast_function"
{
	register long i;
	void* pv;
	i = ID_PRT_PR_MNG;
	
	i = hldPrMngPrtTbl.shPrMngConState;
	if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
	return 0;
	 pv = (void*)&hldPrMngPrtTbl;
	i =  ((ProxyMangerStateDsc*)pv)-> shPrMngConState;
	 i |= (PM_STT_USING_OCS_MSK)|(PM_STT_START_OCS_MSK);
	((ProxyMangerStateDsc*)pv)-> shPrMngConState = i;
	hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;//???
	(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = (unsigned long)(-1);
	
//
//  ((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderSettings.UNSettings.chArSettings[0];//
//

	//Set Transport
	return i;
}	
long WorkPrtTblPrMng (void* pv, long lV)  @ "Fast_function" //State control & Definions
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
		(((ProxyMangerStateDsc*)pv)->ulLifeCtrEct) = (-1);
    }
	if(lV == PM_STT_WORK_OCS_ONB)
    {
       

		i =  ExecPrtTblCmdPrMng (pv,lV);// i = ExecTargetProxyManager(pv,lV);ExecCmdPrtTblPrTpt

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
 int  ReqTransmitPrtTblPrMng;
 int  ReqReceivePrtTblPrMng;
#define ID_PRT_PR_MNG 0X15
ProxyMangerStateDsc  hldPrMngPrtTbl = {
ID_PRT_PR_MNG,
0,
WorkPrtTblPrMng,ExecPrtTblCmdPrMng,
{0,0,0,0,0,0,0,0, 0,0 }, 
{0,0,0,0,0,0,0,0, 0,0 },
0,0,0
};
//Settings Input Param
ObjParamDsc hldTestPrtTblParam = {
sizeof(holderPrtTbl),
(void*)&holderPrtTbl
};




extern volatile  long spi0_txsize, spi0_rxsize;//int txsize_U2;
long ExecCmdPrtTblPrTpt (void* pv, long lV)  @ "Fast_function"
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
if(ReqReceivePrtTblPrTpt==0 ) return 1;
ReqReceivePrtTblPrTpt--;
        sLV.chRetCode = 0;
		pch = (char *)&(hldrRVPrtTblTransportCTpuUnit.RvCnHldr);//holderRVSettingsCTpuUnit);//?
		sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pch)->ulRvCount;pch = (char *)&(hldrRVPrtTblTransportCTpuUnit.arUchRV); //RvCnHldr.pUchRV);
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
			#ifdef BS_G45_FL_RL 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT;
			#else
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT<<5;
			#endif
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
		
			break;
			
		case 0://
		
			//Signal of the End Conection 
			((ProxyTransportStateDsc*)pv)-> arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 1;
			//Call function That fix Error state Proxy and array Data
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
		pch = (char *)&hldrTRPrtTblTransportCTpuUnit.TrCnHldr;
		if(
				//TestReqTransmit ==0 //Out From Queue Ses Leyer
				(hldrTpCnState.chTotalLDC_CNL_Spi<2)&&//???(spi0_txsize==0)&& //Transmition through Phys canel
				(hldrSpiLpduTRUnit.uchLpuSpiState== 0)//Data out from Link Leyer
		)
		{
			//pv  = (void*)& holderProxyTotMeasUnit;
			lV = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;
			if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
			{
				((ProxyTransportStateDsc*)pv)->  arUchResultExecCmd[1] = 1;//
				((BaseAcpuCMUnitDsc*)pv)-> AppObjConState |= STT_STOP_OCS_MSK;
				((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = 2;
				return 0;//Stop Transmittion 
			}
			else 
			{
     			//ID_TEN_PERIOD_SAMPLES_UNIT;
				sLV.ushSizePacket = ((TRBaseCTpuUnitDsc*)pch)->SizeAppObj;
				lV += hldrTRPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj;
				((BaseAcpuCMUnitDsc*)pv)->ulTrCount = lV;
				((TRBaseCTpuUnitDsc*)pch)->SizeAppObj = 0;
				if ((unsigned long)lV>= (((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal))
				return 1;

			}
			 i = 0;
			if( ((BaseAcpuCMUnitDsc*)pv)->ulTrCount == 0 )
			i++;//First Packet
			if(
			sLV.ushSizePacket && (((TRBaseCTpuUnitDsc*)pch)->pUchTR==0)//
			)
			i++;
			
			if (i)
			{ ReqTransmitPrtTblPrTpt = START;//Activate Sesion
			 if(hldrTpCnState.uchTpState_CNL_Spi==0)
			 hldrTpCnState.uchTpState_CNL_Spi  = 1;//Select Channel This is only for speed up activating Transmittion???
			 ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = VAL_TRANSPORT_TRANSMIT<<1;
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
long WorkPrtTblPrTpt (void* pv, long lV)  @ "Fast_function"
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
			if(hldPrMngPrtTbl.ulLifeCtrEct)
			hldPrMngPrtTbl.ulLifeCtrEct = 3;
		}
		
    }

return i;

}
//long InitProxyTransport (void* pv, long lV)
//{
//return 0; 
//}
//long ResetProxyTransport (void* pv, long lV)
//{
//((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
//    ((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
//    ((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = 0;
//    ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
//    ((BaseAcpuCMUnitDsc*)pv)->pUchRV    = (unsigned char*)0;
//    ((BaseAcpuCMUnitDsc*)pv)->pUchTR    = (unsigned char*)0;
//	for (lV = 0; lV < 4; lV++)
//	{
//		((ProxyTransportStateDsc*)pv)->arUchExecCmd      [lV] = 0;
//		((ProxyTransportStateDsc*)pv)->arU32LifeCtr      [lV] = 0;
//		((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[lV] = 0;
//	}
//	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
//	return 0;
//}



#define ID_PRT_PR_TRANSPORT 0X16
ProxyTransportStateDsc hldPrTrptPrtTbl = {
ID_PRT_PR_TRANSPORT,
0,0,0,0,0,
(unsigned char*)0,(unsigned char*)0,
//(PFL_VL)0,(PFL_VL)0,(PFL_VL)0,(PFL_VL)0
//InitProxyTransport,ResetProxyTransport,WorkProxyTransport,ExecCmdProxyTransport,
InitProxyTransport,ResetProxyTransport,WorkPrtTblPrTpt,ExecCmdPrtTblPrTpt,


// arUchExecCmd[4] = {
                   {0,0,0,0}, {0,0,0,0}, {0,0,0,0}
//{0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0 }
};
int  ReqTransmitPrtTblPrTpt;
int  ReqReceivePrtTblPrTpt;



void ActivateServTrApCnPrtTblTptUnitSpi(void)  @ "Fast_function"
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
pv  = (void*)&hldPrTrptPrtTbl.hldrAcpuCMUnitState;//& holderProxySettingsUnit;
//testSettigsState
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
  //Reset Connect State
   pv  = (void*)& (hldrTRPrtTblTransportCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_TRANSPORT_PRT_CNL_SPI;
   if( j> SIZE_TPDU_TRANSPORT_PRT_CNL_SPI)
   j = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI) -4;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_PRT_PR_TRANSPORT;//
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void TerminateServiceApCnPrPrtTblTpt(void)  @ "Fast_function"
{
//register void *pv;
//register long i;
  //pv  = (void*)& (holderTR10PeriodCTpuUnit.TrCnHldr);
  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  hldrTRPrtTblTransportCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  //holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj = 
}
void PrepDecompousePrtTblTptUnitSpi(void)  @ "Fast_function"
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
	if(ReqTransmitPrtTblPrTpt)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = SIZE_TPDU_TRANSPORT_PRT_CNL_SPI;//>>2;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitPrtTblPrTpt==START)
			{
				ActivateServTrApCnPrtTblTptUnitSpi();
				ReqTransmitPrtTblPrTpt = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitPrtTblPrTpt==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRPrtTblTransportCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitPrtTblPrTpt = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitPrtTblPrTpt = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitPrtTblPrTpt==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnPrPrtTblTpt();
					ReqTransmitPrtTblPrTpt = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

void ActivateServTrApCnPrtTblPrMngSpi(void)  @ "Fast_function"
{

register long i,j;
register char *pch;
register void* pv;

pv = (void*)&hldPrtTblCmmMsgTR;j = 0;
i =  ((CmmMsgDsc*)pv)->UNNHdrMsg.uchAr[0];

//Detect Type Msg
	switch (i)
 	{
 	
	case CMD_REQ_REMOUT_RST         :

	case CMM_GET_PRT_TBL_OBJ_FROM_HR : //
	pch = (char *)&(hldrTRPrtTblPrMngCTpuUnit.arUchTR);
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
		pch = (char *)&(hldrTRPrtTblPrMngCTpuUnit.arUchTR);
		pv  = ((CmmMsgDsc*)pv)->p_ObjEntity; //(void*)& holderSrcSamplesUnit;
		j = ((CmmMsgDsc*)pv)->size_Obj;//sizeof(SrcSamplesUnitDsc);
		for (i = 0; i < j; i++)
		{
			pch[i] = ((char*)pv)[i];
		}
	}
	else j = 1;//One Byte


  //Reset Connect State
   pv  = (void*)& ( hldrTRPrtTblPrMngCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_SPI;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_SPI;// Logic can ctrl
   //j = //Size Msg
   if( j> SIZE_TPDU_PRT_PR_MNG_CNL_SPI)
   j = SIZE_TPDU_PRT_PR_MNG_CNL_SPI;//Don`t Send Very Big Msg
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf    = SIZE_TPDU_PRT_PR_MNG_CNL_SPI;
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_PRT_PR_MNG;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
  
   
   
}
void TerminateServiceApCnPrtTblPrMng(void)  @ "Fast_function"
{
//register void *pv;
//register long i;

  hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  hldrTpCnState.uchTpState_CNL_Spi += 2;//For Debug Pupouses only  uchTpState_CNL_HSU2

}
void PrepDecompousePrtTblPrMngSpi(void)  @ "Fast_function"
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
	if(ReqTransmitPrtTblPrMng)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_Spi;j = SIZE_TPDU_PRT_PR_MNG_CNL_SPI;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (ReqTransmitPrtTblPrMng==START)
			{
				ActivateServTrApCnPrtTblPrMngSpi();
				ReqTransmitPrtTblPrMng = EXEC;
			}
			//ProcessTransmit Obj
			if(ReqTransmitPrtTblPrMng==EXEC)
			{
				i = ServiceTRApCn2((void*)&hldrTRPrtTblPrMngCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					ReqTransmitPrtTblPrMng = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				ReqTransmitPrtTblPrMng = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (ReqTransmitPrtTblPrMng==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnPrtTblPrMng();
					ReqTransmitPrtTblPrMng = 0;
				}
			}
		}
		//Try another???
		
	}
	

}


long PassPrtTblPrMngRvMsgOrigin(void);
long PassPrtTblPrMngRvMsg(void* pvLDC, long lID)  @ "Fast_function"
{
register long i;
register void* pv;	
//pv  = (void*)hldrRVStngPrMngCTpuUnit.RvCnHldr;	
//pch = (char *)&( hldrRVStngPrMngCTpuUnit.arUchRV);	
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	hldrRVPrtTblPrMngCTpuUnit.RvCnHldr.ulRvCount  = lID;
	//lID = 3?;
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;
	pv  = (void*)& ( hldrRVPrtTblPrMngCTpuUnit.arUchRV);
	
	for (i = 0; i < lID; i++)
	{
		((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	
	return PassPrtTblPrMngRvMsgOrigin();
}
long PassPrtTblPrMngRvMsgOrigin(void)  @ "Fast_function"
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
	sLV.pvPrMng  = (void*)& hldPrMngPrtTbl;
	sLV.pvCmmMsg = (void*)& hldrRVPrtTblPrMngCTpuUnit;
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
			
			pv  = (void*)& hldrRVPrtTblPrMngCTpuUnit.RvCnHldr;
			j = ((RVBaseCTpuUnitDsc*)pv)-> ulRvCount;//Size of Message
			
			pv  = (void*)& hldPrtTblCmmMsgRV.UNNHdrMsg;//Prepea for hundling 
			 pch = (char *)&( hldrRVPrtTblPrMngCTpuUnit.arUchRV);
			
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
	hldrRVPrtTblPrMngCTpuUnit.RvCnHldr.ulRvCount = 0;//
	
//ExitPassSettingsPrMngRvMsgOrigin:
return sLV.uChIdxByte;
}



























//Function for Modification Proxy state & exec

long TryPrtTblSetSendEct  (void* pv, long lV)  @ "Fast_function"
{
//Simply Control Is Transmition Work?
return   ECT_SEND_PRT_TBL_FROM_HS;
//And Other Param Allowed or Not allowed Transmittion

}
long SetPrtTblSendEct(void* pv, long lV)  @ "Fast_function"
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
		hldPrtTblCmmMsgTR.UNNHdrMsg.uchAr[0] = CMM_GET_PRT_TBL_OBJ_FROM_HR;//CMM_TR_COBJ_HM_TO_HS;//
		
		//Activate Queue
		if(ReqTransmitPrtTblPrMng<EXEC)
		ReqTransmitPrtTblPrMng = START;//Control you Permit Activate 
		
		UNNlV.ulVal = (((ProxyMangerStateDsc*)pv)->ulStateProxyManger);
		UNNlV.uchAr[3] = ECT_SEND_REQ_TR_PRT_TBL_FROM_HS;
		//lV = UNNlV.uchAr[0];
		//lV = ~(RV_CMD_DIS_MSK);
		//UNNlV.uchAr[0] = lV;
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
}

	return UNNlV.uchAr[3];
}

//////////////////////////////////////////////////////////////////
long DpcsPrtTblPrMngMsg   (void* pv, long lV)  @ "Fast_function"
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

		case  CMM_GET_PRT_TBL_OBJ_FROM_HR :  //CMM_GET_STNG_OBJ_FROM_HM: Stub Now
			sLV.chNeedClrMsg++;//In this place hundlers for analise posibility Exec Cmd
			lV =  TryPrtTblSetSendEct(pv,sLV.shV); //   Activate Transport from 
			//if(lV)                FORBID CHANGE STATE !
			//UNNlV.uchAr[3] = lV;  FORBID CHANGE STATE !
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
		if ((((ProxyMangerStateDsc*)pv)->ulStateProxyManger) != UNNlV.ulVal)//if (lV != UNNlV.uchAr[3])
		(((ProxyMangerStateDsc*)pv)->ulStateProxyManger) = UNNlV.ulVal;
	}
			
	if(sLV.chNeedClrMsg)
	hldPrtTblCmmMsgRV.UNNHdrMsg. ulAr  [0] = 0;//Need Clear Receive Msg
return UNNlV.ulVal;


}




#define RV_CMD_DIS_MSK    (1<<0)
//
long ExecPrtTblCmdPrMng  (void* pv, long lV)  @ "Fast_function"
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
		sLV.shVl =  hldPrtTblCmmMsgRV.UNNHdrMsg.uchAr[0];//CmmMsgDsc
		if(sLV.shVl !=0)//Hndl Inp Msg
		{
			UNNlV.ulVal = DpcsPrtTblPrMngMsg(pv,sLV.shVl);//Desigion Point Change State
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
			 WaitPrtTblCmdHmEct(pv,sLV.shVl);
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
		case  ECT_SEND_REQ_TR_PRT_TBL_FROM_HS: //You must be sure that req hundled
			 sLV.shVl = hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj;
			if ((ReqTransmitPrtTblPrMng<EXEC) && sLV.shVl)//Succesful Send ReqTransmitSettingsPrMng
			{
				hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj  = 0;//Clear Size Msg
				lV = ActivatePrtTblRvPrTpt((void*)&testPrtTblState,0); 
				UNNlV.uchAr[3] = ECT_WAIT_CMD_HS;
				lV = UNNlV.uchAr[0];
				lV &= ~(RV_CMD_DIS_MSK);//Eable Receive Cmd
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

long  WaitPrtTblCmdHmEct (void* pv, long lV)  @ "Fast_function"
{
// Insert Wait Phase May be remake
	return lV;
}
//long SetPrtTblSendStngEct(void* pv, long lV)
//{
//// Insert Activation Function
//	return lV;
//}















long ActivatePrtTblRvPrTpt(void* pObjParam, long lV)  @ "Fast_function"
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateRvPrtTblPrTpt;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateRvPrtTblPrTpt;
	}

	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
	 lV |= USING_OCS_MSK|STT_START_OCS_MSK|RV_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
	
	//hldrRVPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchRV = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulRvCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulRvTotal = //16*(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI);
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//
	((ProxyTransportStateDsc*)pv)->arUchResultExecCmd[1] = 0;
    ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = VAL_TRANSPORT_WAIT<<4;
    ((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = 0;

//hldrTRPrtTblPrMngCTpuUnit.TrCnHldr.SizeAppObj = 0;

RetActivateRvPrtTblPrTpt:

return lV;//

}
long ActivatePrtTblTrPrTpt(void* pObjParam, long lV)  @ "Fast_function"
{
//register long i;//,j;
//register char *pSrc;//,*pDst;
register void* pv;


//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	;
	//Detect Self
	;
	//If Possible change State
	;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//sLV.UNNlV.ushAr[0] = lV;//
	
	//STT_WORK_OCS_MSK |TR_MODE_OCS_MSK; Look this maybe you must exlude start when transmit state
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetActivateTrPrtTblPrTpt;
	}
	
	if(lV&(TR_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetActivateTrPrtTblPrTpt;
	}	
	//lV = (i&(STT_WORK_OCS_MSK)) && ((i&( STT_STOP_OCS_MSK ))==0);<- Look Maybe already work?
//Dis Int

	
	
	//hldrRVPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj       = 0;//??
	((BaseAcpuCMUnitDsc*)pv)->pUchTR = (unsigned char *)
	((ObjParamDsc*)pObjParam)-> p_ObjEntity ;// 
	((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
	((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 
	((ObjParamDsc*)pObjParam)->size_Obj ;//sizeof(total_measurement);//
//	SetPrtTestVal(&(holderPrtTbl.UNPrtTbl.CfgPrtTbl));
((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_TRANSMITTING] = (-1);
((ProxyTransportStateDsc*)pv)->arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA] = 0;
hldrTRPrtTblTransportCTpuUnit.TrCnHldr.SizeAppObj  = 0;
 lV |= USING_OCS_MSK|STT_START_OCS_MSK|TR_MODE_OCS_MSK;
 	((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
//Enable Int
RetActivateTrPrtTblPrTpt:

return lV;//

}


long UpdateRVPrTptPrtTbl1(void* pvLDC, long lID)  @ "Fast_function"
{
register long i;//,j;
register char *pSrc;//,*pDst;
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
 sLV.chNeedClrSesData = 0;unnV1.ulVal = 0;
if ( (((LDCIDsc*)pvLDC)-> uchConMode)== 0)
{
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI);
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;//Src Pointer
	
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
	//pSrc = (char *) (((LDCIDsc*)pvLDC)-> pSrc);
	//lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//Activate For Proxy Msg
	//ReqReceive ++;ReqReceiveAr++; //?????
	//Clear All Ses Data
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ConState         = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;ReqReceivePrtTblPrTpt++;

}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
		unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
		unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
		unnV1.uchAr[3] = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&hldrRVPrtTblTransportCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState =((LDCIDsc*)pvLDC)-> uchConMode;//Fix Connection
		//field ((RVBaseCTpuUnitDsc*)pv)->ConState param )-> uchConMode first i Decide use in
		//This function when size receve(transmit obj) not defined use param uchConMode
		//When session continue always 1 when stoped must be 0. 
		//You should change in future ServiceTRApCn2 function for markinga Last Packet
		//in session 
		//param )-> uchConMode == 0 must terminate receve proc in any case
		
	}
	unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
	{
		i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
		if( i<= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
		lID = ((LDCIDsc*)pvLDC)->uchTR_C;
		else
		lID = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
		unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
		i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
		pvLDC = (void*)i;
		i = (long)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
		i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		pv  = (void*)i;
		for (i = 0; i < lID; i++)
		{
			((char*)pv)[i] = ((char*)pvLDC)[i];
		}
		//Update Rv
		pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
		//lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];//Is good desigion
		lID += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
		unnV1.uchAr[2] = 0;
		if  (lID >= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
		unnV1.uchAr[2] |= 1;//Fix Stop Connection
		if(unnV1.uchAr[0]== 0 && ((RVBaseCTpuUnitDsc*)pv)->ConState == 1) //Fix Reset Connection
		unnV1.uchAr[2] |= 2;//Fix Stop Connection
		if ( unnV1.uchAr[2]	)
		{
			
			if ((lID == (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
			||(unnV1.uchAr[2]&2))//Command Reset Connection
			{
				//Activate App Func
				ReqReceivePrtTblPrTpt++;
				
			
			}
			else
			{
			
			}
			 sLV.chNeedClrSesData++;
		
		}
	
	}
	else
	{
		;//Error Session
		 sLV.chNeedClrSesData++;
	
	
	
	}
	if(sLV.chNeedClrSesData)
	{
		pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
		ReqReceivePrtTblPrTpt = 0;	
	
	}

	

}

//Try activate Proxy Transport if not activated
i = ActivatePrtTblRvPrTpt((void*)&testPrtTblState ,0);
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;

return lID;//

}




long GetPrtTblTbl(void)  @ "Fast_function"
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtGetPrtTblTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtGetPrtTblTbl;
	}
//Prepea Transport
//Control State transport

//Activate Proxy
    lV = ActivatePrtTblPrMng();
pv = (void*)&hldPrMngPrtTbl;
//Put Request in queue
if (lV)
// hldCmmMsgRV.UNNHdrMsg.uchAr[0] = ECT_REQ_ACTIVATE_RV;
 lV =  SetPrtTblSendEct(pv,ECT_CREATE_CMM_TR_COBJ_HR_TO_HS);
//Control Ok or Error
//Call Func Control State PrMng + Pr Tpt
//Return Val 1-OK 2-Error 0- No Data
//
RetPtGetPrtTblTbl:
 return lV;
}


long SendPrtTblTbl(void)  @ "Fast_function"
{
register void* pv;
register long lV;
lV = 0;
//Detect State Proxy Transport
	pv = (void*)& hldPrTrptPrtTbl;
	//Look Transport
	pv  = (void*)& hldPrTrptPrtTbl.hldrAcpuCMUnitState;
	//BaseAcpuCMUnitDsc hldrAcpuCMUnitState
	lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
	//i = lV;
	//Ignore Command
	if (lV&(STT_STOP_OCS_MSK))
	{
		lV = 0;
		goto RetPtSendPrtTblTbl;
	}
	if(lV&(RV_MODE_OCS_MSK))//In Receive State now
	{
		lV = 0;
		goto RetPtSendPrtTblTbl;
	}
//Prepea Transport
//Control State transport
//ActivateTransmitStngObj();
 lV =  ActivatePrtTblTrPrTpt((void*)&testPrtTblState,0);


RetPtSendPrtTblTbl:
 return lV;

}




//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqGetPrtTblBR(long lActivation, void* pPrtTblStateDsc);
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
//~~~ pPrtTblStateDsc  - По данному адресу в случае успеха будет помещен указатель
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
char   ReqGetPrtTblBR(long lActivation, void* pPrtTblStateDsc)  @ "Fast_function"
{
    register long i;
	register long j;
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pPrtTblStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		j = 0;
		//Control State Proxy Mng
		i = hldPrMngPrtTbl.shPrMngConState;
		if(i&(PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK))
		{
			i = hldPrMngPrtTbl.ulStateProxyManger; i >>= 24;
			if( (i == 0) || (i == ECT_SEND_PRT_TBL_FROM_HS) )//Phase where data not send from HS
			j++;//State Exec
		}
		//Control State transport
		//i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
		i = hldPrTrptPrtTbl.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = 0;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = (void*)0;
			j++;
			
		}
		if(j)
		i = STATE_EXEC;
		else
		{
		    //((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS      = 0;
			//((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS = (long*)0;
			//.holderProxyPrtTblUnit.hldObjParam.size_Obj = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS; 
			//.holderProxyPrtTblUnit.hldObjParam.p_ObjEntity = 
			//.((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS;
			testPrtTblState.size_PrtTbl = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl;
			testPrtTblState.p_PrtTbl    = ((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl;
			i =  GetPrtTblTbl();//ActivateProxyPrtTbl();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		// i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;
		//if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
		j = 0;
		i = hldPrTrptPrtTbl.arU32LifeCtr[CTR_TRANSPORT_WAITING_DATA];
		if(i>10)
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			j++;//i = STATE_EXEC;
		}
		if(hldPrMngPrtTbl.shPrMngConState&((PM_STT_START_OCS_MSK|PM_STT_WORK_OCS_MSK|PM_STT_STOP_OCS_MSK)))
		j++;
		if(hldPrMngPrtTbl.ulLifeCtrEct)
		j++;
		if(j==0)
		{
		    
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = //lSizeOf_PrtTbl;
			testPrtTblState.size_PrtTbl;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = 
			//(long*)&holderPrtTbl.UNPrtTbl.chArPrtTbl[0];
			testPrtTblState.p_PrtTbl;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArPrtTblData;
			if( (hldPrTrptPrtTbl. arUchResultExecCmd[2] >0)
				&&(hldPrTrptPrtTbl. arUchResultExecCmd[2]<0x80)
			)
			{
				i =  SUCCESS_EXEC;
			}
			
		}
		else
		i = STATE_EXEC;
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""



//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char  ReqSendPrtTblBR(long lActivation, void* pPrtTblStateDsc);
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
//~~~ pPrtTblStateDsc  - По данному адресу в случае успеха будет помещен указатель
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
char   ReqSendPrtTblBR(long lActivation, void* pPrtTblStateDsc)  @ "Fast_function"
{
    register long i;
	
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pPrtTblStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;//Is it Work???
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK  ))
	    {
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = 0;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = (void*)0;
			
			i = STATE_EXEC;
		}
		else
		{
		    //((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS      = 0;
			//((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS = (long*)0;
			//.holderProxyPrtTblUnit.hldObjParam.size_Obj = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_ustuvannja_BS; 
			//.holderProxyPrtTblUnit.hldObjParam.p_ObjEntity = 
			//.((PrtTblStateDsc*)pPrtTblStateDsc)-> p_ustuvannja_BS;
			testPrtTblState.size_PrtTbl = ((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl;
			testPrtTblState.p_PrtTbl    = ((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl ;
			i =  SendPrtTblTbl();//ActivateProxyPrtTbl();
			if (i)
			i = START_EXEC;
			else
			i  = ERROR_EXEC;
			
		}

	}
	else
	{
		 i = hldPrTrptPrtTbl.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))//RV_MODE_OCS_MSK
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((PrtTblStateDsc*)pPrtTblStateDsc)-> size_PrtTbl      = //lSizeOf_PrtTbl;
			testPrtTblState.size_PrtTbl;
			((PrtTblStateDsc*)pPrtTblStateDsc)-> p_PrtTbl = 
			//(long*)&holderPrtTbl.UNPrtTbl.chArPrtTbl[0];
			testPrtTblState.p_PrtTbl;
			i  = ERROR_EXEC;
			//if (chStateAr10PerData != SUCCESS_EXEC)
			//i = chStateArPrtTblData;
			if( (hldPrTrptPrtTbl. arUchResultExecCmd[1] >0)
				&&(hldPrTrptPrtTbl. arUchResultExecCmd[1]<0x80)
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

static char chStateExecReqGetPrtTbl= 0;
long ReqGetPrtTblBRExample(void)   @ "Fast_function"
{
	register long i=0;
	PrtTblStateDsc locPrtTblState;
if ( chStateExecReqGetPrtTbl== 0)
	{
		locPrtTblState.size_PrtTbl = testPrtTblState.size_PrtTbl;
		locPrtTblState. p_PrtTbl   = testPrtTblState.p_PrtTbl  ;
		i =   ReqGetPrtTblBR(1,&locPrtTblState);//
		if (i != ERROR_EXEC)
		{
			chStateExecReqGetPrtTbl= 1;//Start Execution
		}
		else chStateExecReqGetPrtTbl= 0;
	}
	if (chStateExecReqGetPrtTbl== 1 )
	{
		i =   ReqGetPrtTblBR(0,&locPrtTblState);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateExecReqGetPrtTbl= SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqGetPrtTblBR(1,&locPrtTblState);
			if (i== ERROR_EXEC)
			chStateExecReqGetPrtTbl= 0;
			else
			chStateExecReqGetPrtTbl= 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateExecReqGetPrtTbl== SUCCESS_EXEC)
	{
		chStateExecReqGetPrtTbl= 0;;//See data
	}


return chStateExecReqGetPrtTbl;

}

static char chStateReqSendPrtTbl= 0;
long ReqSendPrtTblBRExample(void)   @ "Fast_function"
{
	register long i=0;
	PrtTblStateDsc locPrtTblState;
if ( chStateReqSendPrtTbl== 0)
	{
		locPrtTblState.size_PrtTbl = testPrtTblState.size_PrtTbl;
		locPrtTblState. p_PrtTbl   = testPrtTblState.p_PrtTbl;   
		i =   ReqSendPrtTblBR(1,&locPrtTblState);//ReqGetSettingsBM
		if (i != ERROR_EXEC)
		{
			chStateReqSendPrtTbl= 1;//Start Execution
		}
		else chStateReqSendPrtTbl= 0;
	}
	if (chStateReqSendPrtTbl== 1 )
	{
		i =   ReqSendPrtTblBR(0,&locPrtTblState);//ReqGetSettingsBM
		switch(i)
		{
			case SUCCESS_EXEC:
			chStateReqSendPrtTbl= SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqSendPrtTblBR(1,&locPrtTblState);
			if (i== ERROR_EXEC)
			chStateReqSendPrtTbl= 0;
			else
			chStateReqSendPrtTbl= 1;
			break;
			
			default:
			;
		
		}
		
	
	}
	if (chStateReqSendPrtTbl== SUCCESS_EXEC)
	{
		;//See data
	}



	return chStateReqSendPrtTbl;


}


long MoveCTputoAppObj(void *pBaseAcpuCM, void *pRVBaseCTpu);
long UpdateRVPrTptPrtTbl(void* pvLDC, long lID)  @ "Fast_function"
{
register long i;//,j;
register char *pSrc;//,*pDst;
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
RVBaseCTpuUnitDsc locRVBaseCTpuUnit;	 	
		
		
sLV.pOriginLDC = pvLDC;
 sLV.chNeedClrSesData = 0;unnV1.ulVal = 0;
if (ReqReceivePrtTblPrTpt>=1)//This part of code need as as previous buf need iteretivly  move to proxy
{
locRVBaseCTpuUnit = hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
locRVBaseCTpuUnit.pUchRV = (hldrRVPrtTblTransportCTpuUnit.arUchRV);//Buffer Addr
i = MoveCTputoAppObj((void*)&hldPrTrptPrtTbl.hldrAcpuCMUnitState,
(void*)&locRVBaseCTpuUnit);
//if i == 0 //Error Fix!
ReqReceivePrtTblPrTpt = 0;//Now i think another number  is error
}
	//Move Buff to Obj
if ( (((LDCIDsc*)pvLDC)-> uchConMode)== 0)
{
	i = (((LDCIDsc*)pvLDC)->uchTR_C);//+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
	if( i<= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	else
	lID = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI);
	unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	pvLDC = (void*)i;//Src Pointer
	
	//pv  = (void*)&hldrAcpuCMUnitState.hldrAcpuCMUnitState;
	
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
	//pSrc = (char *) (((LDCIDsc*)pvLDC)-> pSrc);
	//lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	//Activate For Proxy Msg
	//ReqReceive ++;ReqReceiveAr++; //?????
	//Clear All Ses Data
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.uchUsedTransport = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.NumComSes        = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ConState         = 0;
	hldrRVPrtTblTransportCTpuUnit.RvCnHldr.ulRvCount        = lID;ReqReceivePrtTblPrTpt++;

}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
		unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
		unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
		unnV1.uchAr[3] = 0;
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//
		//((RVBaseCTpuUnitDsc*)pv)->pUchRV = (unsigned char*)&hldrRVPrtTblTransportCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
		((RVBaseCTpuUnitDsc*)pv)->ConState =((LDCIDsc*)pvLDC)-> uchConMode;//Fix Connection
		//field ((RVBaseCTpuUnitDsc*)pv)->ConState param )-> uchConMode first i Decide use in
		//This function when size receve(transmit obj) not defined use param uchConMode
		//When session continue always 1 when stoped must be 0. 
		//You should change in future ServiceTRApCn2 function for markinga Last Packet
		//in session 
		//param )-> uchConMode == 0 must terminate receve proc in any case
		
	}
	unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
	if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
	{
		i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
		if( i<= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
		lID = ((LDCIDsc*)pvLDC)->uchTR_C;
		else
		lID = (SIZE_TPDU_TRANSPORT_PRT_CNL_SPI) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
		unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
		i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
		pvLDC = (void*)i;
		i = (long)&hldrRVPrtTblTransportCTpuUnit.arUchRV;
		i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		pv  = (void*)i;
		for (i = 0; i < lID; i++)
		{
			((char*)pv)[i] = ((char*)pvLDC)[i];
		}
		//Update Rv
		pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
		//lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];//Is good desigion
		lID += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
		unnV1.uchAr[2] = 0;
		if  (lID >= (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
		unnV1.uchAr[2] |= 1;//Fix Stop Connection
		if(unnV1.uchAr[0]== 0 && ((RVBaseCTpuUnitDsc*)pv)->ConState == 1) //Fix Reset Connection
		unnV1.uchAr[2] |= 2;//Fix Stop Connection
		if ( unnV1.uchAr[2]	)
		{
			
			if ((lID == (long)(SIZE_TPDU_TRANSPORT_PRT_CNL_SPI))
			||(unnV1.uchAr[2]&2))//Command Reset Connection
			{
				//Activate App Func
				ReqReceivePrtTblPrTpt++;
				
			
			}
			else
			{
			
			}
			 sLV.chNeedClrSesData++;
		
		}
	
	}
	else
	{
		;//Error Session
		 sLV.chNeedClrSesData++;
	
	
	
	}
	if(sLV.chNeedClrSesData)
	{
		pv  = (void*)&hldrRVPrtTblTransportCTpuUnit.RvCnHldr;
		((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
		ReqReceivePrtTblPrTpt = 0;	
	
	}

	

}

//Try activate Proxy Transport if not activated
i = ActivatePrtTblRvPrTpt((void*)&testPrtTblState ,0);
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;

return lID;//

}

long MoveCTputoAppObj(void *pBaseAcpuCM, void *pRVBaseCTpu)  @ "Fast_function"
{
register long i,j;
//register char *pch;
struct 
	{
		char chRetCode;//,
		unsigned short ushSizePacket;//
		void *pOriginBaseAcpuCM;
	} sLV;
sLV.chRetCode = 0;sLV.ushSizePacket = 0;
sLV.pOriginBaseAcpuCM = pBaseAcpuCM;
sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pRVBaseCTpu)->ulRvCount;
//pch = (char *)&(hldrRVPrtTblTransportCTpuUnit.arUchRV);
    j = ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount;//
	j += sLV.ushSizePacket;
	if ((unsigned long)j<(((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvTotal))
	{
		j = sLV.ushSizePacket;
		sLV.chRetCode = 1;

	}
	else
	{
		if ( j ==(((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvTotal)   )
		{
			//(((BaseAcpuCMUnitDsc*)pv)->ulRvCount)		    
			//j = sLV.ushSizePacket; //In this function it is erroneus situation
			j = 0;
			sLV.chRetCode = 2;
			sLV.ushSizePacket = j;
		}
		else
		{
			//It is a error -- Bad assembly array !!
			// You must signal that Assembly Bad!
			j = 0;
			sLV.chRetCode = 0;
			sLV.ushSizePacket = j;
		}
		
	}
	i = (long) ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->pUchRV;
	 
	i+= (long) ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount;//sLV.uVl;
	pBaseAcpuCM = (void*)i;
	i = (long) (((RVBaseCTpuUnitDsc*)pRVBaseCTpu)->pUchRV);
	pRVBaseCTpu  = (void*)i;
	for (i = 0; i < j; i++)
	{
		((char*)pBaseAcpuCM)[i] = ((char*)pRVBaseCTpu)[i];
	}
	if(j)
	{
		pBaseAcpuCM = sLV.pOriginBaseAcpuCM ;
		i= (long) ((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount;
		i += j;
		((BaseAcpuCMUnitDsc*)pBaseAcpuCM)->ulRvCount = i;
	}	
return sLV.ushSizePacket;//Size 
}

extern  long Eval_CS(char* pCh, long iLength );
void SetPrtTestVal(void* pTbl)  @ "Fast_function"
{
  register long i;
  register unsigned long j;
register void *pv1; //,*pv2;

	for (i = 0,  j =(NUM_IN>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeSignal[i] = 0x55;
	}
	
	for (i = 0,  j =(NUM_IN>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeInput[i] = 0x67;
	}
	
	for (i = 0,  j =(NUM_OUT>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeOuts[i] = 0x33;
	}
	for (i = 0,  j =(NUM_LED>>3); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> arUchTypeLeds[i] = 0x44;
	}
	for (i = 0,  j =(NUM_IN); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> ushDurationDI[i] = 0x1111;
	}
	for (i = 0,  j =(NUM_IN*AMOUNT_BYTE_FOR_IEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_di_rank_cfg[i] = 0x22;
	}
	
	for (i = 0,  j =(NUM_OUT*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_do_rank_cfg[i] = 0x22;
	}
	
	for (i = 0,  j =(NUM_LED*AMOUNT_BYTE_FOR_OEPRF); (unsigned long)i < j; i++)
	{
		((CfgTblDsc*)pTbl)-> uc_ar_led_rank_cfg[i] = 0x22;
	}
	((CfgTblDsc*)pTbl)-> PckpStpm_store_selection = 1;
	//PckpStpmStoreDsc 	arPckpStpmStngStore
	pv1  = (void*) &((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[0];
	
	
	for (i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
	{
		pv1  = (void*) &((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i];
		for (j = 0; j< ( sizeof(PckpStpmStoreDsc) );j++)
			((char*)pv1)[j] = 3+i;
	}
	((CfgTblDsc*)pTbl)->state_DstpDriftBlk     = 3;
	((CfgTblDsc*)pTbl)->state_FaultU_Dstp      = 3;
	((CfgTblDsc*)pTbl)-> Dstp_T_UI_NCN         = 3;
	((CfgTblDsc*)pTbl)-> Dstp_T_NonSymMode_NCN = 3;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1Dstp1Mng);
	for (j = 0; j< ( sizeof(Dstp1MngStoreDsc) );j++)
			((char*)pv1)[j] = 1;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2Dstp2Mng);
	for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 1;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg3Dstp2Mng);
	for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 1;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg4Dstp2Mng);
	for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 1;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg5Dstp2Mng);
	for (j = 0; j< ( sizeof(Dstp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 1;
			
	((CfgTblDsc*)pTbl)-> state_FaultU_Ocp = 4;
	
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1DrOcp1Mng);
	for (j = 0; j< ( sizeof(DrOcp1MngStoreDsc) );j++)
			((char*)pv1)[j] = 2;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2DrOcp2Mng);
	for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 2;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg3DrOcp2Mng);
	for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 2;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg4DrOcp2Mng);
	for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 2;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg5DrOcp2Mng);
	for (j = 0; j< ( sizeof(DrOcp2MngStoreDsc) );j++)
			((char*)pv1)[j] = 2;
			
			
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1DrErthMng);
	for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
			((char*)pv1)[j] = 3;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2DrErthMng);
	for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
			((char*)pv1)[j] = 3;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg3DrErthMng);
	for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
			((char*)pv1)[j] = 3;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg4DrErthMng);
	for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
			((char*)pv1)[j] = 3;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg5DrErthMng);
	for (j = 0; j< ( sizeof(DrErthMngStoreDsc) );j++)
			((char*)pv1)[j] = 3;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1NspMng);
	for (j = 0; j< ( sizeof(NspMngStoreDsc) );j++)
			((char*)pv1)[j] = 4;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2NspMng);
	for (j = 0; j< ( sizeof(NspMngStoreDsc) );j++)
			((char*)pv1)[j] = 4;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1UminMng);
	for (j = 0; j< ( sizeof(UminMngStoreDsc) );j++)
			((char*)pv1)[j] = 5;
			
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg2UminMng);
	for (j = 0; j< ( sizeof(UminMngStoreDsc) );j++)
			((char*)pv1)[j] = 5;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStg1UmaxMng);
	for (j = 0; j< ( sizeof(UmaxMngStoreDsc) );j++)
			((char*)pv1)[j] = 7;
	
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrStgU2maxMng);
	for (j = 0; j< ( sizeof(UmaxMngStoreDsc) );j++)
			((char*)pv1)[j] = 7;
			
			
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrRclrMng);
	for (j = 0; j< ( sizeof(RclrMngStoreDsc) );j++)
			((char*)pv1)[j] = 8;
			
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrBrfMng);
	for (j = 0; j< ( sizeof(BrfMngStoreDsc) );j++)
			((char*)pv1)[j] = 9;
	//pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrBru);
	//for (j = 0; j< ( sizeof(BruDsc ) );j++)
			((char*)pv1)[j] = 10;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrFL);
	for (j = 0; j< ( sizeof(FLDsc) );j++)
			((char*)pv1)[j] = 11;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrCalcHvpBrOn);
	for (j = 0; j< ( sizeof(CalcHvpBrOnDsc) );j++)
			((char*)pv1)[j] = 12;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrCalcPwr);
	for (j = 0; j< ( sizeof(CalcPwrDsc) );j++)
			((char*)pv1)[j] = 13;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrOFunc);
	for (j = 0; j< ( sizeof(OFuncDsc) );j++)
			((char*)pv1)[j] = 14;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrOTrg);
	for (j = 0; j< ( sizeof(OTrgDsc) );j++)
			((char*)pv1)[j] = 15;
	pv1  = (void*)&( ((CfgTblDsc*)pTbl)-> ownrOLgc);
	for (j = 0; j< ( sizeof(OLgcDsc) );j++)
			((char*)pv1)[j] = 17;
	
	((PrtTblHldDsc*)pTbl)->lCheckSum = 
	Eval_CS((char*)pTbl,
	sizeof(PrtTblHldDsc)-sizeof(((PrtTblHldDsc*)pTbl)->lCheckSum));
	

/*	
	((CfgTblDsc*)pTbl)-> arUchTypeSignal;
	arUchTypeInput
	arUchTypeOuts
	arUchTypeLeds
	ushDurationDI
	uc_ar_di_rank_cfg
	uc_ar_do_rank_cfg
	uc_ar_led_rank_cfg
	
	*/
//(PrtTblDsc*)

}
//G:\HVP_pj\Hvps\hvps29_07_14\arc\hs1_for_IAR\hs1_30_08_14\mal\inc\variables_global_mal.h 185 CfgTblDsc currnet_settings, edit_settings; 
extern CfgTblDsc eeprom_prt_tbl;
#include    "dstp_df.c"
#include    "hve_df.c"
#include    "docp_df.c"
#include    "StngIci.c"
extern long CheckCorrectnesPrtTbl(void* pCfgTbl);

void ActivateTransmittionOnBR(void)  @ "Fast_function"
{
//	SetPrtTestVal(&(holderPrtTbl.UNPrtTbl.CfgPrtTbl));

	if( CheckCorrectnesPrtTbl((void*)&eeprom_prt_tbl) )//eeprom_prt_tbl.ownrOLgc.sizeAr == 0
	{
		SetPrtTestVal1((void*)&eeprom_prt_tbl);
		
		return;
	}
	holderPrtTbl.UNPrtTbl.CfgPrtTbl = eeprom_prt_tbl;
	holderPrtTbl.lCheckSum = Eval_CS((char*)&holderPrtTbl,
	sizeof(PrtTblHldDsc)-sizeof( holderPrtTbl.lCheckSum) );
	
	if(chStateReqSendPrtTbl>0)
	chStateReqSendPrtTbl = 0;
	ReqSendPrtTblBRExample();
	if(chStateReqSendPrtTbl==3)
	ReqSendPrtTblBRExample();
}

long CheckPrtData(void* pTbl)
{
long i = 0; 

	 //((PrtTblDsc*)pTbl)->

return i;
}


























/* EOF */
