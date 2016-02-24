#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* Umax_pickups_notification_value_changed (
                                                _id_user_widget Id, 
                                                CfgTblDsc *point,
                                                int *p_min,
                                                int *p_max,
                                                float *value,
                                                int *p_value_int
                                              )
{
  int *p_value_int_edit;
  
  switch (Id)
  {
  case ID_ED_UMAX_PICKUP_VALUE_0:
    {
      *p_min = UMAX1_PICKUP0_MIN;
      *p_max = UMAX1_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[Umax_select_group].ownrStage1UmaxPickup.ov_range_Umax;

      break;
    }
  case ID_ED_UMAX_PICKUP_VALUE_1:
    {
      *p_min = UMAX2_PICKUP0_MIN;
      *p_max = UMAX2_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[Umax_select_group].ownrStage2UmaxPickup.ov_range_Umax;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Дії по зміні значення витримок в функції _cbDelays_Protection
**********/

unsigned short int* Umax_delays_notification_value_changed (
                                                            _id_user_widget Id, 
                                                            CfgTblDsc *point,
                                                            unsigned int *p_min,
                                                            unsigned int *p_max,
                                                            float *value,
                                                            unsigned int *p_value_int
                                                           )
{
  unsigned short int *p_value_int_edit;
  
  switch (Id)
  {
  case ID_ED_UMAX_DELAY_VALUE_0:
    {
      *p_min = UMAX1_DELAY0_MIN;
      *p_max = UMAX1_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[Umax_select_group].ownrStage1UmaxStageParam.time_stage_Umax;

      break;
    }
  case ID_ED_UMAX_DELAY_VALUE_1:
    {
      *p_min = UMAX2_DELAY0_MIN;
      *p_max = UMAX2_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[Umax_select_group].ownrStage2UmaxStageParam.time_stage_Umax;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки Umax
**********/
void Umax_pickup_info(
                      unsigned int number,
                      CfgTblDsc *point,
                      int *p_min,
                      int *p_max,
                      float *value,
                      int *p_value_int
                     )
{
  switch (number)
  {
  case 0:
    {
      *p_min = UMAX1_PICKUP0_MIN;
      *p_max = UMAX1_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[Umax_select_group].ownrStage1UmaxPickup.ov_range_Umax;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_UMAX1 + 0:
    {
      *p_min = UMAX2_PICKUP0_MIN;
      *p_max = UMAX2_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[Umax_select_group].ownrStage2UmaxPickup.ov_range_Umax;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки Umax
**********/
void Umax_delay_info(
                     unsigned int number,
                     CfgTblDsc *point,
                     unsigned int *p_min,
                     unsigned int *p_max,
                     float *value,
                     unsigned int *p_value_int
                    )
{
  switch (number)
  {
  case 0:
    {
      *p_min = UMAX1_DELAY0_MIN;
      *p_max = UMAX1_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[Umax_select_group].ownrStage1UmaxStageParam.time_stage_Umax;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_UMAX1 + 0:
    {
      *p_min = UMAX2_DELAY0_MIN;
      *p_max = UMAX2_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[Umax_select_group].ownrStage2UmaxStageParam.time_stage_Umax;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки Umax
**********/
const char* Umax_pickup_info_1(
                               unsigned int number,
                               int *p_min,
                               int *p_max,
                               int *p_shift,
                               unsigned int *extra_param
                              )
{
  const char *p_pickup_dimention;
  *p_min = 0;
  *extra_param = 0;

  switch (number)
  {
  case 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = UMAX1_PICKUP0_MAX/1000;
      *p_shift = UMAX1_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_UMAX1 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = UMAX2_PICKUP0_MAX/1000;
      *p_shift = UMAX2_PICKUP0_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки Umax
**********/
const char* Umax_delay_info_1(
                              unsigned int number,
                              int *p_min,
                              int *p_max,
                              int *p_shift
                             )
{
  const char *p_pickup_dimention = MEASURES[MEASURES_OF_SECOND].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
  *p_min = 0;

  switch (number)
  {
  case 0:
    {
      *p_max = UMAX1_DELAY0_MAX/100;
      *p_shift = UMAX1_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_UMAX1 + 0:
    {
      *p_max = UMAX2_DELAY0_MAX/100;
      *p_shift = UMAX2_DELAY0_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання вказівника на розмірність уставок
**********/
const char* Umax_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  default:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      break;
    }
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання інформації для формувнні назв станів для Umax
**********/
const TITLE* Umax_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  if (
      (number == 1) ||
      (number == (MAX_NUMBER_CTRL_UMAX1+1))
     )   
  {
    p_control_list_name = UMIN_UMAX_TYPE;
  }
  else if (number == (MAX_NUMBER_CTRL_UMAX1 + MAX_NUMBER_CTRL_UMAX2 + 0))
  {
    p_control_list_name = UMIN_UMAX_VOLTAGE;
  }
  else
  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для Umax
**********/
unsigned char* Umax_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrStg1UmaxMng.state_Umax;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrStg1UmaxMng.state_SDEV_Umax;
      break;
    }
  case MAX_NUMBER_CTRL_UMAX1 + 0:
    {
      p_to_state = &point->ownrStgU2maxMng.state_Umax;
      break;
    }
  case MAX_NUMBER_CTRL_UMAX1 + 1:
    {
      p_to_state = &point->ownrStgU2maxMng.state_SDEV_Umax;
      break;
    }
  case MAX_NUMBER_CTRL_UMAX1 + MAX_NUMBER_CTRL_UMAX2 + 0:
    {
      p_to_state = &point->state_SDEV_Phase_Umax;
      break;
    }
  default: break;
  }
  
  return p_to_state;
}
/**********/

/**********
Функція яка виконує певні дії після зміни деяких налаштувань
**********/
void Umax_change_state_callback(
                                unsigned int number,
                                CfgTblDsc *point
                               )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_Umax(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_UMAX) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = UMAX1_PICKUP0_MIN;
          max = UMAX1_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1UmaxPickup.ov_range_Umax;

          break;
        }
      case MAX_NUMBER_PICKUP_UMAX1 + 0:
        {
          min = UMAX2_PICKUP0_MIN;
          max = UMAX2_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2UmaxPickup.ov_range_Umax;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_UMAX) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = UMAX1_DELAY0_MIN;
          max = UMAX1_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1UmaxStageParam.time_stage_Umax;

          break;
        }
      case MAX_NUMBER_DELAY_UMAX1 + 0:
        {
          min = UMAX2_DELAY0_MIN;
          max = UMAX2_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2UmaxStageParam.time_stage_Umax;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }
  }
  
  return ok;
}
/*****************************/

/*****************************
Копіювання змінених данихз структури для редагування у робочу структуру
*****************************/
void copy_data_Umax(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrStage1UmaxPickup = 
    source->arPckpStpmStngStore[i].ownrStage1UmaxPickup; 

    target->arPckpStpmStngStore[i].ownrStage1UmaxStageParam = 
    source->arPckpStpmStngStore[i].ownrStage1UmaxStageParam; 

    target->arPckpStpmStngStore[i].ownrStage2UmaxPickup = 
    source->arPckpStpmStngStore[i].ownrStage2UmaxPickup; 

    target->arPckpStpmStngStore[i].ownrStage2UmaxStageParam = 
    source->arPckpStpmStngStore[i].ownrStage2UmaxStageParam; 
  }
  target->ownrStg1UmaxMng = source->ownrStg1UmaxMng;
  target->ownrStgU2maxMng = source->ownrStgU2maxMng;
  target->state_SDEV_Phase_Umax = source->state_SDEV_Phase_Umax;
}
/*****************************/
