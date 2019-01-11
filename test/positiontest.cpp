#include "gtest/gtest.h"
#include "../src/position.h"
#include <string>

using namespace std;

TEST(setup_fen_test, black_pawn) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_PAWN;
    bitmap expect = 0x00FF000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_pawn) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_PAWN;
    bitmap expect = 0x000000000000FF00;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_minor_major_start) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_PIECES;
    bitmap expect = 0x000000000000FFFF;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, black_minor_major_start) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_PIECES;
    bitmap expect = 0xFFFF000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, board_start) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_PIECES | actualpos.WHITE_PIECES;
    bitmap expect = 0xFFFF00000000FFFF;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, black_rook) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_ROOK;
    bitmap expect = 0x8100000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, black_knight) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_KNIGHT;
    bitmap expect = 0x4200000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, black_bishop) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_BISHOP;
    bitmap expect = 0x2400000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, black_queen) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_QUEEN;
    bitmap expect = 0x1000000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, black_king) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.BLACK_KING;
    bitmap expect = 0x0800000000000000;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_rook) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_ROOK;
    bitmap expect = 0x0000000000000081;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_knight) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_KNIGHT;
    bitmap expect = 0x0000000000000042;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_bishop) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_BISHOP;
    bitmap expect = 0x0000000000000024;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_queen) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_QUEEN;
    bitmap expect = 0x0000000000000010;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

TEST(setup_fen_test, white_king) { 

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    bitmap actual = actualpos.WHITE_KING;
    bitmap expect = 0x0000000000000008;

    EXPECT_EQ ((bitmap)actual, (bitmap)expect);
}

