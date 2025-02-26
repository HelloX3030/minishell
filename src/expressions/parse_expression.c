/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:46:32 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/25 16:10:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_expression	*get_next_expression(t_expression *expr,
		t_token *next_token, t_token *end, t_env *env)
{
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
		return (parse_expression(next_token->next, end, env));
	}
	else
		return (parse_expression(next_token, end, env));
}

static t_expression	*parse_group(t_token *token, t_token *end, t_env *env)
{
	t_expression	*expr;
	char			*str;

	end = get_closing_group(token);
	if (!end)
		return (create_expression(EXPR_SYNTAX_ERROR));
	expr = create_expression(EXPR_CMD);
	if (!expr)
		return (NULL);
	str = ft_strdup(token->str);
	if (!str)
		return (free_expression(expr), NULL);
	expr->args = ft_lstnew(str);
	if (!expr->args)
		return (free_expression(expr), NULL);
	expr->child = parse_expression(token->next, end, env);
	if (!expr->child)
		return (free_expression(expr), NULL);
	if (expression_has_syntax_error(expr->child))
		return (expr);
	expr->next = get_next_expression(expr, end->next, NULL, env);
	if (!expr->next)
		return (free_expression(expr), NULL);
	return (expr);
}

/*
	- when there is an operator,
		after the operator there must be a word or a group
		=> if there is not, return NULL to indicate an error
*/
static t_expression	*parse_cmd(t_token *token, t_token *end, t_env *env)
{
	t_expression	*expr;
	char			*str;

	expr = create_expression(EXPR_CMD);
	if (!expr)
		return (NULL);
	str = ft_strdup(token->str);
	if (!str)
		return (free_expression(expr), NULL);
	expr->args = ft_lstnew(str);
	if (!expr->args || !token->next)
		return (free_expression(expr), NULL);
	token = parse_cmd_values(expr, token, end, env);
	if (!token)
		return (free_expression(expr), NULL);
	if (expr->type == EXPR_SYNTAX_ERROR)
		return (expr);
	expr->next = get_next_expression(expr, token->next, end, env);
	if (!expr->next)
		return (free_expression(expr), NULL);
	return (expr);
}

/*
	- Operators are invalid at this point
		=> when encountering one, just return NULL to indicate an error
	- terminate parsing when encountering end
		=> end holds the closing token of the group
*/
t_expression	*parse_expression(t_token *token, t_token *end, t_env *env)
{
	if (!token)
		return (NULL);
	if (end && token == end)
		return (create_expression(EXPR_END));
	else if (token->type == TOKEN_WORD)
	{
		if (!is_cmd(token->str, env))
			return (create_expression(EXPR_SYNTAX_ERROR));
		else
			return (parse_cmd(token, end, env));
	}
	else if (token->type == TOKEN_GROUP)
		return (parse_group(token, end, env));
	else if (token->type == TOKEN_END)
		return (create_expression(EXPR_END));
	else
		return (create_expression(EXPR_SYNTAX_ERROR));
}
