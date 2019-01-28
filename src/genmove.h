#include "./position.h"

#ifndef GENMOVE_H
#define GENMOVE_H

void generate_moves(position* pos);


void generate_white_moves(position* pos);

void generate_black_moves(position* pos);


position copy_of(position* pos);


void generate_w_pawn_moves(position* pos);

void generate_w_knight_moves(position* pos);

void generate_w_bishop_moves(position* pos);

void generate_w_rook_moves(position* pos);

void generate_w_queen_moves(position* pos);

void generate_w_king_moves(position* pos);



void generate_b_pabn_moves(position* pos);

void generate_b_knight_moves(position* pos);

void generate_b_bishop_moves(position* pos);

void generate_b_rook_moves(position* pos);

void generate_b_queen_moves(position* pos);

void generate_b_king_moves(position* pos);


#endif
