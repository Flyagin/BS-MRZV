#include "LibRS485.h"
#include "constant.h"
#include "variables_extern.h"

#include "communication_constants.h"
#include "modbus_header.h"

extern void request_handler(unsigned short size);

extern unsigned char source_id;

char rs_485_state = RS_485_NO_ERROR;

//------------------------------------------------------------------------------
/// Configures USART in hardware handshaking mode, asynchronous, 8 bits, 1 stop
/// bit, no parity, 115200 bauds and enables its transmitter and receiver.
//------------------------------------------------------------------------------
void ConfigureUsartRS485(void)
{
    unsigned int mode = AT91C_US_USMODE_RS485
                        | AT91C_US_CLKS_CLOCK
                        | AT91C_US_CHRL_8_BITS
                        | AT91C_US_PAR_NONE
                        | AT91C_US_NBSTOP_1_BIT
                        | AT91C_US_CHMODE_NORMAL;

    // Enable the peripheral clock in the PMC
    PMC_EnablePeripheral(BOARD_ID_USART_RS485);

    // Configure the USART in the desired mode @115200 bauds
    USART_Configure(BOARD_USART_BASE_RS485, mode, 115200, BOARD_MCK);

    // Enable receiver & transmitter
    USART_SetTransmitterEnabled(BOARD_USART_BASE_RS485, 1);
    USART_SetReceiverEnabled(BOARD_USART_BASE_RS485, 1);
    
//    Set Time-out
     
    BOARD_USART_BASE_RS485->US_RTOR=18;
    
//    Swich on time out
    BOARD_USART_BASE_RS485->US_CR = AT91C_US_STTTO;
    
//    Swich on PDC
    USART_ReadBuffer(BOARD_USART_BASE_RS485, pBufferRS485, BUFFER_SIZE);
     
}


//------------------------------------------------------------------------------
//Changing configuration of USART
//------------------------------------------------------------------------------

void ConfigureUsartChange(unsigned int BaudRate_tmp, unsigned int PARITY_tmp, 
                          unsigned int StopBit_tmp )
{
  switch(BaudRate_tmp){
    case 0:
      BaudRate_tmp=115200;
      break;
    case 1:
      BaudRate_tmp=57600;
      break;
    case 2:
      BaudRate_tmp=38400;
      break;
    case 3:
      BaudRate_tmp=28800;
      break;
    case 4:
      BaudRate_tmp=19200;
      break;
    case 5:
      BaudRate_tmp=14400;
      break;
    case 6:
      BaudRate_tmp=9600;
      break;
  }
        
  switch(PARITY){
    case 0:
      PARITY_tmp=AT91C_US_PAR_EVEN;
      break;
    case 1:
      PARITY_tmp=AT91C_US_PAR_ODD;
      break;
    case 2:
      PARITY_tmp=AT91C_US_PAR_SPACE;
      break;
    case 3:
      PARITY_tmp=AT91C_US_PAR_MARK;
      break;
    case 4:
      PARITY_tmp=AT91C_US_PAR_NONE;
      break;
    case 5:
      PARITY_tmp=AT91C_US_PAR_MULTI_DROP;
      break;
  } 
  
  switch (StopBit){
    case 0:
      StopBit_tmp=AT91C_US_NBSTOP_1_BIT;
      break;
    case 1:
      StopBit_tmp=AT91C_US_NBSTOP_15_BIT;
      break;
    case 2:
      StopBit_tmp=AT91C_US_NBSTOP_2_BIT;
      break;
  }
  
  unsigned int mode = AT91C_US_USMODE_RS485
                        | AT91C_US_CLKS_CLOCK
                        | AT91C_US_CHRL_8_BITS
                        | PARITY_tmp
                        | StopBit_tmp
                        | AT91C_US_CHMODE_NORMAL;
  
     // Enable the peripheral clock in the PMC
    PMC_EnablePeripheral(BOARD_ID_USART_RS485);

    // Configure the USART in the desired mode bauds
    USART_Configure(BOARD_USART_BASE_RS485, mode, BaudRate_tmp, BOARD_MCK);

    // Enable receiver & transmitter
    USART_SetTransmitterEnabled(BOARD_USART_BASE_RS485, 1);
    USART_SetReceiverEnabled(BOARD_USART_BASE_RS485, 1);
    
//    Set Time-out
     
    BOARD_USART_BASE_RS485->US_RTOR=18;
    
//    Swich on time out
    BOARD_USART_BASE_RS485->US_CR = AT91C_US_STTTO;
    
//    Swich on PDC
    USART_ReadBuffer(BOARD_USART_BASE_RS485, pBufferRS485, BUFFER_SIZE);   
}



