import os
import hashlib
import re
from tqdm import tqdm

def extract_signature(game_text):
    """Extract only FEN + Result and compute a hash."""
    fields = {}
    for key in ["FEN", "Result"]:
        match = re.search(rf'\[{key} "(.*?)"\]', game_text)
        fields[key] = match.group(1) if match else ""
    sig_str = "|".join(fields.values())
    return hashlib.sha256(sig_str.encode("utf-8")).hexdigest()

def load_games_from_file(filepath):
    """Load all games (raw text + signature) from a PGN file."""
    with open(filepath, encoding="utf-8") as f:
        content = f.read()

    raw_games = re.split(r'\n\n(?=\[Event )', content.strip())
    games = []
    for g in raw_games:
        if g.strip():
            sig = extract_signature(g)
            games.append((g, sig))
    return games

def load_games_from_folder(folder, desc="Loading games"):
    """Return dict[file -> list of (raw_game, sig)]."""
    files = [f for f in os.listdir(folder) if f.endswith(".pgn")]
    games_by_file = {}
    for file in tqdm(files, desc=desc):
        filepath = os.path.join(folder, file)
        games = load_games_from_file(filepath)
        games_by_file[file] = games
    return games_by_file

def write_games_to_pgn(games, filepath):
    """Write a list of raw games back to a PGN file."""
    with open(filepath, "w", encoding="utf-8") as f:
        f.write("\n\n".join(games))
        f.write("\n")

def deduplicate(folder1, folder2, output_folder):
    # Load all games from both folders with progress bars
    games1 = load_games_from_folder(folder1, desc="Reading folder1")
    games2 = load_games_from_folder(folder2, desc="Reading folder2")

    # Build set of unique signatures from folder1
    sigs_folder1 = {sig for _, games in games1.items() for _, sig in games}

    os.makedirs(output_folder, exist_ok=True)

    report = []
    for file, games in tqdm(games2.items(), desc="Processing folder2 files"):
        unique_games = []
        duplicates = []
        for raw_game, sig in tqdm(games, desc=f"Checking {file}", leave=False):
            if sig in sigs_folder1:
                duplicates.append(sig)
            else:
                unique_games.append(raw_game)

        # Write cleaned PGN file
        output_path = os.path.join(output_folder, file)
        write_games_to_pgn(unique_games, output_path)

        # Add to report
        if duplicates:
            report.append((file, len(duplicates)))

    return report



# Example usage:
folder1 = "data/v3/mic"
folder2 = "data/v3/server_deduped4"
output_folder = "data/v3/server_deduped5"
report = deduplicate(folder1, folder2, output_folder)

print("\nDuplicate report:")
for file, count in report:
    print(f"{file}: {count} duplicate games removed")

