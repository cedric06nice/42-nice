#!/usr/bin/env python3
"""Runs push_swap on random inputs, replays its moves and checks the result is sorted.

Usage: check_push_swap.py <path/to/push_swap> <size> <max_moves> [runs]
"""
import random
import subprocess
import sys


def replay(numbers, moves):
    a, b = list(numbers), []
    for m in moves:
        if m in ("sa", "ss") and len(a) > 1:
            a[0], a[1] = a[1], a[0]
        if m in ("sb", "ss") and len(b) > 1:
            b[0], b[1] = b[1], b[0]
        if m == "pa" and b:
            a.insert(0, b.pop(0))
        if m == "pb" and a:
            b.insert(0, a.pop(0))
        if m in ("ra", "rr") and a:
            a.append(a.pop(0))
        if m in ("rb", "rr") and b:
            b.append(b.pop(0))
        if m in ("rra", "rrr") and a:
            a.insert(0, a.pop())
        if m in ("rrb", "rrr") and b:
            b.insert(0, b.pop())
    return a, b


def main():
    binary, size, limit = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
    runs = int(sys.argv[4]) if len(sys.argv) > 4 else 10
    worst = 0
    for _ in range(runs):
        numbers = random.sample(range(-2**31, 2**31 - 1), size)
        out = subprocess.run([binary, *map(str, numbers)], capture_output=True,
                             text=True, check=True).stdout.split()
        a, b = replay(numbers, out)
        if b or a != sorted(numbers):
            sys.exit(f"KO: {size} numbers not sorted")
        worst = max(worst, len(out))
    print(f"OK: {runs} runs of {size} numbers, worst case {worst} moves (limit {limit})")
    if worst > limit:
        sys.exit(1)


if __name__ == "__main__":
    main()
