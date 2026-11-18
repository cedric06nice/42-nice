/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:02:01 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/22 06:38:46 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*to_find == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j] && to_find[j])
				j++;
			if (to_find[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	a[] = "This is a test to look into.";
	char	b[] = "not";
	printf("strstr    %s\n", strstr(a, b));
	printf("ft_strstr %s\n", ft_strstr(a, b));
	char	c[] = "This is a test to look into.";
	char	d[] = "look";
	printf("strstr    %s\n", strstr(c, d));
	printf("ft_strstr %s\n", ft_strstr(c, d));
	char	e[] = "This is a test to look into.";
	char	f[] = "a test ";
	printf("strstr    %s\n", strstr(e, f));
	printf("ft_strstr %s\n", ft_strstr(e, f));
	char g[] = "This is a test to look into.";
	char h[] = "";
	printf("strstr    %s\n", strstr(g, h));
	printf("ft_strstr %s\n", ft_strstr(g, h));
	char i[] = "";
	char j[] = "This is a test to look into.";
	printf("trstr     %s\n", strstr(i, j));
	printf("ft_strstr %s\n", ft_strstr(i, j));
	char k[] = "";
	char l[] = "";
	printf("strstr    %s\n", strstr(k, l));
	printf("ft_strstr %s\n", ft_strstr(k, l));
}
*/