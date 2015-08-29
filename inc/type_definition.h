#ifndef __TYPE_DEFINITION__
#define __TYPE_DEFINITION__

#include "modbus_header.h"

//type definitions for EEPROM
typedef enum eepromWriteStep {
  writeArray = 0,
  write_crc,
  controlReading,
  CRanalysis
} eepromWriteStepID;

typedef enum eepromReadStep {
  readArray = 0,
  sendData
} eepromReadStepID;

typedef struct eeprom_r_manager {
  unsigned short startAddr;
  unsigned int length;
  unsigned char *pData;
  eepromReadStepID Rstep;
} eeprom_r_manager;

typedef struct eeprom_w_manager {
  unsigned short startAddr;
  unsigned char *pData;
  unsigned int length;
  eepromWriteStepID Wstep;
  unsigned int bytesSent;
  unsigned int bytesToWrite;
} eeprom_w_manager;

typedef struct eeprom_manager {
  unsigned int statusRegWasRead;
//  unsigned int operationID;
  unsigned short *pCRC;
  unsigned int failCode;
  unsigned int emptyCode;
  unsigned int failCRCCode;
  
  eeprom_w_manager writeManager;
  eeprom_r_manager readManager;
} eeprom_manager;

// type definintion for RTC
typedef struct rtcMgr {
  unsigned char isDataRead;
  unsigned char waitCount;
  unsigned char fieldST;
  unsigned char fieldOF;
  unsigned char fieldHT;
  DateInDevice heldTime;
  unsigned char calibr;
} rtcMgr;

// type definitions for DataFlash AR and DR
typedef enum dataFlashWriteStep {
  memoryToBuffTransfer = 0,
  buffWrite,
  buffToMemoryTransfer,
  wholePageWrite
} dataFlashWriteStepID;

typedef enum dataFlashReadStep {
  readSR = 0,
  startReading,
  sendDataWithPointer
} dataFlashReadStepID;

typedef struct DF_R_manager {
  unsigned short pageAddr;
  unsigned short buffAddr;
  int length;
  dataFlashReadStepID DFStepR;
  unsigned char *pDataArray;
} DF_R_manager;

typedef struct DF_W_manager {
  unsigned short pageAddr;
  unsigned short buffAddr;
  int length;
  unsigned char *pDataArray;
  dataFlashWriteStepID DFstepW;
  unsigned int numBytesToWrite;
  unsigned int bytesSent;
} DF_W_manager;

typedef struct DF_manager
{
  char statusRegWasRead;
  DF_R_manager readManag;
  DF_W_manager writeManag;
  
} DF_manager;

#endif
