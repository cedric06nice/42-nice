/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:11:13 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/03 12:11:24 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(int argc, char **argv)
{
	int	num_count;
	int	*list_num;

	num_count = 0;
	list_num = NULL;
	ft_printf("argc: %d\n", argc);
	ft_printf("argv[0]: %s\n", argv[0]);
	ft_printf("argv[1]: %s\n", argv[1]);
	ft_printf("ps_atoi: %d\n", ps_atoi("123"));
	if (argc < 2)
	{
		ft_printf("No input provided.\n");
		return (1);
	}
	if (argc == 2)
	{
		ft_printf("Single input provided.\n");
		list_num = string_to_number(argv[1], &num_count);
	}
	if (argc > 2)
	{
		ft_printf("Multiple inputs provided.\n");
		list_num = numbers_to_number(argc, argv, &num_count);
	}
	ft_printf("List of numbers:\n");
	ft_printf("num_count: %d\n", num_count);
	for (int i = 0; i < num_count; i++)
		ft_printf("%d\n", list_num[i]);
	free(list_num);
	return (0);
}
