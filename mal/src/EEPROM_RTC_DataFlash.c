#include "header_mal.h"


/**********
Startova konfiguracia SPI1 dlja konfiguruvannja EEPROM, RTC i DataFlash
**********/
void ConfigureSPI1(void)
{
  Pin SPI1_pins[] = {PINS_SPI1_CS_ALL, PINS_SPI1};
  PIO_Configure(SPI1_pins, PIO_LISTSIZE(SPI1_pins));
  
  //Mode-Register
  unsigned int SPI1_Config = AT91C_SPI_MSTR | AT91C_SPI_PS_VARIABLE | AT91C_SPI_MODFDIS |(AT91C_SPI_PCS & (0<<16));
  SPI_Configure(AT91C_BASE_SPI1, AT91C_ID_SPI1, SPI1_Config);

  // RTC
  unsigned int RTC_ConfigNPCS = AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (14<<8) | /*AT91C_SPI_CSAAT|*/ (AT91C_SPI_DLYBCT & (10 << 24)));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 0, RTC_ConfigNPCS);
  
  // EEPROM
  unsigned int EEPROM_ConfigNPCS =  AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (72<<8) | /*AT91C_SPI_CSAAT |*/ (AT91C_SPI_DLYBCT & (3 << 24)));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 1, EEPROM_ConfigNPCS);
  
  // Data Flash DR
  unsigned int DataFlashDigit_ConfigNPCS =   AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (9<<8)) | (AT91C_SPI_DLYBCT & (6 << 24));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 2, DataFlashDigit_ConfigNPCS);
  
  // Data Flash AR
  unsigned int DataFlashAnalog_ConfigNPCS =   AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | (AT91C_SPI_SCBR & (9<<8)) | (AT91C_SPI_DLYBCT & (6 << 24));
  SPI_ConfigureNPCS(AT91C_BASE_SPI1, 3, DataFlashAnalog_ConfigNPCS);

  //Instalation PDC for SPI1
  AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS);
  AT91C_BASE_SPI1->SPI_RPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RNPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RCR = 0;
  AT91C_BASE_SPI1->SPI_RNCR = 0;
  AT91C_BASE_SPI1->SPI_TPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TNPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TCR = 0;
  AT91C_BASE_SPI1->SPI_TNCR = 0;
  
  AT91C_BASE_SPI1->SPI_SR;
  //Enable SPI1
  SPI_Enable(AT91C_BASE_SPI1);
  while ((AT91C_BASE_SPI1->SPI_SR & AT91C_SPI_RDRF) != 0) AT91C_BASE_SPI1->SPI_RDR;
}
/*********/

/*****************************************************/
//������ ����� �� SPI1
/*****************************************************/
void start_exchange_via_SPI1(unsigned int device_type, unsigned int number)
{
  //���������, �� ��� ���� �� ������ SPI1
  state_execution_spi1 = 0;

  //��������� SPI1_PDC ���� �� ��������� � �����������, ������ ����� ���� ����� ����������
  AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS);
  AT91C_BASE_SPI1->SPI_RPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RNPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
  AT91C_BASE_SPI1->SPI_RCR = number;
  AT91C_BASE_SPI1->SPI_RNCR = 0;
  AT91C_BASE_SPI1->SPI_TPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TNPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
  AT91C_BASE_SPI1->SPI_TCR = number;
  AT91C_BASE_SPI1->SPI_TNCR = 0;

  //����������� chip_select
  unsigned int chip_select = 0x000f0000;
  switch (device_type)
  {
  case SPI1_RTC:
    {
      chip_select = 0x00000000;
      break;
    }
  case SPI1_EEPROM:
    {
      chip_select = 0x00010000;
      break;
    }
  case SPI1_DF_DR:
    {
      chip_select = 0x00030000;
      break;
    }
  case SPI1_DF_AR:
    {
      chip_select = 0x00070000;
      break;
    }
  default:
    {
      //³������� ����������� �������, ���� ����� ��� �� ����������������
      while(1);
    }
  }
  for (unsigned int i = 0; i < number; i++) Temporaty_SPI1_Buffer_Tx_with_CS[i] = Temporaty_SPI1_Buffer_Tx[i] | chip_select;
  number_transmit_SPI1 = number;
  
  //������� ������ ��������
  AT91C_BASE_SPI1->SPI_RDR;
  while ((AT91C_BASE_SPI1->SPI_SR & AT91C_SPI_RDRF) != 0) AT91C_BASE_SPI1->SPI_RDR;


  //��������� ������-�������� 
  AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTEN | AT91C_PDC_RXTEN);
}
/*****************************************************/

