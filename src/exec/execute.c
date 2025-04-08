/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:26 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/08 16:16:17 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	execute(char **args, t_minishell *ms)
{
	if (!args)
		return ;
	if (ft_strcmp(args[0], "") == 0)
		return ;
	if (is_builtin(args[0]) == 0)
		dispatch_builtin(args, ms);
	else if (args[0])
		ms->status = execute_ext(args, ms);
}
