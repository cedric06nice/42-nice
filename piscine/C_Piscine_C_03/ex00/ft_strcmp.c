/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:47:09 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/18 13:49:57 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char t1[] = "Testing";
	char t2[] = "salut";
	char t3[] = "a";
	char t4[] = "1354$ 7 )^#";
	char t5[] = "salut";
	printf("std %d\n", strcmp(t1, t2));
	printf("my %d\n", ft_strcmp(t1, t2));
	printf("***********\n");
	printf("std %d\n", strcmp(t2, t3));
	printf("my %d\n", ft_strcmp(t2, t3));
	printf("***********\n");
	printf("std %d\n", strcmp(t3, t4));
	printf("my %d\n", ft_strcmp(t3, t4));
	printf("***********\n");
	printf("std %d\n", strcmp(t4, t5));
	printf("my %d\n", ft_strcmp(t4, t5));
	printf("***********\n");
	printf("std %d\n", strcmp(t5, t2));
	printf("my %d\n", ft_strcmp(t5, t2));
	printf("***********\n");
}
*/