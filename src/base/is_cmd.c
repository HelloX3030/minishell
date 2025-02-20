/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:40 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/20 14:57:59 by lseeger          ###   ########.fr       */
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
		return (1);
	return (0);
}
