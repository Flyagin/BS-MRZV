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
* File Name       : lpu.h
* Description     : support for the lpu.c
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  02/09/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef Lpu_h
#define Lpu_h
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//       Definitions for Sizes
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~       ~~
//~~~       ~~
//~~~       ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define SIZE_LPDU_CNL_1 200

#define SIZE_LPDU_CNL_DOUBLE_ACCESS_MEMORY  512

#define SIZE_LPDU_CNL_HSU7 100

#define SIZE_LPDU_CNL_U3   60

#define SIZE_LPDU_CNL_HSU1 100
#define SIZE_LPDU_CNL_HSU2 100

#define SIZE_LPDU_CNL_SPI  512

#define SIZE_LPDU_CNL_HSU2 100//USART

#define SIZE_LPDU_CNL_U2     100//USART
#define SIZE_LPDU_CNL_U0     100//USART
#define SIZE_LPDU_CNL_DBGU   100//USART
#define SIZE_LPDU_CNL_HSU0   100
//SIZE_LPDU_CNL_U0
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//``````````````````````````````````````````````````````````````````````````````````
#define SIZE_LPCI_FLD_CNL_1    1
#define SIZE_LDC_FLD_CNL_1     1
#define SIZE_CS_FLD_CNL_1      1

#define SIZE_LPCI_FLD_CNL_HSU7    1
#define SIZE_LDC_FLD_CNL_HSU7     1
#define SIZE_CS_FLD_CNL_HSU7      1

#define SIZE_LPCI_FLD_CNL_HSU2    1
#define SIZE_LDC_FLD_CNL_HSU2     1
#define SIZE_CS_FLD_CNL_HSU2      1

#define SIZE_LPCI_FLD_CNL_U2      1
#define SIZE_LDC_FLD_CNL_U2       1
#define SIZE_CS_FLD_CNL_U2        1

#define SIZE_LPCI_FLD_CNL_U0    1
#define SIZE_LDC_FLD_CNL_U0     1
#define SIZE_CS_FLD_CNL_U0      1

#define SIZE_LPCI_FLD_CNL_DBGU    1
#define SIZE_LDC_FLD_CNL_DBGU     1
#define SIZE_CS_FLD_CNL_DBGU      1

#define SIZE_LPCI_FLD_CNL_SPI    1
#define SIZE_LDC_FLD_CNL_SPI     2
#define SIZE_CS_FLD_CNL_SPI      1	
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


#define HDR_MODE_CNL_SPI    ((1<<7) |(1<<2))

#define HDR_MODE_CNL_1      ((1<<7)|(1<<1))
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define ID_CNL_TEST1 0x1
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct StateTpLpuDsc_tag
{
	unsigned char  uchTpState_CNL_1;
	short PayloadLPDU_CNL_1;//Total Payload LPDU_CNL_1 for current Link Frame
	//If on app take command change param phis Frame then change PayloadLPDU_CNL_1
	long lCapicity_CNL_1;//Current Capicity Payload for Transport
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_1;
	
	//--unsigned char  uchhTpState_CNL_2;
	//--long lCapicity_CNL_2;
	//--//unsigned char      *pUchRV;//0   Data  field
	//--unsigned char      *pUchLpuTR_CNL_2;
	unsigned char  uchTpState_CNL_HSU7;
	short PayloadLPDU_HSU7;
	long lCapicity_CNL_HSU7;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_HSU7;
	
	
	unsigned char  uchhTpState_CNL_3;
	long lCapicity_CNL_3;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_3;
	
	unsigned char  uchhTpState_CNL_4;
	long lCapicity_CNL_4;
	//unsigned char      *pUchRV;//0   Data  field
	unsigned char      *pUchLpuTR_CNL_4;
	
}StateTpLpuDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//#define 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_TRStateLpuCn1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_1];//0   Data  field

	
	unsigned char  uchLpuCn1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuCn1Dsc;
typedef struct tag_TRStateLpuHSU7Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
	unsigned char  uchLpuHSU7State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuHSU7Dsc;
typedef struct tag_TRStateLpuHSU2Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU2];//0   Data  field

	
	unsigned char  uchLpuHSU2State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuHSU2Dsc;
typedef struct tag_TRStateLpuHSU1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU1];//0   Data  field

	
	unsigned char  uchLpuHSU1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuHSU1Dsc;
//``````````````````````````````````````````````````````````````````````````````````
typedef struct tag_TRStateLpuU0Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_U0];//0   Data  field

	
	unsigned char  uchLpuU0State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuU0Dsc;

typedef struct tag_TRStateLpuU2Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_U2];//0   Data  field

	
	unsigned char  uchLpuU2State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuU2Dsc;

typedef struct tag_TRStateLpuDbguDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_DBGU];//0   Data  field

	
	unsigned char  uchLpuDbguState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuDbguDsc;


typedef struct tag_TRStateLpuSpiDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_SPI+4];//0   Data  field

	
	unsigned char  uchLpuSpiState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}TRStateLpuSpiDsc;

