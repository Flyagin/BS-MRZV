
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
* File Name       : atrcmd.h
* Description     : support for the atrcmd.c
                    BR BS

*  Version        : 1.00
*
*       +----- (NEW | MODify | ADD | DELete)
*       |
*  No   |   When       Who                What
*-----+---+----------+------------------+--------------------------------------
* 000  NEW  26/06/15   Markovsky A       Creation
*----------------------------------------------------------------------------*/

#ifndef ATR_CMD_h
#define ATR_CMD_h

#ifndef BS_ATR_CMD
#define  BS_ATR_CMD
enum ENMAtrf_Out {
RESERV_000_ATRFG_ONB = 0,
RESERV_001_ATRFG_ONB,

HVSW_ON_DI_ATRFG_ONB                 ,// Вкл. ВВ от ДВ 
HVSW_OFF_DI_ATRFG_ONB                ,// Откл. ВВ 
CTRL_VKL_DI_ATRFG_ONB                ,// Контроль Вкл
CTRL_OTKL_DI_ATRFG_ONB               ,// Контроль Откл
RESET_SIGOUT_DI_ATRFG_ONB            ,// Сброс Реле	
RESET_LED_DI_ATRFG_ONB               ,// Сброс индикаци
BLOCK_SWITCHOVER_DI_ATRFG_ONB        ,// Блокировка включения ВВ
SWITCH_STATE_DI_ATRFG_ONB            ,// Положение ВВ (выключателя)
PERMIT_BLK_SW_MCP_DI_ATRFG_ONB       ,// Разблокировка включения ВВ


BLOCK_DSTP1_DI_ATRFG_ONB             ,// Блокировка Дист З1
BLOCK_DSTP2_DI_ATRFG_ONB             ,// Блокировка Дист З2
ACCLT_DSTP2_DI_ATRFG_ONB             ,//Оперативное ускорение Дист З2
ACCLT_DSTP2_EPI_ATRFG_ONB            ,//Телеускорение ускорение Дист З2 
BLOCK_ACCLT_DSTP2_DI_ATRFG_ONB       ,//Блокировка Опер ускор Дист З2

BLOCK_DSTP3_DI_ATRFG_ONB             ,// Блокировка Дист З3
ACCLT_DSTP3_DI_ATRFG_ONB             ,//Оперативное ускорение Дист З3
ACCLT_DSTP3_EPI_ATRFG_ONB            ,//Телеускорение ускорение Дист З3 
BLOCK_ACCLT_DSTP3_DI_ATRFG_ONB       ,//Блокировка Опер ускор Дист З3
BLOCK_DSTP4_DI_ATRFG_ONB             ,// Блокировка Дист З4
ACCLT_DSTP4_DI_ATRFG_ONB             ,//Оперативное ускорение Дист З4
ACCLT_DSTP4_EPI_ATRFG_ONB            ,//Телеускорение ускорение Дист З4 
BLOCK_ACCLT_DSTP4_DI_ATRFG_ONB       ,//Блокировка Опер ускор Дист З4
BLOCK_DSTP5_DI_ATRFG_ONB             ,// Блокировка Дист З5
ACCLT_DSTP5_DI_ATRFG_ONB             ,//Оперативное ускорение Дист З5
ACCLT_DSTP5_EPI_ATRFG_ONB            ,//Телеускорение ускорение Дист З5 EPI-external program Input
BLOCK_ACCLT_DSTP5_DI_ATRFG_ONB       ,//Блокировка Опер ускор Дист З5

SEC_GR_UST_DSTP_DI_ATRFG_ONB         ,// 2группа уставок ДистЗ


BLOCK_MCP1_DI_ATRFG_ONB              ,// Блокировка МТЗ1
BLOCK_MCP2_DI_ATRFG_ONB              ,// Блокировка МТЗ2
BLOCK_MCP3_DI_ATRFG_ONB              ,// Блокировка МТЗ3
BLOCK_MCP4_DI_ATRFG_ONB              ,// Блокировка МТЗ4
BLOCK_MCP5_DI_ATRFG_ONB              ,// Блокировка МТЗ5

ACCLT_MCP2_EPI_ATRFG_ONB            ,//Телеускорение   МТЗ2 
ACCLT_MCP2_DI_ATRFG_ONB             ,//Оперативное ускорение МТЗ2   
BLOCK_ACCLT_MCP2_DI_ATRFG_ONB       ,//Блокировка Опер ускор МТЗ2

ACCLT_MCP3_EPI_ATRFG_ONB            ,//Телеускорение   МТЗ3 
ACCLT_MCP3_DI_ATRFG_ONB             ,//Оперативное ускорение МТЗ3   
BLOCK_ACCLT_MCP3_DI_ATRFG_ONB       ,//Блокировка Опер ускор МТЗ3

ACCLT_MCP4_EPI_ATRFG_ONB            ,//Телеускорение   МТЗ4 
ACCLT_MCP4_DI_ATRFG_ONB             ,//Оперативное ускорение МТЗ4   
BLOCK_ACCLT_MCP4_DI_ATRFG_ONB       ,//Блокировка Опер ускор МТЗ4

ACCLT_MCP5_EPI_ATRFG_ONB            ,//Телеускорение   МТЗ5 
ACCLT_MCP5_DI_ATRFG_ONB             ,//Оперативное ускорение МТЗ5   
BLOCK_ACCLT_MCP5_DI_ATRFG_ONB       ,//Блокировка Опер ускор МТЗ5

//BLOCK_ACCLT_MCP2_DI_ATRFG_ONB        //

SEC_GR_UST_MCP_DI_ATRFG_ONB          ,//2группа уставок МТЗ

//BLOCK_NZZ_DI_ATRFG_ONB               //

START_AFU_DI_ATRFG_ONB               ,//Пуск АПВ от ДВ 
BLOCK_AFU_DI_ATRFG_ONB               ,//Блокировка АПВ ОТ ДВ

//BLOCK_ARCL_DI_ATRFG_ONB              //

BLOCK_UMIN1_DI_ATRFG_ONB             ,//Блокировка Umin1
START_UMIN1_DI_ATRFG_ONB             ,//Пуск Umin1
BLOCK_UMIN2_DI_ATRFG_ONB             ,//Блокировка Umin2
START_UMIN2_DI_ATRFG_ONB             ,//Пуск Umin2

BLOCK_TZNP1_DI_ATRFG_ONB             ,//Блокировка ТЗНП1
ACCLT_TZNP1_DI_ATRFG_ONB             ,//Оперативное ускорение ТЗНП1   
BLOCK_ACCLT_TZNP1_DI_ATRFG_ONB       ,//Блокировка Опер ускор ТЗНП1
BLOCK_TZNP2_DI_ATRFG_ONB             ,//Блокировка ТЗНП2
ACCLT_TZNP2_DI_ATRFG_ONB             ,//Оперативное ускорение ТЗНП2
BLOCK_ACCLT_TZNP2_DI_ATRFG_ONB       ,//Блокировка Опер ускор ТЗНП2
BLOCK_TZNP3_DI_ATRFG_ONB             ,//Блокировка ТЗНП3
ACCLT_TZNP3_DI_ATRFG_ONB             ,//Оперативное ускорение ТЗНП3
BLOCK_ACCLT_TZNP3_DI_ATRFG_ONB       ,//Блокировка Опер ускор ТЗНП3
BLOCK_TZNP4_DI_ATRFG_ONB             ,//Блокировка ТЗНП4
ACCLT_TZNP4_DI_ATRFG_ONB             ,//Оперативное ускорение ТЗНП4
BLOCK_ACCLT_TZNP4_DI_ATRFG_ONB       ,//Блокировка Опер ускор ТЗНП4

BLOCK_TZNP5_DI_ATRFG_ONB             ,//Блокировка ТЗНП5
ACCLT_TZNP5_DI_ATRFG_ONB             ,//Оперативное ускорение ТЗНП5
BLOCK_ACCLT_TZNP5_DI_ATRFG_ONB       ,//Блокировка Опер ускор ТЗНП5

ACCLT_TZNP1_EPI_ATRFG_ONB            ,//Телеускорение   ТЗНП1 
ACCLT_TZNP2_EPI_ATRFG_ONB            ,//Телеускорение   ТЗНП2 
ACCLT_TZNP3_EPI_ATRFG_ONB            ,//Телеускорение   ТЗНП3 
ACCLT_TZNP4_EPI_ATRFG_ONB            ,//Телеускорение   ТЗНП4 
ACCLT_TZNP5_EPI_ATRFG_ONB            ,//Телеускорение   ТЗНП5 


BLOCK_ZOP1_DI_ATRFG_ONB              ,//Блокировка ЗОП1
BLOCK_ZOP2_DI_ATRFG_ONB              ,//Блокировка ЗОП2
SEC_GR_UST_ZOP_DI_ATRFG_ONB          ,//2группа уставок ЗОП

START_UROV_DI_ATRFG_ONB              ,//Пуск УРОВ

BLOCK_UMAX1_DI_ATRFG_ONB             ,//
BLOCK_UMAX2_DI_ATRFG_ONB             ,//

DRIVER_SW_DI_ATRFG_ONB               ,// Привод ВВ
FLT_U_DSTP_ATRFG_ONB                 ,// Неисправность цепйй напр ДистЗ

SW_OFF_ATRFG_ONB                      ,//.Работа БО
SW_ON_ATRFG_ONB                       ,//.Работа БВ

STPDEV_DSTP1_MF_ATRFG_ONB   ,// ПО ДЗ1 МФ
DSTP1_MF_ATRFG_ONB          ,// Cраб ДЗ1 МФ
STPDEV_MCP_DSTP1_ATRFG_ONB  ,// ПО МТЗ ДЗ1 
MCP_DSTP1_ATRFG_ONB         ,// Сраб МТЗ ДЗ1
STPDEV_DSTP1_OF_ATRFG_ONB   ,// ПО ДЗ1 ОФ
DSTP1_OF_ATRFG_ONB          ,// сраб ДЗ1 ОФ
                    
DSTP2_MF_ATRFG_ONB          ,// Cраб ДЗ2 МФ
STPDEV_DSTP2_MF_ATRFG_ONB   ,// ПО ДЗ2 МФ
MCP_DSTP2_ATRFG_ONB         ,// Сраб МТЗ ДЗ2
STPDEV_MCP_DSTP2_ATRFG_ONB  ,// ПО МТЗ ДЗ2
DSTP2_OF_ATRFG_ONB          ,// Сраб ДЗ2 ОФ
STPDEV_DSTP2_OF_ATRFG_ONB   ,// ПО ДЗ2 ОФ 
                    
DSTP3_MF_ATRFG_ONB            ,// Cраб ДЗ3 МФ
STPDEV_DSTP3_MF_ATRFG_ONB     ,// ПО ДЗ3 МФ
MCP_DSTP3_ATRFG_ONB           ,// Сраб МТЗ ДЗ3
STPDEV_MCP_DSTP3_ATRFG_ONB    ,// ПО МТЗ ДЗ3
DSTP3_OF_ATRFG_ONB            ,// Сраб ДЗ3 ОФ
STPDEV_DSTP3_OF_ATRFG_ONB     ,// ПО ДЗ3 ОФ 
                    
DSTP4_MF_ATRFG_ONB            ,// Cраб ДЗ4 МФ
STPDEV_DSTP4_MF_ATRFG_ONB     ,// ПО ДЗ4 МФ
MCP_DSTP4_ATRFG_ONB           ,// Сраб МТЗ ДЗ4
STPDEV_MCP_DSTP4_ATRFG_ONB    ,// ПО МТЗ ДЗ4
DSTP4_OF_ATRFG_ONB            ,// Сраб ДЗ4 ОФ
STPDEV_DSTP4_OF_ATRFG_ONB     ,// ПО ДЗ4 ОФ 
                    
DSTP5_MF_ATRFG_ONB            ,// Cраб ДЗ5 МФ
STPDEV_DSTP5_MF_ATRFG_ONB     ,// ПО ДЗ5 МФ
MCP_DSTP5_ATRFG_ONB           ,// Сраб МТЗ ДЗ5
STPDEV_MCP_DSTP5_ATRFG_ONB    ,// ПО МТЗ ДЗ5
DSTP5_OF_ATRFG_ONB            ,// Сраб ДЗ5 ОФ
STPDEV_DSTP5_OF_ATRFG_ONB     ,// ПО ДЗ5 ОФ 


STPDEV_SECTOR_MCP1_STAIGHT_ATRFG_ONB ,//Сектор МТЗН1Впер  //
STPDEV_SECTOR_MCP1_BACK_ATRFG_ONB    ,//Сектор МТЗН1Назад
STPDEV_MCP1_BORING_ATRFG_ONB         ,//Сраб ПО МТЗ1
STPDEV_MCP1_STAIGHT_ATRFG_ONB        ,//Сраб ПО МТЗН1Впер
STPDEV_MCP1_BACK_ATRFG_ONB           ,//Сраб ПО МТЗН1Назад
STPDEV_MCP1_VLT_ATRFG_ONB            ,//Сраб ПО МТЗ1ПН
MCP1_ATRFG_ONB                       ,//Сраб МТЗ1

STPDEV_SECTOR_MCP2_STAIGHT_ATRFG_ONB ,//Сектор МТЗН2Впер  //
STPDEV_SECTOR_MCP2_BACK_ATRFG_ONB    ,//Сектор МТЗН2Назад
STPDEV_MCP2_BORING_ATRFG_ONB         ,//Сраб ПО МТЗ2
STPDEV_MCP2_STAIGHT_ATRFG_ONB        ,//Сраб ПО МТЗН2Впер
STPDEV_MCP2_BACK_ATRFG_ONB           ,//Сраб ПО МТЗН2Назад
STPDEV_MCP2_VLT_ATRFG_ONB            ,//Сраб ПО МТЗ2ПН
MCP2_ATRFG_ONB                       ,//Сраб МТЗ2
 
STPDEV_SECTOR_MCP3_STAIGHT_ATRFG_ONB ,//Сектор МТЗН3Впер  //
STPDEV_SECTOR_MCP3_BACK_ATRFG_ONB    ,//Сектор МТЗН3Назад
STPDEV_MCP3_BORING_ATRFG_ONB         ,//Сраб ПО МТЗ3
STPDEV_MCP3_STAIGHT_ATRFG_ONB        ,//Сраб ПО МТЗН3Впер
STPDEV_MCP3_BACK_ATRFG_ONB           ,//Сраб ПО МТЗН3Назад
STPDEV_MCP3_VLT_ATRFG_ONB            ,//Сраб ПО МТЗ3ПН
MCP3_ATRFG_ONB                       ,//Сраб МТЗ3
 
STPDEV_SECTOR_MCP4_STAIGHT_ATRFG_ONB ,//Сектор МТЗН4Впер  //
STPDEV_SECTOR_MCP4_BACK_ATRFG_ONB    ,//Сектор МТЗН4Назад
STPDEV_MCP4_BORING_ATRFG_ONB         ,//Сраб ПО МТЗ4
STPDEV_MCP4_STAIGHT_ATRFG_ONB        ,//Сраб ПО МТЗН4Впер
STPDEV_MCP4_BACK_ATRFG_ONB           ,//Сраб ПО МТЗН4Назад
STPDEV_MCP4_VLT_ATRFG_ONB            ,//Сраб ПО МТЗ4ПН
MCP4_ATRFG_ONB                       ,//Сраб МТЗ4
 
STPDEV_SECTOR_MCP5_STAIGHT_ATRFG_ONB ,//Сектор МТЗН5Впер  //
STPDEV_SECTOR_MCP5_BACK_ATRFG_ONB    ,//Сектор МТЗН5Назад
STPDEV_MCP5_BORING_ATRFG_ONB         ,//Сраб ПО МТЗ5
STPDEV_MCP5_STAIGHT_ATRFG_ONB        ,//Сраб ПО МТЗН5Впер
STPDEV_MCP5_BACK_ATRFG_ONB           ,//Сраб ПО МТЗН5Назад
STPDEV_MCP5_VLT_ATRFG_ONB            ,//Сраб ПО МТЗ5ПН
MCP5_ATRFG_ONB                       ,//Сраб МТЗ5
 
 
STPDEV_SECTOR_TZNP1_ATRFG_ONB        ,//Сектор ТЗНП1
STPDEV_TZNP1_ATRFG_ONB               ,//Сраб ПО ТЗНП1
TZNP1_ATRFG_ONB                      ,//Сраб ТЗНП1
STPDEV_TZNP1_3U0_ATRFG_ONB           ,//ПО ЗНП1(3U0)
TZNP1__3U0_ATRFG_ONB                 ,//Сраб ЗНП1(3U0)
STPDEV_TZNP1_3I0_ATRFG_ONB           ,//ПО ЗНП1(3I0)
TZNP1_3I0_ATRFG_ONB                  ,//Сраб ЗНП1(3I0)

STPDEV_SECTOR_TZNP2_ATRFG_ONB        ,//Сектор ТЗНП2
STPDEV_TZNP2_ATRFG_ONB               ,//Сраб ПО ТЗНП2
TZNP2_ATRFG_ONB                      ,//Сраб ТЗНП2
STPDEV_TZNP2_3U0_ATRFG_ONB           ,//ПО ЗНП2(3U0)
TZNP2_3U0_ATRFG_ONB                  ,//Сраб ЗНП2(3U0)
STPDEV_TZNP2_3I0_ATRFG_ONB           ,//ПО ЗНП2(3I0)
TZNP2_3I0_ATRFG_ONB                  ,//Сраб ЗНП2(3I0)

STPDEV_SECTOR_TZNP3_ATRFG_ONB        ,//Сектор ТЗНП3
STPDEV_TZNP3_ATRFG_ONB               ,//Сраб ПО ТЗНП3
TZNP3_ATRFG_ONB                      ,//Сраб ТЗНП3
STPDEV_TZNP3_3U0_ATRFG_ONB           ,//ПО ЗНП3(3U0)
TZNP3_3U0_ATRFG_ONB                  ,//Сраб ЗНП3(3U0)
STPDEV_TZNP3_3I0_ATRFG_ONB           ,//ПО ЗНП3(3I0)
TZNP3_3I0_ATRFG_ONB                  ,//Сраб ЗНП3(3I0)

STPDEV_SECTOR_TZNP4_ATRFG_ONB        ,//Сектор ТЗНП4
STPDEV_TZNP4_ATRFG_ONB               ,//Сраб ПО ТЗНП4
TZNP4_ATRFG_ONB                      ,//Сраб ТЗНП4
STPDEV_TZNP4_3U0_ATRFG_ONB           ,//ПО ЗНП4(3U0)
TZNP4_3U0_ATRFG_ONB                  ,//Сраб ЗНП4(3U0)
STPDEV_TZNP4_3I0_ATRFG_ONB           ,//ПО ЗНП4(3I0)
TZNP4_3I0_ATRFG_ONB                  ,//Сраб ЗНП4(3I0)

STPDEV_SECTOR_TZNP5_ATRFG_ONB        ,//Сектор ТЗНП5
STPDEV_TZNP5_ATRFG_ONB               ,//Сраб ПО ТЗНП5
TZNP5_ATRFG_ONB                      ,//Сраб ТЗНП5
STPDEV_TZNP5_3U0_ATRFG_ONB           ,//ПО ЗНП5(3U0)
TZNP5_3U0_ATRFG_ONB                  ,//Сраб ЗНП5(3U0)
STPDEV_TZNP5_3I0_ATRFG_ONB           ,//ПО ЗНП5(3I0)
TZNP5_3I0_ATRFG_ONB                  ,//Сраб ЗНП5(3I0)

STPDEV_UMAX1_ATRFG_ONB               ,//Сраб ПО UMAX1
UMAX1_ATRFG_ONB                      ,//Сраб UMAX1
STPDEV_UMAX2_ATRFG_ONB               ,//Сраб ПО UMAX2
UMAX2_ATRFG_ONB                      ,//Сраб UMAX2

STPDEV_UMIN1_ATRFG_ONB               ,//Сраб ПО Umin1
UMIN1_ATRFG_ONB                      ,//Сраб Umin1
STPDEV_UMIN2_ATRFG_ONB               ,//Сраб ПО Umin2
UMIN2_ATRFG_ONB                      ,//Сраб Umin2

OVER_I_NOM_OFF_HSW_ATRFG_ONB         ,//Превышене номинального тока откл ВВ
LIMIT_OUT_ATRFG_HWS                        ,//Ресурс ВВ исчерпан
LIMIT_CRITICAL_ATRFG_HWS                   ,//Критический ресурс Вв

STPDEV_SECTOR_ZOP1_STAIGHT_ATRFG_ONB ,// //Сектор НЗОП1Впер  
STPDEV_SECTOR_ZOP1_BACK_ATRFG_ONB    ,//   Сектор НЗОП1Назад
STPDEV_ZOP1_BORING_ATRFG_ONB         ,//    ПО ЗОП1
STPDEV_ZOP1_STAIGHT_ATRFG_ONB        ,//    ПО НЗОП1Впер
STPDEV_ZOP1_BACK_ATRFG_ONB           ,//    ПО НЗОП1ННазад
ZOP1_ATRFG_ONB                       ,//   Сраб НЗОП1 
 
STPDEV_SECTOR_ZOP2_STAIGHT_ATRFG_ONB ,// //Сектор НЗОП2Впер  
STPDEV_SECTOR_ZOP2_BACK_ATRFG_ONB    ,//   Сектор НЗОП2Назад
STPDEV_ZOP2_BORING_ATRFG_ONB         ,//    ПО ЗОП2
STPDEV_ZOP2_STAIGHT_ATRFG_ONB        ,//    ПО НЗОП2Впер
STPDEV_ZOP2_BACK_ATRFG_ONB           ,//    ПО НЗОП2ННазад
ZOP2_ATRFG_ONB                       ,//   Сраб НЗОП2 
 
UROV1_ATRFG_ONB                      ,//  Сраб УРОВ1
UROV2_ATRFG_ONB                      ,//  Сраб УРОВ1


ARCL1_ATRFG_ONB                      ,//  АПВ1
ARCL2_ATRFG_ONB                      ,//  АПВ2



EDF01_DI_ATRFG_ONB                   ,// Вх Оф 01  
EDF02_DI_ATRFG_ONB                   ,// Вх Оф 02 
EDF03_DI_ATRFG_ONB                   ,// Вх Оф 03 
EDF04_DI_ATRFG_ONB                   ,// Вх Оф 04 
EDF05_DI_ATRFG_ONB                   ,// Вх Оф 05 
EDF06_DI_ATRFG_ONB                   ,// Вх Оф 06 
EDF07_DI_ATRFG_ONB                   ,// Вх Оф 07 
EDF08_DI_ATRFG_ONB                   ,// Вх Оф 08 
EDF09_DI_ATRFG_ONB                   ,// Вх Оф 09 
EDF10_DI_ATRFG_ONB                   ,// Вх Оф 10 
EDF11_DI_ATRFG_ONB                   ,// Вх Оф 11 
EDF12_DI_ATRFG_ONB                   ,// Вх Оф 12 
EDF13_DI_ATRFG_ONB                   ,// Вх Оф 13 
EDF14_DI_ATRFG_ONB                   ,// Вх Оф 14 
EDF15_DI_ATRFG_ONB                   ,// Вх Оф 15 
EDF16_DI_ATRFG_ONB                   ,// Вх Оф 16 

SET_OT1_DI_ATRFG_ONB                 ,//Вх Уст   От1 
RESET_OT1_DI_ATRFG_ONB               ,//Вх Сброс От1 
SET_OT2_DI_ATRFG_ONB                 ,//Вх   Уст От2   
RESET_OT2_DI_ATRFG_ONB               ,//Вх Сброс От2 
SET_OT3_DI_ATRFG_ONB                 ,//Вх   Уст От3   
RESET_OT3_DI_ATRFG_ONB               ,//Вх Сброс От3 
SET_OT4_DI_ATRFG_ONB                 ,//Вх   Уст От4   
RESET_OT4_DI_ATRFG_ONB               ,//Вх Сброс От4 

SET_OT5_DI_ATRFG_ONB                 ,//Вх Уст   От5 
RESET_OT5_DI_ATRFG_ONB               ,//Вх Сброс От5 
SET_OT6_DI_ATRFG_ONB                 ,//Вх Уст   От6   
RESET_OT6_DI_ATRFG_ONB               ,//Вх Сброс От6 
SET_OT7_DI_ATRFG_ONB                 ,//Вх   Уст От7   
RESET_OT7_DI_ATRFG_ONB               ,//Вх Сброс От7 
SET_OT8_DI_ATRFG_ONB                 ,//Вх   Уст От8   
RESET_OT8_DI_ATRFG_ONB               ,//Вх Сброс От8 











EDF01_ATRFG_ONB                      ,//Выход Оф_01  
EDF02_ATRFG_ONB                      ,//Выход Оф_02
EDF03_ATRFG_ONB                      ,//Выход Оф_03
EDF04_ATRFG_ONB                      ,//Выход Оф_04
EDF05_ATRFG_ONB                      ,//Выход Оф_05
EDF06_ATRFG_ONB                      ,//Выход Оф_06
EDF07_ATRFG_ONB                      ,//Выход Оф_07
EDF08_ATRFG_ONB                      ,//Выход Оф_08
EDF09_ATRFG_ONB                      ,//Выход Оф_09
EDF10_ATRFG_ONB                      ,//Выход Оф_10  
EDF11_ATRFG_ONB                      ,//Выход Оф_11
EDF12_ATRFG_ONB                      ,//Выход Оф_12
EDF13_ATRFG_ONB                      ,//Выход Оф_13
EDF14_ATRFG_ONB                      ,//Выход Оф_14
EDF15_ATRFG_ONB                      ,//Выход Оф_15
EDF16_ATRFG_ONB                      ,//Выход Оф_16


OUT_OT1_ATRFG_ONB                    ,//Выход ОТ1
OUT_OT2_ATRFG_ONB                    ,//Выход ОТ2
OUT_OT3_ATRFG_ONB                    ,//Выход ОТ3
OUT_OT4_ATRFG_ONB                    ,//Выход ОТ4
OUT_OT5_ATRFG_ONB                    ,//Выход ОТ5
OUT_OT6_ATRFG_ONB                    ,//Выход ОТ6
OUT_OT7_ATRFG_ONB                    ,//Выход ОТ7
OUT_OT8_ATRFG_ONB                    ,//Выход ОТ8 


RESERV_MAX_ATRFG_ONB

};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define AMOUNT_BYTE_FOR_KEPRF   (((RESERV_MAX_F_EPRF_ONB)>>3) +1) 
#define AMOUNT_BYTE_FOR_ATRFG   (((RESERV_MAX_ATRFG_ONB)>>3) +1) 
//~~~      - 
//``````````````````````````````````````````````````````````````````````````````````

