"""
Tablebase Line Static Eval Plotter
===================================
1. Fetches the optimal tablebase line from a starting FEN (via Lichess TB API)
2. For each position in that line, gets the static eval from a UCI engine
   using:  ./engine  -> "position fen <fen>"  -> "eval"
3. Plots static eval vs. move number as the position progresses toward mate,
   annotating key moments (captures, checks, blunders vs TB, etc.)

Usage:
    python tb_eval_plot.py --engine ./your_engine \
        --fen "8/8/8/8/8/8/1K1k4/1R6 w - - 0 1" \
        [--max-moves 100] [--output eval_plot.png] [--no-show]

Dependencies:
    pip install chess requests matplotlib
"""

import argparse
import json
import subprocess
import sys
import time
import re
import requests
import chess
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.ticker import MaxNLocator
from dataclasses import dataclass, field
from typing import Optional

# ---------------------------------------------------------------------------
# Rate limiter (shared with tb_test.py design — avoids blind sleeps)
# ---------------------------------------------------------------------------

MIN_REQUEST_INTERVAL = 1.1


class RateLimiter:
    def __init__(self, min_interval: float = MIN_REQUEST_INTERVAL):
        self.min_interval = min_interval
        self._last: float = 0.0

    def wait_and_mark(self):
        elapsed = time.monotonic() - self._last
        remaining = self.min_interval - elapsed
        if remaining > 0:
            time.sleep(remaining)
        self._last = time.monotonic()


_rate_limiter = RateLimiter()

# ---------------------------------------------------------------------------
# Lichess Tablebase API
# ---------------------------------------------------------------------------

API_BASE = "https://tablebase.lichess.ovh"


def query_tb(fen: str) -> Optional[dict]:
    _rate_limiter.wait_and_mark()
    try:
        r = requests.get(f"{API_BASE}/standard", params={"fen": fen}, timeout=10)
        r.raise_for_status()
        return r.json()
    except requests.RequestException as e:
        print(f"  [TB API error] {e}", file=sys.stderr)
        return None


def tb_best_move(fen: str) -> Optional[tuple[str, str, Optional[int]]]:
    """
    Returns (uci_move, category, dtm) for the best TB move from `fen`,
    or None if unavailable.
    """
    data = query_tb(fen)
    if data is None:
        return None
    moves = data.get("moves", [])
    if not moves:
        return None
    best = moves[0]
    return best.get("uci"), best.get("category", "unknown"), data.get("dtm")


# ---------------------------------------------------------------------------
# Engine static eval via subprocess
# ---------------------------------------------------------------------------

def get_static_eval(engine_path: str, fen: str) -> Optional[float]:
    """
    Sends to the engine:
        position fen <fen>
        eval
    and parses the static eval from the output.

    Stockfish-style engines print a line like:
        Final evaluation: +1.23 (white side)   or
        NNUE evaluation  +1.23 (white side)    or
        Classical eval: +1.23

    Returns the value in pawns from White's perspective, or None if unparseable.
    """
    try:
        proc = subprocess.Popen(
            [engine_path],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            text=True,
        )
        commands = f"position fen {fen}\neval\nquit\n"
        stdout, _ = proc.communicate(input=commands, timeout=15)
    except (subprocess.TimeoutExpired, FileNotFoundError, OSError) as e:
        print(f"  [Engine error] {e}", file=sys.stderr)
        return None

    # Match "Evaluation (stm): 57" or "Evaluation (stm): -23" etc.
    for line in stdout.splitlines():
        m = re.search(r"evaluation\s*\([^)]*\)\s*:\s*([+\-]?\d+\.?\d*)", line, re.IGNORECASE)
        if m:
            return float(m.group(1))

    return None


# ---------------------------------------------------------------------------
# Build the TB line
# ---------------------------------------------------------------------------

@dataclass
class PositionInfo:
    ply: int                        # half-moves from start (0 = start pos)
    move_number: str                # e.g. "1w", "1b", "2w" …
    fen: str
    move_played: Optional[str]      # SAN move that was played TO reach this pos
    uci_played: Optional[str]       # UCI form
    category: str                   # TB category at this position
    dtm: Optional[int]              # DTM at this position (None if >5 pieces)
    static_eval: Optional[float]    # from engine "eval" command (white POV)
    is_capture: bool = False
    is_check: bool = False


def build_tb_line(
    start_fen: str,
    max_moves: int,
    engine_path: str,
    verbose: bool = True,
) -> list[PositionInfo]:
    """Fetch TB line AND fill evals in one pass (original behaviour)."""
    positions = fetch_tb_line(start_fen, max_moves, verbose)
    fill_evals(positions, engine_path, verbose)
    return positions


