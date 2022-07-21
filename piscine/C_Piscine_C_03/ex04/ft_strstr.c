/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:02:01 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/21 15:08:00 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (to_find[size])
		size++;
	if (size == 0)
		return (str);
	while (str[i])
	{
		while (str[i] == to_find[j])
		{
			j++;
			if (j == size)
				return (&str[i - j + 1]);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	s1[40] = "This is a test to look into.";
	char	s2[40] = "not";
	printf("strstr    %s\n", strstr(s1, s2));
	char	f1[40] = "This is a test to look into.";
	char	f2[40] = "not";
	printf("ft_strstr %s\n", ft_strstr(f1, f2));
	char	s3[40] = "This is a test to look into.";
	char	s4[40] = "a test ";
	printf("strstr    %s\n", strstr(s3, s4));
	char	f3[40] = "This is a test to look into.";
	char	f4[40] = "a test ";
	printf("ft_strstr %s\n", ft_strstr(f3, f4));
	char	s5[40] = "This is a test to look into.";
	char	s6[40] = "";
	printf("strstr    %s\n", strstr(s5, s6));
	char	f5[40] = "This is a test to look into.";
	char	f6[40] = "";
	printf("ft_strstr %s\n", ft_strstr(f5, f6));
}
