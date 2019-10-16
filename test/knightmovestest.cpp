#include "gtest/gtest.h"
#include "../src/genmove.h"
#include "../src/uci.h"
#include "../src/common.h"
#include <string>

using namespace std;

TEST(correct_lookup_table, all_64_knight_moves) {
    EXPECT_EQ (knight_moves[0], 132096ULL);
    EXPECT_EQ (knight_moves[1], 329728ULL);
    EXPECT_EQ (knight_moves[2], 659712ULL);
    EXPECT_EQ (knight_moves[3], 1319424ULL);
    EXPECT_EQ (knight_moves[4], 2638848ULL);
    EXPECT_EQ (knight_moves[5], 5277696ULL);
    EXPECT_EQ (knight_moves[6], 10489856ULL);
    EXPECT_EQ (knight_moves[7], 4202496ULL);
    EXPECT_EQ (knight_moves[8], 33816580ULL);
    EXPECT_EQ (knight_moves[9], 84410376ULL);
    EXPECT_EQ (knight_moves[10], 168886289ULL);
    EXPECT_EQ (knight_moves[11], 337772578ULL);
    EXPECT_EQ (knight_moves[12], 675545156ULL);
    EXPECT_EQ (knight_moves[13], 1351090312ULL);
    EXPECT_EQ (knight_moves[14], 2685403152ULL);
    EXPECT_EQ (knight_moves[15], 1075839008ULL);
    EXPECT_EQ (knight_moves[16], 8657044482ULL);
    EXPECT_EQ (knight_moves[17], 21609056261ULL);
    EXPECT_EQ (knight_moves[18], 43234889994ULL);
    EXPECT_EQ (knight_moves[19], 86469779988ULL);
    EXPECT_EQ (knight_moves[20], 172939559976ULL);
    EXPECT_EQ (knight_moves[21], 345879119952ULL);
    EXPECT_EQ (knight_moves[22], 687463207072ULL);
    EXPECT_EQ (knight_moves[23], 275414786112ULL);
    EXPECT_EQ (knight_moves[24], 2216203387392ULL);
    EXPECT_EQ (knight_moves[25], 5531918402816ULL);
    EXPECT_EQ (knight_moves[26], 11068131838464ULL);
    EXPECT_EQ (knight_moves[27], 22136263676928ULL);
    EXPECT_EQ (knight_moves[28], 44272527353856ULL);
    EXPECT_EQ (knight_moves[29], 88545054707712ULL);
    EXPECT_EQ (knight_moves[30], 175990581010432ULL);
    EXPECT_EQ (knight_moves[31], 70506185244672ULL);
    EXPECT_EQ (knight_moves[32], 567348067172352ULL);
    EXPECT_EQ (knight_moves[33], 1416171111120896ULL);
    EXPECT_EQ (knight_moves[34], 2833441750646784ULL);
    EXPECT_EQ (knight_moves[35], 5666883501293568ULL);
    EXPECT_EQ (knight_moves[36], 11333767002587136ULL);
    EXPECT_EQ (knight_moves[37], 22667534005174272ULL);
    EXPECT_EQ (knight_moves[38], 45053588738670592ULL);
    EXPECT_EQ (knight_moves[39], 18049583422636032ULL);
    EXPECT_EQ (knight_moves[40], 145241105196122112ULL);
    EXPECT_EQ (knight_moves[41], 362539804446949376ULL);
    EXPECT_EQ (knight_moves[42], 725361088165576704ULL);
    EXPECT_EQ (knight_moves[43], 1450722176331153408ULL);
    EXPECT_EQ (knight_moves[44], 2901444352662306816ULL);
    EXPECT_EQ (knight_moves[45], 5802888705324613632ULL);
    EXPECT_EQ (knight_moves[46], 11533718717099671552ULL);
    EXPECT_EQ (knight_moves[47], 4620693356194824192ULL);
    EXPECT_EQ (knight_moves[48], 288234782788157440ULL);
    EXPECT_EQ (knight_moves[49], 576469569871282176ULL);
    EXPECT_EQ (knight_moves[50], 1224997833292120064ULL);
    EXPECT_EQ (knight_moves[51], 2449995666584240128ULL);
    EXPECT_EQ (knight_moves[52], 4899991333168480256ULL);
    EXPECT_EQ (knight_moves[53], 9799982666336960512ULL);
    EXPECT_EQ (knight_moves[54], 1152939783987658752ULL);
    EXPECT_EQ (knight_moves[55], 2305878468463689728ULL);
    EXPECT_EQ (knight_moves[56], 1128098930098176ULL);
    EXPECT_EQ (knight_moves[57], 2257297371824128ULL);
    EXPECT_EQ (knight_moves[58], 4796069720358912ULL);
    EXPECT_EQ (knight_moves[59], 9592139440717824ULL);
    EXPECT_EQ (knight_moves[60], 19184278881435648ULL);
    EXPECT_EQ (knight_moves[61], 38368557762871296ULL);
    EXPECT_EQ (knight_moves[62], 4679521487814656ULL);
    EXPECT_EQ (knight_moves[63], 9077567998918656ULL);
}

