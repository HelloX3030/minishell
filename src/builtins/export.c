/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:57:50 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/18 14:58:55 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	mini_export(char **args, t_env **env)
{
	int		i;
	int		len;
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
		return (0);
	}
	i = 1;
	while(args[i])
	{
		equals = ft_strchr(args[i], '=');
		if (equals)
		{
			len = ft_strlen(equals) - ft_strlen(args[i]);
			key = (char*)malloc(len + 1);
			if (!key)
				return (1);
			ft_strlcpy(key, args[i], (len + 1));
			value = equals + 1;
			set_env_val(env, key, value);
			free (key);
		}
		else
		{
			value = get_env_value(*env, args[i]);
			if (!value)
				set_env_val(env, args[i], "");
		}
	i ++;
	}
	return (0);
}
