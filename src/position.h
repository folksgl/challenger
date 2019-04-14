#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <string.h>
#include "bitboard.h"

#ifndef POSITION_H
#define POSITION_H

using namespace std;

enum Piece_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces, 
                   b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces };

class Position {

    public:
        // Class Attributes
        array<bitboard, 14> maps;

        char active_color;

        bool w_kingside_castle;
        bool w_queenside_castle;
        bool b_kingside_castle;
        bool b_queenside_castle;

        string passant_target_sq;

        unsigned short int halfmove_clock;
        unsigned short int fullmove_number;

        int evaluation_score;

        string movestring;

        std::vector<Position> moves;

        // Constructors

        Position(void) : Position("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {}
        Position(std::string fen);
        Position(const Position& other);

        // Comparisons
        bool operator == (const Position& other) const;

        // Functions
        bool is_white_move(void) const;
        bool is_black_move(void) const;

        void set_piece_positions(char* fen_tok);
        void set_active_color(char* fen_tok);
        void set_castling_rights(char* fen_tok);
        void set_passant_target_sq(char* fen_tok);
        void set_halfmove_clock(char* fen_tok);
        void set_fullmove_number(char* fen_tok);

        void generate_moves(void);
        void evaluate(void);
        void zero_piece_positions();
        void move(std::string move_string);
        int zero_at(int square);

};

#endif

