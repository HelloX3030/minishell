/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:31:48 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

// static int	set_input_redirect(t_expression *expr)
// {
// 	expr->in_redir_count = ft_lstsize(expr->infiles);
// 	if (expr->in_redir_count == 0)
// 		return (EXIT_SUCCESS);
// 	expr->in_redir_fds = malloc(sizeof(int) * expr->in_redir_count);
// 	if (!expr->in_redir_fds)
// 		return (expr->in_redir_count = 0, EXIT_FAILURE);
// 	expr->saved_stdin = dup(STDIN_FILENO);
// 	if (expr->saved_stdin == -1)
// 		return (free(expr->in_redir_fds), expr->in_redir_fds = NULL,
// 			expr->in_redir_count = 0, EXIT_FAILURE);
// 	if (redirect_fd(expr->infiles, expr->in_redir_fds, O_RDONLY,
// 			STDIN_FILENO) == EXIT_FAILURE)
// 	{
// 		dup2(expr->saved_stdin, STDIN_FILENO);
// 		close(expr->saved_stdin);
// 		expr->saved_stdin = -1;
// 		free(expr->in_redir_fds);
// 		expr->in_redir_fds = NULL;
// 		expr->in_redir_count = 0;
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

// static int	set_output_redirect(t_expression *expr)
// {
// 	expr->out_redir_count = ft_lstsize(expr->outfiles);
// 	if (expr->out_redir_count == 0)
// 		return (EXIT_SUCCESS);
// 	expr->out_redir_fds = malloc(sizeof(int) * expr->out_redir_count);
// 	if (!expr->out_redir_fds)
// 		return (expr->out_redir_count = 0, EXIT_FAILURE);
// 	expr->saved_stdout = dup(STDOUT_FILENO);
// 	if (expr->saved_stdout == -1)
// 		return (free(expr->out_redir_fds), expr->out_redir_fds = NULL,
// 			expr->out_redir_count = 0, EXIT_FAILURE);
// 	if (redirect_fd(expr->outfiles, expr->out_redir_fds,
// 			O_WRONLY | O_CREAT | O_TRUNC, STDOUT_FILENO) == EXIT_FAILURE)
// 	{
// 		dup2(expr->saved_stdout, STDOUT_FILENO);
// 		close(expr->saved_stdout);
// 		expr->saved_stdout = -1;
// 		free(expr->out_redir_fds);
// 		expr->out_redir_fds = NULL;
// 		expr->out_redir_count = 0;
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

// static int	set_append_redirect(t_expression *expr)
// {
// 	expr->append_redir_count = ft_lstsize(expr->appendfiles);
// 	if (expr->append_redir_count == 0)
// 		return (EXIT_SUCCESS);
// 	expr->append_redir_fds = malloc(sizeof(int) * expr->append_redir_count);
// 	if (!expr->append_redir_fds)
// 		return (expr->append_redir_count = 0, EXIT_FAILURE);
// 	if (expr->saved_stdout == -1)
// 	{
// 		expr->saved_stdout = dup(STDOUT_FILENO);
// 		if (expr->saved_stdout == -1)
// 			return (free(expr->append_redir_fds), expr->append_redir_fds = NULL,
// 				expr->append_redir_count = 0, EXIT_FAILURE);
// 	}
// 	if (redirect_fd(expr->appendfiles, expr->append_redir_fds,
// 			O_WRONLY | O_CREAT | O_APPEND, STDOUT_FILENO) == EXIT_FAILURE)
// 	{
// 		dup2(expr->saved_stdout, STDOUT_FILENO);
// 		close(expr->saved_stdout);
// 		expr->saved_stdout = -1;
// 		free(expr->append_redir_fds);
// 		expr->append_redir_fds = NULL;
// 		expr->append_redir_count = 0;
// 		return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

int	redirect(t_expression *expr)
{
	// if (set_input_redirect(expr) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// if (set_output_redirect(expr) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// if (set_append_redirect(expr) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// return (EXIT_SUCCESS);
	(void)expr;
	return (EXIT_SUCCESS);
}
