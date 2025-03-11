/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/11 10:26:33 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	execute(char **args, t_env *env)
{
	//if (ft_strcmp(args[0], "minishell") == 0)
	//	exec_shell(args, env);
	if (args && is_builtin(args[0]))
		dispatch_builtin(args, &env);
	else if (args && args[0])
		execute_ext(args, env);
	// for testing exectue expressions
	if (ft_strcmp(args[0], "ls"))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
