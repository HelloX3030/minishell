/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/26 17:21:34 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	if (ms->stop_execution)
		return ;
	if (expr->type == EXPR_CMD && ft_strcmp((char *)expr->args->content,
			"exit") == 0)
	{
		// if shell_level == 0
		free_minishell(ms);
		exit(EXIT_SUCCESS);
		ms->stop_execution = true;
		return ;
	}
	args = list_to_arr(ms->expr->args);
	execute(args, ms->env);
	ft_free_strs(args);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}
