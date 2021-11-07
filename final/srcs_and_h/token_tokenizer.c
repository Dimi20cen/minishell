/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:40:39 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:40:40 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_eof(char *line)
{
	if (line)
		return ;
	printf("\n");
	my_exit();
}

static int	should_tokenize(char *line)
{
	//check_eof is to "capture" the cntl + D, if EOF is encountered while reading a line NULL is returned
	check_eof(line);
	if (line[0] == '\0')
		return (0);
	return (1);
}

void	tokenizer(char **line, t_token **token_lst)
{
	int		i;
	int		end_token;

	i = 0;
	if (!(should_tokenize(*line)))
		return ;
	//prepare line so its easier to split it, by adding spaces before and after operators
	check_and_insert_spaces(line);
	end_token = i;
	// untill the string line is no more run loop
	while ((*line)[i])
		if (!split_to_tokens(&end_token, *line, &i, token_lst))
			return ;
}
