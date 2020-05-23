#include "search.hpp"
#include "evaluate.hpp"
#include "game_variables.hpp"

using namespace std;

#ifdef BENCHMARK
extern unsigned long long positions_searched;
#endif

#define sort_ascending std::sort(pos->moves.rbegin(), pos->moves.rend())
#define sort_descending std::sort(pos->moves.begin(), pos->moves.end())

/*
 * Perform a search of the position given.
 */
void search(Position* pos, int depth) {

    bitboard alpha = std::numeric_limits<int>::min();
    bitboard beta  = std::numeric_limits<int>::max();
    if (pos->is_white_move()) {
        alphaBetaMax(pos, alpha, beta, depth);
        sort_descending;
    }
    else {
        alphaBetaMin(pos, alpha, beta, depth);
        sort_ascending;
    }

    return;
}

int alphaBetaMax(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        #ifdef BENCHMARK
        positions_searched++;
        #endif
        pos->evaluate();
        return pos->eval_score;
    }

    pos->generate_moves();

    #ifdef BENCHMARK
    positions_searched++;
    #endif

    // Sort in descending order of evaluation scores
    sort_descending;

    for (auto p : pos->moves) {
        p.eval_score = alphaBetaMin(&p, alpha, beta, depth - 1);
        if (p.eval_score >= beta) {
            return beta;
        }
        if (p.eval_score > alpha) {
            alpha = p.eval_score;
        }
    }
    return alpha;
}

int alphaBetaMin(Position* pos, int alpha, int beta, int depth) {
    if (depth == 0) {
        #ifdef BENCHMARK
        positions_searched++;
        #endif
        pos->evaluate();
        return pos->eval_score;
    }

    pos->generate_moves();

    #ifdef BENCHMARK
    positions_searched++;
    #endif

    // Sort in ascending order of evaluation scores
    sort_ascending;
    for (auto p : pos->moves) {
        p.eval_score = alphaBetaMax(&p, alpha, beta, depth - 1);
        if (p.eval_score <= alpha) {
            return alpha;
        }
        if (p.eval_score < beta) {
            beta = p.eval_score;
        }
    }
    return beta;
}

