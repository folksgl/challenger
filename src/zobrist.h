#ifndef TRANSPOSITION_H
#define TRANSPOSITION_H

#include <stdlib.h>
#include <array>
#include <random>
#include "position.h"

enum z_piece_names { z_w_pawn, z_w_rook, z_w_knight, z_w_bishop, z_w_queen, z_w_king,  
                     z_b_pawn, z_b_rook, z_b_knight, z_b_bishop, z_b_queen, z_b_king, };

enum zp_piece_to_name { zp_w_pawn = 0, zp_w_rook = 1, zp_w_knight = 2, zp_w_bishop = 3, zp_w_queen = 4, zp_w_king = 5,  
                        zp_b_pawn = 6, zp_b_rook = 7, zp_b_knight = 8, zp_b_bishop = 9, zp_b_queen = 10, zp_b_king = 11 };

const std::unordered_map<bitboard, int> zp_passant {
    {0x0000000000010000, 0},  {0x0000000000020000, 1},
    {0x0000000000040000, 2},  {0x0000000000080000, 3},
    {0x0000000000100000, 4},  {0x0000000000200000, 5},
    {0x0000000000400000, 6},  {0x0000000000800000, 7},

    {0x0000010000000000, 8},  {0x0000020000000000, 9},
    {0x0000040000000000, 10}, {0x0000080000000000, 11},
    {0x0000100000000000, 12}, {0x0000200000000000, 13},
    {0x0000400000000000, 14}, {0x0000800000000000, 15},
    {0x0000000000000000, 16}
};

const std::unordered_map<string, int> catle_string_to_index({
        {"KQkq", 0},  {"KQk" , 1},  {"KQq" , 2},  {"KQ"  , 3}, 
        {"Kkq" , 4},  {"Kk"  , 5},  {"Kq"  , 6},  {"K"   , 7},
        {"Qkq" , 8},  {"Qk"  , 9},  {"Qq"  , 10}, {"Q"   , 11},
        {"kq"  , 12}, {"k"   , 13}, {"q"   , 14}, {"-"   , 15},
});


class Zobrist {

    public:
        std::array<std::array<bitboard, 12>, 64> zobrist_piece_rands;
        bitboard zobrist_black_move;
        std::array<bitboard, 16> zobrist_castling_rights;
        std::array<bitboard, 17> zobrist_passant;

        Zobrist(void);

        bitboard get_zobrist_key(Position* pos);
};

// A Mersenne Twister pseudo-random generator of 64-bit numbers 
typedef std::mersenne_twister_engine<uint_fast64_t,
        64,312,156,31,0xb5026f5aa96619e9,
        29,0x5555555555555555,
        17,0x71d67fffeda60000,
        37,0xfff7eee000000000,
        43,6364136223846793005> mt19937_64;

#endif
