#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include "./bitmap.h"
#include "./genmove.h"
#include "game_variables.h"
#include "./position.h"
#include "./evaluate.h"
#include "algorithm"

using namespace std;

/*
 *  setup_fen returns a position that has been initialized to the fen string passed to it.
 */
position setup_fen(string fen) {

    position board_position;

    // Copy fen string into char[] for tokenizing.
    char * fenstring = new char [fen.length()+1];
    strcpy (fenstring, fen.c_str());

    // Piece string is the first portion of the fen string. Represents the position of the pieces.
    char *piece_string  = strtok(fenstring, " "); 
    char *active_color  = strtok(NULL, " "); 
    char *castle_rights = strtok(NULL, " "); 
    char *passant_sq    = strtok(NULL, " "); 
    char *halfmove_clk  = strtok(NULL, " "); 
    char *fullmove_num  = strtok(NULL, " "); 

    set_piece_positions(piece_string,  &board_position);
    set_active_color(active_color,     &board_position);
    set_castling_rights(castle_rights, &board_position);
    set_passant_target_sq(passant_sq,  &board_position);
    set_halfmove_clock(halfmove_clk,   &board_position);
    set_fullmove_number(fullmove_num,  &board_position);

    board_position.evaluation_score = evaluate_position(&board_position);

    //generate_moves(&board_position);

    //debug_position(board_position);
    return board_position;
}

/*
 *  set_bit sets the value of the bit indicated by sq_num to 1.
 */
void set_bit(bitmap* bit_map, int sq_num) {
    *bit_map = (bitmap)(*bit_map | ((bitmap)1 << sq_num));
}

/*
 *  set_piece_positions sets the value of all the bitmaps in board_position
 *  to the values found in fen_tok.
 */
void set_piece_positions(char* fen_tok, position* pos) {

    string tmp, bit_oriented_string;

    tmp = strtok(fen_tok, "/");
    std::reverse(tmp.begin(), tmp.end());
    bit_oriented_string += tmp;

    for (int i = 0; i < 7; i++) {
        tmp = strtok(NULL, "/");
        std::reverse(tmp.begin(), tmp.end());
        bit_oriented_string += tmp;
    }

    // Create position from fen_tok.
    int sq_num = 63;
    int length = bit_oriented_string.length();
    for (int i = 0; i < length; i++) {
        char input = bit_oriented_string.at(i);
        //cout << "input switched on was: " << input << "\nsquare num is: " << sq_num << endl;
        switch(input) {
            // Lower case = Black Pieces
            case 'p': set_bit(&pos->maps[b_pawn],   sq_num--); break;
            case 'r': set_bit(&pos->maps[b_rook],   sq_num--); break;
            case 'n': set_bit(&pos->maps[b_knight], sq_num--); break;
            case 'b': set_bit(&pos->maps[b_bishop], sq_num--); break;
            case 'q': set_bit(&pos->maps[b_queen],  sq_num--); break;
            case 'k': set_bit(&pos->maps[b_king],   sq_num--); break;

                // Upper case = White Pieces
            case 'P': set_bit(&pos->maps[w_pawn],   sq_num--); break;
            case 'R': set_bit(&pos->maps[w_rook],   sq_num--); break;
            case 'N': set_bit(&pos->maps[w_knight], sq_num--); break;
            case 'B': set_bit(&pos->maps[w_bishop], sq_num--); break;
            case 'Q': set_bit(&pos->maps[w_queen],  sq_num--); break;
            case 'K': set_bit(&pos->maps[w_king],   sq_num--); break;

            default :
                if (isdigit(input)) {
                    sq_num -= atoi(&input);
                }
        }
    }

    pos->maps[w_pieces] = pos->maps[w_pawn] | pos->maps[w_rook]  | pos->maps[w_knight] | 
                        pos->maps[w_bishop] | pos->maps[w_queen] | pos->maps[w_king];

    pos->maps[b_pieces] = pos->maps[b_pawn] | pos->maps[b_rook]  | pos->maps[b_knight] | 
                        pos->maps[b_bishop] | pos->maps[b_queen] | pos->maps[b_king];

    return;
}

