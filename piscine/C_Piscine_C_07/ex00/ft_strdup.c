/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:55:48 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/21 17:23:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*a = malloc(sizeof(src));
	return (a);
}

int	main(void)
{
	char	test[] = "Testing some string";
	
	printf("   strdup = %p\n", strdup(test));
	free(test);
	printf("ft_strdup = %p\n", ft_strdup(test));
	free(test);
}