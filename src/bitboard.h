#ifndef bitboard_H
#define bitboard_H

#include <cstdint>

// 64 bit number to be used in the bitboard representation of the board.
typedef uint64_t bitboard;

#endif

// Define a way to determine the Least Significant Bit
#define lsb(x) (__builtin_ffsll((x)) - 1)
