/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:58 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/11 10:46:59 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "exit") == 0)
		return (SUCCESS);
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
	if (ft_strcmp(cmd, "minishell") == 0)
		return (SUCCESS);
	return (FAILURE);
}

int	dispatch_builtin(char **args, t_minishell *ms)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ms->status = mini_echo(args);
	if (ft_strcmp(args[0], "cd") == 0)
		ms->status = mini_cd(args, ms);
	if (ft_strcmp(args[0], "pwd") == 0)
		ms->status = mini_pwd();
	if (ft_strcmp(args[0], "env") == 0)
		ms->status = mini_env(ms);
	if (ft_strcmp(args[0], "export") == 0)
		ms->status = mini_export(args, ms);
	if (ft_strcmp(args[0], "unset") == 0)
		ms->status = mini_unset(args, ms);
	if (ft_strcmp(args[0], "minishell") == 0)
		ms->status = exec_shell(args, ms);
	return (1);
}
