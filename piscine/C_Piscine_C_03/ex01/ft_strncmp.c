/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:51:55 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/22 06:28:14 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && n > 0)
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int main(void)
{
	for (int i = -2; i < 7; i++)
	{
		char a[] = "A";
		char b[] = "a";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "a";
		char b[] = "A";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "salut";
		char b[] = "a";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "A";
		char b[] = "salut";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "1354$ 7 )^#";
		char b[] = "45jnwoi 4j5r90vj87~rj 8*£";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "";
		char b[] = "salut";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "salut";
		char b[] = "";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
	for (int i = -2; i < 7; i++)
	{
		char a[] = "";
		char b[] = "";
		printf("   strncmp(%s, %s, %d) = %d\n", a, b, i, strncmp(a, b, i));
		printf("ft_strncmp(%s, %s, %d) = %d\n", a, b, i, ft_strncmp(a, b, i));
		printf("\n");
	}
}
*/