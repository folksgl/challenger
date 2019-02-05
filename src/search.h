#include <string>
#include "./position.h"

#ifndef SEARCH_H
#define SEARCH_H

std::string search(Position* pos);
int alphaBetaMax(Position* pos, int alpha, int beta, int depth);
int alphaBetaMin(Position* pos, int alpha, int beta, int depth);

#endif
