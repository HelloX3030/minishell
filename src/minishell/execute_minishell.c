/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 13:41:37 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	args = list_to_arr(ms->expr->args);
	if (!args && ms->expr->args)
		mini_exit(args, ms);
	if (expand_expr_vars(expr, ms) == EXIT_FAILURE)
		mini_exit(args, ms);
	if (redirect(expr) == EXIT_FAILURE)
		mini_exit(args, ms);
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
	if (reset_redirect(expr) == EXIT_FAILURE)
		mini_exit(args, ms);
	ft_free_strs(args);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}

//static void	execute_expression(t_minishell *ms, t_expression *expr)
//{
//	char	**args;

//	if (expand_expr_vars(expr, ms) == EXIT_FAILURE)
//		exit_minishell(ms, EXIT_FAILURE);
//	args = list_to_arr(ms->expr->args);
//	if (!args)
//		exit_minishell(ms, EXIT_FAILURE);
//	// error code 127 btw should maybe the normal exit code of excve be used?
//	if (!is_cmd(*args, ms->env))
//		exit_minishell(ms, EXIT_FAILURE);
//	if (redirect(expr) == EXIT_FAILURE)
//		exit_minishell(ms, EXIT_FAILURE);
//	// obsolete
//	if (ft_strcmp(*args, "exit") == 0)
//		exit_minishell(ms, EXIT_SUCCESS);
//	execute(args, ms);
//	ft_free_strs(args);
//	if (reset_redirect(expr) == EXIT_FAILURE)
//		exit_minishell(ms, EXIT_FAILURE);
//}