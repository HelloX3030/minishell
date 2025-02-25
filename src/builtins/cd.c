/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/21 13:11:07 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int to_path(int fl, t_env **env)
{
	char *path;
	char current_path[PATH_MAX];
	static char old_path[PATH_MAX] = {0};
	int ret;
	
	if (!getcwd(current_path, PATH_MAX))
	{
		ft_putstr_fd("minishell: cd: error retrieving current directory\n", 2);
		return (EXIT_FAILURE);
	}
	if (fl == 0)
	{
		path = get_env_value(*env, "HOME");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (EXIT_FAILURE);
		}
	}
	else
	{
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
	}
	ft_strlcpy(old_path, current_path, PATH_MAX);
	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (EXIT_FAILURE);
	}
	char new_path[PATH_MAX];
	if (getcwd(new_path, PATH_MAX))
	{
		set_env_val(env, "OLDPWD", current_path);
		set_env_val(env, "PWD", new_path);
	}
	return (EXIT_SUCCESS);
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