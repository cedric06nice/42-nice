/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:06:04 by elombard          #+#    #+#             */
/*   Updated: 2022/08/01 16:24:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
** Check if the first line of the file is valid.
** If it is, the board info is set (full, obstacle, empty, y).
*/
int	check_first_line(char **board, t_board_info *board_info)
{
	char			c;
	int				i;
	unsigned int	size;

	size = ft_strlen(board[0]);
	if (size < 4)
		return (0);
	i = size - 1;
	board_info->full = board[0][i--];
	board_info->obstacle = board[0][i--];
	board_info->empty = board[0][i--];
	while (i >= 0)
	{
		c = board[0][i];
		if (c < '0' || c > '9')
			return (0);
		if (((unsigned int) i) == (size - 3))
			board_info->y = c - '0';
		else
			board_info->y = board_info->y * 10 + (c - '0');
		i--;
	}
	return (1);
}

int	check_info_chars(t_board_info *info)
{
	return ((info->empty != info->obstacle && info->empty != info->full)
		&& (info->obstacle != info->full));
}
