#include "../src/position.h"
#include "../src/game_variables.h"
#include <chrono>
#include <iomanip>

using namespace std;

bool G_debug;
Position* G_game_position;
SliderAttacks slider_attacks;

int main()
{
    G_debug = false;

    auto start = chrono::steady_clock::now();
    slider_attacks.Initialize();


    auto end = chrono::steady_clock::now();

    auto diff = end - start;

    cout << "Test1: " << setw(20) << right << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << "Test2: " << setw(20) << right << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << "Test3: " << setw(20) << right << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}
