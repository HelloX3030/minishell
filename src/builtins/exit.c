/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:20:38 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/13 11:10:18 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"


static void	calculate_exit(int *exit_code, char *args[])
{
	*exit_code = ft_atoi(args[1]);
	*exit_code = *exit_code % 256;
}

int	mini_exit(char **args, t_minishell *ms)
{
	int	exit_code;

	exit_code = 0;
	if (args[1] != NULL)
	{
		if (!ft_atoi(args[1]) || ft_strlen(args[1]) == 0)
		{
			ft_putendl_fd("exit", 2);
			ft_putendl_fd("exit: numeric argument required", 2);
			ms->status = 255;
			exit(ms->status);
		}
		if (args[2])
		{
			ft_putendl_fd("exit", 2);
			ft_putendl_fd("exit: too many arguments", 2);
			return (1);
		}
		else
			calculate_exit(&exit_code, args);
	}
	ms->status = exit_code;
	free_minishell(ms);
	ms->stop_execution = true;
	exit(ms->status);
}
