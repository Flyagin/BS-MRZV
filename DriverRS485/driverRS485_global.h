void Setings_RS485(void);
void ConfigureUsart(void);
void ChangeConfRS485(unsigned BaudRate, unsigned PARITY, unsigned StopBit);
int driverRS485_main(void);
void WriteDataRS485(unsigned char *response, unsigned size);
