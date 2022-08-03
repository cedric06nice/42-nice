/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:36:44 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/02 11:17:00 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*file_content;
	char	**dict;
	t_dict	*struct_dict;
	char	**split_numbers;

	i = 0;
	if (argc == 2)
	{
		file_content = read_file("numbers.dict");
		dict = lines_split(file_content, "\n");
		struct_dict = malloc(sizeof(struct_dict) * ft_str_len(file_content));
		while (dict[i])
		{
			struct_dict[i] = dict_line_parsing(dict[i]);
			i++;
		}
		split_numbers = numbersplit(parse_number(argv[1]));
		i = 0;
		while (thousands(split_numbers, &struct_dict)[i])
		{
			i++;
		}
	}
	else if (argc == 3)
	{
		file_content = read_file(argv[1]);
	}
	else
		print_error();
}
