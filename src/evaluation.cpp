#include <ranges>

#include "common.hpp"
#include "position.hpp"
#include "psqt_state.hpp"

#include "evaluation.hpp"

#include "eval_types.hpp"
#include "square.hpp"

namespace Clockwork {

// clang-format off
const PScore PAWN_MAT     = S(272,462);
const PScore KNIGHT_MAT   = S(746,961);
const PScore BISHOP_MAT   = S(763,1010);
const PScore ROOK_MAT     = S(1183,1712);
const PScore QUEEN_MAT    = S(2530,3135);
const PScore MOBILITY_VAL = S(21,7);
const PScore TEMPO_VAL    = S(30,12);

const PScore BISHOP_PAIR_VAL = S(64,199);
const PScore DOUBLED_PAWN_VAL = S(-72,-121);

const std::array<PScore, 48> PAWN_PSQT = {
    S(-125,509),    S(29,464),      S(111,485),     S(249,249),     S(209,257),     S(286,328),     S(135,377),     S(213,380),
    S(-10,152),     S(119,208),     S(70,97),       S(175,7),       S(109,15),      S(27,82),       S(-45,135),     S(-97,110),
    S(-36,-14),     S(-4,-22),      S(-32,-66),     S(-25,-101),    S(-39,-78),     S(-91,-85),     S(-116,-18),    S(-156,18),
    S(-33,-111),    S(22,-86),      S(-44,-121),    S(-56,-113),    S(-58,-135),    S(-115,-124),   S(-146,-47),    S(-193,-48),
    S(14,-151),     S(100,-142),    S(1,-105),      S(-69,-89),     S(-78,-107),    S(-134,-110),   S(-144,-67),    S(-188,-69),
    S(-28,-144),    S(160,-163),    S(45,-113),     S(-91,-65),     S(-143,-132),   S(-155,-98),    S(-171,-45),    S(-200,-56),
};

const std::array<PScore, 64> KNIGHT_PSQT = {
    S(-359,-261),   S(-39,-89),     S(-411,218),    S(97,56),       S(-134,107),    S(-210,153),    S(-199,-41),    S(-455,-88),
    S(62,-79),      S(93,80),       S(266,-12),     S(133,57),      S(198,79),      S(152,-26),     S(2,-8),        S(51,-78),
    S(109,14),      S(161,125),     S(304,72),      S(247,44),      S(208,70),      S(109,69),      S(40,121),      S(-72,35),
    S(172,-7),      S(107,85),      S(193,72),      S(107,104),     S(140,101),     S(71,98),       S(3,77),        S(-12,54),
    S(13,-1),       S(137,53),      S(49,81),       S(55,79),       S(10,111),      S(14,103),      S(-30,98),      S(-69,-31),
    S(-69,-32),     S(11,0),        S(-16,3),       S(27,56),       S(30,55),       S(-90,45),      S(-59,19),      S(-118,-22),
    S(-23,4),       S(-2,0),        S(-34,18),      S(-36,25),      S(-39,-4),      S(-106,27),     S(-117,-15),    S(-175,-107),
    S(-239,-14),    S(-53,-101),    S(-33,-69),     S(-21,-35),     S(-55,-35),     S(-61,-125),    S(-126,-50),    S(-238,-64),
};

const std::array<PScore, 64> BISHOP_PSQT = {
    S(-168,88),     S(-56,25),      S(-465,112),    S(-209,85),     S(-317,142),    S(-388,105),    S(-64,110),     S(-16,69),
    S(-38,-43),     S(-32,103),     S(37,45),       S(31,22),       S(-38,81),      S(-24,77),      S(-18,50),      S(-130,37),
    S(73,39),       S(86,66),       S(261,31),      S(110,48),      S(63,67),       S(1,86),        S(92,35),       S(22,40),
    S(79,-36),      S(1,66),        S(112,18),      S(92,45),       S(129,22),      S(38,59),       S(-1,61),       S(-85,101),
    S(-1,-30),      S(12,25),       S(5,32),        S(53,40),       S(32,74),       S(-13,49),      S(-16,26),      S(-47,-24),
    S(49,-27),      S(29,-15),      S(64,-16),      S(-14,44),      S(-23,58),      S(-35,68),      S(3,-19),       S(11,-41),
    S(-24,-85),     S(94,-45),      S(45,-32),      S(-10,1),       S(-28,-21),     S(0,-6),        S(-39,6),       S(16,-157),
    S(-52,1),       S(-56,7),       S(-74,20),      S(-36,-50),     S(-61,-46),     S(-35,-43),     S(-34,-80),     S(-85,-22),
};

const std::array<PScore, 64> ROOK_PSQT = {
    S(209,-23),     S(323,-14),     S(95,66),       S(115,50),      S(178,0),       S(54,55),       S(115,33),      S(116,39),
    S(253,-8),      S(175,56),      S(319,-1),      S(178,73),      S(182,72),      S(75,105),      S(45,94),       S(81,84),
    S(88,47),       S(268,-4),      S(210,9),       S(173,19),      S(87,39),       S(22,101),      S(37,68),       S(-30,86),
    S(3,52),        S(23,37),       S(48,42),       S(53,2),        S(19,20),       S(-41,113),     S(-49,73),      S(-129,97),
    S(-117,-33),    S(7,-45),       S(-62,27),      S(-67,16),      S(-102,24),     S(-135,81),     S(-174,82),     S(-178,61),
    S(-118,-54),    S(12,-124),     S(-69,-39),     S(-96,-20),     S(-88,-37),     S(-159,33),     S(-175,18),     S(-186,13),
    S(-131,-6),     S(-43,-97),     S(-41,-73),     S(-73,-41),     S(-83,-37),     S(-110,-17),    S(-163,-30),    S(-190,-34),
    S(-133,-17),    S(-66,3),       S(-59,-20),     S(-35,-28),     S(-63,-4),      S(-75,-13),     S(-93,-32),     S(-130,-18),

};

const std::array<PScore, 64> QUEEN_PSQT = {
    S(156,58),      S(139,42),      S(146,181),     S(154,135),     S(133,103),     S(-3,233),      S(70,80),       S(2,53),
    S(160,110),     S(-57,313),     S(100,272),     S(-60,419),     S(-35,305),     S(-100,300),    S(-83,194),     S(6,85),
    S(155,161),     S(203,121),     S(209,177),     S(70,245),      S(-49,290),     S(-60,221),     S(-13,106),     S(24,12),
    S(71,151),      S(14,209),      S(-17,209),     S(-56,259),     S(-69,196),     S(-44,87),      S(-57,69),      S(-40,72),
    S(-18,136),     S(13,92),       S(-70,204),     S(-78,148),     S(-110,148),    S(-113,108),    S(-57,-39),     S(-74,-16),
    S(13,-114),     S(-4,-32),      S(-36,45),      S(-100,66),     S(-72,-27),     S(-73,-54),     S(-56,-74),     S(-62,-17),
    S(26,-231),     S(6,-283),      S(-12,-156),    S(2,-152),      S(-53,-87),     S(-18,-193),    S(-50,-114),    S(-80,-11),
    S(-58,-184),    S(-35,-430),    S(-53,-256),    S(-15,-274),    S(43,-262),     S(20,-276),     S(-45,-130),    S(-93,-10),
};

const std::array<PScore, 64> KING_PSQT = {
    S(481,-522),    S(348,-101),    S(-258,146),    S(-377,159),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(244,-40),     S(-161,140),    S(-139,151),    S(-67,114),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(-129,118),    S(-118,125),    S(-53,105),     S(-71,53),      S(0,0), S(0,0), S(0,0), S(0,0),
    S(-261,110),    S(-214,144),    S(-98,100),     S(-184,80),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(-205,30),     S(-218,76),     S(-177,82),     S(-341,138),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(-113,-32),    S(-94,-14),     S(-245,61),     S(-346,122),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(138,-128),    S(62,-109),     S(-82,-32),     S(-222,30),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(203,-243),    S(173,-181),    S(4,-120),      S(19,-160),     S(0,0), S(0,0), S(0,0), S(0,0),
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
