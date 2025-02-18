/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expression.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:00 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/18 16:03:54 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_expression(t_expression *expr)
{
	if (!expr)
		return ;
	if (expr->cmd)
		free(expr->cmd);
	ft_free_strs(expr->args);
	ft_free_strs(expr->infile);
	ft_free_strs(expr->outfile);
	ft_free_strs(expr->append);
	free_expression(expr->child);
	free_expression(expr->next);
	free(expr);
}
