#include "gtest/gtest.h"
#include "../src/genmove.h"
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
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
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
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(startpos.moves[0].movestring,   "a2a3");
    EXPECT_EQ(startpos.moves[1].movestring,   "a2a4");
    EXPECT_EQ(startpos.moves[2].movestring,   "b2b3");
    EXPECT_EQ(startpos.moves[3].movestring,   "b2b4");
    EXPECT_EQ(startpos.moves[4].movestring,   "c2c3");
    EXPECT_EQ(startpos.moves[5].movestring,   "c2c4");
    EXPECT_EQ(startpos.moves[6].movestring,   "d2d3");
    EXPECT_EQ(startpos.moves[7].movestring,   "d2d4");
    EXPECT_EQ(startpos.moves[8].movestring,   "e2e3");
    EXPECT_EQ(startpos.moves[9].movestring,   "e2e4");
    EXPECT_EQ(startpos.moves[10].movestring,  "f2f3");
    EXPECT_EQ(startpos.moves[11].movestring,  "f2f4");
    EXPECT_EQ(startpos.moves[12].movestring,  "g2g3");
    EXPECT_EQ(startpos.moves[13].movestring,  "g2g4");
    EXPECT_EQ(startpos.moves[14].movestring,  "h2h3");
    EXPECT_EQ(startpos.moves[15].movestring,  "h2h4");
}

TEST(correct_moves_generated, tripple_pawn_standoff_white) {
    std::string test = "rnbqkbnr/pp3ppp/8/2ppp3/2PPP3/8/PP3PPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 14);

    EXPECT_EQ(startpos.moves[0].movestring,   "a2a3");
    EXPECT_EQ(startpos.moves[1].movestring,   "a2a4");
    EXPECT_EQ(startpos.moves[2].movestring,   "b2b3");
    EXPECT_EQ(startpos.moves[3].movestring,   "b2b4");
    EXPECT_EQ(startpos.moves[4].movestring,   "c4d5");
    EXPECT_EQ(startpos.moves[5].movestring,   "d4c5");
    EXPECT_EQ(startpos.moves[6].movestring,   "d4e5");
    EXPECT_EQ(startpos.moves[7].movestring,   "e4d5");
    EXPECT_EQ(startpos.moves[8].movestring,   "f2f3");
    EXPECT_EQ(startpos.moves[9].movestring,   "f2f4");
    EXPECT_EQ(startpos.moves[10].movestring,  "g2g3");
    EXPECT_EQ(startpos.moves[11].movestring,  "g2g4");
    EXPECT_EQ(startpos.moves[12].movestring,  "h2h3");
    EXPECT_EQ(startpos.moves[13].movestring,  "h2h4");
}

TEST(correct_moves_generated, blocked_white_pawn) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/p7/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 15);

    EXPECT_EQ(startpos.moves[0].movestring,   "b2a3");
    EXPECT_EQ(startpos.moves[1].movestring,   "b2b3");
    EXPECT_EQ(startpos.moves[2].movestring,   "b2b4");
    EXPECT_EQ(startpos.moves[3].movestring,   "c2c3");
    EXPECT_EQ(startpos.moves[4].movestring,   "c2c4");
    EXPECT_EQ(startpos.moves[5].movestring,   "d2d3");
    EXPECT_EQ(startpos.moves[6].movestring,   "d2d4");
    EXPECT_EQ(startpos.moves[7].movestring,   "e2e3");
    EXPECT_EQ(startpos.moves[8].movestring,   "e2e4");
    EXPECT_EQ(startpos.moves[9].movestring,   "f2f3");
    EXPECT_EQ(startpos.moves[10].movestring,  "f2f4");
    EXPECT_EQ(startpos.moves[11].movestring,  "g2g3");
    EXPECT_EQ(startpos.moves[12].movestring,  "g2g4");
    EXPECT_EQ(startpos.moves[13].movestring,  "h2h3");
    EXPECT_EQ(startpos.moves[14].movestring,  "h2h4");
}


