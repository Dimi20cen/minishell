/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:37:05 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 09:40:40 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_possible_path(char *envpath, char *cmd)
{
	char	*path;
	char	*joined1;

	if (ft_strncmp(envpath, cmd, ft_strlen(envpath)) == 0)
		path = ft_strdup(cmd);
	else
	{
		joined1 = ft_strjoin(envpath, "/");
		path = ft_strjoin(joined1, cmd);
		free(joined1);
	}
	return (path);
}

static int	can_execute(char *cmd_path)
{
	struct stat	buffer;

	if (stat(cmd_path, &buffer) == 0 && buffer.st_mode & S_IXUSR)
		return (1);
	return (0);
}

char	*get_absolute_path(char *cmd, char *path_variable)
{
	char		**all_paths;
	char		*cmd_path;
	int			i;

	i = 0;
	all_paths = ft_split(path_variable, ':');
	while (all_paths && all_paths[i])
	{
		cmd_path = get_possible_path(all_paths[i], cmd);
		if (can_execute(cmd_path))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_2d_array(all_paths);
	return (cmd_path);
}
