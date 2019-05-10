#include <string.h>
#include <limits>
#include "search.h"
#include "evaluate.h"
#include "game_variables.h"

using namespace std;

/*
 * Perform a search of the position given.
 */
void search(Position* pos, int depth) {

    if (pos == NULL) {
        return;
    }
    int alpha = std::numeric_limits<int>::min();
    int beta  = std::numeric_limits<int>::max();
    if (pos->active_color == 'w') {
        alphaBetaMax(pos, alpha, beta, depth);
        std::sort(pos->moves.begin(), pos->moves.end(), 
                [](Position const &a, Position const &b) { return b.evaluation_score < a.evaluation_score; });
        
    }
    else {
        alphaBetaMin(pos, alpha, beta, depth);
        std::sort(pos->moves.begin(), pos->moves.end(), 
                          [](Position const &a, Position const &b) { return a.evaluation_score < b.evaluation_score; });
    }

    return;
}

int alphaBetaMax(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        return pos->evaluation_score;
    }

    pos->generate_moves();

    // Sort in descending order of evaluation scores
    std::sort(pos->moves.begin(), pos->moves.end(), 
                      [](Position const &a, Position const &b) { return b.evaluation_score < a.evaluation_score; });

    for (vector<Position>::iterator p = pos->moves.begin(); p != pos->moves.end(); p++) {
        p->evaluation_score = alphaBetaMin(&(*p), alpha, beta, depth - 1);
        if (p->evaluation_score >= beta) {
            return beta;
        }
        if (p->evaluation_score > alpha) {
            alpha = p->evaluation_score;
        }
    }
    return alpha;
}

int alphaBetaMin(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        return pos->evaluation_score;
    }

    pos->generate_moves();

    // Sort in ascending order of evaluation scores
    std::sort(pos->moves.begin(), pos->moves.end(), 
                      [](Position const &a, Position const &b) { return a.evaluation_score < b.evaluation_score; });

    for (vector<Position>::iterator p = pos->moves.begin(); p != pos->moves.end(); p++) {
        p->evaluation_score = alphaBetaMax(&(*p), alpha, beta, depth - 1);
        if (p->evaluation_score <= alpha) {
            return alpha;
        }
        if (p->evaluation_score < beta) {
            beta = p->evaluation_score;
        }
    }
    return beta;
}

