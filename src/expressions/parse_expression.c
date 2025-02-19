/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:46:32 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 16:03:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_expression	*parse_group(t_token *token, t_token *end)
{
	t_expression	*expr;
	char			*str;

	end = get_closing_group(token);
	if (!end)
		return (NULL);
	expr = create_expression(EXPR_GROUP);
	str = ft_strdup(token->str);
	expr->args = ft_lstnew(str);
	if (token->next != end)
		expr->child = parse_expression(token->next, end);
	if (end->next)
	{
		expr->next = parse_expression(end->next, NULL);
		if (!expr->next)
			return (free_expression(expr), NULL);
	}
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
		else if (ft_strcmp(next_token->str, "|") == 0)
			expr->type = EXPR_PIPE;
		else
			return (NULL);
		next_expr = parse_expression(next_token->next, end);
	}
	else
		next_expr = parse_expression(next_token, end);
	return (next_expr);
}

/*
	- when there is an operator,
		after the operator there must be a word or a group
		=> if there is not, return NULL to indicate an error
*/
static t_expression	*parse_cmd(t_token *token, t_token *end)
{
	t_expression	*expr;
	char			*str;

	expr = create_expression(EXPR_CMD);
	str = ft_strdup(token->str);
	expr->args = ft_lstnew(str);
	if (token->next)
	{
		if (end && token->next == end)
			return (expr);
		token = parse_cmd_values(expr, token, end);
		if (!token)
			return (free_expression(expr), NULL);
		if (!token->next)
			return (expr);
		expr->next = get_next_expression(expr, token->next, end);
		if (!expr->next)
			return (free_expression(expr), NULL);
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
	{
		if (!is_cmd_placeholder(token->str))
			return (NULL);
		else
			return (parse_cmd(token, end));
	}
	else if (token->type == TOKEN_GROUP)
		return (parse_group(token, end));
	else
		return (NULL);
}
