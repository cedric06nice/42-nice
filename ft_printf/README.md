# ft_printf

`printf` rebuilt from scratch with variadic arguments (`va_start`, `va_arg`), writing with nothing but `write`.

Part of my training at [42 Nice](https://42nice.fr). Score: 100/100.

## Supported conversions

| Conversion | Prints |
| --- | --- |
| `%c` | A character |
| `%s` | A string (`(null)` for a null pointer) |
| `%p` | A pointer address in hexadecimal |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x`, `%X` | A number in lowercase or uppercase hexadecimal |
| `%%` | A percent sign |

Like the real `printf`, it returns the number of characters printed.

## Build

```sh
make            # builds libftprintf.a
```

The library bundles the copy of libft it was submitted with, so it builds on its own.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
