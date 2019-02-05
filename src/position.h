#include "./bitboard.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

#ifndef POSITION_H
#define POSITION_H

using namespace std;

enum Piece_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces, 
                   b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces };

class Position {

    public:
        // Class Attributes
        bitboard maps[14];

        char active_color;

        bool w_kingside_castle;
        bool w_queenside_castle;
        bool b_kingside_castle;
        bool b_queenside_castle;

        char passant_target_sq[2];

        unsigned short int halfmove_clock;
        unsigned short int fullmove_number;

        int evaluation_score;

        std::vector<Position> moves;

        // Constructors
        Position(void);
        Position(std::string fen);

        // Functions
        bool is_white_move(void);
        bool is_black_move(void);
        void generate_moves(void);
        void move(std::string move_string);
        void set_piece_positions(char* fen_tok, Position* pos);
        void set_active_color(char* fen_tok, Position* board_position);
        void set_castling_rights(char* fen_tok, Position* board_position);
        void set_passant_target_sq(char* fen_tok, Position* board_position);
        void set_halfmove_clock(char* fen_tok, Position* board_position);
        void set_fullmove_number(char* fen_tok, Position* board_position);
        void set_bit(bitboard* bit_map, int sq_num);
        void game_move(std::string move, Position* board_position);
        int zero_at(int square);
        int file_to_num(char file);
        int get_square_num(std::string square_string);
        void debug_position(void);
        void print_bitboard(bitboard bb);
};

#endif
