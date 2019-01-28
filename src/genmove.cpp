#include "./position.h"
#include "./evaluate.h"
#include "./genmove.h"

/*
 *  generate_moves takes in a position and generates all possible moves for that position, 
 *  storing the resulting positions in the moves vector for the position.
 */
void generate_moves(position* pos) {

    if (pos->active_color == 'w') {
        generate_white_moves(pos);
    }
    else {
        generate_black_moves(pos);
    }

    return;
}

void generate_white_moves(position* pos) {

    generate_w_pawn_moves(pos);
    generate_w_knight_moves(pos);
    generate_w_bishop_moves(pos);
    generate_w_rook_moves(pos);
    generate_w_queen_moves(pos);
    generate_w_king_moves(pos);

    return;
}

void generate_black_moves(position* pos) {

    generate_b_pabn_moves(pos);
    generate_b_knight_moves(pos);
    generate_b_bishop_moves(pos);
    generate_b_rook_moves(pos);
    generate_b_queen_moves(pos);
    generate_b_king_moves(pos);

    return;
}

position copy_of(position* pos) {
    position tmp_pos;

    // Set the white pieces that aren't pawns
    for (int i = 0; i < 14; i++) {
        tmp_pos.maps[i] = pos->maps[i];
    }

    tmp_pos.active_color = pos->active_color;

    tmp_pos.w_kingside_castle = pos->w_kingside_castle;
    tmp_pos.b_kingside_castle = pos->w_kingside_castle;
    tmp_pos.w_queenside_castle = pos->w_queenside_castle;
    tmp_pos.b_queenside_castle = pos->b_queenside_castle;

    tmp_pos.passant_target_sq = pos->passant_target_sq;

    tmp_pos.halfmove_clock = pos->halfmove_clock;
    tmp_pos.fullmove_number = pos->fullmove_number;

    tmp_pos.evaluation_score = pos->evaluation_score;

    tmp_pos.moves = NULL;

    return tmp_pos;
}

void generate_w_pawn_moves(position* pos) {

    int pawns = 0;
    int num_to_generate = num_set_bits(pos.maps[w_pawn]);

    while (pawns < num_to_generate) {
        
    }

    return;
}

void generate_w_knight_moves(position* pos) {
    return;
}

void generate_w_bishop_moves(position* pos) {
    return;
}

void generate_w_rook_moves(position* pos) {
    return;
}

void generate_w_queen_moves(position* pos) {
    return;
}

void generate_w_king_moves(position* pos) {
    return;
}



void generate_b_pabn_moves(position* pos) {
    return;
}

void generate_b_knight_moves(position* pos) {
    return;
}

void generate_b_bishop_moves(position* pos) {
    return;
}

void generate_b_rook_moves(position* pos) {
    return;
}

void generate_b_queen_moves(position* pos) {
    return;
}

void generate_b_king_moves(position* pos) {
    return;
}

