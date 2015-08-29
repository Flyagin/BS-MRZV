#include "header_mal.h"

/********************
Стартові налаштування периферії для ZigBee
********************/
void settings_for_ZigBee(void)
{
  //Включаємо USART для роботи як прийомопередавач ZigBee  
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_US_ZIGBEE);
  
//  Pin pPins_ZigBee_Tx[1] = {{1 << 4, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}};
//  Pin pPins_ZigBee_Rx[1] = {{1 << 5, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}};
//  PIO_Configure(pPins_ZigBee_Tx, PIO_LISTSIZE(pPins_ZigBee_Tx));
//  PIO_Configure(pPins_ZigBee_Rx, PIO_LISTSIZE(pPins_ZigBee_Rx));
//  
//  while (test == 0)
//  {
//    PIO_Set(pPins_ZigBee_Tx);
//    PIO_Set(pPins_ZigBee_Rx);
//
//    PIO_Clear(pPins_ZigBee_Tx);
//    PIO_Clear(pPins_ZigBee_Rx);
//  }

  //Настроюємо піни TXD, RXD ZigBee як периферію
  Pin pPins_ZigBee[2] = {PIN_ZIGBEE_TXD, PIN_ZIGBEE_RXD};
  PIO_Configure(pPins_ZigBee, PIO_LISTSIZE(pPins_ZigBee));

  //Скидаємо обмін по PDC для USART0
  AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  AT91C_BASE_US_ZIGBEE->US_TCR = 0;
  AT91C_BASE_US_ZIGBEE->US_TNCR = 0;
  AT91C_BASE_US_ZIGBEE->US_RCR = 0;
  AT91C_BASE_US_ZIGBEE->US_RNCR = 0;
  
  //Відключаємо генерацію переривань від USART ZigBee
  AT91C_BASE_AIC->AIC_IDCR = 1 << AT91C_ID_US_ZIGBEE;

  //Забороняємо генерацію переривань від USART ZigBee
  AT91C_BASE_US_ZIGBEE->US_IDR = 0xffffffff;
  
  //Конфігуруємо USART ZigBee 
  USART_Configure(AT91C_BASE_US_ZIGBEE,
                 ((AT91C_US_USMODE & AT91C_US_USMODE_NORMAL) 
                  |(AT91C_US_CLKS & AT91C_US_CLKS_CLOCK)
                  |(AT91C_US_CHRL & AT91C_US_CHRL_8_BITS)
                  |(AT91C_US_PAR & PARE_ZIGBEE)
                  |(AT91C_US_NBSTOP & STOP_BITS_ZIGBEE)
                  /*| AT91C_US_OVER*/),
                  SPEED_ZIGBEE,
                  BOARD_MCK);

//  //Дозволяємо передавач і приймач
  AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_TXEN | AT91C_US_RXEN;
  //Дозволяємо передавач
  AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_TXEN;
  //Дозволяємо приймач
  AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_RXEN;

  //Запиуск очікування нового фрейиму  
  restart_monitoring_ZigBee();
  
}
/*******************/

/********************
Перезапиуск очікування нового фрейиму
********************/
void restart_monitoring_ZigBee(void)
{
  unsigned int timeout = (1 + 8 + 1 + 1)*15/10;
    
  //Зупиняємо автоматичний прийом поки не буде проаналізований прийнятий фрейм
  AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_RXTDIS;

  //Зчитуємо якийсь байт, якщо він є у приймачі
  AT91C_BASE_US_ZIGBEE->US_RHR;
  //Скидаємо біти помилок
  AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_RSTSTA;

  //Запускаємо прийом байт на максимальну величину довжини фрейму  
  AT91C_BASE_US_ZIGBEE->US_RPR = (unsigned int)receiving_buffer_ZigBee;
  AT91C_BASE_US_ZIGBEE->US_RCR = SIZE_BUFFER_ZIGBEE;
  AT91C_BASE_US_ZIGBEE->US_RNCR = 0;
  AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_RXTEN;

  //Перезапускаємо очікування нового фрейму
  AT91C_BASE_US_ZIGBEE->US_RTOR = timeout;
  AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_STTTO;
  
  //Помічаємо, що нового пакету ще не отримано
  data_ZigBee_received = false;
}
/*******************/

