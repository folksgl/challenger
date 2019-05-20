#include "position.h"
#include "evaluate.h"
#include "genmove.h"

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

    set_defaults();
    set_piece_positions(piece_string);
    set_active_color(active_color);
    set_castling_rights(castle_rights);
    set_passant_target_sq(passant_sq);
    set_halfmove_clock(halfmove_clk);
    set_fullmove_number(fullmove_num);

    evaluation_score = evaluate_position(this);

    delete[] fenstring;
}

bool Position::operator == (const Position& other) const {
    if (maps != other.maps) { return false; }

    if (active_color != other.active_color) { return false; }

    if (w_kingside_castle  != other.w_kingside_castle)  { return false; }
    if (b_kingside_castle  != other.b_kingside_castle)  { return false; }
    if (w_queenside_castle != other.w_queenside_castle) { return false; }
    if (w_queenside_castle != other.w_queenside_castle) { return false; }

    if (passant_target_sq  != other.passant_target_sq)  { return false; }

    if (halfmove_clock  != other.halfmove_clock)  { return false; }
    if (fullmove_number != other.fullmove_number) { return false; }

    return true;
}

bool Position::is_white_move(void) const {
    return active_color == 'w';
}

bool Position::is_black_move(void) const {
    return active_color == 'b';
}

void Position::generate_moves() {
    ::generate_moves(this);
    return;
}

void Position::evaluate() {
    evaluation_score = ::evaluate_position(this);
    return;
}

void Position::set_defaults() {

    bitboard board_zero = (bitboard)0;
    for (unsigned int i = 0; i < maps.size(); i++) {
        maps[i] = board_zero;
    }

    active_color = 'w';

    w_kingside_castle = false;
    w_queenside_castle = false;
    b_kingside_castle = false;
    b_queenside_castle = false;

    passant_target_sq = "-";

    halfmove_clock = 0;
    fullmove_number = 0;

    evaluation_score = 0;
}

Position::Position(const Position& other) {
    maps = other.maps;

    active_color = other.active_color;

    w_kingside_castle  = other.w_kingside_castle;
    w_queenside_castle = other.w_queenside_castle;
    b_kingside_castle  = other.b_kingside_castle;
    b_queenside_castle = other.b_queenside_castle;

    passant_target_sq = other.passant_target_sq;

    halfmove_clock = other.halfmove_clock;
    fullmove_number = other.fullmove_number;

    evaluation_score = other.evaluation_score;
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
            case 'p': maps[b_pawn]   |= ((bitboard)1 << sq_num--); break;
            case 'r': maps[b_rook]   |= ((bitboard)1 << sq_num--); break;
            case 'n': maps[b_knight] |= ((bitboard)1 << sq_num--); break;
            case 'b': maps[b_bishop] |= ((bitboard)1 << sq_num--); break;
            case 'q': maps[b_queen]  |= ((bitboard)1 << sq_num--); break;
            case 'k': maps[b_king]   |= ((bitboard)1 << sq_num--); break;

            // Upper case = White Pieces
            case 'P': maps[w_pawn]   |= ((bitboard)1 << sq_num--); break;
            case 'R': maps[w_rook]   |= ((bitboard)1 << sq_num--); break;
            case 'N': maps[w_knight] |= ((bitboard)1 << sq_num--); break;
            case 'B': maps[w_bishop] |= ((bitboard)1 << sq_num--); break;
            case 'Q': maps[w_queen]  |= ((bitboard)1 << sq_num--); break;
            case 'K': maps[w_king]   |= ((bitboard)1 << sq_num--); break;

            default :
                if (isdigit(input)) {
                    sq_num -= (input - '0');
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

    if (fen_tok == NULL || strlen(fen_tok) < 1 || strlen(fen_tok) > 2 || !isalpha(fen_tok[0]) || !isdigit(fen_tok[1])) {
        // No target square or if malformed passant target string, assume there is none.
        return;
    }

    else {
        passant_target_sq = string(fen_tok);
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
void Position::move(string move) {

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
            case 'R': piece = w_rook;   break;
            case 'r': piece = b_rook;   break;
            case 'Q': piece = w_queen;  break;
            case 'q': piece = b_queen;  break;
        }
    }

    // Set the destination square
    zero_at(dest_square);
    maps[piece] |= (bitboard)1 << dest_square;

    if (piece < 6) {
        maps[w_pieces] |= (bitboard)1 << dest_square;
    }
    else {
        maps[b_pieces] |= (bitboard)1 << dest_square;
    }

    if (active_color == 'b') {
        fullmove_number++;
        active_color = 'w';
    }
    else {
        active_color = 'b';
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

    for (unsigned int i = 0; i < maps.size(); i++) {
        if (maps[i] & square_bit) {
            maps[i] = ((bitboard)maps[i] & mask);
            return i;
        }
    }

    return -1; //This should never return -1. A valid move WILL trigger one of the above cases.
}

string Position::to_fen_string() {
    string fenstring = "";

    // Loop through all 64 squares on the board
    for (int i = 63; i >= 0; i--) {
        // Fen string construction begins on the left of the rank (i.e. every 8th square)
        if ((i % 8) == 0) {
            // add current rank
            int empty = 0;

            // Loop over the entire rank
            for (int j = 0; j < 8; j++) {
                bitboard cur_square = squares[i + j];

                // Check for an empty square
                if (!((maps[w_pieces] | maps[b_pieces]) & cur_square)) {
                    empty++;
                    if (j == 7) { fenstring += to_string(empty); }
                    continue;
                }
                // Position was not empty, check if there was an empty streak to add to the fen.
                if (empty != 0) {
                    fenstring += to_string(empty);
                    empty = 0;
                }
                
                // Add the piece to the fen string
                if      (maps[w_pawn]   & cur_square) { fenstring += "P"; }
                else if (maps[b_pawn]   & cur_square) { fenstring += "p"; }
                else if (maps[w_rook]   & cur_square) { fenstring += "R"; }
                else if (maps[b_rook]   & cur_square) { fenstring += "r"; }
                else if (maps[w_bishop] & cur_square) { fenstring += "B"; }
                else if (maps[b_bishop] & cur_square) { fenstring += "b"; }
                else if (maps[w_knight] & cur_square) { fenstring += "N"; }
                else if (maps[b_knight] & cur_square) { fenstring += "n"; }
                else if (maps[w_queen]  & cur_square) { fenstring += "Q"; }
                else if (maps[b_queen]  & cur_square) { fenstring += "q"; }
                else if (maps[w_king]   & cur_square) { fenstring += "K"; }
                else if (maps[b_king]   & cur_square) { fenstring += "k"; }
            }
            // add / on to the end of every rank but the last one
            if ((i - 8) >= 0) {
                fenstring += "/";
            }
        }
    }

    fenstring += ' ';
    fenstring += active_color;
    fenstring += ' ';

    string castling = "";

    if (w_kingside_castle)  { castling += "K"; }
    if (w_queenside_castle) { castling += "Q"; }
    if (b_kingside_castle)  { castling += "k"; }
    if (b_queenside_castle) { castling += "q"; }

    if (castling.empty()) {
        castling += "-";
    }

    fenstring += castling + " ";
    fenstring += passant_target_sq + " ";
    fenstring += to_string(halfmove_clock) + " ";
    fenstring += to_string(fullmove_number);

    return fenstring;
}

