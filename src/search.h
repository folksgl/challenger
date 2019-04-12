#include <string>
#include "./position.h"

#ifndef SEARCH_H
#define SEARCH_H

void search(Position* pos);

void begin_alpha_search(Position* pos);
void begin_beta_search(Position* pos);

int alphaBetaMax(Position* pos, int alpha, int beta, int depth);
int alphaBetaMin(Position* pos, int alpha, int beta, int depth);

#endif
