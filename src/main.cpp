#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "./bitmap.h"

using namespace std;

//#define NUM_THREADS 1
//#define UCI_THREAD 0

// RESERVED THREADS
//
// 0 = stdin/stdout UCI communication thread
//

int main()
{
    string uci_token;

    // Get command from stdin and process>
    do {
        getline(cin, uci_token);

        if (uci_token == "uci") {
            cout << "id name Challenger" << endl;
            cout << "id author folksgl" << endl;
            cout << "uciok" << endl;
        }
        else if (uci_token == "debug") {
            cout << "You entered debug" << endl;
        }
        else if (uci_token == "isready") {
            cout << "readyok" << endl;
        }
        else if (uci_token.substr(0,8) == "setoption") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token.substr(0,7) == "register") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token == "ucinewgame") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token.substr(0,7) == "position") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token.substr(0,1) == "go") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token == "stop") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token == "ponderhit") {
            //TODO
            cout << "Haven't implemented that yet" << endl;
        }
        else if (uci_token == "quit") {
            exit(0)
        }

        // Default action is to do nothing and ignore invalid commands.

    } while (1);

    return 0;
}
