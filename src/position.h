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
        {"KQkq", 0},  {"KQk" , 1},  {"KQq" , 2},  {"KQ"  , 3}, 
        {"Kkq" , 4},  {"Kk"  , 5},  {"Kq"  , 6},  {"K"   , 7},
        {"Qkq" , 8},  {"Qk"  , 9},  {"Qq"  , 10}, {"Q"   , 11},
        {"kq"  , 12}, {"k"   , 13}, {"q"   , 14}, {"-"   , 15},
});

const std::unordered_map<string, bitboard> passant_string_to_bit({
        {"a3", 0x0000000000010000}, {"b3", 0x0000000000020000},
        {"c3", 0x0000000000040000}, {"d3", 0x0000000000080000}, 
        {"e3", 0x0000000000100000}, {"f3", 0x0000000000200000},
        {"g3", 0x0000000000400000}, {"h3", 0x0000000000800000},

        {"a6", 0x0000010000000000}, {"b6", 0x0000020000000000},  
        {"c6", 0x0000040000000000}, {"d6", 0x0000080000000000},
        {"e6", 0x0000100000000000}, {"f6", 0x0000200000000000}, 
        {"g6", 0x0000400000000000}, {"h6", 0x0000800000000000},
        {"-",  0x0000000000000000}
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

enum map_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces, 
                 b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces,
                 act_color, castle_rights, passant_sq, hlf_clock, full_num, eval_score };

enum Color { WHITE , BLACK };

class Position {

    public:
        // Class Attributes
        array<bitboard, 20> maps;

        std::vector<Position> moves;

        // Constructors

        Position(void) : Position("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {}
        Position(std::string fen);
        Position(const Position& other) :
            maps(other.maps) {}

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
        void zero_at(int square, int piece);
        int get_moving_piece(int square);

        std::string to_fen_string();
};

#endif

