#include "./position.h"
#include "./evaluate.h"

Position::Position(string fen) {

    // Copy fen string into char[] for tokenizing.
    char * fenstring = new char [fen.length()+1];
    strcpy (fenstring, fen.c_str());

    char *piece_string  = strtok(fenstring, " "); 
    char *active_color  = strtok(NULL, " "); 
    char *castle_rights = strtok(NULL, " "); 
    char *passant_sq    = strtok(NULL, " "); 
    char *halfmove_clk  = strtok(NULL, " "); 
    char *fullmove_num  = strtok(NULL, " "); 

    zero_piece_positions();
    set_piece_positions(piece_string);
    set_active_color(active_color);
    set_castling_rights(castle_rights);
    set_passant_target_sq(passant_sq);
    set_halfmove_clock(halfmove_clk);
    set_fullmove_number(fullmove_num);

    evaluation_score = evaluate_position(this);
}

bool Position::is_white_move(void) const {
    return active_color == 'w';
}

bool Position::is_black_move(void) const {
    return active_color == 'b';
}

void Position::generate_moves() {
    return;
}

void Position::move(string move_string) {
    return;
}

/*
 *  set_bit sets the value of the bit indicated by sq_num to 1.
 */
void Position::set_bit(bitboard* bit_map, int sq_num) {
    *bit_map |= ((bitboard)1 << sq_num);
}

void Position::zero_piece_positions() {
    for (int i = 0; i < maps.size(); i++) {
        maps[i] = 0;
    }
    return;
}

/*
 *  set_piece_positions sets the value of all the bitboards in board_position
 *  to the values found in fen_tok.
 */
void Position::set_piece_positions(char* fen_tok) {

    string tmp, bit_oriented_string;

    tmp = strtok(fen_tok, "/");
    std::reverse(tmp.begin(), tmp.end());
    bit_oriented_string += tmp;

    for (int i = 0; i < 7; i++) {
        tmp = strtok(NULL, "/");
        std::reverse(tmp.begin(), tmp.end());
        bit_oriented_string += tmp;
    }

    // Create Position from bit_oriented_string.
    int sq_num = 63;
    int length = bit_oriented_string.length();

    for (int i = 0; i < length; i++) {
        char input = bit_oriented_string.at(i);
        switch(input) {
            // Lower case = Black Pieces
            case 'p': set_bit(&maps[b_pawn],   sq_num--); break;
            case 'r': set_bit(&maps[b_rook],   sq_num--); break;
            case 'n': set_bit(&maps[b_knight], sq_num--); break;
            case 'b': set_bit(&maps[b_bishop], sq_num--); break;
            case 'q': set_bit(&maps[b_queen],  sq_num--); break;
            case 'k': set_bit(&maps[b_king],   sq_num--); break;

                // Upper case = White Pieces
            case 'P': set_bit(&maps[w_pawn],   sq_num--); break;
            case 'R': set_bit(&maps[w_rook],   sq_num--); break;
            case 'N': set_bit(&maps[w_knight], sq_num--); break;
            case 'B': set_bit(&maps[w_bishop], sq_num--); break;
            case 'Q': set_bit(&maps[w_queen],  sq_num--); break;
            case 'K': set_bit(&maps[w_king],   sq_num--); break;

            default :
                if (isdigit(input)) {
                    sq_num -= atoi(&input);
                }
        }
    }

    maps[w_pieces] = maps[w_pawn] | maps[w_rook]  | maps[w_knight] | 
                        maps[w_bishop] | maps[w_queen] | maps[w_king];

    maps[b_pieces] = maps[b_pawn] | maps[b_rook]  | maps[b_knight] | 
                        maps[b_bishop] | maps[b_queen] | maps[b_king];

    return;
}

/*
 *  set_castling_rights sets the value of castling_rights in board_position
 *  to the value found in fen_tok.
 */
void Position::set_castling_rights(char* fen_tok) {

    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 4) {
        // Castling right string is malformed, continue with no castling rights 
        return;
    }

    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (fen_tok[i] == 'K') {
            w_kingside_castle = true;
        }
        else if (fen_tok[i] == 'Q') {
            w_queenside_castle = true;
        }
        else if (fen_tok[i] == 'k') {
            b_kingside_castle = true;
        }
        else if (fen_tok[i] == 'q') {
            b_queenside_castle = true;
        }
    }

    return;
}


/*
 *  set_active_color sets the value of active_color in board_position
 *  to the value found in fen_tok.
 */
void Position::set_active_color(char* fen_tok) {

    if (fen_tok == NULL || strlen(fen_tok) != 1) {
        // Malformed active color string. Just assume that it is white's turn.
        return;
    }
    active_color = fen_tok[0];

    return;
}

/*
 *  set_passant_target_sq sets the value of passant_target_sq in board_position
 *  to the value found in fen_tok.
 */
void Position::set_passant_target_sq(char* fen_tok) {
    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 2 || fen_tok[0] == '-' || !isalpha(fen_tok[0]) || !isdigit(fen_tok[1])) {
        // No target square or if malformed passant target string, assume there is none.
        passant_target_sq[0] = '-';
        passant_target_sq[1] = '\0';
        return;
    }

    else {
        passant_target_sq[0] = fen_tok[0];
        passant_target_sq[1] = fen_tok[1];
    }

    return;
}

