#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include "position.h"

void search(Position* pos, int depth);

int alphaBetaMax(Position* pos, bitboard alpha, bitboard beta, int depth);
int alphaBetaMin(Position* pos, bitboard alpha, bitboard beta, int depth);

#endif
