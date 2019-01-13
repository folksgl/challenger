#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./bitmap.h"
#include "game_variables.h"
#include "./position.h"

using namespace std;

position setup_fen(string fen) {

    position board_position;

    // Copy fen string into char[] for tokenizing.
    char * fenstring = new char [fen.length()+1];
    strcpy (fenstring, fen.c_str());

    // Piece string is the first portion of the fen string. Represents the position of the pieces.
    char *piece_string = strtok(fenstring, " "); 

    char* ranks[8];

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

    ranks[7] = strtok(piece_string, "/"); // 8th Rank
    ranks[6] = strtok(NULL, "/");         // 7th Rank
    ranks[5] = strtok(NULL, "/");         // 6th Rank
    ranks[4] = strtok(NULL, "/");         // 5th Rank
    ranks[3] = strtok(NULL, "/");         // 4th Rank
    ranks[2] = strtok(NULL, "/");         // 3rd Rank
    ranks[1] = strtok(NULL, "/");         // 2nd Rank
    ranks[0] = strtok(NULL, "/");         // 1st Rank

    //for (int i = 7; i >= 0; i--) {
        //cout << "Rank " << i << ": " << ranks[i] << endl;
    //}

    if (piece_string == NULL || active_color == NULL || castling_rights == NULL ||
            passant_target_sq == NULL || halfmove_clock == NULL || fullmove_number == NULL) {
        cout << "Malformed fen string." << endl;
    }

    // Create position from piece_string.
    int sq_num = 0;

    for (int j = 0; j < 8; j++) {
        int length = strlen(ranks[j]);
        for (int i = 0; i < length-1; i++) {
            char input = ranks[j][i];
            //cout << "input switched on was: " << input << "\nsquare num is: " << sq_num << endl;
            switch(input) {
                // Lower case = Black Pieces
                case 'p':
                    board_position.BLACK_PAWN = (bitmap)((bitmap)board_position.BLACK_PAWN | ((bitmap)1 << sq_num++));
                    break;
                case 'r':
                    board_position.BLACK_ROOK = (bitmap)(board_position.BLACK_ROOK | ((bitmap)1 << sq_num++));
                    break;
                case 'n':
                    board_position.BLACK_KNIGHT = (bitmap)(board_position.BLACK_KNIGHT | ((bitmap)1 << sq_num++));
                    break;
                case 'b':
                    board_position.BLACK_BISHOP = (bitmap)(board_position.BLACK_BISHOP | ((bitmap)1 << sq_num++));
                    break;
                case 'q':
                    board_position.BLACK_QUEEN = (bitmap)(board_position.BLACK_QUEEN | ((bitmap)1 << sq_num++));
                    break;
                case 'k':
                    board_position.BLACK_KING = (bitmap)(board_position.BLACK_KING | ((bitmap)1 << sq_num++));
                    break;

                    // Upper case = White Pieces
                case 'P':
                    board_position.WHITE_PAWN = (bitmap)(board_position.WHITE_PAWN | ((bitmap)1 << sq_num++));
                    break;
                case 'R':
                    board_position.WHITE_ROOK = (bitmap)(board_position.WHITE_ROOK | ((bitmap)1 << sq_num++));
                    break;
                case 'N':
                    board_position.WHITE_KNIGHT = (bitmap)(board_position.WHITE_KNIGHT | ((bitmap)1 << sq_num++));
                    break;
                case 'B':
                    board_position.WHITE_BISHOP = (bitmap)(board_position.WHITE_BISHOP | ((bitmap)1 << sq_num++));
                    break;
                case 'Q':
                    board_position.WHITE_QUEEN = (bitmap)(board_position.WHITE_QUEEN | ((bitmap)1 << sq_num++));
                    break;
                case 'K':
                    board_position.WHITE_KING = (bitmap)(board_position.WHITE_KING | ((bitmap)1 << sq_num++));
                    break;

                default :
                    if (isdigit(input)) {
                        sq_num += atoi(&input);
                    }
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

void game_move(string uci_move) {

    cout << "getting to method" << endl;
    cout << uci_move << endl;
    return;
}

void set_castling_rights(char* fen_tok, position* board_position) {

    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 4) {
        cout << "Got malformed castling rights string. Exiting..." << endl;
    }

    cout << "The fen_tok for castling is: " << fen_tok << endl;

    cout << "The length of fen_tok is: " << strlen(fen_tok) << endl;
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        cout << "Iterating on fen_tok[" << i << "] -- Value is: " << fen_tok[i] << endl;
        if (fen_tok[i] == 'K') {
            cout << "SHOULD SET KINGSIDE WHITE" << endl;
            board_position->w_kingside_castle = true;
        }
        if (fen_tok[i] == 'Q') {
            board_position->w_queenside_castle = true;
            cout << "SHOULD SET QUEENSIDE WHITE" << endl;
        }
        if (fen_tok[i] == 'k') {
            board_position->b_kingside_castle = true;
            cout << "SHOULD SET KINGSIDE BLACK" << endl;
        }
        if (fen_tok[i] == 'q') {
            cout << "SHOULD SET QUEENSIDE BLACK" << endl;
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
    }
    else if (!isalpha(fen_tok[0]) || !isdigit(fen_tok[1])) {
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

void debug_position(position pos) {

    bitmap maps[14];
    maps[0] = pos.BLACK_PAWN;
    maps[1] = pos.BLACK_ROOK;
    maps[2] = pos.BLACK_KNIGHT;
    maps[3] = pos.BLACK_BISHOP;
    maps[4] = pos.BLACK_QUEEN;
    maps[5] = pos.BLACK_KING;
    maps[6] = pos.BLACK_PIECES;

    maps[7] = pos.WHITE_PAWN;
    maps[8] = pos.WHITE_ROOK;
    maps[9] = pos.WHITE_KNIGHT;
    maps[10] = pos.WHITE_BISHOP;
    maps[11] = pos.WHITE_QUEEN;
    maps[12] = pos.WHITE_KING;
    maps[13] = pos.WHITE_PIECES;

    cout << "\n\n| Black Pawn                | Black Rook                | Black Knight               " << endl;
    for (int h = 0; h < 8; h++) {
        for (int j = 0; j < 3; j++) {
            cout << "|  ";
            for (int i = (56 - (h*8)); i <= (63 - (h * 8)); i++) {
                if (((maps[j] >> i) & 1) == 0) {
                    cout << '-' << ' ';
                }
                else {
                    cout << 'B' << ' ';
                }
            }
            cout << "         ";
        }
        cout << endl;
    }

    cout << "\n\n| Black Bishop              | Black Queen               | Black King                | Black Pieces" << endl;
    for (int h = 0; h < 8; h++) {
        for (int j = 3; j < 7; j++) {
            cout << "|  ";
            for (int i = (56 - (h*8)); i <= (63 - (h * 8)); i++) {
                if (((maps[j] >> i) & 1) == 0) {
                    cout << '-' << ' ';
                }
                else {
                    cout << 'B' << ' ';
                }
            }
            cout << "         ";
        }
        cout << endl;
    }

    cout << "\n=======================================================================================" << endl;

    cout << "\n\n| White Pawn                | White Rook                | White Knight               " << endl;
    for (int h = 0; h < 8; h++) {
        for (int j = 7; j < 10; j++) {
            cout << "|  ";
            for (int i = (56 - (h*8)); i <= (63 - (h * 8)); i++) {
                if (((maps[j] >> i) & 1) == 0) {
                    cout << '-' << ' ';
                }
                else {
                    cout << 'W' << ' ';
                }
            }
            cout << "         ";
        }
        cout << endl;
    }

    cout << "\n\n| White Bishop              | White Queen               | White King                | White Pieces" << endl;
    for (int h = 0; h < 8; h++) {
        for (int j = 10; j < 14; j++) {
            cout << "|  ";
            for (int i = (56 - (h*8)); i <= (63 - (h * 8)); i++) {
                if (((maps[j] >> i) & 1) == 0) {
                    cout << '-' << ' ';
                }
                else {
                    cout << 'W' << ' ';
                }
            }
            cout << "         " ;
        }
        cout << endl;
    }

    return;
}

