/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:53:51 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/30 16:13:23 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*read_file(char *filename)
{
	int	input_file;
	char	*str;

	input_file = open(filename, O_RDONLY);
	if (input_file == -1)
		print_dict_error();
	str = malloc(sizeof(input_file));
	
	close(input_file);
	return (str);
}
