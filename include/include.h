/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/07 13:38:56 by lkubler          ###   ########.fr       */
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
static int	path_history(t_command *args);
int			mini_cd(t_command *command, t_env *env);
static int	count_args(char **args);
int			mini_echo(char **args);
void		mini_pwd(void);

// exec
int		is_builtin(char *cmd);
int		dispatch_builtin(t_command *command);
void	execute(t_command *command);

// tokens
t_token					*create_token(t_token_type type, char *str);
t_token					*parse_token(char *str);
void					print_token(t_token *token);
void					print_token_type(t_token_type type);
void					free_token(t_token *token);

// expressions
t_expression			*create_expression(void);
t_expression			*parse_expression(char *str);
void					print_expression(t_expression *expr, int insertion);
void					print_expression_type(t_expression_type type);
void					free_expression(t_expression *expr);

// commands
t_command				*create_command(void);
t_command				*parse_command(char *str);
void					print_command(t_command *cmd, int insertion);
void					free_command(t_command *cmd);

#endif
