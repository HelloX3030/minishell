/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:49:21 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/07 11:10:50 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	count_args(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	mini_echo(char **args)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	if (count_args(args) >= 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			i++;
			n_flag = 1;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i][0] != '\0' && args[i + 1])
				write(1, " ", 1);
			i++;
		}
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
