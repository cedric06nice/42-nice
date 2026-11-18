/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:59:52 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 18:00:58 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else
			return (0);
	}
	return (1);
}
// int	main(void)
// {
// 	int	i;
// 	i = ft_str_is_uppercase("");
// 	printf("'' = %d\n", i);
// 	i = ft_str_is_uppercase("Testing");
// 	printf("'Testing' = %d\n", i);
// 	i = ft_str_is_uppercase("test1234");
// 	printf("'test1234' = %d\n", i);
// 	i = ft_str_is_uppercase("TESTING");
// 	printf("'TESTING' = %d\n", i);
// }