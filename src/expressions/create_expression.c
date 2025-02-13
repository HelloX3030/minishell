/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_expression.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:45:26 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/12 15:13:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_expression	*create_expression(t_expression_type type)
{
	t_expression	*expr;

	expr = malloc(sizeof(t_expression));
	if (!expr)
		return (NULL);
	expr->str = NULL;
	expr->type = type;
	expr->child = NULL;
	expr->next = NULL;
	return (expr);
}
