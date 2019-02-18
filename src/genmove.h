#include "position.h"
#include "common.h"
#include <unordered_map>

#ifndef GENMOVE_H
#define GENMOVE_H

const std::unordered_map<bitboard, string> bit_to_square({
      {0x01, "a1"}, {0x02, "a2"}, 
      {0x04, "a3"}, {0x08, "a4"},
      {0x10, "a5"}, {0x20, "a6"}, 
      {0x40, "a7"}, {0x80, "a8"}, 
      {0x0100, "b1"}, {0x0200, "b2"}, 
      {0x0400, "b3"}, {0x0800, "b4"},
      {0x1000, "b5"}, {0x2000, "b6"}, 
      {0x4000, "b7"}, {0x8000, "b8"}, 
      {0x010000, "c1"}, {0x020000, "c2"}, 
      {0x040000, "c3"}, {0x080000, "c4"}, 
      {0x100000, "c5"}, {0x200000, "c6"}, 
      {0x400000, "c7"}, {0x800000, "c8"}, 
      {0x01000000, "d1"}, {0x02000000, "d2"}, 
      {0x04000000, "d3"}, {0x08000000, "d4"}, 
      {0x10000000, "d5"}, {0x20000000, "d6"}, 
      {0x40000000, "d7"}, {0x80000000, "d8"}, 
      {0x0100000000, "e1"}, {0x0200000000, "e2"}, 
      {0x0400000000, "e3"}, {0x0800000000, "e4"},
      {0x1000000000, "e5"}, {0x2000000000, "e6"}, 
      {0x4000000000, "e7"}, {0x8000000000, "e8"}, 
      {0x010000000000, "f1"},{0x020000000000, "f2"}, 
      {0x040000000000, "f3"}, {0x080000000000, "f4"}, 
      {0x100000000000, "f5"}, {0x200000000000, "f6"},
      {0x400000000000, "f7"}, {0x800000000000, "f8"}, 
      {0x01000000000000, "g1"}, {0x02000000000000, "g2"},
      {0x04000000000000, "g3"}, {0x08000000000000, "g4"}, 
      {0x10000000000000, "g5"}, {0x20000000000000, "g6"}, 
      {0x40000000000000, "g7"}, {0x80000000000000, "g8"}, 
      {0x0100000000000000, "h1"}, {0x0200000000000000, "h2"}, 
      {0x0400000000000000, "h3"}, {0x0800000000000000, "h4"}, 
      {0x1000000000000000, "h5"}, {0x2000000000000000, "h6"}, 
      {0x4000000000000000, "h7"}, {0x8000000000000000, "h8"}
});

void generate_moves(Position* pos);


void generate_white_moves(Position* pos);

void generate_black_moves(Position* pos);



void generate_w_pawn_moves(Position* pos);

void generate_w_knight_moves(Position* pos);

void generate_w_bishop_moves(Position* pos);

void generate_w_rook_moves(Position* pos);

void generate_w_queen_moves(Position* pos);

void generate_w_king_moves(Position* pos);



void generate_b_pawn_moves(Position* pos);

void generate_b_knight_moves(Position* pos);

void generate_b_bishop_moves(Position* pos);

void generate_b_rook_moves(Position* pos);

void generate_b_queen_moves(Position* pos);

void generate_b_king_moves(Position* pos);

#endif
