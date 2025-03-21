/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_expression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:45:26 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:59:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_expression	*create_expression(t_expression_type type)
{
	t_expression	*expr;

	expr = malloc(sizeof(t_expression));
	if (!expr)
		return (NULL);
	expr->type = type;
	expr->args = NULL;
	expr->child = NULL;
	expr->next = NULL;
	expr->saved_stdout = -1;
	expr->saved_stdin = -1;
	expr->redirs = NULL;
	return (expr);
}
