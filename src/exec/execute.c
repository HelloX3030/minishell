/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/20 11:28:39 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	execute(t_command *command, t_env *env)
{
	int		i;

	i = 0;
	if (command && ft_strcmp(command->cmd, "exit") == 0)
		return ;
		//mini_exit();
	if (command && is_builtin(command->cmd))
		dispatch_builtin(command, &env);
	else if (command && command->cmd)
		execute_ext(command, env);
}
