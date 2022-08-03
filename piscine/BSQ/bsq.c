/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:40:55 by elombard          #+#    #+#             */
/*   Updated: 2022/08/03 09:48:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	check_and_resolve(char *str);
void	free_board(char **board);

int	main(int argc, char **argv)
{
	char	*str;
	char	c;
	int		i;

	if (argc == 1)
	{
		str = malloc(sizeof(char) * BUFF_SIZE);
		while (read(0, &c, 1))
			ft_strcat(str, &c);
		check_and_resolve(str);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (file_exists(argv[i]))
				check_and_resolve(read_board(argv[i]));
			else
				print_map_error();
			i++;
		}
	}
	return (0);
}

void	check_and_resolve(char *str)
{
	t_board_info	info;
	char			**board;

	board = lines_split(str, "\n");
	if (!check_line_breaks(str, board))
		print_map_error();
	else
	{
		if (!has_board(board))
			print_map_error();
		else
		{
			info.x = ft_strlen(board[1]);
			if (check_board(board, &info))
				find_square(board, info);
			else
				print_map_error();
		}
	}
	free(str);
	free_board(board);
}

void	free_board(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}
