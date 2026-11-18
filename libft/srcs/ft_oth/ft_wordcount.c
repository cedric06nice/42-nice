/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:32:39 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 21:28:26 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_wordcount function counts the number of words
** in a string separated by a single character sep
*/
int	ft_wordcount(char const *str, char sep)
{
	int	i;
	int	count;

	if (str == 0 || str[0] == 0)
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}
