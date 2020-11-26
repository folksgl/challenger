#include "gtest/gtest.h"
#include "../src/position.hpp"
#include "../src/game_variables.hpp"

using namespace std;

/////////////////////////////////////////////////////////////////////////
// Include declaration of globals from src/main.cpp since it won't be  //
// included in compilation of tests.                                   //
bool G_debug;                                                          // 
Position* G_game_position;                                             //
SliderAttacks slider_attacks;                                          //
ThreadSafeQueue<UCICommand> command_queue;                             //
search_info G_info;                                                    //
                                                                       //
/////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
