#include "genmove.h"

/*
 *  generate_moves takes in a position and generates all possible moves for that position, 
 *  storing the resulting positions in the moves vector for the position.
 */
void generate_moves(Position* pos) {

    if (pos->active_color == 'w') {
        generate_white_moves(pos);
    }
    else {
        generate_black_moves(pos);
    }

    return;
}

void generate_white_moves(Position* pos) {

    generate_w_pawn_moves(pos);
    generate_w_knight_moves(pos);
    generate_w_bishop_moves(pos);
    generate_w_rook_moves(pos);
    generate_w_queen_moves(pos);
    generate_w_king_moves(pos);

    return;
}

void generate_black_moves(Position* pos) {

    generate_b_pawn_moves(pos);
    generate_b_knight_moves(pos);
    generate_b_bishop_moves(pos);
    generate_b_rook_moves(pos);
    generate_b_queen_moves(pos);
    generate_b_king_moves(pos);

    return;
}

void generate_w_pawn_moves(Position* pos) {

    int pawns = 0;
    int num_to_generate = num_set_bits(pos->maps[w_pawn]);

    while (pawns < num_to_generate) {
        
    }

    return;
}

void generate_w_knight_moves(Position* pos) {
    return;
}

void generate_w_bishop_moves(Position* pos) {
    return;
}

void generate_w_rook_moves(Position* pos) {
    return;
}

void generate_w_queen_moves(Position* pos) {
    return;
}

void generate_w_king_moves(Position* pos) {
    return;
}



void generate_b_pawn_moves(Position* pos) {
    return;
}

void generate_b_knight_moves(Position* pos) {
    return;
}

void generate_b_bishop_moves(Position* pos) {
    return;
}

void generate_b_rook_moves(Position* pos) {
    return;
}

void generate_b_queen_moves(Position* pos) {
    return;
}

void generate_b_king_moves(Position* pos) {
    return;
}

