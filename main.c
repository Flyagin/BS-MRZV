//#include "B16LDfl.c"
#include "memory_map_type_definition.h"
#include "libraries_mal.h"
#include "constants_mal.h"
#include "hv_df.h"
#include "type_definition_mal.h"
#include "variables_global_mal.h"
#include "gui_variables.h"
#include "functions_global_mal.h"
#include "gui_functions.h"
#include "macroses_mal.h"

void periodical_operations(void);
//long SendStngTbl(void);
void ActivateTransmittionStngOnBM(void);
long ReqGetSettingsBMExample(void) ;
extern char  ReqGetSettingsBM(long lActivation, void* pSettingsStateDsc);
extern char  ReqSendSettingsBM(long lActivation, void* pSettingsStateDsc);

#include <pio/pio.h>

#include <usart/usart.h>
#include "./Gui/KbdDrv.h"
#include "./ici_api.h"
#include "modbus_variables.h"
#include "modbus_functions.h"

//FOR DRIVER RS485
#include "LibRS485.h"
#include "constant.h"
#include "variables_global.h"
#include "driverRS485_global.h"

//twi
#include "header.h"

extern unsigned short const __checksum;
extern unsigned int __checksum_begin;
extern unsigned int __checksum_end;


long lDbgActivate = 0x200000;
extern KbdUNFldHolderDsc hldCurScanCode1,hldCurScanCode2;
extern void tmr_init(void);
extern void modbus_variables_init(void);
extern void usb_init(void);
extern void usb_routines(void);
extern void modbus_routines(void);
extern long SetUpArm926ej(void);
extern void u2_hdw_init(void);
extern void ON_BackLight(void );
extern void OFF_BackLight(void );
extern void CollectCfgTbls(void);
extern void RefreshCfgTables(void);
int main()  @ "Fast_function"
{
  AT91C_BASE_PIOD->PIO_PER  = 0xFFFF | (1 << 20) | (1 << 21) | (1 << 22)| (1<<23);
  AT91C_BASE_PIOD->PIO_OER  = 0xFFFF | (1 << 20) | (1 << 21) | (1 << 22)| (1<<23);
  AT91C_BASE_PIOD->PIO_CODR = 0xFFFF | (1 << 20) | (1 << 21) | (1 << 22);
  AT91C_BASE_PIOD->PIO_SODR = (1<<23);
  //AT91C_BASE_PIOD->PIO_SODR = (0xFF);
  AT91C_BASE_PIOD->PIO_CODR = (1<<23);
//  #ifdef  BS_G45_FL_RL
//  __asm volatile("BKPT 4");
//  #endif 
  SetUpArm926ej();
  u2_hdw_init();

  //Test_Loop();
  // tmr_init();
  modbus_variables_init();
//   usb_init();// в налаштуваннях компилятора понизили TRACE_LEVEL=0 був TRACE_LEVEL=4 <- printf не буде працювати

  //AT91C_BASE_PIOC->PIO_PDR  = 0xFFFF0000;
//  SPIOperationTable |= EEPROM_READ_SETTINGS;//EEPROM_WRITE_SETTINGS;
  
  StartUPInitKBD();
  StartUPInitLCD();
//  CollectCfgTbls();
  
  start_tasks_mal();
//  eeprom_bs_settings_tbl.chWinding = 1;
//  eeprom_bs_settings_tbl.chLngGUIText = 1;
//  change_language = 1;
//  _SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
  gui_init();
  
#ifdef  flash  
  while(1);
#endif    
  Setings_RS485(); 
  settings_for_ZigBee();

  while(1)
  {
    /************************************************************/
      //Перевірка контрольної суми програми
    /************************************************************/
      unsigned short sum = 0;
      unsigned char *point = ((unsigned char *)&__checksum_begin);
      //for (unsigned int i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0; i--)
      {
        sum += *point++;
        periodical_operations();
      }
      if (sum != (unsigned short)__checksum)
	  sum++;//while(1);//?????*/
	//  _SET_STATE(resurs_diagnostica, ERROR_EXTERNAL_FLASH_MEMORY_BIT);	  
    //  else
	//	_CLEAR_STATE(resurs_diagnostica, ERROR_EXTERNAL_FLASH_MEMORY_BIT);


  }
 //return 0;
}


void periodical_operations(void) @ "Fast_function"
{
	periodical_tasks_mal();
    gui_routines();
	if ((state_command_power_LCD & (1 << 1)) != 0)
    {
      //Vymykajemo LCD
      state_command_power_LCD &= (unsigned int)(~(1 << 31));//Stan vymkneno
      state_command_power_LCD &= (unsigned int)(~(1 <<  1));//Komandu znimajemo
      OFF_BackLight();
      
    }
	if ((state_command_power_LCD & (1 << 0)) != 0)
    {
      //Vmykajemo LCD
      state_command_power_LCD |= (unsigned int)( (1 << 31));//Stan vvimkneno
      state_command_power_LCD &= (unsigned int)(~(1 <<  0));//Komandu znimajemo
      ON_BackLight();
    }
	if (
        ((state_command_power_LCD & ((unsigned int)(1 << 31))) != 0) && start_gui_exec 
       )
    {
      GUI_MULTIBUF_Begin();
      start_gui_exec = 0;
      gui_update = 0;
      GUI_Exec();
      GUI_MULTIBUF_End();
    }
/////////////////////////////////////////////////////////////////////////////	
	if (lDbgActivate)
	lDbgActivate--;
else
{
  
  //ReqSendYustBMExample();
   if ( lDbgActivate==2)
  ActivateTransmittionStngOnBM();
  if ( lDbgActivate==1)
    ReqGetSettingsBMExample();
  if ( lDbgActivate==3)
    lDbgActivate = ReqGetSettingsBM(0,(void*)&hldCurScanCode2);
  //if ( lDbgActivate==4)
  //  ReqGetSettingsBM();
  
  lDbgActivate = 0x100000;
}
	
//////////////////////////////////////////////////////////////////////////////	
	RefreshCfgTables();
        ServiceLLDFlQuery();
	//
    
    driverRS485_main();
    
    //usb_routines();
    //сканування каналу зв'¤зку з модемом ZigBee
    
    ZigBee_scaner();
    
    modbus_routines();



}	















