/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:40:55 by elombard          #+#    #+#             */
/*   Updated: 2022/08/03 18:13:31 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	Main function
*/
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

/*
**	Check if the content of the file is valid and if it is, resolve it.
*/
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
