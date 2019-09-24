#include "bitboard.h"
#include <string>
#include <unordered_map>

#ifndef COMMON_H
#define COMMON_H

#define lsb(x) (__builtin_ffsll((x)) - 1)

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

const std::array<std::string, 64> bit_to_square_arr = {
      "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", 
      "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", 
      "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", 
      "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", 
      "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", 
      "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", 
      "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", 
      "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"
};

const std::array<std::string, 64> bit_to_square_pawn_arr = {
      "a1q", "b1q", "c1q", "d1q", "e1q", "f1q", "g1q", "h1q", 
      "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", 
      "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", 
      "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", 
      "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", 
      "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", 
      "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", 
      "a8q", "b8q", "c8q", "d8q", "e8q", "f8q", "g8q", "h8q"
};


const std::unordered_map<bitboard, std::string> bit_to_square({
      {0x00, "-"},
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

// Pre-initialized lookup table for possible knight moves on a given square
const bitboard knight_moves[64] = {
    0x0000000000020400, 0x0000000000050800, 0x00000000000A1100, 0x0000000000142200,
    0x0000000000284400, 0x0000000000508800, 0x0000000000A01000, 0x0000000000402000, // 1st Rank
    0x0000000002040004, 0x00000000050A0008, 0x000000000A110011, 0x0000000014220022,
    0x0000000028440044, 0x0000000050880088, 0x00000000A0100010, 0x0000000040200020, // 2nd Rank
    0x0000000204000402, 0x0000000508000805, 0x0000000A1100110A, 0x0000001422002214, 
    0x0000002844004428, 0x0000005088008850, 0x000000A0100010A0, 0x0000004020002040, // 3rd Rank
    0x0000020400040200, 0x0000050800080500, 0x00000A1100110A00, 0x0000142200221400, 
    0x0000284400442800, 0x0000508800885000, 0x0000A0100010A000, 0x0000402000204000, // 4th Rank
    0x0002040004020000, 0x0005080008050000, 0x000A1100110A0000, 0x0014220022140000, 
    0x0028440044280000, 0x0050880088500000, 0x00A0100010A00000, 0x0040200020400000, // 5th Rank
    0x0204000402000000, 0x0508000805000000, 0x0A1100110A000000, 0x1422002214000000, 
    0x2844004428000000, 0x5088008850000000, 0xA0100010A0000000, 0x4020002040000000, // 6th Rank
    0x0400040200000000, 0x0800805000000000, 0x1100110A00000000, 0x2200221400000000, 
    0x4400442800000000, 0x8800885000000000, 0x100010A000000000, 0x2000204000000000, // 7th Rank
    0x0004020000000000, 0x0008050000000000, 0x00110A0000000000, 0x0022140000000000, 
    0x0044280000000000, 0x0088500000000000, 0x0010A00000000000, 0x0020400000000000  // 8th Rank
};

// Pre-initialized lookup table for possible king moves on a given square
const bitboard king_moves[64] = {
    0x0000000000000302, 0x0000000000000705, 0x0000000000000E0A, 0x0000000000001C14,
    0x0000000000003828, 0x0000000000007050, 0x000000000000E0A0, 0x000000000000C040, // 1st Rank
    0x0000000000030203, 0x0000000000070507, 0x00000000000E0A0E, 0x00000000001C141C,
    0x0000000000382838, 0x0000000000705070, 0x0000000000E0A0E0, 0x0000000000C040C0, // 2nd Rank
    0x0000000003020300, 0x0000000007050700, 0x000000000E0A0E00, 0x000000001C141C00,
    0x0000000038283800, 0x0000000070507000, 0x00000000E0A0E000, 0x00000000C040C000, // 3rd Rank
    0x0000000302030000, 0x0000000705070000, 0x0000000E0A0E0000, 0x0000001C141C0000,
    0x0000003828380000, 0x0000007050700000, 0x000000E0A0E00000, 0x000000C040C00000, // 4th Rank
    0x0000030203000000, 0x0000070507000000, 0x00000E0A0E000000, 0x00001C141C000000,
    0x0000382838000000, 0x0000705070000000, 0x0000E0A0E0000000, 0x0000C040C0000000, // 5th Rank
    0x0003020300000000, 0x0007050700000000, 0x000E0A0E00000000, 0x001C141C00000000,
    0x0038283800000000, 0x0070507000000000, 0x00E0A0E000000000, 0x00C040C000000000, // 6th Rank
    0x0302030000000000, 0x0705070000000000, 0x0E0A0E0000000000, 0x1C141C0000000000,
    0x3828380000000000, 0x7050700000000000, 0xE0A0E00000000000, 0xC040C00000000000, // 7th Rank
    0x0203000000000000, 0x0507000000000000, 0x0A0E000000000000, 0x141C000000000000,
    0x2838000000000000, 0x5070000000000000, 0xA0E0000000000000, 0x40C0000000000000, // 8th Rank
};

int num_set_bits(bitboard map);
int get_square_num(std::string square_string);
int file_to_num(char file);

#endif

