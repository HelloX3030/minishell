/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:46:32 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/11 15:20:19 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_expression	*parse_group(t_token *token)
{
	t_expression	*expr;

	expr = create_expression(EXPR_GROUP);
	expr->str = ft_strdup(token->str);
	return (expr);
}

/*
	- when there is a next token, it must be an operator
		=> if it is not, return NULL to indicate an error
	- when there is an operator,
		after the operator there must be a word or a group
		=> if there is not, return NULL to indicate an error
*/
static t_expression	*parse_cmd(t_token *token)
{
	t_expression	*expr;
	t_expression	*next_expr;

	expr = create_expression(EXPR_CMD);
	if (token->next)
	{
		if (token->next->type == TOKEN_WORD || token->next->type == TOKEN_GROUP
			|| !token->next->next)
			return (free_expression(expr), NULL);
		else if (ft_strcmp(token->next->str, "&&") == 0)
			expr->type = EXPR_AND;
		else if (ft_strcmp(token->next->str, "||") == 0)
			expr->type = EXPR_OR;
		next_expr = parse_expression(token->next->next);
		if (!next_expr)
			return (free_expression(expr), NULL);
		expr->next = next_expr;
		expr->str = ft_strdup(token->str);
		return (expr);
	}
	else
		return (expr->str = ft_strdup(token->str), expr);
}

/*
	- Operators are invalid at this point
		=> when encountering one, just return NULL to indicate an error
*/
t_expression	*parse_expression(t_token *token)
{
	if (!token)
		return (NULL);
	else if (token->type == TOKEN_WORD)
		return (parse_cmd(token));
	else if (token->type == TOKEN_GROUP)
		return (parse_group(token));
	else
		return (NULL);
}
