#include "gtest/gtest.h"
#include "../src/position.h"
#include <string>

using namespace std;

namespace {
    // Set up a reusable start position to share across tests to improve test speed.
    // The startpos object is NOT TO BE MODIFIED DURING TESTING.
    
    class StartPosition : public testing::Test {
        protected:
            static void SetUpTestSuite() {
                std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
                startpos = new Position(test);
            }
            static void TearDownTestSuite() {
                delete startpos;
                startpos = NULL;
            }
            static Position* startpos;
    };

    Position* StartPosition::startpos = NULL;

    //
    // START STARTPOS POSITION TESTS ///////////////////////////////////////////////
    //

    TEST_F(StartPosition, black_pawn) {
        EXPECT_EQ (startpos->maps[b_pawn],   0x00FF000000000000); // b_pawn]
    }

    TEST_F(StartPosition, black_rook) {
        EXPECT_EQ (startpos->maps[b_rook],   0x8100000000000000); // b_rook]
    }

    TEST_F(StartPosition, black_knight) {
        EXPECT_EQ (startpos->maps[b_knight], 0x4200000000000000); // b_knight]
    }

    TEST_F(StartPosition, black_bishop) {
        EXPECT_EQ (startpos->maps[b_bishop], 0x2400000000000000); // b_bishop]
    }

    TEST_F(StartPosition, black_queen) {
        EXPECT_EQ (startpos->maps[b_queen],  0x0800000000000000); // b_queen]
    }

    TEST_F(StartPosition, black_king) {
        EXPECT_EQ (startpos->maps[b_king],   0x1000000000000000); // b_king]
    }

    TEST_F(StartPosition, black_pieces) {
        EXPECT_EQ (startpos->maps[b_pieces], 0xFFFF000000000000); // b_pieces]
    }

    TEST_F(StartPosition, white_pawn) {
        EXPECT_EQ (startpos->maps[w_pawn],   0x000000000000FF00); // w_pawn]
    }

    TEST_F(StartPosition, white_rook) {
        EXPECT_EQ (startpos->maps[w_rook],   0x0000000000000081); // w_rook]
    }

    TEST_F(StartPosition, white_knight) {
        EXPECT_EQ (startpos->maps[w_knight], 0x0000000000000042); // w_knight]
    }

    TEST_F(StartPosition, white_bishop) {
        EXPECT_EQ (startpos->maps[w_bishop], 0x0000000000000024); // w_bishop]
    }

    TEST_F(StartPosition, white_queen) {
        EXPECT_EQ (startpos->maps[w_queen],  0x0000000000000008); // w_queen]
    }

    TEST_F(StartPosition, white_king) {
        EXPECT_EQ (startpos->maps[w_king],   0x0000000000000010); // w_king]
    }

    TEST_F(StartPosition, white_pieces) {
        EXPECT_EQ (startpos->maps[w_pieces], 0x000000000000FFFF); // w_pieces]
    }

    TEST_F(StartPosition, whole_board) {
        EXPECT_EQ (startpos->maps[w_pieces] | startpos->maps[b_pieces], 0xFFFF00000000FFFF); // WHOLE_BOARD
    }
}

namespace {
    // Set up a reusable complex position to share across tests to improve test speed.
    // The complexpos object is NOT TO BE MODIFIED DURING TESTING.
    
    class ComplexPosition : public testing::Test {
        protected:
            static void SetUpTestSuite() {
                std::string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
                complexpos = new Position(test);
            }
            static void TearDownTestSuite() {
                delete complexpos;
                complexpos = NULL;
            }
            static Position* complexpos;
    };

    Position* ComplexPosition::complexpos = NULL;

    //
    // START COMPLEX POSITION TESTS ////////////////////////////////////////////////
    //

    TEST_F(ComplexPosition, black_pawn) {
        EXPECT_EQ (complexpos->maps[b_pawn],   0x00E50A1000000000); // b_pawn]
    }

    TEST_F(ComplexPosition, black_rook) {
        EXPECT_EQ (complexpos->maps[b_rook],   0x4002000000000000); // b_rook]
    }

    TEST_F(ComplexPosition, black_knight) {
        EXPECT_EQ (complexpos->maps[b_knight], 0x0000000410000000); // b_knight]
    }

    TEST_F(ComplexPosition, black_bishop) {
        EXPECT_EQ (complexpos->maps[b_bishop], 0x0410000000000000); // b_bishop]
    }

