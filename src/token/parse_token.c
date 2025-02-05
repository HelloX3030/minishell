/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:57 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/05 14:19:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_token	*get_token(char **str)
{
	char	*next;
	t_token	*token;

	next = ft_strchr(*str, ' ');
	if (!next)
		return (NULL);
	token = create_token();
	token->str = ft_strdupn(*str, next);
	*str = next + 1;
	return (token);
}

t_token	*parse_token(char *str)
{
	t_token	*token_start;
	t_token	*token;

	token_start = get_token(&str);
	if (!token_start)
		return (NULL);
	token = token_start;
	while (token)
	{
		token->next = get_token(&str);
		token = token->next;
	}
	return (token_start);
}
