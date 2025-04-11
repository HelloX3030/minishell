/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:49:21 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/11 17:12:21 by lseeger          ###   ########.fr       */
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

static bool	has_n_flag(char *str)
{
	if (!str)
		return (true);
	if (*str != '-')
		return (false);
	str++;
	if (*str != 'n')
		return (false);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (false);
		str++;
	}
	return (true);
}

int	mini_echo(char **args)
{
	int		i;
	bool	n_flag;

	i = 1;
	n_flag = false;
	while (i < count_args(args) && has_n_flag(args[i]))
	{
		n_flag = true;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i][0] != '\0' && args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
