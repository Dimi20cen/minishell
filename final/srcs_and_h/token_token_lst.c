/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_token_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:40:35 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:40:36 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_return_last(t_token *lst)
{
	t_token	*curr;

	if (!lst)
		return (lst);
	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	token_add_back(t_token **lst, t_token *new_token)
{
	t_token	*curr;

	if (*lst == NULL)
	{
		*lst = new_token;
		return ;
	}
	curr = token_return_last(*lst);
	curr->next = new_token;
	new_token->previous = curr;
}

t_token	*token_create_new(char *value, int type)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	new_token->previous = NULL;
	return (new_token);
}

void	token_list_clear(t_token **lst)
{
	t_token	*aux;
	t_token	*temp;

	aux = *lst;
	if (aux == NULL)
		return ;
	while (aux != NULL)
	{
		temp = aux->next;
		free(aux->value);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
