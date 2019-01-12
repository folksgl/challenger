#include "./bitmap.h"
#include <string>

#ifndef POSITION_H
#define POSITION_H

struct position {

    bitmap WHITE_PAWN;
    bitmap WHITE_ROOK;
    bitmap WHITE_KNIGHT;
    bitmap WHITE_BISHOP;
    bitmap WHITE_QUEEN;
    bitmap WHITE_KING;
    bitmap WHITE_PIECES;

    bitmap BLACK_PAWN;
    bitmap BLACK_ROOK;
    bitmap BLACK_KNIGHT;
    bitmap BLACK_BISHOP;
    bitmap BLACK_QUEEN;
    bitmap BLACK_KING;
    bitmap BLACK_PIECES;

};

position setup_fen(std::string fen);

void game_move(std::string uci_move);

void debug_position(position pos);

void print_position(std::string name, bitmap pos);

#endif
