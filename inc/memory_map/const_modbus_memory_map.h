
#ifndef __CONST_MODBUS_MEMORY_MAP__
#define __CONST_MODBUS_MEMORY_MAP__

#define START_ADDRESS_OF_FIRST_OUTPUT                           100 
#define QUANTITY_OF_OUTPUTS                                     23

/******************************************************************************/
/********************** GLOBAL BORDERS  ***************************************/
/******************************************************************************/

#define START_ADDR_GLOBAL_BOUND1                                0
#define LAST_ADDR_GLOBAL_BOUND1                                 1000 // начинается ранжирование
#define START_ADDR_GLOBAL_BOUND2                                4308   
#define LAST_ADDR_GLOBAL_BOUND2                                 6035

/******************************************************************************/
/********************** Device identification *********************************/
/******************************************************************************/

#define START_ADDR_IDENTIFICATION                                 0
#define LAST_ADDR_IDENTIFICATION                                  14

#define IDENTIFICATION_NUMBER_OF_DEVICE                         0
#define DEVICE_MANUFACTURER_1AND2                               1
#define DEVICE_MANUFACTURER_3AND4                               2
#define DEVICE_MANUFACTURER_5AND6                               3
#define DEVICE_MANUFACTURER_7AND8                               4
#define DEVICE_MANUFACTURER_9AND10                              5
#define DEVICE_NAME_1AND2                                       6
#define DEVICE_NAME_3AND4                                       7
#define DEVICE_NAME_5AND6                                       8
#define DEVICE_NAME_7AND8                                       9
#define VERSION_SOFTWARE                                        10
#define DATE_COMPILATION1                                       11
#define DATE_COMPILATION2                                       12
#define TIME_COMPILATION                                        13
#define VERSION_MEMORY_MAP                                      14



/************************ Дискретные выходы ***************************/

#define START_ADDR_DO_VALUES                                    100

#define DO_QUANTITY                                             NUM_OUT

#define DO_REGADDR_1                                            0
//#define LAST_ADDR_DO_VALUES                                     101

/************************ Дискретные входы  ***************************/

#define START_ADDR_DI_VALUES                                    150

#define DI_QUANTITY                                             NUM_IN

#define DI_REGADDR_1                                            0
#define DI_REGADDR_2                                            1
//#define LAST_ADDR_DI_VALUES                                     152


/******************************************************************************/
/* Активные функции                                                           */
/******************************************************************************/

#define START_ADDR_ACTIVE_FUNCTIONS                             200
#define START_BIT_ADDR_ACTIVE_FUNCTIONS                         20000

#define REG_ADDR_F1                                             0
  #define BIT_HVSW_ON                                           0       // Вкл. ВВ от ДВ 
  #define BIT_HVSW_OFF                                          1       // Откл. ВВ 
  #define BIT_CTRL_VKL                                          2       // Контроль Вкл
  #define BIT_CTRL_OTKL                                         3       // Контроль Откл
  #define BIT_RESET_SIGOUT                                      4       // Сброс Реле	
  #define BIT_RESET_LED                                         5       // Сброс индикаци
  #define BIT_BLOCK_SWITCHOVER                                  6       // Блокировка включения ВВ
  #define BIT_SWITCH_STATE                                      7       // Положение ВВ (выключателя)
  #define BIT_PERMIT_BLK_SW_MCP                                 8       // Разблокировка включения ВВ
  #define BIT_OVER_I_NOM_OFF_HSW                                9      //Превышене номинального тока откл ВВ
  #define BIT_LIMIT_OUT_HWS                                     10      //Ресурс ВВ исчерпан
  #define BIT_LIMIT_CRITICAL_HWS                                11      //Критический ресурс Вв         160  

#define REG_ADDR_F2                                             1
  #define BIT_BLOCK_DSTP1                                       0       // Блокировка Дист З1
  #define BIT_BLOCK_DSTP2                                       1       // Блокировка Дист З2
  #define BIT_ACCLT_DSTP2                                       2       // Оперативное ускорение Дист З2
  #define BIT_BLOCK_ACCLT_DSTP2                                 3       // Блокировка Опер ускор Дист З2
  
  #define BIT_BLOCK_DSTP3                                       4       // Блокировка Дист З3
  #define BIT_ACCLT_DSTP3                                       5       // Оперативное ускорение Дист З3
  #define BIT_BLOCK_ACCLT_DSTP3                                 6       // Блокировка Опер ускор Дист З3
  #define BIT_BLOCK_DSTP4                                       7       // Блокировка Дист З4
  #define BIT_ACCLT_DSTP4                                       8       // Оперативное ускорение Дист З4
  #define BIT_BLOCK_ACCLT_DSTP4                                 9       // Блокировка Опер ускор Дист З4
  #define BIT_BLOCK_DSTP5                                       10      // Блокировка Дист З5
  #define BIT_ACCLT_DSTP5                                       11      // Оперативное ускорение Дист З5
  #define BIT_BLOCK_ACCLT_DSTP5                                 12      // Блокировка Опер ускор Дист З5
  #define BIT_SEC_GR_UST_DSTP                                   13      // 2группа уставок ДистЗ

#define REG_ADDR_F3                                             2
  #define BIT_BLOCK_MCP1                                        0       // Блокировка МТЗ1
  #define BIT_BLOCK_MCP2                                        1       // Блокировка МТЗ2
  #define BIT_BLOCK_MCP3                                        2       // Блокировка МТЗ3
  #define BIT_BLOCK_MCP4                                        3       // Блокировка МТЗ4
  #define BIT_BLOCK_MCP5                                        4       // Блокировка МТЗ5
  #define BIT_SEC_GR_UST_MCP                                    5      //2группа уставок МТЗ

//BLOCK_ACCLT_MCP2_DI_IEPRF_ONB        //
#define REG_ADDR_F4                                             3


//BLOCK_NZZ_DI_IEPRF_ONB               //

//BLOCK_ARCL_DI_IEPRF_ONB              //

#define REG_ADDR_F5                                             4
  #define BIT_BLOCK_UMIN1                                       0      //Блокировка Umin1
  #define BIT_START_UMIN1                                       1      //Пуск Umin1
  #define BIT_BLOCK_UMIN2                                       2      //Блокировка Umin2
  #define BIT_START_UMIN2                                       3      //Пуск Umin2

#define REG_ADDR_F6                                             5
  #define BIT_BLOCK_TZNP1                                       0       //Блокировка ТЗНП1
  #define BIT_ACCLT_TZNP1                                       1       //Оперативное ускорение ТЗНП1   
  #define BIT_BLOCK_ACCLT_TZNP1                                 2       //Блокировка Опер ускор ТЗНП1
  #define BIT_BLOCK_TZNP2                                       3       //Блокировка ТЗНП2
  #define BIT_ACCLT_TZNP2                                       4       //Оперативное ускорение ТЗНП2
  #define BIT_BLOCK_ACCLT_TZNP2                                 5       //Блокировка Опер ускор ТЗНП2
  #define BIT_BLOCK_TZNP3                                       6       //Блокировка ТЗНП3
  #define BIT_ACCLT_TZNP3                                       7       //Оперативное ускорение ТЗНП3
  #define BIT_BLOCK_ACCLT_TZNP3                                 8       //Блокировка Опер ускор ТЗНП3
  #define BIT_BLOCK_TZNP4                                       9       //Блокировка ТЗНП4
  #define BIT_ACCLT_TZNP4                                       10      //Оперативное ускорение ТЗНП4
  #define BIT_BLOCK_ACCLT_TZNP4                                 11      //Блокировка Опер ускор ТЗНП4
  #define BIT_BLOCK_TZNP5                                       12      //Блокировка ТЗНП5
  #define BIT_ACCLT_TZNP5                                       13      //Оперативное ускорение ТЗНП5
  #define BIT_BLOCK_ACCLT_TZNP5                                 14      //Блокировка Опер ускор ТЗНП5


#define REG_ADDR_F7                                             6 

#define REG_ADDR_F8                                             7
#define BIT_START_UROV                                          0      //Пуск УРОВ
#define BIT_UROV1                                               1     //  Сраб УРОВ1
#define BIT_UROV2                                               2     //  Сраб УРОВ1

#define REG_ADDR_F9                                             8

#define REG_ADDR_F10                                            9
  #define BIT_STPDEV_SECTOR_MCP1_STAIGHT_OEPRF_ONB              0       //Сектор МТЗН1Впер  //
  #define BIT_STPDEV_SECTOR_MCP1_BACK_OEPRF_ONB                 1       //Сектор МТЗН1Назад
  #define BIT_STPDEV_MCP1_BORING_OEPRF_ONB                      2       //Сраб ПО МТЗ1
  #define BIT_STPDEV_MCP1_STAIGHT_OEPRF_ONB                     3       //Сраб ПО МТЗН1Впер
  #define BIT_STPDEV_MCP1_BACK_OEPRF_ONB                        4       //Сраб ПО МТЗН1Назад
  #define BIT_STPDEV_MCP1_VLT_OEPRF_ONB                         5       //Сраб ПО МТЗ1ПН
  #define BIT_MCP1_OEPRF_ONB                                    6       //Сраб МТЗ1

  #define BIT_STPDEV_SECTOR_MCP2_STAIGHT_OEPRF_ONB              7       //Сектор МТЗН2Впер  //
  #define BIT_STPDEV_SECTOR_MCP2_BACK_OEPRF_ONB                 8       //Сектор МТЗН2Назад
  #define BIT_STPDEV_MCP2_BORING_OEPRF_ONB                      9       //Сраб ПО МТЗ2
  #define BIT_STPDEV_MCP2_STAIGHT_OEPRF_ONB                     10      //Сраб ПО МТЗН2Впер
  #define BIT_STPDEV_MCP2_BACK_OEPRF_ONB                        11      //Сраб ПО МТЗН2Назад
  #define BIT_STPDEV_MCP2_VLT_OEPRF_ONB                         12      //Сраб ПО МТЗ2ПН
  #define BIT_MCP2_OEPRF_ONB                                    13      //Сраб МТЗ2
 
#define REG_ADDR_F11                                            10
  #define BIT_STPDEV_SECTOR_MCP3_STAIGHT_OEPRF_ONB              0       //Сектор МТЗН3Впер  //
  #define BIT_STPDEV_SECTOR_MCP3_BACK_OEPRF_ONB                 1       //Сектор МТЗН3Назад
  #define BIT_STPDEV_MCP3_BORING_OEPRF_ONB                      2       //Сраб ПО МТЗ3
  #define BIT_STPDEV_MCP3_STAIGHT_OEPRF_ONB                     3       //Сраб ПО МТЗН3Впер
  #define BIT_STPDEV_MCP3_BACK_OEPRF_ONB                        4       //Сраб ПО МТЗН3Назад
  #define BIT_STPDEV_MCP3_VLT_OEPRF_ONB                         5       //Сраб ПО МТЗ3ПН
  #define BIT_MCP3_OEPRF_ONB                                    6       //Сраб МТЗ3
 
  #define BIT_STPDEV_SECTOR_MCP4_STAIGHT_OEPRF_ONB              7       //Сектор МТЗН4Впер  //
  #define BIT_STPDEV_SECTOR_MCP4_BACK_OEPRF_ONB                 8       //Сектор МТЗН4Назад
  #define BIT_STPDEV_MCP4_BORING_OEPRF_ONB                      9       //Сраб ПО МТЗ4
  #define BIT_STPDEV_MCP4_STAIGHT_OEPRF_ONB                     10      //Сраб ПО МТЗН4Впер
  #define BIT_STPDEV_MCP4_BACK_OEPRF_ONB                        11      //Сраб ПО МТЗН4Назад
  #define BIT_STPDEV_MCP4_VLT_OEPRF_ONB                         12      //Сраб ПО МТЗ4ПН
  #define BIT_MCP4_OEPRF_ONB                                    13      //Сраб МТЗ4
 
#define REG_ADDR_F12                                            11
  #define BIT_STPDEV_SECTOR_MCP5_STAIGHT_OEPRF_ONB              0       //Сектор МТЗН5Впер  //
  #define BIT_STPDEV_SECTOR_MCP5_BACK_OEPRF_ONB                 1       //Сектор МТЗН5Назад
  #define BIT_STPDEV_MCP5_BORING_OEPRF_ONB                      2       //Сраб ПО МТЗ5
  #define BIT_STPDEV_MCP5_STAIGHT_OEPRF_ONB                     3       //Сраб ПО МТЗН5Впер
  #define BIT_STPDEV_MCP5_BACK_OEPRF_ONB                        4       //Сраб ПО МТЗН5Назад
  #define BIT_STPDEV_MCP5_VLT_OEPRF_ONB                         5       //Сраб ПО МТЗ5ПН
  #define BIT_MCP5_OEPRF_ONB                                    6       //Сраб МТЗ5
 
 
#define REG_ADDR_F13                                            12
  #define BIT_STPDEV_SECTOR_TZNP1                               0       //Сектор ТЗНП1
  #define BIT_STPDEV_TZNP1                                      1       //Сраб ПО ТЗНП1
  #define BIT_TZNP1                                             2       //Сраб ТЗНП1
  #define BIT_STPDEV_TZNP1_3U0                                  3       //ПО ЗНП1(3U0)
  #define BIT_TZNP1__3U0                                        4       //Сраб ЗНП1(3U0)
  #define BIT_STPDEV_TZNP1_3I0                                  5       //ПО ЗНП1(3I0)
  #define BIT_TZNP1_3I0                                         6       //Сраб ЗНП1(3I0)
                                          
  #define BIT_STPDEV_SECTOR_TZNP2                               7       //Сектор ТЗНП2
  #define BIT_STPDEV_TZNP2                                      8       //Сраб ПО ТЗНП2
  #define BIT_TZNP2                                             9       //Сраб ТЗНП2
  #define BIT_STPDEV_TZNP2_3U0                                  10      //ПО ЗНП2(3U0)
  #define BIT_TZNP2_3U0                                         11      //Сраб ЗНП2(3U0)
  #define BIT_STPDEV_TZNP2_3I0                                  12      //ПО ЗНП2(3I0)
  #define BIT_TZNP2_3I0                                         13      //Сраб ЗНП2(3I0)

#define REG_ADDR_F14                                            13
  #define BIT_STPDEV_SECTOR_TZNP3                               0       //Сектор ТЗНП3
  #define BIT_STPDEV_TZNP3                                      1       //Сраб ПО ТЗНП3
  #define BIT_TZNP3                                             2       //Сраб ТЗНП3
  #define BIT_STPDEV_TZNP3_3U0                                  3       //ПО ЗНП3(3U0)
  #define BIT_TZNP3_3U0                                         4       //Сраб ЗНП3(3U0)
  #define BIT_STPDEV_TZNP3_3I0                                  5       //ПО ЗНП3(3I0)
  #define BIT_TZNP3_3I0                                         6       //Сраб ЗНП3(3I0)

  #define BIT_STPDEV_SECTOR_TZNP4                               7       //Сектор ТЗНП4
  #define BIT_STPDEV_TZNP4                                      8       //Сраб ПО ТЗНП4
  #define BIT_TZNP4                                             9       //Сраб ТЗНП4
  #define BIT_STPDEV_TZNP4_3U0                                  10      //ПО ЗНП4(3U0)
  #define BIT_TZNP4_3U0                                         11      //Сраб ЗНП4(3U0)
  #define BIT_STPDEV_TZNP4_3I0                                  12      //ПО ЗНП4(3I0)
  #define BIT_TZNP4_3I0                                         13      //Сраб ЗНП4(3I0)

#define REG_ADDR_F15                                            14
  #define BIT_STPDEV_SECTOR_TZNP5                               0     //Сектор ТЗНП5
  #define BIT_STPDEV_TZNP5                                      1     //Сраб ПО ТЗНП5
  #define BIT_TZNP5                                             2     //Сраб ТЗНП5
  #define BIT_STPDEV_TZNP5_3U0                                  3     //ПО ЗНП5(3U0)
  #define BIT_TZNP5_3U0                                         4     //Сраб ЗНП5(3U0)
  #define BIT_STPDEV_TZNP5_3I0                                  5     //ПО ЗНП5(3I0)
  #define BIT_TZNP5_3I0                                         6     //Сраб ЗНП5(3I0)

