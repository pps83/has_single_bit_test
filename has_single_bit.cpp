#include "has_single_bit.h"
#include <bit>

bool has_single_bit_std(uint16_t _Val)
{
    return std::has_single_bit(_Val);
}

bool has_single_bit_old(uint16_t _Val)
{
    return _Val != 0 && (_Val & (_Val - 1)) == 0;
}

bool has_single_bit_new(uint16_t _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}

bool has_single_bit_std(uint32_t _Val)
{
    return std::has_single_bit(_Val);
}

bool has_single_bit_old(uint32_t _Val)
{
    return _Val != 0 && (_Val & (_Val - 1)) == 0;
}

bool has_single_bit_new(uint32_t _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}

bool has_single_bit_std(uint64_t _Val)
{
    return std::has_single_bit(_Val);
}

bool has_single_bit_old(uint64_t _Val)
{
    return _Val != 0 && (_Val & (_Val - 1)) == 0;
}

bool has_single_bit_new(uint64_t _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}
