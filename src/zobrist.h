#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include "bitboard.h"
#include <stdlib.h>
#include <array>
#include <random>

class Zobrist {

    public:
        std::array<std::array<bitboard, 12>, 64> zobrist_piece_rands;
        bitboard zobrist_black_move;
        std::array<bitboard, 16> zobrist_castling_rights;
        std::array<bitboard, 8> zobrist_passant_file;

        Zobrist(void);
};

// A Mersenne Twister pseudo-random generator of 64-bit numbers 
typedef std::mersenne_twister_engine<uint_fast64_t,
        64,312,156,31,0xb5026f5aa96619e9,
        29,0x5555555555555555,
        17,0x71d67fffeda60000,
        37,0xfff7eee000000000,
        43,6364136223846793005> mt19937_64;

#endif
