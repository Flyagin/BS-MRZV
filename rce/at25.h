#ifndef AT25512_h
#define AT25512_h


//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Перечень констант                                        ~~~~~
//~~~       Instruction Set For Atmel AT25512                        ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//``````````````````````````````````````````````````````````````````````````````````
#define AT25_CMD_WREN   0x6  //.0000 X110 Set Write Enable Latch
#define AT25_CMD_WRDI   0x4  //.0000 X100 Reset Write Enable Latch
#define AT25_CMD_RDSR   0x5  //.0000 X101 Read Status Register
#define AT25_CMD_WRSR   0x1  //.0000 X001 Write Status Register
#define AT25_CMD_READ   0x3  //.0000 X011 Read Data from Memory Array
#define AT25_CMD_WRITE  0x2  //.0000 X010 Write Data to Memory Array Bit

//``````````````````````````````````````````````````````````````````````````````````
//~~~     - 
//~~~     - 
//~~~     - 
//~~~     - 
//..................................................................................

//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
//~~~       Перечень констант  SB Staus bit                                    ~~~~~
//~~~       Status Register Format  Bit Definition                             ~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#define RDY_SB_MSK      (1<<0)//.Bit 0 (RDY) Bit 0 = 0 (RDY) indicates the device is ready.
#define WRITING_SB_MSK  (1<<0)//.Bit 0 = 1 indicates the write cycle is in progress.
#define WEN_SB_MSK      (1<<1)//.Bit 1 (WEN) Bit 1 = 0 indicates the device is not write enabled. Bit 1 = 1 indicates the device is write enabled.
#define BP0_SB_MSK      (1<<2)//.Bit 2 (BP0) See Table 6-4 on page 10.
#define BP1_SB_MSK      (1<<3)//.Bit 3 (BP1) See Table 6-4 on page 10.
//..#define SB_MSK  (1<<0)    //.Bits 4 ? 6 are zeros when the device is not in an internal write cycle.
#define WPEN_SB_MSK     (1<<7)//.Bit 7 (WPEN) See Table 6-5 on page 10.
 //.Bits 0 ? 7 are ones during an internal write cycle.
#define RDY_SB_ONB      (0)//
#define WRITING_SB_ONB  (0)//
#define WEN_SB_ONB      (1)//
#define BP0_SB_ONB      (2)//
#define BP1_SB_ONB      (3)//
#define WPEN_SB_ONB     (7) 
//``````````````````````````````````````````````````````````````````````````````````
//..................................................................................
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#endif //  AT25512_h
