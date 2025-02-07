/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:20 by leokubler         #+#    #+#             */
/*   Updated: 2025/02/07 13:21:26 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void print_env(t_env *env_list)
{
	t_env *current;

	current = env_list;
	while (current)
	{
		ft_printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}
