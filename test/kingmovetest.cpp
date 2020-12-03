#include "gtest/gtest.h"
#include "../src/genmove.hpp"
#include "../src/uci.hpp"
#include "../src/common.hpp"

TEST(correct_king_moves_generated, white_king_a1) {
    std::string test = "8/8/8/8/8/8/8/K7 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a1a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a1b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a1b2");
}

TEST(correct_king_moves_generated, white_king_b1) {
    std::string test = "8/8/8/8/8/8/8/1K6 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b1a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b1a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b1b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b1c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b1c2");
}

TEST(correct_king_moves_generated, white_king_c1) {
    std::string test = "8/8/8/8/8/8/8/2K5 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c1b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c1b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c1c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c1d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c1d2");
}

TEST(correct_king_moves_generated, white_king_d1) {
    std::string test = "8/8/8/8/8/8/8/3K4 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d1c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d1c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d1d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d1e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d1e2");
}

TEST(correct_king_moves_generated, white_king_e1) {
    std::string test = "8/8/8/8/8/8/8/4K3 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e1d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e1d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e1e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e1f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e1f2");
}

TEST(correct_king_moves_generated, white_king_f1) {
    std::string test = "8/8/8/8/8/8/8/5K2 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f1e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f1e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f1f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f1g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f1g2");
}

TEST(correct_king_moves_generated, white_king_g1) {
    std::string test = "8/8/8/8/8/8/8/6K1 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g1f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g1f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g1g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g1h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g1h2");
}

TEST(correct_king_moves_generated, white_king_h1) {
    std::string test = "8/8/8/8/8/8/8/7K w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h1g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h1g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h1h2");
}

TEST(correct_king_moves_generated, white_king_a2) {
    std::string test = "8/8/8/8/8/8/K7/8 w KQkq - 0 1";
    Position startpos(test);

    string actualstring = startpos.to_fen_string();
    EXPECT_EQ(actualstring, test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a2b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a2b3");
}

TEST(correct_king_moves_generated, white_king_b2) {
    std::string test = "8/8/8/8/8/8/1K6/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b2c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b2c3");
}

TEST(correct_king_moves_generated, white_king_c2) {
    std::string test = "8/8/8/8/8/8/2K5/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c2b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c2d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c2d3");
}

TEST(correct_king_moves_generated, white_king_d2) {
    std::string test = "8/8/8/8/8/8/3K4/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d2c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d2e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d2e3");
}

TEST(correct_king_moves_generated, white_king_e2) {
    std::string test = "8/8/8/8/8/8/4K3/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e2d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e2f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e2f3");
}

TEST(correct_king_moves_generated, white_king_f2) {
    std::string test = "8/8/8/8/8/8/5K2/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f2e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f2g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f2g3");
}

TEST(correct_king_moves_generated, white_king_g2) {
    std::string test = "8/8/8/8/8/8/6K1/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g2f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g2h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g2h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g2h3");
}

TEST(correct_king_moves_generated, white_king_h2) {
    std::string test = "8/8/8/8/8/8/7K/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h2g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h2h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h2h3");
}

TEST(correct_king_moves_generated, white_king_a3) {
    std::string test = "8/8/8/8/8/K7/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a3b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a3b4");
}

TEST(correct_king_moves_generated, white_king_b3) {
    std::string test = "8/8/8/8/8/1K6/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b3a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b3b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b3c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b3c4");
}

TEST(correct_king_moves_generated, white_king_c3) {
    std::string test = "8/8/8/8/8/2K5/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c3b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c3b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c3c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c3d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c3d4");
}

TEST(correct_king_moves_generated, white_king_d3) {
    std::string test = "8/8/8/8/8/3K4/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d3c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d3c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d3d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d3e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d3e4");
}

TEST(correct_king_moves_generated, white_king_e3) {
    std::string test = "8/8/8/8/8/4K3/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e3d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e3d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e3e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e3f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e3f4");
}

TEST(correct_king_moves_generated, white_king_f3) {
    std::string test = "8/8/8/8/8/5K2/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f3e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f3e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f3f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f3g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f3g4");
}

