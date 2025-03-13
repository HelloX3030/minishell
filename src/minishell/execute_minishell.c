/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/13 11:11:49 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	args = list_to_arr(ms->expr->args);
	if (expr->type == EXPR_CMD && ft_strcmp((char *)expr->args->content,
		"exit") == 0)
		{
			
			mini_exit(args, ms);
			// if shell_level == 0
			//free_minishell(ms);
			//exit(EXIT_SUCCESS);
			//ms->stop_execution = true;
			//return ;
		}
	execute(args, ms);
	ft_free_strs(args);
	if (reset_redirect(expr) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}
