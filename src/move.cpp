#include "move.hpp"

#include "movegen.hpp"
#include "position.hpp"

namespace Clockwork {

namespace {

std::optional<MoveFlags> build_move_flags(bool en_passant, bool capture, PieceType promo) {
    using enum MoveFlags;
    if (en_passant) {
        return EnPassant;
    }

    u16 flags = 0;
    if (capture) {
        flags |= static_cast<u16>(CaptureBit);
    }
    if (promo != PieceType::None) {
        if (promo < PieceType::Knight || promo > PieceType::Queen) {
            return std::nullopt;
        }
        flags |= static_cast<u16>(PromotionBit) | ((static_cast<u16>(promo) - 2) << 12);
    }
    return static_cast<MoveFlags>(flags);
}

}  // namespace

std::optional<Move> Move::parse(std::string_view str, const Position& ctx) {
    if (str.size() != 4 && str.size() != 5) {
        return std::nullopt;
    }

    auto from = Square::parse(str.substr(0, 2));
    if (!from) {
        return std::nullopt;
    }

    auto to = Square::parse(str.substr(2, 2));
    if (!to) {
        return std::nullopt;
    }

    Place src = ctx.board()[*from];
    Place dst = ctx.board()[*to];

    PieceType ptype   = src.ptype();
    bool      capture = !dst.is_empty();

    if (src.color() != ctx.active_color()) {
        return std::nullopt;
    }

    if (str.size() == 4) {
        if (ptype == PieceType::Pawn) {
            if (ctx.en_passant() == *to) {
                return Move(*from, *to, MoveFlags::EnPassant);
            }
        }
        if (ptype == PieceType::King) {
            Square rook_aside = ctx.rook_info(ctx.active_color()).aside;
            Square rook_hside = ctx.rook_info(ctx.active_color()).hside;
            if (*to == rook_aside || *to == rook_hside) {
                return Move(*from, *to, MoveFlags::Castle);
            }
            if (from->file() == 4 && to->file() == 2) {
                return Move(*from, rook_aside, MoveFlags::Castle);
            }
            if (from->file() == 4 && to->file() == 6) {
                return Move(*from, rook_hside, MoveFlags::Castle);
            }
        }
        return Move(*from, *to, capture ? MoveFlags::CaptureBit : MoveFlags::Normal);
    }

    // This check needs to be here because castling is king captures rook in FRC.
    if (capture && dst.color() == ctx.active_color()) {
        return std::nullopt;
    }

    auto mf = [&]() -> std::optional<MoveFlags> {
        switch (str[4]) {
        case 'q':
            return capture ? MoveFlags::PromoQueenCapture : MoveFlags::PromoQueen;
        case 'n':
            return capture ? MoveFlags::PromoKnightCapture : MoveFlags::PromoKnight;
        case 'r':
            return capture ? MoveFlags::PromoRookCapture : MoveFlags::PromoRook;
        case 'b':
            return capture ? MoveFlags::PromoBishopCapture : MoveFlags::PromoBishop;
        default:
            return std::nullopt;
        }
    }();
    if (!mf) {
        return std::nullopt;
    }
    return Move(*from, *to, *mf);
}

std::optional<Move> Move::parse_san(std::string_view san, const Position& ctx) {
    Color stm = ctx.active_color();

    if (san.size() < 2) {
        return std::nullopt;
    }

    if (san.ends_with('#') || san.ends_with('+')) {
        san.remove_suffix(1);
    }

    if (san == "O-O" || san == "O-O-O") {
        Square rook = san == "O-O" ? ctx.rook_info(stm).hside : ctx.rook_info(stm).aside;
        if (!rook.is_valid()) {
            return std::nullopt;
        }
        return Move(ctx.king_sq(stm), rook, MoveFlags::Castle);
    }

    PieceType promo = PieceType::None;
    if (san.size() >= 2 && san[san.size() - 2] == '=') {
        auto p = parse_piece_char(san.back());
        if (!p) {
            return std::nullopt;
        }
        promo = *p;
        san.remove_suffix(2);
    }

    if (san.size() < 2) {
        return std::nullopt;
    }

    bool is_capture = san.size() > 3 && san[san.size() - 3] == 'x';

    auto to = Square::parse(san.substr(san.size() - 2));
    if (!to) {
        return std::nullopt;
    }
    san.remove_suffix(2 + (is_capture ? 1 : 0));

    if (san.empty()) {
        // Pawn push, e.g. "e4" or "e8=Q"
        if (to->relative_sq(stm).rank() < 2) {
            return std::nullopt;
        }

        auto mf = build_move_flags(false, false, promo);
        if (!mf) {
            return std::nullopt;
        }

        i32    delta = stm == Color::White ? -8 : 8;
        Square push_src{static_cast<u8>(to->raw + delta)};
        if (ctx.board()[push_src].ptype() == PieceType::Pawn
            && ctx.board()[push_src].color() == stm) {
            return Move(push_src, *to, *mf);
        }
        if (to->relative_sq(stm).rank() == 3) {
            Square double_src{static_cast<u8>(to->raw + delta * 2)};
            if (ctx.board()[push_src].is_empty()
                && ctx.board()[double_src].ptype() == PieceType::Pawn
                && ctx.board()[double_src].color() == stm) {
                return Move(double_src, *to, *mf);
            }
        }
        return std::nullopt;
    }

    PieceType src_ptype;
    if (san.size() == 1 && san[0] >= 'a' && san[0] <= 'h') {
        // Pawn capture, e.g. "axb3"
        if (!is_capture) {
            return std::nullopt;
        }
        src_ptype = PieceType::Pawn;
    } else if (auto p = parse_piece_char(san[0]); p && san.size() <= 3) {
        // Piece move with optional disambiguation, e.g. "Nf3", "Nge7", "N1c3", "Qa1xb2"
        src_ptype = *p;
        san.remove_prefix(1);
    } else {
        return std::nullopt;
    }

    bool is_en_passant = src_ptype == PieceType::Pawn && is_capture && *to == ctx.en_passant();

    auto mf = build_move_flags(is_en_passant, is_capture, promo);
    if (!mf) {
        return std::nullopt;
    }

    MoveGen   movegen{ctx};
    PieceMask piece_mask = ctx.attack_table(stm).read(*to) & ctx.piece_list(stm).mask_eq(src_ptype);
    Move      match      = Move::none();
    usize     match_count = 0;
    for (PieceId id : piece_mask) {
        Square from = ctx.piece_list_sq(stm)[id];

        bool disambig_ok = true;
        for (char ch : san) {
            if (ch >= 'a' && ch <= 'h') {
                disambig_ok &= from.file() == ch - 'a';
            } else if (ch >= '1' && ch <= '8') {
                disambig_ok &= from.rank() == ch - '1';
            } else {
                return std::nullopt;
            }
        }
        if (!disambig_ok) {
            continue;
        }

        Move move{from, *to, *mf};
        if (movegen.is_legal(move)) {
            match = move;
            match_count++;
        }
    }

    if (match_count != 1) {
        return std::nullopt;
    }
    return match;
}

}  // namespace Clockwork