TEST(correct_king_moves_generated, white_king_g3) {
    std::string test = "8/8/8/8/8/6K1/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g3f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g3f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g3g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g3h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g3h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g3h4");
}

TEST(correct_king_moves_generated, white_king_h3) {
    std::string test = "8/8/8/8/8/7K/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h3g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h3g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h3h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h3h4");
}

TEST(correct_king_moves_generated, white_king_a4) {
    std::string test = "8/8/8/8/K7/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a4a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a4a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a4b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a4b5");
}

TEST(correct_king_moves_generated, white_king_b4) {
    std::string test = "8/8/8/8/1K6/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b4a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b4a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b4a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b4b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b4c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b4c5");
}

TEST(correct_king_moves_generated, white_king_c4) {
    std::string test = "8/8/8/8/2K5/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c4b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c4b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c4d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c4d5");
}

TEST(correct_king_moves_generated, white_king_d4) {
    std::string test = "8/8/8/8/3K4/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d4c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d4e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d4e5");
}

TEST(correct_king_moves_generated, white_king_e4) {
    std::string test = "8/8/8/8/4K3/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e4d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e4e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e4f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e4f5");
}

TEST(correct_king_moves_generated, white_king_f4) {
    std::string test = "8/8/8/8/5K2/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f4e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f4e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f4f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f4g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f4g5");
}

TEST(correct_king_moves_generated, white_king_g4) {
    std::string test = "8/8/8/8/6K1/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g4f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g4f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g4g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g4h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g4h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g4h5");
}

TEST(correct_king_moves_generated, white_king_h4) {
    std::string test = "8/8/8/8/7K/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h4g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h4g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h4h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h4h5");
}

TEST(correct_king_moves_generated, white_king_a5) {
    std::string test = "8/8/8/K7/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });


    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a5a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a5a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a5b6");
}

TEST(correct_king_moves_generated, white_king_b5) {
    std::string test = "8/8/8/1K6/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b5a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b5a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b5a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b5b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b5c6");
}

TEST(correct_king_moves_generated, white_king_c5) {
    std::string test = "8/8/8/2K5/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c5b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c5d6");
}

TEST(correct_king_moves_generated, white_king_d5) {
    std::string test = "8/8/8/3K4/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d5e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d5e6");
}

TEST(correct_king_moves_generated, white_king_e5) {
    std::string test = "8/8/8/4K3/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5f6");
}

TEST(correct_king_moves_generated, white_king_f5) {
    std::string test = "8/8/8/5K2/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f5e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f5g6");
}

TEST(correct_king_moves_generated, white_king_g5) {
    std::string test = "8/8/8/6K1/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g5g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g5h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g5h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g5h6");
}

TEST(correct_king_moves_generated, white_king_h5) {
    std::string test = "8/8/8/7K/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h5g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h5h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h5h6");
}

TEST(correct_king_moves_generated, white_king_a6) {
    std::string test = "8/8/K7/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a6a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a6a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a6b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a6b7");
}

TEST(correct_king_moves_generated, white_king_b6) {
    std::string test = "8/8/1K6/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b6a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b6a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b6a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b6b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b6c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b6c7");
}

TEST(correct_king_moves_generated, white_king_c6) {
    std::string test = "8/8/2K5/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c6b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c6b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c6c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c6d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c6d7");
}

TEST(correct_king_moves_generated, white_king_d6) {
    std::string test = "8/8/3K4/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d6c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d6c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d6d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d6e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d6e7");
}

TEST(correct_king_moves_generated, white_king_e6) {
    std::string test = "8/8/4K3/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e6d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e6d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e6e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e6f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e6f7");
}

TEST(correct_king_moves_generated, white_king_f6) {
    std::string test = "8/8/5K2/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f6e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f6e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f6f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f6g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f6g7");
}

TEST(correct_king_moves_generated, white_king_g6) {
    std::string test = "8/8/6K1/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g6f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g6f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g6g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g6h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g6h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g6h7");
}

TEST(correct_king_moves_generated, white_king_h6) {
    std::string test = "8/8/7K/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h6g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h6g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h6h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h6h7");
}

