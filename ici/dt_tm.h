
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
* File Name       : dt_tm.h
* Description     : support for the dt_tm.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  25/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef DATE_TIME_h
#define DATE_TIME_h

typedef struct BrDateTimeDsc_TagIn
{

    char msec;     //00h 0.1 seconds 0.01 seconds 						Seconds 00-99
	char sec;      //01h ST 10 seconds  Seconds 						Seconds 00-59
    char min;      //02h 0 10 minutes   Minutes 						Minutes 00-59
    char hour;     //03h CB1 CB0 10 hours Hours (24-hour format) CB0, CB1 = Century bits/hours 0-3/00-23
	char dayweek;  //04h 0 0 0 0 0 Day of week 							Day 01-7
    char day;      //05h 0 0 10 date Date: 								day of month Date 01-31
    char month;    //06h 0 0 0 10M Month 								Month 01-12
    char year;     //07h 10 Years Year 									Year 00-99


}BrDateTime;




                                      
#define __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__ 1
									  
#ifndef __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__
#define SIZE_DATE_TIME 10
#else
#define SIZE_DATE_TIME_INFO sizeof(BrDateTime )
#endif 

typedef struct tag_DateTimeHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__	    	
			char   chADateTime [SIZE_DATE_TIME];
	    	long   lArDateTime [SIZE_DATE_TIME>>2];
#else
			char   chArDateTime [SIZE_DATE_TIME_INFO];
	    	long   lArTDateTime [SIZE_DATE_TIME_INFO>>2];
#endif 			
#ifdef __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__
			//Obj xxx_FCoil;
			struct
			{
				char msec;   
				char sec;    
				char min;    
				char hour;   
				char dayweek;
				char day;    
				char month;  
				char year;   
				
				//char  chArWrp[SIZE_WRP_];//
			}sBsDatetimeInfoWrp;
#else			
			struct
			{
	

				//ApcsMiscDataDsc hldApcsMiscData;
			}sBsDatetimeInfoWrp;
			
#endif
            
	}UNDateTime;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}DateTimeHldDsc;
#ifdef __TYPE_DEFINITION_DATE_TIME_BS_TO_BR__
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )

#define SIZE_DATE_TIME  (sizeof( holderDateTime.UNDateTime.sBsDatetimeInfoWrp ))
#endif

//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_DateTimeWrpDsc//Wrapper 
{

long size_DateTime;      //
void *p_DateTime;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}DateTimeWrpDsc;

extern int AppReqTransmitDateTime;
extern int AppReqReceiveDateTime ;

extern DateTimeHldDsc holderDateTime;
extern DateTimeHldDsc holderDateTimeIciCopy;
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
void PrepDecompouseDateTimeUnitSpi(void);
void TerminateServiceApCnDateTime(void);
void ActivateServTrApCnDateTimeCTpuUnitSpi(void);



#endif //DATE_TIME_h

















