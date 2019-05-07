#include "position.h"
#include "common.h"
#include <unordered_map>

#ifndef GENMOVE_H
#define GENMOVE_H

const std::unordered_map<bitboard, string> bit_to_square({
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