TEST(correct_king_moves_generated, white_king_a7) {
    std::string test = "8/K7/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a7a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a7b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a7b8");
}

TEST(correct_king_moves_generated, white_king_b7) {
    std::string test = "8/1K6/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b7a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b7b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b7c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b7c8");
}

TEST(correct_king_moves_generated, white_king_c7) {
    std::string test = "8/2K5/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c7b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c7b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c7c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c7d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c7d8");
}

TEST(correct_king_moves_generated, white_king_d7) {
    std::string test = "8/3K4/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d7c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d7c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d7d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d7e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d7e8");
}

TEST(correct_king_moves_generated, white_king_e7) {
    std::string test = "8/4K3/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e7d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e7d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e7e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e7f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e7f8");
}

TEST(correct_king_moves_generated, white_king_f7) {
    std::string test = "8/5K2/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f7e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f7e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f7f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f7g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f7g8");
}

TEST(correct_king_moves_generated, white_king_g7) {
    std::string test = "8/6K1/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g7f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g7f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g7g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g7h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g7h7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g7h8");
}

TEST(correct_king_moves_generated, white_king_h7) {
    std::string test = "8/7K/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h7g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h7g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h7h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h7h8");
}

TEST(correct_king_moves_generated, white_king_a8) {
    std::string test = "K7/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a8a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a8b8");
}

TEST(correct_king_moves_generated, white_king_b8) {
    std::string test = "1K6/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b8a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b8a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b8c8");
}

TEST(correct_king_moves_generated, white_king_c8) {
    std::string test = "2K5/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c8b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c8d8");
}

TEST(correct_king_moves_generated, white_king_d8) {
    std::string test = "3K4/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d8c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d8e8");
}

TEST(correct_king_moves_generated, white_king_e8) {
    std::string test = "4K3/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e8d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e8f8");
}

TEST(correct_king_moves_generated, white_king_f8) {
    std::string test = "5K2/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f8e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f8g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f8g8");
}

TEST(correct_king_moves_generated, white_king_g8) {
    std::string test = "6K1/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g8f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g8g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g8h7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g8h8");
}

TEST(correct_king_moves_generated, white_king_h8) {
    std::string test = "7K/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h8g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h8g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h8h7");
}

TEST(correct_king_moves_generated, black_king_a1) {
    std::string test = "8/8/8/8/8/8/8/k7 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a1a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a1b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a1b2");
}

TEST(correct_king_moves_generated, black_king_b1) {
    std::string test = "8/8/8/8/8/8/8/1k6 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b1a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b1a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b1b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b1c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b1c2");
}

TEST(correct_king_moves_generated, black_king_c1) {
    std::string test = "8/8/8/8/8/8/8/2k5 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c1b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c1b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c1c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c1d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c1d2");
}

TEST(correct_king_moves_generated, black_king_d1) {
    std::string test = "8/8/8/8/8/8/8/3k4 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d1c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d1c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d1d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d1e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d1e2");
}

TEST(correct_king_moves_generated, black_king_e1) {
    std::string test = "8/8/8/8/8/8/8/4k3 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e1d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e1d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e1e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e1f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e1f2");
}

TEST(correct_king_moves_generated, black_king_f1) {
    std::string test = "8/8/8/8/8/8/8/5k2 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f1e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f1e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f1f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f1g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f1g2");
}

TEST(correct_king_moves_generated, black_king_g1) {
    std::string test = "8/8/8/8/8/8/8/6k1 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g1f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g1f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g1g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g1h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g1h2");
}

TEST(correct_king_moves_generated, black_king_h1) {
    std::string test = "8/8/8/8/8/8/8/7k b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h1g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h1g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h1h2");
}

TEST(correct_king_moves_generated, black_king_a2) {
    std::string test = "8/8/8/8/8/8/k7/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a2b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a2b3");
}

TEST(correct_king_moves_generated, black_king_b2) {
    std::string test = "8/8/8/8/8/8/1k6/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b2c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b2c3");
}

TEST(correct_king_moves_generated, black_king_c2) {
    std::string test = "8/8/8/8/8/8/2k5/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c2b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c2d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c2d3");
}

