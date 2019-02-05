#include "./evaluate.h"

using namespace std;

#define PAWN   100
#define KNIGHT 350
#define BISHOP 350
#define ROOK   525
#define QUEEN  1000
#define KING   10000

/*
 *  evaluate_position takes in a single position and returns a single number representing its evaluation
 *  score -- positive means white has advantage, negative means black has advantage.
 */
int evaluate_position(Position* pos) {

    int white_material = get_white_material_value(pos);
    int black_material = get_black_material_value(pos);

    return white_material + black_material;
}

/*
 *  get_white_material_value takes in a single position and returns a number representing the strength
 *  of the white pieces in the given position.
 */
int get_white_material_value(Position* pos) {
    int material_val = 0;
    
    material_val += (PAWN   * num_set_bits(pos->maps[w_pawn]));
    material_val += (KNIGHT * num_set_bits(pos->maps[w_knight]));
    material_val += (BISHOP * num_set_bits(pos->maps[w_bishop]));
    material_val += (ROOK   * num_set_bits(pos->maps[w_rook]));
    material_val += (QUEEN  * num_set_bits(pos->maps[w_queen]));

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
    
    material_val -= (PAWN   * num_set_bits(pos->maps[b_pawn]));
    material_val -= (KNIGHT * num_set_bits(pos->maps[b_knight]));
    material_val -= (BISHOP * num_set_bits(pos->maps[b_bishop]));
    material_val -= (ROOK   * num_set_bits(pos->maps[b_rook]));
    material_val -= (QUEEN  * num_set_bits(pos->maps[b_queen]));

    if (pos->maps[w_king]) {
        material_val -= KING;
    }

    return material_val;


}

/*
 *  num_set_bits takes in a bitboard and returns the number of bits in that bitboard that are set to 1.
 */
int num_set_bits(bitboard map) {
    int num_bits = 0;

    for (int i = 0; i < 64; i++) {
        if (map & squares[i]) {
            num_bits++;
        }
    }

    return num_bits;
}

