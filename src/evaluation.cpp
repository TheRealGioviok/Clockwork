#include <ranges>

#include "common.hpp"
#include "position.hpp"
#include "psqt_state.hpp"

#include "evaluation.hpp"

#include "eval_types.hpp"
#include "square.hpp"

namespace Clockwork {

// clang-format off
const PScore PAWN_MAT     = S(298,432);
const PScore KNIGHT_MAT   = S(830,750);
const PScore BISHOP_MAT   = S(853,795);
const PScore ROOK_MAT     = S(1283,1401);
const PScore QUEEN_MAT    = S(3506,1870);
const PScore MOBILITY_VAL = S(16,8);
const PScore TEMPO_VAL    = S(23,5);

const PScore BISHOP_PAIR_VAL = S(80,167);
const PScore DOUBLED_PAWN_VAL = S(-70,-125);

const std::array<PScore, 48> PAWN_PSQT = {
    S(80,292),      S(62,390),      S(352,281),     S(290,199),     S(265,149),     S(362,190),     S(203,278),     S(235,276),
    S(8,119),       S(167,118),     S(106,59),      S(100,37),      S(75,23),       S(53,33),       S(-15,86),      S(-121,119),
    S(-40,-20),     S(6,-30),       S(-13,-74),     S(-7,-99),      S(-19,-93),     S(-80,-78),     S(-92,-29),     S(-151,10),
    S(-50,-85),     S(22,-85),      S(-31,-120),    S(-26,-127),    S(-38,-133),    S(-91,-115),    S(-110,-62),    S(-176,-49),
    S(-4,-118),     S(87,-124),     S(-17,-100),    S(-64,-105),    S(-75,-113),    S(-119,-110),   S(-121,-73),    S(-172,-71),
    S(-38,-111),    S(118,-125),    S(11,-98),      S(-103,-78),    S(-135,-118),   S(-142,-91),    S(-142,-55),    S(-188,-47),
};

const std::array<PScore, 64> KNIGHT_PSQT = {
    S(-382,-55),    S(-100,21),     S(-304,127),    S(125,-2),      S(-67,76),      S(-124,87),     S(-255,30),     S(-463,11),
    S(6,-66),       S(33,45),       S(229,-19),     S(125,63),      S(166,76),      S(95,1),        S(21,5),        S(-4,-45),
    S(64,38),       S(190,61),      S(255,47),      S(246,24),      S(187,44),      S(121,52),      S(94,28),       S(12,-5),
    S(135,0),       S(64,61),       S(145,53),      S(80,73),       S(86,84),       S(78,74),       S(33,37),       S(25,-7),
    S(19,-12),      S(77,18),       S(31,56),       S(60,56),       S(15,73),       S(39,67),       S(33,16),       S(-26,-40),
    S(-60,-59),     S(27,-23),      S(7,-29),       S(34,28),       S(31,30),       S(-48,0),       S(-38,-13),     S(-79,-80),
    S(-10,-45),     S(-24,0),       S(-8,-25),      S(-11,-16),     S(-4,-33),      S(-40,-51),     S(-70,-30),     S(-94,-142),
    S(-201,18),     S(-44,-130),    S(-55,-74),     S(-8,-69),      S(-70,-50),     S(-77,-114),    S(-64,-145),    S(-246,-128),
};

const std::array<PScore, 64> BISHOP_PSQT = {
    S(-96,37),      S(-72,38),      S(-82,11),      S(-114,28),     S(-159,52),     S(-217,64),     S(-118,84),     S(-56,62),
    S(-61,-3),      S(-74,63),      S(24,30),       S(28,22),       S(-68,69),      S(-5,44),       S(-11,30),      S(-68,13),
    S(43,38),       S(154,21),      S(259,-3),      S(136,3),       S(94,3),        S(68,30),       S(88,26),       S(23,5),
    S(28,-32),      S(8,36),        S(95,8),        S(81,14),       S(106,8),       S(48,23),       S(-5,54),       S(-19,7),
    S(29,-43),      S(37,-4),       S(-11,33),      S(60,1),        S(48,31),       S(-21,47),      S(8,0), S(0,-38),
    S(43,-28),      S(27,-14),      S(35,-23),      S(-7,27),       S(-8,28),       S(-13,23),      S(17,-34),      S(-12,-34),
    S(22,-89),      S(79,-47),      S(44,-44),      S(-3,-20),      S(-33,-24),     S(21,-49),      S(-6,-41),      S(33,-106),
    S(-26,-76),     S(-132,15),     S(-69,-31),     S(-48,-42),     S(-61,-52),     S(-25,-88),     S(-22,-65),     S(-59,-33),
};

const std::array<PScore, 64> ROOK_PSQT = {
    S(275,-40),     S(263,-7),      S(88,78),       S(106,61),      S(152,12),      S(154,0),       S(125,6),       S(109,16),
    S(211,2),       S(162,27),      S(261,17),      S(186,47),      S(216,14),      S(134,33),      S(69,37),       S(70,40),
    S(51,63),       S(170,34),      S(193,31),      S(155,32),      S(93,27),       S(28,53),       S(68,32),       S(-13,66),
    S(-27,40),      S(0,40),        S(14,46),       S(27,12),       S(22,17),       S(-31,49),      S(-40,35),      S(-76,38),
    S(-150,8),      S(-53,-3),      S(-94,31),      S(-73,16),      S(-93,23),      S(-129,55),     S(-142,50),     S(-174,43),
    S(-151,-16),    S(-39,-61),     S(-92,-41),     S(-104,-39),    S(-104,-28),    S(-148,-1),     S(-139,-27),    S(-177,-17),
    S(-117,-41),    S(-56,-67),     S(-66,-61),     S(-84,-52),     S(-81,-57),     S(-102,-50),    S(-138,-60),    S(-184,-59),
    S(-126,-54),    S(-98,-12),     S(-61,-33),     S(-23,-65),     S(-42,-44),     S(-64,-36),     S(-81,-60),     S(-109,-45),

};

const std::array<PScore, 64> QUEEN_PSQT = {
    S(124,77),      S(128,80),      S(155,130),     S(77,190),      S(60,149),      S(-13,188),     S(-4,158),      S(-15,88),
    S(117,96),      S(-69,269),     S(92,214),      S(-43,320),     S(-41,262),     S(-54,219),     S(-102,175),    S(10,41),
    S(99,147),      S(162,156),     S(135,163),     S(42,218),      S(-39,244),     S(-40,155),     S(-5,81),       S(15,16),
    S(61,112),      S(-3,198),      S(-8,165),      S(-58,191),     S(-84,202),     S(-49,101),     S(-61,78),      S(-5,-6),
    S(-21,118),     S(12,38),       S(-54,143),     S(-46,59),      S(-80,121),     S(-79,58),      S(-58,10),      S(-40,-53),
    S(0,-62),       S(14,-64),      S(-18,2),       S(-50,-36),     S(-50,-83),     S(-73,-22),     S(-35,-116),    S(-26,-81),
    S(27,-313),     S(36,-396),     S(33,-277),     S(19,-214),     S(-7,-175),     S(11,-266),     S(-12,-172),    S(-8,-153),
    S(83,-576),     S(-22,-595),    S(-44,-369),    S(46,-372),     S(47,-291),     S(45,-355),     S(8,-241),      S(-28,-133),
};

const std::array<PScore, 64> KING_PSQT = {
    S(442,-460),    S(326,6),       S(229,63),      S(-99,32),      S(0,0), S(0,0), S(0,0), S(0,0),
    S(332,-92),     S(101,95),      S(40,88),       S(295,40),      S(0,0), S(0,0), S(0,0), S(0,0),
    S(167,36),      S(-6,74),       S(57,73),       S(-40,59),      S(0,0), S(0,0), S(0,0), S(0,0),
    S(80,4),        S(110,39),      S(68,49),       S(-34,63),      S(0,0), S(0,0), S(0,0), S(0,0),
    S(-79,-8),      S(-47,19),      S(-46,47),      S(-115,71),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(-118,-20),    S(-72,-13),     S(-168,37),     S(-192,64),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(47,-81),      S(-2,-62),      S(-105,-11),    S(-186,12),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(110,-171),    S(102,-121),    S(-21,-80),     S(39,-138),     S(0,0), S(0,0), S(0,0), S(0,0),
};

// clang-format on

Score evaluate_white_pov(const Position& pos, const PsqtState& psqt_state) {

    const Color us    = pos.active_color();
    i32         phase = pos.piece_count(Color::White, PieceType::Knight)
              + pos.piece_count(Color::Black, PieceType::Knight)
              + pos.piece_count(Color::White, PieceType::Bishop)
              + pos.piece_count(Color::Black, PieceType::Bishop)
              + 3
                  * (pos.piece_count(Color::White, PieceType::Rook)
                     + pos.piece_count(Color::Black, PieceType::Rook))
              + 6
                  * (pos.piece_count(Color::White, PieceType::Queen)
                     + pos.piece_count(Color::Black, PieceType::Queen));

    phase = std::min<i32>(phase, 32);

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

    PScore mobility = MOBILITY_VAL * mob_count;

    PScore tempo = (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;
    PScore sum   = psqt_state.score() + mobility + tempo + bishop_pair_bonus + doubled_pawns_bonus;
    return sum->phase<32>(phase);
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return (us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                : -evaluate_white_pov(pos, psqt_state);
}

}  // namespace Clockwork
