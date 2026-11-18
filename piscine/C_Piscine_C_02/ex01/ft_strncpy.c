/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:34:01 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/19 12:48:36 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	ss1[] = "Testing the line";
	char	sd1[20] = "";
	printf("-------- strncpy --------\n");
	printf("Source      = %s\n", ss1);
	printf("Destination = %s\n", sd1);
	strncpy(sd1, ss1, 20);
	printf("strncpy(destination, source, 20)\n");
	printf("Destination = %s\n", sd1);

	char	fs1[] = "Testing the line";
	char	fd1[20] = "";
	printf("------- ft_strncpy -------\n");
	printf("Source      = %s\n", fs1);
	printf("Destination = %s\n", fd1);
	ft_strncpy(fd1, fs1, 20);
	printf("ft_strncpy(destination, source, 20)\n");
	printf("Destination = %s\n", fd1);

	char	ss2[] = "Testing the line";
	char	sd2[20] = "";
	printf("-------- strncpy --------\n");
	printf("Source      = %s\n", ss2);
	printf("Destination = %s\n", sd2);
	strncpy(sd2, ss2, 6);
	printf("strncpy(destination, source, 6)\n");
	printf("Destination = %s\n", sd2);

	char	fs2[] = "Testing the line";
	char	fd2[20] = "";
	printf("------- ft_strncpy -------\n");
	printf("Source      = %s\n", fs2);
	printf("Destination = %s\n", fd2);
	ft_strncpy(fd2, fs2, 6);
	printf("ft_strncpy(destination, source, 6)\n");
	printf("Destination = %s\n", fd2);
}
*/