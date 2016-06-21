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
* File Name       : epr_f.h
* Description     : Definitions and structures for HVP projct
                    BM BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  05/05/14   Markovsky A       Creation
*----------------------------------------------------------------------------*/
/* -----------------------------------------------------------

       +----- (NEW | MODify | ADD | DELete)                                 
       |                                                                    
  No   |         When          Who                What                      
-----|--------|----------|--------------------|----------------------------------------------------| 
 000 | NEW    | __/__/__ |  Markovsky A       |  Creation                                          | 
-----|--------|----------|--------------------|------------------------------------------------    | 
 001 | ADD    | 02/05/16 |  Markovsky A       |   Insert this table                                                 | 
     |        |          |                    |                                                    | 
     | MODify |          |                    |                                                    | 
------------------------------------------------------------------------------------------------   | 
002  | MODify | 07/05/16 |  Markovsky A       |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    | 
------------------------------------------------------------------------------------------------   |  
003  | MODify | 01/09/16 |  Markovsky A       |                                                    |
     |        |          |                    |                                                    | 
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |	 
------------------------------------------------------------------------------------------------   | 
004  | MODify | 29/10/16 | Malinovsky T       |                                                    | 
     |        |          |                    |                                                    | 
     |        |          |                    |                                                    | 
------------------------------------------------------------------------------------------------   | 
 005 |Змінено |31/10/16  |Малиновський Т.     |                                                    | 
     |        |          |                    |                                                    | 
     |        |          |                    |                                                    | 
------------------------------------------------------------------------------------------------   | 	 
     |        |          |                    |                                                    | 
 006 | MODify | 07/11/16 | Markovsky A        |                                                    | 
     |        |          |                    |                                                    | 
     |        |          |                    |                                                    | 
------------------------------------------------------------------------------------------------   | 	 
     |        |          |                    |                                                    | 
 007 | MODify | 08/11/16 | Markovsky A        |                                                    | 
     |        |          |                    |                                                    | 
------------------------------------------------------------------------------------------------   | 	 
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |                                                                       
------------------------------------------------------------------------------------------------   | 	 
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
------------------------------------------------------------------------------------------------   | 	 
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
--------------------------------------------------------------------------------------------------           
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    |
     |        |          |                    |                                                    | 
                                                                                                   |

|---------------------------------------------------------------------------------------           
*/


