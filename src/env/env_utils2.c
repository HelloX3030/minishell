/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:26:27 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/16 13:51:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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

static bool	replace_value(t_env *env, char *key, char *value)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			free(env->value);
			env->value = value;
			return (true);
		}
		env = env->next;
	}
	return (false);
}

void	set_env_val(t_env **env, char *key, char *value)
{
	t_env	*new_node;
	char	*key_copy;

	if (!env || !key || !value)
	{
		free(value);
		return ;
	}
	if (replace_value(*env, key, value))
		return ;
	key_copy = ft_strdup(key);
	if (!key_copy)
	{
		free(value);
		return ;
	}
	new_node = create_env_node(key_copy, value);
	free(key_copy);
	free(value);
	if (!new_node)
		return ;
	add_env_node(env, new_node);
}

void	free_env(t_env *env)
{
	t_env	*current;
	t_env	*next;

	current = env;
	while (current)
	{
		next = current->next;
		if (current->key)
			free(current->key);
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
}

t_env	*init_essentials(void)
{
	t_env	*env_list;
	t_env	*new_node;
	char	cwd[PATH_MAX];

	env_list = NULL;
	if (getcwd(cwd, PATH_MAX))
	{
		new_node = create_env_node("PWD", cwd);
		if (new_node)
			add_env_node(&env_list, new_node);
	}
	new_node = create_env_node("SHLVL", "1");
	if (new_node)
		add_env_node(&env_list, new_node);
	return (env_list);
}
