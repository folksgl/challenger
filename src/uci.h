#include <iostream>

#ifndef UCI_H
#define UCI_H

using namespace std;

void process_uci_inputs(istream& is);

void process_uci_command();

void process_debug_command(std::string uci_token);

void process_setoption_command(std::string uci_token);

void process_position_command(std::string uci_token);

void process_go_command(std::string uci_token);

void process_stop_command();

void process_ponderhit_command();

#endif
