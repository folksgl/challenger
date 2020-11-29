#include "genmove.hpp"

/*
 *  generate_moves takes in a position and generates all possible moves for that position, 
 *  storing the resulting positions in the moves vector for the position.
 */
void generate_moves(Position* pos) {
    bitboard not_own;

    if (pos->is_white_move) {
        not_own = compl (pos->maps[w_pieces]);

        generate_w_pawn_moves(pos);

        leaper_generator (pos, not_own, knight_moves, w_knight);      // knight moves
        leaper_generator(pos, not_own, king_moves, w_king);         // king moves
        slide_generator(pos, pos->maps[w_bishop], not_own, &get_bishop_attacks, w_bishop); // bishop moves
        slide_generator(pos, pos->maps[w_rook],   not_own, &get_rook_attacks, w_rook);   // rook moves
        slide_generator(pos, pos->maps[w_queen],  not_own, &get_queen_attacks, w_queen);  // queen moves

        castling_generator_w(pos);
    }
    else {
        not_own = compl (pos->maps[b_pieces]);

        generate_b_pawn_moves(pos);

        leaper_generator (pos, not_own, knight_moves, b_knight);      // knight moves
        leaper_generator (pos, not_own, king_moves, b_king);        // king moves
        slide_generator(pos, pos->maps[b_bishop], not_own, &get_bishop_attacks, b_bishop); // bishop moves
        slide_generator(pos, pos->maps[b_rook],   not_own, &get_rook_attacks, b_rook);   // rook moves
        slide_generator(pos, pos->maps[b_queen],  not_own, &get_queen_attacks, b_queen);  // queen moves

        castling_generator_b(pos);
    }
}

void add_move(Position* pos, const string& move_string, const map_names king_piece, const int moving_piece) {
    // Create a copy of the position and make the move
    Position copy = *pos;
    copy.move(move_string, moving_piece);

    // If the move introduces check for the player making the move, it is illegal and will not be considered.
    if (not copy.is_square_attacked(copy.maps[king_piece])) {
        // Add the move to the vector of moves possible from the current position.
        pos->moves.push_back(copy);
    }
}

