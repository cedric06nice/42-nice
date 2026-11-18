/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:06:41 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 16:12:16 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*convert_tokens_to_numbers(char **tokens, int num_count)
{
	int	*numbers;
	int	*result_ptr;
	int	i;

	numbers = malloc(num_count * sizeof(int));
	if (numbers == NULL)
		return (NULL);
	i = 0;
	while (i < num_count)
	{
		result_ptr = ps_atoi(tokens[i]);
		if (result_ptr == NULL)
			return (free(numbers), NULL);
		numbers[i] = *result_ptr;
		free(result_ptr);
		i++;
	}
	return (numbers);
}

/*
** Transform string into list of numbers
** Return value must be freed by caller
*/
int	*string_to_number(const char *input_string, int *num_count)
{
	char	**tokens;
	int		*numbers;

	tokens = tokenize_string(input_string, num_count);
	if (tokens == NULL)
		return (NULL);
	numbers = convert_tokens_to_numbers(tokens, *num_count);
	if (numbers == NULL)
	{
		free_tokens(tokens, *num_count);
		return (NULL);
	}
	free_tokens(tokens, *num_count);
	return (numbers);
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
