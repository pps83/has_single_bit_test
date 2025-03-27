#pragma once
#ifndef HAS_SINGLE_BIT_H_
#define HAS_SINGLE_BIT_H_

#define HAS_SINGLE_BIT_INLINE 0

#include <stdint.h>

#if !HAS_SINGLE_BIT_INLINE
bool has_single_bit_std(uint16_t _Val);
bool has_single_bit_old(uint16_t _Val);
bool has_single_bit_new(uint16_t _Val);
bool has_single_bit_std(uint32_t _Val);
bool has_single_bit_old(uint32_t _Val);
bool has_single_bit_new(uint32_t _Val);
bool has_single_bit_std(uint64_t _Val);
bool has_single_bit_old(uint64_t _Val);
bool has_single_bit_new(uint64_t _Val);
#else
#include <bit>
template<typename T>
inline bool has_single_bit_std(T _Val)
{
    return std::has_single_bit(_Val);
}

template<typename T>
inline bool has_single_bit_old(T _Val)
{
    return _Val != 0 && (_Val & (_Val - 1)) == 0;
}

template<typename T>
inline bool has_single_bit_new(T _Val)
{
    return (_Val ^ (_Val - 1)) > _Val - 1;
}
#endif // HAS_SINGLE_BIT_INLINE
#endif // HAS_SINGLE_BIT_H_
