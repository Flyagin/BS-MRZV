#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* UROV_pickups_notification_value_changed (
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
  case ID_ED_UROV_PICKUP_VALUE_0:
    {
      *p_min = UROV_PICKUP0_MIN;
      *p_max = UROV_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[UROV_select_group].ownrBrfPickup.ov_range_Urov;

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

unsigned short int* UROV_delays_notification_value_changed (
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
  case ID_ED_UROV_DELAY_VALUE_0:
    {
      *p_min = UROV_DELAY0_MIN;
      *p_max = UROV_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[UROV_select_group].ownrBrfStageParam.time_stage_Urov1;

      break;
    }
  case ID_ED_UROV_DELAY_VALUE_1:
    {
      *p_min = UROV_DELAY1_MIN;
      *p_max = UROV_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[UROV_select_group].ownrBrfStageParam.time_stage_Urov2;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки UROV
**********/
void UROV_pickup_info(
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
      *p_min = UROV_PICKUP0_MIN;
      *p_max = UROV_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[UROV_select_group].ownrBrfPickup.ov_range_Urov;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки UROV
**********/
void UROV_delay_info(
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
      *p_min = UROV_DELAY0_MIN;
      *p_max = UROV_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[UROV_select_group].ownrBrfStageParam.time_stage_Urov1;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = UROV_DELAY1_MIN;
      *p_max = UROV_DELAY1_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[UROV_select_group].ownrBrfStageParam.time_stage_Urov2;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки UROV
**********/
const char* UROV_pickup_info_1(
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
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      
      *p_max = UROV_PICKUP0_MAX/1000;
      *p_shift = UROV_PICKUP0_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки UROV
**********/
const char* UROV_delay_info_1(
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
      *p_max = UROV_DELAY0_MAX/100;
      *p_shift = UROV_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = UROV_DELAY1_MAX/100;
      *p_shift = UROV_DELAY1_SHIFT;
        
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
const char* UROV_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  default:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      break;
    }
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання інформації для формувнні назв станів для UROV
**********/
const TITLE* UROV_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  {
    p_control_list_name = ON_OFF;
  }
  
  return p_control_list_name;
}
/**********/

/**********
Отримання вказівника на поле структури де зберізається стан налаштування для UROV
**********/
unsigned char* UROV_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrBrfMng.state_Urov;
      break;
    }
  default:
    {
      unsigned int number_func = number - 1;
      unsigned int number_byte = number_func >> 3;
      unsigned int number_bit  = number_func & 0x7;
      temp_data_for_UROV = (point->ownrBrfMng.ar_Brf_Stp_Cmd_state[number_byte] >> number_bit) & 0x1;
      p_to_state = &temp_data_for_UROV;
      break;
    }
  }
  
  return p_to_state;
}
/**********/

/**********
Функція яка виконує певні дії після зміни деяких налаштувань
**********/
void UROV_change_state_callback(
                               unsigned int number,
                               CfgTblDsc *point
                              )
{
  if (number > 0)
  {
    unsigned int number_func = number - 1;
    unsigned int number_byte = number_func >> 3;
    unsigned int number_bit  = number_func & 0x7;
    
    if (temp_data_for_UROV == 0)
    {
      point->ownrBrfMng.ar_Brf_Stp_Cmd_state[number_byte] &= (unsigned char)(~(1 << number_bit));
    }
    else
    {
      point->ownrBrfMng.ar_Brf_Stp_Cmd_state[number_byte] |= (unsigned char)( (1 << number_bit));
    }
  }
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_UROV(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_UROV) && (ok == true); i++)
    { 
      int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = UROV_PICKUP0_MIN;
          max = UROV_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrBrfPickup.ov_range_Urov;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_UROV) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = UROV_DELAY0_MIN;
          max = UROV_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrBrfStageParam.time_stage_Urov1;

          break;
        }
      case 1:
        {
          min = UROV_DELAY1_MIN;
          max = UROV_DELAY1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrBrfStageParam.time_stage_Urov2;

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
void copy_data_UROV(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrBrfPickup = 
    source->arPckpStpmStngStore[i].ownrBrfPickup; 

    target->arPckpStpmStngStore[i].ownrBrfStageParam = 
    source->arPckpStpmStngStore[i].ownrBrfStageParam; 
  }
  target->ownrBrfMng = source->ownrBrfMng;
}
/*****************************/
