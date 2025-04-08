/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:09:30 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/08 13:57:42 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	make_redir(int target_fd, char *file, int flags)
{
	int	new_fd;

	new_fd = open(file, flags, DEFAULT_FILE_PERMISSIONS);
	if (new_fd == -1)
	{
		if (errno == ENOENT)
			write(STDERR_FILENO, "No such file or directory\n", 26);
		else if (errno == EACCES)
			write(STDERR_FILENO, "Permission denied\n", 18);
		else
		{
			write(STDERR_FILENO, "Error opening file: ", 20);
			write(STDERR_FILENO, strerror(errno), strlen(strerror(errno)));
			write(STDERR_FILENO, "\n", 1);
		}
		return (EXIT_FAILURE);
	}
	if (dup2(new_fd, target_fd) == -1)
		return (EXIT_FAILURE);
	if (close(new_fd) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
