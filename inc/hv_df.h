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
* Processor       : All
* File Name       : hv_df.h
* Description     : Definitions and structures for HVP projct
                    BM BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  23/04/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/


#ifndef HV_DF_h
#define HV_DF_h

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Перечень констант которые определяют                       ~~~~~
//~~~       параметры таблиц защит и таблиц   EEPROM                     ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
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

//``````````````````````````````````````````````````````````````````````````````````
//#define NUM_TRG 4

#define NUM_KEY 6
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define NUM_DEF_FUN 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define NUM_DEF_TRG 8
#define NUM_TRG     NUM_DEF_TRG
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define SIZE_PRT_IN_DSC     sizeof(long)
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define SIZE_PRT_OUT_DSC    sizeof(long)
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define SIZE_EPR_IN_DSC     sizeof(char)
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define SIZE_EPR_OUT_DSC    sizeof(char)
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#include "epr_f.h" //Config function
//#include "cmd_f.h" //Command function
//#include "lgr_f.h" //Logger function
//#include "cfg_f.h" //configuration function
//#include "atrs_f.h"//Activators function
//#include "tst_f.h" //Test Self control Bits

//#include "hvp_df.h"
#include "hve_df.h"
#define NUM_PRT 16
//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       List of  Protection Table Const                      ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//#define      1 
//#define      2
//#define      3
//#define      4
//``````````````````````````````````````````````````````````````````````````````````
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Protection Table   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct PrtTblDsc_TagIn
{
unsigned char  arUchTypeSignal[(NUM_IN>>3)];//AC/DC1
/*Маска типа сигнала, который заводится на дискретные вход
	0 - постоянный
	1 - переменный

	MSB ...LSB
	ДВ31 	ДВ0
*/
unsigned char  arUchTypeInput[(NUM_IN>>3)];//normal inverse
/*
	Маска режима работы дискретных входов
	1 - прямой
	0 - инверсный
	Маска
	MSB ...LSB
	ДВ31 	ДВ0
*/
unsigned char  arUchTypeOuts[(NUM_OUT>>3)];//0-signal/ 1-trigger
unsigned char  arUchTypeLeds[(NUM_LED>>3)];//0-signal/ 1-trigger
/*
	Маска типа  выходов и светодиодов
	1 - триггерный
	0 - сигнальный
	Маска
	MSB ...LSB
	
*/

unsigned short ushDurationDI[NUM_IN];//dopusk DV
/*
    Допуск ДВ (для постоянного - величина  10*ushDurationDI мсе
	для переменного пол периода 10+ 10*ushDurationDI  мсек)
*/



}PrtTblDsc;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       List of  Configuration Table Const                      ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//#define      1 
//#define      2
//#define      3
//#define      4
//``````````````````````````````````````````````````````````````````````````````````
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
//                   ~~~   Configuration Table   ~~~
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
typedef struct CfgTblDsc_TagIn
{
unsigned char  arUchTypeSignal[(NUM_IN>>3)];//AC/DC1
/*Маска типа сигнала, который заводится на дискретные вход
	0 - постоянный
	1 - переменный

	MSB ...LSB
	ДВ31 	ДВ0
*/
unsigned char  arUchTypeInput[(NUM_IN>>3)];//normal inverse
/*
	Маска режима работы дискретных входов
	1 - прямой
	0 - инверсный
	Маска
	MSB ...LSB
	ДВ31 	ДВ0
*/
unsigned char  arUchTypeOuts[(NUM_OUT>>3)];//0-signal/ 1-trigger
unsigned char  arUchTypeLeds[(NUM_LED>>3)];//0-signal/ 1-trigger
/*
	Маска типа  выходов и светодиодов
	1 - триггерный
	0 - сигнальный
	Маска
	MSB ...LSB
	
*/

unsigned short ushDurationDI[NUM_IN];//dopusk DV
/*
    Допуск ДВ (для постоянного - величина  10*ushDurationDI мсе
	для переменного пол периода 10+ 10*ushDurationDI  мсек)
*/

#define AMOUNT_BYTE_FOR_IEPRF   (((RESERV_MAX_IEPRF_ONB)>>3) +1) 
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

unsigned char uc_ar_di_rank_cfg[NUM_IN*AMOUNT_BYTE_FOR_IEPRF];//48 bit
//Описание  массива ранжирования дискретных входов
// массив состоит из битовых строк длиной (AMOUNT_BYTE_FOR_IEPRF)*8 бит,
// 
// Строки массивА сопоставляются дискретным входам ОТ 0 ДО NUM_IN
// Биты в строках  - командам которые дискретный вход может сгенерировать
// Строке0 uc_ar_di_rank_cfg[0*AMOUNT_BYTE_FOR_IEPRF] соответствует ДВ1, 
// строке 1 uc_ar_di_rank_cfg[1*AMOUNT_BYTE_FOR_IEPRF] соответствует ДВ2 и т.д.
//  
// Перечень команд и их положение в слове массиве 0 до AMOUNT_BYTE_FOR_IEPRF
// в enum ENMEpr_f_In файла  epr_f.h 

#define AMOUNT_BYTE_FOR_KEPRF   (((RESERV_MAX_F_EPRF_ONB)>>3) +1) 
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````
unsigned char uc_ar_key_rank_cfg[NUM_KEY*AMOUNT_BYTE_FOR_KEPRF];//
//Описание  массива ранжирования функциональных кнопок
// массив состоит из битовых строк длиной (AMOUNT_BYTE_FOR_KEPRF)*8 бит,
// Строки массивА сопоставляются Ф - кнопкам F1 F2 F3 F14
// uc_ar_key_rank_cfg[0*AMOUNT_BYTE_FOR_KEPRF..до 0*AMOUNT_BYTE_FOR_KEPRF+ AMOUNT_BYTE_FOR_KEPRF] кнопка F1 
// uc_ar_key_rank_cfg[1*AMOUNT_BYTE_FOR_KEPRF..до 1*AMOUNT_BYTE_FOR_KEPRF+ AMOUNT_BYTE_FOR_KEPRF] кнопка F2
// uc_ar_key_rank_cfg[2*AMOUNT_BYTE_FOR_KEPRF..до 2*AMOUNT_BYTE_FOR_KEPRF+ AMOUNT_BYTE_FOR_KEPRF]  кнопка F3
// uc_ar_key_rank_cfg[3*AMOUNT_BYTE_FOR_KEPRF..до 3*AMOUNT_BYTE_FOR_KEPRF+ AMOUNT_BYTE_FOR_KEPRF] кнопка F4

#define AMOUNT_BYTE_FOR_OEPRF   (((RESERV_MAX_OEPRF_ONB)>>3) +1) 
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

unsigned char uc_ar_do_rank_cfg[NUM_OUT*AMOUNT_BYTE_FOR_OEPRF];//48 bit
//Описание  массива ранжирования дискретных выходов
// массив состоит из битовых строк длиной (AMOUNT_BYTE_FOR_OEPRF)*8 бит,
// 
// Строки массивА сопоставляются дискретным входам ОТ 0 ДО NUM_OUT
// Биты в строках  - командам которые на дискретный выход можно сранжировать
// Строке0 uc_ar_do_rank_cfg[0...1*AMOUNT_BYTE_FOR_OEPRF] соответствует ДВых1, 
// строке 1 uc_ar_do_rank_cfg[1*AMOUNT_BYTE_FOR_OEPRF...2*AMOUNT_BYTE_FOR_OEPRF]
//  соответствует ДВых2 и т.д. 
// Перечень команд и их положение в слове массиве 0 до AMOUNT_BYTE_FOR_OEPRF
// в enum ENMEpr_f_Out  файла  epr_f.h 




// Описание формата массива регистратора зафиксированных и текущих функций
// Массив состоит из битовых строк длиной XXX бит,
// Биты в строках  - командам которые в enum ENMEpr_f_Lgr  файла  epr_f.h

////////////////////////////////////////////////////////////////////////
//Описание  массива ранжирования светодиодов
unsigned char uc_ar_led_rank_cfg[NUM_LED*AMOUNT_BYTE_FOR_OEPRF];//96 bit
//Перечень команд и их положение в массиве аналогично uc_ar_do_rank_cfg

////////////////////////////////////////////////////////////////////////
//Описание  массива ранжирования команд источников ОТ
unsigned char uc_ar_trg_setPl_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//
unsigned char uc_ar_trg_setMn_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//

unsigned char uc_ar_trg_rstPl_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//
unsigned char uc_ar_trg_rstMn_rank_cfg[NUM_TRG*AMOUNT_BYTE_FOR_OEPRF];//
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
//Описание  массива ранжирования команд источников ОФ
//Перечень команд и их положение в массиве аналогично
////////////////////////////////////////////////////////////////////////
//Описание  массива ранжирования команд источников ОФ

//Источники Определяемых функций+
unsigned char uc_ar_df1_pl_rank_cfg[NUM_DEF_FUN*AMOUNT_BYTE_FOR_OEPRF];//Reserv memory for Table
////////////////////////////////////////////////////////////////////////
//Источники Определяемых функций1-
unsigned char   uc_ar_df1_mn_rank_cfg[NUM_DEF_FUN*AMOUNT_BYTE_FOR_OEPRF];//Reserv memory for Table
////////////////////////////////////////////////////////////////////////

//Источники блокировки Определяемых функций1
unsigned char   uc_ar_df1_blk_rank_cfg[NUM_DEF_FUN*AMOUNT_BYTE_FOR_OEPRF];//Reserv memory for Table
////////////////////////////////////////////////////////////////////////



//Описание условий для старта  дискретного регистратора
unsigned char    uc_ar_DReccfg[AMOUNT_BYTE_FOR_OEPRF];//Reserv memory for Table;

//Описание условий для старта  аналогового регистратора
//такое же как и для дискретного
unsigned char    uc_ar_AReccfg[AMOUNT_BYTE_FOR_OEPRF];//Reserv memory for Table;

//unsigned char    uc_Usyn_Isyn_selection;
//unsigned char    uc_Type_shon_selection;

char PckpStpm_store_selection;
//
//	MSB ...LSB
//	Группа8 	Группа1
//	0 - 1-я группа 
//	1 - 2-я группа
//  2 - 3-я группа
//  3 - 4-я группа <- corrected after discussion 10-07 -2015



//char PckpStpm_store_selector;//
#define AMOUNT_SERIES_PPSPM_SETTINGS 4 //Количество комплектов уставок

PckpStpmStoreDsc arPckpStpmStngStore[AMOUNT_SERIES_PPSPM_SETTINGS];
//PpSpm //Pickup&StageParam

unsigned char state_DstpDriftBlk;//БК ДЗ

//Неисправность цепей напряжения Дистанционной Защитв(для 5 ступеней)
unsigned char state_FaultU_Dstp;//
unsigned short Dstp_T_UI_NCN;//
unsigned short Dstp_T_NonSymMode_NCN;//
  
// Параметры Дистанционной защиты Описание и перечень см hve_df.h
//Управление Дистанционной защиты 
Dstp1MngStoreDsc ownrStg1Dstp1Mng;//1 ступень
Dstp2MngStoreDsc ownrStg2Dstp2Mng;//2 ступень
Dstp2MngStoreDsc ownrStg3Dstp2Mng;//3 ступень
Dstp2MngStoreDsc ownrStg4Dstp2Mng;//4 ступень
Dstp2MngStoreDsc ownrStg5Dstp2Mng;//5 ступень



//Неисправность цепей напряжения (для 5 ступеней)
unsigned char state_FaultU_Ocp;//
//Управление МТЗ
DrOcp1MngStoreDsc    ownrStg1DrOcp1Mng;//1 ступень
DrOcp2MngStoreDsc    ownrStg2DrOcp2Mng;//2 ступень
DrOcp2MngStoreDsc    ownrStg3DrOcp2Mng;//3 ступень
DrOcp2MngStoreDsc    ownrStg4DrOcp2Mng;//4 ступень
DrOcp2MngStoreDsc    ownrStg5DrOcp2Mng;//5 ступень

//Управление ТЗНП
DrErthMngStoreDsc    ownrStg1DrErthMng;//1 ступень
DrErthMngStoreDsc    ownrStg2DrErthMng;//2 ступень
DrErthMngStoreDsc    ownrStg3DrErthMng;//3 ступень
DrErthMngStoreDsc    ownrStg4DrErthMng;//4 ступень
DrErthMngStoreDsc    ownrStg5DrErthMng;//5  ступень
//Управление ЗОП
NspMngStoreDsc      ownrStg1NspMng;//1 ступень
NspMngStoreDsc      ownrStg2NspMng;//2 ступень

//Управление   ЗнМин
UminMngStoreDsc ownrStg1UminMng;//1 ступень 
UminMngStoreDsc ownrStg2UminMng;//2 ступень 
unsigned char state_SDEV_Phase_Umin; //Меню Состояние ПО фазные/линейные 
//Управление  ЗнМакс
UmaxMngStoreDsc ownrStg1UmaxMng;//  1 ступень ЗнМакс
UmaxMngStoreDsc ownrStgU2maxMng;//  2 ступень ЗнМакс
unsigned char state_SDEV_Phase_Umax; //Меню Состояние ПО фазные/линейные 

RclrMngStoreDsc   ownrRclrMng;//АПВ
BrfMngStoreDsc    ownrBrfMng; //УРОВ
BruDsc    ownrBru; //
//Управление выключателем
BruMngStoreDsc ownrBruMngStore;
BruStageParamStoreDsc ownrBruStageParamStore;
FLDsc     ownrFL;  //Определение места повреждения

TransformerMeasDsc ownrTr_Line;//Коэффициенты трансформации и тип линии

CalcHvpBrOnDsc ownrCalcHvpBrOn;   //Расчет ресурса высоковольтного выключателя 

CalcPwrDsc ownrCalcPwr;//Технический учет Электроэнергии
OFuncDsc   ownrOFunc;  //Опред. функции
OTrgDsc    ownrOTrg;   //Опр. триггеры
OLgcDsc    ownrOLgc;   //Расшир. логика

#define AMOUNT_BYTE_FOR_CFG_PRT   (((RESERV_CFG_PRT_ONB)>>3) +1) 
unsigned char  arUchCfgPrt[AMOUNT_BYTE_FOR_CFG_PRT ];//Активация в конфигурации защит
//перечень смотри ENMEpr_CfgPrt


}CfgTblDsc;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern AuxCfgTbl1Dsc AuxCfgTbl1;








/*



*/




















#endif 
