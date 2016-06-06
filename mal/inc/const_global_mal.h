#ifndef CONST_GLOBAL_MAL
#define CONST_GLOBAL_MAL

#define FLAG_SIGNED_FATA        (1 << 0)

#define NUMBER_CANALS_ADC1              3
#define NUMBER_CANALS_ADC2              4
#define NUMBER_CANALS_ADC3              3
#define NUMBER_CANALS_SPI1              (NUMBER_CANALS_ADC1 + NUMBER_CANALS_ADC2)
#define NUMBER_CANALS_SPI2              (NUMBER_CANALS_ADC3)
#define NUMBER_CANALS                   (NUMBER_CANALS_SPI1 + NUMBER_CANALS_SPI2)


#endif