extern unsigned char uc_ar_atrf_cmd[AMOUNT_BYTE_FOR_ATRFG];// bit
//Описание  массива 
// массив состоит из битовых строк длиной (AMOUNT_BYTE_FOR_ATRFG)*8 бит,

// Биты в строках  - командам которые  должны сгенерироваться  и попасть 
//внутрь системы защит и автоматики
//  
// Перечень команд и их положение в слове массиве 0 до AMOUNT_BYTE_FOR_ATRFG
// в enum ENMAtrf_Out файла  xx\ici\var_r_apcs_ici.h


#endif




                                      
#define __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__ 1
									  
#ifndef __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__
#define SIZE_ATR_CMD 32
#else
#define SIZE_ATR_CMD_INFO ( AMOUNT_BYTE_FOR_ATRFG)
#endif 
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
typedef struct tag_AtrCmdHldDsc
{
	union 
	{
#ifndef __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__	    	
			char   chAAtrCmd [SIZE_ATR_CMD];
	    	long   lArAtrCmd [SIZE_ATR_CMD>>2];
#else
			char   chArAtrCmd [SIZE_ATR_CMD_INFO];
	    	long   lArTAtrCmd [SIZE_ATR_CMD_INFO>>2];
#endif 			
#ifdef __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__
			//Obj xxx_FCoil;
			struct
			{
				 unsigned char uc_ar_atrf_cmd[AMOUNT_BYTE_FOR_ATRFG];
	//char  chArWrp[SIZE_WRP_];//
			}sBrAtrCmdInfoWrp;
#else			
			struct
			{
	

				//ApcsMiscDataDsc hldApcsMiscData;
			}sBrAtrCmdInfoWrp;
			
#endif
            
	}UNAtrCmd;
//	struct
//	{
//		long lErrors;
//		long lTotalBadChange;
//		long lTotalGoodChange;
//		long lTotalChange;
//	}statistics;
}AtrCmdHldDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#ifdef __TYPE_DEFINITION_ATR_CMD_BS_TO_BR__
//#define SIZE_APCS ( ((sizeof( __MEASUREMENT_TO_PROTECTION )>>2)<<2) + 4*(1&&(sizeof(__MEASUREMENT_TO_PROTECTION ))&3) )

