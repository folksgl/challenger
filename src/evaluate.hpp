#ifndef SRC_EVALUATE_HPP_
#define SRC_EVALUATE_HPP_

#define PAWN   100
#define KNIGHT 350
#define BISHOP 350
#define ROOK   525
#define QUEEN  1000
#define KING   10000

#define PAWN_DEFEND 20
#define KNIGNT_CENTER 9999
#define MOBILITY 10

#include "position.hpp"
#include "common.hpp"

// Pre-initialized lookup table for possible knight moves on a given square
const bitboard center_attack_bonus[64] = {
    10, 10, 10, 10, 10, 10, 10, 10,  // 1st Rank
    10, 15, 15, 15, 15, 15, 15, 10,  // 2nd Rank
    10, 15, 20, 20, 20, 20, 15, 10,  // 3rd Rank
    10, 15, 20, 25, 25, 20, 15, 10,  // 4th Rank
    10, 15, 20, 25, 25, 20, 15, 10,  // 5th Rank
    10, 15, 20, 20, 20, 20, 15, 10,  // 6th Rank
    10, 15, 15, 15, 15, 15, 15, 10,  // 7th Rank
    10, 10, 10, 10, 10, 10, 10, 10   // 8th Rank
};

const bitboard middle_board = (rank_3 | rank_4 | rank_5 | rank_6) & (c_file | d_file | e_file | f_file);

const bitboard center_board = (rank_4 | rank_5) & (d_file | e_file);

int evaluate_position(Position* pos);

int get_material_value_score(Position* pos);

int white_defending_pawns_bonus(Position* pos);

int black_defending_pawns_bonus(Position* pos);

int knight_center_bonus(bitboard knights);

int diagonal_mobility_bonus(bitboard diagonal_sliders, bitboard board);

#endif  // SRC_EVALUATE_HPP_
