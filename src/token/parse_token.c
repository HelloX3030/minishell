/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:57 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 16:37:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static bool	is_token_limiter(char c)
{
	return (c == ' ' || c == '\t' || c == '(' || c == ')' || c == '<'
		|| c == '>');
}

static char	*get_token_end(char *end)
{
	while (*end)
	{
		if (is_token_limiter(*end))
			break ;
		if (*end == '"')
		{
			end = ft_strchr(end + 1, '"');
			if (!end)
				return (NULL);
			end++;
		}
		if (*end == '\'')
		{
			end = ft_strchr(end + 1, '\'');
			if (!end)
				return (NULL);
			end++;
		}
		if (is_operator(end))
			return (end);
		end++;
	}
	return (end);
}

static t_token	*get_token(char **str)
{
	char	*str_end;
	int		len;

	len = is_operator(*str);
	if (len)
		return (create_token(TOKEN_OPERATOR, str, *str + len));
	len = is_redirection_operator(*str);
	if (len)
		return (create_token(TOKEN_WORD, str, *str + len));
	if (**str == '(' || **str == ')')
		return (create_token(TOKEN_GROUP, str, *str + 1));
	str_end = get_token_end(*str);
	if (!str_end)
		return (create_token(TOKEN_SYNTAX_ERROR, str, ft_strchr(*str, 0)));
	if (*str != str_end)
		return (create_token(TOKEN_WORD, str, str_end));
	return (create_token(TOKEN_END, str, *str));
}

t_token	*parse_token(char *str)
{
	t_token	*token_start;
	t_token	*token;

	str = ft_skip_charset(str, " \t");
	token_start = get_token(&str);
	if (!token_start)
		return (NULL);
	token = token_start;
	while (token->type != TOKEN_END && token->type != TOKEN_SYNTAX_ERROR)
	{
		str = ft_skip_charset(str, " \t");
		token->next = get_token(&str);
		if (!token->next)
			return (free_token(token_start), NULL);
		token = token->next;
	}
	return (token_start);
}
