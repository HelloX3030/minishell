/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/05 14:51:58 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

static int	to_path(int fl, t_command *args)
{
	
}

static int	path_history(t_command *args)
{
	
}
mini_cd(char **args, t_command *env)
{
	int	cd;

	if (!args[1])
		to_path(0, env);
	if (ft_strcmp(args[1], "-") == 0)
		cd = to_path(1, env);
	else
	{
		path_history(args[1]);
		cd = chdir(args[1]);
		if (cd < 0)
			cd *= -1;
		if (cd != 0)
			return (EXIT_FAILURE);
	}
	return(cd);
}