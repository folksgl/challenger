#include "gtest/gtest.h"
#include "../src/position.h"
#include <string>

using namespace std;

//
// START STARTPOS POSITION TESTS ///////////////////////////////////////////////
//

TEST(startpos, black_pawn) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_pawn],   0x00FF000000000000); // b_pawn]
}

TEST(startpos, black_rook) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_rook],   0x8100000000000000); // b_rook]
}

TEST(startpos, black_knight) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_knight], 0x4200000000000000); // b_knight]
}

TEST(startpos, black_bishop) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_bishop], 0x2400000000000000); // b_bishop]
}

TEST(startpos, black_queen) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_queen],  0x0800000000000000); // b_queen]
}

TEST(startpos, black_king) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_king],   0x1000000000000000); // b_king]
}

TEST(startpos, black_pieces) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_pieces], 0xFFFF000000000000); // b_pieces]
}

TEST(startpos, white_pawn) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pawn],   0x000000000000FF00); // w_pawn]
}

TEST(startpos, white_rook) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_rook],   0x0000000000000081); // w_rook]
}

TEST(startpos, white_knight) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_knight], 0x0000000000000042); // w_knight]
}

TEST(startpos, white_bishop) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_bishop], 0x0000000000000024); // w_bishop]
}

TEST(startpos, white_queen) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_queen],  0x0000000000000008); // w_queen]
}

TEST(startpos, white_king) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000010); // w_king]
}

TEST(startpos, white_pieces) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pieces], 0x000000000000FFFF); // w_pieces]
}

TEST(startpos, whole_board) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pieces] | actualpos.maps[b_pieces], 0xFFFF00000000FFFF); // WHOLE_BOARD
}

//
// START COMPLEX POSITION TESTS ////////////////////////////////////////////////
//

TEST(complex_position, black_pawn) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_pawn],   0x00E50A1000000000); // b_pawn]
}

TEST(complex_position, black_rook) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_rook],   0x4002000000000000); // b_rook]
}

TEST(complex_position, black_knight) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_knight], 0x0000000410000000); // b_knight]
}

TEST(complex_position, black_bishop) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_bishop], 0x0410000000000000); // b_bishop]
}

TEST(complex_position, black_queen) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_queen],  0x0000008000000000); // b_queen]
}

TEST(complex_position, black_king) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_king],   0x0200000000000000); // b_king]
}

TEST(complex_position, black_pieces) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_pieces], 0x46F70A9410000000); // b_pieces]
}

TEST(complex_position, white_pawn) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pawn],   0x0000800008542300); // w_pawn]
}

TEST(complex_position, white_rook) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_rook],   0x0000200000000008); // w_rook]
}

TEST(complex_position, white_knight) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_knight], 0x0000000200200000); // w_knight]
}

TEST(complex_position, white_bishop) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_bishop], 0x0000004000000400); // w_bishop]
}

TEST(complex_position, white_queen) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_queen],  0x0000000020000000); // w_queen]
}

TEST(complex_position, white_king) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_king],   0x0000000000000004); // w_king]
}

TEST(complex_position, white_pieces) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pieces], 0x0000A0422874270C); // w_pieces]
}

TEST(complex_position, whole_board) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pieces] | actualpos.maps[b_pieces], 0x46F7AAD63874270C); // WHOLE_BOARD
}

//
// START EMPTY POSITION TESTS //////////////////////////////////////////////////
//

TEST(empty_position, black_pawn) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_pawn],   0); // b_pawn]
}

TEST(empty_position, black_rook) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_rook],   0); // b_rook]
}

TEST(empty_position, black_knight) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_knight], 0); // b_knight]
}

TEST(empty_position, black_bishop) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_bishop], 0); // b_bishop]
}

TEST(empty_position, black_queen) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_queen],  0); // b_queen]
}

TEST(empty_position, black_king) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_king],   0); // b_king]
}

TEST(empty_position, black_pieces) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[b_pieces], 0); // b_pieces]
}

TEST(empty_position, white_pawn) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pawn],   0); // w_pawn]
}

TEST(empty_position, white_rook) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_rook],   0); // w_rook]
}

