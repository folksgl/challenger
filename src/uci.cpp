#include <set>
#include <regex>
#include "uci.hpp"
#include "game_variables.hpp"

using namespace std;

void read_commands() {
    std::set<std::string> command_set { "uci", "debug", "isready", "setoption", "register", "ucinewgame", "position", "go", "stop", "ponderhit", "quit"};

    std::string input_string;
    while (std::getline(std::cin, input_string)) {
        // Remove all leading, trailing, and double spaces in the input text
        input_string = std::regex_replace(input_string, std::regex("^ +| +$|( ) +"), "$1");

        // Split the input string into tokens (delimited by space)
        std::istringstream iss(input_string);
        std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());

        if (results.empty()) {
            continue;
        }

        // Only push commands to the queue that look like valid gui -> engine commands.
        bool contained_uci_command = command_set.find(results[0]) != command_set.end();
        if (contained_uci_command) {
            command_queue.push(results);
        }

        // Exit the thread function on "quit" commands. Allows main thread to join command producer.
        if (results[0] == "quit") {
            return;
        }
    }
}

/*
 *  process_commands reads in input from a UCICommandQueue and
 *  processes the instructions given to manipulate game progression.
 */
void process_commands() {

    std::string uci_command; // The first token of uci_input that should be a uci command

    while (true) {
        // Get command from command_queue
        auto uci_input = command_queue.pop();
        auto begin = uci_input.begin();
        auto end = uci_input.end();

        uci_command = uci_input[0];

        if (uci_command == "uci") {
            process_uci_command();
        }
        else if (uci_command == "debug") {
            process_debug_command(begin, end);
        }
        else if (uci_command == "isready") {
            cout << "readyok" << endl;
        }
        else if (uci_command == "setoption") {
            process_setoption_command(begin, end);
        }
        else if (uci_command == "position") {
            process_position_command(begin, end);
        }
        else if (uci_command == "go") {
            process_go_command(begin, end);
        }
        else if (uci_command == "stop") {
            process_stop_command();
        }
        else if (uci_command == "ponderhit") {
            process_ponderhit_command();
        }
        else if (uci_command == "quit") {
            // return to allow consumer_thread in main to end execution and join.
            return;
        }
        // Default action is to do nothing and ignore invalid commands.
    } 
}

/*
 *  process_uci_command handles the "uci" command given by the gui
 */
void process_uci_command() {
    std::cout << "id name Challenger\n"
            "id author folksgl\n"
            "uciok" << std::endl;
}

/*
 * get_iter_size() returns the std::distance between a begin and end iterator
 */
int get_iter_size(command_iter begin, command_iter end) {
    return std::distance(begin, end);
}

/*
 *  process_debug_command handles the "debug..." command given by the gui
 */
void process_debug_command(command_iter begin, command_iter end) {
    
    int size = get_iter_size(begin, end);
    if (size != 2 or *begin != "debug") {
        return; // Invalid number of tokens for debug command. Do not modify state.
    }

    ++begin;

    if (*begin == "on") {
        G_debug = true;
    }
    else if (*begin == "off") {
        G_debug = false;
    }

    return;
}

/*
 *  process_setoption_command handles the "setoption..." command given by the gui
 */
void process_setoption_command(command_iter begin, command_iter end) {
    //TODO
    //No options yet
    return;
}

/*
 *  process_position_command handles the "position..." command given by the gui
 */
