/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:30:19 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/29 12:00:52 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_charset(char c, char *charset)
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		bool;
	char	**ret;

	i = 0;
	j = 0;
	k = 0;
	bool = 0;
	if (!str || !charset)
		return (NULL);
	ret = malloc(sizeof(char) * ft_strlen(str) * 10 + 1);
	if (!ret)
		return (NULL);
	while (str[i])
	{
		if (!check_charset(str[i], charset))
		{
			ret[j] = malloc(sizeof(char) * ft_strlen(str));
			ret[j][k] = str[i];
			printf("%c", str[i]);
			k++;
			i++;
			bool = 0;
		}
		else if (bool == 0 && check_charset(str[i], charset))
		{
			ret[j] = malloc(sizeof(char) * ft_strlen(str));
			ret[j][k] = '\0';
			bool = 1;
			j++;
		}
		else if (bool == 1 && check_charset(str[i], charset))
			i++;
		else
			i++;
	}
	ret[j] = 0;
	return (ret);
}

/*

qwerty2uiop4asdf8ghjkl7zxcvbnm, 123456789

qwerty
uiop
asdf
ghjkl
zxcvbnm

*/
