/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leokubler <leokubler@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:35:10 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/06 12:43:28 by leokubler        ###   ########.fr       */
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