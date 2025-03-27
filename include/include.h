/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/27 15:42:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <unistd.h>

# define PROMPT "myshell> "
# define SUCCESS 1
# define FAILURE 0

extern volatile sig_atomic_t	g_in_exec;
# define PIPE_READ_END 0
# define PIPE_WRITE_END 1

# define DEFAULT_FILE_PERMISSIONS 0644

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_GROUP,
	TOKEN_OPERATOR,
	TOKEN_END,
	TOKEN_SYNTAX_ERROR,
}								t_token_type;

typedef struct s_token
{
	int							type;
	char						*str;
	struct s_token				*next;
}								t_token;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
}								t_redir_type;

typedef struct s_redir
{
	t_redir_type				type;
	char						*file;
}								t_redir;
void							print_redir_type(t_redir_type type);
void							print_redir(t_redir *redir, int insertion);
t_redir							*create_redir(t_redir_type type, char *file);
void							free_redir(void *redir);

typedef enum e_expression_type
{
	EXPR_CMD,
	EXPR_AND,
	EXPR_OR,
	EXPR_PIPE,
	EXPR_END,
	EXPR_SYNTAX_ERROR,
}								t_expression_type;

/*
	- needed for variable expansion
*/
typedef enum e_quote_type
{
	QUOTE_NONE,
	QUOTE_SINGLE,
	QUOTE_DOUBLE,
}								t_quote_type;
void							print_quote_type(t_quote_type type);

/*
	child: will only be set when type == EXPR_GROUP
		contains the subexpressions of the group via a linked list

	next: the next expression in the list

	e. g.
		cmd1 && (cmd2 || cmd3)
		=> cmd1 type AND
		=> type GROUP:
			=> cmd2 type OR
			=> cmd3 type CMD

	expressionss will be evaluated from left to right,
		beginning from the most nested
*/
typedef struct s_expression
{
	t_expression_type			type;

	// cmd values
	t_list						*args;

	// controll structures
	struct s_expression			*child;
	struct s_expression			*next;

	// redirections
	int							saved_stdout;
	int							saved_stdin;
	t_list						*redirs;
}								t_expression;

typedef struct s_env
{
	char						*key;
	char						*value;
	struct s_env				*next;
}								t_env;

typedef struct s_minishell
{
	t_env						*env;
	char						*input;
	t_token						*token;
	t_expression				*expr;
	int							status;
}								t_minishell;

// tokens
int								is_operator(char *str);
int								is_redirection_operator(char *str);

t_token							*create_token(t_token_type type, char **str,
									char *str_end);
t_token							*parse_token(char *str);
void							print_token(t_token *token);
void							print_token_type(t_token_type type);
void							free_token(t_token *token);
t_token							*get_closing_group(t_token *token);
bool							token_has_syntax_error(t_token *token);

// expressions
t_expression					*create_expression(t_expression_type type);
t_expression					*parse_expression(t_token *token, t_token *end,
									t_env *env);
t_token							*parse_cmd_values(t_expression *expr,
									t_token *token, t_token *end);
void							print_expression(t_expression *expr,
									int insertion);
void							print_expression_type(t_expression_type type);
void							free_expression(t_expression *expr);
bool							expression_has_syntax_error(t_expression *expr);
int								expand_expr_vars(t_expression *expr,
									t_minishell *ms);

// minishell
void							init_minishell(t_minishell *ms, char **envp);
void							free_minishell(t_minishell *ms);
void							execute_minishell(t_minishell *ms);

// builtins
int								to_path(int fl, t_env **env);
int								mini_cd(char **args, t_minishell *ms);
int								count_args(char **args);
int								mini_echo(char **args);
int								mini_env(t_minishell *ms);
int								mini_exit(char **args, t_minishell *ms);
int								mini_export(char **args, t_minishell *ms);
// int						is_valid_identifier(const char *str);
int								mini_pwd(void);
int								is_valid_id(const char *str);
int								mini_unset(char **args, t_minishell *ms);

// envs
void							free_env(t_env *env);
t_env							*create_env_node(char *key, char *value);
void							add_env_node(t_env **head, t_env *new_node);
t_env							*init_env(char **envp);
char							*get_env_value(t_env *env, const char *key);
void							set_env_val(t_env **env, char *key,
									char *value);
void							unset_env_val(t_env **env, const char *key);
char							**env_to_array(t_env *env);

// exec
int								is_builtin(char *cmd);
int								dispatch_builtin(char **args, t_minishell *ms);
void							execute(char **args, t_minishell *ms);
bool							is_cmd(char *args, t_env *env);

// externals
char							*find_cmd_path(const char *cmd, t_env *env);
int								execute_ext(char **args, t_minishell *ms);

// utils
char							*path_join(const char *s1, const char *s2);
char							**list_to_arr(t_list *args);
int								remove_quotes(char **str);
void							free_paths(char **paths);
void							free_array(char **array);

// expansion
char							*get_var_end(char *str);
char							*get_var_value(char **str_pos, t_minishell *ms,
									t_quote_type quote_type);
int								expand_env(char **str, t_minishell *ms);
int								expand_wildcards(char **str);

// shell
void							handle_lvl(t_env **env);
int								exec_shell(char **args, t_minishell *ms);

// signals
void							setup_interactive(void);
void							setup_execution(void);
void							reset_singals(void);

// redirections
int								make_redir(int target_fd, char *file,
									int flags);
int								save_fd(int *saved_fd, int fd);
int								restore_fd(int *saved_fd, int fd);
int								redirect(t_expression *expr);
int								reset_redirect(t_expression *expr);

#endif
