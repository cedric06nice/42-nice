/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:46:26 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/18 15:45:26 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char	s1[40] = "A";
	char	s2[40] = "a";
	char	f1[40] = "A";
	char	f2[40] = "a";
	char	s3[40] = "salut";
	char	s4[40] = "salut";
	char	f3[40] = "salut";
	char	f4[40] = "salut";
	printf("strcat    %s\n", strcat(s1, s2));
	printf("ft_strcat %s\n", ft_strcat(f1, f2));
	printf("***********\n");
	printf("strcat    %s\n", strcat(s3, s4));
	printf("ft_strcat %s\n", ft_strcat(f3, f4));
}
*/