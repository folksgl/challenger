#include "gtest/gtest.h"
#include "../src/genmove.h"
#include "../src/uci.h"
#include "../src/common.h"
#include <string>

using namespace std;

TEST(correct_lookup_table, all_64_king_moves) {
    EXPECT_EQ (king_moves[0], 770ULL);
    EXPECT_EQ (king_moves[1], 1797ULL);
    EXPECT_EQ (king_moves[2], 3594ULL);
    EXPECT_EQ (king_moves[3], 7188ULL);
    EXPECT_EQ (king_moves[4], 14376ULL);
    EXPECT_EQ (king_moves[5], 28752ULL);
    EXPECT_EQ (king_moves[6], 57504ULL);
    EXPECT_EQ (king_moves[7], 49216ULL);
    EXPECT_EQ (king_moves[8], 197123ULL);
    EXPECT_EQ (king_moves[9], 460039ULL);
    EXPECT_EQ (king_moves[10], 920078ULL);
    EXPECT_EQ (king_moves[11], 1840156ULL);
    EXPECT_EQ (king_moves[12], 3680312ULL);
    EXPECT_EQ (king_moves[13], 7360624ULL);
    EXPECT_EQ (king_moves[14], 14721248ULL);
    EXPECT_EQ (king_moves[15], 12599488ULL);
    EXPECT_EQ (king_moves[16], 50463488ULL);
    EXPECT_EQ (king_moves[17], 117769984ULL);
    EXPECT_EQ (king_moves[18], 235539968ULL);
    EXPECT_EQ (king_moves[19], 471079936ULL);
    EXPECT_EQ (king_moves[20], 942159872ULL);
    EXPECT_EQ (king_moves[21], 1884319744ULL);
    EXPECT_EQ (king_moves[22], 3768639488ULL);
    EXPECT_EQ (king_moves[23], 3225468928ULL);
    EXPECT_EQ (king_moves[24], 12918652928ULL);
    EXPECT_EQ (king_moves[25], 30149115904ULL);
    EXPECT_EQ (king_moves[26], 60298231808ULL);
    EXPECT_EQ (king_moves[27], 120596463616ULL);
    EXPECT_EQ (king_moves[28], 241192927232ULL);
    EXPECT_EQ (king_moves[29], 482385854464ULL);
    EXPECT_EQ (king_moves[30], 964771708928ULL);
    EXPECT_EQ (king_moves[31], 825720045568ULL);
    EXPECT_EQ (king_moves[32], 3307175149568ULL);
    EXPECT_EQ (king_moves[33], 7718173671424ULL);
    EXPECT_EQ (king_moves[34], 15436347342848ULL);
    EXPECT_EQ (king_moves[35], 30872694685696ULL);
    EXPECT_EQ (king_moves[36], 61745389371392ULL);
    EXPECT_EQ (king_moves[37], 123490778742784ULL);
    EXPECT_EQ (king_moves[38], 246981557485568ULL);
    EXPECT_EQ (king_moves[39], 211384331665408ULL);
    EXPECT_EQ (king_moves[40], 846636838289408ULL);
    EXPECT_EQ (king_moves[41], 1975852459884544ULL);
    EXPECT_EQ (king_moves[42], 3951704919769088ULL);
    EXPECT_EQ (king_moves[43], 7903409839538176ULL);
    EXPECT_EQ (king_moves[44], 15806819679076352ULL);
    EXPECT_EQ (king_moves[45], 31613639358152704ULL);
    EXPECT_EQ (king_moves[46], 63227278716305408ULL);
    EXPECT_EQ (king_moves[47], 54114388906344448ULL);
    EXPECT_EQ (king_moves[48], 216739030602088448ULL);
    EXPECT_EQ (king_moves[49], 505818229730443264ULL);
    EXPECT_EQ (king_moves[50], 1011636459460886528ULL);
    EXPECT_EQ (king_moves[51], 2023272918921773056ULL);
    EXPECT_EQ (king_moves[52], 4046545837843546112ULL);
    EXPECT_EQ (king_moves[53], 8093091675687092224ULL);
    EXPECT_EQ (king_moves[54], 16186183351374184448ULL);
    EXPECT_EQ (king_moves[55], 13853283560024178688ULL);
    EXPECT_EQ (king_moves[56], 144959613005987840ULL);
    EXPECT_EQ (king_moves[57], 362258295026614272ULL);
    EXPECT_EQ (king_moves[58], 724516590053228544ULL);
    EXPECT_EQ (king_moves[59], 1449033180106457088ULL);
    EXPECT_EQ (king_moves[60], 2898066360212914176ULL);
    EXPECT_EQ (king_moves[61], 5796132720425828352ULL);
    EXPECT_EQ (king_moves[62], 11592265440851656704ULL);
    EXPECT_EQ (king_moves[63], 4665729213955833856ULL);
}

