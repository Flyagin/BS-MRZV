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
* File Name       : CfgTbls.c
* Description     : Functions and Data for hold and Exchange Data in HWP
                    BR BM BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  31/03/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "DbIciCll.h"

//#include "header_mal.h"
#include    "../inc/ici_ef.h"

 
#pragma default_function_attributes = @ "Fast_function"  









// char chbsHldrPrtTblState @  "DMA_BUFFERS";
char chbsHldr10PerSmplState @  "DMA_BUFFERS";
char chCtrReading10PerSmpl;

 
 
 
// char chbsWrCfgMinState @  "DMA_BUFFERS";

short shbsRQ_DbgIciCallChangeState @  "DMA_BUFFERS";













char chSureExecuteIciCall = 0; 



short shbsDbgIciCallState @  "DMA_BUFFERS";

void IciDbgCall_I_Fn(void)//RefreshIciUnits
{
	
	register long i = 0;

	
	//Control Update Prt
	
	if( (shbsDbgIciCallState&(1<<RQ_RD_10_PER_SMPL_TBL_BIT  ))
	||chCtrReading10PerSmpl)//
	{
		//Clear Wr State
		if(chbsHldr10PerSmplState&(1<<BS_RD_END_10_PER_SMPL_ONB))
		{
			chbsHldr10PerSmplState&=~(1<<BS_RD_END_10_PER_SMPL_ONB);
			
		}
		 if(shbsDbgIciCallState&(1<<RQ_RD_10_PER_SMPL_TBL_BIT  ))
		 {
			chCtrReading10PerSmpl = 5;
			//Clear Rq State
			shbsDbgIciCallState &= ~(1<<RQ_RD_10_PER_SMPL_TBL_BIT  );
		 }
		 Read10PerSmpl();//Call Exec ReadCfgTbl();
		if(chbsHldr10PerSmplState&(1<<BS_RD_END_10_PER_SMPL_ONB))
		{
			chCtrReading10PerSmpl = 0;
		}
		goto ExitIciDbgCall_I_Fn;
	}
	
	
/*
//Control Update Prt
	if(
	(shbsRefreshCfgTablesState&(1<<RQ_WR_PRT_TBL_BIT ))||
	chCtrWriting
	)//Writing was fail
	{
		i = chbsHldrPrtTblState;
		if( 
		(i&(BS_HLDR_PRT_TBL_RD_MSK )) 
		&& (i&( BS_HLDR_PRT_TBL_USED_MSK ))
		){
		//In any cases wait result operation success or not
		;//
		}
		else
		{
		     //Clear Wr State
		     if(chbsHldrPrtTblState&(1<<BS_WR_END_HLDR_PRT_TBL_ONB))
		     {
		     	chbsHldrPrtTblState&=~(1<<BS_WR_END_HLDR_PRT_TBL_ONB);//Make Local copy &start operation
		     	//Clear Read State
		     }
			 if(shbsRefreshCfgTablesState&(1<<RQ_WR_PRT_TBL_BIT ))
			 {
				chCtrWriting = 3;//Counter popitoc write activation
				//Clear Rq State
		     	shbsRefreshCfgTablesState &= ~(1<<RQ_WR_PRT_TBL_BIT );
			 }
		     WriteCfgTbl();
		     if(chbsHldrPrtTblState&(1<<BS_WR_END_HLDR_PRT_TBL_ONB))
		     {
		     
				chCtrWriting = 0;//It`s local Copy writing process Indicated ext Req Lock and Execute
		     }
		     
		     goto ExitRefreshCfgTables;
		}
	}
//	else	//Check State Prt
//	CheckCfgTblState();
	if( (shbsRefreshCfgTablesState&(1<<RQ_RD_PRT_TBL_BIT ))
	||chCtrReading)//
	{
		//Clear Wr State
		if(chbsHldrPrtTblState&(1<<BS_RD_END_HLDR_PRT_TBL_ONB))
		{
			chbsHldrPrtTblState&=~(1<<BS_RD_END_HLDR_PRT_TBL_ONB);
			
		}
		 if(shbsRefreshCfgTablesState&(1<<RQ_RD_PRT_TBL_BIT ))
		 {
			chCtrReading = 5;
			//Clear Rq State
			shbsRefreshCfgTablesState &= ~(1<<RQ_RD_PRT_TBL_BIT );
		 }
		ReadCfgTbl();
		if(chbsHldrPrtTblState&(1<<BS_RD_END_HLDR_PRT_TBL_ONB))
		{
			chCtrReading = 0;
		}
		goto ExitRefreshCfgTables;
	}

*/

	

//	if(shbsRefreshCfgTablesState== 0)
//	{
//		if (shbsRQChangeCfgTablesState&(1<<BS_RQ_SET_MIN_CFG_TBL_BIT))
//		{
//			shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
//			//Recode Req Bit
//			//..if(shbsRQChangeCfgTablesState&(1<<BS_RQ_SET_MIN_CFG_TBL_BIT) )
//			shbsRefreshCfgTablesState |= 1<<RQ_WR_MIN_CFG_TBL_BIT;
//			SPIOperationTable |= EEPROM_WRITE_SETTINGS;
//			shbsRQChangeCfgTablesState &= ~(1<<BS_RQ_SET_MIN_CFG_TBL_BIT);
//			shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
//			goto ExitRefreshCfgTables;
//		}
//		if (shbsRQChangeCfgTablesState&(1<<BS_RQ_WR_CFG_TBL_BIT))
//		{
//			SPIOperationTable |= EEPROM_WRITE_SETTINGS;
//			PrepareDhldStngIciTblforTrOnBM();
//			PrepareDholderPrtTblforTrOnBR();
//			shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
//			shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT);
//			shbsRQChangeCfgTablesState &= ~(1<<BS_RQ_WR_CFG_TBL_BIT);
//			shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
//			goto ExitRefreshCfgTables;
//		}
//	
//	}







//
ExitIciDbgCall_I_Fn:
return;


}

