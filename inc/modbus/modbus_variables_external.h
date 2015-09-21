#include "ici_ef.h"
#include "memory_map_type_definition.h"
#include "hv_df.h"
#include "hve_df.h"

#include "../inc/const_BS_BL.h"
#include "../inc/type_definition_BS.h"

extern unsigned char modbus_dev_state;
extern _Bool response_ready;

extern unsigned char modbus_func_id;

extern unsigned char modbus_func_code_arr[NUMBER_MODBUS_FUNCTIONS];

extern _Bool start_update_adc;
extern _Bool start_update_yust_values;
extern _Bool send_settings;
extern _Bool get_settings;
extern _Bool send_yust;
extern _Bool get_yust;
extern _Bool yust_values_is_updated;
extern _Bool error_update_data_from_adc;
extern _Bool error_get_settings;
extern _Bool error_send_settings;
extern _Bool error_get_yust;
extern _Bool error_send_yust;

extern unsigned char data_ADC_index;
extern unsigned char puchMsg[256];
extern unsigned int tmp_outputs;

extern __TOTAL_MEASUREMENT modbus_total_measurement;

extern ArTenPerStateDsc arTenPerStateDsc;

extern SettingsStateDsc pSettigsStateDscTmp1;

extern unsigned short activatingUstValue;
extern _Bool ust_is_active;
extern unsigned int yust_values[NUMBER_CANALS];
extern unsigned int read_yust_counter;
extern YustStateDsc pYustStateDsc;

extern unsigned short tmp_measurements1[15];
extern unsigned short tmp_measurements2[11];
extern unsigned short tmp_angles[6];
extern unsigned short tmp_sectors[10];
extern unsigned short tmp_measurements3[12];
extern float floating_measurements[18];

// Memory map

extern DevIdentification pDevIdentification;
extern CfgTblDsc eeprom_prt_tbl;

extern unsigned short password;
extern unsigned short passwordProtectionSet;

extern unsigned short ActiveFuncStore[NUMBER_REGS_ACTIVE_FUNC];
extern unsigned short trippedFuncStore[NUMBER_REGS_ACTIVE_FUNC];

//extern DateInDevice pDateInDevice;

extern Transformators ownrTransformators;

extern unsigned int GUIlanguage_id;
