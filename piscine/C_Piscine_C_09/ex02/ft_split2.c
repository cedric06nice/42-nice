/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:04:56 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/29 08:35:21 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>

// int	len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	is_charset(char c, char *charset)
// {
// 	int	i;

// 	i = 0;
// 	while (charset[i])
// 	{
// 		if (c == charset[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	**short_split(char *str, char *charset)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**recipe;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	recipe = malloc((len(str) * sizeof(char)) + 1);
// 	while (str[i])
// 	{
// 		recipe[k] = malloc((len(str) * sizeof(char)) + 1);
// 		while (!is_charset(str[i], charset))
// 		{
// 			recipe[k][j] = str[i];
// 			i++;
// 			j++;
// 		}
// 		while (is_charset(str[i], charset))
// 			i++;
// 		k++;
// 		j = 0;
// 	}
// 	recipe[k] = 0;
// 	return (recipe);
// }

// char	**ft_split(char *str, char *charset)
// {
// 	char	**recipe;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	recipe = malloc((len(str) * sizeof(char)) + 1);
// 	if (charset[i] == 0)
// 	{
// 		recipe[k] = malloc((len(str) * sizeof(char)) + 1);
// 		while (str[j])
// 		{
// 			recipe[k][j] = str[j];
// 			j++;
// 		}
// 		return (recipe);
// 	}
// 	return (short_split(str, charset));
// }


// int		c_strlen(char *str)
// {
// 	int len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// int		c_strctn(char *str1, char *str2, int at)
// {
// 	int	len;
// 	int	i;

// 	len = c_strlen(str2);
// 	i = 0;
// 	while (i < len)
// 	{
// 		str1[at + i] = str2[i];
// 		i++;
// 	}
// 	str1[at + i] = 0;
// 	return (len + at);
// }

// char	*c_strautojoin(char **strs, char *sep)
// {
// 	char	*str;
// 	int		len;
// 	int		seplen;
// 	int		i;
// 	int		j;

// 	len = 1;
// 	seplen = c_strlen(sep);
// 	i = 0;
// 	while (strs[i] != NULL)
// 	{
// 		len += c_strlen(strs[i]);
// 		if (strs[i + 1] != NULL)
// 			len += seplen;
// 		i++;
// 	}
// 	str = malloc(len * sizeof(char));
// 	i = 0;
// 	j = 0;
// 	while (strs[j])
// 	{
// 		i = c_strctn(str, strs[j++], i);
// 		if (strs[j])
// 			i = c_strctn(str, sep, i);
// 	}
// 	return (str);
// }

// int		main(void)
// {
// 	char **tab;

// 	tab = ft_split("Ceci&est#########&&&&&&&&&&@@@@@$un#succes@!", "&$#@");
// 	printf("%s\n", c_strautojoin(tab, " "));
// 	tab = ft_split("Success", "CUT");
// 	printf("%s\n", c_strautojoin(tab, " "));
// 	tab = ft_split("Success", "");
// 	printf("%s\n", c_strautojoin(tab, " "));
// 	tab = ft_split("", "");
// 	printf("OK\n");
// 	tab = ft_split("", "CUT");
// 	printf("OK\n");
// 	tab = ft_split("       ", "       ");
// 	printf("OK\n");
// 	tab = ft_split("         ", "       ");
// 	printf("OK\n");
// }