#ifndef EPRF_h
#define EPRF_h
//==========================================================================
//---  Internal  Command  Constant Bit     -----------
//==========================================================================
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//--- Perechen' komand i ikh polozheniye v massive diskretnykh vkhodov
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
enum ENMEpr_f_In {
RESERV_000_IEPRF_ONB = 0,
RESERV_001_IEPRF_ONB,
HVSW_ON_DI_IEPRF_ONB                 ,// Вкл. ВВ от ДВ 
HVSW_OFF_DI_IEPRF_ONB                ,// Откл. ВВ 
CTRL_VKL_DI_IEPRF_ONB                ,// Контроль Вкл
CTRL_OTKL_DI_IEPRF_ONB               ,// Контроль Откл
RESET_SIGOUT_DI_IEPRF_ONB            ,// Сброс Реле	
RESET_LED_DI_IEPRF_ONB               ,// Сброс индикаци
BLOCK_SWITCHOVER_DI_IEPRF_ONB        ,// Блокировка включения ВВ
SWITCH_STATE_DI_IEPRF_ONB            ,// Положение ВВ (выключателя)
PERMIT_BLK_SW_MCP_DI_IEPRF_ONB       ,// Разблокировка включения ВВ

BLOCK_DSTP1_DI_IEPRF_ONB             ,// Блокировка Дист З1
BLOCK_DSTP2_DI_IEPRF_ONB             ,// Блокировка Дист З2
ACCLT_DSTP2_DI_IEPRF_ONB             ,//Оперативное ускорение Дист З2
BLOCK_ACCLT_DSTP2_DI_IEPRF_ONB       ,//Блокировка Опер ускор Дист З2

BLOCK_DSTP3_DI_IEPRF_ONB             ,// Блокировка Дист З3
ACCLT_DSTP3_DI_IEPRF_ONB             ,//Оперативное ускорение Дист З3
BLOCK_ACCLT_DSTP3_DI_IEPRF_ONB       ,//Блокировка Опер ускор Дист З3
BLOCK_DSTP4_DI_IEPRF_ONB             ,// Блокировка Дист З4
ACCLT_DSTP4_DI_IEPRF_ONB             ,//Оперативное ускорение Дист З4
BLOCK_ACCLT_DSTP4_DI_IEPRF_ONB       ,//Блокировка Опер ускор Дист З4
BLOCK_DSTP5_DI_IEPRF_ONB             ,// Блокировка Дист З5
ACCLT_DSTP5_DI_IEPRF_ONB             ,//Оперативное ускорение Дист З5
BLOCK_ACCLT_DSTP5_DI_IEPRF_ONB       ,//Блокировка Опер ускор Дист З5
SEC_GR_UST_DSTP_DI_IEPRF_ONB         ,// 2группа уставок ДистЗ


BLOCK_MCP1_DI_IEPRF_ONB              ,// Блокировка МТЗ1
BLOCK_MCP2_DI_IEPRF_ONB              ,// Блокировка МТЗ2
BLOCK_MCP3_DI_IEPRF_ONB              ,// Блокировка МТЗ3
BLOCK_MCP4_DI_IEPRF_ONB              ,// Блокировка МТЗ4
BLOCK_MCP5_DI_IEPRF_ONB              ,// Блокировка МТЗ5

ACCLT_MCP2_DI_IEPRF_ONB             ,//Оперативное ускорение МТЗ2   
BLOCK_ACCLT_MCP2_DI_IEPRF_ONB       ,//Блокировка Опер ускор МТЗ2
ACCLT_MCP3_DI_IEPRF_ONB             ,//Оперативное ускорение МТЗ3   
BLOCK_ACCLT_MCP3_DI_IEPRF_ONB       ,//Блокировка Опер ускор МТЗ3
ACCLT_MCP4_DI_IEPRF_ONB             ,//Оперативное ускорение МТЗ4   
BLOCK_ACCLT_MCP4_DI_IEPRF_ONB       ,//Блокировка Опер ускор МТЗ4
ACCLT_MCP5_DI_IEPRF_ONB             ,//Оперативное ускорение МТЗ5   
BLOCK_ACCLT_MCP5_DI_IEPRF_ONB       ,//Блокировка Опер ускор МТЗ5

//BLOCK_ACCLT_MCP2_DI_IEPRF_ONB        //

SEC_GR_UST_MCP_DI_IEPRF_ONB          ,//2группа уставок МТЗ

//BLOCK_NZZ_DI_IEPRF_ONB               //

START_AFU_DI_IEPRF_ONB               ,//Пуск АПВ от ДВ 
BLOCK_AFU_DI_IEPRF_ONB               ,//Блокировка АПВ ОТ ДВ

//BLOCK_ARCL_DI_IEPRF_ONB              //

BLOCK_UMIN1_DI_IEPRF_ONB             ,//Блокировка Umin1
START_UMIN1_DI_IEPRF_ONB             ,//Пуск Umin1
BLOCK_UMIN2_DI_IEPRF_ONB             ,//Блокировка Umin2
START_UMIN2_DI_IEPRF_ONB             ,//Пуск Umin2

BLOCK_TZNP1_DI_IEPRF_ONB             ,//Блокировка ТЗНП1
ACCLT_TZNP1_DI_IEPRF_ONB             ,//Оперативное ускорение ТЗНП1   
BLOCK_ACCLT_TZNP1_DI_IEPRF_ONB       ,//Блокировка Опер ускор ТЗНП1
BLOCK_TZNP2_DI_IEPRF_ONB             ,//Блокировка ТЗНП2
ACCLT_TZNP2_DI_IEPRF_ONB             ,//Оперативное ускорение ТЗНП2
BLOCK_ACCLT_TZNP2_DI_IEPRF_ONB       ,//Блокировка Опер ускор ТЗНП2
BLOCK_TZNP3_DI_IEPRF_ONB             ,//Блокировка ТЗНП3
ACCLT_TZNP3_DI_IEPRF_ONB             ,//Оперативное ускорение ТЗНП3
BLOCK_ACCLT_TZNP3_DI_IEPRF_ONB       ,//Блокировка Опер ускор ТЗНП3
BLOCK_TZNP4_DI_IEPRF_ONB             ,//Блокировка ТЗНП4
ACCLT_TZNP4_DI_IEPRF_ONB             ,//Оперативное ускорение ТЗНП4
BLOCK_ACCLT_TZNP4_DI_IEPRF_ONB       ,//Блокировка Опер ускор ТЗНП4

BLOCK_TZNP5_DI_IEPRF_ONB             ,//Блокировка ТЗНП5
ACCLT_TZNP5_DI_IEPRF_ONB             ,//Оперативное ускорение ТЗНП5
BLOCK_ACCLT_TZNP5_DI_IEPRF_ONB       ,//Блокировка Опер ускор ТЗНП5

BLOCK_ZOP1_DI_IEPRF_ONB              ,//Блокировка ЗОП1
BLOCK_ZOP2_DI_IEPRF_ONB              ,//Блокировка ЗОП2
SEC_GR_UST_ZOP_DI_IEPRF_ONB          ,//2группа уставок ЗОП

START_UROV_DI_IEPRF_ONB              ,//Пуск УРОВ

BLOCK_UMAX1_DI_IEPRF_ONB             ,//
BLOCK_UMAX2_DI_IEPRF_ONB             ,//

EDF01_DI_IEPRF_ONB                   ,// Вх Оф 01  
EDF02_DI_IEPRF_ONB                   ,// Вх Оф 02 
EDF03_DI_IEPRF_ONB                   ,// Вх Оф 03 
EDF04_DI_IEPRF_ONB                   ,// Вх Оф 04 
EDF05_DI_IEPRF_ONB                   ,// Вх Оф 05 
EDF06_DI_IEPRF_ONB                   ,// Вх Оф 06 
EDF07_DI_IEPRF_ONB                   ,// Вх Оф 07 
EDF08_DI_IEPRF_ONB                   ,// Вх Оф 08 
EDF09_DI_IEPRF_ONB                   ,// Вх Оф 09 
EDF10_DI_IEPRF_ONB                   ,// Вх Оф 10 
EDF11_DI_IEPRF_ONB                   ,// Вх Оф 11 
EDF12_DI_IEPRF_ONB                   ,// Вх Оф 12 
EDF13_DI_IEPRF_ONB                   ,// Вх Оф 13 
EDF14_DI_IEPRF_ONB                   ,// Вх Оф 14 
EDF15_DI_IEPRF_ONB                   ,// Вх Оф 15 
EDF16_DI_IEPRF_ONB                   ,// Вх Оф 16 

SET_OT1_DI_IEPRF_ONB                 ,//Вх Уст   От1 
RESET_OT1_DI_IEPRF_ONB               ,//Вх Сброс От1 
SET_OT2_DI_IEPRF_ONB                 ,//Вх   Уст От2   
RESET_OT2_DI_IEPRF_ONB               ,//Вх Сброс От2 
SET_OT3_DI_IEPRF_ONB                 ,//Вх   Уст От3   
RESET_OT3_DI_IEPRF_ONB               ,//Вх Сброс От3 
SET_OT4_DI_IEPRF_ONB                 ,//Вх   Уст От4   
RESET_OT4_DI_IEPRF_ONB               ,//Вх Сброс От4 

SET_OT5_DI_IEPRF_ONB                 ,//Вх Уст   От5 
RESET_OT5_DI_IEPRF_ONB               ,//Вх Сброс От5 
SET_OT6_DI_IEPRF_ONB                 ,//Вх Уст   От6   
RESET_OT6_DI_IEPRF_ONB               ,//Вх Сброс От6 
SET_OT7_DI_IEPRF_ONB                 ,//Вх   Уст От7   
RESET_OT7_DI_IEPRF_ONB               ,//Вх Сброс От7 
SET_OT8_DI_IEPRF_ONB                 ,//Вх   Уст От8   
RESET_OT8_DI_IEPRF_ONB               ,//Вх Сброс От8 

//STP_ZDZ_DI_IEPRF_ONB                 //













RESERV_MAX_IEPRF_ONB

};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ Perechen' komand i ikh polozheniye v massive diskretnykh vykhodov
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
enum ENMEpr_f_Out {
RESERV_000_OEPRF_ONB = 0,
RESERV_001_OEPRF_ONB,

HVSW_ON_DI_OEPRF_ONB                 ,// Вкл. ВВ от ДВ 
HVSW_OFF_DI_OEPRF_ONB                ,// Откл. ВВ 
CTRL_VKL_DI_OEPRF_ONB                ,// Контроль Вкл
CTRL_OTKL_DI_OEPRF_ONB               ,// Контроль Откл
RESET_SIGOUT_DI_OEPRF_ONB            ,// Сброс Реле	
RESET_LED_DI_OEPRF_ONB               ,// Сброс индикаци
BLOCK_SWITCHOVER_DI_OEPRF_ONB        ,// Блокировка включения ВВ
SWITCH_STATE_DI_OEPRF_ONB            ,// Положение ВВ (выключателя)
PERMIT_BLK_SW_MCP_DI_OEPRF_ONB       ,// Разблокировка включения ВВ


BLOCK_DSTP1_DI_OEPRF_ONB             ,// Блокировка Дист З1
BLOCK_DSTP2_DI_OEPRF_ONB             ,// Блокировка Дист З2
ACCLT_DSTP2_DI_OEPRF_ONB             ,//Оперативное ускорение Дист З2
ACCLT_DSTP2_EPI_OEPRF_ONB            ,//Телеускорение ускорение Дист З2 
BLOCK_ACCLT_DSTP2_DI_OEPRF_ONB       ,//Блокировка Опер ускор Дист З2

BLOCK_DSTP3_DI_OEPRF_ONB             ,// Блокировка Дист З3
ACCLT_DSTP3_DI_OEPRF_ONB             ,//Оперативное ускорение Дист З3
ACCLT_DSTP3_EPI_OEPRF_ONB            ,//Телеускорение ускорение Дист З3 
BLOCK_ACCLT_DSTP3_DI_OEPRF_ONB       ,//Блокировка Опер ускор Дист З3
BLOCK_DSTP4_DI_OEPRF_ONB             ,// Блокировка Дист З4
ACCLT_DSTP4_DI_OEPRF_ONB             ,//Оперативное ускорение Дист З4
ACCLT_DSTP4_EPI_OEPRF_ONB            ,//Телеускорение ускорение Дист З4 
BLOCK_ACCLT_DSTP4_DI_OEPRF_ONB       ,//Блокировка Опер ускор Дист З4
BLOCK_DSTP5_DI_OEPRF_ONB             ,// Блокировка Дист З5
ACCLT_DSTP5_DI_OEPRF_ONB             ,//Оперативное ускорение Дист З5
ACCLT_DSTP5_EPI_OEPRF_ONB            ,//Телеускорение ускорение Дист З5 EPI-external program Input
BLOCK_ACCLT_DSTP5_DI_OEPRF_ONB       ,//Блокировка Опер ускор Дист З5

SEC_GR_UST_DSTP_DI_OEPRF_ONB         ,// 2группа уставок ДистЗ


BLOCK_MCP1_DI_OEPRF_ONB              ,// Блокировка МТЗ1
BLOCK_MCP2_DI_OEPRF_ONB              ,// Блокировка МТЗ2
BLOCK_MCP3_DI_OEPRF_ONB              ,// Блокировка МТЗ3
BLOCK_MCP4_DI_OEPRF_ONB              ,// Блокировка МТЗ4
BLOCK_MCP5_DI_OEPRF_ONB              ,// Блокировка МТЗ5

ACCLT_MCP2_EPI_OEPRF_ONB            ,//Телеускорение   МТЗ2 
ACCLT_MCP2_DI_OEPRF_ONB             ,//Оперативное ускорение МТЗ2   
BLOCK_ACCLT_MCP2_DI_OEPRF_ONB       ,//Блокировка Опер ускор МТЗ2

ACCLT_MCP3_EPI_OEPRF_ONB            ,//Телеускорение   МТЗ3 
ACCLT_MCP3_DI_OEPRF_ONB             ,//Оперативное ускорение МТЗ3   
BLOCK_ACCLT_MCP3_DI_OEPRF_ONB       ,//Блокировка Опер ускор МТЗ3

ACCLT_MCP4_EPI_OEPRF_ONB            ,//Телеускорение   МТЗ4 
ACCLT_MCP4_DI_OEPRF_ONB             ,//Оперативное ускорение МТЗ4   
BLOCK_ACCLT_MCP4_DI_OEPRF_ONB       ,//Блокировка Опер ускор МТЗ4

ACCLT_MCP5_EPI_OEPRF_ONB            ,//Телеускорение   МТЗ5 
ACCLT_MCP5_DI_OEPRF_ONB             ,//Оперативное ускорение МТЗ5   
BLOCK_ACCLT_MCP5_DI_OEPRF_ONB       ,//Блокировка Опер ускор МТЗ5

//BLOCK_ACCLT_MCP2_DI_OEPRF_ONB        //

SEC_GR_UST_MCP_DI_OEPRF_ONB          ,//2группа уставок МТЗ

//BLOCK_NZZ_DI_OEPRF_ONB               //

START_AFU_DI_OEPRF_ONB               ,//Пуск АПВ от ДВ 
BLOCK_AFU_DI_OEPRF_ONB               ,//Блокировка АПВ ОТ ДВ

//BLOCK_ARCL_DI_OEPRF_ONB              //

BLOCK_UMIN1_DI_OEPRF_ONB             ,//Блокировка Umin1
START_UMIN1_DI_OEPRF_ONB             ,//Пуск Umin1
BLOCK_UMIN2_DI_OEPRF_ONB             ,//Блокировка Umin2
START_UMIN2_DI_OEPRF_ONB             ,//Пуск Umin2

BLOCK_TZNP1_DI_OEPRF_ONB             ,//Блокировка ТЗНП1
ACCLT_TZNP1_DI_OEPRF_ONB             ,//Оперативное ускорение ТЗНП1   
BLOCK_ACCLT_TZNP1_DI_OEPRF_ONB       ,//Блокировка Опер ускор ТЗНП1
BLOCK_TZNP2_DI_OEPRF_ONB             ,//Блокировка ТЗНП2
ACCLT_TZNP2_DI_OEPRF_ONB             ,//Оперативное ускорение ТЗНП2
BLOCK_ACCLT_TZNP2_DI_OEPRF_ONB       ,//Блокировка Опер ускор ТЗНП2
BLOCK_TZNP3_DI_OEPRF_ONB             ,//Блокировка ТЗНП3
ACCLT_TZNP3_DI_OEPRF_ONB             ,//Оперативное ускорение ТЗНП3
BLOCK_ACCLT_TZNP3_DI_OEPRF_ONB       ,//Блокировка Опер ускор ТЗНП3
BLOCK_TZNP4_DI_OEPRF_ONB             ,//Блокировка ТЗНП4
ACCLT_TZNP4_DI_OEPRF_ONB             ,//Оперативное ускорение ТЗНП4
BLOCK_ACCLT_TZNP4_DI_OEPRF_ONB       ,//Блокировка Опер ускор ТЗНП4

BLOCK_TZNP5_DI_OEPRF_ONB             ,//Блокировка ТЗНП5
ACCLT_TZNP5_DI_OEPRF_ONB             ,//Оперативное ускорение ТЗНП5
BLOCK_ACCLT_TZNP5_DI_OEPRF_ONB       ,//Блокировка Опер ускор ТЗНП5

ACCLT_TZNP1_EPI_OEPRF_ONB            ,//Телеускорение   ТЗНП1 
ACCLT_TZNP2_EPI_OEPRF_ONB            ,//Телеускорение   ТЗНП2 
ACCLT_TZNP3_EPI_OEPRF_ONB            ,//Телеускорение   ТЗНП3 
ACCLT_TZNP4_EPI_OEPRF_ONB            ,//Телеускорение   ТЗНП4 
ACCLT_TZNP5_EPI_OEPRF_ONB            ,//Телеускорение   ТЗНП5 


BLOCK_ZOP1_DI_OEPRF_ONB              ,//Блокировка ЗОП1
BLOCK_ZOP2_DI_OEPRF_ONB              ,//Блокировка ЗОП2
SEC_GR_UST_ZOP_DI_OEPRF_ONB          ,//2группа уставок ЗОП

START_UROV_DI_OEPRF_ONB              ,//Пуск УРОВ

BLOCK_UMAX1_DI_OEPRF_ONB             ,//
BLOCK_UMAX2_DI_OEPRF_ONB             ,//

DRIVER_SW_DI_OEPRF_ONB               ,// Привод ВВ
FLT_U_DSTP_OEPRF_ONB                 ,// Неисправность цепйй напр ДистЗ

SW_OFF_CMDF_ONB                      ,//.Работа БО
SW_ON_CMDF_ONB                       ,//.Работа БВ

STPDEV_DSTP1_MF_OEPRF_ONB   ,// ПО ДЗ1 МФ
DSTP1_MF_OEPRF_ONB          ,// Cраб ДЗ1 МФ
STPDEV_MCP_DSTP1_OEPRF_ONB  ,// ПО МТЗ ДЗ1 
MCP_DSTP1_OEPRF_ONB         ,// Сраб МТЗ ДЗ1
STPDEV_DSTP1_OF_OEPRF_ONB   ,// ПО ДЗ1 ОФ
DSTP1_OF_OEPRF_ONB          ,// сраб ДЗ1 ОФ
                    
DSTP2_MF_OEPRF_ONB          ,// Cраб ДЗ2 МФ
STPDEV_DSTP2_MF_OEPRF_ONB   ,// ПО ДЗ2 МФ
MCP_DSTP2_OEPRF_ONB         ,// Сраб МТЗ ДЗ2
STPDEV_MCP_DSTP2_OEPRF_ONB  ,// ПО МТЗ ДЗ2
DSTP2_OF_OEPRF_ONB          ,// Сраб ДЗ2 ОФ
STPDEV_DSTP2_OF_OEPRF_ONB   ,// ПО ДЗ2 ОФ 
                    
DSTP3_MF_OEPRF_ONB            ,// Cраб ДЗ3 МФ
STPDEV_DSTP3_MF_OEPRF_ONB     ,// ПО ДЗ3 МФ
MCP_DSTP3_OEPRF_ONB           ,// Сраб МТЗ ДЗ3
STPDEV_MCP_DSTP3_OEPRF_ONB    ,// ПО МТЗ ДЗ3
DSTP3_OF_OEPRF_ONB            ,// Сраб ДЗ3 ОФ
STPDEV_DSTP3_OF_OEPRF_ONB     ,// ПО ДЗ3 ОФ 
                    
DSTP4_MF_OEPRF_ONB            ,// Cраб ДЗ4 МФ
STPDEV_DSTP4_MF_OEPRF_ONB     ,// ПО ДЗ4 МФ
MCP_DSTP4_OEPRF_ONB           ,// Сраб МТЗ ДЗ4
STPDEV_MCP_DSTP4_OEPRF_ONB    ,// ПО МТЗ ДЗ4
DSTP4_OF_OEPRF_ONB            ,// Сраб ДЗ4 ОФ
STPDEV_DSTP4_OF_OEPRF_ONB     ,// ПО ДЗ4 ОФ 
                    
DSTP5_MF_OEPRF_ONB            ,// Cраб ДЗ5 МФ
STPDEV_DSTP5_MF_OEPRF_ONB     ,// ПО ДЗ5 МФ
MCP_DSTP5_OEPRF_ONB           ,// Сраб МТЗ ДЗ5
STPDEV_MCP_DSTP5_OEPRF_ONB    ,// ПО МТЗ ДЗ5
DSTP5_OF_OEPRF_ONB            ,// Сраб ДЗ5 ОФ
STPDEV_DSTP5_OF_OEPRF_ONB     ,// ПО ДЗ5 ОФ 


STPDEV_SECTOR_MCP1_STAIGHT_OEPRF_ONB ,//Сектор МТЗН1Впер  //
STPDEV_SECTOR_MCP1_BACK_OEPRF_ONB    ,//Сектор МТЗН1Назад
STPDEV_MCP1_BORING_OEPRF_ONB         ,//Сраб ПО МТЗ1
STPDEV_MCP1_STAIGHT_OEPRF_ONB        ,//Сраб ПО МТЗН1Впер
STPDEV_MCP1_BACK_OEPRF_ONB           ,//Сраб ПО МТЗН1Назад
STPDEV_MCP1_VLT_OEPRF_ONB            ,//Сраб ПО МТЗ1ПН
MCP1_OEPRF_ONB                       ,//Сраб МТЗ1

STPDEV_SECTOR_MCP2_STAIGHT_OEPRF_ONB ,//Сектор МТЗН2Впер  //
STPDEV_SECTOR_MCP2_BACK_OEPRF_ONB    ,//Сектор МТЗН2Назад
STPDEV_MCP2_BORING_OEPRF_ONB         ,//Сраб ПО МТЗ2
STPDEV_MCP2_STAIGHT_OEPRF_ONB        ,//Сраб ПО МТЗН2Впер
STPDEV_MCP2_BACK_OEPRF_ONB           ,//Сраб ПО МТЗН2Назад
STPDEV_MCP2_VLT_OEPRF_ONB            ,//Сраб ПО МТЗ2ПН
MCP2_OEPRF_ONB                       ,//Сраб МТЗ2
 
STPDEV_SECTOR_MCP3_STAIGHT_OEPRF_ONB ,//Сектор МТЗН3Впер  //
STPDEV_SECTOR_MCP3_BACK_OEPRF_ONB    ,//Сектор МТЗН3Назад
STPDEV_MCP3_BORING_OEPRF_ONB         ,//Сраб ПО МТЗ3
STPDEV_MCP3_STAIGHT_OEPRF_ONB        ,//Сраб ПО МТЗН3Впер
STPDEV_MCP3_BACK_OEPRF_ONB           ,//Сраб ПО МТЗН3Назад
STPDEV_MCP3_VLT_OEPRF_ONB            ,//Сраб ПО МТЗ3ПН
MCP3_OEPRF_ONB                       ,//Сраб МТЗ3
 
STPDEV_SECTOR_MCP4_STAIGHT_OEPRF_ONB ,//Сектор МТЗН4Впер  //
STPDEV_SECTOR_MCP4_BACK_OEPRF_ONB    ,//Сектор МТЗН4Назад
STPDEV_MCP4_BORING_OEPRF_ONB         ,//Сраб ПО МТЗ4
STPDEV_MCP4_STAIGHT_OEPRF_ONB        ,//Сраб ПО МТЗН4Впер
STPDEV_MCP4_BACK_OEPRF_ONB           ,//Сраб ПО МТЗН4Назад
STPDEV_MCP4_VLT_OEPRF_ONB            ,//Сраб ПО МТЗ4ПН
MCP4_OEPRF_ONB                       ,//Сраб МТЗ4
 
STPDEV_SECTOR_MCP5_STAIGHT_OEPRF_ONB ,//Сектор МТЗН5Впер  //
STPDEV_SECTOR_MCP5_BACK_OEPRF_ONB    ,//Сектор МТЗН5Назад
STPDEV_MCP5_BORING_OEPRF_ONB         ,//Сраб ПО МТЗ5
STPDEV_MCP5_STAIGHT_OEPRF_ONB        ,//Сраб ПО МТЗН5Впер
STPDEV_MCP5_BACK_OEPRF_ONB           ,//Сраб ПО МТЗН5Назад
STPDEV_MCP5_VLT_OEPRF_ONB            ,//Сраб ПО МТЗ5ПН
MCP5_OEPRF_ONB                       ,//Сраб МТЗ5
 
 
STPDEV_SECTOR_TZNP1_OEPRF_ONB        ,//Сектор ТЗНП1
STPDEV_TZNP1_OEPRF_ONB               ,//Сраб ПО ТЗНП1
TZNP1_OEPRF_ONB                      ,//Сраб ТЗНП1
STPDEV_TZNP1_3U0_OEPRF_ONB           ,//ПО ЗНП1(3U0)
TZNP1__3U0_OEPRF_ONB                 ,//Сраб ЗНП1(3U0)
STPDEV_TZNP1_3I0_OEPRF_ONB           ,//ПО ЗНП1(3I0)
TZNP1_3I0_OEPRF_ONB                  ,//Сраб ЗНП1(3I0)

STPDEV_SECTOR_TZNP2_OEPRF_ONB        ,//Сектор ТЗНП2
STPDEV_TZNP2_OEPRF_ONB               ,//Сраб ПО ТЗНП2
TZNP2_OEPRF_ONB                      ,//Сраб ТЗНП2
STPDEV_TZNP2_3U0_OEPRF_ONB           ,//ПО ЗНП2(3U0)
TZNP2_3U0_OEPRF_ONB                  ,//Сраб ЗНП2(3U0)
STPDEV_TZNP2_3I0_OEPRF_ONB           ,//ПО ЗНП2(3I0)
TZNP2_3I0_OEPRF_ONB                  ,//Сраб ЗНП2(3I0)

STPDEV_SECTOR_TZNP3_OEPRF_ONB        ,//Сектор ТЗНП3
STPDEV_TZNP3_OEPRF_ONB               ,//Сраб ПО ТЗНП3
TZNP3_OEPRF_ONB                      ,//Сраб ТЗНП3
STPDEV_TZNP3_3U0_OEPRF_ONB           ,//ПО ЗНП3(3U0)
TZNP3_3U0_OEPRF_ONB                  ,//Сраб ЗНП3(3U0)
STPDEV_TZNP3_3I0_OEPRF_ONB           ,//ПО ЗНП3(3I0)
TZNP3_3I0_OEPRF_ONB                  ,//Сраб ЗНП3(3I0)

STPDEV_SECTOR_TZNP4_OEPRF_ONB        ,//Сектор ТЗНП4
STPDEV_TZNP4_OEPRF_ONB               ,//Сраб ПО ТЗНП4
TZNP4_OEPRF_ONB                      ,//Сраб ТЗНП4
STPDEV_TZNP4_3U0_OEPRF_ONB           ,//ПО ЗНП4(3U0)
TZNP4_3U0_OEPRF_ONB                  ,//Сраб ЗНП4(3U0)
STPDEV_TZNP4_3I0_OEPRF_ONB           ,//ПО ЗНП4(3I0)
TZNP4_3I0_OEPRF_ONB                  ,//Сраб ЗНП4(3I0)

STPDEV_SECTOR_TZNP5_OEPRF_ONB        ,//Сектор ТЗНП5
STPDEV_TZNP5_OEPRF_ONB               ,//Сраб ПО ТЗНП5
TZNP5_OEPRF_ONB                      ,//Сраб ТЗНП5
STPDEV_TZNP5_3U0_OEPRF_ONB           ,//ПО ЗНП5(3U0)
TZNP5_3U0_OEPRF_ONB                  ,//Сраб ЗНП5(3U0)
STPDEV_TZNP5_3I0_OEPRF_ONB           ,//ПО ЗНП5(3I0)
TZNP5_3I0_OEPRF_ONB                  ,//Сраб ЗНП5(3I0)

STPDEV_UMAX1_OEPRF_ONB               ,//Сраб ПО UMAX1
UMAX1_OEPRF_ONB                      ,//Сраб UMAX1
STPDEV_UMAX2_OEPRF_ONB               ,//Сраб ПО UMAX2
UMAX2_OEPRF_ONB                      ,//Сраб UMAX2

STPDEV_UMIN1_OEPRF_ONB               ,//Сраб ПО Umin1
UMIN1_OEPRF_ONB                      ,//Сраб Umin1
STPDEV_UMIN2_OEPRF_ONB               ,//Сраб ПО Umin2
UMIN2_OEPRF_ONB                      ,//Сраб Umin2

OVER_I_NOM_OFF_HSW_OEPRF_ONB         ,//Превышене номинального тока откл ВВ
LIMIT_OUT_HWS                        ,//Ресурс ВВ исчерпан
LIMIT_CRITICAL_HWS                   ,//Критический ресурс Вв

STPDEV_SECTOR_ZOP1_STAIGHT_OEPRF_ONB ,// //Сектор НЗОП1Впер  
STPDEV_SECTOR_ZOP1_BACK_OEPRF_ONB    ,//   Сектор НЗОП1Назад
STPDEV_ZOP1_BORING_OEPRF_ONB         ,//    ПО ЗОП1
STPDEV_ZOP1_STAIGHT_OEPRF_ONB        ,//    ПО НЗОП1Впер
STPDEV_ZOP1_BACK_OEPRF_ONB           ,//    ПО НЗОП1ННазад
ZOP1_OEPRF_ONB                       ,//   Сраб НЗОП1 
 
STPDEV_SECTOR_ZOP2_STAIGHT_OEPRF_ONB ,// //Сектор НЗОП2Впер  
STPDEV_SECTOR_ZOP2_BACK_OEPRF_ONB    ,//   Сектор НЗОП2Назад
STPDEV_ZOP2_BORING_OEPRF_ONB         ,//    ПО ЗОП2
STPDEV_ZOP2_STAIGHT_OEPRF_ONB        ,//    ПО НЗОП2Впер
STPDEV_ZOP2_BACK_OEPRF_ONB           ,//    ПО НЗОП2ННазад
ZOP2_OEPRF_ONB                       ,//   Сраб НЗОП2 
 
UROV1_OEPRF_ONB                      ,//  Сраб УРОВ1
UROV2_OEPRF_ONB                      ,//  Сраб УРОВ1


ARCL1_OEPRF_ONB                      ,//  АПВ1
ARCL2_OEPRF_ONB                      ,//  АПВ2

EDF01_OEPRF_ONB                      ,//Выход Оф_01  
EDF02_OEPRF_ONB                      ,//Выход Оф_02
EDF03_OEPRF_ONB                      ,//Выход Оф_03
EDF04_OEPRF_ONB                      ,//Выход Оф_04
EDF05_OEPRF_ONB                      ,//Выход Оф_05
EDF06_OEPRF_ONB                      ,//Выход Оф_06
EDF07_OEPRF_ONB                      ,//Выход Оф_07
EDF08_OEPRF_ONB                      ,//Выход Оф_08
EDF09_OEPRF_ONB                      ,//Выход Оф_09
EDF10_OEPRF_ONB                      ,//Выход Оф_10  
EDF11_OEPRF_ONB                      ,//Выход Оф_11
EDF12_OEPRF_ONB                      ,//Выход Оф_12
EDF13_OEPRF_ONB                      ,//Выход Оф_13
EDF14_OEPRF_ONB                      ,//Выход Оф_14
EDF15_OEPRF_ONB                      ,//Выход Оф_15
EDF16_OEPRF_ONB                      ,//Выход Оф_16


OUT_OT1_OEPRF_ONB                    ,//Выход ОТ1
OUT_OT2_OEPRF_ONB                    ,//Выход ОТ2
OUT_OT3_OEPRF_ONB                    ,//Выход ОТ3
OUT_OT4_OEPRF_ONB                    ,//Выход ОТ4
OUT_OT5_OEPRF_ONB                    ,//Выход ОТ5
OUT_OT6_OEPRF_ONB                    ,//Выход ОТ6
OUT_OT7_OEPRF_ONB                    ,//Выход ОТ7
OUT_OT8_OEPRF_ONB                    ,//Выход ОТ8 


RESERV_MAX_OEPRF_ONB

};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
enum ENMEpr_StpBrf { //UROV


DSTP1_STP_BRF_ONB                       ,//Сраб ДТЗ1
DSTP2_STP_BRF_ONB                       ,//Сраб ДТЗ2
DSTP3_STP_BRF_ONB                       ,//Сраб ДТЗ3
DSTP4_STP_BRF_ONB                       ,//Сраб ДТЗ4
DSTP5_STP_BRF_ONB                       ,//Сраб ДТЗ5

MCP1_DSTP1_STP_BRF_ONB                  ,//Сраб МТЗ1 ДТЗ1
MCP2_DSTP2_STP_BRF_ONB                  ,//Сраб МТЗ2 ДТЗ2
MCP3_DSTP3_STP_BRF_ONB                  ,//Сраб МТЗ3 ДТЗ3
MCP4_DSTP4_STP_BRF_ONB                  ,//Сраб МТЗ4 ДТЗ4
MCP5_DSTP5_STP_BRF_ONB                  ,//Сраб МТЗ5 ДТЗ5

MCP1_STP_BRF_ONB                       ,//Сраб МТЗ1
MCP2_STP_BRF_ONB                       ,//Сраб МТЗ2
MCP3_STP_BRF_ONB                       ,//Сраб МТЗ3
MCP4_STP_BRF_ONB                       ,//Сраб МТЗ4
MCP5_STP_BRF_ONB                       ,//Сраб МТЗ5

TZNP1_STP_BRF_ONB                      ,//Сраб ТЗНП1
TZNP1_3U0_STP_BRF_ONB                  ,//Сраб ЗНП1(3U0)
TZNP1_3I0_STP_BRF_ONB                  ,//Сраб ЗНП1(3I0)
TZNP2_STP_BRF_ONB                      ,//Сраб ТЗНП2
TZNP2_3U0_STP_BRF_ONB                  ,//Сраб ЗНП2(3U0)
TZNP2_3I0_STP_BRF_ONB                  ,//Сраб ЗНП2(3I0)
TZNP3_STP_BRF_ONB                      ,//Сраб ТЗНП3
TZNP3_3U0_STP_BRF_ONB                  ,//Сраб ЗНП3(3U0)
TZNP3_3I0_STP_BRF_ONB                  ,//Сраб ЗНП3(3I0)
TZNP4_STP_BRF_ONB                      ,//Сраб ТЗНП4
TZNP4_3U0_STP_BRF_ONB                  ,//Сраб ЗНП4(3U0)
TZNP4_3I0_STP_BRF_ONB                  ,//Сраб ЗНП4(3I0)
TZNP5_STP_BRF_ONB                      ,//Сраб ТЗНП5
TZNP5_3U0_STP_BRF_ONB                  ,//Сраб ЗНП5(3U0)
TZNP5_3I0_STP_BRF_ONB                  ,//Сраб ЗНП5(3I0)

UMAX1_STP_BRF_ONB                    ,//Сраб UMAX1
UMAX2_STP_BRF_ONB                    ,//Сраб UMAX2
UMIN1_STP_BRF_ONB                    ,//Сраб Umin1
UMIN2_STP_BRF_ONB                    ,//Сраб Umin2 
ZOP1_STP_BRF_ONB                       ,//   Сраб НЗОП1 
ZOP2_STP_BRF_ONB                       ,//   Сраб НЗОП2 


RESERV_MAX_STP_BRF_ONB

};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
enum ENMEpr_StpRclr { //АПВ


DSTP1_STP_RCLR_ONB                       ,//Сраб ДТЗ1
DSTP2_STP_RCLR_ONB                       ,//Сраб ДТЗ2
DSTP3_STP_RCLR_ONB                       ,//Сраб ДТЗ3
DSTP4_STP_RCLR_ONB                       ,//Сраб ДТЗ4
DSTP5_STP_RCLR_ONB                       ,//Сраб ДТЗ5

MCP1_DSTP1_STP_RCLR_ONB                  ,//Сраб МТЗ1 ДТЗ1
MCP2_DSTP2_STP_RCLR_ONB                  ,//Сраб МТЗ2 ДТЗ2
MCP3_DSTP3_STP_RCLR_ONB                  ,//Сраб МТЗ3 ДТЗ3
MCP4_DSTP4_STP_RCLR_ONB                  ,//Сраб МТЗ4 ДТЗ4
MCP5_DSTP5_STP_RCLR_ONB                  ,//Сраб МТЗ5 ДТЗ5

MCP1_STP_RCLR_ONB                       ,//Сраб МТЗ1
MCP2_STP_RCLR_ONB                       ,//Сраб МТЗ2
MCP3_STP_RCLR_ONB                       ,//Сраб МТЗ3
MCP4_STP_RCLR_ONB                       ,//Сраб МТЗ4
MCP5_STP_RCLR_ONB                       ,//Сраб МТЗ5

TZNP1_STP_RCLR_ONB                      ,//Сраб ТЗНП1
TZNP1_3U0_STP_RCLR_ONB                  ,//Сраб ЗНП1(3U0)
TZNP1_3I0_STP_RCLR_ONB                  ,//Сраб ЗНП1(3I0)
TZNP2_STP_RCLR_ONB                      ,//Сраб ТЗНП2
TZNP2_3U0_STP_RCLR_ONB                  ,//Сраб ЗНП2(3U0)
TZNP2_3I0_STP_RCLR_ONB                  ,//Сраб ЗНП2(3I0)
TZNP3_STP_RCLR_ONB                      ,//Сраб ТЗНП3
TZNP3_3U0_STP_RCLR_ONB                  ,//Сраб ЗНП3(3U0)
TZNP3_3I0_STP_RCLR_ONB                  ,//Сраб ЗНП3(3I0)
TZNP4_STP_RCLR_ONB                      ,//Сраб ТЗНП4
TZNP4_3U0_STP_RCLR_ONB                  ,//Сраб ЗНП4(3U0)
TZNP4_3I0_STP_RCLR_ONB                  ,//Сраб ЗНП4(3I0)
TZNP5_STP_RCLR_ONB                      ,//Сраб ТЗНП5
TZNP5_3U0_STP_RCLR_ONB                  ,//Сраб ЗНП5(3U0)
TZNP5_3I0_STP_RCLR_ONB                  ,//Сраб ЗНП5(3I0)

UMAX1_STP_RCLR_ONB                    ,//Сраб UMAX1
UMAX2_STP_RCLR_ONB                    ,//Сраб UMAX2
UMIN1_STP_RCLR_ONB                    ,//Сраб Umin1
UMIN2_STP_RCLR_ONB                    ,//Сраб Umin2 
ZOP1_STP_RCLR_ONB                       ,//   Сраб НЗОП1 
ZOP2_STP_RCLR_ONB                       ,//   Сраб НЗОП2 


RESERV_MAX_STP_RCLR_ONB

};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ Aktivatsiya v konfiguratsii zashchit
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
enum ENMEpr_CfgPrt {

DSTP_CFG_PRT_ONB,
DROCP_CFG_PRT_ONB,
DRERTH_CFG_PRT_ONB,
NSP_CFG_PRT_ONB,
UMIN_CFG_PRT_ONB,
UMAX_CFG_PRT_ONB,
RCLR_CFG_PRT_ONB,
BRF_CFG_PRT_ONB,

RESERV_CFG_PRT_ONB

};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ perechen' komand ranzhirovaniya funktsional'nykh knopok
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
enum ENMEpr_F_Key_f {

HVSW_ON_DI_F_EPRF_ONB                 ,// Вкл. ВВ 
HVSW_OFF_DI_F_EPRF_ONB                ,// Откл. ВВ 
RESET_SIGOUT_DI_F_EPRF_ONB            ,// Сброс Реле
RESET_LED_DI_F_EPRF_ONB               ,// Сброс индикаци

EDF01_DI_F_EPRF_ONB                   ,// Вх Оф 01  
EDF02_DI_F_EPRF_ONB                   ,// Вх Оф 02 
EDF03_DI_F_EPRF_ONB                   ,// Вх Оф 03 
EDF04_DI_F_EPRF_ONB                   ,// Вх Оф 04 
EDF05_DI_F_EPRF_ONB                   ,// Вх Оф 05 
EDF06_DI_F_EPRF_ONB                   ,// Вх Оф 06 
EDF07_DI_F_EPRF_ONB                   ,// Вх Оф 07 
EDF08_DI_F_EPRF_ONB                   ,// Вх Оф 08 
EDF09_DI_F_EPRF_ONB                   ,// Вх Оф 09 
EDF10_DI_F_EPRF_ONB                   ,// Вх Оф 10 
EDF11_DI_F_EPRF_ONB                   ,// Вх Оф 11 
EDF12_DI_F_EPRF_ONB                   ,// Вх Оф 12 
EDF13_DI_F_EPRF_ONB                   ,// Вх Оф 13 
EDF14_DI_F_EPRF_ONB                   ,// Вх Оф 14 
EDF15_DI_F_EPRF_ONB                   ,// Вх Оф 15 
EDF16_DI_F_EPRF_ONB                   ,// Вх Оф 16 

SET_OT1_DI_F_EPRF_ONB                 ,//Вх Уст   От1 
RESET_OT1_DI_F_EPRF_ONB               ,//Вх Сброс От1 
SET_OT2_DI_F_EPRF_ONB                 ,//Вх   Уст От2   
RESET_OT2_DI_F_EPRF_ONB               ,//Вх Сброс От2 
SET_OT3_DI_F_EPRF_ONB                 ,//Вх   Уст От3   
RESET_OT3_DI_F_EPRF_ONB               ,//Вх Сброс От3 
SET_OT4_DI_F_EPRF_ONB                 ,//Вх   Уст От4   
RESET_OT4_DI_F_EPRF_ONB               ,//Вх Сброс От4 
SET_OT5_DI_F_EPRF_ONB                 ,//Вх Уст   От5 
RESET_OT5_DI_F_EPRF_ONB               ,//Вх Сброс От5 
SET_OT6_DI_F_EPRF_ONB                 ,//Вх Уст   От6   
RESET_OT6_DI_F_EPRF_ONB               ,//Вх Сброс От6 
SET_OT7_DI_F_EPRF_ONB                 ,//Вх   Уст От7   
RESET_OT7_DI_F_EPRF_ONB               ,//Вх Сброс От7 
SET_OT8_DI_F_EPRF_ONB                 ,//Вх   Уст От8   
RESET_OT8_DI_F_EPRF_ONB               ,//Вх Сброс От8 

//RESET_HCB_MNU_CMD_ONB,

RESERV_MAX_F_EPRF_ONB



};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ perechen' komand ranzhirovaniya funktsional'nykh knopok+menu
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
enum ENMEpr_F_Key_Mnu_f {

HVSW_ON_DI_F_CMD_ONB                 ,// Вкл. ВВ 
HVSW_OFF_DI_F_CMD_ONB                ,// Откл. ВВ 
RESET_SIGOUT_DI_F_CMD_ONB            ,// Сброс Реле
RESET_LED_DI_F_CMD_ONB               ,// Сброс индикаци

EDF01_DI_F_CMD_ONB                   ,// Вх Оф 01  
EDF02_DI_F_CMD_ONB                   ,// Вх Оф 02 
EDF03_DI_F_CMD_ONB                   ,// Вх Оф 03 
EDF04_DI_F_CMD_ONB                   ,// Вх Оф 04 
EDF05_DI_F_CMD_ONB                   ,// Вх Оф 05 
EDF06_DI_F_CMD_ONB                   ,// Вх Оф 06 
EDF07_DI_F_CMD_ONB                   ,// Вх Оф 07 
EDF08_DI_F_CMD_ONB                   ,// Вх Оф 08 
EDF09_DI_F_CMD_ONB                   ,// Вх Оф 09 
EDF10_DI_F_CMD_ONB                   ,// Вх Оф 10 
EDF11_DI_F_CMD_ONB                   ,// Вх Оф 11 
EDF12_DI_F_CMD_ONB                   ,// Вх Оф 12 
EDF13_DI_F_CMD_ONB                   ,// Вх Оф 13 
EDF14_DI_F_CMD_ONB                   ,// Вх Оф 14 
EDF15_DI_F_CMD_ONB                   ,// Вх Оф 15 
EDF16_DI_F_CMD_ONB                   ,// Вх Оф 16 

SET_OT1_DI_F_CMD_ONB                 ,//Вх Уст   От1 
RESET_OT1_DI_F_CMD_ONB               ,//Вх Сброс От1 
SET_OT2_DI_F_CMD_ONB                 ,//Вх   Уст От2   
RESET_OT2_DI_F_CMD_ONB               ,//Вх Сброс От2 
SET_OT3_DI_F_CMD_ONB                 ,//Вх   Уст От3   
RESET_OT3_DI_F_CMD_ONB               ,//Вх Сброс От3 
SET_OT4_DI_F_CMD_ONB                 ,//Вх   Уст От4   
RESET_OT4_DI_F_CMD_ONB               ,//Вх Сброс От4 
SET_OT5_DI_F_CMD_ONB                 ,//Вх Уст   От5 
RESET_OT5_DI_F_CMD_ONB               ,//Вх Сброс От5 
SET_OT6_DI_F_CMD_ONB                 ,//Вх Уст   От6   
RESET_OT6_DI_F_CMD_ONB               ,//Вх Сброс От6 
SET_OT7_DI_F_CMD_ONB                 ,//Вх   Уст От7   
RESET_OT7_DI_F_CMD_ONB               ,//Вх Сброс От7 
SET_OT8_DI_F_CMD_ONB                 ,//Вх   Уст От8   
RESET_OT8_DI_F_CMD_ONB               ,//Вх Сброс От8 

RESET_HCB_MNU_CMD_ONB,

RESERV_MAX_F_CMD_ONB



};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""






