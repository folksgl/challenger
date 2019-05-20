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

void add_move(Position* pos, string src, string dest) {
    pos->moves.push_back(*pos);
    Position* p = &pos->moves.back();
    p->move(src + dest);
    p->evaluate();
}

bitboard get_bishop_attacks(bitboard board, int index) {
    return slider_attacks.BishopAttacks(board, index);
}

bitboard get_rook_attacks(bitboard board, int index) {
    return slider_attacks.RookAttacks(board, index);
}

bitboard get_queen_attacks(bitboard board, int index) {
    return slider_attacks.QueenAttacks(board, index);
}

void leap_generator(Position* pos, bitboard leaper, bitboard not_own_pieces, const bitboard move_database[64]) {
    // Loop over the leaper on the board
    int index = lsb(leaper);
    while (index != -1) {
        bitboard squarei = squares[index];
        bitboard attacks = move_database[index] & not_own_pieces;

        string src =  bit_to_square.at(squarei);

        // Loop over the current leaper pieces attacks and add positions
        int inner_index = lsb(attacks);
        while (inner_index != -1) {
            bitboard squarej = squares[inner_index];
            string dest = bit_to_square.at(squarej);
            add_move(pos, src, dest);

            // "Increment" loop index.
            attacks = attacks & (~squarej);
            inner_index = lsb(attacks);
        }
        // "Increment" loop index.
        leaper = leaper & (~squarei);
        index = lsb(leaper);
    }
}

void slide_generator(Position* pos, bitboard bishops, bitboard not_own_pieces, bitboard (*attack_function)(bitboard, int)) {
    bitboard whole_board = pos->maps[w_pieces] | pos->maps[b_pieces];

    int index = lsb(bishops);
    while (index != -1) {
        bitboard squarei = squares[index];
        string src =  bit_to_square.at(squarei);
        bitboard attacks = (*attack_function)(whole_board, index);
        attacks &= not_own_pieces;

        // Loop over the current bishop attacks and add positions
        int inner_index = lsb(attacks);
        while (inner_index != -1) {
            bitboard squarej = squares[inner_index];
            string dest = bit_to_square.at(squarej);
            add_move(pos, src, dest);

            attacks = attacks & (~squarej);
            inner_index = lsb(attacks);
        }
        bishops = bishops & (~squarei);
        index = lsb(bishops);
    }

    return;
}

void generate_w_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[w_pawn];
    bitboard passant_bit = 0;
    if (pos->passant_target_sq != "-") {
        passant_bit = squares[get_square_num(pos->passant_target_sq)];
    }

    bitboard black = pos->maps[b_pieces] | passant_bit;
    bitboard unoccupied = (~pos->maps[w_pieces]) & (~pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = (((pawns & (~a_file)) << 7) & black) >> 7;
    bitboard right_attacks = (((pawns & (~h_file)) << 9) & black) >> 9;
    bitboard forward = ((pawns << 8) & unoccupied) >> 8;
    bitboard double_forward = (((rank_2 & forward) << 16) & unoccupied) >> 16;

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    int index = lsb(pawns);
    while (index != -1) {

        bitboard squarei = squares[index];
        src = bit_to_square.at(squarei);

        if (squarei & left_attacks) {
            dest = bit_to_square_pawn.at(squares[index+7]);
            add_move(pos, src, dest);
        }
        if (squarei & right_attacks) {
            dest = bit_to_square_pawn.at(squares[index+9]);
            add_move(pos, src, dest);
        }
        if (squarei & forward) {
            dest = bit_to_square_pawn.at(squares[index+8]);
            add_move(pos, src, dest);

            if (squarei & double_forward) {
                dest = bit_to_square.at(squares[index+16]);
                add_move(pos, src, dest);
            }
        }

        pawns = pawns & (~squarei);
        index = lsb(pawns);
    }
    return;
}

