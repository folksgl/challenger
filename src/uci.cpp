#include <string>
#include "uci.hpp"
#include "uci_command.hpp"
#include "game_variables.hpp"

/*
 *  read_commands is the "producer" in the producer/consumer pattern for adding
 *  and removing UCICommand objects to the shared command_queue. It will read
 *  commands from the input stream and push new commands to the queue.
 */
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
            continue;  // Just ignore bad command inputs and read the next line
        }
    }
}

/*
 *  process_commands is the "consumer" in the producer/consumer pattern for adding
 *  and removing UCICommand objects to the shared command_queue. It will remove
 *  commands from the queue modify the game accordingly.
 */
void process_commands() {
    while (true) {
        UCICommand command = command_queue.pop();
        if (command.is_quit_command()) {
            return;
        }
        command.execute();
    }
}
