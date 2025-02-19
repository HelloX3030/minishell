/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 14:31:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_lst(char *name, t_list *lst, char *insertion_str,
		char *more_insertion_str)
{
	if (lst)
	{
		printf("%s%s:\n", insertion_str, name);
		while (lst)
		{
			printf("%s%s\n", more_insertion_str, (char *)lst->content);
			lst = lst->next;
		}
	}
}

static void	print_cmd_values(t_expression *expr, int insertion)
{
	char	*insertion_str;
	char	*more_insertion_str;

	insertion_str = ft_get_insertion(insertion);
	more_insertion_str = ft_get_insertion(insertion + 1);
	print_lst("args", expr->args, insertion_str, more_insertion_str);
	print_lst("infiles", expr->infiles, insertion_str, more_insertion_str);
	print_lst("outfiles", expr->outfiles, insertion_str, more_insertion_str);
	print_lst("append", expr->append, insertion_str, more_insertion_str);
	free(insertion_str);
	free(more_insertion_str);
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
		printf("%stype: ", more_insertion);
		print_expression_type(expr->type);
		printf("\n");
		print_cmd_values(expr, insertion + 1);
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
