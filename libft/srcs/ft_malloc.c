/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:29:31 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 21:30:41 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_malloc() function allocates (with malloc)
** and returns an array of strings obtained by splitting str
** using the character sep as a delimiter.
*/
char	**ft_malloc(char const *str, char sep)
{
	int		len;
	char	**tab_str;

	len = ft_wordcount(str, sep);
	tab_str = malloc(sizeof(*tab_str) * (len + 1));
	if (tab_str == 0)
		return (0);
	return (tab_str);
}
