#include "gtest/gtest.h"
#include "../src/evaluate.hpp"
#include "../src/common.hpp"
#include <string>

//
// START GET WHITE MATERIAL TEST ///////////////////////////////////////////////
//

TEST(white_material, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int material = get_material_value_score(&pos);
    EXPECT_EQ (material, 0);
}

//
// START EVALUATE POSITION TEST ////////////////////////////////////////////////
//

TEST(position_eval, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = 0;
    EXPECT_EQ (position_value, half);
}

TEST(position_eval, no_white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNB1KBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = 0;
    EXPECT_EQ (position_value, half - QUEEN);
}

TEST(position_eval, no_white_pieces) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/8/8 w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = 0;

    int all_pieces = KING + QUEEN + (ROOK * 2) + (KNIGHT * 2) + (BISHOP * 2) + (PAWN * 8);
    EXPECT_EQ (position_value, half - all_pieces);
}

TEST(position_eval, no_black_queen) {
    std::string test = "rnb1kbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = 0;
    EXPECT_EQ (position_value, half + QUEEN);
}

TEST(position_eval, no_black_pieces) {
    std::string test = "8/8/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = 0;
    int all_pieces = KING + QUEEN + (ROOK * 2) + (KNIGHT * 2) + (BISHOP * 2) + (PAWN * 8);
    EXPECT_EQ (position_value, half + all_pieces);
}

