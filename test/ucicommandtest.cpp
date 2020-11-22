#include "gtest/gtest.h"
#include "../src/uci_command.hpp"

using namespace std;

TEST (ucicommandtest_uci_regex, good_uci_commands) { 
    ASSERT_NO_THROW(UCICommand("uci"));
    ASSERT_NO_THROW(UCICommand("\nuci"));
    ASSERT_NO_THROW(UCICommand("\tuci"));
    ASSERT_NO_THROW(UCICommand("\n\t   uci\n\t\n\n\t   "));
}

TEST (ucicommandtest_uci_regex, bad_uci_commands) { 
    ASSERT_THROW(UCICommand("uuci"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ucii"), std::invalid_argument);
    ASSERT_THROW(UCICommand("uci asdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("uciasdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdfuci"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdf uci"), std::invalid_argument);
    ASSERT_THROW(UCICommand("1uci"), std::invalid_argument);
    ASSERT_THROW(UCICommand("1 uci"), std::invalid_argument);
    ASSERT_THROW(UCICommand("u ci"), std::invalid_argument);
}
TEST (ucicommandtest_debug_regex, good_debug_commands) { 
    ASSERT_NO_THROW(UCICommand("debug on"));
    ASSERT_NO_THROW(UCICommand("debug off"));
}

TEST (ucicommandtest_debug_regex, bad_debug_commands) { 
    ASSERT_THROW(UCICommand("ddebug on"), std::invalid_argument);
    ASSERT_THROW(UCICommand("debug o"), std::invalid_argument);
    ASSERT_THROW(UCICommand("debug onn"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ebug on"), std::invalid_argument);
    ASSERT_THROW(UCICommand("debug"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdf debug on"), std::invalid_argument);
    ASSERT_THROW(UCICommand("debug on asdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("d\nebug on"), std::invalid_argument);
}

TEST (ucicommandtest_isready_regex, good_isready_commands) { 
    ASSERT_NO_THROW(UCICommand("isready"));
}

TEST (ucicommandtest_isready_regex, bad_isready_commands) { 
    ASSERT_THROW(UCICommand("iisready"), std::invalid_argument);
    ASSERT_THROW(UCICommand("isreadyy"), std::invalid_argument);
    ASSERT_THROW(UCICommand("is ready"), std::invalid_argument);
    ASSERT_THROW(UCICommand("a isready"), std::invalid_argument);
    ASSERT_THROW(UCICommand("isready a"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdfisready"), std::invalid_argument);
    ASSERT_THROW(UCICommand("isreadyasdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("sready"), std::invalid_argument);
    ASSERT_THROW(UCICommand("i\nsready"), std::invalid_argument);
    ASSERT_THROW(UCICommand("i\tsready"), std::invalid_argument);
}

TEST (ucicommandtest_setoption_regex, good_setoption_commands) { 
    ASSERT_NO_THROW(UCICommand("setoption name value x"));
    ASSERT_NO_THROW(UCICommand("setoption name value 1"));
    ASSERT_NO_THROW(UCICommand("setoption asdf_1234"));
    ASSERT_NO_THROW(UCICommand("setoption asdf_1234 value asdf_1234"));
}

TEST (ucicommandtest_setoption_regex, bad_setoption_commands) { 
    ASSERT_THROW(UCICommand("isetoption"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoptiony"), std::invalid_argument);
    ASSERT_THROW(UCICommand("set option"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoptionn name value x"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ssetoption name value x"), std::invalid_argument);
    ASSERT_THROW(UCICommand("etoption asdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoption value"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoption value 42"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoption setoption value 42"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoption value value 42"), std::invalid_argument);
    ASSERT_THROW(UCICommand("setoption 42 24"), std::invalid_argument);
}

TEST (ucicommandtest_ucinewgame_regex, good_ucinewgame_commands) { 
    ASSERT_NO_THROW(UCICommand("ucinewgame"));
}

TEST (ucicommandtest_ucinewgame_regex, bad_ucinewgame_commands) { 
    ASSERT_THROW(UCICommand("uucinewgame"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ucinewgamee"), std::invalid_argument);
    ASSERT_THROW(UCICommand("uci newgame"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("cinewgame"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ucinewgam"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ucinew\ngame"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ucinewgameucinewgame"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ucinewgame ucinewgame"), std::invalid_argument);
}

TEST (ucicommandtest_position_regex, good_position_commands) { 
    ASSERT_NO_THROW(UCICommand("position startpos"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq a1 1 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b Qkq a1 1 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b kq a1 1 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b q a1 1 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b - a1 1 2"));
    ASSERT_NO_THROW(UCICommand("position rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1234567890987654321 2234567890987654321"));
    ASSERT_NO_THROW(UCICommand("position startpos moves a1a2"));
    ASSERT_NO_THROW(UCICommand("position startpos moves a1a2 b2b2"));
    ASSERT_NO_THROW(UCICommand("position startpos moves a1a2 b2b2 c3c3"));
    ASSERT_NO_THROW(UCICommand("position startpos moves a1a2 b2b2 c3c3 d4d4"));
    ASSERT_NO_THROW(UCICommand("position startpos moves a1a2 b2b2 c3c3 d4d4q"));
    ASSERT_NO_THROW(UCICommand("position startpos moves a1a2 b2b2 c3c3 d4d4Q"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e2"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves f1e8 d5f8"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves g1e6 d5f8"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves h1e8 d5f8q"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e5 d5f8Q"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e7 d5f8n"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e7 d5f8n"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e7 d5f8r"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e7 d5f8R"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e7 d5f8b"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves e1e7 d5f8B"));
    ASSERT_NO_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 1 moves d5f8B"));
}

TEST (ucicommandtest_position_regex, bad_position_commands) { 
    ASSERT_THROW(UCICommand("uposition"), std::invalid_argument);
    ASSERT_THROW(UCICommand("positione"), std::invalid_argument);
    ASSERT_THROW(UCICommand("posit on"), std::invalid_argument);
    ASSERT_THROW(UCICommand("asdf"), std::invalid_argument);
    ASSERT_THROW(UCICommand("\n\n"), std::invalid_argument);
    ASSERT_THROW(UCICommand("osition"), std::invalid_argument);
    ASSERT_THROW(UCICommand("startpos"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 -"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 w)"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 - KQkq - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/u w KQkq - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w tQkq - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w Ktkq - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQtq - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkt - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq a 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq 1 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8//8/8 w KQkq - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w - 0 0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos move a1a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves i1a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a1j2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a0a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a9a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a1a0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a1a9"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a1a1qq"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a1a1W"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position startpos moves a1a1w"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 move a1a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves i1a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a1j2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a0a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a9a2"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a1a0"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a1a9"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a1a1qq"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a1a1W"), std::invalid_argument);
    ASSERT_THROW(UCICommand("position 8/8/8/8/8/8/8/8 w KQkq - 0 0 moves a1a1w"), std::invalid_argument);
}

TEST (ucicommandtest_go_regex, good_go_commands) { 
    ASSERT_NO_THROW(UCICommand("go"));
    ASSERT_NO_THROW(UCICommand("go depth 1"));
    ASSERT_NO_THROW(UCICommand("go depth 1234567890"));
    ASSERT_NO_THROW(UCICommand("go depth 1 ponder"));
    ASSERT_NO_THROW(UCICommand("go depth 3 wtime 4"));
    ASSERT_NO_THROW(UCICommand("go nodes 7"));
    ASSERT_NO_THROW(UCICommand("go mate 09"));
    ASSERT_NO_THROW(UCICommand("go infinite searchmoves a1a2 a2a4q"));
}

TEST (ucicommandtest_go_regex, bad_go_commands) { 
    ASSERT_THROW(UCICommand("ugo"), std::invalid_argument);
    ASSERT_THROW(UCICommand("gon"), std::invalid_argument);
    ASSERT_THROW(UCICommand("g\no"), std::invalid_argument);
    ASSERT_THROW(UCICommand("g o"), std::invalid_argument);
    ASSERT_THROW(UCICommand("\n\n"), std::invalid_argument);
    ASSERT_THROW(UCICommand("o"), std::invalid_argument);
    ASSERT_THROW(UCICommand("g"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go depth"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go depth infinite"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go depth a"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go winc"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go binc p"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go movestogo"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go winc binc 4"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go inc 4"), std::invalid_argument);
}

TEST (ucicommandtest_stop_regex, good_stop_commands) { 
    ASSERT_NO_THROW(UCICommand("stop"));
}

TEST (ucicommandtest_stop_regex, bad_stop_commands) { 
    ASSERT_THROW(UCICommand("sstop"), std::invalid_argument);
    ASSERT_THROW(UCICommand("stopp"), std::invalid_argument);
    ASSERT_THROW(UCICommand("st\nop"), std::invalid_argument);
    ASSERT_THROW(UCICommand("st\top"), std::invalid_argument);
    ASSERT_THROW(UCICommand("sto"), std::invalid_argument);
    ASSERT_THROW(UCICommand("top"), std::invalid_argument);
    ASSERT_THROW(UCICommand("st op"), std::invalid_argument);
    ASSERT_THROW(UCICommand("stop stop"), std::invalid_argument);
    ASSERT_THROW(UCICommand("stopstop"), std::invalid_argument);
    ASSERT_THROW(UCICommand("1stop"), std::invalid_argument);
    ASSERT_THROW(UCICommand("astop"), std::invalid_argument);
    ASSERT_THROW(UCICommand("stop1"), std::invalid_argument);
    ASSERT_THROW(UCICommand("stop 1"), std::invalid_argument);
    ASSERT_THROW(UCICommand("st p"), std::invalid_argument);
    ASSERT_THROW(UCICommand("s op"), std::invalid_argument);
    ASSERT_THROW(UCICommand("sto  p"), std::invalid_argument);
}

TEST (ucicommandtest_ponderhit_regex, good_ponderhit_commands) { 
    ASSERT_NO_THROW(UCICommand("ponderhit"));
}

TEST (ucicommandtest_ponderhit_regex, bad_ponderhit_commands) { 
    ASSERT_THROW(UCICommand("pponderhit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponderhitt"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponder\nhit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponder\thit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponderhi"), std::invalid_argument);
    ASSERT_THROW(UCICommand("onderhit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponder hit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponderhitponderhit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponderhit ponderhit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("p  onderhithit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go ponderhit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("ponderhit isready"), std::invalid_argument);
}

TEST (ucicommandtest_quit_regex, good_quit_commands) { 
    ASSERT_NO_THROW(UCICommand("quit"));
}

TEST (ucicommandtest_quit_regex, bad_quit_commands) { 
    ASSERT_THROW(UCICommand("qquit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("quitt"), std::invalid_argument);
    ASSERT_THROW(UCICommand("qu\nit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("qu\tit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("qui"), std::invalid_argument);
    ASSERT_THROW(UCICommand("uit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("qu it"), std::invalid_argument);
    ASSERT_THROW(UCICommand("qu  it"), std::invalid_argument);
    ASSERT_THROW(UCICommand("quitquit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("quit quit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("go quit"), std::invalid_argument);
    ASSERT_THROW(UCICommand("quit isready"), std::invalid_argument);
}
