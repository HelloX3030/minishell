/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/05 13:08:45 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void	execute(t_command *cmd, t_token *token)
{
	char	**cmd;
	int		i;

	cmd = fill_cmd(token);
	i = 0;
	if (cmd && strcmp(cmd[0], "exit") == 0)
		mini_exit();
	if (cmd && is_builtin(cmd[0]))
		dsipatch_builtin();
	else if (cmd)
		external();
}