TEST(capture_passant, white) {
    std::string test = "rnbqkbnr/ppp1pppp/8/2Pp4/8/8/PP1PPPPP/RNBQKBNR w KQkq d6 0 1";
    Position startpos(test);

    generate_w_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(startpos.moves[0].movestring,   "a2a3");
    EXPECT_EQ(startpos.moves[1].movestring,   "a2a4");
    EXPECT_EQ(startpos.moves[2].movestring,   "b2b3");
    EXPECT_EQ(startpos.moves[3].movestring,   "b2b4");
    EXPECT_EQ(startpos.moves[4].movestring,   "c5c6");
    EXPECT_EQ(startpos.moves[5].movestring,   "c5d6");
    EXPECT_EQ(startpos.moves[6].movestring,   "d2d3");
    EXPECT_EQ(startpos.moves[7].movestring,   "d2d4");
    EXPECT_EQ(startpos.moves[8].movestring,   "e2e3");
    EXPECT_EQ(startpos.moves[9].movestring,   "e2e4");
    EXPECT_EQ(startpos.moves[10].movestring,  "f2f3");
    EXPECT_EQ(startpos.moves[11].movestring,  "f2f4");
    EXPECT_EQ(startpos.moves[12].movestring,  "g2g3");
    EXPECT_EQ(startpos.moves[13].movestring,  "g2g4");
    EXPECT_EQ(startpos.moves[14].movestring,  "h2h3");
    EXPECT_EQ(startpos.moves[15].movestring,  "h2h4");

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
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(startpos.moves[0].movestring,   "a7a5");
    EXPECT_EQ(startpos.moves[1].movestring,   "a7a6");
    EXPECT_EQ(startpos.moves[2].movestring,   "b7b5");
    EXPECT_EQ(startpos.moves[3].movestring,   "b7b6");
    EXPECT_EQ(startpos.moves[4].movestring,   "c7c5");
    EXPECT_EQ(startpos.moves[5].movestring,   "c7c6");
    EXPECT_EQ(startpos.moves[6].movestring,   "d7d5");
    EXPECT_EQ(startpos.moves[7].movestring,   "d7d6");
    EXPECT_EQ(startpos.moves[8].movestring,   "e7e5");
    EXPECT_EQ(startpos.moves[9].movestring,   "e7e6");
    EXPECT_EQ(startpos.moves[10].movestring,  "f7f5");
    EXPECT_EQ(startpos.moves[11].movestring,  "f7f6");
    EXPECT_EQ(startpos.moves[12].movestring,  "g7g5");
    EXPECT_EQ(startpos.moves[13].movestring,  "g7g6");
    EXPECT_EQ(startpos.moves[14].movestring,  "h7h5");
    EXPECT_EQ(startpos.moves[15].movestring,  "h7h6");
}

TEST(correct_moves_generated, tripple_pawn_standoff_black) {
    std::string test = "rnbqkbnr/pp3ppp/8/2ppp3/2PPP3/8/PP3PPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 14);

    EXPECT_EQ(startpos.moves[0].movestring,   "a7a5");
    EXPECT_EQ(startpos.moves[1].movestring,   "a7a6");
    EXPECT_EQ(startpos.moves[2].movestring,   "b7b5");
    EXPECT_EQ(startpos.moves[3].movestring,   "b7b6");
    EXPECT_EQ(startpos.moves[4].movestring,   "c5d4");
    EXPECT_EQ(startpos.moves[5].movestring,   "d5c4");
    EXPECT_EQ(startpos.moves[6].movestring,   "d5e4");
    EXPECT_EQ(startpos.moves[7].movestring,   "e5d4");
    EXPECT_EQ(startpos.moves[8].movestring,   "f7f5");
    EXPECT_EQ(startpos.moves[9].movestring,   "f7f6");
    EXPECT_EQ(startpos.moves[10].movestring,  "g7g5");
    EXPECT_EQ(startpos.moves[11].movestring,  "g7g6");
    EXPECT_EQ(startpos.moves[12].movestring,  "h7h5");
    EXPECT_EQ(startpos.moves[13].movestring,  "h7h6");
}

