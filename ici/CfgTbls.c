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

#include    "CfgTbls.h"

#include "header_mal.h"
#include    "../inc/ici_ef.h"
#ifndef BS_RQ_RD_CFG_TBL_BIT
#define BS_RQ_RD_CFG_TBL_BIT       (1)
//-Бит запроса на запись к  системе Ici
#define BS_RQ_WR_CFG_TBL_BIT       (2)
//--Бит запроса на установку мин параметров CFG_TBL
#define BS_RQ_SET_MIN_CFG_TBL_BIT  (3)

#endif

long lStateWriting = 0;

//
// this  Obj for Primary hold data
 char  chReqCallServiceBsTblStates = 0;

 char chStateExecReqGetStngBm = 0;
//extern CfgTblDsc bsCfgTbl;//Main CfgTbl on BS


extern CfgTblDsc bsCfgTbl;//Main CfgTbl on BR


// char chbsCfgTblState @  "DMA_BUFFERS";
short shbsCfgTblState @  "DMA_BUFFERS";


 char chbsHldrPrtTblState @  "DMA_BUFFERS";


 char chbsStngTblState @  "DMA_BUFFERS";

 char chbsYstTblState @  "DMA_BUFFERS";
 
 char chbsWrCfgMinState @  "DMA_BUFFERS";

short shbsRQChangeCfgTablesState @  "DMA_BUFFERS";









extern char chbrCfgTblState;

void CollectCfgTbls(void)
{
//	register long i=0;
shbsRefreshCfgTablesState |=(1<<BS_RF_CFG_VAR_USED_BIT);	
shbsRefreshCfgTablesState |=
(1<<RQ_RD_STNG_TBL_BIT)|
(1<<RQ_RD_YUST_TBL_BIT) 
|(1<<RQ_RD_PRT_TBL_BIT);
	
	
shbsRefreshCfgTablesState &= ~(1<<BS_RF_CFG_VAR_USED_BIT);	
	
	//Activate Get Data from Br

}
void CollectCfgTblsOld(void)
{
	register long i=0;
	SettingsStateDsc locSettingsStateDsc;
	locSettingsStateDsc.size_current_settings = SIZE_SETTINGS_ICI;//testSettigsState.size_current_settings;
	locSettingsStateDsc.p_current_settings    = (void*)&hldStngIciTbl;
	//Activate Get Data From Bm
	i = ReqGetSettingsBM(1,(void*)&locSettingsStateDsc);
	switch(i)
		{
			case SUCCESS_EXEC:
			chStateExecReqGetStngBm = SUCCESS_EXEC;
			break;
			case ERROR_EXEC:
			i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
			if (i== ERROR_EXEC)
			chStateExecReqGetStngBm = 0;
			else
			chStateExecReqGetStngBm = 1;
			break;
			
			default:
			;
		
		}
	
	
	
	
	
	
	
	//Activate Get Data from Br


}

void CheckCfgTables(void)
{

	//Cmp Data  Bm & Bs
	
	//Cmp Data Br & Bs



}



void SendCfgData(void)
{
	

}
char chSureExecute = 0; 

