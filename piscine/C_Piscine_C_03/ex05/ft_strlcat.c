/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:19:27 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/22 08:51:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[j] && j < size)
		j++;
	while (src[i] && size && j + i < size - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (j < size)
		dest[j + i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (j + i);
}
/*
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		char a[] = "This is a test.";
		char b[] = "a";
		printf("   strlcat('%s', '%s', %d)", a, b, i);
		printf(" => %lu  -  %s\n", strlcat(a, b, i), a);
		char c[] = "This is a test.";
		char d[] = "a";
		printf("ft_strlcat('%s', '%s', %d)", c, d, i);
		printf(" => %d  -  %s\n", ft_strlcat(c, d, i), a);
		printf("\n");
	}
	for (int i = 0; i < 3; i++)
	{
		char a[] = "a";
		char b[] = "This is a test.";
		printf("   strlcat('%s', '%s', %d)", a, b, i);
		printf(" => %lu  -  %s\n", strlcat(a, b, i), a);
		char c[] = "a";
		char d[] = "This is a test.";
		printf("ft_strlcat('%s', '%s', %d)", c, d, i);
		printf(" => %d  -  %s\n", ft_strlcat(c, d, i), a);
		printf("\n");
	}
	for (int i = 0; i < 17; i++)
	{
		char a[] = "This is a test.";
		char b[] = "";
		printf("   strlcat('%s', '%s', %d)", a, b, i);
		printf(" => %lu  -  %s\n", strlcat(a, b, i), a);
		char c[] = "This is a test.";
		char d[] = "";
		printf("ft_strlcat('%s', '%s', %d)", c, d, i);
		printf(" => %d  -  %s\n", ft_strlcat(c, d, i), a);
		printf("\n");
	}
	for (int i = 0; i < 2; i++)
	{
		char a[] = "";
		char b[] = "";
		printf("   strlcat('%s', '%s', %d)", a, b, i);
		printf(" => %lu  -  %s\n", strlcat(a, b, i), a);
		char c[] = "";
		char d[] = "";
		printf("ft_strlcat('%s', '%s', %d)", c, d, i);
		printf(" => %d  -  %s\n", ft_strlcat(c, d, i), a);
		printf("\n");
	}
}
*/