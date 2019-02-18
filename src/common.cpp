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

/*
 *  get_square_num calculates the number of the square represented by square_string
 */
int get_square_num(std::string square_string) {

    // To get the square number for a string such as e4, translate the file to a 
    // number (a=0, b=1, etc) and add (rank_multiplier * 8) to get the square.
    int rank_mult = atoi(square_string.substr(1, 1).c_str()) - 1;
    int square_num = file_to_num(square_string.at(0)) + (rank_mult * 8);

    return square_num;
}

/*
 *  file_to_num translates a character representing a file on a chess board (i.e. a, b, etc)
 *  to a number representing its location on the board. a=0, b=1, c=2
 */
int file_to_num(char file) {

    int number = 0;

    switch(file) {
        case 'b': number = 1; break;
        case 'c': number = 2; break;
        case 'd': number = 3; break;
        case 'e': number = 4; break;
        case 'f': number = 5; break;
        case 'g': number = 6; break;
        case 'h': number = 7; break;
    }

    return number;
}


