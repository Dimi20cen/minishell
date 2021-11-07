/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_variables_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:41:21 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 09:46:55 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_in_two(const char *string, char c)
{
	char	**splited_strings;
	char	*c_str;

	splited_strings = malloc(3 * sizeof(char *));
	c_str = ft_strchr(string, c);
	splited_strings[0] = ft_substr(string, 0, (c_str - string));
	splited_strings[1] = ft_substr((c_str + 1), 0, ft_strlen(c_str));
	splited_strings[2] = NULL;
	return (splited_strings);
}

char	*search_var(char *value, int *i)
{
	while (value[*i] != '\0')
	{
		if (value[*i] == '$')
			return (&value[*i]);
		*i += 1;
	}
	return (NULL);
}

int	get_var_size(char *var, int *index)
{
	int	i;

	i = 0;
	while ((var[i + 1] != ' ') && (var[i + 1] != '\0') && (var[i + 1] != '$'))
		i++;
	i++;
	*index += i;
	return (i);
}

void	free_var_struct(t_var *var)
{
	ft_free_and_null((void **)&var->before);
	ft_free_and_null((void **)&var->value);
	ft_free_and_null((void **)&var->after);
}
