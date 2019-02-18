#include "bitboard.h"
#include <string>

#ifndef COMMON_H
#define COMMON_H

const bitboard squares[64] = {
    0x01,               0x02,               0x04,               0x08,               0x10,               0x20,               0x40,               0x80, 
    0x0100,             0x0200,             0x0400,             0x0800,             0x1000,             0x2000,             0x4000,             0x8000,
    0x010000,           0x020000,           0x040000,           0x080000,           0x100000,           0x200000,           0x400000,           0x800000,
    0x01000000,         0x02000000,         0x04000000,         0x08000000,         0x10000000,         0x20000000,         0x40000000,         0x80000000,
    0x0100000000,       0x0200000000,       0x0400000000,       0x0800000000,       0x1000000000,       0x2000000000,       0x4000000000,       0x8000000000,
    0x010000000000,     0x020000000000,     0x040000000000,     0x080000000000,     0x100000000000,     0x200000000000,     0x400000000000,     0x800000000000,
    0x01000000000000,   0x02000000000000,   0x04000000000000,   0x08000000000000,   0x10000000000000,   0x20000000000000,   0x40000000000000,   0x80000000000000,
    0x0100000000000000, 0x0200000000000000, 0x0400000000000000, 0x0800000000000000, 0x1000000000000000, 0x2000000000000000, 0x4000000000000000, 0x8000000000000000
};

const bitboard a_file = 0x0101010101010101;
const bitboard b_file = 0x0202020202020202;
const bitboard c_file = 0x0404040404040404;
const bitboard d_file = 0x0808080808080808;
const bitboard e_file = 0x1010101010101010;
const bitboard f_file = 0x2020202020202020;
const bitboard g_file = 0x4040404040404040;
const bitboard h_file = 0x8080808080808080;

const bitboard rank_1 = 0x00000000000000FF;
const bitboard rank_2 = 0x000000000000FF00;
const bitboard rank_3 = 0x0000000000FF0000;
const bitboard rank_4 = 0x00000000FF000000;
const bitboard rank_5 = 0x000000FF00000000;
const bitboard rank_6 = 0x0000FF0000000000;
const bitboard rank_7 = 0x00FF000000000000;
const bitboard rank_8 = 0xFF00000000000000;

int num_set_bits(bitboard map);
int get_square_num(std::string square_string);
int file_to_num(char file);

#endif

