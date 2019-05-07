#include "common.h"

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

    return file - 'a';
}


