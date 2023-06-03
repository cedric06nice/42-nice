/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:06:41 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/03 17:01:18 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int		*result_ptr;

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
		result_ptr = ps_atoi(token_start);
		if (result_ptr == NULL)
		{
			if (numbers != NULL)
				free(numbers);
			if (input_copy != NULL)
				free(input_copy);
			return (NULL);
		}
		numbers = ft_realloc(numbers, (*num_count) * sizeof(int));
		numbers[*num_count - 1] = *result_ptr;
		free(result_ptr);
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
	int	i;
	int	*result_ptr;

	numbers = NULL;
	*num_count = 0;
	i = 1;
	while (i < argc)
	{
		result_ptr = ps_atoi(argv[i]);
		if (result_ptr == NULL)
			return (free(numbers), NULL);
		(*num_count)++;
		numbers = ft_realloc(numbers, (*num_count) * sizeof(int));
		numbers[*num_count - 1] = *result_ptr;
		free(result_ptr);
		i++;
	}
	return (numbers);
}
