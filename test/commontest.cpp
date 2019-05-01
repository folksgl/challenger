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
        int bits_set = num_set_bits(numpos->maps[b_pawn]);
        EXPECT_EQ (bits_set, 8); 
    }

    TEST_F(NumBitPosition, start_black_knight) {
        int bits_set = num_set_bits(numpos->maps[b_knight]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_bishop) {
        int bits_set = num_set_bits(numpos->maps[b_bishop]);
        EXPECT_EQ (bits_set, 2); 
    }

    TEST_F(NumBitPosition, start_black_rook) {
        int bits_set = num_set_bits(numpos->maps[b_rook]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_queen) {
        int bits_set = num_set_bits(numpos->maps[b_queen]);
        EXPECT_EQ (bits_set, 1); 
    }

    TEST_F(NumBitPosition, start_black_king) {
        int bits_set = num_set_bits(numpos->maps[b_king]);
        EXPECT_EQ (bits_set, 1);
    }

    TEST_F(NumBitPosition, start_white_pawn) {
        int bits_set = num_set_bits(numpos->maps[w_pawn]);
        EXPECT_EQ (bits_set, 8); 
    }

    TEST_F(NumBitPosition, start_white_knight) {
        int bits_set = num_set_bits(numpos->maps[w_knight]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_bishop) {
        int bits_set = num_set_bits(numpos->maps[w_bishop]);
        EXPECT_EQ (bits_set, 2); 
    }

    TEST_F(NumBitPosition, start_white_rook) {
        int bits_set = num_set_bits(numpos->maps[w_rook]);
        EXPECT_EQ (bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_queen) {
        int bits_set = num_set_bits(numpos->maps[w_queen]);
        EXPECT_EQ (bits_set, 1); 
    }

    TEST_F(NumBitPosition, start_white_king) {
        int bits_set = num_set_bits(numpos->maps[w_king]);
        EXPECT_EQ (bits_set, 1);
    }
}

//
// START FILE TO NUM TEST /////////////////////////////////////////////////
//

TEST(file_to_num, a) {
    int file = file_to_num('a');
    EXPECT_EQ (file, 0);
}

TEST(file_to_num, b) {
    int file = file_to_num('b');
    EXPECT_EQ (file, 1);
}

TEST(file_to_num, c) {
    int file = file_to_num('c');
    EXPECT_EQ (file, 2);
}

TEST(file_to_num, d) {
    int file = file_to_num('d');
    EXPECT_EQ (file, 3);
}

TEST(file_to_num, e) {
    int file = file_to_num('e');
    EXPECT_EQ (file, 4);
}

TEST(file_to_num, f) {
    int file = file_to_num('f');
    EXPECT_EQ (file, 5);
}

TEST(file_to_num, g) {
    int file = file_to_num('g');
    EXPECT_EQ (file, 6);
}

TEST(file_to_num, h) {
    int file = file_to_num('h');
    EXPECT_EQ (file, 7);
}

//
// START GET SQUARE NUM TEST //////////////////////////////////////////////
//

TEST(get_sq_num, a1) {
    int square = get_square_num("a1");
    EXPECT_EQ (square, 0);
}

TEST(get_sq_num, b2) {
    int square = get_square_num("b2");
    EXPECT_EQ (square, 9);
}

TEST(get_sq_num, c3) {
    int square = get_square_num("c3");
    EXPECT_EQ (square, 18);
}

TEST(get_sq_num, d4) {
    int square = get_square_num("d4");
    EXPECT_EQ (square, 27);
}

TEST(get_sq_num, e5) {
    int square = get_square_num("e5");
    EXPECT_EQ (square, 36);
}

TEST(get_sq_num, f6) {
    int square = get_square_num("f6");
    EXPECT_EQ (square, 45);
}

TEST(get_sq_num, g7) {
    int square = get_square_num("g7");
    EXPECT_EQ (square, 54);
}

TEST(get_sq_num, h8) {
    int square = get_square_num("h8");
    EXPECT_EQ (square, 63);
}

