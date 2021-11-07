/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:31 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:39:32 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_output(char *file, int flags)
{
	int	fd_file;

	fd_file = open(file, flags, 0777);
	if (fd_file == -1)
		error_message("redirect", strerror(errno), 1);
	else
	{
		dup2(fd_file, STDOUT_FILENO);
		close(fd_file);
	}
}

static void	redirect_input(char *file, int flags)
{
	int	fd_file;

	fd_file = open(file, flags);
	if (fd_file == -1)
		error_message("redirect", strerror(errno), 1);
	else
	{
		dup2(fd_file, IN);
		close(fd_file);
	}
}

static void	make_redirect(char *redirect, char *file, int *pipefd)
{
	if (!ft_strcmp(redirect, ">"))
		redirect_output(file, O_WRONLY | O_CREAT | O_TRUNC);
	else if (!ft_strcmp(redirect, "<"))
		redirect_input(file, O_RDONLY | O_CREAT);
	else if (!ft_strcmp(redirect, ">>"))
		redirect_output(file, O_WRONLY | O_CREAT | O_APPEND);
	else if (!ft_strcmp(redirect, "<<"))
		here_doc_input(file, pipefd);
}

void	check_redirects(t_token *current, t_token *pipe, int *pipefd)
{
	while (current != pipe)
	{
		if (!current->next)
			break ;
		if (current->type == T_REDIRECT && current->next->type == T_FILE)
		{
			make_redirect(current->value, current->next->value, pipefd);
			current = current->next;
		}
		current = current->next;
	}
}
