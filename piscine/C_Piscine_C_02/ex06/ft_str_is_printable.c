/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:02:16 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/17 18:22:02 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			i++;
		else
			return (0);
	}
	return (1);
}
// int	main(void)
// {
// 	int	i;
// 	i = ft_str_is_printable("");
// 	printf("'' = %d\n", i);
// 	i = ft_str_is_printable("w8375 Q&3!@#$^&*()_+=/*-+`");
// 	printf("'w8375 Q&3!@#$^&*()_+=/*-+`' = %d\n", i);
// }