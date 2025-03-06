/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_expression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:45:26 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/06 14:54:59 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	init_cmd_values(t_expression *expr)
{
	expr->args = NULL;
	expr->infiles = NULL;
	expr->outfiles = NULL;
	expr->append = NULL;
}

static void	init_controll_structures(t_expression *expr)
{
	expr->child = NULL;
	expr->next = NULL;
}

static void	init_redirections(t_expression *expr)
{
	expr->saved_stdout = -1;
	expr->out_redir_count = 0;
	expr->out_redir_fds = NULL;
	expr->saved_stdin = -1;
}

t_expression	*create_expression(t_expression_type type)
{
	t_expression	*expr;

	expr = malloc(sizeof(t_expression));
	if (!expr)
		return (NULL);
	expr->type = type;
	init_cmd_values(expr);
	init_controll_structures(expr);
	init_redirections(expr);
	return (expr);
}
