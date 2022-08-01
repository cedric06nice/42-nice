/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:40:55 by elombard          #+#    #+#             */
/*   Updated: 2022/08/01 17:10:55 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int				i;
	char			c;
	t_board_info	board_info;
	char			**board;
	char			*str;

	if (argc == 1)
	{
		read(0, &c, BUFF_SIZE);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (file_exists(argv[i]))
			{
				str = read_board(argv[i]);
				board = lines_split(str, "\n");
				free(str);
				board_info.x = ft_strlen(board[1]);
				if (check_board(board, &board_info))
					find_square(board, board_info);
			}
			i++;
		}
	}
	return (0);
}