void Setings_RS485(void)
{
   /// Pins to configure for the application.
  const Pin pins[] = {
    BOARD_PIN_USART_RXD_RS485,
    BOARD_PIN_USART_TXD_RS485,
    BOARD_PIN_USART_RTS_RS485
};   
  // Configure pins
    PIO_Configure(pins, PIO_LISTSIZE(pins));

  // Configure USART and display startup trace
    ConfigureUsartRS485();
}


void driverRS485_main(void)
{
 
//         Checking buffer 
      
        if (((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_TIMEOUT)!=0)||((BOARD_USART_BASE_RS485->US_CSR & AT91C_US_RXBUFF) != 0)){
//         Checking  errors 
          
          if(((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_OVRE)== 0)&&((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_FRAME)==0)&&((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_PARE)==0)
             &&((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_RXBRK)==0)){
              
              BYTE_COUNTER_READ=BUFFER_SIZE-BOARD_USART_BASE_RS485->US_RCR;
              for (unsigned int i=0; i< BYTE_COUNTER_READ; i++){ 
                
//         Copying data from buffer to data array
                data_read[i]=pBufferRS485[i];
        
                
              }
              flag_read = 1;
           }else{
              BOARD_USART_BASE_RS485->US_CR=AT91C_US_RSTSTA;   
           } 
          
//        Swich on time out
          BOARD_USART_BASE_RS485->US_CR = AT91C_US_STTTO; 
          BOARD_USART_BASE_RS485->US_RCR=0;
          BOARD_USART_BASE_RS485->US_RNCR=0;
          
//        Swich on PDC
          USART_ReadBuffer(BOARD_USART_BASE_RS485, pBufferRS485, BUFFER_SIZE);
           
        }
        if(flag_read==1){
         flag_write = 1;
          BYTE_COUNTER_WRITE=BYTE_COUNTER_READ;

            source_id = RS_485_SOURCE;
            if (modbus_dev_state == DEV_FREE) {
              for (unsigned short i = 0; i < BYTE_COUNTER_READ; i++) {
                *(puchMsg + i) = *(data_read + i);
              }
            }
            request_handler(BYTE_COUNTER_READ);
            
//          }
          flag_read=0;
        }
}

   void WriteDataRS485(unsigned char *response, unsigned size){
   
     // Checking transmission, if it has already done
        if((flag_write==1)&&(flag_writing==1)){
          if (((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_ENDTX)!=0)&&((BOARD_USART_BASE_RS485->US_CSR&AT91C_US_TXBUFE)!=0)){
            flag_writing=0;
            flag_write=1;
          }
         }   
    //Check transmition is ready
     if ((flag_write==1)&&(flag_writing==0)){
          for (unsigned int i=0; i < size; i++){
            *(data_write + i) = *(response + i);
          }
          USART_WriteBuffer(BOARD_USART_BASE_RS485, data_write, size);
          flag_writing=1;
        }
               
    }

       
void ChangeConfRS485(unsigned BaudRate_tmp, unsigned PARITY_tmp, unsigned StopBit_tmp){
          // Disable USART
          PMC_DisablePeripheral(BOARD_ID_USART_RS485);
          // Changing configuratin USART
          ConfigureUsartChange(BaudRate_tmp, PARITY_tmp, StopBit_tmp);
          
        
}

