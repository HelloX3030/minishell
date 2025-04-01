/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:58:32 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/01 14:27:52 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get_env_value(t_env *env, const char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

static int	count_env_vars(t_env *env)
{
	int		count;
	t_env	*tmp;

	count = 0;
	tmp = env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static void	free_env_array(char **envp, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(envp[i++]);
	free(envp);
}

static char	*create_env_string(char *key, char *value)
{
	int		size;
	char	*env_str;

	size = ft_strlen(key) + ft_strlen(value) + 2;
	env_str = malloc(size);
	if (!env_str)
		return (NULL);
	ft_strlcpy(env_str, key, size);
	ft_strlcat(env_str, "=", size);
	ft_strlcat(env_str, value, size);
	return (env_str);
}

char	**env_to_array(t_env *env)
{
	int		size;
	char	**envp;
	int		i;
	char	*env_str;

	size = count_env_vars(env);
	envp = malloc((size + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	while (env)
	{
		env_str = create_env_string(env->key, env->value);
		if (!env_str)
		{
			free_env_array(envp, i);
			return (NULL);
		}
		envp[i++] = env_str;
		env = env->next;
	}
	envp[i] = NULL;
	return (envp);
}
