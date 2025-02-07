/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/07 13:20:21 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

static int	to_path(int fl, t_command *args)
{
	
}

static int	path_history(char *prev_path)
{
	static char	old_path[PATH_MAX];
	char	current_path[PATH_MAX];

	if (!prev_path)
		return (EXIT_FAILURE);
	if (!getcwd(current_path, sizeof(current_path)))
		return (EXIT_FAILURE);
	if (old_path[0] != '\0')
		*prev_path = ft_strdup(old_path);
	else
		*prev_path = NULL;
	ft_strlcpy(old_path, current_path, PATH_MAX - 1);
	old_path[PATH_MAX - 1] = '\0';
}

int	mini_cd(t_command *command, t_env *env)
{
	int	cd;

	if (!command->args)
		to_path(0, env);
	if (ft_strcmp(command->args[0], "-") == 0)
		cd = to_path(1, env);
	else
	{
		path_history(command->args[1]);
		cd = chdir(command->args[1]);
		if (cd < 0)
			cd *= -1;
		if (cd != 0)
			return (EXIT_FAILURE);
	}
	return(cd);
}