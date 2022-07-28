/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:30:19 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/28 17:28:21 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*ret;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!check_charset(str[i], charset))
			ret[j] = str[i];
		else
			j++;
		i++;
	}
	return (str[0]);
}

int	main(int argc, char *argv)
{
	int	i;
	char	
	(void)argc;
	(void)argv;

	i = 0;
	return (0);
}

/*

qwerty2uiop4asdf8ghjkl7zxcvbnm, 123456789

qwerty
uiop
asdf
ghjkl
zxcvbnm

*/