void generate_w_knight_moves(Position* pos) {
    bitboard knights = pos->maps[w_knight];
    bitboard not_own_white = ~(pos->maps[w_pieces]);

    leap_generator(pos, knights, not_own_white, knight_moves);

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


void generate_w_bishop_moves(Position* pos) {
    bitboard bishops = pos->maps[w_bishop];
    bitboard not_own_white = ~(pos->maps[w_pieces]);

    slide_generator(pos, bishops, not_own_white, &get_bishop_attacks);

    return;
}

void generate_w_rook_moves(Position* pos) {
    bitboard rooks = pos->maps[w_rook];
    bitboard not_own_white = ~(pos->maps[w_pieces]);

    slide_generator(pos, rooks, not_own_white, &get_rook_attacks);

    return;
}

void generate_w_queen_moves(Position* pos) {
    bitboard queen = pos->maps[w_queen];
    bitboard not_own_white = ~(pos->maps[w_pieces]);

    slide_generator(pos, queen, not_own_white, &get_queen_attacks);

    return;
}

void generate_w_king_moves(Position* pos) {
    bitboard king = pos->maps[w_king];
    bitboard not_own_white = ~(pos->maps[w_pieces]);

    leap_generator(pos, king, not_own_white, king_moves);

    return;
}



void generate_b_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[b_pawn];
    bitboard passant_bit = 0;
    if (pos->passant_target_sq != "-") {
        passant_bit = squares[get_square_num(pos->passant_target_sq)];
    }

    bitboard white = pos->maps[w_pieces] | passant_bit;
    bitboard unoccupied = (~pos->maps[w_pieces]) & (~pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = (((pawns & (~h_file)) >> 7) & white) << 7;
    bitboard right_attacks = (((pawns & (~a_file)) >> 9) & white) << 9;
    bitboard forward = ((pawns >> 8) & unoccupied) << 8;
    bitboard double_forward = (((rank_7 & forward) >> 16) & unoccupied) << 16;

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    int index = lsb(pawns);
    while (index != -1) {

        bitboard squarei = squares[index];
        src = bit_to_square.at(squarei);

        if (squarei & left_attacks) {
            dest = bit_to_square_pawn.at(squares[index-7]);
            add_move(pos, src, dest);
        }
        if (squarei & right_attacks) {
            dest = bit_to_square_pawn.at(squares[index-9]);
            add_move(pos, src, dest);
        }
        if (squarei & forward) {
            dest = bit_to_square_pawn.at(squares[index-8]);
            add_move(pos, src, dest);

            if (squarei & double_forward) {
                dest = bit_to_square.at(squares[index-16]);
                add_move(pos, src, dest);
            }
        }

        pawns = pawns & (~squarei);
        index = lsb(pawns);
    }
    return;
}

void generate_b_knight_moves(Position* pos) {
    bitboard knights = pos->maps[b_knight];
    bitboard not_own_black = ~(pos->maps[b_pieces]);

    leap_generator(pos, knights, not_own_black, knight_moves);

    return;

}

void generate_b_bishop_moves(Position* pos) {
    bitboard bishops = pos->maps[b_bishop];
    bitboard not_own_black = ~(pos->maps[b_pieces]);

    slide_generator(pos, bishops, not_own_black, &get_bishop_attacks);
    return;
}

void generate_b_rook_moves(Position* pos) {
    bitboard rook = pos->maps[b_rook];
    bitboard not_own_black = ~(pos->maps[b_pieces]);

    slide_generator(pos, rook, not_own_black, &get_rook_attacks);

    return;
}

void generate_b_queen_moves(Position* pos) {
    bitboard queen = pos->maps[b_queen];
    bitboard not_own_black = ~(pos->maps[b_pieces]);

    slide_generator(pos, queen, not_own_black, &get_queen_attacks);

    return;
}

void generate_b_king_moves(Position* pos) {
    bitboard king = pos->maps[b_king];
    bitboard not_own_black = ~(pos->maps[b_pieces]);

    leap_generator(pos, king, not_own_black, king_moves);

    return;
}

