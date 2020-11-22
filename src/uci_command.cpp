#include <regex>
#include <iostream>
#include <numeric>
#include <set>
#include "uci_command.hpp"
#include "search.hpp"
#include "game_variables.hpp"

/* 
 * is_valid_uci_command checks the given string against one or more regular expressions to validate
 * that the string matches the UCI GUI->Engine command structure found here: http://wbec-ridderkerk.nl/html/UCIProtocol.html
 * 
 * The regular expressions in this function may seem complex, but reviewing the C++ regex specs
 * should help even the newest programmers work through them http://www.cplusplus.com/reference/regex/ECMAScript/
 */
bool is_valid_uci_command(std::string& command) {
    return std::regex_match(command, std::regex("^(uci|isready|ucinewgame|stop|ponderhit|quit)$|^debug (on|off)$"))
        or std::regex_match(command, std::regex("^position (startpos|([rnbqkp12345678RNBQKP]{1,8}/){7}[rnbqkp12345678RNBQKP]{1,8} (w|b) (-|[KQkq]{1,4}) (-|[a-h][1-8]) (\\d)+ (\\d)+)( moves( [a-h][1-8][a-h][1-8][rnbqRNBQ]?)+)?$"))
        or std::regex_match(command, std::regex("^go( ponder| infinite| (wtime|btime|winc|binc|movestogo|depth|nodes|mate|movetime) [\\d]+| searchmoves( [a-h][1-8][a-h][1-8][rnbqRNBQ]?)+)*$"))
        or std::regex_match(command, std::regex("^setoption (?!(value|setoption))[\\w]+( value [\\w]+)?$"));
}

UCICommand::UCICommand(std::string command) {
    // Replace all whitespace with literal space characters then
    // remove all leading, trailing, and double spaces in the input text
    command = std::regex_replace(command, std::regex("[[:s:]]"), " ");
    command = std::regex_replace(command, std::regex("^ +| +$|( ) +"), "$1");
    if (not is_valid_uci_command(command)) {
        throw std::invalid_argument("Bad command string. Command failed validation.");
    }

    // Split space-separated string into vector of strings
    std::istringstream iss(command);
    std::string token;
    while(std::getline(iss, token, ' ')) {
        command_list.push_back(token);
    }
}

bool UCICommand::is_quit_command() {
    return command_list.size() == 1 and command_list[0] == "quit";
}

int string_to_int(std::string num) {
    try {
        return std::stoi(num);
    }
    catch (std::invalid_argument& ia) {
        std::cout << "Invalid string passed to std::stoi during command execution.";
        throw;
    }
}

