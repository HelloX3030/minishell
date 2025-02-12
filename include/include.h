/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/12 12:39:25 by lkubler          ###   ########.fr       */
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

typedef enum s_token_type
{
	TOKEN_NONE,
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
	EXPR_NONE,
	EXPR_AND,
	EXPR_OR,
	EXPR_BRACKET,
}						t_expression_type;

/*
	childs: all expressions of the same type are
		grouped together in a NULL-terminated Array

	next: the next subexpressions in the list, which
		will get evaluated before

	e. g.
		cmd1 && cmd2 || cmd3 => one expression with type EXPR_OR
		and two childs: one with type EXPR_AND and one with type EXPR_NONE
*/
typedef struct s_expression
{
	char				*str;
	t_expression_type	type;
	struct s_expression	*childs;
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

// builtins
static int	to_path(int fl, t_command *args);
static int	path_history(char *prev_path);
int			mini_cd(t_command *command, t_env *env);
static int	count_args(char **args);
int			mini_echo(char **args);
int			mini_export(char **args, t_env **env);
void		mini_pwd(void);
int			is_valid_id(const char *str);
int			mini_unset(char **args, t_env **env);


// exec
int		is_builtin(char *cmd);
int		dispatch_builtin(t_command *command);
void	execute(t_command *command);

// envs
t_env	*create_env_node(char *key, char *value);
void	add_env_node(t_env **head, t_env *new_node);
t_env	*init_env(char **envp);
char	*get_env_value(t_env *env, const char *key);
void	set_env_val(t_env **env, const char *key, const char *value);
void	unset_env_val(t_env **env, const char *key);
char	**env_to_array(t_env *env);

#endif
