#include "evaluate.hpp"

#define PAWN   100
#define KNIGHT 350
#define BISHOP 350
#define ROOK   525
#define QUEEN  1000
#define KING   10000

#define PAWN_DEFEND 20
#define KNIGNT_CENTER 20

/*
 *  evaluate_position takes in a single position and returns a single number representing its evaluation
 *  score -- positive means white has advantage, negative means black has advantage.
 */
bitboard evaluate_position(Position* pos) {

    bitboard zero = std::numeric_limits<bitboard>::max() / 2;

    int white_eval = get_white_material_value(pos);
    white_eval += white_defending_pawns_bonus(pos);
    white_eval += white_knight_center_bonus(pos);

    int black_eval = get_black_material_value(pos);
    black_eval += black_defending_pawns_bonus(pos);
    black_eval += black_knight_center_bonus(pos);

    bitboard evaluation = (zero + white_eval) + black_eval;

    return evaluation;
}

/*
 *  get_white_material_value takes in a single position and returns a number representing the strength
 *  of the white pieces in the given position.
 */
int get_white_material_value(Position* pos) {
    int material_val = 0;
    
    material_val += (PAWN   * popcount(pos->maps[w_pawn]));
    material_val += (KNIGHT * popcount(pos->maps[w_knight]));
    material_val += (BISHOP * popcount(pos->maps[w_bishop]));
    material_val += (ROOK   * popcount(pos->maps[w_rook]));
    material_val += (QUEEN  * popcount(pos->maps[w_queen]));

    if (pos->maps[w_king]) {
        material_val += KING;
    }

    return material_val;
}

/*
 *  get_black_material_value takes in a single position and returns a number representing the strength
 *  of the black pieces in the given position.
 */
int get_black_material_value(Position* pos) {
    int material_val = 0;
    
    material_val -= (PAWN   * popcount(pos->maps[b_pawn]));
    material_val -= (KNIGHT * popcount(pos->maps[b_knight]));
    material_val -= (BISHOP * popcount(pos->maps[b_bishop]));
    material_val -= (ROOK   * popcount(pos->maps[b_rook]));
    material_val -= (QUEEN  * popcount(pos->maps[b_queen]));

    if (pos->maps[b_king]) {
        material_val -= KING;
    }

    return material_val;
}

int white_defending_pawns_bonus(Position* pos) {
    int bonus = 0;

    int defending_bonus = PAWN_DEFEND;

    bitboard pawns = pos->maps[w_pawn];
    bitboard white = pos->maps[w_pieces];

    bitboard left_defenders  = (((pawns bitand (compl a_file)) << 7) bitand white) >> 7;
    bitboard right_defenders = (((pawns bitand (compl h_file)) << 9) bitand white) >> 9;

    bonus = defending_bonus * (popcount(left_defenders) + popcount(right_defenders));

    return bonus;
}

int black_defending_pawns_bonus(Position* pos) {
    int bonus = 0;

    int defending_bonus = -PAWN_DEFEND;

    bitboard pawns = pos->maps[b_pawn];
    bitboard black = pos->maps[b_pieces];

    bitboard left_defenders  = (((pawns bitand (compl h_file)) >> 7) bitand black) << 7;
    bitboard right_defenders = (((pawns bitand (compl a_file)) >> 9) bitand black) << 9;

    bonus = defending_bonus * (popcount(left_defenders) + popcount(right_defenders));

    return bonus;
}

int white_knight_center_bonus(Position* pos) {
    bitboard knights = pos->maps[w_knight];
    int bonus = 0;
    int index = lsb(knights);

    while (index != -1) {
        bitboard square = squares[index];
        if (square bitand middle_board) {
            bonus += KNIGNT_CENTER;
        }

        // "Increment" loop index.
        knights and_eq (compl squares[index]);
        index = lsb(knights);
    }

    return bonus;
}

int black_knight_center_bonus(Position* pos) {
    bitboard knights = pos->maps[b_knight];
    int bonus = 0;
    int index = lsb(knights);

    while (index != -1) {
        bitboard square = squares[index];
        if (square bitand middle_board) {
            bonus -= KNIGNT_CENTER;
        }

        // "Increment" loop index.
        knights and_eq (compl squares[index]);
        index = lsb(knights);
    }

    return bonus;
}

