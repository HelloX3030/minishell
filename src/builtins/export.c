/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:57:50 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/10 10:23:43 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void print_export_vars(t_env *env)
{
	t_env *cur;

	cur = env;
	while (cur)
	{
		ft_printf("declare -x %s=\"%s\"\n", cur->key, cur->value);
		cur = cur->next;
	}
}

static int export_with_equals(char *arg, t_env **env)
{
	char *equals;
	char *key;
	char *value;
	int key_len;

	equals = ft_strchr(arg, '=');
	key_len = equals - arg;
	key = (char*)malloc(key_len + 1);
	if (!key)
		return (EXIT_FAILURE);
	
	ft_strlcpy(key, arg, key_len + 1);
	value = ft_strdup(equals + 1);
	set_env_val(env, key, value);
	free(key);
	free(value);
	
	return (EXIT_SUCCESS);
}

static int export_without_equals(char *arg, t_env **env)
{
	char *value;

	value = get_env_value(*env, arg);
	if (!value)
		set_env_val(env, arg, "");
	
	return (EXIT_SUCCESS);
}

int mini_export(char **args, t_env **env)
{
	int i;
	int result;

	if (!args[1])
	{
		print_export_vars(*env);
		return (EXIT_SUCCESS);
	}
	
	i = 1;
	result = EXIT_SUCCESS;
	while (args[i] && result == EXIT_SUCCESS)
	{
		if (ft_strchr(args[i], '='))
			result = export_with_equals(args[i], env);
		else
			result = export_without_equals(args[i], env);
		i++;
	}
	
	return (result);
}
