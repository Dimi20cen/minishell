/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_here_document.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:19 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:39:20 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_temporary_file(void)
{
	int	fd;

	fd = open("poggers", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_message("redirect", strerror(errno), 1);
	return (fd);
}

static	void	get_and_write_input(int tmp_fd, char *eof)
{
	char	*input;

	signal(SIGINT, interrupt_here_document);
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			error_message("warning",
				"here-document delimited by end-of-file", 0);
			close(tmp_fd);
			exit(0);
		}
		if (ft_strcmp(input, eof))
			ft_putendl_fd(input, tmp_fd);
		else
		{
			close(tmp_fd);
			free(input);
			break ;
		}
		free(input);
	}
	exit(0);
}

static void	restores_stdin_and_closes()
{
	int		tmp_fd;

	tmp_fd = open("poggers", O_RDONLY);
	//delete the temp file
	unlink("poggers");
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
}

void	here_doc_input(char *eof, int *pipefd)
{
	int		tmp_fd;
	int		pipefd_out;
	int		pid;
	int		status;

	tmp_fd = create_temporary_file();
	if (tmp_fd == -1)
		return ;
	pipefd_out = dup(STDOUT_FILENO);
	dup2(pipefd[STDOUT_FILENO], STDOUT_FILENO);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		get_and_write_input(tmp_fd, eof);
	waitpid(pid, &status, 0);
	//that's for when I use cntl+d and stop the << 
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		close(tmp_fd);
		g_minishell.error_status = 130;
	}
	restores_stdin_and_closes();
	dup2(pipefd_out, STDOUT_FILENO);
	close(pipefd_out);
}