#define REG_ADDR_F16                                            15
  #define BIT_STPDEV_UMAX1_OEPRF_ONB                            0       //Сраб ПО UMAX1
  #define BIT_UMAX1_OEPRF_ONB                                   1       //Сраб UMAX1
  #define BIT_STPDEV_UMAX2_OEPRF_ONB                            2       //Сраб ПО UMAX2
  #define BIT_UMAX2_OEPRF_ONB                                   3       //Сраб UMAX2

  #define BIT_STPDEV_UMIN1_OEPRF_ONB                            4       //Сраб ПО Umin1
  #define BIT_UMIN1_OEPRF_ONB                                   5       //Сраб Umin1
  #define BIT_STPDEV_UMIN2_OEPRF_ONB                            6       //Сраб ПО Umin2
  #define BIT_UMIN2_OEPRF_ONB                                   7       //Сраб Umin2
  #define BIT_BLOCK_UMAX1                                       8       //
  #define BIT_BLOCK_UMAX2                                       9       //

#define REG_ADDR_F17                                            16
  #define BIT_STPDEV_SECTOR_ZOP1_STAIGHT                        0       // //Сектор НЗОП1Впер  
  #define BIT_STPDEV_SECTOR_ZOP1_BACK                           1       //   Сектор НЗОП1Назад
  #define BIT_STPDEV_ZOP1_BORING                                2       //    ПО ЗОП1
  #define BIT_STPDEV_ZOP1_STAIGHT                               3       //    ПО НЗОП1Впер
  #define BIT_STPDEV_ZOP1_BACK                                  4       //    ПО НЗОП1ННазад
  #define BIT_ZOP1                                              5       //   Сраб НЗОП1 
   
  #define BIT_STPDEV_SECTOR_ZOP2_STAIGHT                        6       // //Сектор НЗОП2Впер  
  #define BIT_STPDEV_SECTOR_ZOP2_BACK                           7       //   Сектор НЗОП2Назад
  #define BIT_STPDEV_ZOP2_BORING                                8       //    ПО ЗОП2
  #define BIT_STPDEV_ZOP2_STAIGHT                               9       //    ПО НЗОП2Впер
  #define BIT_STPDEV_ZOP2_BACK                                  10      //    ПО НЗОП2ННазад
  #define BIT_ZOP2                                              11      //   Сраб НЗОП2
  #define BIT_BLOCK_ZOP1                                        12       //Блокировка ЗОП1
  #define BIT_BLOCK_ZOP2                                        13       //Блокировка ЗОП2
  #define BIT_SEC_GR_UST_ZOP                                    14      //2группа уставок ЗОПBIT

#define REG_ADDR_F18                                            17
  #define BIT_DRIVER_SW                                         0       // Привод ВВ
  #define BIT_FLT_U_DSTP                                        1       // Неисправность цепйй напр ДистЗ

  #define BIT_START_AFU                                         2      //Пуск АПВ от ДВ 
  #define BIT_BLOCK_AFU                                         3      //Блокировка АПВ ОТ ДВ
  #define BIT_ARCL1                                             4     //  АПВ1
  #define BIT_ARCL2                                             5     //  АПВ2

  #define BIT_SW_OFF_CMDF_ONB                                   6       //.Работа БО
  #define BIT_SW_ON_CMDF_ONB                                    7       //.Работа БВ

#define REG_ADDR_F20                                            19
  #define BIT_EDF01_DI_IEPRF_ONB                                0      // Вх Оф 01  
  #define BIT_EDF02_DI_IEPRF_ONB                                1      // Вх Оф 02 
  #define BIT_EDF03_DI_IEPRF_ONB                                2      // Вх Оф 03 
  #define BIT_EDF04_DI_IEPRF_ONB                                3      // Вх Оф 04 
  #define BIT_EDF05_DI_IEPRF_ONB                                4      // Вх Оф 05 
  #define BIT_EDF06_DI_IEPRF_ONB                                5      // Вх Оф 06 
  #define BIT_EDF07_DI_IEPRF_ONB                                6      // Вх Оф 07 
  #define BIT_EDF08_DI_IEPRF_ONB                                7      // Вх Оф 08 
  #define BIT_EDF09_DI_IEPRF_ONB                                8      // Вх Оф 09 
  #define BIT_EDF10_DI_IEPRF_ONB                                9      // Вх Оф 10 
  #define BIT_EDF11_DI_IEPRF_ONB                                10     // Вх Оф 11 
  #define BIT_EDF12_DI_IEPRF_ONB                                11     // Вх Оф 12 
  #define BIT_EDF13_DI_IEPRF_ONB                                12     // Вх Оф 13 
  #define BIT_EDF14_DI_IEPRF_ONB                                13     // Вх Оф 14 
  #define BIT_EDF15_DI_IEPRF_ONB                                14     // Вх Оф 15 
  #define BIT_EDF16_DI_IEPRF_ONB                                15     // Вх Оф 16 

#define REG_ADDR_F21                                            20
  #define BIT_EDF01_OEPRF_ONB                                   0      //Выход Оф_01  
  #define BIT_EDF02_OEPRF_ONB                                   1      //Выход Оф_02
  #define BIT_EDF03_OEPRF_ONB                                   2      //Выход Оф_03
  #define BIT_EDF04_OEPRF_ONB                                   3      //Выход Оф_04
  #define BIT_EDF05_OEPRF_ONB                                   4      //Выход Оф_05
  #define BIT_EDF06_OEPRF_ONB                                   5      //Выход Оф_06
  #define BIT_EDF07_OEPRF_ONB                                   6      //Выход Оф_07
  #define BIT_EDF08_OEPRF_ONB                                   7      //Выход Оф_08
  #define BIT_EDF09_OEPRF_ONB                                   8      //Выход Оф_09
  #define BIT_EDF10_OEPRF_ONB                                   9      //Выход Оф_10  
  #define BIT_EDF11_OEPRF_ONB                                   10     //Выход Оф_11
  #define BIT_EDF12_OEPRF_ONB                                   11     //Выход Оф_12
  #define BIT_EDF13_OEPRF_ONB                                   12     //Выход Оф_13
  #define BIT_EDF14_OEPRF_ONB                                   13     //Выход Оф_14
  #define BIT_EDF15_OEPRF_ONB                                   14     //Выход Оф_15
  #define BIT_EDF16_OEPRF_ONB                                   15     //Выход Оф_16

#define REG_ADDR_F22                                            21
  #define ADDR_SET_OT1                                          0      //Вх Уст   От1 
  #define ADDR_RESET_OT1                                        1      //Вх Сброс От1 
  #define ADDR_SET_OT2                                          2      //Вх   Уст От2   
  #define ADDR_RESET_OT2                                        3      //Вх Сброс От2 
  #define ADDR_SET_OT3                                          4      //Вх   Уст От3   
  #define ADDR_RESET_OT3                                        5      //Вх Сброс От3 
  #define ADDR_SET_OT4                                          6      //Вх   Уст От4   
  #define ADDR_RESET_OT4                                        7      //Вх Сброс От4 

  #define ADDR_SET_OT5                                          8      //Вх Уст   От5 
  #define ADDR_RESET_OT5                                        9      //Вх Сброс От5 
  #define ADDR_SET_OT6                                          10      //Вх Уст   От6   
  #define ADDR_RESET_OT6                                        11      //Вх Сброс От6 
  #define ADDR_SET_OT7                                          12      //Вх   Уст От7   
  #define ADDR_RESET_OT7                                        13      //Вх Сброс От7 
  #define ADDR_SET_OT8                                          14      //Вх   Уст От8   
  #define ADDR_RESET_OT8                                        15      //Вх Сброс От8 

#define REG_ADDR_F23                                            22
  #define BIT_OUT_OT1                                           0     //Выход ОТ1
  #define BIT_OUT_OT2                                           1     //Выход ОТ2
  #define BIT_OUT_OT3                                           2     //Выход ОТ3
  #define BIT_OUT_OT4                                           3     //Выход ОТ4
  #define BIT_OUT_OT5                                           4     //Выход ОТ5
  #define BIT_OUT_OT6                                           5     //Выход ОТ6
  #define BIT_OUT_OT7                                           6     //Выход ОТ7
  #define BIT_OUT_OT8                                           7     //Выход ОТ8 

#define REG_ADDR_F24                                            23
  #define PASS_PROT_SET                                         0

#define REG_ADDR_F25                                            24
  #define BIT_STPDEV_DSTP1_MF_OEPRF_ONB                         0
  #define BIT_DSTP1_MF_OEPRF_ONB                                1
  #define BIT_STPDEV_MCP_DSTP1_OEPRF_ONB                         2       
  #define BIT_MCP_DSTP1_OEPRF_ONB                               3
  #define BIT_STPDEV_DSTP1_OF_OEPRF_ONB                         4
  #define BIT_DSTP1_OF_OEPRF_ONB                                5
  #define BIT_DSTP2_MF_OEPRF_ONB                                6
  #define BIT_STPDEV_DSTP2_MF_OEPRF_ONB                         7
  #define BIT_MCP_DSTP2_OEPRF_ONB                               8
  #define BIT_STPDEV_MCP_DSTP2_OEPRF_ONB                         9       
  #define BIT_DSTP2_OF_OEPRF_ONB                                10
  #define BIT_STPDEV_DSTP2_OF_OEPRF_ONB                         11


#define REG_ADDR_F26                                            25
  #define BIT_DSTP3_MF_OEPRF_ONB                                0
  #define BIT_STPDEV_DSTP3_MF_OEPRF_ONB                         1
  #define BIT_MCP_DSTP3_OEPRF_ONB                               2
  #define BIT_STPDEV_MCP_DSTP3_OEPRF_ONB                         3       
  #define BIT_DSTP3_OF_OEPRF_ONB                                4
  #define BIT_STPDEV_DSTP3_OF_OEPRF_ONB                         5
  #define BIT_DSTP4_MF_OEPRF_ONB                                6
  #define BIT_STPDEV_DSTP4_MF_OEPRF_ONB                         7
  #define BIT_MCP_DSTP4_OEPRF_ONB                               8
  #define BIT_STPDEV_MCP_DSTP4_OEPRF_ONB                         9       
  #define BIT_DSTP4_OF_OEPRF_ONB                                10
  #define BIT_STPDEV_DSTP4_OF_OEPRF_ONB                         11

#define REG_ADDR_F27                                            26
  #define BIT_DSTP5_MF_OEPRF_ONB                                0
  #define BIT_STPDEV_DSTP5_MF_OEPRF_ONB                         1
  #define BIT_MCP_DSTP5_OEPRF_ONB                               2
  #define BIT_STPDEV_MCP_DSTP5_OEPRF_ONB                         3       
  #define BIT_DSTP5_OF_OEPRF_ONB                                4
  #define BIT_STPDEV_DSTP5_OF_OEPRF_ONB                         5

  #define BIT_ACCLT_DSTP2_EPI_OEPRF_ONB                         6
  #define BIT_ACCLT_DSTP3_EPI_OEPRF_ONB                         7
  #define BIT_ACCLT_DSTP4_EPI_OEPRF_ONB                         8
  #define BIT_ACCLT_DSTP5_EPI_OEPRF_ONB                         9
        
#define REG_ADDR_F28                                            27
  #define BIT_ACCLT_MCP2_EPI_OEPRF_ONB                          0
  #define BIT_ACCLT_MCP2_DI_OEPRF_ONB                           1
  #define BIT_BLOCK_ACCLT_MCP2_DI_OEPRF_ONB                      2       
  #define BIT_ACCLT_MCP3_EPI_OEPRF_ONB                          3
  #define BIT_ACCLT_MCP3_DI_OEPRF_ONB                           4
  #define BIT_BLOCK_ACCLT_MCP3_DI_OEPRF_ONB                      5       
  #define BIT_ACCLT_MCP4_EPI_OEPRF_ONB                          6
  #define BIT_ACCLT_MCP4_DI_OEPRF_ONB                           7
  #define BIT_BLOCK_ACCLT_MCP4_DI_OEPRF_ONB                      8       
  #define BIT_ACCLT_MCP5_EPI_OEPRF_ONB                          9
  #define BIT_ACCLT_MCP5_DI_OEPRF_ONB                           10
  #define BIT_BLOCK_ACCLT_MCP5_DI_OEPRF_ONB                       11      

#define REG_ADDR_F29                                            28
  #define BIT_ACCLT_TZNP1_EPI_OEPRF_ONB                         0
  #define BIT_ACCLT_TZNP2_EPI_OEPRF_ONB                         1
  #define BIT_ACCLT_TZNP3_EPI_OEPRF_ONB                         2
  #define BIT_ACCLT_TZNP4_EPI_OEPRF_ONB                         3
  #define BIT_ACCLT_TZNP5_EPI_OEPRF_ONB                         4

#define LAST_ADDR_ACTIVE_FUNCTIONS                              20500

/**************************** Настройки функций *******************************/

#define START_ADDR_FUNC_SETTINGS                                230
#define START_BIT_ADDR_FUNC_SETTINGS                            23000

#define REGADDR_FS1                                             0
  #define STATE_MCP1                                            0
  #define STATE_MCP2                                            1
  #define STATE_MCP3                                            2
  #define STATE_MCP4                                            3
  #define STATE_MCP5                                            4
  #define STATE_ACLT_MCP2                                       5
  #define STATE_ACLT_MCP3                                       6
  #define STATE_ACLT_MCP4                                       7
  #define STATE_ACLT_MCP5                                       8
  #define STATE_ACLT_SW_MCP2                                    9
  #define STATE_ACLT_SW_MCP3                                    10
  #define STATE_ACLT_SW_MCP4                                    11
  #define STATE_ACLT_SW_MCP5                                    12

#define REGADDR_FS2                                             1
  #define STATE_MCP1_FWD                                        0
  #define STATE_MCP1_RVRS                                       1
  #define STATE_MCP2_FWD                                        2
  #define STATE_MCP2_RVRS                                       3
  #define STATE_MCP3_FWD                                        4
  #define STATE_MCP3_RVRS                                       5
  #define STATE_MCP4_FWD                                        6
  #define STATE_MCP4_RVRS                                       7
  #define STATE_MCP5_FWD                                        8
  #define STATE_MCP5_RVRS                                       9

#define REGADDR_FS3                                             2
  #define STATE_DSTP1                                           0
  #define STATE_DSTP1_BLOCK_DRIFT                               1
  #define STATE_DSTP1_MCP                                       2

  #define STATE_DSTP2                                           3
  #define STATE_DSTP2_BLOCK_DRIFT                               4
  #define STATE_DSTP2_MCP                                       5
  #define STATE_DSTP2_AUTO_ACLT                                 6
  #define STATE_DSTP2_ACLT_HWS                                  7
  #define STATE_DSTP2_TELE_ACLT                                 8

  #define STATE_DSTP3                                           9
  #define STATE_DSTP3_BLOCK_DRIFT                               10
  #define STATE_DSTP3_MCP                                       11
  #define STATE_DSTP3_AUTO_ACLT                                 12
  #define STATE_DSTP3_ACLT_HWS                                  13
  #define STATE_DSTP3_TELE_ACLT                                 14

#define REGADDR_FS4                                             3
  #define STATE_DSTP4                                           0
  #define STATE_DSTP4_BLOCK_DRIFT                               1
  #define STATE_DSTP4_MCP                                       2
  #define STATE_DSTP4_AUTO_ACLT                                 3
  #define STATE_DSTP4_ACLT_HWS                                  4
  #define STATE_DSTP4_TELE_ACLT                                 5

  #define STATE_DSTP5                                           6
  #define STATE_DSTP5_BLOCK_DRIFT                               7
  #define STATE_DSTP5_MCP                                       8
  #define STATE_DSTP5_AUTO_ACLT                                 9
  #define STATE_DSTP5_ACLT_HWS                                  10
  #define STATE_DSTP5_TELE_ACLT                                 11

