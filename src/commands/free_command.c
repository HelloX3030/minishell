/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:51:58 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/17 15:34:34 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_command(t_command *cmd)
{
	int	i;

	if (cmd)
		free(cmd->cmd);
	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
	if (cmd->infile)
		free(cmd->infile);
	if (cmd->outfile)
		free(cmd->outfile);
	free(cmd);
}
