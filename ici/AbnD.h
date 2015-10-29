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
* File Name       : AbnD.h
* Description     : support for the AbnD.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  31/08/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ABS_NUMERATOR_h
#define ABS_NUMERATOR_h



#ifndef	ERROR
#define ERROR 4
#endif
#ifndef	OK
#define OK    3
#endif

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                          ~~~~~
//~~~                            ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define AMOUNT_BYTE_FOR_NUMERATOR  4
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
                                      
#define __TYPE_DEFINITION_ABS_NUMERATOR_BS_TO_BR__ 1
									  
#ifndef __TYPE_DEFINITION_ABS_NUMERATOR_BS_TO_BR__

#define SIZE_ABS_NUMERATOR_N 12
#else

#define SIZE_ABS_NUMERATOR (sizeof(char)+sizeof(long)+sizeof(long))

#endif 



typedef struct tag_AbsNumeratorUnnDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_ABS_NUMERATOR_BS_TO_BR__	    	
			char   chArNums [SIZE_ABS_NUMERATOR_N];
	    	long    lArNums [SIZE_ABS_NUMERATOR_N>>2];
#else
			char   chArNums [SIZE_ABS_NUMERATOR];
	    	long    lArNums [SIZE_ABS_NUMERATOR>>2];
#endif 		
#ifdef __TYPE_DEFINITION_ABS_NUMERATOR_BS_TO_BR__		
				//Obj xxx_TeleMechs;
			struct
			{
				char  chBitFld;
				char  chArNum1[AMOUNT_BYTE_FOR_NUMERATOR];
				char  chArNum2[AMOUNT_BYTE_FOR_NUMERATOR];
				
				//char  chArWrp[SIZE_WRP_];//
				//char  chDiag[SIZE_DIAGNOSTIC_DATA];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBsAbsNumeratorWrp;
#else			
			struct
			{
	

				//ApcsMiscDataDsc hldApcsMiscData;
			}sBsAbsNumeratorWrp;
			
#endif
            
	
	}UNNAbsNumtrs;
	
}AbsNumeratorUnnDsc;

extern AbsNumeratorUnnDsc holderAbsNumerator;
extern int AppReqTransmitbsNumerator;
extern int AppReqTransmitbsNumeratorRQ;
//extern int AppReqTransmitbsNumeratorRQ2;

#define __TYPE_DEFINITION_AREC_BS_TO_BR__ 1//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#ifndef __TYPE_DEFINITION_AREC_BS_TO_BR__
#define SIZE_AREC_DATA_BS 0X100
#endif 
#ifdef __TYPE_DEFINITION_AREC_BS_TO_BR__
  
#define SIZE_ANALOG_DATA  ( 64 ) //Arr of Char
#define SIZE_COMMAND_DATA ( (((RESERV_MAX_OEPRF_ONB)>>3) +1)  ) //Arr of Char ~26bytes
#define SIZE_WRP_LOG_DATA ( sizeof( long) )
#define SIZE_ABN_NUMERATOR ( sizeof( long) )
#define SIZE_AWC_LOG_DATA ( SIZE_ANALOG_DATA + SIZE_COMMAND_DATA + SIZE_WRP_LOG_DATA +  SIZE_ABN_NUMERATOR)

#define SIZE_AREC_DATA_BS_TO_BR (SIZE_AWC_LOG_DATA )

#endif
//``````````````````````````````````````````````````````````````````````````````````
//~~~    
//~~~    
//~~~    
//~~~    
//..................................................................................


typedef struct ARecDataBs_TagOut
{
	union 
	{
	    	char   chArArecData [SIZE_AREC_DATA_BS_TO_BR];
	    	long    lArArecData [SIZE_AREC_DATA_BS_TO_BR>>2];
#ifdef __TYPE_DEFINITION_AREC_BS_TO_BR__
			//
			struct
			{
				
				char  chArAnlg[SIZE_ANALOG_DATA];
				char  chArCmd[SIZE_COMMAND_DATA];
				char  chArWrp[SIZE_WRP_LOG_DATA];//Current TimeLab
				char  chAbnNum[SIZE_ABN_NUMERATOR];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sArecBrWrp;
#endif
            
	}UN_ArecDataBS;



}ARecDataDsc;
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct AbsNumersIdxBufBs_TagOut
{
	long l1AbsNumertrs,l2AbsNumertrs;
	long lFirstStartIdx,lFirstIdx,lFirstSize;
	long lSecondStartIdx,lSecondIdx,lSecondSize;
	long lDeltaAbsNumertrs,lSelectedAbsNumertr;
	long lCtrRvAbsNumertrs, lState;

}AbsNumersIdxBufBsDsc;

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//extern void ActivateServTrApCn TeleMechs CTpuUnitSpi(void);
//extern  void TerminateServiceApCn TeleMechs(void);
int AppReqReceiveARecDataBs;

extern char chEnableCheck  ;
extern char chActivateCheck;

extern long lCSFirstStartIdx, lCsFirstIdx, lCsFirstSize;
extern long lCSSecondStartIdx,lCsSecondIdx,lCsSecondSize;

extern unsigned long ulCs;	



extern  long UpdateRVARecDataBsTpuUnit(void* pvLDC, long lID);
extern void PrepDecompouseAbsNumeratorsUnitSPI(void); 
extern void TerminateServiceApCnAbsNumerator(void); 
extern void ActivateServTrApCnAbsNumeratorCTpuUnitSPI(void*pvO);
//extern void CheckActiveElemInArAbs(void);
extern long  CheckActiveElemInArAbs(void* pv);

extern void EvalCSTl(void);


#endif //AbsNumerator_h
