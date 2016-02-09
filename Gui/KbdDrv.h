 #ifndef kbddrv_h
#define kbddrv_h


#include "../LibG45/boards/bs_g45/board.h"
//
#define SW1 (1<<26)
#define SW2 (1<<27)
#define SW3 (1<<28)
#define SW4 (1<<29)
#define SW5 (1<<30)
#define SW6 (1<<31)

#define SWA (1<<20)
#define SWB (1<<21)
#define SWC (1<<22)
#define SWD (1<<23)
#define SWE (1<<24)
#define SWF (1<<25)

#define LINES_MASK  (SW1 | SW2 | SW3 | SW4 | SW5 | SW6)
//#define LINES_OFF_MASK
#define COLUMNS_MASK ( SWA | SWB | SWC | SWD | SWE |SWF)
//#define KEY_MASK ((unsigned long long)0xFFFFFFFFF) //

#define RANG_KEY 2 //2 * unsigned int (8 bytes)

#define _CHECK_KEY_SET_BIT(_key_array, _number_bit)                                             \
        (_key_array[_number_bit >> 5] & ( (unsigned int)( 1 << (_number_bit & 0x1f)) ) )                           

#define _SET_KEY_BIT(_key_array, _number_bit)                                                   \
        _key_array[_number_bit >> 5] |= (unsigned int)(1 << (_number_bit & 0x1f))

#define _CLEAR_KEY_BIT(_key_array, _number_bit)                                                 \
        _key_array[_number_bit >> 5] &= (unsigned int)(~(1 << (_number_bit & 0x1f)))

enum __rang_key {
  VK_OFFSET_MINUS = 0,
  VK_OFFSET_PLUS,
  VK_OFFSET_TAB,
  VK_OFFSET_HOME,
  VK_OFFSET_UP,
  VK_OFFSET_PG_UP,
  VK_OFFSET_7,
  VK_OFFSET_8,
  VK_OFFSET_9,
  VK_OFFSET_LEFT,
  VK_OFFSET_DOWN,
  VK_OFFSET_RIGHT,
  VK_OFFSET_4,
  VK_OFFSET_5,
  VK_OFFSET_6,
  VK_OFFSET_END,
  VK_OFFSET_F1,
  VK_OFFSET_PG_DN,
  VK_OFFSET_1,
  VK_OFFSET_2,
  VK_OFFSET_3,
  VK_OFFSET_ESC,
  VK_OFFSET_F2,
  VK_OFFSET_ENTER,
  VK_OFFSET_POINT,
  VK_OFFSET_0,
  VK_OFFSET_DEL,
  VK_OFFSET_RESERV1,
  VK_OFFSET_F3,
  VK_OFFSET_RESERV2,
  VK_OFFSET_ALT,
  VK_OFFSET_SHIFT,
  VK_OFFSET_CTRL,
  VK_OFFSET_LED,
  VK_OFFSET_F4,
  /*----------------*/
  NR_KEY_ITEMS
};

#define _KEY_MASK_ ((unsigned int)0xFFFFFFFF0)

//#define VK_MINUS                                0
//#define VK_PLUS                                 1
//#define VK_TAB                                  2
//#define VK_HOME                                 3
//#define VK_UP                                   4
//#define VK_PG_UP                                5
//#define VK_7                                    6
//#define VK_8                                    7
//#define VK_9                                    8
//#define VK_LEFT                                 9
//#define VK_DOWN                                 10
//#define VK_RIGHT                                11
//#define VK_4                                    12
//#define VK_5                                    13
//#define VK_6                                    14
//#define VK_END                                  15
//#define VK_F1                                   16
//#define VK_PG_DN                                17
//#define VK_1                                    18
//#define VK_2                                    19
//#define VK_3                                    20
//#define VK_ESC                                  21
//#define VK_F2                                   22
//#define VK_ENTER                                23
//#define VK_POINT                                24
//#define VK_0                                    25
//#define VK_DEL                                  26
//#define VK_RESERV1                              27
//#define VK_F3                                   28
//#define VK_RESERV2                              29
//#define VK_ALT                                  30
//#define VK_SHIFT                                31
//#define VK_CTRL                                 32
//#define VK_LED                                  33
//#define VK_F4                                   34
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
typedef struct tag_KbdU32
{
  union {
    unsigned char      arUch[8]; //0  input Data  field
    unsigned short     arUsh[4]; //01 Key1 field
    unsigned long int  arUl [2]; //02 Key2 field
  } UNFKeyField; //UNF-Union Field Bit - Total 64 bit

  union {
    unsigned long ulReserv; //0x Reserv fiel for future
  } UNFReserv; //
} KbdUNFldHolderDsc;
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
extern void StartUPInitKBD(void);
extern void kbd_scan(void*pv);
extern KbdUNFldHolderDsc hldScanCode;

//extern unsigned int uiCtrHideScr; 
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 
void ServiceLLDFlQuery(void);
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//~~~~~~~~~~~~~~~~    Define Layer T         ~~~~~~~~~~~~~~~~~
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//~~~~~~~~~~~~~~~~ 

//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#endif /* kbddrv_h */
