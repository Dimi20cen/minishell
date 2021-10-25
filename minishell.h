
#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_split
{
	int		i;
	char	tokens[40][200];
}			t_split;

typedef struct s_env
{
	char	*name;
	char	*value;
}		t_env;

# include "Libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/stat.h>

void	ms_input_parser(char *input, t_split *data);
int	ms_add2list(t_list **ehead, char *str);
int	ms_init_env(t_list **ehead, char **env);

#endif
