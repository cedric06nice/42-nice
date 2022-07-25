/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:55:48 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/25 17:16:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*a;

	i = 0;
	a = malloc(sizeof(src));
	while (src[i])
	{
		a[i] = src[i];
		i++;
	}
	return (a);
}
/*
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	test[] = "Testing some string";
	char	*p_strdup;
	char	*p_ft_strdup;
	
	p_strdup = strdup(test);
	p_ft_strdup = ft_strdup(test);
	printf("   strdup = %p\n", p_strdup);
	printf("   strdup = %s\n", p_strdup);
	printf("ft_strdup = %p\n", p_ft_strdup);
	printf("ft_strdup = %s\n", p_ft_strdup);
	free(p_strdup);
	free(p_ft_strdup);
}
*/