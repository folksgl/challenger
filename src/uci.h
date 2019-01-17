#ifndef UCI_H
#define UCI_H

void process_uci_commands();

void process_uci_signal();

void process_debug_signal(std::string uci_token);

void process_setoption_signal(std::string uci_token);

void process_position_signal(std::string uci_token);

void process_go_signal(std::string uci_token);

void process_stop_signal();

void process_ponderhit_signal();

#endif
