/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:39:03 by dmylonas          #+#    #+#             */
/*   Updated: 2021/11/07 13:37:51 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>

//token's types
# define T_PIPE			69
# define T_FILE			3
# define T_BUILTIN		0
# define T_REDIRECT		24
# define T_HERE_DOC		42
# define T_LITERAL		11

# define IN		0
# define OUT	1
# define KEY	0
# define VALUE	1

typedef struct s_pair
{
	char			*key;
	char			*value;
	struct s_pair	*next;
}					t_pair;

typedef struct s_hashmap
{
	t_pair			**pairs;
	unsigned int	count;
	unsigned int	size;
}					t_hashmap;

typedef struct s_env
{
	char	*name;
	char	*value;
}			t_env;

//error_status is for the $?
typedef struct s_minishell
{
	t_hashmap	*env;
	t_hashmap	*local_vars;
	int			error_status;
}				t_minishell;
t_minishell	g_minishell;

//for the tokenizer
typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
	struct s_token	*previous;
}					t_token;

typedef struct s_var
{
	char	*before;
	char	*after;
	char	*value;
	char	*pointer;
}			t_var;

//utils
void				print_2d_array_fd(char **array, int fd);
void				free_2d_array(char **ptr);

//exec
char				*get_absolute_path(char *cmd, char *path_variable);
void				execute(char **cmd);

//parse
void				parse_and_execute(t_token *token_lst);
void				command_parser(
						t_token *token_lst, t_token *pipe, int *old_pipe_in);
void				check_redirects(
						t_token *token_lst, t_token *pipe, int *pipefd);
void				here_doc_input(char *eof, int *pipefd);
char				**create_command_array(t_token *head, t_token *pipe);
void				interrupt_here_document(int signal);

//----------------------------------------------------------------------------
//tokenizer

void				tokenizer(char **line, t_token **token_lst);
void				add_token(char *line,
						int start, int end_token, t_token **token_lst);
int					split_to_tokens(int *end_token,
						char *line, int *i, t_token **token_lst);
void				check_and_insert_spaces(char **line);
int					no_blanks_around_operator(char *line, char *line_init);
void				handle_quotes(char **token_ptr, int i, int *end_quote);
void				define_end_quote(char *token, int has_variable,
						char first_quote, int *end_quote);

int					is_quote(char c);
int					is_between_quotes(
						char *line, int i, int *match_index, char c);
void				remove_quotes(char **value, char quote);

void				define_type(t_token *previous, char *value, int *type);
int					is_builtin(char *value);

void				expand_variables(char **value);
void				free_var_struct(t_var *var);
void				expand(char **variable);
void				handle_var_single_quote(t_var *var, char **value, int i);

char				*search_var(char *value, int *i);
int					get_var_size(char *var, int *index);
void				free_var_struct(t_var *var);
char				**split_in_two(const char *string, char c);

void				token_list_clear(t_token **lst);
t_token				*token_create_new(char *value, int type);
void				token_add_back(t_token **lst, t_token *new_token);
t_token				*token_return_last(t_token *lst);
//-------------------------------------------------------------------

char				*create_prompt(void);
void				define_input_signals(void);

//--------------------------------------------------------------------HASHING

t_pair				*hashmap_create_pair(char *key, char *value);
t_hashmap			*hashmap_create_table(unsigned int size);
void				hashmap_free_pair(t_pair *pair);
void				hashmap_free_table(t_hashmap *table);
void				hashmap_insert(char *key, char *value, t_hashmap *table);
char				*hashmap_search(t_hashmap *table, char *key);
void				hashmap_handle_collision(t_hashmap *table,
						unsigned long int index, t_pair *new_pair);
void				hashmap_delete(t_hashmap *table, char *key);
unsigned long int	hash(char *key, unsigned int size);

//--------------------------------------------------------------------------
void				error_message(char *input, char *message, int status);
//--------------------------------------------------------------------------

t_hashmap			*env_to_hashmap(char **env);
char				**hashmap_to_env(t_hashmap *table);
char				**hashmap_to_env_with_quotes(t_hashmap *table);

void				print_environment(t_hashmap *env, int fd);
int					export(char **cmd);
void				unset(char **cmd);
void				pwd(void);
void				cd(char *path);
void				echo(char **cmd);
void				exit_builtin(char **cmd);
void				my_exit(void);
int					set_local_variable(char **cmd, int *i);

int					get_2d_array_len(char **array);
void				join_2d_array(char *string_to_join, char **array);

#endif
