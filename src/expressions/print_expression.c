/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/18 15:55:57 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_strs(char **strs, char *insertion_str)
{
	int	i;

	i = -1;
	while (strs[++i])
		printf("%s%s\n", insertion_str, strs[i]);
}

static void	print_cmd_values(t_expression *expr, char *more_insertion)
{
	if (expr->cmd)
		printf("%sCommand: %s\n", more_insertion, expr->cmd);
	if (expr->args)
	{
		printf("%sArguments:\n", more_insertion);
		print_strs(expr->args, more_insertion);
	}
	if (expr->infile)
	{
		printf("%sInfile:\n", more_insertion);
		print_strs(expr->infile, more_insertion);
	}
	if (expr->outfile)
	{
		printf("%sOutfile:\n", more_insertion);
		print_strs(expr->outfile, more_insertion);
	}
	if (expr->append)
	{
		printf("%sAppend:\n", more_insertion);
		print_strs(expr->append, more_insertion);
	}
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
		print_cmd_values(expr, more_insertion);
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
