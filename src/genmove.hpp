#ifndef SRC_GENMOVE_HPP_
#define SRC_GENMOVE_HPP_

#include <string>
#include "position.hpp"
#include "common.hpp"
#include "game_variables.hpp"

void generate_moves(Position* pos);

void add_move(Position* pos, const string& move_string, const map_names king_piece, const int moving_piece);

void generate_w_pawn_moves(Position* pos);

void generate_b_pawn_moves(Position* pos);

void leaper_generator(Position* pos, bitboard not_own_pieces, const bitboard attack_table[], const int moving_piece);

void slide_generator(Position* pos, bitboard bishops, bitboard not_own_pieces, bitboard (*attack_function)(bitboard, int), const int moving_piece);

void castling_generator_w(Position* pos);

void castling_generator_b(Position* pos);

bitboard get_bishop_attacks(bitboard board, int index);

bitboard get_rook_attacks(bitboard board, int index);

bitboard get_queen_attacks(bitboard board, int index);

#endif  // SRC_GENMOVE_HPP_
