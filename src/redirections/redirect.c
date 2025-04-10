/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 13:47:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	redir_in(t_expression *expr, t_redir *redir_data)
{
	if (save_fd(&expr->saved_stdin, STDIN_FILENO) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdin, STDIN_FILENO), EXIT_FAILURE);
	if (make_redir(STDIN_FILENO, redir_data->file, O_RDONLY) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdin, STDIN_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	redir_out(t_expression *expr, t_redir *redir_data)
{
	if (save_fd(&expr->saved_stdout, STDOUT_FILENO) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdout, STDOUT_FILENO), EXIT_FAILURE);
	if (make_redir(STDOUT_FILENO, redir_data->file,
			O_WRONLY | O_CREAT | O_TRUNC) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdout, STDOUT_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	redir_append(t_expression *expr, t_redir *redir_data)
{
	if (save_fd(&expr->saved_stdout, STDOUT_FILENO) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdout, STDOUT_FILENO), EXIT_FAILURE);
	if (make_redir(STDOUT_FILENO, redir_data->file,
			O_WRONLY | O_CREAT | O_APPEND) == EXIT_FAILURE)
		return (restore_fd(&expr->saved_stdout, STDOUT_FILENO), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	handle_redir_data(t_expression *expr, t_redir *redir_data)
{
	if (redir_data->type == REDIR_IN)
	{
		if (redir_in(expr, redir_data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (redir_data->type == REDIR_OUT)
	{
		if (redir_out(expr, redir_data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (redir_data->type == REDIR_APPEND)
	{
		if (redir_append(expr, redir_data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (redir_data->type == REDIR_HEREDOC)
	{
		if (redir_herdoc(expr, redir_data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	redirect(t_expression *expr)
{
	t_list	*redir;

	redir = expr->redirs;
	while (redir)
	{
		if (handle_redir_data(expr, redir->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
