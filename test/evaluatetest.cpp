#include "gtest/gtest.h"
#include "../src/evaluate.h"
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
// START GET WHITE MATERIAL TEST ///////////////////////////////////////////////
//

TEST(white_material, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int white_material = get_white_material_value(&pos);
    EXPECT_EQ (white_material, 14250);
}

//
// START GET BLACK MATERIAL TEST ///////////////////////////////////////////////
//

TEST(black_material, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int black_material = get_black_material_value(&pos);
    EXPECT_EQ (black_material, -14250);
}

//
// START EVALUATE POSITION TEST ////////////////////////////////////////////////
//

TEST(position_eval, all) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos(test);

    int position_value = evaluate_position(&pos);
    EXPECT_EQ (position_value, 0);
}


