import random
import sys
import os

def phase_scale_factor(phase: int) -> float:
    odd_scale = min(0.9, -0.09793221 * (phase - 23) + 0.189393939)
    p16 = abs(phase - 16)
    if phase > 16:
        base = 1 - 0.875 * (p16 / 8.0) ** 2
    else:
        base = 1 - 0.95 * (p16 / 16) ** 2
    if phase % 2 > 0 and phase > 12:
        return odd_scale * base
    return base

def fen_phase(fen: str) -> int:
    phase = 0
    for chr in fen:
        match chr:
            case '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '/' | 'p' | 'P' | 'k' | 'K':
                continue
            case 'n' | 'N' | 'b' | 'B':
                phase += 1
            case 'r' | 'R':
                phase += 2
            case 'q' | 'Q':
                phase += 4
            case _:
                break
    return min(phase, 24)

if __name__ == "__main__":
    if "--out" not in sys.argv:
        print("Usage: python script.py <input1> <input2> ... --out <output>")
        sys.exit(1)

    out_idx = sys.argv.index("--out")
    input_files = sys.argv[1:out_idx]
    output_filename = sys.argv[out_idx + 1]

    if os.path.exists(output_filename):
        print(f"ERROR: Output file {output_filename} already exists. Use --force to overwrite.")
        sys.exit(1)

    print(f"Reading from {len(input_files)} files and writing to {output_filename}")

    # Collect all lines from all input files
    lines = []
    for fname in input_files:
        with open(fname, "r") as infile:
            file_lines = infile.readlines()
            print(f"Loaded {len(file_lines)} lines from {fname}")
            lines.extend(file_lines)

    print(f"Total {len(lines)} lines loaded")

    # Count phases
    phase_counts = [0] * 25
    for line in lines:
        phase_counts[fen_phase(line)] += 1

    # Compute keep probabilities
    phase_keep_probs = [0] * 25
    phase_norm_const = 100
    for phase in range(25):
        observed = phase_counts[phase] / len(lines) if len(lines) > 0 else 1
        desired = phase_scale_factor(phase)
        if observed > 0:
            phase_keep_probs[phase] = desired / observed
            phase_norm_const = min(phase_norm_const, observed / desired)

    for phase in range(25):
        phase_keep_probs[phase] = min(phase_keep_probs[phase] * phase_norm_const, 1)
        print(f"Phase {phase} has keep probability {phase_keep_probs[phase]}")

    # Filter and write output
    kept = 0
    with open(output_filename, "w") as outfile:
        for line in lines:
            phase = fen_phase(line)
            if random.random() < phase_keep_probs[phase]:
                outfile.write(line)
                kept += 1

    print(f"Finished: kept {kept} out of {len(lines)} lines")
