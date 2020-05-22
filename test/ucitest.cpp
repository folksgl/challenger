#include "gtest/gtest.h"
#include "../src/uci.hpp"
#include "../src/game_variables.hpp"

using namespace std;
using ::testing::MatchesRegex;

//TEST (process_command, uci) { 
    //testing::internal::CaptureStdout();
    //process_uci_command();
    //std::string output = testing::internal::GetCapturedStdout();

    //ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
//}

//TEST (process_command, debug_on) { 
    //std::vector<string> commands = {"debug", "on"};
    //process_debug_command(commands.begin(), commands.end());

    //ASSERT_TRUE(G_debug);
//}

//TEST (process_command, debug_off) { 
    //std::vector<string> commands = {"debug", "off"};
    //process_debug_command(commands.begin(), commands.end());

    //ASSERT_FALSE(G_debug);
//}

////TEST (process_command, setoption) { 
    ////ASSERT_EQ ();
////}

//TEST (process_command, position_startpos) { 
    //std::vector<string> commands = {"position", "startpos"};
    //process_position_command(commands.begin(), commands.end());

    //string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    //ASSERT_EQ (G_game_position->to_fen_string(), fen);
//}

//TEST (process_command, position_pawns_forward) { 
    //std::vector<string> commands = {"position", "startpos", "moves", "a2a4", "a7a5", "b2b4",
                                    //"b7b5", "c2c4", "c7c5", "d2d4", "d7d5", "e2e4", "e7e5",
                                    //"f2f4", "f7f5", "g2g4", "g7g5", "h2h4", "h7h5"};
    //process_position_command(commands.begin(), commands.end());
    
    //string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    //ASSERT_EQ (G_game_position->to_fen_string(), fen);
//}

//TEST (process_command, position_startpos_as_fen) { 
    //std::vector<string> commands = {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "w",
                                    //"KQkq", "-", "0", "1"};
    //process_position_command(commands.begin(), commands.end());

    //string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    //ASSERT_EQ (G_game_position->to_fen_string(), fen);
//}

//TEST (process_command, position_pawns_forward_as_fen) { 
    //std::vector<string> commands = {"position", "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR", "w",
                                    //"KQkq", "-", "0", "1", "moves", "a2a4", "a7a5", "b2b4", "b7b5",
                                    //"c2c4", "c7c5", "d2d4", "d7d5", "e2e4", "e7e5", "f2f4", "f7f5",
                                    //"g2g4", "g7g5", "h2h4", "h7h5"};
    //process_position_command(commands.begin(), commands.end());

    //string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    //ASSERT_EQ (G_game_position->to_fen_string(), fen);
//}


////TEST (process_command, go) { 
////}

////TEST (process_command, stop) { 
    ////ASSERT_EQ();
////}

////TEST (process_command, ponderhit) { 
    ////ASSERT_EQ();
////}

//TEST (process_commands, quit) { 
    //std::vector<string> commands = {"quit"};
    //command_queue.push(commands);
    //process_commands();

    //ASSERT_TRUE(true);
//}

////TEST (process_commands, uci_quit) { 
    ////std::vector<string> commands = {"uci", "quit"};
    ////command_queue.push(commands);

    ////// This can be an ofstream as well or any other ostream
    ////std::stringstream buffer;

    ////// Save cout's buffer here
    ////std::streambuf *sbuf = std::cout.rdbuf();

    ////// Redirect cout to our stringstream buffer or any other ostream
    ////std::cout.rdbuf(buffer.rdbuf());

    ////// Use cout as usual
    ////std::cout << "Hello World";
    ////process_commands();

    ////// When done redirect cout to its old self
    ////std::cout.rdbuf(sbuf);

    ////std::string output = buffer.str();

    ////ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
////}

//TEST (process_commands, debug_off_quit) { 
    //std::vector<string> commands = {"debug", "off", "quit"};
    //command_queue.push(commands);

    //process_commands();

    //ASSERT_FALSE(G_debug);
//}

//TEST (process_commands, isready_quit) { 
    //std::vector<string> commands = {"isready", "quit"};
    //command_queue.push(commands);

    //testing::internal::CaptureStdout();
    //process_commands();
    //string output = testing::internal::GetCapturedStdout();
    //ASSERT_EQ (output, "readyok\n");
//}

//TEST (process_commands, go_quit_startpos) { 
    //std::vector<string> commands = {"position", "startpos", "go", "quit"};
    //command_queue.push(commands);

    //testing::internal::CaptureStdout();
    //process_commands();
    //string output = testing::internal::GetCapturedStdout();
    //EXPECT_THAT(output, MatchesRegex("^bestmove\\s\\w\\w\\w\\w\\w?\\s$"));
//}

//TEST (process_commands, go_quit_nullpos) { 
    //std::vector<string> commands = {"position", "8/8/8/8/8/8/8/8", "w", "-", "-", "0", "1", "go",
                                    //"depth", "1", "quit"};
    //command_queue.push(commands);

    //testing::internal::CaptureStdout();
    //process_commands();
    //string output = testing::internal::GetCapturedStdout();
    //EXPECT_EQ(output, "Fatal error, no moves found.\n");
//}

