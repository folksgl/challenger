#include "gtest/gtest.h"
#include "../src/genmove.h"
#include "../src/uci.h"
#include <string>

using namespace std;

/*
 *  Generating moves is likely the most difficult task challenger performs. As such, its 
 *  going to recieve a little special treatment when it comes to the grouping of the 
 *  tests within this file. The tests will be grouped by move generation for specific 
 *  pieces instead of the type of tests themselves. For example, there will be one test 
 *  per section checking the number of moves generated by specific call, instead of a 
 *  single section for tests that check the same number.
 */

//
// START WHITE MOVE TESTS //////////////////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_white_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 20);
}

//
// START BLACK MOVE TESTS //////////////////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_black_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 20);
}

//
// START WHITE PAWN GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white_pawns) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 16);
}

TEST(correct_moves_generated, startpos_white) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a2a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c2c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d2d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "e2e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "f2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "f2f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "g2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "g2g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),  "h2h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[15]),  "h2h4");
}

TEST(correct_moves_generated, tripple_pawn_standoff_white) {
    std::string test = "rnbqkbnr/pp3ppp/8/2ppp3/2PPP3/8/PP3PPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 14);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a2a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d4e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "f2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "f2f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "g2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "g2g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "h2h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "h2h4");
}

TEST(correct_moves_generated, blocked_white_pawn) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/p7/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 15);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c2c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d2d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e2e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "f2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "f2f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "g2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "g2g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "h2h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),  "h2h4");
}


TEST(capture_passant, white) {
    std::string test = "rnbqkbnr/ppp1pppp/8/2Pp4/8/8/PP1PPPPP/RNBQKBNR w KQkq d6 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a2a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d2d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "e2e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "f2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "f2f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "g2g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "g2g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),  "h2h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[15]),  "h2h4");

}

//
// START BLACK PAWN GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black_pawns) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 16);
}

TEST(correct_moves_generated, startpos_black) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a7a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c7c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d7d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e7e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "e7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "f7f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "f7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "g7g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "g7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),  "h7h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[15]),  "h7h6");
}

TEST(correct_moves_generated, tripple_pawn_standoff_black) {
    std::string test = "rnbqkbnr/pp3ppp/8/2ppp3/2PPP3/8/PP3PPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 14);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a7a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "f7f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "f7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "g7g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "g7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "h7h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "h7h6");
}

TEST(correct_moves_generated, blocked_black_pawn) {
    std::string test = "rnbqkbnr/pppppppp/P7/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 15);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b7b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c7c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d7d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e7e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "f7f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "f7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "g7g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "g7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "h7h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),  "h7h6");
}


TEST(capture_passant, black) {
    std::string test = "rnbqkbnr/pp1ppppp/8/8/2pP4/8/PP2PPPP/RNBQKBNR b KQkq d3 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a7a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d7d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e7e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "e7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),  "f7f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),  "f7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),  "g7g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),  "g7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),  "h7h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[15]),  "h7h6");

}

//
// START WHITE KNIGHT GENERATION TESTS /////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_knight_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 4);
}

TEST(correct_moves_generated, startpos_white_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b1a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b1c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g1f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g1h3");
}

TEST(correct_moves_generated, e5_white_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/4N3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 12);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b1a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b1c3");

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e5d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e5d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e5f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "e5g6");

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),   "g1f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),   "g1h3");
}

//
// START BLACK KNIGHT GENERATION TESTS /////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_knight_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 4);
}

TEST(correct_moves_generated, startpos_black_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b8a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b8c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g8f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g8h6");
}

TEST(correct_moves_generated, e4_black_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/4n3/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 12);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b8a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b8c6");

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e4d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e4d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e4f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e4f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),   "e4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),   "e4g5");

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),   "g8f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),   "g8h6");
}

//
// START WHITE BISHOP GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_bishop_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, e5_white_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/4B3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_bishop_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(correct_moves_generated, e5_white_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/4B3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_bishop_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e5c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e5c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e5g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5g7");
}

//
// START BLACK BISHOP GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_bishop_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, e5_black_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/4b3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_bishop_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(correct_moves_generated, e5_black_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/4b3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_bishop_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e5b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e5c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e5g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5h2");
}

//
// START WHITE ROOK GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_rook_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, e5_white_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/4R3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_rook_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 11);
}

TEST(correct_moves_generated, e5_white_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/4R3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_rook_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 11);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),    "e5a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),    "e5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),    "e5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),    "e5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),    "e5e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),    "e5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),    "e5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),    "e5e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),    "e5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),    "e5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),   "e5h5");
}

//
// START BLACK ROOK GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_rook_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, e5_black_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/4r3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_rook_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 11);
}

TEST(correct_moves_generated, e5_black_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/4r3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_rook_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 11);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),    "e5a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),    "e5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),    "e5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),    "e5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),    "e5e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),    "e5e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),    "e5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),    "e5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),    "e5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),    "e5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),   "e5h5");
}

//
// START WHITE QUEEN GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_queen_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, e5_white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/4Q3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_queen_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 19);
}

TEST(correct_moves_generated, e5_white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/4Q3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_queen_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 19);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),     "e5a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),     "e5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),     "e5c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),     "e5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),     "e5c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),     "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),     "e5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),     "e5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),     "e5e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),     "e5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),    "e5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),    "e5e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),    "e5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),    "e5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),    "e5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[15]),    "e5g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[16]),    "e5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[17]),    "e5g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[18]),    "e5h5");
}

//
// START BLACK QUEEN GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_queen_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, e5_black_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/4q3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_queen_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 19);
}

TEST(correct_moves_generated, e5_black_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/4q3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_queen_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 19);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),     "e5a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),     "e5b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),     "e5b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),     "e5c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),     "e5c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),     "e5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),     "e5d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),     "e5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[8]),     "e5e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[9]),     "e5e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[10]),    "e5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[11]),    "e5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[12]),    "e5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[13]),    "e5f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[14]),    "e5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[15]),    "e5g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[16]),    "e5g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[17]),    "e5h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[18]),    "e5h5");
}

//
// START WHITE KING GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_white_king) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_king_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, middleboard_white_king) {
    std::string test = "rnbqkbnr/pppppppp/8/8/4K3/8/PPPPPPPP/RNBQ1BNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_king_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(number_of_moves_generated, pressed_white_king) {
    std::string test = "rnbqkbnr/pppppppp/4K3/8/8/8/PPPPPPPP/RNBQ1BNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_king_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(correct_moves_generated, middleboard_white_king) {
    std::string test = "rnbqkbnr/pppppppp/8/4K3/8/8/PPPPPPPP/RNBQ1BNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_king_moves(&startpos);
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

//
// START BLACK KING GENERATION TESTS ///////////////////////////////////////////
//

TEST(number_of_moves_generated, startpos_black_king) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_king_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 0);
}

TEST(number_of_moves_generated, middleboard_black_king) {
    std::string test = "rnbq1bnr/pppppppp/8/4k3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_king_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(number_of_moves_generated, pressed_black_king) {
    std::string test = "rnbq1bnr/pppppppp/8/8/8/4k3/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_king_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(correct_moves_generated, middleboard_black_king) {
    std::string test = "rnbq1bnr/pppppppp/8/4k3/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_king_moves(&startpos);
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