TEST(correct_knight_moves_generated, white_knight_a1) {
    std::string test = "8/8/8/8/8/8/8/N7 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 2);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a1b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a1c2");
}

TEST(correct_knight_moves_generated, white_knight_b1) {
    std::string test = "8/8/8/8/8/8/8/1N6 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b1a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b1c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b1d2");
}

TEST(correct_knight_moves_generated, white_knight_c1) {
    std::string test = "8/8/8/8/8/8/8/2N5 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c1a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c1b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c1d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c1e2");
}

TEST(correct_knight_moves_generated, white_knight_d1) {
    std::string test = "8/8/8/8/8/8/8/3N4 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d1b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d1c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d1e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d1f2");
}

TEST(correct_knight_moves_generated, white_knight_e1) {
    std::string test = "8/8/8/8/8/8/8/4N3 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e1c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e1d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e1f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e1g2");
}

TEST(correct_knight_moves_generated, white_knight_f1) {
    std::string test = "8/8/8/8/8/8/8/5N2 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f1d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f1e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f1g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f1h2");
}

TEST(correct_knight_moves_generated, white_knight_g1) {
    std::string test = "8/8/8/8/8/8/8/6N1 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g1e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g1f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g1h3");
}

TEST(correct_knight_moves_generated, white_knight_h1) {
    std::string test = "8/8/8/8/8/8/8/7N w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 2);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h1f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h1g3");
}

TEST(correct_knight_moves_generated, white_knight_a2) {
    std::string test = "8/8/8/8/8/8/N7/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a2b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a2c3");
}

TEST(correct_knight_moves_generated, white_knight_b2) {
    std::string test = "8/8/8/8/8/8/1N6/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b2a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b2c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b2d3");
}

TEST(correct_knight_moves_generated, white_knight_c2) {
    std::string test = "8/8/8/8/8/8/2N5/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c2a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c2a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c2b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c2d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c2e3");
}

TEST(correct_knight_moves_generated, white_knight_d2) {
    std::string test = "8/8/8/8/8/8/3N4/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d2b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d2b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d2c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d2e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d2f3");
}

TEST(correct_knight_moves_generated, white_knight_e2) {
    std::string test = "8/8/8/8/8/8/4N3/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e2c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e2c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e2d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e2f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e2g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e2g3");
}

TEST(correct_knight_moves_generated, white_knight_f2) {
    std::string test = "8/8/8/8/8/8/5N2/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f2d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f2d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f2e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f2g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f2h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f2h3");
}

TEST(correct_knight_moves_generated, white_knight_g2) {
    std::string test = "8/8/8/8/8/8/6N1/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g2e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g2e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g2f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g2h4");
}

TEST(correct_knight_moves_generated, white_knight_h2) {
    std::string test = "8/8/8/8/8/8/7N/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h2f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h2f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h2g4");
}

TEST(correct_knight_moves_generated, white_knight_a3) {
    std::string test = "8/8/8/8/8/N7/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a3b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a3b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a3c4");
}

TEST(correct_knight_moves_generated, white_knight_b3) {
    std::string test = "8/8/8/8/8/1N6/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b3a1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b3a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b3c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b3c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b3d4");
}

TEST(correct_knight_moves_generated, white_knight_c3) {
    std::string test = "8/8/8/8/8/2N5/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c3a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c3a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c3b1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c3b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c3d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c3d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c3e4");
}

