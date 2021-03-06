#include "gtest/gtest.h"
#include "../src/position.hpp"
#include "../src/common.hpp"

//
// START STARTPOS POSITION TESTS ///////////////////////////////////////////////
//

TEST(StartPosition, black_pawn) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_pawn],   0x00FF000000000000);
}

TEST(StartPosition, black_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_rook],   0x8100000000000000);
}

TEST(StartPosition, black_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_knight], 0x4200000000000000);
}

TEST(StartPosition, black_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_bishop], 0x2400000000000000);
}

TEST(StartPosition, black_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_queen],  0x0800000000000000);
}

TEST(StartPosition, black_king) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_king],   0x1000000000000000);
}

TEST(StartPosition, black_pieces) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[b_pieces], 0xFFFF000000000000);
}

TEST(StartPosition, white_pawn) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_pawn],   0x000000000000FF00);
}

TEST(StartPosition, white_rook) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_rook],   0x0000000000000081);
}

TEST(StartPosition, white_knight) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_knight], 0x0000000000000042);
}

TEST(StartPosition, white_bishop) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_bishop], 0x0000000000000024);
}

TEST(StartPosition, white_queen) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_queen],  0x0000000000000008);
}

TEST(StartPosition, white_king) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_king],   0x0000000000000010);
}

TEST(StartPosition, white_pieces) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_pieces], 0x000000000000FFFF);
}

TEST(StartPosition, whole_board) {
    std::string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position startpos(test);
    EXPECT_EQ(startpos.maps[w_pieces] | startpos.maps[b_pieces], 0xFFFF00000000FFFF);
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
    EXPECT_EQ(complexpos->maps[b_pawn],   0x00E50A1000000000);
}

TEST_F(ComplexPosition, black_rook) {
    EXPECT_EQ(complexpos->maps[b_rook],   0x4002000000000000);
}

TEST_F(ComplexPosition, black_knight) {
    EXPECT_EQ(complexpos->maps[b_knight], 0x0000000410000000);
}

TEST_F(ComplexPosition, black_bishop) {
    EXPECT_EQ(complexpos->maps[b_bishop], 0x0410000000000000);
}

TEST_F(ComplexPosition, black_queen) {
    EXPECT_EQ(complexpos->maps[b_queen],  0x0000008000000000);
}

TEST_F(ComplexPosition, black_king) {
    EXPECT_EQ(complexpos->maps[b_king],   0x0200000000000000);
}

TEST_F(ComplexPosition, black_pieces) {
    EXPECT_EQ(complexpos->maps[b_pieces], 0x46F70A9410000000);
}

TEST_F(ComplexPosition, white_pawn) {
    EXPECT_EQ(complexpos->maps[w_pawn],   0x0000800008542300);
}

TEST_F(ComplexPosition, white_rook) {
    EXPECT_EQ(complexpos->maps[w_rook],   0x0000200000000008);
}

TEST_F(ComplexPosition, white_knight) {
    EXPECT_EQ(complexpos->maps[w_knight], 0x0000000200200000);
}

TEST_F(ComplexPosition, white_bishop) {
    EXPECT_EQ(complexpos->maps[w_bishop], 0x0000004000000400);
}

TEST_F(ComplexPosition, white_queen) {
    EXPECT_EQ(complexpos->maps[w_queen],  0x0000000020000000);
}

TEST_F(ComplexPosition, white_king) {
    EXPECT_EQ(complexpos->maps[w_king],   0x0000000000000004);
}

TEST_F(ComplexPosition, white_pieces) {
    EXPECT_EQ(complexpos->maps[w_pieces], 0x0000A0422874270C);
}

TEST_F(ComplexPosition, whole_board) {
    EXPECT_EQ(complexpos->maps[w_pieces] | complexpos->maps[b_pieces], 0x46F7AAD63874270C);
}
}  // namespace



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
    EXPECT_EQ(emptypos->maps[b_pawn],   0);
}

TEST_F(EmptyPosition, black_rook) {
    EXPECT_EQ(emptypos->maps[b_rook],   0);
}

