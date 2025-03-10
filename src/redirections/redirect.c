/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 18:40:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	make_redir(int *saved_fd, char *file, int flags)
{
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
			make_redir(&expr->saved_stdin, redir_data->file, O_RDONLY);
		else if (redir_data->type == REDIR_OUT)
			make_redir(&expr->saved_stdout, redir_data->file,
				O_WRONLY | O_CREAT | O_TRUNC);
		else if (redir_data->type == REDIR_APPEND)
			make_redir(&expr->saved_stdout, redir_data->file,
				O_WRONLY | O_CREAT | O_APPEND);
		redir = redir->next;
	}
	return (EXIT_SUCCESS);
}
