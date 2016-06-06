/*------------------------------------------------------------------------------

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
* File Name       : Yustprx.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

void ActivateProxyYust(void)
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
	
	hldLDCI.uchConMode     = 0; //unsigned char  uchConMode;
	hldLDCI.uchStartSesion = 0; //unsigned char  uchStartSesion;
	hldLDCI.uchTR_C        = 
	  SIZE_TPDU_10PER_CNL_HSU2; //unsigned char  uchTR_C;//Size Transmit Data
	hldLDCI.NumComSes      = 0; //unsigned char  NumComSes;
	hldLDCI.IdConObj       = 
	  ID_TOTAL_MEAS_UNIT; //unsigned short IdConObj;
	//char *pSrc,*pDst;
	hldLDCI.pSrc       =  (char*)arCh;//holderRV10PeriodCTpuUnit.arUchRV;  
	//hldLDCI.pDst       =  holderProxyYustUnit.arUchRvParamCmd;
    chStateAr10PerData = 0;
	
	
	//.ActivateRVProxyYustCTpuUnit((void*)&hldLDCI,i);
	ActivateTRProxyYustCTpuUnit((void*)&hldLDCI,i);
}
//Activator Proxy
long ActivateTRProxyYustCTpuUnit(void* pvLDC, long lID)
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
i = holderProxyYustUnit.hldrAcpuCMUnitState.AppObjConState;
if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	return 0;


//~unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
//~unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
//~unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
//~unnV1.uchAr[3] = 0;

//.pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
pv = (void*)&(holderProxyYustUnit.arUchRvParamCmd);
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
  pv = (void*)&(holderProxyYustUnit.hldrAcpuCMUnitState);
  i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
  i |= USING_OCS_MSK|STT_START_OCS_MSK;
  ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
  //((BaseAcpuCMUnitDsc*)pv)->pf_Work         = WorkProxyYust;
  //TestReqTransmitYust++;
  
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
  holderTRYustCTpuUnit.TrCnHldr.SizeAppObj       = 0;
  ((BaseAcpuCMUnitDsc*)pv)->ulTrCount   = 0;
  ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal   = 8;
  ((BaseAcpuCMUnitDsc*)pv)->pUchTR      = 
  &(holderProxyYustUnit.arUchRvParamCmd[0]);
((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderYust.UNYust.chArYust[0];
//holderArYustUnit.current_data_transmit[0];
  ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal = SIZE_TOTAL_MEASUREMENT ;//Tempor
  ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal = lSizeOf_total_measurement ;//Tempor
  
return lID;//
}
long ActivateRVProxyYustCTpuUnit(void* pvLDC, long lID)
{
register long i;//,j;
//register char *pSrc;//,*pDst;
void* pv;

//.pv = (void*)&holderRVSrcSamplesCTpuUnit.arUchRV[0];
pv = (void*)&(holderProxyYustUnit.arUchRvParamCmd);
//.//((RVSrcSamplesCTpuUnitDsc*)pv )->
i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
 lID = 8;//((LDCIDsc*)pvLDC)->uchTR_C;
 pvLDC = (void*)i;
 
  for (i = 0; i < lID; i++)
  {
    ((char*)pv)[i] = ((char*)pvLDC)[i];
  }
  //.unnV1.uchAr[3] = lID;//Save amount Extract Data
  holderProxyYustUnit.hldrAcpuCMUnitState.pUchRV =
  (unsigned char*)&holderYust.UNYust.chArYust[0];
  holderProxyYustUnit.hldrAcpuCMUnitState.ulRvTotal = SIZE_TOTAL_MEASUREMENT;
  
  //Activate Proxy  Execution
  pv = (void*)&(holderProxyYustUnit.hldrAcpuCMUnitState);
  i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
  i |= USING_OCS_MSK|STT_START_OCS_MSK;
  ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;
  
  ((BaseAcpuCMUnitDsc*)pv)-> pUchRV = (unsigned char*)&holderYust.UNYust.chArYust[0];
  ((BaseAcpuCMUnitDsc*)pv)-> ulRvTotal = lSizeOf_total_measurement;
  //((BaseAcpuCMUnitDsc*)pv)->pf_Work         = WorkProxyYust;
  //TestReqTransmitYust++;
  
  //Clear All Ses Data
  i = 0;
  holderRVYustCTpuUnit.RvCnHldr.uchUsedTransport = 0;
  holderRVYustCTpuUnit.RvCnHldr.NumComSes        = 0;
  holderRVYustCTpuUnit.RvCnHldr.ConState         = 0;
  holderRVYustCTpuUnit.RvCnHldr.ulRvCount        = 0;
  holderTRYustCTpuUnit.TrCnHldr.SizeAppObj       = 0;
//.  
//.  //Indicator data Transmit to Application
//.  //holderRVSrcSamplesCTpuUnit. TrCnHldr.pUchRV           = 0;
return lID;//
}

void ActivateServTrApCnYustUnitHSU2(void)
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
pv  = (void*)& holderProxyYustUnit;
pch = (char *)((BaseAcpuCMUnitDsc*)pv)->pUchTR;//Base Addr Obj
i = ((BaseAcpuCMUnitDsc*)pv)->ulTrCount;//
j = ((BaseAcpuCMUnitDsc*)pv)->ulTrTotal;
   j -= i;
pch += i;//Addr Of Transmition
  //Reset Connect State
   pv  = (void*)& (holderTRYustCTpuUnit.TrCnHldr);
   
   ((TRBaseCTpuUnitDsc*)pv)->uchBaseTransport  = ID_CNL_HSU2;// If need change
   ((TRBaseCTpuUnitDsc*)pv)->uchUsedTransport  = ID_CNL_HSU2;// Logic can ctrl
   
   if( j> SIZE_TPDU_TOT_MEAS_CNL_HSU2)
   j = SIZE_TPDU_TOT_MEAS_CNL_HSU2;
   //((TRBaseCTpuUnitDsc*)pv)->NumComSes  = ;
   ((TRBaseCTpuUnitDsc*)pv)->ConState   = 0;//Reset Con State
   ((TRBaseCTpuUnitDsc*)pv)->SizeAppObj = j;//
   ((TRBaseCTpuUnitDsc*)pv)->IdConObj   = ID_TOTAL_MEAS_UNIT;//ID_TEN_PERIOD_SAMPLES_UNIT;
   ((TRBaseCTpuUnitDsc*)pv)->ulTrCount  = 0;//Reset  counter
   ((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)pch;
   //(unsigned char*)& holderTRSrcSamplesCTpuUnit.arUchTR;
   
}
void TerminateServiceApCnProxyYust(void)
{
//register void *pv;
//register long i;
  //pv  = (void*)& (holderTR10PeriodCTpuUnit.TrCnHldr);
  //((TRBaseCTpuUnitDsc*)pv)->pUchTR     = (unsigned char*)0;
  holderTRYustCTpuUnit.TrCnHldr.pUchTR = (unsigned char*)0;
  //holderTR10PeriodCTpuUnit.TrCnHldr.SizeAppObj = 
}
void PrepDecompouseYustUnitHSU2(void)
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
	if(TestReqTransmitYust)
	{
		//Control State Channel
		i = ((StateTpCnDsc*)pv)-> lCapicity_CNL_HSU2;j = SIZE_TPDU_TOT_MEAS_CNL_HSU2>>4;//If Channel full
		//If busy - Try another
		if( i > j )//Minimal Size - Stop try transmit
		{
			if (TestReqTransmitYust==START)
			{
				ActivateServTrApCnYustUnitHSU2();
				TestReqTransmitYust = EXEC;
			}
			//ProcessTransmit Obj
			if(TestReqTransmitYust==EXEC)
			{
				i = ServiceTRApCn2((void*)&holderTRYustCTpuUnit.TrCnHldr,(void*)&hldrTpCnState);
				if(i &(1<<6))
				{
					TestReqTransmitYust = TERM;//sLV.chRetCode |= (1<<6);
					
					
				}	
				if(i &(1<<7))//channel Full
				TestReqTransmitYust = EXEC;//Activate Channel transmition and Set Zapret vizova ses poka ne otrabotaet chanel transmit LPU

				if (TestReqTransmitYust==TERM)
				{
					//.TerminateServiceApCn((void*)& holderSrcSamplesUnit,ID_SRC_SAMPLES_UNIT);
					TerminateServiceApCnProxyYust();
					TestReqTransmitYust = 0;
				}
			}
		}
		//Try another???
		
	}
	

}

long InitProxyYust (void* pv, long lV)
{
return 0; 
}
long WorkProxyYust (void* pv, long lV)
{
register long i = 0;
register long j;
    if(lV == STT_START_OCS_ONB)
    {
        //Do SomeSing! for Init
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0] = 1;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[1] = ACTIVATE_TRANSMIT_RQ_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[2] = TRANSMIT_RQ_DATA ;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[3] = CONTROL_RV_FILL_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[4] = FREE_FILL_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[5] = FREE_FILL_DATA;
		i = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		i |= STT_WORK_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = i;	
		
		//Now it is all cmd
    	i = ExecCmdProxyYust(pv,ACTIVATE_TRANSMIT_RQ_DATA);
		if (i==0)//Ok
		  ((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0] = 2;
		//return i;
    }
	if(lV == STT_WORK_OCS_ONB)
    {
       
	   i = ((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0];//Pointer to Active Cmd
	   if (i==0)
	   return lV--;// ! Error
	   if (i<TOTAL_CMD)//Now Treshold for this Executor
	   {
	      j = ((ProxyYustUnitDsc*)pv)-> arUchExecCmd[i];//Load Command
		  //...((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0] = 0;
	      lV = ExecCmdProxyYust(pv,j);
		  if (lV==0)//Ok
		  ((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0] = ++i;
	   }
	   else{
	   ((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0] = 0;//Terminate Exec
	   }
	   //return i;
    }
	if(lV == STT_STOP_OCS_ONB)
    {
        //Do SomeSing! for Init
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[0] = 0;//1;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[1] = 0;//ACTIVATE_FILL_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[2] = 0;//RECIVE_FILL_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[3] = 0;//ACTIVATE_TRANSMIT_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[4] = 0;//TRANSMIT_FILL_DATA;
		((ProxyYustUnitDsc*)pv)-> arUchExecCmd[5] = 0;//FREE_FILL_DATA;
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
long ResetProxyYust (void* pv, long lV)
{
return 0;
}

//.extern unsigned int volatile command_to_receive_current_data;
//.extern int current_data_transmit[NUMBER_CANALS*NUMBER_POINT*NUMBER_PERIOD_TRANSMIT]; 

long ExecCmdProxyYust (void* pv, long lV)
{
//register long i;
//register void* pv;
    
	if(lV == ACTIVATE_TRANSMIT_RQ_DATA)
    {
        lV = ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		if (lV  == 0)		 
		{
		    if(TestReqTransmitYust==0)
		    {
		        ;
		    	TestReqTransmitYust = START;
		    	hldrTpCnState.uchTpState_CNL_HSU2  = 1;
				((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = VAL_TRANSMITTING;
		    	return 0;
		    	
		    }
		}
		else
		{
		    lV = ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		    lV--; ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = lV;
			if (lV ==0)
			{
				return 0;//Error
		    }
			else
			{
			    if(	(holderTRYustCTpuUnit.TrCnHldr.pUchTR == 0)
				&& (holderTRYustCTpuUnit.TrCnHldr.SizeAppObj ) )
			    {
			         holderTRYustCTpuUnit.TrCnHldr.SizeAppObj = 0;
					 ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = 1;
					 return 0;
			    }
			}	
		}
		
		return 1;
		
		
    }
	if(lV == TRANSMIT_RQ_DATA )
    {
        lV = ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING];
		lV--; ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING] = lV;
		if (lV ==0)
		{
			if (((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING])
			return 0;
			
			//Try Reset Whith Error Proxy Obj
			return 0;//Error
		}
		else
		{
		    //Control Transmitting
			//
			
			if(	(holderTRYustCTpuUnit.TrCnHldr.pUchTR == 0)
			&& (holderTRYustCTpuUnit.TrCnHldr.SizeAppObj ) )
			{
			     holderTRYustCTpuUnit.TrCnHldr.SizeAppObj = 0;
				 ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = 
				 VAL_WAITING_DATA_SAMPLES;
				 return 0; //Success Transmit
			}	 
			else 
			{
			     if (((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_TRANSMITTING])
			return 0;
			}
			return 1;
		}
	   
	   
		
    }
	
	if(lV == CONTROL_RV_FILL_DATA )
    {
        lV = ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES];
		lV--; ((ProxyYustUnitDsc*)pv)->arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = lV;
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
       
 	   pv  = (void*)& holderProxyYustUnit;
	   //Control Correctnes Receive Data
	   //compare Total &  actual Receive data
	   if ( (((RVBaseCTpuUnitDsc*)pv)->ulRvCount) ==(((BaseAcpuCMUnitDsc*)pv)->ulRvTotal)   )
	   chStateArYustData = SUCCESS_EXEC;
	   else 
	   chStateArYustData = ERROR_EXEC;
	   
		((BaseAcpuCMUnitDsc*)pv)->pUchTR = 0;//Base Addr Obj
		((BaseAcpuCMUnitDsc*)pv)->ulTrCount = 0;
		((BaseAcpuCMUnitDsc*)pv)->ulTrTotal = 0;
		//,((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = 0;
		lV = ((BaseAcpuCMUnitDsc*)pv)-> AppObjConState;
		lV |= STT_STOP_OCS_MSK;
		((BaseAcpuCMUnitDsc*)pv)-> AppObjConState = lV;
		((ProxyYustUnitDsc*)pv)->arU32LifeCtr[0] = 0;
		((ProxyYustUnitDsc*)pv)->arU32LifeCtr[1] = 0;
		((ProxyYustUnitDsc*)pv)->arU32LifeCtr[2] = 0;
		((ProxyYustUnitDsc*)pv)->arU32LifeCtr[3] = 0;
		//Clear Tran
		TestReqTransmitYust=0;
	
	   return 0;//Exex Action for Taras Array
    }
	
	
return 0;
}

//Aplic Level Func
void YustRvServCTpuApCnUnit(void)
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
    pv  = (void*)&(holderRVYustCTpuUnit.RvCnHldr);
	sLV.ushSizePacket = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;//Size Packet
//Copy
  pch = (char *)&(holderRVYustCTpuUnit.arUchRV);//( holderRVSrcSamplesCTpuUnit.arUchRV);
  //pch = (char *)((RVBaseCTpuUnitDsc*)pv)->pUchRV; Now Zero
  
  //Get Date from Proxy
  pv  = (void*)&holderProxyYustUnit;//&holderSrcSamplesUnit;
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
  i = (long) &holderYust.UNYust.chArYust[0];
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
   TestReqReceiveYust = 0;
   //Set Addition data for Use Data
   //sLV.ushSizePacket = j;
   pv  = (void*)&holderProxyYustUnit;
   	switch (sLV.chRetCode )
	{
	case 1:
		i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
		i += j;
		((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
		((ProxyYustUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = VAL_WAITING_DATA_SAMPLES;
		break;
	case 2://
		i= (long) ((BaseAcpuCMUnitDsc*)pv)->ulRvCount;
		i += j;
		((BaseAcpuCMUnitDsc*)pv)->ulRvCount = i;
		//Signal of the End Conection 
		((ProxyYustUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = 1;
		//Call function That Set apropriate data
		
		//Signal of the End Conection 
	
		break;
		
	case 0://
	
		//Signal of the End Conection 
		((ProxyYustUnitDsc*)pv)-> arU32LifeCtr[CTR_WAITING_DATA_SAMPLES] = 1;
		//Call function That fix Error state Proxy and array Data
		break;
	default:
		;
	}
   
}




void ProxyYustRvServCTpuApCnUnit(void)
{



}
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---
extern char ReqYustData(long lActivation, void* pYustStateDsc);
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
char  ReqYustData(long lActivation, void* pYustStateDsc)
{
    register long i;
	
	if (lActivation>1 && lActivation<0) 
	return ERROR_EXEC;
	if (pYustStateDsc == 0) 
	return ERROR_EXEC;
	
	if (lActivation == 1)
	{
		i = holderProxyYustUnit.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	    {
			((YustStateDsc*)pYustStateDsc)-> size_total_measurement      = 0;
			((YustStateDsc*)pYustStateDsc)-> p_total_measurement = (long*)0;
			
			i = STATE_EXEC;
		}
		else
		{
		    ((YustStateDsc*)pYustStateDsc)-> size_total_measurement      = 0;
			((YustStateDsc*)pYustStateDsc)-> p_total_measurement = (long*)0;
			ActivateProxyYust();
			
		}

	}
	else
	{
		 i = holderProxyYustUnit.hldrAcpuCMUnitState.AppObjConState;
		if(i&(STT_START_OCS_MSK|STT_WORK_OCS_MSK |STT_STOP_OCS_MSK ))
	    {
			//((ArTenPerStateDsc*)pArDataDsc)-> sizeAr      = 0;
			//((ArTenPerStateDsc*)pArDataDsc)-> pTenPerData = 0;
			
			i = STATE_EXEC;
		}
		else
		{
		    
			((YustStateDsc*)pYustStateDsc)-> size_total_measurement      = lSizeOf_total_measurement;
			((YustStateDsc*)pYustStateDsc)-> p_total_measurement = 
			(long*)&holderYust.UNYust.chArYust[0];
			//if (chStateAr10PerData != SUCCESS_EXEC)
			i = chStateArYustData;
			
		}
	
	}
	
	
	return i;

}
//----------------------------------------------------------------------------------
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""





