# push_swap

Sorts a list of integers using two stacks and a fixed set of 11 moves (swap, push, rotate, reverse rotate), and prints the shortest sequence of moves it can find.

Part of my training at [42 Nice](https://42nice.fr). Score: 100/100.

**About 600 moves for 100 numbers and 5,430 for 500**, under 42's full-marks limits of 700 and 5,500 in most runs. The [build workflow](../.github/workflows/build.yml) checks correctness and move counts on every push.

## Build and run

```sh
make
./push_swap 3 2 5 1 4
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

Invalid input (non-numbers, duplicates, values outside the `int` range) prints `Error` on stderr. Numbers can also be passed as one quoted string.

## How it works

1. **Parse and rank.** Arguments are validated and each number is replaced by its rank, so the algorithm works on 0 to n−1.
2. **Small inputs.** Up to 6 numbers: push the smallest to stack B, sort the last three with at most 2 moves, then push back.
3. **Keep a sorted backbone.** For large inputs, it finds the longest run of numbers already in order in stack A and keeps them there; everything else is pushed to stack B, split around the average so B is roughly pre-sorted.
4. **Insert back by cost.** For every number in B it computes the moves needed to bring it to the top of B and its slot to the top of A, and inserts the cheapest one first.
5. **Merge moves.** A final pass merges pairs such as `ra` + `rb` into `rr`, and removes moves that cancel out.

## What I learned

- Measure before optimising: my first working version needed far more moves; the cost-based insertion and the merge pass brought it under the limit.
- Valgrind and memory discipline: no leaks, and no invalid reads after fixing `ft_realloc` in my libft.
- Keeping 30 source files within the Norm's 25 lines per function.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
