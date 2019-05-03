#include "gtest/gtest.h"
#include "../src/uci.h"
#include "../src/game_variables.h"

using namespace std;

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

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq - 0 9";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_startpos_as_fen) { 
    process_position_command("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}

TEST (process_command, position_pawns_forward_as_fen) { 
    process_position_command("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 moves a2a4 a7a5 b2b4 b7b5 c2c4 c7c5 d2d4 d7d5 e2e4 e7e5 f2f4 f7f5 g2g4 g7g5 h2h4 h7h5");

    string fen = "rnbqkbnr/8/8/pppppppp/PPPPPPPP/8/8/RNBQKBNR w KQkq - 0 9";

    ASSERT_EQ (G_game_position->to_fen_string(), fen);
}


TEST (process_command, go) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

//TEST (process_command, stop) { 
    //ASSERT_EQ ();
//}

TEST (process_command, ponderhit) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

