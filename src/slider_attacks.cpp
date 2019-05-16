#include "slider_attacks.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <array>

void SliderAttacks::Initialize() {
    std::array<bitboard, kSquares> rook_masks = {
        0x101010101017e, 0x202020202027c, 0x404040404047a, 0x8080808080876,
        0x1010101010106e, 0x2020202020205e, 0x4040404040403e, 0x8080808080807e,
        0x1010101017e00, 0x2020202027c00, 0x4040404047a00, 0x8080808087600, 
        0x10101010106e00, 0x20202020205e00, 0x40404040403e00, 0x80808080807e00, 
        0x10101017e0100, 0x20202027c0200, 0x40404047a0400, 0x8080808760800, 
        0x101010106e1000, 0x202020205e2000, 0x404040403e4000, 0x808080807e8000, 
        0x101017e010100, 0x202027c020200, 0x404047a040400, 0x8080876080800, 
        0x1010106e101000, 0x2020205e202000, 0x4040403e404000, 0x8080807e808000, 
        0x1017e01010100, 0x2027c02020200, 0x4047a04040400, 0x8087608080800, 
        0x10106e10101000, 0x20205e20202000, 0x40403e40404000, 0x80807e80808000, 
        0x17e0101010100, 0x27c0202020200, 0x47a0404040400, 0x8760808080800, 
        0x106e1010101000, 0x205e2020202000, 0x403e4040404000, 0x807e8080808000, 
        0x7e010101010100, 0x7c020202020200, 0x7a040404040400, 0x76080808080800, 
        0x6e101010101000, 0x5e202020202000, 0x3e404040404000, 0x7e808080808000, 
        0x7e01010101010100, 0x7c02020202020200, 0x7a04040404040400, 0x7608080808080800, 
        0x6e10101010101000, 0x5e20202020202000, 0x3e40404040404000, 0x7e80808080808000
    };

    std::array<bitboard, kSquares> bishop_masks = {
        0x40201008040200, 0x402010080400, 0x4020100a00, 0x40221400, 0x2442800, 
        0x204085000, 0x20408102000, 0x2040810204000, 0x20100804020000, 0x40201008040000, 
        0x4020100a0000, 0x4022140000, 0x244280000, 0x20408500000, 0x2040810200000, 
        0x4081020400000, 0x10080402000200, 0x20100804000400, 0x4020100a000a00, 
        0x402214001400, 0x24428002800, 0x2040850005000, 0x4081020002000, 
        0x8102040004000, 0x8040200020400, 0x10080400040800, 0x20100a000a1000, 
        0x40221400142200, 0x2442800284400, 0x4085000500800, 0x8102000201000, 
        0x10204000402000, 0x4020002040800, 0x8040004081000, 0x100a000a102000, 
        0x22140014224000, 0x44280028440200, 0x8500050080400, 0x10200020100800, 
        0x20400040201000, 0x2000204081000, 0x4000408102000, 0xa000a10204000, 
        0x14001422400000, 0x28002844020000, 0x50005008040200, 0x20002010080400, 
        0x40004020100800, 0x20408102000, 0x40810204000, 0xa1020400000, 0x142240000000, 
        0x284402000000, 0x500804020000, 0x201008040200, 0x402010080400, 0x2040810204000, 
        0x4081020400000, 0xa102040000000, 0x14224000000000, 0x28440200000000, 
        0x50080402000000, 0x20100804020000, 0x40201008040200
    };

    std::array<bitboard, kSquares> rook_magics = {
        0x880081080c00020, 0x210020c000308100, 0x80082001100280, 0x1001000a0050108, 
        0x200041029600a00, 0x5100010008220400, 0x8280120001000d80, 0x1880012100014080, 
        0x3040800340008020, 0x400400050026003, 0x21002000104902, 0x20900200a100100, 
        0xd800802840080, 0x2808004000600, 0x24001002110814, 0x2000800541000480, 
        0x8000ee8002400080, 0x24c04010002005, 0x822002401000c800, 0x2040808010000800, 
        0x804080800c000802, 0x2a0080110402004, 0x201044000810010a, 0x4080020004004483, 
        0x4d84400180228000, 0x1406400880200880, 0x801200402203, 0x1080080280100084, 
        0x402140080080080, 0xa880c0080020080, 0x342000200080405, 0x20004a8200050044, 
        0x8280c00020800889, 0x8002201000400940, 0x44a200101001542, 0x88090021005000, 
        0x3008004200c00400, 0x284120080800400, 0x4462106804000201, 0x1008240382000061, 
        0x80400080208002, 0x20100040004020, 0x4000802042020010, 0x40a002042120008, 
        0x12a008820120004, 0x6000408020010, 0x2008405020008, 0x80100c0040820003, 
        0x2800100446100, 0xa0982002400080, 0x9a0080010014040, 0x380c209200420a00, 
        0xc04008108000580, 0xc002008004002280, 0x2900842a000100, 0x40100008a004300, 
        0x10211800020c3, 0xa08412050242, 0x2001004010200489, 0xa00081000210045, 
        0x4512002810204402, 0x8c22000401102802, 0x485000082005401, 0x100208400ce
    };

    std::array<bitboard, kSquares> bishop_magics = {
        0x820420460402a080, 0x20021200451400, 0x10011200218000, 0x4040888100800, 
        0x6211001000400, 0x401042240021400, 0x884029888090060, 0x24202808080810, 
        0x20242038024080, 0x80021081010102, 0x100004090c030120, 0x210c0420814205, 
        0x408311040061010, 0x4900011016100900, 0x6841020d30461020, 0x220112088080800, 
        0x8040000802080628, 0x4a48000408480040, 0x2010000e00b20060, 0x1004020809409102, 
        0x1011090400801, 0x2002000420842000, 0xa01200443a090402, 0x1010082a4020221, 
        0x7118c00204100682, 0x2223440021040c00, 0xa208018c08020142, 0x4404004010200, 
        0x14840004802000, 0x204016024100401, 0x23021a0005451020, 0x204222022c10410, 
        0x122010002002b0, 0x2501000022200, 0x84002804001800a1, 0x1002080800060a00, 
        0x40018020120220, 0x41108881004a0100, 0x800c041410224502, 0x4001020080006403, 
        0x205091140081002, 0x491210901c001808, 0x400084048001000, 0x8824200910800, 
        0xca00400408228102, 0x2042240800221200, 0x54082081000405, 0x1010202004291, 
        0x4040a40920100100, 0x4802060101082c10, 0x208002623100105, 0x1000e2c084040010, 
        0x202302400682008a, 0x20820c50024a0c10, 0x200c20020c090100, 0x684010822028800, 
        0x400e002101482012, 0x800804218044242, 0x8a0040201008820, 0xc000000024420200, 
        0x3404102090c20200, 0x8000840810104981, 0x80330810d0009101, 0x4011001020084
    };

    std::array<int, kSquares> rook_offsets = {
        0x0, 0x1000, 0x1800, 0x2000, 0x2800, 0x3000, 0x3800, 0x4000, 0x5000, 0x5800, 
        0x5c00, 0x6000, 0x6400, 0x6800, 0x6c00, 0x7000, 0x7800, 0x8000, 0x8400, 0x8800, 
        0x8c00, 0x9000, 0x9400, 0x9800, 0xa000, 0xa800, 0xac00, 0xb000, 0xb400, 0xb800, 
        0xbc00, 0xc000, 0xc800, 0xd000, 0xd400, 0xd800, 0xdc00, 0xe000, 0xe400, 0xe800, 
        0xf000, 0xf800, 0xfc00, 0x10000, 0x10400, 0x10800, 0x10c00, 0x11000, 0x11800, 
        0x12000, 0x12400, 0x12800, 0x12c00, 0x13000, 0x13400, 0x13800, 0x14000, 0x15000, 
        0x15800, 0x16000, 0x16800, 0x17000, 0x17800, 0x18000
    };

    std::array<int, kSquares> bishop_offsets = {
        0x0, 0x40, 0x60, 0x80, 0xa0, 0xc0, 0xe0, 0x100, 0x140, 0x160, 0x180, 0x1a0, 0x1c0, 
        0x1e0, 0x200, 0x220, 0x240, 0x260, 0x280, 0x300, 0x380, 0x400, 0x480, 0x4a0, 0x4c0, 
        0x4e0, 0x500, 0x580, 0x780, 0x980, 0xa00, 0xa20, 0xa40, 0xa60, 0xa80, 0xb00, 0xd00, 
        0xf00, 0xf80, 0xfa0, 0xfc0, 0xfe0, 0x1000, 0x1080, 0x1100, 0x1180, 0x1200, 0x1220, 
        0x1240, 0x1260, 0x1280, 0x12a0, 0x12c0, 0x12e0, 0x1300, 0x1320, 0x1340, 0x1380, 
        0x13a0, 0x13c0, 0x13e0, 0x1400, 0x1420, 0x1440
    };

    std::array<int, kSquares> rook_shifts = {
        0xc, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xc, 0xb, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xb, 0xb, 
        0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xb, 0xb, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xb, 0xb, 0xa, 
        0xa, 0xa, 0xa, 0xa, 0xa, 0xb, 0xb, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xb, 0xb, 0xa, 0xa, 
        0xa, 0xa, 0xa, 0xa, 0xb, 0xc, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xc
    };

    std::array<int, kSquares> bishop_shifts = {
        0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 
        0x5, 0x7, 0x7, 0x7, 0x7, 0x5, 0x5, 0x5, 0x5, 0x7, 0x9, 0x9, 0x7, 0x5, 0x5, 0x5, 0x5, 
        0x7, 0x9, 0x9, 0x7, 0x5, 0x5, 0x5, 0x5, 0x7, 0x7, 0x7, 0x7, 0x5, 0x5, 0x5, 0x5, 0x5, 
        0x5, 0x5, 0x5, 0x5, 0x5, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x6
    };

    rook_attack_table_.shrink_to_fit();

    bishop_attack_table_.shrink_to_fit();

    for (int i = 0; i < kSquares; ++i) {
        rook_magics_[i] = { rook_masks.at(i), rook_magics.at(i),
            rook_shifts.at(i), rook_offsets.at(i) };
        bishop_magics_[i] = { bishop_masks.at(i), bishop_magics.at(i),
            bishop_shifts.at(i), bishop_offsets.at(i) };
    }
}
