/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expression.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:00 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 13:01:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_expression(t_expression *expr)
{
	int	i;

	if (expr->str)
		free(expr->str);
	i = 0;
	while (expr->childs + i)
	{
		free_expression(expr->childs + i);
		i++;
	}
	if (expr->next)
		free_expression(expr->next);
	free(expr);
}
