#ifndef __MEMORY_MAP_TYPE_DEFINITION_BL_H
#define __MEMORY_MAP_TYPE_DEFINITION_BL_H

#define NUMBER_REGS_ACTIVE_FUNC                                 24
/////////// Identification of Device //////////////
typedef struct DevIdentification_Tag
{
  unsigned short IdentNumberDevice;
  unsigned short Manufacturer1and2;
  unsigned short Manufacturer3and4;
  unsigned short Manufacturer5and6;
  unsigned short Manufacturer7and8;
  unsigned short Manufacturer9and10;
  unsigned short NameOfDevice1and2;
  unsigned short NameOfDevice3and4;
  unsigned short NameOfDevice5and6;
  unsigned short NameOfDevice7and8;
  unsigned short SoftwareVersion;
  unsigned short DateOfCompilation1;
  unsigned short DateOfCompilation2;
  unsigned short TimeOfCompilation;
  unsigned short VersionOfMemoryMap;
} DevIdentification;

// Time and date
typedef struct DateInDevice_Tag
{
  unsigned char miliSeconds;
  unsigned char seconds;
  unsigned char minutes;
  unsigned char hour;
  unsigned char dayOfWeek;
  unsigned char dayOfMonth;
  unsigned char month;
  unsigned char year;
} DateInDevice;

// Transformators
typedef struct Transformators_Tag
{
  unsigned int tn1_coef_trans;
  unsigned int tn2_coef_trans;
  unsigned int tt_coef_trans;
  unsigned int to_coef_trans;
} Transformators;


#endif
