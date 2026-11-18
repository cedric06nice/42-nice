/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:30:44 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 13:33:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*range;

	printf("Warn: Any segfault will mean that arrays are not correctly allocated\n");
	printf("            5 => %d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2, 3, 4 => %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	printf("            0 => %d\n", ft_ultimate_range(&range, 3, 3));
	printf("            2 => %d\n", ft_ultimate_range(&range, -1, 1));
	printf("        -1, 0 => %d, %d", range[0], range[1]);
}
