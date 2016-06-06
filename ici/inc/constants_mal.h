#ifndef __CONSTANTS_MAL_H
#define __CONSTANTS_MAL_H

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif        

#define LED_TEST_BIT        21

#define NUMBER_PERIOD                    50
#define NUMBER_PERIOD_TRANSMIT           10
#define NUMBER_POINT                     40
#define MAIN_FREQUENCY                   50      //Гц
#define MIN_FREQUENCY                    48      //Гц
#define MAX_FREQUENCY                    52      //Гц

#define BASE_PERIOD_MEAS_SYSTEM_0       (1000000/(NUMBER_POINT*MAIN_FREQUENCY))     //мкс

#define VREF_NORMAL_VALUE_MIN_L2        0x7333
#define VREF_NORMAL_VALUE_MIN_L1        0x7999
#define VREF_NORMAL_VALUE               0x8000
#define VREF_NORMAL_VALUE_MAX_L1        0x8666
#define VREF_NORMAL_VALUE_MAX_L2        0x8CCC

#define VDD_NORMAL_VALUE_MIN_L2         0xBB7F
#define VDD_NORMAL_VALUE_MIN_L1         0xC5EA
#define VDD_NORMAL_VALUE                0xD055
#define VDD_NORMAL_VALUE_MAX_L1         0xDABF
#define VDD_NORMAL_VALUE_MAX_L2         0xE52A


#define TICK_HSTimer_MATCH0_1_2 (BASE_PERIOD_MEAS_SYSTEM_0*(PER_CLK/1000000))

#define NUM_SPI                 2
#define N_SPI_1                   0
#define N_SPI_2                   1

#define NUM_CANALS_ADC          8

#define GPO_1_BIT               (1UL)
#define GPO_1                   _BIT(GPO_1_BIT)
#define GPO_2_BIT               (2UL)
#define GPO_2                   _BIT(GPO_2_BIT)
#define GPO_3_BIT               (3UL)
#define GPO_3                   _BIT(GPO_3_BIT)
#define GPO_4_BIT               (4UL)
#define GPO_4                   _BIT(GPO_4_BIT)

#define ADC1_READ1_BIT          0
#define ADC1_READ1              (1 << ADC1_READ1_BIT)
#define ADC1_READ2_BIT          1
#define ADC1_READ2              (1 << ADC1_READ2_BIT)

#define ADC2_READ1_BIT          2
#define ADC2_READ1              (1 << ADC2_READ1_BIT)
#define ADC2_READ2_BIT          3
#define ADC2_READ2              (1 << ADC2_READ2_BIT)

#define ADC3_READ1_BIT          4
#define ADC3_READ1              (1 << ADC3_READ1_BIT)
#define ADC3_READ2_BIT          5
#define ADC3_READ2              (1 << ADC3_READ2_BIT)

#define ADC1_READING_BIT        (28UL)
#define ADC1_READING            (unsigned int)(1 << ADC1_READING_BIT)

#define ADC2_READING_BIT        (29UL)
#define ADC2_READING            (unsigned int)(1 << ADC2_READING_BIT)

#define ADC3_READING_BIT        (30UL)
#define ADC3_READING            (unsigned int)(1 << ADC3_READING_BIT)

#define ADC4_READING_BIT        (31UL)
#define ADC4_READING            (unsigned int)(1 << ADC4_READING_BIT)

#define MASKA_ADC_SPI1          (ADC1_READ1 | ADC1_READ2 | ADC2_READ1 | ADC2_READ2)
#define MASKA_ADC_SPI2          (ADC3_READ1 | ADC3_READ2                          )

#define NUMBER_ANALOG_CANALES_ADC1      4
#define NUMBER_ANALOG_CANALES_ADC2      4
#define NUMBER_ANALOG_CANALES_ADC3      3

#define NUMBER_VREF_ADC1                2
#define NUMBER_VREF_ADC2                2
#define NUMBER_VREF_ADC3                3

#define NUMBER_CANALS_ADC1              4
#define NUMBER_CANALS_ADC2              4
#define NUMBER_CANALS_ADC3              3
#define NUMBER_CANALS_SPI1              (NUMBER_CANALS_ADC1 + NUMBER_CANALS_ADC2)
#define NUMBER_CANALS_SPI2              (NUMBER_CANALS_ADC3)
#define NUMBER_CANALS                   (NUMBER_CANALS_SPI1 + NUMBER_CANALS_SPI2)

