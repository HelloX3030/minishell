/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leokubler <leokubler@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:20 by leokubler         #+#    #+#             */
/*   Updated: 2025/02/06 12:57:32 by leokubler        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

int mini_env(t_env *env)
{
    while (env && env->next != NULL)
    {
		ft_putendl_fd(env->str, 1);
		env = env->next;
    }
	if (env)
		ft_putendl_fd(env->str, 1);
	return (EXIT_SUCCESS);
}