#include <ranges>

#include "common.hpp"
#include "position.hpp"
#include "psqt_state.hpp"

#include "evaluation.hpp"

#include "eval_types.hpp"
#include "square.hpp"

namespace Clockwork {

// clang-format off
const PScore PAWN_MAT     = S(300,512);
const PScore KNIGHT_MAT   = S(917,1128);
const PScore BISHOP_MAT   = S(959,1161);
const PScore ROOK_MAT     = S(1305,2110);
const PScore QUEEN_MAT    = S(2693,3897);
const PScore MOBILITY_VAL = S(18,15);
const PScore TEMPO_VAL    = S(70,78);

const PScore BISHOP_PAIR_VAL =  S(67,232);
const PScore DOUBLED_PAWN_VAL = S(-58,-159);

const std::array<PScore, 48> PAWN_PSQT = {
    S(-195,652),    S(-91,583),     S(106,513),     S(206,324),     S(193,309),     S(173,373),     S(129,469),     S(3,510),
    S(-14,281),     S(92,293),      S(116,129),     S(63,104),      S(52,102),      S(68,104),      S(-56,231),     S(-132,223),
    S(-18,-21),     S(35,-38),      S(4,-94),       S(8,-131),      S(-43,-116),    S(-72,-96),     S(-81,-39),     S(-173,9),
    S(-43,-106),    S(10,-97),      S(-27,-140),    S(-21,-145),    S(-39,-150),    S(-93,-136),    S(-112,-85),    S(-207,-67),
    S(-1,-140),     S(84,-114),     S(-9,-120),     S(-27,-115),    S(-64,-117),    S(-100,-131),   S(-120,-84),    S(-211,-78),
    S(-32,-150),    S(133,-137),    S(29,-119),     S(-62,-68),     S(-121,-109),   S(-131,-107),   S(-133,-70),    S(-211,-59),
};

const std::array<PScore, 64> KNIGHT_PSQT = {
    S(-308,-287),   S(-252,-57),    S(-190,-21),    S(82,-16),      S(-101,55),     S(-177,45),     S(-400,72),     S(-402,-166),
    S(68,-59),      S(84,10),       S(265,-26),     S(76,28),       S(169,17),      S(109,49),      S(58,74),       S(24,10),
    S(122,-6),      S(182,26),      S(289,16),      S(277,37),      S(169,94),      S(158,90),      S(115,63),      S(37,39),
    S(128,35),      S(64,112),      S(172,109),     S(81,138),      S(132,137),     S(83,127),      S(33,112),      S(34,84),
    S(13,46),       S(64,66),       S(36,101),      S(59,129),      S(32,130),      S(16,134),      S(23,86),       S(-38,71),
    S(-36,14),      S(31,32),       S(6,31),        S(53,90),       S(17,97),       S(-39,51),      S(-45,51),      S(-92,9),
    S(-14,29),      S(-22,17),      S(17,25),       S(7,41),        S(1,37),        S(-49,44),      S(-72,11),      S(-96,-13),
    S(-144,-3),     S(-61,-16),     S(-15,3),       S(-27,39),      S(-36,17),      S(-86,1),       S(-62,-43),     S(-225,-22),
};

const std::array<PScore, 64> BISHOP_PSQT = {
    S(-133,-4),     S(-125,54),     S(-165,51),     S(-250,79),     S(-298,97),     S(-233,64),     S(-149,61),     S(-69,54),
    S(-61,-4),      S(-40,57),      S(15,25),       S(33,12),       S(-63,57),      S(17,32),       S(85,22),       S(-4,5),
    S(74,65),       S(128,38),      S(177,36),      S(67,39),       S(85,1),        S(74,36),       S(63,39),       S(35,64),
    S(-13,49),      S(3,57),        S(62,60),       S(73,46),       S(101,64),      S(58,40),       S(4,76),        S(-16,52),
    S(10,-5),       S(-14,58),      S(-16,48),      S(62,41),       S(61,44),       S(-31,82),      S(-21,65),      S(-25,39),
    S(63,6),        S(20,23),       S(31,38),       S(13,58),       S(5,52),        S(5,58),        S(7,57),        S(-9,22),
    S(29,-9),       S(88,7),        S(67,4),        S(7,26),        S(-20,28),      S(46,-21),      S(3,-3),        S(37,0),
    S(21,-56),      S(29,7),        S(-34,44),      S(1,16),        S(-15,11),      S(3,-21),       S(44,36),       S(-36,-24),
};

const std::array<PScore, 64> ROOK_PSQT = {
    S(147,36),      S(-49,113),     S(96,87),       S(64,60),       S(-3,97),       S(7,104),       S(39,73),       S(36,83),
    S(244,-12),     S(153,54),      S(186,60),      S(62,91),       S(106,98),      S(46,128),      S(-1,119),      S(13,98),
    S(163,-4),      S(220,21),      S(125,27),      S(80,51),       S(-7,78),       S(-8,97),       S(16,87),       S(-45,97),
    S(6,39),        S(-4,45),       S(-4,50),       S(-39,57),      S(-35,73),      S(-62,98),      S(-52,78),      S(-87,99),
    S(-81,18),      S(-36,22),      S(-99,46),      S(-69,49),      S(-84,64),      S(-117,76),     S(-141,72),     S(-145,78),
    S(-34,-35),     S(17,-50),      S(-65,-3),      S(-72,13),      S(-107,40),     S(-125,30),     S(-121,23),     S(-157,44),
    S(-74,-18),     S(21,-43),      S(-34,-10),     S(-48,2),       S(-64,17),      S(-65,15),      S(-125,29),     S(-151,23),
    S(-111,-37),    S(-49,17),      S(-54,21),      S(-10,2),       S(-24,14),      S(-48,24),      S(-75,13),      S(-105,16),
};

const std::array<PScore, 64> QUEEN_PSQT = {
    S(80,66),       S(216,31),      S(93,241),      S(57,238),      S(42,211),      S(-51,264),     S(-106,224),    S(-45,184),
    S(187,157),     S(-7,258),      S(38,334),      S(-122,447),    S(-96,370),     S(-63,283),     S(-47,208),     S(41,147),
    S(152,194),     S(162,194),     S(78,321),      S(-25,334),     S(-59,312),     S(-30,253),     S(17,138),      S(63,121),
    S(37,237),      S(-41,317),     S(-58,310),     S(-109,318),    S(-99,275),     S(-73,213),     S(-57,185),     S(-16,151),
    S(9,184),       S(-37,224),     S(-90,236),     S(-79,231),     S(-96,235),     S(-112,205),    S(-80,181),     S(-57,166),
    S(20,86),       S(2,131),       S(-40,157),     S(-74,163),     S(-79,133),     S(-74,158),     S(-45,121),     S(-21,85),
    S(50,-80),      S(39,-69),      S(40,-16),      S(0,62),        S(-8,54),       S(-6,44),       S(-22,67),      S(35,-5),
    S(24,-132),     S(-15,-39),     S(-36,53),      S(30,1),        S(33,57),       S(22,6),        S(4,24),        S(-18,44),
};

const std::array<PScore, 64> KING_PSQT = {
    S(463,-371),    S(228,-139),    S(209,-96),     S(-140,-9),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(-161,9),      S(-61,73),      S(-162,105),    S(46,44),       S(0,0), S(0,0), S(0,0), S(0,0),
    S(-203,63),     S(-7,97),       S(-44,126),     S(-186,156),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(-333,51),     S(-302,102),    S(-336,146),    S(-453,175),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(-346,15),     S(-333,41),     S(-357,98),     S(-467,149),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(-121,-41),    S(-116,-35),    S(-279,36),     S(-298,74),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(127,-123),    S(52,-110),     S(-83,-41),     S(-157,-6),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(223,-247),    S(169,-172),    S(53,-109),     S(61,-136),     S(0,0), S(0,0), S(0,0), S(0,0),
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

    PScore mobility = MOBILITY_VAL * mob_count;

    PScore tempo = (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;
    PScore sum   = psqt_state.score() + mobility + tempo + bishop_pair_bonus + doubled_pawns_bonus;
    return sum->phase<24>(phase);
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return (us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                : -evaluate_white_pov(pos, psqt_state);
}

}  // namespace Clockwork
