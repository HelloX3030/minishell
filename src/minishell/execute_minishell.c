/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/05 13:56:24 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	if (expr->type == EXPR_CMD && ft_strcmp((char *)expr->args->content,
			"exit") == 0)
	{
		free_minishell(ms);
		exit(EXIT_SUCCESS);
	}
	args = list_to_arr(ms->expr->args);
	if (!args)
	{
		free_minishell(ms);
		exit(EXIT_FAILURE);
	}
	execute(args, ms->env);
	ft_free_strs(args);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}