#define SIZE_ATR_CMD  (sizeof( holderAtrCmd.UNAtrCmd.sBrAtrCmdInfoWrp ))
#endif


//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
typedef struct tag_AtrCmdWrpDsc//Wrapper 
{

long size_AtrCmd;      //
void *p_AtrCmd;        //

	struct
	{
		long lErrors;
		long lTotalBadChange;
		long lTotalGoodChange;
		long lTotalChange;
	}statistics;
}AtrCmdWrpDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

extern int AppReqTransmitAtrCmd;
extern int AppReqReceiveAtrCmd ;

extern AtrCmdHldDsc holderAtrCmd;
extern AtrCmdHldDsc holderAtrCmdIciCopy;




//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//.extern void ActivateServTrApCnAtrCmdCTpuUnitSpi(void);
//.extern  void TerminateServiceApCnAtrCmd(void);
void PrepDecompouseAtrCmdUnitSpi(void);
void TerminateServiceApCnAtrCmd(void);
void ActivateServTrApCnAtrCmdCTpuUnitSpi(void);

//////////////////////////////////////////////////////////////////////////////////////////
//========================================================================================
//````````````````````````````````````````````````````````````````````````````````````````
//    Secure with Ack Exchange                                      
//........................................................................................
//========================================================================================
//////////////////////////////////////////////////////////////////////////////////////////


