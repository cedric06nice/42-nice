/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:53:59 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 21:37:29 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strcmp function compares two strings and returns an integer
** less than, equal to, or greater than zero if s1 is found,
** respectively, to be less than, to match, or be greater than s2.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