TEST(empty_position, white_knight) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_knight], 0); // w_knight]
}

TEST(empty_position, white_bishop) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_bishop], 0); // w_bishop]
}

TEST(empty_position, white_queen) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_queen],  0); // w_queen]
}

TEST(empty_position, white_king) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_king],   0); // w_king]
}

TEST(empty_position, white_pieces) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.maps[w_pieces], 0); // w_pieces]
}

TEST(empty_position, whole_board) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    bitmap whole = actualpos.maps[w_pieces] | actualpos.maps[b_pieces];
    EXPECT_EQ (whole, 0); // WHOLE_BOARD
}

//
// START POSITION STRUCT INITIALIZATION TEST ///////////////////////////////////
//

TEST(position_initialization, correct_defaults_black_pawn) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_pawn],   0);
}

TEST(position_initialization, correct_defaults_black_rook) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_rook],   0);
}

TEST(position_initialization, correct_defaults_black_knight) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_knight], 0);
}

TEST(position_initialization, correct_defaults_black_bishop) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_bishop], 0);
}

TEST(position_initialization, correct_defaults_black_queen) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_queen],  0);
}

TEST(position_initialization, correct_defaults_black_king) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_king],   0);
}

TEST(position_initialization, correct_defaults_black_pieces) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[b_pieces], 0);
}

TEST(position_initialization, correct_defaults_white_pawn) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_pawn],   0);
}

TEST(position_initialization, correct_defaults_white_rook) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_rook],   0); 
}

TEST(position_initialization, correct_defaults_white_knight) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_knight], 0);
}

TEST(position_initialization, correct_defaults_white_bishop) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_bishop], 0);
}

TEST(position_initialization, correct_defaults_white_queen) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_queen],  0);
}

TEST(position_initialization, correct_defaults_white_king) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_king],   0);
}

TEST(position_initialization, correct_defaults_white_pieces) {
    position actualpos;
    EXPECT_EQ (actualpos.maps[w_pieces], 0);
}

TEST(position_initialization, correct_defaults_active_color) {
    position actualpos;
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(position_initialization, correct_defaults_wk_castle) {
    position actualpos;
    EXPECT_EQ (actualpos.w_kingside_castle, false);
}

TEST(position_initialization, correct_defaults_wq_castle) {
    position actualpos;
    EXPECT_EQ (actualpos.w_queenside_castle, false);
}

TEST(position_initialization, correct_defaults_bk_castle) {
    position actualpos;
    EXPECT_EQ (actualpos.b_kingside_castle, false);
}

TEST(position_initialization, correct_defaults_bq_castle) {
    position actualpos;
    EXPECT_EQ (actualpos.b_queenside_castle, false);
}

TEST(position_initialization, correct_defaults_passant) {
    position actualpos;
    EXPECT_STREQ (actualpos.passant_target_sq, "-");
}

TEST(position_initialization, correct_defaults_halfmove) {
    position actualpos;
    EXPECT_EQ (actualpos.halfmove_clock, 0);
}

TEST(position_initialization, correct_defaults_fullmove) {
    position actualpos;
    EXPECT_EQ (actualpos.fullmove_number, 0);
}

//
// START CASTLING RIGHTS TEST //////////////////////////////////////////////////
//

TEST(castling_rights, all_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.w_kingside_castle);
    EXPECT_TRUE (actualpos.w_queenside_castle);
    EXPECT_TRUE (actualpos.b_kingside_castle);
    EXPECT_TRUE (actualpos.b_queenside_castle);
}

TEST(castling_rights, white_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.w_kingside_castle);
    EXPECT_TRUE (actualpos.w_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
}

TEST(castling_rights, black_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w kq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.b_kingside_castle);
    EXPECT_TRUE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

TEST(castling_rights, white_kingside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w K - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
}

