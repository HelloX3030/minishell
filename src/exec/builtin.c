/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:58 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/19 10:41:43 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
}

int	dispatch_builtin(t_command *command, t_env **env)
{
	int	result;

	result = 0;
	if (ft_strcmp(command->cmd, "echo") == 0)
		result = mini_echo(&command->cmd);
	if (ft_strcmp(command->cmd, "cd") == 0)
		result = mini_cd(command, *env);
	if (ft_strcmp(command->cmd, "pwd") == 0)
		mini_pwd();
	if (ft_strcmp(command->cmd, "env") == 0)
		mini_env(*env);
	if (ft_strcmp(command->cmd, "export") == 0)
		mini_export(command->args, env);
	if (ft_strcmp(command->cmd, "unset") == 0)
		mini_unset(command->args, env);
	return (1);
}