long Read10PerSmplGood = 0;
long Read10PerSmplBad = 0;

//char chCtrReading ;
void  Read10PerSmpl(void)//
{
register long i;
ArTenPerStateDsc locArTenPerState; 

	i = chbsHldr10PerSmplState;
	//Check State Setting
	if( (i&(BS_RD_END_10_PER_SMPL_MSK )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_10_PER_SMPL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_10_PER_SMPL_RD_MSK )) == 0)
			{
				//Activate Reading
				chbsHldr10PerSmplState |= BS_10_PER_SMPL_USED_MSK|BS_10_PER_SMPL_RD_MSK;
				//Move Data to Holder
                //locPrtTblState.size_PrtTbl = sizeof(PrtTblHldDsc);//testPrtTblState.
                // locPrtTblState. p_PrtTbl    = (void*)&holderPrtTbl;
                 //Activate Get Data From Br
                 i = ReqArTenPerData(1,&locArTenPerState);//ReqGetPrtTblBR(1,(void*)&locPrtTblState);
			  
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		
						
                 		////Move if needed CfgPrtTbl
                 		//break;
                 		case ERROR_EXEC:
                 		chbsHldr10PerSmplState &=	~(BS_10_PER_SMPL_USED_MSK|BS_10_PER_SMPL_RD_MSK);//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
                 			//.. if (i== ERROR_EXEC)
                 			//.. chStateExecReqGetStngBm = 0;
                 			//.. else
                 			//.. chStateExecReqGetStngBm = 1;
                 		break;
                 		
                 		default:
                 		chSureExecuteIciCall++;//Test Only
                 	
                 	}

			}
		
		}
		
		
	}
	else
	{
		//Detect was reading Sucess or Not
		//Look Result Proxy tpt
		
		
		//If SUCCESS_EXEC Do Nothing
		//else Try Activate Reading again
		if( (i&( BS_10_PER_SMPL_RD_MSK )) == 0)//
		{
			;
			if((i&( BS_10_PER_SMPL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_10_PER_SMPL_USED_MSK )) == 0)
				{
					chbsHldr10PerSmplState &=~( BS_RD_END_10_PER_SMPL_MSK);// Try Activate Reading again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsHldr10PerSmplState;
	if( 
	(i&(BS_10_PER_SMPL_RD_MSK )) 
	&& (i&( BS_10_PER_SMPL_USED_MSK ))
	)
	{  
		//Check result Reading
		i = ReqArTenPerData(0,&locArTenPerState); //ReqGetPrtTblBR(0,(void*)&locPrtTblState);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecuteIciCall == 0)
				{
					i =  SIZE_OF_AR_TPS_CALC;
					if(
					(locArTenPerState.sizeAr      == i)&&//(locPrtTblState.size_PrtTbl == sizeof(PrtTblHldDsc))&&
					(locArTenPerState.pTenPerData == (long *)&holderArTenPerSamplesUnit.current_data_transmit[0] )
					//(locPrtTblState.p_PrtTbl    == ( (void*)&holderPrtTbl )) 
					)
					{
						//chbsHldr10PerSmplState |= BS_RD_END_10_PER_SMPL_MSK;
            			chbsHldr10PerSmplState &=~( BS_10_PER_SMPL_USED_MSK  | BS_10_PER_SMPL_RD_MSK ); 
						//Export Data 
						
						//`. i = Eval_CS((char*)&holderPrtTbl,
						//`. sizeof(PrtTblHldDsc)-sizeof( holderPrtTbl.lCheckSum) );
						//`. if (holderPrtTbl.lCheckSum== i)
						{
							//Cmp & Check
							//eeprom_prt_tbl  holderPrtTbl.UNPrtTbl.CfgPrtTbl;
							Read10PerSmplGood++;
							if(Read10PerSmplGood)
							chbsHldr10PerSmplState |= BS_RD_END_10_PER_SMPL_MSK;
						}
						//else
						//{
						//	//Fix Error Excange
						//	Read10PerSmplBad++;
						//}
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					 chbsHldr10PerSmplState &=~( BS_10_PER_SMPL_USED_MSK  | BS_10_PER_SMPL_RD_MSK );
            		 chbsHldr10PerSmplState &=~(  BS_RD_END_10_PER_SMPL_MSK);
            			Read10PerSmplBad++;	
					if(chCtrReading10PerSmpl	) chCtrReading10PerSmpl--;
					// Try Repeat
					
				
				
        		break;
        		
        		default:
        		if(chSureExecuteIciCall)
				  chSureExecuteIciCall-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}

/*

char chCtrWriting ;
void WriteCfgTbl(void)
{
register long i;
PrtTblStateDsc locPrtTblState;


	i = chbsHldrPrtTblState;
	//Check State Setting
	if( (i&(BS_WR_END_HLD_RPRT_TBL_MSK  )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_HLDR_PRT_TBL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_HLDR_PRT_TBL_WR_MSK )) == 0)
			{
				//Activate Reading
				chbsHldrPrtTblState |= BS_HLDR_PRT_TBL_USED_MSK|BS_HLDR_PRT_TBL_WR_MSK;
				//Move Data to Holder
                locPrtTblState.size_PrtTbl = sizeof(PrtTblHldDsc);//testPrtTblState.
                 locPrtTblState. p_PrtTbl    = (void*)&holderPrtTbl;
                 //Activate Get Data From Br
                 i =  ReqSendPrtTblBR(1,(void*)&locPrtTblState);
				 
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		//chStateExecReqSendStngBm = SUCCESS_EXEC;
						chSureExecute = 0;
                 		//Move if needed CfgPrtTbl
                 		break;
                 		case ERROR_EXEC:
                 			//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
                 			//.. if (i== ERROR_EXEC)
                 			//.. chStateExecReqGetStngBm = 0;
                 			//.. else
                 			//.. chStateExecReqGetStngBm = 1;
							//Simply Clear All in feature
							chSureExecute = 0;
                 		break;
                 		
                 		default:
                 		chSureExecute++;//Test Only
                 	
                 	}
				if(i ==  STATE_EXEC || i== START_EXEC)	
				chbsHldrPrtTblState |= ( BS_HLDR_PRT_TBL_USED_MSK | BS_HLDR_PRT_TBL_WR_MSK );
				//chSureExecute++;//This  part for additional control only
				
			}
		
		}
		
		
	}
	else
	{
		//Detect was reading Sucess or Not
		//Look Result Proxy tpt
		
		
		//If SUCCESS_EXEC Do Nothing
		//else Try Activate Reading again
		if( (i&(  BS_HLDR_PRT_TBL_WR_MSK )) == 0)//
		{
			;
			if((i&( BS_HLDR_PRT_TBL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_HLDR_PRT_TBL_USED_MSK )) == 0)
				{
					chbsHldrPrtTblState &=~(  BS_WR_END_HLD_RPRT_TBL_MSK);// Try Activate Writing again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsHldrPrtTblState;
	if( 
	(i&(BS_HLDR_PRT_TBL_WR_MSK  )) 
	&& (i&( BS_HLDR_PRT_TBL_USED_MSK ))
	)
	{
		//Check result Reading
		i =  ReqSendPrtTblBR(0,(void*)&locPrtTblState);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecute == 0)
				{
				 
					if(
						(locPrtTblState.size_PrtTbl == sizeof(PrtTblHldDsc))&&
					    (locPrtTblState.p_PrtTbl    == ( (void*)&holderPrtTbl )) 
					)
					{
						chbsHldrPrtTblState |= BS_WR_END_HLD_RPRT_TBL_MSK;
						chbsHldrPrtTblState &=~( BS_HLDR_PRT_TBL_USED_MSK | BS_HLDR_PRT_TBL_WR_MSK		); 
						
						//Export Data to bsCfgTbl
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					chbsHldrPrtTblState &=~( BS_HLDR_PRT_TBL_USED_MSK | BS_HLDR_PRT_TBL_WR_MSK );
					chbsHldrPrtTblState &=~( BS_WR_END_HLD_RPRT_TBL_MSK);
					// Try Repeat
					if (chCtrWriting) chCtrWriting--;
				
				
        		break;
        		
        		default:
        		if(chSureExecute)
				  chSureExecute-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}


long ReadPrtTblGood = 0;
long ReadPrtTblBad = 0;

char chCtrReading ;
void  ReadCfgTbl(void)//Last Modify for Getting data from BM
{
register long i;
PrtTblStateDsc locPrtTblState;

	i = chbsHldrPrtTblState;
	//Check State Setting
	if( (i&(BS_RD_END_HLD_RPRT_TBL_MSK )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_HLDR_PRT_TBL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_HLDR_PRT_TBL_RD_MSK )) == 0)
			{
				//Activate Reading
				chbsHldrPrtTblState |= BS_HLDR_PRT_TBL_USED_MSK|BS_HLDR_PRT_TBL_RD_MSK;
				//Move Data to Holder
                locPrtTblState.size_PrtTbl = sizeof(PrtTblHldDsc);//testPrtTblState.
                 locPrtTblState. p_PrtTbl    = (void*)&holderPrtTbl;
                 //Activate Get Data From Br
                 i = ReqGetPrtTblBR(1,(void*)&locPrtTblState);
				 
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		
						
                 		////Move if needed CfgPrtTbl
                 		//break;
                 		case ERROR_EXEC:
                 		chbsHldrPrtTblState &=	~(BS_HLDR_PRT_TBL_USED_MSK|BS_HLDR_PRT_TBL_RD_MSK);//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
                 			//.. if (i== ERROR_EXEC)
                 			//.. chStateExecReqGetStngBm = 0;
                 			//.. else
                 			//.. chStateExecReqGetStngBm = 1;
                 		break;
                 		
                 		default:
                 		chSureExecute++;//Test Only
                 	
                 	}

			}
		
		}
		
		
	}
	else
	{
		//Detect was reading Sucess or Not
		//Look Result Proxy tpt
		
		
		//If SUCCESS_EXEC Do Nothing
		//else Try Activate Reading again
		if( (i&( BS_HLDR_PRT_TBL_RD_MSK )) == 0)//
		{
			;
			if((i&( BS_HLDR_PRT_TBL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_HLDR_PRT_TBL_USED_MSK )) == 0)
				{
					chbsHldrPrtTblState &=~( BS_RD_END_HLD_RPRT_TBL_MSK);// Try Activate Reading again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsHldrPrtTblState;
	if( 
	(i&(BS_HLDR_PRT_TBL_RD_MSK )) 
	&& (i&( BS_HLDR_PRT_TBL_USED_MSK ))
	)
	{  
		//Check result Reading
		i = ReqGetPrtTblBR(0,(void*)&locPrtTblState);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecute == 0)
				{
				
					if(
					(locPrtTblState.size_PrtTbl == sizeof(PrtTblHldDsc))&&
					(locPrtTblState.p_PrtTbl    == ( (void*)&holderPrtTbl )) 
					)
					{
						//chbsHldrPrtTblState |= BS_RD_END_HLD_RPRT_TBL_MSK;
            			chbsHldrPrtTblState &=~( BS_HLDR_PRT_TBL_USED_MSK  | BS_HLDR_PRT_TBL_RD_MSK ); 
						//Export Data to bsCfgTbl
						
						i = Eval_CS((char*)&holderPrtTbl,
						sizeof(PrtTblHldDsc)-sizeof( holderPrtTbl.lCheckSum) );
						if (holderPrtTbl.lCheckSum== i)
						{
							//Cmp & Check
							//eeprom_prt_tbl  holderPrtTbl.UNPrtTbl.CfgPrtTbl;
							ReadPrtTblGood++;
							if(ReadPrtTblGood)
							chbsHldrPrtTblState |= BS_RD_END_HLD_RPRT_TBL_MSK;
						}
						else
						{
							//Fix Error Excange
							ReadPrtTblBad++;
						}
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					 chbsHldrPrtTblState &=~( BS_HLDR_PRT_TBL_USED_MSK  | BS_HLDR_PRT_TBL_RD_MSK );
            		 chbsHldrPrtTblState &=~(  BS_RD_END_HLD_RPRT_TBL_MSK);
            			ReadPrtTblBad++;	
					if(chCtrReading	) chCtrReading--;
					// Try Repeat
					
				
				
        		break;
        		
        		default:
        		if(chSureExecute)
				  chSureExecute-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}


*/













#pragma default_function_attributes = 





/* EOF */