/*
 *  set_castling_rights sets the value of castling_rights in board_position
 *  to the value found in fen_tok.
 */
void set_castling_rights(char* fen_tok, position* board_position) {

    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 4) {
        // Castling right string is malformed, continue with no castling rights 
        return;
    }

    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (fen_tok[i] == 'K') {
            board_position->w_kingside_castle = true;
        }
        else if (fen_tok[i] == 'Q') {
            board_position->w_queenside_castle = true;
        }
        else if (fen_tok[i] == 'k') {
            board_position->b_kingside_castle = true;
        }
        else if (fen_tok[i] == 'q') {
            board_position->b_queenside_castle = true;
        }
    }

    return;
}


/*
 *  set_active_color sets the value of active_color in board_position
 *  to the value found in fen_tok.
 */
void set_active_color(char* fen_tok, position* board_position) {

    if (fen_tok == NULL || strlen(fen_tok) != 1) {
        // Malformed active color string. Just assume that it is white's turn.
        return;
    }
    board_position->active_color = fen_tok[0];

    return;
}

/*
 *  set_passant_target_sq sets the value of passant_target_sq in board_position
 *  to the value found in fen_tok.
 */
void set_passant_target_sq(char* fen_tok, position* board_position) {
    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 2 || fen_tok[0] == '-' || !isalpha(fen_tok[0]) || !isdigit(fen_tok[1])) {
        // No target square or if malformed passant target string, assume there is none.
        board_position->passant_target_sq[0] = '-';
        board_position->passant_target_sq[1] = '\0';
        return;
    }

    else {
        board_position->passant_target_sq[0] = fen_tok[0];
        board_position->passant_target_sq[1] = fen_tok[1];
    }

    return;
}

/*
 *  set_halfmove_clock sets the value of halfmove_clock in board_position
 *  to the value found in fen_tok.
 */
void set_halfmove_clock(char* fen_tok, position* board_position) {
    if (fen_tok == NULL) {
        // Malformed clock string, just don't modify the clock and ignore token.
        return;
    }
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (!isdigit(fen_tok[i])) {
            // Malformed clock string, just don't modify the clock and ignore token.
            return;
        }
    }

    char* end;
    board_position->halfmove_clock = strtoul(fen_tok, &end, 10);

    return;
}

/*
 *  set_fullmove_number sets the value of fullmove_number in board_position
 *  to the value found in fen_tok.
 */
void set_fullmove_number(char* fen_tok, position* board_position) {
    if (fen_tok == NULL) {
        // Malformed move number string, ignore token and don't modify move number.
        return;
    }
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (!isdigit(fen_tok[i])) {
            // Malformed move number string, ignore token and don't modify move number.
            return;
        }
    }

    char* end;
    board_position->fullmove_number = strtoul(fen_tok, &end, 10);

    return;
}

/*
 *  game_move performs the move given in the move string on board_position.
 */
void game_move(string move, position* board_position) {

    if (move.length() != 4 || move.length() != 5) {
        // Malformed move string, ignore move and don't change the position.
        return;
    }

    // Extract start and destination squares from the move
    int start_square = get_square_num(move.substr(0,2));
    int dest_square = get_square_num(move.substr(2,2));

    // Zero out the start square
    int piece = zero_at(start_square, board_position);

    // Check for pawn promotion
    if (move.length() == 5) {
        char promoted_to = move.at(4);
        switch (promoted_to) {
            case 'N': piece = w_knight; break;
            case 'n': piece = b_knight; break;
            case 'B': piece = w_bishop; break;
            case 'b': piece = b_bishop; break;
            case 'Q': piece = w_queen;  break;
            case 'q': piece = b_queen;  break;
        }
    }

    // Set the destination square
    zero_at(dest_square, board_position);
    set_bit(&board_position->maps[piece], dest_square);

    if (piece < 6) {
        set_bit(&board_position->maps[w_pieces], dest_square);
    }
    else {
        set_bit(&board_position->maps[b_pieces], dest_square);
    }

    return;
}

