/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_expr_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:16:17 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/08 14:49:53 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	expand_args(t_list *args, t_minishell *ms)
{
	t_list	*lst_start;

	lst_start = args;
	while (args)
	{
		if (expand_env((char **)&args->content, ms) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		args = args->next;
	}
	if (expand_wildcards(lst_start) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	args = lst_start;
	while (args)
	{
		if (remove_quotes((char **)&args->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		args = args->next;
	}
	return (EXIT_SUCCESS);
}

static int	expand_redirs(t_list *redirs, t_minishell *ms)
{
	t_list	*lst_start;
	t_redir	*redir;
	int		status;

	lst_start = redirs;
	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		if (expand_env(&redir->file, ms) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redirs = redirs->next;
	}
	status = expand_redirect_wildcard(lst_start);
	if (status != EXIT_SUCCESS)
		return (status);
	redirs = lst_start;
	while (redirs)
	{
		redir = (t_redir *)redirs->content;
		if (remove_quotes(&redir->file) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
}

int	expand_expr_vars(t_expression *expr, t_minishell *ms)
{
	if (expand_args(expr->args, ms) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (expand_redirs(expr->redirs, ms));
}
