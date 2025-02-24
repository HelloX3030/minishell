/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression_has_syntax_error.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:32:07 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/24 16:33:14 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

bool	expression_has_syntax_error(t_expression *expr)
{
	if (!expr)
		return (false);
	if (expr->type == EXPR_SYNTAX_ERROR)
		return (true);
	if (expression_has_syntax_error(expr->child))
		return (true);
	if (expression_has_syntax_error(expr->next))
		return (true);
	return (false);
}
