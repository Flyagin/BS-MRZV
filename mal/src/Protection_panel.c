#include "header_mal.h"

#define X0                              0
#define Y0                              20
#define X_SIZE                          GUI_X_MAX
#define Y_SIZE                          (GUI_Y_MAX - 40)

/*****************************
Пошук ідентифікатора основного фрейму 
*****************************/
static int find_id_FrameWin(WM_HWIN hWin)
{
  WM_HWIN hObj_FrameWin = hWin;
  while (
         (hObj_FrameWin != DZ_FrameWin  ) &&
         (hObj_FrameWin != MTZ_FrameWin ) &&
         (hObj_FrameWin != Umin_FrameWin) &&
         (hObj_FrameWin != Umax_FrameWin) &&
         (hObj_FrameWin != TZNP_FrameWin) &&
         (hObj_FrameWin != ZOP_FrameWin ) &&
         (hObj_FrameWin != APV_FrameWin ) &&
         (hObj_FrameWin != UROV_FrameWin) &&
         (hObj_FrameWin != CB_FrameWin  )
        )   
  {
    hObj_FrameWin =  WM_GetParent(hObj_FrameWin);
  }

  return WM_GetId(hObj_FrameWin);
}
/*****************************/

/*****************************
       _cbPickups_Protection
*****************************/
static WM_HWIN focus_DZ_Pickup_v;
static WM_HWIN focus_MTZ_Pickup_v;
static WM_HWIN focus_Umin_Pickup_v;
static WM_HWIN focus_Umax_Pickup_v;
static WM_HWIN focus_TZNP_Pickup_v;
static WM_HWIN focus_ZOP_Pickup_v;
static WM_HWIN focus_APV_Pickup_v;
static WM_HWIN focus_UROV_Pickup_v;
static WM_HWIN focus_CB_Pickup_v;
static void _cbPickups_Protection(WM_MESSAGE * pMsg) 
{
  // USER START (Optionally insert additional variables)
  // USER END
  switch (pMsg->MsgId) 
  {
  // USER START (Optionally insert additional message handling)
    // витримокUSER END
  case WM_NOTIFY_PARENT:
    {
      WM_HWIN *Protection_FrameWin, *ScrollBar_Protection_Pages, *Protection_Pickup_t, *Protection_Pickup_v, *Protection_Pickup_m;
      WM_HWIN *focus_Protection_Pickup_v;
      const TITLE *Protection_panel_title;
      unsigned int max_number_pickup_protection;
      _id_user_widget id_ed_protection_pickup_value_min, id_ed_protection_pickup_value_max;
      int* (*Protection_pickups_notification_value_changed)(_id_user_widget, CfgTblDsc*, int*, int*, float*, int*);
      int *_y_cbPickup_Protection;
        
      switch (find_id_FrameWin(pMsg->hWin))
      {
      case ID_DZ_FRAMEWIN:
        {
          Protection_FrameWin = &DZ_FrameWin;
          Protection_panel_title = &DZ_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_DZ_Pages[0];
          
          max_number_pickup_protection = MAX_NUMBER_PICKUP_DZ;
          
          Protection_Pickup_t = DZ_Pickup_t;
          Protection_Pickup_v = DZ_Pickup_v;
          Protection_Pickup_m = DZ_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_DZ_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_DZ_PICKUP_VALUE_107;
          
          Protection_pickups_notification_value_changed = DZ_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_DZ_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_DZ;
            
          break;
        }
      case ID_MTZ_FRAMEWIN:
        {
          Protection_FrameWin = &MTZ_FrameWin;
          Protection_panel_title = &MTZ_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_MTZ_Pages[0];
          
          max_number_pickup_protection = MAX_NUMBER_PICKUP_MTZ;
          
          Protection_Pickup_t = MTZ_Pickup_t;
          Protection_Pickup_v = MTZ_Pickup_v;
          Protection_Pickup_m = MTZ_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_MTZ_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_MTZ_PICKUP_VALUE_29;
          
          Protection_pickups_notification_value_changed = MTZ_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_MTZ_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_MTZ;
            
          break;
        }
      case ID_UMIN_FRAMEWIN:
        {
          Protection_FrameWin = &Umin_FrameWin;
          Protection_panel_title = &Umin_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_Umin_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_UMIN;

          Protection_Pickup_t = Umin_Pickup_t;
          Protection_Pickup_v = Umin_Pickup_v;
          Protection_Pickup_m = Umin_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_UMIN_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_UMIN_PICKUP_VALUE_3;
          
          Protection_pickups_notification_value_changed = Umin_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_Umin_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_Umin;
            
          break;
        }
      case ID_UMAX_FRAMEWIN:
        {
          Protection_FrameWin = &Umax_FrameWin;
          Protection_panel_title = &Umax_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_Umax_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_UMAX;

          Protection_Pickup_t = Umax_Pickup_t;
          Protection_Pickup_v = Umax_Pickup_v;
          Protection_Pickup_m = Umax_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_UMAX_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_UMAX_PICKUP_VALUE_1;
          
          Protection_pickups_notification_value_changed = Umax_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_Umax_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_Umax;
            
          break;
        }
      case ID_TZNP_FRAMEWIN:
        {
          Protection_FrameWin = &TZNP_FrameWin;
          Protection_panel_title = &TZNP_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_TZNP_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_TZNP;

          Protection_Pickup_t = TZNP_Pickup_t;
          Protection_Pickup_v = TZNP_Pickup_v;
          Protection_Pickup_m = TZNP_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_TZNP_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_TZNP_PICKUP_VALUE_14;
          
          Protection_pickups_notification_value_changed = TZNP_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_TZNP_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_TZNP;
            
          break;
        }
      case ID_ZOP_FRAMEWIN:
        {
          Protection_FrameWin = &ZOP_FrameWin;
          Protection_panel_title = &ZOP_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_ZOP_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_ZOP;

          Protection_Pickup_t = ZOP_Pickup_t;
          Protection_Pickup_v = ZOP_Pickup_v;
          Protection_Pickup_m = ZOP_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_ZOP_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_ZOP_PICKUP_VALUE_11;
          
          Protection_pickups_notification_value_changed = ZOP_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_ZOP_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_ZOP;
            
          break;
        }
      case ID_APV_FRAMEWIN:
        {
          Protection_FrameWin = &APV_FrameWin;
          Protection_panel_title = &APV_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_APV_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_APV;

          Protection_Pickup_t = APV_Pickup_t;
          Protection_Pickup_v = APV_Pickup_v;
          Protection_Pickup_m = APV_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_APV_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_APV_PICKUP_VALUE_6;
          
          Protection_pickups_notification_value_changed = APV_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_APV_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_APV;
            
          break;
        }
      case ID_UROV_FRAMEWIN:
        {
          Protection_FrameWin = &UROV_FrameWin;
          Protection_panel_title = &UROV_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_UROV_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_UROV;

          Protection_Pickup_t = UROV_Pickup_t;
          Protection_Pickup_v = UROV_Pickup_v;
          Protection_Pickup_m = UROV_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_UROV_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_UROV_PICKUP_VALUE_0;
          
          Protection_pickups_notification_value_changed = UROV_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_UROV_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_UROV;
            
          break;
        }
      case ID_CB_FRAMEWIN:
        {
          Protection_FrameWin = &CB_FrameWin;
          Protection_panel_title = &CB_panel_title;
            
          ScrollBar_Protection_Pages = &ScrollBar_CB_Pages[0];

          max_number_pickup_protection = MAX_NUMBER_PICKUP_CB;

          Protection_Pickup_t = CB_Pickup_t;
          Protection_Pickup_v = CB_Pickup_v;
          Protection_Pickup_m = CB_Pickup_m;
          
          id_ed_protection_pickup_value_min = ID_ED_CB_PICKUP_VALUE_0;
          id_ed_protection_pickup_value_max = ID_ED_CB_PICKUP_VALUE_6;
          
          Protection_pickups_notification_value_changed = CB_pickups_notification_value_changed;
          
          focus_Protection_Pickup_v = &focus_CB_Pickup_v;
          _y_cbPickup_Protection = &_y_cbPickup_CB;
            
          break;
        }
      default:
        {
          //Сюди програма ніколи б не мала зайти
          while(1);
        }
      }

      WM_HWIN hObjSrc = pMsg->hWinSrc;
      int Id = WM_GetId(hObjSrc);
      int NCode = pMsg->Data.v;

      
      switch (NCode)
      {
      case WM_NOTIFICATION_GOT_FOCUS:
        {
          if (*focus_Protection_Pickup_v != hObjSrc)
          {
            /*
            Визначаємо координати об'єкта, який сфокусований
            */
            WM_SCROLL_STATE ScrollState;
            WM_GetScrollState(*ScrollBar_Protection_Pages, &ScrollState);

            int y_hWinSrc = *_y_cbPickup_Protection + WM_GetWindowOrgY(pMsg->hWinSrc);
            int y_hWin    = WM_GetWindowOrgY(pMsg->hWin);
            int y_tmp = y_hWinSrc - y_hWin;
            int v_scroll;
            v_scroll = y_tmp/ScrollState.PageSize;
            v_scroll *= ScrollState.PageSize;
        
            if (*_y_cbPickup_Protection != v_scroll)
            {
              int dy = *_y_cbPickup_Protection - v_scroll;
              for (unsigned int i = 0; i < max_number_pickup_protection; i++) 
              {
                WM_MoveWindow(*(Protection_Pickup_t + i), 0, dy);
                WM_MoveWindow(*(Protection_Pickup_v + i), 0, dy);
                WM_MoveWindow(*(Protection_Pickup_m + i), 0, dy);
              }
            }
            *_y_cbPickup_Protection = v_scroll;
            *focus_Protection_Pickup_v = hObjSrc;
            SCROLLBAR_SetValue(*ScrollBar_Protection_Pages, v_scroll);
          }
          break;
        }
      case WM_NOTIFICATION_VALUE_CHANGED:
        {
          if (
              (Id >= id_ed_protection_pickup_value_min) &&
              (Id <= id_ed_protection_pickup_value_max)
             )   
          {
            CfgTblDsc *point;
            if (current_ekran.edition == 0) point = &eeprom_prt_tbl;
            else  point = &edit_settings;
            
            float value = EDIT_GetFloatValue(hObjSrc);

            int value_int, *p_value_int_edit;
            int  min = 0, max = 0;
          
            p_value_int_edit = (*Protection_pickups_notification_value_changed)((_id_user_widget)Id, point, &min, &max, &value, &value_int);
            
            if (
                (current_ekran.edition != 0)
              )   
            {
              //Режим редагування
              if (
                  (*p_value_int_edit != value_int) &&
                  (point == &edit_settings) /*це перестраховка*/
                )   
              {
                *p_value_int_edit = value_int;

                if (current_ekran.edition == 1)
                {
                  //Помічаємо, що дані змінені
                  char title[256];
                  title[0] = '\0';
                  strcat_mal(title, (char *)Protection_panel_title->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
                  strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
                  strcat_mal(title, "*");
                  FRAMEWIN_SetText(*Protection_FrameWin, title);
                  current_ekran.edition = 2;
                }
              }
            }
            
            __info_data info_data;
            EDIT_GetUserData(hObjSrc, &info_data, sizeof(__info_data));
            if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) value_int = abs(value_int);
            if ((value_int >= min) && (value_int <= max))
            {
              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_BLACK);
              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_BLACK);
            }
            else
            {
              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_RED);
              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_RED);
            }
          }
          
          break;
        }
      default: break;
      }

      break;
    }
