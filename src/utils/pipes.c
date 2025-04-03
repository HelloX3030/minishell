/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:24:46 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/03 11:48:43 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	setup_child1(int *pipefd, t_minishell *ms, t_expression *expr)
{
	int	status;

	close(pipefd[PIPE_READ_END]);
	dup2(pipefd[PIPE_WRITE_END], STDOUT_FILENO);
	close(pipefd[PIPE_WRITE_END]);
	status = execute_expression(ms, expr);
	exit(status);
}

static void	setup_child2(int *pipefd, t_minishell *ms, t_expression *expr)
{
	int	status;

	close(pipefd[PIPE_WRITE_END]);
	dup2(pipefd[PIPE_READ_END], STDIN_FILENO);
	close(pipefd[PIPE_READ_END]);
	status = execute_expression(ms, expr->next);
	exit(status);
}

static int	wait_for_child(pid_t pid1, pid_t pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

static int	cleanup_pipe(int *pipefd, pid_t pid1, pid_t pid2)
{
	close(pipefd[PIPE_READ_END]);
	close(pipefd[PIPE_WRITE_END]);
	if (pid1 > 0)
		waitpid(pid1, NULL, 0);
	if (pid2 > 0)
		waitpid(pid2, NULL, 0);
	return (EXIT_FAILURE);
}

int	execute_pipe(t_minishell *ms, t_expression *expr)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		return (EXIT_FAILURE);
	pid1 = fork();
	if (pid1 < 0)
		return (cleanup_pipe(pipefd, 0, 0));
	if (pid1 == 0)
		setup_child1(pipefd, ms, expr);
	pid2 = fork();
	if (pid2 < 0)
	{
		waitpid(pid1, NULL, 0);
		return (cleanup_pipe(pipefd, 0, 0));
	}
	if (pid2 == 0)
		setup_child2(pipefd, ms, expr);
	close(pipefd[PIPE_READ_END]);
	close(pipefd[PIPE_WRITE_END]);
	return (wait_for_child(pid1, pid2));
}
