#include <iostream>
#include <stdio.h>
#include <string.h>
#include "./bitmap.h"
#include "game_variables.h"
#include "./position.h"

using namespace std;

position setup_fen(string fen) {

    position board_position;

    // Zero out the board to prepare for fen string input.
    board_position.WHITE_PAWN = 0;
    board_position.WHITE_ROOK = 0;
    board_position.WHITE_KNIGHT = 0;
    board_position.WHITE_BISHOP = 0;
    board_position.WHITE_QUEEN = 0;
    board_position.WHITE_KING = 0;
    board_position.WHITE_PIECES = 0;

    board_position.BLACK_PAWN = 0;
    board_position.BLACK_ROOK = 0;
    board_position.BLACK_KNIGHT = 0;
    board_position.BLACK_BISHOP = 0;
    board_position.BLACK_QUEEN = 0;
    board_position.BLACK_KING = 0;
    board_position.BLACK_PIECES = 0;

    // Copy fen string into char[] for tokenizing.
    char * fenstring = new char [fen.length()+1];
    strcpy (fenstring, fen.c_str());

    char *piece_string = strtok(fenstring, " "); 
    //char *active_color = strtok(NULL, " ");
    //char *castling_rights = strtok(NULL, " ");
    //char *passant_target_sq = strtok(NULL, " ");
    //char *halfmove_clock = strtok(NULL, " ");
    //char *fullmove_number = strtok(NULL, " ");

    //if (piece_string == NULL || active_color == NULL || castling_rights == NULL ||
            //passant_target == NULL || halfmove_clock == NULL || fullmove_number == NULL) {
        //cout << "Malformed fen string." << endl;
    //}

    // Create position from piece_string.
    int sq_num = 0;

    int length = strlen(piece_string);
    for (int i = length-1; i >= 0; i--) {
        char input = piece_string[i];
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

    board_position.WHITE_PIECES = board_position.WHITE_PAWN | board_position.WHITE_ROOK |
        board_position.WHITE_KNIGHT | board_position.WHITE_BISHOP | board_position.WHITE_QUEEN |
        board_position.WHITE_KING;

    board_position.BLACK_PIECES = board_position.BLACK_PAWN | board_position.BLACK_ROOK |
        board_position.BLACK_KNIGHT | board_position.BLACK_BISHOP | board_position.BLACK_QUEEN |
        board_position.BLACK_KING;

    debug_position(board_position);
    return board_position;
}

void game_move(string uci_move) {

    cout << "getting to method" << endl;
    cout << uci_move << endl;
    return;
}

void debug_position(position pos) {
    print_position("BLACK_PAWN", pos.BLACK_PAWN);
    print_position("BLACK_ROOK", pos.BLACK_ROOK);
    print_position("BLACK_KNIGHT", pos.BLACK_KNIGHT);
    print_position("BLACK_BISHOP", pos.BLACK_BISHOP);
    print_position("BLACK_QUEEN", pos.BLACK_QUEEN);
    print_position("BLACK_KING", pos.BLACK_KING);
    print_position("BLACK_PIECES", pos.BLACK_PIECES);

    print_position("WHITE_PAWN", pos.WHITE_PAWN);
    print_position("WHITE_ROOK", pos.WHITE_ROOK);
    print_position("WHITE_KNIGHT", pos.WHITE_KNIGHT);
    print_position("WHITE_BISHOP", pos.WHITE_BISHOP);
    print_position("WHITE_QUEEN", pos.WHITE_QUEEN);
    print_position("WHITE_KING", pos.WHITE_KING);
    print_position("WHITE_PIECES", pos.WHITE_PIECES);
}

void print_position(string name, bitmap pos) {
    cout << "\n\n" <<  name << endl;

    for (int i = 63; i >= 0; i--) {
        if (((pos >> i) & 1) == 0) {
            cout << '-';
        }
        else {
            cout << 'X';
        }
        if (i % 8 == 0) { 
            cout << endl; 
        }
    }
}

