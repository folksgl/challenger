#include <regex>
#include "uci_command.hpp"

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