    TEST_F(ComplexPosition, black_queen) {
        EXPECT_EQ (complexpos->maps[b_queen],  0x0000008000000000); // b_queen]
    }

    TEST_F(ComplexPosition, black_king) {
        EXPECT_EQ (complexpos->maps[b_king],   0x0200000000000000); // b_king]
    }

    TEST_F(ComplexPosition, black_pieces) {
        EXPECT_EQ (complexpos->maps[b_pieces], 0x46F70A9410000000); // b_pieces]
    }

    TEST_F(ComplexPosition, white_pawn) {
        EXPECT_EQ (complexpos->maps[w_pawn],   0x0000800008542300); // w_pawn]
    }

    TEST_F(ComplexPosition, white_rook) {
        EXPECT_EQ (complexpos->maps[w_rook],   0x0000200000000008); // w_rook]
    }

    TEST_F(ComplexPosition, white_knight) {
        EXPECT_EQ (complexpos->maps[w_knight], 0x0000000200200000); // w_knight]
    }

    TEST_F(ComplexPosition, white_bishop) {
        EXPECT_EQ (complexpos->maps[w_bishop], 0x0000004000000400); // w_bishop]
    }

    TEST_F(ComplexPosition, white_queen) {
        EXPECT_EQ (complexpos->maps[w_queen],  0x0000000020000000); // w_queen]
    }

    TEST_F(ComplexPosition, white_king) {
        EXPECT_EQ (complexpos->maps[w_king],   0x0000000000000004); // w_king]
    }

    TEST_F(ComplexPosition, white_pieces) {
        EXPECT_EQ (complexpos->maps[w_pieces], 0x0000A0422874270C); // w_pieces]
    }

    TEST_F(ComplexPosition, whole_board) {
        EXPECT_EQ (complexpos->maps[w_pieces] | complexpos->maps[b_pieces], 0x46F7AAD63874270C); // WHOLE_BOARD
    }
}



namespace {
    // Set up a reusable empty position to share across tests to improve test speed.
    // The emptypos object is NOT TO BE MODIFIED DURING TESTING.
     
    class EmptyPosition : public testing::Test {
        protected:
            static void SetUpTestSuite() {
                string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
                emptypos = new Position(test);
            }
            static void TearDownTestSuite() {
                delete emptypos;
                emptypos = NULL;
            }
            static Position* emptypos;
    };

    Position* EmptyPosition::emptypos = NULL;

    //
    // START EMPTY POSITION TESTS //////////////////////////////////////////////////
    //

    TEST_F(EmptyPosition, black_pawn) {
        EXPECT_EQ (emptypos->maps[b_pawn],   0); // b_pawn]
    }

    TEST_F(EmptyPosition, black_rook) {
        EXPECT_EQ (emptypos->maps[b_rook],   0); // b_rook]
    }

    TEST_F(EmptyPosition, black_knight) {
        EXPECT_EQ (emptypos->maps[b_knight], 0); // b_knight]
    }

    TEST_F(EmptyPosition, black_bishop) {
        EXPECT_EQ (emptypos->maps[b_bishop], 0); // b_bishop]
    }

    TEST_F(EmptyPosition, black_queen) {
        EXPECT_EQ (emptypos->maps[b_queen],  0); // b_queen]
    }

    TEST_F(EmptyPosition, black_king) {
        EXPECT_EQ (emptypos->maps[b_king],   0); // b_king]
    }

    TEST_F(EmptyPosition, black_pieces) {
        EXPECT_EQ (emptypos->maps[b_pieces], 0); // b_pieces]
    }

    TEST_F(EmptyPosition, white_pawn) {
        EXPECT_EQ (emptypos->maps[w_pawn],   0); // w_pawn]
    }

    TEST_F(EmptyPosition, white_rook) {
        EXPECT_EQ (emptypos->maps[w_rook],   0); // w_rook]
    }

    TEST_F(EmptyPosition, white_knight) {
        EXPECT_EQ (emptypos->maps[w_knight], 0); // w_knight]
    }

    TEST_F(EmptyPosition, white_bishop) {
        EXPECT_EQ (emptypos->maps[w_bishop], 0); // w_bishop]
    }

    TEST_F(EmptyPosition, white_queen) {
        EXPECT_EQ (emptypos->maps[w_queen],  0); // w_queen]
    }

