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

    int white_material = get_white_material_value(&pos);
    EXPECT_EQ (white_material, 14250);
}

//
// START GET BLACK MATERIAL TEST ///////////////////////////////////////////////
//

TEST(black_material, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int black_material = get_black_material_value(&pos);
    EXPECT_EQ (black_material, -14250);
}

//
// START EVALUATE POSITION TEST ////////////////////////////////////////////////
//

TEST(position_eval, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = std::numeric_limits<bitboard>::max() / 2;
    EXPECT_EQ (position_value, half);
}

TEST(position_eval, no_white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNB1KBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = std::numeric_limits<bitboard>::max() / 2;
    EXPECT_EQ (position_value, half-1000);
}

TEST(position_eval, no_white_pieces) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/8/8 w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = std::numeric_limits<bitboard>::max() / 2;
    EXPECT_EQ (position_value, half-14250);
}

TEST(position_eval, no_black_queen) {
    std::string test = "rnb1kbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = std::numeric_limits<bitboard>::max() / 2;
    EXPECT_EQ (position_value, half+1000);
}

TEST(position_eval, no_black_pieces) {
    std::string test = "8/8/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    bitboard half = std::numeric_limits<bitboard>::max() / 2;
    EXPECT_EQ (position_value, half+14250);
}