/*
 *  zero_at zero's the bit indicated by square on the position given and
 *  set a number representing the piece type that was in the square.
 *
 *  return the map position of the piece changed
 */
int zero_at(int square, position* board_position) {

    bitmap square_bit = (bitmap)1 << square;
    bitmap mask = 0xFFFFFFFFFFFFFFFF & ~square_bit;

    board_position->maps[b_pieces] = ((bitmap)board_position->maps[b_pieces] & mask);
    board_position->maps[w_pieces] = ((bitmap)board_position->maps[w_pieces] & mask);

    for (int i = 0; i < 14; i++) {
        if (board_position->maps[i] & square_bit) {
            board_position->maps[i] = ((bitmap)board_position->maps[i] & mask);
            return i;
        }
    }

    return -1; //This should never return -1. A valid move WILL trigger one of the above cases.
}

/*
 *  get_square_num calculates the number of the square represented by square_string
 */
int get_square_num(std::string square_string) {

    // To get the square number for a string such as e4, translate the file to a 
    // number (a=0, b=1, etc) and add (rank_multiplier * 8) to get the square.
    int rank_mult = atoi(square_string.substr(1, 1).c_str()) - 1;
    int square_num = file_to_num(square_string.at(0)) + (rank_mult * 8);

    return square_num;
}

/*
 *  file_to_num translates a character representing a file on a chess board (i.e. a, b, etc)
 *  to a number representing its location on the board. a=0, b=1, c=2
 */
int file_to_num(char file) {

    int number = 0;

    switch(file) {
        case 'b': number = 1; break;
        case 'c': number = 2; break;
        case 'd': number = 3; break;
        case 'e': number = 4; break;
        case 'f': number = 5; break;
        case 'g': number = 6; break;
        case 'h': number = 7; break;
    }

    return number;
}

void debug_position(position pos) {

    bitmap bb;

    cout << "\n\nBlack pawn" << endl;   bb = pos.maps[b_pawn];   print_bitboard(bb);
    cout << "\n\nBlack rook" << endl;   bb = pos.maps[b_rook];   print_bitboard(bb);
    cout << "\n\nBlack knight" << endl; bb = pos.maps[b_knight]; print_bitboard(bb);
    cout << "\n\nBlack bishop" << endl; bb = pos.maps[b_bishop]; print_bitboard(bb);
    cout << "\n\nBlack queen" << endl;  bb = pos.maps[b_queen];  print_bitboard(bb);
    cout << "\n\nBlack king" << endl;   bb = pos.maps[b_king];   print_bitboard(bb);
    cout << "\n\nBlack pieces" << endl; bb = pos.maps[b_pieces]; print_bitboard(bb);

    cout << "\n\nWhite pawn" << endl;   bb = pos.maps[w_pawn];   print_bitboard(bb);
    cout << "\n\nWhite rook" << endl;   bb = pos.maps[w_rook];   print_bitboard(bb);
    cout << "\n\nWhite knight" << endl; bb = pos.maps[w_knight]; print_bitboard(bb);
    cout << "\n\nWhite bishop" << endl; bb = pos.maps[w_bishop]; print_bitboard(bb);
    cout << "\n\nWhite queen" << endl;  bb = pos.maps[w_queen];  print_bitboard(bb);
    cout << "\n\nWhite king" << endl;   bb = pos.maps[w_king];   print_bitboard(bb);
    cout << "\n\nWhite pieces" << endl; bb = pos.maps[w_pieces]; print_bitboard(bb);

}

void print_bitboard(bitmap bb) {

    for (int i = 56; i < 64; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 48; i < 56; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 40; i < 48; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 32; i < 40; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 24; i < 32; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 16; i < 24; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 8; i < 16; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 0; i < 8; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    return;
}

