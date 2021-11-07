/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_execute_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:37:00 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 09:43:18 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	define_path_variable(char **path_variable, char **cmd)
{
	*path_variable = hashmap_search(g_minishell.env, "PATH");
	if (!*path_variable)
	{
		*path_variable = hashmap_search(g_minishell.local_vars, "PATH");
		if (!*path_variable)
		{
			error_message(cmd[0], "no such file or directory.", 127);
			return (0);
		}
	}
	return (1);
}

static int	add_path_to_cmd_name(char **cmd)
{
	char	*cmd_name;
	char	*path_variable;

	if (!cmd[0] || (!define_path_variable(&path_variable, cmd)))
		return (0);
	cmd_name = get_absolute_path(cmd[0], path_variable);
	if (!cmd_name)
	{
		error_message(cmd[0], "command not found.", 127);
		return (0);
	}
	free(cmd[0]);
	cmd[0] = cmd_name;
	return (1);
}

static void	execute_builtin(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "echo")))
		echo(cmd);
	else if (!(ft_strcmp(cmd[0], "cd")))
		cd(cmd[1]);
	else if (!(ft_strcmp(cmd[0], "pwd")))
		pwd();
	else if (!(ft_strcmp(cmd[0], "export")))
		export(cmd);
	else if (!(ft_strcmp(cmd[0], "unset")))
		unset(cmd);
	else if (!(ft_strcmp(cmd[0], "env")))
		print_environment(g_minishell.env, STDOUT_FILENO);
	else if (!(ft_strcmp(cmd[0], "exit")))
		my_exit();
}

static void	execute_cmd(char **cmd)
{
	int		pid;
	int		status;
	char	**env_variables;

	if ((!cmd[0]) || (!add_path_to_cmd_name(cmd)))
		return ;
	pid = fork();
	//child process
	if (pid == 0)
	{
		env_variables = hashmap_to_env(g_minishell.env);
		execve(cmd[0], cmd, env_variables);
		free_2d_array(env_variables);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_minishell.error_status = WEXITSTATUS(status);
}

void	execute(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[i])
	{
		if (ft_strchr(cmd[i], '='))
			set_local_variable(cmd, &i);
	}
	if (is_builtin(cmd[i]))
		execute_builtin(&cmd[i]);
	else
		execute_cmd(&cmd[i]);
}
