#ifndef SEARCHPFT
#define SEARCHPFT

#include <chrono>
#include <iomanip>
#include "../src/game_variables.hpp"

void search_to_depth(Position* pos, int depth);

void search_perft(int depth);

#endif