void add_move_pawn_promotion(Position* pos, const string& move_string, map_names king_piece, const int moving_piece) {
    // Create a copy of the position and make the move
    Position copy_queen = *pos;
    string queen_string, rook_string, knight_string, bishop_string;

    if (copy_queen.is_white_move) {
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
    copy_queen.move(move_string + queen_string, moving_piece);

    // If the move introduces check for the player making the move, it is illegal and will not be considered.
    if (copy_queen.is_square_attacked(copy_queen.maps[king_piece])) {
        return; 
    }

    // Create copies of the position for all possible promotions
    Position copy_rook = Position(*pos);
    Position copy_knight = Position(*pos);
    Position copy_bishop = Position(*pos);

    // Perform the moves
    copy_rook.move(move_string + rook_string, moving_piece);
    copy_knight.move(move_string + knight_string, moving_piece);
    copy_bishop.move(move_string + bishop_string, moving_piece);

    // Add the moves to the vector of moves possible from the current position
    pos->moves.push_back(copy_queen);
    pos->moves.push_back(copy_rook);
    pos->moves.push_back(copy_knight);
    pos->moves.push_back(copy_bishop);
}

void add_move_castle(Position* pos, const string& move_string, const int moving_piece) {
    // Create a copy of the position and make the move
    Position copy = Position(*pos);
    copy.move(move_string, moving_piece);

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

void leaper_generator(Position* pos, bitboard not_own_pieces, const bitboard* attack_table, const int moving_piece) {
    bitboard leaper = pos->maps[moving_piece];
    map_names king_piece = pos->is_white_move ? w_king : b_king;
    // Loop over the leaper on the board
    while (leaper) {
        int index = lsb_unsafe(leaper);
        bitboard attacks = attack_table[index] bitand not_own_pieces;

        string src =  bit_to_square_arr[index];

        // Loop over the current leaper pieces attacks and add positions
        while (attacks) {
            int inner_index = lsb_unsafe(attacks);
            add_move(pos, src + bit_to_square_arr[inner_index], king_piece, moving_piece);

            // "Increment" loop index.
            attacks xor_eq square_bit(inner_index);
        }
        // "Increment" loop index.
        leaper xor_eq square_bit(index);
    }
}

void slide_generator(Position* pos, bitboard slider, bitboard not_own_pieces, bitboard (*attack_function)(bitboard, int), const int moving_piece) {
    map_names king_piece = pos->is_white_move ? w_king : b_king;
    bitboard whole_board = pos->maps[w_pieces] bitor pos->maps[b_pieces];

    while (slider) {
        int index = lsb_unsafe(slider);
        string src =  bit_to_square_arr[index];
        bitboard attacks = (*attack_function)(whole_board, index);
        attacks and_eq not_own_pieces;

        // Loop over the current bishop attacks and add positions
        while (attacks) {
            int inner_index = lsb_unsafe(attacks);
            add_move(pos, src + bit_to_square_arr[inner_index], king_piece, moving_piece);

            attacks xor_eq square_bit(inner_index);
        }
        slider xor_eq square_bit(index);
    }
}

void castling_generator_w(Position* pos) {
    Position opposite_turn = Position((*pos));
    opposite_turn.is_white_move = not opposite_turn.is_white_move; // Toggle active color.
    bitboard whole_board = pos->maps[w_pieces] bitor pos->maps[b_pieces];

    // If king is not present on the initial square, do not add moves
    if (not (pos->maps[w_king] bitand square_bit(4))) {
        return;
    }

    // Check castling availability
    if (pos->w_kingside_castle) {
        if (pos->maps[w_rook] bitand square_bit(7)) {
            if (not (whole_board bitand w_kingside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(square_bit(4)) or 
                        opposite_turn.is_square_attacked(square_bit(5)) or 
                        opposite_turn.is_square_attacked(square_bit(6)));
                if (not enters_check) {
                    add_move_castle(pos, "e1g1", w_king);
                }
            }
        }
    }
    if (pos->w_queenside_castle) {
        if (pos->maps[w_rook] bitand square_bit(0)) { 
            if (not (whole_board bitand w_queenside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(square_bit(2)) or
                        opposite_turn.is_square_attacked(square_bit(3)) or
                        opposite_turn.is_square_attacked(square_bit(4)));
                if (not enters_check) {
                    add_move_castle(pos, "e1c1", w_king);
                }
            }
        }
    }
}

void castling_generator_b(Position* pos) {
    Position opposite_turn = Position((*pos));
    opposite_turn.is_white_move = not opposite_turn.is_white_move; // Toggle active color.
    bitboard whole_board = pos->maps[w_pieces] bitor pos->maps[b_pieces];

    if (pos->b_kingside_castle) {
        if (pos->maps[b_rook] bitand square_bit(63)) {
            if (not (whole_board bitand b_kingside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(square_bit(60)) or 
                        opposite_turn.is_square_attacked(square_bit(61)) or 
                        opposite_turn.is_square_attacked(square_bit(62)));
                if (not enters_check) {
                    add_move_castle(pos, "e8g8", b_king);
                }
            }
        }
    }
    if (pos->b_queenside_castle) {
        if (pos->maps[b_rook] bitand square_bit(56)) {
            if (not (whole_board bitand b_queenside_castle_empty)) {
                bool enters_check = (opposite_turn.is_square_attacked(square_bit(60)) or 
                        opposite_turn.is_square_attacked(square_bit(59)) or
                        opposite_turn.is_square_attacked(square_bit(58)));
                if (not enters_check) {
                    add_move_castle(pos, "e8c8", b_king);
                }
            }
        }
    }
}

void generate_w_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[w_pawn];

    bitboard black = pos->maps[b_pieces] bitor pos->passant_sq;
    bitboard unoccupied = compl (pos->maps[w_pieces] bitor pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = pawns bitand ((black bitand not_h_file) >> 7);
    bitboard right_attacks = pawns bitand ((black bitand not_a_file) >> 9);
    bitboard forward = pawns bitand (unoccupied >> 8);
    bitboard double_forward = (rank_2 bitand forward) bitand (unoccupied >> 16);

    map_names king_piece = pos->is_white_move ? w_king : b_king;
    // Loop over pawns and generate appropriate moves.
    while (pawns) {
        int index = lsb_unsafe(pawns);

        bitboard squarei = square_bit(index);
        string src = bit_to_square_arr[index];

        if (squarei bitand rank_7) {
            if (squarei bitand left_attacks) {
                add_move_pawn_promotion(pos, src + bit_to_square_arr[index + 7], king_piece, w_pawn);
            }
            if (squarei bitand right_attacks) {
                add_move_pawn_promotion(pos, src + bit_to_square_arr[index + 9], king_piece, w_pawn);
            }
            if (squarei bitand forward) {
                add_move_pawn_promotion(pos, src + bit_to_square_arr[index + 8], king_piece, w_pawn);
            }
        }
        else {
            if (squarei bitand left_attacks) {
                add_move(pos, src + bit_to_square_arr[index + 7], king_piece, w_pawn);
            }
            if (squarei bitand right_attacks) {
                add_move(pos, src + bit_to_square_arr[index + 9], king_piece, w_pawn);
            }
            if (squarei bitand forward) {
                add_move(pos, src + bit_to_square_arr[index + 8], king_piece, w_pawn);

                if (squarei bitand double_forward) {
                    add_move(pos, src + bit_to_square_arr[index + 16], king_piece, w_pawn);
                }
            }
        }

        pawns xor_eq squarei;
    }
    return;
}

void generate_b_pawn_moves(Position* pos) {
    bitboard pawns = pos->maps[b_pawn];

    bitboard white = pos->maps[w_pieces] bitor pos->passant_sq;
    bitboard unoccupied = compl (pos->maps[w_pieces] bitor pos->maps[b_pieces]);

    // left/right/forward contain the start squares of pawns that can perform those moves.
    bitboard left_attacks  = pawns bitand ((white bitand not_a_file) << 7);
    bitboard right_attacks = pawns bitand ((white bitand not_h_file) << 9);
    bitboard forward = pawns bitand (unoccupied << 8);
    bitboard double_forward = (rank_7 bitand forward) bitand (unoccupied << 16);

    map_names king_piece = pos->is_white_move ? w_king : b_king;
    // Loop over pawns and generate appropriate moves.
    while (pawns) {
        int index = lsb_unsafe(pawns);

        bitboard squarei = square_bit(index);
        string src = bit_to_square_arr[index];

        if (squarei bitand rank_2) {
            if (squarei bitand left_attacks) {
                add_move_pawn_promotion(pos, src + bit_to_square_arr[index - 7], king_piece, b_pawn);
            }
            if (squarei bitand right_attacks) {
                add_move_pawn_promotion(pos, src + bit_to_square_arr[index - 9], king_piece, b_pawn);
            }
            if (squarei bitand forward) {
                add_move_pawn_promotion(pos, src + bit_to_square_arr[index - 8], king_piece, b_pawn);
            }
        }
        else {
            if (squarei bitand left_attacks) {
                add_move(pos, src + bit_to_square_arr[index - 7], king_piece, b_pawn);
            }
            if (squarei bitand right_attacks) {
                add_move(pos, src + bit_to_square_arr[index - 9], king_piece, b_pawn);
            }
            if (squarei bitand forward) {
                add_move(pos, src + bit_to_square_arr[index - 8], king_piece, b_pawn);

                if (squarei bitand double_forward) {
                    add_move(pos, src + bit_to_square_arr[index - 16], king_piece, b_pawn);
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
