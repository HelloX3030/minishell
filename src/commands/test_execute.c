/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:48:41 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/17 15:53:53 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	test_execute(t_expression *expr)
{
	t_command		*cmd;
	t_expression	*end;

	end = get_expression_end(expr);
	if (!end)
		return ;
	cmd = parse_command(expr, end);
}
