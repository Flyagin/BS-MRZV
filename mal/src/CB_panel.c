#include "header_mal.h"

/***
Дії по зміні значення уставки в функції _cbPickups_Protection
***/

int* CB_pickups_notification_value_changed (
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
  case ID_ED_CB_PICKUP_VALUE_0:
    {
      *p_min = CB_PICKUP0_MIN;
      *p_max = CB_PICKUP0_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.Inom;

      break;
    }
  case ID_ED_CB_PICKUP_VALUE_1:
    {
      *p_min = CB_PICKUP1_MIN;
      *p_max = CB_PICKUP1_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.RBR_Inom;

      break;
    }
  case ID_ED_CB_PICKUP_VALUE_2:
    {
      *p_min = CB_PICKUP2_MIN;
      *p_max = CB_PICKUP2_MAX;
      
      *p_value_int = (int)(round((*value)*1000.0f));
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.Ioff_nom;

      break;
    }
  case ID_ED_CB_PICKUP_VALUE_3:
    {
      *p_min = CB_PICKUP3_MIN;
      *p_max = CB_PICKUP3_MAX;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.RBR_off_nom;

      break;
    }
  case ID_ED_CB_PICKUP_VALUE_4:
    {
      if (point->ownrCalcHvpBrOn.RBR_off_nom != 0)
      {
        int chastka = point->ownrCalcHvpBrOn.RBR_Inom/point->ownrCalcHvpBrOn.RBR_off_nom;
        *p_min = 2*chastka;
        *p_max = point->ownrCalcHvpBrOn.RBR_Inom;
      }
      else
      {
        //При правильному параметруванні цієї ситуації ніколи не мало б бути
        *p_min = 0;
        *p_max = 0;
      }
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.BegRscVal;

      break;
    }
  case ID_ED_CB_PICKUP_VALUE_5:
    {
      if (point->ownrCalcHvpBrOn.RBR_off_nom != 0)
      {
        int chastka = point->ownrCalcHvpBrOn.RBR_Inom/point->ownrCalcHvpBrOn.RBR_off_nom;
        *p_min = chastka;
        *p_max = 2*chastka;
      }
      else
      {
        //При правильному параметруванні цієї ситуації ніколи не мало б бути
        *p_min = 0;
        *p_max = 0;
      }
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.CriticalRsc;

      break;
    }
  case ID_ED_CB_PICKUP_VALUE_6:
    {
      *p_min = CB_PICKUP6_MIN;
      *p_max = point->ownrCalcHvpBrOn.RBR_Inom;
      
      *p_value_int = (int)(*value);
      p_value_int_edit = (int *)&point->ownrCalcHvpBrOn.AmtSwTripping;

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

unsigned short int* CB_delays_notification_value_changed (
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
  case ID_ED_CB_DELAY_VALUE_0:
    {
      *p_min = CB_DELAY0_MIN;
      *p_max = CB_DELAY0_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->ownrBruStageParamStore.time_stageOFFUnit;

      break;
    }
  case ID_ED_CB_DELAY_VALUE_1:
    {
      *p_min = CB_DELAY1_MIN;
      *p_max = CB_DELAY1_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->ownrBruStageParamStore.time_stageONUnit;

      break;
    }
  case ID_ED_CB_DELAY_VALUE_2:
    {
      *p_min = CB_DELAY2_MIN;
      *p_max = CB_DELAY2_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->ownrBruStageParamStore.time_stageONCtrl;

      break;
    }
  case ID_ED_CB_DELAY_VALUE_3:
    {
      *p_min = CB_DELAY3_MIN;
      *p_max = CB_DELAY3_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->ownrBruStageParamStore.time_stageONUnitBlk;

      break;
    }
  case ID_ED_CB_DELAY_VALUE_4:
    {
      *p_min = CB_DELAY4_MIN;
      *p_max = CB_DELAY4_MAX;
      
      *p_value_int = (unsigned int)(round((*value)*100.0f));
      p_value_int_edit = &point->ownrBruStageParamStore.time_ActuatorHVS;

      break;
    }
  default: break;
  }
  
  return p_value_int_edit;
}
/**********/

/**********
Отримання параметрів значення уставки CB
**********/
void CB_pickup_info(
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
      *p_min = CB_PICKUP0_MIN;
      *p_max = CB_PICKUP0_MAX;
                
      *p_value_int = point->ownrCalcHvpBrOn.Inom;
      *value = (float)(*p_value_int);
      break;
    }
  case 1:
    {
      *p_min = CB_PICKUP1_MIN;
      *p_max = CB_PICKUP1_MAX;
                
      *p_value_int = point->ownrCalcHvpBrOn.RBR_Inom;
      *value = (float)(*p_value_int);
      break;
    }
  case 2:
    {
      *p_min = CB_PICKUP2_MIN;
      *p_max = CB_PICKUP2_MAX;
                
      *p_value_int = point->ownrCalcHvpBrOn.Ioff_nom;
      *value = (float)(*p_value_int)/1000.0f;
      break;
    }
  case 3:
    {
      *p_min = CB_PICKUP3_MIN;
      *p_max = CB_PICKUP3_MAX;
                
      *p_value_int = point->ownrCalcHvpBrOn.RBR_off_nom;
      *value = (float)(*p_value_int);
      break;
    }
  case 4:
    {
      if (point->ownrCalcHvpBrOn.RBR_off_nom != 0)
      {
        int chastka = point->ownrCalcHvpBrOn.RBR_Inom/point->ownrCalcHvpBrOn.RBR_off_nom;
        *p_min = 2*chastka;
        *p_max = point->ownrCalcHvpBrOn.RBR_Inom;
      }
      else
      {
        //При правильному параметруванні цієї ситуації ніколи не мало б бути
        *p_min = 0;
        *p_max = 0;
      }
                
      *p_value_int = point->ownrCalcHvpBrOn.BegRscVal;
      *value = (float)(*p_value_int);
      break;
    }
  case 5:
    {
      if (point->ownrCalcHvpBrOn.RBR_off_nom != 0)
      {
        int chastka = point->ownrCalcHvpBrOn.RBR_Inom/point->ownrCalcHvpBrOn.RBR_off_nom;
        *p_min = chastka;
        *p_max = 2*chastka;
      }
      else
      {
        //При правильному параметруванні цієї ситуації ніколи не мало б бути
        *p_min = 0;
        *p_max = 0;
      }
                
      *p_value_int = point->ownrCalcHvpBrOn.CriticalRsc;
      *value = (float)(*p_value_int);
      break;
    }
  case 6:
    {
      *p_min = CB_PICKUP6_MIN;
      *p_max = point->ownrCalcHvpBrOn.RBR_Inom;
                
      *p_value_int = point->ownrCalcHvpBrOn.AmtSwTripping;
      *value = (float)(*p_value_int);
      break;
    }
    default: break;
  }
}
/**********/

