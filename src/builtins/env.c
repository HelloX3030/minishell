/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:20 by leokubler         #+#    #+#             */
/*   Updated: 2025/03/10 15:03:59 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	mini_env(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		ft_printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}
