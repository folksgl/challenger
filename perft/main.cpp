#include <iostream>
#include "../src/game_variables.h"
#include "move_generation_benchmark.h"
#include "search_benchmark.h"

using namespace std;

bool G_debug;
Position* G_game_position;
SliderAttacks slider_attacks;
Zobrist zobrist;

unsigned long long positions_generated;
unsigned long long positions_searched;

int main(int argc, char* argv[])
{
    G_debug = false;
    positions_generated = 0;
    slider_attacks.Initialize();

    string input = argv[1];
    move_generation_perft_from_position_debug(input);


    return 0;
}
