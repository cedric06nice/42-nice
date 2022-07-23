/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:20:24 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/23 06:27:32 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int ft_is_minus(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count_minus;
	int	number;

	i = 0;
	count_minus = 0;
	number = 0;
	while (ft_is_space(str[i]))
		i++;
	while (ft_is_sign(str[i]))
	{
		count_minus += ft_is_minus(str[i]);
		i++;
	}
	while (ft_is_number(str[i]))
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (count_minus % 2 == 1)
		number *= -1;
	return (number);
}
/*
int	main(void)
{
	int	val;
	char	str[20];

	strcpy(str, "--98993489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "    --++-12345");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, " -+--98993A489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, " ---+--+1234ab567");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "9899+3489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "--98993489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "    --++-12345");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, " -+--98993A489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, " ---+--+1234ab567");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "9899+3489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "A98993489");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "-1-");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "\n\t\r\v\f 2");
	val = atoi(str);
	printf("   ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = '%s'\n", str);
	printf("           Int value = %d\n", val);
	printf("\n**************\n\n");

	strcpy(str, "\b 2");
	val = atoi(str);
	printf("   ATOI String value = ' %s'\n", str);
	printf("           Int value = %d\n", val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = ' %s'\n", str);
	printf("           Int value = %d\n", val);
}
*/