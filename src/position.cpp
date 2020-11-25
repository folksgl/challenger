#include "position.hpp"
#include "evaluate.hpp"
#include "genmove.hpp"
#include "game_variables.hpp"
#include <cctype>
#include <string.h>
#include <sstream>
#include <iterator>
#include <algorithm>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Position::Position(string fen) {

    std::vector<std::string> results = split(fen, ' ');

    set_piece_positions(results[0]);
    set_active_color(results[1]);
    set_castling_rights(results[2]);
    set_passant_target_sq(results[3]);
    set_halfmove_clock(results[4]);
    set_fullmove_number(results[5]);

    eval_score = evaluate_position(this);
}

void Position::generate_moves() {
    moves.reserve(32);
    ::generate_moves(this);
    return;
}

void Position::evaluate() {
    eval_score = evaluate_position(this);
    return;
}

/*
 *  set_piece_positions sets the value of all the bitboards in a Position
 *  to the values found in fen_tok.
 */
void Position::set_piece_positions(std::string str) {

    // Split string on '/' character and reverse all strings in the resulting vector
    std::vector<std::string> piece_strings = split(str , '/');
    std::transform(piece_strings.begin(), piece_strings.end(), piece_strings.begin(), [](std::string str) { std::reverse(str.begin(), str.end()); return str;});

    string bit_oriented_string;
    for (const auto &str : piece_strings) {
        bit_oriented_string += str;
    }

    // Populate the Position from bit_oriented_string.
    int sq_num = 63;

    for (const char input : bit_oriented_string) {
        switch(input) {
            // Lower case = Black Pieces
            case 'p': maps[b_pawn]   or_eq square_bit(sq_num--); continue;
            case 'r': maps[b_rook]   or_eq square_bit(sq_num--); continue;
            case 'n': maps[b_knight] or_eq square_bit(sq_num--); continue;
            case 'b': maps[b_bishop] or_eq square_bit(sq_num--); continue;
            case 'q': maps[b_queen]  or_eq square_bit(sq_num--); continue;
            case 'k': maps[b_king]   or_eq square_bit(sq_num--); continue;

            // Upper case = White Pieces
            case 'P': maps[w_pawn]   or_eq square_bit(sq_num--); continue;
            case 'R': maps[w_rook]   or_eq square_bit(sq_num--); continue;
            case 'N': maps[w_knight] or_eq square_bit(sq_num--); continue;
            case 'B': maps[w_bishop] or_eq square_bit(sq_num--); continue;
            case 'Q': maps[w_queen]  or_eq square_bit(sq_num--); continue;
            case 'K': maps[w_king]   or_eq square_bit(sq_num--); continue;

            default :
                if (isdigit(input)) {
                    sq_num -= (input - '0');
                }
        }
    }

    maps[w_pieces] = maps[w_pawn] bitor maps[w_rook]  bitor maps[w_knight] bitor 
                        maps[w_bishop] bitor maps[w_queen] bitor maps[w_king];

    maps[b_pieces] = maps[b_pawn] bitor maps[b_rook]  bitor maps[b_knight] bitor 
                        maps[b_bishop] bitor maps[b_queen] bitor maps[b_king];

    return;
}

/*
 *  set_castling_rights sets the castling rights of the Position based on str
 */
void Position::set_castling_rights(std::string str) {

    // Check for malformed castling string. Set otherwise.
    if (str.length() > 0 and str.length() < 5) {
        for (char ch : str) {
            if (ch == 'K') {
                w_kingside_castle = true;
            }
            else if (ch == 'Q') {
                w_queenside_castle = true;
            }
            else if (ch == 'k') {
                b_kingside_castle = true;
            }
            else if (ch == 'q') {
                b_queenside_castle = true;
            }
        }
    }

    return;
}


/*
 *  set_active_color sets the active color in the Position based on str
 */
void Position::set_active_color(std::string str) {

    // Check for malformed active color string. Set otherwise.
    if (str.length() == 1) {
        is_white_move = (str == "w");
    }

    return;
}

