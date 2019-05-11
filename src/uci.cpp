#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iterator>
#include <regex>
#include "uci.h"
#include "game_variables.h"
#include "position.h"
#include "search.h"

using namespace std;


/*
 *  process_uci_inputs reads in input from stdin (given by a uci-compatible gui) and
 *  processes the instructions given to manipulate game progression.
 */
void process_uci_inputs(istream& is) {

    string uci_input;   // The current line read from stdin.
    string uci_command; // The first token of uci_input that should be a uci command

    // Get command from stdin and process
    while (getline(is, uci_input)) 
    {
        // Remove all leading, trailing, and double spaces in the input text
        uci_input = std::regex_replace(uci_input, std::regex("^ +| +$|( ) +"), "$1");

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

    // Turn inputs into a vector of strings, split by spaces.
    std::istringstream iss(uci_input);
    vector<string> tokens(istream_iterator<string>{iss}, istream_iterator<string>());

    if (tokens.size() < 2 || tokens[0] != "position") {
        // only "position" was given or position was not the first token
        return;
    }
    // remove "position" token
    tokens.erase(tokens.begin());
    if (tokens[0] == "startpos") {
        G_game_position = new Position();
        tokens.erase(tokens.begin());
    }
    else {
        // Not enough tokens to build a valid fen-string
        if (tokens.size() < 6) { 
            return; 
        }

        string fen = tokens[0] + " " + tokens[1] + " " + tokens[2] + " " +
                     tokens[3] + " " + tokens[4] + " " + tokens[5];

        G_game_position = new Position(fen);

        // Remove fen tokens
        for (int i = 0; i < 6; i++) {
            tokens.erase(tokens.begin());
        }
    }
    if (tokens.size() < 2 || tokens[0] != "moves") {
        // Not enough tokens to have moves + <move> or token was invalid
        return;
    }
    // Clear "moves" token and process remaining moves
    tokens.erase(tokens.begin());
    for (auto tok : tokens) {
        G_game_position->move(tok);
    }
    return;
}

/*
 *  process_go_command handles the "go..." command given by the gui
 */
void process_go_command(std::string uci_input) {

    if (G_game_position == NULL) {
        cout << "ERROR: no position has been given. Ignoring go command." << endl;
    }
    // Convert uci_input into char array.
    char * command = new char [uci_input.length()+1];
    strcpy (command, uci_input.c_str());

    // First token is the "go" command, disregard this and get to the rest of the command.
    char *token = strtok(command, " "); 
    token = strtok(NULL, " "); 

    int depth = 1; // Default to searching to a depth of 25 plys ahead

    while (token != NULL) {
        string tok(token);
        if (tok == "depth") {
            token = strtok(NULL, " ");
            if (token == NULL) {
                break;
            }
            tok = string(token);
            if (tok.find_first_not_of("0123456789") == std::string::npos) {
                depth = stoi(token);
            }
        }
        //else if (tok == "wtime") {

        //}
        //else if (tok == "btime") {

        //}
        token = strtok(NULL, " ");
    }

    delete[] command;

    search(G_game_position, depth);
    if (G_game_position == NULL || G_game_position->moves.empty()) {
        cout << "Fatal error, no moves found." << endl;
    }
    else {
        cout << "bestmove " << G_game_position->moves[0].movestring << endl;
    }

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

