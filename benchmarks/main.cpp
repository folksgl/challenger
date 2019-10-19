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

int main()
{
    G_debug = false;
    positions_generated = 0;
    slider_attacks.Initialize();

    cout << endl << endl << endl;
    cout << "Starting position" << endl;

    move_generation_perft(1);
    move_generation_perft(2);
    move_generation_perft(3);
    move_generation_perft(4);
    move_generation_perft(5);
    move_generation_perft(6);
    //move_generation_perft(7); Takes too long to execute

    cout << endl;

    search_perft(1);
    search_perft(2);
    search_perft(3);
    search_perft(4);
    search_perft(5);
    search_perft(6);
    search_perft(7);

    cout << endl;

    cout << "Position 2" << endl;
    move_generation_perft_from_position_2(1);
    move_generation_perft_from_position_2(2);
    move_generation_perft_from_position_2(3);
    cout << endl;

    cout << "Position 3" << endl;
    move_generation_perft_from_position_3(1);
    move_generation_perft_from_position_3(2);
    move_generation_perft_from_position_3(3);
    cout << endl;

    cout << "Position 4" << endl;
    move_generation_perft_from_position_4(1);
    move_generation_perft_from_position_4(2);
    move_generation_perft_from_position_4(3);
    cout << endl;

    cout << "Position 5" << endl;
    move_generation_perft_from_position_5(1);
    move_generation_perft_from_position_5(2);
    move_generation_perft_from_position_5(3);
    cout << endl;

    cout << "Position 6" << endl;
    move_generation_perft_from_position_6(1);
    move_generation_perft_from_position_6(2);
    move_generation_perft_from_position_6(3);
    cout << endl;

    return 0;
}
