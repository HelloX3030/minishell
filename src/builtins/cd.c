/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/10 10:21:38 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int change_directory(char *path, char *current_path, t_env **env)
{
	int ret;
	char new_path[PATH_MAX];
	
	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (EXIT_FAILURE);
	}
	
	if (getcwd(new_path, PATH_MAX))
	{
		set_env_val(env, "OLDPWD", current_path);
		set_env_val(env, "PWD", new_path);
	}
	return (EXIT_SUCCESS);
}

static int handle_home_path(t_env **env, char *current_path)
{
	char *path;
	
	path = get_env_value(*env, "HOME");
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (EXIT_FAILURE);
	}
	return (change_directory(path, current_path, env));
}

static int handle_old_path(t_env **env, char *current_path, char *old_path)
{
	char *path;
	
	if (!old_path[0])
	{
		path = get_env_value(*env, "OLDPWD");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	else
		path = old_path;
	
	ft_putendl_fd(path, 1);
	return (change_directory(path, current_path, env));
}

int to_path(int fl, t_env **env)
{
	char current_path[PATH_MAX];
	static char old_path[PATH_MAX] = {0};
	int result;
	
	if (!getcwd(current_path, PATH_MAX))
	{
		ft_putstr_fd("minishell: cd: error retrieving current directory\n", 2);
		return (EXIT_FAILURE);
	}
	char temp_path[PATH_MAX];
	ft_strlcpy(temp_path, current_path, PATH_MAX);
	
	if (fl == 0)
		result = handle_home_path(env, current_path);
	else
		result = handle_old_path(env, current_path, old_path);
	if (result == EXIT_SUCCESS)
		ft_strlcpy(old_path, temp_path, PATH_MAX);
	
	return (result);
}

int mini_cd(char **args, t_env **env)
{
	if (!args || !args[1])
		return (to_path(0, env));
	if (ft_strcmp(args[1], "-") == 0)
		return (to_path(1, env));
	char current_path[PATH_MAX];
	if (getcwd(current_path, PATH_MAX))
		set_env_val(env, "OLDPWD", current_path);
	int cd = chdir(args[1]);
	if (cd != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (EXIT_FAILURE);
	}
	char new_path[PATH_MAX];
	if (getcwd(new_path, PATH_MAX))
		set_env_val(env, "PWD", new_path);

	return (EXIT_SUCCESS);
}
