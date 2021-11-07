/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:40:29 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:40:30 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	 find_end_of_token(char *line, int i, int *end)
{
	char quote_found;

	while (line[i] && line[i] != ' ')
	{
		// if there're quotes i just move after them
		if ((line[i] == '\'' && ft_strchr(line + i + 1, '\'')) ||
			((line[i] == '"' && ft_strchr(line + i + 1, '"'))))
		{
			quote_found = line[i];
			i++;
			while (line[i] != quote_found)
				i++;
		}
		i++;
	}
	*end = i;
	return (i);
}

int	split_to_tokens(int *end_token, char *line, int *i, t_token **token_lst)
{
	while (line[*i] == ' ')
		*i += 1;
	if (!line[*i])
		return (0);
	add_token(line, *i, find_end_of_token(line, *i, end_token), token_lst);
	*i = *end_token;
	if (line[*i])
		*i += 1;
	return (1);
}
