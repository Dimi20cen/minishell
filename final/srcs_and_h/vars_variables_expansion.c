/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_variables_expansion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:41:16 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:41:17 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_exit_status_variable(char **value)
{
	if (ft_strcmp(*value, "$?") == 0)
	{
		free(*value);
		*value = ft_itoa(g_minishell.error_status);
		return (1);
	}
	return (0);
}

static void	deal_with_string_slices(t_var *var, char **value, int *i)
{
	var->before = ft_substr(*value, 0, *i);
	var->value = ft_substr(*value, *i, get_var_size(var->pointer, i));
	if (ft_strchr(var->value, '\''))
		handle_var_single_quote(var, value, *i);
	else
		var->after = ft_substr(*value, *i, (ft_strlen(*value) - *i));
	expand(&var->value);
}

static int	has_dollar_sign(char **value, int *i, t_var *var)
{
	if (!(*value) || is_exit_status_variable(value))
		return (0);
	var->pointer = search_var(*value, i);
	if (!(var->pointer))
		return (0);
	return (1);
}

static int	only_dollar_in_quotes(char **value)
{
	if (!ft_strcmp(*value, "\"$\""))
	{
		free(*value);
		*value = ft_strdup("$");
		return (1);
	}
	return (0);
}

void	expand_variables(char **value)
{
	t_var	var;
	char	*new_str;
	int		i;
	char	*joined;

	i = 0;
	if (!has_dollar_sign(value, &i, &var) || only_dollar_in_quotes(value))
		return ;
	deal_with_string_slices(&var, value, &i);
	joined = ft_strjoin(var.before, var.value);
	new_str = ft_strjoin(joined, var.after);
	free(joined);
	free(*value);
	*value = new_str;
	free_var_struct(&var);
	expand_variables(value);
}