/*****************************************************/
//��������� ������ ����� SPI
/*****************************************************/
void main_routines_for_spi1(void)
{
  //�������� �����, ��� ����� ���� ���� ��������� ����� ���������� � EEPROM
  static unsigned int number_block_settings_prt_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ��������� ����� ���������� � EEPROM
  static unsigned int number_block_settings_bs_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ��������� ����� ���������� � EEPROM
  static unsigned int number_block_ustuvannja_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ����� ������ � �������������� ����� ���������� � EEPROM
  static unsigned int number_block_state_leds_outputs_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ����� �������� ������� ����� ���������� � EEPROM
  static unsigned int number_block_state_trg_func_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ���������� �� ����������� ���������� ����� ���������� � EEPROM
  static unsigned int number_block_info_rejestrator_ar_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ���������� �� ����������� ���������� ����� ���������� � EEPROM
  static unsigned int number_block_info_rejestrator_dr_write_to_eeprom;
  //�������� �����, ��� ����� ���� ���� ���������� �� ��������� ���������� ���� ����� ���������� � EEPROM
  static unsigned int number_block_info_rejestrator_pr_err_write_to_eeprom;

  static unsigned int temp_value_for_rtc;

  //�������� ������� ����, �� ������ ��� ��������� �������� ��������/������ ��������� DataFlash
  static unsigned int address_read_write_ar_tmp, number_bytes_read_write_ar_tmp;
  static int etap_writing_df_ar;
  static unsigned int address_read_write_dr_tmp, number_bytes_read_write_dr_tmp;
  static int etap_writing_df_dr;
  
  //������� ���� ��� �������� ���������� ������
  static CfgTblDsc eeprom_prt_tbl_comp;
  static AuxCfgTbl1Dsc eeprom_bs_settings_tbl_comp;
  static unsigned int ustuvannja_comp[NUMBER_CANALS], phi_ustuvannja_comp[NUMBER_CANALS], ustuvannja_P_comp[3], ustuvannja_Q_comp[3];
  static unsigned int state_trigger_leds_comp, state_signal_outputs_comp;
  static unsigned int trigger_active_functions_comp[N_TMP];
  static __TEMP_STRUCTURE EepromARecDesc_comp;
  static __TEMP_STRUCTURE EepromDRecDesc_comp;
  static __TEMP_STRUCTURE EepromErrRecDesc_comp;
  
  if (state_execution_spi1 == 0)
  {
    //Vidbuvajetsja obmin
    unsigned int status_SPI1 = AT91C_BASE_SPI1->SPI_SR;
    
    if (
        ((status_SPI1 & (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE)) == (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE)) ||
        ((status_SPI1 & AT91C_SPI_OVRES) != 0)
       )   
    {
      if ((status_SPI1 & AT91C_SPI_OVRES) != 0)
      {
        //Fiksacija pomylky pid chas opbinu
        state_execution_spi1 = 2;

        /*����������� ����������� ��� ������� ����� ����� SPI_RED*/
        _SET_BIT(diagnostyka, ERROR_SPI_RED_BIT);
      }
      else if ((status_SPI1 & (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE)) == (AT91C_SPI_RXBUFF | AT91C_SPI_TXBUFE))
      {
        //Fiksacija zavershennja obminu
        for (unsigned int i = 0; i < number_transmit_SPI1; i++) Temporaty_SPI1_Buffer_Rx[i] = Temporaty_SPI1_Buffer_Rx_with_CS[i] & 0xff;
        state_execution_spi1 = 1;

        //���� ������� ����� - ������� ����������� ��� ���������� ������� ������� ����� ����� SPI_RED
        _CLEAR_BIT(diagnostyka, ERROR_SPI_RED_BIT);
      }
      
      AT91C_BASE_SPI1->SPI_PTCR = (AT91C_PDC_TXTDIS | AT91C_PDC_RXTDIS);
      AT91C_BASE_SPI1->SPI_RPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
      AT91C_BASE_SPI1->SPI_RNPR = (unsigned int) Temporaty_SPI1_Buffer_Rx_with_CS;
      AT91C_BASE_SPI1->SPI_RCR = 0;
      AT91C_BASE_SPI1->SPI_RNCR = 0;
      AT91C_BASE_SPI1->SPI_TPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
      AT91C_BASE_SPI1->SPI_TNPR = (unsigned int) Temporaty_SPI1_Buffer_Tx_with_CS;
      AT91C_BASE_SPI1->SPI_TCR = 0;
      AT91C_BASE_SPI1->SPI_TNCR = 0;
      number_transmit_SPI1 = 0;
    }
  }
  
  if (state_execution_spi1 < 0)
  {
    /*************************************************/
    //����� ����� ��������� ���� ���������� ����� SPI
    /*************************************************/
    
    if (
        ((control_spi1_taskes[0] & (MASKA_ACTION_DF_AR_0 | MASKA_ACTION_DF_DR_0)) != 0) ||
        ((control_spi1_taskes[1] & (MASKA_ACTION_DF_AR_1 | MASKA_ACTION_DF_DR_1)) != 0)
       ) 
    {    
      //������ � ���� ������� ��� DataFlash
      if ((AR_DR & _DF_LOCK) == 0)
      {
        //�� ������� ����������� ����� ������ �������� �� DataFlash
        if      (
                 (
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_AR_0) != 0) ||
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_AR_1) != 0)
                 )
                 &&  
                 (  
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_DR_0) == 0) &&
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_DR_1) == 0)
                 )   
                ) 
        {
          //������ � ���� �� ������� ����� ������ ��� ����������� ����������
          AR_DR = _DF_AR | _DF_LOCK;
        }
        else if (
                 (
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_DR_0) != 0) ||
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_DR_1) != 0)
                 )
                 &&  
                 (  
                  ((control_spi1_taskes[0] & MASKA_ACTION_DF_AR_0) == 0) &&
                  ((control_spi1_taskes[1] & MASKA_ACTION_DF_AR_1) == 0)
                 )   
                ) 
        {
          //������ � ���� �� ������� ����� ������ ��� ����������� ����������
          AR_DR = _DF_DR | _DF_LOCK;
        }
        else
        {
          //������ � ���� �� ������� ������ � ��� ����������� ����������, � ��� ����������� ����������
          if (AR_DR == _DF_AR) AR_DR = _DF_DR | _DF_LOCK;
          else  AR_DR = _DF_AR | _DF_LOCK;
        }
      }
    }
    else AR_DR = _DF_NONE;
      
    unsigned int AR_DR_tmp = AR_DR & (unsigned int)(~_DF_LOCK);
    
    if(_CHECK_SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT) !=0)
    {
      //����������� ������� RTC � ������ ������� �������� ��� ����, ��� �� ����� ���� 1 ��
      if (etap_settings_test_frequency == 0)
      {
        //������� ����� ��� �������� � RTC (�� ������ + ��������� ������ - ����������� �����)
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0xC;
        Temporaty_SPI1_Buffer_Tx[1] = temp_register_rtc[0];
      
        //��������� ������ ������ � RTC
        start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
      }
      else if (etap_settings_test_frequency == 1)
      {
        //������� ����� ��� �������� � RTC (�� ������ + ��������� ������ - ����������� �����)
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0x13;
        Temporaty_SPI1_Buffer_Tx[1] = 0xf0;
      
        //��������� ������ ������ � RTC
        start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
      }
      else
      {
        //������� ����� ��� �������� � RTC (�� ������ + ��������� ������ - ����������� �����)
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0xA;
        Temporaty_SPI1_Buffer_Tx[1] = temp_register_rtc[1];
      
        //��������� ������ ������ � RTC
        start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
      }
    }
    else if((_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0) || (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT) !=0))
    {
      //������� ����� ��� �������� � RTC (�� ������ + ��������� ������ - ����������� �����)

      if (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0)
      {
        //�������� OF-�� � RTC
        if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_STOP)
          Temporaty_SPI1_Buffer_Tx[1] = rtc_time[1] | (1<<7); //ST = 1
        else if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_CLEAR)
          Temporaty_SPI1_Buffer_Tx[1] = rtc_time[1] & (~(1<<7)) ; //ST = 0
        else
          Temporaty_SPI1_Buffer_Tx[1] = (unsigned char)(temp_value_for_rtc) & (~(1<<2)) ; //OF = 0
      }
      else
      {
        Temporaty_SPI1_Buffer_Tx[1] = rtc_time[1] & (~(1<<7)) ; //ST = 0;
      }
      
      //��������� ������ ������ � RTC
      if ((_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0) && (etap_reset_of_bit != ETAP_CLEAR_OF_ST_STOP) && (etap_reset_of_bit != ETAP_CLEAR_OF_ST_CLEAR))
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0xF;
      else
        Temporaty_SPI1_Buffer_Tx[0] = (WRITE_BIT_OPERATION << 7) | 0x1;

      start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
    }
    else if(_CHECK_SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT) !=0)
    {
      unsigned int number;
      
      //������� ����� ��� �������� �  EEPROM (�� ������ + ��������� ������ - ����������� �����)
      if ((etap_eeprom_write_enable < 0) || ((etap_eeprom_write_enable > 1))) etap_eeprom_write_enable = 0;

      if (etap_eeprom_write_enable == 0)
      {
        //������ ������ �������
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_RDSR;
        Temporaty_SPI1_Buffer_Tx[1] = 0; //����-���� ���� ��� ����, ��� �������� ������� ������� �������;
        number = 2;
      }
      else if (etap_eeprom_write_enable == 1)
      {
        //������ ������ �������
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WREN;
        number = 1;
      }
      
      //��������� ������ ������ � EEPROM
      start_exchange_via_SPI1(SPI1_EEPROM, number);
    }
    else if(
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
           )   
    {
      //������ ������ ������� � ��������� DataFlash
      Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_STATUS_READ;
      Temporaty_SPI1_Buffer_Tx[1] = 0; //����-���� ���� ��� ����, ��� �������� ������� ������� �������;
      
      //��������� ������ ������ � EEPROM
      AR_DR = AR_DR_tmp;
      start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, 2);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� � EEPROM ���������

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_settings_prt_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (sizeof(eeprom_prt_tbl) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_SETTINGS_PRT_IN_EEPROM + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ��������� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_SETTINGS_PRT_IN_EEPROM + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ��������� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ��������� ��� ���������, ���� ������� ����� ������ ��������� � EEPROM

        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_SETTINGS_PRT;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
        
        //������� ����� ������ ��������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� � EEPROM ��������� ��

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_settings_bs_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (sizeof(eeprom_bs_settings_tbl) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_SETTINGS_BS_IN_EEPROM + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ��������� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_SETTINGS_BS_IN_EEPROM + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ��������� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ��������� ��� ���������, ���� ������� ����� ������ ��������� � EEPROM

        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_SETTINGS_BS;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
        
        //������� ����� ������ ��������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� � EEPROM ���������

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_ustuvannja_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (SIZE_USTUVANNJA + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_USTUVANNJA_IN_EEPROM + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ��������� � �������� ������ � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_USTUVANNJA_IN_EEPROM + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ��������� � �������� ������ � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ��������� ��� ���������

        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_USTUVANNJA;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
        
        //������� ����� ������ ��������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� � EEPROM ����� ������ � ��������������

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_state_leds_outputs_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = 4 - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ����� ������ � �������������� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ����� ������ � �������������� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ����� ������ � �������������� ��� ���������, ���� ������� ����� ������ ����� ������ � �������������� � EEPROM

        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_STATE_LEDS_OUTPUTS;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);

        //C������ ����� ������ ����� ������-�������������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� � EEPROM ����� �������� �������

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_state_trg_func_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (sizeof(trigger_active_functions) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ����� �������� ������� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ����� �������� ������� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ����� �������� ������� ��� ���������, ���� ������� ����� ������ ����� �������� ������� � EEPROM

        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_TRG_FUNC;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);

        //C������ ����� ������ ����� �������� ������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� ���������� ����������� ���������� � EEPROM

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_info_rejestrator_ar_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (sizeof(EepromARecDesc) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_INFO_REJESTRATORS_AR + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ��������� ����������� ���������� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_INFO_REJESTRATORS_AR + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ��������� ����������� ���������� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ��� ���������
       
        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_INFO_REJESTRATOR_AR;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);

        //C������ ����� ������ ���������� ����������� ���������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� ���������� ����������� ���������� � EEPROM

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_info_rejestrator_dr_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (sizeof(EepromDRecDesc) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_INFO_REJESTRATORS_DR + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ��������� ����������� ���������� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_INFO_REJESTRATORS_DR + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ��������� ����������� ���������� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ��� ���������
       
        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_INFO_REJESTRATOR_DR;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);

        //C������ ����� ������ ���������� ����������� ���������� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //����� ����� ������ ����� ���������� ���������� ���������� ���� � EEPROM

      int size_to_end;
      unsigned int number, offset_from_start;
      
      //��������� � ����� ���� ����� ������ ����������
      offset_from_start = number_block_info_rejestrator_pr_err_write_to_eeprom*SIZE_PAGE_EEPROM;

      //ʳ������ ���� �� ���� ������ 
      size_to_end = (sizeof(EepromErrRecDesc) + 1) - offset_from_start; 
      
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = OPCODE_WRITE;
        Temporaty_SPI1_Buffer_Tx[1] = ((START_ADDRESS_INFO_REJESTRATORS_PR_ERR + offset_from_start) >> 8) & 0xff; //������  ������ ������� ��������� ��������� ���������� ���������� ���� � EEPROM
        Temporaty_SPI1_Buffer_Tx[2] = ((START_ADDRESS_INFO_REJESTRATORS_PR_ERR + offset_from_start)     ) & 0xff; //������� ������ ������� ��������� ��������� ���������� ���������� ���� � EEPROM

        if (size_to_end < SIZE_PAGE_EEPROM) number = size_to_end;
        else number = SIZE_PAGE_EEPROM;

        if (offset_from_start != 0)
        {
          //��������� ��� ��� ������ �� ������ � ������� ������� ������ ��� ����, ��� ���������� ����� ����� ��� �������� �� PDC
          for (unsigned int i = 0; i < number; i++)
            Temporaty_SPI1_Buffer_Tx[3 + i] = Temporaty_SPI1_Buffer_Tx[3 + offset_from_start + i];
        }
        
        //��������� ������ ������ � EEPROM
        start_exchange_via_SPI1(SPI1_EEPROM, (3 + number));
      }
      else
      {
        //���� ����� ��� ���������
       
        //����������� ������� ������������ ������� ��� ��������� ����������� �������� ����������
        comparison_writing |= COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR;
        _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);

        //C������ ����� ������ ���������� ���������� ���������� ���� � EEPROM
        _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //��������� ������ ������� ��������� - ������� ����� ��� ����������� � EEPROM ��� ��������� ��������� � ������� �����
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_USTUVANNJA_IN_EEPROM >> 8) & 0xff; //������  ������ ������� ��������� ��������� � �������� ������ � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_USTUVANNJA_IN_EEPROM     ) & 0xff; //������� ������ ������� ��������� ��������� � �������� ������ � EEPROM
                                                                                      //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((SIZE_USTUVANNJA + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //��������� ������ ������� ��������� - ������� ����� ��� ����������� � EEPROM ��� ��������� ���������
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_SETTINGS_PRT_IN_EEPROM >> 8) & 0xff; //������  ������ ������� ��������� ��������� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_SETTINGS_PRT_IN_EEPROM     ) & 0xff; //������� ������ ������� ��������� ��������� � EEPROM
                                                                                    //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(eeprom_prt_tbl) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //��������� ������ ������� ��������� - ������� ����� ��� ����������� � EEPROM ��� ��������� ��������� ��
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_SETTINGS_BS_IN_EEPROM >> 8) & 0xff; //������  ������ ������� ��������� ��������� �� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_SETTINGS_BS_IN_EEPROM     ) & 0xff; //������� ������ ������� ��������� ��������� �� � EEPROM
                                                                                    //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(eeprom_bs_settings_tbl) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //��������� ������ �������  ����� ��� �������� ������ � ������� ��������� - ������� ����� ��� ����������� � EEPROM ��� ���������  ��� ��� �������� ������ � ������� ���������
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM >> 8) & 0xff; //������  ������ ������� ��������� ����� ��� �������� ������ � ������� ��������� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_STATE_LEDS_OUTPUTS_IN_EEPROM     ) & 0xff; //������� ������ ������� ��������� ����� ��� �������� ������ � ������� ��������� � EEPROM
                                                                                              //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, (4 + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //��������� ������ �������  ����� ��� �� - ������� ����� ��� ����������� � EEPROM ��� ���������  ��� ��� ��
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM >> 8) & 0xff; //������  ������ ������� ��������� ����� ��� �� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_STATE_TRG_FUNC_IN_EEPROM     ) & 0xff; //������� ������ ������� ��������� ����� ��� �� � EEPROM
                                                                                          //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(trigger_active_functions) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //��������� ������ ������� ���������� �� ����������� ���������� - ������� ����� ��� ����������� � EEPROM ��� ���������  ��� �� ����������� ����������
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_INFO_REJESTRATORS_AR >> 8) & 0xff; //������  ������ ������� ��������� ����� �� ����������� ���������� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_INFO_REJESTRATORS_AR     ) & 0xff; //������� ������ ������� ��������� ����� �� ����������� ���������� � EEPROM
                                                                                      //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(EepromARecDesc) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //��������� ������ ������� ���������� �� ����������� ���������� - ������� ����� ��� ����������� � EEPROM ��� ���������  ��� �� ����������� ����������
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_INFO_REJESTRATORS_DR >> 8) & 0xff; //������  ������ ������� ��������� ����� �� ����������� ���������� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_INFO_REJESTRATORS_DR     ) & 0xff; //������� ������ ������� ��������� ����� �� ����������� ���������� � EEPROM
                                                                                      //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(EepromDRecDesc) + 1) + 3));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //��������� ������ ������� ���������� �� ���������� ���������� ���� - ������� ����� ��� ����������� � EEPROM ��� ���������  ��� �� ���������� ���������� ����
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_READ;
      Temporaty_SPI1_Buffer_Tx[1] = (START_ADDRESS_INFO_REJESTRATORS_PR_ERR >> 8) & 0xff; //������  ������ ������� ��������� ����� �� ���������� ���������� ���� � EEPROM
      Temporaty_SPI1_Buffer_Tx[2] = (START_ADDRESS_INFO_REJESTRATORS_PR_ERR     ) & 0xff; //������� ������ ������� ��������� ����� �� ���������� ���������� ���� � EEPROM
                                                                                          //������ �������� ���� �� �� ��������
      start_exchange_via_SPI1(SPI1_EEPROM, ((sizeof(EepromErrRecDesc) + 1) + 3));
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT) !=0)
//    {
//      //��������� ������ �������� ��������� DataFlash �� ����� ������� � 256 ����
//      Temporaty_SPI1_Buffer_Tx[0] = 0x3D;
//      Temporaty_SPI1_Buffer_Tx[1] = 0x2A;
//      Temporaty_SPI1_Buffer_Tx[2] = 0x80;
//      Temporaty_SPI1_Buffer_Tx[3] = 0xA6;
//
//      start_exchange_via_SPI1(SPI1_DF, 4);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //��������� ������ �������� ��������� DataFlash
      Temporaty_SPI1_Buffer_Tx[0] = 0xC7;
      Temporaty_SPI1_Buffer_Tx[1] = 0x94;
      Temporaty_SPI1_Buffer_Tx[2] = 0x80;
      Temporaty_SPI1_Buffer_Tx[3] = 0x9A;

      AR_DR = AR_DR_tmp;
      start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, 4);
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //����� ����� ������ ��������� DataFlash
      unsigned int size_page, size_buffer;
               int *point_to_etap_writing_df;
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_number_bytes_read_write;
      unsigned int *point_to_address_read_write_tmp;
      unsigned int *point_to_address_read_write;
      unsigned int *buffer_serial_DataFlash_read_write;
      
      if (AR_DR_tmp == _DF_AR)
      {
        size_page = SIZE_PAGE_SERIAL_DATAFLASH_AR;
        size_buffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR;
        point_to_etap_writing_df = &etap_writing_df_ar;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_ar;
        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
        point_to_address_read_write = &address_read_write_ar;
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_ar;
      }
      else
      {
        size_page = SIZE_PAGE_SERIAL_DATAFLASH_DR;
        size_buffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR;
        point_to_etap_writing_df = &etap_writing_df_dr;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_dr;
        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
        point_to_address_read_write = &address_read_write_dr;
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_dr;
      }

      unsigned int _PA, _BA;
      _PA = *point_to_address_read_write_tmp / size_page;
      _BA = *point_to_address_read_write_tmp - _PA*size_page;
      
      if (*point_to_etap_writing_df == ETAP_WRITING_DF_NONE)
      {
        //����� ������ ���� ��������

        //ʳ������ ���� �� ���� ������ 
        int size_to_end = *point_to_number_bytes_read_write - (*point_to_address_read_write_tmp - *point_to_address_read_write);

        if (size_to_end > 0)
        {
          int size_from_begin_page = *point_to_address_read_write_tmp % size_page;
          if (
              (size_to_end >= (int)size_page)  &&
              (size_from_begin_page == 0)
             )
          {
            //����� ���������� ����� ���� ������� ��������� "Main Memory Page Program Through Buffer"
            *point_to_number_bytes_read_write_tmp = size_page;
            
            *point_to_etap_writing_df = ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER;
          }
          else
          {
            //����� ���������� "������ �������� ��������" ��� ������ � ���������� �� � �������� "Main Memory Page to Buffer Transfer"
            int size_to_end_page = size_page - size_from_begin_page;
            if (size_to_end > size_to_end_page) *point_to_number_bytes_read_write_tmp = size_to_end_page;
            else *point_to_number_bytes_read_write_tmp = size_to_end;
            
            *point_to_etap_writing_df = ETAP_WRITING_DF_MAIN_MEMORY_TO_BUFFER_TRANSFER;
          }
        }
        else
        {
          //���� ����� ��� ���������, ���� ������� ����� ������ ��������� DataFlash
          *point_to_number_bytes_read_write_tmp = 0;
          
          *point_to_etap_writing_df = ETAP_WRITING_DF_NONE;
        }
      }
      
      unsigned int number_transmit;
      
      switch (*point_to_etap_writing_df)
      {
      case ETAP_WRITING_DF_NONE:
        {
          //����� ��������� ��������� ������
          _CLEAR_BIT(control_spi1_taskes, ((AR_DR_tmp == _DF_AR) ? TASK_WRITING_SERIAL_DATAFLASH_AR_BIT : TASK_WRITING_SERIAL_DATAFLASH_DR_BIT));
          break;
        }
      case ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER:
        {
          //����� ������� ��������� ���� ������� � ���'��� ��������� DataFlash 
          
          unsigned int base_index = (*point_to_address_read_write_tmp - *point_to_address_read_write);
          if ((base_index + size_page) > size_buffer)
          {
            //³������� ����������� �������, ���� ����� ��� �� ����������������
            while(1);
          }

          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_WRITE_PAGE_THROUGH_BUFFER;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          for (unsigned int i = 0; i < size_page; i++)
            Temporaty_SPI1_Buffer_Tx[4 + i] = buffer_serial_DataFlash_read_write[base_index + i];
            
          number_transmit = 4 + size_page;
          break;
        }
      case ETAP_WRITING_DF_MAIN_MEMORY_TO_BUFFER_TRANSFER:
        {
          //����� ������� ��������� ������� � ����� ��������� DataFlash 
          
          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_READ_PAGE_INTO_BUFFER;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          //������ � ������� ������� �� �� ��������, ��� ���� �� ���
          
          number_transmit = 4;
          break;
        }
      case ETAP_WRITING_DF_BUFFER_WRITE:
        {
          //����� ������������ ������� ������

          unsigned int base_index = (*point_to_address_read_write_tmp - *point_to_address_read_write);
          if ((base_index + *point_to_number_bytes_read_write_tmp) > size_buffer)
          {
            //³������� ����������� �������, ���� ����� ��� �� ����������������
            while(1);
          }

          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_WRITE_BUFFER;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[2] = ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[2] = ((_BA >> 8) & 0x01);
            Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
          }
          for (unsigned int i = 0; i < *point_to_number_bytes_read_write_tmp; i++)
            Temporaty_SPI1_Buffer_Tx[4 + i] = buffer_serial_DataFlash_read_write[base_index + i];
            
          number_transmit = 4 + *point_to_number_bytes_read_write_tmp;
          break;
        }
      case ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE:
        {
          //����� �������� ����� ��������� DataFlash � ���'��� ��������� DataFlash � ��������� ������ �������
          
          Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_WRITE_BUFFER_INTO_MEMORY_WITH_ERASE;
          if (AR_DR_tmp == _DF_AR)
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          else
          {
            Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
            Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe);
          }
          //������ � ������� ������� �� �� ��������, ��� ���� �� ���
          
          number_transmit = 4;
          break;
        }
      default:
        {
          //³������� ����������� �������, ���� ����� ��� �� ����������������
          while(1);
        }
      }

      
      AR_DR = AR_DR_tmp;
      if (*point_to_etap_writing_df != ETAP_WRITING_DF_NONE)
      {
        //��������� ������ ����� DataFlash, ��� � �� ����������
        start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, number_transmit);
      }
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //����� ����� ������� ��������� DataFlash
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_number_bytes_read_write;
      unsigned int *point_to_address_read_write_tmp;
      unsigned int *point_to_address_read_write;
      unsigned int _PA, _BA;
      
      if (AR_DR_tmp == _DF_AR)
      {
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_ar;
        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
        point_to_address_read_write = &address_read_write_ar;

        _PA = *point_to_address_read_write_tmp / SIZE_PAGE_SERIAL_DATAFLASH_AR;
        _BA = *point_to_address_read_write_tmp - _PA*SIZE_PAGE_SERIAL_DATAFLASH_AR;
      }
      else
      {
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;
        point_to_number_bytes_read_write = &number_bytes_read_write_dr;
        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
        point_to_address_read_write = &address_read_write_dr;

        _PA = *point_to_address_read_write_tmp / SIZE_PAGE_SERIAL_DATAFLASH_DR;
        _BA = *point_to_address_read_write_tmp - _PA*SIZE_PAGE_SERIAL_DATAFLASH_DR;
      }

      int size_to_end;
      
      //ʳ������ ���� �� ���� ������ 
      size_to_end = *point_to_number_bytes_read_write - (*point_to_address_read_write_tmp - *point_to_address_read_write); 
      
      AR_DR = AR_DR_tmp;
      if (size_to_end > 0)
      {
        Temporaty_SPI1_Buffer_Tx[0] = CODE_OPERATION_READ_HIGH_FREQ;
        if (AR_DR_tmp == _DF_AR)
        {
          Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
          Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
          Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
        }
        else
        {
          Temporaty_SPI1_Buffer_Tx[1] =  (_PA >> 7);
          Temporaty_SPI1_Buffer_Tx[2] = ((_PA << 1) & 0xfe) | ((_BA >> 8) & 0x01);
          Temporaty_SPI1_Buffer_Tx[3] =  _BA & 0xff;
        }
        //ϳ��� ������ �� ��� ���� ��������� ���� �� ����� ����� �������� ����������� �������� �����

        if (((unsigned int)(size_to_end + 5)) <= SIZE_BUFFER_FOR_RED) *point_to_number_bytes_read_write_tmp = size_to_end;
        else *point_to_number_bytes_read_write_tmp = (SIZE_BUFFER_FOR_RED - 5);
        
        //��������� ������ ������� � DataFlash
        start_exchange_via_SPI1((AR_DR_tmp == _DF_AR) ? SPI1_DF_AR : SPI1_DF_DR, (5 + *point_to_number_bytes_read_write_tmp));
      }
      else
      {
        //���� ����� ��� ��������, ���� ������� ����� ������� ��������� DataFlash
        _CLEAR_BIT(control_spi1_taskes, ((AR_DR_tmp == _DF_AR) ? TASK_READING_SERIAL_DATAFLASH_AR_BIT : TASK_READING_SERIAL_DATAFLASH_DR_BIT));
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM ���������
      /***/
      
      //������ ����� ��� ������ ��������� � EEPROM ����� � ����������� �����
      unsigned char crc_eeprom_settings = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&eeprom_prt_tbl); 
      unsigned char  *point_2 = (unsigned char*)(&eeprom_prt_tbl_comp); 
      for (unsigned int i =0; i < sizeof(CfgTblDsc); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_settings += temp_value;
      }
      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(CfgTblDsc)] = (unsigned char)((~(unsigned int)crc_eeprom_settings) & 0xff);
      
