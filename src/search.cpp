#include "./search.h"
#include "./evaluate.h"
#include <string.h>
#include <limits>

using namespace std;

std::string search(Position* pos) {
    int beta  = std::numeric_limits<int>::max();
    int alpha = std::numeric_limits<int>::min();

    int bestscore = 0;
    if (pos->active_color == 'w') {
        bestscore = alphaBetaMax(pos, alpha, beta, 15);
    }
    else if (pos->active_color == 'b') {
        bestscore = alphaBetaMin(pos, alpha, beta, 15);
    }

    return "TODO" + bestscore;
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