TEST_F(EmptyPosition, black_knight) {
    EXPECT_EQ(emptypos->maps[b_knight], 0);
}

TEST_F(EmptyPosition, black_bishop) {
    EXPECT_EQ(emptypos->maps[b_bishop], 0);
}

TEST_F(EmptyPosition, black_queen) {
    EXPECT_EQ(emptypos->maps[b_queen],  0);
}

TEST_F(EmptyPosition, black_king) {
    EXPECT_EQ(emptypos->maps[b_king],   0);
}

TEST_F(EmptyPosition, black_pieces) {
    EXPECT_EQ(emptypos->maps[b_pieces], 0);
}

TEST_F(EmptyPosition, white_pawn) {
    EXPECT_EQ(emptypos->maps[w_pawn],   0);
}

TEST_F(EmptyPosition, white_rook) {
    EXPECT_EQ(emptypos->maps[w_rook],   0);
}

TEST_F(EmptyPosition, white_knight) {
    EXPECT_EQ(emptypos->maps[w_knight], 0);
}

TEST_F(EmptyPosition, white_bishop) {
    EXPECT_EQ(emptypos->maps[w_bishop], 0);
}

TEST_F(EmptyPosition, white_queen) {
    EXPECT_EQ(emptypos->maps[w_queen],  0);
}

TEST_F(EmptyPosition, white_king) {
    EXPECT_EQ(emptypos->maps[w_king],   0);
}

TEST_F(EmptyPosition, white_pieces) {
    EXPECT_EQ(emptypos->maps[w_pieces], 0);
}

TEST_F(EmptyPosition, whole_board) {
    EXPECT_EQ((emptypos->maps[w_pieces] | emptypos->maps[b_pieces]), 0);
}
}  // namespace

//
// START CASTLING RIGHTS TEST //////////////////////////////////////////////////
//

TEST(castling_rights, all_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.w_kingside_castle);
    EXPECT_TRUE(actualpos.w_queenside_castle);
    EXPECT_TRUE(actualpos.b_kingside_castle);
    EXPECT_TRUE(actualpos.b_queenside_castle);
}

TEST(castling_rights, white_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.w_kingside_castle);
    EXPECT_TRUE(actualpos.w_queenside_castle);
    EXPECT_FALSE(actualpos.b_kingside_castle);
    EXPECT_FALSE(actualpos.b_queenside_castle);
}

TEST(castling_rights, black_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w kq - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.b_kingside_castle);
    EXPECT_TRUE(actualpos.b_queenside_castle);
    EXPECT_FALSE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, white_kingside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w K - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.w_queenside_castle);
    EXPECT_FALSE(actualpos.b_kingside_castle);
    EXPECT_FALSE(actualpos.b_queenside_castle);
}

TEST(castling_rights, black_kingside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w k - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.b_kingside_castle);
    EXPECT_FALSE(actualpos.b_queenside_castle);
    EXPECT_FALSE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, white_queenside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Q - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.w_queenside_castle);
    EXPECT_FALSE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.b_queenside_castle);
    EXPECT_FALSE(actualpos.b_kingside_castle);
}

TEST(castling_rights, black_queenside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w q - 0 1";
    Position actualpos(test);
    EXPECT_TRUE(actualpos.b_queenside_castle);
    EXPECT_FALSE(actualpos.b_kingside_castle);
    EXPECT_FALSE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, no_castling_allowed_all) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.b_queenside_castle);
    EXPECT_FALSE(actualpos.b_kingside_castle);
    EXPECT_FALSE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, no_castling_allowed_q) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.b_queenside_castle);
}

TEST(castling_rights, no_castling_allowed_k) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.b_kingside_castle);
}

TEST(castling_rights, no_castling_allowed_Q) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, no_castling_allowed_K) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.w_kingside_castle);
}





TEST(castling_rights, bk_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.b_kingside_castle);
}

TEST(castling_rights, wk_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, wq_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.w_queenside_castle);
}

TEST(castling_rights, bq_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    Position actualpos(test);
    EXPECT_FALSE(actualpos.b_queenside_castle);
}