/*
 *  set_passant_target_sq sets the passant target square for the Position based on str
 */
void Position::set_passant_target_sq(std::string str) {

    // If no target square or if malformed passant target string, assume there is none.
    if (str.length() == 2 and isalpha(str[0]) and isdigit(str[1])) {
        passant_sq = square_bit(get_square_num(str[0], str[1]));
    }

    return;
}

/*
 *  set_halfmove_clock sets the halfmove clock in Position based on str
 */
void Position::set_halfmove_clock(std::string str) {

    if (not str.empty() and std::all_of(str.begin(), str.end(), ::isdigit)) {
        hlf_clock = std::stoull(str, nullptr, 10);
    }

    return;
}

/*
 *  set_fullmove_number sets the fullmove number in Position based in str
 */
void Position::set_fullmove_number(std::string str) {

    if (not str.empty() and std::all_of(str.begin(), str.end(), ::isdigit)) {
        full_num = std::stoull(str, nullptr, 10);
    }
    return;
}

/*
 *  move performs the move given in the move string for the Position.
 */
void Position::move(const string& move, const int moving_piece) {

    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);


    // Check if there is a piece on the dest square and remove if needed.
    bitboard dest_square_bit = square_bit(dest_square);
    if ((maps[w_pieces] bitor maps[b_pieces]) bitand dest_square_bit) {
        zero_at(dest_square, get_moving_piece(dest_square));
        hlf_clock = -1;
    }

    if (moving_piece == w_pawn) {

        // If capturing en passant, remove the captured pawn
        if (dest_square_bit bitand passant_sq) {
            zero_at(dest_square - 8, b_pawn);
        }
        hlf_clock = -1;
    }
    else if (moving_piece == b_pawn) {

        if (dest_square_bit bitand passant_sq) {
            zero_at(dest_square + 8, w_pawn);
        }
        hlf_clock = -1;
    }
    else if (moving_piece == w_king) {
        w_kingside_castle = false;
        w_queenside_castle = false;
        hlf_clock = -1;
    }
    else if (moving_piece == b_king) {
        b_kingside_castle = false;
        b_queenside_castle = false;
        hlf_clock = -1;
    }
    else if (moving_piece == w_rook or moving_piece == b_rook) {
        if (start_square == 0) {
            w_queenside_castle = false;
        }
        else if (start_square == 7) {
            w_kingside_castle = false;
        }
        else if (start_square == 56) {
            b_queenside_castle = false;
        }
        else if (start_square == 63) {
            b_kingside_castle = false;
        }

        hlf_clock = -1;
    }

    passant_sq = 0;

    // Zero out the starting square
    zero_at(start_square, moving_piece);

    // Set the destination square
    bitboard square_to_add = dest_square_bit;
    maps[moving_piece] or_eq square_to_add;

    if (moving_piece < 6) {
        maps[w_pieces] or_eq square_to_add;
    }
    else {
        maps[b_pieces] or_eq square_to_add;
    }
    
    // When active color is black(1) increments the fullmove number, but prevents branching based off the active color.
    full_num += not is_white_move;
    hlf_clock++; // Toggle halfmove clock.
    is_white_move = not is_white_move; // Toggle active color.

    return;
}

/*
 *  move_pawn_promotion performs pawn promotion given in the move string
 */
