/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/26 12:01:53 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;
	int		status;

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
	status = ms->status;
	if (reset_redirect(expr) == EXIT_FAILURE)
		mini_exit(args, ms);
	ft_free_strs(args);
	return(status);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	ms->status = execute_expression(ms, ms->expr);
}
