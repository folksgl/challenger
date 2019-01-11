#include "gtest/gtest.h"

TEST(myfuncTest, PositiveNos) { 
    EXPECT_EQ (18.0, 18.0);
}

TEST (myfuncTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