#define REGADDR_FS5                                             4
  #define STATE_TZNP1                                           0
  #define STATE_DIRECTION_TZNP1                                 1
  #define STATE_TZNP1_3U0                                       2
  #define STATE_TZNP1_3I0                                       3 
  #define STATE_TZNP1_ACLT                                      4
  #define STATE_TZNP1_OVER_WK_ACLT                              5
  #define STATE_TZNP1_ACLT_SW                                   6

  #define STATE_TZNP2                                           7
  #define STATE_DIRECTION_TZNP2                                 8
  #define STATE_TZNP2_3U0                                       9
  #define STATE_TZNP2_3I0                                       10 
  #define STATE_TZNP2_ACLT                                      11
  #define STATE_TZNP2_OVER_WK_ACLT                              12
  #define STATE_TZNP2_ACLT_SW                                   13

#define REGADDR_FS6                                             5
  #define STATE_TZNP3                                           0
  #define STATE_DIRECTION_TZNP3                                 1
  #define STATE_TZNP3_3U0                                       2
  #define STATE_TZNP3_3I0                                       3 
  #define STATE_TZNP3_ACLT                                      4
  #define STATE_TZNP3_OVER_WK_ACLT                              5
  #define STATE_TZNP3_ACLT_SW                                   6

  #define STATE_TZNP4                                           7
  #define STATE_DIRECTION_TZNP4                                 8
  #define STATE_TZNP4_3U0                                       9
  #define STATE_TZNP4_3I0                                       10 
  #define STATE_TZNP4_ACLT                                      11
  #define STATE_TZNP4_OVER_WK_ACLT                              12
  #define STATE_TZNP4_ACLT_SW                                   13

#define REGADDR_FS7                                             6
  #define STATE_TZNP5                                           0
  #define STATE_DIRECTION_TZNP5                                 1
  #define STATE_TZNP5_3U0                                       2
  #define STATE_TZNP5_3I0                                       3 
  #define STATE_TZNP5_ACLT                                      4
  #define STATE_TZNP5_OVER_WK_ACLT                              5
  #define STATE_TZNP5_ACLT_SW                                   6

#define REGADDR_FS8                                             7
  #define STATE_NSP1                                            0
  #define STATE_DIRECTION_PROT_NSP1                             1
  #define STATE_DIRECTION_NSP1                                  2
  #define STATE_NSP2                                            3
  #define STATE_DIRECTION_PROT_NSP2                             4
  #define STATE_DIRECTION_NSP2                                  5

#define REGADDR_FS9                                             8
  #define STATE_UMIN1                                           0
  #define STATE_SDEV_UMIN1                                      1
  #define STATE_UBLOCK_UMIN1                                    2
  #define STATE_IBLOCK_UMIN1                                    3
  #define STATE_SDEV_PHASE_UMIN1                                4
  #define STATE_UMIN2                                           5
  #define STATE_SDEV_UMIN2                                      6
  #define STATE_UBLOCK_UMIN2                                    7
  #define STATE_IBLOCK_UMIN2                                    8
  #define STATE_SDEV_PHASE_UMIN2                                9

#define REGADDR_FS10                                            9
  #define STATE_UMAX1                                           0
  #define STATE_SDEV_UMAX1                                      1
  #define STATE_SDEV_PHASE_UMAX1                                2
  #define STATE_UMAX2                                           3
  #define STATE_SDEV_UMAX2                                      4
  #define STATE_SDEV_PHASE_UMAX2                                5

#define REGADDR_FS11                                            10
  #define STATE_RCRL1                                           0
  #define STATE_RCRL2                                           1

//массив битовых переключателей RCRL
#define REGADDR_FS12                                            11
#define REGADDR_FS13                                            12
#define REGADDR_FS14                                            13

#define REGADDR_FS15                                            14
  #define STATE_BRF                                             0

// массив битовых переключателей BRF
#define REGADDR_FS16                                            15
#define REGADDR_FS17                                            16
#define REGADDR_FS18                                            17

#define REGADDR_FS19                                            18
  #define STATE_BRU_DELAY_ON_UNIT                               0
  #define STATE_BRU_BLK_SET_ON                                  1

// Конфигурация
#define REGADDR_FS20                                            19
// Пароль
#define REGADDR_FS21_PASSWORD                                   20

// Time and date
#define REGADDR_FS22_YEAR                                       21
#define REGADDR_FS23_MONTH                                      22
#define REGADDR_FS24_DAY                                        23
#define REGADDR_FS25_HOUR                                       24
#define REGADDR_FS26_MINUTES                                    25
#define REGADDR_FS27_SECONDS                                    26
#define REGADDR_FS28_MILISECONDS                                27

// Language of GUI
#define REGADDR_FS29_LANGGUI                                    28

// MODBUS settings
#define REGADDR_FS30_DEVADDR                                    29  // addr device

// RS-485 settings
#define REGADDR_FS31_BAUDRATE                                   30
#define REGADDR_FS31_STOPBIT                                    31
#define REGADDR_FS32_PARITY                                     32
#define REGADDR_FS33_RESIVE_DELAY                               33


//#define LAST_ADDR_FUNC_SETTINGS                                 279 // тоже от балды. ПЕРЕПИСАТЬ

/******************************************************************************/
/*                             Tripped functions                              */
/******************************************************************************/
#define START_BIT_ADDR_TRIPPED_FUNC                             26000
#define LAST_BIT_ADDR_TRIPPED_FUNC                              29000

/******************************************************************************/
/*                       Селекция МТЗ                                         */
/******************************************************************************/
#define START_ADDR_SELECTION_MCP                                305

#define SELECT_MCP1                                             0
#define SELECT_MCP2                                             1
#define SELECT_MCP3                                             2
#define SELECT_MCP4                                             3
#define SELECT_MCP5                                             4

/******************************************************************************/
/*                       Уставки МТЗ первой ступени                           */
/******************************************************************************/

#define PERVAYA_GRUPPA_USTAVOK                                     4308
#define VTORAYA_GRUPPA_USTAVOK                                     4740
#define TRETYA_GRUPPA_USTAVOK                                     5172
#define CHETVERTAYA_GRUPPA_USTAVOK                                  5604

#define START_ADDR_MTZ1                      0
#define G1_START_ADDR_MTZ1                   PERVAYA_GRUPPA_USTAVOK + START_ADDR_MTZ1
#define G2_START_ADDR_MTZ1                   VTORAYA_GRUPPA_USTAVOK + START_ADDR_MTZ1
#define G3_START_ADDR_MTZ1                   TRETYA_GRUPPA_USTAVOK + START_ADDR_MTZ1
#define G4_START_ADDR_MTZ1                   CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_MTZ1



#define USTAV_MTZ1                                              0
#define USTAV_MTZ1_NAPR_VPER                                    1
#define USTAV_MTZ1_NAPR_NAZ                                     2
#define USTAV_MTZ1_S_PUSKOM_PO_U                                3
#define U_PUSKA_MTZ1                                            4
#define UGOL_POVOR_ZONY_SRAB_MTZ1                               5



#define USTAV_MTZ1_KMIN                                50
#define USTAV_MTZ1_NAPR_VPER_KMIN                      50
#define USTAV_MTZ1_NAPR_NAZ_KMIN                       50
#define USTAV_MTZ1_S_PUSKOM_PO_U_KMIN                  50
#define U_PUSKA_MTZ1_KMIN                              200
#define UGOL_POVOR_ZONY_SRAB_MTZ1_KMIN                 0

#define USTAV_MTZ1_KMAX                                15000
#define USTAV_MTZ1_NAPR_VPER_KMAX                      15000
#define USTAV_MTZ1_NAPR_NAZ_KMAX                       15000
#define USTAV_MTZ1_S_PUSKOM_PO_U_KMAX                  15000
#define U_PUSKA_MTZ1_KMAX                              15000
#define UGOL_POVOR_ZONY_SRAB_MTZ1_KMAX                 90





#define VIDERZH_VREM_MTZ1                                       6
#define VIDERZH_VREM_MTZ1_NAPR_VPER                             7
#define VIDERZH_VREM_MTZ1_NAPR_NAZ                              8
#define VIDERZH_VREM_MTZ1_S_PUSKOM_PO_U                         9





#define VIDERZH_VREM_MTZ1_KMIN                              0
#define VIDERZH_VREM_MTZ1_NAPR_VPER_KMIN                    0
#define VIDERZH_VREM_MTZ1_NAPR_NAZ_KMIN                     0
#define VIDERZH_VREM_MTZ1_S_PUSKOM_PO_U_KMIN                0

#define VIDERZH_VREM_MTZ1_KMAX                              3200
#define VIDERZH_VREM_MTZ1_NAPR_VPER_KMAX                    3200
#define VIDERZH_VREM_MTZ1_NAPR_NAZ_KMAX                     3200
#define VIDERZH_VREM_MTZ1_S_PUSKOM_PO_U_KMAX                3200


#define START_ADDR_MTZ2                      10
#define G1_START_ADDR_MTZ2                   PERVAYA_GRUPPA_USTAVOK + START_ADDR_MTZ2
#define G2_START_ADDR_MTZ2                   VTORAYA_GRUPPA_USTAVOK + START_ADDR_MTZ2
#define G3_START_ADDR_MTZ2                   TRETYA_GRUPPA_USTAVOK + START_ADDR_MTZ2
#define G4_START_ADDR_MTZ2                   CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_MTZ2


#define USTAV_MTZ2                                              0
#define USTAV_MTZ2_NAPR_VPER                                    1
#define USTAV_MTZ2_NAPR_NAZ                                     2
#define USTAV_MTZ2_S_PUSKOM_PO_U                                3
#define U_PUSKA_MTZ2                                            4
#define UGOL_POVOR_ZONY_SRAB_MTZ2                               5
#define VIDERZH_VREM_MTZ2                                       6
#define VIDERZH_VREM_MTZ2_NAPR_VPER                             7
#define VIDERZH_VREM_MTZ2_NAPR_NAZ                              8
#define VIDERZH_VREM_MTZ2_S_PUSKOM_PO_U                         9
#define VIDERZH_VVODA_USK_MTZ2                                  10
#define VIDERZH_USK_MTZ2_VV                                     11
#define VIDERZH_USK_MTZ2_OU                                     12
#define VIDERZH_USK_MTZ2_TU                                     13
#define VIDERZH_USK_MTZ2_NAPR_VPER_VV                           14
#define VIDERZH_USK_MTZ2_NAPR_VPER_OU                           15
#define VIDERZH_USK_MTZ2_NAPR_VPER_TU                           16
#define VIDERZH_USK_MTZ2_NAPR_NAZ_VV                            17
#define VIDERZH_USK_MTZ2_NAPR_NAZ_OU                            18
#define VIDERZH_USK_MTZ2_NAPR_NAZ_TU                            19
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_VV                       20
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_OU                       21
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_TU                       22




#define USTAV_MTZ2_KMIN 50
#define USTAV_MTZ2_NAPR_VPER_KMIN 50
#define USTAV_MTZ2_NAPR_NAZ_KMIN 50
#define USTAV_MTZ2_S_PUSKOM_PO_U_KMIN 50
#define U_PUSKA_MTZ2_KMIN 200
#define UGOL_POVOR_ZONY_SRAB_MTZ2_KMIN 0
#define VIDERZH_VREM_MTZ2_KMIN 0
#define VIDERZH_VREM_MTZ2_NAPR_VPER_KMIN 0
#define VIDERZH_VREM_MTZ2_NAPR_NAZ_KMIN 0
#define VIDERZH_VREM_MTZ2_S_PUSKOM_PO_U_KMIN 0
#define VIDERZH_VVODA_USK_MTZ2_KMIN 0
#define VIDERZH_USK_MTZ2_VV_KMIN 0
#define VIDERZH_USK_MTZ2_OU_KMIN 0
#define VIDERZH_USK_MTZ2_TU_KMIN 0
#define VIDERZH_USK_MTZ2_NAPR_VPER_VV_KMIN 0
#define VIDERZH_USK_MTZ2_NAPR_VPER_OU_KMIN 0
#define VIDERZH_USK_MTZ2_NAPR_VPER_TU_KMIN 0
#define VIDERZH_USK_MTZ2_NAPR_NAZ_VV_KMIN 0
#define VIDERZH_USK_MTZ2_NAPR_NAZ_OU_KMIN 0
#define VIDERZH_USK_MTZ2_NAPR_NAZ_TU_KMIN 0
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_VV_KMIN 0
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_OU_KMIN 0
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_TU_KMIN 0

#define USTAV_MTZ2_KMAX 15000
#define USTAV_MTZ2_NAPR_VPER_KMAX 15000
#define USTAV_MTZ2_NAPR_NAZ_KMAX 15000
#define USTAV_MTZ2_S_PUSKOM_PO_U_KMAX 15000
#define U_PUSKA_MTZ2_KMAX 15000
#define UGOL_POVOR_ZONY_SRAB_MTZ2_KMAX 90
#define VIDERZH_VREM_MTZ2_KMAX 3200
#define VIDERZH_VREM_MTZ2_NAPR_VPER_KMAX 3200
#define VIDERZH_VREM_MTZ2_NAPR_NAZ_KMAX 3200
#define VIDERZH_VREM_MTZ2_S_PUSKOM_PO_U_KMAX 3200
#define VIDERZH_VVODA_USK_MTZ2_KMAX 500
#define VIDERZH_USK_MTZ2_VV_KMAX 500
#define VIDERZH_USK_MTZ2_OU_KMAX 500
#define VIDERZH_USK_MTZ2_TU_KMAX 500
#define VIDERZH_USK_MTZ2_NAPR_VPER_VV_KMAX 500
#define VIDERZH_USK_MTZ2_NAPR_VPER_OU_KMAX 500
#define VIDERZH_USK_MTZ2_NAPR_VPER_TU_KMAX 500
#define VIDERZH_USK_MTZ2_NAPR_NAZ_VV_KMAX 500
#define VIDERZH_USK_MTZ2_NAPR_NAZ_OU_KMAX 500
#define VIDERZH_USK_MTZ2_NAPR_NAZ_TU_KMAX 500
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_VV_KMAX 500
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_OU_KMAX 500
#define VIDERZH_USK_MTZ2_S_PUSKOM_PO_U_TU_KMAX 500




#define START_ADDR_MTZ3                      33
#define G1_START_ADDR_MTZ3                   PERVAYA_GRUPPA_USTAVOK + START_ADDR_MTZ3
#define G2_START_ADDR_MTZ3                   VTORAYA_GRUPPA_USTAVOK + START_ADDR_MTZ3
#define G3_START_ADDR_MTZ3                   TRETYA_GRUPPA_USTAVOK + START_ADDR_MTZ3
#define G4_START_ADDR_MTZ3                   CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_MTZ3

#define START_ADDR_MTZ4                      56
#define G1_START_ADDR_MTZ4                   PERVAYA_GRUPPA_USTAVOK + START_ADDR_MTZ4
#define G2_START_ADDR_MTZ4                   VTORAYA_GRUPPA_USTAVOK + START_ADDR_MTZ4
#define G3_START_ADDR_MTZ4                   TRETYA_GRUPPA_USTAVOK + START_ADDR_MTZ4
#define G4_START_ADDR_MTZ4                   CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_MTZ4

#define START_ADDR_MTZ5                      79
#define G1_START_ADDR_MTZ5                   PERVAYA_GRUPPA_USTAVOK + START_ADDR_MTZ5
#define G2_START_ADDR_MTZ5                   VTORAYA_GRUPPA_USTAVOK + START_ADDR_MTZ5
#define G3_START_ADDR_MTZ5                   TRETYA_GRUPPA_USTAVOK + START_ADDR_MTZ5
#define G4_START_ADDR_MTZ5                   CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_MTZ5



#define START_ADDR_ZOP                       252
#define G1_START_ADDR_ZOP                    PERVAYA_GRUPPA_USTAVOK + START_ADDR_ZOP
#define G2_START_ADDR_ZOP                    VTORAYA_GRUPPA_USTAVOK + START_ADDR_ZOP
#define G3_START_ADDR_ZOP                    TRETYA_GRUPPA_USTAVOK + START_ADDR_ZOP
#define G4_START_ADDR_ZOP                    CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_ZOP


