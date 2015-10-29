

/// Pins to configure for the application.
//const Pin pins[] = {
//    BOARD_PIN_USART_RXD,
//    BOARD_PIN_USART_TXD
//};

/// Number of bytes received between two timer ticks.
//volatile unsigned int bytesReceivedRS485 = 0;

/// Receive buffer.
unsigned char pBufferRS485[BUFFER_SIZE] @"DMA_BUFFERS";

/// String buffer.
//char pStringRS485[24];

// Intermediarte buffer 
unsigned char data_read[BUFFER_SIZE];
unsigned char data_write[BUFFER_SIZE];



unsigned int flag_read=0, flag_write=0, flag_writing=0; // flags for swiching  between reading & writing& transmiting

unsigned int BYTE_COUNTER_READ, BYTE_COUNTER_WRITE; // counter for byte 

//unsigned int BaudRate, PARITY, StopBit; // variables for changing settings of usart
