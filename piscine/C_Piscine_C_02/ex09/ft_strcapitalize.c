/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:30:53 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/19 10:54:17 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
			if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
				if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
					if (str[i] >= 'a' && str[i] <= 'z')
						if (!(str[i] >= 'A' && str[i] <= 'Z'))
							str[i] -= 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	a[] = "Testing a line to capitalise.";
	printf("'Testing a line to capitalise.' = %s\n", ft_strcapitalize(a));
	char	b[] = "anot+hEr one";
	printf("'anot+hEr one' = %s\n", ft_strcapitalize(b));
	char	c[] = "ALL CAPS";
	printf("'ALL CAPS' = %s\n", ft_strcapitalize(c));
	char	d[] = "salut, comment tu vas ?";
	printf("%s\n", ft_strcapitalize(d));
	char	e[] = "42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(e));
}
*/