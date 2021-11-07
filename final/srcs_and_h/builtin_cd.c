/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:35:23 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 09:42:22 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir_to_path(char *path)
{
	char	*pwd;
	char	*error_msg;
	char	buffer[1024];

	pwd = getcwd(buffer, 1024);
	hashmap_insert("OLDPWD", pwd, g_minishell.env);
	if (chdir(path) != 0 && ft_strchr(path, '>') == NULL)
	{
		error_msg = ft_strjoin("cd: ", path);
		error_message(error_msg, strerror(errno), 1);
		free(error_msg);
		return ;
	}
	pwd = getcwd(buffer, 1024);
	hashmap_insert("PWD", pwd, g_minishell.env);
}

static void	change_dir_to_oldpwd(char *path)
{
	printf("%s\n", path);
	change_dir_to_path(path);
}

static void	change_dir_to_home(void)
{
	char	*path;

	path = ft_strdup(hashmap_search(g_minishell.env, "HOME"));
	if (path == NULL)
	{
		error_message("cd", "HOME not  set.", 1);
		free(path);
		return ;
	}
	change_dir_to_path(path);
	free(path);
}

void	cd(char	*path)
{
	char	*current_path;

	g_minishell.error_status = 0;
	//homepath
	if ((!path) || ft_strcmp(path, "~") == 0)
	{
		change_dir_to_home();
		return ;
	}
	//previous location
	else if (ft_strcmp(path, "-") == 0)
	{
		current_path = ft_strdup(hashmap_search(g_minishell.env, "OLDPWD"));
		if (current_path == NULL)
		{
			error_message("cd", "OLDPWD not set.", 1);
			return ;
		}
		change_dir_to_oldpwd(current_path);
	}
	//path
	else
	{
		current_path = ft_strdup(path);
		change_dir_to_path(current_path);
	}
	free(current_path);
}
