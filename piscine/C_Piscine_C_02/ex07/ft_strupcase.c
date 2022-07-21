/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 07:59:47 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/18 09:16:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = (str[i] - 32);
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	i[] = "Testing a Line to uppercase.";
	printf("'Testing a Line to uppercase.' = %s\n", ft_strupcase(i));
	char	j[] = "another one";
	printf("'another one' = %s\n", ft_strupcase(j));
}
*/