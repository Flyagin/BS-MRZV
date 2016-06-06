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
* Processor       : Lpc_3240
* File Name       : mTotprx.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  03/12/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

void ActivateProxyTotMeas(void)
{
	register long i;
	i = ID_TOTAL_MEAS_UNIT;
	LDCIDsc hldLDCI;
    static char arCh[20] = {
0x54,0x65,0x73,0x74,0x20,0x4D,0x65,0x73,0x73,0x61,//0x45,0x45,0x45,0x45,
0x67,0x65,0x45,0x45,0x45,0x45,0x45,0x45,0x45,0x45 //0x45,0x45,0x45,0x45,
//54 65 73 74 20 4D 65 73 73 61 67 65
};	
	//Emulate Receive Command
	//holderRV10PeriodCTpuUnit.RvCnHldr = 
	//holderRV10PeriodCTpuUnit.arUchRV  =
	//return;// !!!!
	hldLDCI.uchConMode     = 0; //unsigned char  uchConMode;
	hldLDCI.uchStartSesion = 0; //unsigned char  uchStartSesion;
	hldLDCI.uchTR_C        = 
	  SIZE_TPDU_10PER_CNL_HSU2; //unsigned char  uchTR_C;//Size Transmit Data
	hldLDCI.NumComSes      = 0; //unsigned char  NumComSes;
	hldLDCI.IdConObj       = 
	  ID_TOTAL_MEAS_UNIT; //unsigned short IdConObj;
	//char *pSrc,*pDst;
	hldLDCI.pSrc       =  (char*)arCh;//holderRV10PeriodCTpuUnit.arUchRV;  
	//hldLDCI.pDst       =  holderProxyTotMeasUnit.arUchRvParamCmd;
    chStateAr10PerData = 0;
	
	
	//.ActivateRVProxyTotMeasCTpuUnit((void*)&hldLDCI,i);
	ActivateTRProxyTotMeasCTpuUnit((void*)&hldLDCI,i);
}
//Activator Proxy
long ActivateTRProxyTotMeasCTpuUnit(void* pvLDC, long lID) @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;
//.struct 
//.	{
//.		void *pOriginLDC;
//.	} sLV;
//.union 
//.	    {
//.	    	unsigned char   uchAr [4];
//.	    	unsigned short  ushAr [2];
//.            unsigned long   ulVal;
//.	    }unnV1;	

//.sLV.pOriginLDC = pvLDC;
i = holderProxyTotMeasUnit.hldrAcpuCMUnitState.AppObjConState;
if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	return 0;


//~unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
//~unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
//~unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
//~unnV1.uchAr[3] = 0;

//.pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
pv = (void*)&(holderProxyTotMeasUnit.arUchRvParamCmd);
//.//((RVSrcSamplesCTpuUnitDsc*)pv )->
i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
 lID = 8;//((LDCIDsc*)pvLDC)->uchTR_C;
 pvLDC = (void*)i;
 
  for (i = 0; i < lID; i++)
  {
    ((char*)pv)[i] = ((char*)pvLDC)[i];
  }
//.  unnV1.uchAr[3] = lID;//Save amount Extract Data
  //Activate Proxy  Execution
  pv = (void*)&(holderProxyTotMeasUnit.hldrAcpuCMUnitState);
  i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
  i |= USING_OCS_MSK|STT_START_OCS_MSK;
  ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
  //((BaseAcpuCMUnitDsc*)pv)->pf_Work         = WorkProxyTotMeas;
  TestReqTransmitTotMeas++;
  
  //Clear All Ses Data
  i = 0;
//.  holderRV10PeriodCTpuUnit.RvCnHldr.uchUsedTransport = 0;
//.  holderRV10PeriodCTpuUnit.RvCnHldr.NumComSes        = 0;
//.  holderRV10PeriodCTpuUnit.RvCnHldr.ConState         = 0;
//.  holderRV10PeriodCTpuUnit.RvCnHldr.ulRvCount        = 0;
//.  holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj       = 0;
  //holderTR10PeriodCTpuUnit.RvCnHldr.uchUsedTransport = 0;
  //holderTR10PeriodCTpuUnit.RvCnHldr.NumComSes        = 0;
  //holderTR10PeriodCTpuUnit.RvCnHldr.ConState         = 0;
  //holderTR10PeriodCTpuUnit.RvCnHldr.ulRvCount        = 0;
  holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj       = 0;
  ((BaseAcpuCMUnitDsc*)pv)->ulTrCount   = 0;
  ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal   = 8;
  ((BaseAcpuCMUnitDsc*)pv)->pUchTR      = 
  &(holderProxyTotMeasUnit.arUchRvParamCmd[0]);
