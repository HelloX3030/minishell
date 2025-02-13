/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/13 14:33:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_helper(t_expression *expr, int insertion)
{
	char	*insertion_str;
	char	*more_insertion;

	insertion_str = ft_get_insertion(insertion);
	more_insertion = ft_get_insertion(insertion + 1);
	if (expr)
	{
		printf("%sExpression:\n", insertion_str);
		if (expr->str)
			printf("%sstr: %s\n", more_insertion, expr->str);
		printf("%stype: ", more_insertion);
		print_expression_type(expr->type);
		printf("\n");
		if (expr->child)
		{
			printf("%sChild:\n", more_insertion);
			print_helper(expr->child, insertion + 2);
		}
		if (expr->next)
			print_helper(expr->next, insertion);
	}
	free(insertion_str);
	free(more_insertion);
}

void	print_expression(t_expression *expr, int insertion)
{
	char	*insertion_str;

	insertion_str = ft_get_insertion(insertion);
	printf("%sExpressions:\n", insertion_str);
	print_helper(expr, insertion + 1);
	free(insertion_str);
}
