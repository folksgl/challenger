#ifndef MOVEGEN
#define MOVEGEN

#include <chrono>
#include <iomanip>
#include "../src/game_variables.h"

typedef unsigned long long ull;

const ull correct_perft[14] = { 
                                1, 
                                20, 
                                400, 
                                8902, 
                                197281, 
                                4865609, 
                                119060324, 
                                3195901860, 
                                84998978956, 
                                2439530234167, 
                                69352859712417, 
                                2097651003696806, 
                                62854969236701747, 
                                1981066775000396239,
                              };

void generate_moves_to_depth(Position* pos, int depth);

void move_generation_perft(int depth);

#endif
