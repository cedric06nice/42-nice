/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 06:53:29 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/27 09:29:17 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_str	*s_str;

	s_str = ft_strs_to_tab(argc, argv);
	for (int i = 0; i < argc; i++)
	{
		printf("Size = %d\n", s_str[i].size);
		printf("str = %s | ", s_str[i].str);
		printf("copy = %s\n", s_str[i].str);
	}
	return (0);
}
