#include "has_single_bit.h"
#include <bit>

#if !HAS_SINGLE_BIT_INLINE
bool has_single_bit_std(uint16_t _Val)
{
    return std::has_single_bit(_Val);
}

bool has_single_bit_new(uint16_t _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}

bool has_single_bit_popcount(uint16_t _Val)
{
    return 1 == std::_Unchecked_popcount(_Val);
}

bool has_single_bit_std(uint32_t _Val)
{
    return std::has_single_bit(_Val);
}

bool has_single_bit_new(uint32_t _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}

bool has_single_bit_popcount(uint32_t _Val)
{
    return 1 == std::_Unchecked_popcount(_Val);
}

bool has_single_bit_std(uint64_t _Val)
{
    return std::has_single_bit(_Val);
}

bool has_single_bit_new(uint64_t _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}

bool has_single_bit_popcount(uint64_t _Val)
{
    return 1 == std::_Unchecked_popcount(_Val);
}
#endif //!HAS_SINGLE_BIT_INLINE
