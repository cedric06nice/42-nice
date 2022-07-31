/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_line_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:04:25 by acanavat          #+#    #+#             */
/*   Updated: 2022/07/31 12:34:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	dict_line_parsing(char *str)
{
	int		i;
	int		w;
	t_dict	dict;

	i = 0;
	w = 0;
	dict.id = malloc(sizeof(char) * ft_str_len(str));
	dict.word = malloc(sizeof(char) * ft_str_len(str));
	while (str[i] >= '0' && str[i] <= '9')
	{
		dict.id[i] = str[i];
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == ':')
		i++;
	while ((str[i] >= ' ' && str[i] <= '~' ) && str[i] != '\n')
	{
		if (str[i] == ' ')
			dict.word[w++] = str[i];
		while (str[i] == ' ')
			i++;
		dict.word[w++] = str[i++];
	}
	while (dict.word[w - 1] == ' ' || dict.word[w - 1] == '\n'
		|| dict.word[w - 1] == '\0')
		dict.word[w-- - 1] = '\0';
	return (dict);
}
