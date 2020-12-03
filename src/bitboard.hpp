#ifndef SRC_BITBOARD_HPP_
#define SRC_BITBOARD_HPP_

#include <cstdint>

// 64 bit number to be used in the bitboard representation of the board.
typedef std::uint64_t bitboard;

// Define a way to determine the Least Significant Bit
int lsb(bitboard x);

const bitboard one = static_cast<bitboard>(1);

#define popcount(x) (__builtin_popcountll(x))

#define lsb(x) (__builtin_ffsll(x) - 1)

#define lsb_unsafe(x) (__builtin_ctzll(x))

#endif  // SRC_BITBOARD_HPP_
