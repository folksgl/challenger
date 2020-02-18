#ifndef EVALUATE_H
#define EVALUATE_H

#include "position.h"
#include "common.h"

// Pre-initialized lookup table for possible knight moves on a given square
const bitboard center_attack_bonus[64] = {
    10, 10, 10, 10, 10, 10, 10, 10, // 1st Rank
    10, 15, 15, 15, 15, 15, 15, 10, // 2nd Rank
    10, 15, 20, 20, 20, 20, 15, 10, // 3rd Rank
    10, 15, 20, 25, 25, 20, 15, 10, // 4th Rank
    10, 15, 20, 25, 25, 20, 15, 10, // 5th Rank
    10, 15, 20, 20, 20, 20, 15, 10, // 6th Rank
    10, 15, 15, 15, 15, 15, 15, 10, // 7th Rank
    10, 10, 10, 10, 10, 10, 10, 10  // 8th Rank
};

const bitboard middle_board = (rank_3 | rank_4 | rank_5 | rank_6) & (c_file | d_file | e_file | f_file);

const bitboard center_board = (rank_4 | rank_5) & (d_file | e_file);

bitboard evaluate_position(Position* pos);

int get_white_material_value(Position* pos);

int get_black_material_value(Position* pos);

int white_defending_pawns_bonus(Position* pos);

int black_defending_pawns_bonus(Position* pos);

int white_knight_center_bonus(Position* pos);

int black_knight_center_bonus(Position* pos);

#endif
