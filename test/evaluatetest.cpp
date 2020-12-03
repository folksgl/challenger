#include "gtest/gtest.h"
#include "../src/evaluate.hpp"
#include "../src/common.hpp"

//
// START GET WHITE MATERIAL TEST ///////////////////////////////////////////////
//

TEST(white_material, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int material = get_material_value_score(&pos);
    EXPECT_EQ(material, 0);
}

//
// START EVALUATE POSITION TEST ////////////////////////////////////////////////
//

TEST(position_eval, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int position_value = evaluate_position(&pos);
    EXPECT_EQ(position_value, 0);
}

TEST(position_eval, no_white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNB1KBNR w KQkq - 0 1";
    Position pos(test);

    int position_value = evaluate_position(&pos);
    int half = 0;
    EXPECT_LE(position_value, half - QUEEN);
}

TEST(position_eval, no_white_pieces) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/8/8 w KQkq - 0 1";
    Position pos(test);

    int position_value = evaluate_position(&pos);
    int half = 0;

    int all_pieces = KING + QUEEN + (ROOK * 2) + (KNIGHT * 2) + (BISHOP * 2) + (PAWN * 8);
    EXPECT_LE(position_value, half - all_pieces);
}

TEST(position_eval, no_black_queen) {
    std::string test = "rnb1kbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    int half = 0;
    EXPECT_GE(position_value, half + QUEEN);
}

TEST(position_eval, no_black_pieces) {
    std::string test = "8/8/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    bitboard position_value = evaluate_position(&pos);
    int all_pieces = KING + QUEEN + (ROOK * 2) + (KNIGHT * 2) + (BISHOP * 2) + (PAWN * 8);
    EXPECT_GE(position_value, all_pieces);
}

TEST(evaluation, white_pawn_defending) {
    std::string test = "rnbqk1nr/ppp1pppp/8/2Np1b2/3P4/4P3/PPP2PPP/RNBQKB1R w KQkq - 0 1";
    Position pos(test);

    int position_value = white_defending_pawns_bonus(&pos);
    EXPECT_EQ(position_value, PAWN_DEFEND * 3);
}

TEST(evaluation, black_pawn_defending) {
    std::string test = "r1bqk1nr/ppp2ppp/4p3/2Np1b2/2nP1B2/4P3/PPP2PPP/RNBQK2R w KQkq - 0 1";
    Position pos(test);

    int position_value = black_defending_pawns_bonus(&pos);
    EXPECT_EQ(position_value, PAWN_DEFEND * 4);
}

TEST(evaluation, white_knight_center_board) {
    std::string test = "r1bqk1nr/ppp2ppp/4p3/2Np1b2/2nP1B2/4P3/PPP2PPP/RNBQK2R w KQkq - 0 1";
    Position pos(test);

    int position_value = knight_center_bonus(pos.maps[w_knight]);
    EXPECT_EQ(position_value, KNIGNT_CENTER * 1);
}

TEST(evaluation, black_knight_center_board) {
    std::string test = "r1bqk1nr/ppp2ppp/4p3/2Np1b2/2nP1B2/4P3/PPP2PPP/RNBQK2R w KQkq - 0 1";
    Position pos(test);

    int position_value = knight_center_bonus(pos.maps[b_knight]);
    EXPECT_EQ(position_value, KNIGNT_CENTER * 1);
}

