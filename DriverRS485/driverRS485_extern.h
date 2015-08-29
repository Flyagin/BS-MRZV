extern void Setings_RS485(void);
extern void ConfigureUsart(void);
extern void ChangeConfRS485(unsigned BaudRate, unsigned PARITY, unsigned StopBit);
extern int driverRS485_main(void);
extern void WriteDataRS485(unsigned char *response, unsigned size);
