/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:40 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/24 10:00:11 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

bool	is_cmd(char *args, t_env *env)
{
	char	*is_ext;
	int		is_built;

	is_ext = find_cmd_path(args, env);
	is_built = is_builtin(args);
	if (is_ext)
		free(is_ext);
	if (is_built || is_ext)
		return (SUCCESS);
	return (FAILURE);
}
