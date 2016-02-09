
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
* File Name       : dgn_vr.h
* Description     : support for the ver_info.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  30/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef DIAGN_VER_INFO_h
#define DIAGN_VER_INFO_h


#define TO_IDX_U32(val)     ((val             )>>5)//   
#define TO_IDX_U8(val)      ((val             )>>3)// 
#define TO_U32_MSK(val)     (1<<(( val  )-(32*(val  >>5)))  )//    
#define TO_U8_MSK(val)      (1<<(( val  )-(8*(val   >>3)))  )//


//DIAGN_VER_INFO_EVT_h
#ifndef DIAGNOSTICS_h
#define DIAGN_VER_INFO_EVT_h
typedef struct RamErrRec_TAG 
{
	unsigned long ulCheck_0_FEBF;//0  Fix Error Bit Field
	unsigned long ulCheck_1_FEBF;//01 
	//unsigned long ul__2_FEBF;//02 
	//unsigned long ulRes___3_FEBF;//03 
	union 
	    {
	    	unsigned char uchStateSDFE;//1<<0 -BIT-Fault Error 1<<1-Diagnostic Error
			unsigned char   uchAr [4];
	    	unsigned short  ushAr [2];
            unsigned long   ulVal;//Bound Word
	    }UNNStateSDFE;
	//

	
}TotErrEvtDsc;



#endif 

                                      
#define __TYPE_DEFINITION_DIAGN_BS_TO_BR__ 1
									  
#ifndef __TYPE_DEFINITION_DIAGN_BS_TO_BR__
#define SIZE_DIAGN 8
#else


#define SIZE_DIAGN ( sizeof(RamErrEvtDsc ))

#endif 

typedef struct tag_DiagnHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_DIAGN_BS_TO_BR__	    	
			char   chArSDFE [SIZE_DIAGN];
	    	long   lArSDFE  [SIZE_DIAGN>>2];
#else
			char   chArSDFE [SIZE_DIAGN];
	    	long   lArSDFE  [SIZE_DIAGN>>2];
#endif 			
#ifdef __TYPE_DEFINITION_DIAGN_BS_TO_BR__
			//Obj xxx_FCoil;
//			RamErrEvtDsc mRamErrEvt;
			UNN_PrgEvtBmBrBs muPrgEvtBmBrBs;
#else			
			;
			
#endif
            
	}UNN_Sdfe;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}DiadnHldDsc;
#ifdef __TYPE_DEFINITION_DIAGN_BS_TO_BR__
#ifndef SIZE_DIAGN
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )
// .RamErrEvtDsc

#define SIZE_DIAGN  (sizeof( holderDiagnBmBs.UNN_Sdfe.mRamErrEvt))
#endif
#endif

//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_DiagnWrpDsc//Wrapper 
{

long size_Diagn;      //
void *p_Diagn;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}DiagnWrpDsc;

extern int AppReqTransmitDiagnBsBr;
//extern int AppReqTransmitDiagnBBr;
extern int AppReqReceiveDiagnBmBs ;
extern int AppReqReceiveDiagnBrBs ;

extern DiadnHldDsc holderDiagnBmBs;
extern DiadnHldDsc holderDiagnBmBr;
extern DiadnHldDsc holderDiagnBrBs;
extern DiadnHldDsc holderDiagnBsBr;

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
//.extern void ActivateServTrApCnDateTimeCTpuUnitSpi(void);
//.extern  void TerminateServiceApCnDateTime(void);
#ifndef VER_INFO_h
#define VER_INFO_h
typedef struct tag_NumVerInfo{
char ver;//Main Number
char sub_ver;//Describe functionality change  z TU abo bez TU
char corr_num;//Nomer correkcii Vupravlennya pomulok
long Bield_num;//Compile Counter
}NumVerInfo ;


typedef struct TotVerInfoDsc_TagIn
{

    char ArDateStr [16];      //
    char ArTimeStr [16];      //
	char chSizeDateStr;       //
    char chSizeTimeStr;       //
	short sh;
	long long llIarVersion;  //
    NumVerInfo mVerInfo;


}TotVerInfo;
#endif 



#define __TYPE_DEFINITION_VER_INFO_BM_TO_BS__ 1
									  
#ifndef __TYPE_DEFINITION_VER_INFO_BM_TO_BS__
#define SIZE_VER_INFO 40
#else
#define SIZE_VER_INFO ( sizeof(TotVerInfo ))
#endif 

typedef struct tag_TotVerInfoHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_VER_INFO_BM_TO_BS__	    	
			char   chArVerI [SIZE_VER_INFO];
	    	long   lArVerI [SIZE_VER_INFO>>2];
#else
			char   chArVerI [SIZE_VER_INFO];
	    	long   lArVerI [SIZE_VER_INFO>>2];
#endif 			
#ifdef __TYPE_DEFINITION_VER_INFO_BM_TO_BS__
			//Obj xxx_FCoil;
			TotVerInfo mTotVerInfo;
#else			
			;
			
#endif
            
	}UNN_TotVerInfo;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}TotVerInfoHldDsc;
#ifdef __TYPE_DEFINITION_VER_INFO_BM_TO_BS__
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )
//.mTotVerInfo 

#define SIZE_TOT_VER_INFO  (sizeof(  holderTotVerInfo.UNN_TotVerInfo.mTotVerInfo))
#endif

//

typedef struct tag_VerInfoWrpDsc//Wrapper 
{

long size_VerInfo;      //
void *p_VerInfo;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}VerInfoWrpDsc;

//extern int AppReqTransmitTotVerInfoBmBs;
extern int AppReqReceiveTotVerInfoBmBs; 
extern int AppReqReceiveTotVerInfoBrBs; 

extern TotVerInfoHldDsc holderTotVerInfoBm;
extern TotVerInfoHldDsc holderTotVerInfoBr;
extern TotVerInfoHldDsc holderTotVerInfoBs;




#endif //DIAGN_VER_INFO_TIME_h



