/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_define_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:40:13 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:40:14 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_redirect(char *value)
{
	if (!ft_strcmp(value, ">") || !ft_strcmp(value, "<"))
		return (1);
	if (!ft_strcmp(value, ">>"))
		return (1);
	return (0);
}

static int	is_operator(char *value)
{
	if (!(ft_strcmp(value, "|")))
		return (1);
	if (!(ft_strcmp(value, ">")) || !(ft_strcmp(value, "<")))
		return (1);
	if (!(ft_strcmp(value, ">>")) || !(ft_strcmp(value, "<<")))
		return (1);
	return (0);
}

int	is_builtin(char *value)
{
	if (!value)
		return (0);
	if (!(ft_strcmp(value, "echo")) || !(ft_strcmp(value, "cd")))
		return (1);
	if (!(ft_strcmp(value, "pwd")) || !(ft_strcmp(value, "export")))
		return (1);
	if (!(ft_strcmp(value, "unset")) || !(ft_strcmp(value, "env")))
		return (1);
	if (!(ft_strcmp(value, "exit")))
		return (1);
	return (0);
}

static int	define_operator(char *value)
{
	if (!(ft_strcmp(value, "|")))
		return (T_PIPE);
	if (is_redirect(value))
		return (T_REDIRECT);
	if (!(ft_strcmp(value, "<<")))
		return (T_REDIRECT);
	return (0);
}

void	define_type(t_token *previous, char *value, int *type)
{
	int	previous_type;

	previous_type = 0;
	if (previous)
		previous_type = previous->type;
	if (is_builtin(value) && (previous_type != T_REDIRECT))
		*type = T_BUILTIN;
	else if (is_operator(value))
		*type = define_operator(value);
	else if (previous_type == T_REDIRECT)
		*type = T_FILE;
	else
		*type = T_LITERAL;
}
