#include <cctype>
#include <numeric>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "position.hpp"
#include "evaluate.hpp"
#include "genmove.hpp"
#include "game_variables.hpp"

using std::vector;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Position::Position(const string& fen) {
    vector<string> results = split(fen, ' ');

    set_piece_positions(results[0]);
    set_active_color(results[1]);
    set_castling_rights(results[2]);
    set_passant_target_sq(results[3]);
    set_halfmove_clock(results[4]);
    set_fullmove_number(results[5]);

    eval_score = evaluate_position(this);
}

void Position::generate_moves() {
    moves.reserve(32);
    ::generate_moves(this);
    return;
}

void Position::evaluate() {
    eval_score = evaluate_position(this);
    return;
}

/*
 *  set_piece_positions sets the value of all the bitboards in a Position
 *  to the values found in fen_tok.
 */
void Position::set_piece_positions(const string& str) {
    // Split string on '/' character and reverse all strings in the resulting vector
    vector<string> piece_strings = split(str , '/');
    std::transform(piece_strings.begin(), piece_strings.end(), piece_strings.begin(),
            [](string str) { std::reverse(str.begin(), str.end()); return str;});
    string bit_oriented_string = std::accumulate(piece_strings.begin(), piece_strings.end(), string());

    // Populate the Position from bit_oriented_string.
    int sq_num = 63;

    for (const char input : bit_oriented_string) {
        switch (input) {
            // Lower case = Black Pieces
            case 'p': maps[b_pawn]   |= square_bit(sq_num--); continue;
            case 'r': maps[b_rook]   |= square_bit(sq_num--); continue;
            case 'n': maps[b_knight] |= square_bit(sq_num--); continue;
            case 'b': maps[b_bishop] |= square_bit(sq_num--); continue;
            case 'q': maps[b_queen]  |= square_bit(sq_num--); continue;
            case 'k': maps[b_king]   |= square_bit(sq_num--); continue;

            // Upper case = White Pieces
            case 'P': maps[w_pawn]   |= square_bit(sq_num--); continue;
            case 'R': maps[w_rook]   |= square_bit(sq_num--); continue;
            case 'N': maps[w_knight] |= square_bit(sq_num--); continue;
            case 'B': maps[w_bishop] |= square_bit(sq_num--); continue;
            case 'Q': maps[w_queen]  |= square_bit(sq_num--); continue;
            case 'K': maps[w_king]   |= square_bit(sq_num--); continue;

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
 *  set_castling_rights sets the castling rights of the Position based on str
 */
void Position::set_castling_rights(const string& str) {
    // Check for malformed castling string. Set otherwise.
    if (str.length() > 0 && str.length() < 5) {
        for (char ch : str) {
            if (ch == 'K') {
                w_kingside_castle = true;
            } else if (ch == 'Q') {
                w_queenside_castle = true;
            } else if (ch == 'k') {
                b_kingside_castle = true;
            } else if (ch == 'q') {
                b_queenside_castle = true;
            }
        }
    }

    return;
}


/*
 *  set_active_color sets the active color in the Position based on str
 */
void Position::set_active_color(const string& str) {
    // Check for malformed active color string. Set otherwise.
    if (str.length() == 1) {
        is_white_move = (str == "w");
    }

    return;
}

/*
 *  set_passant_target_sq sets the passant target square for the Position based on str
 */
void Position::set_passant_target_sq(const string& str) {
    // If no target square or if malformed passant target string, assume there is none.
    if (str.length() == 2 && isalpha(str[0]) && isdigit(str[1])) {
        passant_sq = square_bit(get_square_num(str[0], str[1]));
    }

    return;
}

/*
 *  set_halfmove_clock sets the halfmove clock in Position based on str
 */
void Position::set_halfmove_clock(const string& str) {
    if (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit)) {
        hlf_clock = std::stoull(str, nullptr, 10);
    }

    return;
}

/*
 *  set_fullmove_number sets the fullmove number in Position based in str
 */
void Position::set_fullmove_number(const string& str) {
    if (!str.empty() && std::all_of(str.begin(), str.end(), ::isdigit)) {
        full_num = std::stoull(str, nullptr, 10);
    }
    return;
}

/*
 *  move performs the move given in the move string for the Position.
 */
void Position::move(const string& move, const int moving_piece) {
    // Extract start and destination squares from the move
    int start_square = get_square_num(move[0], move[1]);
    int dest_square = get_square_num(move[2], move[3]);


    // Check if there is a piece on the dest square and remove if needed.
    bitboard start_square_bit = square_bit(start_square);
    bitboard dest_square_bit = square_bit(dest_square);
    bitboard moving_bits = start_square_bit | dest_square_bit;

    // If a capture is taking place. Zero the destination square and reset halfmove clock.
    if ((maps[w_pieces] | maps[b_pieces]) & dest_square_bit) {
        bitboard dest_zero_mask = ~dest_square_bit;
        for (bitboard& bb : maps) {
            bb &= dest_zero_mask;
        }
        hlf_clock = -1;
    }

    bitboard new_passant_sq = 0;  // Default is 0, only set on double forward pawn move

    // Check for special move-types
    if (moving_piece == w_pawn || moving_piece == b_pawn) {
        if (dest_square_bit & passant_sq) {  // En passant capture
            int dest_zero = (moving_piece == w_pawn) ? dest_square - 8: dest_square + 8;

            bitboard mask = ~square_bit(dest_zero);
            maps[w_pieces] &= mask;
            maps[b_pieces] &= mask;
            maps[w_pawn] &= mask;
            maps[b_pawn] &= mask;
        } else if (abs(dest_square - start_square) == 16) {  // Pawn double forward
            new_passant_sq = square_bit((start_square + dest_square) / 2);
        } else if (dest_square_bit & (rank_1 | rank_8)) {  // Pawn promotion
            // Set the destination square bit in the pawn bitboard. It will be unset when
            // the moving_bits xor operation occurs.
            maps[moving_piece] |= dest_square_bit;
            char promoted_to = move.at(4);
            switch (promoted_to) {
                case 'q': maps[b_queen] |= dest_square_bit;  break;
                case 'Q': maps[w_queen] |= dest_square_bit;  break;
                case 'N': maps[w_knight] |= dest_square_bit; break;
                case 'n': maps[b_knight] |= dest_square_bit; break;
                case 'B': maps[w_bishop] |= dest_square_bit; break;
                case 'b': maps[b_bishop] |= dest_square_bit; break;
                case 'R': maps[w_rook] |= dest_square_bit;   break;
                case 'r': maps[b_rook] |= dest_square_bit;   break;
            }
        }
        hlf_clock = -1;  // Pawn moves reset the halfmove clock.
    } else if (moving_piece == w_king) {
        w_kingside_castle = false;
        w_queenside_castle = false;
        hlf_clock = -1;
        if ((start_square - dest_square) == 2) {  // Queenside Castling
            maps[w_rook] ^= 0x0000000000000009;
            maps[w_pieces] ^= 0x0000000000000009;
        } else if ((start_square - dest_square) == -2) {  // Kingside Castling
            maps[w_rook] ^= 0x00000000000000A0;
            maps[w_pieces] ^= 0x00000000000000A0;
        }
    } else if (moving_piece == b_king) {
        b_kingside_castle = false;
        b_queenside_castle = false;
        hlf_clock = -1;
        if ((start_square - dest_square) == 2) {  // Queenside Castling
            maps[b_rook] ^= 0x0900000000000000;
            maps[b_pieces] ^= 0x0900000000000000;
        } else if ((start_square - dest_square) == -2) {  // Kingside Castling
            maps[b_rook] ^= 0xA000000000000000;
            maps[b_pieces] ^= 0xA000000000000000;
        }
    } else if (moving_piece == w_rook || moving_piece == b_rook) {
        if (start_square == 0) {
            w_queenside_castle = false;
        } else if (start_square == 7) {
            w_kingside_castle = false;
        } else if (start_square == 56) {
            b_queenside_castle = false;
        } else if (start_square == 63) {
            b_kingside_castle = false;
        }

        hlf_clock = -1;
    }

    passant_sq = new_passant_sq;

    // Set side-to-move's changed bits
    maps[moving_piece] ^= moving_bits;
    if (moving_piece < 6) {
        maps[w_pieces] ^= moving_bits;
    } else {
        maps[b_pieces] ^= moving_bits;
    }

    // When active color is black(1) increments the fullmove number, but prevents branching based off the active color.
    full_num += !is_white_move;
    hlf_clock++;  // Toggle halfmove clock.
    is_white_move = !is_white_move;  // Toggle active color.

    return;
}

int Position::get_moving_piece(int square) {
    bitboard bit = square_bit(square);

    for (unsigned int i = 0; i < maps.size(); i++) {
        if (maps[i] & bit) {
            return i;
        }
    }

    return -1;
}

bool Position::is_square_attacked(bitboard square) {
    if (!square) return false;  // Square was 0, which is !valid

    bitboard whole_board = maps[w_pieces] | maps[b_pieces];
    bitboard pawns, bishops, rooks, knights, king, attackers;
    int index = lsb_unsafe(square);

    if (is_white_move) {
        pawns = maps[w_pawn];
        bishops = maps[w_bishop] | maps[w_queen];
        rooks = maps[w_rook] | maps[w_queen];
        knights = maps[w_knight];
        king = maps[w_king];

        attackers = ((pawns & not_a_file) << 7) & square;
        attackers |= ((pawns & not_h_file) << 9) & square;
    } else {
        pawns = maps[b_pawn];
        bishops = maps[b_bishop] | maps[b_queen];
        rooks = maps[b_rook] | maps[b_queen];
        knights = maps[b_knight];
        king = maps[b_king];

        attackers = ((pawns & not_h_file) >> 7) & square;
        attackers |= ((pawns & not_a_file) >> 9) & square;
    }

    attackers |= (slider_attacks.RookAttacks(whole_board, index) & rooks);
    attackers |= (slider_attacks.BishopAttacks(whole_board, index) & bishops);
    attackers |= (knight_moves[index] & knights);
    attackers |= (king_moves[index] & king);

    return attackers;
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
                bitboard cur_square = square_bit(i + j);

                // Check for an empty square
                if (!((maps[w_pieces] | maps[b_pieces]) & cur_square)) {
                    empty++;
                    if (j == 7) { fenstring += std::to_string(empty); }
                    continue;
                }
                // Position was !empty, check if there was an empty streak to add to the fen.
                if (empty != 0) {
                    fenstring += std::to_string(empty);
                    empty = 0;
                }

                // Add the piece to the fen string
                if (maps[w_pawn] & cur_square) {
                    fenstring += "P";
                } else if (maps[b_pawn] & cur_square) {
                    fenstring += "p";
                } else if (maps[w_rook] & cur_square) {
                    fenstring += "R";
                } else if (maps[b_rook] & cur_square) {
                    fenstring += "r";
                } else if (maps[w_bishop] & cur_square) {
                    fenstring += "B";
                } else if (maps[b_bishop] & cur_square) {
                    fenstring += "b";
                } else if (maps[w_knight] & cur_square) {
                    fenstring += "N";
                } else if (maps[b_knight] & cur_square) {
                    fenstring += "n";
                } else if (maps[w_queen] & cur_square) {
                    fenstring += "Q";
                } else if (maps[b_queen] & cur_square) {
                    fenstring += "q";
                } else if (maps[w_king] & cur_square) {
                    fenstring += "K";
                } else if (maps[b_king] & cur_square) {
                    fenstring += "k";
                }
            }
            // add / on to the end of every rank but the last one
            if ((i - 8) >= 0) {
                fenstring += "/";
            }
        }
    }

    fenstring += ' ';
    fenstring += (is_white_move) ? 'w' : 'b';
    fenstring += ' ';

    string castling = "";

    if (w_kingside_castle) { castling += "K"; }
    if (w_queenside_castle) { castling += "Q"; }
    if (b_kingside_castle) { castling += "k"; }
    if (b_queenside_castle) { castling += "q"; }

    if (castling.empty()) {
        castling += "-";
    }

    fenstring += castling + " ";
    fenstring += bit_to_square.at(passant_sq) + " ";
    fenstring += std::to_string(hlf_clock) + " ";
    fenstring += std::to_string(full_num);

    return fenstring;
}

