import os
import random
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path
from typing import List, Optional
import chess
import chess.pgn
import io
from tqdm import tqdm



def is_capture_or_promotion(board: chess.Board, move: chess.Move) -> bool:
    """Check if a move is a capture or promotion."""
    return board.is_capture(move) or move.promotion is not None


def extract_positions_from_game(game_data: str, n_positions: int = 5) -> List[str]:
    """Extract N sampled positions from a game, with original restrictions, labeled with final result (w/d/b)."""
    try:
        pgn_io = io.StringIO(game_data)
        game = chess.pgn.read_game(pgn_io)
        if not game:
            return []

        # Map result to label
        result = game.headers.get("Result", "")
        if result == "1-0":
            outcome = "w"
        elif result == "0-1":
            outcome = "b"
        elif result == "1/2-1/2":
            outcome = "d"
        else:
            return []  # Skip unfinished/invalid games

        board = game.board()
        valid_positions = []
        move_number = 0

        # Iterate through all moves in the game
        for node in game.mainline():
            move = node.move
            if move:
                board.push(move)
                move_number += 1

            # Skip if in check or no legal moves
            if board.is_check() or not any(board.legal_moves):
                continue

            next_node = node.next()
            best_move = next_node.move if next_node else None

            # Skip if best move is capture or promotion
            if best_move and is_capture_or_promotion(board, best_move):
                continue

            valid_positions.append(board.fen())

        if not valid_positions:
            return []

        # Randomly select up to n_positions
        if len(valid_positions) > n_positions:
            valid_positions = random.sample(valid_positions, n_positions)

        return [f"{fen};{outcome}" for fen in valid_positions]

    except Exception:
        return []


def count_games_in_file(file_path: Path) -> int:
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            content = f.read()
        return content.count("[Event ")
    except Exception:
        return 0


def process_pgn_file(file_path: Path, positions_per_game: int = 5, pbar=None) -> List[str]:
    """
    Process a PGN file game by game, streaming it line by line.
    Returns a list of positions extracted from all games.
    """
    results = []
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            current_game_lines = []

            for line in f:
                line = line.strip()
                if line.startswith("[Event ") and current_game_lines:
                    # Process the previous game
                    game_data = "\n".join(current_game_lines)
                    positions = extract_positions_from_game(game_data, positions_per_game)
                    results.extend(positions)
                    if pbar:
                        pbar.update(1)

                    current_game_lines = [line]
                else:
                    current_game_lines.append(line)

            # Process the last game in the file
            if current_game_lines:
                game_data = "\n".join(current_game_lines)
                positions = extract_positions_from_game(game_data, positions_per_game)
                results.extend(positions)
                if pbar:
                    pbar.update(1)

    except Exception as e:
        print(f"Error processing file {file_path}: {e}")
        if pbar:
            pbar.update(count_games_in_file(file_path))

    return results


def extract_positions_from_folder(folder_path: str, positions_per_game: int = 5, max_workers: int = 4) -> List[str]:
    folder = Path(folder_path)
    if not folder.exists():
        raise FileNotFoundError(f"Folder {folder_path} does not exist")

    pgn_files = list(folder.glob("*.pgn"))
    if not pgn_files:
        print(f"No PGN files found in {folder_path}")
        return []

    print(f"Found {len(pgn_files)} PGN files")

    # Count total games for progress bar
    total_games = 0
    for pgn_file in tqdm(pgn_files, desc="Counting games"):
        total_games += count_games_in_file(pgn_file)
    print(f"Total games to process: {total_games}")

    all_results: List[str] = []

    # Use a process pool for CPU-bound work
    with ProcessPoolExecutor(max_workers=max_workers) as executor:
        # Submit all files for processing
        future_to_file = {
            executor.submit(process_pgn_file, pgn_file, positions_per_game, None): pgn_file
            for pgn_file in pgn_files
        }

        # Progress bar in main thread
        with tqdm(total=total_games, desc="Processing games", unit="games") as pbar:
            for future in as_completed(future_to_file):
                try:
                    results = future.result()
                    all_results.extend(results)
                    # Approximate: assume each file has roughly its counted number of games
                    pbar.update(count_games_in_file(future_to_file[future]))
                except Exception as e:
                    print(f"Error processing {future_to_file[future]}: {e}")
                    # Still update progress bar
                    pbar.update(count_games_in_file(future_to_file[future]))

    return all_results


def save_positions_to_file(positions: List[str], output_file: str = "sampled_positions.txt"):
    with open(output_file, "w", encoding="utf-8") as f:
        for line in positions:
            f.write(line + "\n")
    print(f"Saved {len(positions)} positions to {output_file}")


def main():
    folder_path = input("Enter the path to the folder containing PGN files: ").strip()
    try:
        positions_per_game = int(input("Enter number of positions per game (default 5): ") or "5")
    except ValueError:
        positions_per_game = 5

    try:
        max_workers = int(input("Enter maximum number of worker threads (default 4): ") or "4")
    except ValueError:
        max_workers = 4

    try:
        positions = extract_positions_from_folder(
            folder_path, positions_per_game=positions_per_game, max_workers=max_workers
        )
        if positions:
            output_file = f"sampled_positions_{len(positions)}.txt"
            save_positions_to_file(positions, output_file)
            print(f"\nSummary:")
            print(f"- Total positions saved: {len(positions)}")
            print(f"- File: {output_file}")
        else:
            print("No valid games found!")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    try:
        import chess
        import chess.pgn
        from tqdm import tqdm
    except ImportError:
        print("Please install required dependencies:")
        print("pip install python-chess tqdm")
        exit(1)

    main()
