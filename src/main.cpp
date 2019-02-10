#include "position.h"
#include "game_variables.h"
#include "uci.h"

using namespace std;

bool G_debug;
Position* G_game_position;

int main()
{
    G_debug = false;

    process_uci_inputs();

    return 0;
}
