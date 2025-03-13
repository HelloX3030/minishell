/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/13 13:57:55 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	if (expand_expr_vars(expr, ms->env) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
	args = list_to_arr(ms->expr->args);
	if (!args)
		exit_minishell(ms, EXIT_FAILURE);
	// error code 127 btw should maybe the normal exit code of excve be used?
	if (!is_cmd(*args, ms->env))
		exit_minishell(ms, EXIT_FAILURE);
	if (redirect(expr) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
	// obsolete
	if (ft_strcmp(*args, "exit") == 0)
		exit_minishell(ms, EXIT_SUCCESS);
	execute(args, ms->env);
	ft_free_strs(args);
	if (reset_redirect(expr) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}