    TEST_F(EmptyPosition, white_king) {
        EXPECT_EQ (emptypos->maps[w_king],   0); // w_king]
    }

    TEST_F(EmptyPosition, white_pieces) {
        EXPECT_EQ (emptypos->maps[w_pieces], 0); // w_pieces]
    }

    TEST_F(EmptyPosition, whole_board) {
        EXPECT_EQ ((emptypos->maps[w_pieces] | emptypos->maps[b_pieces]), 0); // WHOLE_BOARD
    }
}

//
// START POSITION STRUCT INITIALIZATION TEST ///////////////////////////////////
//

TEST(position_initialization, correct_defaults_black_pawn) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_pawn],   0);
}

TEST(position_initialization, correct_defaults_black_rook) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_rook],   0);
}

TEST(position_initialization, correct_defaults_black_knight) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_knight], 0);
}

TEST(position_initialization, correct_defaults_black_bishop) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_bishop], 0);
}

TEST(position_initialization, correct_defaults_black_queen) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_queen],  0);
}

TEST(position_initialization, correct_defaults_black_king) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_king],   0);
}

TEST(position_initialization, correct_defaults_black_pieces) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[b_pieces], 0);
}

TEST(position_initialization, correct_defaults_white_pawn) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_pawn],   0);
}

TEST(position_initialization, correct_defaults_white_rook) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_rook],   0); 
}

TEST(position_initialization, correct_defaults_white_knight) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_knight], 0);
}

TEST(position_initialization, correct_defaults_white_bishop) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_bishop], 0);
}

TEST(position_initialization, correct_defaults_white_queen) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_queen],  0);
}

TEST(position_initialization, correct_defaults_white_king) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_king],   0);
}

TEST(position_initialization, correct_defaults_white_pieces) {
    Position actualpos;
    EXPECT_EQ (actualpos.maps[w_pieces], 0);
}

TEST(position_initialization, correct_defaults_active_color) {
    Position actualpos;
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(position_initialization, correct_defaults_wk_castle) {
    Position actualpos;
    EXPECT_EQ (actualpos.w_kingside_castle, false);
}

TEST(position_initialization, correct_defaults_wq_castle) {
    Position actualpos;
    EXPECT_EQ (actualpos.w_queenside_castle, false);
}

TEST(position_initialization, correct_defaults_bk_castle) {
    Position actualpos;
    EXPECT_EQ (actualpos.b_kingside_castle, false);
}

TEST(position_initialization, correct_defaults_bq_castle) {
    Position actualpos;
    EXPECT_EQ (actualpos.b_queenside_castle, false);
}

TEST(position_initialization, correct_defaults_passant) {
    Position actualpos;
    EXPECT_STREQ (actualpos.passant_target_sq, "-");
}

TEST(position_initialization, correct_defaults_halfmove) {
    Position actualpos;
    EXPECT_EQ (actualpos.halfmove_clock, 0);
}

TEST(position_initialization, correct_defaults_fullmove) {
    Position actualpos;
    EXPECT_EQ (actualpos.fullmove_number, 0);
}

//
// START CASTLING RIGHTS TEST //////////////////////////////////////////////////
//

TEST(castling_rights, all_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.w_kingside_castle);
    EXPECT_TRUE (actualpos.w_queenside_castle);
    EXPECT_TRUE (actualpos.b_kingside_castle);
    EXPECT_TRUE (actualpos.b_queenside_castle);
}

TEST(castling_rights, white_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.w_kingside_castle);
    EXPECT_TRUE (actualpos.w_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
}

TEST(castling_rights, black_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w kq - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.b_kingside_castle);
    EXPECT_TRUE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

TEST(castling_rights, white_kingside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w K - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
}

TEST(castling_rights, black_kingside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w k - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

TEST(castling_rights, white_queenside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Q - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.w_queenside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
}

TEST(castling_rights, black_queenside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w q - 0 1";
    Position actualpos(test);
    EXPECT_TRUE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

TEST(castling_rights, no_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

//
// START ACTIVE COLOR TEST /////////////////////////////////////////////////////
//

TEST(active_color, white_active) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(active_color, black_active) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.active_color, 'b');
}

//
// START EN PASSANT TEST ///////////////////////////////////////////////////////
//

TEST(en_passant, d3) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq d3 0 1";
    Position actualpos(test);
    EXPECT_STREQ (actualpos.passant_target_sq, "d3");
}