void Position::move_pawn_promotion(const string& move) {

    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);


    bitboard dest_square_bit = square_bit(dest_square);
    if ((maps[w_pieces] bitor maps[b_pieces]) bitand dest_square_bit) {
        zero_at(dest_square, get_moving_piece(dest_square));
    }

    // Check if there is a piece on the dest square and remove if needed.
    int dest_piece = get_moving_piece(dest_square);

    if (dest_piece != -1) {
        zero_at(dest_square, dest_piece);
    }

    // Get the piece that is moving
    int piece = is_white_move ? w_pawn : b_pawn;

    // Reset the en passant square.
    passant_sq = 0;

    zero_at(start_square, piece);

    char promoted_to = move.at(4);
    switch (promoted_to) {
        case 'q': piece = b_queen;  break;
        case 'Q': piece = w_queen;  break;
        case 'N': piece = w_knight; break;
        case 'n': piece = b_knight; break;
        case 'B': piece = w_bishop; break;
        case 'b': piece = b_bishop; break;
        case 'R': piece = w_rook;   break;
        case 'r': piece = b_rook;   break;
    }

    // Set the destination square
    bitboard square_to_add = dest_square_bit;
    maps[piece] or_eq square_to_add;

    if (piece < 6) {
        maps[w_pieces] or_eq square_to_add;
    }
    else {
        maps[b_pieces] or_eq square_to_add;
    }

    full_num += not is_white_move; // Increment fullmove number.
    hlf_clock = 0;            // Toggle halfmove clock.
    is_white_move = not is_white_move;   // Toggle active color.

    return;
}

/*
 *  move_pawn_double_forward() performs pawn promotion given in the move string on board_position.
 */
void Position::move_pawn_double_forward(const string& move) {

    if (move.length() != 4) {
        // Malformed move string, ignore move and don't change the position.
        return;
    }

    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);

    // Get the piece that is moving
    int piece = is_white_move ? w_pawn : b_pawn;

    // Set the en passant square.
    passant_sq = is_white_move? square_bit(dest_square - 8) : square_bit(dest_square + 8);

    zero_at(start_square, piece);

    // Set the destination square
    bitboard square_to_add = square_bit(dest_square);
    maps[piece] or_eq square_to_add;

    if (piece < 6) {
        maps[w_pieces] or_eq square_to_add;
    }
    else {
        maps[b_pieces] or_eq square_to_add;
    }

    full_num += not is_white_move; // Increment fullmove number.
    hlf_clock = 0;            // Toggle halfmove clock.
    is_white_move = not is_white_move;   // Toggle active color.

    return;
}

void Position::castle(Castling_names type) {

    // reset the en passant square.
    passant_sq = 0;

    if (type == c_w_king) {
        maps[w_king] xor_eq 0x0000000000000050;
        maps[w_rook] xor_eq 0x00000000000000A0;
        maps[w_pieces] xor_eq 0x00000000000000F0;

        w_kingside_castle = false;
        w_queenside_castle = false;
    }
    else if (type == c_w_queen) {
        maps[w_king] xor_eq 0x0000000000000014;
        maps[w_rook] xor_eq 0x0000000000000009;
        maps[w_pieces] xor_eq 0x000000000000001D;

        w_kingside_castle = false;
        w_queenside_castle = false;
    }
    else if (type == c_b_king) {
        maps[b_king] xor_eq 0x5000000000000000;
        maps[b_rook] xor_eq 0xA000000000000000;
        maps[b_pieces] xor_eq 0xF000000000000000;

        b_kingside_castle = false;
        b_queenside_castle = false;
    }
    else {
        maps[b_king] xor_eq 0x1400000000000000;
        maps[b_rook] xor_eq 0x0900000000000000;
        maps[b_pieces] xor_eq 0x1D00000000000000;

        b_kingside_castle = false;
        b_queenside_castle = false;
    }

    full_num += not is_white_move; // Increment fullmove number.
    hlf_clock = 0;            // Toggle halfmove clock.
    is_white_move = not is_white_move;   // Toggle active color.

    return;
}

/*
 *  zero_at zero's the bit indicated by square on the position given and
 *  set a number representing the piece type that was in the square.
 *
 *  return whether a bit was cleared from the square
 */
void Position::zero_at(int square, int piece) {

    bitboard mask = compl square_bit(square);

    maps[w_pieces] and_eq mask;
    maps[b_pieces] and_eq mask;
    maps[piece] and_eq mask;
}

int Position::get_moving_piece(int square) {
    bitboard bit = square_bit(square);

    int i = bit bitand maps[w_pieces] ? 0 : 7;

    for (; i < 14; i++) {
        if (maps[i] bitand bit) {
            return i;
        }
    }

    return -1;
}

