# minitalk

A client and a server that exchange text using nothing but two UNIX signals, `SIGUSR1` and `SIGUSR2`: each character is sent bit by bit, one signal per bit.

Part of my training at [42 Nice](https://42nice.fr). Score: 125/100 (with bonus).

## Build and run

```sh
make            # builds server and client (make bonus for the bonus version)
./server        # prints its PID
./client <server PID> "Hello, world"
```

## How it works

- The client sends the 8 bits of each byte as signals: `SIGUSR1` for 1, `SIGUSR2` for 0.
- The server rebuilds each byte from the 8 signals it receives, then prints it.
- **Bonus:** the server confirms each message back to the client with a signal, and the client reports how many signals were delivered.
- Multi-byte characters (UTF-8 accents, symbols and emoji) arrive intact, because the server rebuilds raw bytes.
- The server keeps running and serves clients one after another.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
