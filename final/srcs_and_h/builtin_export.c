/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:35:47 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:35:48 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_env_array(void)
{
	char	**env_array;

	env_array = hashmap_to_env_with_quotes(g_minishell.env);
	join_2d_array("declare -x ", env_array);
	print_2d_array_fd(env_array, 1);
	free_2d_array(env_array);
	return (0);
}

static void	define_var(char **cmd, int index)
{
	char	**var;

	var = split_in_two(cmd[index], '=');
	if (hashmap_search(g_minishell.env, var[KEY]))
		hashmap_delete(g_minishell.env, var[KEY]);
	hashmap_insert(var[KEY], var[VALUE], g_minishell.env);
	free_2d_array(var);
}

static int	export_variable(char **cmd, int index)
{
	if (!cmd[index])
		return (0);
	if (ft_strchr(cmd[index], '='))
		define_var(cmd, index);
	return (export_variable(cmd, index + 1));
}

int	export(char **cmd)
{
	g_minishell.error_status = 0;
	if (cmd[1])
		return (export_variable(cmd, 1));
	else
		return (print_env_array());
}
