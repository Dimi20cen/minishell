/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_define_end_quote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:40:08 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:40:09 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	define_end_quote(char *token, int has_variable,
			char first_quote, int *end_quote)
{
	char	*quote;

	quote = NULL;
	quote = ft_strchr(token, '"');
	if (!quote && !has_variable)
		quote = ft_strchr(token, '\'');
	else if (quote && first_quote != '\'')
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = '"';
	}
	else if (!quote || first_quote == '\'')
		*end_quote = ft_strlen(token);
	else
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = '\'';
	}
}
