#include "position.h"
#include "evaluate.h"
#include "genmove.h"
#include "zobrist.h"
#include "game_variables.h"

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

    set_piece_positions(piece_string);
    set_active_color(active_color);
    set_castling_rights(castle_rights);
    set_passant_target_sq(passant_sq);
    set_halfmove_clock(halfmove_clk);
    set_fullmove_number(fullmove_num);

    maps[eval_score] = evaluate_position(this);
    maps[zobrist_key] = zobrist.get_zobrist_key(this);

    delete[] fenstring;
}

void Position::generate_moves() {
    ::generate_moves(this);
    return;
}

void Position::evaluate() {
    maps[eval_score] = evaluate_position(this);
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
            case 'p': maps[b_pawn]   |= (single_bit << sq_num--); break;
            case 'r': maps[b_rook]   |= (single_bit << sq_num--); break;
            case 'n': maps[b_knight] |= (single_bit << sq_num--); break;
            case 'b': maps[b_bishop] |= (single_bit << sq_num--); break;
            case 'q': maps[b_queen]  |= (single_bit << sq_num--); break;
            case 'k': maps[b_king]   |= (single_bit << sq_num--); break;

            // Upper case = White Pieces
            case 'P': maps[w_pawn]   |= (single_bit << sq_num--); break;
            case 'R': maps[w_rook]   |= (single_bit << sq_num--); break;
            case 'N': maps[w_knight] |= (single_bit << sq_num--); break;
            case 'B': maps[w_bishop] |= (single_bit << sq_num--); break;
            case 'Q': maps[w_queen]  |= (single_bit << sq_num--); break;
            case 'K': maps[w_king]   |= (single_bit << sq_num--); break;

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

    maps[castle_rights] = castle_string_to_index.at(string(fen_tok));

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
    maps[act_color] = (fen_tok[0] == 'w') ? WHITE : BLACK;

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
        maps[passant_sq] = passant_string_to_bit.at(string(fen_tok));
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

    maps[hlf_clock] = Clock(strtoul(fen_tok, &end, 10));

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
    maps[full_num] = strtoul(fen_tok, &end, 10);

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


    // Check if there is a piece on the dest square and remove if needed.
    int dest_piece = get_moving_piece(dest_square);
    int z_piece = (dest_piece > 6) ? dest_piece : dest_piece - 1;
    if (dest_piece != -1) {
        maps[zobrist_key] ^= zobrist.zobrist_piece_rands[dest_square][z_piece];
        zero_at(dest_square, dest_piece);
    }
    // Get the piece that is moving
    int piece = get_moving_piece(start_square);
    z_piece = (piece > 6) ? piece : piece - 1;

    zero_at(start_square, piece);
    maps[zobrist_key] ^= zobrist.zobrist_piece_rands[start_square][z_piece];

    // Check for pawn promotion
    if (move.length() == 5) {
        char promoted_to = move.at(4);
        switch (promoted_to) {
            case 'q': piece = b_queen;  break;
            case 'Q': piece = w_queen;  break;
            case 'N': piece = w_knight; break;
            case 'n': piece = b_knight; break;
            case 'B': piece = w_bishop; break;
            case 'b': piece = b_bishop; break;
            case 'R': piece = w_rook;   break;
            case 'r': piece = b_rook;   break;
        }
    }

    z_piece = (piece > 6) ? piece : piece - 1;
    maps[zobrist_key] ^= zobrist.zobrist_piece_rands[dest_square][z_piece];

    // Set the destination square
    bitboard square_to_add = squares[dest_square];
    maps[piece] |= square_to_add;

    if (piece < 6) {
        maps[w_pieces] |= square_to_add;
    }
    else {
        maps[b_pieces] |= square_to_add;
    }

    // Increment move number based on current halfmove clock
    maps[full_num] += maps[hlf_clock];

    maps[hlf_clock] ^= ONE; // Toggle halfmove clock.

    maps[zobrist_key] ^= zobrist.zobrist_black_move; // Toggle Zobrist value for active color.
    maps[act_color] ^= BLACK; // Toggle active color.

    return;
}

/*
 *  zero_at zero's the bit indicated by square on the position given and
 *  set a number representing the piece type that was in the square.
 *
 *  return the map position of the piece changed
 */
void Position::zero_at(int square, int piece) {

    bitboard mask = ~(squares[square]);

    if (piece < 6) {
        maps[w_pieces] &= mask;
    }
    else {
        maps[b_pieces] &= mask;
    }
    maps[piece] &= mask;

    return;
}

int Position::get_moving_piece(int square) {
    bitboard square_bit = squares[square];

    for (unsigned int i = 0; i < 14; i++) {
        if (maps[i] & square_bit) {
            return i;
        }
    }

    return -1;
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
    fenstring += (maps[act_color] == WHITE) ? 'w' : 'b';
    fenstring += ' ';

    string castling = "";

    if (castling_rights[maps[castle_rights]][c_w_king])   { castling += "K"; }
    if (castling_rights[maps[castle_rights]][c_w_queen])  { castling += "Q"; }
    if (castling_rights[maps[castle_rights]][c_b_king])   { castling += "k"; }
    if (castling_rights[maps[castle_rights]][c_b_queen])  { castling += "q"; }

    if (castling.empty()) {
        castling += "-";
    }

    fenstring += castling + " ";
    fenstring += bit_to_square.at(maps[passant_sq]) + " ";
    fenstring += to_string(maps[hlf_clock]) + " ";
    fenstring += to_string(maps[full_num]);

    return fenstring;
}

