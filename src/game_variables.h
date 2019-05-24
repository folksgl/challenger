#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include "position.h"
#include "slider_attacks.h"
#include "zobrist.h"

extern bool G_debug;
extern Position* G_game_position;
extern SliderAttacks slider_attacks;
extern Zobrist zobrist;

#endif