TEST(correct_king_moves_generated, black_king_d2) {
    std::string test = "8/8/8/8/8/8/3k4/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d2c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d2e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d2e3");
}

TEST(correct_king_moves_generated, black_king_e2) {
    std::string test = "8/8/8/8/8/8/4k3/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e2d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e2f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e2f3");
}

TEST(correct_king_moves_generated, black_king_f2) {
    std::string test = "8/8/8/8/8/8/5k2/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f2e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f2g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f2g3");
}

TEST(correct_king_moves_generated, black_king_g2) {
    std::string test = "8/8/8/8/8/8/6k1/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g2f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g2h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g2h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g2h3");
}

TEST(correct_king_moves_generated, black_king_h2) {
    std::string test = "8/8/8/8/8/8/7k/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h2g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h2h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h2h3");
}

TEST(correct_king_moves_generated, black_king_a3) {
    std::string test = "8/8/8/8/8/k7/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a3b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a3b4");
}

TEST(correct_king_moves_generated, black_king_b3) {
    std::string test = "8/8/8/8/8/1k6/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b3a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b3b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b3c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b3c4");
}

TEST(correct_king_moves_generated, black_king_c3) {
    std::string test = "8/8/8/8/8/2k5/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c3b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c3b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c3c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c3d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c3d4");
}

TEST(correct_king_moves_generated, black_king_d3) {
    std::string test = "8/8/8/8/8/3k4/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d3c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d3c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d3d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d3e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d3e4");
}

TEST(correct_king_moves_generated, black_king_e3) {
    std::string test = "8/8/8/8/8/4k3/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e3d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e3d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e3e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e3f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e3f4");
}

TEST(correct_king_moves_generated, black_king_f3) {
    std::string test = "8/8/8/8/8/5k2/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f3e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f3e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f3f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f3g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f3g4");
}

TEST(correct_king_moves_generated, black_king_g3) {
    std::string test = "8/8/8/8/8/6k1/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g3f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g3f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g3g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g3h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g3h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g3h4");
}

TEST(correct_king_moves_generated, black_king_h3) {
    std::string test = "8/8/8/8/8/7k/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h3g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h3g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h3h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h3h4");
}

TEST(correct_king_moves_generated, black_king_a4) {
    std::string test = "8/8/8/8/k7/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a4a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a4a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a4b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a4b5");
}

TEST(correct_king_moves_generated, black_king_b4) {
    std::string test = "8/8/8/8/1k6/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b4a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b4a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b4a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b4b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b4c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b4c5");
}

TEST(correct_king_moves_generated, black_king_c4) {
    std::string test = "8/8/8/8/2k5/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c4b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c4b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c4d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c4d5");
}

TEST(correct_king_moves_generated, black_king_d4) {
    std::string test = "8/8/8/8/3k4/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d4c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d4e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d4e5");
}

TEST(correct_king_moves_generated, black_king_e4) {
    std::string test = "8/8/8/8/4k3/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e4d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e4e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e4f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e4f5");
}

TEST(correct_king_moves_generated, black_king_f4) {
    std::string test = "8/8/8/8/5k2/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f4e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f4e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f4f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f4g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f4g5");
}

TEST(correct_king_moves_generated, black_king_g4) {
    std::string test = "8/8/8/8/6k1/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g4f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g4f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g4g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g4h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g4h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g4h5");
}

TEST(correct_king_moves_generated, black_king_h4) {
    std::string test = "8/8/8/8/7k/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h4g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h4g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h4h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h4h5");
}

TEST(correct_king_moves_generated, black_king_a5) {
    std::string test = "8/8/8/k7/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });


    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a5a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a5a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a5b6");
}

TEST(correct_king_moves_generated, black_king_b5) {
    std::string test = "8/8/8/1k6/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b5a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b5a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b5a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b5b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b5c6");
}

TEST(correct_king_moves_generated, black_king_c5) {
    std::string test = "8/8/8/2k5/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c5b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c5d6");
}

TEST(correct_king_moves_generated, black_king_d5) {
    std::string test = "8/8/8/3k4/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d5e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d5e6");
}

