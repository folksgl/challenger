#include "gtest/gtest.h"
#include "../src/evaluate.h"
#include "../src/common.h"
#include <string>

namespace {
    // Set up a reusable start position to share across tests to improve test speed.
    // The startpos object is NOT TO BE MODIFIED DURING TESTING.
    
    class NumBitPosition : public testing::Test {
        protected:
            static void SetUpTestSuite() {
                std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
                numpos = new Position(test);
            }
            static void TearDownTestSuite() {
                delete numpos;
                numpos = NULL;
            }
            static Position* numpos;
    };

    Position* NumBitPosition::numpos = NULL;

    //
    // START NUM SET BITS TEST /////////////////////////////////////////////////////
    //

    TEST_F(NumBitPosition, start_black_pawn) {
        int bits_set = __builtin_popcountll(numpos->maps[b_pawn]);
        EXPECT_EQ (bits_set, 8); 
    }

    TEST_F(NumBitPosition, start_black_knight) {
        int bits_set = __builtin_popcountll(numpos->maps[b_knight]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_bishop) {
        int bits_set = __builtin_popcountll(numpos->maps[b_bishop]);
        EXPECT_EQ (bits_set, 2); 
    }

    TEST_F(NumBitPosition, start_black_rook) {
        int bits_set = __builtin_popcountll(numpos->maps[b_rook]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_queen) {
        int bits_set = __builtin_popcountll(numpos->maps[b_queen]);
        EXPECT_EQ (bits_set, 1); 
    }

    TEST_F(NumBitPosition, start_black_king) {
        int bits_set = __builtin_popcountll(numpos->maps[b_king]);
        EXPECT_EQ (bits_set, 1);
    }

    TEST_F(NumBitPosition, start_white_pawn) {
        int bits_set = __builtin_popcountll(numpos->maps[w_pawn]);
        EXPECT_EQ (bits_set, 8); 
    }

    TEST_F(NumBitPosition, start_white_knight) {
        int bits_set = __builtin_popcountll(numpos->maps[w_knight]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_bishop) {
        int bits_set = __builtin_popcountll(numpos->maps[w_bishop]);
        EXPECT_EQ (bits_set, 2); 
    }

    TEST_F(NumBitPosition, start_white_rook) {
        int bits_set = __builtin_popcountll(numpos->maps[w_rook]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_queen) {
        int bits_set = __builtin_popcountll(numpos->maps[w_queen]);
        EXPECT_EQ (bits_set, 1); 
    }

    TEST_F(NumBitPosition, start_white_king) {
        int bits_set = __builtin_popcountll(numpos->maps[w_king]);
        EXPECT_EQ (bits_set, 1);
    }
}

//
// START GET SQUARE NUM TEST //////////////////////////////////////////////
//

TEST(get_sq_num, a1) {
    int square = get_square_num("a1");
    EXPECT_EQ (square, 0);
}

TEST(get_sq_num, a2) {
    int square = get_square_num("a2");
    EXPECT_EQ (square, 8);
}

TEST(get_sq_num, a3) {
    int square = get_square_num("a3");
    EXPECT_EQ (square, 16);
}

TEST(get_sq_num, b2) {
    int square = get_square_num("b2");
    EXPECT_EQ (square, 9);
}

TEST(get_sq_num, b3) {
    int square = get_square_num("b3");
    EXPECT_EQ (square, 17);
}

TEST(get_sq_num, b4) {
    int square = get_square_num("b4");
    EXPECT_EQ (square, 25);
}

TEST(get_sq_num, c3) {
    int square = get_square_num("c3");
    EXPECT_EQ (square, 18);
}

TEST(get_sq_num, c4) {
    int square = get_square_num("c3");
    EXPECT_EQ (square, 18);
}

TEST(get_sq_num, c5) {
    int square = get_square_num("c3");
    EXPECT_EQ (square, 18);
}

TEST(get_sq_num, d4) {
    int square = get_square_num("d4");
    EXPECT_EQ (square, 27);
}

TEST(get_sq_num, d5) {
    int square = get_square_num("d5");
    EXPECT_EQ (square, 35);
}

TEST(get_sq_num, d6) {
    int square = get_square_num("d6");
    EXPECT_EQ (square, 43);
}

TEST(get_sq_num, e5) {
    int square = get_square_num("e5");
    EXPECT_EQ (square, 36);
}

TEST(get_sq_num, e6) {
    int square = get_square_num("e6");
    EXPECT_EQ (square, 44);
}

TEST(get_sq_num, e7) {
    int square = get_square_num("e7");
    EXPECT_EQ (square, 52);
}

TEST(get_sq_num, f6) {
    int square = get_square_num("f6");
    EXPECT_EQ (square, 45);
}

TEST(get_sq_num, f7) {
    int square = get_square_num("f7");
    EXPECT_EQ (square, 53);
}

TEST(get_sq_num, f8) {
    int square = get_square_num("f8");
    EXPECT_EQ (square, 61);
}

TEST(get_sq_num, g7) {
    int square = get_square_num("g7");
    EXPECT_EQ (square, 54);
}

TEST(get_sq_num, g8) {
    int square = get_square_num("g8");
    EXPECT_EQ (square, 62);
}

TEST(get_sq_num, g1) {
    int square = get_square_num("g1");
    EXPECT_EQ (square, 6);
}

TEST(get_sq_num, h8) {
    int square = get_square_num("h8");
    EXPECT_EQ (square, 63);
}

TEST(get_sq_num, h1) {
    int square = get_square_num("h1");
    EXPECT_EQ (square, 7);
}

TEST(get_sq_num, h2) {
    int square = get_square_num("h2");
    EXPECT_EQ (square, 15);
}

