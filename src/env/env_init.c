/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:29:18 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/10 10:25:54 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_env	*create_env_node(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	return (new_node);
}

void	add_env_node(t_env **head, t_env *new_node)
{
	t_env	*cur;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_node;
}

static t_env *process_env_var(char *env_var, t_env *env_list)
{
	char *equals;
	char *key;
	char *value;
	int key_len;
	t_env *new_node;

	equals = ft_strchr(env_var, '=');
	if (!equals)
		return (env_list);
	
	key_len = equals - env_var;
	key = (char *)malloc(key_len + 1);
	if (!key)
		return (env_list);
	ft_strlcpy(key, env_var, key_len + 1);
	key[key_len] = '\0';
	value = ft_strdup(equals + 1);
	new_node = create_env_node(key, value);
	if (new_node)
		add_env_node(&env_list, new_node);
	free(key);
	free(value);
	return (env_list);
}

t_env *init_env(char **envp)
{
	t_env *env_list;
	int i;

	env_list = NULL;
	i = 0;
	while (envp[i])
	{
		env_list = process_env_var(envp[i], env_list);
		i++;
	}
	return (env_list);
}