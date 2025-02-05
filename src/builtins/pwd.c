/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:32:18 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/05 13:39:55 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void	mini_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd, PATH_MAX != NULL)
	{
		ft_putendl_fd(cwd, 1);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}