TEST(correct_knight_moves_generated, white_knight_d3) {
    std::string test = "8/8/8/8/8/3N4/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d3b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d3b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d3c1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d3c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d3e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d3e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d3f4");
}

TEST(correct_knight_moves_generated, white_knight_e3) {
    std::string test = "8/8/8/8/8/4N3/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e3c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e3c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e3d1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e3d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e3f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e3f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e3g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e3g4");
}

TEST(correct_knight_moves_generated, white_knight_f3) {
    std::string test = "8/8/8/8/8/5N2/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f3d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f3d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f3e1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f3e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f3g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f3g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f3h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f3h4");
}

TEST(correct_knight_moves_generated, white_knight_g3) {
    std::string test = "8/8/8/8/8/6N1/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g3e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g3e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g3f1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g3f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g3h1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g3h5");
}

TEST(correct_knight_moves_generated, white_knight_h3) {
    std::string test = "8/8/8/8/8/7N/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h3f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h3f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h3g1");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h3g5");
}

TEST(correct_knight_moves_generated, white_knight_a4) {
    std::string test = "8/8/8/8/N7/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a4b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a4b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a4c5");
}

TEST(correct_knight_moves_generated, white_knight_b4) {
    std::string test = "8/8/8/8/1N6/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b4a2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b4a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b4c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b4c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b4d5");
}

TEST(correct_knight_moves_generated, white_knight_c4) {
    std::string test = "8/8/8/8/2N5/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c4a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c4a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c4b2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c4b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c4d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c4d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c4e5");
}

TEST(correct_knight_moves_generated, white_knight_d4) {
    std::string test = "8/8/8/8/3N4/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d4b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d4b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d4c2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d4c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d4e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d4e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d4f5");
}

TEST(correct_knight_moves_generated, white_knight_e4) {
    std::string test = "8/8/8/8/4N3/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e4c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e4c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e4d2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e4d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e4f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e4f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e4g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e4g5");
}

TEST(correct_knight_moves_generated, white_knight_f4) {
    std::string test = "8/8/8/8/5N2/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f4d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f4d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f4e2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f4e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f4g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f4g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f4h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f4h5");
}

TEST(correct_knight_moves_generated, white_knight_g4) {
    std::string test = "8/8/8/8/6N1/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g4e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g4e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g4f2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g4f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g4h2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g4h6");
}

TEST(correct_knight_moves_generated, white_knight_h4) {
    std::string test = "8/8/8/8/7N/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h4f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h4f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h4g2");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h4g6");
}

TEST(correct_knight_moves_generated, white_knight_a5) {
    std::string test = "8/8/8/N7/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a5b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a5b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a5c6");
}

TEST(correct_knight_moves_generated, white_knight_b5) {
    std::string test = "8/8/8/1N6/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b5a3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b5a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b5c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b5c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b5d6");
}

TEST(correct_knight_moves_generated, white_knight_c5) {
    std::string test = "8/8/8/2N5/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c5a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c5a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c5b3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c5b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c5d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c5d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c5e6");
}

TEST(correct_knight_moves_generated, white_knight_d5) {
    std::string test = "8/8/8/3N4/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d5b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d5b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d5c3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d5c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d5e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d5e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d5f6");
}

TEST(correct_knight_moves_generated, white_knight_e5) {
    std::string test = "8/8/8/4N3/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e5c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e5c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e5d3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e5d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e5f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e5f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e5g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e5g6");
}

TEST(correct_knight_moves_generated, white_knight_f5) {
    std::string test = "8/8/8/5N2/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f5d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f5d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f5e3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f5e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f5g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f5g7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f5h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f5h6");
}

TEST(correct_knight_moves_generated, white_knight_g5) {
    std::string test = "8/8/8/6N1/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g5e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g5e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g5f3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g5f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g5h3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g5h7");
}

TEST(correct_knight_moves_generated, white_knight_h5) {
    std::string test = "8/8/8/7N/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h5f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h5f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h5g3");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h5g7");
}

TEST(correct_knight_moves_generated, white_knight_a6) {
    std::string test = "8/8/N7/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a6b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a6b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "a6c7");
}

TEST(correct_knight_moves_generated, white_knight_b6) {
    std::string test = "8/8/1N6/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b6a4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b6a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b6c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b6c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "b6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "b6d7");
}

