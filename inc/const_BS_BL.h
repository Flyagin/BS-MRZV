#ifndef __CONST_BS_BL_H
#define __CONST_BS_BL_H

#define NUMBER_CANALS_ADC1              3
#define NUMBER_CANALS_ADC2              4
#define NUMBER_CANALS_ADC3              3
#define NUMBER_CANALS_SPI1              (NUMBER_CANALS_ADC1 + NUMBER_CANALS_ADC2)
#define NUMBER_CANALS_SPI2              (NUMBER_CANALS_ADC3)
#define NUMBER_CANALS                   (NUMBER_CANALS_SPI1 + NUMBER_CANALS_SPI2)

#define INDEX_IA                        0
#define INDEX_IB                        1
#define INDEX_IC                        2
#define INDEX_3U0                       3
#define INDEX_UA                        4
#define INDEX_UB                        5
#define INDEX_UC                        6
#define INDEX_ISYN                      7
#define INDEX_USYN                      8
#define INDEX_UBC_TN2                   9
#define INDEX_I2                        10
#define INDEX_U2                        11
#define INDEX_I1                        12
#define INDEX_U1                        13
#define INDEX_I0                        14

#define INDEX_UBC_2         8
#define INDEX_IZ            9
#define INDEX_UZ            10
#define INDEX_IP            11
#define INDEX_UP            12
#define INDEX_UL            13



#define INDEX_RES  6

#endif
