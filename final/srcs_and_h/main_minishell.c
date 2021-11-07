/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:26:28 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 09:42:31 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_input(char **input)
{
	char	*prompt;

	prompt = create_prompt();
	define_input_signals();
	*input = readline(prompt);
	free(prompt);
}

//Read–eval–print loop
static void	repl(void)
{
	char	*input;
	t_token	*token_lst;

	while (1)
	{
		token_lst = NULL;
		input = NULL;
		read_input(&input);
		if (input && *input)
			add_history(input);
		tokenizer(&input, &token_lst);
		parse_and_execute(token_lst);
		token_list_clear(&token_lst);
		if (input)
			free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	g_minishell.error_status = 0;
	if (argc > 1 && argv)
		error_message("bruv", "too many arguments.", 42);
	g_minishell.env = env_to_hashmap(env);
	g_minishell.local_vars = hashmap_create_table(69);
	repl();
	return (0);
}
