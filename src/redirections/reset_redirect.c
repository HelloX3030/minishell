/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 13:29:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	reset_redirect(t_expression *expr)
{
	int	return_value;

	return_value = restore_fd(&expr->saved_stdin, STDIN_FILENO);
	if (restore_fd(&expr->saved_stdout, STDOUT_FILENO) == EXIT_FAILURE)
		return_value = EXIT_FAILURE;
	return (return_value);
}
