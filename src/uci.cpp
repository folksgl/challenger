#include <set>
#include <regex>
#include "uci.hpp"
#include "game_variables.hpp"
#include "uci_command.hpp"

using namespace std;

void read_commands(std::istream& is) {

    std::string input_string;
    while (std::getline(is, input_string)) {
        try {
            UCICommand command = UCICommand(input_string);
            command_queue.push(command);

            // Exit the thread function on "quit" commands. Allows main thread to join command producer.
            if (command.is_quit_command()) {
                return;
            }
        }
        catch (std::invalid_argument &ia) {
            continue; // Just ignore bad command inputs and read the next line
        }
    }
}

/*
 *  process_commands reads in input from a UCICommandQueue and
 *  processes the instructions given to manipulate game progression.
 */
void process_commands() {

    std::string command; // The first token of uci_input that should be a uci command

    while (true) {
        UCICommand command = command_queue.pop();
        if (command.is_quit_command()) {
            return;
        }
        command.execute();
    } 
}
