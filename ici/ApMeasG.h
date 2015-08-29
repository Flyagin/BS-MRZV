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
* File Name       : ApMeasG.h
* Description     : support for the AppCn.
                    
					
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  10/12/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ApMeasG
#define ApMeasG
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef __TYPE_DEFINITION_BS_H
#define SIZE_TOTAL_MEASUREMENT_G 0X1000
#endif 
#ifdef __TYPE_DEFINITION_BS_H
		#define SIZE_TOTAL_MEASUREMENT_G ( ((sizeof(__TOTAL_MEASUREMENT )>>2)<<2) + 4*(1&&(sizeof(__TOTAL_MEASUREMENT ))&3) )
#endif
typedef struct tag_TotMeasGHldDsc
{
	union 
	{
	    	char   chArTotMeas [SIZE_TOTAL_MEASUREMENT_G];
	    	long   lArTotMeas  [SIZE_TOTAL_MEASUREMENT_G>>2];
#ifdef __TYPE_DEFINITION_BS_H
			__TOTAL_MEASUREMENT total_measurement;
#endif
            
	}UNTotMeas;
	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}TotMeasGHldDsc;
extern TotMeasGHldDsc holderTotMeasG;

//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_TotMeasGWrpDsc//Wrapper 
{

long size_total_measurement;      //
void *p_total_measurement;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}TotMeasGWrpDsc;
extern TotMeasGWrpDsc hldTotMeasGWrp;
extern int AppReqTransmitTotMeasG;
extern int AppReqReceiveTotMeasG;

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
extern void ActivateServTrApCnTotMeasGCTpuUnitU2(void);
extern  void TerminateServiceApCnTotMeasG(void);



#endif 
/* ApMeasG */
