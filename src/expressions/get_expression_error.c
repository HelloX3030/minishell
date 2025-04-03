/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expression_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:07 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/03 17:07:29 by lseeger          ###   ########.fr       */
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

t_expression_type	get_expression_error(t_expression *expr)
{
	t_expression_type	type;

	if (!expr)
		return (EXPR_CMD);
	if (return_type(expr->type))
		return (expr->type);
	type = get_expression_error(expr->child);
	if (return_type(type))
		return (type);
	type = get_expression_error(expr->next);
	if (return_type(type))
		return (type);
	return (EXPR_CMD);
}
