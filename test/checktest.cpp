#include "gtest/gtest.h"
#include "../src/genmove.hpp"
#include "../src/uci.hpp"
#include "../src/common.hpp"
#include <string>

using namespace std;

//
// Ensure pawn moves don't introduce check.
//

TEST(pawn_doesnt_introduce_check, forward_castle) {
    std::string test = "8/8/8/8/8/KP4r1/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a3b4");
}

TEST(pawn_doesnt_introduce_check, attack_right_castle) {
    std::string test = "8/8/8/8/3r4/1KP3r1/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b3a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b3c2");
}

TEST(pawn_doesnt_introduce_check, attack_right_capture_knight) {
    std::string test = "8/8/8/8/3n4/1KP3r1/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b3a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b3b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b3c4");
}

TEST(pawn_doesnt_introduce_check, forward_bishop) {
    std::string test = "8/8/8/8/3b4/2P3r1/1K6/8 w KQkq - 0 1";
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
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c3d4");
}

TEST(pawn_doesnt_introduce_check, forward_queen) {
    std::string test = "8/8/8/8/3q4/2P3r1/1K6/8 w KQkq - 0 1";
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
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c3d4");
}

TEST(pawn_doesnt_introduce_check, forward_knight) {
    std::string test = "8/8/8/8/3n4/2P3r1/1K6/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 7);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c3c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c3d4");
}

//
// Ensure king moves don't introduce check.
//

TEST(king_doesnt_introduce_check, doubled_pawn) {
    std::string test = "8/8/8/8/3p4/2p5/1K6/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 7);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b2c2");
}

TEST(king_doesnt_introduce_check, enemy_king) {
    std::string test = "8/8/8/8/3k4/2p5/1K6/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 7);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "b2c2");
}

