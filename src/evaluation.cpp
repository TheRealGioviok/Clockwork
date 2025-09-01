#include <ranges>

#include "common.hpp"
#include "position.hpp"
#include "psqt_state.hpp"

#include "evaluation.hpp"

#include "eval_types.hpp"
#include "square.hpp"

namespace Clockwork {

// clang-format off
const PScore PAWN_MAT     = S(151,258);
const PScore KNIGHT_MAT   = S(758,781);
const PScore BISHOP_MAT   = S(833,774);
const PScore ROOK_MAT     = S(986,1309);
const PScore QUEEN_MAT    = S(2525,2007);
const PScore MOBILITY_VAL = S(20, 5);
const PScore TEMPO_VAL    = S(20, 6);

const std::array<PScore, 48> PAWN_PSQT = {
    S(189,570),     S(74,670),      S(211,574),     S(250,511),     S(262,400),     S(376,343),     S(235,439),     S(301,429),
    S(56,345),      S(90,426),      S(142,352),     S(189,318),     S(150,279),     S(122,253),     S(67,292),      S(-36,319),
    S(39,212),      S(91,220),      S(85,179),      S(86,165),      S(88,144),      S(22,153),      S(23,189),      S(-42,223),
    S(21,161),      S(99,176),      S(85,119),      S(90,124),      S(76,108),      S(17,112),      S(2,178),       S(-68,180),
    S(17,128),      S(133,122),     S(99,109),      S(92,121),      S(63,118),      S(-8,113),      S(9,146),       S(-62,143),
    S(26,132),      S(129,127),     S(106,126),     S(89,129),      S(32,110),      S(9,133),       S(-6,162),      S(-60,162),
};

const std::array<PScore, 64> KNIGHT_PSQT = {
    S(-213,-101),   S(90,125),      S(-76,136),     S(286,103),     S(170,128),     S(71,182),      S(-278,180),    S(-170,-95),
    S(116,71),      S(137,155),     S(220,139),     S(177,180),     S(286,144),     S(174,138),     S(158,107),     S(95,43),
    S(104,171),     S(204,155),     S(340,149),     S(314,137),     S(316,138),     S(209,189),     S(171,165),     S(127,102),
    S(172,124),     S(116,177),     S(215,172),     S(162,219),     S(186,220),     S(160,202),     S(109,161),     S(137,115),
    S(109,115),     S(132,133),     S(131,175),     S(125,190),     S(118,188),     S(124,199),     S(122,137),     S(75,106),
    S(15,67),       S(67,113),      S(44,117),      S(111,159),     S(98,163),      S(29,128),      S(37,134),      S(15,23),
    S(-26,99),      S(36,119),      S(68,92),       S(85,89),       S(77,91),       S(32,77),       S(61,70),       S(6,-31),
    S(-119,83),     S(59,12),       S(47,31),       S(63,46),       S(29,71),       S(8,3),         S(47,-3),       S(-105,-40),
};

const std::array<PScore, 64> BISHOP_PSQT = {
    S(43,224),      S(77,207),      S(-15,214),     S(0,223),       S(-16,228),     S(-10,222),     S(5,276),       S(9,254),
    S(14,175),      S(31,238),      S(111,213),     S(104,207),     S(135,205),     S(115,220),     S(71,232),      S(-12,174),
    S(155,161),     S(149,218),     S(192,218),     S(239,168),     S(218,190),     S(155,213),     S(144,203),     S(85,178),
    S(144,160),     S(111,217),     S(181,204),     S(189,198),     S(197,199),     S(138,204),     S(101,217),     S(77,161),
    S(130,124),     S(141,161),     S(88,203),      S(156,181),     S(144,200),     S(68,215),      S(117,175),     S(105,148),
    S(104,146),     S(90,153),      S(113,175),     S(95,196),      S(86,205),      S(91,189),      S(96,138),      S(106,104),
    S(117,100),     S(110,143),     S(103,138),     S(89,165),      S(76,157),      S(95,144),      S(88,124),      S(101,81),
    S(63,153),      S(48,141),      S(59,102),      S(14,137),      S(36,122),      S(99,82),       S(67,107),      S(-33,140),
};

const std::array<PScore, 64> ROOK_PSQT = {
    S(485,300),     S(356,364),     S(310,405),     S(282,379),     S(378,331),     S(438,305),     S(397,324),     S(313,348),
    S(421,315),     S(259,402),     S(405,361),     S(409,355),     S(451,338),     S(392,338),     S(266,375),     S(313,344),
    S(294,357),     S(360,347),     S(388,367),     S(418,343),     S(433,329),     S(367,349),     S(325,341),     S(218,374),
    S(176,342),     S(181,382),     S(228,382),     S(249,345),     S(253,357),     S(230,367),     S(153,383),     S(137,374),
    S(66,341),      S(93,366),      S(97,377),      S(106,362),     S(121,359),     S(88,383),      S(52,383),      S(6,391),
    S(-29,325),     S(44,323),      S(38,346),      S(67,333),      S(61,332),      S(38,332),      S(11,344),      S(-38,344),
    S(-77,351),     S(6,328),       S(35,337),      S(75,308),      S(65,314),      S(35,317),      S(-9,339),      S(-62,327),
    S(-33,343),     S(20,349),      S(34,350),      S(101,309),     S(90,327),      S(58,327),      S(26,331),      S(-15,328),
};

const std::array<PScore, 64> QUEEN_PSQT = {
    S(387,892),     S(496,869),     S(479,924),     S(390,1011),    S(454,928),     S(438,920),     S(402,890),     S(279,925),
    S(336,963),     S(222,1070),    S(383,1060),    S(317,1056),    S(285,1129),    S(194,1119),    S(166,1006),    S(289,867),
    S(321,984),     S(366,1003),    S(395,1010),    S(404,1005),    S(352,1002),    S(291,986),     S(287,963),     S(252,919),
    S(266,1031),    S(227,1092),    S(275,1074),    S(247,1114),    S(214,1120),    S(244,1018),    S(219,980),     S(249,871),
    S(215,911),     S(242,989),     S(199,1009),    S(215,1025),    S(187,1039),    S(186,979),     S(210,890),     S(212,871),
    S(220,796),     S(223,826),     S(204,916),     S(200,878),     S(189,851),     S(179,839),     S(202,784),     S(214,812),
    S(225,616),     S(223,604),     S(226,707),     S(242,663),     S(214,702),     S(224,660),     S(185,718),     S(220,783),
    S(169,781),     S(248,492),     S(177,661),     S(240,551),     S(249,605),     S(231,586),     S(224,634),     S(170,780),
};

const std::array<PScore, 64> KING_PSQT = {
    S(484,-277),    S(416,-102),    S(430,-86),     S(551,-34),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(60,-53),      S(-20,81),      S(51,62),       S(65,50),       S(0,0), S(0,0), S(0,0), S(0,0),
    S(-81,70),      S(-99,144),     S(-65,134),     S(-127,109),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(-267,59),     S(-69,103),     S(-147,113),    S(-172,96),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(-197,19),     S(-101,35),     S(-181,68),     S(-155,71),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(-51,-66),     S(-57,-32),     S(-153,16),     S(-185,42),     S(0,0), S(0,0), S(0,0), S(0,0),
    S(85,-135),     S(16,-94),      S(-36,-58),     S(-107,-22),    S(0,0), S(0,0), S(0,0), S(0,0),
    S(156,-218),    S(165,-184),    S(44,-133),     S(36,-145),     S(0,0), S(0,0), S(0,0), S(0,0),
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

    const Bitboard mobility_area[2] = {
        ~pos.get_pt_attacks<PieceType::Pawn, Color::Black>(),
        ~pos.get_pt_attacks<PieceType::Pawn, Color::White>()
    };

    i32 mob_count = 0;

    auto count_mobility = [&](Color c) {
        u16 nonpawn_idx = pos.piece_list(c).mask_nonempty_neq(PieceType::Pawn);
        while (nonpawn_idx) {
            i32      i       = std::countr_zero(nonpawn_idx);
            Bitboard attacks = pos.attack_table(c).get_piece_mask_bitboard(1 << i);
            mob_count += (attacks & mobility_area[static_cast<size_t>(c)]).popcount();
            nonpawn_idx &= nonpawn_idx - 1;
        }
    };

    count_mobility(Color::Black);
    mob_count = -mob_count; // Persy trick
    count_mobility(Color::White);


    PScore mobility = MOBILITY_VAL * mob_count;

    PScore tempo = (us == Color::White) ? TEMPO_VAL : -TEMPO_VAL;
    PScore sum   = psqt_state.score() + mobility + tempo;
    return sum->phase<24>(phase);
};

Score evaluate_stm_pov(const Position& pos, const PsqtState& psqt_state) {
    const Color us = pos.active_color();
    return (us == Color::White) ? evaluate_white_pov(pos, psqt_state)
                                : -evaluate_white_pov(pos, psqt_state);
}

}  // namespace Clockwork
