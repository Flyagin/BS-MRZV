
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
* File Name       : CfgTbls.h
* Description     : support for the CfgTbls.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  31/03/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef CFG_TBLS_h
#define CFG_TBLS_h

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~                          ~~~~~
//~~~                            ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//extern char chbsCfgTblState;
extern char chbsHldrPrtTblState;
extern char chbsStngTblState;
extern char  chReqCallServiceBsTblStates;//tHIS IS IF MAY BE NEED DO SOMETHING ONCE UPPON 10 MS



extern  short shbsCfgTblState;
#define BS_CFG_TBL_USED_BIT         (0)
//-Бит указывающий что ресурс занят и меняется
//#define BS_WR_CFG_MIN_ONB           (1)

#define BS_CFG_TBL_ICI_MF_BIT       (2)
//-Бит указывающий что ресурс был изменен системой межпроцессорного обмена
#define BS_CFG_TBL_EPR_MF_BIT       (3)
//-Бит указывающий что ресурс был изменен системой обслуживания EEPROM
#define BS_CFG_TBL_WR_EPR_BIT       (4)
//-Бит запроса на запись к  системе обслуживания EEPROM
#define BS_CFG_TBL_RD_EPR_BIT       (5)
//--Бит запроса на чтение к  системе обслуживания EEPROM
#define BS_WR_END_CFG_MIN_ONB       (6)

extern  char chCtrReading;
extern  char chCtrWriting;
extern  char chbsHldrPrtTblState;
#define BS_HLDR_PRT_TBL_USED_BIT         (1)
//-Бит указывающий что ресурс занят и меняется
#define BS_HLDR_PRT_TBL_ICI_MF_BIT       (2)
//-Бит указывающий что ресурс был изменен системой межпроцессорного обмена
#define BS_WR_END_PRT_TBL_MF_BIT       (3)
//-Бит указывающий что ресурс был XX системой обслуживания 
//Bit succesful writing
#define BS_RD_END_PRT_TBL_MF_BIT       (4)
//-Бит указывающий что ресурс был XX системой обслуживания 

#define BS_HLDR_PRT_TBL_WR_BIT       (5)
//-Бит запроса на запись к  системе обслуживания ICI
#define BS_HLDR_PRT_TBL_RD_BIT       (6)
//--Бит запроса на чтение к  системе обслуживания ICI

#define BS_HLDR_PRT_TBL_USED_ONB          BS_HLDR_PRT_TBL_USED_BIT
#define BS_HLDR_PRT_TBL_ICI_MF_ONB        BS_HLDR_PRT_TBL_ICI_MF_BIT
#define BS_WR_END_HLDR_PRT_TBL_ONB        BS_WR_END_PRT_TBL_MF_BIT 
#define BS_RD_END_HLDR_PRT_TBL_ONB        BS_RD_END_PRT_TBL_MF_BIT 
#define BS_HLDR_PRT_TBL_WR_ONB            BS_HLDR_PRT_TBL_WR_BIT 
#define BS_HLDR_PRT_TBL_RD_ONB            BS_HLDR_PRT_TBL_RD_BIT 

#define BS_HLDR_PRT_TBL_USED_MSK     (1<< BS_HLDR_PRT_TBL_USED_ONB  )
#define BS_HLDR_PRT_TBL_ICI_MF_MSK   (1<< BS_HLDR_PRT_TBL_ICI_MF_ONB)
#define BS_WR_END_HLD_RPRT_TBL_MSK   (1<< BS_WR_END_HLDR_PRT_TBL_ONB  )
#define BS_RD_END_HLD_RPRT_TBL_MSK   (1<< BS_RD_END_HLDR_PRT_TBL_ONB  )
#define BS_HLDR_PRT_TBL_WR_MSK       (1<< BS_HLDR_PRT_TBL_WR_ONB     )
#define BS_HLDR_PRT_TBL_RD_MSK       (1<< BS_HLDR_PRT_TBL_RD_ONB     )

extern  char chCtrReadingStng;
extern  char chCtrWritingStng;
extern  char chbsStngTblState;
#define BS_HLDR_STNG_TBL_USED_ONB         (1)
//-Бит указывающий что ресурс занят и меняется
#define BS_HLDR_STNG_TBL_ICI_MF_ONB       (2)
//-Бит указывающий что ресурс был изменен системой межпроцессорного обмена
#define BS_WR_END_STNG_TBL_ONB       (3)
//-Бит указывающий что ресурс был XX системой обслуживания 
#define BS_RD_END_STNG_TBL_ONB       (4)
//-Бит указывающий что ресурс был XX системой обслуживания 

#define BS_HLDR_STNG_TBL_WR_ONB       (5)
//-Бит запроса на запись к  системе обслуживания ICI
#define BS_HLDR_STNG_TBL_RD_ONB       (6)
//--Бит запроса на чтение к  системе обслуживания ICI


#define BS_HLDR_STNG_TBL_USED_MSK     (1<< BS_HLDR_STNG_TBL_USED_ONB  )
#define BS_HLDR_STNG_TBL_ICI_MF_MSK   (1<< BS_HLDR_STNG_TBL_ICI_MF_ONB)
#define BS_WR_END_STNG_TBL_MSK        (1<< BS_WR_END_STNG_TBL_ONB  )
#define BS_RD_END_STNG_TBL_MSK        (1<< BS_RD_END_STNG_TBL_ONB  )
#define BS_HLDR_STNG_TBL_WR_MSK       (1<< BS_HLDR_STNG_TBL_WR_ONB     )
#define BS_HLDR_STNG_TBL_RD_MSK       (1<< BS_HLDR_STNG_TBL_RD_ONB     )

