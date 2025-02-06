/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:05:35 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/06 14:40:52 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_expression_type(t_expression_type type)
{
	if (type == EXPR_NONE)
		printf("EXPR_NONE");
	else if (type == EXPR_AND)
		printf("EXPR_AND");
	else if (type == EXPR_OR)
		printf("EXPR_OR");
	else if (type == EXPR_GROUP)
		printf("EXPR_GROUP");
	else
		printf("EXPR_UNKNOWN");
}
