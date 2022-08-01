/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:10:29 by elombard          #+#    #+#             */
/*   Updated: 2022/08/01 16:24:55 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Check if the board is valid
*/
int	check_board(char **board, t_board_info *info)
{
	printf("check_board......\n");
	if (!check_first_line(board, info))
		return (0);
	printf("check_first_line ok\n");
	if (!check_x(board, info))
		return (0);
	printf("check_x ok\n");
	if (!valid_chars(board, info))
		return (0);
	printf("valid_chars ok\n");
	if (!check_info_chars(info))
		return (0);
	printf("check_info_chars ok\n");
	return (1);
}

/*
**	Check if every line length are equals
**  if they are, the x of the board_info is set to the length of the lines
*/
int	check_x(char **board, t_board_info *info)
{
	int	i;

	i = 1;
	while (board[i] != 0)
	{
		if (i == 1)
			info->x = ft_strlen(board[i]);
		else if (info->x != ft_strlen(board[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** Check if the board contains only valid characters
*/
int	valid_chars(char **board, t_board_info *info)
{
	int	i;
	int	j;

	i = 1;
	while (board[i] != 0)
	{
		j = 0;
		while (board[i][j] != 0)
		{
			if (board[i][j] != info->empty &&
				board[i][j] != info->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
