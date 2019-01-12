#include "gtest/gtest.h"
#include "../src/position.h"
#include <string>

using namespace std;

TEST(setup_fen_test, starting_position) { 

    // rnbqkbnr
    // pppppppp
    // --------
    // --------
    // --------
    // --------
    // PPPPPPPP
    // RNBQKBNR

    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);

    EXPECT_EQ (actualpos.BLACK_PAWN,   0x00FF000000000000); // BLACK_PAWN
    EXPECT_EQ (actualpos.BLACK_ROOK,   0x8100000000000000); // BLACK_ROOK
    EXPECT_EQ (actualpos.BLACK_KNIGHT, 0x4200000000000000); // BLACK_KNIGHT
    EXPECT_EQ (actualpos.BLACK_BISHOP, 0x2400000000000000); // BLACK_BISHOP
    EXPECT_EQ (actualpos.BLACK_QUEEN,  0x1000000000000000); // BLACK_QUEEN
    EXPECT_EQ (actualpos.BLACK_KING,   0x0800000000000000); // BLACK_KING
    EXPECT_EQ (actualpos.BLACK_PIECES, 0xFFFF000000000000); // BLACK_PIECES

    EXPECT_EQ (actualpos.WHITE_PAWN,   0x000000000000FF00); // WHITE_PAWN
    EXPECT_EQ (actualpos.WHITE_ROOK,   0x0000000000000081); // WHITE_ROOK
    EXPECT_EQ (actualpos.WHITE_KNIGHT, 0x0000000000000042); // WHITE_KNIGHT
    EXPECT_EQ (actualpos.WHITE_BISHOP, 0x0000000000000024); // WHITE_BISHOP
    EXPECT_EQ (actualpos.WHITE_QUEEN,  0x0000000000000010); // WHITE_QUEEN
    EXPECT_EQ (actualpos.WHITE_KING,   0x0000000000000008); // WHITE_KING
    EXPECT_EQ (actualpos.WHITE_PIECES, 0x000000000000FFFF); // WHITE_PIECES

    bitmap board = actualpos.WHITE_PIECES | actualpos.BLACK_PIECES;
    EXPECT_EQ (board, 0xFFFF00000000FFFF); // WHITE_PIECES

}

TEST(setup_fen_test, complex_position) { 

    // -kb---r-
    // prp-bppp
    // -p-p-R-P
    // -Kk-p-Bq
    // ---PkQ--
    // --P-PKP-
    // PPB--P--
    // --KR----

    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);

    EXPECT_EQ (actualpos.BLACK_PAWN,   0xE50A100000000000); // BLACK_PAWN
    EXPECT_EQ (actualpos.BLACK_ROOK,   0x4002000000000000); // BLACK_ROOK
    EXPECT_EQ (actualpos.BLACK_KNIGHT, 0x0000000410000000); // BLACK_KNIGHT
    //EXPECT_EQ (actualpos.BLACK_BISHOP, 0x0); // BLACK_BISHOP
    //EXPECT_EQ (actualpos.BLACK_QUEEN,  0x0); // BLACK_QUEEN
    //EXPECT_EQ (actualpos.BLACK_KING,   0x0); // BLACK_KING
    //EXPECT_EQ (actualpos.BLACK_PIECES, 0x0); // BLACK_PIECES

    //EXPECT_EQ (actualpos.WHITE_PAWN,   0x0); // WHITE_PAWN
    //EXPECT_EQ (actualpos.WHITE_ROOK,   0x0); // WHITE_ROOK
    //EXPECT_EQ (actualpos.WHITE_KNIGHT, 0x0); // WHITE_KNIGHT
    //EXPECT_EQ (actualpos.WHITE_BISHOP, 0x0); // WHITE_BISHOP
    //EXPECT_EQ (actualpos.WHITE_QUEEN,  0x0); // WHITE_QUEEN
    //EXPECT_EQ (actualpos.WHITE_KING,   0x0); // WHITE_KING
    //EXPECT_EQ (actualpos.WHITE_PIECES, 0x0); // WHITE_PIECES

    bitmap board = actualpos.WHITE_PIECES | actualpos.BLACK_PIECES;
    EXPECT_EQ (board, 0x46F7AAD63874270C); // WHITE_PIECES

}