TEST(en_passant, a6) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq a6 0 1";
    Position actualpos(test);
    EXPECT_STREQ (actualpos.passant_target_sq, "a6");
}

TEST(en_passant, h4) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq h4 0 1";
    Position actualpos(test);
    EXPECT_STREQ (actualpos.passant_target_sq, "h4");
}

TEST(en_passant, c2) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 1";
    Position actualpos(test);
    EXPECT_STREQ (actualpos.passant_target_sq, "c2");
}

//
// START HALFMOVE CLOCK TEST ///////////////////////////////////////////////////
//

TEST(halfmove_clock, zero) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.halfmove_clock, 0);
}

TEST(halfmove_clock, one) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 1 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.halfmove_clock, 1);
}

TEST(halfmove_clock, seventy_four) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 74 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.halfmove_clock, 74);
}

TEST(halfmove_clock, threehundred_twelve) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 312 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.halfmove_clock, 312);
}

TEST(halfmove_clock, two_thousand_eighty_five) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 2085 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.halfmove_clock, 2085);
}

//
// START FULLMOVE NUMBER TEST //////////////////////////////////////////////////
//

TEST(fullmove_number, zero) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 0";
    Position actualpos(test);
    EXPECT_EQ (actualpos.fullmove_number, 0);
}

TEST(fullmove_number, one) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 1";
    Position actualpos(test);
    EXPECT_EQ (actualpos.fullmove_number, 1);
}

TEST(fullmove_number, seventy_four) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 74";
    Position actualpos(test);
    EXPECT_EQ (actualpos.fullmove_number, 74);
}

TEST(fullmove_number, threehundred_twelve) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 312";
    Position actualpos(test);
    EXPECT_EQ (actualpos.fullmove_number, 312);
}

TEST(fullmove_number, two_thousand_eighty_five) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 2085";
    Position actualpos(test);
    EXPECT_EQ (actualpos.fullmove_number, 2085);
}

//
// START ZERO AT TEST /////////////////////////////////////////////////////
//

TEST(zero_at, square_0) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(0);
    EXPECT_EQ (actualpos.maps[w_rook], 0x80);
}

TEST(zero_at, square_1) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(1);
    EXPECT_EQ (actualpos.maps[w_knight], 0x40);
}

TEST(zero_at, square_3) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(3);
    EXPECT_EQ (actualpos.maps[w_queen], 0);
}

TEST(zero_at, square_7) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(7);
    EXPECT_EQ (actualpos.maps[w_rook], 0x01);
}

TEST(zero_at, square_15) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(15);
    EXPECT_EQ (actualpos.maps[w_pawn], 0x7F00);
}

TEST(zero_at, square_31) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(31);
    EXPECT_EQ (actualpos.maps[w_pieces], 0xFFFF);
}

TEST(zero_at, square_63) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.zero_at(63);
    EXPECT_EQ (actualpos.maps[b_rook], 0x0100000000000000);
}

//
// START GET SQUARE NUM TEST //////////////////////////////////////////////
//

TEST(get_sq_num, a1) {
    Position pos;
    int square = pos.get_square_num("a1");
    EXPECT_EQ (square, 0);
}

TEST(get_sq_num, b2) {
    Position pos;
    int square = pos.get_square_num("b2");
    EXPECT_EQ (square, 9);
}

TEST(get_sq_num, c3) {
    Position pos;
    int square = pos.get_square_num("c3");
    EXPECT_EQ (square, 18);
}

TEST(get_sq_num, d4) {
    Position pos;
    int square = pos.get_square_num("d4");
    EXPECT_EQ (square, 27);
}

TEST(get_sq_num, e5) {
    Position pos;
    int square = pos.get_square_num("e5");
    EXPECT_EQ (square, 36);
}

TEST(get_sq_num, f6) {
    Position pos;
    int square = pos.get_square_num("f6");
    EXPECT_EQ (square, 45);
}

TEST(get_sq_num, g7) {
    Position pos;
    int square = pos.get_square_num("g7");
    EXPECT_EQ (square, 54);
}

TEST(get_sq_num, h8) {
    Position pos;
    int square = pos.get_square_num("h8");
    EXPECT_EQ (square, 63);
}