#define I_DLYA_ZOP1_PRYAM                                       0
#define U_DLYA_ZOP1_PRYAM                                       1
#define I_DLYA_ZOP1_OBR                                         2
#define U_DLYA_ZOP1_OBR                                         3
#define UGOL_POVOROTA_ZOP1                                      4
#define VIDERZH_ZOP1                                            5
#define VIDERZH_ZOP1_VPER                                       6
#define VIDERZH_ZOP1_NAZ                                        7
#define I_DLYA_ZOP2_PRYAM                                       8
#define U_DLYA_ZOP2_PRYAM                                       9
#define I_DLYA_ZOP2_OBR                                         10
#define U_DLYA_ZOP2_OBR                                         11
#define UGOL_POVOR_ZOP2                                         12
#define VIDERZH_ZOP2                                            13
#define VIDERZH_ZOP2_VPER                                       14
#define VIDERZH_ZOP2_NAZ                                        15



#define I_DLYA_ZOP1_PRYAM_KMIN 25
#define U_DLYA_ZOP1_PRYAM_KMIN 1000
#define I_DLYA_ZOP1_OBR_KMIN 25
#define U_DLYA_ZOP1_OBR_KMIN 1000
#define UGOL_POVOROTA_ZOP1_KMIN 0
#define VIDERZH_ZOP1_KMIN 0
#define VIDERZH_ZOP1_VPER_KMIN 0
#define VIDERZH_ZOP1_NAZ_KMIN 0
#define I_DLYA_ZOP2_PRYAM_KMIN 25
#define U_DLYA_ZOP2_PRYAM_KMIN 1000
#define I_DLYA_ZOP2_OBR_KMIN 25
#define U_DLYA_ZOP2_OBR_KMIN 1000
#define UGOL_POVOR_ZOP2_KMIN 0
#define VIDERZH_ZOP2_KMIN 0
#define VIDERZH_ZOP2_VPER_KMIN 0
#define VIDERZH_ZOP2_NAZ_KMIN 0

#define I_DLYA_ZOP1_PRYAM_KMAX 5000
#define U_DLYA_ZOP1_PRYAM_KMAX 15000
#define I_DLYA_ZOP1_OBR_KMAX 5000
#define U_DLYA_ZOP1_OBR_KMAX 15000
#define UGOL_POVOROTA_ZOP1_KMAX 90
#define VIDERZH_ZOP1_KMAX 3200
#define VIDERZH_ZOP1_VPER_KMAX 3200
#define VIDERZH_ZOP1_NAZ_KMAX 3200
#define I_DLYA_ZOP2_PRYAM_KMAX 5000
#define U_DLYA_ZOP2_PRYAM_KMAX 15000
#define I_DLYA_ZOP2_OBR_KMAX 5000
#define U_DLYA_ZOP2_OBR_KMAX 15000
#define UGOL_POVOR_ZOP2_KMAX 90
#define VIDERZH_ZOP2_KMAX 3200
#define VIDERZH_ZOP2_VPER_KMAX 3200
#define VIDERZH_ZOP2_NAZ_KMAX 3200



#define START_ADDR_TZNP                                         268
#define G1_START_ADDR_TZNP                    PERVAYA_GRUPPA_USTAVOK + START_ADDR_TZNP
#define G2_START_ADDR_TZNP                    VTORAYA_GRUPPA_USTAVOK + START_ADDR_TZNP
#define G3_START_ADDR_TZNP                    TRETYA_GRUPPA_USTAVOK + START_ADDR_TZNP
#define G4_START_ADDR_TZNP                    CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_TZNP


#define USTAV_TZNP1_3I0                                         0
#define USTAV_TZNP1_3U0                                         1
#define UGOL_TZNP1_3I0                                          2
#define VIDERZH_TZNP1                                           3
#define VIDERZH_TZNP1_VV                                        4
#define VIDERZH_TZNP1_OU                                        5
#define VIDERZH_TZNP1_TU                                        6
#define VIDERZH_TZNP1_3I0                                       7
#define VIDERZH_TZNP1_3I0_VV                                    8
#define VIDERZH_TZNP1_3I0_OU                                    9
#define VIDERZH_TZNP1_3I0_TU                                    10
#define VIDERZH_TZNP1_3U0                                       11
#define DL_FORM_IMP_USK_TZNP1                                   12
#define USTAV_TZNP2_3I0                                         13
#define USTAV_TZNP2_3U0                                         14
#define UGOL_TZNP2_3I0                                          15
#define VIDERZH_TZNP2                                           16
#define VIDERZH_TZNP2_VV                                        17
#define VIDERZH_TZNP2_OU                                        18
#define VIDERZH_TZNP2_TU                                        19
#define VIDERZH_TZNP2_3I0                                       20
#define VIDERZH_TZNP2_3I0_VV                                    21
#define VIDERZH_TZNP2_3I0_OU                                    22
#define VIDERZH_TZNP2_3I0_TU                                    23
#define VIDERZH_TZNP2_3U0                                       24
#define DL_FORM_IMP_USK_TZNP2                                   25
#define USTAV_TZNP3_3I0                                         26
#define USTAV_TZNP3_3U0                                         27
#define UGOL_TZNP3_3I0                                          28
#define VIDERZH_TZNP3                                           29
#define VIDERZH_TZNP3_VV                                        30
#define VIDERZH_TZNP3_OU                                        31
#define VIDERZH_TZNP3_TU                                        32
#define VIDERZH_TZNP3_3I0                                       33
#define VIDERZH_TZNP3_3I0_VV                                    34
#define VIDERZH_TZNP3_3I0_OU                                    35
#define VIDERZH_TZNP3_3I0_TU                                    36
#define VIDERZH_TZNP3_3U0                                       37
#define DL_FORM_IMP_USK_TZNP3                                   38
#define USTAV_TZNP4_3I0                                         39
#define USTAV_TZNP4_3U0                                         40
#define UGOL_TZNP4_3I0                                          41
#define VIDERZH_TZNP4                                           42
#define VIDERZH_TZNP4_VV                                        43
#define VIDERZH_TZNP4_OU                                        44
#define VIDERZH_TZNP4_TU                                        45
#define VIDERZH_TZNP4_3I0                                       46
#define VIDERZH_TZNP4_3I0_VV                                    47
#define VIDERZH_TZNP4_3I0_OU                                    48
#define VIDERZH_TZNP4_3I0_TU                                    49
#define VIDERZH_TZNP4_3U0                                       50
#define DL_FORM_IMP_USK_TZNP4                                   51
#define USTAV_TZNP5_3I0                                         52
#define USTAV_TZNP5_3U0                                         53
#define UGOL_TZNP5_3I0                                          54
#define VIDERZH_TZNP5                                           55
#define VIDERZH_TZNP5_VV                                        56
#define VIDERZH_TZNP5_OU                                        57
#define VIDERZH_TZNP5_TU                                        58
#define VIDERZH_TZNP5_3I0                                       59
#define VIDERZH_TZNP5_3I0_VV                                    60
#define VIDERZH_TZNP5_3I0_OU                                    61
#define VIDERZH_TZNP5_3I0_TU                                    62
#define VIDERZH_TZNP5_3U0                                       63
#define DL_FORM_IMP_USK_TZNP5                                   64



#define USTAV_TZNP1_3I0_KMIN 25
#define USTAV_TZNP1_3U0_KMIN 1000
#define UGOL_TZNP1_3I0_KMIN 0
#define VIDERZH_TZNP1_KMIN 0
#define VIDERZH_TZNP1_VV_KMIN 0
#define VIDERZH_TZNP1_OU_KMIN 0
#define VIDERZH_TZNP1_TU_KMIN 0
#define VIDERZH_TZNP1_3I0_KMIN 0
#define VIDERZH_TZNP1_3I0_VV_KMIN 0
#define VIDERZH_TZNP1_3I0_OU_KMIN 0
#define VIDERZH_TZNP1_3I0_TU_KMIN 0
#define VIDERZH_TZNP1_3U0_KMIN 0
#define DL_FORM_IMP_USK_TZNP1_KMIN 0
#define USTAV_TZNP2_3I0_KMIN 25
#define USTAV_TZNP2_3U0_KMIN 1000
#define UGOL_TZNP2_3I0_KMIN 0
#define VIDERZH_TZNP2_KMIN 0
#define VIDERZH_TZNP2_VV_KMIN 0
#define VIDERZH_TZNP2_OU_KMIN 0
#define VIDERZH_TZNP2_TU_KMIN 0
#define VIDERZH_TZNP2_3I0_KMIN 0
#define VIDERZH_TZNP2_3I0_VV_KMIN 0
#define VIDERZH_TZNP2_3I0_OU_KMIN 0
#define VIDERZH_TZNP2_3I0_TU_KMIN 0
#define VIDERZH_TZNP2_3U0_KMIN 0
#define DL_FORM_IMP_USK_TZNP2_KMIN 0
#define USTAV_TZNP3_3I0_KMIN 25
#define USTAV_TZNP3_3U0_KMIN 1000
#define UGOL_TZNP3_3I0_KMIN 0
#define VIDERZH_TZNP3_KMIN 0
#define VIDERZH_TZNP3_VV_KMIN 0
#define VIDERZH_TZNP3_OU_KMIN 0
#define VIDERZH_TZNP3_TU_KMIN 0
#define VIDERZH_TZNP3_3I0_KMIN 0
#define VIDERZH_TZNP3_3I0_VV_KMIN 0
#define VIDERZH_TZNP3_3I0_OU_KMIN 0
#define VIDERZH_TZNP3_3I0_TU_KMIN 0
#define VIDERZH_TZNP3_3U0_KMIN 0
#define DL_FORM_IMP_USK_TZNP3_KMIN 0
#define USTAV_TZNP4_3I0_KMIN 25
#define USTAV_TZNP4_3U0_KMIN 1000
#define UGOL_TZNP4_3I0_KMIN 0
#define VIDERZH_TZNP4_KMIN 0
#define VIDERZH_TZNP4_VV_KMIN 0
#define VIDERZH_TZNP4_OU_KMIN 0
#define VIDERZH_TZNP4_TU_KMIN 0
#define VIDERZH_TZNP4_3I0_KMIN 0
#define VIDERZH_TZNP4_3I0_VV_KMIN 0
#define VIDERZH_TZNP4_3I0_OU_KMIN 0
#define VIDERZH_TZNP4_3I0_TU_KMIN 0
#define VIDERZH_TZNP4_3U0_KMIN 0
#define DL_FORM_IMP_USK_TZNP4_KMIN 0
#define USTAV_TZNP5_3I0_KMIN 25
#define USTAV_TZNP5_3U0_KMIN 1000
#define UGOL_TZNP5_3I0_KMIN 0
#define VIDERZH_TZNP5_KMIN 0
#define VIDERZH_TZNP5_VV_KMIN 0
#define VIDERZH_TZNP5_OU_KMIN 0
#define VIDERZH_TZNP5_TU_KMIN 0
#define VIDERZH_TZNP5_3I0_KMIN 0
#define VIDERZH_TZNP5_3I0_VV_KMIN 0
#define VIDERZH_TZNP5_3I0_OU_KMIN 0
#define VIDERZH_TZNP5_3I0_TU_KMIN 0
#define VIDERZH_TZNP5_3U0_KMIN 0
#define DL_FORM_IMP_USK_TZNP5_KMIN 0

#define USTAV_TZNP1_3I0_KMAX 15000
#define USTAV_TZNP1_3U0_KMAX 15000
#define UGOL_TZNP1_3I0_KMAX 90
#define VIDERZH_TZNP1_KMAX 3200
#define VIDERZH_TZNP1_VV_KMAX 1000
#define VIDERZH_TZNP1_OU_KMAX 1000
#define VIDERZH_TZNP1_TU_KMAX 1000
#define VIDERZH_TZNP1_3I0_KMAX 3200
#define VIDERZH_TZNP1_3I0_VV_KMAX 1000
#define VIDERZH_TZNP1_3I0_OU_KMAX 1000
#define VIDERZH_TZNP1_3I0_TU_KMAX 1000
#define VIDERZH_TZNP1_3U0_KMAX 3200
#define DL_FORM_IMP_USK_TZNP1_KMAX 1000
#define USTAV_TZNP2_3I0_KMAX 15000
#define USTAV_TZNP2_3U0_KMAX 15000
#define UGOL_TZNP2_3I0_KMAX 90
#define VIDERZH_TZNP2_KMAX 3200
#define VIDERZH_TZNP2_VV_KMAX 1000
#define VIDERZH_TZNP2_OU_KMAX 1000
#define VIDERZH_TZNP2_TU_KMAX 1000
#define VIDERZH_TZNP2_3I0_KMAX 3200
#define VIDERZH_TZNP2_3I0_VV_KMAX 1000
#define VIDERZH_TZNP2_3I0_OU_KMAX 1000
#define VIDERZH_TZNP2_3I0_TU_KMAX 1000
#define VIDERZH_TZNP2_3U0_KMAX 3200
#define DL_FORM_IMP_USK_TZNP2_KMAX 1000
#define USTAV_TZNP3_3I0_KMAX 15000
#define USTAV_TZNP3_3U0_KMAX 15000
#define UGOL_TZNP3_3I0_KMAX 90
#define VIDERZH_TZNP3_KMAX 3200
#define VIDERZH_TZNP3_VV_KMAX 1000
#define VIDERZH_TZNP3_OU_KMAX 1000
#define VIDERZH_TZNP3_TU_KMAX 1000
#define VIDERZH_TZNP3_3I0_KMAX 3200
#define VIDERZH_TZNP3_3I0_VV_KMAX 1000
#define VIDERZH_TZNP3_3I0_OU_KMAX 1000
#define VIDERZH_TZNP3_3I0_TU_KMAX 1000
#define VIDERZH_TZNP3_3U0_KMAX 3200
#define DL_FORM_IMP_USK_TZNP3_KMAX 1000
#define USTAV_TZNP4_3I0_KMAX 15000
#define USTAV_TZNP4_3U0_KMAX 15000
#define UGOL_TZNP4_3I0_KMAX 90
#define VIDERZH_TZNP4_KMAX 3200
#define VIDERZH_TZNP4_VV_KMAX 1000
#define VIDERZH_TZNP4_OU_KMAX 1000
#define VIDERZH_TZNP4_TU_KMAX 1000
#define VIDERZH_TZNP4_3I0_KMAX 3200
#define VIDERZH_TZNP4_3I0_VV_KMAX 1000
#define VIDERZH_TZNP4_3I0_OU_KMAX 1000
#define VIDERZH_TZNP4_3I0_TU_KMAX 1000
#define VIDERZH_TZNP4_3U0_KMAX 3200
#define DL_FORM_IMP_USK_TZNP4_KMAX 1000
#define USTAV_TZNP5_3I0_KMAX 15000
#define USTAV_TZNP5_3U0_KMAX 15000
#define UGOL_TZNP5_3I0_KMAX 90
#define VIDERZH_TZNP5_KMAX 3200
#define VIDERZH_TZNP5_VV_KMAX 1000
#define VIDERZH_TZNP5_OU_KMAX 1000
#define VIDERZH_TZNP5_TU_KMAX 1000
#define VIDERZH_TZNP5_3I0_KMAX 3200
#define VIDERZH_TZNP5_3I0_VV_KMAX 1000
#define VIDERZH_TZNP5_3I0_OU_KMAX 1000
#define VIDERZH_TZNP5_3I0_TU_KMAX 1000
#define VIDERZH_TZNP5_3U0_KMAX 3200
#define DL_FORM_IMP_USK_TZNP5_KMAX 1000





#define START_ADDR_ZNMIN                                        333
#define G1_START_ADDR_ZNMIN                    PERVAYA_GRUPPA_USTAVOK + START_ADDR_ZNMIN
#define G2_START_ADDR_ZNMIN                    VTORAYA_GRUPPA_USTAVOK + START_ADDR_ZNMIN
#define G3_START_ADDR_ZNMIN                    TRETYA_GRUPPA_USTAVOK + START_ADDR_ZNMIN
#define G4_START_ADDR_ZNMIN                    CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_ZNMIN