bool Position::is_square_attacked(bitboard square) {

    if (not square) return false;

    bitboard whole_board = maps[w_pieces] bitor maps[b_pieces];
    bitboard pawns, bishops, rooks, knights, king, attackers;
    int index = lsb_unsafe(square);

    if (is_white_move) {
        pawns = maps[w_pawn];
        bishops = maps[w_bishop] bitor maps[w_queen];
        rooks = maps[w_rook] bitor maps[w_queen];
        knights = maps[w_knight];
        king = maps[w_king];

        attackers = ((pawns bitand not_a_file) << 7) bitand square;
        attackers or_eq ((pawns bitand not_h_file) << 9) bitand square;
    }
    else {
        pawns = maps[b_pawn];
        bishops = maps[b_bishop] bitor maps[b_queen];
        rooks = maps[b_rook] bitor maps[b_queen];
        knights = maps[b_knight];
        king = maps[b_king];

        attackers = ((pawns bitand not_h_file) >> 7) bitand square;
        attackers or_eq ((pawns bitand not_a_file) >> 9) bitand square;
    }

    attackers or_eq (slider_attacks.RookAttacks(whole_board, index) bitand rooks);
    attackers or_eq (slider_attacks.BishopAttacks(whole_board, index) bitand bishops);
    attackers or_eq (knight_moves[index] bitand knights);
    attackers or_eq (king_moves[index] bitand king);
    
    return attackers;
}

string Position::to_fen_string() {
    string fenstring = "";

    // Loop through all 64 squares on the board
    for (int i = 63; i >= 0; i--) {
        // Fen string construction begins on the left of the rank (i.e. every 8th square)
        if ((i % 8) == 0) {
            // add current rank
            int empty = 0;

            // Loop over the entire rank
            for (int j = 0; j < 8; j++) {
                bitboard cur_square = square_bit(i + j);

                // Check for an empty square
                if (not ((maps[w_pieces] bitor maps[b_pieces]) bitand cur_square)) {
                    empty++;
                    if (j == 7) { fenstring += to_string(empty); }
                    continue;
                }
                // Position was not empty, check if there was an empty streak to add to the fen.
                if (empty != 0) {
                    fenstring += to_string(empty);
                    empty = 0;
                }
                
                // Add the piece to the fen string
                if      (maps[w_pawn]   bitand cur_square) { fenstring += "P"; }
                else if (maps[b_pawn]   bitand cur_square) { fenstring += "p"; }
                else if (maps[w_rook]   bitand cur_square) { fenstring += "R"; }
                else if (maps[b_rook]   bitand cur_square) { fenstring += "r"; }
                else if (maps[w_bishop] bitand cur_square) { fenstring += "B"; }
                else if (maps[b_bishop] bitand cur_square) { fenstring += "b"; }
                else if (maps[w_knight] bitand cur_square) { fenstring += "N"; }
                else if (maps[b_knight] bitand cur_square) { fenstring += "n"; }
                else if (maps[w_queen]  bitand cur_square) { fenstring += "Q"; }
                else if (maps[b_queen]  bitand cur_square) { fenstring += "q"; }
                else if (maps[w_king]   bitand cur_square) { fenstring += "K"; }
                else if (maps[b_king]   bitand cur_square) { fenstring += "k"; }
            }
            // add / on to the end of every rank but the last one
            if ((i - 8) >= 0) {
                fenstring += "/";
            }
        }
    }

    fenstring += ' ';
    fenstring += (is_white_move) ? 'w' : 'b';
    fenstring += ' ';

    string castling = "";

    if (w_kingside_castle) { castling += "K"; }
    if (w_queenside_castle) { castling += "Q"; }
    if (b_kingside_castle) { castling += "k"; }
    if (b_queenside_castle) { castling += "q"; }

    if (castling.empty()) {
        castling += "-";
    }

    fenstring += castling + " ";
    fenstring += bit_to_square.at(passant_sq) + " ";
    fenstring += to_string(hlf_clock) + " ";
    fenstring += to_string(full_num);

    return fenstring;
}

