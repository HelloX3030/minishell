/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:07:17 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 13:09:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	restore_fd(int *saved_fd, int fd)
{
	int	return_value;

	return_value = EXIT_SUCCESS;
	if (*saved_fd != -1)
	{
		if (dup2(*saved_fd, fd) == -1)
			return_value = EXIT_FAILURE;
		if (close(*saved_fd) == -1)
			return_value = EXIT_FAILURE;
		*saved_fd = -1;
	}
	return (return_value);
}