#define USTAV_ZNMIN1                                            0
#define VIDERZH_ZNMIN1                                          1
#define BLOKIR_ZNMIN1_PO_I                                      2
#define USTAV_ZNMIN2                                            3
#define VIDERZH_ZNMIN2                                          4
#define BLOKIR_ZNMIN2_PO_I                                      5




#define USTAV_ZNMIN1_KMIN 1400
#define VIDERZH_ZNMIN1_KMIN 10
#define BLOKIR_ZNMIN1_PO_I_KMIN 25
#define USTAV_ZNMIN2_KMIN 1400
#define VIDERZH_ZNMIN2_KMIN 10
#define BLOKIR_ZNMIN2_PO_I_KMIN 25

#define USTAV_ZNMIN1_KMAX 11000
#define VIDERZH_ZNMIN1_KMAX 3200
#define BLOKIR_ZNMIN1_PO_I_KMAX 500
#define USTAV_ZNMIN2_KMAX 11000
#define VIDERZH_ZNMIN2_KMAX 3200
#define BLOKIR_ZNMIN2_PO_I_KMAX 500




#define START_ADDR_ZNMAX                                        339
#define G1_START_ADDR_ZNMAX                    PERVAYA_GRUPPA_USTAVOK + START_ADDR_ZNMAX
#define G2_START_ADDR_ZNMAX                    VTORAYA_GRUPPA_USTAVOK + START_ADDR_ZNMAX
#define G3_START_ADDR_ZNMAX                    TRETYA_GRUPPA_USTAVOK + START_ADDR_ZNMAX
#define G4_START_ADDR_ZNMAX                    CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_ZNMAX


#define USTAV_ZNMAX1                                            0
#define VIDERZH_ZNMAX1                                          1
#define USTAV_ZNMAX2                                            2
#define VIDERZH_ZNMAX2                                          3




#define USTAV_ZNMAX1_KMIN 2500
#define VIDERZH_ZNMAX1_KMIN 10
#define USTAV_ZNMAX2_KMIN 2500
#define VIDERZH_ZNMAX2_KMIN 10

#define USTAV_ZNMAX1_KMAX 11000
#define VIDERZH_ZNMAX1_KMAX 3200
#define USTAV_ZNMAX2_KMAX 11000
#define VIDERZH_ZNMAX2_KMAX 3200



#define START_ADDR_APV                                          343
#define G1_START_ADDR_APV                      PERVAYA_GRUPPA_USTAVOK + START_ADDR_APV
#define G2_START_ADDR_APV                      VTORAYA_GRUPPA_USTAVOK + START_ADDR_APV
#define G3_START_ADDR_APV                      TRETYA_GRUPPA_USTAVOK + START_ADDR_APV
#define G4_START_ADDR_APV                      CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_APV


#define PO_APV1                                                 0
#define PO_APV2                                                 1
#define PO_APV3                                                 2
#define PO_APV4                                                 3
#define RAZNICA_NAPR                                            4
#define UGOL_RASSOGL                                            5
#define SKOROST_SKOLZH                                          6
#define VIDERZH_OZH_U_APV1                                      7
#define VIDERZH_OZH_SINHR_APV1                                  8
#define VIDERZH_DL_BLOK_APV1                                    9
#define VIDERZH_DL_APV1                                         10
#define VIDERZH_DL_ZAPR_APV1                                    11
#define VIDERZH_DL_BLOK_APV_OT_VV                               12
#define VIDERZH_OZH_U_APV2                                      13
#define VIDERZH_OZH_SINHR_APV2                                  14
#define VIDERZH_DL_BLOK_APV2                                    15
#define VIDERZH_DL_APV2                                         16






#define PO_APV1_KMIN 4000
#define PO_APV2_KMIN 100
#define PO_APV3_KMIN 4000
#define PO_APV4_KMIN 100
#define RAZNICA_NAPR_KMIN 100
#define UGOL_RASSOGL_KMIN 5
#define SKOROST_SKOLZH_KMIN 50
#define VIDERZH_OZH_U_APV1_KMIN 0
#define VIDERZH_OZH_SINHR_APV1_KMIN 0
#define VIDERZH_DL_BLOK_APV1_KMIN 0
#define VIDERZH_DL_APV1_KMIN 0
#define VIDERZH_DL_ZAPR_APV1_KMIN 0
#define VIDERZH_DL_BLOK_APV_OT_VV_KMIN 0
#define VIDERZH_OZH_U_APV2_KMIN 0
#define VIDERZH_OZH_SINHR_APV2_KMIN 0
#define VIDERZH_DL_BLOK_APV2_KMIN 0
#define VIDERZH_DL_APV2_KMIN 0

#define PO_APV1_KMAX 14000
#define PO_APV2_KMAX 2000
#define PO_APV3_KMAX 14000
#define PO_APV4_KMAX 2000
#define RAZNICA_NAPR_KMAX 2000
#define UGOL_RASSOGL_KMAX 50
#define SKOROST_SKOLZH_KMAX 300
#define VIDERZH_OZH_U_APV1_KMAX 3200
#define VIDERZH_OZH_SINHR_APV1_KMAX 3200
#define VIDERZH_DL_BLOK_APV1_KMAX 3200
#define VIDERZH_DL_APV1_KMAX 3200
#define VIDERZH_DL_ZAPR_APV1_KMAX 3200
#define VIDERZH_DL_BLOK_APV_OT_VV_KMAX 3200
#define VIDERZH_OZH_U_APV2_KMAX 3200
#define VIDERZH_OZH_SINHR_APV2_KMAX 3200
#define VIDERZH_DL_BLOK_APV2_KMAX 3200
#define VIDERZH_DL_APV2_KMAX 3200





#define START_ADDR_UROV                                         360
#define G1_START_ADDR_UROV                     PERVAYA_GRUPPA_USTAVOK + START_ADDR_UROV
#define G2_START_ADDR_UROV                     VTORAYA_GRUPPA_USTAVOK + START_ADDR_UROV
#define G3_START_ADDR_UROV                     TRETYA_GRUPPA_USTAVOK + START_ADDR_UROV
#define G4_START_ADDR_UROV                     CHETVERTAYA_GRUPPA_USTAVOK + START_ADDR_UROV


#define USTAV_UROV1                                             0
#define VIDERZH_UROV1                                           1
#define VIDERZH_UROV2                                           2



#define USTAV_UROV1_KMIN 25
#define VIDERZH_UROV1_KMIN 0
#define VIDERZH_UROV2_KMIN 0

#define USTAV_UROV1_KMAX 500
#define VIDERZH_UROV1_KMAX 3200
#define VIDERZH_UROV2_KMAX 3200



#define G1_START_ADDR_MCP1                                         4308
#define G1_START_ADDR_MCP2                                         320
#define G1_START_ADDR_MCP3                                         335
#define G1_START_ADDR_MCP4                                         350
#define G1_START_ADDR_MCP5                                         365





/*************************  для Сокола begin  ********************************/


/************************ Уставки первой ступени ДЗ ***************************/
// Уставки однофазного КЗ 
#define G1_START_ADDR_STEP1_DP                                     380

#define STEP1_SING_PHASE_ACTIVE_RESISTANCE_P1                   0
#define STEP1_SING_PHASE_REACTIVE_RESISTANCE_P1                 1
#define STEP1_SING_PHASE_ACTIVE_RESISTANCE_P2                   2
#define STEP1_SING_PHASE_REACTIVE_RESISTANCE_P2                 3
#define STEP1_SING_PHASE_ACTIVE_RESISTANCE_P3                   4
#define STEP1_SING_PHASE_REACTIVE_RESISTANCE_P3                 5
#define STEP1_SING_PHASE_ACTIVE_RESISTANCE_P4                   6
#define STEP1_SING_PHASE_REACTIVE_RESISTANCE_P4                 7

// Уставки межфазного КЗ
#define STEP1_INTER_PHASE_ACTIVE_RESISTANCE_P1                  8
#define STEP1_INTER_PHASE_REACTIVE_RESISTANCE_P1                9
#define STEP1_INTER_PHASE_ACTIVE_RESISTANCE_P2                  10
#define STEP1_INTER_PHASE_REACTIVE_RESISTANCE_P2                11
#define STEP1_INTER_PHASE_ACTIVE_RESISTANCE_P3                  12
#define STEP1_INTER_PHASE_REACTIVE_RESISTANCE_P3                13
#define STEP1_INTER_PHASE_ACTIVE_RESISTANCE_P4                  14
#define STEP1_INTER_PHASE_REACTIVE_RESISTANCE_P4                15

#define STEP1_SETPOINT_CURRENT                                  16

// Выдержки первой ступени ДЗ
#define STEP1_TIME_STAGE_SING_PHASE                             17
#define STEP1_TIME_STAGE_INTER_PHASE                            18
#define STEP1_TIME_STAGE_OCP                                    19


//#define LAST_ADDR_STEP1_DP                                      400

/************************ Уставки второй ступени ДЗ ***************************/

// Уставки однофазного КЗ 
#define G1_START_ADDR_STEP2_DP                                     400

#define STEP2_SING_PHASE_ACTIVE_RESISTANCE_P1                   0
#define STEP2_SING_PHASE_REACTIVE_RESISTANCE_P1                 1
#define STEP2_SING_PHASE_ACTIVE_RESISTANCE_P2                   2
#define STEP2_SING_PHASE_REACTIVE_RESISTANCE_P2                 3
#define STEP2_SING_PHASE_ACTIVE_RESISTANCE_P3                   4
#define STEP2_SING_PHASE_REACTIVE_RESISTANCE_P3                 5
#define STEP2_SING_PHASE_ACTIVE_RESISTANCE_P4                   6
#define STEP2_SING_PHASE_REACTIVE_RESISTANCE_P4                 7

// Уставки межфазного КЗ
#define STEP2_INTER_PHASE_ACTIVE_RESISTANCE_P1                  8
#define STEP2_INTER_PHASE_REACTIVE_RESISTANCE_P1                9
#define STEP2_INTER_PHASE_ACTIVE_RESISTANCE_P2                  10
#define STEP2_INTER_PHASE_REACTIVE_RESISTANCE_P2                11
#define STEP2_INTER_PHASE_ACTIVE_RESISTANCE_P3                  12
#define STEP2_INTER_PHASE_REACTIVE_RESISTANCE_P3                13
#define STEP2_INTER_PHASE_ACTIVE_RESISTANCE_P4                  14
#define STEP2_INTER_PHASE_REACTIVE_RESISTANCE_P4                15

#define STEP2_SETPOINT_CURRENT                                  16

#define STEP2_COMPENSATION_INTPHASE_CURRENT                     17

// выдержки
#define STEP2_TIME_STAGE_SING_PHASE_OP_ACLT                     18
#define STEP2_TIME_STAGE_SING_PHASE_AUTO_ACLT                   19
#define STEP2_TIME_STAGE_SING_PHASE_ACLT                        20
#define STEP2_TIME_STAGE_SING_PHASE_TELE_ACLT                   21
#define STEP2_TIME_STAGE_SING_PHASE                             22

#define STEP2_TIME_STAGE_INTER_PHASE_OP_ACLT                    23
#define STEP2_TIME_STAGE_INTER_PHASE_AUTO_ACLT                  24
#define STEP2_TIME_STAGE_INTER_PHASE_ACLT                       25
#define STEP2_TIME_STAGE_INTER_PHASE_TELE_ACLT                  26
#define STEP2_TIME_STAGE_INTER_PHASE                            27

#define STEP2_TIME_STAGE_OCP_OP_ACLT                            28
#define STEP2_TIME_STAGE_OCP_AUTO_ACLT                          29
#define STEP2_TIME_STAGE_OCP_ACLT                               30
#define STEP2_TIME_STAGE_OCP_TELE_ACLT                          31
#define STEP2_TIME_STAGE_OCP                                    32

#define STEP2_TIME_STAGE_HWS_TAU_ACLT                           33
#define STEP2_TIME_STAGE_OCP_HWS_TAU_ACLT                       34

//#define LAST_ADDR_STEP2_DP                                      435



/******************************************************************************/
/*            Уставки третьей ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                      */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G1_START_ADDR_STEP3_DP                                     435
//#define LAST_ADDR_STEP3_DP                                      470

/******************************************************************************/
/*            Уставки четвертой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G1_START_ADDR_STEP4_DP                                     470
//#define LAST_ADDR_STEP4_DP                                      505

/******************************************************************************/
/*            Уставки четвертой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G1_START_ADDR_STEP5_DP                                     505
//#define LAST_ADDR_STEP5_DP                                      540

#define LAST_ADDR_SOKIL               539

/******************************  для Сокола end  ********************************/





/******************************************************************************/
/*                    Уставки первой ступени ЗОП                              */
/******************************************************************************/

#define G1_START_ADDR_NSP1                                         540

#define NSP_CURRENT                                             0
#define NSP_I2_FWD                                              1
#define NSP_U2_FWD                                              2
#define NSP_I2_RVRS                                             3
#define NSP_U2_RVRS                                             4

#define NSP_TIME_STAGE                                          5
#define NSP_TIME_STAGE_FWD                                      6
#define NSP_TIME_STAGE_RVRS                                     7

//#define LAST_ADDR_NSP1                                          548

/******************************************************************************/
/*                    Уставки второй ступени ЗОП (ГРАНИЦЫ)                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G1_START_ADDR_NSP2                                         548
//#define LAST_ADDR_NSP2                                          556

/******************************************************************************/
/*                               Уставки ЗНмин                                */
/******************************************************************************/
#define G1_START_ADDR_UMIN                                         556

#define TIME_STAGE_UMIN1                                        0
#define RANGE_UMIN1                                             1
#define RANGE_IBLCK_UMIN1                                       2
#define TIME_STAGE_UMIN2                                        3
#define RANGE_UMIN2                                             4
#define RANGE_IBLCK_UMIN2                                       5

//#define LAST_ADDR_UMIN                                          562

/******************************************************************************/
/*                               Уставки ЗНмакс                               */
/******************************************************************************/

#define G1_START_ADDR_UMAX                                         562

#define TIME_STAGE_UMAX1                                        0
#define RANGE_UMAX1                                             1
#define TIME_STAGE_UMAX2                                        2
#define RANGE_UMAX2                                             3

//#define LAST_ADDR_UMAX                                          566
/******************************************************************************/
/*                      Уставки ТЗНП первой ступени                           */
/******************************************************************************/

#define G1_START_ADDR_TZNP1                                        570

// уставки 
#define TZNP_ANGLE_ROTATION                                     0
#define TZNP_CURRENT                                            1
#define TZNP_VOLTAGE                                            2

// выдержки
#define TZNP_TIME                                               3
#define TZNP_TIME_STAGE_ACLT                                    4
#define TZNP_TIME_STAGE_3UO                                     5
#define TZNP_TIME_STAGE_3I0                                     6
#define TZNP_TIME_STAGE_ACLT_CURR                               7
#define TZNP_TIME_STAGE_TAU_ACLT                                8

//#define LAST_ADDR_TZNP1                                         579

/******************************************************************************/
/*                Уставки ТЗНП второй ступени (ГРАНИЦЫ)                       */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G1_START_ADDR_TZNP2                                        579
//#define LAST_ADDR_TZNP2                                         588

/******************************************************************************/
/*                Уставки ТЗНП третьей ступени (ГРАНИЦЫ)                      */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G1_START_ADDR_TZNP3                                        588
//#define LAST_ADDR_TZNP3                                         597

/******************************************************************************/
/*                Уставки ТЗНП четвертой ступени (ГРАНИЦЫ)                    */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G1_START_ADDR_TZNP4                                        597
//#define LAST_ADDR_TZNP4                                         606

/******************************************************************************/
/*                Уставки ТЗНП пятой ступени (ГРАНИЦЫ)                        */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G1_START_ADDR_TZNP5                                        606
//#define LAST_ADDR_TZNP5                                         615

/******************************************************************************/
/*                           Уставки АПВ                                      */
/******************************************************************************/
#define G1_START_ADDR_RCRL                                        615

//уставки
#define RCRL_U_OV_RANGE1                                        0
#define RCRL_U_OV_RANGE2                                        1
#define RCRL_U_OV_RANGE3                                        2
#define RCRL_U_OV_RANGE4                                        3
#define RCRL_DELTA_U                                            4
#define RCRL_DELTA_PHI                                          5
#define RCRL_DELTA_PHI_DT                                       6

