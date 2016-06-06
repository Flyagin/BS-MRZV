#ifndef __DIAGNOSTYKA_BS_H
#define __DIAGNOSTYKA_BS_H

#ifndef __CONST_DIAGNOSTYKA__
#include    "../mal/inc/diagnostyka_mal.h" //G:\HVP_pj\Hvps\hvps_D_28_09_15\HS1_0100_00_i720

#endif



enum _error_bs_id {
ERROR_BS_TEST1_BIT = 0,


};
enum BsFatalEror {

ERROR_BS_VREF_ADC1_TEST_BIT                      = ERROR_BS_TEST1_BIT,



ERROR_BS_SETTINGS_PRT_EEPROM_BIT              = ERROR_SETTINGS_PRT_EEPROM_BIT, 
ERROR_BS_SETTINGS_PRT_EEPROM_EMPTY_BIT        = ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT,
ERROR_BS_SETTINGS_PRT_EEPROM_COMPARISON_BIT   = ERROR_SETTINGS_PRT_EEPROM_COMPARISON_BIT,
ERROR_BS_SETTINGS_PRT_EEPROM_CONTROL_BIT      = ERROR_SETTINGS_PRT_EEPROM_CONTROL_BIT,

ERROR_BS_SETTINGS_BS_EEPROM_BIT               = ERROR_SETTINGS_BS_EEPROM_BIT,
ERROR_BS_SETTINGS_BS_EEPROM_EMPTY_BIT         = ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT,
ERROR_BS_SETTINGS_BS_EEPROM_COMPARISON_BIT    = ERROR_SETTINGS_BS_EEPROM_COMPARISON_BIT,
ERROR_BS_SETTINGS_BS_EEPROM_CONTROL_BIT       = ERROR_SETTINGS_BS_EEPROM_CONTROL_BIT,

ERROR_BS_USTUVANNJA_EEPROM_BIT                   = ERROR_USTUVANNJA_EEPROM_BIT,
ERROR_BS_USTUVANNJA_EEPROM_EMPTY_BIT             = ERROR_USTUVANNJA_EEPROM_EMPTY_BIT,
ERROR_BS_USTUVANNJA_EEPROM_COMPARISON_BIT        = ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT,
ERROR_BS_USTUVANNJA_EEPROM_CONTROL_BIT           = ERROR_USTUVANNJA_EEPROM_CONTROL_BIT,


ERROR_BS_STATE_LEDS_EEPROM_BIT                   = ERROR_STATE_LEDS_EEPROM_BIT,
ERROR_BS_STATE_OUTPUTS_EEPROM_BIT                = ERROR_STATE_OUTPUTS_EEPROM_BIT,

ERROR_BS_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT       = ERROR_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT,
ERROR_BS_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT  = ERROR_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT,

ERROR_BS_TRG_FUNC_EEPROM_BIT                       = ERROR_TRG_FUNC_EEPROM_BIT,
ERROR_BS_TRG_FUNC_EEPROM_EMPTY_BIT                 = ERROR_TRG_FUNC_EEPROM_EMPTY_BIT,
ERROR_BS_TRG_FUNC_EEPROM_COMPARISON_BIT            = ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT,

ERROR_BS_INFO_REJESTRATOR_AR_EEPROM_BIT            = ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT,
ERROR_BS_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT      = ERROR_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT,
ERROR_BS_INFO_REJESTRATOR_AR_COMPARISON_BIT        = ERROR_INFO_REJESTRATOR_AR_COMPARISON_BIT,
ERROR_BS_INFO_REJESTRATOR_AR_CONTROL_BIT           = ERROR_INFO_REJESTRATOR_AR_CONTROL_BIT,

ERROR_BS_INFO_REJESTRATOR_DR_EEPROM_BIT        = ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT,
ERROR_BS_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT  = ERROR_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT,
ERROR_BS_INFO_REJESTRATOR_DR_COMPARISON_BIT    = ERROR_INFO_REJESTRATOR_DR_COMPARISON_BIT,
ERROR_BS_INFO_REJESTRATOR_DR_CONTROL_BIT       = ERROR_INFO_REJESTRATOR_DR_CONTROL_BIT,

ERROR_BS_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT       = ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT,
ERROR_BS_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT = ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT,
ERROR_BS_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT   = ERROR_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT,
ERROR_BS_INFO_REJESTRATOR_PR_ERR_CONTROL_BIT      = ERROR_INFO_REJESTRATOR_PR_ERR_CONTROL_BIT,

ERROR_BS_RTC_BATTERY_LOW_BIT  =  RTC_BATTERY_LOW_BIT,

ERROR_BS_RTC_OSCILLATOR_STOPED_BIT  = RTC_OSCILLATOR_STOPED_BIT,
ERROR_BS_RTC_OSCILLATOR_FAIL_BIT    = RTC_OSCILLATOR_FAIL_BIT,

ERROR_BS_RTC_UPDATING_HALTED_BIT     = RTC_UPDATING_HALTED_BIT,

ERROR_BS_RTC_WORK_FIELD_NOT_SET_BIT  = RTC_WORK_FIELD_NOT_SET_BIT,

ERROR_BS_SPI_RED_BIT = ERROR_SPI_RED_BIT,

ERROR_BS_AR_TEMPORARY_BUSY_BIT    = (ERROR_BS_SPI_RED_BIT + 1),
ERROR_BS_AR_OVERLOAD_BUFFER_BIT   = (ERROR_BS_SPI_RED_BIT + 2),
ERROR_BS_AR_LOSS_INFORMATION_BIT  = (ERROR_BS_SPI_RED_BIT + 3),

ERROR_BS_DDR_CHECK_BIT  = 64,

ERROR_BS_SPI_ICI_BIT         = (ERROR_BS_DDR_CHECK_BIT+1),  //transmittion not present
ERROR_BS_SPI_HDW_ICI_BIT     = (ERROR_BS_DDR_CHECK_BIT+2),  //hdw error framing etc
ERROR_BS_UART2_ICI_BIT       = (ERROR_BS_DDR_CHECK_BIT+3),  //transmittion not present
ERROR_BS_UART2_HDW_ICI_BIT   = (ERROR_BS_DDR_CHECK_BIT+4),  //hdw error framing parity etc
ERROR_BS_CHECKSUM_AR_PRG_EVT_BIT,
ERROR_BS_FATAL_EROR_LAST_BIT

};

// .#define SIZE_BS_RAM_PRG_EVT_UNN (  (( (ERROR_BS_FATAL_EROR_LAST_BIT )>>2)<<2) + (4*(1&&( (ERROR_BS_FATAL_EROR_LAST_BIT ))&3))    )
#define SIZE_BS_RAM_PRG_EVT_UNN (  (( (ERROR_BS_FATAL_EROR_LAST_BIT )>>3)) + (4*(1&&( (ERROR_BS_FATAL_EROR_LAST_BIT ))&3))    )

//#endif 

typedef struct tag_BsRamPrgEvtDsc
{
	union 
	{
		char   chArBsPrgEvts  [  SIZE_BS_RAM_PRG_EVT_UNN];
		short  shArBsPrgEvts  [ (SIZE_BS_RAM_PRG_EVT_UNN>>1)];
	    long    lArBsPrgEvts  [ (SIZE_BS_RAM_PRG_EVT_UNN>>2)];
		
	}UNBsRamPrgEvts;
	//long Additio Var if Need;
}BsRamPrgEvtDsc;





#endif
