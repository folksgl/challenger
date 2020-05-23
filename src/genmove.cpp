#include "genmove.hpp"

/*
 *  generate_moves takes in a position and generates all possible moves for that position, 
 *  storing the resulting positions in the moves vector for the position.
 */
void generate_moves(Position* pos) {
    bitboard not_own;

    if (pos->is_white_move()) {
        not_own = compl (pos->maps[w_pieces]);

        generate_w_pawn_moves(pos);

        leaper_generator (pos, pos->maps[w_knight], not_own, knight_moves);                    // knight moves
        leaper_generator (pos, pos->maps[w_king],   not_own, king_moves);                      // king moves
        slide_generator(pos, pos->maps[w_bishop], not_own, &get_bishop_attacks); // bishop moves
        slide_generator(pos, pos->maps[w_rook],   not_own, &get_rook_attacks);   // rook moves
        slide_generator(pos, pos->maps[w_queen],  not_own, &get_queen_attacks);  // queen moves

        castling_generator_w(pos);
    }
    else {
        not_own = compl (pos->maps[b_pieces]);

        generate_b_pawn_moves(pos);

        leaper_generator (pos, pos->maps[b_knight], not_own, knight_moves);                    // knight moves
        leaper_generator (pos, pos->maps[b_king],   not_own, king_moves);                      // king moves
        slide_generator(pos, pos->maps[b_bishop], not_own, &get_bishop_attacks); // bishop moves
        slide_generator(pos, pos->maps[b_rook],   not_own, &get_rook_attacks);   // rook moves
        slide_generator(pos, pos->maps[b_queen],  not_own, &get_queen_attacks);  // queen moves

        castling_generator_b(pos);
    }
}

void add_move(Position* pos, const string& src, const string& dest) {
    // Create a copy of the position and make the move
    Position copy = Position(*pos);
    copy.move(src + dest);

    // If the move introduces check for the player making the move, it is illegal and will not be considered.
    bitboard king_square = copy.is_white_move() ? copy.maps[b_king] : copy.maps[w_king];
    if (not copy.is_square_attacked(king_square)) {
        // Add the move to the vector of moves possible from the current position.
        pos->moves.push_back(copy);
    }
}

void add_move_pawn_promotion(Position* pos, const string& src, const string& dest) {
    // Create a copy of the position and make the move
    Position copy_queen = Position(*pos);
    string queen_string, rook_string, knight_string, bishop_string;

    if (copy_queen.is_white_move()) {
        queen_string = "Q";
        rook_string = "R";
        knight_string = "N";
        bishop_string = "B";
    }
    else {
        queen_string = "q";
        rook_string = "r";
        knight_string = "n";
        bishop_string = "b";
    }
    copy_queen.move_pawn_promotion(src + dest + queen_string);

    // If the move introduces check for the player making the move, it is illegal and will not be considered.
    bitboard king_square = copy_queen.is_white_move() ? copy_queen.maps[b_king] : copy_queen.maps[w_king];
    if (copy_queen.is_square_attacked(king_square)) {
        return; 
    }

    // Create copies of the position for all possible promotions
    Position copy_rook = Position(*pos);
    Position copy_knight = Position(*pos);
    Position copy_bishop = Position(*pos);

    // Perform the moves
    copy_rook.move_pawn_promotion(src + dest + rook_string);
    copy_knight.move_pawn_promotion(src + dest + knight_string);
    copy_bishop.move_pawn_promotion(src + dest + bishop_string);

    // Add the moves to the vector of moves possible from the current position
    pos->moves.push_back(copy_queen);
    pos->moves.push_back(copy_rook);
    pos->moves.push_back(copy_knight);
    pos->moves.push_back(copy_bishop);
}

void add_move_pawn_double_forward(Position* pos, const string& src, const string& dest) {
    // Create a copy of the position and make the move
    Position copy = Position(*pos);
    copy.move_pawn_double_forward(src + dest);

    // If the move introduces check for the player making the move, it is illegal and will not be considered.
    bitboard king_square = copy.is_white_move() ? copy.maps[b_king] : copy.maps[w_king];
    if (not copy.is_square_attacked(king_square)) {
        // Add the move to the vector of moves possible from the current position.
        pos->moves.push_back(copy);
    }
}

