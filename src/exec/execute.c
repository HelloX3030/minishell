/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/19 14:01:10 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	execute(char **args, t_minishell *ms)
{
	//if (ft_strcmp(args[0], "minishell") == 0)
	//	exec_shell(args, env);
	if (args && is_builtin(args[0]))
		dispatch_builtin(args, ms);
	else if (args && args[0])
		ms->status = execute_ext(args, ms);
}