void CheckStngState(void)
{
register long i;
SettingsStateDsc locSettingsStateDsc;


	i = chbsStngTblState;
	//Check State Setting
	if( (i&(BS_HLDR_STNG_TBL_USED_MSK )) == 0)//Table not Blocked
	{
		;
		if((i&(BS_RD_END_STNG_TBL_MSK)) == 0)//Check after Start
		{
			//Check if Not Read
			if((i&(BS_HLDR_STNG_TBL_RD_MSK )) == 0)
			{
				//Activate Reading
				chbsStngTblState |= BS_HLDR_STNG_TBL_USED_MSK|BS_HLDR_STNG_TBL_RD_MSK;
				//Move Data to Holder
                locSettingsStateDsc.size_current_settings = SIZE_SETTINGS_ICI;//testSettigsState.size_current_settings;
                locSettingsStateDsc.p_current_settings    = (void*)&hldStngIciTbl;
                 //Activate Get Data From Bm
                 i = ReqGetSettingsBM(1,(void*)&locSettingsStateDsc);
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		chStateExecReqGetStngBm = SUCCESS_EXEC;
						
                 		//Move if needed CfgPrtTbl
                 		break;
                 		case ERROR_EXEC:
                 			//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
                 			//.. if (i== ERROR_EXEC)
                 			//.. chStateExecReqGetStngBm = 0;
                 			//.. else
                 			//.. chStateExecReqGetStngBm = 1;
                 		break;
                 		
                 		default:
                 		chSureExecute++;
                 	
                 	}

			}
			else 
			{
				//Check result Reading
				i = ReqGetSettingsBM(0,(void*)&locSettingsStateDsc);
				switch(i)
            		{
            			case SUCCESS_EXEC:
						if(chSureExecute == 0)
						{
						
							if(
							(locSettingsStateDsc.size_current_settings == SIZE_SETTINGS_ICI)&&
							(locSettingsStateDsc.p_current_settings    == ((void*)&hldStngIciTbl) ) 
							)
							{
								chbsStngTblState |= BS_RD_END_STNG_TBL_MSK;
								chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_RD_MSK ); 
								//Export Data to bsCfgTbl
							}
						}
            			break;
            			case ERROR_EXEC:
							//Clear state then next time must be reading
							chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_RD_MSK );
							chbsStngTblState &=~( BS_RD_END_STNG_TBL_MSK);
							// Try Repeat
							
						
						
            			break;
            			
            			default:
            			chSureExecute-- ;
            		
            		}
				;//	
			
			}
		
		}
		else
		{
			//Control Result
			//Check result Reading
			i = ReqGetSettingsBM(0,(void*)&locSettingsStateDsc);
			//
		
		}
		
		//Control Update  Setting
	}
	else
	{
		if((i&(BS_HLDR_STNG_TBL_RD_MSK )) )
		{
			//Check result Reading
				i = ReqGetSettingsBM(0,(void*)&locSettingsStateDsc);
				switch(i)
            		{
            			case SUCCESS_EXEC:
						if(
						(locSettingsStateDsc.size_current_settings == SIZE_SETTINGS_ICI)&&
						(locSettingsStateDsc.p_current_settings    == ((void*)&hldStngIciTbl) ) 
						)
						{
							chbsStngTblState |= BS_RD_END_STNG_TBL_MSK;
							chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_RD_MSK ); 
							//Export Data to bsCfgTbl
						}	
            			break;
            			case ERROR_EXEC:
							//Clear state then next time must be reading
							chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_RD_MSK );
							chbsStngTblState &=~( BS_RD_END_STNG_TBL_MSK);
							// Try Repeat
							
						
						
            			break;
            			
            			default:
            			if(chSureExecute)
						chSureExecute-- ;
            		
            		}
				;//
			
			
			
		}
	}

}
void CheckPrtTblState(void)
{


register long i=0;
PrtTblStateDsc locPrtTblState;

	i =  chbsHldrPrtTblState;
	//Check State Setting
	if(i&( BS_HLDR_PRT_TBL_USED_MSK  ) == 0)//Table not Blocked
	{
		;
		if(i&( BS_RD_END_HLD_RPRT_TBL_MSK ) == 0)//Check after Start
		{
			//Check if Not Read
			if(i&(BS_HLDR_PRT_TBL_RD_MSK ) == 0)
			{
                //Activate Reading
                chbsHldrPrtTblState |= BS_HLDR_PRT_TBL_USED_MSK |BS_HLDR_PRT_TBL_RD_MSK;
                //Move Data to Holder
                locPrtTblState.size_PrtTbl = sizeof(PrtTblHldDsc);//testPrtTblState.
                 locPrtTblState. p_PrtTbl    = (void*)&holderPrtTbl;
                 //Activate Get Data From Bm
                 i = ReqGetPrtTblBR(1,(void*)&locPrtTblState);
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		//chStateExecReqGetStngBm = SUCCESS_EXEC;
                 		//Move if needed CfgPrtTbl
                 		break;
                 		case ERROR_EXEC:
                 			//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
                 			//.. if (i== ERROR_EXEC)
                 			//.. chStateExecReqGetStngBm = 0;
                 			//.. else
                 			//.. chStateExecReqGetStngBm = 1;
                 		break;
                 		
                 		default:
                 		;
                 	
                 	}

			}
			else 
			{
				//Check result Reading
				i = ReqGetPrtTblBR(0,(void*)&locPrtTblState);
				switch(i)
            		{
            			case SUCCESS_EXEC:
            			chbsHldrPrtTblState |= BS_RD_END_HLD_RPRT_TBL_MSK;
            			chbsHldrPrtTblState &=~( BS_HLDR_PRT_TBL_USED_MSK  | BS_HLDR_PRT_TBL_RD_MSK ); 
            			break;
            			case ERROR_EXEC:
            				//Clear state then next time must be reading
            				 chbsHldrPrtTblState &=~( BS_HLDR_PRT_TBL_USED_MSK  | BS_HLDR_PRT_TBL_RD_MSK );
            				 chbsHldrPrtTblState &=~(  BS_RD_END_HLD_RPRT_TBL_MSK);
            				// Try Repeat
            				
            			
            			
            			break;
            			
            			default:
            			;
            		
            		}
				;// 
			
			}
		
		}
		else
		{
			//Control Result
			
		
		}
		
		//Control Update  Setting
	}

}