def fetch_tb_line(
    start_fen: str,
    max_moves: int,
    verbose: bool = True,
) -> list[PositionInfo]:
    """
    Follow TB-optimal play from both sides until mate (or max_moves).
    Returns positions with TB metadata but NO engine evals (static_eval=None).
    Save this with save_line() and reuse across engine comparisons.
    """
    board = chess.Board(start_fen)
    positions: list[PositionInfo] = []

    def move_label(ply: int, color: chess.Color) -> str:
        full = ply // 2 + 1
        side = "w" if color == chess.WHITE else "b"
        return f"{full}{side}"

    # --- Starting position ---
    if verbose:
        print(f"Querying TB for start position…")

    data = query_tb(start_fen)
    start_cat = data.get("category", "unknown") if data else "unknown"
    start_dtm = data.get("dtm") if data else None

    positions.append(PositionInfo(
        ply=0,
        move_number="0",
        fen=start_fen,
        move_played=None,
        uci_played=None,
        category=start_cat,
        dtm=start_dtm,
        static_eval=None,
    ))

    if verbose:
        print(f"  Start: cat={start_cat}, dtm={start_dtm}")

    ply = 0
    while not board.is_game_over() and ply < max_moves * 2:
        result = tb_best_move(board.fen())
        if result is None:
            print("  [TB] No move returned, stopping.", file=sys.stderr)
            break

        uci, cat_after, _ = result
        try:
            move = chess.Move.from_uci(uci)
        except ValueError:
            print(f"  [TB] Invalid UCI move: {uci}", file=sys.stderr)
            break

        if move not in board.legal_moves:
            print(f"  [TB] Illegal move {uci}, stopping.", file=sys.stderr)
            break

        is_capture = board.is_capture(move)
        san = board.san(move)
        mover = board.turn

        board.push(move)
        ply += 1

        new_fen = board.fen()
        is_check = board.is_check()

        tb_data = query_tb(new_fen)
        pos_cat = tb_data.get("category", "unknown") if tb_data else "unknown"
        pos_dtm = tb_data.get("dtm") if tb_data else None

        positions.append(PositionInfo(
            ply=ply,
            move_number=move_label(ply - 1, mover),
            fen=new_fen,
            move_played=san,
            uci_played=uci,
            category=pos_cat,
            dtm=pos_dtm,
            static_eval=None,
            is_capture=is_capture,
            is_check=is_check,
        ))

        if verbose:
            print(f"  Ply {ply} [{move_label(ply-1, mover)}] {san}  cat={pos_cat}, dtm={pos_dtm}")

        if board.is_checkmate():
            break

    return positions


def fill_evals(
    positions: list[PositionInfo],
    engine_path: str,
    verbose: bool = True,
) -> None:
    """Fill static_eval in-place for every position using the given engine."""
    total = len(positions)
    for i, p in enumerate(positions):
        if verbose:
            print(f"  Eval {i+1}/{total}  ply={p.ply}  {p.move_played or 'start'}…")
        raw = get_static_eval(engine_path, p.fen)
        # Normalise to White POV: engine returns STM-relative eval
        if raw is not None:
            board = chess.Board(p.fen)
            p.static_eval = raw if board.turn == chess.WHITE else -raw
        else:
            p.static_eval = None


# ---------------------------------------------------------------------------
# Save / load TB line
# ---------------------------------------------------------------------------

def save_line(positions: list[PositionInfo], path: str) -> None:
    """Serialise the TB line (FENs, moves, TB metadata) to a JSON file.
    Engine evals are intentionally excluded so the file stays engine-agnostic."""
    data = [
        {
            "ply":          p.ply,
            "move_number":  p.move_number,
            "fen":          p.fen,
            "move_played":  p.move_played,
            "uci_played":   p.uci_played,
            "category":     p.category,
            "dtm":          p.dtm,
            "is_capture":   p.is_capture,
            "is_check":     p.is_check,
            # static_eval omitted — re-filled per engine
        }
        for p in positions
    ]
    with open(path, "w") as f:
        json.dump(data, f, indent=2)
    print(f"TB line saved to: {path}  ({len(positions)} positions)")


def load_line(path: str) -> list[PositionInfo]:
    """Load a previously saved TB line. static_eval will be None until fill_evals() is called."""
    with open(path) as f:
        data = json.load(f)
    return [
        PositionInfo(
            ply=d["ply"],
            move_number=d["move_number"],
            fen=d["fen"],
            move_played=d.get("move_played"),
            uci_played=d.get("uci_played"),
            category=d.get("category", "unknown"),
            dtm=d.get("dtm"),
            static_eval=None,
            is_capture=d.get("is_capture", False),
            is_check=d.get("is_check", False),
        )
        for d in data
    ]


