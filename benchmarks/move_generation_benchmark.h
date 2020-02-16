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
                                1981066775000396239
                              };

const ull correct_perft_position_2[7] = { 
                                1, 
                                48, 
                                2039, 
                                97862, 
                                4085603, 
                                193690690, 
                                8031647685
                              };

const ull correct_perft_position_3[9] = { 
                                1, 
                                14, 
                                191,
                                2812, 
                                43238, 
                                674624, 
                                11030083, 
                                178633661, 
                                3009794393
                              };

const ull correct_perft_position_4[7] = { 
                                1, 
                                6, 
                                264,
                                9467, 
                                422333, 
                                15833292, 
                                706045033
                              };

const ull correct_perft_position_5[6] = { 
                                1, 
                                44, 
                                1486,
                                62379, 
                                2103487, 
                                89941194
                              };

const ull correct_perft_position_6[10] = { 
                                1, 
                                46, 
                                2079,
                                89890, 
                                3894594, 
                                164075551,
                                6923051137,
                                287188994746,
                                11923589843526,
                                490154852788714
                              };

void generate_moves_to_depth(Position* pos, int depth);

void move_generation_perft(int depth);

void move_generation_perft_from_position_debug(string fen);

void move_generation_perft_from_position_2(int depth);

void move_generation_perft_from_position_3(int depth);

void move_generation_perft_from_position_4(int depth);

void move_generation_perft_from_position_5(int depth);

void move_generation_perft_from_position_6(int depth);

string fmt(Position* initial, Position* next);

#endif
