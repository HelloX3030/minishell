/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:20:38 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/11 17:14:13 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	calculate_exit(int *exit_code, char *args[])
{
	*exit_code = ft_atoi(args[1]);
	*exit_code = *exit_code % 256;
}

static void	handle_no_numeric_argument(t_minishell *ms, char **args)
{
	ft_putstr_fd("exit: numeric argument required\n", 2);
	ms->status = 255;
	ft_free_strs(args);
	exit(ms->status);
}

int	mini_exit(char **args, t_minishell *ms)
{
	int	exit_code;

	exit_code = 0;
	if (args)
	{
		if (args[1] != NULL)
		{
			if (!ft_atoi(args[1]) || ft_strlen(args[1]) == 0)
				handle_no_numeric_argument(ms, args);
			if (args[2])
			{
				ft_putstr_fd("exit: too many arguments\n", 2);
				return (ms->status = 1, 1);
			}
			else
				calculate_exit(&exit_code, args);
		}
		ms->status = exit_code;
	}
	ft_free_strs(args);
	free_minishell(ms);
	exit(ms->status);
}
