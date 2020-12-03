#ifndef SRC_GAME_VARIABLES_HPP_
#define SRC_GAME_VARIABLES_HPP_

#include "position.hpp"
#include "slider_attacks.hpp"
#include "thread_safe_queue.hpp"
#include "uci_command.hpp"
#include "search.hpp"

extern bool G_debug;
extern Position* G_game_position;
extern SliderAttacks slider_attacks;
extern ThreadSafeQueue<UCICommand> command_queue;
extern search_info G_info;

#endif  // SRC_GAME_VARIABLES_HPP_
