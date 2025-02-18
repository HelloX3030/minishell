/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:58:32 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/18 15:06:10 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get_env_value(t_env *env, const char *key)
{
	while(env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	set_env_val(t_env **env, char *key, char *value)
{
	t_env	*cur;
	t_env	*new_node;

	cur = *env;
	while(cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			free(cur->value);
			cur->value = ft_strdup(value);
			return ;
		}
	}
	new_node = create_env_node(key, value);
	new_node->next = *env;
	*env = new_node;
}

void	unset_env_val(t_env **env, const char *key)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env;
	prev = NULL;

	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*env = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

char	**env_to_array(t_env *env)
{
	int		size;
	t_env	*tmp;
	char	**envp;
	int		i;

	tmp = env;
	size = 0;
	while(tmp)
	{
		size ++;
		tmp = tmp->next;
	}
	envp = malloc((size + 1) * sizeof(char*));
	if (!envp)
		return (NULL);
	i = 0;
	while (env)
	{
		size = ft_strlen(env->key) + ft_strlen(env->value) + 2;
		envp[i] = malloc (size);
		if (!envp[i])
		{
			while(i > 0)
				free(envp[--i]);
			free(envp);
			return (NULL);
		}
		ft_strlcpy(envp[i], env->key, size);
		ft_strlcat(envp[i], "=", size);
		ft_strlcat(envp[i], env->value, size);
		env = env->next;
		i ++;
	}
	envp[i] = NULL;
	return (envp);
}
