//#include "zobrist.hpp"

//Zobrist::Zobrist(void) {
    
    //// A Mersenne Twister pseudo-random generator of 64-bit numbers 
    //mt19937_64 random_number;

    //for (int i = 0; i < 64; i++) {
        //for (int j = 0; j < 12; j++) {
            //zobrist_piece_rands[i][j] = random_number();
        //}
    //}

    //zobrist_black_move = random_number();

    //for (int i = 0; i < 16; i++) {
        //zobrist_castling_rights[i] = random_number();
    //}

    //for (int i = 0; i < 17; i++) {
        //zobrist_passant[i] = random_number();
    //}
//}

//bitboard Zobrist::get_zobrist_key(Position* pos) {
    //bitboard zobrist_hashkey = 0;

    //for (short i = 0; i < 64; i++) {
        //bitboard square = 0x01;
        //square <<= i;

        //// Piece is white
        //if (pos->maps[w_pieces] bitand square) {
            //if (pos->maps[w_pawn] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_w_pawn];
            //}
            //else if (pos->maps[w_knight] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_w_knight];
            //}
            //else if (pos->maps[w_rook] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_w_rook];
            //}
            //else if (pos->maps[w_bishop] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_w_bishop];
            //}
            //else if (pos->maps[w_queen] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_w_queen];
            //}
            //else if (pos->maps[w_king] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_w_king];
            //}
        //}
        //else if (pos->maps[b_pieces] bitand square) {
            //if (pos->maps[b_pawn] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_b_pawn];
            //}
            //else if (pos->maps[b_knight] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_b_knight];
            //}
            //else if (pos->maps[b_rook] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_b_rook];
            //}
            //else if (pos->maps[b_bishop] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_b_bishop];
            //}
            //else if (pos->maps[b_queen] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_b_queen];
            //}
            //else if (pos->maps[b_king] bitand square) {
                //zobrist_hashkey xor_eq zobrist_piece_rands[i][z_b_king];
            //}

        //}
    //}
    //zobrist_hashkey xor_eq zobrist_castling_rights[pos->maps[castle_rights]];     // Castling rights
    //zobrist_hashkey xor_eq zobrist_passant[zp_passant.at(pos->maps[passant_sq])]; // Passant Square

    //if (pos->is_black_move()) {
        //zobrist_hashkey xor_eq zobrist_black_move;
    //}

    //return zobrist_hashkey;
//}
