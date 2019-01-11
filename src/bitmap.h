#ifndef BITMAP_H
#define BITMAP_H

// 64 bit number to be used in the bitmap representation of the board.
typedef unsigned long long bitmap;

// Macro to append appropriate suffix to unsigned 64-bit constants
#define C64(x) x##ULL
#define U64FULL C64(0xFFFFFFFFFFFFFFFF)


#endif
