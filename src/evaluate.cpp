#include "evaluate.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SCORING
//
// Scoring will be done by returning a single, signed number representing the strength of the position
// for one side or the other.
//
// Positive scores represent an advantage for white, while negative scores represent an advantage for black.
//
// ANY function to evaluate an advantage for one side should return a positive number representing the strength
// of the advantage for that particular analysis. e.g. when looking at whether pawns defend other pieces, both
// the white and black evaluation of defending pawns will return a positive number. The evaluate_position
// function should take the returns from all functions and it alone will be responsible for subtracting to 
// determine the final evaluation
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 *  evaluate_position takes in a single position and returns a single number representing its evaluation
 *  score -- positive means white has advantage, negative means black has advantage.
 */
int evaluate_position(Position* pos) {

    int evaluation = 0;

    evaluation += get_material_value_score(pos);

    //evaluation += white_defending_pawns_bonus(pos);
    //evaluation += white_knight_center_bonus(pos);

    //evaluation += black_defending_pawns_bonus(pos);
    //evaluation += black_knight_center_bonus(pos);

    return evaluation;
}

/*
 *  get_material_value_score takes in a single position and returns a number representing the strength
 *  of the pieces left in the given position, with no reguard to their positional advantage/disadvantage.
 */
int get_material_value_score(Position* pos) {
    int material_val = 0;
    
    material_val += (PAWN   * popcount(pos->maps[w_pawn]));
    material_val += (KNIGHT * popcount(pos->maps[w_knight]));
    material_val += (BISHOP * popcount(pos->maps[w_bishop]));
    material_val += (ROOK   * popcount(pos->maps[w_rook]));
    material_val += (QUEEN  * popcount(pos->maps[w_queen]));
    material_val += (KING   * popcount(pos->maps[w_king]));

    material_val -= (PAWN   * popcount(pos->maps[b_pawn]));
    material_val -= (KNIGHT * popcount(pos->maps[b_knight]));
    material_val -= (BISHOP * popcount(pos->maps[b_bishop]));
    material_val -= (ROOK   * popcount(pos->maps[b_rook]));
    material_val -= (QUEEN  * popcount(pos->maps[b_queen]));
    material_val -= (KING   * popcount(pos->maps[b_king]));

    return material_val;
}

int white_defending_pawns_bonus(Position* pos) {
    bitboard pawns = pos->maps[w_pawn];
    bitboard white = pos->maps[w_pieces];

    bitboard left_defenders = ((pawns bitand not_a_file) << 7) bitand white;
    bitboard right_defenders = ((pawns bitand not_h_file) << 9) bitand white;

    return PAWN_DEFEND * (popcount(left_defenders) + popcount(right_defenders));
}

int black_defending_pawns_bonus(Position* pos) {
    bitboard pawns = pos->maps[b_pawn];
    bitboard black = pos->maps[b_pieces];

    bitboard left_defenders = ((pawns bitand not_h_file) >> 7) bitand black;
    bitboard right_defenders = ((pawns bitand not_a_file) >> 9) bitand black;

    return PAWN_DEFEND * (popcount(left_defenders) + popcount(right_defenders));
}

int knight_center_bonus(bitboard knights) {
    int bonus = 0;

    while (knights) {
        int index = lsb_unsafe(knights);
        bitboard square = one << index;
        if (square bitand middle_board) {
            bonus += KNIGNT_CENTER;
        }

        // "Increment" loop index.
        knights xor_eq square;
    }

    return bonus;
}

