#include "move_generation_benchmark.h"
#include "../src/common.h"
#include <string>

using namespace std;
using namespace chrono;

extern unsigned long long positions_generated;

void generate_moves_to_depth(Position* pos, int depth) {

    pos->generate_moves();

    if (depth == 1) { // If the search depth is zero, count the node.
        positions_generated += pos->moves.size();
        return;
    }
    else {
        for (auto move : pos->moves) {
            generate_moves_to_depth(&move, depth-1);
        }
    }
}


void move_generation_perft(int depth) {

    unsigned long long count = 0;
    positions_generated = 0;

    //for (int i = 0; i < 20; i++) {
        //// Reset position to default starting position
        //G_game_position = new Position();


        //generate_moves_to_depth(G_game_position, depth);

        //auto end = steady_clock::now();   // End timing.
        //auto diff = end - start;          // Duration of execution

        //count += duration <double, micro> (diff).count(); // Running sum of all 10 execution times.
    //}
    //// Get the average of the 10 runs of the code.
    //count /= 10;
    //// Number of positions generated per run.
    //positions_generated /= 20;

    G_game_position = new Position();

    auto start = steady_clock::now(); // Start timing.
    
    generate_moves_to_depth(G_game_position, depth);
    
    auto end = steady_clock::now();   // End timing.
    auto diff = end - start;          // Duration of execution
    
    count = duration <double, micro> (diff).count(); // Running sum of all 10 execution times.
    
    string label = "";
    if (positions_generated != correct_perft[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " average: " << setw(10) << right << count << " µs. Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

void move_generation_perft_from_position_2(int depth) {

    positions_generated = 0;

    // Reset position to default starting position
    G_game_position = new Position("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1");

    generate_moves_to_depth(G_game_position, depth);

    string label = "";
    if (positions_generated != correct_perft_position_2[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft_position_2[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

void move_generation_perft_from_position_3(int depth) {

    positions_generated = 0;

    // Reset position to default starting position
    G_game_position = new Position("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1");

    generate_moves_to_depth(G_game_position, depth);

    string label = "";
    if (positions_generated != correct_perft_position_3[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft_position_3[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

void move_generation_perft_from_position_4(int depth) {

    positions_generated = 0;

    // Reset position to default starting position
    G_game_position = new Position("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1");

    generate_moves_to_depth(G_game_position, depth);

    string label = "";
    if (positions_generated != correct_perft_position_4[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft_position_4[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

void move_generation_perft_from_position_5(int depth) {

    positions_generated = 0;

    // Reset position to default starting position
    G_game_position = new Position("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8");

    generate_moves_to_depth(G_game_position, depth);

    string label = "";
    if (positions_generated != correct_perft_position_5[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft_position_5[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

void move_generation_perft_from_position_6(int depth) {

    positions_generated = 0;

    // Reset position to default starting position
    G_game_position = new Position("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - - 0 10");

    generate_moves_to_depth(G_game_position, depth);

    string label = "";
    if (positions_generated != correct_perft_position_6[depth]) {
        label = " FAILED perft(" + to_string(depth) + ") = " + to_string(correct_perft_position_6[depth]);
    }

    cout << "Depth_to_" << setw(2) << left << depth << " Positions generated: " << setw(15) << left << positions_generated << label << endl;
    positions_generated = 0;
}

