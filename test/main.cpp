#include "gtest/gtest.h"

#include "../src/position.h"
#include "../src/game_variables.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////
// Include declaration of globals from src/main.cpp since it won't be  //
// included in compilation of tests.                                   //
bool G_debug;                                                          // 
position G_game_position;                                              //
                                                                       //
/////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
