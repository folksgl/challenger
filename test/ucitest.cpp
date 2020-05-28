#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/uci.hpp"
#include "../src/game_variables.hpp"

using namespace std;
using ::testing::MatchesRegex;

std::string process_with_capture() {
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    process_commands();

    std::cout.rdbuf(sbuf);
    return buffer.str();
}

TEST (process_command, debug_on) { 
    std::vector<string> commands = {"debug", "on"};
    process_debug_command(commands.begin(), commands.end());

    ASSERT_TRUE(G_debug);
}

TEST (process_command, debug_off) { 
    std::vector<string> commands = {"debug", "off"};
    process_debug_command(commands.begin(), commands.end());

    ASSERT_FALSE(G_debug);
}

TEST (process_command, position_startpos) { 
    std::vector<string> commands = {"position", "startpos"};
    process_position_command(commands.begin(), commands.end());

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_pawns_forward) { 
    std::vector<string> commands = {"position", "startpos", "moves", "a2a4", "a7a5", "b2b4",
                                    "b7b5", "c2c4", "c7c5", "d2d4", "d7d5", "e2e4", "e7e5",
                                    "f2f4", "f7f5", "g2g4", "g7g5", "h2h4", "h7h5"};
    process_position_command(commands.begin(), commands.end());
    
    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_startpos_as_fen) { 
    std::vector<string> commands = {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "w",
                                    "KQkq", "-", "0", "1"};
    process_position_command(commands.begin(), commands.end());

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_pawns_forward_as_fen) { 
    std::vector<string> commands = {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "w",
                                    "KQkq", "-", "0", "1", "moves", "a2a4", "a7a5", "b2b4", "b7b5",
                                    "c2c4", "c7c5", "d2d4", "d7d5", "e2e4", "e7e5", "f2f4", "f7f5",
                                    "g2g4", "g7g5", "h2h4", "h7h5"};
    process_position_command(commands.begin(), commands.end());

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_commands, quit) { 
    std::vector<string> commands = {"quit"};
    command_queue.push(commands);
    process_commands();

    ASSERT_TRUE(true);
}

TEST (process_commands, uci_quit) { 
    std::vector<string> command1 = {"uci"};
    std::vector<string> command2 = {"quit"};

    command_queue.push(command1);
    command_queue.push(command2);

    std::string output = process_with_capture();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_commands, debug_off_quit) { 
    std::vector<string> command1 = {"debug", "off"};
    std::vector<string> command2 = {"quit"};

    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    ASSERT_FALSE(G_debug);
}

TEST (process_commands, isready_quit) { 
    std::vector<string> command1 = {"isready"};
    std::vector<string> command2 = {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    std::string output = process_with_capture();
    ASSERT_EQ (output, "readyok\n");
}

TEST (process_commands, go_quit_startpos) { 
    std::vector<string> command1 = {"position", "startpos"};
    std::vector<string> command2 = {"go"};
    std::vector<string> command3 = {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);
    command_queue.push(command3);

    std::string output = process_with_capture();

    EXPECT_THAT(output, MatchesRegex("^bestmove\\s\\w\\w\\w\\w\\w?\\s$"));
}

TEST (process_commands, go_quit_nullpos) { 
    std::vector<string> command1 = {"position", "8/8/8/8/8/8/8/8", "w", "-", "-", "0", "1"};
    std::vector<string> command2 = {"go", "depth", "1"};
    std::vector<string> command3 = {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);
    command_queue.push(command3);

    std::string output = process_with_capture();
    EXPECT_EQ(output, "Fatal error, no moves found.\n");
}

TEST (process_commands, bad_debug_command) { 
    std::vector<string> command1 = {"debug"};
    std::vector<string> command2 = {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();
    EXPECT_FALSE(G_debug);
}

TEST (process_commands, w_pawn_promotion) { 
    std::vector<string> command1 = {"position", "2bqk1nr/Ppp2ppp/4p3/2Np1b2/2nP1B2/4P3/PPP2P1P/RNBQK2R", "w", "-", "-", "0", "1", "moves", "a7a8Q"};
    std::vector<string> command2 = {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();
    EXPECT_FALSE(G_debug);
}

TEST (read_commands, three_valid) { 
    std::istringstream iss("position 8/8/8/8/8/8/8/8 w - - 0 1\ngo depth 1\nquit");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 3);

    std::vector<std::string> command1 {"position", "8/8/8/8/8/8/8/8", "w", "-", "-", "0", "1"};
    EXPECT_EQ(command_queue.pop(), command1);

    std::vector<std::string> command2 {"go", "depth", "1"};
    EXPECT_EQ(command_queue.pop(), command2);

    std::vector<std::string> command3 {"quit"};
    EXPECT_EQ(command_queue.pop(), command3);
}

TEST (read_commands, two_valid) { 
    std::istringstream iss("position 8/8/8/8/8/8/8/8 w - - 0 1\ngo depth 1\nnotvalid hello world");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 2);

    std::vector<std::string> command1 {"position", "8/8/8/8/8/8/8/8", "w", "-", "-", "0", "1"};
    EXPECT_EQ(command_queue.pop(), command1);

    std::vector<std::string> command2 {"go", "depth", "1"};
    EXPECT_EQ(command_queue.pop(), command2);
}

TEST (read_commands, none_valid) { 
    std::istringstream iss("hello position 8/8/8/8/8/8/8/8 w - - 0 1\nworld go depth 1\nnotvalid hello world");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 0);
}

