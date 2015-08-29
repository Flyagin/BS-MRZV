#ifndef __CONST_GLOBAL_ZIGBEE__
#define __CONST_GLOBAL_ZIGBEE__

#define AT91C_ID_US_ZIGBEE      AT91C_ID_US1
#define AT91C_BASE_US_ZIGBEE       AT91C_BASE_US1

// USART1 TXD pin як передавач для ZigBee
#define PIN_ZIGBEE_TXD  {1 << 4, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
// USART1 RXD як приймач для ZigBee
#define PIN_ZIGBEE_RXD  {1 << 5, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}

#define SPEED_ZIGBEE            115200
#define PARE_ZIGBEE             AT91C_US_PAR_EVEN /*Парність*/
#define STOP_BITS_ZIGBEE        AT91C_US_NBSTOP_1_BIT /*1 Стоп-біт*/

#define SIZE_BUFFER_ZIGBEE 255


#endif
