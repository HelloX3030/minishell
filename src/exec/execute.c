/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/18 14:59:10 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	execute(t_command *command, t_env *env)
{
	int		i;

	i = 0;
	if (command && strcmp(command->cmd, "exit") == 0)
		mini_exit();
	if (command && is_builtin(command->cmd))
		dsipatch_builtin(command, env);
	else if (command && command->cmd)
		execute_ext(command, env);
}