void add_move_castle(Position* pos, Castling_names type) {
    // Create a copy of the position and make the move
    Position copy = Position(*pos);
    copy.castle(type);

    // Add the move to the vector of moves possible from the current position.
    pos->moves.push_back(copy);
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

void leaper_generator(Position* pos, bitboard leaper, bitboard not_own_pieces, const bitboard* attack_table) {
    // Loop over the leaper on the board
    while (leaper) {
        int index = lsb_unsafe(leaper);
        bitboard attacks = attack_table[index] bitand not_own_pieces;

        string src =  bit_to_square_arr[index];

        // Loop over the current leaper pieces attacks and add positions
        while (attacks) {
            int inner_index = lsb_unsafe(attacks);
            string dest = bit_to_square_arr[inner_index];
            add_move(pos, src, dest);

            // "Increment" loop index.
            attacks xor_eq (one << inner_index);
        }
        // "Increment" loop index.
        leaper xor_eq (one << index);
    }
}

void slide_generator(Position* pos, bitboard slider, bitboard not_own_pieces, bitboard (*attack_function)(bitboard, int)) {
    bitboard whole_board = pos->maps[w_pieces] bitor pos->maps[b_pieces];

    while (slider) {
        int index = lsb_unsafe(slider);
        string src =  bit_to_square_arr[index];
        bitboard attacks = (*attack_function)(whole_board, index);
        attacks and_eq not_own_pieces;

        // Loop over the current bishop attacks and add positions
        while (attacks) {
            int inner_index = lsb_unsafe(attacks);
            string dest = bit_to_square_arr[inner_index];
            add_move(pos, src, dest);

            attacks xor_eq (one << inner_index);
        }
        slider xor_eq (one << index);
    }

    return;
}

void castling_generator_w(Position* pos) {
    Position opposite_turn = Position(*pos);
    opposite_turn.maps[act_color] xor_eq BLACK; // Toggle active color.
    bitboard whole_board = pos->maps[w_pieces] bitor pos->maps[b_pieces];

    // If no king present, don't attempt to castle
    if (not pos->maps[w_king]) {
        return;
    }

    if (pos->w_kingside_castle()) { // Check castling availability
        if (pos->maps[w_rook] bitand squares[7]) { // Ensure king and rook are on the board
            if (not (whole_board bitand w_kingside_castle_empty)) {     // Ensure the squares in-between are empty
                bool enters_check = (opposite_turn.is_square_attacked(squares[4]) or 
                        opposite_turn.is_square_attacked(squares[5]) or 
                        opposite_turn.is_square_attacked(squares[6]));
                if (not enters_check) {
                    add_move_castle(pos, c_w_king);
                }
            }
        }
    }
    if (pos->w_queenside_castle()) {
        if (pos->maps[w_king] and (pos->maps[w_rook] bitand squares[0])) { 
            if (not (whole_board bitand w_queenside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(squares[2]) or
                        opposite_turn.is_square_attacked(squares[3]) or
                        opposite_turn.is_square_attacked(squares[4]));
                if (not enters_check) {
                    add_move_castle(pos, c_w_queen);
                }
            }
        }
    }
}

void castling_generator_b(Position* pos) {
    Position opposite_turn = Position(*pos);
    opposite_turn.maps[act_color] xor_eq BLACK; // Toggle active color.
    bitboard whole_board = pos->maps[w_pieces] bitor pos->maps[b_pieces];

    if (pos->b_kingside_castle()) {
        if (pos->maps[b_king] and (pos->maps[b_rook] bitand squares[63])) {
            if (not (whole_board bitand b_kingside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(squares[60]) or 
                        opposite_turn.is_square_attacked(squares[61]) or 
                        opposite_turn.is_square_attacked(squares[62]));
                if (not enters_check) {
                    add_move_castle(pos, c_b_king);
                }
            }
        }
    }
    if (pos->b_queenside_castle()) {
        if (pos->maps[b_king] and (pos->maps[b_rook] bitand squares[56])) {
            if (not (whole_board bitand b_queenside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(squares[60]) or 
                        opposite_turn.is_square_attacked(squares[59]) or
                        opposite_turn.is_square_attacked(squares[58]));
                if (not enters_check) {
                    add_move_castle(pos, c_b_queen);
                }
            }
        }
    }
}

void generate_w_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[w_pawn];

    bitboard black = pos->maps[b_pieces] bitor pos->maps[passant_sq];
    bitboard unoccupied = (compl pos->maps[w_pieces]) bitand (compl pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = pawns bitand ((black bitand (compl h_file)) >> 7);
    bitboard right_attacks = pawns bitand ((black bitand (compl a_file)) >> 9);
    bitboard forward = pawns bitand (unoccupied >> 8);
    bitboard double_forward = (rank_2 bitand forward) bitand (unoccupied >> 16);

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    while (pawns) {
        int index = lsb_unsafe(pawns);

        bitboard squarei = squares[index];
        src = bit_to_square_arr[index];

        if (squarei bitand rank_7) {
            if (squarei bitand left_attacks) {
                dest = bit_to_square_arr[index+7];
                add_move_pawn_promotion(pos, src, dest);
            }
            if (squarei bitand right_attacks) {
                dest = bit_to_square_arr[index+9];
                add_move_pawn_promotion(pos, src, dest);
            }
            if (squarei bitand forward) {
                dest = bit_to_square_arr[index+8];
                add_move_pawn_promotion(pos, src, dest);
            }
        }
        else {
            if (squarei bitand left_attacks) {
                dest = bit_to_square_arr[index+7];
                add_move(pos, src, dest);
            }
            if (squarei bitand right_attacks) {
                dest = bit_to_square_arr[index+9];
                add_move(pos, src, dest);
            }
            if (squarei bitand forward) {
                dest = bit_to_square_arr[index+8];
                add_move(pos, src, dest);

                if (squarei bitand double_forward) {
                    dest = bit_to_square_arr[index+16];
                    add_move_pawn_double_forward(pos, src, dest);
                }
            }
        }

        pawns xor_eq squarei;
    }
    return;
}

void generate_b_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[b_pawn];

    bitboard white = pos->maps[w_pieces] bitor pos->maps[passant_sq];
    bitboard unoccupied = (compl pos->maps[w_pieces]) bitand (compl pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = pawns bitand ((white bitand (compl a_file)) << 7);
    bitboard right_attacks = pawns bitand ((white bitand (compl h_file)) << 9);
    bitboard forward = pawns bitand (unoccupied << 8);
    bitboard double_forward = (rank_7 bitand forward) bitand (unoccupied << 16);

    string src, dest;

    // Loop over pawns and generate appropriate moves.
    while (pawns) {
        int index = lsb_unsafe(pawns);

        bitboard squarei = squares[index];
        src = bit_to_square_arr[index];

        if (squarei bitand rank_2) {
            if (squarei bitand left_attacks) {
                dest = bit_to_square_arr[index-7];
                add_move_pawn_promotion(pos, src, dest);
            }
            if (squarei bitand right_attacks) {
                dest = bit_to_square_arr[index-9];
                add_move_pawn_promotion(pos, src, dest);
            }
            if (squarei bitand forward) {
                dest = bit_to_square_arr[index-8];
                add_move_pawn_promotion(pos, src, dest);
            }
        }
        else {
            if (squarei bitand left_attacks) {
                dest = bit_to_square_arr[index-7];
                add_move(pos, src, dest);
            }
            if (squarei bitand right_attacks) {
                dest = bit_to_square_arr[index-9];
                add_move(pos, src, dest);
            }
            if (squarei bitand forward) {
                dest = bit_to_square_arr[index-8];
                add_move(pos, src, dest);

                if (squarei bitand double_forward) {
                    dest = bit_to_square_arr[index-16];
                    add_move_pawn_double_forward(pos, src, dest);
                }
            }
        }

        pawns xor_eq squarei;
    }
    return;
}

#ifdef DEBUG
void PrintBitBoard(const bitboard bb) {
    for (int row = 7; row >= 0; --row) {
        for (int col = 0; col <= 7; ++col) {
            if (bb bitand (1ULL << ((row * 8) + col))) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}
#endif
