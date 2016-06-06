/*------------------------------------------------------------------------------
* Copyright (c) 2013 -
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
* File Name       : SmpWrp.h
* Description     : support for the AppCn.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  14/12/13   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef SmpWrp
#define SmpWrp


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef TYPE_RAW_SAMPLES
#define SIZE_RAW_SAMPLES 52
#endif 
#ifdef __TYPE_DEFINITION_X_
		#define SIZE_RAW_SAMPLES (48 )
#endif
typedef struct tag_RawSamplGHldDsc
{
	union 
	{
	    	char   chArSmpl [SIZE_RAW_SAMPLES];
	    	long   lArSmpl  [SIZE_RAW_SAMPLES>>2];
#ifdef __TYPE_DEFINITION_X_
			__RAW_SAMPLES_ raw_samples;
#endif
            
	}UNRawSampl;
	struct
	{
		unsigned long long u2LAbsTrNumber;
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}RawSamplHldDsc;

extern  RawSamplHldDsc holderRawSampl;
//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_RawSamplWrpDsc//Wrapper 
{

long size_raw_samples;      //
void *p_raw_samples;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}RawSamplWrpDsc;
extern int AppReqTransmitRawSampl;
extern int AppReqReceiveRawSampl; 
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
extern void ActivateServTrApCnRawSamplCTpuUnitHSU2(void);
extern  void TerminateServiceApCnRawSampl(void);



#endif /* SmpWrp.h */
