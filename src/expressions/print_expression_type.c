/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:05:35 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/11 14:24:56 by lseeger          ###   ########.fr       */
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
	else if (type == EXPR_GROUP)
		printf("EXPR_GROUP");
	else
		printf("EXPR_UNKNOWN");
}
