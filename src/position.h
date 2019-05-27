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
        {"KQkq", 1},  {"KQk" , 2},  {"KQq" , 3},  {"KQ"  , 4}, 
        {"Kkq" , 5},  {"Kk"  , 6},  {"Kq"  , 7},  {"K"   , 8},
        {"Qkq" , 9},  {"Qk"  , 10}, {"Qq"  , 11}, {"Q"   , 12},
        {"kq"  , 13}, {"k"   , 14}, {"q"   , 15}, {"-"   , 0},
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
      { false, false, false, false}, // 0 = -    
      { true, true, true, true    }, // 1  = KQkq
      { true, true, true, false   }, // 2  = KQk
      { true, true, false, true   }, // 3  = KQq
      { true, true, false, false  }, // 4  = KQ
      { true, false, true, true   }, // 5  = Kkq
      { true, false, true, false  }, // 6  = Kk
      { true, false, false, true  }, // 7  = Kq
      { true, false, false, false }, // 8  = K
      { false, true, true, true   }, // 9  = Qkq
      { false, true, true, false  }, // 10 = Qk
      { false, true, false, true  }, // 11 = Qq
      { false, true, false, false }, // 12 = Q
      { false, false, true, true  }, // 13 = kq
      { false, false, true, false }, // 14 = k
      { false, false, false, true }  // 15 = q
}};

enum map_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces, 
                 b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces,
                 act_color, castle_rights, passant_sq, hlf_clock, full_num, eval_score,
                 zobrist_key};

enum Color: bitboard { WHITE , BLACK };
enum Clock: bitboard { ZERO, ONE};

class Position {

    public:
        // Class Attributes
        array<bitboard, 21> maps = {0};

        std::vector<Position> moves;

        // Constructors

        Position(void) : Position("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1") {}
        Position(std::string fen);
        Position(const Position& other) :
            maps(other.maps) {}

        // Comparisons
        bool operator == (const Position& other) const { return maps == other.maps; }
        bool operator < (const Position& other) const { 
            return maps[eval_score] < other.maps[eval_score]; 
        }

        // Functions
        bool is_white_move(void) const { return maps[act_color] == WHITE; } 
        bool is_black_move(void) const { return maps[act_color] == BLACK; }

        bool w_kingside_castle(void)  const { return castling_rights[maps[castle_rights]][c_w_king];  }
        bool w_queenside_castle(void) const { return castling_rights[maps[castle_rights]][c_w_queen]; }
        bool b_kingside_castle(void)  const { return castling_rights[maps[castle_rights]][c_b_king];  }
        bool b_queenside_castle(void) const { return castling_rights[maps[castle_rights]][c_b_queen]; }

        void set_piece_positions(char* fen_tok);
        void set_active_color(char* fen_tok);
        void set_castling_rights(char* fen_tok);
        void set_passant_target_sq(char* fen_tok);
        void set_halfmove_clock(char* fen_tok);
        void set_fullmove_number(char* fen_tok);

        void generate_moves(void);
        void evaluate(void);
        void move(std::string move_string);
        void zero_at(int square, int piece);
        int get_moving_piece(int square);

        std::string to_fen_string();
};

#endif