((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderTotMeas.UNTotMeas.chArTotMeas[0];
//holderArTotMeasUnit.current_data_transmit[0];
  ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal = SIZE_TOTAL_MEASUREMENT ;//Tempor
  ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal = lSizeOf_total_measurement ;//Tempor
  
return lID;//
}
long ActivateRVProxyTotMeasCTpuUnit(void* pvLDC, long lID) @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;

//.pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
pv = (void*)&(holderProxyTotMeasUnit.arUchRvParamCmd);
//.//((RVSrcSamplesCTpuUnitDsc*)pv )->
i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
 lID = 8;//((LDCIDsc*)pvLDC)->uchTR_C;
 pvLDC = (void*)i;
 
  for (i = 0; i < lID; i++)
  {
    ((char*)pv)[i] = ((char*)pvLDC)[i];
  }
  //.unnV1.uchAr[3] = lID;//Save amount Extract Data
  holderProxyTotMeasUnit.hldrAcpuCMUnitState.pUchRV =
  (unsigned char*)&holderTotMeas.UNTotMeas.chArTotMeas[0];
  holderProxyTotMeasUnit.hldrAcpuCMUnitState.ulRvTotal = SIZE_TOTAL_MEASUREMENT;
  
  //Activate Proxy  Execution
  pv = (void*)&(holderProxyTotMeasUnit.hldrAcpuCMUnitState);
  i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
  i |= USING_OCS_MSK|STT_START_OCS_MSK;
  ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
  
  ((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderTotMeas.UNTotMeas.chArTotMeas[0];
  ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal = lSizeOf_total_measurement;
  //((BaseAcpuCMUnitDsc*)pv)->pf_Work         = WorkProxyTotMeas;
  //TestReqTransmitTotMeas++;
  
  //Clear All Ses Data
  i = 0;
  holderRVTotMeasCTpuUnit.RvCnHldr.uchUsedTransport = 0;
  holderRVTotMeasCTpuUnit.RvCnHldr.NumComSes        = 0;
  holderRVTotMeasCTpuUnit.RvCnHldr.ConState         = 0;
  holderRVTotMeasCTpuUnit.RvCnHldr.ulRvCount        = 0;
  holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj       = 0;
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//
}

void ActivateServTrApCnTotMeasUnitHSU2(void) @ "Fast_function"
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
//-  }
pv  = (void*)& holderProxyTotMeasUnit;
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
  //Reset Connect State
   pv  = (void*)& (holderTRTotMeasCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
   if( j> SIZE_TPDU_TOT_MEAS_CNL_HSU2)
   j = SIZE_TPDU_TOT_MEAS_CNL_HSU2;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->uchSizeCTpuBuf = SIZE_TPDU_TOT_MEAS_CNL_HSU2;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_TOTAL_MEAS_UNIT;//ID_TEN_PERIOD_SAMPLES_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void TerminateServiceApCnProxyTotMeas(void)
{
  register void *pv;
//register long i;
  //pv  = (void*)& (holderTR10PeriodCTpuUnit.TrCnHldr);
  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
    holderTRTotMeasCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
   // pv  = (void*)& (holderTRTotMeasCTpuUnit.TrCnHldr);
   //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;   
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = 0;
   //((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;
  //holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj = 
}
void PrepDecompouseTotMeasUnitHSU2(void) @ "Fast_function"
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
	if(TestReqTransmitTotMeas)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_TOT_MEAS_CNL_HSU2>>4;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitTotMeas==START)
			{
				ActivateServTrApCnTotMeasUnitHSU2();
				TestReqTransmitTotMeas = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitTotMeas==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRTotMeasCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitTotMeas = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				TestReqTransmitTotMeas = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitTotMeas==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnProxyTotMeas();
					TestReqTransmitTotMeas = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

long InitProxyTotMeas (void* pv, long lV)
{
return 0; 
}
long WorkProxyTotMeas (void* pv, long lV) @ "Fast_function"
{
register long i = 0;
register long j;
    if(lV == STT_START_OCS_ONB)
    {
        //Do SomeSing! for Init
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 1;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[1] = ACTIVATE_TRANSMIT_RQ_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[2] = TRANSMIT_RQ_DATA ;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[3] = CONTROL_RV_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[4] = FREE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[5] = FREE_FILL_DATA;
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i |= STT_WORK_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		
		//Now it is all cmd
    	i = ExecCmdProxyTotMeas(pv,ACTIVATE_TRANSMIT_RQ_DATA);
		if (i==0)//Ok
		  ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 2;
		//return i;
    }
	if(lV == STT_WORK_OCS_ONB)
    {
       
	   i = ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0];//Pointer to Active Cmd
	   if (i==0)
	   return lV--;// ! Error
	   if (i<TOTAL_CMD)//Now Treshold for this Executor
	   {
	      j = ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[i];//Load Command
		  //...((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;
	      lV = ExecCmdProxyTotMeas(pv,j);
		  if (lV==0)//Ok
		  ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = ++i;
	   }
	   else{
	   ((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;//Terminate Exec
	   }
	   //return i;
    }
	if(lV == STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[0] = 0;//1;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[1] = 0;//ACTIVATE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[2] = 0;//RECIVE_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[3] = 0;//ACTIVATE_TRANSMIT_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[4] = 0;//TRANSMIT_FILL_DATA;
		((ProxyTotMeasUnitDsc*)pv)-> arUchExecCmd[5] = 0;//FREE_FILL_DATA;
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i = 0;//AUX_OCS_MSK;//Reset State
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		((BaseAcpuCMUnitDsc*)pv)-> ulRvCount  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulTrCount  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> ulTrTotal  = 0;
		((BaseAcpuCMUnitDsc*)pv)-> pUchRV     = 0;
		((BaseAcpuCMUnitDsc*)pv)-> pUchTR     = 0;
		//Now it is all cmd
    	
		
    }

return i;
}
long ResetProxyTotMeas (void* pv, long lV)
{
return 0;
}

//.extern unsigned int volatile command_to_receive_current_data;
//.extern int current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]; 
long lAmountSuccessTotMeas = 0;
long lAmountErrorTotMeas = 0;

long ExecCmdProxyTotMeas (void* pv, long lV) @ "Fast_function"
{
//register long i;
//register void* pv;
    
	if(lV == ACTIVATE_TRANSMIT_RQ_DATA)
    {
        lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		if (lV  == 0)		 
		{
		    if(TestReqTransmitTotMeas==0)
		    {
		        ;
		    	TestReqTransmitTotMeas = START;
		    	hldrTpCnState.uchTpState_CNL_HSU2  = 1;
				((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = VAL_TRANSMITTING;
		    	return 0;
		    	
		    }
		}
		else
		{
		    lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		    lV--; ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = lV;
			if (lV ==0)
			{
				return 0;//Error
		    }
			else
			{
			    if(	(holderTRTotMeasCTpuUnit.TrCnHldr.pUchTR == 0)
				&& (holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj ) )
			    {
			         holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj = 0;
					 ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = 1;
					 return 0;
			    }
			}	
		}
		
		return 1;
		
		
    }
	if(lV == TRANSMIT_RQ_DATA )
    {
        lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		lV--; ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = lV;
		if (lV ==0)
		{
			if (((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING])
			return 0;
			
			//Try Reset Whith Error Proxy Obj
			return 0;//Error
		}
		else
		{
		    //Control Transmitting
			//
			
			if(	(holderTRTotMeasCTpuUnit.TrCnHldr.pUchTR == 0)
			&& (holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj ) )
			{
			     holderTRTotMeasCTpuUnit.TrCnHldr.SizeAppObj = 0;
				  #ifdef BS_G45_FL_RL 
				  ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES>>3;
				  #else
				  ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES;
				  #endif
				 return 0; //Success Transmit
			}	 
			else 
			{
			     if ( (((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING]) < 10)
			return 0;
			}
			return 1;
		}
	   
	   
		
    }
	
	if(lV == CONTROL_RV_FILL_DATA )
    {
        lV = ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
		lV--; ((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = lV;
		if (lV ==0)
		{
			//Try Reset Whith Error Proxy Obj
			return 0;//Error
		}
		else
		{
		     return 1;
		}
    }
	

	if(lV == FREE_FILL_DATA)
    {
       
 	   pv  = (void*)& holderProxyTotMeasUnit;
	   //Control Correctnes Receive Data
	   //compare Total &  actual Receive data
	   if ( (((BaseAcpuCMUnitDsc*)pv)->ulRvCount) ==(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal)   )
		{
			chStateArTotMeasData = SUCCESS_EXEC;
			lAmountSuccessTotMeas++;
		}
	   else 
		{
			chStateArTotMeasData = ERROR_EXEC;
			lAmountErrorTotMeas++;
		}	
	   
		((BaseAcpuCMUnitDsc*)pv)->pUchTR = 0;//Base Addr Obj
		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
		//,((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		lV |= STT_STOP_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[0] = 0;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[1] = 0;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[2] = 0;
		((ProxyTotMeasUnitDsc*)pv)->arU32LifeCtr[3] = 0;
		//Clear Tran
		TestReqTransmitTotMeas=0;
	
	   return 0;//Exex Action for Taras Array
    }
	
	
return 0;
}

//Aplic Level Func
void TotMeasRvServCTpuApCnUnit(void) @ "Fast_function"
{
register long i,j;
register char *pch;
register void* pv;
struct 
	{
		char chRetCode;//,
		unsigned short ushSizePacket;//ushIdObj;
		//unsigned long uVl;
	    //unsigned char *pUchRV;//
		//void  *pOriginTR, *pOriginTpCn;
		
	} sLV;
//Detect if Data Not Used Update
sLV.chRetCode = 0;
    pv  = (void*)&(holderRVTotMeasCTpuUnit.RvCnHldr);
	sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;//Size Packet
//Copy
  pch = (char *)&(holderRVTotMeasCTpuUnit.arUchRV);//( holderRVSrcSamplesCTpuUnit.arUchRV);
  //pch = (char *)((RVBaseCTpuUnitDsc*)pv)->pUchRV; Now Zero
  
  //Get Date from Proxy
  pv  = (void*)&holderProxyTotMeasUnit;//&holderSrcSamplesUnit;
  j = ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;//sLV.uVl = 
  j += sLV.ushSizePacket;
//You Can Insert Control order of assembly Parts of array Now all poslidovno  
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
	
  //sLV.pUchRV = ((BaseAcpuCMUnitDsc*)pv)->pUchRV;
  i = (long) ((BaseAcpuCMUnitDsc*)pv)->pUchRV;
  i = (long) &holderTotMeas.UNTotMeas.chArTotMeas[0];
  i+= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;//sLV.uVl;
   pv  = (void*)i;
  //j = sLV.ushSizePacketsizeof(SrcSamplesUnitDsc);
  for (i = 0; i < j; i++)
  {
     ((char*)pv)[i] = pch[i];
  }
  //Reset Connect State
//   pv  = (void*)& (holderTRSrcSamplesCTpuUnit.TrCnHldr);
   
//.   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU7;// If need change
//.   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU7;// Logic can ctrl
//.   
//.  
//.   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
//.   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = sizeof(SrcSamplesUnitDsc);
//.   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_SRC_SAMPLES_UNIT;
//.   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
//.   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   TestReqReceiveTotMeas = 0;
   //Set Addition data for Use Data
   //sLV.ushSizePacket = j;
   pv  = (void*)&holderProxyTotMeasUnit;
   	switch (sLV.chRetCode )
	{
	case 1:
		i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
		i += j;
		((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
		((ProxyTotMeasUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES;
		break;
	case 2://
		i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
		i += j;
		((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
		//Signal of the End Conection 
		((ProxyTotMeasUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = 1;
		//Call function That Set apropriate data
		
		//Signal of the End Conection 
	
		break;
		
	case 0://
	
		//Signal of the End Conection 
		((ProxyTotMeasUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = 1;
		//Call function That fix Error state Proxy and array Data
		break;
	default:
		;
	}
   
}




void ProxyTotMeasRvServCTpuApCnUnit(void)
{



}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char ReqTotMeasData(long lActivation, void* pTotMeasStateDsc);
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~     функция запроса/получения  массива 10 периодов мгновенных            ~~~~~
//~~~     значений                                                             ~~~~~
//~~~                                                                          ~~~~~
//~~~    Возвращаемое значение                                                 ~~~~~
//~~~    1 - команда начала выполняться                                        ~~~~~
//~~~    2 - системы защит и автоматики находится в состоянии выполнении запроса ~~~
//~~~    3 - команда выполнена успешно                                         ~~~~~
//~~~    4 - возникла  ошибка при старте, передаче,                            ~~~~~
//~~~     или данные недостоверны                                              ~~~~~
 
//``````````````````````````````````````````````````````````````````````````````````
//~~~ pTotMeasStateDsc  - По данному адресу в случае успеха будет помещен указатель
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
char  ReqTotMeasData(long lActivation, void* pTotMeasStateDsc) @ "Fast_function"
{
    register long i;
	
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pTotMeasStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		i = holderProxyTotMeasUnit.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	    {
			((TotMeasStateDsc*)pTotMeasStateDsc)-> size_total_measurement      = 0;
			((TotMeasStateDsc*)pTotMeasStateDsc)-> p_total_measurement = (long*)0;
			
			i = STATE_EXEC;
		}
		else
		{
		    ((TotMeasStateDsc*)pTotMeasStateDsc)-> size_total_measurement      = 0;
			((TotMeasStateDsc*)pTotMeasStateDsc)-> p_total_measurement = (long*)0;
			ActivateProxyTotMeas();
			
		}

	}
	else
	{
		 i = holderProxyTotMeasUnit.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((TotMeasStateDsc*)pTotMeasStateDsc)-> size_total_measurement      = lSizeOf_total_measurement;
			((TotMeasStateDsc*)pTotMeasStateDsc)-> p_total_measurement = 
			(long*)&holderTotMeas.UNTotMeas.chArTotMeas[0];
			//if (chStateAr10PerData != SUCCESS_EXEC)
			i = chStateArTotMeasData;
			
		}
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""





