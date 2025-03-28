/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:57:50 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/28 13:16:08 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_export_vars(t_env *env)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		ft_printf("declare -x %s=\"%s\"\n", cur->key, cur->value);
		cur = cur->next;
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
			return (ft_putendl_fd("not a valid identifier", 2), EXIT_FAILURE);
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
	free(value);
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
			return (ft_putendl_fd("not a valid identifier", 2), EXIT_FAILURE);
		i++;
	}
	if (!value)
		set_env_val(env, arg, "");
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
				return (ft_putendl_fd("not a valid identifier", 2),
					EXIT_FAILURE);
			result = export_with_equals(args[i], &ms->env);
		}
		else
			result = export_without_equals(args[i], &ms->env);
		i++;
	}
	return (result);
}
