/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:05:35 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 12:49:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_expression_type(t_expression_type type)
{
	if (type == EXPR_CMD)
		ft_putstr("EXPR_CMD");
	else if (type == EXPR_AND)
		ft_putstr("EXPR_AND");
	else if (type == EXPR_OR)
		ft_putstr("EXPR_OR");
	else if (type == EXPR_PIPE)
		ft_putstr("EXPR_PIPE");
	else if (type == EXPR_END)
		ft_putstr("EXPR_END");
	else if (type == EXPR_SYNTAX_ERROR)
		ft_putstr("EXPR_SYNTAX_ERROR");
	else if (type == EXPR_UNCLOSED_GROUP)
		ft_putstr("EXPR_UNCLOSED_GROUP");
	else if (type == EXPR_UNCLOSED_AND)
		ft_putstr("EXPR_UNCLOSED_AND");
	else if (type == EXPR_UNCLOSED_OR)
		ft_putstr("EXPR_UNCLOSED_OR");
	else if (type == EXPR_UNCLOSED_PIPE)
		ft_putstr("EXPR_UNCLOSED_PIPE");
	else
		ft_putstr("EXPR_UNKNOWN");
}
