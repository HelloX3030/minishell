/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/31 11:58:18 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	execute_expression(t_minishell *ms, t_expression *expr)
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

static int	handle_and(t_minishell *ms, t_expression *expr)
{
	int	status;

	status = execute_expression(ms, expr);
	if (status == EXIT_SUCCESS)
		return (rec_handle_type(ms, expr->next));
	return (status);
}

static int	handle_or(t_minishell *ms, t_expression *expr)
{
	int	status;

	status = execute_expression(ms, expr);
	if (status != EXIT_SUCCESS)
		return (rec_handle_type(ms, expr->next));
	return (status);
}

int	rec_handle_type(t_minishell *ms, t_expression *expr)
{
	if (!expr)
		return (EXIT_SUCCESS);
	if(expr->type == EXPR_CMD)
		return (execute_expression(ms, expr));
	else if (expr->type == EXPR_PIPE)
		return (execute_pipe(ms, expr));
	else if (expr->type == EXPR_AND)
		return (handle_and(ms, expr));
	else if (expr->type == EXPR_OR)
		return (handle_or(ms, expr));
	return (EXIT_SUCCESS);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	ms->status = rec_handle_type(ms, ms->expr);
}
