#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./bitmap.h"
#include "game_variables.h"
#include "./position.h"
#include "algorithm"

using namespace std;

position setup_fen(string fen) {

    position board_position;

    // Copy fen string into char[] for tokenizing.
    char * fenstring = new char [fen.length()+1];
    strcpy (fenstring, fen.c_str());

    // Piece string is the first portion of the fen string. Represents the position of the pieces.
    char *piece_string = strtok(fenstring, " "); 

    char *active_color = strtok(NULL, " ");
    char *castling_rights = strtok(NULL, " ");
    char *passant_target_sq = strtok(NULL, " ");
    char *halfmove_clock = strtok(NULL, " ");
    char *fullmove_number = strtok(NULL, " ");

    set_active_color(active_color, &board_position);
    set_castling_rights(castling_rights, &board_position);
    set_passant_target_sq(passant_target_sq, &board_position);
    set_halfmove_clock(halfmove_clock, &board_position);
    set_fullmove_number(fullmove_number, &board_position);

    string tmp, bit_oriented_string;

    tmp = strtok(piece_string, "/");
    std::reverse(tmp.begin(), tmp.end());
    bit_oriented_string += tmp;

    for (int i = 0; i < 7; i++) {
        tmp = strtok(NULL, "/");
        std::reverse(tmp.begin(), tmp.end());
        bit_oriented_string += tmp;
    }

    // Create position from piece_string.
    int sq_num = 63;
    int length = bit_oriented_string.length();
    for (int i = 0; i < length; i++) {
        char input = bit_oriented_string.at(i);
        //cout << "input switched on was: " << input << "\nsquare num is: " << sq_num << endl;
        switch(input) {
            // Lower case = Black Pieces
            case 'p':
                set_bit(&board_position.BLACK_PAWN, sq_num--);
                break;
            case 'r':
                set_bit(&board_position.BLACK_ROOK, sq_num--);
                break;
            case 'n':
                set_bit(&board_position.BLACK_KNIGHT, sq_num--);
                break;
            case 'b':
                set_bit(&board_position.BLACK_BISHOP, sq_num--);
                break;
            case 'q':
                set_bit(&board_position.BLACK_QUEEN, sq_num--);
                break;
            case 'k':
                set_bit(&board_position.BLACK_KING, sq_num--);
                break;

                // Upper case = White Pieces
            case 'P':
                set_bit(&board_position.WHITE_PAWN, sq_num--);
                break;
            case 'R':
                set_bit(&board_position.WHITE_ROOK, sq_num--);
                break;
            case 'N':
                set_bit(&board_position.WHITE_KNIGHT, sq_num--);
                break;
            case 'B':
                set_bit(&board_position.WHITE_BISHOP, sq_num--);
                break;
            case 'Q':
                set_bit(&board_position.WHITE_QUEEN, sq_num--);
                break;
            case 'K':
                set_bit(&board_position.WHITE_KING, sq_num--);
                break;

            default :
                if (isdigit(input)) {
                    sq_num -= atoi(&input);
                }
        }
    }

    board_position.WHITE_PIECES = board_position.WHITE_PAWN | board_position.WHITE_ROOK |
        board_position.WHITE_KNIGHT | board_position.WHITE_BISHOP | board_position.WHITE_QUEEN |
        board_position.WHITE_KING;

    board_position.BLACK_PIECES = board_position.BLACK_PAWN | board_position.BLACK_ROOK |
        board_position.BLACK_KNIGHT | board_position.BLACK_BISHOP | board_position.BLACK_QUEEN |
        board_position.BLACK_KING;

    //debug_position(board_position);
    return board_position;
}

void set_bit(bitmap* bit_map, int sq_num) {
    *bit_map = *bit_map | (bitmap)(*bit_map | ((bitmap)1 << sq_num));
}

void set_castling_rights(char* fen_tok, position* board_position) {

    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 4) {
        cout << "Got malformed castling rights string. Exiting..." << endl;
    }

    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (fen_tok[i] == 'K') {
            board_position->w_kingside_castle = true;
        }
        if (fen_tok[i] == 'Q') {
            board_position->w_queenside_castle = true;
        }
        if (fen_tok[i] == 'k') {
            board_position->b_kingside_castle = true;
        }
        if (fen_tok[i] == 'q') {
            board_position->b_queenside_castle = true;
        }
    }

    return;
}


void set_active_color(char* fen_tok, position* board_position) {

    if (fen_tok == NULL || strlen(fen_tok) != 1) {
        cout << "Got malformed active color string. Exiting..." << endl;
        exit(1);
    }
    board_position->active_color = fen_tok[0];

    return;
}

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

    cout << "\n\nBlack pawn" << endl;
    bb = pos.BLACK_PAWN;
    print_bitboard(bb);
    cout << "\n\nBlack rook" << endl;
    bb = pos.BLACK_ROOK;
    print_bitboard(bb);
    cout << "\n\nBlack knight" << endl;
    bb = pos.BLACK_KNIGHT;
    print_bitboard(bb);
    cout << "\n\nBlack bishop" << endl;
    bb = pos.BLACK_BISHOP;
    print_bitboard(bb);
    cout << "\n\nBlack queen" << endl;
    bb = pos.BLACK_QUEEN;
    print_bitboard(bb);
    cout << "\n\nBlack king" << endl;
    bb = pos.BLACK_KING;
    print_bitboard(bb);
    cout << "\n\nBlack pieces" << endl;
    bb = pos.BLACK_PIECES;
    print_bitboard(bb);

    cout << "\n\nWhite pawn" << endl;
    bb = pos.WHITE_PAWN;
    print_bitboard(bb);
    cout << "\n\nWhite rook" << endl;
    bb = pos.WHITE_ROOK;
    print_bitboard(bb);
    cout << "\n\nWhite knight" << endl;
    bb = pos.WHITE_KNIGHT;
    print_bitboard(bb);
    cout << "\n\nWhite bishop" << endl;
    bb = pos.WHITE_BISHOP;
    print_bitboard(bb);
    cout << "\n\nWhite queen" << endl;
    bb = pos.WHITE_QUEEN;
    print_bitboard(bb);
    cout << "\n\nWhite king" << endl;
    bb = pos.WHITE_KING;
    print_bitboard(bb);
    cout << "\n\nWhite pieces" << endl;
    bb = pos.WHITE_PIECES;
    print_bitboard(bb);

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

