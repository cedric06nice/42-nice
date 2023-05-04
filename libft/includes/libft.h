/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:08:24 by cpugnair          #+#    #+#             */
/*   Updated: 2023/05/04 07:46:13 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// ft_is
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

//ft_lst
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

//ft_mat
int		ft_abs(int n);
int		ft_factorial(int nb);
int		ft_fibonacci(int index);
int		ft_is_prime(int nb);
int		ft_pow(int nb, int power);
int		ft_sqrt(int nb);

// ft_mem
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_free(char **str_tab, int i);
char	**ft_malloc(char const *str, char sep);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);

//ft_oth
int		ft_intlen(int num);
void	ft_sort_int_tab(int *tab, int size);
void	ft_swap(void *a, void *b, size_t size);
int		ft_wordcount(char const *str, char sep);

//ft_put
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

//ft_str
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str);
char	*ft_strtrim(char const *s1, char const *set);

//ft_sub
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//ft_to
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_uitoa(unsigned int n);

#endif
