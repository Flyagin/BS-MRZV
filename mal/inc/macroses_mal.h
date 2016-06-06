#ifndef __MACROSES_MAL__
#define __MACROSES_MAL__

#define _CHECK_SET_BIT(_array, _number_bit)                                     \
    (_array[_number_bit >> 5] & ( (unsigned int)( 1 << (_number_bit & 0x1f)) ) )                           

#define _SET_BIT(_array, _number_bit)                                           \
      _array[_number_bit >> 5] |= (unsigned int)(1 << (_number_bit & 0x1f))

#define _CLEAR_BIT(_array, _number_bit)                                         \
      _array[_number_bit >> 5] &= (unsigned int)(~(1 << (_number_bit & 0x1f)))
        
#endif

