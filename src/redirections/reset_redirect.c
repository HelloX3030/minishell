/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:32:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

// static int	reset_input_redirect(t_expression *expr)
// {
// 	int	return_value;

// 	return_value = EXIT_SUCCESS;
// 	if (expr->saved_stdin != -1)
// 	{
// 		if (dup2(expr->saved_stdin, STDIN_FILENO) == -1)
// 			return_value = EXIT_FAILURE;
// 		if (close(expr->saved_stdin) == -1)
// 			return_value = EXIT_FAILURE;
// 		expr->saved_stdin = -1;
// 	}
// 	if (close_fds(expr->in_redir_fds, expr->in_redir_count) == EXIT_FAILURE)
// 		return_value = EXIT_FAILURE;
// 	expr->in_redir_count = 0;
// 	free(expr->in_redir_fds);
// 	expr->in_redir_fds = NULL;
// 	return (return_value);
// }

// static int	reset_output_redirect(t_expression *expr)
// {
// 	int	return_value;

// 	return_value = EXIT_SUCCESS;
// 	if (close_fds(expr->out_redir_fds, expr->out_redir_count) == EXIT_FAILURE)
// 		return_value = EXIT_FAILURE;
// 	expr->out_redir_count = 0;
// 	free(expr->out_redir_fds);
// 	expr->out_redir_fds = NULL;
// 	return (return_value);
// }

// static int	reset_append_redirect(t_expression *expr)
// {
// 	(void)expr;
// 	return (EXIT_SUCCESS);
// }

int	reset_redirect(t_expression *expr)
{
	// int	return_value;
	// return_value = EXIT_SUCCESS;
	// if (expr->saved_stdout != -1)
	// {
	// 	if (dup2(expr->saved_stdout, STDOUT_FILENO) == -1)
	// 		return_value = EXIT_FAILURE;
	// 	if (close(expr->saved_stdout) == -1)
	// 		return_value = EXIT_FAILURE;
	// 	expr->saved_stdout = -1;
	// }
	// if (reset_input_redirect(expr) == EXIT_FAILURE)
	// 	return_value = EXIT_FAILURE;
	// if (reset_output_redirect(expr) == EXIT_FAILURE)
	// 	return_value = EXIT_FAILURE;
	// if (reset_append_redirect(expr) == EXIT_FAILURE)
	// 	return_value = EXIT_FAILURE;
	// return (return_value);
	(void)expr;
	return (EXIT_SUCCESS);
}
