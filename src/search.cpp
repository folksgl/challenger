#include <string.h>
#include <limits>
#include "search.h"
#include "evaluate.h"
#include "movestore.h"
#include "game_variables.h"

using namespace std;

/*
 * Perform a search of the position given and return a string representing the best move to make.
 */
void search(Position* pos) {
    if (pos->active_color == 'w') {
        begin_alpha_search(pos);
    }
    else if (pos->active_color == 'b') {
        begin_beta_search(pos);
    }

    return;
}

void begin_alpha_search(Position* pos) {
    int beta  = std::numeric_limits<int>::max();
    int alpha = std::numeric_limits<int>::min();

    int score = 0;

    for (vector<Position>::iterator p = pos->moves.begin(); p != pos->moves.end(); p++) {
        Move move;
        move.value = alphaBetaMax(&(*p), alpha, beta, 15);
        move.movestring = p->movestring;

        G_movestore->add_move(move);

        if (score <= alpha) {
            //return alpha;
        }
        if (score < beta) {
            beta = score;
        }
    }
}

void begin_beta_search(Position* pos) {
    //int beta  = std::numeric_limits<int>::max();
    //int alpha = std::numeric_limits<int>::min();
}

int alphaBetaMax(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        return pos->evaluation_score;
    }

    std::sort(pos->moves.begin(), pos->moves.end(), 
                      [](Position const &a, Position const &b) { return b.evaluation_score < a.evaluation_score; });

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

    std::sort(pos->moves.begin(), pos->moves.end(), 
                      [](Position const &a, Position const &b) { return a.evaluation_score < b.evaluation_score; });

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
