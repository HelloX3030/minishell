/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:51:33 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/26 14:29:05 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_token	*add_lst(t_expression *expr, t_list **lst, t_token *token,
		t_token *end)
{
	char	*str;
	t_list	*new_element;

	if (!token || token->type != TOKEN_WORD || (end && token == end)
		|| is_redirection_operator(token->str))
	{
		expr->type = EXPR_SYNTAX_ERROR;
		return (token);
	}
	str = ft_strdup(token->str);
	if (!str)
		return (NULL);
	new_element = ft_lstnew(str);
	if (!new_element)
	{
		free(str);
		return (NULL);
	}
	ft_lstadd_back(lst, new_element);
	return (token);
}

static t_token	*add_args(t_expression *expr, t_token *token)
{
	char	*str;
	t_list	*new_element;

	str = ft_strdup(token->str);
	if (!str)
		return (NULL);
	new_element = ft_lstnew(str);
	if (!new_element)
	{
		free(str);
		return (NULL);
	}
	ft_lstadd_back(&expr->args, new_element);
	return (token);
}

/*
	- returns the last processed token
	- when no token is processed,
		returns the token that was passed as an argument
	- when an error occurs, returns NULL
	- when an an syntax error occurs,
		edits the current expression to represent the error
*/
t_token	*parse_cmd_values(t_expression *expr, t_token *token, t_token *end)
{
	while (token->next && (!end || token->next != end)
		&& (token->next->type == TOKEN_WORD))
	{
		token = token->next;
		if (ft_strcmp(token->str, "<") == 0)
			token = add_lst(expr, &expr->infiles, token->next, end);
		else if (ft_strcmp(token->str, ">") == 0)
			token = add_lst(expr, &expr->outfiles, token->next, end);
		else if (ft_strcmp(token->str, ">>") == 0)
			token = add_lst(expr, &expr->append, token->next, end);
		else
			token = add_args(expr, token);
		if (!token)
			return (NULL);
		if (expr->type == EXPR_SYNTAX_ERROR)
			return (token);
	}
	return (token);
}
