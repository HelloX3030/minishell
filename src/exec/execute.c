/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/20 13:46:13 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	execute(char **args, t_env *env)
{
	int		i;

	i = 0;
	if (args && ft_strcmp(args[0], "exit") == 0)
		return ;
		//mini_exit();
	if (args && is_builtin(args[0]))
		dispatch_builtin(args, &env);
	else if (args && args[0])
		execute_ext(args, env);
}
