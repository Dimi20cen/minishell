/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:16:28 by graja             #+#    #+#             */
/*   Updated: 2021/10/25 11:55:54 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static
void	ms_printenv(t_list *head)
{
	t_env	*val;

	while (head)
	{
		val = (t_env *)(head->content);
		printf("Name	= %s\n", val->name);
		printf("Value	= %s\n\n", val->value);
		head = head->next;
	}
}

int	ms_add2list(t_list **ehead, char *str)
{
	t_env	*content;
	char	**rst;

	content = malloc(sizeof(t_env));
	if (!ehead || !str || !content)
		return (1);
	rst = ft_split(str, '=');
	if (!rst)
		return (1);
	content->name = rst[0];
	content->value = rst[1];
	ft_lstadd_back(ehead, ft_lstnew(content));
	return (0);
}


int	ms_init_env(t_list **ehead, char **env)
{
	int	err;
	int	i;

	err = 0;
	i = 0;
	while (!err && env && env[i])
	{
		err = ms_add2list(ehead, env[i]);
		i++;
	}
	if (!env || !i)
		err = 1;
	ms_printenv(*ehead);
	return (err);
}
