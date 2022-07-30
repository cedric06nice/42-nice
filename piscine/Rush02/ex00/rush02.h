/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:17 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/30 18:14:25 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dico {
	int		id;
	char	*word;
}	t_dico;

void			print_error(void);
void			print_dict_error(void);

unsigned int	parse_number(char *str);

char			*read_file(char *filename);

unsigned int	**numbersplit(unsigned int number);
unsigned int	**execute(unsigned int number, unsigned int **t);
unsigned int	intlen(unsigned int number);

void			line_line_parsing(char *str);

void			ft_putstr(char *str);
void			print_words(unsigned int **nb);
#endif