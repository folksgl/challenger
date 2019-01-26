#include "./position.h"
#include "./bitmap.h"
#include "./evaluate.h"

using namespace std;

#define PAWN   100
#define KNIGHT 350
#define BISHOP 350
#define ROOK   525
#define QUEEN  1000
#define KING   10000

const bitmap squares[64] = {
    0x01,               0x02,               0x04,               0x08,               0x10,               0x20,               0x40,               0x80, 
    0x0100,             0x0200,             0x0400,             0x0800,             0x1000,             0x2000,             0x4000,             0x8000,
    0x010000,           0x020000,           0x040000,           0x080000,           0x100000,           0x200000,           0x400000,           0x800000,
    0x01000000,         0x02000000,         0x04000000,         0x08000000,         0x10000000,         0x20000000,         0x40000000,         0x80000000,
    0x0100000000,       0x0200000000,       0x0400000000,       0x0800000000,       0x1000000000,       0x2000000000,       0x4000000000,       0x8000000000,
    0x010000000000,     0x020000000000,     0x040000000000,     0x080000000000,     0x100000000000,     0x200000000000,     0x400000000000,     0x800000000000,
    0x01000000000000,   0x02000000000000,   0x04000000000000,   0x08000000000000,   0x10000000000000,   0x20000000000000,   0x40000000000000,   0x80000000000000,
    0x0100000000000000, 0x0200000000000000, 0x0400000000000000, 0x0800000000000000, 0x1000000000000000, 0x2000000000000000, 0x4000000000000000, 0x8000000000000000
};

int evaluate_position(position* pos) {

    int white_material = get_white_material_value(pos);
    int black_material = get_black_material_value(pos);

    return white_material - black_material;
}

int get_white_material_value(position* pos) {
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

int get_black_material_value(position* pos) {
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

int num_set_bits(bitmap map) {
    int num_bits = 0;

    for (int i = 0; i < 64; i++) {
        if (map & squares[i]) {
            num_bits++;
        }
    }

    return num_bits;
}

