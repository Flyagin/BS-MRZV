
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
* File Name       : ADPrcd.h
* Description     : support for the Arec Drec Prec
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  07/12/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#ifndef DIAGNOSTICS_h
#define DIAGNOSTICS_h
#include "diagBsEn.h"
#include "diagBmEn.h"
#include "diagBrEn.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//==================================================================================
//--- 			 INTERNAL  diagnostik  CONSTANT BIT     -----------
//==================================================================================
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~   diagBmEn En -enumms not English        ~~
//~~~           ~~ 
//~~~           ~~
//~~~           ~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define SIZE_DIAGN_FIELD ( sizeof(BmRamPrgEvtDsc ) \
+ sizeof(BrRamPrgEvtDsc ) + sizeof(BsRamPrgEvtDsc) )


typedef union 
{
#ifndef DIAGNOSTICS_h	    	
//			char   chArSDFE [SIZE_DIAGN_FIELD];
//	    	long   lArSDFE  [SIZE_DIAGN_FIELD>>2];
#else
			char   chArRamPrgEvt [SIZE_DIAGN_FIELD];
	    	long    lArRamPrgEvt [SIZE_DIAGN_FIELD>>2];
#endif 			
#ifdef DIAGNOSTICS_h
			//Obj xxx_
			struct
			{
				BmRamPrgEvtDsc hldrPrgEvtBm;
				BrRamPrgEvtDsc hldrPrgEvtBr; 
				BsRamPrgEvtDsc hldrPrgEvtBs;
			}RamPrgEvtFld;	
#else			
			;
			
#endif
            
}UNN_PrgEvtBmBrBs;

typedef struct PrgEvtRecord_T1_tag
{
UNN_PrgEvtBmBrBs hld_UNN_PrgEvt;
long lTimeLabSysU32;
long lCompresDataTime;

}PrgEvtRecord_T1_Dsc;


typedef struct PrgEvtFlash_2_Dsc_TAG             // <-to EEPROM
{
	UNN_PrgEvtBmBrBs hldFixUNN_PrgEvt;//Previous   
//	UNN_PrgEvtBmBrBs hldUNN_PrgEvt;//Current       <-
	unsigned char	chAmountRecords;//Register AmountRecords
	unsigned char	uchIdxWrRecord;//index Wr Rec
	unsigned long ulCheckSum_arPrgEvt;

	
	//-unsigned char	arErrorEvents[50*( sizeof(long)+2*sizeof(char) )]; 
	unsigned long	ulCheckSum;                   //<-to EEPROM
}PrgEvtFlash_2_Dsc;

extern PrgEvtFlash_2_Dsc   hPrgEvtMangInfo;//This struct should write to EEPROM

extern UNN_PrgEvtBmBrBs hldUNN_PrgEvt;



#endif 
         