#ifndef ApCn_h
//Pointer function return long param void and long
typedef long(*PFL_VL)(void* pv, long lV);

typedef long(*PFL_V )(void* pv);


#endif /* ApCn_h */

//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
#define MAX_CMD     10
typedef struct SecureExecState_TagIn
{

	short shExecConState;//Describe Obj Self Service
//Connection State 
//0 - Obj Active
//1 - Decompose Call
//2 - 1 - State Start
//3 - 1 - State Work
//4 - 1 - State Stop 
//5 - 1- Error State
//	PFL_VL pf_Work;
//	PFL_VL pf_ExecCmd;
	

	long lOrderNumIteration;//Tru program Iteration
	long lIdxStepExec;//???Meaning this var 
	long lCtrCes;//Counter current elementary step
	short ushEvtField;//For Describe state curr Exec State
	
//Obs - unsigned long   ulStateProxyManger;//
//Obs -   //b3 - Target b2 -Phase b1- Error Code b0 - bit Flags
	unsigned long   ulLifeCtrEct;//

	unsigned short ushRvCount;
	unsigned short ushTrCount;
	unsigned short ushRvTotal;
	unsigned short ushTrTotal;
	unsigned char      *pUchRV;//Base
	unsigned char      *pUchTR;//Base
	
	unsigned short ushAmtPhases;
    unsigned short ushAmtStep;
	unsigned short ushAmtIteration;
	unsigned short ushDefaultTimeOutVal;
	
}SecureExecStateDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define INIT_PART     1
#define TRANSMIT_PART 3
#define TERMINATE_PART 20


