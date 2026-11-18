# Piscine

The Piscine ("swimming pool") is 42's entrance exam: four weeks of full-time exercises, a weekly exam and three team projects, in July–August 2022. Passing it is how you get into the school.

Every exercise was graded by other candidates and by 42's automatic grader, under the Norm (25 lines per function, no `for` loops, only `write` and later `malloc` allowed).

| Module | Topic |
| --- | --- |
| [Shell00](Shell00/) | Files, permissions, links, Git basics |
| [Shell01](Shell01/) | Shell scripting: `find`, pipes, `sed`, environment variables |
| [C00](C_Piscine_C_00/) | `write`, loops, printing numbers and combinations |
| [C01](C_Piscine_C_01/) | Pointers |
| [C02](C_Piscine_C_02/) | String functions (`strcpy`, case checks, hex printing) |
| [C03](C_Piscine_C_03/) | `strcmp`, `strcat`, `strstr`, `strlcat` |
| [C04](C_Piscine_C_04/) | `atoi`, number printing in any base |
| [C05](C_Piscine_C_05/) | Recursion and maths: factorial, power, Fibonacci, square roots, primes |
| [C06](C_Piscine_C_06/) | Command-line arguments |
| [C07](C_Piscine_C_07/) | Memory allocation: `strdup`, `range`, `strjoin`, `split` |
| [C08](C_Piscine_C_08/) | Headers, macros, structures |
| [C09](C_Piscine_C_09/) | Makefiles and static libraries |
| [C10](C_Piscine_C_10/) | Reading files with system calls |
| [C11](C_Piscine_C_11/) | Function pointers |
| [BSQ](BSQ/) | Final project: find the biggest empty square in a map |

## BSQ

The final Piscine project: read a map of empty cells and obstacles, and print it with the largest possible empty square filled in. It validates the map (line lengths, allowed characters, the header line), then tries each position and grows the square until it would hit an obstacle, keeping the largest and top-left-most one.

```sh
cd BSQ && make
./bsq full
```

## Rushes: team projects in 48 hours

Each Rush was done in a team of two or three candidates assigned at random, with 48 hours from subject to evaluation. They are kept here as they were submitted at the deadline, unfinished parts included.

| Rush | Task | State at the deadline |
| --- | --- | --- |
| [Rush00](Rush00/) | Draw rectangles of any size with different border styles | Complete |
| [Rush01](Rush01/) | Solve a 4x4 "skyscrapers" logic puzzle from its clues | Input parsing and validation done; solver unfinished |
| [Rush02](Rush02/) | Convert a number into English words using a dictionary file | Dictionary parsing and number splitting done; does not build as submitted |

## What I took from it

- Learning without teachers: reading `man` pages, asking peers and checking answers against tests.
- Writing small, testable functions under strict constraints.
- Working under time pressure with people I had never met.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
