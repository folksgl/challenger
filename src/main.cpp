#include "position.h"
#include "game_variables.h"
#include "uci.h"
#include "movestore.h"

using namespace std;

bool G_debug;
Position* G_game_position;
MoveStore* G_movestore;

int main()
{
    G_debug = false;

    process_uci_inputs();

    return 0;
}
