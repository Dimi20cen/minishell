/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_to_hashmap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:35:33 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:35:36 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_find_value(char *env_line)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (env_line[i] != '=')
		i++;
	j = i;
	while (env_line[j])
		j++;
	value = ft_substr(env_line, i + 1, j);
	return (value);
}

static char	*env_find_key(char *env_line)
{
	int		i;
	char	*key;

	i = 0;
	while (env_line[i] != '=')
		i++;
	key = ft_substr(env_line, 0, i);
	return (key);
}

t_hashmap	*env_to_hashmap(char **env)
{
	t_hashmap	*table;
	int			len;
	int			i;
	char		*key;
	char		*value;

	len = 0;
	i = 0;
	while (env[len])
		len++;
	table = hashmap_create_table(len * 3);
	//passing env to table
	while (i < len)
	{
		key = env_find_key(env[i]);
		value = env_find_value(env[i]);
		hashmap_insert(key, value, table);
		i++;
		free(key);
		free(value);
	}
	return (table);
}