/**********
Отримання параметрів значення витримки CB
**********/
void CB_delay_info(
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
      *p_min = CB_DELAY0_MIN;
      *p_max = CB_DELAY0_MAX;
          
      *p_value_int = point->ownrBruStageParamStore.time_stageOFFUnit;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 1:
    {
      *p_min = CB_DELAY1_MIN;
      *p_max = CB_DELAY1_MAX;
          
      *p_value_int = point->ownrBruStageParamStore.time_stageONUnit;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 2:
    {
      *p_min = CB_DELAY2_MIN;
      *p_max = CB_DELAY2_MAX;
          
      *p_value_int = point->ownrBruStageParamStore.time_stageONCtrl;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 3:
    {
      *p_min = CB_DELAY3_MIN;
      *p_max = CB_DELAY3_MAX;
          
      *p_value_int = point->ownrBruStageParamStore.time_stageONUnitBlk;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  case 4:
    {
      *p_min = CB_DELAY4_MIN;
      *p_max = CB_DELAY4_MAX;
          
      *p_value_int = point->ownrBruStageParamStore.time_ActuatorHVS;
      *value = (float)(*p_value_int)/100.0f;
      break;
    }
  default: break;
  }
}
/**********/

/**********
Отримання параметрів для уставки CB
**********/
const char* CB_pickup_info_1(
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
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      
      *p_max = CB_PICKUP0_MAX;
      *p_shift = CB_PICKUP0_SHIFT;
        
      break;
    }
  case 1:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = CB_PICKUP1_MAX;
      *p_shift = CB_PICKUP1_SHIFT;
        
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT_K].ptitle[sel_language];
      
      *p_max = CB_PICKUP2_MAX/1000;
      *p_shift = CB_PICKUP2_SHIFT;
        
      break;
    }
  case 3:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = CB_PICKUP3_MAX;
      *p_shift = CB_PICKUP3_SHIFT;
        
      break;
    }
  case 4:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = CB_PICKUP1_MAX; /*тут треба взяти максимальне значення з усіх можливих, тому береться CB_PICKUP1_MAX*/
      *p_shift = CB_PICKUP4_SHIFT;
        
      break;
    }
  case 5:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = CB_PICKUP1_MAX; /*тут треба взяти максимальне значення з усіх можливих, тому береться CB_PICKUP1_MAX*/
      *p_shift = CB_PICKUP5_SHIFT;
        
      break;
    }
  case 6:
    {
      p_pickup_dimention = empty_string;
      
      *p_max = CB_PICKUP1_MAX; /*тут треба взяти максимальне значення з усіх можливих, тому береться CB_PICKUP1_MAX*/
      *p_shift = CB_PICKUP6_SHIFT;
        
      break;
    }
  default: break;
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання параметрів для витримки CB
**********/
const char* CB_delay_info_1(
                            unsigned int number,
                            int *p_min,
                            int *p_max,
                            int *p_shift
                           )
{
  const char *p_pickup_dimention = MEASURES[MEASURES_OF_SECOND].ptitle[sel_language];
  *p_min = 0;

  switch (number)
  {
  case 0:
    {
      *p_max = CB_DELAY0_MAX/100;
      *p_shift = CB_DELAY0_SHIFT;
        
      break;
    }
  case 1:
    {
      *p_max = CB_DELAY1_MAX/100;
      *p_shift = CB_DELAY1_SHIFT;
        
      break;
    }
  case 2:
    {
      *p_max = CB_DELAY2_MAX/100;
      *p_shift = CB_DELAY2_SHIFT;
        
      break;
    }
  case 3:
    {
      *p_max = CB_DELAY3_MAX/100;
      *p_shift = CB_DELAY3_SHIFT;
        
      break;
    }
  case 4:
    {
      *p_max = CB_DELAY4_MAX/100;
      *p_shift = CB_DELAY4_SHIFT;
        
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
const char* CB_pickup_dimention(unsigned int number)
{
  const char *p_pickup_dimention;

  switch (number)
  {
  case 0:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT].ptitle[sel_language];
      break;
    }
  case 2:
    {
      p_pickup_dimention = MEASURES[MEASURES_OF_CURRENT_K].ptitle[sel_language];
      break;
    }
  default:
    {
      p_pickup_dimention = empty_string;
      break;
    }
  }
  
  return p_pickup_dimention;
}
/**********/

/**********
Отримання інформації для формувнні назв станів для CB
**********/
const TITLE* CB_control_info(unsigned int number, int *p_j_max)
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
Отримання вказівника на поле структури де зберізається стан налаштування для CB
**********/
unsigned char* CB_pointer_to_state(
                                     unsigned int number,
                                     CfgTblDsc *point
                                    )
{
  unsigned char *p_to_state = NULL;

  switch (number)
  {
  case 0:
    {
      p_to_state = &point->ownrBruMngStore.state_Delay_ON_Unit;
      break;
    }
  case 1:
    {
      p_to_state = &point->ownrBruMngStore.state_Blk_SetON;
      break;
    }
  case 2:
    {
      p_to_state = &point->ownrBruMngStore.state_CheckHVS;
      break;
    }
  case 3:
    {
      p_to_state = &point->ownrBruMngStore.state_ResourceHVS;
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
void CB_change_state_callback(
                              unsigned int number,
                              CfgTblDsc *point
                             )
{
}
/**********/

/*****************************
Перевірка чи всі значення уставок-витримок у межах діапазону
*****************************/
unsigned int check_pickup_delay_CB(CfgTblDsc *point)
{
  unsigned int  ok = true;
  
  for (unsigned int group = 0; (group < 1) && (ok == true); group++)
  {
    for (unsigned int i = 0; (i < MAX_NUMBER_PICKUP_CB) && (ok == true); i++)
    { 
      int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = CB_PICKUP0_MIN;
          max = CB_PICKUP0_MAX;
          value_int = point->ownrCalcHvpBrOn.Inom;

          break;
        }
      case 1:
        {
          min = CB_PICKUP1_MIN;
          max = CB_PICKUP1_MAX;
          value_int = point->ownrCalcHvpBrOn.RBR_Inom;

          break;
        }
      case 2:
        {
          min = CB_PICKUP2_MIN;
          max = CB_PICKUP2_MAX;
          value_int = point->ownrCalcHvpBrOn.Ioff_nom;

          break;
        }
      case 3:
        {
          min = CB_PICKUP3_MIN;
          max = CB_PICKUP3_MAX;
          value_int = point->ownrCalcHvpBrOn.RBR_off_nom;

          break;
        }
      case 4:
        {
          if (point->ownrCalcHvpBrOn.RBR_off_nom != 0)
          {
            int chastka = point->ownrCalcHvpBrOn.RBR_Inom/point->ownrCalcHvpBrOn.RBR_off_nom;
            min = 2*chastka;
            max = point->ownrCalcHvpBrOn.RBR_Inom;
          }
          else
          {
            //При правильному параметруванні цієї ситуації ніколи не мало б бути
            min = 0;
            max = 0;
          }
          value_int = point->ownrCalcHvpBrOn.BegRscVal;

          break;
        }
      case 5:
        {
          if (point->ownrCalcHvpBrOn.RBR_off_nom != 0)
          {
            int chastka = point->ownrCalcHvpBrOn.RBR_Inom/point->ownrCalcHvpBrOn.RBR_off_nom;
            min = chastka;
            max = 2*chastka;
          }
          else
          {
            //При правильному параметруванні цієї ситуації ніколи не мало б бути
            min = 0;
            max = 0;
          }
          value_int = point->ownrCalcHvpBrOn.CriticalRsc;

          break;
        }
      case 6:
        {
          min = CB_PICKUP6_MIN;
          max = point->ownrCalcHvpBrOn.RBR_Inom;
          value_int = point->ownrCalcHvpBrOn.AmtSwTripping;

          break;
        }
      default: break;
      }

      if ((value_int < min) || (value_int > max)) ok = false;
    }

    for (unsigned int i = 0; (i < MAX_NUMBER_DELAY_CB) && (ok == true); i++)
    { 
      unsigned int value_int, min, max;
      switch (i)
      {
      case 0:
        {
          min = CB_DELAY0_MIN;
          max = CB_DELAY0_MAX;
          value_int = point->ownrBruStageParamStore.time_stageOFFUnit;

          break;
        }
      case 1:
        {
          min = CB_DELAY1_MIN;
          max = CB_DELAY1_MAX;
          value_int = point->ownrBruStageParamStore.time_stageONUnit;

          break;
        }
      case 2:
        {
          min = CB_DELAY2_MIN;
          max = CB_DELAY2_MAX;
          value_int = point->ownrBruStageParamStore.time_stageONCtrl;

          break;
        }
      case 3:
        {
          min = CB_DELAY3_MIN;
          max = CB_DELAY3_MAX;
          value_int = point->ownrBruStageParamStore.time_stageONUnitBlk;

          break;
        }
      case 4:
        {
          min = CB_DELAY4_MIN;
          max = CB_DELAY4_MAX;
          value_int = point->ownrBruStageParamStore.time_ActuatorHVS;

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
void copy_data_CB(CfgTblDsc *target, CfgTblDsc *source)
{
  target->ownrCalcHvpBrOn = 
  source->ownrCalcHvpBrOn; 

  target->ownrBruStageParamStore = 
  source->ownrBruStageParamStore; 
    
  target->ownrBruMngStore = source->ownrBruMngStore;
}
/*****************************/
