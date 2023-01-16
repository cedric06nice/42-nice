/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:43:10 by cpugnair          #+#    #+#             */
/*   Updated: 2022/11/19 23:04:54 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** The ft_split() function allocates (with malloc)
** and returns an array of strings obtained by splitting s
** using the character c as a delimiter.
** The array must be ended by a NULL pointer.
*/

static int	ft_wordcount(char const *str, char sep)
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

static char	**ft_malloc(char const *str, char sep)
{
	int		len;
	char	**tab_str;

	len = ft_wordcount(str, sep);
	tab_str = malloc(sizeof(*tab_str) * (len + 1));
	if (tab_str == 0)
		return (0);
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

static char	**ft_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i && str_tab[j] != 0)
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

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
