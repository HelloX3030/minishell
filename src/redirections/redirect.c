/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/06 15:36:53 by lseeger          ###   ########.fr       */
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
	t_list	*node;
	int		i;

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
	node = expr->outfiles;
	i = 0;
	while (node)
	{
		expr->out_redir_fds[i] = open(node->content,
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (expr->out_redir_fds[i] == -1)
			// incomplete
			return (EXIT_FAILURE);
		if (dup2(expr->out_redir_fds[i], STDOUT_FILENO) == -1)
			// incomplete
			return (EXIT_FAILURE);
		i++;
		node = node->next;
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
