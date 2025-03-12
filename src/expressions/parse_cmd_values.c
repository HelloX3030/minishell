/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:51:33 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:48:10 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_token	*add_redir(t_expression *expr, t_redir_type type,
		t_token *token, t_token *end)
{
	t_list	*new_element;
	t_redir	*redir;

	if (!token || token->type != TOKEN_WORD || (end && token == end)
		|| is_redirection_operator(token->str))
	{
		expr->type = EXPR_SYNTAX_ERROR;
		return (token);
	}
	redir = create_redir(type, token->str);
	if (!redir)
		return (NULL);
	new_element = ft_lstnew(redir);
	if (!new_element)
	{
		free_redir(redir);
		return (NULL);
	}
	ft_lstadd_back(&expr->redirs, new_element);
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
			token = add_redir(expr, REDIR_IN, token->next, end);
		else if (ft_strcmp(token->str, ">") == 0)
			token = add_redir(expr, REDIR_OUT, token->next, end);
		else if (ft_strcmp(token->str, ">>") == 0)
			token = add_redir(expr, REDIR_APPEND, token->next, end);
		else
			token = add_args(expr, token);
		if (!token)
			return (NULL);
		if (expr->type == EXPR_SYNTAX_ERROR)
			return (token);
	}
	return (token);
}
