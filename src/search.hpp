#ifndef SEARCH_H
#define SEARCH_H

#include "position.hpp"

struct search_info {
    int wtime = std::numeric_limits<int>::max();
    int btime = std::numeric_limits<int>::max();
    int winc = 0;
    int binc = 0;
    int movestogo = 0;
    int depth = 6;
    int nodes = 0;
    int mate = 0;
    int movetime = 0;
    bool infinite = false;
    bool ponder = false;
    std::vector<std::string> searchmoves;
};

void search(Position* pos, int depth);

int alphaBetaMax(Position* pos, int alpha, int beta, int depth);
int alphaBetaMin(Position* pos, int alpha, int beta, int depth);

#endif
