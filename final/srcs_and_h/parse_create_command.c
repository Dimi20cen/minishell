/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_create_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:13 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:39:14 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_cmd_or_arg(int type)
{
	if (((type == T_LITERAL) || (type == T_BUILTIN)))
		return (1);
	return (0);
}

static int	return_length(t_token *current, t_token *pipe)
{
	int	i;

	i = 0;
	while (current != pipe)
	{
		if (is_cmd_or_arg(current->type))
			i++;
		current = current->next;
	}
	return (i);
}

static char	**fill_command_array(t_token *current, t_token *end, char **cmd)
{
	int	i;

	i = 0;
	while (current != end)
	{
		if (is_cmd_or_arg(current->type))
		{
			cmd[i] = ft_strdup(current->value);
			i++;
		}
		current = current->next;
	}
	return (cmd);
}

char	**create_command_array(t_token *head, t_token *pipe)
{
	char	**cmd;
	int		cmd_length;

	cmd_length = return_length(head, pipe);
	cmd = malloc(sizeof(char *) * (cmd_length + 1));
	//so we know where the cmd ends
	cmd[cmd_length] = NULL;
	cmd = fill_command_array(head, pipe, cmd);
	return (cmd);
}
