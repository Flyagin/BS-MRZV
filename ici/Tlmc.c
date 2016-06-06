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
* Processor       : Lpc_3240
* File Name       : Tlmc.c
* Description     : Functions and Data for Extract from Transport to Applicayion
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include <string.h>
#include <intrinsics.h>
#include    "Tlmc.h"
// this  Obj for Primary hold data
TeleMechsHldDsc holderTeleMechs = {

{0,0,0,0}
};
// This Obj Use for Transmittion
TeleMechsHldDsc holderTeleMechsIciCopy = {

{0,0,0,0}
};

TeleMechsWrpDsc  hldTeleMechsWrp = {

#ifdef __TYPE_DEFINITION_TELE_BR_TO_BS__
SIZE_TELE_INFO ,	(void*)	&holderTeleMechs.UNTeleMechs.lArTeleMechs[0],		
#endif
#ifndef __TYPE_DEFINITION_TELE_BR_TO_BS__
0,	(void*)	0,
#endif
{0,0,0,0}

};

TeleMechsMgrDsc hldTeleMechsMgr = {
0,//RegisterdUsr
0,0,0,0
};

int AppReqTransmitTeleMechs;
int AppReqReceiveTeleMechs ; //int AppReqReceiveTotMeasG;


long UpdateRVTotTeleMechsTpuUnit(void* pvLDC, long lID)   @ "Fast_function"
{
register long i;//,j;
//register char *pSrc;//,*pDst;
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
//RVSrcSamplesCTpuUnitDsc  holderRVSrcSamplesCTpuUnit
 sLV.chNeedClrSesData = 0;
unnV1.uchAr[0] = ((LDCIDsc*)pvLDC)-> uchConMode;
unnV1.uchAr[1] = ((LDCIDsc*)pvLDC)-> uchStartSesion;
unnV1.uchAr[2] = ((LDCIDsc*)pvLDC)-> NumComSes;
unnV1.uchAr[3] = 0;
pv  = (void*)&holderRVTeleMechsSOCTpuUnit.RvCnHldr;
if (unnV1.uchAr[0]== 0)
{
	hldTeleMechsMgr.chIsExec++;
	if(hldTeleMechsMgr.shCurCopyUser)
	hldTeleMechsMgr.shCopyWasCorrupted |= hldTeleMechsMgr.shCurCopyUser;
	//pv  = (void*)&holderRVTotMeasCTpuUnit.arUchRV;
	pv  = (void*)	&holderTeleMechs.UNTeleMechs.lArTeleMechs[0];
	
	i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
	lID = ((LDCIDsc*)pvLDC)->uchTR_C;
	pvLDC = (void*)i;
	
	//MoveData: 
	for (i = 0; i < lID; i++)
	{
	  ((char*)pv)[i] = ((char*)pvLDC)[i];
	}
	 pvLDC = &hldTeleMechsWrp;
//Inform about Succes statistics
	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
	i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
	((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
	AppReqReceiveTeleMechs++;
	hldTeleMechsMgr.chDataWasCorrupted = 0;
	hldTeleMechsMgr.chIsExec--;
}
else
{
	//-Analize Sesion state Etc.
	pv  = (void*)&holderRVTeleMechsSOCTpuUnit.RvCnHldr;
	if ( ((LDCIDsc*)pvLDC)-> uchStartSesion == 1)
	{
		((RVBaseCTpuUnitDsc*)pv)->NumComSes = (unnV1.uchAr[2])>>4;//<<= 4
		//Select Active Buf
		((RVBaseCTpuUnitDsc*)pv)->pUchRV = //holderRVTotMeasGSOCTpuUnit
		(unsigned char*)&holderRVTeleMechsSOCTpuUnit.arUchRV; 
		((RVBaseCTpuUnitDsc*)pv)->ulRvCount = 0;
	}
	return lID;
	i = (((LDCIDsc*)pvLDC)->NumComSes)>>4;
		if (i== (((RVBaseCTpuUnitDsc*)pv)->NumComSes) )
		{
			i = (((LDCIDsc*)pvLDC)->uchTR_C)+ (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);
			if( i<= (long)(SIZE_TELE_INFO))
			lID = ((LDCIDsc*)pvLDC)->uchTR_C;
			else
			lID = (SIZE_TELE_INFO) - (((RVBaseCTpuUnitDsc*)pv)->ulRvCount);//For Exlude buf overrun
			unnV1.uchAr[3] = ((LDCIDsc*)pvLDC)->uchTR_C;//Save Cur size rv data
			i = (long)(((LDCIDsc*)pvLDC)-> pSrc);
			
			pvLDC = (void*)i;
			i = (long)holderRVTeleMechsSOCTpuUnit.RvCnHldr.pUchRV;
			i += ((RVBaseCTpuUnitDsc*)pv)->ulRvCount;
			pv  = (void*)i;
			for (i = 0; i < lID; i++)
			{
			((char*)pv)[i] = ((char*)pvLDC)[i];
			}
			//Update Rv
			pv  = (void*)&holderRVTeleMechsSOCTpuUnit.RvCnHldr;
			lID = ((RVBaseCTpuUnitDsc*)pv)->ulRvCount+unnV1.uchAr[3];
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount = lID;
			if (lID >= (long)(SIZE_TELE_INFO))
			{
				 pvLDC = &hldTeleMechsWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
				 i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
				((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
				//Sucess Terminate Session
				if (lID == (long)(SIZE_TELE_INFO))
				{
					//Activate App Func
					AppReqReceiveTeleMechs++;
					i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange;i++;
					((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalGoodChange = i;
					
					//hldTeleMechsWrp.size_total_measurement = 0;//AppReqReceiveTotMeasG = 0;
					// hldTeleMechsWrp.p_total_measurement =
					//  (void*)&(holderTeleMechs.UNTotMeas.total_measurement);
					  
				}
				else{
						 //pvLDC = ((RVBaseCTpuUnitDsc*)pv)->pUchRV;
						i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors;i++;
						((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors = i;
						i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
						((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
						
				}
				 sLV.chNeedClrSesData++;
			}
			
		}
		else
		{
			;//Error Sesion
			
			 pvLDC = &hldTeleMechsWrp;//((RVBaseCTpuUnitDsc*)pv)->pUchRV;
			i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors;i++;
			((TeleMechsWrpDsc*)pvLDC)-> statistics.lErrors = i;
			i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange;i++;
			((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalBadChange = i;
			i = ((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange;i++;
			((TeleMechsWrpDsc*)pvLDC)-> statistics.lTotalChange = i;
			 sLV.chNeedClrSesData++;
			
			
			
		}
		if(sLV.chNeedClrSesData)
		{
			pv  = (void*)&holderRVTeleMechsSOCTpuUnit.RvCnHldr;
			((RVBaseCTpuUnitDsc*)pv)->uchUsedTransport = 0;
			((RVBaseCTpuUnitDsc*)pv)->NumComSes        = 0;
			((RVBaseCTpuUnitDsc*)pv)->ConState         = 0;
			((RVBaseCTpuUnitDsc*)pv)->ulRvCount        = 0;
			
		}
}

return lID;//unnV1.uchAr[3];
}


void TeleMechsRvServCTpuApCnUnit(void)   @ "Fast_function"
{
long i;
hldTeleMechsWrp.size_TeleMechs = 0;
AppReqReceiveTeleMechs = 0;
//~  hldTeleMechsWrp.p_TeleMechs =
//~  (void*)&holderTeleMechs.UNTeleMechs.chArTeleMechs[0];
//~ //Req Copy Operation
//~ holderTeleMechsIciCopy.UNTeleMechs.sBrTeleMechsTeleInfoWrp
//~ = holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp;
//~ hldTeleMechsWrp.p_TeleMechs = (void*)	&holderTeleMechs.UNTeleMechs.chArTeleMechs[0];
//~ hldTeleMechsWrp.size_TeleMechs =  sizeof(  SIZE_TELE_INFO );

i = holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLed[0];
i|= holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp.chArLed[1]<<8;
AT91C_BASE_PIOD->PIO_SODR = i&0x3fff;
AT91C_BASE_PIOD->PIO_CODR = (~i)&0x3fff;

}

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long  GetTeleMechsData(long lUsrKey, void *pBuf) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long GetTeleMechsData(long lUsrKey, void *pBuf) @ "Fast_function"
{
register long i;

TeleMechsMgrDsc  *pTeleMechsMgr = &hldTeleMechsMgr; 

i = ERROR_EXEC; 
//Control Param
if ((lUsrKey<1) || (lUsrKey>16))
return ERROR_EXEC;
lUsrKey--;
i = (pTeleMechsMgr->ushRegisterdUsr)&(1<<lUsrKey);
if (i== 0 )
return ERROR_EXEC;//Not Registered Call
if (pTeleMechsMgr-> chIsExec)
return STATE_EXEC;
if (pTeleMechsMgr-> chDataWasCorrupted)
return  ERROR_EXEC;
(pTeleMechsMgr->shCopyWasCorrupted) &= ~(1<< lUsrKey);
pTeleMechsMgr->shCurCopyUser |= 1<< lUsrKey;

//void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
//The function copies the array of char beginning at the address s2 to 
//the array of char beginning at the address s1 (both of size n).
// It returns s1. The elements of the arrays can be accessed and stored in any order.

memcpy(pBuf,(void*)	&holderTeleMechs.UNTeleMechs.chArTeleMechs[0], SIZE_TELE );
pTeleMechsMgr->shCurCopyUser &= ~(1<< lUsrKey);
i = (pTeleMechsMgr->shCopyWasCorrupted)&(1<<lUsrKey);
if(i)
{
	(pTeleMechsMgr->shCopyWasCorrupted) &= ~(1<< lUsrKey);
	return ERROR_EXEC ;
}
i = SUCCESS_EXEC;


//ExitGetTeleMechsData:
	return i;
}
//---------------------------------------------------------------------------------

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long GetUserKeyTeleMechsData(void) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long GetUserKeyTeleMechsData(void)  @ "Fast_function"
{
register long i,j;
//register void *pv;

TeleMechsMgrDsc  *pTeleMechsMgr = &hldTeleMechsMgr; 
i = 0;
__istate_t s = __get_interrupt_state();
__disable_interrupt();
j = (pTeleMechsMgr->ushRegisterdUsr);//&(1<<lUsrKey))
 //Disable Irq
	while( i<16 )
	{
		if ( (j&(1<<i))==0 )
		{
			pTeleMechsMgr->ushRegisterdUsr |= (1<< i);
			 ++i;//break;
			goto  ExitGetUserKeyTeleMechsData;
		}	
		i++; 
	}
	i = 0;//return 0;

ExitGetUserKeyTeleMechsData:
//Enable Irq
 __set_interrupt_state(s);
	return i;
}
//---------------------------------------------------------------------------------
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//---   
long ReturnUserKeyTeleMechsData(long lKey) @ "Fast_function";
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~ Purpose:                          ~~~
//~~~ Processing:                       ~~~
//~~~        ~~~
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~                                                                             ~~
//~~~                                                                             ~~ 
//~~~                                                                             ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//=================================================================================
//Body func                                                                  
//=================================================================================
long ReturnUserKeyTeleMechsData(long lKey)  @ "Fast_function"
{
//register long i;
//register void *pv;
__istate_t s;
TeleMechsMgrDsc  *pTeleMechsMgr = &hldTeleMechsMgr; 

	if ((lKey<1) || (lKey>16))
	{
		
		goto ExitReturnUserKeyTeleMechsData;//Error
	}
 s = __get_interrupt_state();
 __disable_interrupt();
 //Disable Irq	
lKey--;//i = lKey-1;
pTeleMechsMgr->ushRegisterdUsr &= ~(1<< lKey);
//Enable Irq
	lKey++;//i = lKey;//return lKey;
	 __set_interrupt_state(s);
ExitReturnUserKeyTeleMechsData:

return lKey; 
}
//---------------------------------------------------------------------------------
//.#ifdef ici_e_fn_h
//.#undef ici_e_fn_h
//.#include    "../inc/ici_ef.h"
static long lUserKeyforTest = 0;
TeleMechsInfoDsc Test10msTeleMechsInfo;
void TestCopyTeleMechsData(void)
{
register long i;
register long lRes;
TeleMechsInfoDsc locTeleMechsInfo;

		
	i = GetUserKeyTeleMechsData();
	if(i)
	lUserKeyforTest = i;
	else return;//Error State
	
	lRes =  GetTeleMechsData(lUserKeyforTest,(void*)&locTeleMechsInfo);
	
	if(lRes == STATE_EXEC)
	goto ExitTestCopyTeleMechsData;
	if(lRes == ERROR_EXEC)
	{
		lRes =  GetTeleMechsData(lUserKeyforTest,(void*)&locTeleMechsInfo);
	
	}
	if(lRes == SUCCESS_EXEC)
	Test10msTeleMechsInfo = locTeleMechsInfo;
	

ExitTestCopyTeleMechsData:
	i = ReturnUserKeyTeleMechsData(lUserKeyforTest);

}
















/* EOF */

