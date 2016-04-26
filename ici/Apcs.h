/*------------------------------------------------------------------------------
* Created (c) 2014 - Factory “KyivPrylad”
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
* File Name       : Apcs.h
* Description     : support for the Apcs.c
                    BS BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef Apcs_H
#define Apcs_H

typedef struct HvpBrOnCalcInfo_TAG{

	long lResourceCB;   //Resurs Vikluchtelya
	long lAmountSetOnCB;//Kol-vo otkl

}HvpBrOnCalcInfoDsc;



#define __TYPE_DEFINITION__
#ifdef __TYPE_DEFINITION__
#define SIZE_WRP 1
#define SIZE_APCS ( sizeof(HvpBrOnCalcInfoDsc)+SIZE_WRP)
#else
#define SIZE_APCS 20
#endif
typedef struct tag_ApcsHldDsc
{
	char  chArWrp[SIZE_WRP];//Header Info
	union 
	{
	    	char   chArApcs [SIZE_APCS];
	    	long   lArApcs  [SIZE_APCS>>2];
#ifdef __TYPE_DEFINITION__
			//Obj xxx_Apcs;
			HvpBrOnCalcInfoDsc hldHvpBrOnCalcInfo;
#endif
            
	}UNApcs;
	
}ApcsHldDsc;


//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_ApcsWrpDsc//Wrapper 
{

long size_Apcs;      //
void *p_Apcs;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}ApcsWrpDsc;

extern int AppReqTransmitApcs;
extern int AppReqReceiveApcs ;

extern ApcsHldDsc holderApcs;
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
extern void ActivateServTrApCnApcsCTpuUnitSpi(void);
extern  void TerminateServiceApCnApcs(void);






#endif //Apcs_h