short shbsRefreshCfgTablesState @  "DMA_BUFFERS";
void RefreshCfgTables(void)
{
	
	register long i = 0;
	
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
				lStateWriting |= (1<<(WR_PRT_TBL_BIT ));
			 }
		     WriteCfgTbl();
		     if(chbsHldrPrtTblState&(1<<BS_WR_END_HLDR_PRT_TBL_ONB))
		     {
		        lStateWriting &= ~(1<<(WR_PRT_TBL_BIT));
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



	if(
	(shbsRefreshCfgTablesState&(1<<RQ_WR_STNG_TBL_BIT))||
	chCtrWritingStng
	)//Writing was fail
	{
		i = chbsStngTblState;
		if( 
		(i&(BS_HLDR_STNG_TBL_RD_MSK )) 
		&& (i&( BS_HLDR_STNG_TBL_USED_MSK ))
		){
		//In any cases wait result operation success or not
		;//
		}
		else
		{
		
			//Clear Wr State
			if(chbsStngTblState&(1<<BS_WR_END_STNG_TBL_ONB))
			{
				chbsStngTblState&=~(1<<BS_WR_END_STNG_TBL_ONB);
				
			}
			if(shbsRefreshCfgTablesState&(1<<RQ_WR_STNG_TBL_BIT ))
			 {
				chCtrWritingStng = 3;//Counter popitoc write activation
				//Clear Rq State
		     	shbsRefreshCfgTablesState &= ~(1<<RQ_WR_STNG_TBL_BIT );
				lStateWriting |= (1<<(WR_STNG_TBL_BIT ));
			 }
			WriteStngState();
			if(chbsStngTblState&(1<<BS_WR_END_STNG_TBL_ONB))
			{
				chCtrWritingStng = 0;
				lStateWriting &= ~(1<<(WR_STNG_TBL_BIT) );
			//Clear Rq State
				//shbsRefreshCfgTablesState &= ~(1<<RQ_WR_STNG_TBL_BIT);
			}
			 goto ExitRefreshCfgTables;
		}
	}
	
	//else
	//CheckStngState();
	if(
	(shbsRefreshCfgTablesState&(1<<RQ_RD_STNG_TBL_BIT ))
	|| chCtrReadingStng)//Writing was fail
	{
		//Clear Wr State
		if(chbsStngTblState&(1<<BS_RD_END_STNG_TBL_ONB))
		{
			chbsStngTblState&=~(1<<BS_RD_END_STNG_TBL_ONB);
			
		}
		if(shbsRefreshCfgTablesState&(1<<RQ_RD_STNG_TBL_BIT ))
		 {
			chCtrReadingStng = 17;
			//Clear Rq State
			shbsRefreshCfgTablesState &= ~(1<<RQ_RD_STNG_TBL_BIT );
		 }
		ReadStngTbl();
		if(chbsStngTblState&(1<<BS_RD_END_STNG_TBL_ONB))
		{
		//Clear Rq State
			//shbsRefreshCfgTablesState &= ~(1<<RQ_RD_STNG_TBL_BIT );
			chCtrReadingStng = 0;
		}
		goto ExitRefreshCfgTables;
	}
//Check State Yst
//Control Update Ust
	if(
	(shbsRefreshCfgTablesState&(1<<RQ_WR_YUST_TBL_BIT ))||
	chCtrWritingYst
	)//Writing was fail
	{
		//Clear Wr State
		if(chbsYstTblState&(1<<BS_WR_END_YUST_TBL_ONB))
		{
			chbsYstTblState&=~(1<<BS_WR_END_YUST_TBL_ONB);
			
		}
		if(shbsRefreshCfgTablesState&(1<<RQ_WR_YUST_TBL_BIT ))
			 {
				chCtrWritingYst = 3;//Counter popitoc write activation
				//Clear Rq State
		     	shbsRefreshCfgTablesState &= ~(1<<RQ_WR_YUST_TBL_BIT );
			 }
		WriteYstState();
		if(chbsYstTblState&(1<<BS_WR_END_YUST_TBL_ONB))
		{
		//Clear Rq State
			//shbsRefreshCfgTablesState &= ~(1<<RQ_WR_YUST_TBL_BIT );
			chCtrWritingYst = 0;
		}
		goto ExitRefreshCfgTables;
	}
	//else
	//CheckStngState();
	if((shbsRefreshCfgTablesState&(1<<RQ_RD_YUST_TBL_BIT ))
	||chCtrReadingYst
	)//Writing was fail
	{
		//Clear Wr State
		if(chbsYstTblState&(1<<BS_RD_END_YUST_TBL_ONB))
		{
			chbsYstTblState&=~(1<<BS_RD_END_YUST_TBL_ONB);
			
		}
		if(shbsRefreshCfgTablesState&(1<<RQ_RD_YUST_TBL_BIT ))
		 {
			chCtrReadingYst = 17;
			//Clear Rq State
			shbsRefreshCfgTablesState &= ~(1<<RQ_RD_YUST_TBL_BIT );
		 }
		ReadYstTbl();
		if(chbsYstTblState&(1<<BS_RD_END_YUST_TBL_ONB))
		{
			chCtrReadingYst = 0;
		//Clear Rq State
			//shbsRefreshCfgTablesState &= ~(1<<RQ_RD_YUST_TBL_BIT );
		}
		goto ExitRefreshCfgTables;
	}
	if(shbsRefreshCfgTablesState&(1<<RQ_WR_MIN_CFG_TBL_BIT ))//Writing was fail
	{
		//Clear Wr State
		if(shbsCfgTblState&(1<<BS_WR_END_CFG_MIN_ONB))
		{
			shbsCfgTblState&=~(1<<BS_WR_END_CFG_MIN_ONB);
			
		}
		ForceSetMinParamCfgTbl();//ReadYstTbl();
		if(shbsCfgTblState&(1<<BS_WR_END_CFG_MIN_ONB))
		{
		//Clear Rq State
			shbsRefreshCfgTablesState &= ~(1<<RQ_WR_MIN_CFG_TBL_BIT );
		}
		goto ExitRefreshCfgTables;
	}
	if(shbsRefreshCfgTablesState== 0)
	{
		if (shbsRQChangeCfgTablesState&(1<<BS_RQ_SET_MIN_CFG_TBL_BIT))
		{
			shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
			//Recode Req Bit
			//..if(shbsRQChangeCfgTablesState&(1<<BS_RQ_SET_MIN_CFG_TBL_BIT) )
			shbsRefreshCfgTablesState |= 1<<RQ_WR_MIN_CFG_TBL_BIT;
			_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT);
			shbsRQChangeCfgTablesState &= ~(1<<BS_RQ_SET_MIN_CFG_TBL_BIT);
			shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
			goto ExitRefreshCfgTables;
		}
		if (shbsRQChangeCfgTablesState&(1<<BS_RQ_WR_CFG_TBL_BIT))
		{
			_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT);
			PrepareDhldStngIciTblforTrOnBM();
			PrepareDholderPrtTblforTrOnBR();
			shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
			shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT);
			shbsRQChangeCfgTablesState &= ~(1<<BS_RQ_WR_CFG_TBL_BIT);
			shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
			goto ExitRefreshCfgTables;
		}
		IciDbgCall_I_Fn();
	
	}







