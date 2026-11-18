/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:56:09 by cpugnair          #+#    #+#             */
/*   Updated: 2023/06/04 16:11:09 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	end_token(char **token_start, char **token_end)
{
	*token_start = *token_end + 1;
	*token_end = ft_strchr(*token_start, ' ');
}

static char	**realloc_tokens(char **tokens, int num_count)
{
	tokens = ft_realloc(tokens, (num_count - 1) * sizeof(char *),
			num_count * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	tokens[num_count - 1] = NULL;
	return (tokens);
}

/*
** Free all tokens
*/
void	free_tokens(char **tokens, int num_count)
{
	int	i;

	i = 0;
	while (i < num_count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/*
** Tokenize the input string and return an array of tokens
*/
char	**tokenize_string(const char *input_str, int *num_count)
{
	char	*input_copy;
	char	**tokens;
	char	*token_start;
	char	*token_end;

	input_copy = ft_strndup(input_str, ft_strlen(input_str));
	tokens = NULL;
	token_start = input_copy;
	*num_count = 0;
	token_end = ft_strchr(input_copy, ' ');
	while (token_start != NULL)
	{
		if (token_end != NULL)
			*token_end = '\0';
		(*num_count)++;
		tokens = realloc_tokens(tokens, *num_count);
		if (tokens == NULL)
			return (free(input_copy),
				free_tokens(tokens, *num_count - 1), NULL);
		tokens[*num_count - 1] = ft_strdup(token_start);
		token_start = NULL;
		if (token_end != NULL)
			end_token(&token_start, &token_end);
	}
	return (free(input_copy), free(token_start), free(token_end), tokens);
}
