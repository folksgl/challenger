#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "./uci.h"
#include "./game_variables.h"
#include "./position.h"

using namespace std;

#define start_pos "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

void process_uci_commands() {

    string uci_token; // The current UCI command read from stdin.
    string uci_signal;

    // Get command from stdin and process>
    while (getline(cin, uci_token)) 
    {
        uci_signal = uci_token.substr(0, uci_token.find_first_of(" "));

        // Output name and author, followed by "uciok".
        if (uci_signal == "uci") {
            process_uci_signal();
        }
        // Turns on/off debugging.
        else if (uci_signal == "debug") {
            process_debug_signal(uci_token);
        }
        // Signals the engine is ready to proceed with the next command.
        else if (uci_signal == "isready") {
            cout << "readyok" << endl;
        }
        else if (uci_signal == "setoption") {
            process_setoption_signal(uci_token);
        }
        // Set up the position given.
        else if (uci_signal == "position") {
            process_position_signal(uci_token);
        }
        else if (uci_signal == "go") {
            process_go_signal(uci_token);
        }
        else if (uci_signal == "stop") {
            process_stop_signal();
        }
        else if (uci_signal == "ponderhit") {
            process_ponderhit_signal();
        }
        else if (uci_signal == "quit") {
            exit(0);
        }
        // Default action is to do nothing and ignore invalid commands.
    } 
}

void process_uci_signal() {
    cout << "id name Challenger" << endl;
    cout << "id author folksgl" << endl;
    cout << "uciok" << endl;
}

void process_debug_signal(std::string uci_token) {
    if (uci_token == "debug on") {
        G_debug = true;
    }
    else if (uci_token == "debug off") {
        G_debug = false;
    }

    return;
}

void process_setoption_signal(std::string uci_token) {
    //TODO
    //No options yet
    return;
}

void process_position_signal(std::string uci_token) {
    // Convert uci_token into char array.
    char * command = new char [uci_token.length()+1];
    strcpy (command, uci_token.c_str());

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
    strcpy (command, uci_token.c_str());
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

void process_go_signal(std::string uci_token) {
    //TODO
    //cout << "bestmove " << char(105-flag) << "7" << char(105-flag) << "5" << endl;
    return;
}

void process_stop_signal() {

    return;
}

void process_ponderhit_signal() {

    return;
}

