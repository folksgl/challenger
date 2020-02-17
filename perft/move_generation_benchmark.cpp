#include "move_generation_benchmark.h"
#include "../src/common.h"
#include <string>

using namespace std;
using namespace chrono;

extern unsigned long long positions_generated;

void move_generation_perft_from_position_debug(string fen) {

    positions_generated = 0;

    // Reset position to default starting position
    G_game_position = new Position(fen);

    G_game_position->generate_moves(); // Initial moves from position

    int total = 0;
    for (auto position: G_game_position->moves) {
        position.generate_moves(); // Responding moves
        int response = 0;
        for (auto innerpos: position.moves) {
            innerpos.generate_moves(); // Inital players response back
            response += innerpos.moves.size();
            total += innerpos.moves.size();
        }
        cout << fmt(G_game_position, &position) << " - " << response << " - " << position.to_fen_string() << endl;
    }
    positions_generated = 0;
}

string fmt(Position* initial, Position* next) {
    string src  = "notset";
    string dest = "notset";

    bool white_turn = initial->is_white_move();

    bitboard initial_king = (white_turn) ? initial->maps[w_king] : initial->maps[b_king];
    bitboard initial_rook = (white_turn) ? initial->maps[w_rook] : initial->maps[b_rook];
    bitboard next_king = (white_turn) ? next->maps[w_king] : next->maps[b_king];
    bitboard next_rook = (white_turn) ? next->maps[w_rook] : next->maps[b_rook];

    // Castling occured, adjust movestring
    if ((initial_king != next_king) && (initial_rook != next_rook)) {
        if (white_turn) {
            src  = "e1";
            if ((initial_rook & squares[0]) && !(next_rook & squares[0])) {
                dest = "c1";
            }
            else {
                dest = "g1";
            }
        }
        else {
            src = "e8";
            if ((initial_rook & squares[63]) && !(next_rook & squares[63])) {
                dest = "g8";
            }
            else {
                dest = "c8";
            }
        }
        return src + dest;
    }

    bitboard initial_pieces = (white_turn) ? initial->maps[w_pieces] : initial->maps[b_pieces];
    bitboard next_pieces = (white_turn) ? next->maps[w_pieces] : next->maps[b_pieces];

    int dest_square = 0;

    // Normal moves will be set here. (i.e. not castling/promotion)
    for (int i = 0; i < 64; i++) {
        // check set bits
        if (initial_pieces & squares[i]) {
            // Set bit was changed to unset
            if (!(next_pieces & squares[i])) {
                src = bit_to_square.at(squares[i]);
            }
        }
        // check unset bits
        else {
            if (next_pieces & squares[i]) {
                dest_square = i;
                dest = bit_to_square.at(squares[i]);
            }
        }
    }

    bitboard initial_pawn = (white_turn) ? initial->maps[w_pawn] : initial->maps[b_pawn];
    bitboard next_pawn = (white_turn) ? next->maps[w_pawn] : next->maps[b_pawn];

    if (white_turn) {
        initial_pawn &= rank_7;
        next_pawn &= rank_7;
    }
    else {
        initial_pawn &= rank_2;
        next_pawn &= rank_2;
    } 

    // Pawn promotion happened, adjust movestring
    if (initial_pawn != next_pawn) {
        if (white_turn) {
            if (squares[dest_square] & next->maps[w_queen])  { dest += "Q"; }
            if (squares[dest_square] & next->maps[w_bishop]) { dest += "B"; }
            if (squares[dest_square] & next->maps[w_knight]) { dest += "N"; }
            if (squares[dest_square] & next->maps[w_rook])   { dest += "R"; }
        }
        else {
            if (squares[dest_square] & next->maps[b_queen])  { dest += "q"; }
            if (squares[dest_square] & next->maps[b_bishop]) { dest += "b"; }
            if (squares[dest_square] & next->maps[b_knight]) { dest += "n"; }
            if (squares[dest_square] & next->maps[b_rook])   { dest += "r"; }
        }
    }

    return src + dest;
}

