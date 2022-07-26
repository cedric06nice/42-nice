/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:51:57 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/26 18:41:37 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *str;
	int x;
	int i;
	int j;

	str = malloc(sizeof(strs));
	x = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[x++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			str[x++] = sep[j++];
		i++;
	}
	str[x] = '\0';
	return (str);
}
