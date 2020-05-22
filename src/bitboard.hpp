#ifndef bitboard_H
#define bitboard_H

#include <cstdint>
#include <strings.h>

// 64 bit number to be used in the bitboard representation of the board.
typedef std::uint64_t bitboard;

// Define a way to determine the Least Significant Bit
int lsb(bitboard x);

#define popcount(x) (__builtin_popcountll(x))

#define lsb(x) (__builtin_ffsll(x) - 1)

#define lsb_unsafe(x) (__builtin_ctzll(x))

#endif
