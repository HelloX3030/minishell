/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:03:25 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/01 15:41:33 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

//static void	print_redirs(t_expression *expr, int insertion)
//{
//	t_list	*tmp;

//	if (expr->redirs)
//	{
//		ft_printf_insertion(insertion);
//		printf("Redirs:\n");
//		tmp = expr->redirs;
//		while (tmp)
//		{
//			print_redir((t_redir *)tmp->content, insertion);
//			tmp = tmp->next;
//		}
//	}
//}

//static void	print_cmd_values(t_expression *expr, int insertion)
//{
//	t_list	*tmp;

//	if (expr->args)
//	{
//		ft_printf_insertion(insertion);
//		printf("Args:\n");
//		tmp = expr->args;
//		while (tmp)
//		{
//			ft_printf_insertion(insertion + 1);
//			printf("%s\n", (char *)tmp->content);
//			tmp = tmp->next;
//		}
//	}
//	print_redirs(expr, insertion);
//}

//static void	print_helper(t_expression *expr, int insertion)
//{
//	if (expr)
//	{
//		ft_printf_insertion(insertion);
//		printf("Expression:\n");
//		ft_printf_insertion(insertion + 1);
//		printf("type: ");
//		print_expression_type(expr->type);
//		printf("\n");
//		print_cmd_values(expr, insertion + 1);
//		if (expr->child)
//		{
//			ft_printf_insertion(insertion + 1);
//			print_helper(expr->child, insertion + 2);
//		}
//		if (expr->next)
//			print_helper(expr->next, insertion);
//	}
//}

//void	print_expression(t_expression *expr, int insertion)
//{
//	ft_printf_insertion(insertion);
//	printf("Expressions:\n");
//	print_helper(expr, insertion + 1);
//}
