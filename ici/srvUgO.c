

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
* File Name       : srvUgO.c service urgent Object
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  22/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#include    "srvUO.h"
#include    "fcoil.h"
#include    "dt_tm.h"
#include    "atrcmd.h"
#include   <string.h>


 char chBsFCoilState;
 char chBsDateTimeState;
 char chBsCmdState;

  short shbsUrgObjIciCallState  @  "DMA_BUFFERS";
  short shbsUrgObjCopyIciCallState  @  "DMA_BUFFERS";
  
 short shbsUrgObjIciUsedState  @  "DMA_BUFFERS";

BrSetInOutDsc hldBrSetInOut;
  
  BrDateTime hldrDtTm = {
  0x12,03,03,04,01,01,01,0x15
  };
const  unsigned char uc_arTst_atrf_cmd[AMOUNT_BYTE_FOR_ATRFG] = {
  0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8, 0x9,0xa,0xb,0xc,0xd,0xe,0xf,0x10,
  0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18, 0x19,0x1a,0x1b,0x1c,0x1d,0x1e//,0x1f,0x20,
  //0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28, 0x29,0x2a,0x2b,0x2c//,0x2d,0x2e,0x2f,0x30
  
  };
  
  
  
  
  
  
void ServiceBsTrUrgObjStates(void)
{
	//register long i;
	register void *pv;
	if ( (chBsFCoilState&( BS_USED_MSK )) )//
	{
		if (  chBsFCoilState&( BS_WR_END_MSK )  )
		{
			chBsFCoilState &= ~( BS_WR_END_MSK );
		
		}
		//Control Process Activation
		if(AppReqTransmitFCoil == 0	)
		{
		
		
			if (  chBsFCoilState&( BS_WR_END_MSK )  )
			{
				chBsFCoilState &= ~( BS_USED_MSK );
			
			}
			//Ending Queue
		}
	
		
	}
	else//Analise Activation
	{
		if (shbsUrgObjIciCallState&(1<<RQ_WR_FCOIL_BIT))
		{
			if((shbsUrgObjIciUsedState&(1<<RQ_WR_FCOIL_BIT)) == 0)
			{
				shbsUrgObjIciUsedState |= (1<<RQ_WR_FCOIL_BIT);
				//shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
				//shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT);
				if ((chBsFCoilState&(BS_WR_MSK | BS_USED_MSK )) == 0)//Already work On Obj
				{
					
					chBsFCoilState &= ~(BS_WR_END_MSK);
					chBsFCoilState |= BS_WR_MSK;
					pv = (void*)&holderFCoil.UNFCoil.sBrFCoilInfoWrp;//;
					*((BrSetInOutDsc*)pv) = hldBrSetInOut;
					AppReqTransmitFCoil= START;
				
					
				}
				shbsUrgObjIciUsedState &= ~(1<<RQ_WR_FCOIL_BIT);
				
				shbsUrgObjIciCallState &= ~(1<<RQ_WR_FCOIL_BIT);
					//shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
				goto ExitServiceBsTrUrgObjStates;
				
			}
			
			
			
		}
		
		
		
	
	}
	if ( (chBsDateTimeState&( BS_USED_MSK )) )//
	{
		if (  chBsDateTimeState&( BS_WR_END_MSK )  )
		{
			chBsDateTimeState &= ~( BS_WR_END_MSK );
		
		}
		//Control Process Activation
		if(AppReqTransmitDateTime == 0	)
		{
		
		
			if (  chBsDateTimeState&( BS_WR_END_MSK )  )
			{
				chBsDateTimeState &= ~( BS_USED_MSK );
			
			}
			//Ending Queue
		}
		
		
	
		
	}
	else//Analise Activation
	{
		if (shbsUrgObjIciCallState&(1<<RQ_WR_DATE_TIME_BIT))
		{
			if((shbsUrgObjIciUsedState&(1<<RQ_WR_DATE_TIME_BIT)) == 0)
			{
				shbsUrgObjIciUsedState |= (1<<RQ_WR_DATE_TIME_BIT);
				//shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
				//shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT);
				if ((chBsDateTimeState&(BS_WR_MSK | BS_USED_MSK )) == 0)//Already work On Obj
				{
					
					chBsDateTimeState &= ~(BS_WR_END_MSK);
					chBsDateTimeState |= BS_WR_MSK;
					pv = (void*)&holderDateTime.UNDateTime.sBsDatetimeInfoWrp;//;
					*((BrDateTime*)pv) = hldrDtTm;
					AppReqTransmitDateTime= START;
				
					
				}
				shbsUrgObjIciUsedState &= ~(1<<RQ_WR_DATE_TIME_BIT);//This var neded if yuo use read & write Operation
				
				shbsUrgObjIciCallState &= ~(1<<RQ_WR_DATE_TIME_BIT);
					//shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
				goto ExitServiceBsTrUrgObjStates;
				
			}
			
			
			
		}
		
		
		
	
	}
	if ( chBsCmdState&( BS_WR_MSK ) )//()and this Block Use for writing 
	{
		
		 //;shbsUrgObjIciUsedState&(1<<RQ_WR_CMD_BIT) <- use this var for select reading and writing states
		if (  chBsCmdState&( BS_WR_END_MSK )  )
		{
			chBsCmdState &= ~( BS_WR_END_MSK );
		
		}
		//Control Process Activation
		if(AppReqTransmitAtrCmd == 0	)
		{
			shbsUrgObjIciUsedState &= ~(1<<RQ_WR_CMD_BIT);//this for enabling Line for reading
		
			if (  chBsCmdState&( BS_WR_MSK )  )
			{
				if( (chBsCmdState&(BS_USED_MSK)) == 0 )
				chBsCmdState &= ~(BS_WR_MSK );// |
				chBsCmdState |=BS_WR_END_MSK;
			}
			//Ending Queue
		}
		
		
	
		
	}
	else//Analise Activation
		{
			if (shbsUrgObjIciCallState&(1<<RQ_WR_CMD_BIT))
			{
				if((shbsUrgObjIciUsedState&(1<<RQ_WR_CMD_BIT)) == 0)
				{
					shbsUrgObjIciUsedState |= (1<<RQ_WR_CMD_BIT);
					//shbsRefreshCfgTablesState |= (1<<BS_RF_CFG_VAR_USED_BIT);
					//shbsRefreshCfgTablesState |=(1<<RQ_WR_STNG_TBL_BIT)|(1<<RQ_WR_PRT_TBL_BIT);
					if ((chBsCmdState&(BS_WR_MSK | BS_USED_MSK )) == 0)//Already work On Obj
					{
						
						chBsCmdState &= ~(BS_WR_END_MSK);
						chBsCmdState |= BS_WR_MSK  ;
						pv = (void*)&holderAtrCmd.UNAtrCmd.sBrAtrCmdInfoWrp;//;
						
						//*((unsigned char*)pv) = uc_arTst_atrf_cmd;
						memcpy(pv,uc_arTst_atrf_cmd,AMOUNT_BYTE_FOR_ATRFG);
						AppReqTransmitAtrCmd= START;
						shbsUrgObjIciUsedState &= ~(1<<RQ_WR_CMD_BIT);
					
						shbsUrgObjIciCallState &= ~(1<<RQ_WR_CMD_BIT);
					
						
					}
					
						//shbsRefreshCfgTablesState &=~(1<<BS_RF_CFG_VAR_USED_BIT);
					goto ExitServiceBsTrUrgObjStates;
					
				}
				
				
				
			}
			
			
			
		
		}
	
	
	
	
	
	
	
	
	
	
ExitServiceBsTrUrgObjStates:	
return;
}

/*


*/


/* EOF */

