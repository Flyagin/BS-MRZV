
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
* File Name       : Tlmc.h
* Description     : support for the Tlmc.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  29/01/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef TELEMECHANICS_h
#define TELEMECHANICS_h

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                          ~~~~~
//~~~                            ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_IN  32
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_OUT 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
#define NUM_LED 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````


#define AMOUNT_BYTE_FOR_IN            (((NUM_IN)>>3) ) //+1) 

#define AMOUNT_BYTE_FOR_OUT           (((NUM_OUT)>>3)) // +1) 

#define AMOUNT_BYTE_FOR_OUT_TRG       (((NUM_OUT)>>3)  ) //+1)
                                                        //
#define AMOUNT_BYTE_FOR_LED           (((NUM_LED)>>3) ) //+1)
                                                        //
#define AMOUNT_BYTE_FOR_LED_TRG       (((NUM_LED)>>3) ) //+1)

#define AMOUNT_BYTE_FOR_GRP_SELECTOR   1
                                      
#define __TYPE_DEFINITION_TELE_BR_TO_BS__ 1
									  
#ifndef __TYPE_DEFINITION_TELE_BR_TO_BS__
#define SIZE_TELE 20
#else
#define SIZE_TELE_INFO (AMOUNT_BYTE_FOR_IN+ AMOUNT_BYTE_FOR_OUT \
+AMOUNT_BYTE_FOR_OUT_TRG + AMOUNT_BYTE_FOR_LED + AMOUNT_BYTE_FOR_LED_TRG + AMOUNT_BYTE_FOR_GRP_SELECTOR)
#endif 

typedef struct tag_TeleMechsHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_TELE_BR_TO_BS__	    	
			char   chArTeleMechs [SIZE_TELE];
	    	long   lArTeleMechs  [SIZE_TELE>>2];
#else
			char   chArTeleMechs [SIZE_TELE_INFO];
	    	long   lArTeleMechs  [SIZE_TELE_INFO>>2];
#endif 			
#ifdef __TYPE_DEFINITION_TELE_BR_TO_BS__
			//Obj xxx_TeleMechs;
			struct
			{
				char  chArIn    [AMOUNT_BYTE_FOR_IN ];
				char  chArOut   [AMOUNT_BYTE_FOR_OUT];
				char  chArOutTrg[AMOUNT_BYTE_FOR_OUT_TRG];
				char  chArLed   [AMOUNT_BYTE_FOR_LED];
				char  chArLedTrg[AMOUNT_BYTE_FOR_LED_TRG ];
				char  chGrpSelector;
				//char  chArWrp[SIZE_WRP_];//
				//char  chDiag[SIZE_DIAGNOSTIC_DATA];
				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrTeleMechsTeleInfoWrp;
#else			
			struct
			{
	

				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrTeleMechsTeleInfoWrp;
			
#endif
            
	}UNTeleMechs;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}TeleMechsHldDsc;
#ifdef __TYPE_DEFINITION_TELE_BR_TO_BS__
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )
extern TeleMechsHldDsc holderTeleMechs;
#define SIZE_TELE (sizeof(holderTeleMechs.UNTeleMechs.sBrTeleMechsTeleInfoWrp ))
#endif

//extern __TOTAL_MEASUREMENT total_measurement;
//Mgr mean mahager or dispatcher
typedef struct tag_TeleMechsMgr
{
unsigned short ushRegisterdUsr;//Keys Field
char chIsExec;
char chDataWasCorrupted;//when Session part was Fault
short shCurCopyUser;//
short shCopyWasCorrupted;


}TeleMechsMgrDsc;


typedef struct tag_TeleMechsWrpDsc//Wrapper 
{

long size_TeleMechs;      //
void *p_TeleMechs;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}TeleMechsWrpDsc;

extern int AppReqTransmitTeleMechs;
extern int AppReqReceiveTeleMechs ;

extern TeleMechsHldDsc holderTeleMechs;
extern TeleMechsHldDsc holderTeleMechsIciCopy;
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
extern TeleMechsMgrDsc hldTeleMechsMgr;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//.extern void ActivateServTrApCnTeleMechsCTpuUnitSpi(void);
//.extern  void TerminateServiceApCnTeleMechs(void);
extern long GetUserKeyTeleMechsData(void);
extern long GetTeleMechsData(long lUsrKey, void *pBuf);
extern long ReturnUserKeyTeleMechsData(long lKey);



#endif //TELEMECHANICS_h
