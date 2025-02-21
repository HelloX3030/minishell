/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/21 13:09:41 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <unistd.h>

# define PROMPT "myshell> "
# define SUCCESS "1"
# define FAILURE "0"

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_GROUP,
	TOKEN_OPERATOR,
}						t_token_type;

typedef struct s_token
{
	int					type;
	char				*str;
	struct s_token		*next;
}						t_token;

typedef enum e_expression_type
{
	EXPR_CMD,
	EXPR_AND,
	EXPR_OR,
	EXPR_GROUP,
	EXPR_PIPE,
}						t_expression_type;

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
	t_expression_type	type;

	// cmd values
	t_list				*args;
	t_list				*infiles;
	t_list				*outfiles;
	t_list				*append;

	// controll structures
	struct s_expression	*child;
	struct s_expression	*next;
}						t_expression;

/*
	infile:		"<"
	outfile:	">"
	append:		">>"
	pipe: 		"|"
*/
typedef struct s_command
{
	char				**args;
	char				*infile;
	char				*outfile;
	bool				append;
	struct s_command	*pipe;
}						t_command;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

// tokens
int						is_operator(char *str);
int						is_redirection_operator(char *str);

t_token					*create_token(t_token_type type, char *str);
t_token					*parse_token(char *str);
void					print_token(t_token *token);
void					print_token_type(t_token_type type);
void					free_token(t_token *token);
t_token					*get_closing_group(t_token *token);

// expressions
t_expression			*create_expression(t_expression_type type);
t_expression			*parse_expression(t_token *token, t_token *end, t_env *env);
t_token					*parse_cmd_values(t_expression *expr, t_token *token, t_token *end, t_env *env);
void					print_expression(t_expression *expr, int insertion);
void					print_expression_type(t_expression_type type);
void					free_expression(t_expression *expr);
void					execute_expression(t_expression *expr);

// builtins
int to_path(int fl, t_env **env);  // Changed to t_env ** to modify environment
int mini_cd(char **args, t_env **env);  // Changed to t_env **
int		count_args(char **args);
int		mini_echo(char **args);
void	mini_env(t_env *env);
int		mini_export(char **args, t_env **env);
void	mini_pwd(void);
int		is_valid_id(const char *str);
int		mini_unset(char **args, t_env **env);

// envs
t_env	*create_env_node(char *key, char *value);
void	add_env_node(t_env **head, t_env *new_node);
t_env	*init_env(char **envp);
char	*get_env_value(t_env *env, const char *key);
void	set_env_val(t_env **env, char *key, char *value);
void	unset_env_val(t_env **env, const char *key);
char	**env_to_array(t_env *env);

// exec
int	is_builtin(char *cmd);
int	dispatch_builtin(char **args, t_env **env);
void	execute(char **args, t_env *env);
bool	is_cmd(char *args, t_env *env);

// externals
char	*find_cmd_path(const char *cmd, t_env *env);
void	free_array(char **array);
int	execute_ext(char **args, t_env *env);


// utils
char	*path_join(const char *s1, const char *s2);
char	**list_to_arr(t_list *args);

#endif
