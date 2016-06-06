
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
* File Name       : fcoil.h
* Description     : support for the fcoil.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  20/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef FORCE_COIL_h
#define FORCE_COIL_h

#ifndef BR_SET_IN_OUT
#define  BR_SET_IN_OUT
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

typedef struct BrSetInOutDsc_TagIn
{
	char  chArIn    [AMOUNT_BYTE_FOR_IN ];
	char  chArOut   [AMOUNT_BYTE_FOR_OUT];
	
	char  chAr[4];//ID_Activator -  Who generate command or it may be Adress IEC
	//char  chArWrp[SIZE_WRP_];//
	
	
}BrSetInOutDsc;
#endif




                                      
#define __TYPE_DEFINITION_FCOIL_BS_TO_BR__ 1
									  
#ifndef __TYPE_DEFINITION_FCOIL_BS_TO_BR__
#define SIZE_FCOIL 20
#else
#define SIZE_FCOIL_INFO ( AMOUNT_BYTE_FOR_IN + AMOUNT_BYTE_FOR_OUT + 4)
#endif 

typedef struct tag_FCoilHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_FCOIL_BS_TO_BR__	    	
			char   chAFCoil [SIZE_FCOIL];
	    	long   lArFCoil [SIZE_FCOIL>>2];
#else
			char   chArFCoil [SIZE_FCOIL_INFO];
	    	long   lArTFCoil [SIZE_FCOIL_INFO>>2];
#endif 			
#ifdef __TYPE_DEFINITION_FCOIL_BS_TO_BR__
			//Obj xxx_FCoil;
			struct
			{
				char  chArIn    [AMOUNT_BYTE_FOR_IN ];
				char  chArOut   [AMOUNT_BYTE_FOR_OUT];
				
				char  chAr[4];//ID_Activator -  Who generate command or it may be Adress IEC
	//char  chArWrp[SIZE_WRP_];//
			}sBrFCoilInfoWrp;
#else			
			struct
			{
	

				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrFCoilInfoWrp;
			
#endif
            
	}UNFCoil;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}FCoilHldDsc;
#ifdef __TYPE_DEFINITION_FCOIL_BS_TO_BR__
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )

#define SIZE_FCOIL  (sizeof( holderFCoil.UNFCoil.sBrFCoilInfoWrp ))
#endif

//extern __TOTAL_MEASUREMENT total_measurement;

typedef struct tag_FCoilWrpDsc//Wrapper 
{

long size_FCoil;      //
void *p_FCoil;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}FCoilWrpDsc;

extern int AppReqTransmitFCoil;
extern int AppReqReceiveFCoil ;

extern FCoilHldDsc holderFCoil;
extern FCoilHldDsc holderFCoilIciCopy;
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
//.extern void ActivateServTrApCnFCoilCTpuUnitSpi(void);
//.extern  void TerminateServiceApCnFCoil(void);
void PrepDecompouseFCoilUnitSpi(void);
void TerminateServiceApCnFCoil(void);
void ActivateServTrApCnFCoilCTpuUnitSpi(void);



#endif //FORCE_COIL_h

















