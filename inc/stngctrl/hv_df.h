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
* File Name       : hvp_df.h
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

#define NUM_KEY 4
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define NUM_DEF_FUN 16
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

#define NUM_DEF_TRG 4
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

#include "hvp_df.h"
#include "hve_df.h"
#include "cmd_f.h" //Command function
#include "lgr_f.h" //Logger function
#include "cfg_f.h" //configuration function
#include "atrs_f.h"//Activators function
#include "tst_f.h" //Test Self control Bits

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
#define AMOUNT_SERIES_DSTP_SETTINGS 5 //Количество комплектов уставок
// Параметры Дистанционной защиты Описание и перечень см hve_df.h
DstpDsc ownrDstp1;
DstpDsc ownrDstp2;
DstpDsc ownrDstp3;
DstpDsc ownrDstp4;
DstpDsc ownrDstp5;

DstpStngStoreDsc arDstpStngStore[AMOUNT_SERIES_DSTP_SETTINGS];

//Неисправность цепей напряжения (для 5 ступеней)
unsigned char state_FaultU;//

unsigned char select_g2;//меню  2-я группа уставок МТЗ
//.	Состояние
//.	1 -вкл
//.	0 - выкл



}CfgTblDsc;
//~~~   
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""










/*



*/




















#endif 