/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:20 by leokubler         #+#    #+#             */
/*   Updated: 2025/04/08 16:49:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	mini_env(t_minishell *ms)
{
	t_env	*current;

	current = ms->env;
	while (current)
	{
		if (printf("%s=%s\n", current->key, current->value) < 0)
		{
			perror("env");
			return (EXIT_FAILURE);
		}
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
