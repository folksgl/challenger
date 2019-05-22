#include "bitboard.h"
#include "position.h"

#ifndef EVALUATE_H
#define EVALUATE_H

// Pre-initialized lookup table for possible knight moves on a given square
const bitboard center_attack_bonus[64] = {
    10, 10, 10, 10, 10, 10, 10, 10, // 1st Rank
    10, 25, 25, 25, 25, 25, 25, 10, // 2nd Rank
    10, 25, 40, 40, 40, 40, 25, 10, // 3rd Rank
    10, 25, 40, 50, 50, 40, 25, 10, // 4th Rank
    10, 25, 40, 50, 50, 40, 25, 10, // 5th Rank
    10, 25, 40, 40, 40, 40, 25, 10, // 6th Rank
    10, 25, 25, 25, 25, 25, 25, 10, // 7th Rank
    10, 10, 10, 10, 10, 10, 10, 10  // 8th Rank
};

int evaluate_position(Position* pos);

int get_white_material_value(Position* pos);

int get_black_material_value(Position* pos);

int white_defending_pawns_bonus(Position* pos);

int black_defending_pawns_bonus(Position* pos);

#endif
