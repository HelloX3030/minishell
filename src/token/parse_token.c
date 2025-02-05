/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:57 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/05 17:18:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static char	*get_token_end(char *end)
{
	char	*end_quote;

	while (*end)
	{
		if (*end == ' ' || *end == '\t' || *end == '(' || *end == ')')
			break ;
		if (*end == '"')
		{
			end_quote = ft_strchr(end + 1, '"');
			if (end_quote)
				return (end_quote + 1);
		}
		if (*end == '\'')
		{
			end_quote = ft_strchr(end + 1, '\'');
			if (end_quote)
				return (end_quote + 1);
		}
		if (!ft_strncmp(end, "&&", 2) || !ft_strncmp(end, "||", 2))
			return (end);
		end++;
	}
	return (end);
}

static t_token	*get_direct_token(char **str_pos, char *str)
{
	t_token	*token;

	if (!ft_strncmp(str, "&&", 2) || !ft_strncmp(str, "||", 2))
	{
		token = create_token(TOKEN_OPERATOR, ft_strdupn(str, str + 2));
		if (!token)
			return (NULL);
		*str_pos = str + 2;
		return (token);
	}
	if (*str == '(' || *str == ')')
	{
		token = create_token(TOKEN_GROUP, ft_strdupn(str, str + 1));
		if (!token)
			return (NULL);
		*str_pos = str + 1;
		return (token);
	}
	return (NULL);
}

static t_token	*get_token(char **str_pos)
{
	char	*str;
	char	*end;
	t_token	*token;

	str = *str_pos;
	while (*str == ' ' || *str == '\t')
		str++;
	if (!*str)
		return (NULL);
	token = get_direct_token(str_pos, str);
	if (token)
		return (token);
	end = get_token_end(str);
	token = create_token(TOKEN_WORD, ft_strdupn(str, end));
	if (!token)
		return (NULL);
	*str_pos = end;
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
