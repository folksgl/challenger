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
    EXPECT_EQ (actualpos.BLACK_PAWN,   0x00FF000000000000); // BLACK_PAWN
}

TEST(startpos, black_rook) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_ROOK,   0x8100000000000000); // BLACK_ROOK
}

TEST(startpos, black_knight) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_KNIGHT, 0x4200000000000000); // BLACK_KNIGHT
}

TEST(startpos, black_bishop) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_BISHOP, 0x2400000000000000); // BLACK_BISHOP
}

TEST(startpos, black_queen) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_QUEEN,  0x0800000000000000); // BLACK_QUEEN
}

TEST(startpos, black_king) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_KING,   0x1000000000000000); // BLACK_KING
}

TEST(startpos, black_pieces) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_PIECES, 0xFFFF000000000000); // BLACK_PIECES
}

TEST(startpos, white_pawn) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PAWN,   0x000000000000FF00); // WHITE_PAWN
}

TEST(startpos, white_rook) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_ROOK,   0x0000000000000081); // WHITE_ROOK
}

TEST(startpos, white_knight) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_KNIGHT, 0x0000000000000042); // WHITE_KNIGHT
}

TEST(startpos, white_bishop) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_BISHOP, 0x0000000000000024); // WHITE_BISHOP
}

TEST(startpos, white_queen) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_QUEEN,  0x0000000000000008); // WHITE_QUEEN
}

TEST(startpos, white_king) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_KING,   0x0000000000000010); // WHITE_KING
}

TEST(startpos, white_pieces) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PIECES, 0x000000000000FFFF); // WHITE_PIECES
}

TEST(startpos, whole_board) {
    string test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PIECES | actualpos.BLACK_PIECES, 0xFFFF00000000FFFF); // WHOLE_BOARD
}

//
// START COMPLEX POSITION TESTS ////////////////////////////////////////////////
//

TEST(complex_position, black_pawn) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_PAWN,   0x00E50A1000000000); // BLACK_PAWN
}

TEST(complex_position, black_rook) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_ROOK,   0x4002000000000000); // BLACK_ROOK
}

TEST(complex_position, black_knight) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_KNIGHT, 0x0000000410000000); // BLACK_KNIGHT
}

TEST(complex_position, black_bishop) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_BISHOP, 0x0410000000000000); // BLACK_BISHOP
}

TEST(complex_position, black_queen) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_QUEEN,  0x0000008000000000); // BLACK_QUEEN
}

TEST(complex_position, black_king) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_KING,   0x0200000000000000); // BLACK_KING
}

TEST(complex_position, black_pieces) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_PIECES, 0x46F70A9410000000); // BLACK_PIECES
}

TEST(complex_position, white_pawn) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PAWN,   0x0000800008542300); // WHITE_PAWN
}

TEST(complex_position, white_rook) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_ROOK,   0x0000200000000008); // WHITE_ROOK
}

TEST(complex_position, white_knight) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_KNIGHT, 0x0000000200200000); // WHITE_KNIGHT
}

TEST(complex_position, white_bishop) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_BISHOP, 0x0000004000000400); // WHITE_BISHOP
}

TEST(complex_position, white_queen) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_QUEEN,  0x0000000020000000); // WHITE_QUEEN
}

TEST(complex_position, white_king) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_KING,   0x0000000000000004); // WHITE_KING
}

TEST(complex_position, white_pieces) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PIECES, 0x0000A0422874270C); // WHITE_PIECES
}

TEST(complex_position, whole_board) {
    string test = "1kb3r1/prp1bppp/1p1p1R1P/1Nn1p1Bq/3PnQ2/2P1PNP1/PPB2P2/2KR4 w - - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PIECES | actualpos.BLACK_PIECES, 0x46F7AAD63874270C); // WHOLE_BOARD
}

//
// START EMPTY POSITION TESTS //////////////////////////////////////////////////
//

TEST(empty_position, black_pawn) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_PAWN,   0); // BLACK_PAWN
}

TEST(empty_position, black_rook) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_ROOK,   0); // BLACK_ROOK
}

TEST(empty_position, black_knight) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_KNIGHT, 0); // BLACK_KNIGHT
}

TEST(empty_position, black_bishop) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_BISHOP, 0); // BLACK_BISHOP
}

TEST(empty_position, black_queen) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_QUEEN,  0); // BLACK_QUEEN
}

TEST(empty_position, black_king) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_KING,   0); // BLACK_KING
}

TEST(empty_position, black_pieces) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.BLACK_PIECES, 0); // BLACK_PIECES
}

TEST(empty_position, white_pawn) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PAWN,   0); // WHITE_PAWN
}

TEST(empty_position, white_rook) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_ROOK,   0); // WHITE_ROOK
}

TEST(empty_position, white_knight) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_KNIGHT, 0); // WHITE_KNIGHT
}

TEST(empty_position, white_bishop) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_BISHOP, 0); // WHITE_BISHOP
}

TEST(empty_position, white_queen) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_QUEEN,  0); // WHITE_QUEEN
}

TEST(empty_position, white_king) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_KING,   0); // WHITE_KING
}

TEST(empty_position, white_pieces) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    EXPECT_EQ (actualpos.WHITE_PIECES, 0); // WHITE_PIECES
}

TEST(empty_position, whole_board) {
    string test = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
    position actualpos = setup_fen(test);
    bitmap whole = actualpos.WHITE_PIECES & actualpos.BLACK_PIECES;
    EXPECT_EQ (whole, 0); // WHOLE_BOARD
}

//
// START POSITION STRUCT INITIALIZATION TEST ///////////////////////////////////
//

TEST(position_initialization, correct_defaults_black_pawn) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_PAWN,   0);
}

TEST(position_initialization, correct_defaults_black_rook) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_ROOK,   0);
}

TEST(position_initialization, correct_defaults_black_knight) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_KNIGHT, 0);
}

TEST(position_initialization, correct_defaults_black_bishop) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_BISHOP, 0);
}

TEST(position_initialization, correct_defaults_black_queen) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_QUEEN,  0);
}

TEST(position_initialization, correct_defaults_black_king) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_KING,   0);
}

TEST(position_initialization, correct_defaults_black_pieces) {
    position actualpos;
    EXPECT_EQ (actualpos.BLACK_PIECES, 0);
}

TEST(position_initialization, correct_defaults_white_pawn) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_PAWN,   0);
}

TEST(position_initialization, correct_defaults_white_rook) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_ROOK,   0); 
}

TEST(position_initialization, correct_defaults_white_knight) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_KNIGHT, 0);
}

TEST(position_initialization, correct_defaults_white_bishop) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_BISHOP, 0);
}

TEST(position_initialization, correct_defaults_white_queen) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_QUEEN,  0);
}

TEST(position_initialization, correct_defaults_white_king) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_KING,   0);
}

TEST(position_initialization, correct_defaults_white_pieces) {
    position actualpos;
    EXPECT_EQ (actualpos.WHITE_PIECES,   0);
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

