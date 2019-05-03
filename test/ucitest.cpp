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

TEST (process_command, setoption) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_command, position) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_command, go) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_command, stop) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

TEST (process_command, ponderhit) { 
    testing::internal::CaptureStdout();
    process_uci_command();
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ (output, "id name Challenger\nid author folksgl\nuciok\n");
}

