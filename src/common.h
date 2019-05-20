#include "bitboard.h"
#include <string>
#include <unordered_map>

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

const std::unordered_map<bitboard, std::string> bit_to_square({
      {0x01, "a1"}, {0x02, "b1"}, 
      {0x04, "c1"}, {0x08, "d1"},
      {0x10, "e1"}, {0x20, "f1"}, 
      {0x40, "g1"}, {0x80, "h1"}, 
      {0x0100, "a2"}, {0x0200, "b2"}, 
      {0x0400, "c2"}, {0x0800, "d2"},
      {0x1000, "e2"}, {0x2000, "f2"}, 
      {0x4000, "g2"}, {0x8000, "h2"}, 
      {0x010000, "a3"}, {0x020000, "b3"}, 
      {0x040000, "c3"}, {0x080000, "d3"}, 
      {0x100000, "e3"}, {0x200000, "f3"}, 
      {0x400000, "g3"}, {0x800000, "h3"}, 
      {0x01000000, "a4"}, {0x02000000, "b4"}, 
      {0x04000000, "c4"}, {0x08000000, "d4"}, 
      {0x10000000, "e4"}, {0x20000000, "f4"}, 
      {0x40000000, "g4"}, {0x80000000, "h4"}, 
      {0x0100000000, "a5"}, {0x0200000000, "b5"}, 
      {0x0400000000, "c5"}, {0x0800000000, "d5"},
      {0x1000000000, "e5"}, {0x2000000000, "f5"}, 
      {0x4000000000, "g5"}, {0x8000000000, "h5"}, 
      {0x010000000000, "a6"}, {0x020000000000, "b6"}, 
      {0x040000000000, "c6"}, {0x080000000000, "d6"}, 
      {0x100000000000, "e6"}, {0x200000000000, "f6"},
      {0x400000000000, "g6"}, {0x800000000000, "h6"}, 
      {0x01000000000000, "a7"}, {0x02000000000000, "b7"},
      {0x04000000000000, "c7"}, {0x08000000000000, "d7"}, 
      {0x10000000000000, "e7"}, {0x20000000000000, "f7"}, 
      {0x40000000000000, "g7"}, {0x80000000000000, "h7"}, 
      {0x0100000000000000, "a8"}, {0x0200000000000000, "b8"}, 
      {0x0400000000000000, "c8"}, {0x0800000000000000, "d8"}, 
      {0x1000000000000000, "e8"}, {0x2000000000000000, "f8"}, 
      {0x4000000000000000, "g8"}, {0x8000000000000000, "h8"}
});

int num_set_bits(bitboard map);
int get_square_num(std::string square_string);
int file_to_num(char file);

#endif