//
ExitRefreshCfgTables:
return;


}


void ServiceBsTblStates(void)
{

}

long ReadstngTblGood = 0;
long ReadstngTblBad  = 0;
  char chCtrReadingStng = 0;
void ReadStngTbl(void)//Last Modify for Getting data from BM
{
register long i;
SettingsStateDsc locSettingsStateDsc;


	i = chbsStngTblState;
	//Check State Setting
	if( (i&(BS_RD_END_STNG_TBL_MSK )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_HLDR_STNG_TBL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_HLDR_STNG_TBL_RD_MSK )) == 0)
			{
				//Activate Reading
				chbsStngTblState |= BS_HLDR_STNG_TBL_USED_MSK|BS_HLDR_STNG_TBL_RD_MSK;
				//Move Data to Holder
                locSettingsStateDsc.size_current_settings = SIZE_SETTINGS_ICI;//testSettigsState.size_current_settings;
                locSettingsStateDsc.p_current_settings    = (void*)&hldStngIciTbl;
                 //Activate Get Data From Bm
                 i = ReqGetSettingsBM(1,(void*)&locSettingsStateDsc);
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		chStateExecReqGetStngBm = SUCCESS_EXEC;
						
                 		//Move if needed CfgPrtTbl
                 		break;
                 		case ERROR_EXEC:
                 			//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
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
		if( (i&( BS_HLDR_STNG_TBL_RD_MSK )) == 0)//
		{
			;
			if((i&( BS_HLDR_STNG_TBL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_HLDR_STNG_TBL_USED_MSK )) == 0)
				{
					chbsStngTblState &=~( BS_RD_END_STNG_TBL_MSK);// Try Activate Reading again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsStngTblState;
	if( 
	(i&(BS_HLDR_STNG_TBL_RD_MSK )) 
	&& (i&( BS_HLDR_STNG_TBL_USED_MSK ))
	)
	{
		//Check result Reading
		i = ReqGetSettingsBM(0,(void*)&locSettingsStateDsc);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecute == 0)
				{
				
					if(
					(locSettingsStateDsc.size_current_settings == SIZE_SETTINGS_ICI)&&
					(locSettingsStateDsc.p_current_settings    == ((void*)&hldStngIciTbl) ) 
					)
					{
						
						chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_RD_MSK ); 
						//Export Data to bsCfgTbl
						i = Eval_CS((char*)&hldStngIciTbl,
						(SIZE_SETTINGS_ICI)-sizeof( hldStngIciTbl.lCheckSum) );
						if (hldStngIciTbl.lCheckSum== i)
						{
							//Cmp & Check
							//eeprom_prt_tbl  holderPrtTbl.UNPrtTbl.CfgPrtTbl;
							ReadstngTblGood++;
							if(ReadstngTblGood)
							chbsStngTblState |= BS_RD_END_STNG_TBL_MSK;
							
						}
						else
						{
							//Fix Error Excange
							ReadstngTblBad++;
						}
						
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_RD_MSK );
					chbsStngTblState &=~( BS_RD_END_STNG_TBL_MSK);
					// Try Repeat
					ReadstngTblBad++;
					if (chCtrReadingStng) chCtrReadingStng--;
				
				
        		break;
        		
        		default:
        		if(chSureExecute)
				  chSureExecute-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}
  char chCtrWritingStng = 0;
void WriteStngState(void)
{
register long i;
SettingsStateDsc locSettingsStateDsc;


	i = chbsStngTblState;
	//Check State Setting
	if( (i&(BS_WR_END_STNG_TBL_MSK  )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_HLDR_STNG_TBL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_HLDR_STNG_TBL_WR_MSK )) == 0)
			{
				//Activate Reading
				chbsStngTblState |= BS_HLDR_STNG_TBL_USED_MSK|BS_HLDR_STNG_TBL_WR_MSK;
				//Move Data to Holder
                locSettingsStateDsc.size_current_settings = SIZE_SETTINGS_ICI;//testSettigsState.size_current_settings;
                locSettingsStateDsc.p_current_settings    = (void*)&hldStngIciTbl;
                 //Activate Get Data From Bm
                 i = ReqSendSettingsBM(1,(void*)&locSettingsStateDsc);
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
				chbsStngTblState |= ( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_WR_MSK );
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
		if( (i&(  BS_HLDR_STNG_TBL_WR_MSK )) == 0)//
		{
			;
			if((i&( BS_HLDR_STNG_TBL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_HLDR_STNG_TBL_USED_MSK )) == 0)
				{
					chbsStngTblState &=~(  BS_WR_END_STNG_TBL_MSK);// Try Activate Writing again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsStngTblState;
	if( 
	(i&(BS_HLDR_STNG_TBL_WR_MSK )) 
	&& (i&( BS_HLDR_STNG_TBL_USED_MSK ))
	)
	{
		//Check result Reading
		i = ReqSendSettingsBM(0,(void*)&locSettingsStateDsc);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecute == 0)
				{
				
					if(
					(locSettingsStateDsc.size_current_settings == SIZE_SETTINGS_ICI)&&
					(locSettingsStateDsc.p_current_settings    == ((void*)&hldStngIciTbl) ) 
					)
					{
						chbsStngTblState |= BS_WR_END_STNG_TBL_MSK;
						chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_WR_MSK ); 
						
						//Export Data to bsCfgTbl
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					chbsStngTblState &=~( BS_HLDR_STNG_TBL_USED_MSK | BS_HLDR_STNG_TBL_WR_MSK);
					chbsStngTblState &=~( BS_WR_END_STNG_TBL_MSK);
					// Try Repeat
					if (chCtrWritingStng) chCtrWritingStng--;
				
				
        		break;
        		
        		default:
        		if(chSureExecute)
				  chSureExecute-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}

//void PrepareDhldStngIciTblforTrOnBM(void) ;
//void PrepareDholderPrtTblforTrOnBR(void) ;

//G:\HVP_pj\Hvps\hvps_B_03_04_15\HS1_0100_00_i720\inc\variables_external_twi.h

void ActivateTransmittion_StngAndPrt(void)
{
_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT);
//Set Trigger

 //BS_RF_CFG_VAR_USED_BIT <- Means My example table busy and any operation now impossible
if(shbsRefreshCfgTablesState
&( (1<<BS_RF_CFG_VAR_USED_BIT)|(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT) )
)
return;
shbsRefreshCfgTablesState |=(1<<BS_RF_CFG_VAR_USED_BIT);
PrepareDhldStngIciTblforTrOnBM();
PrepareDholderPrtTblforTrOnBR();
shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT);

shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
}


void PrepareDhldStngIciTblforTrOnBM(void) 
{
register long i;//,j;
register char *pDst;//*pSrc;//,
void* pTbl;

	hldStngIciTbl.lCheckSum = 0;
	//Import from CfgPrtTbl 
	pTbl = (void*)&eeprom_prt_tbl;
	pDst = (char*)&(hldStngIciTbl.UNStngIciTbl.StngIciTbl);
	
	for (i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
	{
		// Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
		((__SETTINGS* )pDst)->dz1_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz2_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz3_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz4_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz5_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		
		 // Угол доворота для МТЗ
		((__SETTINGS* )pDst)->mtz1_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz2_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz3_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz4_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz5_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		 // Угол доворота для ТЗНП
		((__SETTINGS* )pDst)->tznp1_angle_r[i] = 
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;
        ((__SETTINGS* )pDst)->tznp2_angle_r[i] =
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp3_angle_r[i] =
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp4_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp5_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;
		 // Угол доворота для ZOP
		((__SETTINGS* )pDst)->zop1_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;
	    ((__SETTINGS* )pDst)->zop2_angle_r[i] =
	    ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;
        
	}

	//Set Additional Field
	// /-*Рассогласование углов
    //    0 - Usyn
    //    1 - Isyn
    //    0 - Ua
    //    1 - Ub
    //    2 - Uc
	
    i = ((CfgTblDsc*)pTbl)-> ownrTr_Line.chLineWGV == I_SYN;
	
//	((__SETTINGS* )pDst)->a_Usyn_Isyn = ;
//	else
//	((__SETTINGS* )pDst)->a_Usyn_Isyn = 0;
	
	switch(i)
	{
	case I_SYN:
	
	((__SETTINGS* )pDst)->a_Usyn_Isyn =  U_SYN;
	break;
	case U_SYN:
	((__SETTINGS* )pDst)->a_Usyn_Isyn =  I_SYN;
	break;
	case UAB_TH2:
	((__SETTINGS* )pDst)->a_Usyn_Isyn = i; 
	break;
	
	default:
	;
	}
	
	
	
	//((CfgTblDsc*)pTbl)-> uc_Usyn_Isyn_selection;
	if (((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase >3 )
	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase = 0;
	((__SETTINGS* )pDst)-> a_Ua_Ub_Uc =
	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase;
	//((__SETTINGS* )pDst)->In_type_shon = 0;//Temp
	//((CfgTblDsc*)pTbl)-> uc_Type_shon_selection;
	
	//Put check sum
		i = Eval_CS((char*)&hldStngIciTbl,
	sizeof(StngIciTblDsc)-sizeof( hldStngIciTbl.lCheckSum) );
	
	hldStngIciTbl.lCheckSum = i;
	//Activate Transmittion
	//holderSettings.UNSettings.current_settings = hldStngIciTbl.UNStngIciTbl.StngIciTbl;
	//holderSettings.lCheckSum = hldStngIciTbl.lCheckSum;
	
	//locSettigsState.size_current_settings = SIZE_SETTINGS_ICI;
	//locSettigsState.p_current_settings    = (void*)&hldStngIciTbl;
	// ReqSendSettingsBM(1,&locSettigsState);



	//shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT);
}
void PrepareDholderPrtTblforTrOnBR(void)
{
	holderPrtTbl.UNPrtTbl.CfgPrtTbl = eeprom_prt_tbl;
	holderPrtTbl.lCheckSum = Eval_CS((char*)&holderPrtTbl,
	sizeof(PrtTblHldDsc)-sizeof( holderPrtTbl.lCheckSum) );
}


void ActivateTransmittionStngOnBM_V(void) 
{
register long i;//,j;
register char *pDst;//*pSrc;//,
void* pTbl;

	hldStngIciTbl.lCheckSum = 0;
	//Import from CfgPrtTbl 
	pTbl = (void*)&eeprom_prt_tbl;
	pDst = (char*)&(hldStngIciTbl.UNStngIciTbl.StngIciTbl);
	
	for (i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
	{
		// Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
		((__SETTINGS* )pDst)->dz1_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz2_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz3_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz4_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		((__SETTINGS* )pDst)->dz5_K[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		
		 // Угол доворота для МТЗ
		((__SETTINGS* )pDst)->mtz1_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz2_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz3_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz4_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		((__SETTINGS* )pDst)->mtz5_angle_r[i] = 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		 // Угол доворота для ТЗНП
		((__SETTINGS* )pDst)->tznp1_angle_r[i] = 
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;
        ((__SETTINGS* )pDst)->tznp2_angle_r[i] =
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp3_angle_r[i] =
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp4_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;
		((__SETTINGS* )pDst)->tznp5_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;
		 // Угол доворота для ZOP
		((__SETTINGS* )pDst)->zop1_angle_r[i] =
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;
	    ((__SETTINGS* )pDst)->zop2_angle_r[i] =
	    ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;
        
	}

	//Set Additional Field
	// /-*Рассогласование углов
    //    0 - Usyn
    //    1 - Isyn
    //    0 - Ua
    //    1 - Ub
    //    2 - Uc
  
	((__SETTINGS* )pDst)->a_Usyn_Isyn = 0;
	//((CfgTblDsc*)pTbl)-> uc_Usyn_Isyn_selection;
	if (((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase >3 )
	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase = 0;
	((__SETTINGS* )pDst)-> a_Ua_Ub_Uc =
	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase;
	//((__SETTINGS* )pDst)->In_type_shon = 0;//Temp
	//((CfgTblDsc*)pTbl)-> uc_Type_shon_selection;
	
	//Put check sum
		i = Eval_CS((char*)&hldStngIciTbl,
	sizeof(StngIciTblDsc)-sizeof( hldStngIciTbl.lCheckSum) );
	
	hldStngIciTbl.lCheckSum = i;
	//Activate Transmittion
	//holderSettings.UNSettings.current_settings = hldStngIciTbl.UNStngIciTbl.StngIciTbl;
	//holderSettings.lCheckSum = hldStngIciTbl.lCheckSum;
	
	//locSettigsState.size_current_settings = SIZE_SETTINGS_ICI;
	//locSettigsState.p_current_settings    = (void*)&hldStngIciTbl;
	// ReqSendSettingsBM(1,&locSettigsState);



	//shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT);
}


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

 char chCtrWritingYst = 0;
void WriteYstState(void)
{
register long i;
YustStateDsc locYustTblState;

	i = chbsYstTblState;
	//Check State Setting
	if( (i&(BS_WR_END_YUST_TBL_MSK  )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_HLDR_YUST_TBL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_HLDR_YUST_TBL_WR_MSK )) == 0)
			{
				//Activate Reading
				chbsYstTblState |= BS_HLDR_YUST_TBL_USED_MSK|BS_HLDR_YUST_TBL_WR_MSK;
				//Move Data to Holder
                locYustTblState.size_ustuvannja_BS = sizeof(YustHldDsc);//testPrtTblState.
                 locYustTblState. p_ustuvannja_BS    = (void*)&holderYust;
				 i =   Eval_CS((char*)&holderYust,
			sizeof(YustHldDsc)-sizeof( holderYust.lCheckSum) );	
			holderYust.lCheckSum = i;	
	
                 //Activate Get Data From Br
                 i =  ReqSendYustBM(1,(void*)&locYustTblState);
				 
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
				chbsYstTblState |= ( BS_HLDR_YUST_TBL_USED_MSK | BS_HLDR_YUST_TBL_WR_MSK );
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
		if( (i&(  BS_HLDR_YUST_TBL_WR_MSK )) == 0)//
		{
			;
			if((i&( BS_HLDR_YUST_TBL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_HLDR_YUST_TBL_USED_MSK )) == 0)
				{
					chbsYstTblState &=~(  BS_WR_END_YUST_TBL_MSK);// Try Activate Writing again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsYstTblState;
	if( 
	(i&(BS_HLDR_YUST_TBL_WR_MSK  )) 
	&& (i&( BS_HLDR_YUST_TBL_USED_MSK ))
	)
	{
		//Check result Reading
		i =  ReqSendYustBM(0,(void*)&locYustTblState);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecute == 0)
				{
				
					if(
						(locYustTblState.size_ustuvannja_BS == sizeof(YustHldDsc))&&
					    (locYustTblState.p_ustuvannja_BS    == ( (void*)&holderYust )) 
					)
					{
						chbsYstTblState |= BS_WR_END_YUST_TBL_MSK;
						chbsYstTblState &=~( BS_HLDR_YUST_TBL_USED_MSK | BS_HLDR_YUST_TBL_WR_MSK  ); 
						//Export Data to bsCfgTbl
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					chbsYstTblState &=~( BS_HLDR_YUST_TBL_USED_MSK | BS_HLDR_YUST_TBL_WR_MSK );
					chbsYstTblState &=~( BS_WR_END_YUST_TBL_MSK);
					// Try Repeat
					if(chCtrWritingYst	) chCtrWritingYst--;
				
				
        		break;
        		
        		default:
        		if(chSureExecute)
				  chSureExecute-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}
long ReadYstTblGood = 0;
long ReadYstTblBad = 0;
  char chCtrReadingYst = 0;
void  ReadYstTbl(void)//Last Modify for Getting data from BM
{
register long i;
YustStateDsc locYustTblState;

	i = chbsYstTblState;
	//Check State Setting
	if( (i&(BS_RD_END_YUST_TBL_MSK )) == 0)//Table not Read At Contorolled Period
	{
		;
		if( (i&(BS_HLDR_YUST_TBL_USED_MSK )) == 0)//Table not Blocked Possible Writing write now
		{
			//Check if Not Read
			if((i&(BS_HLDR_YUST_TBL_RD_MSK  )) == 0)
			{
				//Activate Reading
				chbsYstTblState |= BS_HLDR_YUST_TBL_USED_MSK|BS_HLDR_YUST_TBL_RD_MSK ;
				//Move Data to Holder
                locYustTblState.size_ustuvannja_BS = sizeof(YustHldDsc);//testPrtTblState.
                 locYustTblState.p_ustuvannja_BS     = (void*)&holderYust;
                 //Activate Get Data From Br
                 i =  ReqGetYustBM(1,(void*)&locYustTblState);
				 
                 switch(i)
                 	{
                 		case SUCCESS_EXEC:
                 		
						
                 		////Move if needed CfgPrtTbl
                 		//break;
                 		case ERROR_EXEC:
                 		chbsYstTblState &=	~(BS_HLDR_YUST_TBL_USED_MSK|BS_HLDR_YUST_TBL_RD_MSK );//.. i =   ReqGetSettingsBM(1,&locSettingsStateDsc);
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
		if( (i&( BS_HLDR_YUST_TBL_RD_MSK  )) == 0)//
		{
			;
			if((i&( BS_HLDR_YUST_TBL_ICI_MF_MSK )) == 0)
			{
				if((i&( BS_HLDR_YUST_TBL_USED_MSK )) == 0)
				{
					chbsYstTblState &=~( BS_RD_END_YUST_TBL_MSK);// Try Activate Reading again
				
				}
			
			
			}
			
			//Control Update  Setting
		}
		
	}

	//Control Update  Setting
	i = chbsYstTblState;
	if( 
	(i&(BS_HLDR_YUST_TBL_RD_MSK  )) 
	&& (i&( BS_HLDR_YUST_TBL_USED_MSK ))
	)
	{  
		//Check result Reading
		i =  ReqGetYustBM(0,(void*)&locYustTblState);
		switch(i)
        	{
        		case SUCCESS_EXEC:
				if(chSureExecute == 0)
				{
				
					if(
					(locYustTblState.size_ustuvannja_BS == sizeof(YustHldDsc))&&
					(locYustTblState.p_ustuvannja_BS    == ( (void*)&holderYust )) 
					)
					{
						//chbsYstTblState |= BS_RD_END_YUST_TBL_MSK;
            			chbsYstTblState &=~( BS_HLDR_YUST_TBL_USED_MSK  | BS_HLDR_YUST_TBL_RD_MSK  ); 
						//Export Data to bsCfgTbl
						
						i = Eval_CS((char*)&holderYust,
						sizeof(YustHldDsc)-sizeof( holderYust.lCheckSum) );
						if (holderYust.lCheckSum== i)
						{
							//Cmp & Check
							//eeprom_prt_tbl  holderPrtTbl.UNPrtTbl.CfgPrtTbl;
							ReadYstTblGood++;
							if(ReadYstTblGood)
							chbsYstTblState |= BS_RD_END_YUST_TBL_MSK;
						}
						else
						{
							//Fix Error Excange
							ReadYstTblBad++;
						}
					}
				}
        		break;
        		case ERROR_EXEC:
					//Investigate reason 
					//Look Proxy state					
					//Clear state then next time must be reading
					 chbsYstTblState &=~( BS_HLDR_YUST_TBL_USED_MSK  | BS_HLDR_YUST_TBL_RD_MSK  );
            		 chbsYstTblState &=~(  BS_RD_END_YUST_TBL_MSK);
            			ReadYstTblBad++;
					if(chCtrReadingYst	) chCtrReadingYst--;						
					// Try Repeat
					
				
				
        		break;
        		
        		default:
        		if(chSureExecute)
				  chSureExecute-- ;
        	
        	}
		;//	
		
	    
	    
	
	}
}

extern CfgTblDsc eeprom_prt_tbl;
extern long CheckCorrectnesPrtTbl(void* pCfgTbl);
// extern void SetPrtTestVal(void* pTbl);
extern void SetPrtTestVal1(void* pTbl);

void ForceSetMinParamCfgTbl(void)
{
//long i= CheckCorrectnesPrtTbl((void*)&eeprom_prt_tbl);
shbsCfgTblState|= (1<< BS_CFG_TBL_USED_BIT);
SetPrtTestVal1((void*)&eeprom_prt_tbl);
shbsCfgTblState|= (1<< BS_WR_END_CFG_MIN_ONB );
shbsCfgTblState&=~(1<< BS_CFG_TBL_USED_BIT);
_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT);
command_menu |= (1 << REWRITE_MENU);

}


long CheckDhldStngIciTblforTrOnBM(void) 
{
register long i;//,j;
register char *pDst;//*pSrc;//,
void* pTbl;
long lDiffCount;

lDiffCount = 0;

	hldStngIciTbl.lCheckSum = 0;
	//Import from CfgPrtTbl 
	pTbl = (void*)&eeprom_prt_tbl;
	pDst = (char*)&(hldStngIciTbl.UNStngIciTbl.StngIciTbl);
	
	for (i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
	{
		// Коефіцієнт компенсації фазного струму струмом нульової послідовності для однофазного дистанційного захисту (для кожної ступені і для всіх груп)
		if(
		((__SETTINGS* )pDst)->dz1_K[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur
		)
		{
		
//		((__SETTINGS* )pDst)->dz1_K[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1Dstp1Pickup.Dstp1_Coef_Compens_IntPhaseCur;
		lDiffCount++;
		}
		if(
		((__SETTINGS* )pDst)->dz2_K[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur
		)
		{
//		((__SETTINGS* )pDst)->dz2_K[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->dz3_K[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur
		)
		{
//		((__SETTINGS* )pDst)->dz3_K[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->dz4_K[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur
		)
		{
//		((__SETTINGS* )pDst)->dz4_K[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->dz5_K[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur
		)
		{
//		((__SETTINGS* )pDst)->dz5_K[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5Dstp2Pickup.Dstp2_Coef_Compens_IntPhaseCur;
		lDiffCount++;
		}
		
		
		if(
		 // Угол доворота для МТЗ
		((__SETTINGS* )pDst)->mtz1_angle_r[i] != 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage
		)
		{
//		((__SETTINGS* )pDst)->mtz1_angle_r[i] = 
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrOcp1Pickup.mcp1_AngleRotation_linear_voltage;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->mtz2_angle_r[i] != 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage
		)
		{
//		((__SETTINGS* )pDst)->mtz2_angle_r[i] = 
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->mtz3_angle_r[i] != 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage
		)
		{
//		((__SETTINGS* )pDst)->mtz3_angle_r[i] = 
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->mtz4_angle_r[i] != 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage
		)
		{
//		((__SETTINGS* )pDst)->mtz4_angle_r[i] = 
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->mtz5_angle_r[i] != 
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage
		)
		{
//		((__SETTINGS* )pDst)->mtz5_angle_r[i] = 
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrOcp2Pickup.mcp_AngleRotation_linear_voltage;
		lDiffCount++;
		}
		
		 if(
		// Угол доворота для ТЗНП
		((__SETTINGS* )pDst)->tznp1_angle_r[i] != 
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp
		)
		{
//		((__SETTINGS* )pDst)->tznp1_angle_r[i] = 
//        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1DrErthPickup.AngleRotation_3I0_Tznp;
		lDiffCount++;
		}
		
        if(
		((__SETTINGS* )pDst)->tznp2_angle_r[i] !=
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp
		)
		{
//		((__SETTINGS* )pDst)->tznp2_angle_r[i] =
//        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2DrErthPickup.AngleRotation_3I0_Tznp;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->tznp3_angle_r[i] !=
        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp
		)
		{
//		((__SETTINGS* )pDst)->tznp3_angle_r[i] =
//        ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage3DrErthPickup.AngleRotation_3I0_Tznp;
		lDiffCount++;
		}
		
		if(
		((__SETTINGS* )pDst)->tznp4_angle_r[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp
		)
		{
//		((__SETTINGS* )pDst)->tznp4_angle_r[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage4DrErthPickup.AngleRotation_3I0_Tznp;
		lDiffCount++;
		}
		
		if(
		
		((__SETTINGS* )pDst)->tznp5_angle_r[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp
		)
		{
//		((__SETTINGS* )pDst)->tznp5_angle_r[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage5DrErthPickup.AngleRotation_3I0_Tznp;
		lDiffCount++;
		}
		
		 if(
		// Угол доворота для ZOP
		((__SETTINGS* )pDst)->zop1_angle_r[i] !=
		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp
		)
		{
//		((__SETTINGS* )pDst)->zop1_angle_r[i] =
//		((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage1NspPickupStoreDsc.AngleRotation_U_Nsmp;
		lDiffCount++;
		}
		
	    if(
		((__SETTINGS* )pDst)->zop2_angle_r[i] !=
	    ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp
		)
		{
//        ((__SETTINGS* )pDst)->zop2_angle_r[i] =
//	    ((CfgTblDsc*)pTbl)-> arPckpStpmStngStore[i].ownrStage2NspPickupStoreDsc.AngleRotation_U_Nsmp;
        lDiffCount++;
		}
		
	}

	//Set Additional Field
	// /-*Рассогласование углов
    //    0 - Usyn
    //    1 - Isyn
    //    0 - Ua
    //    1 - Ub
    //    2 - Uc
  
//.	((__SETTINGS* )pDst)->a_Usyn_Isyn = 0;
//.	//((CfgTblDsc*)pTbl)-> uc_Usyn_Isyn_selection;
//.	if (((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase >3 )
//.	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase = 0;
//.	
//.	((__SETTINGS* )pDst)-> a_Ua_Ub_Uc =
//.	((CfgTblDsc*)pTbl)-> ownrRclrMng.selectPhase;
	//((__SETTINGS* )pDst)->In_type_shon = 0;//Temp
	//((CfgTblDsc*)pTbl)-> uc_Type_shon_selection;
	

return lDiffCount;

	//shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT);
}

















/* EOF */
