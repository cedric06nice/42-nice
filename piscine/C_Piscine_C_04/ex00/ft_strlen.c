/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:04:15 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 08:43:16 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf("strlen    = %lu\n", strlen(argv[1]));
	printf("ft_strlen = %d\n", ft_strlen(argv[1]));
}
*/