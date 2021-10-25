
#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_split
{
	int		i;
	char	tokens[40][200];
}			t_split;

# include "Libft/libft.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ms_input_parser(char *input, t_split *data);

#endif