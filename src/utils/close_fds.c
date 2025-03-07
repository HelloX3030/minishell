/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:12:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/07 16:13:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	close_fds(int *fds, int count)
{
	int	i;
	int	return_value;

	return_value = EXIT_SUCCESS;
	i = 0;
	while (i < count)
	{
		if (close(fds[i]) == -1)
			return_value = EXIT_FAILURE;
		i++;
	}
	return (return_value);
}