#define INDEX_3I0                       0
#define INDEX_IA                        1
#define INDEX_IB                        2
#define INDEX_IC                        3
#define INDEX_3U0                       4
#define INDEX_UA                        5
#define INDEX_UB                        6
#define INDEX_UC                        7
#define INDEX_ISYN                      8
#define INDEX_USYN                      9
#define INDEX_UBC_TN2                   10

#define INDEX_FAPCH_UA                  0
#define INDEX_FAPCH_UB                  1
#define INDEX_FAPCH_UC                  2
#define INDEX_FAPCH_ISYN                3
#define INDEX_FAPCH_USYN                4

#define NUMBER_VDD_ADC1                 1
#define NUMBER_VDD_ADC2                 1
#define NUMBER_VDD_ADC3                 1

#define ADC1_3I0_1                      0
#define ADC1_IC                         1
#define ADC1_IB                         2
#define ADC1_IA                         3
#define ADC1_3I0_16                     4
#define ADC1_VREF1                      5
#define ADC1_VREF2                      6
#define ADC1_VDD1                       7

#define ADC2_VREF1                      0
#define ADC2_UA                         1
#define ADC2_UB                         2
#define ADC2_UC                         3
#define ADC2_3U0_1                      4
#define ADC2_3U0_16                     5
#define ADC2_VREF2                      6
#define ADC2_VDD1                       7

#define ADC3_USYN                       0
#define ADC3_ISYN_1                     1
#define ADC3_ISYN_16                    2
#define ADC3_UBC_TN2                    3
#define ADC3_VREF1                      4
#define ADC3_VREF2                      5
#define ADC3_VREF3                      6
#define ADC3_VDD1                       7

/*****************************************/
//Константи для фіксації зміни юстування
/*****************************************/
#define CHANGED_ETAP_NONE               0
#define CHANGED_ETAP_EXECUTION          1
#define CHANGED_ETAP_ENDED              2
/*****************************************/

#define PORIG_FOR_FAPCH_U 10000
#define PORIG_FOR_FAPCH_I 1000

#define SIN_COS_VAGA 7
#define AMPLITUDA_SIN_COS (1<<SIN_COS_VAGA)
#define USTUVANNJA_VAGA 12
#define DEFAULT_USTUVANNJA_VALUE ((1<<USTUVANNJA_VAGA) - 1)

/*****************************************/
//Константи для обчислення швидкості зміни кута
/*****************************************/
#define NUMBER_FOR_ANGLE_SPEED          5

#define CMD_AS_FIX_Ua_Ub_Uc_BIT         0
#define CMD_AS_FIX_Ua_Ub_Uc             (1 << CMD_AS_FIX_Ua_Ub_Uc_BIT)

#define CMD_AS_FIX_Isyn_Usyn_BIT        1
#define CMD_AS_FIX_Isyn_Usyn            (1 << CMD_AS_FIX_Isyn_Usyn_BIT)

#define CMD_AS_COPY_DATA_BIT            2
#define CMD_AS_COPY_DATA                (1 << CMD_AS_COPY_DATA_BIT)

#define INDEX_AS_UA                     0
#define INDEX_AS_UB                     1
#define INDEX_AS_UC                     2
#define INDEX_AS_ISYN                   3
#define INDEX_AS_USYN                   4

/*****************************************/

#define TASK_500msk_BIT                 0
#define TASK_500mks                     (1 << TASK_500msk_BIT)

#define TASK_ANGLE_SPEED_BIT                   1
#define TASK_ANGLE_SPEED                      (1 << TASK_ANGLE_SPEED_BIT)

#define TASK_1s_BIT                     2
#define TASK_1s                         (1 << TASK_1s_BIT)

#define TASK_TEST_FLASH_MEMORY_BIT      3
#define TASK_TEST_FLASH_MEMORY          (1 << TASK_TEST_FLASH_MEMORY_BIT)

#define EXTERNAL_SRAM_OK                0x12345678

#endif
