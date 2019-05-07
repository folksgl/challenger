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

    bitboard passant_bit;
    if (pos->passant_target_sq == "-" || pos->passant_target_sq.empty()) {
        passant_bit = 0;
    }
    else {
        passant_bit = squares[get_square_num(pos->passant_target_sq)];
    }

    bitboard pawns = pos->maps[w_pawn];
    bitboard black = pos->maps[b_pieces] | passant_bit;

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = (((pawns & (~a_file)) << 7) & black) >> 7;
    bitboard right_attacks = (((pawns & (~h_file)) << 9) & black) >> 9;
    bitboard forward = ((pawns << 8) & (~black)) >> 8;
    bitboard double_forward = ((((pawns & rank_2) & forward) << 16) & (~black)) >> 16;

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    for (int i = 0; i < 64; i++) {
        // Found a pawn; check for 4 possible moves
        if (squares[i] & pawns) {
            src = bit_to_square.at(squares[i]);

            if (squares[i] & left_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i+7]);
                if (dest.at(1) == '8') { dest += 'q'; }
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
            if (squares[i] & right_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i+9]);
                if (dest.at(1) == '8') { dest += 'q'; }
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
            if (squares[i] & forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i+8]);
                if (dest.at(1) == '8') { dest += 'q'; }
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
            if (squares[i] & double_forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i+16]);
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
        }
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

    bitboard passant_bit;
    if (pos->passant_target_sq == "-" || pos->passant_target_sq.empty()) {
        passant_bit = 0;
    }
    else {
        passant_bit = squares[get_square_num(pos->passant_target_sq)];
    }

    bitboard pawns = pos->maps[b_pawn];
    bitboard white = pos->maps[w_pieces] | passant_bit;

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = (((pawns & (~h_file)) >> 7) & white) << 7;
    bitboard right_attacks = (((pawns & (~a_file)) >> 9) & white) << 9;
    bitboard forward = ((pawns >> 8) & (~white)) << 8;
    bitboard double_forward = ((((pawns & rank_7) & forward) >> 16) & (~white)) << 16;

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    for (int i = 0; i < 64; i++) {
        // Found a pawn; check for 4 possible moves
        if (squares[i] & pawns) {
            src = bit_to_square.at(squares[i]);

            if (squares[i] & left_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i-7]);
                if (dest.at(1) == '8') { dest += 'q'; }
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
            if (squares[i] & right_attacks) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i-9]);
                if (dest.at(1) == '1') { dest += 'q'; }
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
            if (squares[i] & forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i-8]);
                if (dest.at(1) == '1') { dest += 'q'; }
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
            if (squares[i] & double_forward) {
                Position pawnmove(*pos);
                dest = bit_to_square.at(squares[i-16]);
                pawnmove.movestring = src + dest;
                pawnmove.move(src+dest);
                pawnmove.evaluate();
                pos->moves.push_back(pawnmove);
            }
        }
    }
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

