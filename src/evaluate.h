#include "bitboard.h"
#include "position.h"

#ifndef EVALUATE_H
#define EVALUATE_H

int evaluate_position(Position* pos);

int get_white_material_value(Position* pos);

int get_black_material_value(Position* pos);

#endif
