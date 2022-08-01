/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:34:59 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/01 17:10:02 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFF_SIZE 4096

# include "libraries.h"
# include "structs.h"

// check_board.c
int				check_board(char **board, t_board_info *info);
int				check_x(char **board, t_board_info *info);
int				valid_chars(char **board, t_board_info *info);

//check_first_line.c
int				ft_str_is_numeric(char *str);
int				check_first_line(char **board, t_board_info *board_info);
int				check_info_chars(t_board_info *info);

// errors.c
void			print_map_error(void);

// file_exists.c
int				file_exists(char *filename);

// file_size.c
int				file_size(char *file);

// find_square.c
void			find_square(char **board, t_board_info	board_info);

// ft_basic.c
void			ft_putstr(char *str);
unsigned int	ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strstr(char *str, char *to_find);

//line_split.h
char			*ft_strdup(char	*src, int min, int max);
int				ischarset(char c, char *charset);
int				count(char *str, char *charset);
char			**split2(char *str, char *charset);
char			**lines_split(char *str, char *charset);

// read_board.c
char			*read_board(char *filename);

#endif