//  case WM_PAINT:
//    {
//      break;
//    }
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}
/*****************************/

/*****************************
       _cbDelays_Protection
*****************************/
static WM_HWIN focus_DZ_Delay_v;
static WM_HWIN focus_MTZ_Delay_v;
static WM_HWIN focus_Umin_Delay_v;
static WM_HWIN focus_Umax_Delay_v;
static WM_HWIN focus_TZNP_Delay_v;
static WM_HWIN focus_ZOP_Delay_v;
static WM_HWIN focus_APV_Delay_v;
static WM_HWIN focus_UROV_Delay_v;
static WM_HWIN focus_CB_Delay_v;
static void _cbDelays_Protection(WM_MESSAGE * pMsg) 
{
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) 
  {
  // USER START (Optionally insert additional message handling)
  // USER END
  case WM_NOTIFY_PARENT:
    {
      WM_HWIN *Protection_FrameWin, *ScrollBar_Protection_Pages, *Protection_Delay_t, *Protection_Delay_v, *Protection_Delay_m;
      WM_HWIN *focus_Protection_Delay_v;
      const TITLE *Protection_panel_title;
      unsigned int max_number_delay_protection;
      _id_user_widget id_ed_protection_delay_value_min, id_ed_protection_delay_value_max;
      unsigned short int* (*Protection_delays_notification_value_changed)(_id_user_widget, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
      int *_y_cbDelay_Protection;
      unsigned int index_shift = 0;

      switch (find_id_FrameWin(pMsg->hWin))
      {
      case ID_DZ_FRAMEWIN:
        {
          Protection_FrameWin = &DZ_FrameWin;
          Protection_panel_title = &DZ_panel_title;
          
          Protection_delays_notification_value_changed = DZ_delays_notification_value_changed;

          focus_Protection_Delay_v = &focus_DZ_Delay_v;

          Protection_Delay_t = DZ_Delay_t;
          Protection_Delay_v = DZ_Delay_v;
          Protection_Delay_m = DZ_Delay_m;
          
          if (WM_IsVisible(DZ_SubPages_delay[0]))
          {
            ScrollBar_Protection_Pages = &ScrollBar_DZ_SubPages_delay[0];
          
            max_number_delay_protection = MAX_NUMBER_DELAY_DZ;
          
            id_ed_protection_delay_value_min = ID_ED_DZ_DELAY_VALUE_0;
            id_ed_protection_delay_value_max = ID_ED_DZ_DELAY_VALUE_66;
          
            _y_cbDelay_Protection = &_y_cbDelay_DZ;
          }
          else
          {
            ScrollBar_Protection_Pages = &ScrollBar_DZ_SubPages_delay[1];
          
            index_shift = MAX_NUMBER_DELAY_DZ;
            max_number_delay_protection = MAX_NUMBER_DELAY_DZ_G;
          
            id_ed_protection_delay_value_min = ID_ED_DZ_DELAY_G_VALUE_0;
            id_ed_protection_delay_value_max = ID_ED_DZ_DELAY_G_VALUE_1;
          
            _y_cbDelay_Protection = &_y_cbDelay_DZ_g;
          }
            
          break;
        }
      case ID_MTZ_FRAMEWIN:
        {
          Protection_FrameWin = &MTZ_FrameWin;
          Protection_panel_title = &MTZ_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_MTZ_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_MTZ;
          
          Protection_Delay_t = MTZ_Delay_t;
          Protection_Delay_v = MTZ_Delay_v;
          Protection_Delay_m = MTZ_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_MTZ_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_MTZ_DELAY_VALUE_71;
          
          Protection_delays_notification_value_changed = MTZ_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_MTZ_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_MTZ;
            
          break;
        }
      case ID_UMIN_FRAMEWIN:
        {
          Protection_FrameWin = &Umin_FrameWin;
          Protection_panel_title = &Umin_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_Umin_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_UMIN;
          
          Protection_Delay_t = Umin_Delay_t;
          Protection_Delay_v = Umin_Delay_v;
          Protection_Delay_m = Umin_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_UMIN_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_UMIN_DELAY_VALUE_1;
          
          Protection_delays_notification_value_changed = Umin_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_Umin_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_Umin;
            
          break;
        }
      case ID_UMAX_FRAMEWIN:
        {
          Protection_FrameWin = &Umax_FrameWin;
          Protection_panel_title = &Umax_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_Umax_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_UMAX;
          
          Protection_Delay_t = Umax_Delay_t;
          Protection_Delay_v = Umax_Delay_v;
          Protection_Delay_m = Umax_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_UMAX_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_UMAX_DELAY_VALUE_1;
          
          Protection_delays_notification_value_changed = Umax_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_Umax_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_Umax;
            
          break;
        }
      case ID_TZNP_FRAMEWIN:
        {
          Protection_FrameWin = &TZNP_FrameWin;
          Protection_panel_title = &TZNP_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_TZNP_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_TZNP;
          
          Protection_Delay_t = TZNP_Delay_t;
          Protection_Delay_v = TZNP_Delay_v;
          Protection_Delay_m = TZNP_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_TZNP_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_TZNP_DELAY_VALUE_49;
          
          Protection_delays_notification_value_changed = TZNP_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_TZNP_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_TZNP;
            
          break;
        }
      case ID_ZOP_FRAMEWIN:
        {
          Protection_FrameWin = &ZOP_FrameWin;
          Protection_panel_title = &ZOP_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_ZOP_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_ZOP;
          
          Protection_Delay_t = ZOP_Delay_t;
          Protection_Delay_v = ZOP_Delay_v;
          Protection_Delay_m = ZOP_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_ZOP_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_ZOP_DELAY_VALUE_5;
          
          Protection_delays_notification_value_changed = ZOP_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_ZOP_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_ZOP;
            
          break;
        }
      case ID_APV_FRAMEWIN:
        {
          Protection_FrameWin = &APV_FrameWin;
          Protection_panel_title = &APV_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_APV_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_APV;
          
          Protection_Delay_t = APV_Delay_t;
          Protection_Delay_v = APV_Delay_v;
          Protection_Delay_m = APV_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_APV_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_APV_DELAY_VALUE_9;
          
          Protection_delays_notification_value_changed = APV_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_APV_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_APV;
            
          break;
        }
      case ID_UROV_FRAMEWIN:
        {
          Protection_FrameWin = &UROV_FrameWin;
          Protection_panel_title = &UROV_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_UROV_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_UROV;
          
          Protection_Delay_t = UROV_Delay_t;
          Protection_Delay_v = UROV_Delay_v;
          Protection_Delay_m = UROV_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_UROV_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_UROV_DELAY_VALUE_1;
          
          Protection_delays_notification_value_changed = UROV_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_UROV_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_UROV;
            
          break;
        }
      case ID_CB_FRAMEWIN:
        {
          Protection_FrameWin = &CB_FrameWin;
          Protection_panel_title = &CB_panel_title;
          
          ScrollBar_Protection_Pages = &ScrollBar_CB_Pages[1];
          
          max_number_delay_protection = MAX_NUMBER_DELAY_CB;
          
          Protection_Delay_t = CB_Delay_t;
          Protection_Delay_v = CB_Delay_v;
          Protection_Delay_m = CB_Delay_m;
          
          id_ed_protection_delay_value_min = ID_ED_CB_DELAY_VALUE_0;
          id_ed_protection_delay_value_max = ID_ED_CB_DELAY_VALUE_4;
          
          Protection_delays_notification_value_changed = CB_delays_notification_value_changed;
          
          focus_Protection_Delay_v = &focus_CB_Delay_v;
          _y_cbDelay_Protection = &_y_cbDelay_CB;
            
          break;
        }
      default:
        {
          //Сюди програма ніколи б не мала зайти
          while(1);
        }
      }

      WM_HWIN hObjSrc = pMsg->hWinSrc;
      int Id    = WM_GetId(hObjSrc);
      int NCode = pMsg->Data.v;
      
      switch (NCode)
      {
      case WM_NOTIFICATION_GOT_FOCUS:
        {
          if (*focus_Protection_Delay_v != hObjSrc)
          {
            /*
            Визначаємо координати об'єкта, який сфокусований
            */
            WM_SCROLL_STATE ScrollState;
            WM_GetScrollState(*ScrollBar_Protection_Pages, &ScrollState);

            int y_hWinSrc = *_y_cbDelay_Protection + WM_GetWindowOrgY(pMsg->hWinSrc);
            int y_hWin    = WM_GetWindowOrgY(pMsg->hWin);
            int y_tmp = y_hWinSrc - y_hWin;
            int v_scroll;
            v_scroll = y_tmp/ScrollState.PageSize;
            v_scroll *= ScrollState.PageSize;
        
            if (*_y_cbDelay_Protection != v_scroll)
            {
              int dy = *_y_cbDelay_Protection - v_scroll;
              for (unsigned int i = 0; i < max_number_delay_protection; i++) 
              {
                WM_MoveWindow(*(Protection_Delay_t + index_shift + i), 0, dy);
                WM_MoveWindow(*(Protection_Delay_v + index_shift + i), 0, dy);
                WM_MoveWindow(*(Protection_Delay_m + index_shift + i), 0, dy);
              }
            }
            *_y_cbDelay_Protection = v_scroll;
            *focus_Protection_Delay_v = hObjSrc;
            SCROLLBAR_SetValue(*ScrollBar_Protection_Pages, v_scroll);
          }
          break;
        }
      case WM_NOTIFICATION_VALUE_CHANGED:
        {
          if (
              (Id >= id_ed_protection_delay_value_min) &&
              (Id <= id_ed_protection_delay_value_max)
             )   
          {
            CfgTblDsc *point;
            if (current_ekran.edition == 0) point = &eeprom_prt_tbl;
            else  point = &edit_settings;
            
            float value = EDIT_GetFloatValue(hObjSrc);

            unsigned int value_int;
            unsigned short *p_value_int_edit;
            unsigned int  min = 0, max = 0;
          
            p_value_int_edit = (*Protection_delays_notification_value_changed)((_id_user_widget)Id, point, &min, &max, &value, &value_int);
            
            if (
                (current_ekran.edition != 0)
               )   
            {
              //Режим редагування
              if (
                  (*p_value_int_edit != value_int) &&
                  (point == &edit_settings) /*це перестраховка*/
                 )   
              {
                *p_value_int_edit = (unsigned short)value_int;

                if (current_ekran.edition == 1)
                {
                  //Помічаємо, що дані змінені
                  char title[256];
                  title[0] = '\0';
                  strcat_mal(title, (char *)Protection_panel_title->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
                  strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
                  strcat_mal(title, "*");
                  FRAMEWIN_SetText(*Protection_FrameWin, title);
                  current_ekran.edition = 2;
                }
              }
            }
            
            if ((value_int >= min) && (value_int <= max))
            {
              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_BLACK);
              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_BLACK);
            }
            else
            {
              EDIT_SetTextColor(hObjSrc, EDIT_CI_DISABLED, GUI_RED);
              EDIT_SetTextColor(hObjSrc, EDIT_CI_ENABLED, GUI_RED);
            }
          }
          
          break;
        }
      default: break;
      }

      break;
    }
//  case WM_PAINT:
//    {
//      break;
//    }
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}
/*****************************/

