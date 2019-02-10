#include "position.h"

#ifndef GENMOVE_H
#define GENMOVE_H

void generate_moves(Position* pos);


void generate_white_moves(Position* pos);

void generate_black_moves(Position* pos);


Position copy_of(Position* pos);


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
