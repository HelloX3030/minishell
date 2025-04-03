/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:05:35 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/03 16:39:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_expression_type(t_expression_type type)
{
	if (type == EXPR_CMD)
		printf("EXPR_CMD");
	else if (type == EXPR_AND)
		printf("EXPR_AND");
	else if (type == EXPR_OR)
		printf("EXPR_OR");
	else if (type == EXPR_PIPE)
		printf("EXPR_PIPE");
	else if (type == EXPR_END)
		printf("EXPR_END");
	else if (type == EXPR_SYNTAX_ERROR)
		printf("EXPR_SYNTAX_ERROR");
	else if (type == EXPR_UNCLOSED_GROUP)
		printf("EXPR_UNCLOSED_GROUP");
	else if (type == EXPR_UNCLOSED_AND)
		printf("EXPR_UNCLOSED_AND");
	else if (type == EXPR_UNCLOSED_OR)
		printf("EXPR_UNCLOSED_OR");
	else if (type == EXPR_UNCLOSED_PIPE)
		printf("EXPR_UNCLOSED_PIPE");
	else
		printf("EXPR_UNKNOWN");
}
