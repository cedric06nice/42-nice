/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:48:45 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 13:18:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && size - 1 > i)
	{
		dest[i] = src[i];
		i++;
	}
	while (ft_strlen(dest) > i)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char t0a[5] = "dddd";
	char t0b[150] = "jkhgfdcy6rty bhyubthyhg\0";
	char t0c[5] = "qqqq";
	char t0d[150] = "12 eee34 5uh gfds t6hy";
	char t0e[150] = "1354$ 7 )^#";
	char t0f[150] = "salut, comment tu vas ? 42mots quarante-deux;";
	char t1a[5] = "dddd";
	char t1b[150] = "jkhgfdcy6rty bhyubthyhg\0";
	char t1c[150] = "qqqq";
	char t1d[150] = "12 eee34 5uh gfds t6hy";
	char t1e[150] = "1354$ 7 )^#";
	char t1f[150] = "salut, comment tu vas ? 42mots quarante-deux;";
	printf("std = %lu\n", strlcpy(t0a, t0b, 5));
	printf("moi = %u\n", ft_strlcpy(t1a, t1b, 5));
	printf("std = %s\n", t0a);
	printf("moi = %s\n", t1a);
	printf("***********\n");
	printf("std = %lu\n", strlcpy(t0d, t0c, 5));
	printf("moi = %u\n", ft_strlcpy(t1d, t1c, 5));
	printf("std = %s\n", t0d);
	printf("moi = %s\n", t1d);
	printf("***********\n");
	printf("std = %lu\n", strlcpy(t0f, t0e, 5));
	printf("moi = %u\n", ft_strlcpy(t1f, t1e, 5));
	printf("std = %s\n", t0f);
	printf("moi = %s\n", t1f);
	printf("***********\n");
}
*/