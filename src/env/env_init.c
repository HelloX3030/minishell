/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:29:18 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/07 13:03:47 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

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

t_env	*init_env(char **envp)
{
	t_env	*env_list;
	char	*key;
	char	*value;
	char	*equals;
	int		i;
	int		key_len;

	env_list = NULL;
	i = 0;
	while(envp[i])
	{
		equals = ft_strchr(envp[i], '=');
		if (equals)
		{
			key_len = equals - envp[i];
			key = (char *)malloc(key_len + 1);
			ft_strlcpy(key, envp[i], key_len);
			value = ft_strdup(equals + 1);
			t_env *new_node = create_env_node(key, value);
			if (new_node)
				add_env_node(&env_list, new_node);
			free(key);
			free(value);
		}
		i ++;
	}
	return (env_list);
}

