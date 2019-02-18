#include "common.h"

/*
 *  num_set_bits takes in a bitboard and returns the number of bits in that bitboard that are set to 1.
 */
int num_set_bits(bitboard map) {
    int num_bits = 0;

    for (int i = 0; i < 64; i++) {
        if (map & squares[i]) {
            num_bits++;
        }
    }

    return num_bits;
}

