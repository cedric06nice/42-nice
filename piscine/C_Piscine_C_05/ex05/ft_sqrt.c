/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:53:05 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 08:26:05 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i != nb)
		return (0);
	return (i);
}
/*
#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	a;

	a = -1;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 0;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 1;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 2;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 3;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 4;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 5;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 6;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 7;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 8;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 9;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
	printf("\n");
	a = 10;
	printf("   SQRT %d = %f\n", a, sqrt(a));
	printf("FT_SQRT %d = %d\n", a, ft_sqrt(a));
}
*/