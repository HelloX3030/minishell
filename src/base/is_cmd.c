/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:40 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/03 13:45:46 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static char	*check_direct_path(const char *cmd)
{
	if (!cmd || !cmd[0] || !ft_strchr(cmd, '/'))
		return (NULL);
	if (access(cmd, F_OK) != 0)
		return (NULL);
	if (is_directory(cmd))
		return (NULL);
	if (access(cmd, X_OK) != 0)
		return (NULL);
	return (ft_strdup(cmd));
}

static char	*try_path(const char *dir, const char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!full_path)
	{
		free(full_path);
		return (NULL);
	}
	if (access(full_path, F_OK) != 0 || is_directory(full_path)
		|| access(full_path, X_OK) != 0)
	{
		free(full_path);
		return (NULL);
	}
	return (full_path);
}

static char	*search_in_path(const char *cmd, char **paths)
{
	int		i;
	char	*result;

	i = 0;
	while (paths[i])
	{
		result = try_path(paths[i], cmd);
		if (result)
		{
			ft_free_strs(paths);
			return (result);
		}
		i++;
	}
	ft_free_strs(paths);
	return (NULL);
}

static char	*is_external(const char *cmd, t_env *env)
{
	char	*path_env;
	char	**paths;
	char	*result;

	result = check_direct_path(cmd);
	if (result || !cmd || !cmd[0])
		return (result);
	path_env = get_env_value(env, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
	{
		free(paths);
		return (NULL);
	}
	return (search_in_path(cmd, paths));
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
