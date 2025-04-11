/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:57:50 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/11 16:39:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_env	*get_next(t_env *env, t_env *cur)
{
	t_env	*min;

	min = NULL;
	while (env)
	{
		if (ft_strcmp(env->key, cur->key) > 0)
		{
			if (!min || ft_strcmp(env->key, min->key) < 0)
				min = env;
		}
		env = env->next;
	}
	return (min);
}

static void	print_export_vars(t_env *env)
{
	t_env	*cur;

	cur = env;
	while (env)
	{
		if (ft_strcmp(env->key, cur->key) < 0)
			cur = env;
		env = env->next;
	}
	while (cur)
	{
		printf("declare -x %s=\"%s\"\n", cur->key, cur->value);
		cur = get_next(env, cur);
	}
}

static int	export_with_equals(char *arg, t_env **env)
{
	char	*equals;
	char	*key;
	char	*value;
	int		key_len;
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i++]))
			return (ft_putstr_fd("not a valid identifier\n", 2), EXIT_FAILURE);
	}
	equals = ft_strchr(arg, '=');
	key_len = equals - arg;
	key = (char *)malloc(key_len + 1);
	if (!key)
		return (EXIT_FAILURE);
	ft_strlcpy(key, arg, key_len + 1);
	value = ft_strdup(equals + 1);
	if (!value)
		return (EXIT_FAILURE);
	set_env_val(env, key, value);
	free(key);
	return (EXIT_SUCCESS);
}

static int	export_without_equals(char *arg, t_env **env)
{
	char	*value;
	int		i;

	i = 0;
	value = get_env_value(*env, arg);
	while (arg[i])
	{
		if (!ft_isalpha(arg[i]))
			return (ft_putstr_fd("not a valid identifier\n", 2), EXIT_FAILURE);
		i++;
	}
	if (!value)
		set_env_val(env, arg, ft_strdup(""));
	return (EXIT_SUCCESS);
}

int	mini_export(char **args, t_minishell *ms)
{
	int	i;
	int	result;

	if (!args[1])
	{
		print_export_vars(ms->env);
		return (EXIT_SUCCESS);
	}
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			if (args[i][0] == '=')
				return (ft_putstr_fd("not a valid identifier\n", 2),
					EXIT_FAILURE);
			result = export_with_equals(args[i], &ms->env);
		}
		else
			result = export_without_equals(args[i], &ms->env);
		i++;
	}
	return (result);
}