/*******************
Сканування аналу обміну з модемом ZigBee
*******************/
void ZigBee_scaner(void)
{
  unsigned int status = AT91C_BASE_US_ZIGBEE->US_CSR;
  if (data_ZigBee_transmiting == false)
  {
    //Іде процес приймання даних від модему ZigBee

    if ((status & AT91C_US_TIMEOUT) != 0)
    {
      //Зупиняємо автоматичний прийом поки не буде проаналізований прийнятий фрейм
      AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_RXTDIS;

      if((status & (AT91C_US_RXBRK | AT91C_US_OVRE | AT91C_US_FRAME | AT91C_US_PARE)) == 0)
      {
        //Не зафіксовано помиилок при прийомі
        count_receiving_byte_ZigBee = SIZE_BUFFER_ZIGBEE - AT91C_BASE_US_ZIGBEE->US_RCR;

        if (
            (count_receiving_byte_ZigBee == 3) &&
            (receiving_buffer_ZigBee[0] == 'c' ) &&
            (receiving_buffer_ZigBee[1] == 'd' ) &&
            (receiving_buffer_ZigBee[2] == 'e' )
           )   
        {
          //Передаємо пакет синхронізації
          unsigned char address = eeprom_bs_settings_tbl.RS_comm_addres;
          transmiting_buffer_ZigBee[0] = address;
          transmiting_buffer_ZigBee[1] = (unsigned char)((~(unsigned int)address) & 0xff);
          count_transmiting_byte_ZigBee = 2;
          ZigBee_transmit();
        }
        else if (receiving_buffer_ZigBee[0] == eeprom_bs_settings_tbl.RS_comm_addres)
        {
          //Виставляємо повідомлення про прийняті байти по інтерфейсу ZigBee
          data_ZigBee_received = true;
        
          /***
          Тимчасово для відладки
          ***/
          count_transmiting_byte_ZigBee = count_receiving_byte_ZigBee;
          for (int i = 0; i < count_transmiting_byte_ZigBee; i++)
            transmiting_buffer_ZigBee[i] = receiving_buffer_ZigBee[i];
          ZigBee_transmit();
          /**/
        }
      }
      else
      {
        //Перезапиуск очікування нового фрейиму  
        restart_monitoring_ZigBee();
      }
    }
  }
  else
  {
    //Іде процес передавання даних в модем ZigBee
    
    if ((status & AT91C_US_TXBUFE) != 0)
    {
      //Зупиняємо PDC на передавання
      AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_TXTDIS;
      //Включаємо приймач
      AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_RXEN;
      //Знімаємо індикацію пропередачі фрейму
      data_ZigBee_transmiting = false;

      //Перезапиуск очікування нового фрейиму  
      restart_monitoring_ZigBee();
    }
  }
 }
/*******************/

/*******************
Відправлення даних у модем ZigBee
*******************/
void ZigBee_transmit(void)
{
  //Помічаємо, що почалася передача по ZigBee
  data_ZigBee_transmiting = true;
  
  //Відключаємо приймач
  AT91C_BASE_US_ZIGBEE->US_CR = AT91C_US_RXDIS;

  //Запускаємо передавання байт у модем ZigBee  
  AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_TXTDIS;
  AT91C_BASE_US_ZIGBEE->US_TPR = (unsigned int)transmiting_buffer_ZigBee;
  AT91C_BASE_US_ZIGBEE->US_TCR = count_transmiting_byte_ZigBee;
  AT91C_BASE_US_ZIGBEE->US_TNCR = 0;
  AT91C_BASE_US_ZIGBEE->US_PTCR = AT91C_PDC_TXTEN;
}
/*****************/