TEST (read_commands, empty_blank) { 
    std::istringstream iss("     \n\n");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 0);
}

TEST (read_commands, bad_debug_command) { 
    std::istringstream iss("     debug");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 1);

    std::vector<std::string> command1 {"debug"};
    EXPECT_EQ(command_queue.pop(), command1);
    EXPECT_EQ(G_debug, false);
}

TEST (is_go_subcommand, True) { 
    EXPECT_TRUE(is_go_subcommand("searchmoves"));
    EXPECT_TRUE(is_go_subcommand("ponder"));
    EXPECT_TRUE(is_go_subcommand("wtime"));
    EXPECT_TRUE(is_go_subcommand("btime"));
    EXPECT_TRUE(is_go_subcommand("winc"));
    EXPECT_TRUE(is_go_subcommand("binc"));
    EXPECT_TRUE(is_go_subcommand("movestogo"));
    EXPECT_TRUE(is_go_subcommand("depth"));
    EXPECT_TRUE(is_go_subcommand("nodes"));
    EXPECT_TRUE(is_go_subcommand("mate"));
    EXPECT_TRUE(is_go_subcommand("movetime"));
    EXPECT_TRUE(is_go_subcommand("infinite"));
}

TEST (is_go_subcommand, False) { 
    EXPECT_FALSE(is_go_subcommand("not"));
    EXPECT_FALSE(is_go_subcommand("subcommands"));
}

TEST (process_position, pawn_single_forward_white) { 
    std::vector<std::string> command1 {"position", "startpos", "moves", "a2a3"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/P7/1PPPPPPP/RNBQKBNR b KQkq - 0 1");
}

TEST (process_position, pawn_single_forward_black) { 
    std::vector<std::string> command1 {"position", "startpos", "moves", "a2a3", "a7a6"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/1ppppppp/p7/8/8/P7/1PPPPPPP/RNBQKBNR w KQkq - 0 2");
}

TEST (process_position, white_castle_kingside) { 
    std::vector<std::string> command1 {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQK2R", "w", "KQkq", "-", "0", "1", "moves", "e1g1"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQ1RK1 b kq - 0 1");
}

TEST (process_position, black_castle_kingside) { 
    std::vector<std::string> command1 {"position", "rnbqk2r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "b", "KQkq", "-", "0", "1", "moves", "e8g8"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbq1rk1/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 2");
}

TEST (process_position, white_castle_queenside) { 
    std::vector<std::string> command1 {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/R3KBNR", "w", "KQkq", "-", "0", "1", "moves", "e1c1"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/2KR1BNR b kq - 0 1");
}

TEST (process_position, black_castle_queenside) { 
    std::vector<std::string> command1 {"position", "r3kbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "b", "KQkq", "-", "0", "1", "moves", "e8c8"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "2kr1bnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 2");
}

TEST (process_position, white_knight) { 
    std::vector<std::string> command1 {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "w", "KQkq", "-", "0", "1", "moves", "g1f3"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq - 1 1");
}

TEST (process_position, black_knight) { 
    std::vector<std::string> command1 {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "b", "KQkq", "-", "0", "1", "moves", "g8f6"};
    std::vector<std::string> command2 {"quit"};
    command_queue.push(command1);
    command_queue.push(command2);

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkb1r/pppppppp/5n2/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 1 2");
}

