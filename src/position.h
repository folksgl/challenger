#include "./bitmap.h"
#include <string>
#include <vector>

#ifndef POSITION_H
#define POSITION_H

enum Piece_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces, 
                   b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces };

struct position {

    bitmap maps[14] = { };

    char active_color = 'w';

    bool w_kingside_castle = false;
    bool w_queenside_castle = false;
    bool b_kingside_castle = false;
    bool b_queenside_castle = false;

    char passant_target_sq[2] = "-";

    unsigned short int halfmove_clock = 0;
    unsigned short int fullmove_number = 0;

    int evaluation_score = 0;

    std::vector<position> moves;
};

position setup_fen(std::string fen);

void set_piece_positions(char* fen_tok, position* pos);

void set_active_color(char* fen_tok, position* board_position);

void set_castling_rights(char* fen_tok, position* board_position);

void set_passant_target_sq(char* fen_tok, position* board_position);

void set_halfmove_clock(char* fen_tok, position* board_position);

void set_fullmove_number(char* fen_tok, position* board_position);


void set_bit(bitmap* bit_map, int sq_num);

void game_move(std::string move, position* board_position);

int zero_at(int square, position* board_position);

int file_to_num(char file);

int get_square_num(std::string square_string);

void debug_position(position pos);

void print_bitboard(bitmap bb);

#endif