/*
Transmit Obj 
Have           Pointer_Data & size_of_Data & potental sizeof_cutting
Possible       & maximum amount_of_Phases & maximum amtStep_per_Phases

Need struct_of_jornal
1)Order number - Order Number Iteration
2)Counter current elementary step <<-- It means step can`t be repeated more then 3 times 
3)Ord_Num_of_Step_Transmit/Ord_Num_of_Step_Receive
4)Info_Transmit/Info_Receive

*/
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
typedef struct CmnPipeLogDsc_Tag
{
	
	long lOrderNumIteration;//
	long lCtrCes;//Counter current elementary step
	short ushEvtField;
	//0 - Reserv
	//1 - step transmit - Mean lOrderNumStep Transmit Param 1- Receive
	//2 - step receive - Mean lOrderNumStep Transmit Param 1- Receive
	//3 - Info Present
	//4 - 
	short shReserv;
	long lOrderNumStep;
	void* pvInfo;
	
}CmnPipeLogDsc;//Communication Pipe
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
#define MAX_COMMUNICATE_ITERATION 1
CmnPipeLogDsc arCmnPipeLogDsc[MAX_COMMUNICATE_ITERATION];


typedef struct tag_BFMemDsc{
	struct tag_BFMemDsc*pNext;
	struct tag_BFMemDsc*pPrev;
	unsigned short ushOffset;//Offset Curr Chunk in Mem
	unsigned short ushSizeChunk; 

}ChankMemDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
#define TOTAL_AMOUNT_INFO_RECORD 20
#define BUFF_SIZE              2000
typedef struct CmnPipeInfoBufDsc_TAG
{
	short shAvailMem;
	long lFixAmtInfoEvtRec;
	// Obs-> short shIdxInfoEvtRec;
	ChankMemDsc *pHeadDesc,*pTailDesc;
	//Headr Part
	ChankMemDsc arDescriptChunk[TOTAL_AMOUNT_INFO_RECORD];//short Offset in Buff short Size Chunck
	
	//Data Part
	
	
} CmnPipeInfoBufDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
typedef struct ReliableCmnDsc_TAG{

	RVFrgDsc RvFrgAtrCmd;
	long lAtrCmdOrderNumRvFragment;
	char chStateReciveStngAck;//Inform  ACK Good
	//0 - Inform  ACK Good
	//1 - Cmp OrderNumFrg
	//2 - Cmp Size Pack
	//3 - 
	//4 - 
	char ch1,ch2,ch3;//chTerminateSes;//
	long lAtrCmdOrderNumTrFragment;
	TRFrgDsc TrFrgAtrCmd;

}ReliableCmnDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~~~~ 
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
typedef struct tag_ConvParam
{
	char  *pI8In  ;
	char  *pI8Out ;
	char  *pOnbVal;
	short  shStartNumBit;
	
    //
}ConvParamDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


