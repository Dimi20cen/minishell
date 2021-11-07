/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:27 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:39:28 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_checker(t_token *head, int *old_pipe_in)
{
	t_token	*current;

	current = head;
	while (current)
	{
		if (current->type == T_PIPE)
		{
			command_parser(head, current, old_pipe_in);
			head = current->next;
			pipe_checker(head, old_pipe_in);
			break ;
		}
		current = current->next;
	}
	//if no pipe is found
	if (!current)
		command_parser(head, current, old_pipe_in);
}

void	parse_and_execute(t_token *token_lst)
{
	int	old_pipe_in;

	if (!token_lst)
		return ;
	old_pipe_in = 0;
	pipe_checker(token_lst, &old_pipe_in);
	if (old_pipe_in != 0)
		close(old_pipe_in);
}
