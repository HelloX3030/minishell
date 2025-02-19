/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:40 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/19 14:04:25 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"


bool	is_cmd_ext(t_command *cmd, t_env *env)
{
	char *is_ext;
	char *is_built;

	is_ext = find_cmd_path(cmd->cmd, env);
	is_built = is_builtin(cmd->cmd);
	if (!is_ext || !is_built)
		return (0);
	return (1);
}