//выдержки
#define RCRL1_TIME_STAGE_WAIT_U                                 7
#define RCRL1_TIME_STAGE_WAIT_SYNCRO                            8
#define RCRL1_TIME_STAGE_BLOCK                                  9
#define RCRL1_TIME_STAGE                                        10
#define RCRL1_TIME_STAGE_FORBID                                 11
#define RCRL_TIME_STAGE_BLOCK_HSW                               12
#define RCRL2_TIME_STAGE_WAIT_U                                 13
#define RCRL2_TIME_STAGE_WAIT_SYNCRO                            14
#define RCRL2_TIME_STAGE_BLOCK                                  15
#define RCRL2_TIME_STAGE                                        16

//#define LAST_ADDR_RCRL                                          632

/******************************************************************************/
/*                           Уставки УРОВ                                     */
/******************************************************************************/

#define G1_START_ADDR_BRF                                         632

//уставки 
#define BRF_CURRENT                                             0

//выдеркжи
#define BRF1_TIME_STAGE                                         1
#define BRF2_TIME_STAGE                                         2

//#define LAST_ADDR_BRF                                           635

/******************************************************************************/
/*                 Уставки Защиты от колебаний (межфазн)                      */
/******************************************************************************/

#define G1_START_ADDR_DFT_IF                                    639

//уставки 
#define DFT_IF_UP_BOUND_DFT_ZAB                                 0
#define DFT_IF_LOW_BOUND_DFT_ZAB                                1
#define DFT_IF_UP_BOUND_DFT_ZBC                                 2
#define DFT_IF_LOW_BOUND_DFT_ZBC                                3
#define DFT_IF_UP_BOUND_DFT_ZCA                                 4
#define DFT_IF_LOW_BOUND_DFT_ZCA                                5
#define DFT_IF_DELTA_ZAB                                        6
#define DFT_IF_DELTA_ZBC                                        7
#define DFT_IF_DELTA_ZCA                                        8
#define DFT_IF_COUNTER                                          9

//выдеркжи
#define DFT_IF_TIME_STAGE_TAB                                   10
#define DFT_IF_TIME_STAGE_TBC                                   11
#define DFT_IF_TIME_STAGE_TCA                                   12

//#define LAST_ADDR_DFT_IF                                      652
/******************************************************************************/
/*                Уставки Защиты от колебаний (однофазн)                      */
/******************************************************************************/

#define G1_START_ADDR_DFT_SF                                    652

//уставки 
#define DFT_SF_UP_BOUND_DFT_ZA                                  0
#define DFT_SF_LOW_BOUND_DFT_ZA                                 1
#define DFT_SF_UP_BOUND_DFT_ZB                                  2
#define DFT_SF_LOW_BOUND_DFT_ZB                                 3
#define DFT_SF_UP_BOUND_DFT_ZC                                  4
#define DFT_SF_LOW_BOUND_DFT_ZC                                 5
#define DFT_SF_DELTA_ZA                                         6
#define DFT_SF_DELTA_ZB                                         7
#define DFT_SF_DELTA_ZC                                         8
#define DFT_SF_COUNTER                                          9

//выдеркжи
#define DFT_SF_TIME_STAGE_TA                                    10
#define DFT_SF_TIME_STAGE_TB                                    11
#define DFT_SF_TIME_STAGE_TC                                    12

//#define LAST_ADDR_DFT_IF                                        665
/******************************************************************************/        
/*                       Конец первой группы уставок                          */
/******************************************************************************/

/******************************************************************************/
/* Ранжирование                                                               */
/******************************************************************************/

#define START_ADDR_RANKING_DO1                                  1000

#define LAST_ADDR_RANKING_DO1                                   1256

//-----------------------------------------------------------------------------

#define START_ADDR_RANKING_DI1                                  1260

#define LAST_ADDR_RANKING_DI1                                   1517


/******************************************************************************/
/*                       ВТОРАЯ ГРУППА УСТАВОК                                */
/******************************************************************************/
#define G2_ADDRESS_OFFSET                                       1290

/******************************************************************************/
/*                       Уставки МТЗ первой ступени                           */
/******************************************************************************/

#define G2_START_ADDR_MCP1                                      G1_START_ADDR_MCP1 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_MCP1                                        

/******************************************************************************/
/*                       Уставки МТЗ второй ступени                           */
/******************************************************************************/

#define G2_START_ADDR_MCP2                                      G1_START_ADDR_MCP2 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_MCP2                                         

/******************************************************************************/
/*                Уставки МТЗ третьей ступени (ГРАНИЦЫ)                       */
/*                  поля дублируются из второго этапа                         */
/******************************************************************************/

#define G2_START_ADDR_MCP3                                      G1_START_ADDR_MCP3 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_MCP3                                        

/******************************************************************************/
/*                Уставки МТЗ четвертой ступени (ГРАНИЦЫ)                     */
/*                  поля дублируются из второго этапа                         */
/******************************************************************************/

#define G2_START_ADDR_MCP4                                      G1_START_ADDR_MCP4 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_MCP4                                          

/******************************************************************************/
/*                Уставки МТЗ пятой ступени (ГРАНИЦЫ)                         */
/*                 поля дублируются из второго этапа                          */
/******************************************************************************/

#define G2_START_ADDR_MCP5                                      G1_START_ADDR_MCP5 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_MCP5                                          

/************************ Уставки первой ступени ДЗ ***************************/
// Уставки однофазного КЗ 
#define G2_START_ADDR_STEP1_DP                                  G1_START_ADDR_STEP1_DP + G2_ADDRESS_OFFSET
//#define LAST_ADDR_STEP1_DP                                      

/************************ Уставки второй ступени ДЗ ***************************/

// Уставки однофазного КЗ 
#define G2_START_ADDR_STEP2_DP                                  G1_START_ADDR_STEP2_DP + G2_ADDRESS_OFFSET
//#define LAST_ADDR_STEP2_DP                                      

/******************************************************************************/
/*            Уставки третьей ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                      */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G2_START_ADDR_STEP3_DP                                  G1_START_ADDR_STEP3_DP + G2_ADDRESS_OFFSET
//#define LAST_ADDR_STEP3_DP                                      

/******************************************************************************/
/*            Уставки четвертой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G2_START_ADDR_STEP4_DP                                  G1_START_ADDR_STEP4_DP + G2_ADDRESS_OFFSET
//#define LAST_ADDR_STEP4_DP                                      

/******************************************************************************/
/*            Уставки пятой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                        */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G2_START_ADDR_STEP5_DP                                  G1_START_ADDR_STEP5_DP + G2_ADDRESS_OFFSET
//#define LAST_ADDR_STEP5_DP                                      

/******************************************************************************/
/*                    Уставки первой ступени ЗОП                              */
/******************************************************************************/

#define G2_START_ADDR_NSP1                                      G1_START_ADDR_NSP1 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_NSP1                                          

/******************************************************************************/
/*                    Уставки второй ступени ЗОП (ГРАНИЦЫ)                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G2_START_ADDR_NSP2                                      G1_START_ADDR_NSP2 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_NSP2                                          

/******************************************************************************/
/*                               Уставки ЗНмин                                */
/******************************************************************************/
#define G2_START_ADDR_UMIN                                      G1_START_ADDR_UMIN + G2_ADDRESS_OFFSET
//#define LAST_ADDR_UMIN                                        

/******************************************************************************/
/*                               Уставки ЗНмакс                               */
/******************************************************************************/

#define G2_START_ADDR_UMAX                                      G1_START_ADDR_UMAX + G2_ADDRESS_OFFSET
//#define LAST_ADDR_UMAX                                        

/******************************************************************************/
/*                      Уставки ТЗНП первой ступени                           */
/******************************************************************************/

#define G2_START_ADDR_TZNP1                                     G1_START_ADDR_TZNP1 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP1                                        

/******************************************************************************/
/*                Уставки ТЗНП второй ступени (ГРАНИЦЫ)                       */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G2_START_ADDR_TZNP2                                     G1_START_ADDR_TZNP2 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP2                                        

/******************************************************************************/
/*                Уставки ТЗНП третьей ступени (ГРАНИЦЫ)                      */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G2_START_ADDR_TZNP3                                     G1_START_ADDR_TZNP3 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP3                                        

/******************************************************************************/
/*                Уставки ТЗНП четвертой ступени (ГРАНИЦЫ)                    */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G2_START_ADDR_TZNP4                                     G1_START_ADDR_TZNP4 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP4                                         

/******************************************************************************/
/*                Уставки ТЗНП пятой ступени (ГРАНИЦЫ)                        */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G2_START_ADDR_TZNP5                                     G1_START_ADDR_TZNP5 + G2_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP5                                        

/******************************************************************************/
/*                           Уставки АПВ                                      */
/******************************************************************************/
#define G2_START_ADDR_RCRL                                      G1_START_ADDR_RCRL + G2_ADDRESS_OFFSET
//#define LAST_ADDR_RCRL                                         

/******************************************************************************/
/*                           Уставки УРОВ                                     */
/******************************************************************************/

#define G2_START_ADDR_BRF                                       G1_START_ADDR_BRF + G2_ADDRESS_OFFSET
//#define LAST_ADDR_BRF                                          
/******************************************************************************/
/*                 Уставки Защиты от колебаний (межфазн)                      */
/******************************************************************************/

#define G2_START_ADDR_DFT_IF                                    G1_START_ADDR_DFT_IF + G2_ADDRESS_OFFSET
//#define LAST_ADDR_DFT_IF                                      
/******************************************************************************/
/*                Уставки Защиты от колебаний (однофазн)                      */
/******************************************************************************/

#define G2_START_ADDR_DFT_SF                                    G1_START_ADDR_DFT_SF + G2_ADDRESS_OFFSET
//#define LAST_ADDR_DFT_IF                                                  

//                      КОНЕЦ ВТОРОЙ ГРУППЫ УСТАВОК
/******************************************************************************/
/********************* ТРЕТЬЯ ГРУППА УСТАВОК **********************************/
/******************************************************************************/

#define G3_ADDRESS_OFFSET                                       1690

/******************************************************************************/
/*                       Уставки МТЗ первой ступени                           */
/******************************************************************************/

#define G3_START_ADDR_MCP1                                      G1_START_ADDR_MCP1 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_MCP1                                        

/******************************************************************************/
/*                       Уставки МТЗ второй ступени                           */
/******************************************************************************/

#define G3_START_ADDR_MCP2                                      G1_START_ADDR_MCP2 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_MCP2                                         

/******************************************************************************/
/*                Уставки МТЗ третьей ступени (ГРАНИЦЫ)                       */
/*                  поля дублируются из второго этапа                         */
/******************************************************************************/

#define G3_START_ADDR_MCP3                                      G1_START_ADDR_MCP3 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_MCP3                                        

/******************************************************************************/
/*                Уставки МТЗ четвертой ступени (ГРАНИЦЫ)                     */
/*                  поля дублируются из второго этапа                         */
/******************************************************************************/

#define G3_START_ADDR_MCP4                                      G1_START_ADDR_MCP4 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_MCP4                                          

/******************************************************************************/
/*                Уставки МТЗ пятой ступени (ГРАНИЦЫ)                         */
/*                 поля дублируются из второго этапа                          */
/******************************************************************************/

#define G3_START_ADDR_MCP5                                      G1_START_ADDR_MCP5 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_MCP5                                          

/************************ Уставки первой ступени ДЗ ***************************/
// Уставки однофазного КЗ 
#define G3_START_ADDR_STEP1_DP                                  G1_START_ADDR_STEP1_DP + G3_ADDRESS_OFFSET
//#define LAST_ADDR_STEP1_DP                                      

/************************ Уставки второй ступени ДЗ ***************************/

// Уставки однофазного КЗ 
#define G3_START_ADDR_STEP2_DP                                  G1_START_ADDR_STEP2_DP + G3_ADDRESS_OFFSET
//#define LAST_ADDR_STEP2_DP                                      

/******************************************************************************/
/*            Уставки третьей ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                      */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G3_START_ADDR_STEP3_DP                                  G1_START_ADDR_STEP3_DP + G3_ADDRESS_OFFSET
//#define LAST_ADDR_STEP3_DP                                      

/******************************************************************************/
/*            Уставки четвертой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G3_START_ADDR_STEP4_DP                                  G1_START_ADDR_STEP4_DP + G3_ADDRESS_OFFSET
//#define LAST_ADDR_STEP4_DP                                      

/******************************************************************************/
/*            Уставки пятой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                        */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G3_START_ADDR_STEP5_DP                                  G1_START_ADDR_STEP5_DP + G3_ADDRESS_OFFSET
//#define LAST_ADDR_STEP5_DP                                      

/******************************************************************************/
/*                    Уставки первой ступени ЗОП                              */
/******************************************************************************/

#define G3_START_ADDR_NSP1                                      G1_START_ADDR_NSP1 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_NSP1                                          

/******************************************************************************/
/*                    Уставки второй ступени ЗОП (ГРАНИЦЫ)                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G3_START_ADDR_NSP2                                      G1_START_ADDR_NSP2 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_NSP2                                          

/******************************************************************************/
/*                               Уставки ЗНмин                                */
/******************************************************************************/
#define G3_START_ADDR_UMIN                                      G1_START_ADDR_UMIN + G3_ADDRESS_OFFSET
//#define LAST_ADDR_UMIN                                        

/******************************************************************************/
/*                               Уставки ЗНмакс                               */
/******************************************************************************/

#define G3_START_ADDR_UMAX                                      G1_START_ADDR_UMAX + G3_ADDRESS_OFFSET
//#define LAST_ADDR_UMAX                                        

/******************************************************************************/
/*                      Уставки ТЗНП первой ступени                           */
/******************************************************************************/

#define G3_START_ADDR_TZNP1                                     G1_START_ADDR_TZNP1 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP1                                        

/******************************************************************************/
/*                Уставки ТЗНП второй ступени (ГРАНИЦЫ)                       */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G3_START_ADDR_TZNP2                                     G1_START_ADDR_TZNP2 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP2                                        

/******************************************************************************/
/*                Уставки ТЗНП третьей ступени (ГРАНИЦЫ)                      */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G3_START_ADDR_TZNP3                                     G1_START_ADDR_TZNP3 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP3                                        

/******************************************************************************/
/*                Уставки ТЗНП четвертой ступени (ГРАНИЦЫ)                    */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G3_START_ADDR_TZNP4                                     G1_START_ADDR_TZNP4 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP4                                         

/******************************************************************************/
/*                Уставки ТЗНП пятой ступени (ГРАНИЦЫ)                        */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G3_START_ADDR_TZNP5                                     G1_START_ADDR_TZNP5 + G3_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP5                                        

/******************************************************************************/
/*                           Уставки АПВ                                      */
/******************************************************************************/
#define G3_START_ADDR_RCRL                                      G1_START_ADDR_RCRL + G3_ADDRESS_OFFSET
//#define LAST_ADDR_RCRL                                         

/******************************************************************************/
/*                           Уставки УРОВ                                     */
/******************************************************************************/

#define G3_START_ADDR_BRF                                       G1_START_ADDR_BRF + G3_ADDRESS_OFFSET
//#define LAST_ADDR_BRF                                          
/******************************************************************************/
/*                 Уставки Защиты от колебаний (межфазн)                      */
/******************************************************************************/

#define G3_START_ADDR_DFT_IF                                    G1_START_ADDR_DFT_IF + G3_ADDRESS_OFFSET
//#define LAST_ADDR_DFT_IF                                      
/******************************************************************************/
/*                Уставки Защиты от колебаний (однофазн)                      */
/******************************************************************************/

#define G3_START_ADDR_DFT_SF                                    G1_START_ADDR_DFT_SF + G3_ADDRESS_OFFSET
//#define LAST_ADDR_DFT_IF                                                  

//                      КОНЕЦ ТРЕТЬЕЙ ГРУППЫ УСТАВОК
/******************************************************************************/

