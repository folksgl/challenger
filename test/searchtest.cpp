#include "gtest/gtest.h"
#include "../src/search.hpp"
#include "../src/genmove.hpp"

using namespace std;

//
// Ensure that alphaBetaMax of a position results in a move list sorted in decending order by evaluation score.
//
TEST (search, white_result_is_descending) { 
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    search(&startpos, 2);

    int prev = -999999999;

    for (auto p : startpos.moves) {
        ASSERT_GE(p.eval_score, prev);
        prev = p.eval_score;
    }
    ASSERT_EQ(startpos.moves.size(), 20);
    ASSERT_NE(startpos.moves.begin()->eval_score, startpos.moves.end()->eval_score);
}

TEST (search, black_result_is_descending) { 
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position startpos(test);

    search(&startpos, 2);

    int prev = -999999999;

    for (auto p : startpos.moves) {
        ASSERT_GE(p.eval_score, prev);
        prev = p.eval_score;
    }
    ASSERT_EQ(startpos.moves.size(), 20);
    ASSERT_NE(startpos.moves.begin()->eval_score, startpos.moves.end()->eval_score);
}

//
// Ensure that alphaBetaMax of a position results in a move list sorted in decending order by evaluation score.
//
TEST (alpha_max, result_is_descending) { 
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    alphaBetaMax(&startpos, 0, 0, 2);

    int prev = -999999999;

    for (auto p : startpos.moves) {
        ASSERT_GE(p.eval_score, prev);
        prev = p.eval_score;
    }
    ASSERT_EQ(startpos.moves.size(), 20);
    ASSERT_NE(startpos.moves.begin()->eval_score, startpos.moves.end()->eval_score);
}

//
// Ensure that alphaBetaMin of a position results in a move list sorted in ascending order by evaluation score.
//
TEST (alpha_min, result_is_ascending) { 
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);

    alphaBetaMax(&startpos, 0, 0, 2);

    int prev = 999999999;

    for (auto p : startpos.moves) {
        ASSERT_LE(p.eval_score, prev);
        prev = p.eval_score;
    }

    ASSERT_EQ(startpos.moves.size(), 20);
    ASSERT_NE(startpos.moves.begin()->eval_score, startpos.moves.end()->eval_score);
}