string find_move_taken(Position* initial, Position* next) {
    std::string src  = "notset";
    std::string dest = "notset";

    bool white_turn = initial->is_white_move;

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
            if ((initial_rook bitand square_bit(0)) and not (next_rook bitand square_bit(0))) {
                dest = "c1";
            }
            else {
                dest = "g1";
            }
        }
        else {
            src = "e8";
            if ((initial_rook bitand square_bit(63)) and not (next_rook bitand square_bit(63))) {
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
        if (initial_pieces bitand square_bit(i)) {
            // Set bit was changed to unset
            if (!(next_pieces bitand square_bit(i))) {
                src = bit_to_square.at(square_bit(i));
            }
        }
        // check unset bits
        else {
            if (next_pieces bitand square_bit(i)) {
                dest_square = i;
                dest = bit_to_square.at(square_bit(i));
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
            if (square_bit(dest_square) bitand next->maps[w_queen])  { dest += "Q"; }
            if (square_bit(dest_square) bitand next->maps[w_bishop]) { dest += "B"; }
            if (square_bit(dest_square) bitand next->maps[w_knight]) { dest += "N"; }
            if (square_bit(dest_square) bitand next->maps[w_rook])   { dest += "R"; }
        }
        else {
            if (square_bit(dest_square) bitand next->maps[b_queen])  { dest += "q"; }
            if (square_bit(dest_square) bitand next->maps[b_bishop]) { dest += "b"; }
            if (square_bit(dest_square) bitand next->maps[b_knight]) { dest += "n"; }
            if (square_bit(dest_square) bitand next->maps[b_rook])   { dest += "r"; }
        }
    }

    return src + dest;
}

void UCICommand::execute() {
    std::string begin_token = command_list[0];
    if (begin_token == "uci") {
        std::cout << "id name Challenger\nid author folksgl\nuciok" << std::endl;
    }
    else if (begin_token == "debug") {
        G_debug = command_list[1] == "on";
    }
    else if (begin_token == "isready") {
        std::cout << "readyok" << endl;
    }
    else if (begin_token == "setoption") {
        return; // Challenger has no options available yet.
    }
    else if (begin_token == "ucinewgame") {
        return; // Nothing is currently required for challenger to search positions from another game.
    }
    else if (begin_token == "position") {
        std::vector<std::string>::iterator begin_moves = command_list.end();
        if (command_list[1] == "startpos") {
            G_game_position = new Position();

            if (command_list.size() > 2) {
                begin_moves = command_list.begin() + 3;
            }
        }
        else {
            auto space_fold = [](const std::string& a, const std::string& b) { return a + ' ' + b; };
            std::string fen = std::accumulate(command_list.begin() + 1, command_list.begin() + 7, std::string(), space_fold);
            fen.erase(0, 1); // Erase leading ' ' from space_fold_function
            G_game_position = new Position(fen);

            if (command_list.size() > 7) {
                begin_moves = command_list.begin() + 8;
            }
        }

        // This logic all needs to be moved to INSIDE the .move function of a Position object
        for (auto it = begin_moves; it != command_list.end(); it++) {
            std::string tok = *it;
            if (tok.length() == 5) {
                G_game_position->move_pawn_promotion(tok);
            }
            else if (tok.length() == 4) {
                int start_square = get_square_num(tok[0], tok[1]);
                int dest_square = get_square_num(tok[2], tok[3]);
                int moving_piece = G_game_position->get_moving_piece(start_square);
                if (moving_piece == w_pawn) {
                    if (start_square + 16 == dest_square) {
                        G_game_position->move_pawn_double_forward(tok);
                    }
                    else {
                        G_game_position->move(tok, moving_piece);
                    }
                }
                else if (moving_piece == b_pawn) {
                    if (start_square - 16 == dest_square) {
                        G_game_position->move_pawn_double_forward(tok);
                    }
                    else {
                        G_game_position->move(tok, moving_piece);
                    }
                }
                else if (moving_piece == w_king) {
                    if (start_square == 4 and dest_square == 6) {
                        G_game_position->castle(c_w_king);
                    }
                    else if (start_square == 4 and dest_square == 2) {
                        G_game_position->castle(c_w_queen);
                    }
                }
                else if (moving_piece == b_king) {
                    if (start_square == 60 and dest_square == 62) {
                        G_game_position->castle(c_b_king);
                    }
                    else if (start_square == 60 and dest_square == 58) {
                        G_game_position->castle(c_b_queen);
                    }
                }
                else {
                    G_game_position->move(tok, moving_piece);
                }
            }
        }
    }
    else if (begin_token == "go") {
        search_info info;
        auto elem = command_list.begin(); // elem points to first token after "go"
        std::set<std::string> subcommands{"searchmoves", "ponder", "wtime", "btime", "winc", "binc",
                                          "movestogo", "depth", "nodes", "mate", "movetime", "infinite"};
        while (++elem != command_list.end()) {
            if (*elem == "searchmoves") {
                while(++elem != command_list.end() and subcommands.find(*elem) != subcommands.end()) {
                    info.searchmoves.push_back(std::string(*elem));
                }
                elem--;
            }
            else if (*elem == "wtime") {
                info.wtime = string_to_int(*(++elem));
            }
            else if (*elem == "btime") {
                info.btime = string_to_int(*(++elem));
            }
            else if (*elem == "winc") {
                info.winc = string_to_int(*(++elem));
            }
            else if (*elem == "binc") {
                info.binc = string_to_int(*(++elem));
            }
            else if (*elem == "movestogo") {
                info.movestogo = string_to_int(*(++elem));
            }
            else if (*elem == "depth") {
                info.depth = string_to_int(*(++elem));
            }
            else if (*elem == "nodes") {
                info.nodes = string_to_int(*(++elem));
            }
            else if (*elem == "mate") {
                info.mate = string_to_int(*(++elem));
            }
            else if (*elem == "movetime") {
                info.movetime = string_to_int(*(++elem));
            }
            else if (*elem == "infinite") {
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
    }
    else if (begin_token == "ponderhit") {
        //Nothing to do yet
    }
    else if (begin_token == "stop") {
        //Nothing to do yet
    }
}
