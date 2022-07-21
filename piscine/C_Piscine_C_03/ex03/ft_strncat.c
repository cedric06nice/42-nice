/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:54:42 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/18 16:00:45 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i] && i < nb)
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
	printf("strncat    %s\n", strncat(s1, s2, 2));
	printf("ft_strncat %s\n", ft_strncat(f1, f2, 2));
	printf("***********\n");
	printf("strncat    %s\n", strncat(s3, s4, 2));
	printf("ft_strncat %s\n", ft_strncat(f3, f4, 2));
}
*/