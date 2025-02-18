/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:42:00 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/18 14:15:00 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

static char	*find_cmd_path(const char *cmd, t_env *env)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = get_env_value(env, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(full_path, X_OK) == 0)
		{
			while (paths[i])
				free(paths[i++]);
			free (paths);
			return (full_path);
		}
		free(full_path);
		i ++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

static void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	execute_ext(t_command *cmd, t_env *env)
{
	char	*cmd_path;
	char	 **envp;
	pid_t	pid;
	int		status;

	cmd_path = find_cmd_path(cmd->args[0], env);
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	envp = env_to_array(env);
	if (!envp)
	{
		free(cmd_path);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		free_array(envp);
		return (1);
	}
	if (pid == 0)
	{
		execve(cmd_path, cmd->args, envp);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		perror(": ");
		free(cmd_path);
		free_array(envp);
		exit(126);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd_path);
		free_array(envp);
		if (WIFEXITED(status))
			return (WIFEXITED(status));
		else if (WIFSIGNALED(status))
			return (128 + WTERMSIG(status));
		return (1);
	}
}