/*
Вкл. ВВ от ДВ 
Откл. ВВ 
Контроль Вкл
Контроль Откл
Сброс Реле	
Сброс индикации
Блокировка включения ВВ
Положение ВВ (выключателя)

Блокировка МТЗ1
Блокировка МТЗ2
Блокировка МТЗ3
Блокировка МТЗ4
Блокировка МТЗ5

Блокировка ТЗНП1
Оперативное ускорение ТЗНП1
Блокировка ускорения  ТЗНП1

Блокировка ТЗНП2
Оперативное ускорение ТЗНП2
Блокировка ускорения  ТЗНП2

Оперативное ускорение ТЗНП3
Блокировка ускорения  ТЗНП3
Блокировка ТЗНП3

Оперативное ускорение ТЗНП4
Блокировка ускорения  ТЗНП4
Блокировка ТЗНП4

Оперативное ускорение ТЗНП5
Блокировка ускорения  ТЗНП5
Блокировка ТЗНП5

Блокировка UMAX1
Блокировка UMAX2

Блокировка Umin1
Пуск Umin1
Блокировка Umin2
Пуск Umin2
Блокировка ЗОП1
Блокировка ЗОП2

Пуск АПВ
Блокировка АПВ


Вкл. ВВ от ДВ 
Откл. ВВ 
Контроль Вкл
Контроль Откл
Сброс Реле	
Сброс индикации
Блокировка включения ВВБлокировка МТЗ1
Положение ВВ (выключателя)2группа уставок МТЗ

Привод ВВ

Блокировка МТЗ1
Блокировка МТЗ2
Блокировка МТЗ3
Блокировка МТЗ4
Блокировка МТЗ5

Блокировка ТЗНП1
Блокировка ТЗНП2
Блокировка ТЗНП3











Сектор МТЗН1Впер  
Сектор МТЗН1Назад
Сраб ПО МТЗ1
Сраб ПО МТЗН1Впер
Сраб ПО МТЗН1Назад
Сраб ПО МТЗ1ПН
Сраб МТЗ1





Сектор МТЗН2Впер  
Сектор МТЗН2Назад
Сраб ПО МТЗ2
Сраб ПО МТЗН2Впер
Сраб ПО МТЗН2Назад
Сраб ПО МТЗ2ПН
Сраб МТЗ2

Сектор МТЗН3Впер  
Сектор МТЗН3Назад
Сраб ПО МТЗ3
Сраб ПО МТЗН3Впер
Сраб ПО МТЗН3Назад
Сраб ПО МТЗ3ПН
Сраб МТЗ3

Сектор МТЗН4Впер  
Сектор МТЗН4Назад
Сраб ПО МТЗ4
Сраб ПО МТЗН4Впер
Сраб ПО МТЗН4Назад
Сраб ПО МТЗ4ПН
Сраб МТЗ4

Сектор МТЗН5Впер  
Сектор МТЗН5Назад
Сраб ПО МТЗ5
Сраб ПО МТЗН5Впер
Сраб ПО МТЗН5Назад
Сраб ПО МТЗ5ПН
Сраб МТЗ5

Сектор ТЗНП1
Сраб ПО ТЗНП1
Сраб ТЗНП1
ПО ЗНП1(3U0)
Сраб ЗНП1(3U0)
ПО ЗНП1(3I0)
Сраб ЗНП1(3I0)


Сектор ТЗНП2
Сраб ПО ТЗНП2
Сраб ТЗНП2
ПО ЗНП2(3U0)
Сраб ЗНП2(3U0)
ПО ЗНП2(3I0)
Сраб ЗНП2(3I0)


Сектор ТЗНП3
Сраб ПО ТЗНП3
Сраб ТЗНП3
ПО ЗНП3(3U0)
Сраб ЗНП3(3U0)
ПО ЗНП3(3I0)
Сраб ЗНП3(3I0)


Сектор ТЗНП4
Сраб ПО ТЗНП4
Сраб ТЗНП4
ПО ЗНП4(3U0)
Сраб ЗНП4(3U0)
ПО ЗНП4(3I0)
Сраб ЗНП4(3I0)


Сектор ТЗНП5
Сраб ПО ТЗНП5
Сраб ТЗНП5
ПО ЗНП5(3U0)
Сраб ЗНП5(3U0)
ПО ЗНП5(3I0)
Сраб ЗНП5(3I0)

Сраб ПО UMAX1
Сраб UMAX1
Сраб ПО UMAX2
Сраб UMAX2

Сраб ПО Umin1
Сраб Umin1
Сраб ПО Umin2
Сраб Umin2

Превышене номинального тока откл ВВ
Ресурс ВВ исчерпан
Критический ресурс Вв

Сектор НЗОП1Впер  
Сектор НЗОП1Назад
 ПО ЗОП1
 ПО НЗОП1Впер
 ПО НЗОП1ННазад
Сраб НЗОП1
Сектор НЗОП2Впер  
Сектор НЗОП2Назад
 ПО ЗОП2
 ПО НЗОП2Впер
 ПО НЗОП2ННазад
Сраб НЗОП2

Сраб УРОВ1
Сраб УРОВ1


 АПВ1
 АПВ2



Выход Оф_01  
Выход Оф_02
Выход Оф_03
Выход Оф_04
Выход Оф_05
Выход Оф_06
Выход Оф_07
Выход Оф_08
Выход Оф_09  
Выход Оф_10
Выход Оф_11
Выход Оф_12
Выход Оф_13
Выход Оф_14
Выход Оф_15
Выход Оф_16

Выход ОТ1
Выход ОТ2
Выход ОТ3
Выход ОТ4
Выход ОТ5
Выход ОТ6
Выход ОТ7
Выход ОТ8



owner possessor keeper





Работа БО
Работа БВ



*/



#endif 
