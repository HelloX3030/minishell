/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:32:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 18:42:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	reset_redirect(t_expression *expr)
{
	// int	return_value;
	// return_value = EXIT_SUCCESS;
	// if (expr->saved_stdout != -1)
	// {
	// 	if (dup2(expr->saved_stdout, STDOUT_FILENO) == -1)
	// 		return_value = EXIT_FAILURE;
	// 	if (close(expr->saved_stdout) == -1)
	// 		return_value = EXIT_FAILURE;
	// 	expr->saved_stdout = -1;
	// }
	// if (reset_input_redirect(expr) == EXIT_FAILURE)
	// 	return_value = EXIT_FAILURE;
	// if (reset_output_redirect(expr) == EXIT_FAILURE)
	// 	return_value = EXIT_FAILURE;
	// if (reset_append_redirect(expr) == EXIT_FAILURE)
	// 	return_value = EXIT_FAILURE;
	// return (return_value);
	(void)expr;
	return (EXIT_SUCCESS);
}
