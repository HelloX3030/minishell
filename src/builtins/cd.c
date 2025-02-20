/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/19 12:11:37 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int to_path(int fl, t_env *env)
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
		path = get_env_value(env, "HOME");
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
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (EXIT_FAILURE);
		}
		path = old_path;
		ft_putendl_fd(path, 1);
	}
	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (EXIT_FAILURE);
	}
	ft_strlcpy(old_path, current_path, PATH_MAX);
	char new_path[PATH_MAX];
	if (getcwd(new_path, PATH_MAX))
	{
		set_env_val(&env, "OLDPWD", current_path);
		set_env_val(&env, "PWD", new_path);
	}
	return (EXIT_SUCCESS);
}

static int	path_history(char *prev_path)
{
	char	old_path[PATH_MAX];
	char	current_path[PATH_MAX];

	if (!prev_path)
		return (EXIT_FAILURE);
	if (!getcwd(current_path, sizeof(current_path)))
		return (EXIT_FAILURE);
	if (old_path[0] != '\0')
		prev_path = ft_strdup(old_path);
	else
		prev_path = NULL;
	ft_strlcpy(old_path, current_path, PATH_MAX - 1);
	old_path[PATH_MAX - 1] = '\0';
	return (EXIT_SUCCESS);
}

int	mini_cd(t_command *command, t_env *env)
{
	int	cd;

	cd = 0;
	if (!command->args)
		to_path(0, env);
	if (ft_strcmp(command->args[0], "-") == 0)
		cd = to_path(1, env);
	else
	{
		path_history(command->args[1]);
		cd = chdir(command->args[1]);
		if (cd < 0)
			cd *= -1;
		if (cd != 0)
			return (EXIT_FAILURE);
	}
	return(cd);
}
