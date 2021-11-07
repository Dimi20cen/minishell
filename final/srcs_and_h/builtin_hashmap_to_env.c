/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_hashmap_to_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:35:58 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:35:59 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pair_to_env_entry(t_pair *pair)
{
	char	*entry;
	char	*temp;

	temp = ft_strjoin(pair->key, "=");
	entry = ft_strjoin(temp, pair->value);
	free(temp);
	return (entry);
}

char	**hashmap_to_env(t_hashmap *table)
{
	unsigned int	i;
	unsigned int	j;
	t_pair			*current;
	t_pair			*temp;
	char			**env;

	i = 0;
	j = 0;
	env = ft_calloc(sizeof (char *), table->count + 1);
	while (i < table->size && j < table->count)
	{
		current = table->pairs[i];
		while (current != NULL)
		{
			temp = current->next;
			env[j] = pair_to_env_entry(current);
			current = temp;
			j++;
		}
		i++;
	}
	return (env);
}
