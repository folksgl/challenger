#include "../src/game_variables.h"
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

bool G_debug;
Position* G_game_position;
SliderAttacks slider_attacks;
unsigned long long positions_generated;

void generate_moves_to_depth(Position* pos, int depth) {
    if (!depth) {
        positions_generated++;
        return;
    }
    else {
        pos->generate_moves();
        for (auto move : pos->moves) {
            generate_moves_to_depth(&move, depth-1);
        }
       //positions_generated++;
    }
}

void run_average_for_depth(int depth) {

    unsigned long long count = 0;

    for (int i = 0; i < 10; i++) {
        // Reset position to default starting position
        G_game_position = new Position();

        auto start = steady_clock::now(); // Start timing.

        generate_moves_to_depth(G_game_position, depth);

        auto end = steady_clock::now();   // End timing.
        auto diff = end - start;          // Duration of execution

        count += duration <double, milli> (diff).count(); // Running sum of all 10 execution times.
    }
    // Get the average of the 10 runs of the code.
    count /= 10;
    // Number of positions generated per run.
    positions_generated /= 10;

    cout << "Depth_to_" << setw(2) << left << depth << " average: " << setw(20) << right << count << " ms. Positions generated: " << positions_generated << endl;
    positions_generated = 0;
}

int main()
{
    G_debug = false;
    positions_generated = 0;
    slider_attacks.Initialize();

    run_average_for_depth(1);
    run_average_for_depth(2);
    run_average_for_depth(3);
    run_average_for_depth(4);
    run_average_for_depth(5);

    return 0;
}
