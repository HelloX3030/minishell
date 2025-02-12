/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expression.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:00 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/12 15:14:46 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_expression(t_expression *expr)
{
	if (!expr)
		return ;
	if (expr->str)
		free(expr->str);
	if (expr->child)
		free_expression(expr->child);
	if (expr->next)
		free_expression(expr->next);
	free(expr);
}
