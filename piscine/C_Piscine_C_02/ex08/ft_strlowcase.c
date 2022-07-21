/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:26:36 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/18 09:29:46 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] + 32);
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	i[] = "Testing a Line to lowercase.";
	printf("'Testing a Line to lowercase.' = %s\n", ft_strlowcase(i));
	char	j[] = "another one";
	printf("'another one' = %s\n", ft_strlowcase(j));
}
*/