/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:20:24 by cpugnair          #+#    #+#             */
/*   Updated: 2022/07/20 16:22:08 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_str_is_numeric(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n')
		return (1);
	else if (str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_string_size(char *str)
{
	int	i;
	int	start;
	int end;

	i = 0;
	start = 0;
	end = 0;
	while (str[i])
	{
		if (ft_str_is_numeric(str[i]))
		{
			start = i;
			break;
		}
		i++;
	}
	while (str[i + start])
	{
		end = i + start;
		if (!ft_str_is_numeric(str[i]))
			break;
		i++;
	}
	return (end - start);
}

int ft_atoi(char *str)
{
	int	i;
	int	count_minus;
	int	number;

	i = 0;
	count_minus = 0;
	number = 0;
	while (str[i])
	{
		if(ft_is_space(str[i]))
			i++;
		else if (str[i] == '-')
		{
			count_minus++;
			i++;
		}
		else if (!ft_str_is_numeric(str[i]))
			break;
		else
		{
			i++;
		}
	}
	while (str[i] <= i - ft_string_size(str))
	{
		number += (str[i] - '0');
	}
	if (count_minus % 2 == 1)
		number *= -1;
	return (number);
}

int	main(void)
{
	int val;
	char str[20];
	strcpy(str, "--98993489");
	
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s,\n", str);
	printf("           Int value = %d\n", val);
	printf("**************\n");
	strcpy(str, "    --++-12345");
	
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s,\n", str);
	printf("           Int value = %d\n", val);
	printf("**************\n");
	strcpy(str, " -+--98993A489");
	
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s,\n", str);
	printf("           Int value = %d\n", val);
	printf("**************\n");
	strcpy(str, " ---+--+1234ab567");
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s,\n", str);
	printf("           Int value = %d\n", val);
	printf("**************\n");
	
	strcpy(str, "9899+3489");
	val = atoi(str);
	printf("ATOI    String value = %s,\n", str);
	printf("           Int value = %d\n", val);
	printf("**************\n");
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s,\n", str);
	printf("           Int value = %d\n", val);
	printf("**************\n");



	strcpy(str, "--98993489");
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "    --++-12345");
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, " -+--98993A489");
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, " ---+--+1234ab567");
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "9899+3489");
	val = atoi(str);
	printf("ATOI    String value = %s, Int value = %d\n", str, val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "A98993489");
	val = atoi(str);
	printf("ATOI    String value = %s, Int value = %d\n", str, val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "-1-");
	val = atoi(str);
	printf("ATOI    String value = %s, Int value = %d\n", str, val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "");
	val = atoi(str);
	printf("ATOI    String value = %s, Int value = %d\n", str, val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "\n\t\r\v\f 2");
	val = atoi(str);
	printf("ATOI    String value = %s, Int value = %d\n", str, val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
	printf("\n**************\n\n");
	strcpy(str, "\b 2");
	val = atoi(str);
	printf("ATOI    String value = %s, Int value = %d\n", str, val);
	val = ft_atoi(str);
	printf("FT_ATOI String value = %s, Int value = %d\n", str, val);
}