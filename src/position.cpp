#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./bitmap.h"
#include "game_variables.h"
#include "./position.h"
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

    //debug_position(board_position);
    return board_position;
}

/*
 *  set_bit sets the value of the bit indicated by sq_num to 1.
 */
void set_bit(bitmap* bit_map, int sq_num) {
    *bit_map = *bit_map | (bitmap)(*bit_map | ((bitmap)1 << sq_num));
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
            case 'p': set_bit(&pos->BLACK_PAWN,   sq_num--); break;
            case 'r': set_bit(&pos->BLACK_ROOK,   sq_num--); break;
            case 'n': set_bit(&pos->BLACK_KNIGHT, sq_num--); break;
            case 'b': set_bit(&pos->BLACK_BISHOP, sq_num--); break;
            case 'q': set_bit(&pos->BLACK_QUEEN,  sq_num--); break;
            case 'k': set_bit(&pos->BLACK_KING,   sq_num--); break;

                // Upper case = White Pieces
            case 'P': set_bit(&pos->WHITE_PAWN,   sq_num--); break;
            case 'R': set_bit(&pos->WHITE_ROOK,   sq_num--); break;
            case 'N': set_bit(&pos->WHITE_KNIGHT, sq_num--); break;
            case 'B': set_bit(&pos->WHITE_BISHOP, sq_num--); break;
            case 'Q': set_bit(&pos->WHITE_QUEEN,  sq_num--); break;
            case 'K': set_bit(&pos->WHITE_KING,   sq_num--); break;

            default :
                if (isdigit(input)) {
                    sq_num -= atoi(&input);
                }
        }
    }

    pos->WHITE_PIECES = pos->WHITE_PAWN   | pos->WHITE_ROOK  | pos->WHITE_KNIGHT | 
                        pos->WHITE_BISHOP | pos->WHITE_QUEEN | pos->WHITE_KING;

    pos->BLACK_PIECES = pos->BLACK_PAWN   | pos->BLACK_ROOK  | pos->BLACK_KNIGHT | 
                        pos->BLACK_BISHOP | pos->BLACK_QUEEN | pos->BLACK_KING;

    return;
}

/*
 *  set_castling_rights sets the value of castling_rights in board_position
 *  to the value found in fen_tok.
 */
void set_castling_rights(char* fen_tok, position* board_position) {

    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 4) {
        cout << "Got malformed castling rights string. Exiting..." << endl;
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
        cout << "Got malformed active color string. Exiting..." << endl;
        exit(1);
    }
    board_position->active_color = fen_tok[0];

    return;
}

/*
 *  set_passant_target_sq sets the value of passant_target_sq in board_position
 *  to the value found in fen_tok.
 */
void set_passant_target_sq(char* fen_tok, position* board_position) {
    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 2) {
        cout << "Got malformed passant target square string. Exiting..." << endl;
        exit(1);
    }

    if (fen_tok[0] == '-') {
        board_position->passant_target_sq[0] = '-';
        board_position->passant_target_sq[0] = '\0';
        return;
    }

    if (!isalpha(fen_tok[0]) || !isdigit(fen_tok[1])) {
        cout << "Got malformed passant target square string. Exiting..." << endl;
        exit(1);
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
        cout << "Got malformed halfmove clock string. Exiting...";
        exit(1);
    }
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (!isdigit(fen_tok[i])) {
            cout << "Got malformed halfmove clock string. Exiting...";
            exit(1);
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
        cout << "Got malformed fullmove_number string. Exiting...";
        exit(1);
    }
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (!isdigit(fen_tok[i])) {
            cout << "Got malformed fullmove_number string. Exiting...";
            exit(1);
        }
    }

    char* end;
    board_position->fullmove_number = strtoul(fen_tok, &end, 10);

    return;
}

void game_move(string uci_move) {

    cout << "getting to method" << endl;
    cout << uci_move << endl;
    return;
}

void debug_position(position pos) {

    bitmap bb;

    cout << "\n\nBlack pawn" << endl;   bb = pos.BLACK_PAWN;   print_bitboard(bb);
    cout << "\n\nBlack rook" << endl;   bb = pos.BLACK_ROOK;   print_bitboard(bb);
    cout << "\n\nBlack knight" << endl; bb = pos.BLACK_KNIGHT; print_bitboard(bb);
    cout << "\n\nBlack bishop" << endl; bb = pos.BLACK_BISHOP; print_bitboard(bb);
    cout << "\n\nBlack queen" << endl;  bb = pos.BLACK_QUEEN;  print_bitboard(bb);
    cout << "\n\nBlack king" << endl;   bb = pos.BLACK_KING;   print_bitboard(bb);
    cout << "\n\nBlack pieces" << endl; bb = pos.BLACK_PIECES; print_bitboard(bb);

    cout << "\n\nWhite pawn" << endl;   bb = pos.WHITE_PAWN;   print_bitboard(bb);
    cout << "\n\nWhite rook" << endl;   bb = pos.WHITE_ROOK;   print_bitboard(bb);
    cout << "\n\nWhite knight" << endl; bb = pos.WHITE_KNIGHT; print_bitboard(bb);
    cout << "\n\nWhite bishop" << endl; bb = pos.WHITE_BISHOP; print_bitboard(bb);
    cout << "\n\nWhite queen" << endl;  bb = pos.WHITE_QUEEN;  print_bitboard(bb);
    cout << "\n\nWhite king" << endl;   bb = pos.WHITE_KING;   print_bitboard(bb);
    cout << "\n\nWhite pieces" << endl; bb = pos.WHITE_PIECES; print_bitboard(bb);

}

void print_bitboard(bitmap bb) {

    for (int i = 56; i < 64; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    for (int i = 48; i < 56; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    for (int i = 40; i < 48; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;

    for (int i = 32; i < 40; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    for (int i = 24; i < 32; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    for (int i = 16; i < 24; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    for (int i = 8; i < 16; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        if ((bb >> i) & 0x1) {
            cout << 'B';
        }
        else {
            cout << '-';
        }
    }
    cout << endl;
    return;
}