TEST(correct_moves_generated, blocked_black_pawn) {
    std::string test = "rnbqkbnr/pppppppp/P7/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 15);

    EXPECT_EQ(startpos.moves[0].movestring,   "b7a6");
    EXPECT_EQ(startpos.moves[1].movestring,   "b7b5");
    EXPECT_EQ(startpos.moves[2].movestring,   "b7b6");
    EXPECT_EQ(startpos.moves[3].movestring,   "c7c5");
    EXPECT_EQ(startpos.moves[4].movestring,   "c7c6");
    EXPECT_EQ(startpos.moves[5].movestring,   "d7d5");
    EXPECT_EQ(startpos.moves[6].movestring,   "d7d6");
    EXPECT_EQ(startpos.moves[7].movestring,   "e7e5");
    EXPECT_EQ(startpos.moves[8].movestring,   "e7e6");
    EXPECT_EQ(startpos.moves[9].movestring,   "f7f5");
    EXPECT_EQ(startpos.moves[10].movestring,  "f7f6");
    EXPECT_EQ(startpos.moves[11].movestring,  "g7g5");
    EXPECT_EQ(startpos.moves[12].movestring,  "g7g6");
    EXPECT_EQ(startpos.moves[13].movestring,  "h7h5");
    EXPECT_EQ(startpos.moves[14].movestring,  "h7h6");
}


TEST(capture_passant, black) {
    std::string test = "rnbqkbnr/pp1ppppp/8/8/2pP4/8/PP2PPPP/RNBQKBNR b KQkq d3 0 1";
    Position startpos(test);

    generate_b_pawn_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 16);

    EXPECT_EQ(startpos.moves[0].movestring,   "a7a5");
    EXPECT_EQ(startpos.moves[1].movestring,   "a7a6");
    EXPECT_EQ(startpos.moves[2].movestring,   "b7b5");
    EXPECT_EQ(startpos.moves[3].movestring,   "b7b6");
    EXPECT_EQ(startpos.moves[4].movestring,   "c4c3");
    EXPECT_EQ(startpos.moves[5].movestring,   "c4d3");
    EXPECT_EQ(startpos.moves[6].movestring,   "d7d5");
    EXPECT_EQ(startpos.moves[7].movestring,   "d7d6");
    EXPECT_EQ(startpos.moves[8].movestring,   "e7e5");
    EXPECT_EQ(startpos.moves[9].movestring,   "e7e6");
    EXPECT_EQ(startpos.moves[10].movestring,  "f7f5");
    EXPECT_EQ(startpos.moves[11].movestring,  "f7f6");
    EXPECT_EQ(startpos.moves[12].movestring,  "g7g5");
    EXPECT_EQ(startpos.moves[13].movestring,  "g7g6");
    EXPECT_EQ(startpos.moves[14].movestring,  "h7h5");
    EXPECT_EQ(startpos.moves[15].movestring,  "h7h6");

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
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(startpos.moves[0].movestring,   "b1a3");
    EXPECT_EQ(startpos.moves[1].movestring,   "b1c3");
    EXPECT_EQ(startpos.moves[2].movestring,   "g1f3");
    EXPECT_EQ(startpos.moves[3].movestring,   "g1h3");
}

TEST(correct_moves_generated, e5_white_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/4N3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_w_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 12);

    EXPECT_EQ(startpos.moves[0].movestring,   "b1a3");
    EXPECT_EQ(startpos.moves[1].movestring,   "b1c3");

    EXPECT_EQ(startpos.moves[2].movestring,   "e5c4");
    EXPECT_EQ(startpos.moves[3].movestring,   "e5c6");
    EXPECT_EQ(startpos.moves[4].movestring,   "e5d3");
    EXPECT_EQ(startpos.moves[5].movestring,   "e5d7");
    EXPECT_EQ(startpos.moves[6].movestring,   "e5f3");
    EXPECT_EQ(startpos.moves[7].movestring,   "e5f7");
    EXPECT_EQ(startpos.moves[8].movestring,   "e5g4");
    EXPECT_EQ(startpos.moves[9].movestring,   "e5g6");

    EXPECT_EQ(startpos.moves[10].movestring,   "g1f3");
    EXPECT_EQ(startpos.moves[11].movestring,   "g1h3");
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
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(startpos.moves[0].movestring,   "b8a6");
    EXPECT_EQ(startpos.moves[1].movestring,   "b8c6");
    EXPECT_EQ(startpos.moves[2].movestring,   "g8f6");
    EXPECT_EQ(startpos.moves[3].movestring,   "g8h6");
}

