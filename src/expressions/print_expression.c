/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 15:28:47 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_redirs(t_expression *expr, int insertion)
{
	t_list	*tmp;

	if (expr->redirs)
	{
		ft_write_insertion(insertion);
		ft_putstr("Redirs:\n");
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
	t_list	*tmp;

	if (expr->args)
	{
		ft_write_insertion(insertion);
		ft_putstr("Args:\n");
		tmp = expr->args;
		while (tmp)
		{
			ft_write_insertion(insertion + 1);
			ft_putstr("<");
			ft_putstr(tmp->content);
			ft_putstr(">\n");
			tmp = tmp->next;
		}
	}
	print_redirs(expr, insertion);
}

static void	print_helper(t_expression *expr, int insertion)
{
	if (expr)
	{
		ft_write_insertion(insertion);
		ft_putstr("Expression:\n");
		ft_write_insertion(insertion + 1);
		ft_putstr("type: ");
		print_expression_type(expr->type);
		ft_putstr("\n");
		print_cmd_values(expr, insertion + 1);
		if (expr->child)
			printf("Childs:\n");
		print_helper(expr->child, insertion + 2);
		if (expr->next)
		{
			printf("Child:\n");
			print_helper(expr->next, insertion);
		}
	}
}

void	print_expression(t_expression *expr)
{
	ft_putstr("Expressions:\n");
	print_helper(expr, 1);
}
