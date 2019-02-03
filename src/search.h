#include <string>
#include "./position.h"

#ifndef SEARCH_H
#define SEARCH_H

std::string search(position* pos);
int alphaBetaMax(position* pos, int alpha, int beta, int depth);
int alphaBetaMin(position* pos, int alpha, int beta, int depth);

#endif
