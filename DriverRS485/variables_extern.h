
/// Pins to configure for the application.
//extern const Pin pins[];

/// Number of bytes received between two timer ticks.
//extern volatile unsigned int bytesReceivedRS485;

/// Receive buffer.
extern unsigned char pBufferRS485[BUFFER_SIZE];

/// String buffer.
//extern char pStringRS485[24];

// Intermediarte buffer 
extern unsigned char data_read[BUFFER_SIZE];
extern unsigned char data_write[BUFFER_SIZE];



extern unsigned int flag_read, flag_write, flag_writing; // flags for swiching  between reading & writing

extern unsigned int BYTE_COUNTER_READ, BYTE_COUNTER_WRITE; // counter for byte 

//extern unsigned int BaudRate, PARITY, StopBit; // variables for changing settings of usart
