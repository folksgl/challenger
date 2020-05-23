#include "search_benchmark.hpp"
#include "move_generation_benchmark.hpp"
#include <string>
#include "../src/search.hpp"

extern unsigned long long positions_searched;

using namespace std;
using namespace chrono;

void search_to_depth(Position* pos, int depth) {
    return;
}

void search_perft(int depth) {

    G_game_position = new Position();

    auto start = steady_clock::now(); // Start timing.

    search(G_game_position, depth);

    auto end = steady_clock::now();   // End timing.
    auto diff = end - start;          // Duration of execution

    unsigned long long positions_possible = correct_perft[depth];
    double ratio = ((double)positions_searched / positions_possible);
    double efficiency = 100 - (ratio * 100);

    cout << "Search(" << setw(2) << right << depth << ") searched: " << setw(15) << right << positions_searched << " positions. " << setw(2) << left << efficiency << "% efficiency." << endl;
    return;
}
