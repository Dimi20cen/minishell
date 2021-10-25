/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:26:28 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/24 19:24:15 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//"lol sdfasd adfasdf sdfasdf" sdfasdf   "fasdf sdfasdf /// ||| "sadfadf\nfdasfd"
//"0"1"

// Greeting shell during startup
void ms_init_shell()
{
	char	*input;
	t_split	data;

	while (1)
	{
		data.i = 0;
		if (!(input = readline("gimme input NOW >")))
			continue ;
		// printf("the input is: %s\n", input);
		add_history(input);
		ms_input_parser(input, &data);
		int j = -1;
		while (j++ < 7)
		{
			printf("argument %d is: %s\n", j, data.tokens[j]);
		}
	}
}

int main()
{
	ms_init_shell();
	return (0);
}