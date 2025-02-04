/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:49:19 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 12:50:59 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_command	*parse_command(char *str)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = ft_split(str, ' ');
	if (!cmd->args)
	{
		free(cmd);
		return (NULL);
	}
	// parsing logic
	return (cmd);
}
