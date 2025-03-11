/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_minishell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:31:14 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 18:18:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	expand_expr_vars(t_expression *expr, t_env *env)
{
	t_list	*tmp;
	char	**arg;
	t_redir	*redir;

	tmp = expr->args;
	while (tmp)
	{
		arg = (char **)&tmp->content;
		if (expand_env(arg, env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	tmp = expr->redirs;
	while (tmp)
	{
		redir = tmp->content;
		if (expand_env(&redir->file, env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

static void	execute_expression(t_minishell *ms, t_expression *expr)
{
	char	**args;

	if (expand_expr_vars(expr, ms->env) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
	args = list_to_arr(ms->expr->args);
	if (!args)
		exit_minishell(ms, EXIT_FAILURE);
	if (!is_cmd(*args, ms->env))
		exit_minishell(ms, EXIT_FAILURE); // error code 127
	if (redirect(expr) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
	// obsolete
	if (ft_strcmp(*args, "exit") == 0)
		exit_minishell(ms, EXIT_SUCCESS);
	execute(args, ms->env);
	ft_free_strs(args);
	if (reset_redirect(expr) == EXIT_FAILURE)
		exit_minishell(ms, EXIT_FAILURE);
}

void	execute_minishell(t_minishell *ms)
{
	// placeholder
	execute_expression(ms, ms->expr);
}
