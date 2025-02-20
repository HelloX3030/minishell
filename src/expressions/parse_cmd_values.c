/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:51:33 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/20 14:01:09 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static inline bool	next_is_valid(t_token *token, t_token *end, t_env *env)
{
	return (token->next && (!end || token->next != end)
		&& (token->next->type == TOKEN_WORD
			&& !is_cmd(token->next->str, env)));
}

static t_token	*add_lst(t_list **lst, t_token *token, t_token *end,
		char *compare)
{
	t_list	*new_element;
	char	*str;

	if (!compare || ft_strcmp(token->str, compare) == 0)
	{
		token = token->next;
		if (token && (!end || token != end) && token->type == TOKEN_WORD
			&& !is_redirection_operator(token->str))
		{
			str = ft_strdup(token->str);
			new_element = ft_lstnew(str);
			ft_lstadd_back(lst, new_element);
			return (token);
		}
		else
			return (NULL);
	}
	return (token);
}

/*
	- returns the last processed token
	- when no token is processed,
		returns the token that was passed as an argument
	- when an error occurs, returns NULL
*/
t_token	*parse_cmd_values(t_expression *expr, t_token *token, t_token *end, t_env *env)
{
	while (next_is_valid(token, end, env))
	{
		token = token->next;
		token = add_lst(&expr->infiles, token, end, "<");
		if (!token)
			return (NULL);
		token = add_lst(&expr->outfiles, token, end, ">");
		if (!token)
			return (NULL);
		token = add_lst(&expr->append, token, end, ">>");
		if (!token)
			return (NULL);
	}
	return (token);
}
