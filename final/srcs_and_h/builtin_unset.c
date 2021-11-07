/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:36:20 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:36:21 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char **cmd)
{
	int	i;

	i = 1;
	g_minishell.error_status = 0;
	while (cmd[i])
	{
		if (hashmap_search(g_minishell.env, cmd[i]))
			hashmap_delete(g_minishell.env, cmd[i]);
		else if (hashmap_search(g_minishell.local_vars, cmd[i]))
			hashmap_delete(g_minishell.local_vars, cmd[i]);
		i++;
	}
}
