/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:00 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/17 15:00:16 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	handle_cmd_not_found(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (127);
}

static int	handle_fork_error(char *cmd_path, char **envp)
{
	perror("fork");
	free(cmd_path);
	ft_free_strs(envp);
	return (1);
}

static void	child_process(t_minishell *ms, char *cmd_path, char **args,
		char **envp)
{
	execve(cmd_path, args, envp);
	ft_free_strs(args);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args[0], 2);
	perror(": ");
	free(cmd_path);
	ft_free_strs(envp);
	ms->status = 126;
	mini_exit(NULL, ms);
}

static int	parent_process(pid_t pid, char *cmd_path, char **envp)
{
	int	status;

	waitpid(pid, &status, 0);
	free(cmd_path);
	ft_free_strs(envp);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

int	execute_ext(char **args, t_minishell *ms)
{
	char	*cmd_path;
	char	**envp;
	pid_t	pid;
	int		result;

	cmd_path = find_cmd_path(args[0], ms->env);
	if (!cmd_path)
		return (handle_cmd_not_found(args[0]));
	envp = env_to_array(ms->env);
	if (!envp)
		return (free(cmd_path), 1);
	g_in_exec = 1;
	pid = fork();
	if (pid == -1)
		return (handle_fork_error(cmd_path, envp));
	if (pid == 0)
	{
		sigmode_kill();
		child_process(ms, cmd_path, args, envp);
	}
	result = parent_process(pid, cmd_path, envp);
	g_in_exec = 0;
	return (result);
}
