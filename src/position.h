#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <string.h>
#include <unordered_map>
#include "bitboard.h"

#ifndef POSITION_H
#define POSITION_H

using namespace std;

enum Castling_names { c_w_king, c_w_queen, c_b_king, c_b_queen};

const std::unordered_map<string, int> castle_string_to_index({
        {"KQkq", 0},
        {"KQk" , 1},
        {"KQq" , 2},
        {"KQ"  , 3},
        {"Kkq" , 4},
        {"Kk"  , 5},
        {"Kq"  , 6},
        {"K"   , 7},
        {"Qkq" , 8},
        {"Qk"  , 9},
        {"Qq"  , 10},
        {"Q"   , 11},
        {"kq"  , 12},
        {"k"   , 13},
        {"q"   , 14},
        {"-"   , 15},
});

const std::array<std::array<bool, 4>, 16> castling_rights {{
      { true, true, true, true    }, // 0  = KQkq
      { true, true, true, false   }, // 1  = KQk
      { true, true, false, true   }, // 2  = KQq
      { true, true, false, false  }, // 3  = KQ
      { true, false, true, true   }, // 4  = Kkq
      { true, false, true, false  }, // 5  = Kk
      { true, false, false, true  }, // 6  = Kq
      { true, false, false, false }, // 7  = K
      { false, true, true, true   }, // 8  = Qkq
      { false, true, true, false  }, // 9  = Qk
      { false, true, false, true  }, // 10 = Qq
      { false, true, false, false }, // 11 = Q
      { false, false, true, true  }, // 12 = kq
      { false, false, true, false }, // 13 = k
      { false, false, false, true }, // 14 = q
      { false, false, false, false}  // 15 = -    
}};

enum Piece_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces, 
                   b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces };

class Position {

    public:
        // Class Attributes
        array<bitboard, 14> maps;

        char active_color;

        char castling_rights_index;

        string passant_target_sq;

        unsigned short int halfmove_clock;
        unsigned short int fullmove_number;

        int evaluation_score;

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

        bool w_kingside_castle(void) const;
        bool w_queenside_castle(void) const;
        bool b_kingside_castle(void) const;
        bool b_queenside_castle(void) const;

        void set_piece_positions(char* fen_tok);
        void set_active_color(char* fen_tok);
        void set_castling_rights(char* fen_tok);
        void set_passant_target_sq(char* fen_tok);
        void set_halfmove_clock(char* fen_tok);
        void set_fullmove_number(char* fen_tok);

        void generate_moves(void);
        void evaluate(void);
        void set_defaults();
        void move(std::string move_string);
        int zero_at(int square);

        std::string to_fen_string();
};

#endif