//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//       Definitions for Sizes
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~        ~~~
//~~~        ~~~
//``````````````````````````````````````````````````````````````````````````````````
//~~~       ~~
//~~~       ~~
//~~~       ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
typedef struct tag_RVStateLpuCnlDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      *pUch;//0   Data  field

	
	unsigned char  uchLpuCn1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;

	
}RVStateLpuCnlDsc;
typedef struct tag_RVStateLpuCn1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_1];//0   Data  field

	
	unsigned char  uchLpuCn1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;

	
}RVStateLpuCn1Dsc;

typedef struct tag_RVStateLpuU3Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_U3];//0   Data  field

	
	unsigned char  uchLpuU3State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuU3Dsc;

typedef struct tag_RVStateLpuHSU7Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU7];//0   Data  field

	
	unsigned char  uchLpuHSU7State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuHSU7Dsc;

typedef struct tag_RVStateLpuHSU1Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU1];//0   Data  field

	
	unsigned char  uchLpuHSU1State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuHSU1Dsc;
typedef struct tag_RVStateLpuHSU2Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_HSU2];//0   Data  field

	
	unsigned char  uchLpuHSU2State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuHSU2Dsc;
//``````````````````````````````````````````````````````````````````````````````````
typedef struct tag_RVStateLpuU2Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_U2];//0   Data  field

	
	unsigned char  uchLpuU2State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuU2Dsc;

typedef struct tag_RVStateLpuU0Dsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_U0];//0   Data  field

	
	unsigned char  uchLpuU0State;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuU0Dsc;

typedef struct tag_RVStateLpuDbguDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_DBGU];//0   Data  field

	
	unsigned char  uchLpuDbguState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuDbguDsc;

typedef struct tag_RVStateLpuSpiDsc
{
	long lCapicity;//For offset Mem Only
	unsigned char      arUch[SIZE_LPDU_CNL_SPI+4];//0   Data  field

	
	unsigned char  uchLpuSpiState;
	unsigned char  uchCI;
	
	unsigned short ushSizeLDC;
	long lCs;
	
	
}RVStateLpuSpiDsc;
	



//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define SIZE_LPDU_CNL_2 248
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_LpuState
{
	unsigned char  uchLpuCn2State;
	unsigned short ushSizeLDC;
	
	long lCap;
	
}StateLpuCn2Dsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern TRStateLpuCn1Dsc holderCn1LpduUnit;
extern RVStateLpuCn1Dsc hldrCn1LpduUnit;

extern TRStateLpuHSU7Dsc hldrHSU7LpduTRUnit;
extern TRStateLpuHSU1Dsc hldrHSU1LpduTRUnit;
extern TRStateLpuHSU2Dsc hldrHSU2LpduTRUnit;

extern TRStateLpuU0Dsc   hldrU0LpduTRUnit;
extern TRStateLpuU2Dsc   hldrU2LpduTRUnit;
extern TRStateLpuDbguDsc hldrDbguLpduTRUnit;
extern TRStateLpuSpiDsc  hldrSpiLpduTRUnit;

extern RVStateLpuU3Dsc   hldrU3LpduUnit;
extern RVStateLpuHSU7Dsc hldrHSU7LpduUnit;
extern RVStateLpuHSU1Dsc hldrHSU1LpduUnit;
extern RVStateLpuHSU2Dsc hldrHSU2LpduUnit;

extern RVStateLpuU0Dsc    hldrU0LpduRvUnit;
extern RVStateLpuU2Dsc    hldrU2LpduRvUnit;
extern RVStateLpuDbguDsc hldrDBGULpduRvUnit;
extern RVStateLpuSpiDsc  hldrSpiLpduUnit;
extern long timerWaitReqSpi;



extern void ProcessReceiveLpdu(void);
extern void ProcessReceiveLpduSpi(void);

extern void ProcessTransmitLpdu(void);

extern void ProcessTransmitLpduHSU7(void);
extern void ProcessTransmitLpduHSU2(void);

extern void Rst_LpduHSU7_TpCnState(void);
extern void Rst_LpduHSU1_TpCnState(void);
extern void Rst_LpduHSU2_TpCnState(void);
extern void Rst_LpduHSU0_TpCnState(void);

extern void ProcessTransmitLpduU2(void);
extern void ProcessTransmitLpduU0(void);
extern void ProcessTransmitLpduDBGU(void);

extern void ProcessTransmitLpduSpi(void);



extern void Rst_LpduU0_TpCnState(void);
extern void Rst_LpduU2_TpCnState(void);
extern void Rst_LpduDBGU_TpCnState(void);
extern void Rst_LpduSpi_TpCnState(void);

extern long outSpi0(unsigned char *dat, long bytes) @ "Fastest_function";
extern long  inSpi0(unsigned char *buff,long bytes) @ "Fastest_function";
extern void Spi0_Rst(void);
extern void DisblGSpiInt(void); 
extern void EnblGSpiInt(void);  

extern unsigned char chGoosB_Data_Rdy;
extern long lCtrSuccRvPack;
extern long lTresholdSuccRvPack;
extern long GoosB_Rdy_Handler   (void* pv);
extern void GossBRvPackActivator(void);
extern void ProcessReceiveQueueU0(void);
extern void ProcessReceiveQueueU0_V0(void);
extern void ProcessTransmitStubSeqUart(void);



extern unsigned long ulCtrTransmitLpduHSU2;

extern long lBlockHSU2Ctr;
extern void HSU2StallHundler(void);

#endif
 /* Lpu_h */