//
// START FILE TO NUM TEST /////////////////////////////////////////////////
//

TEST(file_to_num, a) {
    Position pos;
    int file = pos.file_to_num('a');
    EXPECT_EQ (file, 0);
}

TEST(file_to_num, b) {
    Position pos;
    int file = pos.file_to_num('b');
    EXPECT_EQ (file, 1);
}

TEST(file_to_num, c) {
    Position pos;
    int file = pos.file_to_num('c');
    EXPECT_EQ (file, 2);
}

TEST(file_to_num, d) {
    Position pos;
    int file = pos.file_to_num('d');
    EXPECT_EQ (file, 3);
}

TEST(file_to_num, e) {
    Position pos;
    int file = pos.file_to_num('e');
    EXPECT_EQ (file, 4);
}

TEST(file_to_num, f) {
    Position pos;
    int file = pos.file_to_num('f');
    EXPECT_EQ (file, 5);
}

TEST(file_to_num, g) {
    Position pos;
    int file = pos.file_to_num('g');
    EXPECT_EQ (file, 6);
}

TEST(file_to_num, h) {
    Position pos;
    int file = pos.file_to_num('h');
    EXPECT_EQ (file, 7);
}

//
// START GAME MOVE TEST ///////////////////////////////////////////////////
//
    //EXPECT_EQ (actualpos.maps[b_pawn],   0x00FF000000000000); // b_pawn
    //EXPECT_EQ (actualpos.maps[b_rook],   0x8100000000000000); // b_rook
    //EXPECT_EQ (actualpos.maps[b_knight], 0x4200000000000000); // b_knight
    //EXPECT_EQ (actualpos.maps[b_bishop], 0x2400000000000000); // b_bishop
    //EXPECT_EQ (actualpos.maps[b_queen],  0x0800000000000000); // b_queen
    //EXPECT_EQ (actualpos.maps[b_king],   0x1000000000000000); // b_king
    //EXPECT_EQ (actualpos.maps[b_pieces], 0xFFFF000000000000); // b_pieces

    //EXPECT_EQ (actualpos.maps[w_pawn],   0x000000000000FF00); // w_pawn
    //EXPECT_EQ (actualpos.maps[w_rook],   0x0000000000000081); // w_rook
    //EXPECT_EQ (actualpos.maps[w_knight], 0x0000000000000042); // w_knight
    //EXPECT_EQ (actualpos.maps[w_bishop], 0x0000000000000024); // w_bishop
    //EXPECT_EQ (actualpos.maps[w_queen],  0x0000000000000008); // w_queen
    //EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000010); // w_king
    //EXPECT_EQ (actualpos.maps[w_pieces], 0x000000000000FFFF); // w_pieces


TEST(game_move, a2a4) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.game_move("a2a4", &actualpos);

    EXPECT_EQ (actualpos.maps[b_pawn],   0x00FF000000000000); // b_pawn
    EXPECT_EQ (actualpos.maps[b_rook],   0x8100000000000000); // b_rook
    EXPECT_EQ (actualpos.maps[b_knight], 0x4200000000000000); // b_knight
    EXPECT_EQ (actualpos.maps[b_bishop], 0x2400000000000000); // b_bishop
    EXPECT_EQ (actualpos.maps[b_queen],  0x0800000000000000); // b_queen
    EXPECT_EQ (actualpos.maps[b_king],   0x1000000000000000); // b_king
    EXPECT_EQ (actualpos.maps[b_pieces], 0xFFFF000000000000); // b_pieces

    EXPECT_EQ (actualpos.maps[w_pawn],   0x000000000100FE00); // w_pawn
    EXPECT_EQ (actualpos.maps[w_rook],   0x0000000000000081); // w_rook
    EXPECT_EQ (actualpos.maps[w_knight], 0x0000000000000042); // w_knight
    EXPECT_EQ (actualpos.maps[w_bishop], 0x0000000000000024); // w_bishop
    EXPECT_EQ (actualpos.maps[w_queen],  0x0000000000000008); // w_queen
    EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000010); // w_king
    EXPECT_EQ (actualpos.maps[w_pieces], 0x000000000100FEFF); // w_pieces
}

