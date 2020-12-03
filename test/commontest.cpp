#include "gtest/gtest.h"
#include "../src/evaluate.hpp"
#include "../src/common.hpp"

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
        int bits_set = popcount(numpos->maps[b_pawn]);
        ASSERT_EQ(bits_set, 8);
    }

    TEST_F(NumBitPosition, start_black_knight) {
        int bits_set = popcount(numpos->maps[b_knight]);
        ASSERT_EQ(bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_bishop) {
        int bits_set = popcount(numpos->maps[b_bishop]);
        ASSERT_EQ(bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_rook) {
        int bits_set = popcount(numpos->maps[b_rook]);
        ASSERT_EQ(bits_set, 2);
    }

    TEST_F(NumBitPosition, start_black_queen) {
        int bits_set = popcount(numpos->maps[b_queen]);
        ASSERT_EQ(bits_set, 1);
    }

    TEST_F(NumBitPosition, start_black_king) {
        int bits_set = popcount(numpos->maps[b_king]);
        ASSERT_EQ(bits_set, 1);
    }

    TEST_F(NumBitPosition, start_white_pawn) {
        int bits_set = popcount(numpos->maps[w_pawn]);
        ASSERT_EQ(bits_set, 8);
    }

    TEST_F(NumBitPosition, start_white_knight) {
        int bits_set = popcount(numpos->maps[w_knight]);
        ASSERT_EQ(bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_bishop) {
        int bits_set = popcount(numpos->maps[w_bishop]);
        ASSERT_EQ(bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_rook) {
        int bits_set = popcount(numpos->maps[w_rook]);
        ASSERT_EQ(bits_set, 2);
    }

    TEST_F(NumBitPosition, start_white_queen) {
        int bits_set = popcount(numpos->maps[w_queen]);
        ASSERT_EQ(bits_set, 1);
    }

    TEST_F(NumBitPosition, start_white_king) {
        int bits_set = popcount(numpos->maps[w_king]);
        ASSERT_EQ(bits_set, 1);
    }
}  // namespace

//
// START GET SQUARE NUM TEST //////////////////////////////////////////////
//

TEST(get_sq_num, a1) { ASSERT_EQ(get_square_num('a', '1'), 0); }
TEST(get_sq_num, b1) { ASSERT_EQ(get_square_num('b', '1'), 1); }
TEST(get_sq_num, c1) { ASSERT_EQ(get_square_num('c', '1'), 2); }
TEST(get_sq_num, d1) { ASSERT_EQ(get_square_num('d', '1'), 3); }
TEST(get_sq_num, e1) { ASSERT_EQ(get_square_num('e', '1'), 4); }
TEST(get_sq_num, f1) { ASSERT_EQ(get_square_num('f', '1'), 5); }
TEST(get_sq_num, g1) { ASSERT_EQ(get_square_num('g', '1'), 6); }
TEST(get_sq_num, h1) { ASSERT_EQ(get_square_num('h', '1'), 7); }
TEST(get_sq_num, a2) { ASSERT_EQ(get_square_num('a', '2'), 8); }
TEST(get_sq_num, b2) { ASSERT_EQ(get_square_num('b', '2'), 9); }
TEST(get_sq_num, c2) { ASSERT_EQ(get_square_num('c', '2'), 10); }
TEST(get_sq_num, d2) { ASSERT_EQ(get_square_num('d', '2'), 11); }
TEST(get_sq_num, e2) { ASSERT_EQ(get_square_num('e', '2'), 12); }
TEST(get_sq_num, f2) { ASSERT_EQ(get_square_num('f', '2'), 13); }
TEST(get_sq_num, g2) { ASSERT_EQ(get_square_num('g', '2'), 14); }
TEST(get_sq_num, h2) { ASSERT_EQ(get_square_num('h', '2'), 15); }
TEST(get_sq_num, a3) { ASSERT_EQ(get_square_num('a', '3'), 16); }
TEST(get_sq_num, b3) { ASSERT_EQ(get_square_num('b', '3'), 17); }
TEST(get_sq_num, c3) { ASSERT_EQ(get_square_num('c', '3'), 18); }
TEST(get_sq_num, d3) { ASSERT_EQ(get_square_num('d', '3'), 19); }
TEST(get_sq_num, e3) { ASSERT_EQ(get_square_num('e', '3'), 20); }
TEST(get_sq_num, f3) { ASSERT_EQ(get_square_num('f', '3'), 21); }
TEST(get_sq_num, g3) { ASSERT_EQ(get_square_num('g', '3'), 22); }
TEST(get_sq_num, h3) { ASSERT_EQ(get_square_num('h', '3'), 23); }
TEST(get_sq_num, a4) { ASSERT_EQ(get_square_num('a', '4'), 24); }
TEST(get_sq_num, b4) { ASSERT_EQ(get_square_num('b', '4'), 25); }
TEST(get_sq_num, c4) { ASSERT_EQ(get_square_num('c', '4'), 26); }
TEST(get_sq_num, d4) { ASSERT_EQ(get_square_num('d', '4'), 27); }
TEST(get_sq_num, e4) { ASSERT_EQ(get_square_num('e', '4'), 28); }
TEST(get_sq_num, f4) { ASSERT_EQ(get_square_num('f', '4'), 29); }
TEST(get_sq_num, g4) { ASSERT_EQ(get_square_num('g', '4'), 30); }
TEST(get_sq_num, h4) { ASSERT_EQ(get_square_num('h', '4'), 31); }
TEST(get_sq_num, a5) { ASSERT_EQ(get_square_num('a', '5'), 32); }
TEST(get_sq_num, b5) { ASSERT_EQ(get_square_num('b', '5'), 33); }
TEST(get_sq_num, c5) { ASSERT_EQ(get_square_num('c', '5'), 34); }
TEST(get_sq_num, d5) { ASSERT_EQ(get_square_num('d', '5'), 35); }
TEST(get_sq_num, e5) { ASSERT_EQ(get_square_num('e', '5'), 36); }
TEST(get_sq_num, f5) { ASSERT_EQ(get_square_num('f', '5'), 37); }
TEST(get_sq_num, g5) { ASSERT_EQ(get_square_num('g', '5'), 38); }
TEST(get_sq_num, h5) { ASSERT_EQ(get_square_num('h', '5'), 39); }
TEST(get_sq_num, a6) { ASSERT_EQ(get_square_num('a', '6'), 40); }
TEST(get_sq_num, b6) { ASSERT_EQ(get_square_num('b', '6'), 41); }
TEST(get_sq_num, c6) { ASSERT_EQ(get_square_num('c', '6'), 42); }
TEST(get_sq_num, d6) { ASSERT_EQ(get_square_num('d', '6'), 43); }
TEST(get_sq_num, e6) { ASSERT_EQ(get_square_num('e', '6'), 44); }
TEST(get_sq_num, f6) { ASSERT_EQ(get_square_num('f', '6'), 45); }
TEST(get_sq_num, g6) { ASSERT_EQ(get_square_num('g', '6'), 46); }
TEST(get_sq_num, h6) { ASSERT_EQ(get_square_num('h', '6'), 47); }
TEST(get_sq_num, a7) { ASSERT_EQ(get_square_num('a', '7'), 48); }
TEST(get_sq_num, b7) { ASSERT_EQ(get_square_num('b', '7'), 49); }
TEST(get_sq_num, c7) { ASSERT_EQ(get_square_num('c', '7'), 50); }
TEST(get_sq_num, d7) { ASSERT_EQ(get_square_num('d', '7'), 51); }
TEST(get_sq_num, e7) { ASSERT_EQ(get_square_num('e', '7'), 52); }
TEST(get_sq_num, f7) { ASSERT_EQ(get_square_num('f', '7'), 53); }
TEST(get_sq_num, g7) { ASSERT_EQ(get_square_num('g', '7'), 54); }
TEST(get_sq_num, h7) { ASSERT_EQ(get_square_num('h', '7'), 55); }
TEST(get_sq_num, a8) { ASSERT_EQ(get_square_num('a', '8'), 56); }
TEST(get_sq_num, b8) { ASSERT_EQ(get_square_num('b', '8'), 57); }
TEST(get_sq_num, c8) { ASSERT_EQ(get_square_num('c', '8'), 58); }
TEST(get_sq_num, d8) { ASSERT_EQ(get_square_num('d', '8'), 59); }
TEST(get_sq_num, e8) { ASSERT_EQ(get_square_num('e', '8'), 60); }
TEST(get_sq_num, f8) { ASSERT_EQ(get_square_num('f', '8'), 61); }
TEST(get_sq_num, g8) { ASSERT_EQ(get_square_num('g', '8'), 62); }
TEST(get_sq_num, h8) { ASSERT_EQ(get_square_num('h', '8'), 63); }

//
// CONST FILE TEST
//

TEST(const_files, a) { ASSERT_EQ(a_file, 0x0101010101010101); }
TEST(const_files, b) { ASSERT_EQ(b_file, 0x0202020202020202); }
TEST(const_files, c) { ASSERT_EQ(c_file, 0x0404040404040404); }
TEST(const_files, d) { ASSERT_EQ(d_file, 0x0808080808080808); }
TEST(const_files, e) { ASSERT_EQ(e_file, 0x1010101010101010); }
TEST(const_files, f) { ASSERT_EQ(f_file, 0x2020202020202020); }
TEST(const_files, g) { ASSERT_EQ(g_file, 0x4040404040404040); }
TEST(const_files, h) { ASSERT_EQ(h_file, 0x8080808080808080); }
TEST(const_files, not_a) { ASSERT_EQ(not_a_file, 0xFEFEFEFEFEFEFEFE); }
TEST(const_files, not_h) { ASSERT_EQ(not_h_file, 0x7F7F7F7F7F7F7F7F); }

//
// KNIGHT LOOKUP TABLE TESTS
//

TEST(correct_lookup_table, all_64_knight_moves) {
    ASSERT_EQ(knight_moves[0], 132096ULL);
    ASSERT_EQ(knight_moves[1], 329728ULL);
    ASSERT_EQ(knight_moves[2], 659712ULL);
    ASSERT_EQ(knight_moves[3], 1319424ULL);
    ASSERT_EQ(knight_moves[4], 2638848ULL);
    ASSERT_EQ(knight_moves[5], 5277696ULL);
    ASSERT_EQ(knight_moves[6], 10489856ULL);
    ASSERT_EQ(knight_moves[7], 4202496ULL);
    ASSERT_EQ(knight_moves[8], 33816580ULL);
    ASSERT_EQ(knight_moves[9], 84410376ULL);
    ASSERT_EQ(knight_moves[10], 168886289ULL);
    ASSERT_EQ(knight_moves[11], 337772578ULL);
    ASSERT_EQ(knight_moves[12], 675545156ULL);
    ASSERT_EQ(knight_moves[13], 1351090312ULL);
    ASSERT_EQ(knight_moves[14], 2685403152ULL);
    ASSERT_EQ(knight_moves[15], 1075839008ULL);
    ASSERT_EQ(knight_moves[16], 8657044482ULL);
    ASSERT_EQ(knight_moves[17], 21609056261ULL);
    ASSERT_EQ(knight_moves[18], 43234889994ULL);
    ASSERT_EQ(knight_moves[19], 86469779988ULL);
    ASSERT_EQ(knight_moves[20], 172939559976ULL);
    ASSERT_EQ(knight_moves[21], 345879119952ULL);
    ASSERT_EQ(knight_moves[22], 687463207072ULL);
    ASSERT_EQ(knight_moves[23], 275414786112ULL);
    ASSERT_EQ(knight_moves[24], 2216203387392ULL);
    ASSERT_EQ(knight_moves[25], 5531918402816ULL);
    ASSERT_EQ(knight_moves[26], 11068131838464ULL);
    ASSERT_EQ(knight_moves[27], 22136263676928ULL);
    ASSERT_EQ(knight_moves[28], 44272527353856ULL);
    ASSERT_EQ(knight_moves[29], 88545054707712ULL);
    ASSERT_EQ(knight_moves[30], 175990581010432ULL);
    ASSERT_EQ(knight_moves[31], 70506185244672ULL);
    ASSERT_EQ(knight_moves[32], 567348067172352ULL);
    ASSERT_EQ(knight_moves[33], 1416171111120896ULL);
    ASSERT_EQ(knight_moves[34], 2833441750646784ULL);
    ASSERT_EQ(knight_moves[35], 5666883501293568ULL);
    ASSERT_EQ(knight_moves[36], 11333767002587136ULL);
    ASSERT_EQ(knight_moves[37], 22667534005174272ULL);
    ASSERT_EQ(knight_moves[38], 45053588738670592ULL);
    ASSERT_EQ(knight_moves[39], 18049583422636032ULL);
    ASSERT_EQ(knight_moves[40], 145241105196122112ULL);
    ASSERT_EQ(knight_moves[41], 362539804446949376ULL);
    ASSERT_EQ(knight_moves[42], 725361088165576704ULL);
    ASSERT_EQ(knight_moves[43], 1450722176331153408ULL);
    ASSERT_EQ(knight_moves[44], 2901444352662306816ULL);
    ASSERT_EQ(knight_moves[45], 5802888705324613632ULL);
    ASSERT_EQ(knight_moves[46], 11533718717099671552ULL);
    ASSERT_EQ(knight_moves[47], 4620693356194824192ULL);
    ASSERT_EQ(knight_moves[48], 288234782788157440ULL);
    ASSERT_EQ(knight_moves[49], 576469569871282176ULL);
    ASSERT_EQ(knight_moves[50], 1224997833292120064ULL);
    ASSERT_EQ(knight_moves[51], 2449995666584240128ULL);
    ASSERT_EQ(knight_moves[52], 4899991333168480256ULL);
    ASSERT_EQ(knight_moves[53], 9799982666336960512ULL);
    ASSERT_EQ(knight_moves[54], 1152939783987658752ULL);
    ASSERT_EQ(knight_moves[55], 2305878468463689728ULL);
    ASSERT_EQ(knight_moves[56], 1128098930098176ULL);
    ASSERT_EQ(knight_moves[57], 2257297371824128ULL);
    ASSERT_EQ(knight_moves[58], 4796069720358912ULL);
    ASSERT_EQ(knight_moves[59], 9592139440717824ULL);
    ASSERT_EQ(knight_moves[60], 19184278881435648ULL);
    ASSERT_EQ(knight_moves[61], 38368557762871296ULL);
    ASSERT_EQ(knight_moves[62], 4679521487814656ULL);
    ASSERT_EQ(knight_moves[63], 9077567998918656ULL);
}

//
// KING LOOKUP TABLE TESTS
//

TEST(correct_lookup_table, all_64_king_moves) {
    ASSERT_EQ(king_moves[0], 770ULL);
    ASSERT_EQ(king_moves[1], 1797ULL);
    ASSERT_EQ(king_moves[2], 3594ULL);
    ASSERT_EQ(king_moves[3], 7188ULL);
    ASSERT_EQ(king_moves[4], 14376ULL);
    ASSERT_EQ(king_moves[5], 28752ULL);
    ASSERT_EQ(king_moves[6], 57504ULL);
    ASSERT_EQ(king_moves[7], 49216ULL);
    ASSERT_EQ(king_moves[8], 197123ULL);
    ASSERT_EQ(king_moves[9], 460039ULL);
    ASSERT_EQ(king_moves[10], 920078ULL);
    ASSERT_EQ(king_moves[11], 1840156ULL);
    ASSERT_EQ(king_moves[12], 3680312ULL);
    ASSERT_EQ(king_moves[13], 7360624ULL);
    ASSERT_EQ(king_moves[14], 14721248ULL);
    ASSERT_EQ(king_moves[15], 12599488ULL);
    ASSERT_EQ(king_moves[16], 50463488ULL);
    ASSERT_EQ(king_moves[17], 117769984ULL);
    ASSERT_EQ(king_moves[18], 235539968ULL);
    ASSERT_EQ(king_moves[19], 471079936ULL);
    ASSERT_EQ(king_moves[20], 942159872ULL);
    ASSERT_EQ(king_moves[21], 1884319744ULL);
    ASSERT_EQ(king_moves[22], 3768639488ULL);
    ASSERT_EQ(king_moves[23], 3225468928ULL);
    ASSERT_EQ(king_moves[24], 12918652928ULL);
    ASSERT_EQ(king_moves[25], 30149115904ULL);
    ASSERT_EQ(king_moves[26], 60298231808ULL);
    ASSERT_EQ(king_moves[27], 120596463616ULL);
    ASSERT_EQ(king_moves[28], 241192927232ULL);
    ASSERT_EQ(king_moves[29], 482385854464ULL);
    ASSERT_EQ(king_moves[30], 964771708928ULL);
    ASSERT_EQ(king_moves[31], 825720045568ULL);
    ASSERT_EQ(king_moves[32], 3307175149568ULL);
    ASSERT_EQ(king_moves[33], 7718173671424ULL);
    ASSERT_EQ(king_moves[34], 15436347342848ULL);
    ASSERT_EQ(king_moves[35], 30872694685696ULL);
    ASSERT_EQ(king_moves[36], 61745389371392ULL);
    ASSERT_EQ(king_moves[37], 123490778742784ULL);
    ASSERT_EQ(king_moves[38], 246981557485568ULL);
    ASSERT_EQ(king_moves[39], 211384331665408ULL);
    ASSERT_EQ(king_moves[40], 846636838289408ULL);
    ASSERT_EQ(king_moves[41], 1975852459884544ULL);
    ASSERT_EQ(king_moves[42], 3951704919769088ULL);
    ASSERT_EQ(king_moves[43], 7903409839538176ULL);
    ASSERT_EQ(king_moves[44], 15806819679076352ULL);
    ASSERT_EQ(king_moves[45], 31613639358152704ULL);
    ASSERT_EQ(king_moves[46], 63227278716305408ULL);
    ASSERT_EQ(king_moves[47], 54114388906344448ULL);
    ASSERT_EQ(king_moves[48], 216739030602088448ULL);
    ASSERT_EQ(king_moves[49], 505818229730443264ULL);
    ASSERT_EQ(king_moves[50], 1011636459460886528ULL);
    ASSERT_EQ(king_moves[51], 2023272918921773056ULL);
    ASSERT_EQ(king_moves[52], 4046545837843546112ULL);
    ASSERT_EQ(king_moves[53], 8093091675687092224ULL);
    ASSERT_EQ(king_moves[54], 16186183351374184448ULL);
    ASSERT_EQ(king_moves[55], 13853283560024178688ULL);
    ASSERT_EQ(king_moves[56], 144959613005987840ULL);
    ASSERT_EQ(king_moves[57], 362258295026614272ULL);
    ASSERT_EQ(king_moves[58], 724516590053228544ULL);
    ASSERT_EQ(king_moves[59], 1449033180106457088ULL);
    ASSERT_EQ(king_moves[60], 2898066360212914176ULL);
    ASSERT_EQ(king_moves[61], 5796132720425828352ULL);
    ASSERT_EQ(king_moves[62], 11592265440851656704ULL);
    ASSERT_EQ(king_moves[63], 4665729213955833856ULL);
}

