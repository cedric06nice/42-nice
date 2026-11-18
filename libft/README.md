# libft

My own C standard library: about 80 functions for characters, strings, memory, linked lists and maths, plus my `ft_printf` and `get_next_line`. Every later 42 project in this repository links against it.

Part of my training at [42 Nice](https://42nice.fr). Score: 125/100 (with bonus).

## Build

```sh
make            # builds libft.a
```

Use it from another project with `-I libft/includes` and link `libft/libft.a`.

## Contents

| Folder | Functions |
| --- | --- |
| `ft_is` | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| `ft_str` | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_strndup`, … |
| `ft_sub` | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` |
| `ft_mem` | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`, `ft_realloc` |
| `ft_to` | `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower` |
| `ft_put` | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`, `ft_putnbr_base` |
| `ft_lst` | Singly linked lists: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstmap`, … |
| `ft_mat` | `ft_abs`, `ft_pow`, `ft_sqrt`, `ft_is_prime`, `ft_factorial`, `ft_fibonacci` |
| `ft_prf` | [`ft_printf`](../ft_printf/) |
| `ft_gnl` | [`get_next_line`](../get_next_line/) |

## Notes

- The mandatory part reimplements libc functions with the same behaviour, edge cases included (`ft_strlcat` with a too-small buffer, `ft_memmove` with overlapping memory).
- `ft_realloc` takes the old size as a parameter: libft cannot read the size of a `malloc`'d block, and copying the new size would read past the end of the old one. I found this bug with Valgrind while preparing this repository.

---

Cedric Pugnaire · Software Developer · [cedric06nice.com](https://cedric06nice.com) · [CV](https://cedric06nice.com/cv) · [All my 42 projects](../README.md)