TEST(game_move, a2a4_b2b4) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.game_move("a2a4", &actualpos);
    actualpos.game_move("b2b4", &actualpos);

    EXPECT_EQ (actualpos.maps[b_pawn],   0x00FF000000000000); // b_pawn
    EXPECT_EQ (actualpos.maps[b_rook],   0x8100000000000000); // b_rook
    EXPECT_EQ (actualpos.maps[b_knight], 0x4200000000000000); // b_knight
    EXPECT_EQ (actualpos.maps[b_bishop], 0x2400000000000000); // b_bishop
    EXPECT_EQ (actualpos.maps[b_queen],  0x0800000000000000); // b_queen
    EXPECT_EQ (actualpos.maps[b_king],   0x1000000000000000); // b_king
    EXPECT_EQ (actualpos.maps[b_pieces], 0xFFFF000000000000); // b_pieces

    EXPECT_EQ (actualpos.maps[w_pawn],   0x000000000300FC00); // w_pawn
    EXPECT_EQ (actualpos.maps[w_rook],   0x0000000000000081); // w_rook
    EXPECT_EQ (actualpos.maps[w_knight], 0x0000000000000042); // w_knight
    EXPECT_EQ (actualpos.maps[w_bishop], 0x0000000000000024); // w_bishop
    EXPECT_EQ (actualpos.maps[w_queen],  0x0000000000000008); // w_queen
    EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000010); // w_king
    EXPECT_EQ (actualpos.maps[w_pieces], 0x000000000300FCFF); // w_pieces

}

TEST(game_move, a2a7) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.game_move("a2a7", &actualpos);

    EXPECT_EQ (actualpos.maps[b_pawn],   0x00FE000000000000); // b_pawn
    EXPECT_EQ (actualpos.maps[b_rook],   0x8100000000000000); // b_rook
    EXPECT_EQ (actualpos.maps[b_knight], 0x4200000000000000); // b_knight
    EXPECT_EQ (actualpos.maps[b_bishop], 0x2400000000000000); // b_bishop
    EXPECT_EQ (actualpos.maps[b_queen],  0x0800000000000000); // b_queen
    EXPECT_EQ (actualpos.maps[b_king],   0x1000000000000000); // b_king
    EXPECT_EQ (actualpos.maps[b_pieces], 0xFFFE000000000000); // b_pieces

    EXPECT_EQ (actualpos.maps[w_pawn],   0x000100000000FE00); // w_pawn
    EXPECT_EQ (actualpos.maps[w_rook],   0x0000000000000081); // w_rook
    EXPECT_EQ (actualpos.maps[w_knight], 0x0000000000000042); // w_knight
    EXPECT_EQ (actualpos.maps[w_bishop], 0x0000000000000024); // w_bishop
    EXPECT_EQ (actualpos.maps[w_queen],  0x0000000000000008); // w_queen
    EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000010); // w_king
    EXPECT_EQ (actualpos.maps[w_pieces], 0x000100000000FEFF); // w_pieces

}

TEST(game_move, a2a7_a7b7) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.game_move("a2a7", &actualpos);
    actualpos.game_move("a7b7", &actualpos);

    EXPECT_EQ (actualpos.maps[b_pawn],   0x00FC000000000000); // b_pawn
    EXPECT_EQ (actualpos.maps[b_rook],   0x8100000000000000); // b_rook
    EXPECT_EQ (actualpos.maps[b_knight], 0x4200000000000000); // b_knight
    EXPECT_EQ (actualpos.maps[b_bishop], 0x2400000000000000); // b_bishop
    EXPECT_EQ (actualpos.maps[b_queen],  0x0800000000000000); // b_queen
    EXPECT_EQ (actualpos.maps[b_king],   0x1000000000000000); // b_king
    EXPECT_EQ (actualpos.maps[b_pieces], 0xFFFC000000000000); // b_pieces

    EXPECT_EQ (actualpos.maps[w_pawn],   0x000200000000FE00); // w_pawn
    EXPECT_EQ (actualpos.maps[w_rook],   0x0000000000000081); // w_rook
    EXPECT_EQ (actualpos.maps[w_knight], 0x0000000000000042); // w_knight
    EXPECT_EQ (actualpos.maps[w_bishop], 0x0000000000000024); // w_bishop
    EXPECT_EQ (actualpos.maps[w_queen],  0x0000000000000008); // w_queen
    EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000010); // w_king
    EXPECT_EQ (actualpos.maps[w_pieces], 0x000200000000FEFF); // w_pieces

}

