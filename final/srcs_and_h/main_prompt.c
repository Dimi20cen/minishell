/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:38:26 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:38:27 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_prompt()
{
	char	*pwd_buffer;
	char	*pwd;
	char	*prompt;
	char	*prompt1;
	char	*prompt2;

	pwd_buffer = NULL;
	pwd = getcwd(pwd_buffer, 0);
	prompt1 = ft_strjoin(pwd, "$ ");
	prompt2 = ft_strjoin("\x1b[32m", prompt1);
	prompt = ft_strjoin(prompt2, "\x1b[0m");

	free(pwd);
	free(prompt1);
	free(prompt2);
	return (prompt);
}
