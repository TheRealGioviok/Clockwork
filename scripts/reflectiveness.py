import subprocess
import chess
import random
import time
import sys

ENGINE_PATH = sys.argv[1] if len(sys.argv) > 1 else "./clockwork"

NUM_POSITIONS = 1000000
MIN_RANDOM_PLIES = 4
MAX_RANDOM_PLIES = 25

DUMP_FILE = "failures.txt"


class Engine:
    def __init__(self, path):
        self.proc = subprocess.Popen(
            path,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,
            text=True,
            bufsize=1
        )
        self._init_uci()

    def send(self, cmd):
        self.proc.stdin.write(cmd + "\n")
        self.proc.stdin.flush()

    def read_until(self, keyword):
        while True:
            line = self.proc.stdout.readline()
            if keyword in line:
                return line.strip()

    def _init_uci(self):
        self.send("uci")
        self.read_until("uciok")
        self.send("isready")
        self.read_until("readyok")

    def eval(self, board):
        fen = board.fen()
        self.send(f"position fen {fen}")
        self.send("eval")

        # Expect: "Evaluation (stm): xxxx"
        while True:
            line = self.proc.stdout.readline()
            if "Evaluation" in line:
                try:
                    val = int(line.strip().split()[-1])
                    return val
                except:
                    continue

    def quit(self):
        self.send("quit")
        self.proc.kill()


def random_position():
    board = chess.Board()

    n_moves = random.randint(MIN_RANDOM_PLIES, MAX_RANDOM_PLIES)

    for i in range(n_moves):
        if board.is_game_over():
            break

        moves = list(board.legal_moves)
        if not moves:
            break

        move = random.choice(moves)
        board.push(move)

    # No positions in check
    if board.is_check():
        return None

    return board


def mirror_board(board):
    return board.mirror()

def main():
    engine = Engine(ENGINE_PATH)
    dump = open(DUMP_FILE, "w")
    tested = 0
    failures = 0

    start_time = time.time()

    while tested < NUM_POSITIONS:
        board = random_position()
        if board is None:
            continue

        mirrored = mirror_board(board)

        eval1 = engine.eval(board)
        eval2 = engine.eval(mirrored)

        if eval1 is None or eval2 is None:
            continue

        if eval1 != eval2:
            failures += 1

            fen1 = board.fen()
            fen2 = mirrored.fen()

            print()
            print("Asymmetry detected!")
            print("FEN:", fen1, " --- ", fen2)
            print("Eval:", eval1)
            print("Mirrored Eval:", eval2)
            print("Diff:", eval1 - eval2)

            # Write to file
            dump.write("=== FAILURE ===\n")
            dump.write(f"f: {fen1}\t")
            dump.write(f"m: {fen2}\t\t")
            dump.write(f"1: {eval1}\t")
            dump.write(f"2: {eval2}\t")

            if failures % 10 == 0:
                dump.flush()

        tested += 1

        if tested % 100 == 0:
            elapsed = time.time() - start_time
            print(f"Tested: {tested}, Failures: {failures}, Time: {elapsed:.1f}s")

    engine.quit()
    dump.close()

    print("\n==== DONE ====")
    print(f"Positions tested: {tested}")
    print(f"Failures: {failures}")
    print(f"Failure rate: {failures / tested:.6f}")


if __name__ == "__main__":
    main()