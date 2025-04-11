/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/11 12:44:09 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;
	int		status;

	status = expand_expr_vars(expr, ms);
	if (status == EXIT_FAILURE)
		mini_exit(list_to_arr(expr->args), ms);
	else if (status == EXIT_CONTINUE)
		return (ms->status = 1, write(STDERR_FILENO, "ambiguous redirect\n",
				19), EXIT_FAILURE);
	args = list_to_arr(expr->args);
	if (!args && expr->args)
		mini_exit(args, ms);
	if (redirect(ms, expr) == EXIT_FAILURE)
		return (ft_free_strs(args), ms->status = 1, EXIT_FAILURE);
	if (expr->type == EXPR_CMD && ft_strcmp((char *)expr->args->content,
			"exit") == 0)
		mini_exit(args, ms);
	execute(args, ms);
	status = ms->status;
	if (reset_redirect(expr) == EXIT_FAILURE)
		mini_exit(args, ms);
	return (ft_free_strs(args), status);
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
	char	**args;

	if (!expr)
		return (EXIT_SUCCESS);
	else if (expr->type == EXPR_CMD)
	{
		args = list_to_arr(expr->args);
		if (ft_strcmp(args[0], "(") == 0)
		{
			ft_free_strs(args);
			return (handle_group(ms, expr));
		}
		ft_free_strs(args);
		return (execute_expression(ms, expr));
	}
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
	if (get_expression_error(ms->expr) != EXPR_CMD)
	{
		ms->status = ERROR_CODE_SYNTAX;
		write(STDERR_FILENO, SYNTAX_ERROR, ft_strlen(SYNTAX_ERROR));
		write(STDERR_FILENO, "\n", 1);
		return ;
	}
	ms->heredoc_count = 0;
	ms->status = rec_handle_type(ms, ms->expr);
}
