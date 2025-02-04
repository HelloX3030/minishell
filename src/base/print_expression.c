/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 13:50:07 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_childs(t_expression *expr, int insertion)
{
	const char	*insertion_str = ft_get_insertion(insertion);
	int			i;

	i = 0;
	if (expr->childs)
		printf("%sChilds:\n", insertion_str);
	while (expr->childs + i)
	{
		print_expression(expr->childs + i, insertion + 1);
		i++;
	}
	free(insertion_str);
}

void	print_expression(t_expression *expr, int insertion)
{
	const char	*insertion_str = ft_get_insertion(insertion);

	if (expr)
	{
		printf("%sExpression:\n", insertion_str);
		if (expr->str)
			printf("%sstr: %s\n", insertion_str, expr->str);
		printf("%stype: ", insertion_str);
		print_expression_type(expr->type);
		printf("\n");
		print_childs(expr, insertion + 1);
		if (expr->next)
		{
			printf("%sNext:\n", insertion_str);
			print_expression(expr->next, insertion + 1);
		}
	}
	free(insertion_str);
}
