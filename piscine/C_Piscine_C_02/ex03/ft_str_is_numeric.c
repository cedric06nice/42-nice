/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:12:06 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 17:16:04 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
// int	main(void)
// {
// 	int	i;
// 	i = ft_str_is_numeric("");
// 	printf("'' = %d\n", i);
// 	i = ft_str_is_numeric("Testing");
// 	printf("'Testing' = %d\n", i);
// 	i = ft_str_is_numeric("125dvdvds423");
// 	printf("'125dvdvds423' = %d\n", i);
// 	i = ft_str_is_numeric("12598056189423");
// 	printf("'12598056189423' = %d\n", i);
// }
