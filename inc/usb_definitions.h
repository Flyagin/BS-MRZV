
//------------------------------------------------------------------------------
//      Definitions
//------------------------------------------------------------------------------
#ifndef AT91C_ID_TC0
    #define AT91C_ID_TC0 AT91C_ID_TC
#endif

/// Size in bytes of the buffer used for reading data from the USB & USART
#define DATABUFFERSIZE \
    BOARD_USB_ENDPOINTS_MAXPACKETSIZE(CDCDSerialDriverDescriptors_DATAIN)

/// Use for power management
#define STATE_IDLE    0
/// The USB device is in suspend state
#define STATE_SUSPEND 4
/// The USB device is in resume state
#define STATE_RESUME  5

//#if defined(at91sam9m10ek) || defined(at91sam3uek)
//#define PINS_USART      PIN_USART1_TXD, PIN_USART1_RXD
//#define BASE_USART      AT91C_BASE_US1
//#define ID_USART        AT91C_ID_US1     
//#else
//#define PINS_USART      PIN_USART0_TXD, PIN_USART0_RXD
//#define BASE_USART      AT91C_BASE_US0
//#define ID_USART        AT91C_ID_US0
//#endif
