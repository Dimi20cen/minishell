/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command_parser.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:09 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 09:42:55 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	restore_pipefds(int *pipefd)
{
	dup2(pipefd[IN], STDIN_FILENO);
	close(pipefd[IN]);
	dup2(pipefd[OUT], STDOUT_FILENO);
	close(pipefd[OUT]);
}

static void	create_pipe(t_token *pipe_token, int *old_pipe_in)
{
	int	new_pipe[2];

	dup2(*old_pipe_in, STDIN_FILENO);
	if (*old_pipe_in != 0)
		close(*old_pipe_in);
	if (!pipe_token)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[OUT], STDOUT_FILENO);
	close(new_pipe[OUT]);
	*old_pipe_in = dup(new_pipe[IN]);
	close(new_pipe[IN]);
}

static int	is_filename_after_redirect(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		if (token->type == T_REDIRECT)
			if (!next || next->type != T_FILE)
				return (0);
		token = next;
	}
	return (1);
}

void	command_parser(t_token *token_lst, t_token *pipe, int *old_pipe_in)
{
	int		pipefd[2];
	char	**cmd;

	if (!is_filename_after_redirect(token_lst))
	{
		error_message("redirect", "syntax error!", 2);
		return ;
	}
	pipefd[IN] = dup(STDIN_FILENO);
	pipefd[OUT] = dup(STDOUT_FILENO);
	create_pipe(pipe, old_pipe_in);
	check_redirects(token_lst, pipe, pipefd);
	cmd = create_command_array(token_lst, pipe);
	execute(cmd);
	free_2d_array(cmd);
	restore_pipefds(pipefd);
}
