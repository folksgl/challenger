#include "./bitmap.h"
#include <string>

#ifndef POSITION_H
#define POSITION_H

struct position {

    bitmap WHITE_PAWN = 0;
    bitmap WHITE_ROOK = 0;
    bitmap WHITE_KNIGHT = 0;
    bitmap WHITE_BISHOP = 0;
    bitmap WHITE_QUEEN = 0;
    bitmap WHITE_KING = 0;
    bitmap WHITE_PIECES = 0;

    bitmap BLACK_PAWN = 0;
    bitmap BLACK_ROOK = 0;
    bitmap BLACK_KNIGHT = 0;
    bitmap BLACK_BISHOP = 0;
    bitmap BLACK_QUEEN = 0;
    bitmap BLACK_KING = 0;
    bitmap BLACK_PIECES = 0;

    char active_color = 'w';

    bool w_kingside_castle = false;
    bool w_queenside_castle = false;
    bool b_kingside_castle = false;
    bool b_queenside_castle = false;

    char passant_target_sq[2] = "-";

    unsigned short int halfmove_clock = 0;
    unsigned short int fullmove_number = 0;


};

position setup_fen(std::string fen);

void set_active_color(char* fen_tok, position* board_position);

void set_castling_rights(char* fen_tok, position* board_position);

void set_passant_target_sq(char* fen_tok, position* board_position);

void set_halfmove_clock(char* fen_tok, position* board_position);

void set_fullmove_number(char* fen_tok, position* board_position);

void set_bit(bitmap* bit_map, int sq_num);

void game_move(std::string uci_move);

void debug_position(position pos);

void print_bitboard(bitmap bb);

#endif
