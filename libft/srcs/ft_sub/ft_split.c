/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:43:10 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/16 21:40:55 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_next_word_count(char const *str, char sep, int i);

/*
** The ft_split() function allocates (with malloc)
** and returns an array of strings obtained by splitting s
** using the character c as a delimiter.
** The array must be ended by a NULL pointer.
*/
char	**ft_split(const char *str, char c)
{
	int		s;
	int		i;
	int		j;
	char	**tab_str;

	s = 0;
	i = -1;
	tab_str = ft_malloc(str, c);
	if (str == 0 || !tab_str)
		return (0);
	while (++i < ft_wordcount(str, c))
	{
		j = 0;
		tab_str[i] = malloc(ft_next_word_count(str, c, s) + 1);
		if (!tab_str[i])
			return (ft_free(tab_str, i));
		while (str[s] != '\0' && str[s] == c)
			s++;
		while (str[s] != '\0' && str[s] != c)
			tab_str[i][j++] = str[s++];
		tab_str[i][j] = '\0';
	}
	tab_str[i] = 0;
	return (tab_str);
}

static int	ft_next_word_count(char const *str, char sep, int i)
{
	int	count;

	count = 0;
	while (str[i] == sep && str[i] != '\0')
		i++;
	while (str[i] != '\0' && str[i] != sep)
	{
		count++;
		i++;
	}
	return (count);
}