//      /***
//      ҳ���� ��� �������
//      ***/
//      for (int i1 = 0; i1 < 50; i1++)
//      {
//        array_status[i1][0] = 0;
//        array_status[i1][1] = 0;
//        array_status[i1][2] = -1;
//        array_status[i1][3] = 0;
//        array_status[i1][4] = 0;
//      }
//      iteration = 0;
//      error_spi_eeprom = 0;
//      good_spi_eeprom = 0;
//      /**/
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_PRT_EEPROM_BIT);
      
      //����������� ������ ���� ��������� ������ � EEPROM
      number_block_settings_prt_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM ��������� ��
      /***/
      
      //������ ����� ��� ������ ��������� � EEPROM ����� � ����������� �����
      unsigned char crc_bs_eeprom_settings = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&eeprom_bs_settings_tbl); 
      unsigned char  *point_2 = (unsigned char*)(&eeprom_bs_settings_tbl_comp); 
      for (unsigned int i =0; i < sizeof(AuxCfgTbl1Dsc); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_bs_eeprom_settings += temp_value;
      }
      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(AuxCfgTbl1Dsc)] = (unsigned char)((~(unsigned int)crc_bs_eeprom_settings) & 0xff);
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SETTINGS_BS_EEPROM_BIT);
      
      //����������� ������ ���� ��������� ������ � EEPROM
      number_block_settings_bs_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM ���������
      
      //������ ���� ���������� ���������� ��� ��������
      
      //������ ����� ��� ������ ��������� � EEPROM ����� � ����������������
      unsigned char crc_eeprom_ustuvannja = 0, temp_value;
      unsigned char  *point_1; 
      unsigned char  *point_2;
      unsigned int offset = 0;

      point_1 = (unsigned char*)(&ustuvannja); 
      point_2 = (unsigned char*)(&ustuvannja_comp); 
      for (unsigned int i =0; i < sizeof(ustuvannja); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(ustuvannja);

      //������ ������� ����������� ���
      point_1 = (unsigned char*)(&phi_ustuvannja); 
      point_2 = (unsigned char*)(&phi_ustuvannja_comp);
      for (unsigned int i = 0; i < sizeof(phi_ustuvannja); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(phi_ustuvannja);

      //������ ������� ����������� ��� ������� ����㳿
      point_1 = (unsigned char*)(&ustuvannja_P); 
      point_2 = (unsigned char*)(&ustuvannja_P_comp);
      for (unsigned int i = 0; i < sizeof(ustuvannja_P); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(ustuvannja_P);

      //������ ������� ����������� ��� ��������� ����㳿
      point_1 = (unsigned char*)(&ustuvannja_Q); 
      point_2 = (unsigned char*)(&ustuvannja_Q_comp);
      for (unsigned int i = 0; i < sizeof(ustuvannja_Q); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_ustuvannja += temp_value;
      }
      offset += sizeof(ustuvannja_Q);
      
      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + offset] = (unsigned char)((~(unsigned int)crc_eeprom_ustuvannja) & 0xff);
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_USTUVANNJA_EEPROM_BIT);
      
      //����������� ������ ���� ��������� ������ � EEPROM
      number_block_ustuvannja_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM ����� ���������� ������ � ��������� ��������������
      
      //������ ����� ��� ������
      unsigned char temp_value = state_trigger_leds;
      state_trigger_leds_comp = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 0] = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 1] = (unsigned char)((~(unsigned int)temp_value) & 0xff);
      temp_value = state_signal_outputs;
      state_signal_outputs_comp = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 2] = temp_value;
      Temporaty_SPI1_Buffer_Tx[3 + 3] = (unsigned char)((~(unsigned int)temp_value) & 0xff);

      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);

      //����������� ������ ���� ����� ������-�������������� ������ � EEPROM
      number_block_state_leds_outputs_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM ����� �������� �������

      //������ ����� ��� ������ ��������� � EEPROM ����� � ����������������
      unsigned char crc_eeprom_trg_func = 0, temp_value;
      unsigned char  *point_1; 
      unsigned char  *point_2;
      unsigned int offset = 0;

      //������ ������ �������
      point_1 = (unsigned char*)(&trigger_active_functions); 
      point_2 = (unsigned char*)(&trigger_active_functions_comp);
      for (unsigned int i =0; i < sizeof(trigger_active_functions); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + offset + i] = temp_value;
        crc_eeprom_trg_func += temp_value;
      }
      offset += sizeof(trigger_active_functions);

      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + offset] = (unsigned char)((~(unsigned int)crc_eeprom_trg_func) & 0xff);
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_TRG_FUNC_EEPROM_BIT);

      //����������� ������ ���� ����� �������� ������� ������ � EEPROM
      number_block_state_trg_func_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM �� ���������� ����������� ����������
      
      //������ ����� ��� ������ � EEPROM ����� � ����������� �����
      unsigned char crc_eeprom_info_rejestrator_ar = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&EepromARecDesc); 
      unsigned char  *point_2 = (unsigned char*)(&EepromARecDesc_comp); 
      for (unsigned int i = 0; i < sizeof(__TEMP_STRUCTURE); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_info_rejestrator_ar += temp_value;
      }

      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(__TEMP_STRUCTURE)] = (unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_ar) & 0xff);
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_AR_EEPROM_BIT);
      
      //����������� ������ ���� ������ � EEPROM
      number_block_info_rejestrator_ar_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM �� ���������� ����������� ����������
      
      //������ ����� ��� ������ � EEPROM ����� � ����������� �����
      unsigned char crc_eeprom_info_rejestrator_dr = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&EepromDRecDesc); 
      unsigned char  *point_2 = (unsigned char*)(&EepromDRecDesc_comp); 
      for (unsigned int i = 0; i < sizeof(__TEMP_STRUCTURE); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
        Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_info_rejestrator_dr += temp_value;
      }

      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(__TEMP_STRUCTURE)] = (unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_dr) & 0xff);
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_DR_EEPROM_BIT);
      
      //����������� ������ ���� ������ � EEPROM
      number_block_info_rejestrator_dr_write_to_eeprom = 0;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ������ ������ � EEPROM �� ���������� ���������� ���������� ����

      //������ ����� ��� ������ � EEPROM ����� � ����������� �����
      unsigned char crc_eeprom_info_rejestrator_pr_err = 0, temp_value;
      unsigned char  *point_1 = (unsigned char*)(&EepromErrRecDesc); 
      unsigned char  *point_2 = (unsigned char*)(&EepromErrRecDesc_comp); 
      for (unsigned int i = 0; i < sizeof(__TEMP_STRUCTURE); i++)
      {
        temp_value = *(point_1);
        *(point_2) = temp_value;
        point_1++;
        point_2++;
         Temporaty_SPI1_Buffer_Tx[3 + i] = temp_value;
        crc_eeprom_info_rejestrator_pr_err += temp_value;
      }

      //���������� ����������� ���������� ���� � ����� ������
      Temporaty_SPI1_Buffer_Tx[3 + sizeof(__TEMP_STRUCTURE)] = (unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_pr_err) & 0xff);
      
      //������� �� ������� ������ ������ � ����������� �� ������ ����� � EEPROM � ���� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
      _SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      
      //����������� ������ ���� ������ � EEPROM
      number_block_info_rejestrator_pr_err_write_to_eeprom = 0;
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT             ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT           ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT            ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT               ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT    ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT    ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)  
            )
    {
      //��������� ������ �������

      //������ ������ ������� ������ �� ����� ������ EEPROM ���� ��� ������ ������
      Temporaty_SPI1_Buffer_Tx[0] = OPCODE_RDSR;
      Temporaty_SPI1_Buffer_Tx[1] = 0; //����-���� ���� ��� ����, ��� �������� ������� ������� �������;

      //��������� ������ ������ � RTC
      start_exchange_via_SPI1(SPI1_EEPROM, 2);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT) !=0)
    {
      //������� ����� ��� �������� � RTC (�� ������� + ��������� ������ - ����� ���� �� ����� ��������)
      Temporaty_SPI1_Buffer_Tx[0] = (READ_BIT_OPERATION << 7) | 0x0;
      
      //C������ �� ������� ������� RTC � ����������� �� ������� ������� RTC
      _SET_BIT(control_spi1_taskes, TASK_READING_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);

      //��������� ������ ������� RTC
      start_exchange_via_SPI1(SPI1_RTC, 21);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT) !=0)
    {
      //��������� ������ ������ ���� � RTC
      //������� ����� ��� �������� � RTC (�� ������ + ��������� ������ - ����������� �����)
      copying_time = 1; //�������, �� �����  �� ����� ���������� ����� ����
      Temporaty_SPI1_Buffer_Tx[    0] = (WRITE_BIT_OPERATION << 7) | 0x0;
      Temporaty_SPI1_Buffer_Tx[1 + 0] = rtc_time[0] = rtc_time_edit[0] & 0xFF;
      Temporaty_SPI1_Buffer_Tx[1 + 1] = rtc_time[1] = rtc_time_edit[1] & 0x7F;
      Temporaty_SPI1_Buffer_Tx[1 + 2] = rtc_time[2] = rtc_time_edit[2] & 0x7F;
      Temporaty_SPI1_Buffer_Tx[1 + 3] = rtc_time[3] = rtc_time_edit[3] & 0x3F;
      
      unsigned char time_edit_tmp = rtc_time_edit[4];
      if ((time_edit_tmp & 0x07) == 0) time_edit_tmp = (time_edit_tmp & 0x80) | 0x1;
      rtc_time[4] = time_edit_tmp & 0x07;
      Temporaty_SPI1_Buffer_Tx[1 + 4] = time_edit_tmp & 0x87;
      
      Temporaty_SPI1_Buffer_Tx[1 + 5] = rtc_time[5] = rtc_time_edit[5] & 0x3F;
      Temporaty_SPI1_Buffer_Tx[1 + 6] = rtc_time[6] = rtc_time_edit[6] & 0x1F;
      Temporaty_SPI1_Buffer_Tx[1 + 7] = rtc_time[7] = rtc_time_edit[7] & 0xFF;
      
      copying_time = 0; //�������, �� ���������� ����� ���� ���������
      
      //������ ���� ������ ���� ��� ����, ��� ���� �������� ����� ���� ����������� ����� ���� ����� ������� ����� ��������, ��� ��������� �������� ���� � ���� � ����� ������
      for(unsigned int i = 0; i < 8; i++) rtc_time_copy[i] = rtc_time[i];

      //������� �� ������� RTC � ����������� �� ������� ������� RTC
      _SET_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT);

      //��������� ������ ������ � RTC
      start_exchange_via_SPI1(SPI1_RTC, (1 + 8));
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT) !=0)
    {
      //��������� ������ ������ ��������� � RTC
      //������� ����� ��� �������� � RTC (�� ������ + ��������� ������ - ����������� �����)
      Temporaty_SPI1_Buffer_Tx[    0] = (WRITE_BIT_OPERATION << 7) | 0x8;
      Temporaty_SPI1_Buffer_Tx[1 + 0] = (rtc_calibration_edit & 0x3f) | (copy_register8_RTC & 0xC0);
      
      //������� �� ������� RTC � ����������� �� ������� ������� RTC
      _SET_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT);

      //��������� ������ ������ � RTC
      start_exchange_via_SPI1(SPI1_RTC, (1 + 1));
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_MAKE_PAGE_SIZE_256_BIT) !=0)
//    {
//      //������� �� ������� ����������� ��������� �� ������ ������� � 256 ���� � ����������� �� ����������� ��������� �� ������ ������� � 256 ���� � ���� ������� ������� �������
//      _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_BIT);
//      _SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT);
//      _CLEAR_BIT(control_spi1_taskes, TASK_START_MAKE_PAGE_SIZE_256_BIT);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      //������� �� ������� �������� �񳺿 ��������� DataFlash � ����������� �� �������� ��������� DataFlash � ���� ������� ������� �������
      if (AR_DR_tmp == _DF_AR)
      {
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_AR_BIT);
      }
      else
      {
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_ERASE_DATAFLASH_DR_BIT);
      }
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      if (AR_DR_tmp == _DF_AR)
      {
//        /*****/
//        //ҳ���� ��� �������
//        /*****/
//        for(unsigned int i = 0; i < number_bytes_read_write_ar; i++)
//          buffer_serial_DataFlash_read_write_ar[i] = (i+1) & 0xff;
//        /*****/

        //��������� ������ � �������� DataFlash � ��� ����� ������ ����������
        address_read_write_ar_tmp = address_read_write_ar;
        //�������, �� �� ����� ������ �� �� ��� ����� �����
        number_bytes_read_write_ar_tmp = 0;
        //�������, �� �������� ������ �����������
        etap_writing_df_ar = ETAP_WRITING_DF_NONE;
      
        //������� �� ������� ������ ��������� DataFlash � ����������� �� ������ ��������� DataFlash � ���� ������� ������� �������
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_AR_BIT);
      }
      else
      {
//        /*****/
//        //ҳ���� ��� �������
//        /*****/
//        for(unsigned int i = number_bytes_read_write_dr; i > 0; i--)
//          buffer_serial_DataFlash_read_write_dr[number_bytes_read_write_dr - i] = (i) & 0xff;
//        /*****/

        //��������� ������ � �������� DataFlash � ��� ����� ������ ����������
        address_read_write_dr_tmp = address_read_write_dr;
        //�������, �� �� ����� ������ �� �� ��� ����� �����
        number_bytes_read_write_dr_tmp = 0;
        //�������, �� �������� ������ �����������
        etap_writing_df_dr = ETAP_WRITING_DF_NONE;
      
        //������� �� ������� ������ ��������� DataFlash � ����������� �� ������ ��������� DataFlash � ���� ������� ������� �������
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_WRITE_SERIAL_DATAFLASH_DR_BIT);
      }
        
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR_tmp == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR_tmp == _DF_DR))
            ) 
    {
      if (AR_DR_tmp == _DF_AR)
      {
        //��������� ������ � �������� DataFlash � ��� ����� ������ �������
        address_read_write_ar_tmp = address_read_write_ar;
        //�������, �� �� ����� ������ �� �� ��� ���� ����������
        number_bytes_read_write_ar_tmp = 0;
      
        //������� �� ������� ������� ��������� DataFlash � ����������� �� ������� ��������� DataFlash � ���� ������� ������� �������
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_AR_BIT);
      }
      else
      {
        //��������� ������ � �������� DataFlash � ��� ����� ������ �������
        address_read_write_dr_tmp = address_read_write_dr;
        //�������, �� �� ����� ������ �� �� ��� ���� ����������
        number_bytes_read_write_dr_tmp = 0;
      
        //������� �� ������� ������� ��������� DataFlash � ����������� �� ������� ��������� DataFlash � ���� ������� ������� �������
        _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT);
        _SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT);
        _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SERIAL_DATAFLASH_DR_BIT);
      }
    }
    /*************************************************/
  }
  else if (state_execution_spi1 == 1)
  {
    /*************************************************/
    //���� ���������� ��� �������
    /*************************************************/

    //����������� �����������, �� I2C ������� �� ���� ���������� 
    state_execution_spi1 = -1;

    if(_CHECK_SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT) !=0)
    {
//      /***
//      ҳ���� ��� �������
//      ***/
//      if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT))
//      {
//        if (etap_eeprom_write_enable == 0)
//        {
//          if (iteration == 0) array_status[number_block_settings_write_to_eeprom_prt][0] = Temporaty_SPI1_Buffer_Rx[1 + 0];
//          iteration++;
//          
//          if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & 0x70) != 0)
//          {
//            if (Temporaty_SPI1_Buffer_Rx[1 + 0] != 0xff)
//            {
//              error_spi_eeprom++;
//            }
//            else good_spi_eeprom++;
//          }
//          else good_spi_eeprom++;
//        }
//      }
//      /**/

      //��� ���� �� ���� ������ ������, ��� ���� ��� �������� �� ���������� ������ �� ������������ ������������ ������
      if (etap_eeprom_write_enable == 0)
      {
        //��������� ������ �������

        if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & 0x70) != 0)
        {
          /*
          ���� 4-6 ���������� � "1" ����� �� ��� ����������� ������� ������� - 
          ����� ������������ ������ ������ �������
          */
          etap_eeprom_write_enable = 0;  
          if (Temporaty_SPI1_Buffer_Rx[1 + 0] != 0xff)
          {
            /*
            ϳ� ��� ����������� ������� ������ �� ��� 0-7 ������� �������, 
            ����� ������������, ����� ���� ����������.
            ���� � - �� �������, ��� ������� ����������, ������ � �� ������ ������
            �������������� "1" �� ���������� ����� ��3
            */
//            GPIO_KT3->BSRR = GPIO_KT3_Pin;
          }
          else
          {
            /*
            ϳ� ��� ����������� ������� ������ �� ��� 0-7 ������� �������, 
            ����� ������������, ����� ���� ����������.
            ���� ��� � �, �� � ������ ��������� ������ �������������� "0" �� ���������� ����� ��3
            */
//             GPIO_KT3->BRR = GPIO_KT3_Pin;
          }
        }
        else if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & (1 << 0)) == 0)
        {
          /*
          �������������� "0" �� ���������� ����� ��3 ������� ��������� ������ �
          �������� �������/�������� ������ EEPROM
          */
//          GPIO_KT3->BRR = GPIO_KT3_Pin;
          
          //������ ������ � EEPROM �� ����������
          if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & (1 << 1)) != 0)
          {
//            /***
//            ҳ���� ��� �������
//            ***/
//            if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT))
//            {
//              array_status[number_block_settings_write_to_eeprom_prt][1] = Temporaty_SPI1_Buffer_Rx[1 + 0];
//              array_status[number_block_settings_write_to_eeprom_prt][2] = iteration;
//              array_status[number_block_settings_write_to_eeprom_prt][3] = error_spi_eeprom;
//              array_status[number_block_settings_write_to_eeprom_prt][4] = good_spi_eeprom;
//              iteration = 0;
//              error_spi_eeprom = 0;
//              good_spi_eeprom = 0;
//            }
//            /**/

            //EEPROM � ��������� �� ������
            //������� �� ��������� �� ������ EEPROM
            _CLEAR_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
            etap_eeprom_write_enable = -1;
          }
          else
          {
            //EEPROM � �� ��������� �� ������ - ���������� �� ���� ������ ������� ������� ������ � EEPROM
            etap_eeprom_write_enable = 1;
          }
        }
        else
        {
          //������ �������� �������� �� ���� �������, ���� � EEPROM �� ���������� ������ ������

          /*
          �������������� "0" �� ���������� ����� ��3 ������� ��������� ������ �
          �������� �������/�������� ������ EEPROM
          */
//          GPIO_KT3->BRR = GPIO_KT3_Pin;
        }
      }
      else if (etap_eeprom_write_enable == 1)
      {
        /*
        �������������� "0" �� ���������� ����� ��3 ������� ��������� ������ �
        �������� �������/�������� ������ EEPROM
        */
//        GPIO_KT3->BRR = GPIO_KT3_Pin;
        
        //�������� ������� ������� ������ - �������� ������ ������� �������
        etap_eeprom_write_enable = 0;
        //��� ��������� �� ������ EEPROM �� �������, �� ���� ������������, �� ������ ������ ������ �����������
      }
      else
      {
        //���������� �������� ���� � �� ���� ����� �����
        //³������� ����������� �������, ���� ����� ��� �� ����������������
        while(1);
      }
    }
    else if(
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
            ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT) !=0) && (AR_DR == _DF_DR))
           )   
    {
      //��� ���� �� ���� ������ ������ ���� ������� ������� ������� EEPROM, ��� ���� ��� �������� �� ���������� ������ �� ������������ ������������ ������
      
      unsigned int *point_to_status_register_df; 
      if (AR_DR == _DF_AR) point_to_status_register_df = &status_register_df_ar;
      else point_to_status_register_df = &status_register_df_dr;
      
      *point_to_status_register_df = Temporaty_SPI1_Buffer_Rx[1 + 0];

      //��������� ������ �������
      if ((*point_to_status_register_df & (1 << 7)) != 0)
      {
        //̳�������� DataFlash �� � � ���� "BUSY"
        _CLEAR_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
      }
      else
      {
        //������ �������� �������� �� ���� �������, ���� ̳�������� DataFlash �� ������� � ���� "BUSY"
      }
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT           ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT            ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT             ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT               ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) !=0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
            )
    {
      //����� ����� ������ ����� � EEPROM

      if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT) !=0)
      {
        //����������� ��������� ���� ��������� ������ � EEPROM
        number_block_settings_prt_write_to_eeprom++;
      }
      else if(_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT) !=0)
      {
        //����������� ��������� ���� ��������� �� ������ � EEPROM
        number_block_settings_bs_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT) !=0)
      {
        //����������� ��������� ���� ��������� ������ � EEPROM
        number_block_ustuvannja_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT) != 0)
      {
        //����������� �� ����� ������-�������������� ��� ������� - ����� ����� �������� ��������� �� �������� � ��������� ���� �� ���� ��������� ������ � ��������
        number_block_state_leds_outputs_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT) != 0)
      {
        //����������� �� ����� �������� ������� ��� ������� - ����� ����� �������� ��������� �� �������� � ��������� ���� �� ���� ��������� ������ � ��������
        number_block_state_trg_func_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT) != 0)
      {
        //����������� ��������� ���� ���������� �� ����������� ������ � EEPROM
        number_block_info_rejestrator_ar_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT) != 0)
      {
        //����������� ��������� ���� ���������� �� ����������� ������ � EEPROM
        number_block_info_rejestrator_dr_write_to_eeprom++;
      }
      else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) != 0)
      {
        //����������� ��������� ���� ���������� �� ����������� ������ � EEPROM
        number_block_info_rejestrator_pr_err_write_to_eeprom++;
      }
      else
      {
        //���� �������� �� ���� � ���������� ����� ��������
        //���� ���� ����� ��������, ������� �������� ����������� �������, ���� ����� ��������� ��������, ��� ���� ���� �� ������������
        while(1);
      }

      //����������� �� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
    }
    else if(
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT             ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT           ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT            ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT               ) !=0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT    ) !=0) || 
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT    ) !=0) ||  
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)  
           )  
    {
      //��������� ������ �������
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0] & (1 << 0)) == 0)
      {
        //������ ������ � EEPROM �� ����������
        if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ��������� � ����������� �� ������� ������� ���������
          _SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ��������� � ����������� �� ������� ������� ���������
          _SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ��������� � ����������� �� ������� ������� ��������� ��
          _SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ����� ��������� ��������� � ���������� ���� � ����������� �� ������� ������� ��������� ��������� � ���������� ����
          _SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ����� �������� ������� � ����������� �� ������� ������� �������� �������
          _SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ���������� �� ����������� ���������� � ����������� �� ������� ������� ���������� �� ����������� ����������
          _SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ���������� �� ����������� ���������� � ����������� �� ������� ������� ���������� �� ����������� ����������
          _SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);
        }
        else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
        {
          //������� �� ������� ������� ���������� �� ����������� ���������� � ����������� �� ������� ������� ���������� �� ����������� ����������
          _SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
          _CLEAR_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
        }
        else
        {
          //���� �������� �� ���� � ���������� ����� ��������
          //���� ���� ����� ��������, ������� �������� ����������� �������, ���� ����� ��������� ��������, ��� ���� ���� �� ������������
          while(1);
        }
      }
      else
      {
        //������ �������� �������� �� ���� �������, ���� � EEPROM �� ���������� ������ ������
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      DDR2_B1_2_DATA static CfgTblDsc eeprom_prt_tbl_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(CfgTblDsc) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� ������������ �� � ������
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_EMPTY);
        //������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � ��������� ���������
        unsigned char crc_eeprom_settings = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&eeprom_prt_tbl_tmp); 
        for (i =0; i < sizeof(CfgTblDsc); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_settings += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(CfgTblDsc)]  == ((unsigned char)((~(unsigned int)crc_eeprom_settings) & 0xff)))
        {
          //����������� ���� ���������

          //�������� ���������� ���� (�� �����������)
          crc_settings_prt = crc_eeprom_settings;

          if ((comparison_writing & COMPARISON_WRITING_SETTINGS_PRT) == 0)
          {
            //������������ ���������� ��������� � ������� ���������
            
            //���������� ������� ��������� � ����������� ������ � ������ �������
            eeprom_prt_tbl = eeprom_prt_tbl_tmp;
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned char  *point_to_read  = (unsigned char*)(&eeprom_prt_tbl_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&eeprom_prt_tbl_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(CfgTblDsc)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //�������� ���������� ������� ������

              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
              _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_FAIL);
          state_spi1_task |= STATE_SETTINGS_PRT_EEPROM_GOOD;
          
          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT);
        }
        else
        {
          //���������� ���� �� ���������
          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_GOOD);
          state_spi1_task |= STATE_SETTINGS_PRT_EEPROM_FAIL;
 
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� ��������� � ������
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_FAIL);
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_PRT_EEPROM_GOOD);
        state_spi1_task |= STATE_SETTINGS_PRT_EEPROM_EMPTY;
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_SETTINGS_PRT_EEPROM_EMPTY_BIT);
      }

      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS_PRT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      DDR2_B1_2_DATA static AuxCfgTbl1Dsc eeprom_bs_settings_tbl_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(AuxCfgTbl1Dsc) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� ������������ �� � ������
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_EMPTY);
        //������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � ��������� ���������
        unsigned char crc_eeprom_settings_bs = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&eeprom_bs_settings_tbl_tmp); 
        for (i =0; i < sizeof(AuxCfgTbl1Dsc); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_settings_bs += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(AuxCfgTbl1Dsc)]  == ((unsigned char)((~(unsigned int)crc_eeprom_settings_bs) & 0xff)))
        {
          //����������� ���� ���������

          //�������� ���������� ���� (�� �����������)
          crc_settings_bs = crc_eeprom_settings_bs;

          if ((comparison_writing & COMPARISON_WRITING_SETTINGS_BS) == 0)
          {
            //������������ ���������� ��������� �� � ������� ��������� ��
            
            //���������� ������� ��������� �� � ����������� ������ � ������ ������� ��
            eeprom_bs_settings_tbl = eeprom_bs_settings_tbl_tmp;
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned char  *point_to_read  = (unsigned char*)(&eeprom_bs_settings_tbl_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&eeprom_bs_settings_tbl_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(AuxCfgTbl1Dsc)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //�������� ���������� ������� ������

              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
              _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_FAIL);
          state_spi1_task |= STATE_SETTINGS_BS_EEPROM_GOOD;
          
          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT);
        }
        else
        {
          //���������� ���� �� ���������
          state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_GOOD);
          state_spi1_task |= STATE_SETTINGS_BS_EEPROM_FAIL;
 
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� ��������� � ������
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_FAIL);
        state_spi1_task &= (unsigned int)(~STATE_SETTINGS_BS_EEPROM_GOOD);
        state_spi1_task |= STATE_SETTINGS_BS_EEPROM_EMPTY;
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_SETTINGS_BS_EEPROM_EMPTY_BIT);
      }

      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_SETTINGS_BS);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      unsigned int ustuvannja_tmp[NUMBER_CANALS], phi_ustuvannja_tmp[NUMBER_CANALS];
      unsigned int ustuvannja_P_tmp[3], ustuvannja_Q_tmp[3];
      
      while ((empty_block != 0) && ( i < (SIZE_USTUVANNJA + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� ������������ �� � ������
        state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_EMPTY);
        //������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � ����� ��������� � ������� �������
        unsigned char crc_eeprom_ustuvannja = 0, temp_value;
        unsigned char  *point;
        unsigned int offset = 0;

        point = (unsigned char*)(&ustuvannja_tmp); 
        for (i =0; i < sizeof(ustuvannja_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(ustuvannja_tmp);
        
        point = (unsigned char*)(&phi_ustuvannja_tmp); 
        for (i =0; i < sizeof(phi_ustuvannja_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(phi_ustuvannja_tmp);
        
        point = (unsigned char*)(&ustuvannja_P_tmp); 
        for (i =0; i < sizeof(ustuvannja_P_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(ustuvannja_P_tmp);
        
        point = (unsigned char*)(&ustuvannja_Q_tmp); 
        for (i =0; i < sizeof(ustuvannja_Q_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_ustuvannja += temp_value;
          point++;
        }
        offset +=  sizeof(ustuvannja_Q_tmp);
        
        if (Temporaty_SPI1_Buffer_Rx[3 + SIZE_USTUVANNJA]  == ((unsigned char)((~(unsigned int)crc_eeprom_ustuvannja) & 0xff)))
        {
          //����������� ���� ���������
    
          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_BIT);

          //�������� ���������� ���� (�� �����������)
          crc_ustuvannja = crc_eeprom_ustuvannja;
          
          if ((comparison_writing & COMPARISON_WRITING_USTUVANNJA) == 0)
          {
            //������������ ���������� ��������� � ����� ���������
            
            //���������� ����� ��������� � ����������� ������ � ������� �����
            for(unsigned int l = 0; l < NUMBER_CANALS; l++) 
            {
              ustuvannja[l] = ustuvannja_tmp[l];
              phi_ustuvannja[l] = phi_ustuvannja_tmp[l];
            }
            for(unsigned int l = 0; l < 3; l++) 
            {
              ustuvannja_P[l] = ustuvannja_P_tmp[l];
              ustuvannja_Q[l] = ustuvannja_Q_tmp[l];
            }
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && (i < NUMBER_CANALS))
            {
              //�������� ������ �������� �����������
              if (
                  (ustuvannja_comp[i] != ustuvannja_tmp[i]) ||
                  (phi_ustuvannja_comp[i] != phi_ustuvannja_tmp[i])
                 )
              {
                difference = 0xff;
              }
              else
              {
                i++;
              }
            }
            
            i = 0;
            while ((difference == 0) && (i < 3))
            {
              //�������� ������ �������� ����������� ��� �����������
              if (
                  (ustuvannja_P_comp[i] != ustuvannja_P_tmp[i]) ||
                  (ustuvannja_Q_comp[i] != ustuvannja_Q_tmp[i])
                 )
              {
                difference = 0xff;
              }
              else
              {
                i++;
              }
            }
            
            if (difference == 0)
            {
              //�������� ���������� ������� ������

              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
              _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_FAIL);
          state_spi1_task |= STATE_USTUVANNJA_EEPROM_GOOD;
        }
        else
        {
          //���������� ���� �� ���������
          state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_GOOD);
          state_spi1_task |= STATE_USTUVANNJA_EEPROM_FAIL;
     
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� ��������� � ������
        state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_FAIL);
        state_spi1_task &= (unsigned int)(~STATE_USTUVANNJA_EEPROM_GOOD);
        state_spi1_task |= STATE_USTUVANNJA_EEPROM_EMPTY;

        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_USTUVANNJA_EEPROM_EMPTY_BIT);
      }
            
      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_USTUVANNJA);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      unsigned char state_trigger_leds_tmp, state_signal_outputs_tmp;
      
      while ((empty_block != 0) && ( i < 4))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� �� � ������
        state_spi1_task &= (unsigned int)(~STATE_LEDS_OUTPUTS_EEPROM_EMPTY);
        
        //������� ����������� � ���� ����������, �� ���� ������
        _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT);
        
        //���������� ����������� ����� ��������� ����������
        state_trigger_leds_tmp = Temporaty_SPI1_Buffer_Rx[3 + 0];
        state_signal_outputs_tmp = Temporaty_SPI1_Buffer_Rx[3 + 2];
        
        unsigned char value_1 = Temporaty_SPI1_Buffer_Rx[3 + 1];
        if (state_trigger_leds_tmp == (unsigned char)((~(unsigned int)value_1) & 0xff))
        {
          //��������� �������

          if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) == 0)
          {
            //������������ ���������� ����� ��������� ��������������/���������� ������

            //³��������� ���������� �� ��������� ���������������
            /*state_leds = */state_trigger_leds = state_trigger_leds_tmp;
          }

          state_spi1_task &= (unsigned int)(~STATE_LEDS_EEPROM_FAIL);
          state_spi1_task |= STATE_LEDS_EEPROM_GOOD;
          
          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_EEPROM_BIT);
        }
        else
        {
          //��������� �� �������
          state_spi1_task &= (unsigned int)(~STATE_LEDS_EEPROM_GOOD);
          state_spi1_task |= STATE_LEDS_EEPROM_FAIL;
          
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_STATE_LEDS_EEPROM_BIT);
        }

        //���������� ����������� ����� ���������� ������
        value_1 = Temporaty_SPI1_Buffer_Rx[3 + 3];
        if (state_signal_outputs_tmp == (unsigned char)((~(unsigned int)value_1) & 0xff))
        {
          //��������� �������

          if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) == 0)
          {
            //������������ ���������� ����� ��������� ��������������/���������� ������

            //³��������� ���������� �� ���������� �������
            /*state_outputs = */state_signal_outputs = state_signal_outputs_tmp;
          }

          state_spi1_task &= (unsigned int)(~STATE_OUTPUTS_EEPROM_FAIL);
          state_spi1_task |= STATE_OUTPUTS_EEPROM_GOOD;
          
          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_STATE_OUTPUTS_EEPROM_BIT);
        }
        else
        {
          //��������� �� �������
          state_spi1_task &= (unsigned int)(~STATE_OUTPUTS_EEPROM_GOOD);
          state_spi1_task |= STATE_OUTPUTS_EEPROM_FAIL;
          
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_STATE_OUTPUTS_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� � ������
        state_spi1_task &= (unsigned int)(~(STATE_LEDS_EEPROM_FAIL | STATE_LEDS_EEPROM_GOOD | STATE_OUTPUTS_EEPROM_FAIL | STATE_OUTPUTS_EEPROM_GOOD));
        state_spi1_task |= STATE_LEDS_OUTPUTS_EEPROM_EMPTY;
        
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_EEPROM_BIT);
        _CLEAR_BIT(diagnostyka, ERROR_STATE_OUTPUTS_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_EMPTY_BIT);

