#ifndef __CONST_CALCULATION_H
#define __CONST_CALCULATION_H

#define  MNOGNYK_3I0_DIJUCHE           1.739954653f
#define  MNOGNYK_3I0_DIJUCHE_3         0.579984884f
#define  MNOGNYK_3U0_DIJUCHE           6.908212742f
#define  MNOGNYK_ISYN_DIJUCHE          0.14092745f
#define  MNOGNYK_USYN_DIJUCHE          4.162641011f
#define  MNOGNYK_I_DIJUCHE             8.699773265f
#define  MNOGNYK_U_DIJUCHE             6.908212742f

#define  MNOGNYK_3I0                   2.460667468f
#define  MNOGNYK_3I0_3                 0.820222489f
#define  MNOGNYK_3U0                   9.769688152f
#define  MNOGNYK_ISYN                  0.19930151f
#define  MNOGNYK_USYN                  5.886863374f
#define  MNOGNYK_I                     12.30333734f
#define  MNOGNYK_U                     9.769688152f

#define I_IZ         0
#define I_UZ         1

#define INDEX_I2      11
#define INDEX_U2      12
#define INDEX_I1      13
#define INDEX_U1      14
#define INDEX_I0      15
#define INDEX_U0      16

#define I_MIN_DZ      50

#define INDEX_UBC     0
#define INDEX_UCA     1
#define INDEX_UAB     2

#define k 0.001f // коэффициент компенсации фазного тока током нулевой последовательности  
#define INDEX_RES  6
#define KOEF_ACCURACY   1000.0f

#define PI 3.1415926535897932384626433832795

#define SECTOR1_1_1    85
#define SECTOR1_1_2   -85
#define SECTOR1_2_1    95
#define SECTOR1_2_2   -95

#define SECTOR2_1_1    80
#define SECTOR2_1_2   -80
#define SECTOR2_2_1    100
#define SECTOR2_2_2   -100

#define AMPLITUDA_SECTOR_VAGA 7
#define AMPLITUDA_SECTOR      (1 << AMPLITUDA_SECTOR_VAGA)
#define AMPLITUDA_FI_VAGA     15
#define AMPLITUDA_FI          (1 << AMPLITUDA_FI_VAGA)

#define K_USYN           1.283f
#define K_ISYN_TYPE0     384.912f
#define K_ISYN_TYPE1     769.823f




#endif
