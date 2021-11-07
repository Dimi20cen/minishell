/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:38:11 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 00:38:12 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(char *input, char *message, int status)
{
	char	*output;
	char	*joined1;
	char	*joined2;
	char	*joined3;
	char	*joined4;

	joined1 = ft_strjoin("\033[1;33m", "minishell: ");
	joined2 = ft_strjoin(joined1, input);
	joined3 = ft_strjoin(joined2, ": ");
	joined4 = ft_strjoin(joined3, message);
	output = ft_strjoin(joined4, "\033[0m");
	free(joined1);
	free(joined2);
	free(joined3);
	free(joined4);
	ft_putendl_fd(output, 2);
	g_minishell.error_status = status;
	free(output);
}
