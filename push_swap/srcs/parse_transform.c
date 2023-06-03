/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:06:41 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/03 12:09:53 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Check if there are duplicates in the list of numbers
*/
// static int	check_duplicates(int *arr, int num)
// {
// 	int	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		if (arr[i] == num)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

/*
** Transform string into list of numbers
** Return value must be freed by caller
*/
int	*string_to_number(const char *input_string, int *num_count)
{
	char	*input_copy;
	int		*numbers;
	char	*token_start;
	char	*token_end;

	input_copy = ft_strndup(input_string, ft_strlen(input_string));
	numbers = NULL;
	*num_count = 0;
	token_start = input_copy;
	token_end = ft_strchr(input_copy, ' ');
	while (token_start != NULL)
	{
		if (token_end != NULL)
			*token_end = '\0';
		(*num_count)++;
		ft_printf("ps_atoi: %d\n", ps_atoi(token_start));
		numbers = ft_realloc(numbers, (*num_count) * sizeof(int));
		numbers[*num_count - 1] = *ps_atoi(token_start);
		token_start = NULL;
		if (token_end != NULL)
		{
			token_start = token_end + 1;
			token_end = ft_strchr(token_start, ' ');
		}
	}
	return (free(input_copy), free(token_start), free(token_end), numbers);
}

/*
** Transform arguments into list of numbers
** Return value must be freed by caller
*/
int	*numbers_to_number(int argc, char **argv, int *num_count)
{
	int	*numbers;
	int	number;
	int	i;
	int	*tmp;

	numbers = NULL;
	*num_count = 0;
	i = 1;
	while (i < argc)
	{
		ft_printf("ps_atoi: %d\n", ps_atoi(argv[i]));
		number = *ps_atoi(argv[i]);
		(*num_count)++;
		tmp = ft_realloc(numbers, (*num_count) * sizeof(int));
		if (tmp == NULL)
			return (free(numbers), NULL);
		numbers = tmp;
		numbers[*num_count - 1] = number;
		i++;
	}
	return (numbers);
}

// static int	count_j(char **arg, int i, int j)
// {
// 	if (j == 0 && (ft_isdigit(arg[i][j]) || ((arg[i][j] == '-'
// 			|| arg[i][j] == '+') && ft_isdigit(arg[i][j + 1]))))
// 		return (j + 1);
// 	else if (ft_isdigit(arg[i][j]))
// 		return (j + 1);
// 	else
// 		return (-1);
// }

/*
** Transform arguments into list of numbers
** Return value must be freed by caller
*/
// int	*transform_args(char **arguments, int i, int count_args)
// {
// 	int		*list_num;
// 	char	*tmp;
// 	int		j;
// 	int		k;
// 	int		num;

// 	list_num = malloc(sizeof(int) * count_args);
// 	(void)i;
// 	list_num = string_to_number(*arguments, &count_args);
// 	// k = 0;
// 	// while (arguments[i])
// 	// {
// 	// 	j = 0;
// 	// 	while (arguments[i][j])
// 	// 	{
// 	// 		if (count_j(arguments, i, j) == -1)
// 	// 			return (free(list_num), NULL);
// 	// 		j = count_j(arguments, i, j);
// 	// 	}
// 	// 	num = ps_atoi(arguments[i]);
// 	// 	if (num >= INT_MAX || num <= INT_MIN)
// 	// 		return (free(list_num), NULL);
// 	// 	list_num[k++] = num;
// 	// 	i++;
// 	// }
// 	check_duplicates(list_num, 1);
// 	return (list_num);
// }
