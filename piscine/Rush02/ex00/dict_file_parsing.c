/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_file_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:53:51 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/31 13:02:36 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

#define BUF_SIZE 1000

char	*read_file(char *filename)
{
	int		input_file;
	int		ret;
	char	*str;

	str = malloc(sizeof(char) * BUF_SIZE);
	input_file = open(filename, O_RDONLY);
	if (input_file == -1)
		print_dict_error();
	ret = read(input_file, str, BUF_SIZE);
	str[ret + 1] = '\0';
	if (close(input_file) == -1)
		print_dict_error();
	return (str);
}
