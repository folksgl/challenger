#include "position.hpp"
#include "evaluate.hpp"
#include "genmove.hpp"
#include "zobrist.hpp"
#include "game_variables.hpp"
#include <string.h>
#include <sstream>
#include <iterator>
#include <algorithm>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

Position::Position(string fen) {

    // Split the input string into tokens (delimited by space)
    std::vector<std::string> results = split(fen, ' ');

    set_piece_positions(results[0]);
    set_active_color(results[1]);
    set_castling_rights(results[2]);
    set_passant_target_sq(results[3]);
    set_halfmove_clock(results[4]);
    set_fullmove_number(results[5]);

    eval_score = evaluate_position(this);
    maps[zobrist_key] = zobrist.get_zobrist_key(this);
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
 *  set_piece_positions sets the value of all the bitboards in board_position
 *  to the values found in fen_tok.
 */
void Position::set_piece_positions(std::string fen_tok) {

    // Split string on '/' character and reverse all strings in the resulting vector
    std::vector<std::string> piece_strings = split(fen_tok, '/');
    std::transform(piece_strings.begin(), piece_strings.end(), piece_strings.begin(), [](std::string str) { std::reverse(str.begin(), str.end()); return str;});

    string bit_oriented_string;
    for (const auto &str : piece_strings) {
        bit_oriented_string += str;
    }

    // Create Position from bit_oriented_string.
    int sq_num = 63;
    int length = bit_oriented_string.length();

    for (int i = 0; i < length; i++) {
        char input = bit_oriented_string.at(i);
        switch(input) {
            // Lower case = Black Pieces
            case 'p': maps[b_pawn]   or_eq (one << sq_num--); break;
            case 'r': maps[b_rook]   or_eq (one << sq_num--); break;
            case 'n': maps[b_knight] or_eq (one << sq_num--); break;
            case 'b': maps[b_bishop] or_eq (one << sq_num--); break;
            case 'q': maps[b_queen]  or_eq (one << sq_num--); break;
            case 'k': maps[b_king]   or_eq (one << sq_num--); break;

            // Upper case = White Pieces
            case 'P': maps[w_pawn]   or_eq (one << sq_num--); break;
            case 'R': maps[w_rook]   or_eq (one << sq_num--); break;
            case 'N': maps[w_knight] or_eq (one << sq_num--); break;
            case 'B': maps[w_bishop] or_eq (one << sq_num--); break;
            case 'Q': maps[w_queen]  or_eq (one << sq_num--); break;
            case 'K': maps[w_king]   or_eq (one << sq_num--); break;

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
 *  set_castling_rights sets the value of castling_rights in board_position
 *  to the value found in fen_tok.
 */
void Position::set_castling_rights(std::string fen_tok) {

    if (fen_tok.length() < 1 or fen_tok.length() > 4) {
        // Castling right string is malformed, continue with no castling rights 
        return;
    }

    maps[castle_rights] = castle_string_to_index.at(fen_tok);

    return;
}


/*
 *  set_active_color sets the value of active_color in board_position
 *  to the value found in fen_tok.
 */
void Position::set_active_color(std::string fen_tok) {

    if (fen_tok.length() not_eq 1) {
        // Malformed active color string. Just assume that it is white's turn.
        return;
    }
    maps[act_color] = (fen_tok[0] == 'w') ? WHITE : BLACK;

    return;
}

/*
 *  set_passant_target_sq sets the value of passant_target_sq in board_position
 *  to the value found in fen_tok.
 */
void Position::set_passant_target_sq(std::string fen_tok) {

    if (fen_tok.length() < 1 or fen_tok.length() > 2 or !isalpha(fen_tok[0]) or !isdigit(fen_tok[1])) {
        // No target square or if malformed passant target string, assume there is none.
        return;
    }
    maps[passant_sq] = passant_string_to_bit.at(string(fen_tok));

    return;
}

/*
 *  set_halfmove_clock sets the value of halfmove_clock in board_position
 *  to the value found in fen_tok.
 */
void Position::set_halfmove_clock(std::string fen_tok) {

    for (unsigned int i = 0; i < fen_tok.length(); i++) {
        if (not isdigit(fen_tok[i])) {
            // Malformed clock string, just don't modify the clock and ignore token.
            return;
        }
    }

    char* end;

    maps[hlf_clock] = std::strtoull(fen_tok.c_str(), &end, 10);

    return;
}

/*
 *  set_fullmove_number sets the value of fullmove_number in board_position
 *  to the value found in fen_tok.
 */
void Position::set_fullmove_number(std::string fen_tok) {

    for (unsigned int i = 0; i < fen_tok.length(); i++) {
        if (not isdigit(fen_tok[i])) {
            // Malformed move number string, ignore token and don't modify move number.
            return;
        }
    }

    char* end;
    maps[full_num] = strtoul(fen_tok.c_str(), &end, 10);

    return;
}


/*
 *  move() performs the move given in the move string on board_position.
 */
void Position::move(string move) {

    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);


    // Check if there is a piece on the dest square and remove if needed.
    int dest_piece = get_moving_piece(dest_square);
    if (dest_piece != -1) {
        zero_at(dest_square, dest_piece);
        maps[hlf_clock] = 0 - 1;
    }

    // Get the piece that is moving
    int piece = get_moving_piece(start_square);

    if (piece == w_pawn) {

        // If capturing en passant, remove the captured pawn
        if (square_bit(dest_square) bitand maps[passant_sq]) {
            zero_at(dest_square - 8, b_pawn);
        }
        maps[hlf_clock] = 0 - 1;
    }
    else if (piece == b_pawn) {

        if (square_bit(dest_square) bitand maps[passant_sq]) {
            zero_at(dest_square + 8, w_pawn);
        }
        maps[hlf_clock] = 0 - 1;
    }
    else if (piece == w_king) {
        string removechars = "KQ";
        string rights = castle_index_to_string.at(maps[castle_rights]);

        for (char c: removechars) {
            rights.erase(remove(rights.begin(), rights.end(), c), rights.end());
        }

        maps[castle_rights] = castle_string_to_index.at(rights);
        maps[hlf_clock] = 0 - 1;
    }
    else if (piece == b_king) {
        string removechars = "kq";
        string rights = castle_index_to_string.at(maps[castle_rights]);

        for (char c: removechars) {
            rights.erase(remove(rights.begin(), rights.end(), c), rights.end());
        }

        maps[castle_rights] = castle_string_to_index.at(rights);
        maps[hlf_clock] = 0 - 1;
    }
    else if (piece == w_rook or piece == b_rook) {
        string removechars = "";
        if (start_square == 0) {
            removechars = "Q";
        }
        if (start_square == 7) {
            removechars = "K";
        }
        if (start_square == 56) {
            removechars = "q";
        }
        if (start_square == 63) {
            removechars = "k";
        }

        string rights = castle_index_to_string.at(maps[castle_rights]);

        for (char c: removechars) {
            rights.erase(remove(rights.begin(), rights.end(), c), rights.end());
        }

        maps[castle_rights] = castle_string_to_index.at(rights);
        maps[hlf_clock] = 0 - 1;
    }

    maps[passant_sq] = 0x0000000000000000;

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
    
    // When active color is black(1) increments the fullmove number, but prevents branching based off the active color.
    maps[full_num] += maps[act_color];
    maps[hlf_clock]++; // Toggle halfmove clock.
    maps[act_color] xor_eq BLACK; // Toggle active color.

    return;
}

/*
 *  move_pawn_promotion() performs pawn promotion given in the move string on board_position.
 */
void Position::move_pawn_promotion(string move) {

    if (move.length() != 5) {
        // Malformed move string, ignore move and don't change the position.
        return;
    }

    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);


    // Check if there is a piece on the dest square and remove if needed.
    int dest_piece = get_moving_piece(dest_square);

    if (dest_piece != -1) {
        zero_at(dest_square, dest_piece);
    }

    // Get the piece that is moving
    int piece = this->is_white_move() ? w_pawn : b_pawn;

    // Reset the en passant square.
    maps[passant_sq] = 0x0000000000000000;

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
    bitboard square_to_add = square_bit(dest_square);
    maps[piece] or_eq square_to_add;

    if (piece < 6) {
        maps[w_pieces] or_eq square_to_add;
    }
    else {
        maps[b_pieces] or_eq square_to_add;
    }

    maps[full_num] += maps[act_color]; // Increment fullmove number.
    maps[hlf_clock] = 0;            // Toggle halfmove clock.
    maps[act_color] xor_eq BLACK;   // Toggle active color.

    return;
}

/*
 *  move_pawn_double_forward() performs pawn promotion given in the move string on board_position.
 */
void Position::move_pawn_double_forward(string move) {

    if (move.length() != 4) {
        // Malformed move string, ignore move and don't change the position.
        return;
    }

    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);

    bool white_move = this->is_white_move();

    // Get the piece that is moving
    int piece = white_move ? w_pawn : b_pawn;

    // Set the en passant square.
    maps[passant_sq] = white_move? square_bit(dest_square - 8) : square_bit(dest_square + 8);

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

    maps[full_num] += maps[act_color]; // Increment fullmove number.
    maps[hlf_clock] = 0;            // Toggle halfmove clock.
    maps[act_color] xor_eq BLACK;   // Toggle active color.

    return;
}

void Position::castle(Castling_names type) {

    // reset the en passant square.
    maps[passant_sq] = 0x0000000000000000;
    string removechars = "KQ";

    if (type == c_w_king) {
        maps[w_king] xor_eq 0x0000000000000050;
        maps[w_rook] xor_eq 0x00000000000000A0;
        maps[w_pieces] xor_eq 0x00000000000000F0;
    }
    else if (type == c_w_queen) {
        maps[w_king] xor_eq 0x0000000000000014;
        maps[w_rook] xor_eq 0x0000000000000009;
        maps[w_pieces] xor_eq 0x000000000000001D;
    }
    else if (type == c_b_king) {
        maps[b_king] xor_eq 0x5000000000000000;
        maps[b_rook] xor_eq 0xA000000000000000;
        maps[b_pieces] xor_eq 0xF000000000000000;
        removechars = "kq";
    }
    else {
        maps[b_king] xor_eq 0x1400000000000000;
        maps[b_rook] xor_eq 0x0900000000000000;
        maps[b_pieces] xor_eq 0x1D00000000000000;
        removechars = "kq";
    }

    string rights = castle_index_to_string.at(maps[castle_rights]);

    for (char c: removechars) {
        rights.erase(remove(rights.begin(), rights.end(), c), rights.end());
    }

    maps[castle_rights] = castle_string_to_index.at(rights);

    maps[full_num] += maps[act_color]; // Increment fullmove number.
    maps[hlf_clock] = 0;            // Toggle halfmove clock.
    maps[act_color] xor_eq BLACK;   // Toggle active color.

    return;
}

/*
 *  zero_at zero's the bit indicated by square on the position given and
 *  set a number representing the piece type that was in the square.
 *
 *  return the map position of the piece changed
 */
void Position::zero_at(int square, int piece) {

    bitboard mask = compl (square_bit(square));

    maps[6 + (7 * (piece / 7))] and_eq mask;
    maps[piece] and_eq mask;

    return;
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
    bitboard attacked_squares;

    bitboard whole_board = maps[w_pieces] bitor maps[b_pieces];
    bitboard pawns, bishops, knights, rooks, king;

    bool is_white_move = this->is_white_move();

    if (is_white_move) {
        pawns = maps[w_pawn];
        bishops = maps[w_bishop] bitor maps[w_queen];
        rooks = maps[w_rook] bitor maps[w_queen];
        knights = maps[w_knight];
        king = maps[w_king];

        // Add pawn attacks
        attacked_squares = (pawns bitand not_a_file) << 7;
        attacked_squares or_eq (pawns bitand not_h_file) << 9;
    }
    else {
        pawns = maps[b_pawn];
        bishops = maps[b_bishop] bitor maps[b_queen];
        rooks = maps[b_rook] bitor maps[b_queen];
        knights = maps[b_knight];
        king = maps[b_king];

        // Add pawn attacks
        attacked_squares = (pawns bitand not_h_file) >> 7;
        attacked_squares or_eq (pawns bitand not_a_file) >> 9;
    }

    // Attempt to shortcircuit the rest of the method.
    if (square bitand attacked_squares) {
        return true;
    }

    // Add the Bishop slider attacks
    while (bishops) {
        int index = lsb_unsafe(bishops);
        attacked_squares or_eq slider_attacks.BishopAttacks(whole_board, index);
        // "Increment" loop index.
        bishops xor_eq square_bit(index);
    }

    // Attempt to shortcircuit the rest of the method.
    if (square bitand attacked_squares) {
        return true;
    }

    // Add the Rook slider attacks
    while (rooks) {
        int index = lsb_unsafe(rooks);
        attacked_squares or_eq slider_attacks.RookAttacks(whole_board, index);
        // "Increment" loop index.
        rooks xor_eq square_bit(index);
    }

    // Attempt to shortcircuit the rest of the method.
    if (square bitand attacked_squares) {
        return true;
    }

    while (knights) {
        int index = lsb_unsafe(knights);
        attacked_squares or_eq knight_moves[index];
        // "Increment" loop index.
        knights xor_eq square_bit(index);
    }

    if (king) {
        attacked_squares or_eq king_moves[lsb_unsafe(king)];
    }

    if (square bitand attacked_squares) {
        return true;
    }
    return false;
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
    fenstring += (maps[act_color] == WHITE) ? 'w' : 'b';
    fenstring += ' ';

    string castling = "";

    if (castling_rights[maps[castle_rights]][c_w_king])   { castling += "K"; }
    if (castling_rights[maps[castle_rights]][c_w_queen])  { castling += "Q"; }
    if (castling_rights[maps[castle_rights]][c_b_king])   { castling += "k"; }
    if (castling_rights[maps[castle_rights]][c_b_queen])  { castling += "q"; }

    if (castling.empty()) {
        castling += "-";
    }

    fenstring += castling + " ";
    fenstring += bit_to_square.at(maps[passant_sq]) + " ";
    fenstring += to_string(maps[hlf_clock]) + " ";
    fenstring += to_string(maps[full_num]);

    return fenstring;
}

