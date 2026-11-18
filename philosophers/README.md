# philosophers

The dining philosophers problem with POSIX threads: philosophers sit around a table with one fork between each pair, and need two forks to eat. Each one must eat before `time_to_die` milliseconds pass, without deadlocks or data races.

Part of my training at [42 Nice](https://42nice.fr). Score: 100/100.

## Build and run

```sh
make
./philo 5 800 200 200        # philosophers, time to die, eat, sleep (ms)
./philo 5 800 200 200 7      # stop once each has eaten 7 times
```

Output follows the subject's format, one line per event:

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
310 4 died
```

## How it works

- **One thread per philosopher** plus a monitor thread that keeps checking whether someone has starved or everyone has eaten enough.
- **One mutex per fork**, and separate mutexes for each philosopher's last meal time, the stop flag and printing, so no two threads touch the same data unprotected.
- **No deadlock:** forks are always taken lowest number first. The last philosopher reaches for fork 1 before his own, which breaks the circle where everyone holds one fork and waits.
- **No starvation with an odd number of philosophers:** after his first meal, each philosopher thinks long enough for both neighbours to eat.
- A death is reported within 10 ms, as the subject requires.

## Testing

Clean under ThreadSanitizer (`-fsanitize=thread`): no data races and no lock-order inversions. Checked cases: `1 800 200 200` (dies), `4 310 200 100` (dies), `4 410 200 200` and `5 800 200 200` (nobody dies), `199 610 200 200` (nobody dies).

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
