/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expression.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:00 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:34:51 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_expression(t_expression *expr)
{
	if (!expr)
		return ;
	ft_lstclear(&expr->args, free);
	ft_lstclear(&expr->redirs, free_redir);
	free_expression(expr->child);
	free_expression(expr->next);
	reset_redirect(expr);
	free(expr);
}
