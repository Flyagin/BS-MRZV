/*------------------------------------------------------------------------------
*  Created (c) 2014 - Factory “KyivPrylad”
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
* File Name       : TC_G45.h
* Description     : Definition of AT91SAM9G45-BS characteristics, 
                    AT91SAM9G45-dependant PIOs and external components
					interfacing.
                    
*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  22/05/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef TC_G45_h
#define TC_G45_h

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
/*
-
-
-
*/
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//#define 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 



//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//#define SIZE_LPDU_CNL_2 248
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

typedef struct tag_InitAT91TCDsc//Wrapper 
{
unsigned long at91c_id_tc_Val;
unsigned long ul_CMR_Val;//Mode of Timer
unsigned long ul_Prior_Val;//PRIOR for AIC
unsigned long ul_RC_Val;
void* pf_TC_irq_handler;
void *pTC;


}InitAT91TCDsc;

typedef struct tag_AT91TC_IrqData_Dsc//Wrapper 
{
unsigned char uChActiveTimers;//Bit fild ord num Use Timers
unsigned char uChShadowActiveTimers;//Bit fild ord num Use Timers
char chAmountUseTimers;//
char chIdxProcessTimer;//Timer now scan
void (*arPF_TC_irq_handlers [8])(void) ;
void* arAT91TC_BASE_Pointers[8];
char arChRefNum[8];//Last Num First Process
long arStatusReg[8];//Copy Status Register Must Clear In Interrupt Hndler
}AT91TC_IrqData_Dsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 


//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    HEADER    STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct PflMdlRcdDsc_TagIn
{
long  Id_Module;      //
short Cv_Start;//
short Cv_End;//
unsigned long IciCallCounterVal;

}PflMdlRcdDsc;
//Profiler Module Record Descriptor
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define ID_1 1//
#define ID_2 2
#define ID_3 3
#define ID_4 4
#define ID_5 5


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~    HEADER    STRUCTS  ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define TOT_AMT_PFL_RECORD      2000//1000
#define MIN_AVIABLE_PFL_RECORD      5
#define CRITICAL_TIME_EXEC_INT  1200//2000

//``````````````````````````````````````````````````````````````````````````````````

typedef struct PflrDataDsc_TagIn
{
long  IdxWrPflrMdlRcd;      //Index write PflMdlRcd
long lAmtPflrMdlRcd;        //Amount Record In
short shR;
short shOrderNumProcessingRecord;

//Filling Distance betwenn fill and last Record 
//. hs1_txfill == hs1_txget)&&(hs1_txsize
// hs1_rxfill == hs1_rxget hs1_rxsize
long  IdxFillRcd;
long  IdxGetRcd;
PflMdlRcdDsc arPflMdlRcd [TOT_AMT_PFL_RECORD];
//int threedim[5][10][4];
char arNamePflMdlRcd[100][ 255];//TOT_AMT_PFL_RECORD
}PflDataDsc;
//Profiler Module Record Descriptor
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


extern PflDataDsc PflData , PflDataSaveBig;
//lIdx_wz_amt <- Index with amount 0-last
extern long GetPflrMdlRcd(void* pvRcd,long lIdx_wz_amt);
extern long PutPflrMdlRcd(void* pvRcd,long lAmt);
extern long CreatePflrMdlRcd(long lId_Mod, long lCv,void* pvRcd);
extern int InsertDscMsg(char const *file, int line,int IDPflrMdlRcd,
 char const *func, char const * msg);
extern void OutTerminalCurrPflrData(void *pFlrData);
extern void SaveCurrIciCallSlises(void );
extern long PutPflrMdlRcd_1(void* pvRcd,long lAmt);


//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
void TC_irq_handler ( void );
void TC1_irq_handler ( void );
long RegisterTC1 ( void );
long UnRegisterTC1 ( void );

extern AT91TC_IrqData_Dsc  TCIrqData;
extern long lInInt ;




void TC1Init ( void );



extern long TC2_Stop(void);
extern void TC2_Start(void);



#endif 
/* TC_G45_h */