/******************************************************************************/
/********************* ЧЕТВЕРТАЯ ГРУППА УСТАВОК *******************************/
/******************************************************************************/
#define G4_ADDRESS_OFFSET                                       2190

/******************************************************************************/
/*                       Уставки МТЗ первой ступени                           */
/******************************************************************************/

#define G4_START_ADDR_MCP1                                      G1_START_ADDR_MCP1 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_MCP1                                        

/******************************************************************************/
/*                       Уставки МТЗ второй ступени                           */
/******************************************************************************/

#define G4_START_ADDR_MCP2                                      G1_START_ADDR_MCP2 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_MCP2                                         

/******************************************************************************/
/*                Уставки МТЗ третьей ступени (ГРАНИЦЫ)                       */
/*                  поля дублируются из второго этапа                         */
/******************************************************************************/

#define G4_START_ADDR_MCP3                                      G1_START_ADDR_MCP3 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_MCP3                                        

/******************************************************************************/
/*                Уставки МТЗ четвертой ступени (ГРАНИЦЫ)                     */
/*                  поля дублируются из второго этапа                         */
/******************************************************************************/

#define G4_START_ADDR_MCP4                                      G1_START_ADDR_MCP4 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_MCP4                                          

/******************************************************************************/
/*                Уставки МТЗ пятой ступени (ГРАНИЦЫ)                         */
/*                 поля дублируются из второго этапа                          */
/******************************************************************************/

#define G4_START_ADDR_MCP5                                      G1_START_ADDR_MCP5 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_MCP5                                          

/************************ Уставки первой ступени ДЗ ***************************/
// Уставки однофазного КЗ 
#define G4_START_ADDR_STEP1_DP                                  G1_START_ADDR_STEP1_DP + G4_ADDRESS_OFFSET
//#define LAST_ADDR_STEP1_DP                                      

/************************ Уставки второй ступени ДЗ ***************************/

// Уставки однофазного КЗ 
#define G4_START_ADDR_STEP2_DP                                  G1_START_ADDR_STEP2_DP + G4_ADDRESS_OFFSET
//#define LAST_ADDR_STEP2_DP                                      

/******************************************************************************/
/*            Уставки третьей ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                      */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G4_START_ADDR_STEP3_DP                                  G1_START_ADDR_STEP3_DP + G4_ADDRESS_OFFSET
//#define LAST_ADDR_STEP3_DP                                      

/******************************************************************************/
/*            Уставки четвертой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G4_START_ADDR_STEP4_DP                                  G1_START_ADDR_STEP4_DP + G4_ADDRESS_OFFSET
//#define LAST_ADDR_STEP4_DP                                      

/******************************************************************************/
/*            Уставки пятой ступени ДЗ. ТОЛЬКО ГРАНИЦЫ                        */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G4_START_ADDR_STEP5_DP                                  G1_START_ADDR_STEP5_DP + G4_ADDRESS_OFFSET
//#define LAST_ADDR_STEP5_DP                                      

/******************************************************************************/
/*                    Уставки первой ступени ЗОП                              */
/******************************************************************************/

#define G4_START_ADDR_NSP1                                      G1_START_ADDR_NSP1 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_NSP1                                          

/******************************************************************************/
/*                    Уставки второй ступени ЗОП (ГРАНИЦЫ)                    */
/*        Уставки и выдержки такие же, как во второй ступени                  */
/******************************************************************************/
#define G4_START_ADDR_NSP2                                      G1_START_ADDR_NSP2 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_NSP2                                          

/******************************************************************************/
/*                               Уставки ЗНмин                                */
/******************************************************************************/
#define G4_START_ADDR_UMIN                                      G1_START_ADDR_UMIN + G4_ADDRESS_OFFSET
//#define LAST_ADDR_UMIN                                        

/******************************************************************************/
/*                               Уставки ЗНмакс                               */
/******************************************************************************/

#define G4_START_ADDR_UMAX                                      G1_START_ADDR_UMAX + G4_ADDRESS_OFFSET
//#define LAST_ADDR_UMAX                                        

/******************************************************************************/
/*                      Уставки ТЗНП первой ступени                           */
/******************************************************************************/

#define G4_START_ADDR_TZNP1                                     G1_START_ADDR_TZNP1 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP1                                        

/******************************************************************************/
/*                Уставки ТЗНП второй ступени (ГРАНИЦЫ)                       */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G4_START_ADDR_TZNP2                                     G1_START_ADDR_TZNP2 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP2                                        

/******************************************************************************/
/*                Уставки ТЗНП третьей ступени (ГРАНИЦЫ)                      */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G4_START_ADDR_TZNP3                                     G1_START_ADDR_TZNP3 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP3                                        

/******************************************************************************/
/*                Уставки ТЗНП четвертой ступени (ГРАНИЦЫ)                    */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G4_START_ADDR_TZNP4                                     G1_START_ADDR_TZNP4 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP4                                         

/******************************************************************************/
/*                Уставки ТЗНП пятой ступени (ГРАНИЦЫ)                        */
/*                 поля дублируются из первого этапа                          */
/******************************************************************************/

#define G4_START_ADDR_TZNP5                                     G1_START_ADDR_TZNP5 + G4_ADDRESS_OFFSET
//#define LAST_ADDR_TZNP5                                        

/******************************************************************************/
/*                           Уставки АПВ                                      */
/******************************************************************************/
#define G4_START_ADDR_RCRL                                      G1_START_ADDR_RCRL + G4_ADDRESS_OFFSET
//#define LAST_ADDR_RCRL                                         

/******************************************************************************/
/*                           Уставки УРОВ                                     */
/******************************************************************************/

#define G4_START_ADDR_BRF                                       G1_START_ADDR_BRF + G4_ADDRESS_OFFSET
//#define LAST_ADDR_BRF                                          
/******************************************************************************/
/*                 Уставки Защиты от колебаний (межфазн)                      */
/******************************************************************************/

#define G4_START_ADDR_DFT_IF                                    G1_START_ADDR_DFT_IF + G4_ADDRESS_OFFSET
//#define LAST_ADDR_DFT_IF                                      
/******************************************************************************/
/*                Уставки Защиты от колебаний (однофазн)                      */
/******************************************************************************/

#define G4_START_ADDR_DFT_SF                                    G1_START_ADDR_DFT_SF + G4_ADDRESS_OFFSET
//#define LAST_ADDR_DFT_IF                                                  
//                      КОНЕЦ ЧЕТВЕРТОЙ ГРУППЫ УСТАВОК
/******************************************************************************/

/******************************************************************************/
/*                           Transformators                                   */
/******************************************************************************/
#define START_ADDR_TRASFORM                                     3000

#define TRANSF_TN1_COEF                                         0
#define TRANSF_TN2_COEF                                         1
#define TRANSF_TT_COEF                                          2
#define TRANSF_TO_COEF                                          3

//#define LAST_ADDR_TRANSFORM                                     3003

/******************************************************************************/
/*                    Breaker Unit Managing                                   */
/******************************************************************************/

#define START_ADDR_BRU_MNG                                      3004

#define BRU_TIME_STAGE_OFF_UNIT                                 0
#define BRU_TIME_STAGE_ON_UNIT                                  1
#define BRU_TIME_STAGE_ON_CTRL                                  2
#define BRU_TIME_STAGE_ON_UNIT_BLK                              3
#define BRU_TIME_STAGE_ACTUATOR_HVS                             4

//#define LAST_ADDR_BRU                                           3008

/******************************************************************************/
/*                   Calculation of BRU                                       */
/******************************************************************************/

#define START_ADDR_CALC_BRU                                     3009

#define CALC_BRU_INOM                                           0
#define CALC_BRU_RBR_INOM                                       1
#define CALC_BRU_IOFF_NOM                                       2
#define CALC_BRU_RBR_OFF_NOM                                    3
#define CALC_BRU_BEGRSCVAL                                      4
#define CALC_BRU_CRIT_RES                                       5
#define CALC_BRU_AMTSWTRIP                                      6

//#define LAST_ADDR_CALC_BRU                                    3015

/******************************************************************************/
/*                   Patameters of Dig.in/out                                 */
/******************************************************************************/
#define START_ADDR_PARAM_DIGIO                                  3016

#define TYPE_DIG_IN1_16                                         0
#define TYPE_DIG_IN17_32                                        1
#define TYPESIG_DIGIN1_16                                       2
#define TYPESIG_DIGIN17_32                                      3
#define TYPE_DIG_OUT                                            4
#define TYPE_FUNC


#define DURATION_DI1                                            5
#define DURATION_DI2                                            6
#define DURATION_DI3                                            7
#define DURATION_DI4                                            8
#define DURATION_DI5                                            9
#define DURATION_DI6                                            10
#define DURATION_DI7                                            11
#define DURATION_DI8                                            12
#define DURATION_DI9                                            13
#define DURATION_DI10                                           14
#define DURATION_DI11                                           15
#define DURATION_DI12                                           16
#define DURATION_DI13                                           17
#define DURATION_DI14                                           18
#define DURATION_DI15                                           19
#define DURATION_DI16                                           20
#define DURATION_DI17                                           21
#define DURATION_DI18                                           22
#define DURATION_DI19                                           23
#define DURATION_DI20                                           24
#define DURATION_DI21                                           25
#define DURATION_DI22                                           26
#define DURATION_DI23                                           27
#define DURATION_DI24                                           28
#define DURATION_DI25                                           29
#define DURATION_DI26                                           30
#define DURATION_DI27                                           31
#define DURATION_DI28                                           32
#define DURATION_DI29                                           33
#define DURATION_DI30                                           34
#define DURATION_DI31                                           35
#define DURATION_DI32                                           36

//#define LAST_ADDR_PARAM_DIGIO                                   3052

/******************************************************************************/
/* Углы                                                                       */
/******************************************************************************/
#define M_ADDRESS_FIRST_ANGLES                                  4000

#define OFFSET_ANGLE_IA_UBC                                     0
#define OFFSET_ANGLE_IB_UCA                                     1
#define OFFSET_ANGLE_IC_UAB                                     2
#define OFFSET_ANGLE_I2_U2                                      3
#define OFFSET_ANGLE_3I0_3U0                                    4
#define OFFSET_ANGLE_UNBALANCE                                  5

//Угол вектора сопротивления
#define OFFSET_RESISTANCE_ANGLE_ZAB                             6
#define OFFSET_RESISTANCE_ANGLE_ZBC                             7
#define OFFSET_RESISTANCE_ANGLE_ZCA                             8

#define OFFSET_RESISTANCE_ANGLE_ZA0_1ST                         9
#define OFFSET_RESISTANCE_ANGLE_ZB0_1ST                         10
#define OFFSET_RESISTANCE_ANGLE_ZC0_1ST                         11

#define OFFSET_RESISTANCE_ANGLE_ZA0_2ST                         12
#define OFFSET_RESISTANCE_ANGLE_ZB0_2ST                         13
#define OFFSET_RESISTANCE_ANGLE_ZC0_2ST                         14

#define OFFSET_RESISTANCE_ANGLE_ZA0_3ST                         15
#define OFFSET_RESISTANCE_ANGLE_ZB0_3ST                         16
#define OFFSET_RESISTANCE_ANGLE_ZC0_3ST                         17

#define OFFSET_RESISTANCE_ANGLE_ZA0_4ST                         18
#define OFFSET_RESISTANCE_ANGLE_ZB0_4ST                         19
#define OFFSET_RESISTANCE_ANGLE_ZC0_4ST                         20

#define OFFSET_RESISTANCE_ANGLE_ZA0_5ST                         21
#define OFFSET_RESISTANCE_ANGLE_ZB0_5ST                         22
#define OFFSET_RESISTANCE_ANGLE_ZC0_5ST                         23

//Углы для отображения веторов
#define OFFSET_VECTOR_ANGLE_IA                                  24
#define OFFSET_VECTOR_ANGLE_IB                                  25
#define OFFSET_VECTOR_ANGLE_IC                                  26
#define OFFSET_VECTOR_ANGLE_UB                                  27
#define OFFSET_VECTOR_ANGLE_UC                                  28
#define OFFSET_VECTOR_ANGLE_3U0                                 29
#define OFFSET_VECTOR_ANGLE_3I0                                 30
#define OFFSET_VECTOR_ANGLE_ISYN                                31
#define OFFSET_VECTOR_ANGLE_USYN                                32
#define OFFSET_VECTOR_ANGLE_UBC_TN2                             33

#define M_ADDRESS_LAST_ANGLES                                   4034
/******************************************************************************/

/******************************************************************************/
/* Попадание в зону срабатывания                                              */
/******************************************************************************/
#define M_ADDRESS_FIRST_SECTORS                                 4040

//Сектор отпускания
#define OFFSET_SECTOR_3I0_3U0_1                                 0
#define OFFSET_SECTOR_IA_UBC_1                                  1
#define OFFSET_SECTOR_IB_UCA_1                                  2
#define OFFSET_SECTOR_IC_UAB_1                                  3
#define OFFSET_SECTOR_I2_U2_1                                   4

//Сектор сработки
#define OFFSET_SECTOR_3I0_3U0_2                                 5
#define OFFSET_SECTOR_IA_UBC_2                                  6
#define OFFSET_SECTOR_IB_UCA_2                                  7
#define OFFSET_SECTOR_IC_UAB_2                                  8
#define OFFSET_SECTOR_I2_U2_2                                   9

#define OFFSET_SECTOR_3I0_3U0_3                                 10
#define OFFSET_SECTOR_IA_UBC_3                                  11
#define OFFSET_SECTOR_IB_UCA_3                                  12
#define OFFSET_SECTOR_IC_UAB_3                                  13
#define OFFSET_SECTOR_I2_U2_3                                   14

#define OFFSET_SECTOR_3I0_3U0_4                                 15
#define OFFSET_SECTOR_IA_UBC_4                                  16
#define OFFSET_SECTOR_IB_UCA_4                                  17
#define OFFSET_SECTOR_IC_UAB_4                                  18
#define OFFSET_SECTOR_I2_U2_4                                   19

#define OFFSET_SECTOR_3I0_3U0_5                                 20
#define OFFSET_SECTOR_IA_UBC_5                                  21
#define OFFSET_SECTOR_IB_UCA_5                                  22
#define OFFSET_SECTOR_IC_UAB_5                                  23
#define OFFSET_SECTOR_I2_U2_5                                   24

#define M_ADDRESS_LAST_SECTORS                                  4065
/******************************************************************************/

/******************************************************************************/
/* Другие измерения                                                           */
/******************************************************************************/
#define M_ADDRESS_FIRST_MEASUREMENTS_3                          4080

#define OFFSET_MEASUREMENT_3_F1                                 0
#define OFFSET_MEASUREMENT_3_F2                                 1
#define OFFSET_MEASUREMENT_3_DIAGNOSTICA                        2
#define OFFSET_MEASUREMENT_3_SPEED_ANGLE_CHANGE                 3
#define OFFSET_MEASUREMENT_3_LINEAR_CURRENT_IAB                 4
#define OFFSET_MEASUREMENT_3_LINEAR_CURRENT_IBC                 5
#define OFFSET_MEASUREMENT_3_LINEAR_CURRENT_ICA                 6
#define OFFSET_MEASUREMENT_3_LINEAR_CURRENT_UAB                 7
#define OFFSET_MEASUREMENT_3_LINEAR_CURRENT_UBC                 8
#define OFFSET_MEASUREMENT_3_LINEAR_CURRENT_UCA                 9
#define OFFSET_MEASUREMENT_3_VOLTAGE_DIFFERENCE                 10
#define OFFSET_MEASUREMENT_3_U_LINE                             11

#define OFFSET_MEASUREMENT_ACTIVE_POWER_A_Hi                    12
#define OFFSET_MEASUREMENT_ACTIVE_POWER_A_Lo                    13
#define OFFSET_MEASUREMENT_ACTIVE_POWER_B_Hi                    14
#define OFFSET_MEASUREMENT_ACTIVE_POWER_B_Lo                    15
#define OFFSET_MEASUREMENT_ACTIVE_POWER_C_Hi                    16
#define OFFSET_MEASUREMENT_ACTIVE_POWER_C_Lo                    17

