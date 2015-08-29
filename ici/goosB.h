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
* File Name       : GoosB.h
* Description     : support for the GoosB.c
                    BM BR

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  11/03/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef GoosB_H
#define GoosB_H


#ifndef __TYPE_DEFINITION__
#define SIZE_GOOS_B 0X320
#endif 
#ifdef __TYPE_DEFINITION__
//#define SIZE_GOOS_B ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )
#define SIZE_GOOS_B 0X320
#endif
typedef struct tag_GoosBHldDsc
{
	union 
	{
	    	char   chArGoosB [SIZE_GOOS_B];
	    	long   lArGoosB  [SIZE_GOOS_B>>2];
#ifdef __TYPE_DEFINITION__
			//Obj xxx_GoosB;
#endif
            
	}UNGoosB;
	BigObjCMUnitDsc hldGoosBObjConMode;
	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}GoosBHldDsc;


//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_GoosBWrpDsc//Wrapper 
{

long size_GoosB;      //
void *p_GoosB;        //
	
	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
	
}GoosBWrpDsc;

extern int AppReqTransmitGoosB;
extern int AppReqReceiveGoosB ;

extern GoosBHldDsc holderGoosB;
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
extern void ActivateServTrApCnGoosBCTpuUnitSpi(void);
extern  void TerminateServiceApCnGoosB(void);

extern  long Eval_CS(char* pCh, long iLength );
extern long CalcGoosBHldCs( void* pGoosBHldDsc);
extern long CheckGoosBHldCs( void* pGoosBHldDsc);



#endif //GoosB_h


