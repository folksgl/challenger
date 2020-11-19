#include <set>
#include <regex>
#include "uci_command.hpp"

UCICommand::UCICommand(std::string command) {
    // Remove all leading, trailing, and double spaces in the input text
    command = std::regex_replace(command, std::regex("^ +| +$|( ) +"), "$1");

    // Split space-separated string into vector of strings
    std::istringstream iss(command);
    std::string token;
    while(std::getline(iss, token, ' ')) {
        command_list.push_back(token);
    }

    if (command_list.empty()) {
        throw std::invalid_argument("Bad command string given for UCICommand");
    }

    // Make sure the command is a valid UCI (GUI->Engine) command
    std::set<std::string> command_set { "uci", "debug", "isready", "setoption", "register", "ucinewgame", "position", "go", "stop", "ponderhit", "quit"};
    if (command_set.find(command_list[0]) == command_set.end()) {
        throw std::invalid_argument("Bad command string given for UCICommand");
    }

}

bool UCICommand::is_quit_command() {
    return command_list.size() == 1 and command_list[0] == "quit";
}