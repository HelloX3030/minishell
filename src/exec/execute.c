/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/28 12:44:08 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	execute(char **args, t_env *env)
{
	//if (ft_strcmp(args[0], "minishell") == 0)
	//	exec_shell(args, env);
	if (args && ft_strcmp(args[0], "exit") == 0)
		return;
	if (args && is_builtin(args[0]))
		dispatch_builtin(args, &env);
	else if (args && args[0])
		execute_ext(args, env);
}
