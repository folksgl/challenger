#include <vector>
#include <string>
#include <algorithm>
#include <thread>
#include <mutex>
#include "game_variables.h"

#ifndef MOVESTORE_H
#define MOVESTORE_H

using namespace std;

struct Move {
    string movestring;
    int value;
};

class MoveStore {
    public:
        vector<Move> moves;
        mutex mtx;

        string best_move();
        void add_move(Move move);
        void clear();
};

#endif