TEST(castling_rights, w_castle_revoked) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQK2R w KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('e', '1'));
    actualpos.move("e1f1", moving_piece);

    EXPECT_FALSE(actualpos.w_kingside_castle);
    EXPECT_FALSE(actualpos.w_queenside_castle);

    EXPECT_TRUE(actualpos.b_kingside_castle);
    EXPECT_TRUE(actualpos.b_queenside_castle);
}

//
// START ACTIVE COLOR TEST /////////////////////////////////////////////////////
//

TEST(active_color, white_active) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.is_white_move, true);
}

TEST(active_color, white_active_change) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a3", moving_piece);
    EXPECT_EQ(actualpos.is_white_move, false);
}

TEST(active_color, black_active) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.is_white_move, false);
}

TEST(active_color, black_active_change) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '7'));
    actualpos.move("a7a6", moving_piece);
    EXPECT_EQ(actualpos.is_white_move, true);
}

//
// START EN PASSANT TEST ///////////////////////////////////////////////////////
//

TEST(en_passant, d3) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq d3 0 1";
    Position actualpos(test);
    EXPECT_EQ(bit_to_square.at(actualpos.passant_sq), "d3");
}

TEST(en_passant, a6) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq a6 0 1";
    Position actualpos(test);
    EXPECT_EQ(bit_to_square.at(actualpos.passant_sq), "a6");
}

TEST(en_passant, h3) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq h3 0 1";
    Position actualpos(test);
    EXPECT_EQ(bit_to_square.at(actualpos.passant_sq), "h3");
}

TEST(en_passant, c6) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c6 0 1";
    Position actualpos(test);
    EXPECT_EQ(bit_to_square.at(actualpos.passant_sq), "c6");
}

//
// START HALFMOVE CLOCK TEST ///////////////////////////////////////////////////
//

TEST(halfmove_clock, zero) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.hlf_clock, 0);
}

TEST(halfmove_clock, one) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 1 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.hlf_clock, 1);
}

TEST(halfmove_clock, seventy_four) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 74 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.hlf_clock, 74);
}

TEST(halfmove_clock, threehundred_twelve) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 312 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.hlf_clock, 312);
}

TEST(halfmove_clock, two_thousand_eighty_five) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 2085 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.hlf_clock, 2085);
}

//
// START FULLMOVE NUMBER TEST //////////////////////////////////////////////////
//

TEST(fullmove_number, zero) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c3 0 0";
    Position actualpos(test);
    EXPECT_EQ(actualpos.full_num, 0);
}

TEST(fullmove_number, one) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c3 0 1";
    Position actualpos(test);
    EXPECT_EQ(actualpos.full_num, 1);
}

TEST(fullmove_number, seventy_four) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c3 0 74";
    Position actualpos(test);
    EXPECT_EQ(actualpos.full_num, 74);
}

TEST(fullmove_number, threehundred_twelve) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c3 0 312";
    Position actualpos(test);
    EXPECT_EQ(actualpos.full_num, 312);
}

TEST(fullmove_number, two_thousand_eighty_five) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c3 0 2085";
    Position actualpos(test);
    EXPECT_EQ(actualpos.full_num, 2085);
}

//
// START GAME MOVE TEST ///////////////////////////////////////////////////
//

TEST(game_move, a2a4) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a4", moving_piece);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FF000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFF000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000100FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000000000100FEFF);
}

TEST(game_move, a2a4_b2b4) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a4", moving_piece);
    moving_piece = actualpos.get_moving_piece(get_square_num('b', '2'));
    actualpos.move("b2b4", moving_piece);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FF000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFF000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000300FC00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000000000300FCFF);
}

TEST(game_move, a2a7) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a7", moving_piece);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FE000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFE000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000100000000FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000100000000FEFF);
}

TEST(game_move, a2a7_a7b7) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a7", moving_piece);
    moving_piece = actualpos.get_moving_piece(get_square_num('a', '7'));
    actualpos.move("a7b7", moving_piece);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FC000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFC000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000200000000FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000200000000FEFF);
}

TEST(game_move, promote_w_knight_a2a8N) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a2a8N", w_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FF000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8000000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFEFF000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0100000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x010000000000FEFF);
}