void process_position_command(command_iter begin, command_iter end) {

    int size = get_iter_size(begin, end);

    if (size < 2) {
        // only "position" was given or position was not the first token. Do not modify state.
        return;
    }
    // Disreguard "position" token. Advance to the second token in the sequence
    ++begin;

    if (*begin == "startpos") {
        G_game_position = new Position();
        // Advance to third token in sequence
        if (++begin == end) {
            // Only 2 tokens found. Nothing more to do.
            return;
        }
    }
    else {
        if (size < 7) { // position + fen = 7 tokens minumum
            return; 
        }
        std::string fen = "";

        for (int i = 0; i < 6; i++) {
            fen += *begin + " ";
            ++begin;
        }

        G_game_position = new Position(fen);

        if (begin == end) {
            // Out of tokens, return.
            return;
        }
    }
    if (*begin != "moves") {
        // Token found was invalid for this position in the input command.
        return;
    }
    // Clear "moves" token and process remaining moves
    ++begin;
    int moving_piece, start_square, dest_square;
    for (auto it = begin; it != end; ++it) {
        std::string tok = *it;
        if (tok.length() == 5) {
            G_game_position->move_pawn_promotion(tok);
        }
        else if (tok.length() == 4) {
            start_square = get_square_num(tok[0], tok[1]);
            dest_square = get_square_num(tok[2], tok[3]);
            moving_piece = G_game_position->get_moving_piece(start_square);
            if (moving_piece == w_pawn) {
                if (start_square + 16 == dest_square) {
                    G_game_position->move_pawn_double_forward(tok);
                }
                else {
                    G_game_position->move(tok);
                }
            }
            else if (moving_piece == b_pawn) {
                if (start_square - 16 == dest_square) {
                    G_game_position->move_pawn_double_forward(tok);
                }
                else {
                    G_game_position->move(tok);
                }
            }
            else if (moving_piece == w_king) {
                if (start_square == 4 and dest_square == 6) {
                    G_game_position->castle(c_w_king);
                }
                else if (start_square == 4 and dest_square == 2) {
                    G_game_position->castle(c_w_king);
                }
            }
            else if (moving_piece == b_king) {
                if (start_square == 60 and dest_square == 62) {
                    G_game_position->castle(c_w_king);
                }
                else if (start_square == 60 and dest_square == 58) {
                    G_game_position->castle(c_w_king);
                }
            }
            else {
                G_game_position->move(tok);
            }
        }
        // If the token wasnt 4 or 5 characters in length, then it is invalid and the position is not modified for that token.
    }
    return;
}

/*
 * return the integer representation of the string, or 0 if an integer representation is not found
 */
int get_num_from_string(std::string numstring) {
        return (numstring.find_first_not_of("0123456789") == std::string::npos) ? std::stoi(numstring) : 0;
}

bool is_go_subcommand(std::string command) {
    std::set<std::string> subcommands { "searchmoves", "ponder", "wtime", "btime", "winc", "binc",
                                   "movestogo", "depth", "nodes", "mate", "movetime", "infinite"};
    return subcommands.find(command) != subcommands.end();
}

/*
 *  process_go_command handles the "go..." command given by the gui
 */
void process_go_command(command_iter begin, command_iter end) {

    if (G_game_position == NULL) {
        cout << "ERROR: no position has been given. Ignoring go command." << endl;
    }

    search_info info;

    // "go" command can have multiple sub-commands, each with different length arguments.
    while(++begin != end) {
        std::string sub_command = *begin;

        if (sub_command == "depth") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.depth = get_num_from_string(*(++begin));
        }
        else if (sub_command == "searchmoves") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            do {
                ++begin;
                if (is_go_subcommand(*begin)) {
                    --begin; // Return the begin iter back to just before the subcommand.
                    break;
                }
                info.searchmoves.push_back(*begin);
            }
            while (begin != end);
        }
        else if (sub_command == "ponder") {
            info.ponder = true;
        }
        else if (sub_command == "wtime") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.wtime = get_num_from_string(*(++begin));
        }
        else if (sub_command == "btime") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.btime = get_num_from_string(*(++begin));
        }
        else if (sub_command == "winc") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.winc = get_num_from_string(*(++begin));
        }
        else if (sub_command == "binc") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.binc = get_num_from_string(*(++begin));
        }
        else if (sub_command == "movestogo") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.movestogo = get_num_from_string(*(++begin));
        }
        else if (sub_command == "nodes") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.nodes = get_num_from_string(*(++begin));
        }
        else if (sub_command == "mate") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.mate = get_num_from_string(*(++begin));
        }
        else if (sub_command == "movetime") {
            if (begin == end) { return; } // Sub-command requires additional arguments
            info.movetime = get_num_from_string(*(++begin));
        }
        else if (sub_command == "infinite") {
            info.infinite = true;
        }
    }

    search(G_game_position, info.depth);
    if (G_game_position == NULL) {
        cout << "Fatal error, no game found." << endl;
    }
    else if (G_game_position->moves.empty()) {
        cout << "Fatal error, no moves found." << endl;
    }
    else {
        std::string movestring = find_move_taken(G_game_position, &G_game_position->moves[0]);
        cout << "bestmove " << movestring << endl;
    }

    return;
}