TEST(correct_moves_generated, e4_black_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/4n3/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_knight_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 12);

    EXPECT_EQ(startpos.moves[0].movestring,   "b8a6");
    EXPECT_EQ(startpos.moves[1].movestring,   "b8c6");

    EXPECT_EQ(startpos.moves[2].movestring,   "e4c3");
    EXPECT_EQ(startpos.moves[3].movestring,   "e4c5");
    EXPECT_EQ(startpos.moves[4].movestring,   "e4d2");
    EXPECT_EQ(startpos.moves[5].movestring,   "e4d6");
    EXPECT_EQ(startpos.moves[6].movestring,   "e4f2");
    EXPECT_EQ(startpos.moves[7].movestring,   "e4f6");
    EXPECT_EQ(startpos.moves[8].movestring,   "e4g3");
    EXPECT_EQ(startpos.moves[9].movestring,   "e4g5");

    EXPECT_EQ(startpos.moves[10].movestring,   "g8f6");
    EXPECT_EQ(startpos.moves[11].movestring,   "g8h6");
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
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(startpos.moves[0].movestring,   "e5c3");
    EXPECT_EQ(startpos.moves[1].movestring,   "e5c7");
    EXPECT_EQ(startpos.moves[2].movestring,   "e5d4");
    EXPECT_EQ(startpos.moves[3].movestring,   "e5d6");
    EXPECT_EQ(startpos.moves[4].movestring,   "e5f4");
    EXPECT_EQ(startpos.moves[5].movestring,   "e5f6");
    EXPECT_EQ(startpos.moves[6].movestring,   "e5g3");
    EXPECT_EQ(startpos.moves[7].movestring,   "e5g7");
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
    std::string test = "rnbqkbnr/pppppppp/8/4b3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_bishop_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 8);
}

TEST(correct_moves_generated, e5_black_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/4b3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_bishop_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(startpos.moves[0].movestring,   "e5b2");
    EXPECT_EQ(startpos.moves[1].movestring,   "e5c3");
    EXPECT_EQ(startpos.moves[2].movestring,   "e5d4");
    EXPECT_EQ(startpos.moves[3].movestring,   "e5d6");
    EXPECT_EQ(startpos.moves[4].movestring,   "e5f4");
    EXPECT_EQ(startpos.moves[5].movestring,   "e5f6");
    EXPECT_EQ(startpos.moves[6].movestring,   "e5g3");
    EXPECT_EQ(startpos.moves[7].movestring,   "e5h2");
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
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 11);

    EXPECT_EQ(startpos.moves[0].movestring,    "e5a5");
    EXPECT_EQ(startpos.moves[1].movestring,    "e5b5");
    EXPECT_EQ(startpos.moves[2].movestring,    "e5c5");
    EXPECT_EQ(startpos.moves[3].movestring,    "e5d5");
    EXPECT_EQ(startpos.moves[4].movestring,    "e5e3");
    EXPECT_EQ(startpos.moves[5].movestring,    "e5e4");
    EXPECT_EQ(startpos.moves[6].movestring,    "e5e6");
    EXPECT_EQ(startpos.moves[7].movestring,    "e5e7");
    EXPECT_EQ(startpos.moves[8].movestring,    "e5f5");
    EXPECT_EQ(startpos.moves[9].movestring,    "e5g5");
    EXPECT_EQ(startpos.moves[10].movestring,   "e5h5");
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
    std::string test = "rnbqkbnr/pppppppp/8/4r3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_rook_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 11);
}

TEST(correct_moves_generated, e5_black_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/4r3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_rook_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 11);

    EXPECT_EQ(startpos.moves[0].movestring,    "e5a5");
    EXPECT_EQ(startpos.moves[1].movestring,    "e5b5");
    EXPECT_EQ(startpos.moves[2].movestring,    "e5c5");
    EXPECT_EQ(startpos.moves[3].movestring,    "e5d5");
    EXPECT_EQ(startpos.moves[4].movestring,    "e5e2");
    EXPECT_EQ(startpos.moves[5].movestring,    "e5e3");
    EXPECT_EQ(startpos.moves[6].movestring,    "e5e4");
    EXPECT_EQ(startpos.moves[7].movestring,    "e5e6");
    EXPECT_EQ(startpos.moves[8].movestring,    "e5f5");
    EXPECT_EQ(startpos.moves[9].movestring,    "e5g5");
    EXPECT_EQ(startpos.moves[10].movestring,   "e5h5");
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
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 19);

    EXPECT_EQ(startpos.moves[0].movestring,     "e5a5");
    EXPECT_EQ(startpos.moves[1].movestring,     "e5b5");
    EXPECT_EQ(startpos.moves[2].movestring,     "e5c3");
    EXPECT_EQ(startpos.moves[3].movestring,     "e5c5");
    EXPECT_EQ(startpos.moves[4].movestring,     "e5c7");
    EXPECT_EQ(startpos.moves[5].movestring,     "e5d4");
    EXPECT_EQ(startpos.moves[6].movestring,     "e5d5");
    EXPECT_EQ(startpos.moves[7].movestring,     "e5d6");
    EXPECT_EQ(startpos.moves[8].movestring,     "e5e3");
    EXPECT_EQ(startpos.moves[9].movestring,     "e5e4");
    EXPECT_EQ(startpos.moves[10].movestring,    "e5e6");
    EXPECT_EQ(startpos.moves[11].movestring,    "e5e7");
    EXPECT_EQ(startpos.moves[12].movestring,    "e5f4");
    EXPECT_EQ(startpos.moves[13].movestring,    "e5f5");
    EXPECT_EQ(startpos.moves[14].movestring,    "e5f6");
    EXPECT_EQ(startpos.moves[15].movestring,    "e5g3");
    EXPECT_EQ(startpos.moves[16].movestring,    "e5g5");
    EXPECT_EQ(startpos.moves[17].movestring,    "e5g7");
    EXPECT_EQ(startpos.moves[18].movestring,    "e5h5");
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
    std::string test = "rnbqkbnr/pppppppp/8/4q3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_queen_moves(&startpos);

    EXPECT_EQ (startpos.moves.size(), 19);
}

