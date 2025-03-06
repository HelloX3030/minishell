/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/06 15:44:47 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	reset_input_redirect(t_expression *expr)
{
	(void)expr;
	return (EXIT_SUCCESS);
}

static int	reset_output_redirect(t_expression *expr)
{
	int	i;

	i = -1;
	while (++i < expr->out_redir_count)
	{
		if (close(expr->out_redir_fds[i]) == -1)
			return (EXIT_FAILURE);
	}
	free(expr->out_redir_fds);
	expr->out_redir_fds = NULL;
	expr->out_redir_count = 0;
	if (expr->saved_stdout != -1)
	{
		if (dup2(expr->saved_stdout, STDOUT_FILENO) == -1)
			return (EXIT_FAILURE);
		if (close(expr->saved_stdout) == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	reset_append_redirect(t_expression *expr)
{
	(void)expr;
	return (EXIT_SUCCESS);
}

int	reset_redirect(t_expression *expr)
{
	if (reset_input_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (reset_output_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (reset_append_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
