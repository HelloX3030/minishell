/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/07 13:22:08 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void	execute(t_command *command)
{
	int		i;

	i = 0;
	if (command && strcmp(command->cmd, "exit") == 0)
		mini_exit();
	if (command && is_builtin(command->cmd))
		dsipatch_builtin(command);
	else if (command && command->cmd)
		external();
}