//        if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) == 0)
//        {
//          /*
//          ����������� ����������� ��� ��, �� � EEPROM ����� �������� ��� ��������
//          ���������� ������ � ��������� �������������� ����� ���, ���� �� �������
//          �������� ��� ��� ���������� �� � ���������� ���'��, � �� ���� �� ��������� 
//          �������� ������.
//          �� ��� �������� ������ ��� ������� ����� �� ������ ���������� ���, �� � � 
//          ���������� ���'�� � ��� �����, �����, ���� ����� ������� �������, ��,
//          ������� �� �������� � ������� � ���������� ���'��,  �� � � ��� ��������,
//          �� �� �� ����� � ����������, �� �� ������ �� ���������������� ����������� ������������� 
//          ��� ������ � EEPROM �� ��� �� ��������
//          */
//          _SET_BIT(control_spi1_taskes, TASK_START_WRITE_STATE_LEDS_OUTPUTS_EEPROM_BIT);
//        }
      }
      
      if ((comparison_writing & COMPARISON_WRITING_STATE_LEDS_OUTPUTS) != 0)
      {
        //������������ �������� ����������� �������� ���������� � EEPROM � �����������
        
        if(
           ((state_spi1_task & STATE_LEDS_EEPROM_GOOD   ) != 0) &&
           ((state_spi1_task & STATE_OUTPUTS_EEPROM_GOOD) != 0)
          )
        {
          //�������� ������ ��������� ����� ���, ���� ���� ���� ������� �� � ������ � ������� �� �����������
          
          if (
              (state_trigger_leds_comp   == state_trigger_leds_tmp   ) &&
              (state_signal_outputs_comp == state_signal_outputs_tmp )
             )   
          {
            //�������� ���������� ������� ������

            //������� ����������� � ���� ����������
            _CLEAR_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT);
          }
          else
          {
            //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

            //���������� ����������� � ���� ����������
            _SET_BIT(diagnostyka, ERROR_STATE_LEDS_OUTPUTS_EEPROM_COMPARISON_BIT);
          }
        }
      }

      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_STATE_LEDS_OUTPUTS);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ��������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      unsigned int trigger_active_functions_tmp[N_TMP];
      
      while ((empty_block != 0) && ( i < sizeof(trigger_active_functions_tmp) + 1))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� �� � ������
        state_spi1_task &= (unsigned int)(~STATE_TRG_FUNC_EEPROM_EMPTY);
        
        //������� ����������� � ���� ����������, �� ���� ������
        _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � �������� ����
        unsigned char crc_eeprom_trg_func = 0, temp_value;
        unsigned char  *point;
        unsigned int offset = 0;

        point = (unsigned char*)(&trigger_active_functions_tmp); 
        for (i =0; i < sizeof(trigger_active_functions_tmp); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + offset + i];
          *(point) = temp_value;
          crc_eeprom_trg_func += temp_value;
          point++;
        }
        offset +=  sizeof(trigger_active_functions_tmp);
        
        if (Temporaty_SPI1_Buffer_Rx[3 + offset]  == ((unsigned char)((~(unsigned int)crc_eeprom_trg_func) & 0xff)))
        {
          //��������� �������

          if ((comparison_writing & COMPARISON_WRITING_TRG_FUNC) == 0)
          {
            //������������ ���������� ����� �������� �������

            //���������� ������� ���������� � ������ ����
            for(unsigned int k = 0; k < N_TMP; k++) trigger_active_functions[k] = trigger_active_functions_tmp[k];
//            restore_trigger_functions(trigger_active_functions);
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned int difference = 0;
  
            i = 0;
            while ((difference == 0) && (i < N_TMP))
            {
              //�������� ������ ������� �������� ���� ���������� � ��������������� ���'��
              if (trigger_active_functions_comp[i] != trigger_active_functions_tmp[i]) difference = 0xff;
              else
              {
                i++;
              }
            }
            
            if (difference == 0)
            {
              //�������� ���������� ������� ������
  
              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
              _SET_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_COMPARISON_BIT);
            }
          }

          state_spi1_task &= (unsigned int)(~STATE_TRG_FUNC_EEPROM_FAIL);
          state_spi1_task |= STATE_TRG_FUNC_EEPROM_GOOD;
          
          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_BIT);
        }
        else
        {
          //��������� �� �������
          state_spi1_task &= (unsigned int)(~STATE_TRG_FUNC_EEPROM_GOOD);
          state_spi1_task |= STATE_TRG_FUNC_EEPROM_FAIL;
          
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� � ������
        state_spi1_task &= (unsigned int)(~(STATE_TRG_FUNC_EEPROM_FAIL | STATE_TRG_FUNC_EEPROM_GOOD));
        state_spi1_task |= STATE_TRG_FUNC_EEPROM_EMPTY;
        
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_TRG_FUNC_EEPROM_EMPTY_BIT);
      }

      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_TRG_FUNC);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      __TEMP_STRUCTURE EepromARecDesc_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(__TEMP_STRUCTURE) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� �� � ������
        state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY);
        //������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � ���������
        unsigned char crc_eeprom_info_rejestrator_ar = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&EepromARecDesc_tmp); 
        for (i =0; i < sizeof(__TEMP_STRUCTURE); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_info_rejestrator_ar += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(__TEMP_STRUCTURE)]  == ((unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_ar) & 0xff)))
        {
          //����������� ���� ���������

          //�������� ���������� ���� (�� �����������)
          crc_info_rejestrator_ar = crc_eeprom_info_rejestrator_ar;

          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL);
          state_spi1_task |= STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD;

          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT);

          if ((comparison_writing & COMPARISON_WRITING_INFO_REJESTRATOR_AR) == 0)
          {
            //������������ ���������� ���������� �� ����������� ���������� � ������ ���������
            
            //���������� ���������� �� ����������� ���������� � ��������� ��������� � ������ ���������
            EepromARecDesc = EepromARecDesc_tmp;
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned char  *point_to_read  = (unsigned char*)(&EepromARecDesc_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&EepromARecDesc_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(__TEMP_STRUCTURE)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //�������� ���������� ������� ������

              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
              _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_COMPARISON_BIT);
            }
          }
        }
        else
        {
          //���������� ���� �� ���������
          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD);
          state_spi1_task |= STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL;
          
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� � ������
        state_spi1_task &= (unsigned int)(~(STATE_INFO_REJESTRATOR_AR_EEPROM_FAIL | STATE_INFO_REJESTRATOR_AR_EEPROM_GOOD));
        state_spi1_task |= STATE_INFO_REJESTRATOR_AR_EEPROM_EMPTY;
        
        
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_AR_EEPROM_EMPTY_BIT);
      }
     
      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_AR);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      __TEMP_STRUCTURE EepromDRecDesc_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(__TEMP_STRUCTURE) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� �� � ������
        state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY);
        //������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � ���������
        unsigned char crc_eeprom_info_rejestrator_dr = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&EepromDRecDesc_tmp); 
        for (i =0; i < sizeof(__TEMP_STRUCTURE); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_info_rejestrator_dr += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(__TEMP_STRUCTURE)]  == ((unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_dr) & 0xff)))
        {
          //����������� ���� ���������

          //�������� ���������� ���� (�� �����������)
          crc_info_rejestrator_dr = crc_eeprom_info_rejestrator_dr;

          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL);
          state_spi1_task |= STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD;

          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT);

          if ((comparison_writing & COMPARISON_WRITING_INFO_REJESTRATOR_DR) == 0)
          {
            //������������ ���������� ���������� �� ����������� ���������� � ������ ���������
            
            //���������� ���������� �� ����������� ���������� � ��������� ��������� � ������ ���������
            EepromDRecDesc = EepromDRecDesc_tmp;
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned char  *point_to_read  = (unsigned char*)(&EepromDRecDesc_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&EepromDRecDesc_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(__TEMP_STRUCTURE)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //�������� ���������� ������� ������

              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
             _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_COMPARISON_BIT);
            }
          }
        }
        else
        {
          //���������� ���� �� ���������
          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD);
          state_spi1_task |= STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL;
          
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� � ������
        state_spi1_task &= (unsigned int)(~(STATE_INFO_REJESTRATOR_DR_EEPROM_FAIL | STATE_INFO_REJESTRATOR_DR_EEPROM_GOOD));
        state_spi1_task |= STATE_INFO_REJESTRATOR_DR_EEPROM_EMPTY;
        
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_DR_EEPROM_EMPTY_BIT);
      }
      
      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_DR);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      
      //�������� �������� ���
      //�������� ��������, �� ���������� ���� � ������, �� ��� ���������� ���������
      unsigned int empty_block = 1, i = 0; 
      __TEMP_STRUCTURE EepromErrRecDesc_tmp;
      
      while ((empty_block != 0) && ( i < (sizeof(__TEMP_STRUCTURE) + 1)))
      {
        if (Temporaty_SPI1_Buffer_Rx[3 + i] != 0xff) empty_block = 0;
        i++;
      }
      
      if(empty_block == 0)
      {
        //�������, �� ���� �� � ������
        state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY);
        //������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT);
        
        //���������� ���������� ���� � ���������� �������� ��� � ���������
        unsigned char crc_eeprom_info_rejestrator_pr_err = 0, temp_value;
        unsigned char  *point = (unsigned char*)(&EepromErrRecDesc_tmp); 
        for (i =0; i < sizeof(__TEMP_STRUCTURE); i++)
        {
          temp_value = Temporaty_SPI1_Buffer_Rx[3 + i];
          *(point) = temp_value;
          crc_eeprom_info_rejestrator_pr_err += temp_value;
          point++;
        }
        if (Temporaty_SPI1_Buffer_Rx[3 + sizeof(__TEMP_STRUCTURE)]  == ((unsigned char)((~(unsigned int)crc_eeprom_info_rejestrator_pr_err) & 0xff)))
        {
          //����������� ���� ���������

          //�������� ���������� ���� (�� �����������)
          crc_info_rejestrator_pr_err = crc_eeprom_info_rejestrator_pr_err;

          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL);
          state_spi1_task |= STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD;

          //������� ����������� � ���� ����������
          _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);

          if ((comparison_writing & COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR) == 0)
          {
            //������������ ���������� ���������� �� ���������� ���������� ���� � ������ ���������
            
            //���������� ���������� �� ���������� ���������� ���� � ��������� ��������� � ������ ���������
            EepromErrRecDesc = EepromErrRecDesc_tmp;
          }
          else
          {
            //������������ �������� ����������� �������� ���������� � EEPROM � �����������
            
            unsigned char  *point_to_read  = (unsigned char*)(&EepromErrRecDesc_tmp );
            unsigned char  *point_to_write = (unsigned char*)(&EepromErrRecDesc_comp);
            unsigned int difference = 0;

            i = 0;
            while ((difference == 0) && ( i < sizeof(__TEMP_STRUCTURE)))
            {
              if (*point_to_write != *point_to_read) difference = 0xff;
              else
              {
                point_to_write++;
                point_to_read++;
                i++;
              }
            }
            if (difference == 0)
            {
              //�������� ���������� ������� ������

              //������� ����������� � ���� ����������
              _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT);
            }
            else
            {
              //�������� ���������� ���������� ��������� �� ��������� � ����������� �����������

              //���������� ����������� � ���� ����������
              _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_COMPARISON_BIT);
            }
          }
        }
        else
        {
          //���������� ���� �� ���������
          state_spi1_task &= (unsigned int)(~STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD);
          state_spi1_task |= STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL;
          
          //���������� ����������� � ���� ����������
          _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
        }
      }
      else
      {
        //�������, �� ���������� ���� � ������
        state_spi1_task &= (unsigned int)(~(STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_FAIL | STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_GOOD));
        state_spi1_task |= STATE_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY;
        
        //���������� ����������� � ���� ����������
        _CLEAR_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
        _SET_BIT(diagnostyka, ERROR_INFO_REJESTRATOR_PR_ERR_EEPROM_EMPTY_BIT);
      }

      //������ ������� �����������, �� ������������ ����������
      comparison_writing &= (unsigned int)(~COMPARISON_WRITING_INFO_REJESTRATOR_PR_ERR);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_RTC_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_RTC_BIT);
      
      //�������� �������� ���
      if (
          ((Temporaty_SPI1_Buffer_Rx[1 + 0xA ] & (1<< 6)) == 0 ) /*SQWE = 0*/ ||
          ((Temporaty_SPI1_Buffer_Rx[1 + 0xC ] & (1<< 6)) != 0 ) /*HT  = 1 */ ||
          ((Temporaty_SPI1_Buffer_Rx[1 + 0x13]          ) != 0xf0) /*������� �������*/ 
         )
      {
        //����� ������ ���  � ����� ��������� � ������ ��������, ��� �� ����� �������� 1��
        temp_register_rtc[0] = Temporaty_SPI1_Buffer_Rx[1 + 0xC ] & (unsigned char)(~ (1<< 6));
        temp_register_rtc[1] = Temporaty_SPI1_Buffer_Rx[1 + 0xA ] | (1<< 6);

        //����������� ��� �� ����������� �����������, ���� �� ��� �����-�� ����� ����������
        if((state_spi1_task & STATE_FIRST_READING_RTC) == 0 ) _SET_BIT(diagnostyka, RTC_WORK_FIELD_NOT_SET_BIT);
        else _CLEAR_BIT(diagnostyka, RTC_WORK_FIELD_NOT_SET_BIT);
        
        etap_settings_test_frequency = 0;
        _SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT);
      } 
      else
        _CLEAR_BIT(diagnostyka, RTC_WORK_FIELD_NOT_SET_BIT);
      
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0x1] &  (1<< 7)) != 0) /*ST = 1 */
      {
        //����� ���������� ��������� ��� RTC
        _SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT);
      }
      else if ((etap_reset_of_bit < ETAP_CLEAR_OF_ST_STOP) && ((Temporaty_SPI1_Buffer_Rx[1 + 0xf] & (1<<2)) != 0))
      {
        _SET_BIT(diagnostyka, RTC_OSCILLATOR_FAIL_BIT);
        //����� ST-�� ��������� � 1 � ������� ������� ���� � 0. �������� ����� 5 ������ �� �� ���������
        if((state_spi1_task & STATE_FIRST_READING_RTC) == 0 )
        {
          etap_reset_of_bit = ETAP_CLEAR_OF_ST_STOP;
          _SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
        }
        else
          etap_reset_of_bit = ETAP_CLEAR_OF_ST_START_WAITING_5S;
      }
      else if (etap_reset_of_bit == ETAP_CLEAR_OF_WRITE_OF_0)
      {
        //����� �������� OF-��
        temp_value_for_rtc = Temporaty_SPI1_Buffer_Rx[1 + 0xf];
        _SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
      }
      
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0xC] & (1<< 6)) != 0) /*������������ HT-��*/
      {
        //����������� ��� �� ����������� �����������, ���� �� ��� �����-�� ����� ����������
        if((state_spi1_task & STATE_FIRST_READING_RTC) == 0 ) _SET_BIT(diagnostyka, RTC_UPDATING_HALTED_BIT);
        else _CLEAR_BIT(diagnostyka, RTC_UPDATING_HALTED_BIT);
      }
      else _CLEAR_BIT(diagnostyka, RTC_UPDATING_HALTED_BIT);
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0x1] &  (1<< 7)) != 0) _SET_BIT(diagnostyka, RTC_OSCILLATOR_STOPED_BIT);
      else _CLEAR_BIT(diagnostyka, RTC_OSCILLATOR_STOPED_BIT);
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0xF] &  (1<< 4)) != 0) _SET_BIT(diagnostyka, RTC_BATTERY_LOW_BIT);
      else _CLEAR_BIT(diagnostyka, RTC_BATTERY_LOW_BIT);
      if ((Temporaty_SPI1_Buffer_Rx[1 + 0xF] &  (1<< 2)) == 0) _CLEAR_BIT(diagnostyka, RTC_OSCILLATOR_FAIL_BIT);

      if((state_spi1_task & STATE_FIRST_READING_RTC) !=0)
      {
        //����� ���������� ����� ���������� ����� � RTC - ������� �� ������� �������
        state_spi1_task &= (unsigned int)(~STATE_FIRST_READING_RTC);
      }

      //���������� ���
      copying_time = 1; //�������, �� ����� ���������� ����� ����
      rtc_time[0] = Temporaty_SPI1_Buffer_Rx[1 + 0] & 0xff;
      rtc_time[1] = Temporaty_SPI1_Buffer_Rx[1 + 1] & 0x7f;
      rtc_time[2] = Temporaty_SPI1_Buffer_Rx[1 + 2] & 0x7f;
      rtc_time[3] = Temporaty_SPI1_Buffer_Rx[1 + 3] & 0x3f;

      rtc_time[4] = Temporaty_SPI1_Buffer_Rx[1 + 4] & 0x07;
      if ((rtc_time[4] & 0x07) == 0) rtc_time[4] = (rtc_time[4] & 0x80) | 0x1;

      rtc_time[5] = Temporaty_SPI1_Buffer_Rx[1 + 5] & 0x3f;
      rtc_time[6] = Temporaty_SPI1_Buffer_Rx[1 + 6] & 0x1f;
      rtc_time[7] = Temporaty_SPI1_Buffer_Rx[1 + 7] & 0xff;
      copy_register8_RTC = Temporaty_SPI1_Buffer_Rx[1 + 8];
      rtc_calibration = copy_register8_RTC & 0x3f;


      copying_time = 0; //�������, �� ���������� ����� ���� ���������
      
      //������ ���� ������ ���� ��� ����, ��� ���� �������� ����� ���� ����������� ����� ���� ����� ������� ����� ��������, ��� ��������� �������� ���� � ���� � ����� ������
      for(unsigned int i = 0; i < 8; i++) rtc_time_copy[i] = rtc_time[i];
      rtc_calibration_copy = rtc_calibration;
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT) !=0)
    {
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT) !=0)
    {
      etap_settings_test_frequency++;
      if (etap_settings_test_frequency > 2)
      {
        //������� �� ����������� ��� � ���� � ������ ��������, ���� �� ���� �������
        _CLEAR_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT);
        //�������� ��������� ������� ������� RTC
        _SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);
        etap_settings_test_frequency = -1;
      }
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT) !=0)
    {
      //������� �� ������� ���������� RTC
      _CLEAR_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT) !=0)
    {
      etap_reset_of_bit++;
      if (etap_reset_of_bit == ETAP_CLEAR_OF_ST_START_WAITING_5S)
      {
        //������� ������� �������� ������������  �������� OF-���, ��� �� ���� ��������� 5� ��� ����������� �������� OF-���
        _CLEAR_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
      }
      else if (etap_reset_of_bit >= ETAP_CLEAR_OF_WRITE_OF_0)
      {
        //������� ������� �������� �������� OF-���
        etap_reset_of_bit = ETAP_CLEAR_OF_NONE;
        _CLEAR_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT);
      }
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT) !=0)
//    {
//      //���������� ������ �������� ��������� DataFlash �� ����� ������� � 256 ����
//
//      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
//      _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_BIT);
//
//      //������� �� ������� �������� ��������� DataFlash �� ����� ������� � 256 ����
//      _CLEAR_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //���������� ������ �������� ��������� DataFlash

      /*
      �� ����������� �� ���������� ������� ������� - ��� ��������� � ������ 
      ����� �������� (�� � ���������� DataFlash). � ����� ����� ��������� ������ � 
      ���������� DataFlash ������ ���� ���������� ������� ������� �������
      */
