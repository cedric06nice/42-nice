# 42 Nice

[![build](https://github.com/cedric06nice/42-nice/actions/workflows/build.yml/badge.svg)](https://github.com/cedric06nice/42-nice/actions/workflows/build.yml)

My work at [42 Nice](https://42nice.fr) (2022–2024), a peer-to-peer software engineering school: no teachers, no lectures, and every project is graded by other students after reading the code and questioning its author.

Everything is written in C with a minimal set of allowed functions (usually `malloc`, `free`, `write` and a few system calls) and follows 42's coding standard, the Norm: at most 25 lines per function, 5 functions per file and 4 parameters per function. [norminette](https://github.com/42School/norminette) checks it on every push.

| Project | What it is | Skills | Score |
| --- | --- | --- | --- |
| [Piscine](piscine/) | The 4-week entrance bootcamp: shell, then C from `write` to function pointers | Shell, C, Git, team work | Admitted |
| [libft](libft/) | My C standard library, reused by every later project | Strings, memory, linked lists | 125/100 |
| [ft_printf](ft_printf/) | `printf` rebuilt from scratch | Variadic functions, formatting | 100/100 |
| [get_next_line](get_next_line/) | Reads a file one line at a time, from several files at once | Buffers, static variables | 125/100 |
| [Born2beRoot](born2beroot/) | A hardened Debian server set up by hand | Linux, SSH, firewall, sudo, cron | 90/100 |
| [minitalk](minitalk/) | Client and server that talk only through UNIX signals | Signals, bit manipulation | 125/100 |
| [so_long](so_long/) | A small 2D game | Graphics, events, path-finding | 120/100 |
| [push_swap](push_swap/) | Sorts numbers with two stacks in as few moves as possible | Algorithms, optimisation | 100/100 |
| [philosophers](philosophers/) | The dining philosophers problem | Threads, mutexes, data races | 100/100 |

Scores above 100 include the optional bonus part.

## Build

```sh
git clone https://github.com/cedric06nice/42-nice.git
cd 42-nice
make          # builds every project (so_long on macOS only)
make norm     # runs norminette (pip install norminette)
```

The [build workflow](.github/workflows/build.yml) compiles everything on Ubuntu and macOS, checks that push_swap sorts correctly within 42's move limits, runs philosophers and minitalk, and runs norminette.

## About this repository

Each project started in its own repository during my training. I merged them here with their full commit history (2022–2023), then removed the official subject PDFs, which 42 does not allow students to publish, and fixed what no longer built on current compilers. Each project's README describes the task in my own words.

---

Cedric Pugnaire · Software Developer · iOS (Swift, SwiftUI) and Flutter · Open to junior roles, remote or hybrid in Manchester

[cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [LinkedIn](https://www.linkedin.com/in/cedric06nice) · [App Store](https://apps.apple.com/gb/developer/cedric-pugnaire/id1509549174)
