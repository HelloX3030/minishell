/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:26:27 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/11 16:36:15 by lkubler          ###   ########.fr       */
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

void	set_env_val(t_env **env, char *key, char *value)
{
	t_env	*cur;
	t_env	*new_node;
	char    *key_copy;

	if (!env || !key || !value)
	{
		if (value)
			free(value);
		return ;
	}
	
	cur = *env;
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			free(cur->value);
			cur->value = value;  // Take ownership of value
			return ;
		}
		cur = cur->next;
	}
	
	// Need to make a copy of key since we don't own it
	key_copy = ft_strdup(key);
	if (!key_copy)
	{
		free(value);
		return ;
	}
	
	new_node = create_env_node(key_copy, value);
	if (!new_node)
	{
		free(key_copy);
		free(value);
		return ;
	}
	
	// create_env_node makes its own copies, so free our copies
	free(key_copy);
	free(value);
	
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
