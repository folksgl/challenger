#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "./uci.h"
#include "./game_variables.h"
#include "./position.h"

using namespace std;

#define start_pos "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

void process_uci_inputs() {

    string uci_input; // The current UCI command read from stdin.
    string uci_command;

    // Get command from stdin and process>
    while (getline(cin, uci_input)) 
    {
        uci_command = uci_input.substr(0, uci_input.find_first_of(" "));

        // Output name and author, followed by "uciok".
        if (uci_command == "uci") {
            process_uci_command();
        }
        // Turns on/off debugging.
        else if (uci_command == "debug") {
            process_debug_command(uci_input);
        }
        // Signals the engine is ready to proceed with the next command.
        else if (uci_command == "isready") {
            cout << "readyok" << endl;
        }
        else if (uci_command == "setoption") {
            process_setoption_command(uci_input);
        }
        // Set up the position given.
        else if (uci_command == "position") {
            process_position_command(uci_input);
        }
        else if (uci_command == "go") {
            process_go_command(uci_input);
        }
        else if (uci_command == "stop") {
            process_stop_command();
        }
        else if (uci_command == "ponderhit") {
            process_ponderhit_command();
        }
        else if (uci_command == "quit") {
            exit(0);
        }
        // Default action is to do nothing and ignore invalid commands.
    } 
}

void process_uci_command() {
    cout << "id name Challenger\n"
            "id author folksgl\n"
            "uciok" << endl;
}

void process_debug_command(std::string uci_input) {
    if (uci_input == "debug on") {
        G_debug = true;
    }
    else if (uci_input == "debug off") {
        G_debug = false;
    }

    return;
}

void process_setoption_command(std::string uci_input) {
    //TODO
    //No options yet
    return;
}

void process_position_command(std::string uci_input) {
    // Convert uci_input into char array.
    char * command = new char [uci_input.length()+1];
    strcpy (command, uci_input.c_str());

    // First token is the "position command"
    char *token = strtok(command, " "); 

    // Disregard the "position" token and get the fen string.
    token = strtok(NULL, " "); 
    string startpos = "startpos";

    // Check for bad (empty) position command.
    if (token == NULL) {
        return;
    }

    // If the "startpos" position is given, use the starting position.
    if (startpos.compare(token) == 0) {
        G_game_position = setup_fen(start_pos);
    }
    else {
        string uci_fen = token;
        for (int i = 0; i < 5; i++) {
            token = strtok(NULL, " ");
            uci_fen += ' ';
            uci_fen += token;
        }
        G_game_position = setup_fen(uci_fen);
    }

    // Reset the command string to the full command.
    strcpy (command, uci_input.c_str());
    token = strtok(command, " ");
    cout << "The value after reset is: " << token << endl;

    while (token != NULL) 
    {
        if (strncmp(token, "moves", 6) == 0) {
            cout << "Moves was reached" << endl;
            token = strtok(NULL, " "); 
            while (token != NULL) {
                cout << "The token after moves " << token << endl;
                game_move(token);
                token = strtok(NULL, " "); 
            }
            break;
        }
        token = strtok(NULL, " ");
    } 

    return;
}

void process_go_command(std::string uci_input) {
    //TODO
    //cout << "bestmove " << char(105-flag) << "7" << char(105-flag) << "5" << endl;
    return;
}

void process_stop_command() {

    return;
}

void process_ponderhit_command() {

    return;
}

