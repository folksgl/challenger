#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/uci.h"
#include "../src/game_variables.h"

using namespace std;
using ::testing::MatchesRegex;

TEST (process_command, uci) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_command, debug_on) { 
    string debug = "debug on";
    process_debug_command(debug);

    ASSERT_TRUE(G_debug);
}

TEST (process_command, debug_off) { 
    string debug = "debug off";
    process_debug_command(debug);

    ASSERT_FALSE(G_debug);
}

//TEST (process_command, setoption) { 
    //ASSERT_EQ ();
//}

TEST (process_command, position_startpos) { 
    process_position_command("position startpos");

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_pawns_forward) { 
    process_position_command("position startpos moves a2a4 a7a5 b2b4 b7b5 c2c4 c7c5 d2d4 d7d5 e2e4 e7e5 f2f4 f7f5 g2g4 g7g5 h2h4 h7h5");

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_startpos_as_fen) { 
    process_position_command("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_pawns_forward_as_fen) { 
    process_position_command("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 moves a2a4 a7a5 b2b4 b7b5 c2c4 c7c5 d2d4 d7d5 e2e4 e7e5 f2f4 f7f5 g2g4 g7g5 h2h4 h7h5");

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq h6 0 9";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}


//TEST (process_command, go) { 
//}

//TEST (process_command, stop) { 
    //ASSERT_EQ();
//}

//TEST (process_command, ponderhit) { 
    //ASSERT_EQ();
//}

TEST (process_uci_inputs, quit) { 
    string uci_command = "quit\n";
    istringstream iss(uci_command);

    EXPECT_EXIT(process_uci_inputs(iss), ::testing::ExitedWithCode(0), "");
}

TEST (process_uci_inputs, uci_quit) { 
    string uci_command = "uci\nquit\n";
    istringstream iss(uci_command);

    testing::internal::CaptureStdout();
    EXPECT_EXIT(process_uci_inputs(iss), ::testing::ExitedWithCode(0), "");
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_uci_inputs, debug_off_quit) { 
    string uci_command = "debug off\nquit\n";
    istringstream iss(uci_command);

    EXPECT_EXIT(process_uci_inputs(iss), ::testing::ExitedWithCode(0), "");

    ASSERT_FALSE(G_debug);
}

TEST (process_uci_inputs, isready_quit) { 
    string uci_command = "isready\nquit\n";
    istringstream iss(uci_command);

    testing::internal::CaptureStdout();
    EXPECT_EXIT(process_uci_inputs(iss), ::testing::ExitedWithCode(0), "");
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ (output, "readyok\n");
}

TEST (process_uci_inputs, go_quit_startpos) { 
    string uci_command = "position startpos\ngo\nquit\n";
    istringstream iss(uci_command);

    testing::internal::CaptureStdout();
    EXPECT_EXIT(process_uci_inputs(iss), ::testing::ExitedWithCode(0), "");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_THAT(output, MatchesRegex("^bestmove\\s\\w\\w\\w\\w\\w?\\s$"));
}

TEST (process_uci_inputs, go_quit_nullpos) { 
    string uci_command = "position 8/8/8/8/8/8/8/8 w - - 0 1\ngo depth 1\nquit\n";
    istringstream iss(uci_command);

    testing::internal::CaptureStdout();
    EXPECT_EXIT(process_uci_inputs(iss), ::testing::ExitedWithCode(0), "");
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Fatal error, no moves found.\n");
}

