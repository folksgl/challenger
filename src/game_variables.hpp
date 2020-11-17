#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include "position.hpp"
#include "slider_attacks.hpp"
#include "thread_safe_queue.hpp"

extern bool G_debug;
extern Position* G_game_position;
extern SliderAttacks slider_attacks;
extern ThreadSafeQueue<uci_command> command_queue;

#endif
