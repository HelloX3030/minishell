/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expression_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:07 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/04 16:21:43 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static bool	return_type(t_expression_type type)
{
	if (type == EXPR_SYNTAX_ERROR || type == EXPR_UNCLOSED_GROUP
		|| type == EXPR_UNCLOSED_AND || type == EXPR_UNCLOSED_OR
		|| type == EXPR_UNCLOSED_PIPE)
		return (true);
	return (false);
}

/*
	- group with no childs
	- cmds with no valid follow up
	=> Warning: no else if, both cases need to be checked combined
*/
static bool	syntax_error(t_expression *expr)
{
	if (expr->type == EXPR_CMD && ft_strcmp(expr->args->content, "(") == 0
		&& (!expr->child || expr->child->type == EXPR_END))
		return (true);
	if (expr->type == EXPR_CMD && (!expr->next || expr->next->type == EXPR_CMD))
		return (true);
	return (false);
}

t_expression_type	get_expression_error(t_expression *expr)
{
	t_expression_type	type;

	if (!expr)
		return (EXPR_CMD);
	else if (expr->type == EXPR_SYNTAX_ERROR
		|| expr->type == EXPR_UNCLOSED_GROUP)
		return (expr->type);
	else if (syntax_error(expr))
		return (EXPR_SYNTAX_ERROR);
	else if (expr->type == EXPR_PIPE && expr->next->type == EXPR_END)
		return (EXPR_UNCLOSED_PIPE);
	else if (expr->type == EXPR_AND && expr->next->type == EXPR_END)
		return (EXPR_UNCLOSED_AND);
	else if (expr->type == EXPR_OR && expr->next->type == EXPR_END)
		return (EXPR_UNCLOSED_OR);
	type = get_expression_error(expr->child);
	if (return_type(type))
		return (type);
	type = get_expression_error(expr->next);
	if (return_type(type))
		return (type);
	return (EXPR_CMD);
}