string find_move_taken(Position* initial, Position* next) {
    std::string src  = "notset";
    std::string dest = "notset";

    bool white_turn = initial->is_white_move();

    bitboard initial_king, initial_rook, next_king, next_rook;

    if (white_turn) {
        initial_king = initial->maps[w_king];
        initial_rook = initial->maps[w_rook];
        next_king = next->maps[w_king];
        next_rook = next->maps[w_rook];
    }
    else {
        initial_king = initial->maps[b_king];
        initial_rook = initial->maps[b_rook];
        next_king = next->maps[b_king];
        next_rook = next->maps[b_rook];
    }

    // Castling occured, adjust movestring
    if ((initial_king != next_king) and (initial_rook != next_rook)) {
        if (white_turn) {
            src  = "e1";
            if ((initial_rook bitand squares[0]) and not (next_rook bitand squares[0])) {
                dest = "c1";
            }
            else {
                dest = "g1";
            }
        }
        else {
            src = "e8";
            if ((initial_rook bitand squares[63]) and not (next_rook bitand squares[63])) {
                dest = "g8";
            }
            else {
                dest = "c8";
            }
        }
        return src + dest;
    }

    bitboard initial_pieces = (white_turn) ? initial->maps[w_pieces] : initial->maps[b_pieces];
    bitboard next_pieces = (white_turn) ? next->maps[w_pieces] : next->maps[b_pieces];

    int dest_square = 0;

    // Normal moves will be set here. (i.e. not castling/promotion)
    for (int i = 0; i < 64; i++) {
        // check set bits
        if (initial_pieces bitand squares[i]) {
            // Set bit was changed to unset
            if (!(next_pieces bitand squares[i])) {
                src = bit_to_square.at(squares[i]);
            }
        }
        // check unset bits
        else {
            if (next_pieces bitand squares[i]) {
                dest_square = i;
                dest = bit_to_square.at(squares[i]);
            }
        }
    }

    bitboard initial_pawn = (white_turn) ? initial->maps[w_pawn] : initial->maps[b_pawn];
    bitboard next_pawn = (white_turn) ? next->maps[w_pawn] : next->maps[b_pawn];

    if (white_turn) {
        initial_pawn &= rank_7;
        next_pawn &= rank_7;
    }
    else {
        initial_pawn &= rank_2;
        next_pawn &= rank_2;
    } 

    // Pawn promotion happened, adjust movestring
    if (initial_pawn != next_pawn) {
        if (white_turn) {
            if (squares[dest_square] bitand next->maps[w_queen])  { dest += "Q"; }
            if (squares[dest_square] bitand next->maps[w_bishop]) { dest += "B"; }
            if (squares[dest_square] bitand next->maps[w_knight]) { dest += "N"; }
            if (squares[dest_square] bitand next->maps[w_rook])   { dest += "R"; }
        }
        else {
            if (squares[dest_square] bitand next->maps[b_queen])  { dest += "q"; }
            if (squares[dest_square] bitand next->maps[b_bishop]) { dest += "b"; }
            if (squares[dest_square] bitand next->maps[b_knight]) { dest += "n"; }
            if (squares[dest_square] bitand next->maps[b_rook])   { dest += "r"; }
        }
    }

    return src + dest;
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

