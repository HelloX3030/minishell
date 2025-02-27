/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:40 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/27 15:16:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static char	*is_external(const char *cmd, t_env *env)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;
	DIR		*dir_check;
	int		j;

	// Handle empty command
	if (!cmd || !cmd[0])
		return (NULL);
	// Handle commands with path (relative or absolute paths)
	if (ft_strchr(cmd, '/'))
	{
		// Check if path exists and is accessible
		if (access(cmd, F_OK) == 0)
		{
			// Check if it's not a directory
			dir_check = opendir(cmd);
			if (dir_check)
			{
				// It's a directory, not a command
				closedir(dir_check);
				return (NULL);
			}
			// Check if it's executable
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
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		// Check if file exists
		if (access(full_path, F_OK) == 0)
		{
			// Check if it's not a directory
			dir_check = opendir(full_path);
			if (dir_check)
			{
				// It's a directory, not a command
				closedir(dir_check);
				free(full_path);
				i++;
				continue ;
			}
			// Check if it's executable
			if (access(full_path, X_OK) == 0)
			{
				// Clean up the paths array before returning
				j = 0;
				while (paths[j])
					free(paths[j++]);
				free(paths);
				return (full_path);
			}
		}
		free(full_path);
		i++;
	}
	// Clean up
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
