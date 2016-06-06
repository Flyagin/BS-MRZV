/* This file declares the TWI function for BS*/

bool IsTWIReady(void);

void TWISendData(
    AT91S_TWI *pTwi,
    unsigned char address,
    unsigned int iaddress,
    unsigned char isize,
    unsigned int BytesToSend,
    unsigned char bytes[]);


void TWIReadData(
    AT91S_TWI *pTwiBS,
    unsigned char address,
    unsigned int iaddress,
    unsigned char isize);

void AltTWIWriteData(AT91S_TWI *pTwiBS, unsigned char* dataBuf[], int NumByteToWrite,
                     unsigned char address, unsigned int iaddress, unsigned char isize);

void setTWIClock(AT91S_TWI *pTwiBS, unsigned int twck, unsigned int mck);

