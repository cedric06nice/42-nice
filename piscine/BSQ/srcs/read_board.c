/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:41:29 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 18:14:28 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Read the board and store it as string.
*/
char	*read_board(char *filename)
{
	int		input_file;
	int		ret;
	char	*str;

	str = malloc(sizeof(char) * (file_size(filename) + 1));
	input_file = open(filename, O_RDONLY);
	if (input_file == -1)
		print_map_error();
	ret = read(input_file, str, BUFF_SIZE);
	str[ret + 1] = '\0';
	if (close(input_file) == -1)
		print_map_error();
	return (str);
}
