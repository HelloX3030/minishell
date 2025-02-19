/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:51:33 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/18 17:23:11 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_token	*get_end(t_token *token, t_token *end)
{
	while ((token->next && (!end || token->next != end)
			&& (token->next->type == TOKEN_WORD
				&& !is_cmd_placeholder(token->next))))
		token = token->next;
	return (token);
}

static int	count_values(t_token *token, t_token *end, char *key)
{
	int	count;

	count = 0;
	while (token && token != end)
	{
		if (ft_strcmp(token->str, key) == 0)
			count++;
		token = token->next;
	}
}

/*
	- returns the last processed token
	- when no token is processed,
		returns the token that was passed as an argument
	- when an error occurs, returns NULL
*/
t_token	*parse_cmd_values(t_expression *expr, t_token *token, t_token *end)
{
	end = get_end(token, end);
	return (end);
}
