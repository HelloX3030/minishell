/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:46:32 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/18 15:56:18 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_expression	*parse_group(t_token *token, t_token *end)
{
	t_expression	*expr;

	expr = create_expression(EXPR_GROUP);
	// expr->str = ft_strdup(token->str);
	end = get_closing_group(token);
	if (end)
	{
		expr->child = parse_expression(token->next, end);
		if (end->next)
			expr->next = parse_expression(end->next, NULL);
	}
	else
		expr->next = parse_expression(token->next, NULL);
	return (expr);
}

static t_expression	*get_next_expression(t_expression *expr,
		t_token *next_token, t_token *end)
{
	t_expression	*next_expr;

	if (next_token->type == TOKEN_OPERATOR)
	{
		if (ft_strcmp(next_token->str, "&&") == 0)
			expr->type = EXPR_AND;
		else if (ft_strcmp(next_token->str, "||") == 0)
			expr->type = EXPR_OR;
		else
			return (NULL);
		next_expr = parse_expression(next_token->next, end);
	}
	else
		next_expr = parse_expression(next_token, end);
	return (next_expr);
}

/*
	- when there is a next token, it must be an operator
		=> if it is not, return NULL to indicate an error
	- when there is an operator,
		after the operator there must be a word or a group
		=> if there is not, return NULL to indicate an error
*/
static t_expression	*parse_cmd(t_token *token, t_token *end)
{
	t_expression	*expr;
	t_expression	*next_expr;

	expr = create_expression(EXPR_CMD);
	// expr->str = ft_strdup(token->str);
	if (token->next)
	{
		if (end && token->next == end)
			return (expr);
		next_expr = get_next_expression(expr, token->next, end);
		if (!next_expr)
			return (free_expression(expr), NULL);
		expr->next = next_expr;
	}
	return (expr);
}

/*
	- Operators are invalid at this point
		=> when encountering one, just return NULL to indicate an error
	- terminate parsing when encountering end
		=> end holds the closing token of the group
*/
t_expression	*parse_expression(t_token *token, t_token *end)
{
	if (!token)
		return (NULL);
	else if (token->type == TOKEN_WORD)
		return (parse_cmd(token, end));
	else if (token->type == TOKEN_GROUP)
		return (parse_group(token, end));
	else
		return (NULL);
}