//      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));

      //������� �� �������� ��������� DataFlash
      _CLEAR_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_ERASING_DATAFLASH_AR_BIT : TASK_ERASING_DATAFLASH_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //���������� ���� ������� ������ ����������, �������� ������  number_bytes_read_write_tmp, � ��������� DataFlash
               int *point_to_etap_writing_df;
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_address_read_write_tmp;
      
      if (AR_DR == _DF_AR)
      {
        point_to_etap_writing_df = &etap_writing_df_ar;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;
        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
      }
      else
      {
        point_to_etap_writing_df = &etap_writing_df_dr;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;
        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
      }
      
      if (
          (*point_to_etap_writing_df == ETAP_WRITING_DF_MAIN_MEMORY_PROGRAM_THROUGH_BUFFER              ) ||
          (*point_to_etap_writing_df == ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE)
         ) 
      {
        //����������� �������� ������ ������ ���������� � ���'��� ��������� DataFlash

        //�������� ������ � ���, �������, ����� ���� ���������� �������
        *point_to_address_read_write_tmp += *point_to_number_bytes_read_write_tmp;
        
        //�������. �� ����� ���������� ���� ������ ���������� ��� ������
        *point_to_etap_writing_df = ETAP_WRITING_DF_NONE;
      }
      else if (
               (*point_to_etap_writing_df == ETAP_WRITING_DF_NONE                                           ) ||
               (*point_to_etap_writing_df >  ETAP_WRITING_DF_BUFFER_TO_MAIN_MEMORY_PROGRAM_WITH_BUIT_IN_ERASE)  
              )   
      {
        //³������� ����������� �������, ���� ����� ��� �� ����������������
        while(1);
      }
      else
      {
        //���������� �� ��������� ���� ������ ������ ���������� �������� ������  number_bytes_read_write_tmp
        (*point_to_etap_writing_df)++;
      }

      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      unsigned int size_biffer;
      unsigned int *point_to_number_bytes_read_write_tmp;
      unsigned int *point_to_address_read_write_tmp;
      unsigned int *point_to_address_read_write;
      unsigned int *buffer_serial_DataFlash_read_write;
      
      //���������� ������ ������� ����������, �������� ����������  point_to_number_bytes_read_write_tmp, � ��������� DataFlash
      if (AR_DR == _DF_AR)
      {
        size_biffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_AR;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_ar_tmp;

        point_to_address_read_write_tmp = &address_read_write_ar_tmp;
        point_to_address_read_write = &address_read_write_ar;
        
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_ar;
      }
      else
      {
        size_biffer = SIZE_BUFFER_SERIAL_DATAFLASH_READ_WRITE_DR;
        point_to_number_bytes_read_write_tmp = &number_bytes_read_write_dr_tmp;

        point_to_address_read_write_tmp = &address_read_write_dr_tmp;
        point_to_address_read_write = &address_read_write_dr;
        
        buffer_serial_DataFlash_read_write = buffer_serial_DataFlash_read_write_dr;
      }
      
      //������� �������� ����������
      unsigned int base_index = (*point_to_address_read_write_tmp - *point_to_address_read_write);
      if ((base_index + *point_to_number_bytes_read_write_tmp) > size_biffer)
      {
        //³������� ����������� �������, ���� ����� ��� �� ����������������
        while(1);
      }
      for(unsigned int i = 0; i < *point_to_number_bytes_read_write_tmp; i++)
        buffer_serial_DataFlash_read_write[base_index + i] = Temporaty_SPI1_Buffer_Rx[5 + i];
      
      //�������� ������ � ���, �������, ����� ���� ���������� �������
      *point_to_address_read_write_tmp += *point_to_number_bytes_read_write_tmp;

      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else
    {
      //����, ����������, ����� �� ���� � ����
      //� ��� ������� �������� ����� �� ������
    }
    /*************************************************/
  }
  else if (state_execution_spi1 == 2)
  {
    /*************************************************/
    //���� ���������� � ��������
    /*************************************************/

    //����������� �����������, �� I2C ������� �� ���� ���������� 
    state_execution_spi1 = -1;

    //����������� � ���������� ����
    if(_CHECK_SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT) != 0)
    {
      //���������� �� ������� ���� ���������
      etap_eeprom_write_enable = -1;
    }
    else if(
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_AR_BIT) != 0) ||
            (_CHECK_SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_DR_BIT) != 0)
           )   
    {
      //�������� ������ ������� ��������� DataFlash 
      
      //�������� ������ ������ ������� ��������� DataFlash  
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_PRT_EEPROM_BIT           ) != 0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SETTINGS_BS_EEPROM_BIT            ) != 0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_USTUVANNJA_EEPROM_BIT             ) != 0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_STATE_LEDS_OUTPUTS_EEPROM_BIT     ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_TRG_FUNC_EEPROM_BIT               ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_AR_EEPROM_BIT    ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_DR_EEPROM_BIT    ) != 0) || 
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) != 0)
            )
    {
      //����� ����� ������ ����� � EEPROM
      //�������� ����� ����� ��� ������ � EEPROM ��� �����, �� ���� ������������, �� �� ���������
      //����������� �� ������������ ������� �� �����
      _SET_BIT(control_spi1_taskes, TASK_EEPROM_WRITE_PREPARATION_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM ���������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_PRT_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_PRT_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM ��������� ��
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_SETTINGS_BS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_SETTINGS_BS_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM ���������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_USTUVANNJA_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_USTUVANNJA_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM ����� ��������� �������������� � ���������� ������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_STATE_LEDS_OUTPUTS_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_STATE_LEDS_OUTPUTS_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM ����� �������� �������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_TRG_FUNC_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_TRG_FUNC_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM �� ����������� ���������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_AR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_AR_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM �� ����������� ���������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_DR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_DR_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT) !=0)
    {
      //����� ����� ������� ����� � EEPROM �� ��������� ��������������
      
      //�������� ��������� ������ �������
      _SET_BIT(control_spi1_taskes, TASK_START_READ_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_INFO_REJESTRATOR_PR_ERR_EEPROM_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_RTC_BIT) !=0)
    {
      //����� ����� ������� RTC
      
      //�������� ��������� ������ ������� RTC
      _SET_BIT(control_spi1_taskes, TASK_START_READ_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_READING_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT) !=0)
    {
      //����� ����� ������ ����-���� � RTC
      
      //�������� ��������� ������ ������ RTC
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_RTC_BIT);
    }
    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT) !=0)
    {
      //����� ����� ������ ��������� RTC
      
      //�������� ��������� ������ ������ RTC
      _SET_BIT(control_spi1_taskes, TASK_START_WRITE_CALIBR_RTC_BIT);
      _CLEAR_BIT(control_spi1_taskes, TASK_WRITING_CALIBR_RTC_BIT);
    }
    else if (
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_OF_RTC_BIT          ) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_SET_START_SETTINGS_RTC_BIT) !=0) ||
             (_CHECK_SET_BIT(control_spi1_taskes, TASK_RESET_ST_RTC_BIT) !=0     )
            )
    {
      //����� ����� �������� ���������������� ���� RTC 
      
      //�������� ��������� ���������������� ���� RTC � ���� ������ ����, ���� �� ������
    }
