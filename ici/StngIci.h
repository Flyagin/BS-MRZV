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
* File Name       : StngIci.h
* Description     :  support for the stng_tpt.c
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  04/01/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/
#include    "../inc/const_BS_BL.h" 
#include    "../inc/type_definition_BS.h"
#include    "../inc/type_definition_BL.h" 

#ifndef STNG_TPT_TBL_h
#define STNG_TPT_TBL_h

#include    "hv_df.h"
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef HV_DF_h
#define SIZE_PRT 0X1035
#endif 
#ifdef HV_DF_h
#define SIZE_PRT (  ((sizeof(CfgTblDsc )>>2)<<2) + (4*(1&&(sizeof(CfgTblDsc ))&3))    )
//( ((sizeof(__YUST )>>2)<<2) + 4*(1&&(sizeof(__YUST ))&3) )
#else	
typedef struct tag_PrtTblHldDsc
{
	union 
	{
#ifdef 	HV_DF_h	
			char   chArPrt  [ sizeof(CfgTblDsc )];
#else					
	    	char   chArPrt  [ SIZE_PRT];
#endif			
	    	long    lArPrt  [ (SIZE_PRT>>2)+1];//One additional Word

#ifdef 	HV_DF_h
			CfgTblDsc CfgPrtTbl;
#else			
			unsigned int PrtTbl[SIZE_PRT>>2];
#endif
            
	}UNPrtTbl;
	long lCheckSum;
}PrtTblHldDsc;
#endif
extern PrtTblHldDsc holderPrtTbl;
extern long lSizeOf_PrtTbl;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifndef __TYPE_DEFINITION_BS_H
#define SIZE_STNG_UNN 0X1035
#endif 
#ifdef __TYPE_DEFINITION_BS_H
#define SIZE_STNG_UNN (  ((sizeof(__SETTINGS )>>2)<<2) + (4*(1&&(sizeof(__SETTINGS ))&3))    )
//( ((sizeof(__YUST )>>2)<<2) + 4*(1&&(sizeof(__YUST ))&3) )
#endif
typedef struct tag_StngIciTblDsc
{
	union 
	{
#ifdef 	__TYPE_DEFINITION_BS_H
			char   chArStngIci  [ sizeof(__SETTINGS )];
#else					
	    	char   chArStngIci  [ SIZE_STNG_UNN];
#endif			
	    	long    lArStngIci  [ (SIZE_STNG_UNN>>2)];
			//[(SIZE_STNG_UNN>>2)+1] <- One additional Word

#ifdef 	__TYPE_DEFINITION_BS_H
			__SETTINGS StngIciTbl;
#else			
			unsigned int StngIciTbl[SIZE_STNG_UNN>>2];
#endif
            
	}UNStngIciTbl;
	long lCheckSum;
}StngIciTblDsc;
#define SIZE_SETTINGS_ICI sizeof(SettingsHldDsc )
extern StngIciTblDsc hldStngIciTbl;//Vmesto CurrSettingsDbg
extern long lSizeOf_StngIci;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern void ActivateTransmittionStngOnBM(void);
extern  long Eval_CS(char* pCh, long iLength );

#endif

