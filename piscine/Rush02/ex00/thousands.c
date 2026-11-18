/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thousands.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:05:17 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/01 19:31:25 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char *thousands(char **numbers, t_dict **struct_dict)
{
	int i;

	i = 0;
	while (numbers[i])
	{
		numberprint(numbers[i], *struct_dict);
		printf("i = %d\n", i);
		printf("numbers[i] = %s\n", numbers[i]);
		printf("POW  = %d\n", ft_pow(1000, i));
		printf("STR  = %s\n", struct_dict[1]->id);
		printf("Word = %s\n", struct_dict[1]->word);
		// if (ft_pow(1000, i) == struct_dict[i].id)
		// {
		// 	ft_putstr(struct_dict[i].word);
		// 	e++;
		// }
		i++;
		i++;
	}
	return ("");
}
