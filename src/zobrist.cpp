#include "zobrist.h"

Zobrist::Zobrist(void) {
    
    // A Mersenne Twister pseudo-random generator of 64-bit numbers 
    mt19937_64 random_number;

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 12; j++) {
            zobrist_piece_rands[i][j] = random_number();
        }
    }

    zobrist_black_move = random_number();

    for (int i = 0; i < 16; i++) {
        zobrist_castling_rights[i] = random_number();
    }

    for (int i = 0; i < 8; i++) {
        zobrist_passant_file[i] = random_number();
    }
}
