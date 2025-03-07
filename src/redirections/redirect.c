/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/07 16:22:58 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	set_input_redirect(t_expression *expr)
{
	(void)expr;
	return (EXIT_SUCCESS);
}

static int	set_output_redirect(t_expression *expr)
{
	expr->out_redir_count = ft_lstsize(expr->outfiles);
	if (expr->out_redir_count == 0)
		return (EXIT_SUCCESS);
	expr->out_redir_fds = malloc(sizeof(int) * expr->out_redir_count);
	if (!expr->out_redir_fds)
		return (expr->out_redir_count = 0, EXIT_FAILURE);
	expr->saved_stdout = dup(STDOUT_FILENO);
	if (expr->saved_stdout == -1)
		return (free(expr->out_redir_fds), expr->out_redir_count = 0,
			EXIT_FAILURE);
	if (redirect_fd(expr->outfiles, expr->out_redir_fds,
			O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO) == EXIT_FAILURE)
	{
		dup2(expr->saved_stdout, STDOUT_FILENO);
		close(expr->saved_stdout);
		expr->saved_stdout = -1;
		free(expr->out_redir_fds);
		expr->out_redir_fds = NULL;
		expr->out_redir_count = 0;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	set_append_redirect(t_expression *expr)
{
	(void)expr;
	return (EXIT_SUCCESS);
}

int	redirect(t_expression *expr)
{
	if (set_input_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_output_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_append_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