TEST(game_move, promote_b_knight_a2a8n) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a7a1n", b_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FE000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000001);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFE000000000001);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FF00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000080);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000000000000FFFE);
}

TEST(game_move, promote_w_bishop_a2a8B) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a2a8B", w_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FF000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8000000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFEFF000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0100000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x010000000000FEFF);
}

TEST(game_move, promote_b_bishop_a2a8b) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a7a1b", b_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FE000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000001);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFE000000000001);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FF00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000080);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000000000000FFFE);
}

TEST(game_move, promote_w_rook_a2a8R) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a2a8R", w_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FF000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8000000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFEFF000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0100000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x010000000000FEFF);
}

TEST(game_move, promote_b_rook_a2a8r) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a7a1r", b_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FE000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000001);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFE000000000001);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FF00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000080);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000000000000FFFE);
}

TEST(game_move, promote_w_queen_a2a8Q) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a2a8Q", w_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FF000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8000000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000000);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFEFF000000000000);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FE00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000081);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0100000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x010000000000FEFF);
}

TEST(game_move, promote_b_queen_a2a8q) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.move("a7a1q", b_pawn);

    EXPECT_EQ(actualpos.maps[b_pawn],   0x00FE000000000000);
    EXPECT_EQ(actualpos.maps[b_rook],   0x8100000000000000);
    EXPECT_EQ(actualpos.maps[b_knight], 0x4200000000000000);
    EXPECT_EQ(actualpos.maps[b_bishop], 0x2400000000000000);
    EXPECT_EQ(actualpos.maps[b_queen],  0x0800000000000001);
    EXPECT_EQ(actualpos.maps[b_king],   0x1000000000000000);
    EXPECT_EQ(actualpos.maps[b_pieces], 0xFFFE000000000001);

    EXPECT_EQ(actualpos.maps[w_pawn],   0x000000000000FF00);
    EXPECT_EQ(actualpos.maps[w_rook],   0x0000000000000080);
    EXPECT_EQ(actualpos.maps[w_knight], 0x0000000000000042);
    EXPECT_EQ(actualpos.maps[w_bishop], 0x0000000000000024);
    EXPECT_EQ(actualpos.maps[w_queen],  0x0000000000000008);
    EXPECT_EQ(actualpos.maps[w_king],   0x0000000000000010);
    EXPECT_EQ(actualpos.maps[w_pieces], 0x000000000000FFFE);
}

//
// START COPY CONSTRUCTOR TEST  ///////////////////////////////////////////
//

TEST(copy_constructor, deep_maps) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    Position copypos = Position(actualpos);

    EXPECT_EQ(actualpos.maps[w_pawn], 0x000000000000FF00);
    EXPECT_EQ(copypos.maps[w_pawn], 0x000000000000FF00);
}

TEST(copy_constructor, deep_color) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    Position copypos = Position(actualpos);

    EXPECT_EQ(actualpos.is_white_move, true);
    EXPECT_EQ(copypos.is_white_move,   true);
}

TEST(copy_constructor, deep_moves) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    actualpos.generate_moves();
    Position copypos = Position(actualpos);

    EXPECT_EQ(actualpos.moves.size(), 20);
    EXPECT_EQ(copypos.moves.size(), 0);
}

//
// START OBJECT SIZE TESTS ////////////////////////////////////////////////
//
// The size of a position should not change due to generating moves for that position
TEST(objectsize, position_generation) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position pos_one(test);
    Position pos_two(test);
    pos_one.generate_moves();

    EXPECT_EQ(sizeof(pos_one), sizeof(pos_two));
}

//
// START TO_FEN_STRING TESTS //////////////////////////////////////////////
//

TEST(to_fen_string, startposition) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    string actualstring = actualpos.to_fen_string();

    EXPECT_EQ(actualstring, test);
}

TEST(to_fen_string, random1) {
    string test1 = "2N1bbN1/2k1p3/4K3/1p5r/7R/1nPP4/Q6P/5R2 w - - 0 1";
    Position actualpos(test1);
    string actualstring = actualpos.to_fen_string();

    EXPECT_EQ(actualstring, test1);
}

