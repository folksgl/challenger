#include "./search.h"
#include "./evaluate.h"
#include <string.h>
#include <limits>

using namespace std;

/*
 * Perform a search of the position given and return a string representing the best move to make.
 */
std::string search(Position* pos) {
    int beta  = std::numeric_limits<int>::max();
    int alpha = std::numeric_limits<int>::min();

    int bestscore = 0;

    move_order(pos);

    if (pos->active_color == 'w') {
        bestscore = alphaBetaMax(pos, alpha, beta, 15);
    }
    else if (pos->active_color == 'b') {
        bestscore = alphaBetaMin(pos, alpha, beta, 15);
    }

    return "TODO" + bestscore;
}

/*
 * Sort the moves vector of the position to attempt to maximize pruning of alpha-beta search
 */
void move_order(Position* pos) {
    if (pos->active_color == 'w') {
        std::sort(pos->moves.begin(), pos->moves.end(), 
                          [](Position const &a, Position const &b) { return b.evaluation_score < a.evaluation_score; });
    }
    else {
        std::sort(pos->moves.begin(), pos->moves.end(), 
                          [](Position const &a, Position const &b) { return a.evaluation_score < b.evaluation_score; });
    }
}

int alphaBetaMax(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        return pos->evaluation_score;
    }

    int score = 0;

    for (vector<Position>::iterator p = pos->moves.begin(); p != pos->moves.end(); p++) {
        score = alphaBetaMin(&(*p), alpha, beta, depth - 1);
        if (score >= beta) {
            return beta;
        }
        if (score > alpha) {
            alpha = score;
        }
    }
    return alpha;
}

int alphaBetaMin(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        return pos->evaluation_score;
    }

    int score = 0;

    for (vector<Position>::iterator p = pos->moves.begin(); p != pos->moves.end(); p++) {
        score = alphaBetaMax(&(*p), alpha, beta, depth - 1);
        if (score <= alpha) {
            return alpha;
        }
        if (score < beta) {
            beta = score;
        }
    }
    return beta;
}