/*
typedef struct tag_ActivatorReq
{
	long   ulActivationWord;//Requst Word Sequnce
	char   chID_Activator;  //From Here
	char   chReqActivation;//Req
	short  shReserv;
	
    //
}ActivatorCmdDsc;



typedef struct tag_ActivatorCmd
{
	//long   ulActivationWord;//Write when Work Sequense 
	//void*  pvActivCmdWdsHldrDsc;
	CmdWordsHolderDsc m_ActivCmdWdHldr;
	short  shMapW32Used;//
	//bit of order number Activation 32b Word 0-wd, 1-wd 2 ,3-wd etc
	char   chSourcesActivation;//0bit Key 1-RS485 2-USB 3-ZigBee
	char   chState;            //StateActivation;
	
	//short  shReserv;
	//void*  pvReserv;
    //
}ActivationCmdDsc;
*/
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Перечень констант  идентификаторов активаторов телемеханики        ~~~~~
//~~~                                                                          ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define ID_KEY           1 
#define ID_RS485         (ID_KEY       + 1) //2-
#define ID_RS232         (ID_RS485     + 1) //3-
#define ID_USB           (ID_RS232     + 1) //4-
#define ID_ZIG_BEE       (ID_USB       + 1) //5-
#define ID_ETHERNET      (ID_ZIG_BEE   + 1) //6-
//``````````````````````````````````````````````````````````````````````````````````
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#define SIZE_QUEUE_ATR_CMD     8
extern char chReqKeyCallAtrCmd;
extern long chStateQueueAtrCmd;
extern char chSizeQueueHldAtrCmd;

//extern AtrCmdHldDsc arHldAtrCmd[ZIZE_QUEUE_ATR_CMD];
extern ObjDataMgrDsc hldAtrCmdMgr;







extern const char arAtrs_f_IN_Cmd_f [] ;

extern ReliableCmnDsc hldReliableCmnAtrcmd;
extern SecureExecStateDsc hldrConState;

void PrepDecompouseAtrCmdUnitSpiSecure(void);
void  ExecIteration(void* pv);
void BaseTransmitOperation(void* pv); 
void PrepDecompouseStableAtrCmdUnitSpi(void);
void ActivateServTrApCnAtrCmdCTpuUnitSpi(void);
void ActivateServTrApCnStableAtrCmdCTpuUnitSpi(void);
void TerminateServiceApCnStableAtrCmd(void);
void RecodeBit(char *pRamBitArr, char* pLgrBitArr,long nOnbIn,long nOnbOut);
extern long CreateTRFragment(void* pvTRFrgDsc);
long ActivateTrAtrCmdExec(void* pvAdrAtrCmd,long lSize);


#endif //ATR_CMD_h

