/*****************************
       _cbControl_Protection
*****************************/
static WM_HWIN focus_DZ_State_v;
static WM_HWIN focus_MTZ_State_v;
static WM_HWIN focus_Umin_State_v;
static WM_HWIN focus_Umax_State_v;
static WM_HWIN focus_TZNP_State_v;
static WM_HWIN focus_ZOP_State_v;
static WM_HWIN focus_APV_State_v;
static WM_HWIN focus_UROV_State_v;
static WM_HWIN focus_CB_State_v;
static void _cbControl_Protection(WM_MESSAGE * pMsg) 
{
  // USER START (Optionally insert additional variables)
  // USER END
  switch (pMsg->MsgId) 
  {
  // USER START (Optionally insert additional message handling)
  // USER END
  case WM_NOTIFY_PARENT:
    {
      WM_HWIN *ScrollBar_Protection_Pages, *Protection_State_t, *Protection_State_v;
      WM_HWIN *focus_Protection_State_v;
      unsigned int max_number_ctrl_protection;
      int *_y_cbControl_Protection;

      switch (find_id_FrameWin(pMsg->hWin))
      {
      case ID_DZ_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_DZ_Pages[2];

          max_number_ctrl_protection = MAX_NUMBER_CTRL_DZ;

          Protection_State_t = DZ_State_t;
          Protection_State_v = DZ_State_v;

          focus_Protection_State_v = &focus_DZ_State_v;
          _y_cbControl_Protection = &_y_cbControl_DZ;
          
          break;
        }
      case ID_MTZ_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_MTZ_Pages[2];

          max_number_ctrl_protection = MAX_NUMBER_CTRL_MTZ;

          Protection_State_t = MTZ_State_t;
          Protection_State_v = MTZ_State_v;

          focus_Protection_State_v = &focus_MTZ_State_v;
          _y_cbControl_Protection = &_y_cbControl_MTZ;
          
          break;
        }
      case ID_UMIN_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_Umin_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_UMIN;

          Protection_State_t = Umin_State_t;
          Protection_State_v = Umin_State_v;

          focus_Protection_State_v = &focus_Umin_State_v;
          _y_cbControl_Protection = &_y_cbControl_Umin;

          break;
        }
      case ID_UMAX_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_Umax_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_UMAX;

          Protection_State_t = Umax_State_t;
          Protection_State_v = Umax_State_v;

          focus_Protection_State_v = &focus_Umax_State_v;
          _y_cbControl_Protection = &_y_cbControl_Umax;

          break;
        }
      case ID_TZNP_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_TZNP_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_TZNP;

          Protection_State_t = TZNP_State_t;
          Protection_State_v = TZNP_State_v;

          focus_Protection_State_v = &focus_TZNP_State_v;
          _y_cbControl_Protection = &_y_cbControl_TZNP;

          break;
        }
      case ID_ZOP_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_ZOP_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_ZOP;

          Protection_State_t = ZOP_State_t;
          Protection_State_v = ZOP_State_v;

          focus_Protection_State_v = &focus_ZOP_State_v;
          _y_cbControl_Protection = &_y_cbControl_ZOP;

          break;
        }
      case ID_APV_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_APV_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_APV;

          Protection_State_t = APV_State_t;
          Protection_State_v = APV_State_v;

          focus_Protection_State_v = &focus_APV_State_v;
          _y_cbControl_Protection = &_y_cbControl_APV;

          break;
        }
      case ID_UROV_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_UROV_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_UROV;

          Protection_State_t = UROV_State_t;
          Protection_State_v = UROV_State_v;

          focus_Protection_State_v = &focus_UROV_State_v;
          _y_cbControl_Protection = &_y_cbControl_UROV;

          break;
        }
      case ID_CB_FRAMEWIN:
        {
          ScrollBar_Protection_Pages = &ScrollBar_CB_Pages[2];
            
          max_number_ctrl_protection = MAX_NUMBER_CTRL_CB;

          Protection_State_t = CB_State_t;
          Protection_State_v = CB_State_v;

          focus_Protection_State_v = &focus_CB_State_v;
          _y_cbControl_Protection = &_y_cbControl_CB;

          break;
        }
      default:
        {
          //Сюди програма ніколи б не мала зайти
          while(1);
        }
      }

      if (
          (pMsg->Data.v == WM_NOTIFICATION_GOT_FOCUS) &&
          (*focus_Protection_State_v != pMsg->hWinSrc)
         )  
      {
        /*
        Визначаємо координати об'єкта, який сфокусований
        */
        WM_SCROLL_STATE ScrollState;
        WM_GetScrollState(*ScrollBar_Protection_Pages, &ScrollState);

        int y_hWinSrc = *_y_cbControl_Protection + WM_GetWindowOrgY(pMsg->hWinSrc);
        int y_hWin    = WM_GetWindowOrgY(pMsg->hWin);
        int y_tmp = y_hWinSrc - y_hWin;
        int v_scroll;
        v_scroll = y_tmp/ScrollState.PageSize;
        v_scroll *= ScrollState.PageSize;
        
        if (*_y_cbControl_Protection != v_scroll)
        {
          int dy = *_y_cbControl_Protection - v_scroll;
          for (unsigned int i = 0; i < max_number_ctrl_protection; i++) 
          {
            WM_MoveWindow(*(Protection_State_t + i), 0, dy);
            WM_MoveWindow(*(Protection_State_v + i), 0, dy);
          }
        }
        *_y_cbControl_Protection = v_scroll;
        *focus_Protection_State_v = pMsg->hWinSrc;
        SCROLLBAR_SetValue(*ScrollBar_Protection_Pages, v_scroll);
      }
      break;
    }
//  case WM_PAINT:
//    {
//      break;
//    }
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}
/*****************************/

/*****************************
Вибір сторінки
*****************************/
void select_multipage_general(WM_HWIN widget, int index) 
{
  if (MULTIPAGE_GetSelection(widget) != index)
  {
    for (int i = 0; i < MAX_PAGES_PROTECTION_SDC; i++)
    {
      if(i != index) 
      {
        MULTIPAGE_DisablePage(widget, i);
      }
      else
      {
        MULTIPAGE_EnablePage(widget, index);
        MULTIPAGE_SelectPage(widget, index);
      }
    }
  }
}
/*****************************/

/*****************************
Вибір сторінки групи уставок
*****************************/
void select_multipage_groups(WM_HWIN widget, WM_HWIN *Protection_Pages, int index_g, int index_p, int max_p) 
{
  if ((index_p + 1) < max_p)
  {
    if (MULTIPAGE_GetSelection(widget) != index_g)
    {
      for (int i = 0; i < (AMOUNT_SERIES_PPSPM_SETTINGS + 1); i++) 
      {
        if (i != index_g) MULTIPAGE_DisablePage(widget, i);
      }

      MULTIPAGE_EnablePage(widget, index_g);
      MULTIPAGE_SelectPage(widget, index_g);
      
      if ((Protection_Pages == DZ_Pages) && (index_p == 1))
      {
        if (index_g != AMOUNT_SERIES_PPSPM_SETTINGS)
        {
          WM_HideWindow(DZ_SubPages_delay[1]);
          WM_ShowWindow(DZ_SubPages_delay[0]);
        }
        else
        {
          WM_HideWindow(DZ_SubPages_delay[0]);
          WM_ShowWindow(DZ_SubPages_delay[1]);
        }
      }
    }
  }
  else
  {
    if (MULTIPAGE_GetSelection(widget) != AMOUNT_SERIES_PPSPM_SETTINGS)
    {
      for (unsigned int i = 0; i < AMOUNT_SERIES_PPSPM_SETTINGS; i++) MULTIPAGE_DisablePage(widget, i);

      MULTIPAGE_EnablePage(widget, AMOUNT_SERIES_PPSPM_SETTINGS);
      MULTIPAGE_SelectPage(widget, AMOUNT_SERIES_PPSPM_SETTINGS);
    }
  }
}
/*****************************/

