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
* File Name       : ici_api.h
* Description     : Functions and Data for API,
                    interprocessor communication

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  31/08/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef	ICI_API_H
#define	ICI_API_H

//#include "./lpc_types.h"


#if defined (__cplusplus)
extern "C"
{
#endif

 extern void u2_hdw_init(void);
extern long lSpi0HdwState;
extern long Spi0_Syncro1(void);
extern void Spi0_Syncro2(void);
extern long outSpi0(unsigned char *dat, long bytes); 
extern long  inSpi0(unsigned char *buff,long bytes); 

extern unsigned char chEntry_Hs7;
extern long lEndU2Tr;
extern long lSetCtr;
extern long lClrCtr;


extern void ProcessReceiveLpduHSU7(void);
extern void ProcessReceiveLpduU2_T(void);


extern unsigned long samples_data_rdy;

extern unsigned char meas_data_rdy;
extern unsigned char chGoosB_Data_Rdy;
extern  char chLogicSpi0HdwError;

extern long Samples_Ready_Handler(void* pv);
extern long Meas_Ready_Handler   (void* pv);
extern long GoosB_Rdy_Handler   (void* pv);


extern void ici_hdw_init(void);

extern void ProcessTransmitEvt(void);
extern void ProcessReceiveEvt(void);

extern void Scan_Ici_Event_Req(void);
extern void Scan_Ici_Entry_Data(void);

extern void PrepDecompouseSrcSamplesUnit(void);
extern void TestSetup_SrcSamples_ForTransmit(void);
extern void Rst_LpduHSU2_TpCnState(void);


extern void TestSetup_LpduHSU7_ForTransmit(void);
extern void ProcessTransmitLpduHSU7(void);

extern void ExecProxyOld(void);
extern void ExecProxyTps(void);
extern void ExecProxyTotMeas(void);
extern void ExecExistProxy(void* pvProxy);
extern void UpdateAppData(void);
extern void StubForSpiChanel(void);
extern void StubForSpiChanel1(void);

extern void TestActivateTransport(void);

extern void DbgModifyPrMng(void* pv, long lV);
extern long Test_Init(void);
extern void Test_Loop(void);
extern void ReInitSpi0Param(void);

extern void SPI0_DMA_Enable(void);

extern void StartUPInitTotVerInfo(void);
#endif