//    else if (_CHECK_SET_BIT(control_spi1_taskes, TASK_MAKING_PAGE_SIZE_256_BIT) !=0)
//    {
//      //���������� ������ �������� ��������� DataFlash �� ����� ������� � 256 ����
//
//      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
//      _SET_BIT(control_spi1_taskes, TASK_READ_SR_DF_BIT);
//    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_ERASING_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //���������� ������ �������� ��������� DataFlash

      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_WRITING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //���������� ������ ����� ���������� � ��������� DataFlash
      int *point_to_etap_writing_df;
      
      if (AR_DR == _DF_AR)
      {
        point_to_etap_writing_df = &etap_writing_df_ar;
      }
      else
      {
        point_to_etap_writing_df = &etap_writing_df_dr;
      }
      
      //���������� ���� ������ ������ ���������� (�������� ������  number_bytes_read_write_tmp) � ���������� ����
      *point_to_etap_writing_df = ETAP_WRITING_DF_NONE;
      
      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else if (
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_AR_BIT) !=0) && (AR_DR == _DF_AR)) ||
             ((_CHECK_SET_BIT(control_spi1_taskes, TASK_READING_SERIAL_DATAFLASH_DR_BIT) !=0) && (AR_DR == _DF_DR))
            ) 
    {
      //���������� ������ ������� ���������� � ��������� DataFlash
      
      //����������� �� ���������� ������� ������� ������� ��������� DataFlash
      _SET_BIT(control_spi1_taskes, ((AR_DR == _DF_AR) ? TASK_READ_SR_DF_AR_BIT : TASK_READ_SR_DF_DR_BIT));
    }
    else
    {
      //� ��� ������� �������� ����� �� ������
    }
    /*************************************************/
  }
}
/*****************************************************/

