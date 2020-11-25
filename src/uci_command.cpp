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

/*
 *  find_move_taken takes two positions and attempts to find the move that was taken to get from
 *  'initial' to 'next' and return this value as a string. e.g. "a2a4". It does no validation of
 *  whether the move taken was legal or not and does not guarantee that a move between the two
 *  positions is possible.
 */
string find_move_taken(Position* initial, Position* next) {

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
            if ((initial_rook xor next_rook) bitand square_bit(0)) {
                return "e1c1";
            }
            else {
                return "e1g1";
            }
        }
        else {
            if ((initial_rook xor next_rook) bitand square_bit(63)) {
                return "e8g8";
            }
            else {
                return "e8c8";
            }
        }
    }

    bitboard initial_pieces = (white_turn) ? initial->maps[w_pieces] : initial->maps[b_pieces];
    bitboard next_pieces = (white_turn) ? next->maps[w_pieces] : next->maps[b_pieces];

    // Normal moves will be set here. (i.e. not castling/promotion)
    bitboard moved_bits = initial_pieces xor next_pieces;
    std::string src = bit_to_square_arr[lsb_unsafe(moved_bits bitand initial_pieces)];
    std::string dest = bit_to_square_arr[lsb_unsafe(moved_bits bitand next_pieces)];
    int dest_square = lsb_unsafe(moved_bits bitand next_pieces);

    // Begin chec 
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
        bitboard square = square_bit(dest_square);
        if (white_turn) {
            if (square bitand next->maps[w_queen])  { dest += "Q"; }
            else if (square bitand next->maps[w_bishop]) { dest += "B"; }
            else if (square bitand next->maps[w_knight]) { dest += "N"; }
            else if (square bitand next->maps[w_rook])   { dest += "R"; }
        }
        else {
            if (square bitand next->maps[b_queen])  { dest += "q"; }
            else if (square bitand next->maps[b_bishop]) { dest += "b"; }
            else if (square bitand next->maps[b_knight]) { dest += "n"; }
            else if (square bitand next->maps[b_rook])   { dest += "r"; }
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
            // std::accumulate builds fen string from vector<string> using lambda that concatenate strings with ' ' between them.
            auto space_fold = [](const std::string& a, const std::string& b) { return a + ' ' + b; };
            std::string fen = std::accumulate(command_list.begin() + 2, command_list.begin() + 7, std::string(command_list[1]), space_fold);

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
                info.wtime = std::stoi(*(++elem));

            }
            else if (*elem == "btime") {
                info.btime = std::stoi(*(++elem));
            }
            else if (*elem == "winc") {
                info.winc = std::stoi(*(++elem));
            }
            else if (*elem == "binc") {
                info.binc = std::stoi(*(++elem));
            }
            else if (*elem == "movestogo") {
                info.movestogo = std::stoi(*(++elem));
            }
            else if (*elem == "depth") {
                info.depth = std::stoi(*(++elem));
            }
            else if (*elem == "nodes") {
                info.nodes = std::stoi(*(++elem));
            }
            else if (*elem == "mate") {
                info.mate = std::stoi(*(++elem));
            }
            else if (*elem == "movetime") {
                info.movetime = std::stoi(*(++elem));
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
