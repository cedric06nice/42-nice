/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:53:54 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 17:58:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else
			return (0);
	}
	return (1);
}
// int	main(void)
// {
// 	int	i;
// 	i = ft_str_is_lowercase("");
// 	printf("'' = %d\n", i);
// 	i = ft_str_is_lowercase("Testing");
// 	printf("'Testing' = %d\n", i);
// 	i = ft_str_is_lowercase("test1234");
// 	printf("'test1234' = %d\n", i);
// 	i = ft_str_is_lowercase("testing");
// 	printf("'testing' = %d\n", i);
// }
