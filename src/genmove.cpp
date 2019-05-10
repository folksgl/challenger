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

void add_move(Position* pos, Position* new_pos, string src, string dest) {
    new_pos->movestring = src + dest;
    new_pos->move(src + dest);
    new_pos->evaluate();
    pos->moves.push_back(*new_pos);
}

void generate_w_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[w_pawn];
    // check if there are any pawns to generate moves for
    if (pawns) {
        bitboard passant_bit = 0;
        if (pos->passant_target_sq != "-") {
            passant_bit = squares[get_square_num(pos->passant_target_sq)];
        }

        bitboard black = pos->maps[b_pieces] | passant_bit;

        // left/right/forward contain the start squares of pawns that can perform those moves.
        bitboard left_attacks  = (((pawns & (~a_file)) << 7) & black) >> 7;
        bitboard right_attacks = (((pawns & (~h_file)) << 9) & black) >> 9;
        bitboard forward = ((pawns << 8) & (~black)) >> 8;
        bitboard double_forward = ((((pawns & rank_2) & forward) << 16) & (~black)) >> 16;

        string src, dest;

        // Loop over pawns and generate appropriate moves.
        int index = __builtin_ffsll(pawns) - 1;
        while (index != -1) {

            bitboard squarei = squares[index];
            src = bit_to_square.at(squarei);

            if (squarei & left_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index+7]);
                if (dest.at(1) == '8') { dest += 'q'; }
                add_move(pos, &pawnmove, src, dest);
            }
            if (squarei & right_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index+9]);
                if (dest.at(1) == '8') { dest += 'q'; }
                add_move(pos, &pawnmove, src, dest);
            }
            if (squarei & forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index+8]);
                if (dest.at(1) == '8') { dest += 'q'; }
                add_move(pos, &pawnmove, src, dest);
            }
            if (squarei & double_forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index+16]);
                add_move(pos, &pawnmove, src, dest);
            }

            pawns = pawns & (~squarei);
            index = __builtin_ffsll(pawns) - 1;
        }
    }
    return;
}

void generate_w_knight_moves(Position* pos) {
    bitboard knights = pos->maps[w_knight];
    bitboard white = pos->maps[w_pieces];

    // Loop over the knights on the board
    int index = __builtin_ffsll(knights) - 1;
    while (index != -1) {
        bitboard squarei = squares[index];
        bitboard attacks = knight_moves[index] & ~(white);

        string src =  bit_to_square.at(squarei);

        // Loop over the current knights attacks and add positions
        int inner_index = __builtin_ffsll(attacks) - 1;
        while (inner_index != -1) {
            bitboard squarej = squares[inner_index];
            Position knightmove(*pos);
            string dest = bit_to_square.at(squarej);
            add_move(pos, &knightmove, src, dest);

            attacks = attacks & (~squarej);
            inner_index = __builtin_ffsll(attacks) - 1;
        }
        knights = knights & (~squarei);
        index = __builtin_ffsll(knights) - 1;
    }
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
    bitboard pawns = pos->maps[b_pawn];
    // check if there are any pawns to generate moves for
    if (pawns) {
        bitboard passant_bit = 0;
        if (pos->passant_target_sq != "-") {
            passant_bit = squares[get_square_num(pos->passant_target_sq)];
        }

        bitboard white = pos->maps[w_pieces] | passant_bit;

        // left/right/forward contain the start squares of pawns that can perform those moves.
        bitboard left_attacks  = (((pawns & (~h_file)) >> 7) & white) << 7;
        bitboard right_attacks = (((pawns & (~a_file)) >> 9) & white) << 9;
        bitboard forward = ((pawns >> 8) & (~white)) << 8;
        bitboard double_forward = ((((pawns & rank_7) & forward) >> 16) & (~white)) << 16;

        string src, dest;

        // Loop over pawns and generate appropriate moves.
        int index = __builtin_ffsll(pawns) - 1;
        while (index != -1) {

            bitboard squarei = squares[index];
            src = bit_to_square.at(squarei);

            if (squarei & left_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index-7]);
                if (dest.at(1) == '8') { dest += 'q'; }
                add_move(pos, &pawnmove, src, dest);
            }
            if (squarei & right_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index-9]);
                if (dest.at(1) == '1') { dest += 'q'; }
                add_move(pos, &pawnmove, src, dest);
            }
            if (squarei & forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index-8]);
                if (dest.at(1) == '1') { dest += 'q'; }
                add_move(pos, &pawnmove, src, dest);
            }
            if (squarei & double_forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[index-16]);
                add_move(pos, &pawnmove, src, dest);
            }

            pawns = pawns & (~squarei);
            index = __builtin_ffsll(pawns) - 1;
        }
    }
    return;
}

void generate_b_knight_moves(Position* pos) {
    bitboard knights = pos->maps[b_knight];
    bitboard black = pos->maps[b_pieces];

    // Loop over the knights on the board
    int index = __builtin_ffsll(knights) - 1;
    while (index != -1) {
        bitboard squarei = squares[index];
        bitboard attacks = knight_moves[index] & ~(black);

        string src =  bit_to_square.at(squarei);

        // Loop over the current knights attacks and add positions
        int inner_index = __builtin_ffsll(attacks) - 1;
        while (inner_index != -1) {
            bitboard squarej = squares[inner_index];
            Position knightmove(*pos);
            string dest = bit_to_square.at(squarej);
            add_move(pos, &knightmove, src, dest);

            attacks = attacks & (~squarej);
            inner_index = __builtin_ffsll(attacks) - 1;
        }
        knights = knights & (~squarei);
        index = __builtin_ffsll(knights) - 1;
    }
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