/*
 *  set_halfmove_clock sets the value of halfmove_clock in board_position
 *  to the value found in fen_tok.
 */
void Position::set_halfmove_clock(char* fen_tok) {
    if (fen_tok == NULL) {
        // Malformed clock string, just don't modify the clock and ignore token.
        return;
    }
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (!isdigit(fen_tok[i])) {
            // Malformed clock string, just don't modify the clock and ignore token.
            return;
        }
    }

    char* end;

    halfmove_clock = strtoul(fen_tok, &end, 10);;

    return;
}

/*
 *  set_fullmove_number sets the value of fullmove_number in board_position
 *  to the value found in fen_tok.
 */
void Position::set_fullmove_number(char* fen_tok) {
    if (fen_tok == NULL) {
        // Malformed move number string, ignore token and don't modify move number.
        return;
    }
    for (unsigned int i = 0; i < strlen(fen_tok); i++) {
        if (!isdigit(fen_tok[i])) {
            // Malformed move number string, ignore token and don't modify move number.
            return;
        }
    }

    char* end;
    fullmove_number = strtoul(fen_tok, &end, 10);

    return;
}

/*
 *  game_move performs the move given in the move string on board_position.
 */
void Position::game_move(string move) {

    if (move.length() != 4 && move.length() != 5) {
        // Malformed move string, ignore move and don't change the position.
        return;
    }

    // Extract start and destination squares from the move
    int start_square = get_square_num(move.substr(0,2));
    int dest_square = get_square_num(move.substr(2,2));

    // Zero out the start square
    int piece = zero_at(start_square);

    // Check for pawn promotion
    if (move.length() == 5) {
        char promoted_to = move.at(4);
        switch (promoted_to) {
            case 'N': piece = w_knight; break;
            case 'n': piece = b_knight; break;
            case 'B': piece = w_bishop; break;
            case 'b': piece = b_bishop; break;
            case 'Q': piece = w_queen;  break;
            case 'q': piece = b_queen;  break;
        }
    }

    // Set the destination square
    zero_at(dest_square);
    set_bit(&maps[piece], dest_square);

    if (piece < 6) {
        set_bit(&maps[w_pieces], dest_square);
    }
    else {
        set_bit(&maps[b_pieces], dest_square);
    }

    return;
}

/*
 *  zero_at zero's the bit indicated by square on the position given and
 *  set a number representing the piece type that was in the square.
 *
 *  return the map position of the piece changed
 */
int Position::zero_at(int square) {

    bitboard square_bit = (bitboard)1 << square;
    bitboard mask = 0xFFFFFFFFFFFFFFFF & ~square_bit;

    maps[b_pieces] = ((bitboard)maps[b_pieces] & mask);
    maps[w_pieces] = ((bitboard)maps[w_pieces] & mask);

    for (int i = 0; i < maps.size(); i++) {
        if (maps[i] & square_bit) {
            maps[i] = ((bitboard)maps[i] & mask);
            return i;
        }
    }

    return -1; //This should never return -1. A valid move WILL trigger one of the above cases.
}

/*
 *  get_square_num calculates the number of the square represented by square_string
 */
int Position::get_square_num(std::string square_string) const {

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
int Position::file_to_num(char file) const {

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

void Position::debug_position() const {

    bitboard bb;

    cout << "\n\nBlack pawn" << endl;   bb = maps[b_pawn];   print_bitboard(bb);
    cout << "\n\nBlack rook" << endl;   bb = maps[b_rook];   print_bitboard(bb);
    cout << "\n\nBlack knight" << endl; bb = maps[b_knight]; print_bitboard(bb);
    cout << "\n\nBlack bishop" << endl; bb = maps[b_bishop]; print_bitboard(bb);
    cout << "\n\nBlack queen" << endl;  bb = maps[b_queen];  print_bitboard(bb);
    cout << "\n\nBlack king" << endl;   bb = maps[b_king];   print_bitboard(bb);
    cout << "\n\nBlack pieces" << endl; bb = maps[b_pieces]; print_bitboard(bb);

    cout << "\n\nWhite pawn" << endl;   bb = maps[w_pawn];   print_bitboard(bb);
    cout << "\n\nWhite rook" << endl;   bb = maps[w_rook];   print_bitboard(bb);
    cout << "\n\nWhite knight" << endl; bb = maps[w_knight]; print_bitboard(bb);
    cout << "\n\nWhite bishop" << endl; bb = maps[w_bishop]; print_bitboard(bb);
    cout << "\n\nWhite queen" << endl;  bb = maps[w_queen];  print_bitboard(bb);
    cout << "\n\nWhite king" << endl;   bb = maps[w_king];   print_bitboard(bb);
    cout << "\n\nWhite pieces" << endl; bb = maps[w_pieces]; print_bitboard(bb);

}

void Position::print_bitboard(bitboard bb) const {

    for (int i = 56; i < 64; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 48; i < 56; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 40; i < 48; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 32; i < 40; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 24; i < 32; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 16; i < 24; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 8; i < 16; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    for (int i = 0; i < 8; i++) { if ((bb >> i) & 0x1) { cout << 'B'; } else { cout << '-'; } }
    cout << endl;
    return;
}

