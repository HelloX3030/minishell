/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:49:19 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/17 16:23:19 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_command	*parse_command(t_expression *expr, t_expression *end)
{
	t_command	*cmd;

	cmd = create_command(expr->str);
	(void)expr;
	(void)end;
	// parsing logic
	return (cmd);
}
