/*------------------------------------------------------------------------------
* Created (c) 2013 - Factory “KyivPrylad”
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
* File Name       : dFlMap.h
* Description     : Memory Map defenition for DataFlash
                    BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  05/11/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef  D_FL_MAP_h
#define  D_FL_MAP_h


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Data flash memory map                      ~~~~~
//~~~       D                      ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#ifndef DIAGNOSTICS_h

#define AMOUNT_PRG_EVT_RECORD 100
#define SIZE_DIAGN_FIELD (3*16)

#else
			
#endif 


#define SIZE_AREA_PREC  (SIZE_DIAGN_FIELD*AMOUNT_PRG_EVT_RECORD)
#define SIZE_AREA_DREC  640
//``````````````````````````````````````````````````````````````````````````````````
//~~~   
//..................................................................................
#define ADR_AREA_PREC 0
#define ADR_AREA_DREC   (ADR_AREA_PREC +SIZE_AREA_PREC )

//SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR



#ifndef __EEPROM_RTC_DATAFLASH__
#define SIZE_BUF_DFL (5*264)
#else
#define SIZE_BUF_DFL SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR
#endif



extern char  chReqCallServiceDFlAreas;//extern chDFlAreasRq; //Hold Req of adresats Dfl
#define DFL_AREAS_VAR_USED_BIT         (0)
#define RQ_DFL_AREA_PREC_USED_BIT          (1)   
#define RQ_DFL_AREA_DREC_USED_BIT          (2)   

//extern char  chReqCallServicePrec;



#endif /* D_FL_MAP_h */
