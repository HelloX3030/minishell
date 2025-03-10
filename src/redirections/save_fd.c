/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:07:46 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 19:08:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	save_fd(int *saved_fd, int fd)
{
	if (*saved_fd == -1)
	{
		*saved_fd = dup(fd);
		if (*saved_fd == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
