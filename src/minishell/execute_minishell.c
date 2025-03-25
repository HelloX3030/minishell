/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 14:11:29 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	if (expand_expr_vars(expr, ms) == EXIT_FAILURE)
		mini_exit(list_to_arr(expr->args), ms);
	args = list_to_arr(expr->args);
	if (!args && expr->args)
		mini_exit(args, ms);
	if (redirect(expr) == EXIT_FAILURE)
		mini_exit(args, ms);
	if (expr->type == EXPR_CMD && ft_strcmp((char *)expr->args->content,
			"exit") == 0)
		mini_exit(args, ms);
	execute(args, ms);
	if (reset_redirect(expr) == EXIT_FAILURE)
		mini_exit(args, ms);
	ft_free_strs(args);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}
