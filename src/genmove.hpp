#ifndef GENMOVE_H
#define GENMOVE_H

#include "position.hpp"
#include "common.hpp"
#include "game_variables.hpp"

void generate_moves(Position* pos);

void add_move(Position* pos, Position* new_pos, string src, string dest);

void generate_w_pawn_moves(Position* pos);

void generate_b_pawn_moves(Position* pos);

void leaper_generator(Position* pos, bitboard leaper, bitboard not_own_pieces, const bitboard attack_table[]);

void slide_generator(Position* pos, bitboard bishops, bitboard not_own_pieces, bitboard (*attack_function)(bitboard, int));

void castling_generator_w(Position* pos);

void castling_generator_b(Position* pos);

bitboard get_bishop_attacks(bitboard board, int index);

bitboard get_rook_attacks(bitboard board, int index);

bitboard get_queen_attacks(bitboard board, int index);

#endif