TEST(castling_rights, black_kingside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w k - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

TEST(castling_rights, white_queenside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Q - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.w_queenside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
}

TEST(castling_rights, black_queenside_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w q - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_TRUE (actualpos.b_queenside_castle);
    EXPECT_FALSE (actualpos.b_kingside_castle);
    EXPECT_FALSE (actualpos.w_kingside_castle);
    EXPECT_FALSE (actualpos.w_queenside_castle);
}

TEST(castling_rights, no_castling_allowed) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - - 0 1";
    position actualpos = setup_fen(test);
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
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(active_color, black_active) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.active_color, 'b');
}

//
// START EN PASSANT TEST ///////////////////////////////////////////////////////
//

TEST(en_passant, d3) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq d3 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(en_passant, a6) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq a6 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(en_passant, h4) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq h4 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.active_color, 'w');
}

TEST(en_passant, c2) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.active_color, 'w');
}

//
// START HALFMOVE CLOCK TEST ///////////////////////////////////////////////////
//

TEST(halfmove_clock, zero) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.halfmove_clock, 0);
}

TEST(halfmove_clock, one) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 1 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.halfmove_clock, 1);
}

TEST(halfmove_clock, seventy_four) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 74 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.halfmove_clock, 74);
}

TEST(halfmove_clock, threehundred_twelve) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 312 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.halfmove_clock, 312);
}

TEST(halfmove_clock, two_thousand_eighty_five) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 2085 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.halfmove_clock, 2085);
}

//
// START FULLMOVE NUMBER TEST //////////////////////////////////////////////////
//

TEST(fullmove_number, zero) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 0";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.fullmove_number, 0);
}

TEST(fullmove_number, one) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.fullmove_number, 1);
}

TEST(fullmove_number, seventy_four) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 74";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.fullmove_number, 74);
}

TEST(fullmove_number, threehundred_twelve) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 312";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.fullmove_number, 312);
}

TEST(fullmove_number, two_thousand_eighty_five) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq c2 0 2085";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.fullmove_number, 2085);
}

//
// START SET BIT TEST /////////////////////////////////////////////////////
//

TEST(set_bit, square_0) {
    bitmap num1 = 0;
    set_bit(&num1, 0);
    EXPECT_EQ (num1, 0x1);
}

TEST(set_bit, square_1) {
    bitmap num1 = 0;
    set_bit(&num1, 1);
    EXPECT_EQ (num1, 0x2);
}

TEST(set_bit, square_3) {
    bitmap num1 = 0;
    set_bit(&num1, 3);
    EXPECT_EQ (num1, 0x8);
}

TEST(set_bit, square_7) {
    bitmap num1 = 0;
    set_bit(&num1, 7);
    EXPECT_EQ (num1, 0x80);
}

TEST(set_bit, square_15) {
    bitmap num1 = 0;
    set_bit(&num1, 15);
    EXPECT_EQ (num1, 0x8000);
}

TEST(set_bit, square_31) {
    bitmap num1 = 0;
    set_bit(&num1, 31);
    EXPECT_EQ (num1, 0x80000000);
}

TEST(set_bit, square_63) {
    bitmap num1 = 0;
    set_bit(&num1, 63);
    EXPECT_EQ (num1, 0x8000000000000000);
}

//
// START ZERO AT TEST /////////////////////////////////////////////////////
//

TEST(zero_at, square_0) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(0, &actualpos);
    EXPECT_EQ (actualpos.maps[w_rook], 0x80);
}

TEST(zero_at, square_1) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(1, &actualpos);
    EXPECT_EQ (actualpos.maps[w_knight], 0x40);
}

TEST(zero_at, square_3) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(3, &actualpos);
    EXPECT_EQ (actualpos.maps[w_queen], 0);
}

TEST(zero_at, square_7) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(7, &actualpos);
    EXPECT_EQ (actualpos.maps[w_rook], 0x01);
}

TEST(zero_at, square_15) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(15, &actualpos);
    EXPECT_EQ (actualpos.maps[w_pawn], 0x7F00);
}

TEST(zero_at, square_31) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(31, &actualpos);
    EXPECT_EQ (actualpos.maps[w_pieces], 0xFFFF);
}

TEST(zero_at, square_63) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    zero_at(63, &actualpos);
    EXPECT_EQ (actualpos.maps[b_rook], 0x0100000000000000);
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

