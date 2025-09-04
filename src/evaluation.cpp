#include <ranges>

#include "common.hpp"
#include "position.hpp"
#include "psqt_state.hpp"

#include "evaluation.hpp"

#include "eval_types.hpp"
#include "square.hpp"

namespace Clockwork {

// clang-format off
const PScore PAWN_MAT     = S(305,420);
const PScore KNIGHT_MAT   = S(876,696);
const PScore BISHOP_MAT   = S(907,739);
const PScore ROOK_MAT     = S(1425,1294);
const PScore QUEEN_MAT    = S(3897,1569);
const PScore MOBILITY_VAL = S(14,7);
const PScore TEMPO_VAL    = S(23,4);

const PScore BISHOP_PAIR_VAL = S(80,164);
const PScore DOUBLED_PAWN_VAL = S(-67,-122);
const PScore ROOK_NONOPEN_FILE_VAL = S(-82,22);

static Bitboard fill_verticals(const Bitboard mask) {
    Bitboard result = mask | (mask >> 8);
    result |= result >> 16;
    result |= result >> 32;
    return (result & Bitboard::rank_mask(0)) * Bitboard::file_mask(0);
}

const std::array<PScore, 48> PAWN_PSQT = {
S(55,283),      S(40,367),      S(403,255),     S(291,188),     S(286,132),     S(370,182),     S(186,269),     S(246,265),
S(-4,113),      S(156,109),     S(103,56),      S(97,34),       S(66,27),       S(52,35),       S(-29,84),      S(-132,122),
S(-55,-14),     S(0,-29),       S(-13,-71),     S(-1,-101),     S(-15,-91),     S(-79,-75),     S(-93,-26),     S(-161,15),
S(-63,-75),     S(16,-79),      S(-34,-116),    S(-25,-121),    S(-38,-126),    S(-92,-112),    S(-111,-57),    S(-182,-42),
S(-18,-106),    S(82,-114),     S(-29,-91),     S(-72,-100),    S(-82,-104),    S(-124,-104),   S(-125,-69),    S(-179,-65),
S(-52,-98),     S(109,-111),    S(0,-88),       S(-113,-69),    S(-142,-115),   S(-148,-86),    S(-147,-49),    S(-196,-40),
};

const std::array<PScore, 64> KNIGHT_PSQT = {
S(-397,5),      S(-248,51),     S(-345,146),    S(91,2),        S(-116,89),     S(-115,82),     S(-355,38),     S(-468,34),
S(20,-71),      S(12,43),       S(234,-16),     S(116,76),      S(143,82),      S(99,-4),       S(11,4),        S(-2,-44),
S(59,35),       S(190,58),      S(266,40),      S(263,15),      S(187,41),      S(119,42),      S(107,17),      S(-8,-3),
S(145,-6),      S(70,61),       S(156,46),      S(93,57),       S(96,76),       S(94,66),       S(44,26),       S(29,-9),
S(28,-18),      S(87,14),       S(39,50),       S(70,51),       S(22,71),       S(50,60),       S(54,5),        S(-13,-47),
S(-50,-60),     S(38,-21),      S(19,-30),      S(42,23),       S(40,23),       S(-34,-6),      S(-23,-18),     S(-66,-87),
S(9,-47),       S(-13,-5),      S(4,-25),       S(-1,-17),      S(5,-39),       S(-26,-62),     S(-51,-43),     S(-74,-153),
S(-220,29),     S(-39,-127),    S(-48,-75),     S(3,-78),       S(-63,-57),     S(-56,-123),    S(-55,-149),    S(-252,-122),
};

const std::array<PScore, 64> BISHOP_PSQT = {
S(-89,36),      S(-64,34),      S(-3,-8),       S(-77,23),      S(-144,49),     S(-281,78),     S(-123,85),     S(-88,74),
S(-52,-7),      S(-83,56),      S(3,33),        S(33,20),       S(-78,72),      S(-9,45),       S(-16,31),      S(-70,18),
S(38,33),       S(148,18),      S(274,-14),     S(122,5),       S(104,-2),      S(64,25),       S(86,23),       S(7,6),
S(27,-31),      S(8,36),        S(99,2),        S(83,9),        S(111,2),       S(46,19),       S(-9,52),       S(-26,11),
S(25,-37),      S(41,-7),       S(-10,37),      S(64,0),        S(46,30),       S(-19,46),      S(10,1),        S(0,-39),
S(40,-24),      S(28,-9),       S(31,-23),      S(-8,31),       S(-7,28),       S(-17,25),      S(22,-41),      S(-15,-36),
S(25,-93),      S(78,-50),      S(42,-43),      S(-5,-23),      S(-33,-26),     S(25,-55),      S(-4,-51),      S(38,-102),
S(-30,-74),     S(-135,19),     S(-72,-29),     S(-48,-36),     S(-69,-53),     S(-28,-91),     S(-31,-63),     S(-55,-37),
};

const std::array<PScore, 64> ROOK_PSQT = {
S(367,-73),     S(335,-33),     S(89,66),       S(74,69),       S(115,22),      S(139,5),       S(90,13),       S(70,29),
S(219,-6),      S(202,8),       S(221,29),      S(161,60),      S(215,13),      S(120,30),      S(55,35),       S(51,41),
S(19,74),       S(169,37),      S(201,28),      S(135,53),      S(62,33),       S(23,56),       S(83,30),       S(-17,65),
S(-28,32),      S(10,29),       S(23,33),       S(31,8),        S(2,23),        S(-30,42),      S(-24,27),      S(-70,31),
S(-145,2),      S(-43,-12),     S(-94,28),      S(-78,16),      S(-98,20),      S(-141,56),     S(-144,46),     S(-164,36),
S(-135,-24),    S(-26,-68),     S(-81,-40),     S(-98,-48),     S(-106,-34),    S(-150,-6),     S(-123,-34),    S(-163,-23),
S(-120,-44),    S(-37,-73),     S(-45,-78),     S(-85,-54),     S(-79,-64),     S(-104,-48),    S(-128,-58),    S(-170,-61),
S(-113,-53),    S(-94,-12),     S(-47,-33),     S(-15,-70),     S(-41,-50),     S(-62,-34),     S(-71,-59),     S(-94,-46),
};

const std::array<PScore, 64> QUEEN_PSQT = {
S(149,47),      S(133,74),      S(182,115),     S(65,196),      S(22,170),      S(-75,230),     S(-69,188),     S(-3,86),
S(96,96),       S(-87,259),     S(83,189),      S(-72,305),     S(-65,258),     S(-73,213),     S(-119,156),    S(-9,33),
S(96,118),      S(150,149),     S(122,161),     S(45,202),      S(-41,221),     S(-43,143),     S(-25,81),      S(16,15),
S(63,65),       S(-7,175),      S(-20,155),     S(-62,179),     S(-91,184),     S(-50,92),      S(-61,51),      S(-11,-15),
S(-24,104),     S(14,24),       S(-57,127),     S(-44,46),      S(-83,114),     S(-73,46),      S(-56,6),       S(-39,-51),
S(-2,-40),      S(16,-61),      S(-17,-7),      S(-44,-48),     S(-42,-91),     S(-68,-34),     S(-28,-121),    S(-29,-74),
S(35,-306),     S(54,-385),     S(39,-248),     S(24,-209),     S(0,-192),      S(20,-254),     S(2,-170),      S(-9,-149),
S(78,-513),     S(-8,-528),     S(-40,-348),    S(48,-336),     S(45,-241),     S(52,-326),     S(8,-217),      S(-21,-139),
};

const std::array<PScore, 64> KING_PSQT = {
S(414,-432),    S(250,25),      S(189,72),      S(-160,48),     S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(296,-76),     S(49,101),      S(-38,93),      S(288,50),      S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(120,38),      S(-76,77),      S(-7,77),       S(-144,73),     S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(51,8),        S(77,40),       S(51,48),       S(-79,66),      S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(-69,-13),     S(-49,16),      S(-49,45),      S(-117,67),     S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(-132,-20),    S(-79,-12),     S(-170,36),     S(-196,60),     S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(23,-69),      S(-16,-54),     S(-109,-12),    S(-184,8),      S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
S(93,-157),     S(91,-115),     S(-27,-79),     S(40,-136),     S(-11,3),       S(-11,3),       S(-11,3),       S(-11,3),
};

// clang-format on

Score evaluate_white_pov(const Position& pos, const PsqtState& psqt_state) {

    const Color us    = pos.active_color();
    i32         phase = pos.piece_count(Color::White, PieceType::Knight)
              + pos.piece_count(Color::Black, PieceType::Knight)
              + pos.piece_count(Color::White, PieceType::Bishop)
              + pos.piece_count(Color::Black, PieceType::Bishop)
              + 2
                  * (pos.piece_count(Color::White, PieceType::Rook)
                     + pos.piece_count(Color::Black, PieceType::Rook))
              + 4
                  * (pos.piece_count(Color::White, PieceType::Queen)
                     + pos.piece_count(Color::Black, PieceType::Queen));

    phase = std::min<i32>(phase, 24);

    i32 mob_count = 0;
    for (u64 x : std::bit_cast<std::array<u64, 16>>(pos.attack_table(Color::White))) {
        mob_count += std::popcount(x);
    }
    for (u64 x : std::bit_cast<std::array<u64, 16>>(pos.attack_table(Color::Black))) {
        mob_count -= std::popcount(x);
    }

    const std::array<Bitboard, 2> pawns = {pos.board().bitboard_for(Color::White, PieceType::Pawn),
                                           pos.board().bitboard_for(Color::Black, PieceType::Pawn)};

    PScore doubled_pawns_bonus = DOUBLED_PAWN_VAL
                               * ((pawns[0] & pawns[0].shift(Direction::North)).popcount()
                                  - (pawns[1] & pawns[1].shift(Direction::South)).popcount());

    PScore bishop_pair_bonus = BISHOP_PAIR_VAL
                             * ((pos.piece_count(Color::White, PieceType::Bishop) >= 2)
                                - (pos.piece_count(Color::Black, PieceType::Bishop) >= 2));

    Bitboard open_files = fill_verticals(pos.board().bitboard_for(PieceType::Pawn));
    PScore   rook_nonopen_file_bonus =
      ROOK_NONOPEN_FILE_VAL
      * ((open_files & pos.board().bitboard_for(Color::White, PieceType::Rook)).popcount()
         - (open_files & pos.board().bitboard_for(Color::Black, PieceType::Rook)).popcount());

    PScore mobility = MOBILITY_VAL * mob_count;

    PScore tempo = (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;
    PScore sum   = psqt_state.score() + mobility + tempo + bishop_pair_bonus + doubled_pawns_bonus + rook_nonopen_file_bonus;
    return sum->phase<24>(phase);
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return (us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                : -evaluate_white_pov(pos, psqt_state);
}

}  // namespace Clockwork
