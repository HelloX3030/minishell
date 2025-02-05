/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:55:06 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/05 12:37:51 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <limits.h>
#include <unistd.h>

# define PROMPT "myshell> "

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
	e. g. a && b || c => one expression with type EXPR_OR
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
	char				*cmd;
	char				**args;
	char				*infile;
	char				*outfile;
	bool				append;
	struct s_command	*pipe;
}						t_command;

#endif
