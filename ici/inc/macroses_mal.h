#ifndef __MACROSES_MAL_H
#define __MACROSES_MAL_H

#define __DESELECT_ALL_ADC                              \
{                                                       \
    GPIO->p0_outp_clr = GPO_1 | GPO_2 | GPO_3 | GPO_4;  \
}

#define __SELECT_ADC_1                                  \
{                                                       \
    GPIO->p3_outp_clr =                         GPO_4;  \
    GPIO->p3_outp_set = GPO_1 ;                         \
}

#define __SELECT_ADC_2                                  \
{                                                       \
    GPIO->p3_outp_set =         GPO_2         | GPO_4;  \
}

#define __SELECT_ADC_3                                  \
{                                                       \
    GPIO->p3_outp_set =                 GPO_3 ;         \
}

#define __SELECT_ADC_4                                  \
{                                                       \
    GPIO->p3_outp_clr =                 GPO_3 ;         \
}

#define _SET_STATE(_output, _output_bit) _output |= (1 << _output_bit)

#define _CLEAR_STATE(_output, _output_bit) _output &= (unsigned int)(~(1 << _output_bit))

#define _GET_OUTPUT_STATE(_input, _input_bit) ((_input & ((unsigned int)(1 << _input_bit))) != 0)

#endif
