#ifndef __TYPE_DEFINITION__
#define __TYPE_DEFINITION__

#define I_RAM _Pragma("location=\"I_RAM_variables\"")

#include "type_definition_BS.h"
#include "type_definition_BL.h"

struct partial_VFP_state_t
{
  double reg_D0, reg_D1;
  unsigned long reg_FPSCR;
};

typedef struct 
{
  unsigned int x1;
  int y1;

  unsigned int x2;
  int y2;

} VYBORKA_XY;

typedef struct
{
  unsigned int Ua_x1;
  int Ua_y1;
  unsigned int Ua_x2;
  int Ua_y2;

  unsigned int Ub_x1;
  int Ub_y1;
  unsigned int Ub_x2;
  int Ub_y2;

  unsigned int Uc_x1;
  int Uc_y1;  
  unsigned int Uc_x2;
  int Uc_y2;  

  unsigned int Isyn_x1;
  int Isyn_y1;
  unsigned int Isyn_x2;
  int Isyn_y2;

  unsigned int Usyn_x1;
  int Usyn_y1;
  unsigned int Usyn_x2;
  int Usyn_y2;
  
} POPEREDNJY_PERECHID;

typedef struct
{
  unsigned int SPI1_time_p;
  int SPI1_data_p[NUMBER_CANALS_SPI1];

  unsigned int SPI1_time_c;
  int SPI1_data_c[NUMBER_CANALS_SPI1];

  unsigned int SPI2_time_p;
  int SPI2_data_p[NUMBER_CANALS_SPI2];

  unsigned int SPI2_time_c;
  int SPI2_data_c[NUMBER_CANALS_SPI2];
} ROZSHYRENA_VYBORKA;

typedef struct
{
  unsigned int time_stemp;
  unsigned int SPI1_fix;
  unsigned int SPI2_fix;
  int data [NUMBER_CANALS];
  
} DATA_FOR_OSCYLOGRAPH;

typedef struct
{
  //Стан обміну
  int state_execution;        //-1 - драйвер готовий до початку нових транзакцій
                              // 0 - відбувається обмін
                              // 1 - обмін завершений без помилок
                              // 2 - обмін завершений з помилками
  
  
  //Код операції
  int action;                 //-1 - не визначений
                              // 0 - зчитування
                              // 1 - запис
  

} __DRIVER_I2C;

#endif
