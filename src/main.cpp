#include "position.h"
#include "game_variables.h"
#include "uci.h"

using namespace std;

bool G_debug;
Position* G_game_position;
SliderAttacks slider_attacks;

int main()
{
    G_debug = false;

    slider_attacks.Initialize();

    process_uci_inputs(cin);

    return 0;
}
