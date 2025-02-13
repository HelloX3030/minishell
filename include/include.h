/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/13 14:46:52 by lseeger          ###   ########.fr       */
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
	char				*str;
	t_expression_type	type;
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

// tokens
t_token					*create_token(t_token_type type, char *str);
t_token					*parse_token(char *str);
void					print_token(t_token *token);
void					print_token_type(t_token_type type);
void					free_token(t_token *token);
t_token					*get_closing_group(t_token *token);

// expressions
t_expression			*create_expression(t_expression_type type);
t_expression			*parse_expression(t_token *token, t_token *end);
void					print_expression(t_expression *expr, int insertion);
void					print_expression_type(t_expression_type type);
void					free_expression(t_expression *expr);

// envs
t_env					*create_env_node(char *key, char *value);
void					add_env_node(t_env **head, t_env *new_node);
t_env					*init_env(char **envp);
char					*get_env_value(t_env *env, const char *key);
void					set_env_val(t_env **env, const char *key,
							const char *value);
void					unset_env_val(t_env **env, const char *key);
char					**env_to_array(t_env *env);

#endif
