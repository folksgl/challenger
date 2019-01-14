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
    int flag = 1;     // TEMPORARY until chess logic in place.

    // Get command from stdin and process>
    while (getline(cin, uci_token)) 
    {
        // Output name and author, followed by "uciok".
        if (uci_token == "uci") {
            cout << "id name Challenger" << endl;
            cout << "id author folksgl" << endl;
            cout << "uciok" << endl;
        }
        // Turns on/off debugging.
        else if (uci_token.substr(0,6) == "debug") {
            if (uci_token == "debug on") {
                G_debug = true;
            }
            else if (uci_token == "debug off") {
                G_debug = false;
            }
        }
        // Signals the engine is ready to proceed with the next command.
        else if (uci_token == "isready") {
            cout << "readyok" << endl;
        }
        else if (uci_token.substr(0,9) == "setoption") {
            //TODO
            //No options yet
        }
        else if (uci_token == "ucinewgame") {
            //TODO
            // Not implemented yet
        }
        // Set up the position given.
        else if (uci_token.substr(0,8) == "position") {
            // Convert uci_token into char array.
            char * command = new char [uci_token.length()+1];
            strcpy (command, uci_token.c_str());

            // Tokenize command on spaces. First token is the "position command"
            char *token = strtok(command, " "); 

            // Disregard the "position" token and get the fen string.
            token = strtok(NULL, " "); 
            string startpos = "startpos";

            // Check for bad (empty) position command.
            if (token == NULL) {
                continue;
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

            // Handle any moves passed after the fen string.
            token = strtok(NULL, " "); 
            if (token == NULL ) {
                continue;
            }
            if (strncmp(token, "moves", 6) == 0) {
                token = strtok(NULL, " "); 
                while (token != NULL) 
                { 
                    game_move(token);
                    token = strtok(NULL, " "); 
                } 
            }
        }
        else if (uci_token.substr(0,2) == "go") {
            //TODO
            cout << "bestmove " << char(105-flag) << "7" << char(105-flag) << "5" << endl;
            flag++;
        }
        else if (uci_token == "stop") {
            //TODO
            // Not implemented yet
        }
        else if (uci_token == "ponderhit") {
            //TODO
            // Not implemented yet
        }
        else if (uci_token == "quit") {
            exit(0);
        }
        // Default action is to do nothing and ignore invalid commands.
    } 
}
