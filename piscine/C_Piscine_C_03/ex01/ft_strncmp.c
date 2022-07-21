/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:51:55 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/21 15:06:59 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]) && (s1[i] == s2[i]))
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int main(void)
{
	char t1[] = "A";
	char t2[] = "salut";
	char t3[] = "a";
	char t4[] = "1354$ 7 )^#";
	char t5[] = "salut";
	char t6[] = "";
	printf("std %d\n", strncmp(t1, t3, 1));
	printf("my %d\n", ft_strncmp(t1, t3, 1));
	printf("***********\n");
	printf("std %d\n", strncmp(t2, t3, 1));
	printf("my %d\n", ft_strncmp(t2, t3, 1));
	printf("***********\n");
	printf("std %d\n", strncmp(t3, t4, 1));
	printf("my %d\n", ft_strncmp(t3, t4, 1));
	printf("***********\n");
	printf("std %d\n", strncmp(t4, t5, 3));
	printf("my %d\n", ft_strncmp(t4, t5, 3));
	printf("***********\n");
	printf("std %d\n", strncmp(t5, t2, 4));
	printf("my %d\n", ft_strncmp(t5, t2, 4));
	printf("***********\n");
	printf("std %d\n", strncmp(t5, t6, 4));
	printf("my %d\n", ft_strncmp(t5, t6, 4));
	printf("***********\n");
	printf("std %d\n", strncmp(t6, t5, 2));
	printf("my %d\n", ft_strncmp(t6, t5, 2));
	printf("***********\n");
}