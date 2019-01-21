#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "./uci.h"
#include "./game_variables.h"
#include "./position.h"

using namespace std;

#define start_pos "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

/*
 *  process_uci_inputs reads in input from stdin (given by a uci-compatible gui) and
 *  processes the instructions given to manipulate game progression.
 */
void process_uci_inputs() {

    string uci_input;   // The current line read from stdin.
    string uci_command; // The first token of uci_input that should be a uci command

    // Get command from stdin and process
    while (getline(cin, uci_input)) 
    {
        uci_command = uci_input.substr(0, uci_input.find_first_of(" "));

        if (uci_command == "uci") {
            process_uci_command();
        }
        else if (uci_command == "debug") {
            process_debug_command(uci_input);
        }
        else if (uci_command == "isready") {
            cout << "readyok" << endl;
        }
        else if (uci_command == "setoption") {
            process_setoption_command(uci_input);
        }
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

/*
 *  process_uci_command handles the "uci" command given by the gui
 */
void process_uci_command() {
    cout << "id name Challenger\n"
            "id author folksgl\n"
            "uciok" << endl;
}

/*
 *  process_debug_command handles the "debug..." command given by the gui
 */
void process_debug_command(std::string uci_input) {
    if (uci_input == "debug on") {
        G_debug = true;
    }
    else if (uci_input == "debug off") {
        G_debug = false;
    }

    return;
}

/*
 *  process_setoption_command handles the "setoption..." command given by the gui
 */
void process_setoption_command(std::string uci_input) {
    //TODO
    //No options yet
    return;
}

/*
 *  process_position_command handles the "position..." command given by the gui
 */
void process_position_command(std::string uci_input) {
    // Convert uci_input into char array.
    char * command = new char [uci_input.length()+1];
    strcpy (command, uci_input.c_str());

    // First token is the "position command", disregard this and get to the fen string.
    char *token = strtok(command, " "); 
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
            uci_fen += ' ' + token;
        }
        G_game_position = setup_fen(uci_fen);
    }

    // Reset the command string to the full command.
    strcpy (command, uci_input.c_str());
    token = strtok(command, " ");

    while (token != NULL) 
    {
        if (strncmp(token, "moves", 6) == 0) {
            token = strtok(NULL, " "); 
            while (token != NULL) {
                game_move(token, &G_game_position);
                token = strtok(NULL, " "); 
            }
            break;
        }
        token = strtok(NULL, " ");
    } 

    return;
}

/*
 *  process_go_command handles the "go..." command given by the gui
 */
void process_go_command(std::string uci_input) {
    //TODO
    //cout << "bestmove " << char(105-flag) << "7" << char(105-flag) << "5" << endl;
    return;
}

/*
 *  process_stop_command handles the "stop..." command given by the gui
 */
void process_stop_command() {

    return;
}

/*
 *  process_ponderhit_command handles the "ponderhit..." command given by the gui
 */
void process_ponderhit_command() {

    return;
}

