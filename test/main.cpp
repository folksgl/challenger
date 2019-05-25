#include "gtest/gtest.h"
#include "../src/position.h"
#include "../src/game_variables.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////
// Include declaration of globals from src/main.cpp since it won't be  //
// included in compilation of tests.                                   //
bool G_debug;                                                          // 
Position* G_game_position;                                              //
SliderAttacks slider_attacks;
Zobrist zobrist;
                                                                       //
/////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
    slider_attacks.Initialize();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
