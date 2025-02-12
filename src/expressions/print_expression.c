/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/12 14:31:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_helper(t_expression *expr, int insertion);

static void	print_childs(t_expression *expr, int insertion)
{
	char	*insertion_str;
	int		i;

	insertion_str = ft_get_insertion(insertion);
	i = 0;
	if (expr->childs)
		printf("%sChilds:\n", insertion_str);
	while (expr->childs + i)
	{
		print_helper(expr->childs + i, insertion + 1);
		i++;
	}
	free(insertion_str);
}

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
		print_childs(expr, insertion + 1);
		if (expr->next)
		{
			print_helper(expr->next, insertion);
		}
	}
	free(insertion_str);
	free(more_insertion);
}

void	print_expression(t_expression *expr, int insertion)
{
	char	*insertion_str;

	insertion_str = ft_get_insertion(insertion);
	printf("%sExpressions:\n", insertion_str);
	print_helper(expr, insertion);
	free(insertion_str);
}
