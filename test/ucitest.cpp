#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/uci.hpp"
#include "../src/game_variables.hpp"

using ::testing::MatchesRegex;

std::string process_with_capture() {
    std::stringstream buffer;
    std::streambuf *sbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    process_commands();

    std::cout.rdbuf(sbuf);
    return buffer.str();
}

TEST(process_command, debug_on) {
    UCICommand command("debug on");
    command.execute();

    ASSERT_TRUE(G_debug);
}

TEST(process_command, debug_off) {
    UCICommand command("debug off");
    command.execute();

    ASSERT_FALSE(G_debug);
}

TEST(process_command, position_startpos) {
    UCICommand command("position startpos");
    command.execute();

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ(G_game_position->to_fen_string(), fen);
}

TEST(process_command, position_pawns_forward) {
    UCICommand command("position startpos moves a2a4 a7a5 b2b4 b7b5 c2c4 c7c5 d2d4 d7d5 e2e4 e7e5 f2f4 f7f5 g2g4 g7g5 h2h4 h7h5");
    command.execute();

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    ASSERT_EQ(G_game_position->to_fen_string(), fen);
}

TEST(process_command, position_startpos_as_fen) {
    UCICommand command("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    command.execute();

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ(G_game_position->to_fen_string(), fen);
}

TEST(process_command, position_pawns_forward_as_fen) {
    UCICommand command("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 moves a2a4 a7a5 b2b4 b7b5 c2c4 c7c5 d2d4 d7d5 e2e4 e7e5 f2f4 f7f5 g2g4 g7g5 h2h4 h7h5");
    command.execute();

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    ASSERT_EQ(G_game_position->to_fen_string(), fen);
}

TEST(process_commands, quit) {
    command_queue.push(UCICommand("quit"));
    process_commands();

    ASSERT_TRUE(true);
}

TEST(process_commands, uci_quit) {
    command_queue.push(UCICommand("uci"));
    command_queue.push(UCICommand("quit"));

    std::string output = process_with_capture();

    ASSERT_EQ(output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST(process_commands, debug_off_quit) {
    command_queue.push(UCICommand("debug off"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    ASSERT_FALSE(G_debug);
}

TEST(process_commands, isready_quit) {
    command_queue.push(UCICommand("isready"));
    command_queue.push(UCICommand("quit"));

    std::string output = process_with_capture();
    ASSERT_EQ(output, "readyok\n");
}

TEST(process_commands, go_quit_startpos) {
    command_queue.push(UCICommand("position startpos"));
    command_queue.push(UCICommand("go"));
    command_queue.push(UCICommand("quit"));

    std::string output = process_with_capture();

    EXPECT_THAT(output, MatchesRegex("^bestmove\\s\\w\\w\\w\\w\\w?\\s$"));
}

TEST(process_commands, go_quit_nullpos) {
    command_queue.push(UCICommand("position 8/8/8/8/8/8/8/8 w - - 0 1"));
    command_queue.push(UCICommand("go depth 1"));
    command_queue.push(UCICommand("quit"));

    std::string output = process_with_capture();
    EXPECT_EQ(output, "Fatal error, no moves found.\n");
}

TEST(process_commands, w_pawn_promotion) {
    command_queue.push(UCICommand("position 2bqk1nr/Ppp2ppp/4p3/2Np1b2/2nP1B2/4P3/PPP2P1P/RNBQK2R w - - 0 1 moves a7a8Q"));
    command_queue.push(UCICommand("quit"));

    process_commands();
    EXPECT_FALSE(G_debug);
}

TEST(read_commands, three_valid) {
    std::istringstream iss("position 8/8/8/8/8/8/8/8 w - - 0 1\ngo depth 1\nquit");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 3);

    std::vector<std::string> command1 {"position", "8/8/8/8/8/8/8/8", "w", "-", "-", "0", "1"};
    UCICommand cmdout = command_queue.pop();
    std::vector<std::string> command1out(cmdout.begin(), cmdout.end());
    EXPECT_EQ(command1out, command1);

    std::vector<std::string> command2 {"go", "depth", "1"};
    cmdout = command_queue.pop();
    std::vector<std::string> command2out(cmdout.begin(), cmdout.end());
    EXPECT_EQ(command2out, command2);

    std::vector<std::string> command3 {"quit"};
    cmdout = command_queue.pop();
    std::vector<std::string> command3out(cmdout.begin(), cmdout.end());
    EXPECT_EQ(command3out, command3);
}

TEST(read_commands, two_valid) {
    std::istringstream iss("position 8/8/8/8/8/8/8/8 w - - 0 1\ngo depth 1\nnotvalid hello world");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 2);

    std::vector<std::string> command1 {"position", "8/8/8/8/8/8/8/8", "w", "-", "-", "0", "1"};
    UCICommand cmdout = command_queue.pop();
    std::vector<std::string> command1out(cmdout.begin(), cmdout.end());
    EXPECT_EQ(command1out, command1);

    std::vector<std::string> command2 {"go", "depth", "1"};
    cmdout = command_queue.pop();
    std::vector<std::string> command2out(cmdout.begin(), cmdout.end());
    EXPECT_EQ(command2out, command2);
}

TEST(read_commands, none_valid) {
    std::istringstream iss("hello position 8/8/8/8/8/8/8/8 w - - 0 1\nworld go depth 1\nnotvalid hello world");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 0);
}

TEST(read_commands, empty_blank) {
    std::istringstream iss("     \n\n");
    read_commands(iss);

    EXPECT_EQ(command_queue.size(), 0);
}

TEST(process_position, pawn_single_forward_white) {
    command_queue.push(UCICommand("position startpos moves a2a3"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/P7/1PPPPPPP/RNBQKBNR b KQkq - 0 1");
}

TEST(process_position, pawn_single_forward_black) {
    command_queue.push(UCICommand("position startpos moves a2a3 a7a6"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/1ppppppp/p7/8/8/P7/1PPPPPPP/RNBQKBNR w KQkq - 0 2");
}

TEST(process_position, white_castle_kingside) {
    command_queue.push(UCICommand("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQK2R w KQkq - 0 1 moves e1g1"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQ1RK1 b kq - 0 1");
}

TEST(process_position, black_castle_kingside) {
    command_queue.push(UCICommand("position rnbqk2r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1 moves e8g8"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbq1rk1/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 2");
}

TEST(process_position, white_castle_queenside) {
    command_queue.push(UCICommand("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/R3KBNR w KQkq - 0 1 moves e1c1"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/2KR1BNR b kq - 0 1");
}

TEST(process_position, black_castle_queenside) {
    command_queue.push(UCICommand("position r3kbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1 moves e8c8"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "2kr1bnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQ - 0 2");
}

TEST(process_position, white_knight) {
    command_queue.push(UCICommand("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 moves g1f3"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkbnr/pppppppp/8/8/8/5N2/PPPPPPPP/RNBQKB1R b KQkq - 1 1");
}

TEST(process_position, black_knight) {
    command_queue.push(UCICommand("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1 moves g8f6"));
    command_queue.push(UCICommand("quit"));

    process_commands();

    EXPECT_EQ(G_game_position->to_fen_string(), "rnbqkb1r/pppppppp/5n2/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 1 2");
}
