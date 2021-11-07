/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:40:56 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:40:57 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_double_quotes(char **temp, int *has_quote, char **key)
{
	if (ft_strchr(*temp, '"'))
	{
		*key = ft_strtrim(*temp, "\"");
		*has_quote = 1;
	}
	else
		*key = ft_strdup(*temp);
}

static void	define_value(char **value, char *key)
{
	*value = ft_strdup(hashmap_search(g_minishell.env, key));
	if (!*value)
		*value = ft_strdup(hashmap_search(g_minishell.local_vars, key));
	if (!*value)
		*value = ft_strdup("");
}

static void	restore_quote(int has_quote, char **value, char **temp)
{
	if (has_quote)
	{
		*temp = ft_strjoin(*value, "\"");
		free(*value);
		*value = ft_strdup(*temp);
		free(*temp);
	}
}

void	expand(char **variable)
{
	char	*value;
	char	*key;
	char	*temp;
	int		has_quote;

	has_quote = 0;
	temp = *variable;
	temp++;
	check_double_quotes(&temp, &has_quote, &key);
	define_value(&value, key);
	free(*variable);
	free(key);
	restore_quote(has_quote, &value, &temp);
	*variable = value;
}
