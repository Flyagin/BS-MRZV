#ifndef __MODBUS_VARIABLES__
#define __MODBUS_VARIABLES__

#include "modbus_constants.h"
#include "ici_ef.h"
#include "hv_df.h"
#include "hve_df.h"
#include "memory_map_type_definition.h"

#include "../inc/const_BS_BL.h"
#include "../inc/type_definition_BS.h"

unsigned char modbus_dev_state = DEV_FREE;
_Bool response_ready = true;

unsigned char modbus_func_id = MODBUS_EMPTY_FUNC;

_Bool start_update_adc = false;
_Bool start_update_yust_values = false;
_Bool send_settings = false;
_Bool get_settings = false;
_Bool send_yust = false;
_Bool get_yust = false;
_Bool yust_values_is_updated = false;

_Bool error_update_data_from_adc = false;
_Bool error_get_settings = false;
_Bool error_send_settings = false;
_Bool error_get_yust = false;
_Bool error_send_yust = false;
unsigned char data_ADC_index = 0;

unsigned char puchMsg[256];

unsigned int tmp_outputs = 0x000260FB; //0x0007ffff
ArTenPerStateDsc arTenPerStateDsc;

__TOTAL_MEASUREMENT modbus_total_measurement;

SettingsStateDsc pSettigsStateDscTmp1;

unsigned short activatingUstValue = 6520;
_Bool ust_is_active = false;
unsigned int yust_values[NUMBER_CANALS];
unsigned int read_yust_counter = 0;
YustStateDsc pYustStateDsc;

unsigned short tmp_measurements1[15];
unsigned short tmp_measurements2[11];
unsigned short tmp_angles[6];
unsigned short tmp_sectors[10];
unsigned short tmp_measurements3[12];
float floating_measurements[18];

unsigned char modbus_func_code_arr[NUMBER_MODBUS_FUNCTIONS] =
{
  MODBUS_FUNC1, MODBUS_FUNC2, MODBUS_FUNC3,  MODBUS_FUNC4,  MODBUS_FUNC5, 
  MODBUS_FUNC6 /*, MODBUS_FUNC8*/, MODBUS_FUNC15, MODBUS_FUNC16/*, MODBUS_FUNC20 */
};

/******************************************************************************/
/************************ Variables for memory map ****************************/
/******************************************************************************/

// Data
DevIdentification pDevIdentification;
extern CfgTblDsc eeprom_prt_tbl;

//test

unsigned short password;
unsigned short passwordProtectionSet;


unsigned short ActiveFuncStore[NUMBER_REGS_ACTIVE_FUNC]; // к-во элементов по количеству регистров в блоке КП
unsigned short trippedFuncStore[NUMBER_REGS_ACTIVE_FUNC];

//DateInDevice pDateInDevice @"DMA_BUFFERS";

Transformators ownrTransformators;

unsigned int GUIlanguage_id;

#endif

