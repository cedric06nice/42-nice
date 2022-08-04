/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:40:55 by elombard          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/03 19:40:19 by cpugnair         ###   ########.fr       */
=======
/*   Updated: 2022/08/03 18:13:31 by cpugnair         ###   ########.fr       */
>>>>>>> bfaa20a52b4efd1df866847e2f6d10959b42ac28
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**	Main function
*/
<<<<<<< HEAD
int main(int argc, char **argv)
{
	char *str;
	char c;
	int i;
=======
int	main(int argc, char **argv)
{
	char	*str;
	char	c;
	int		i;
>>>>>>> bfaa20a52b4efd1df866847e2f6d10959b42ac28

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
<<<<<<< HEAD
void check_and_resolve(char *str)
{
	t_board_info info;
	char **board;
=======
void	check_and_resolve(char *str)
{
	t_board_info	info;
	char			**board;
>>>>>>> bfaa20a52b4efd1df866847e2f6d10959b42ac28

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
<<<<<<< HEAD
	while (42);
}

void free_board(char **board)
{
	int i;
=======
}

void	free_board(char **board)
{
	int	i;
>>>>>>> bfaa20a52b4efd1df866847e2f6d10959b42ac28

	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}