#define OFFSET_MEASUREMENT_REACTIVE_POWER_A_Hi                  18
#define OFFSET_MEASUREMENT_REACTIVE_POWER_A_Lo                  19
#define OFFSET_MEASUREMENT_REACTIVE_POWER_B_Hi                  20
#define OFFSET_MEASUREMENT_REACTIVE_POWER_B_Lo                  21
#define OFFSET_MEASUREMENT_REACTIVE_POWER_C_Hi                  22
#define OFFSET_MEASUREMENT_REACTIVE_POWER_C_Lo                  23

#define OFFSET_MEASUREMENT_FULL_POWER_A_Hi                      24
#define OFFSET_MEASUREMENT_FULL_POWER_A_Lo                      25
#define OFFSET_MEASUREMENT_FULL_POWER_B_Hi                      26
#define OFFSET_MEASUREMENT_FULL_POWER_B_Lo                      27
#define OFFSET_MEASUREMENT_FULL_POWER_C_Hi                      28
#define OFFSET_MEASUREMENT_FULL_POWER_C_Lo                      29

#define OFFSET_MEASUREMENT_SUM_POWER_A_Hi                       30
#define OFFSET_MEASUREMENT_SUM_POWER_A_Lo                       31
#define OFFSET_MEASUREMENT_SUM_POWER_B_Hi                       32
#define OFFSET_MEASUREMENT_SUM_POWER_B_Lo                       33
#define OFFSET_MEASUREMENT_SUM_POWER_C_Hi                       34
#define OFFSET_MEASUREMENT_SUM_POWER_C_Lo                       35

//float (little indian)
#define OFFSET_MEASUREMENT_POWER_COEFFICIENT_A_Lo               36
#define OFFSET_MEASUREMENT_POWER_COEFFICIENT_A_Hi               37
#define OFFSET_MEASUREMENT_POWER_COEFFICIENT_B_Lo               38
#define OFFSET_MEASUREMENT_POWER_COEFFICIENT_B_Hi               39
#define OFFSET_MEASUREMENT_POWER_COEFFICIENT_C_Lo               40
#define OFFSET_MEASUREMENT_POWER_COEFFICIENT_C_Hi               41

//float (000,0000000)? (little indian)
#define OFFSET_MEASUREMENT_ACTIVE_POWER_PLUS_Lo                 42
#define OFFSET_MEASUREMENT_ACTIVE_POWER_PLUS_Hi                 43
#define OFFSET_MEASUREMENT_ACTIVE_POWER_MINUS_Lo                44
#define OFFSET_MEASUREMENT_ACTIVE_POWER_MINUS_Hi                45
#define OFFSET_MEASUREMENT_REACTIVE_POWER_1Q_Lo                 46
#define OFFSET_MEASUREMENT_REACTIVE_POWER_1Q_Hi                 47
#define OFFSET_MEASUREMENT_REACTIVE_POWER_2Q_Lo                 48
#define OFFSET_MEASUREMENT_REACTIVE_POWER_2Q_Hi                 49
#define OFFSET_MEASUREMENT_REACTIVE_POWER_3Q_Lo                 50
#define OFFSET_MEASUREMENT_REACTIVE_POWER_3Q_Hi                 51
#define OFFSET_MEASUREMENT_REACTIVE_POWER_4Q_Lo                 52
#define OFFSET_MEASUREMENT_REACTIVE_POWER_4Q_Hi                 53

//Скорость изменения сопротивления
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zab_Hi       54
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zab_Lo       55
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zbc_Hi       56
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zbc_Lo       57
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zca_Hi       58
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zca_Lo       59

#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Hi_1ST   60
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Lo_1ST   61
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Hi_1ST   62
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Lo_1ST   63
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Hi_1ST   64
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Lo_1ST   65

#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Hi_2ST   66
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Lo_2ST   67
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Hi_2ST   68
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Lo_2ST   69
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Hi_2ST   70
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Lo_2ST   71

#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Hi_3ST   72
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Lo_3ST   73
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Hi_3ST   74
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Lo_3ST   75
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Hi_3ST   76
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Lo_3ST   77

#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Hi_4ST   78
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Lo_4ST   79
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Hi_4ST   80
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Lo_4ST   81
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Hi_4ST   82
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Lo_4ST   83

#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Hi_5ST   84
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Za0_Lo_5ST   85
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Hi_5ST   86
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zb0_Lo_5ST   87
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Hi_5ST   88
#define OFFSET_MEASUREMENT_SPEED_RESISTANCE_CHANGE_Zc0_Lo_5ST   89

#define M_ADDRESS_LAST_MEASUREMENTS_3                           4170
/******************************************************************************/




/*************************  для Сокола begin  ********************************/

/******************************************************************************/
/* Значения с плавающей запятой                                               */
/******************************************************************************/
#define M_ADDRESS_FIRST_FLOATING_MEASUREMENTS                   4200

//Комплексные межфазные сопротивления (little indian)
#define OFFSET_FLOATING_MEASUREMENTS_ZAB_RE_Lo                  0
#define OFFSET_FLOATING_MEASUREMENTS_ZAB_RE_Hi                  1
#define OFFSET_FLOATING_MEASUREMENTS_ZAB_IM_Lo                  2
#define OFFSET_FLOATING_MEASUREMENTS_ZAB_IM_Hi                  3
#define OFFSET_FLOATING_MEASUREMENTS_ZBC_RE_Lo                  4
#define OFFSET_FLOATING_MEASUREMENTS_ZBC_RE_Hi                  5
#define OFFSET_FLOATING_MEASUREMENTS_ZBC_IM_Lo                  6
#define OFFSET_FLOATING_MEASUREMENTS_ZBC_IM_Hi                  7
#define OFFSET_FLOATING_MEASUREMENTS_ZCA_RE_Lo                  8
#define OFFSET_FLOATING_MEASUREMENTS_ZCA_RE_Hi                  9
#define OFFSET_FLOATING_MEASUREMENTS_ZCA_IM_Lo                  10
#define OFFSET_FLOATING_MEASUREMENTS_ZCA_IM_Hi                  11

//Комплексные фазные сопротивления (little indian)
// first stage
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Lo_1ST              12
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Hi_1ST              13
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Lo_1ST              14
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Hi_1ST              15
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Lo_1ST              16
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Hi_1ST              17
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Lo_1ST              18
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Hi_1ST              19
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Lo_1ST              20
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Hi_1ST              21
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Lo_1ST              22
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Hi_1ST              23

//second stage
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Lo_2ST              24
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Hi_2ST              25
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Lo_2ST              26
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Hi_2ST              27
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Lo_2ST              28
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Hi_2ST              29
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Lo_2ST              30
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Hi_2ST              31
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Lo_2ST              32
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Hi_2ST              33
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Lo_2ST              34
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Hi_2ST              35

//third stage
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Lo_3ST              36
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Hi_3ST              37
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Lo_3ST              38
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Hi_3ST              39
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Lo_3ST              40
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Hi_3ST              41
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Lo_3ST              42
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Hi_3ST              43
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Lo_3ST              44
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Hi_3ST              45
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Lo_3ST              46
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Hi_3ST              47

//fourth stage
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Lo_4ST              48
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Hi_4ST              49
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Lo_4ST              50
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Hi_4ST              51
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Lo_4ST              52
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Hi_4ST              53
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Lo_4ST              54
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Hi_4ST              55
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Lo_4ST              56
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Hi_4ST              57
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Lo_4ST              58
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Hi_4ST              59

// fifth stage
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Lo_5ST              60
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_RE_Hi_5ST              61
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Lo_5ST              62
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_IM_Hi_5ST              63
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Lo_5ST              64
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_RE_Hi_5ST              65
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Lo_5ST              66
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_IM_Hi_5ST              67
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Lo_5ST              68
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_RE_Hi_5ST              69
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Lo_5ST              70
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_IM_Hi_5ST              71

//Комплексные сопротивления (little indian)
#define OFFSET_FLOATING_MEASUREMENTS_ZAB_COMPLEX_Lo             72
#define OFFSET_FLOATING_MEASUREMENTS_ZAB_COMPLEX_Hi             73
#define OFFSET_FLOATING_MEASUREMENTS_ZBC_COMPLEX_Lo             74
#define OFFSET_FLOATING_MEASUREMENTS_ZBC_COMPLEX_Hi             75
#define OFFSET_FLOATING_MEASUREMENTS_ZCA_COMPLEX_Lo             76
#define OFFSET_FLOATING_MEASUREMENTS_ZCA_COMPLEX_Hi             77

#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Lo_1ST                 78
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Hi_1ST                 79
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Lo_1ST                 80
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Hi_1ST                 81
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Lo_1ST                 82
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Hi_1ST                 83


#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Lo_2ST                 84
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Hi_2ST                 85
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Lo_2ST                 86
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Hi_2ST                 87
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Lo_2ST                 88
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Hi_2ST                 89


#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Lo_3ST                 90
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Hi_3ST                 91
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Lo_3ST                 92
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Hi_3ST                 93
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Lo_3ST                 94
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Hi_3ST                 95


#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Lo_4ST                 96
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Hi_4ST                 97
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Lo_4ST                 98
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Hi_4ST                 99
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Lo_4ST                 100
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Hi_4ST                 101

#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Lo_5ST                 102
#define OFFSET_FLOATING_MEASUREMENTS_ZA0_Hi_5ST                 103
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Lo_5ST                 104
#define OFFSET_FLOATING_MEASUREMENTS_ZB0_Hi_5ST                 105
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Lo_5ST                 106
#define OFFSET_FLOATING_MEASUREMENTS_ZC0_Hi_5ST                 107

#define M_ADDRESS_LAST_FLOATING_MEASUREMENTS                    4307
/*************************  для Сокола end  ********************************/




/******************************************************************************/
/* Мгновенные измерения рассчитанные методом преобразований Фурье             */
/******************************************************************************/
#define M_ADDRESS_FIRST_MEASUREMENTS_1                          4308

#define OFFSET_MEASUREMENT1_3I0_Hi                              0
#define OFFSET_MEASUREMENT1_3I0_Lo                              1
#define OFFSET_MEASUREMENT1_IA_Hi                               2
#define OFFSET_MEASUREMENT1_IA_Lo                               3
#define OFFSET_MEASUREMENT1_IB_Hi                               4
#define OFFSET_MEASUREMENT1_IB_Lo                               5
#define OFFSET_MEASUREMENT1_IC_Hi                               6
#define OFFSET_MEASUREMENT1_IC_Lo                               7
#define OFFSET_MEASUREMENT1_3U0_Hi                              8
#define OFFSET_MEASUREMENT1_3U0_Lo                              9
#define OFFSET_MEASUREMENT1_UA_Hi                               10
#define OFFSET_MEASUREMENT1_UA_Lo                               11
#define OFFSET_MEASUREMENT1_UB_Hi                               12
#define OFFSET_MEASUREMENT1_UB_Lo                               13
#define OFFSET_MEASUREMENT1_UC_Hi                               14
#define OFFSET_MEASUREMENT1_UC_Lo                               15
#define OFFSET_MEASUREMENT1_ISYN_Hi                             16
#define OFFSET_MEASUREMENT1_ISYN_Lo                             17
#define OFFSET_MEASUREMENT1_USYN_Hi                             18
#define OFFSET_MEASUREMENT1_USYN_Lo                             19
#define OFFSET_MEASUREMENT1_UBC_TN2_Hi                          20
#define OFFSET_MEASUREMENT1_UBC_TN2_Lo                          21
#define OFFSET_MEASUREMENT1_I2_Hi                               22
#define OFFSET_MEASUREMENT1_I2_Lo                               23
#define OFFSET_MEASUREMENT1_U2_Hi                               24
#define OFFSET_MEASUREMENT1_U2_Lo                               25
#define OFFSET_MEASUREMENT1_I1_Hi                               26
#define OFFSET_MEASUREMENT1_I1_Lo                               27
#define OFFSET_MEASUREMENT1_U1_Hi                               28
#define OFFSET_MEASUREMENT1_U1_Lo                               29
#define OFFSET_MEASUREMENT1_I0_Hi                               30
#define OFFSET_MEASUREMENT1_I0_Lo                               31

#define M_ADDRESS_LAST_MEASUREMENTS_1                           4340
/******************************************************************************/
/******************************************************************************/
/* Мгновенные измерения рассчитанные методом квадратного корня суммы квадратов*/
/* мгновенных значений за период                                              */
/******************************************************************************/
#define M_ADDRESS_FIRST_MEASUREMENTS_2                          4340

#define OFFSET_MEASUREMENT2_3I0_Hi                              0
#define OFFSET_MEASUREMENT2_3I0_Lo                              1
#define OFFSET_MEASUREMENT2_IA_Hi                               2
#define OFFSET_MEASUREMENT2_IA_Lo                               3
#define OFFSET_MEASUREMENT2_IB_Hi                               4
#define OFFSET_MEASUREMENT2_IB_Lo                               5
#define OFFSET_MEASUREMENT2_IC_Hi                               6
#define OFFSET_MEASUREMENT2_IC_Lo                               7
#define OFFSET_MEASUREMENT2_3U0_Hi                              8
#define OFFSET_MEASUREMENT2_3U0_Lo                              9
#define OFFSET_MEASUREMENT2_UA_Hi                               10
#define OFFSET_MEASUREMENT2_UA_Lo                               11
#define OFFSET_MEASUREMENT2_UB_Hi                               12
#define OFFSET_MEASUREMENT2_UB_Lo                               13
#define OFFSET_MEASUREMENT2_UC_Hi                               14
#define OFFSET_MEASUREMENT2_UC_Lo                               15
#define OFFSET_MEASUREMENT2_ISYN_Hi                             16
#define OFFSET_MEASUREMENT2_ISYN_Lo                             17
#define OFFSET_MEASUREMENT2_USYN_Hi                             18
#define OFFSET_MEASUREMENT2_USYN_Lo                             19
#define OFFSET_MEASUREMENT2_UBC_TN2_Hi                          20
#define OFFSET_MEASUREMENT2_UBC_TN2_Lo                          21

#define M_ADDRESS_LAST_MEASUREMENTS_2                           4362
/******************************************************************************/
/******************************************************************************/
/* Настройки                                                                  */
/******************************************************************************/
#define MA_PART_SETTINGS_FIRST_ADDR                             50000
#define OFFSET_SETTINGS_DEVICE_ID                               0
#define OFFSET_SETTINGS_A_USYN_ISYN                             1
#define OFFSET_SETTINGS_A_UA_UB_UC                              2
#define OFFSET_SETTINGS_ANGLE_R                                 3
#define OFFSET_SETTINGS_IN_TYPE_SHON                            4
#define MA_PART_SETTINGS_LAST_ADDR                              50005
/******************************************************************************/
            
/******************************************************************************/
/* Юстировка                                                                  */
/******************************************************************************/
#define MA_POSSIBILITY_USTUVANNJA                               50016
#define MA_ADDRESS_FIRST_USTUVANNJA                             61968
#define MA_ADDRESS_LAST_USTUVANNJA                              61975
//!!!#define MA_ADDRESS_LAST_USTUVANNJA                              (MA_ADDRESS_FIRST_USTUVANNJA + NUMBER_CANALS)
/******************************************************************************/

/******************************************************************************/
/* Адрес старта процесса считывания действующих значений                      */
/* Считывание действующих значений будет начинатся после записи по этому адр. */
/******************************************************************************/
//#define M_ADDRESS_START_UPDATE_CURRENT_MEASUREMENTS           55000
/******************************************************************************/
/******************************************************************************/
/* Мгновенные измерения                                                       */
/******************************************************************************/
#define MA_PART_RECEIVE_DIG_OSCILOGRAPH                         60303
#define M_ADDRESS_FIRST_DIG_OSCILOGRAPH                         60304
#define NUMBER_REGISTER_DIG_OSCILOGRAPH                         4400
#define STEP_DIG_OSCILOGRAPH                                    55
#define M_ADDRESS_LAST_DIG_OSCILOGRAPH \
          (M_ADDRESS_FIRST_DIG_OSCILOGRAPH + NUMBER_REGISTER_DIG_OSCILOGRAPH)
/******************************************************************************/
            
#endif

