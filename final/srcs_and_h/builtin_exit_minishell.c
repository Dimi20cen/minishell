/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit_minishell.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:35:41 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:35:42 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_exit(void)
{
	hashmap_free_table(g_minishell.env);
	hashmap_free_table(g_minishell.local_vars);
	exit(g_minishell.error_status);
}
