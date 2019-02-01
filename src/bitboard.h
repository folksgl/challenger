#ifndef bitboard_H
#define bitboard_H

#include <cstdint>

// 64 bit number to be used in the bitboard representation of the board.
typedef uint64_t bitboard;

// Macro to append appropriate suffix to unsigned 64-bit constants
#define C64(x) x##ULL
#define U64FULL C64(0xFFFFFFFFFFFFFFFF)


#endif
