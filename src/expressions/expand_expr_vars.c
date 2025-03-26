/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_expr_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:16:17 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 14:37:48 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int expand_args(t_list *args, t_minishell *ms)
{
	while (args)
	{
		// debug print
		printf("arg before expansion: %s\n", (char *)args->content);
		if (expand_env((char **)&args->content, ms) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		printf("arg after expand_env(): %s\n", (char *)args->content);
		if (expand_wildcards((char **)&args->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		printf("arg after expand_wildcards(): %s\n", (char *)args->content);
		if (remove_quotes((char **)&args->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		printf("arg after removing quotes: %s\n", (char *)args->content);
		args = args->next;
	}
	return (EXIT_SUCCESS);
}

static int expand_redirs(t_list *redirs, t_minishell *ms)
{
	while (redirs)
	{
		if (expand_env(&((t_redir *)redirs->content)->file, ms) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (remove_quotes(&((t_redir *)redirs->content)->file) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		redirs = redirs->next;
	}
	return (EXIT_SUCCESS);
}

int expand_expr_vars(t_expression *expr, t_minishell *ms)
{
	if (expand_args(expr->args, ms) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (expand_redirs(expr->redirs, ms) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
