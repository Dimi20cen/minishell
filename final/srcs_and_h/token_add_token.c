/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:50 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:39:51 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	deal_with_quotes(char **value)
{
	int		i;
	int		end_quote;
	char	*token;

	i = 0;
	token = *value;
	while (token[i])
	{
		if (is_between_quotes(token, i, &end_quote, token[i]))
		{
			printf("token: ,%s,\n", token);
			handle_quotes(&token, i, &end_quote);
			i = end_quote - 1;
			if (i < 0)
				i = 0;
		}
		if (token[i])
			i++;
	}
	*value = token;
	printf("value: ,%s,\n", *value);
}

void	add_token(char *line, int start, int end_token, t_token **token_lst)
{
	char	*value;
	int		type;

	value = ft_substr(line, start, (end_token - start));
	if (!value)
		return ;
	else if (ft_strchr(value, '\'') || ft_strchr(value, '"'))
		deal_with_quotes(&value);
	else if (ft_strchr(value, '$'))
		expand_variables(&value);
	define_type(token_return_last(*token_lst), value, &type);
	//add token to list
	token_add_back(token_lst, token_create_new(value, type));
}
