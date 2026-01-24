# fen_to_ascii.py

FENS = """
  1. [18.1446] rnbq2kr/pppp2pp/4P3/4P3/1P6/P7/5PPP/RNbQK2R b KQ - 0 1 [0.0]
  2. [17.8963] r2q1bnr/1b1knQp1/pp1Pp1Bp/2P5/8/2N5/PPP2PPP/R1B1K2R b KQ - 0 1 [0.0]
  3. [17.7095] 2b2Bk1/1pp3pp/r4p2/p3p3/2PP4/1P3p2/2K1P1PP/R4BNR w - - 0 1 [1.0]
  4. [17.6892] rn1R1b1N/8/2p1kPp1/1p5p/p4B2/2N2Q2/PqP3PP/7K b - - 0 1 [1.0]
  5. [17.5440] 1n3qr1/QR4bk/2P3pp/1P6/3B2P1/2P5/5P1P/6K1 b - - 0 1 [1.0]
  6. [17.4888] 3q2k1/2p2p1p/p2P1bp1/8/6P1/2PQ4/1rBP1PKP/RNr5 w - - 0 1 [0.0]
  7. [17.1184] 1R3b2/2pk1p2/4bPp1/2p1P1Pp/2P4P/2K2N2/r7/8 b - - 0 1 [0.0]
  8. [16.9287] 2r2rk1/p5qp/4b3/1Q4p1/KP2p3/P1bpP3/5PPP/2R3NR w - - 0 1 [0.0]
  9. [16.8283] rnb5/ppQp3p/4p1p1/8/3P1P2/5q2/PPPK4/6k1 b - - 0 2 [0.0]
 10. [16.7954] 8/pppkn2Q/8/8/4P3/2P2K2/PP1P4/RNn3q1 w - - 0 1 [0.0]
 11. [16.7500] r3k2r/p2q1ppp/8/2b4n/3p1P2/2P1p1P1/PP1B3P/RN2K2R w KQkq - 0 1 [0.0]
 12. [16.7404] 8/p5Bp/6kP/3b4/4ppp1/1P1p4/3K1PP1/Nrn2B1R w - - 0 1 [0.0]
 13. [16.7404] 8/p5Bp/6kP/3b4/4ppp1/1P1p4/3K1PP1/Nrn2B1R w - - 0 1 [0.0]
 14. [16.7300] 1n6/3p4/1p1Pb3/1P6/P3R3/6k1/4K3/8 b - - 0 1 [1.0]
 15. [16.5437] 4kbnr/2Bb1pp1/8/2PN3p/8/8/3KPPPP/nr3BNR w - - 0 1 [0.0]
 16. [16.4992] 2b5/p4Q2/4P3/1k1p4/2pP4/Pp3K2/1P6/R1B1q1r1 w - - 0 1 [0.5]
 17. [16.4846] r6k/pppnq3/7p/8/6Q1/4P3/PPPP2PK/RNB2r2 w - - 0 1 [0.0]
 18. [16.3994] R4br1/1kN5/1p1PB3/2p1Pp2/5p2/1P3P2/1B3K2/8 b - - 0 1 [1.0]
 19. [16.3862] 8/pppnk3/3p2K1/4p3/8/4P3/PPPP4/RNB4r w - - 0 1 [1.0]
 20. [16.3664] 1R3b1r/3k1p1p/2bPp1p1/6P1/7P/P7/1PPR1P2/2K5 b - - 0 1 [1.0]
 21. [16.3643] 1n2r2k/1RRbr2p/p2q2p1/1pNP4/1P2Bp2/3Q1P2/4K1P1/8 b - - 0 1 [1.0]
 22. [16.2944] rn4Q1/1R1pkr1p/1p2pp2/1P5q/1P6/P3BP2/4n1PP/5R1K b - - 0 1 [0.5]
 23. [16.1852] rn1RR3/p5p1/4p1kp/1PB5/2P1p1PP/5r2/4K3/8 b - - 0 1 [1.0]
 24. [16.1840] 6nr/2k1p3/r2pB1p1/PRpP2Pp/4P2P/2P1K3/8/R7 b - - 0 1 [1.0]
 25. [16.1296] rn1R4/1r4pk/7p/1P6/p1PBR1PP/8/4K3/8 b - - 0 1 [1.0]
 26. [16.0627] rnbq1r2/1p1pn2R/p1p1p2Q/5k2/3P4/2N2P2/PPP2P2/R3KB2 b - - 0 1 [1.0]
 27. [15.8915] rn2k2r/1bpqp3/p2pP2p/1p1P1pp1/8/1BP2P1P/P1P1QBn1/R4KNR b kq - 1 1 [1.0]
 28. [15.8832] 2r3k1/pp3ppp/2n1b3/1N6/Pq6/1P3p2/2K1P1PP/5BNR w - - 0 1 [0.0]
 29. [15.8815] 1n4R1/1p5p/p1p4P/1P2kb2/P1B3n1/1QP3P1/5P2/R5K1 b - - 0 1 [1.0]
 30. [15.8811] r1b2Rnr/N2p2pp/4p2q/kpQ1P3/2B5/P2P2P1/2P4P/R3K3 b - - 0 1 [1.0]
 31. [15.8756] 8/8/2r1kb1p/5p2/1p2pK2/1P1p2P1/1P1R1P1B/1Nr5 w - - 0 1 [0.0]
 32. [15.8113] 5rk1/4n1b1/2npb1p1/2p1p1P1/1p2P3/2PB1P2/1q1B3Q/1N2K1NR w K - 0 3 [0.0]
 33. [15.8065] rn2b1k1/pp2n1pp/3pP3/PP1P4/4P3/2Nr4/4NR1P/R6K b - - 0 1 [1.0]
 34. [15.7850] 5r2/1b3p1p/p2bpNk1/1p6/1p3P2/4P3/P2P1KPP/RN5r w - - 0 1 [0.0]
 35. [15.7775] 1nRQ1r1k/7b/p3B3/1pN5/1P4P1/7K/5pP1/8 b - - 0 1 [1.0]
 36. [15.7137] R4b2/3k1p1p/2p2Pp1/2p1P1P1/7P/3b4/3r4/B1K5 b - - 0 1 [0.0]
""".strip().splitlines()

FILES = "abcdefgh"

def parse_result(fen: str) -> str:
    # Discard first part before the actual FEN
    fen = fen.split()[2:]
    fen = " ".join(fen)
    result = fen.split()[-1]
    if result == "[1.0]":
        return "White wins"
    elif result == "[0.0]":
        return "Black wins"
    elif result == "[0.5]":
        return "Draw"
    else:
        return "Unknown result"

def fen_to_ascii(fen: str) -> str:
    # Strip move number and eval, keep real FEN
    fen = " ".join(fen.split()[2:])

    board_part = fen.split()[0]
    rows = board_part.split("/")
    lines = []

    for rank, row in zip(range(8, 0, -1), rows):
        line = []
        for char in row:
            if char.isdigit():
                line.extend(["."] * int(char))
            else:
                line.append(char)
        lines.append(f"{rank} | " + " ".join(line))

    header = "    " + " ".join(FILES)
    separator = "  ----------------"
    return "\n".join([header, separator] + lines)




def main():
    for i, fen in enumerate(FENS, start=1):
        result = parse_result(fen)
        print(f"\nPosition {i}")
        print(f"Result: {result}")
        print(fen)
        print(fen_to_ascii(fen))


if __name__ == "__main__":
    main()