
#include <tc/tc.h>
#include "modbus_header.h"

extern void clean_arr(unsigned char* pArr, unsigned int size);

void modbus_variables_init() {
  unsigned int size = sizeof(yust_values);
  clean_arr((unsigned char*)yust_values, size);
  pYustStateDsc.size_ustuvannja_BS = size;
  pYustStateDsc.p_ustuvannja_BS = &yust_values[0];
  
  //для карты памяти - первый блок
  pDevIdentification.IdentNumberDevice = 1;
  pDevIdentification.Manufacturer1and2 = 0x4b69; // "Ki"
  pDevIdentification.Manufacturer3and4 = 0x6576; // "ev"
  pDevIdentification.Manufacturer5and6 = 0x7072; // "pr"
  pDevIdentification.Manufacturer7and8 = 0x6962; // "ib"
  pDevIdentification.Manufacturer9and10 = 0x6f72; // "or"
  pDevIdentification.NameOfDevice1and2 = 0x4d52; // "MR"
  pDevIdentification.NameOfDevice3and4 = 0x5a56; // "ZV"
  pDevIdentification.NameOfDevice5and6 = 0x2020; // "  "
  pDevIdentification.NameOfDevice7and8 = 0x2020; // "  "
  pDevIdentification.SoftwareVersion = 0x0101;
  pDevIdentification.DateOfCompilation1 = 0x0102;
  pDevIdentification.DateOfCompilation2 = 0x0304;
  pDevIdentification.TimeOfCompilation = 0x0506;
  pDevIdentification.VersionOfMemoryMap = 0x0101;
}

