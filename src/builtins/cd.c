/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/16 13:53:03 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	change_directory(char *path, char *current_path, t_env **env)
{
	int		ret;
	char	new_path[PATH_MAX];
	char	*n_path;

	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		free(current_path);
		return (EXIT_FAILURE);
	}
	if (getcwd(new_path, PATH_MAX))
	{
		set_env_val(env, "OLDPWD", current_path);
		n_path = ft_strdup(new_path);
		set_env_val(env, "PWD", n_path);
	}
	else
	{
		free(current_path);
	}
	return (EXIT_SUCCESS);
}

static int	handle_home_path(t_env **env, char *current_path)
{
	char	*path;

	path = get_env_value(*env, "HOME");
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		free(current_path);
		return (EXIT_FAILURE);
	}
	return (change_directory(path, current_path, env));
}

static int	handle_old_path(t_env **env, char *current_path)
{
	char	*path;

	path = get_env_value(*env, "OLDPWD");
	if (!path)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		free(current_path);
		return (EXIT_FAILURE);
	}
	printf("%s\n", path);
	return (change_directory(path, current_path, env));
}

int	to_path(int fl, t_env **env)
{
	char		current_path[PATH_MAX];
	char		*cur_path;
	int			result;

	if (!getcwd(current_path, PATH_MAX))
	{
		ft_putstr_fd("minishell: cd: error retrieving current directory\n", 2);
		return (EXIT_FAILURE);
	}
	cur_path = ft_strdup(current_path);
	if (!cur_path)
		return (EXIT_FAILURE);
	if (fl == 0)
		result = handle_home_path(env, cur_path);
	else
		result = handle_old_path(env, cur_path);
	return (result);
}

int	mini_cd(char **args, t_minishell *ms)
{
	char	current_path[PATH_MAX];
	char	new_path[PATH_MAX];
	char	*cur_path;
	char	*n_path;

	if (!args || !args[1])
		return (to_path(0, &ms->env));
	if (ft_strcmp(args[1], "-") == 0)
		return (to_path(1, &ms->env));
	if (getcwd(current_path, PATH_MAX))
	{
		cur_path = ft_strdup(current_path);
		if (cur_path)
			set_env_val(&ms->env, "OLDPWD", cur_path);
	}
	if (chdir(args[1]) != 0)
		return (cd_error(args[1]), EXIT_FAILURE);
	if (getcwd(new_path, PATH_MAX))
	{
		n_path = ft_strdup(new_path);
		if (n_path)
			set_env_val(&ms->env, "PWD", n_path);
	}
	return (EXIT_SUCCESS);
}
