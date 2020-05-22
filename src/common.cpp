#include "common.hpp"

int get_square_num(char file, char rank) {
    return (file - 'a') + ((rank - '1') * 8);
}
