/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:57:50 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/26 14:33:06 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	mini_export(char **args, t_env **env)
{
	int		i;
	int		key_len;
	char	*equals;
	char	*key;
	char	*value;
	t_env	*cur;

	if (!args[1])
	{
		cur = *env;
		while (cur)
		{
			ft_printf("declare -x %s=\"%s\"\n", cur->key, cur->value);
			cur = cur->next;
		}
		return (EXIT_SUCCESS);
	}
	i = 1;
	while(args[i])
	{
		equals = ft_strchr(args[i], '=');
		if (equals)
		{
			key_len = equals - args[i];
			key = (char*)malloc(key_len + 1);
			if (!key)
				return (EXIT_FAILURE);
			ft_strlcpy(key, args[i], key_len + 1);
			value = ft_strdup(equals + 1);
			set_env_val(env, key, value);
			free(key);
			free(value);
		}
		else
		{
			value = get_env_value(*env, args[i]);
			if (!value)
				set_env_val(env, args[i], "");
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
