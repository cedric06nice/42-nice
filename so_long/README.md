# so_long

A small top-down 2D game in C: collect every key on the map, then reach the open door. Built with MiniLibX, 42's minimal graphics library over OpenGL.

Part of my training at [42 Nice](https://42nice.fr). Score: 120/100 (with bonus).

## Build and play (macOS)

```sh
make            # downloads MiniLibX on the first build
./so_long maps/1.ber
make bonus && ./so_long maps/b1.ber
```

Move with W A S D. Quit with Esc or the window's close button.

## Maps

Maps are text files (`.ber`): `1` wall, `0` floor, `P` player, `C` key to collect, `E` exit.

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Before the game starts, every map is checked: rectangular, closed by walls, exactly one player and one exit, at least one key, and a path from the player to every key and to the exit. The path check is a recursive flood fill (backtracking) over a copy of the map.

## Bonus

- The move counter is shown in the game window.
- The player sprite turns to face the direction of travel.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
