/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:19:27 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/21 15:11:22 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_size;
	unsigned int	dest_size;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (size == 0 || dest_size >= size)
		return (size + src_size);
	else if (i <= (size - dest_size - 1) && src[i])
	{
		dest[dest_size + i] = *src;
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}

int	main(void)
{
	char	s1[40] = "This is a test to look into.";
	char	s2[40] = "not";
	printf("strlcat    %lu\n", strlcat(s1, s2, 40));
	printf("strlcat    %s\n", s1);
	char	f1[40] = "This is a test to look into.";
	char	f2[40] = "not";
	printf("ft_strlcat %u\n", ft_strlcat(f1, f2, 40));
	printf("ft_strlcat %s\n", f1);
	
	char	s3[40] = "This is a test to look into.";
	char	s4[40] = "a test ";
	printf("strlcat    %lu\n", strlcat(s3, s4, 5));
	printf("strlcat    %s\n", s3);
	char	f3[40] = "This is a test to look into.";
	char	f4[40] = "a test ";
	printf("ft_strlcat %u\n", ft_strlcat(f3, f4, 5));
	printf("ft_strlcat %s\n", f3);
	
	char	s5[40] = "This is a test to look into.";
	char	s6[40] = "";
	printf("strlcat    %lu\n", strlcat(s5, s6, 5));
	printf("strlcat    %s\n", s5);
	char	f5[40] = "This is a test to look into.";
	char	f6[40] = "";
	printf("ft_strlcat %u\n", ft_strlcat(f5, f6, 5));
	printf("ft_strlcat %s\n", f5);
}
