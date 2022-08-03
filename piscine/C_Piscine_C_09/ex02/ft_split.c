/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:30:19 by cpugnair          #+#    #+#             */
/*   Updated: 2022/08/03 11:00:59 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char	*src, int min, int max)
{
	int		x;
	int		y;
	char	*dest;

	x = max - min;
	y = 0;
	dest = (char *) malloc((x + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (min < max)
	{
		dest[y] = src [min];
		min++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count(char *str, char *charset)
{
	int	i;
	int	c;
	int	start;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_charset(str[i], charset))
			i++;
		if (i != start)
			c++;
	}
	return (c);
}

char	**split2(char *str, char *charset)
{
	char	**t;
	int		i;
	int		c;
	int		start;

	i = 0;
	c = 0;
	t = (char **) malloc(sizeof(char *) * (count(str, charset) + 1));
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_charset(str[i], charset))
			i++;
		if (i != start)
		{
			t[c] = ft_strdup(str, start, i);
			c++;
		}
	}
	return (t);
}

char	**ft_split(char *str, char *charset)
{
	char	**t;

	t = (char **) malloc(sizeof(char *) * (count(str, charset) + 1));
	if (t == 0)
		return (0);
	t = split2(str, charset);
	t[count(str, charset)] = 0;
	return (t);
}
