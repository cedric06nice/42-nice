/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:17 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/31 22:37:55 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict {
	char	*id;
	char	*word;
}	t_dict;

unsigned int	ft_int_len(unsigned int number);
int				ft_str_len(char *str);
void			ft_putstr(char *str);
int				ft_pow(int nb, int power);
int				ft_strcmp(char *s1, char *s2);

int				print_error(void);
int				print_dict_error(void);

char			*parse_number(char *str);
char			*read_file(char *filename);

char			**execute(char *number, char **t);
char			**numbersplit(char	*number);

char			**lines_split(char *str, char *charset);
t_dict			dict_line_parsing(char *str);

void			print_words(unsigned int **nb);
char			*thousands(char **numbers, t_dict **struct_dict);
void			numberprint(char *str, t_dict *struct_dict);
#endif
