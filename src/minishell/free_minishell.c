/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:35:08 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/17 16:03:14 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_minishell(t_minishell *ms)
{
	free_env(ms->env);
	if (ms->input)
		free(ms->input);
	ms->input = NULL;
	free_token(ms->token);
	ms->token = NULL;
	free_expression(ms->expr);
	ms->expr = NULL;
}

static int	execute_group_child(t_minishell *ms, t_expression *expr)
{
	int	exit_status;

	exit_status = rec_handle_type(ms, expr->child);
	free_minishell(ms);
	exit(exit_status);
	return (EXIT_FAILURE);
}

static int	handle_group_parent(pid_t pid, t_minishell *ms)
{
	int	status;

	g_in_exec = 1;
	waitpid(pid, &status, 0);
	g_in_exec = 0;
	if (WIFEXITED(status))
		ms->status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ms->status = 128 + WTERMSIG(status);
	return (ms->status);
}

static int	fork_group_process(t_minishell *ms, t_expression *expr)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("minishell: fork failed\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
		execute_group_child(ms, expr);
	else
		return (handle_group_parent(pid, ms));
	return (EXIT_FAILURE);
}

int	handle_group(t_minishell *ms, t_expression *expr)
{
	int	status;

	if (!expr || !expr->child)
		return (EXIT_FAILURE);
	if (redirect(expr) == EXIT_FAILURE)
	{
		ms->status = 1;
		return (EXIT_FAILURE);
	}
	status = fork_group_process(ms, expr);
	if (reset_redirect(expr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (status);
}
