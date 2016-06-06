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
* File Name       : MnPrPrt.h
* Description     :  support for the MnPrPrt.c
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#ifndef MNR_PR_PRTTBL_h
#define MNR_PR_PRTTBL_h

#include    "hv_df.h"
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef HV_DF_h
#define SIZE_PRT 0X1035
#endif 
#ifdef HV_DF_h
#define SIZE_PRT (  ((sizeof(CfgTblDsc )>>2)<<2) + (4*(1&&(sizeof(CfgTblDsc ))&3))    )
//( ((sizeof(__YUST )>>2)<<2) + 4*(1&&(sizeof(__YUST ))&3) )
#endif
typedef struct tag_PrtTblHldDsc
{
	union 
	{
#ifdef 	HV_DF_h	
			char   chArPrt  [ sizeof(CfgTblDsc )];
#else					
	    	char   chArPrt  [ SIZE_PRT];
#endif			
	    	long    lArPrt  [ (SIZE_PRT>>2)+1];//One additional Word

#ifdef 	HV_DF_h
			CfgTblDsc CfgPrtTbl;
#else			
			unsigned int PrtTbl[SIZE_PRT>>2];
#endif
            
	}UNPrtTbl;
	long lCheckSum;
}PrtTblHldDsc;
extern PrtTblHldDsc holderPrtTbl;
extern long lSizeOf_PrtTbl;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""






extern int  ReqTransmitPrtTblPrMng;
extern int  ReqReceivePrtTblPrMng;


extern ProxyTransportStateDsc hldPrTrptPrtTbl;
extern ProxyMangerStateDsc  hldPrMngPrtTbl;
extern int  ReqTransmitPrtTblPrTpt;
extern int  ReqReceivePrtTblPrTpt;

extern long WorkProxyManager (void* pv, long lV);
extern long ExecTargetProxyManager (void* pv, long lV);

long ExecCmdPrtTblPrTpt (void* pv, long lV);
long ResetPrtTblPrTpt (void* pv, long lV);
long ActivatePrtTblTrPrTpt(void* pObjParam, long lV);
long ActivatePrtTblRvPrTpt(void* pObjParam, long lV);



extern long ActivatePrtTblPrMng(void);

//extern long ActivateTRStngPrTpt(void* pObjParam, long lID);

//extern long ActivateTransmitStngObj(void);
extern long ActivatePrtTblTransmitObj(void);
//extern long ActivateReceiveStngObj(void);
extern long ActivatePrtTblReceiveObj(void);

extern PrtTblStateDsc testPrtTblState;


long TryPrtTblSetSendEct   (void* pv, long lV);
long DpcsPrtTblPrMngMsg   (void* pv, long lV);
long ExecPrtTblCmdPrMng   (void* pv, long lV);
long SetPrtTblSendEct ( void* pv, long lV);
long WaitPrtTblCmdHmEct   (void* pv, long lV);

long SetPrtTblSendReqTrEct(void* pv, long lV);



long ActivatePrtTblPrMng       (void);
long PassPrtTblPrMngRvMsgOrigin(void);

long SendPrtTblTbl(void);
long GetPrtTblTbl(void);
void SetPrtTestVal(void* pTbl);


#include    "CmmConst.h"
#endif
