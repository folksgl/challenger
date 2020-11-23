#ifndef UCI_H
#define UCI_H

#include "position.hpp"
#include "game_variables.hpp"
#include "common.hpp"
#include "search.hpp"
#include "thread_safe_queue.hpp"

using namespace std;

void read_commands(std::istream& is);

void process_commands();

#endif