TEST(correct_knight_moves_generated, white_knight_c6) {
    std::string test = "8/8/2N5/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c6a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c6a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c6b4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c6b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c6d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c6d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "c6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "c6e7");
}

TEST(correct_knight_moves_generated, white_knight_d6) {
    std::string test = "8/8/3N4/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d6b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d6b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d6c4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d6c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d6e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d6e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "d6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "d6f7");
}

TEST(correct_knight_moves_generated, white_knight_e6) {
    std::string test = "8/8/4N3/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e6c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e6c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e6d4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e6d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e6f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e6f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "e6g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "e6g7");
}

TEST(correct_knight_moves_generated, white_knight_f6) {
    std::string test = "8/8/5N2/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 8);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f6d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f6d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f6e4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f6e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f6g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f6g8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[6]),   "f6h5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[7]),   "f6h7");
}

TEST(correct_knight_moves_generated, white_knight_g6) {
    std::string test = "8/8/6N1/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g6e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g6e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g6f4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g6f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "g6h4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "g6h8");
}

TEST(correct_knight_moves_generated, white_knight_h6) {
    std::string test = "8/8/7N/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h6f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h6f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h6g4");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "h6g8");
}

TEST(correct_knight_moves_generated, white_knight_a7) {
    std::string test = "8/N7/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a7b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "a7c8");
}

TEST(correct_knight_moves_generated, white_knight_b7) {
    std::string test = "8/1N6/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b7a5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b7c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "b7d8");
}

TEST(correct_knight_moves_generated, white_knight_c7) {
    std::string test = "8/2N5/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c7a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c7a8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c7b5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c7d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "c7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "c7e8");
}

TEST(correct_knight_moves_generated, white_knight_d7) {
    std::string test = "8/3N4/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d7b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d7b8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d7c5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d7e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "d7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "d7f8");
}

TEST(correct_knight_moves_generated, white_knight_e7) {
    std::string test = "8/4N3/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e7c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e7c8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e7d5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e7f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "e7g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "e7g8");
}

TEST(correct_knight_moves_generated, white_knight_f7) {
    std::string test = "8/5N2/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 6);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f7d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f7d8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f7e5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f7g5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[4]),   "f7h6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[5]),   "f7h8");
}

TEST(correct_knight_moves_generated, white_knight_g7) {
    std::string test = "8/6N1/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g7e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g7e8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g7f5");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "g7h5");
}

TEST(correct_knight_moves_generated, white_knight_h7) {
    std::string test = "8/7N/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h7f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h7f8");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "h7g5");
}

TEST(correct_knight_moves_generated, white_knight_a8) {
    std::string test = "N7/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 2);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "a8b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "a8c7");
}

TEST(correct_knight_moves_generated, white_knight_b8) {
    std::string test = "1N6/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "b8a6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "b8c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "b8d7");
}

TEST(correct_knight_moves_generated, white_knight_c8) {
    std::string test = "2N5/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "c8a7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "c8b6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "c8d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "c8e7");
}

TEST(correct_knight_moves_generated, white_knight_d8) {
    std::string test = "3N4/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "d8b7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "d8c6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "d8e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "d8f7");
}

TEST(correct_knight_moves_generated, white_knight_e8) {
    std::string test = "4N3/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "e8c7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "e8d6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "e8f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "e8g7");
}

TEST(correct_knight_moves_generated, white_knight_f8) {
    std::string test = "5N2/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 4);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "f8d7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "f8e6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "f8g6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[3]),   "f8h7");
}

TEST(correct_knight_moves_generated, white_knight_g8) {
    std::string test = "6N1/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 3);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "g8e7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "g8f6");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[2]),   "g8h6");
}

TEST(correct_knight_moves_generated, white_knight_h8) {
    std::string test = "7N/8/8/8/8/8/8/8 w KQkq - 0 1";
    Position startpos(test);

    generate_moves(&startpos);

    std::sort(startpos.moves.begin(), startpos.moves.end(), 
            [&startpos](Position &a, Position &b) { return find_move_taken(&startpos, &a) < find_move_taken(&startpos, &b); });

    ASSERT_EQ(startpos.moves.size(), 2);

    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[0]),   "h8f7");
    EXPECT_EQ(find_move_taken(&startpos, &startpos.moves[1]),   "h8g6");
}

