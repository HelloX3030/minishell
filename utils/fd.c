/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:31:15 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/04 14:35:09 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/include.h"

void	fd_close(int fd)
{
	if (fd > 0)
		close (fd);
}

void	close_fds(t_command cmd)
{
	fd_close(cmd->fdin);
	fd_close(cmd->fdout);
	fd_close(cmd->inpipe);
	fd_close(cmd->outpipe);
}