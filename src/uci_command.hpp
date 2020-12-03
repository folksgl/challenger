#ifndef SRC_UCI_COMMAND_HPP_
#define SRC_UCI_COMMAND_HPP_

#include <string>
#include <vector>
#include <iterator>
#include <exception>
#include "position.hpp"

class UCICommand {
 private:
    std::vector<std::string> command_list;
 public:
    explicit UCICommand(std::string command);

    std::vector<std::string>::iterator begin() { return command_list.begin(); }
    std::vector<std::string>::iterator end() { return command_list.end(); }
    std::vector<std::string>::const_iterator begin() const { return command_list.begin(); }
    std::vector<std::string>::const_iterator end() const { return command_list.end(); }
    std::vector<std::string>::const_iterator cbegin() const { return command_list.cbegin(); }
    std::vector<std::string>::const_iterator cend() const { return command_list.cend(); }

    std::string& operator[](int index) {
        return command_list[index];
    }

    bool is_quit_command();
    void execute();
};

std::string find_move_taken(Position* initial, Position* next);
#endif  // SRC_UCI_COMMAND_HPP_
