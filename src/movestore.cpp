#include "movestore.h"

void MoveStore::add_move(Move move) {
    mtx.lock();
    moves.push_back(move);
    mtx.unlock();
}

void MoveStore::clear() {
    mtx.lock();
    moves.clear();
    mtx.unlock();
}

string MoveStore::best_move() {
    string best_move;
    mtx.lock();
    if (G_game_position->active_color == 'w') {
        // Descending
        std::sort(moves.begin(), moves.end(), 
                [](Move const &a, Move const &b) { return b.value < a.value; });
    }
    else {
        // Ascending
        std::sort(moves.begin(), moves.end(), 
                [](Move const &a, Move const &b) { return a.value < b.value; });
    }

    best_move = moves.at(0).movestring;

    mtx.unlock();

    return best_move;
}
