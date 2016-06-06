#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* Umin_pickups_notification_value_changed (
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
  case ID_ED_UMIN_PICKUP_VALUE_0:
    {
      *p_min = UMIN1_PICKUP0_MIN;
      *p_max = UMIN1_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[Umin_select_group].ownrStage1UminPickup.ov_range_Umin;

      break;
    }
  case ID_ED_UMIN_PICKUP_VALUE_1:
    {
      *p_min = UMIN1_PICKUP1_MIN;
      *p_max = UMIN1_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[Umin_select_group].ownrStage1UminPickup.ov_range_IblkUmin;

      break;
    }
  case ID_ED_UMIN_PICKUP_VALUE_2:
    {
      *p_min = UMIN2_PICKUP0_MIN;
      *p_max = UMIN2_PICKUP0_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[Umin_select_group].ownrStage2UminPickup.ov_range_Umin;

      break;
    }
  case ID_ED_UMIN_PICKUP_VALUE_3:
    {
      *p_min = UMIN2_PICKUP1_MIN;
      *p_max = UMIN2_PICKUP1_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->arPckpStpmStngStore[Umin_select_group].ownrStage2UminPickup.ov_range_IblkUmin;

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

unsigned short int* Umin_delays_notification_value_changed (
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
  case ID_ED_UMIN_DELAY_VALUE_0:
    {
      *p_min = UMIN1_DELAY0_MIN;
      *p_max = UMIN1_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[Umin_select_group].ownrStage1UminStageParam.time_stage_Umin;

      break;
    }
  case ID_ED_UMIN_DELAY_VALUE_1:
    {
      *p_min = UMIN2_DELAY0_MIN;
      *p_max = UMIN2_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->arPckpStpmStngStore[Umin_select_group].ownrStage2UminStageParam.time_stage_Umin;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки Umin
**********/
void Umin_pickup_info(
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
      *p_min = UMIN1_PICKUP0_MIN;
      *p_max = UMIN1_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[Umin_select_group].ownrStage1UminPickup.ov_range_Umin;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 1:
    {
      *p_min = UMIN1_PICKUP1_MIN;
      *p_max = UMIN1_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[Umin_select_group].ownrStage1UminPickup.ov_range_IblkUmin;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_UMIN1 + 0:
    {
      *p_min = UMIN2_PICKUP0_MIN;
      *p_max = UMIN2_PICKUP0_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[Umin_select_group].ownrStage2UminPickup.ov_range_Umin;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case MAX_NUMBER_PICKUP_UMIN1 + 1:
    {
      *p_min = UMIN2_PICKUP1_MIN;
      *p_max = UMIN2_PICKUP1_MAX;
                
      *p_value_int = point->arPckpStpmStngStore[Umin_select_group].ownrStage2UminPickup.ov_range_IblkUmin;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки Umin
**********/
void Umin_delay_info(
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
      *p_min = UMIN1_DELAY0_MIN;
      *p_max = UMIN1_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[Umin_select_group].ownrStage1UminStageParam.time_stage_Umin;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case MAX_NUMBER_DELAY_UMIN1 + 0:
    {
      *p_min = UMIN2_DELAY0_MIN;
      *p_max = UMIN2_DELAY0_MAX;
          
      *p_value_int = point->arPckpStpmStngStore[Umin_select_group].ownrStage2UminStageParam.time_stage_Umin;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки Umin
**********/
const char* Umin_pickup_info_1(
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
        
      *p_max = UMIN1_PICKUP0_MAX/1000;
      *p_shift = UMIN1_PICKUP0_SHIFT;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = UMIN1_PICKUP1_MAX/1000;
      *p_shift = UMIN1_PICKUP1_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_UMIN1 + 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_VOLTAGE].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = UMIN2_PICKUP0_MAX/1000;
      *p_shift = UMIN2_PICKUP0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_PICKUP_UMIN1 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
        
      *p_max = UMIN2_PICKUP1_MAX/1000;
      *p_shift = UMIN2_PICKUP1_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки Umin
**********/
const char* Umin_delay_info_1(
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
      *p_max = UMIN1_DELAY0_MAX/100;
      *p_shift = UMIN1_DELAY0_SHIFT;
        
      break;
    }
  case MAX_NUMBER_DELAY_UMIN1 + 0:
    {
      *p_max = UMIN2_DELAY0_MAX/100;
      *p_shift = UMIN2_DELAY0_SHIFT;
        
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
const char* Umin_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 1:
  case MAX_NUMBER_PICKUP_UMIN1 + 1:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[eeprom_bs_settings_tbl.chLngGUIText];
      break;
    }
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
Отримання інформації для формувнні назв станів для Umin
**********/
const TITLE* Umin_control_info(unsigned int number, int *p_j_max)
{
  const TITLE *p_control_list_name;
  *p_j_max = 2;

  if (
      (number == 1) ||
      (number == (MAX_NUMBER_CTRL_UMIN1+1))
     )   
  {
    p_control_list_name = UMIN_UMAX_TYPE;
  }
  else if (number == (MAX_NUMBER_CTRL_UMIN1 + MAX_NUMBER_CTRL_UMIN2 + 0))
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
Отримання вказівника на поле структури де зберізається стан налаштування для Umin
**********/
unsigned char* Umin_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrStg1UminMng.state_Umin;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrStg1UminMng.state_SDEV_Umin;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrStg1UminMng.state_Umin_Iblk;
      break;
    }
  case 3:
    {
      p_to_state = &point->ownrStg1UminMng.state_Umin_Ublk;
      break;
    }
  case MAX_NUMBER_CTRL_UMIN1 + 0:
    {
      p_to_state = &point->ownrStg2UminMng.state_Umin;
      break;
    }
  case MAX_NUMBER_CTRL_UMIN1 + 1:
    {
      p_to_state = &point->ownrStg2UminMng.state_SDEV_Umin;
      break;
    }
  case MAX_NUMBER_CTRL_UMIN1 + 2:
    {
      p_to_state = &point->ownrStg2UminMng.state_Umin_Iblk;
      break;
    }
  case MAX_NUMBER_CTRL_UMIN1 + 3:
    {
      p_to_state = &point->ownrStg2UminMng.state_Umin_Ublk;
      break;
    }
  case MAX_NUMBER_CTRL_UMIN1 + MAX_NUMBER_CTRL_UMIN2 + 0:
    {
      p_to_state = &point->state_SDEV_Phase_Umin;
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
void Umin_change_state_callback(
                                unsigned int number,
                                CfgTblDsc *point
                               )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_Umin(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < AMOUNT_SERIES_PPSPM_SETTINGS) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_UMIN) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = UMIN1_PICKUP0_MIN;
          max = UMIN1_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1UminPickup.ov_range_Umin;

          break;
        }
      case 1:
        {
          min = UMIN1_PICKUP1_MIN;
          max = UMIN1_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1UminPickup.ov_range_IblkUmin;

          break;
        }
      case MAX_NUMBER_PICKUP_UMIN1 + 0:
        {
          min = UMIN2_PICKUP0_MIN;
          max = UMIN2_PICKUP0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2UminPickup.ov_range_Umin;

          break;
        }
      case MAX_NUMBER_PICKUP_UMIN1 + 1:
        {
          min = UMIN2_PICKUP1_MIN;
          max = UMIN2_PICKUP1_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2UminPickup.ov_range_IblkUmin;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_UMIN) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = UMIN1_DELAY0_MIN;
          max = UMIN1_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage1UminStageParam.time_stage_Umin;

          break;
        }
      case MAX_NUMBER_DELAY_UMIN1 + 0:
        {
          min = UMIN2_DELAY0_MIN;
          max = UMIN2_DELAY0_MAX;
          value_int = point->arPckpStpmStngStore[group].ownrStage2UminStageParam.time_stage_Umin;

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
void copy_data_Umin(CfgTblDsc *target, CfgTblDsc *source)
{
  for (int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++)
  {
    target->arPckpStpmStngStore[i].ownrStage1UminPickup = 
    source->arPckpStpmStngStore[i].ownrStage1UminPickup; 

    target->arPckpStpmStngStore[i].ownrStage1UminStageParam = 
    source->arPckpStpmStngStore[i].ownrStage1UminStageParam; 

    target->arPckpStpmStngStore[i].ownrStage2UminPickup = 
    source->arPckpStpmStngStore[i].ownrStage2UminPickup; 

    target->arPckpStpmStngStore[i].ownrStage2UminStageParam = 
    source->arPckpStpmStngStore[i].ownrStage2UminStageParam; 
  }
  target->ownrStg1UminMng = source->ownrStg1UminMng;
  target->ownrStg2UminMng = source->ownrStg2UminMng;
  target->state_SDEV_Phase_Umin = source->state_SDEV_Phase_Umin;
}
/*****************************/
