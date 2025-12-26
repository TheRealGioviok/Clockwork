import math
import re

# Change config as needed
VALUES_FILE = "spsa_out_140k_stc.txt"
HEADER_FILE = "src/tuned.hpp"
OUTPUT_FILE = "src/tuned.hpp"

PREFIX_TO_STRIP = "tune_"
RECOMPUTE_RANGES = True

RECOMPUTE_MIN_DIVIDE = 2
RECOMPUTE_MAX_MULTIPLY = 2
RECOMPUTE_STEP_DIVISOR = 10

import re


def load_values(path):
    values = {}
    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue

            name, value = line.split(",", 1)
            name = name.strip()
            value = value.strip()

            if name.startswith(PREFIX_TO_STRIP):
                name = name[len(PREFIX_TO_STRIP):]

            values[name] = round(float(value))

    return values


def replace_macro_values(text, values):
    macro_re = re.compile(
        r"""
        (?P<macro>TUNE|NO_TUNE)
        \(
        (?P<name>\s*[\w\d_]+)\s*,
        (?P<v2>\s*[^,]+)\s*,
        (?P<v3>\s*[^,]+)\s*,
        (?P<v4>\s*[^,]+)\s*,
        (?P<v5>\s*[^,]+)
        """,
        re.VERBOSE,
    )

    def repl(match):
        name = match.group("name").strip()

        if name not in values:
            return match.group(0)

        new_v2 = values[name]

        if not RECOMPUTE_RANGES:
            return (
                f"{match.group('macro')}("
                f"{match.group('name')}, "
                f"{new_v2}, "
                f"{match.group('v3')}, "
                f"{match.group('v4')}, "
                f"{match.group('v5')}"
            )

        # Recompute and round values
        new_v3 = math.ceil(new_v2 * RECOMPUTE_MAX_MULTIPLY)
        new_v4 = math.ceil(new_v2 / RECOMPUTE_MIN_DIVIDE)
        new_v5 = math.ceil((new_v3 - new_v2) / RECOMPUTE_STEP_DIVISOR)

        return (
            f"{match.group('macro')}("
            f"{match.group('name')}, "
            f"{new_v2}, "
            f"{new_v3}, "
            f"{new_v4}, "
            f"{new_v5}"
        )

    return macro_re.sub(repl, text)


def main():
    values = load_values(VALUES_FILE)

    with open(HEADER_FILE, "r") as f:
        original = f.read()

    updated = replace_macro_values(original, values)

    with open(OUTPUT_FILE, "w") as f:
        f.write(updated)


if __name__ == "__main__":
    main()
