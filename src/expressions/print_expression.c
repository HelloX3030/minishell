/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:59:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_redirs(t_expression *expr, char *insertion_str, int insertion)
{
	t_list	*tmp;

	if (expr->redirs)
	{
		printf("%sRedirs:\n", insertion_str);
		tmp = expr->redirs;
		while (tmp)
		{
			print_redir((t_redir *)tmp->content, insertion);
			tmp = tmp->next;
		}
	}
}

static void	print_cmd_values(t_expression *expr, int insertion)
{
	char	*insertion_str;
	char	*more_insertion_str;
	t_list	*tmp;

	insertion_str = ft_get_insertion(insertion);
	more_insertion_str = ft_get_insertion(insertion + 1);
	if (expr->args)
	{
		printf("%sArgs:\n", insertion_str);
		tmp = expr->args;
		while (tmp)
		{
			printf("%s%s\n", more_insertion_str, (char *)tmp->content);
			tmp = tmp->next;
		}
	}
	print_redirs(expr, insertion_str, insertion + 1);
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
