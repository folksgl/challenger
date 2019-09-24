#include "genmove.h"

/*
 *  generate_moves takes in a position and generates all possible moves for that position, 
 *  storing the resulting positions in the moves vector for the position.
 */
void generate_moves(Position* pos) {
    bitboard not_own;

    if (pos->is_white_move()) {
        not_own = ~(pos->maps[w_pieces]);

        generate_w_pawn_moves(pos);

        leap_generator (pos, pos->maps[w_knight], not_own, knight_moves);        // knight moves
        slide_generator(pos, pos->maps[w_bishop], not_own, &get_bishop_attacks); // bishop moves
        slide_generator(pos, pos->maps[w_rook],   not_own, &get_rook_attacks);   // rook moves
        slide_generator(pos, pos->maps[w_queen],  not_own, &get_queen_attacks);  // queen moves
        leap_generator (pos, pos->maps[w_king],   not_own, king_moves);          // king moves
    }
    else {
        not_own = ~(pos->maps[b_pieces]);

        generate_b_pawn_moves(pos);

        leap_generator (pos, pos->maps[b_knight], not_own, knight_moves);        // knight moves
        slide_generator(pos, pos->maps[b_bishop], not_own, &get_bishop_attacks); // bishop moves
        slide_generator(pos, pos->maps[b_rook],   not_own, &get_rook_attacks);   // rook moves
        slide_generator(pos, pos->maps[b_queen],  not_own, &get_queen_attacks);  // queen moves
        leap_generator (pos, pos->maps[b_king],   not_own, king_moves);          // king moves
    }

}

void add_move(Position* pos, string& src, string& dest) {
    // Create a copy of the position and make the move
    Position copy = *pos;
    copy.move(src + dest);

    // If the move introduces check for the player making the move, it is illegal and will not be considered.
    bool is_check = copy.is_opposite_check();
    if (is_check) { 
        return; 
    }

    // Add the move the vector of moves possible from the current position and evaluate.
    pos->moves.push_back(copy);
    Position* p = &pos->moves.back();
    p->evaluate();
}

inline bitboard get_bishop_attacks(bitboard board, int index) {
    return slider_attacks.BishopAttacks(board, index);
}

inline bitboard get_rook_attacks(bitboard board, int index) {
    return slider_attacks.RookAttacks(board, index);
}

inline bitboard get_queen_attacks(bitboard board, int index) {
    return slider_attacks.QueenAttacks(board, index);
}

void leap_generator(Position* pos, bitboard leaper, bitboard not_own_pieces, const bitboard move_database[64]) {
    // Loop over the leaper on the board
    int index = lsb(leaper);
    while (index != -1) {
        bitboard attacks = move_database[index] & not_own_pieces;

        string src =  bit_to_square_arr[index];

        // Loop over the current leaper pieces attacks and add positions
        int inner_index = lsb(attacks);
        while (inner_index != -1) {
            string dest = bit_to_square_arr[inner_index];
            add_move(pos, src, dest);

            // "Increment" loop index.
            attacks &= ~squares[inner_index];
            inner_index = lsb(attacks);
        }
        // "Increment" loop index.
        leaper &= ~squares[index];
        index = lsb(leaper);
    }
}

void slide_generator(Position* pos, bitboard bishops, bitboard not_own_pieces, bitboard (*attack_function)(bitboard, int)) {
    bitboard whole_board = pos->maps[w_pieces] | pos->maps[b_pieces];

    int index = lsb(bishops);
    while (index != -1) {
        string src =  bit_to_square_arr[index];
        bitboard attacks = (*attack_function)(whole_board, index);
        attacks &= not_own_pieces;

        // Loop over the current bishop attacks and add positions
        int inner_index = lsb(attacks);
        while (inner_index != -1) {
            string dest = bit_to_square_arr[inner_index];
            add_move(pos, src, dest);

            attacks &= ~squares[inner_index];
            inner_index = lsb(attacks);
        }
        bishops &= ~squares[index];
        index = lsb(bishops);
    }

    return;
}

void generate_w_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[w_pawn];

    bitboard black = pos->maps[b_pieces] | pos->maps[passant_sq];
    bitboard unoccupied = (~pos->maps[w_pieces]) & (~pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = pawns & ((black & (~h_file)) >> 7);
    bitboard right_attacks = pawns & ((black & (~a_file)) >> 9);
    bitboard forward = pawns & (unoccupied >> 8);
    bitboard double_forward = (rank_2 & forward) & (unoccupied >> 16);

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    int index = lsb(pawns);
    while (index != -1) {

        bitboard squarei = squares[index];
        src = bit_to_square_arr[index];

        if (squarei & left_attacks) {
            dest = bit_to_square_pawn_arr[index+7];
            add_move(pos, src, dest);
        }
        if (squarei & right_attacks) {
            dest = bit_to_square_pawn_arr[index+9];
            add_move(pos, src, dest);
        }
        if (squarei & forward) {
            dest = bit_to_square_pawn_arr[index+8];
            add_move(pos, src, dest);

            if (squarei & double_forward) {
                dest = bit_to_square_arr[index+16];
                add_move(pos, src, dest);
            }
        }

        pawns &= ~squarei;
        index = lsb(pawns);
    }
    return;
}

void generate_b_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[b_pawn];

    bitboard white = pos->maps[w_pieces] | pos->maps[passant_sq];
    bitboard unoccupied = (~pos->maps[w_pieces]) & (~pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = pawns & ((white & (~a_file)) << 7);
    bitboard right_attacks = pawns & ((white & (~h_file)) << 9);
    bitboard forward = pawns & (unoccupied << 8);
    bitboard double_forward = (rank_7 & forward) & (unoccupied << 16);

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    int index = lsb(pawns);
    while (index != -1) {

        bitboard squarei = squares[index];
        src = bit_to_square_arr[index];

        if (squarei & left_attacks) {
            dest = bit_to_square_pawn_arr[index-7];
            add_move(pos, src, dest);
        }
        if (squarei & right_attacks) {
            dest = bit_to_square_pawn_arr[index-9];
            add_move(pos, src, dest);
        }
        if (squarei & forward) {
            dest = bit_to_square_pawn_arr[index-8];
            add_move(pos, src, dest);

            if (squarei & double_forward) {
                dest = bit_to_square_arr[index-16];
                add_move(pos, src, dest);
            }
        }

        pawns &= ~squarei;
        index = lsb(pawns);
    }
    return;
}

void PrintBitBoard(const bitboard bb) {
    for (int row = 7; row >= 0; --row) {
        for (int col = 0; col <= 7; ++col) {
            if (bb & (1ULL << ((row * 8) + col))) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

