/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:00 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/12 12:46:30 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static char *try_path(const char *dir, const char *cmd)
{
	char *tmp;
	char *full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	
	if (!full_path)
		return (NULL);
	
	if (access(full_path, X_OK) != 0)
	{
		free(full_path);
		return (NULL);
	}
	
	return (full_path);
}

static char *search_in_paths(char **paths, const char *cmd)
{
	int i;
	char *result;

	i = 0;
	while (paths[i])
	{
		result = try_path(paths[i], cmd);
		if (result)
		{
			free_paths(paths);
			return (result);
		}
		i++;
	}
	
	free_paths(paths);
	return (NULL);
}

char *find_cmd_path(const char *cmd, t_env *env)
{
	char *path_env;
	char **paths;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	
	path_env = get_env_value(env, "PATH");
	if (!path_env)
		return (NULL);
	
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	
	return (search_in_paths(paths, cmd));
}

static int handle_cmd_not_found(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (127);
}

static int handle_fork_error(char *cmd_path, char **envp)
{
	perror("fork");
	free(cmd_path);
	free_array(envp);
	return (1);
}

static void child_process(char *cmd_path, char **args, char **envp)
{
	execve(cmd_path, args, envp);
	
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(args[0], 2);
	perror(": ");
	
	free(cmd_path);
	free_array(envp);
	exit(126);
}

static int parent_process(pid_t pid, char *cmd_path, char **envp)
{
	int status;
	
	waitpid(pid, &status, 0);
	free(cmd_path);
	free_array(envp);
	
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	
	return (1);
}

int execute_ext(char **args, t_minishell *ms)
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
	{
		free(cmd_path);
		return (1);
	}
	g_in_exec = 1;
	pid = fork();
	if (pid == -1)
		return (handle_fork_error(cmd_path, envp));
	if (pid == 0)
	{
		setup_execution();
		child_process(cmd_path, args, envp);
	}
	result = parent_process(pid, cmd_path, envp);
	g_in_exec = 0;
	return (result);
}
