#ifndef SRC_POSITION_HPP_
#define SRC_POSITION_HPP_

#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "bitboard.hpp"
#include "common.hpp"

using std::string;

constexpr bitboard neg_clock = static_cast<bitboard>(0) - 1;

enum Castling_names { c_w_king, c_w_queen, c_b_king, c_b_queen};

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

enum map_names { w_pawn, w_rook, w_knight, w_bishop, w_queen, w_king, w_pieces,
    b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king, b_pieces };

class Position {
 public:
    // Class Attributes
    std::array<bitboard, 14> maps = {0};
    bitboard passant_sq = 0;

    // Container representing possible moves that can be taken from this position
    std::vector<Position> moves;

    // Castling rights
    bool w_kingside_castle = false;
    bool w_queenside_castle = false;
    bool b_kingside_castle = false;
    bool b_queenside_castle = false;

    // Evaluation score for the position
    int eval_score = 0;

    // Player to move (true=WHITE, false=BLACK)
    bool is_white_move = true;

    // Clocks
    short hlf_clock = 0;
    short full_num = 0;

    // Constructors
    explicit Position(const string& fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Position(const Position& other) :
        maps(other.maps),
        passant_sq(other.passant_sq),
        w_kingside_castle(other.w_kingside_castle),
        w_queenside_castle(other.w_queenside_castle),
        b_kingside_castle(other.b_kingside_castle),
        b_queenside_castle(other.b_queenside_castle),
        is_white_move(other.is_white_move) {}

    // Operator Overloads
    bool operator == (const Position& other) const {
        return maps == other.maps &&
            w_kingside_castle == other.w_kingside_castle &&
            w_queenside_castle == other.w_queenside_castle &&
            b_kingside_castle == other.b_kingside_castle &&
            b_queenside_castle == other.b_queenside_castle &&
            is_white_move == other.is_white_move &&
            passant_sq == other.passant_sq;
    }
    bool operator < (const Position& other) const {
        return eval_score < other.eval_score;
    }

    // Functions

    void set_piece_positions(const string&);
    void set_active_color(const string&);
    void set_castling_rights(const string&);
    void set_passant_target_sq(const string&);
    void set_halfmove_clock(const string&);
    void set_fullmove_number(const string&);

    void generate_moves(void);
    void evaluate(void);
    void move(const string& move, const int moving_piece);
    int get_moving_piece(int square);
    bool is_square_attacked(bitboard square);

    string to_fen_string();
};

#endif  // SRC_POSITION_HPP_