# ---------------------------------------------------------------------------
# Plotting
# ---------------------------------------------------------------------------

def plot_eval_line(positions: list[PositionInfo], output_path: Optional[str], show: bool):
    # Filter to positions that have an eval
    valid = [p for p in positions if p.static_eval is not None]
    if not valid:
        print("No static evals available — nothing to plot.", file=sys.stderr)
        return

    plies   = [p.ply for p in valid]
    evals   = [p.static_eval for p in valid]
    labels  = [p.move_number for p in valid]
    dtms    = [p.dtm for p in valid]

    # Determine winning side (from start position)
    start_cat = positions[0].category
    winning_white = start_cat in ("win", "cursed-win") and chess.Board(positions[0].fen).turn == chess.WHITE

    # ---- Figure setup ----
    fig, ax = plt.subplots(figsize=(14, 6))
    fig.patch.set_facecolor("#0f1117")
    ax.set_facecolor("#0f1117")

    for spine in ax.spines.values():
        spine.set_color("#2a2d3a")

    ax.tick_params(colors="#8b92a5", labelsize=9)
    ax.xaxis.label.set_color("#8b92a5")
    ax.yaxis.label.set_color("#8b92a5")

    # ---- Gradient fill under curve ----
    # Use a subtle fill: positive eval = winning side advantage
    ax.fill_between(plies, evals, 0,
                    where=[e >= 0 for e in evals],
                    alpha=0.15, color="#4ade80", interpolate=True)
    ax.fill_between(plies, evals, 0,
                    where=[e < 0 for e in evals],
                    alpha=0.15, color="#f87171", interpolate=True)

    # ---- Main eval line ----
    ax.plot(plies, evals, color="#e2e8f0", linewidth=1.8, zorder=3, solid_capstyle="round")

    # ---- Zero line ----
    ax.axhline(0, color="#2a2d3a", linewidth=1.0, zorder=1)

    # ---- Annotate captures ----
    for p in valid:
        if p.is_capture:
            ax.scatter(p.ply, p.static_eval, color="#facc15", s=60, zorder=5,
                       marker="D", linewidths=0)

    # ---- Annotate checks ----
    for p in valid:
        if p.is_check and not p.ply == plies[-1]:  # skip checkmate marker clash
            ax.scatter(p.ply, p.static_eval, color="#60a5fa", s=45, zorder=5,
                       marker="^", linewidths=0)

    # ---- Checkmate marker ----
    last = valid[-1]
    if chess.Board(last.fen).is_checkmate():
        ax.scatter(last.ply, last.static_eval, color="#f43f5e", s=120, zorder=6,
                   marker="*", linewidths=0)

    # ---- DTM secondary axis ----
    ax2 = ax.twinx()
    ax2.set_facecolor("#0f1117")
    dtm_valid = [(p.ply, abs(p.dtm)) for p in valid if p.dtm is not None]
    if dtm_valid:
        dx, dy = zip(*dtm_valid)
        ax2.plot(dx, dy, color="#a78bfa", linewidth=1.2, linestyle="--",
                 alpha=0.7, zorder=2, label="DTM")
        ax2.tick_params(colors="#a78bfa", labelsize=8)
        ax2.set_ylabel("DTM (moves to mate)", color="#a78bfa", fontsize=9)
        ax2.spines["right"].set_color("#2a2d3a")
        for spine in ["top", "left", "bottom"]:
            ax2.spines[spine].set_visible(False)

    # ---- Y-axis: fit to actual data range + small padding ----
    eval_min, eval_max = min(evals), max(evals)
    eval_span = max(eval_max - eval_min, 1)   # avoid zero-span for flat lines
    padding = eval_span * 0.12
    ax.set_ylim(eval_min - padding, eval_max + padding)

    # ---- X-axis ticks: show move labels every N plies ----
    step = max(1, len(plies) // 20)
    tick_plies  = plies[::step]
    tick_labels = labels[::step]
    ax.set_xticks(tick_plies)
    ax.set_xticklabels(tick_labels, rotation=45, ha="right", fontsize=8)
    ax.xaxis.set_minor_locator(matplotlib.ticker.MultipleLocator(1))

    # ---- Labels & title ----
    ax.set_xlabel("Move", fontsize=10, labelpad=8)
    ax.set_ylabel("Static eval (cp, white POV)", fontsize=10, labelpad=8)

    start_fen_short = positions[0].fen.split(" ")[0]
    ax.set_title(
        f"Tablebase line — static eval progression\n"
        f"{start_fen_short}   DTM={positions[0].dtm}   ({positions[0].category})",
        color="#e2e8f0", fontsize=12, pad=14,
        fontfamily="monospace",
    )

    # ---- Legend — placed below the chart to avoid overlapping the line ----
    legend_items = [
        mpatches.Patch(color="#e2e8f0", label="Static eval"),
        mpatches.Patch(color="#a78bfa", label="DTM"),
        plt.Line2D([0], [0], marker="D", color="w", markerfacecolor="#facc15",
                   markersize=7, label="Capture", linestyle="None"),
        plt.Line2D([0], [0], marker="^", color="w", markerfacecolor="#60a5fa",
                   markersize=7, label="Check", linestyle="None"),
        plt.Line2D([0], [0], marker="*", color="w", markerfacecolor="#f43f5e",
                   markersize=10, label="Checkmate", linestyle="None"),
    ]
    ax.legend(handles=legend_items,
              loc="upper center", bbox_to_anchor=(0.5, -0.18),
              ncol=5, facecolor="#1a1d27", edgecolor="#2a2d3a",
              labelcolor="#c4c9d4", fontsize=9, framealpha=0.9)

    fig.tight_layout()
    fig.subplots_adjust(bottom=0.22)   # make room for the legend below x-axis

    if output_path:
        fig.savefig(output_path, dpi=150, bbox_inches="tight",
                    facecolor=fig.get_facecolor())
        print(f"\nPlot saved to: {output_path}")

    if show:
        plt.show()

    plt.close(fig)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description="Plot static eval along the optimal TB line from a given position",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Workflows:
  # Fetch TB line, score with engine, save line for reuse, plot
  %(prog)s --engine ./eng --fen "<fen>" --save-line line.json

  # Reload saved line, score with a different engine, plot
  %(prog)s --engine ./eng2 --load-line line.json --output eng2_plot.png

  # Fetch TB line only (no engine, no plot) — useful for pre-fetching
  %(prog)s --fetch-only --fen "<fen>" --save-line line.json
""",
    )

    # Source: either a fresh FEN or a saved line
    src = parser.add_mutually_exclusive_group(required=True)
    src.add_argument("--fen",       help="Starting FEN (fetches TB line from Lichess)")
    src.add_argument("--load-line", metavar="FILE",
                     help="Load a previously saved TB line JSON (skips TB queries)")

    parser.add_argument("--engine",    help="Path to UCI engine binary (required unless --fetch-only)")
    parser.add_argument("--save-line", metavar="FILE",
                        help="Save the TB line (FENs + TB metadata, no evals) to this JSON file")
    parser.add_argument("--fetch-only", action="store_true",
                        help="Only fetch and save the TB line, skip eval and plotting (requires --save-line)")
    parser.add_argument("--max-moves", type=int, default=100,
                        help="Max full moves to follow when fetching (default: 100)")
    parser.add_argument("--output",    default="tb_eval_plot.png",
                        help="Output image path (default: tb_eval_plot.png)")
    parser.add_argument("--no-show",   action="store_true",
                        help="Don't open the plot window, just save the image")
    parser.add_argument("--quiet",     action="store_true",
                        help="Suppress per-move progress output")
    args = parser.parse_args()

    verbose = not args.quiet

    # Validate
    if args.fetch_only and not args.save_line:
        parser.error("--fetch-only requires --save-line")
    if not args.fetch_only and not args.engine:
        parser.error("--engine is required unless using --fetch-only")

    # --- Step 1: get the TB line (fetch or load) ---
    if args.load_line:
        print(f"Loading TB line from: {args.load_line}")
        positions = load_line(args.load_line)
        print(f"  Loaded {len(positions)} positions.")
    else:
        print(f"Fetching TB line from: {args.fen}")
        positions = fetch_tb_line(args.fen, args.max_moves, verbose)
        print(f"  Fetched {len(positions)} positions.")

    # --- Step 2: optionally save the line ---
    if args.save_line:
        save_line(positions, args.save_line)

    if args.fetch_only:
        return

    # --- Step 3: fill evals with the engine ---
    print(f"\nScoring with engine: {args.engine}")
    fill_evals(positions, args.engine, verbose)

    # --- Step 4: plot ---
    print(f"\nPlotting…")
    plot_eval_line(
        positions=positions,
        output_path=args.output,
        show=not args.no_show,
    )


if __name__ == "__main__":
    main()