extern  char chCtrReadingYst;
extern  char chCtrWritingYst;
extern  char chbsYstTblState;
#define BS_HLDR_YUST_TBL_USED_ONB         (1)
//-Бит указывающий что ресурс занят и меняется
#define BS_HLDR_YUST_TBL_ICI_MF_ONB       (2)
//-Бит указывающий что ресурс был изменен системой межпроцессорного обмена
#define BS_WR_END_YUST_TBL_ONB       (3)
//-Бит указывающий что ресурс был XX системой обслуживания 
#define BS_RD_END_YUST_TBL_ONB       (4)
//-Бит указывающий что ресурс был XX системой обслуживания 

#define BS_HLDR_YUST_TBL_WR_ONB       (5)
//-Бит запроса на запись к  системе обслуживания ICI
#define BS_HLDR_YUST_TBL_RD_ONB       (6)
//--Бит запроса на чтение к  системе обслуживания ICI


#define BS_HLDR_YUST_TBL_USED_MSK     (1<< BS_HLDR_YUST_TBL_USED_ONB  )
#define BS_HLDR_YUST_TBL_ICI_MF_MSK   (1<< BS_HLDR_YUST_TBL_ICI_MF_ONB)
#define BS_WR_END_YUST_TBL_MSK        (1<< BS_WR_END_YUST_TBL_ONB  )
#define BS_RD_END_YUST_TBL_MSK        (1<< BS_RD_END_YUST_TBL_ONB  )
#define BS_HLDR_YUST_TBL_WR_MSK       (1<< BS_HLDR_YUST_TBL_WR_ONB     )
#define BS_HLDR_YUST_TBL_RD_MSK       (1<< BS_HLDR_YUST_TBL_RD_ONB     )



//extern   char chbsWrCfgMinState;
//#define BS_CFG_MIN_USED_ONB         (1)
//#define BS_WR_END_CFG_MIN_ONB       (3)
//#define BS_WR_CFG_MIN_ONB           (5)

//`extern char chbsHldrPrtTblState;
//`#define BS_CFG_TBL_USED_BIT         (1)
//`//-Бит указывающий что ресурс занят и меняется
//`#define BS_CFG_TBL_ICI_MF_BIT       (2)
//`//-Бит указывающий что ресурс был изменен системой межпроцессорного обмена
//`#define BS_CFG_TBL_EPR_MF_BIT       (3)
//`//-Бит указывающий что ресурс был изменен системой обслуживания EEPROM
//`#define BS_CFG_TBL_WR_EPR_BIT       (4)
//`//-Бит запроса на запись к  системе обслуживания EEPROM
//`#define BS_CFG_TBL_RD_EPR_BIT       (5)
//`//--Бит запроса на чтение к  системе обслуживания EEPROM


extern  short shbsRefreshCfgTablesState;

#define BS_RF_CFG_VAR_USED_BIT         (0)
//-Бит указывающий что ресурс shbsRefreshCfgTablesState занят и меняется
#define  RQ_RD_STNG_TBL_BIT       (2)
//-Бит запроса на чтение к RefreshCfgTables()
#define RQ_WR_STNG_TBL_BIT       (3)
//-Бит запроса на запись к RefreshCfgTables() 
#define RQ_RD_YUST_TBL_BIT       (4)
//-Бит запроса на запись к  системе обслуживания EEPROM
#define RQ_WR_YUST_TBL_BIT       (5)
//--Бит запроса на чтение к  системе обслуживания EEPROM
#define RQ_RD_PRT_TBL_BIT       (6)
//-Бит запроса на запись к  системе обслуживания EEPROM
#define RQ_WR_PRT_TBL_BIT       (7)
//--Бит запроса на чтение к  системе обслуживания EEPROM
#define RQ_WR_MIN_CFG_TBL_BIT       (8)
//--Бит запроса на установку мин параметров EEPROM


//~//--Бит запроса на чтение к  системе Ici
//~#define BS_RQ_RD_CFG_TBL_BIT       (1)
//~//-Бит запроса на запись к  системе Ici
//~#define BS_RQ_WR_CFG_TBL_BIT       (2)
//~//--Бит запроса на установку мин параметров CFG_TBL
//~#define BS_RQ_SET_MIN_CFG_TBL_BIT  (3)
//~
//~extern  short shbsRQChangeCfgTablesState;
#define WR_PRT_TBL_BIT       (0)
#define WR_STNG_TBL_BIT      (1)
extern long lStateWriting;








extern void Ici10msRing(void);
extern void ServiceBsTblStates(void);

extern void RefreshCfgTables(void);
extern void CollectCfgTbls(void);
extern void CheckCfgTables(void);
extern void SendCfgData(void);
extern void CheckStngState1(void);
extern void WriteStngState(void);
extern void ReadStngTbl(void);

extern void WriteCfgTbl(void);
extern void ReadCfgTbl(void);

extern void WriteYstState(void);
extern void ReadYstTbl(void);
extern void ForceSetMinParamCfgTbl(void);

extern void PrepareDhldStngIciTblforTrOnBM(void) ;
extern void PrepareDholderPrtTblforTrOnBR(void) ;


extern void IciDbgCall_I_Fn(void);

#endif //CFG_TBLS_h
