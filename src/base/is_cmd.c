/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:40 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/11 13:32:57 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	free_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}
static char	*is_external(const char *cmd, t_env *env)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;
	DIR		*dir_check;

	if (!cmd || !cmd[0])
		return (NULL);
	// Handle commands with path
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
		{
			dir_check = opendir(cmd);
			if (dir_check)
			{
				closedir(dir_check);
				return (NULL);
			}
			if (access(cmd, X_OK) == 0)
				return (ft_strdup(cmd));
		}
		return (NULL);
	}
	// Look for command in PATH
	path_env = get_env_value(env, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		// Create full path
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
		{
			free_paths(paths);
			return (NULL);
		}
		full_path = ft_strjoin(tmp, cmd);
		free(tmp); // Free tmp immediately after use
		if (!full_path)
		{
			// Free paths array if full_path allocation fails
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (NULL);
		}
		// Check if file exists and is executable
		if (access(full_path, F_OK) == 0)
		{
			dir_check = opendir(full_path);
			if (dir_check)
			{
				closedir(dir_check);
				free(full_path);
			}
			else if (access(full_path, X_OK) == 0)
			{
				// Success: clean up paths and return full_path
				while (paths[i])
					free(paths[i++]);
				free(paths);
				return (full_path);
			}
			else
				free(full_path);
		}
		else
			free(full_path);
		i++;
	}
	// Clean up if no executable found
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (NULL);
}

bool	is_cmd(char *args, t_env *env)
{
	char	*cmd_path;
	int		is_built;

	if (!args || !args[0])
		return (FAILURE);
	is_built = is_builtin(args);
	if (is_built)
		return (SUCCESS);
	cmd_path = is_external(args, env);
	if (cmd_path)
	{
		free(cmd_path);
		return (SUCCESS);
	}
	return (FAILURE);
}
