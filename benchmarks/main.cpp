#include "../src/game_variables.h"
#include "move_generation_benchmark.h"
#include "search_benchmark.h"

using namespace std;

bool G_debug;
Position* G_game_position;
SliderAttacks slider_attacks;
unsigned long long positions_generated;
unsigned long long positions_searched;

int main()
{
    G_debug = false;
    positions_generated = 0;
    slider_attacks.Initialize();

    move_generation_perft(1);
    move_generation_perft(2);
    move_generation_perft(3);
    move_generation_perft(4);

    cout << endl;

    search_perft(1);
    search_perft(2);
    search_perft(3);
    search_perft(4);
    search_perft(5);
    search_perft(6);
    search_perft(7);

    return 0;
}