TEST(correct_king_moves_generated, black_king_e5) {
    std::string test = "8/8/8/4k3/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5f6");
}

TEST(correct_king_moves_generated, black_king_f5) {
    std::string test = "8/8/8/5k2/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f5e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f5g6");
}

TEST(correct_king_moves_generated, black_king_g5) {
    std::string test = "8/8/8/6k1/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g5g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g5h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g5h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g5h6");
}

TEST(correct_king_moves_generated, black_king_h5) {
    std::string test = "8/8/8/7k/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h5g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h5h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h5h6");
}

TEST(correct_king_moves_generated, black_king_a6) {
    std::string test = "8/8/k7/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a6a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a6a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a6b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a6b7");
}

TEST(correct_king_moves_generated, black_king_b6) {
    std::string test = "8/8/1k6/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b6a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b6a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b6a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b6b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b6c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b6c7");
}

TEST(correct_king_moves_generated, black_king_c6) {
    std::string test = "8/8/2k5/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c6b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c6b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c6c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c6d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c6d7");
}

TEST(correct_king_moves_generated, black_king_d6) {
    std::string test = "8/8/3k4/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d6c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d6c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d6d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d6e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d6e7");
}

TEST(correct_king_moves_generated, black_king_e6) {
    std::string test = "8/8/4k3/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e6d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e6d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e6e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e6f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e6f7");
}

TEST(correct_king_moves_generated, black_king_f6) {
    std::string test = "8/8/5k2/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f6e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f6e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f6f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f6g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f6g7");
}

TEST(correct_king_moves_generated, black_king_g6) {
    std::string test = "8/8/6k1/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g6f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g6f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g6g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g6h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g6h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g6h7");
}

TEST(correct_king_moves_generated, black_king_h6) {
    std::string test = "8/8/7k/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h6g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h6g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h6h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h6h7");
}

TEST(correct_king_moves_generated, black_king_a7) {
    std::string test = "8/k7/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a7a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a7b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "a7b8");
}

TEST(correct_king_moves_generated, black_king_b7) {
    std::string test = "8/1k6/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b7a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b7b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b7c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "b7c8");
}

TEST(correct_king_moves_generated, black_king_c7) {
    std::string test = "8/2k5/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c7b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c7b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c7c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c7d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c7d8");
}

TEST(correct_king_moves_generated, black_king_d7) {
    std::string test = "8/3k4/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d7c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d7c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d7d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d7e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d7e8");
}

TEST(correct_king_moves_generated, black_king_e7) {
    std::string test = "8/4k3/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e7d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e7d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e7e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e7f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e7f8");
}

TEST(correct_king_moves_generated, black_king_f7) {
    std::string test = "8/5k2/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f7e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f7e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f7f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f7g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f7g8");
}

TEST(correct_king_moves_generated, black_king_g7) {
    std::string test = "8/6k1/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g7f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g7f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g7g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g7h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "g7h7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "g7h8");
}

TEST(correct_king_moves_generated, black_king_h7) {
    std::string test = "8/7k/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h7g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h7g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h7h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "h7h8");
}

TEST(correct_king_moves_generated, black_king_a8) {
    std::string test = "k7/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a8a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a8b8");
}

TEST(correct_king_moves_generated, black_king_b8) {
    std::string test = "1k6/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b8a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b8a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b8c8");
}

TEST(correct_king_moves_generated, black_king_c8) {
    std::string test = "2k5/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c8b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c8d8");
}

TEST(correct_king_moves_generated, black_king_d8) {
    std::string test = "3k4/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d8c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d8e8");
}

TEST(correct_king_moves_generated, black_king_e8) {
    std::string test = "4k3/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e8d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e8f8");
}

TEST(correct_king_moves_generated, black_king_f8) {
    std::string test = "5k2/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f8e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f8g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f8g8");
}

TEST(correct_king_moves_generated, black_king_g8) {
    std::string test = "6k1/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 5);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g8f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g8g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g8h7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g8h8");
}

TEST(correct_king_moves_generated, black_king_h8) {
    std::string test = "7k/8/8/8/8/8/8/8 b KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(),
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h8g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h8g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h8h7");
}

