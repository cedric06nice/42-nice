/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:22:57 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 17:10:31 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else
			return (0);
	}
	return (1);
}
// int	main(void)
// {
// 	int	i;
// 	i = ft_str_is_alpha("");
// 	printf("'' = %d\n", i);
// 	i = ft_str_is_alpha("Testing");
// 	printf("'Testing' = %d\n", i);
// 	i = ft_str_is_alpha("With space");
// 	printf("'With space' = %d\n", i);
// }