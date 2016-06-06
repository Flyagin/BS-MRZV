#include "header_mal.h"

extern void Ici10msRing(void);
//extern void run_ReqTotMeasData(void);

/***********************************************************************************
Запуск таймеру PIT з періодом 10 мс
***********************************************************************************/
void ConfigurePIT(void)
{
  //Встановлюємо перод PIT = 10мс
  AT91C_BASE_PITC->PITC_PIMR = (PIT_PERIOD - 1) | AT91C_PITC_PITIEN;
  //Настроюємо переривання від PIT
  IRQ_ConfigureIT(AT91C_ID_SYS, 0, Sys_IrqHandler);
  AT91C_BASE_AIC->AIC_IECR = 1 << AT91C_ID_SYS;

  //Запускаємо таймер
  AT91C_BASE_PITC->PITC_PIMR |= AT91C_PITC_PITEN;

}
/***********************************************************************************/

/***********************************************************************************
Переривання від System peripherals
***********************************************************************************/
void Sys_IrqHandler(void)
{
  if (AT91C_BASE_PITC->PITC_PISR & AT91C_PITC_PITS)
  {
    AT91C_BASE_PITC->PITC_PIVR;
    
    //Робота з клавіатурою
    handle_kbd();
    unsigned int threshold_timeout_LCD = ((unsigned int)eeprom_bs_settings_tbl.chSleepTmVal)*60*100;
    
    if (hldScanCode.UNFKeyField.arUl[0] || hldScanCode.UNFKeyField.arUl[1])
    {
      timeout_LCD = 0;
    }
    else
    {
      if (timeout_LCD < threshold_timeout_LCD) timeout_LCD++;
    }
    if ((state_command_power_LCD & ((unsigned int)(1 << 31))) == 0)
    {
      //LCD vymknutyj
      if (timeout_LCD == 0) state_command_power_LCD |= (1 << 0); //Komanda na vvimknennja LCD
    }
    else
    {
      //LCD vimknutyj
      if (
          (timeout_LCD >= threshold_timeout_LCD) &&
          (timeout_LCD > 0)  
         )   
      {
        state_command_power_LCD |= (1 << 1); //Komanda na vymknennja LCD
      }
    }

    /***********************************************************/
    //Лічильник ресурсу + періодичні операції раз у секунду
    /***********************************************************/
    static unsigned int number_ticks_for_OF_bit_reset;

    if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_START_WAITING_5S)
    {
      etap_reset_of_bit = ETAP_CLEAR_OF_ST_WAITING_5S;
      number_ticks_for_OF_bit_reset = 0;
    }
    else if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_WAITING_5S)
    {
      number_ticks_for_OF_bit_reset++;
      if (number_ticks_for_OF_bit_reset > 500) etap_reset_of_bit = ETAP_CLEAR_OF_WRITE_OF_0;
    }
    
    if (++tick_for_1s >= 100)
    { 
      //Запусаємо раз у секунду самоконтроль важливих змінних
      periodical_tasks_TEST_SETTINGS_PRT                = 
      periodical_tasks_TEST_SETTINGS_BS                 = 
      periodical_tasks_TEST_USTUVANNJA                  = 
      periodical_tasks_TEST_TRG_FUNC                    = 
      periodical_tasks_TEST_INFO_REJESTRATOR_AR         = 
      periodical_tasks_TEST_INFO_REJESTRATOR_DR         = 
      periodical_tasks_TEST_INFO_REJESTRATOR_PR_ERR     = true;

      /*Зафікосваний період в 1(с) = 100 х 10(мс)*/
      tick_for_1s = 0;
      
      //Vystavljaemo praporec pro peremaljovuvannja paneli statusu
      redraw_status_bar = 1;

      //Komanda chytannja danykh z RTC
      _SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);

      //Ресурс
      resurs_global = resurs_temp;
      resurs_temp = 0;
      if (restart_resurs_count != 0)
      {
        restart_resurs_count = 0;
        
        resurs_global_min = 0xffffffff;
        resurs_global_max = 0;
      }
      if (resurs_global < resurs_global_min) resurs_global_min = resurs_global;
      if (resurs_global > resurs_global_max) resurs_global_max = resurs_global;

      if (
          ((Clock_FrameWin != WM_UNATTACHED) && (current_ekran.edition == 0)) ||
          (TM_FrameWin != WM_UNATTACHED) ||
          (Diagnostics_FrameWin != WM_UNATTACHED) ||
          (Resurs_FrameWin != WM_UNATTACHED)  
         )
      {
        command_menu |= (1 << REFRESH_ACTIVE_PANELS);
      }
      
      //Вызов ф-ции обновления значений на панэли измерений
      if (!gui_update && ((state_command_power_LCD & ( (unsigned int) ((1 << 31) | (1 << 1)) )) == (unsigned int) (1 << 31) ) ) {
        gui_tmr_routines();
      }
    }
    
    if (++tick_for_2s >= 200) {
      /*Зафікосваний період в 2(с) = 200 х 10(мс)*/
      tick_for_2s = 0;
      
    }
    
    if (++tick_for_3s >= 300) {
      /*Зафікосваний період в 3(с) = 300 х 10(мс)*/
      tick_for_3s = 0;
      
    }
    Ici10msRing();
    
    
    //Зафіксовано період в 10мс
    period_10ms = true;
  }
}
/***********************************************************************************/
