#include "move_generation_benchmark.h"
#include <string>

using namespace std;
using namespace chrono;

extern unsigned long long positions_generated;

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


void move_generation_perft(int depth) {

    unsigned long long count = 0;

    for (int i = 0; i < 20; i++) {
        // Reset position to default starting position
        G_game_position = new Position();

        auto start = steady_clock::now(); // Start timing.

        generate_moves_to_depth(G_game_position, depth);

        auto end = steady_clock::now();   // End timing.
        auto diff = end - start;          // Duration of execution

        count += duration <double, micro> (diff).count(); // Running sum of all 10 execution times.
    }
    // Get the average of the 10 runs of the code.
    count /= 10;
    // Number of positions generated per run.
    positions_generated /= 10;

    string label = "";
    if (positions_generated != correct_perft[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " average: " << setw(10) << right << count << " µs. Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

