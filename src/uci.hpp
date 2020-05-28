#ifndef UCI_H
#define UCI_H

#include "position.hpp"
#include "game_variables.hpp"
#include "common.hpp"
#include "search.hpp"
#include "uci_command_queue.hpp"

using namespace std;

void read_commands(std::istream& is);

void process_commands();

void process_uci_command();

void process_debug_command(command_iter begin, command_iter end);

void process_setoption_command(command_iter begin, command_iter end);

void process_position_command(command_iter begin, command_iter end);

void process_go_command(command_iter begin, command_iter end);

std::string find_move_taken(Position* initial, Position* next);

void process_stop_command();

void process_ponderhit_command();

bool is_go_subcommand(std::string command);

#endif
