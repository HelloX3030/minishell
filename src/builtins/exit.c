/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:20:38 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/11 13:26:12 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	*status(void)
{
	static int	status = 0;

	return (&status);
}

static void	calculate_exit(int *exit_code, char *args[])
{
	*exit_code = ft_atoi(args[1]);
	*exit_code = *exit_code % 256;
	*status() = *exit_code;
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
			*status() = 255;
			exit(*status());
		}
		if (args[2])
		{
			ft_putendl_fd("exit", 2);
			ft_putendl_fd("exit: too many arguments", 2);
			return (*status() = 1, 1);
		}
		else
			calculate_exit(&exit_code, args);
	}
	exit_code = *status();
	free_minishell(ms);
	// ms->stop_execution = true;
	exit(exit_code);
}
