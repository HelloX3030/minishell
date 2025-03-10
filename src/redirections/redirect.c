/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 19:27:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	redir_in(t_expression *expr, t_redir *redir_data)
{
	save_fd(&expr->saved_stdin, STDIN_FILENO);
	make_redir(STDIN_FILENO, redir_data->file, O_RDONLY);
}

static int	redir_out(t_expression *expr, t_redir *redir_data)
{
	save_fd(&expr->saved_stdout, STDOUT_FILENO);
	make_redir(STDOUT_FILENO, redir_data->file, O_WRONLY | O_CREAT | O_TRUNC);
}

static int	redir_append(t_expression *expr, t_redir *redir_data)
{
	save_fd(&expr->saved_stdout, STDOUT_FILENO);
	make_redir(STDOUT_FILENO, redir_data->file, O_WRONLY | O_CREAT | O_APPEND);
}

int	redirect(t_expression *expr)
{
	t_list	*redir;
	t_redir	*redir_data;

	redir = expr->redirs;
	while (redir)
	{
		redir_data = redir->content;
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
		else if (redir_append(expr, redir_data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
