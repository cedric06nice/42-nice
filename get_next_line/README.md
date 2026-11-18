# get_next_line

A function that returns a file one line at a time: each call to `get_next_line(fd)` returns the next line, until the end of the file. It reads in chunks of `BUFFER_SIZE` bytes and keeps whatever it read past the newline in a static buffer for the next call.

Part of my training at [42 Nice](https://42nice.fr). Score: 125/100 (with bonus).

The bonus version keeps a separate buffer for each file descriptor, so several files can be read in turn without losing their place.

## Build and try

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl                      # reads test.txt and test2.txt alternately
```

It works with any buffer size, from 1 byte to more than the file's length, and handles invalid file descriptors and files without a final newline.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
