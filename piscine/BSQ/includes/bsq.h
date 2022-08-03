/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:34:59 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 09:47:48 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFF_SIZE 2147483647

# include "libraries.h"
# include "structs.h"

/*
** check_board.c
*/
int				check_board(char **board, t_board_info *info);
int				check_x(char **board, t_board_info *info);
int				check_y(char **board, t_board_info *info);
int				valid_chars(char **board, t_board_info *info);
int				has_board(char **board);

/*
** check_first_line.c
*/
int				ft_str_is_numeric(char *str);
int				check_first_line(char **board, t_board_info *board_info);
int				check_info_chars(t_board_info *info);

/*
** check_line_breaks.c
*/
int				check_line_breaks(char *str, char **board);

/*
** errors.c
*/
void			print_map_error(void);

/*
** file_exists.c
*/
int				file_exists(char *filename);

/*
** file_size.c
*/
int				file_size(char *file);

/*
** find_square.c
*/
void			find_square(char **board, t_board_info info);
void			init_squares(t_square *square, t_square *best_square);
int				is_obstacle(char **board, t_square square, t_board_info info);
t_square		find_best_square(t_square square, t_square best_square);

/*
** ft_basic.c
*/
unsigned int	ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src);

/*
** line_split.c
*/
char			*ft_strdup(char *src, int min, int max);
int				ischarset(char c, char *charset);
int				count(char *str, char *charset);
char			**split2(char *str, char *charset);
char			**lines_split(char *str, char *charset);

/*
** print_board.c
*/
void			print_board(char **board, t_board_info info, t_square square);

/*
** read_board.c
*/
char			*read_board(char *filename);

#endif