TEST(correct_moves_generated, e5_black_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/4q3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_queen_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 19);

    EXPECT_EQ(startpos.moves[0].movestring,     "e5a5");
    EXPECT_EQ(startpos.moves[1].movestring,     "e5b2");
    EXPECT_EQ(startpos.moves[2].movestring,     "e5b5");
    EXPECT_EQ(startpos.moves[3].movestring,     "e5c3");
    EXPECT_EQ(startpos.moves[4].movestring,     "e5c5");
    EXPECT_EQ(startpos.moves[5].movestring,     "e5d4");
    EXPECT_EQ(startpos.moves[6].movestring,     "e5d5");
    EXPECT_EQ(startpos.moves[7].movestring,     "e5d6");
    EXPECT_EQ(startpos.moves[8].movestring,     "e5e2");
    EXPECT_EQ(startpos.moves[9].movestring,     "e5e3");
    EXPECT_EQ(startpos.moves[10].movestring,    "e5e4");
    EXPECT_EQ(startpos.moves[11].movestring,    "e5e6");
    EXPECT_EQ(startpos.moves[12].movestring,    "e5f4");
    EXPECT_EQ(startpos.moves[13].movestring,    "e5f5");
    EXPECT_EQ(startpos.moves[14].movestring,    "e5f6");
    EXPECT_EQ(startpos.moves[15].movestring,    "e5g3");
    EXPECT_EQ(startpos.moves[16].movestring,    "e5g5");
    EXPECT_EQ(startpos.moves[17].movestring,    "e5h2");
    EXPECT_EQ(startpos.moves[18].movestring,    "e5h5");
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
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(startpos.moves[0].movestring,   "e5d4");
    EXPECT_EQ(startpos.moves[1].movestring,   "e5d5");
    EXPECT_EQ(startpos.moves[2].movestring,   "e5d6");
    EXPECT_EQ(startpos.moves[3].movestring,   "e5e4");
    EXPECT_EQ(startpos.moves[4].movestring,   "e5e6");
    EXPECT_EQ(startpos.moves[5].movestring,   "e5f4");
    EXPECT_EQ(startpos.moves[6].movestring,   "e5f5");
    EXPECT_EQ(startpos.moves[7].movestring,   "e5f6");
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
    std::string test = "rnbq1bnr/pppppppp/8/4k3/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    generate_b_king_moves(&startpos);
    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [](Position const &a, Position const &b) { return a.movestring < b.movestring; });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(startpos.moves[0].movestring,   "e5d4");
    EXPECT_EQ(startpos.moves[1].movestring,   "e5d5");
    EXPECT_EQ(startpos.moves[2].movestring,   "e5d6");
    EXPECT_EQ(startpos.moves[3].movestring,   "e5e4");
    EXPECT_EQ(startpos.moves[4].movestring,   "e5e6");
    EXPECT_EQ(startpos.moves[5].movestring,   "e5f4");
    EXPECT_EQ(startpos.moves[6].movestring,   "e5f5");
    EXPECT_EQ(startpos.moves[7].movestring,   "e5f6");
}