TEST(to_fen_string, random2) {
    string test2 = "q4rN1/p1r2Pp1/N1PPp1bQ/2p1p2B/3P1R2/1P1Pk1Pn/1bK1pp2/8 w - - 0 1";
    Position actualpos(test2);
    string actualstring = actualpos.to_fen_string();

    EXPECT_EQ(actualstring, test2);
}

//
// START EQUAL_OPERATOR TESTS /////////////////////////////////////////////
//

TEST(equality_operator, equal) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string test2 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    Position actualpos2(test2);

    bool equal = (actualpos == actualpos2);

    EXPECT_TRUE(equal);
}

TEST(equality_operator, not_equal_maps) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string test2 = "Rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);
    Position actualpos2(test2);

    bool equal = (actualpos == actualpos2);

    EXPECT_FALSE(equal);
}

TEST(equality_operator, not_equal_active_color) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string test2 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position actualpos(test);
    Position actualpos2(test2);

    bool equal = (actualpos == actualpos2);

    EXPECT_FALSE(equal);
}

TEST(equality_operator, not_equal_castling) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    string test2 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Qkq - 0 1";
    Position actualpos(test);
    Position actualpos2(test2);

    bool equal = (actualpos == actualpos2);

    EXPECT_FALSE(equal);
}

//
// START IS_X_MOVE TESTS //////////////////////////////////////////////////
//

TEST(is_x_move, white) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);

    bool white_move = actualpos.is_white_move;

    EXPECT_TRUE(white_move);
}

TEST(is_x_move, not_white) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position actualpos(test);

    bool white_move = actualpos.is_white_move;

    EXPECT_FALSE(white_move);
}

TEST(is_x_move, black) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    Position actualpos(test);

    bool black_move = !actualpos.is_white_move;

    EXPECT_TRUE(black_move);
}

TEST(is_x_move, not_black) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);

    bool black_move = !actualpos.is_white_move;

    EXPECT_FALSE(black_move);
}

//
// START EVALUATE TESTS  //////////////////////////////////////////////////
//

TEST(evaluate, evaluation_is_number) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);

    actualpos.evaluate();

    bool isNumber = false;

    if (actualpos.eval_score <= 0 || actualpos.eval_score > 0) {
        isNumber = true;
    }

    EXPECT_TRUE(isNumber);
}

//
// START GENERATE_MOVES TESTS /////////////////////////////////////////////
//

TEST(generate_moves, vector_not_empty) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);

    actualpos.generate_moves();

    EXPECT_FALSE(actualpos.moves.empty());
}

//
// START ~OPERATOR TESTS //////////////////////////////////////////////////
//

TEST(active_color, switch_with_not_operator) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);

    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a3", moving_piece);

    EXPECT_EQ(actualpos.is_white_move, false);
}

TEST(active_color, switch_with_not_operator_2) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Position actualpos(test);

    int moving_piece = actualpos.get_moving_piece(get_square_num('a', '2'));
    actualpos.move("a2a3", moving_piece);
    moving_piece = actualpos.get_moving_piece(get_square_num('a', '7'));
    actualpos.move("a7a6", moving_piece);

    EXPECT_EQ(actualpos.is_white_move, true);
}

//
// START IS_SQUARE_ATTACKED TESTS /////////////////////////////////////////
//

TEST(is_square_attacked, rook_attacks_b_king_post_passant) {
    string test = "8/2p5/3p4/KP5r/1R5k/6p1/4P3/8 w - - 0 1";
    Position actualpos(test);

    EXPECT_EQ(actualpos.is_square_attacked(actualpos.maps[b_king]), true);
}

TEST(is_square_attacked, rook_attacks_b_king_post_passant_2) {
    string test = "8/2p5/3p4/KP5r/1R2Pp1k/8/6P1/8 b - e3 0 1";
    Position actualpos(test);
    int moving_piece = actualpos.get_moving_piece(get_square_num('f', '4'));
    actualpos.move("f4e3", moving_piece);

    EXPECT_EQ(actualpos.is_square_attacked(actualpos.maps[b_king]), true);
}
