/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:35:28 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:35:29 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **cmd)
{
	int		n_exists;
	int		i;

	i = 1;
	n_exists = 0;
	if (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
	{
		n_exists = 1;
		i = 2;
	}
	while (cmd[i])
	{
		printf("%s ", cmd[i]);
		i++;
	}
	if (n_exists == 0)
		printf("\n");
	g_minishell.error_status = 0;
}
