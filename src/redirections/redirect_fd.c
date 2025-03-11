/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:43:23 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 13:25:37 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	redirect_fd(t_list *files, int *fds, int flags, int target_fd)
{
	// int	i;
	// i = 0;
	// while (files)
	// {
	// 	fds[i] = open(files->content, flags, DEFAULT_FILE_PERMISSIONS);
	// 	if (fds[i] == -1)
	// 		return (close_fds(fds, i), EXIT_FAILURE);
	// 	if (dup2(fds[i], target_fd) == -1)
	// 		return (close_fds(fds, i + 1), EXIT_FAILURE);
	// 	i++;
	// 	files = files->next;
	// }
	(void)files;
	(void)fds;
	(void)flags;
	(void)target_fd;
	return (EXIT_SUCCESS);
}