/*****************************
Ініціалізація панелі для захистів
*****************************/
void protection_settings_panel_show(unsigned int id_protection)
{
  _id_user_widget id_protection_framewin, id_protection_multipage_groups, id_protection_groups;
  _id_user_widget id_protection_multipage_type_info, id_protection_pickups;
  _id_user_widget id_text_protection_pickup_0_title, id_ed_protection_pickup_value_0, id_text_protection_pickup_0_measures;
  _id_user_widget id_text_protection_delay_0_title, id_ed_protection_delay_value_0, id_text_protection_delay_0_measures;
  _id_user_widget id_text_protection_state_0, id_dd_protection_state_0;

  const TITLE *Protection_panel_title, *Protection_Pickup_title, *Protection_Delay_title, *Protection_State_title;

  WM_HWIN *Protection_FrameWin, *Protection_MultiPage_groups, *Protection_Window_group;
  WM_HWIN *Protection_MultiPage_type_info, *Protection_Pages, *ScrollBar_Protection_Pages;
  WM_HWIN *Protection_Pickup_t, *Protection_Pickup_v, *Protection_Pickup_m;
  WM_HWIN *Protection_Delay_t, *Protection_Delay_v, *Protection_Delay_m;
  WM_HWIN *Protection_State_t, *Protection_State_v;
    
  unsigned int max_number_pickup_protection, max_number_delay_protection, max_number_ctrl_protection;
  unsigned int max_kilkist_stupeniv_protection;
  const unsigned short int *nalashtuvannja_protection;
  
  const char* (*Protection_pickup_info_1)(unsigned int, int*, int*, int*, unsigned int*);
  const char* (*Protection_delay_info_1)(unsigned int, int*, int*, int*);
  const TITLE* (*Protection_control_info)(unsigned int, int*);
  
  int width_x_t, width_x_v;
  
  unsigned int groups = AMOUNT_SERIES_PPSPM_SETTINGS;
  
  switch (id_protection)
  {
  case ID_DZ_PG:
    {
      id_protection_framewin = ID_DZ_FRAMEWIN;
      Protection_panel_title = &DZ_panel_title;
      Protection_FrameWin = &DZ_FrameWin;
      
      id_protection_multipage_groups = ID_DZ_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &DZ_MultiPage_groups;
      
      id_protection_groups = ID_DZ_GROUPS;
      Protection_Window_group = &DZ_Window_group;
      
      id_protection_multipage_type_info = ID_DZ_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &DZ_MultiPage_type_info;
      
      id_protection_pickups = ID_DZ_PICKUPS;
      Protection_Pages = DZ_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_DZ_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_DZ;
      max_number_delay_protection = MAX_NUMBER_DELAY_DZ;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_DZ;
      
      max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_DZ + 1;
      nalashtuvannja_protection = nalashtuvannja_DZ;
      
      id_text_protection_pickup_0_title = ID_TEXT_DZ_PICKUP_0_TITLE;
      Protection_Pickup_t = DZ_Pickup_t;
      Protection_Pickup_title = DZ_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_DZ_PICKUP_VALUE_0;
      Protection_Pickup_v = DZ_Pickup_v;
      Protection_pickup_info_1 = DZ_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_DZ_PICKUP_0_MEASURES;
      Protection_Pickup_m = DZ_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_DZ_DELAY_0_TITLE;
      Protection_Delay_t = DZ_Delay_t;
      Protection_Delay_title = DZ_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_DZ_DELAY_VALUE_0;
      Protection_Delay_v = DZ_Delay_v;
      Protection_delay_info_1 = DZ_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_DZ_DELAY_0_MEASURES;
      Protection_Delay_m = DZ_Delay_m;

      id_text_protection_state_0 = ID_TEXT_DZ_STATE_0;
      Protection_State_t = DZ_State_t;
      Protection_State_title = DZ_State_title;
      id_dd_protection_state_0 = ID_DD_DZ_STATE_0;
      Protection_State_v = DZ_State_v;
      Protection_control_info = DZ_control_info;
      
      width_x_t = 83;
      width_x_v = 55;
      
      break;
    }
  case ID_MTZ_PG:
    {
      id_protection_framewin = ID_MTZ_FRAMEWIN;
      Protection_panel_title = &MTZ_panel_title;
      Protection_FrameWin = &MTZ_FrameWin;
      
      id_protection_multipage_groups = ID_MTZ_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &MTZ_MultiPage_groups;
      
      id_protection_groups = ID_MTZ_GROUPS;
      Protection_Window_group = &MTZ_Window_group;
      
      id_protection_multipage_type_info = ID_MTZ_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &MTZ_MultiPage_type_info;
      
      id_protection_pickups = ID_MTZ_PICKUPS;
      Protection_Pages = MTZ_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_MTZ_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_MTZ;
      max_number_delay_protection = MAX_NUMBER_DELAY_MTZ;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_MTZ;
      
      max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_MTZ + 1;
      nalashtuvannja_protection = nalashtuvannja_MTZ;
      
      id_text_protection_pickup_0_title = ID_TEXT_MTZ_PICKUP_0_TITLE;
      Protection_Pickup_t = MTZ_Pickup_t;
      Protection_Pickup_title = MTZ_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_MTZ_PICKUP_VALUE_0;
      Protection_Pickup_v = MTZ_Pickup_v;
      Protection_pickup_info_1 = MTZ_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_MTZ_PICKUP_0_MEASURES;
      Protection_Pickup_m = MTZ_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_MTZ_DELAY_0_TITLE;
      Protection_Delay_t = MTZ_Delay_t;
      Protection_Delay_title = MTZ_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_MTZ_DELAY_VALUE_0;
      Protection_Delay_v = MTZ_Delay_v;
      Protection_delay_info_1 = MTZ_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_MTZ_DELAY_0_MEASURES;
      Protection_Delay_m = MTZ_Delay_m;

      id_text_protection_state_0 = ID_TEXT_MTZ_STATE_0;
      Protection_State_t = MTZ_State_t;
      Protection_State_title = MTZ_State_title;
      id_dd_protection_state_0 = ID_DD_MTZ_STATE_0;
      Protection_State_v = MTZ_State_v;
      Protection_control_info = MTZ_control_info;
      
      width_x_t = 67;
      width_x_v = 67;
      
      break;
    }
  case ID_UMIN_PG:
    {
      id_protection_framewin = ID_UMIN_FRAMEWIN;
      Protection_panel_title = &Umin_panel_title;
      Protection_FrameWin = &Umin_FrameWin;
      
      id_protection_multipage_groups = ID_UMIN_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &Umin_MultiPage_groups;
      
      id_protection_groups = ID_UMIN_GROUPS;
      Protection_Window_group = &Umin_Window_group;
      
      id_protection_multipage_type_info = ID_UMIN_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &Umin_MultiPage_type_info;

      id_protection_pickups = ID_UMIN_PICKUPS;
      Protection_Pages = Umin_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_Umin_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_UMIN;
      max_number_delay_protection = MAX_NUMBER_DELAY_UMIN;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_UMIN;

      max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_UMIN + 1;
      nalashtuvannja_protection = nalashtuvannja_Umin;
      
      id_text_protection_pickup_0_title = ID_TEXT_UMIN_PICKUP_0_TITLE;
      Protection_Pickup_t = Umin_Pickup_t;
      Protection_Pickup_title = Umin_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_UMIN_PICKUP_VALUE_0;
      Protection_Pickup_v = Umin_Pickup_v;
      Protection_pickup_info_1 = Umin_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_UMIN_PICKUP_0_MEASURES;
      Protection_Pickup_m = Umin_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_UMIN_DELAY_0_TITLE;
      Protection_Delay_t = Umin_Delay_t;
      Protection_Delay_title = Umin_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_UMIN_DELAY_VALUE_0;
      Protection_Delay_v = Umin_Delay_v;
      Protection_delay_info_1 = Umin_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_UMIN_DELAY_0_MEASURES;
      Protection_Delay_m = Umin_Delay_m;

      id_text_protection_state_0 = ID_TEXT_UMIN_STATE_0;
      Protection_State_t = Umin_State_t;
      Protection_State_title = Umin_State_title;
      id_dd_protection_state_0 = ID_DD_UMIN_STATE_0;
      Protection_State_v = Umin_State_v;
      Protection_control_info = Umin_control_info;
      
      width_x_t = 80;
      width_x_v = 54;
      
      break;
    }
  case ID_UMAX_PG:
    {
      id_protection_framewin = ID_UMAX_FRAMEWIN;
      Protection_panel_title = &Umax_panel_title;
      Protection_FrameWin = &Umax_FrameWin;
      
      id_protection_multipage_groups = ID_UMAX_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &Umax_MultiPage_groups;
      
      id_protection_groups = ID_UMAX_GROUPS;
      Protection_Window_group = &Umax_Window_group;
      
      id_protection_multipage_type_info = ID_UMAX_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &Umax_MultiPage_type_info;

      id_protection_pickups = ID_UMAX_PICKUPS;
      Protection_Pages = Umax_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_Umax_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_UMAX;
      max_number_delay_protection = MAX_NUMBER_DELAY_UMAX;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_UMAX;

      max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_UMAX + 1;
      nalashtuvannja_protection = nalashtuvannja_Umax;
      
      id_text_protection_pickup_0_title = ID_TEXT_UMAX_PICKUP_0_TITLE;
      Protection_Pickup_t = Umax_Pickup_t;
      Protection_Pickup_title = Umax_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_UMAX_PICKUP_VALUE_0;
      Protection_Pickup_v = Umax_Pickup_v;
      Protection_pickup_info_1 = Umax_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_UMAX_PICKUP_0_MEASURES;
      Protection_Pickup_m = Umax_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_UMAX_DELAY_0_TITLE;
      Protection_Delay_t = Umax_Delay_t;
      Protection_Delay_title = Umax_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_UMAX_DELAY_VALUE_0;
      Protection_Delay_v = Umax_Delay_v;
      Protection_delay_info_1 = Umax_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_UMAX_DELAY_0_MEASURES;
      Protection_Delay_m = Umax_Delay_m;

      id_text_protection_state_0 = ID_TEXT_UMAX_STATE_0;
      Protection_State_t = Umax_State_t;
      Protection_State_title = Umax_State_title;
      id_dd_protection_state_0 = ID_DD_UMAX_STATE_0;
      Protection_State_v = Umax_State_v;
      Protection_control_info = Umax_control_info;
      
      width_x_t = 80;
      width_x_v = 54;
      
      break;
    }
  case ID_TZNP_PG:
    {
      id_protection_framewin = ID_TZNP_FRAMEWIN;
      Protection_panel_title = &TZNP_panel_title;
      Protection_FrameWin = &TZNP_FrameWin;
      
      id_protection_multipage_groups = ID_TZNP_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &TZNP_MultiPage_groups;
      
      id_protection_groups = ID_TZNP_GROUPS;
      Protection_Window_group = &TZNP_Window_group;
      
      id_protection_multipage_type_info = ID_TZNP_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &TZNP_MultiPage_type_info;

      id_protection_pickups = ID_TZNP_PICKUPS;
      Protection_Pages = TZNP_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_TZNP_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_TZNP;
      max_number_delay_protection = MAX_NUMBER_DELAY_TZNP;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_TZNP;

      max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_TZNP + 1;
      nalashtuvannja_protection = nalashtuvannja_TZNP;
      
      id_text_protection_pickup_0_title = ID_TEXT_TZNP_PICKUP_0_TITLE;
      Protection_Pickup_t = TZNP_Pickup_t;
      Protection_Pickup_title = TZNP_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_TZNP_PICKUP_VALUE_0;
      Protection_Pickup_v = TZNP_Pickup_v;
      Protection_pickup_info_1 = TZNP_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_TZNP_PICKUP_0_MEASURES;
      Protection_Pickup_m = TZNP_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_TZNP_DELAY_0_TITLE;
      Protection_Delay_t = TZNP_Delay_t;
      Protection_Delay_title = TZNP_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_TZNP_DELAY_VALUE_0;
      Protection_Delay_v = TZNP_Delay_v;
      Protection_delay_info_1 = TZNP_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_TZNP_DELAY_0_MEASURES;
      Protection_Delay_m = TZNP_Delay_m;

      id_text_protection_state_0 = ID_TEXT_TZNP_STATE_0;
      Protection_State_t = TZNP_State_t;
      Protection_State_title = TZNP_State_title;
      id_dd_protection_state_0 = ID_DD_TZNP_STATE_0;
      Protection_State_v = TZNP_State_v;
      Protection_control_info = TZNP_control_info;
      
      width_x_t = 72;
      width_x_v = 62;
      
      break;
    }
  case ID_ZOP_PG:
    {
      id_protection_framewin = ID_ZOP_FRAMEWIN;
      Protection_panel_title = &ZOP_panel_title;
      Protection_FrameWin = &ZOP_FrameWin;
      
      id_protection_multipage_groups = ID_ZOP_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &ZOP_MultiPage_groups;
      
      id_protection_groups = ID_ZOP_GROUPS;
      Protection_Window_group = &ZOP_Window_group;
      
      id_protection_multipage_type_info = ID_ZOP_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &ZOP_MultiPage_type_info;

      id_protection_pickups = ID_ZOP_PICKUPS;
      Protection_Pages = ZOP_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_ZOP_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_ZOP;
      max_number_delay_protection = MAX_NUMBER_DELAY_ZOP;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_ZOP;

      max_kilkist_stupeniv_protection = MAX_KILKIST_STUPENIV_ZOP + 1;
      nalashtuvannja_protection = nalashtuvannja_ZOP;
      
      id_text_protection_pickup_0_title = ID_TEXT_ZOP_PICKUP_0_TITLE;
      Protection_Pickup_t = ZOP_Pickup_t;
      Protection_Pickup_title = ZOP_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_ZOP_PICKUP_VALUE_0;
      Protection_Pickup_v = ZOP_Pickup_v;
      Protection_pickup_info_1 = ZOP_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_ZOP_PICKUP_0_MEASURES;
      Protection_Pickup_m = ZOP_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_ZOP_DELAY_0_TITLE;
      Protection_Delay_t = ZOP_Delay_t;
      Protection_Delay_title = ZOP_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_ZOP_DELAY_VALUE_0;
      Protection_Delay_v = ZOP_Delay_v;
      Protection_delay_info_1 = ZOP_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_ZOP_DELAY_0_MEASURES;
      Protection_Delay_m = ZOP_Delay_m;

      id_text_protection_state_0 = ID_TEXT_ZOP_STATE_0;
      Protection_State_t = ZOP_State_t;
      Protection_State_title = ZOP_State_title;
      id_dd_protection_state_0 = ID_DD_ZOP_STATE_0;
      Protection_State_v = ZOP_State_v;
      Protection_control_info = ZOP_control_info;
      
      width_x_t = 64;
      width_x_v = 70;
      
      break;
    }
  case ID_APV_PG:
    {
      id_protection_framewin = ID_APV_FRAMEWIN;
      Protection_panel_title = &APV_panel_title;
      Protection_FrameWin = &APV_FrameWin;
      
      id_protection_multipage_groups = ID_APV_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &APV_MultiPage_groups;
      
      id_protection_groups = ID_APV_GROUPS;
      Protection_Window_group = &APV_Window_group;
      
      id_protection_multipage_type_info = ID_APV_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &APV_MultiPage_type_info;

      id_protection_pickups = ID_APV_PICKUPS;
      Protection_Pages = APV_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_APV_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_APV;
      max_number_delay_protection = MAX_NUMBER_DELAY_APV;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_APV;

      max_kilkist_stupeniv_protection = /*MAX_KILKIST_STUPENIV_APV + 1*/8;
      nalashtuvannja_protection = nalashtuvannja_APV;
      
      id_text_protection_pickup_0_title = ID_TEXT_APV_PICKUP_0_TITLE;
      Protection_Pickup_t = APV_Pickup_t;
      Protection_Pickup_title = APV_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_APV_PICKUP_VALUE_0;
      Protection_Pickup_v = APV_Pickup_v;
      Protection_pickup_info_1 = APV_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_APV_PICKUP_0_MEASURES;
      Protection_Pickup_m = APV_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_APV_DELAY_0_TITLE;
      Protection_Delay_t = APV_Delay_t;
      Protection_Delay_title = APV_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_APV_DELAY_VALUE_0;
      Protection_Delay_v = APV_Delay_v;
      Protection_delay_info_1 = APV_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_APV_DELAY_0_MEASURES;
      Protection_Delay_m = APV_Delay_m;

      id_text_protection_state_0 = ID_TEXT_APV_STATE_0;
      Protection_State_t = APV_State_t;
      Protection_State_title = APV_State_title;
      id_dd_protection_state_0 = ID_DD_APV_STATE_0;
      Protection_State_v = APV_State_v;
      Protection_control_info = APV_control_info;
      
      width_x_t = 84;
      width_x_v = 52;
      
      break;
    }
  case ID_UROV_PG:
    {
      id_protection_framewin = ID_UROV_FRAMEWIN;
      Protection_panel_title = &UROV_panel_title;
      Protection_FrameWin = &UROV_FrameWin;
      
      id_protection_multipage_groups = ID_UROV_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &UROV_MultiPage_groups;
      
      id_protection_groups = ID_UROV_GROUPS;
      Protection_Window_group = &UROV_Window_group;
      
      id_protection_multipage_type_info = ID_UROV_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &UROV_MultiPage_type_info;

      id_protection_pickups = ID_UROV_PICKUPS;
      Protection_Pages = UROV_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_UROV_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_UROV;
      max_number_delay_protection = MAX_NUMBER_DELAY_UROV;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_UROV;

      max_kilkist_stupeniv_protection = /*MAX_KILKIST_STUPENIV_UROV + 1*/8;
      nalashtuvannja_protection = nalashtuvannja_UROV;
      
      id_text_protection_pickup_0_title = ID_TEXT_UROV_PICKUP_0_TITLE;
      Protection_Pickup_t = UROV_Pickup_t;
      Protection_Pickup_title = UROV_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_UROV_PICKUP_VALUE_0;
      Protection_Pickup_v = UROV_Pickup_v;
      Protection_pickup_info_1 = UROV_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_UROV_PICKUP_0_MEASURES;
      Protection_Pickup_m = UROV_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_UROV_DELAY_0_TITLE;
      Protection_Delay_t = UROV_Delay_t;
      Protection_Delay_title = UROV_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_UROV_DELAY_VALUE_0;
      Protection_Delay_v = UROV_Delay_v;
      Protection_delay_info_1 = UROV_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_UROV_DELAY_0_MEASURES;
      Protection_Delay_m = UROV_Delay_m;

      id_text_protection_state_0 = ID_TEXT_UROV_STATE_0;
      Protection_State_t = UROV_State_t;
      Protection_State_title = UROV_State_title;
      id_dd_protection_state_0 = ID_DD_UROV_STATE_0;
      Protection_State_v = UROV_State_v;
      Protection_control_info = UROV_control_info;
      
      width_x_t = 84;
      width_x_v = 52;
      
      break;
    }
  case ID_CB_PG:
    {
      id_protection_framewin = ID_CB_FRAMEWIN;
      Protection_panel_title = &CB_panel_title;
      Protection_FrameWin = &CB_FrameWin;
      
      id_protection_multipage_groups = ID_CB_MULTIPAGE_GROUPS;
      Protection_MultiPage_groups = &CB_MultiPage_groups;
      
      id_protection_groups = ID_CB_GROUPS;
      Protection_Window_group = &CB_Window_group;
      
      id_protection_multipage_type_info = ID_CB_MULTIPAGE_TYPE_INFO;
      Protection_MultiPage_type_info = &CB_MultiPage_type_info;

      id_protection_pickups = ID_CB_PICKUPS;
      Protection_Pages = CB_Pages;
      
      ScrollBar_Protection_Pages = ScrollBar_CB_Pages;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_CB;
      max_number_delay_protection = MAX_NUMBER_DELAY_CB;
      max_number_ctrl_protection = MAX_NUMBER_CTRL_CB;

      max_kilkist_stupeniv_protection = 1;
      nalashtuvannja_protection = nalashtuvannja_CB;
      
      id_text_protection_pickup_0_title = ID_TEXT_CB_PICKUP_0_TITLE;
      Protection_Pickup_t = CB_Pickup_t;
      Protection_Pickup_title = CB_Pickup_title;
      id_ed_protection_pickup_value_0 = ID_ED_CB_PICKUP_VALUE_0;
      Protection_Pickup_v = CB_Pickup_v;
      Protection_pickup_info_1 = CB_pickup_info_1;
      id_text_protection_pickup_0_measures = ID_TEXT_CB_PICKUP_0_MEASURES;
      Protection_Pickup_m = CB_Pickup_m;
      
      id_text_protection_delay_0_title = ID_TEXT_CB_DELAY_0_TITLE;
      Protection_Delay_t = CB_Delay_t;
      Protection_Delay_title = CB_Delay_title;
      id_ed_protection_delay_value_0 = ID_ED_CB_DELAY_VALUE_0;
      Protection_Delay_v = CB_Delay_v;
      Protection_delay_info_1 = CB_delay_info_1;
      id_text_protection_delay_0_measures = ID_TEXT_CB_DELAY_0_MEASURES;
      Protection_Delay_m = CB_Delay_m;

      id_text_protection_state_0 = ID_TEXT_CB_STATE_0;
      Protection_State_t = CB_State_t;
      Protection_State_title = CB_State_title;
      id_dd_protection_state_0 = ID_DD_CB_STATE_0;
      Protection_State_v = CB_State_v;
      Protection_control_info = CB_control_info;
      
      width_x_t = 84;
      width_x_v = 52;
      
      groups = 1;
      
      break;
    }
  default:
    {
      //Сюди програма ніколи б не мала зайти
      while(1);
    }
  }
  
  if (*Protection_FrameWin == WM_UNATTACHED)
  {
    
    //Створюємо FrameWin для уставок-витримок-налаштування МСЗ
    *Protection_FrameWin = FRAMEWIN_CreateEx(X0, Y0, X_SIZE, Y_SIZE, 0, WM_CF_HIDE, 0, id_protection_framewin, Protection_panel_title->ptitle[eeprom_bs_settings_tbl.chLngGUIText], _cbEmpty);
    FRAMEWIN_SetFont(*Protection_FrameWin, &GUI_FontArialBold14_8_Unicode);
    FRAMEWIN_SetTextAlign(*Protection_FrameWin, GUI_TA_HCENTER);
    FRAMEWIN_SetBarColor(*Protection_FrameWin, 1, GUI_GREEN);
    FRAMEWIN_SetBarColor(*Protection_FrameWin, 0, GUI_LIGHTGRAY);
    FRAMEWIN_SetTextColor(*Protection_FrameWin, GUI_BLUE);
 
    WM_HWIN parent_window = *Protection_FrameWin;
    int x_wight_parent_window = X_SIZE;
    if (groups > 1)
    {
      //Створюємо вкладки для вибору груп уставок
      *Protection_MultiPage_groups = MULTIPAGE_CreateEx(0, 0, x_wight_parent_window, Y_SIZE, WM_GetClientWindow(parent_window), WM_CF_SHOW, 0, id_protection_multipage_groups); 
//      WIDGET_OrState(*Protection_MultiPage_groups, WIDGET_STATE_FOCUSSABLE);
      MULTIPAGE_SetFont(*Protection_MultiPage_groups, &GUI_FontArialBold14_8_Unicode);
      MULTIPAGE_SetBkColor(*Protection_MultiPage_groups, GUI_BLACK, MULTIPAGE_CI_ENABLED);
      MULTIPAGE_SetTextColor(*Protection_MultiPage_groups, GUI_BLACK, MULTIPAGE_CI_DISABLED);
      MULTIPAGE_SetTextColor(*Protection_MultiPage_groups, GUI_YELLOW, MULTIPAGE_CI_ENABLED);
      MULTIPAGE_SetRotation(*Protection_MultiPage_groups, MULTIPAGE_CF_ROTATE_CW);
  
      *Protection_Window_group = WINDOW_CreateEx(0, 0, X_SIZE, Y_SIZE, WM_UNATTACHED,  WM_CF_SHOW, 0, id_protection_groups, _cbEmpty);
      for (unsigned int i = 0; i < (groups + 1); i++)
      {
        MULTIPAGE_AddPage(*Protection_MultiPage_groups, *Protection_Window_group, _MultiPage_groups_Items[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
        MULTIPAGE_DisablePage(*Protection_MultiPage_groups, i);
      }
      MULTIPAGE_EnablePage(*Protection_MultiPage_groups, 0);
      MULTIPAGE_SelectPage(*Protection_MultiPage_groups, 0);
      
      parent_window = *Protection_Window_group;
      x_wight_parent_window -= 20;
    }
    
    //Створюємо вкладки для уставок-витримок-налаштувань
    *Protection_MultiPage_type_info = MULTIPAGE_CreateEx(0, 0, x_wight_parent_window, (Y_SIZE - 20), WM_GetClientWindow(parent_window), WM_CF_SHOW, 0, id_protection_multipage_type_info);
    WIDGET_OrState(*Protection_MultiPage_type_info, WIDGET_STATE_FOCUSSABLE);
    MULTIPAGE_SetBkColor(*Protection_MultiPage_type_info, GUI_BLACK, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetTextColor(*Protection_MultiPage_type_info, GUI_BLACK, MULTIPAGE_CI_DISABLED);
    MULTIPAGE_SetTextColor(*Protection_MultiPage_type_info, GUI_YELLOW, MULTIPAGE_CI_ENABLED);
    MULTIPAGE_SetFont(*Protection_MultiPage_type_info, &GUI_FontArialBold14_8_Unicode);
    MULTIPAGE_SetAlign(*Protection_MultiPage_type_info, /*(MULTIPAGE_ALIGN_TOP | MULTIPAGE_ALIGN_LEFT)*/(MULTIPAGE_ALIGN_BOTTOM | MULTIPAGE_ALIGN_RIGHT));
  
#define ROW_1_Y         10
#define HIGHT_Y         20
#define SHIFT_Y         (ROW_1_Y + HIGHT_Y)
  
    for (unsigned int i = 0; i < MAX_PAGES_PROTECTION_SDC; i++)
    {
      WM_CALLBACK *cb, *subcb;
      if (i == 0 ) cb = _cbPickups_Protection;
      else if (i == 1) 
      {
        if (id_protection != ID_DZ_PG)
          cb = _cbDelays_Protection;
        else
        {
          cb = _cbEmpty;
          subcb = _cbDelays_Protection;
        }
      }
      else cb = _cbControl_Protection;
    
      int num_row = 0, num_row_g = 0;
      if (i == 0)
      {
        num_row = max_number_pickup_protection;
      }
      else if (i == 1)
      {
        num_row = max_number_delay_protection;

        if (id_protection == ID_DZ_PG)
          num_row_g = MAX_NUMBER_DELAY_DZ_G;
      }
      else if (i == 2)
      {
        unsigned int max_number_ctrl_protection_tmp = max_number_ctrl_protection;
        for (unsigned int stupin = 0; stupin < max_kilkist_stupeniv_protection; stupin++)
        {
          if (((*(nalashtuvannja_protection + stupin)) & 0x1) != 0 ) max_number_ctrl_protection_tmp++;
        }
        num_row = (max_number_ctrl_protection_tmp >> 1) + (max_number_ctrl_protection_tmp & 0x1);
      }

      *(Protection_Pages + i) = WINDOW_CreateEx(0, 0, (x_wight_parent_window - 6)/*X_SIZE - 26*/, 5*SHIFT_Y + 6,  WM_UNATTACHED,  WM_CF_SHOW, 0, id_protection_pickups + i, cb);
      if ((id_protection == ID_DZ_PG) && (i == 1))
      {
        DZ_SubPages_delay[0] = WINDOW_CreateEx(0, 0, (x_wight_parent_window - 6)/*X_SIZE - 26*/, 5*SHIFT_Y + 6,  WM_GetClientWindow(*(Protection_Pages + 1)),  WM_CF_SHOW, 0, ID_DZ_SUBDELAYS_0, subcb);
        DZ_SubPages_delay[1] = WINDOW_CreateEx(0, 0, (x_wight_parent_window - 6)/*X_SIZE - 26*/, 5*SHIFT_Y + 6,  WM_GetClientWindow(*(Protection_Pages + 1)),  WM_CF_HIDE, 0, ID_DZ_SUBDELAYS_1, subcb);
      }

      MULTIPAGE_AddPage(*Protection_MultiPage_type_info, *(Protection_Pages + i), _MultiPage_type_info_Items[i].pText[eeprom_bs_settings_tbl.chLngGUIText]);
      MULTIPAGE_DisablePage(*Protection_MultiPage_type_info, i);
    
      if ((id_protection == ID_DZ_PG) && (i == 1))
      {
        *(ScrollBar_Protection_Pages + i) = 0;
      
        ScrollBar_DZ_SubPages_delay[0] = SCROLLBAR_CreateAttached(WM_GetClientWindow(DZ_SubPages_delay[0]), SCROLLBAR_CF_VERTICAL);
        SCROLLBAR_SetNumItems(ScrollBar_DZ_SubPages_delay[0], num_row*SHIFT_Y);
        SCROLLBAR_SetPageSize(ScrollBar_DZ_SubPages_delay[0], 5*SHIFT_Y);

        ScrollBar_DZ_SubPages_delay[1] = SCROLLBAR_CreateAttached(WM_GetClientWindow(DZ_SubPages_delay[1]), SCROLLBAR_CF_VERTICAL);
        SCROLLBAR_SetNumItems(ScrollBar_DZ_SubPages_delay[1], num_row_g*SHIFT_Y);
        SCROLLBAR_SetPageSize(ScrollBar_DZ_SubPages_delay[1], 5*SHIFT_Y);
      }
      else
      {
        *(ScrollBar_Protection_Pages + i) = SCROLLBAR_CreateAttached(WM_GetClientWindow(*(Protection_Pages + i)), SCROLLBAR_CF_VERTICAL);
        SCROLLBAR_SetNumItems(*(ScrollBar_Protection_Pages + i), num_row*SHIFT_Y);
        SCROLLBAR_SetPageSize(*(ScrollBar_Protection_Pages + i), 5*SHIFT_Y);
      }
    }
    MULTIPAGE_EnablePage(*Protection_MultiPage_type_info, 0);
    MULTIPAGE_SelectPage(*Protection_MultiPage_type_info, 0);

#define COL_1_X         5

#define WIDTH_X_T       165
#define WIDTH_X_V       60

#define SHIFT_X1        (WIDTH_X_T + 10)
#define SHIFT_X2        (SHIFT_X1 + WIDTH_X_V + 10)
    
    for (unsigned int i = 0; i < max_number_pickup_protection; i++)
    {
      int y0 =  ROW_1_Y + i*SHIFT_Y;

      *(Protection_Pickup_t + i) = TEXT_CreateEx(COL_1_X, y0, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(*(Protection_Pages + 0)), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_pickup_0_title + i,  (Protection_Pickup_title + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetFont(*(Protection_Pickup_t + i), &GUI_FontArialStandard14_8_Unicode);

    
      *(Protection_Pickup_v + i) = EDIT_CreateUser(COL_1_X + SHIFT_X1, y0, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(*(Protection_Pages + 0)), WM_CF_SHOW, 0, id_ed_protection_pickup_value_0 + i, 10, sizeof(__info_data));
      EDIT_SetFont(*(Protection_Pickup_v + i), &GUI_FontArialStandard14_8_Unicode);

      const char *p_title;
      int min, max;
      int shift;
      unsigned int extra_param;

      p_title = (*Protection_pickup_info_1)(i, &min, &max, &shift, &extra_param);
    
      float _shift = 0.0f;
      for (int rozrjad = 0; rozrjad < shift; rozrjad++) 
      {
        _shift /= 10.0f;
        _shift += 0.9f;
      }

      int max_tmp = max;
      float _max = 10;
      while ( abs(max_tmp /= 10) >= 1) _max *= 10.0f;
      if (max > 0)
      {
        _max = _max - 1 + _shift;
      }
      else if (max < 0)
      {
        _max = -(_max / 10);
      }
      else _max = 0;
    
      int min_tmp = min;
      float _min = 10;
      while ( abs(min_tmp /= 10) >= 1) _min *= 10.0f;
      if (min > 0)
      {
        _min = (_min / 10);
      }
      else if (min < 0)
      {
        _min = -(_min - 1 + _shift);
      }
      else _min = 0;
      
      __info_data info_data = { _min, _max, shift, extra_param};
      

      EDIT_SetUserData(*(Protection_Pickup_v + i), &info_data, sizeof(__info_data));
      EDIT_SetFloatMode(*(Protection_Pickup_v + i), 0, _min, _max, shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
      
      *(Protection_Pickup_m + i) = TEXT_CreateEx(COL_1_X + SHIFT_X2 , y0, 40, HIGHT_Y, WM_GetClientWindow(*(Protection_Pages + 0)), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_pickup_0_measures + i,  p_title);
      TEXT_SetFont(*(Protection_Pickup_m + i), &GUI_FontArialStandard14_8_Unicode);
    }
  
#undef WIDTH_X_T
#undef WIDTH_X_V

#define WIDTH_X_T       185
#define WIDTH_X_V       40

    WM_HWIN Parent_Window;
    if (id_protection != ID_DZ_PG)
      Parent_Window = *(Protection_Pages + 1);
    else
      Parent_Window = DZ_SubPages_delay[0];
  
    for (unsigned int i = 0; i < max_number_delay_protection; i++)
    {
      int y0 =  ROW_1_Y + i*SHIFT_Y;

      *(Protection_Delay_t + i) = TEXT_CreateEx(COL_1_X, y0, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Parent_Window), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_delay_0_title + i,  (Protection_Delay_title + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetFont(*(Protection_Delay_t + i), &GUI_FontArialStandard14_8_Unicode);
    
      *(Protection_Delay_v + i) = EDIT_CreateUser(COL_1_X + SHIFT_X1, y0, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Parent_Window), WM_CF_SHOW, 0, id_ed_protection_delay_value_0 + i, 10, sizeof(__info_data));
      EDIT_SetFont(*(Protection_Delay_v + i), &GUI_FontArialStandard14_8_Unicode);

      const char *p_title;
      int min, max;
      int shift;

      p_title = (*Protection_delay_info_1)(i, &min, &max, &shift);

      float _max = 10;
      while ( (max /= 10) >= 1) _max *= 10.0f;
      _max -= 1;
    
      float _shift = 0.0f;
      for (int rozrjad = 0; rozrjad < shift; rozrjad++) 
      {
        _shift /= 10.0f;
        _shift += 0.9f;
      }
      
      __info_data info_data = { min, (_max + _shift), shift, 0};
      
      EDIT_SetUserData(*(Protection_Delay_v + i), &info_data, sizeof(__info_data));
      EDIT_SetFloatMode(*(Protection_Delay_v + i), 0, min, (_max + _shift), shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
      
      *(Protection_Delay_m + i) = TEXT_CreateEx(COL_1_X + SHIFT_X2 , y0, 40, HIGHT_Y, WM_GetClientWindow(Parent_Window), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_delay_0_measures + i,  p_title);
      TEXT_SetFont(*(Protection_Delay_m + i), &GUI_FontArialStandard14_8_Unicode);
    }
    if(id_protection == ID_DZ_PG)
    {
      Parent_Window = DZ_SubPages_delay[1];
      for (unsigned int i = MAX_NUMBER_DELAY_DZ; i < (MAX_NUMBER_DELAY_DZ + MAX_NUMBER_DELAY_DZ_G); i++)
      {
        int y0 =  ROW_1_Y + (i - MAX_NUMBER_DELAY_DZ)*SHIFT_Y;

        *(Protection_Delay_t + i) = TEXT_CreateEx(COL_1_X, y0, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(Parent_Window), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_delay_0_title + i,  (Protection_Delay_title + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
        TEXT_SetFont(*(Protection_Delay_t + i), &GUI_FontArialStandard14_8_Unicode);
    
        *(Protection_Delay_v + i) = EDIT_CreateUser(COL_1_X + SHIFT_X1, y0, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(Parent_Window), WM_CF_SHOW, 0, id_ed_protection_delay_value_0 + i, 10, sizeof(__info_data));
        EDIT_SetFont(*(Protection_Delay_v + i), &GUI_FontArialStandard14_8_Unicode);

        const char *p_title;
        int min, max;
        int shift;

        p_title = (*Protection_delay_info_1)(i, &min, &max, &shift);

        float _max = 10;
        while ( (max /= 10) >= 1) _max *= 10.0f;
        _max -= 1;
    
        float _shift = 0.0f;
        for (int rozrjad = 0; rozrjad < shift; rozrjad++) 
        {
          _shift /= 10.0f;
          _shift += 0.9f;
        }
        
        __info_data info_data = { min, (_max + _shift), shift, 0};
        
        EDIT_SetUserData(*(Protection_Delay_v + i), &info_data, sizeof(__info_data));
        EDIT_SetFloatMode(*(Protection_Delay_v + i), 0, min, (_max + _shift), shift, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
      
        *(Protection_Delay_m + i) = TEXT_CreateEx(COL_1_X + SHIFT_X2 , y0, 40, HIGHT_Y, WM_GetClientWindow(Parent_Window), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_delay_0_measures + i,  p_title);
        TEXT_SetFont(*(Protection_Delay_m + i), &GUI_FontArialStandard14_8_Unicode);
      }
  }
#undef COL_1_X

#undef WIDTH_X_T
#undef WIDTH_X_V

#undef SHIFT_X1
#undef SHIFT_X2

#define COL_1_X         2

#define WIDTH_X_T       width_x_t
#define WIDTH_X_V       width_x_v

#define SHIFT_X1        (WIDTH_X_T + 2)
#define SHIFT_X2        (SHIFT_X1 + WIDTH_X_V + 2)
    for (unsigned int i = 0; i < max_number_ctrl_protection; i++)
    {
      int x0, y0;
      int i_tmp = i;

      unsigned int porikh_kilkosti = 0;
      for (unsigned int stupin = 1; ((stupin < max_kilkist_stupeniv_protection) && (i >= porikh_kilkosti)) ; stupin++)
      {
        porikh_kilkosti += *(nalashtuvannja_protection + stupin - 1); //сума налашутвань для ступенів захисту по номеру нижчих ніж який позначає stupin
        if (
            (i >= porikh_kilkosti) &&
            (((*(nalashtuvannja_protection + stupin - 1)) & 0x1) != 0)
           )
          i_tmp++;
      }
   
      y0 = ROW_1_Y + (i_tmp >> 1)*SHIFT_Y;
      if ((i_tmp & 0x1) == 0)
      {
        //Парні індекси
        x0 = COL_1_X;
      }
      else
      {
        //Непарні індекси
        x0 = COL_1_X + SHIFT_X2;
      }
    
      *(Protection_State_t + i) = TEXT_CreateEx(x0, y0, WIDTH_X_T, HIGHT_Y, WM_GetClientWindow(*(Protection_Pages + 2)), WM_CF_SHOW, TEXT_CF_LEFT | TEXT_CF_VCENTER, id_text_protection_state_0 + i, (Protection_State_title + i)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      TEXT_SetFont(*(Protection_State_t + i), &GUI_FontArialStandard14_8_Unicode);

      *(Protection_State_v + i) = DROPDOWN_CreateEx(x0 + SHIFT_X1, y0, WIDTH_X_V, HIGHT_Y, WM_GetClientWindow(*(Protection_Pages + 2)), WM_CF_SHOW, DROPDOWN_CF_AUTOSCROLLBAR, id_dd_protection_state_0 + i);
      DROPDOWN_SetFont(*(Protection_State_v + i), &GUI_FontArialStandard14_8_Unicode);
      DROPDOWN_SetBkColor(*(Protection_State_v + i),DROPDOWN_CI_UNSEL, GUI_GRAY);
      DROPDOWN_SetBkColor(*(Protection_State_v + i),DROPDOWN_CI_SEL,  GUI_GRAY);
      DROPDOWN_SetBkColor(*(Protection_State_v + i),DROPDOWN_CI_SELFOCUS, GUI_BLUE);

      int j_max;
      const TITLE *p_control_list_name;
        
      p_control_list_name = Protection_control_info(i, &j_max);
      DROPDOWN_AddString(*(Protection_State_v + i), "");
      for (int j = 0; j < j_max; j++)
      {
        DROPDOWN_AddString(*(Protection_State_v + i), (p_control_list_name + j)->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      }
    
    }
#undef COL_1_X

#undef WIDTH_X_T
#undef WIDTH_X_V

#undef SHIFT_X1
#undef SHIFT_X2

#undef ROW_1_Y
#undef HIGHT_Y
#undef SHIFT_Y
  
  }
  
  WM_BringToTop(*Protection_FrameWin);
  WM_ShowWindow(*Protection_FrameWin);
}
/*****************************/

/*****************************
Обновлення інформації на панелі вибраного захисту
*****************************/
void redraw_panel_protection(__index_level_menu id_protection)
{
  WM_HWIN *Protection_FrameWin, *Protection_MultiPage_groups, *Protection_MultiPage_type_info;
  WM_HWIN *Protection_Pickup_v, *Protection_Delay_v, *Protection_State_v; 
  WM_HWIN *Protection_Pages;

  const TITLE *Protection_panel_title;
  unsigned int max_number_pickup_protection, max_number_delay_protection, max_number_ctrl_protection;
  int *point_to_select_group;
  
  void (*protection_pickup_info)(unsigned int, CfgTblDsc*, int*, int*, float*, int*);
  void (*protection_delay_info)(unsigned int, CfgTblDsc*, unsigned int*, unsigned int*, float*, unsigned int*);
  unsigned char* (*Protection_pointer_to_state)(unsigned int, CfgTblDsc*);

  unsigned int groups = AMOUNT_SERIES_PPSPM_SETTINGS;
  
  EDIT_SetText(hEdit, _aBitmapItem_settings[SETTINGS_DZ_ID + (int)(id_protection - ID_DZ_PG)].pExplanation[eeprom_bs_settings_tbl.chLngGUIText]);
  switch (id_protection)
  {
  case ID_DZ_PG:
    {
      point_to_select_group = &DZ_select_group;
      
      Protection_FrameWin = &DZ_FrameWin; 
      Protection_Pages = DZ_Pages;
      Protection_panel_title = &DZ_panel_title;
      
      Protection_MultiPage_groups = &DZ_MultiPage_groups;
      
      Protection_MultiPage_type_info = &DZ_MultiPage_type_info;

      max_number_pickup_protection = MAX_NUMBER_PICKUP_DZ;
      protection_pickup_info = DZ_pickup_info;
      Protection_Pickup_v = DZ_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_DZ;
      protection_delay_info = DZ_delay_info;
      Protection_Delay_v = DZ_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_DZ;
      Protection_State_v = DZ_State_v;
      Protection_pointer_to_state = DZ_pointer_to_state;

      break;
    }
  case ID_MTZ_PG:
    {
      point_to_select_group = &MTZ_select_group;
      
      Protection_FrameWin = &MTZ_FrameWin; 
      Protection_Pages = MTZ_Pages;
      Protection_panel_title = &MTZ_panel_title;
      
      Protection_MultiPage_groups = &MTZ_MultiPage_groups;
      
      Protection_MultiPage_type_info = &MTZ_MultiPage_type_info;

      max_number_pickup_protection = MAX_NUMBER_PICKUP_MTZ;
      protection_pickup_info = MTZ_pickup_info;
      Protection_Pickup_v = MTZ_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_MTZ;
      protection_delay_info = MTZ_delay_info;
      Protection_Delay_v = MTZ_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_MTZ;
      Protection_State_v = MTZ_State_v;
      Protection_pointer_to_state = MTZ_pointer_to_state;

      break;
    }
  case ID_UMIN_PG:
    {
      point_to_select_group = &Umin_select_group;

      Protection_FrameWin = &Umin_FrameWin; 
      Protection_Pages = Umin_Pages;
      Protection_panel_title = &Umin_panel_title;
      
      Protection_MultiPage_groups = &Umin_MultiPage_groups;
      
      Protection_MultiPage_type_info = &Umin_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_UMIN;
      protection_pickup_info = Umin_pickup_info;
      Protection_Pickup_v = Umin_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_UMIN;
      protection_delay_info = Umin_delay_info;
      Protection_Delay_v = Umin_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_UMIN;
      Protection_State_v = Umin_State_v;
      Protection_pointer_to_state = Umin_pointer_to_state;

      break;
    }
  case ID_UMAX_PG:
    {
      point_to_select_group = &Umax_select_group;

      Protection_FrameWin = &Umax_FrameWin; 
      Protection_Pages = Umax_Pages;
      Protection_panel_title = &Umax_panel_title;
      
      Protection_MultiPage_groups = &Umax_MultiPage_groups;
      
      Protection_MultiPage_type_info = &Umax_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_UMAX;
      protection_pickup_info = Umax_pickup_info;
      Protection_Pickup_v = Umax_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_UMAX;
      protection_delay_info = Umax_delay_info;
      Protection_Delay_v = Umax_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_UMAX;
      Protection_State_v = Umax_State_v;
      Protection_pointer_to_state = Umax_pointer_to_state;

      break;
    }
  case ID_TZNP_PG:
    {
      point_to_select_group = &TZNP_select_group;

      Protection_FrameWin = &TZNP_FrameWin; 
      Protection_Pages = TZNP_Pages;
      Protection_panel_title = &TZNP_panel_title;
      
      Protection_MultiPage_groups = &TZNP_MultiPage_groups;
      
      Protection_MultiPage_type_info = &TZNP_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_TZNP;
      protection_pickup_info = TZNP_pickup_info;
      Protection_Pickup_v = TZNP_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_TZNP;
      protection_delay_info = TZNP_delay_info;
      Protection_Delay_v = TZNP_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_TZNP;
      Protection_State_v = TZNP_State_v;
      Protection_pointer_to_state = TZNP_pointer_to_state;

      break;
    }
  case ID_ZOP_PG:
    {
      point_to_select_group = &ZOP_select_group;

      Protection_FrameWin = &ZOP_FrameWin; 
      Protection_Pages = ZOP_Pages;
      Protection_panel_title = &ZOP_panel_title;
      
      Protection_MultiPage_groups = &ZOP_MultiPage_groups;
      
      Protection_MultiPage_type_info = &ZOP_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_ZOP;
      protection_pickup_info = ZOP_pickup_info;
      Protection_Pickup_v = ZOP_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_ZOP;
      protection_delay_info = ZOP_delay_info;
      Protection_Delay_v = ZOP_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_ZOP;
      Protection_State_v = ZOP_State_v;
      Protection_pointer_to_state = ZOP_pointer_to_state;

      break;
    }
  case ID_APV_PG:
    {
      point_to_select_group = &APV_select_group;

      Protection_FrameWin = &APV_FrameWin; 
      Protection_Pages = APV_Pages;
      Protection_panel_title = &APV_panel_title;
      
      Protection_MultiPage_groups = &APV_MultiPage_groups;
      
      Protection_MultiPage_type_info = &APV_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_APV;
      protection_pickup_info = APV_pickup_info;
      Protection_Pickup_v = APV_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_APV;
      protection_delay_info = APV_delay_info;
      Protection_Delay_v = APV_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_APV;
      Protection_State_v = APV_State_v;
      Protection_pointer_to_state = APV_pointer_to_state;

      break;
    }
  case ID_UROV_PG:
    {
      point_to_select_group = &UROV_select_group;

      Protection_FrameWin = &UROV_FrameWin; 
      Protection_Pages = UROV_Pages;
      Protection_panel_title = &UROV_panel_title;
      
      Protection_MultiPage_groups = &UROV_MultiPage_groups;
      
      Protection_MultiPage_type_info = &UROV_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_UROV;
      protection_pickup_info = UROV_pickup_info;
      Protection_Pickup_v = UROV_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_UROV;
      protection_delay_info = UROV_delay_info;
      Protection_Delay_v = UROV_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_UROV;
      Protection_State_v = UROV_State_v;
      Protection_pointer_to_state = UROV_pointer_to_state;

      break;
    }
  case ID_CB_PG:
    {
      point_to_select_group = &one_group;

      Protection_FrameWin = &CB_FrameWin; 
      Protection_Pages = CB_Pages;
      Protection_panel_title = &CB_panel_title;
      
      Protection_MultiPage_groups = &CB_MultiPage_groups;
      
      Protection_MultiPage_type_info = &CB_MultiPage_type_info;
      
      max_number_pickup_protection = MAX_NUMBER_PICKUP_CB;
      protection_pickup_info = CB_pickup_info;
      Protection_Pickup_v = CB_Pickup_v;

      max_number_delay_protection = MAX_NUMBER_DELAY_CB;
      protection_delay_info = CB_delay_info;
      Protection_Delay_v = CB_Delay_v;

      max_number_ctrl_protection = MAX_NUMBER_CTRL_CB;
      Protection_State_v = CB_State_v;
      Protection_pointer_to_state = CB_pointer_to_state;
      
      groups = 1;

      break;
    }
  default:
    {
      //Сюди програма ніколи б не мала зайти
      while(1);
    }
  }

  char title[256];
  title[0] = '\0';
  strcat_mal(title, (char *)Protection_panel_title->ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
  
  unsigned int error_data = _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT) | _CHECK_SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
  if (error_data)
  {
    //Nalashtuvannja nemaje u tablyci nalashtuvan
    strcat_mal(title, (char *)ERROR_MES.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
    FRAMEWIN_SetText(*Protection_FrameWin, title);

    FRAMEWIN_SetBarColor(*Protection_FrameWin, 1, GUI_RED);
    FRAMEWIN_SetTextColor(*Protection_FrameWin, GUI_YELLOW);
  }
  else
  {
    //Nalashtuvannja realno je u tablyci nalashtuvan
    if (current_ekran.edition != 0)
    {
      strcat_mal(title, (char *)MODE.ptitle[eeprom_bs_settings_tbl.chLngGUIText]);
      if (current_ekran.edition != 1)
      {
        //Помічаємо, що дані змінені
        strcat_mal(title, "*");
      }
    }
    FRAMEWIN_SetText(*Protection_FrameWin, title);

    if (current_ekran.edition == 0)
    {
      FRAMEWIN_SetBarColor(*Protection_FrameWin, 1, GUI_GREEN);
      FRAMEWIN_SetTextColor(*Protection_FrameWin, GUI_BLUE);
    }
    else
    {
      FRAMEWIN_SetBarColor(*Protection_FrameWin, 1, GUI_YELLOW);
      FRAMEWIN_SetTextColor(*Protection_FrameWin, GUI_RED);
    }
  }

  if (groups > 1) select_multipage_groups(*Protection_MultiPage_groups, Protection_Pages, *point_to_select_group, current_ekran.index_position, MAX_PAGES_PROTECTION_SDC); 
  select_multipage_general(*Protection_MultiPage_type_info, current_ekran.index_position);
  
  CfgTblDsc *point;
  if (current_ekran.edition == 0) point = &eeprom_prt_tbl;
  else  point = &edit_settings;
  
//  WM_HWIN FocussedWindow = 0;
  static WM_HWIN FocussedWindow;
  switch (current_ekran.index_position)
  {
  case 0:
    {
      __info_data info_data;
      for (unsigned int i = 0; i < max_number_pickup_protection; i++)
      {
        if (error_data)
        {
          EDIT_SetText(*(Protection_Pickup_v + i), "");
        }
        else
        {
          float value = 0;
          int value_int, min, max;
        
          (*protection_pickup_info)(i, point, &min, &max, &value, &value_int);
          EDIT_GetUserData(*(Protection_Pickup_v + i), &info_data, sizeof(__info_data));

          U8 Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
          if (current_ekran.edition != 0) 
          {
            if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) Flags = GUI_EDIT_SIGNED;
            else Flags = 0;
          }
          EDIT_SetFloatMode(*(Protection_Pickup_v + i), value, info_data.min, info_data.max, info_data.shift, Flags);
        
          if ((info_data.extra_param & FLAG_SIGNED_FATA) != 0) value_int = abs(value_int);
          if ((value_int >= min) && (value_int <= max))
          {
            EDIT_SetTextColor(*(Protection_Pickup_v + i), EDIT_CI_DISABLED, GUI_BLACK);
            EDIT_SetTextColor(*(Protection_Pickup_v + i), EDIT_CI_ENABLED, GUI_BLACK);
          }
          else
          {
            EDIT_SetTextColor(*(Protection_Pickup_v + i), EDIT_CI_DISABLED, GUI_RED);
            EDIT_SetTextColor(*(Protection_Pickup_v + i), EDIT_CI_ENABLED, GUI_RED);
          }
        }
      }
      
      FocussedWindow = *(Protection_Pickup_v + current_ekran.index_position_1);
      EDIT_SetCursorAtChar(FocussedWindow, 0);
      break;
    }
  case 1:
    {
      unsigned int index_min = 0;
      if (id_protection == ID_DZ_PG)
      { 
        if (WM_IsVisible(DZ_SubPages_delay[1]))
        {
          index_min = max_number_delay_protection;
          max_number_delay_protection = MAX_NUMBER_DELAY_DZ_G;
        }
      }
      unsigned int index_max = index_min + max_number_delay_protection;
      
      __info_data info_data;
      for (unsigned int i = index_min; i < index_max; i++)
      {
        if (error_data)
        {
          EDIT_SetText(*(Protection_Delay_v + i), "");
        }
        else
        {
          float value = 0;
          unsigned int value_int, min, max;
        
          (*protection_delay_info)(i, point, &min, &max, &value, &value_int);
          EDIT_GetUserData(*(Protection_Delay_v + i), &info_data, sizeof(__info_data));

          U8 Flags = GUI_EDIT_SUPPRESS_LEADING_ZEROES;
          if (current_ekran.edition != 0) 
          {
            Flags = 0;
          }
          EDIT_SetFloatMode(*(Protection_Delay_v + i), value, info_data.min, info_data.max, info_data.shift, Flags);
        
          if ((value_int >= min) && (value_int <= max))
          {
            EDIT_SetTextColor(*(Protection_Delay_v + i), EDIT_CI_DISABLED, GUI_BLACK);
            EDIT_SetTextColor(*(Protection_Delay_v + i), EDIT_CI_ENABLED, GUI_BLACK);
          }
          else
          {
            EDIT_SetTextColor(*(Protection_Delay_v + i), EDIT_CI_DISABLED, GUI_RED);
            EDIT_SetTextColor(*(Protection_Delay_v + i), EDIT_CI_ENABLED, GUI_RED);
          }
        }
      }
      
      FocussedWindow = *(Protection_Delay_v + index_min + current_ekran.index_position_1);
      EDIT_SetCursorAtChar(FocussedWindow, 0);
      break;
    }
  case 2:
    {
      for (unsigned int i = 0; i < max_number_ctrl_protection; i++)
      {
        if (error_data)
        {
          DROPDOWN_SetSel(*(Protection_State_v + i), 0);
        }
        else
        {
          int Sel = 0;
          unsigned char *p_to_state = Protection_pointer_to_state(i, point);
          if (p_to_state != NULL) Sel = *p_to_state + 1;
          DROPDOWN_SetSel(*(Protection_State_v + i), Sel);
        }
      }
      
      FocussedWindow = *(Protection_State_v + current_ekran.index_position_1);
      break;
    }
  default: break;
  }

//  if (!WM_HasFocus(FocussedWindow))WM_SetFocus(FocussedWindow);
  WM_SetFocus(FocussedWindow);
}
/*****************************/

/*****************************
Підрахунок кількості пропусків у матриці налаштувань для МТЗ до вказаного індексу 
*****************************/
void calc_number_gaps_ctrl_protection(unsigned int *p_gaps, int *p_position, unsigned int stupin, const unsigned short int *nalashtuvannja_protection, unsigned int max_kilkist_stupeniv_protection)
{
  if (stupin == 0) *p_gaps = 0; //Вводимо стартове значення
  
  //Підраховуємо кількість налаштувань для ступенів вибраного захисту для яких номером менший-рівний числа яке міститься у stupin
  int max_number_ctrl = 0;
  unsigned int porig = stupin;
  if (stupin > max_kilkist_stupeniv_protection) porig = max_kilkist_stupeniv_protection;
  else  porig = stupin;
  for (unsigned int i = 0; (i <= porig); i++) max_number_ctrl += *(nalashtuvannja_protection + i);
  
  if (
      (*p_position >= max_number_ctrl) &&
      (stupin < max_kilkist_stupeniv_protection)  
     )   
  {
    if ((*(nalashtuvannja_protection + stupin)) & 0x1)
    {
      *p_gaps = *p_gaps + 1;
      
    }
    calc_number_gaps_ctrl_protection(p_gaps, p_position, (stupin + 1), nalashtuvannja_protection, max_kilkist_stupeniv_protection);
  }
}
/*****************************/


#undef X0
#undef Y0
#undef X_SIZE
#undef Y_SIZE
