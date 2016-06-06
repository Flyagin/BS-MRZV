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
* File Name       : MnPrYust.h
* Description     :  support for the MnPrYust.c
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#ifndef MNR_PR_YUST_h
#define MNR_PR_YUST_h

#define SIZE_TPDU_TRANSPORT_YUST_CNL_HSU2_MDR1 40





extern int  ReqTransmitYustPrMng;
extern int  ReqReceiveYustPrMng;
extern unsigned long ulCtrDecompouseYustTptUnitHSU2;

extern ProxyTransportStateDsc hldPrTrptYust;
extern ProxyMangerStateDsc  hldPrMngYust;
extern int  ReqTransmitYustPrTpt;
extern int  ReqReceiveYustPrTpt;

extern long WorkProxyManager (void* pv, long lV);
extern long ExecTargetProxyManager (void* pv, long lV);

long ExecCmdYustPrTpt (void* pv, long lV);
long ResetYustPrTpt (void* pv, long lV);
long ActivateYustTrPrTpt(void* pObjParam, long lV);
long ActivateYustRvPrTpt(void* pObjParam, long lV);



extern long ActivateYustPrMng(void);

//extern long ActivateTRStngPrTpt(void* pObjParam, long lID);

//extern long ActivateTransmitStngObj(void);
extern long ActivateYustTransmitObj(void);
//extern long ActivateReceiveStngObj(void);
extern long ActivateYustReceiveObj(void);

extern YustStateDsc testYustState;


long TryYustSetSendEct   (void* pv, long lV);
long DpcsYustPrMngMsg   (void* pv, long lV);
long ExecYustCmdPrMng   (void* pv, long lV);
long SetYustSendEct ( void* pv, long lV);
long WaitYustCmdHmEct   (void* pv, long lV);

long SetYustSendReqTrEct(void* pv, long lV);
long CreateTRFragment(void* pvTRFrgDsc);


long ActivateYustPrMng       (void);
long PassYustPrMngRvMsgOrigin(void);






#include    "CmmConst.h"
#endif
