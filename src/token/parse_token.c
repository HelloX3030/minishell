/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:57 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/05 15:00:05 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_token	*get_token(char **str_pos)
{
	char	*str;
	char	*next;
	t_token	*token;

	str = *str_pos;
	while (*str == ' ')
		str++;
	if (!*str)
		return (NULL);
	next = str;
	while (*next && !ft_strchr(" ", *next))
		next++;
	token = create_token();
	token->str = ft_strdupn(str, next);
	if (*next)
		*str_pos = next + 1;
	else
		*str_pos = next;
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
