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

    bitboard alpha = std::numeric_limits<bitboard>::min();
    bitboard beta  = std::numeric_limits<bitboard>::max();
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

int alphaBetaMax(Position* pos, bitboard alpha, bitboard beta, int depth) {
    if (depth == 0) {
        #ifdef BENCHMARK
        positions_searched++;
        #endif
        pos->evaluate();
        return pos->maps[eval_score];
    }

    pos->generate_moves();

    #ifdef BENCHMARK
    positions_searched++;
    #endif

    // Sort in descending order of evaluation scores
    sort_descending;

    for (auto p : pos->moves) {
        p.maps[eval_score] = alphaBetaMin(&p, alpha, beta, depth - 1);
        if (p.maps[eval_score] >= beta) {
            return beta;
        }
        if (p.maps[eval_score] > alpha) {
            alpha = p.maps[eval_score];
        }
    }
    return alpha;
}

int alphaBetaMin(Position* pos, bitboard alpha, bitboard beta, int depth) {
    if (depth == 0) {
        #ifdef BENCHMARK
        positions_searched++;
        #endif
        return pos->maps[eval_score];
    }

    pos->generate_moves();

    #ifdef BENCHMARK
    positions_searched++;
    #endif

    // Sort in ascending order of evaluation scores
    sort_ascending;
    for (auto p : pos->moves) {
        p.maps[eval_score] = alphaBetaMax(&p, alpha, beta, depth - 1);
        if (p.maps[eval_score] <= alpha) {
            return alpha;
        }
        if (p.maps[eval_score] < beta) {
            beta = p.maps[eval_score];
        }
    }
    return beta;
}

