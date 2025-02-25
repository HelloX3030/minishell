/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:58 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/25 08:33:07 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "cd") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "env") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "export") == 0)
		return (SUCCESS);
	if (ft_strcmp(cmd, "unset") == 0)
		return (SUCCESS);
	return (FAILURE);
}

int	dispatch_builtin(char **args, t_env **env)
{
	int	result;

	result = 0;
	(void)result;
	if (ft_strcmp(args[0], "echo") == 0)
		result = mini_echo(args);
	if (ft_strcmp(args[0], "cd") == 0)
		result = mini_cd(args, env);
	if (ft_strcmp(args[0], "pwd") == 0)
		mini_pwd();
	if (ft_strcmp(args[0], "env") == 0)
		mini_env(*env);
	if (ft_strcmp(args[0], "export") == 0)
		mini_export(args, env);
	if (ft_strcmp(args[0], "unset") == 0)
		mini_unset(args, env);
	return (1);
}
