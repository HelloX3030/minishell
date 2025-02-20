/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:57 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/20 18:29:14 by lseeger          ###   ########.fr       */
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

	len = is_operator(str);
	if (len)
		return (create_token(TOKEN_OPERATOR, *str, *str + len));
	len = is_redirection_operator(*str);
	if (len)
		return (create_token(TOKEN_WORD, *str, *str + len));
	if (*str == '(' || *str == ')')
		return (create_token(TOKEN_GROUP, *str, *str + 1));
	str_end = get_token_end(*str);
	if (str != str_end)
		return (create_token(TOKEN_WORD, *str, str_end));
	return (create_token(TOKEN_END, str, str));
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
	while (token->type != TOKEN_END)
	{
		str = ft_skip_charset(str, " \t");
		token->next = get_token(str);
		if (!token->next)
		{
			free_token(token_start);
			return (NULL);
		}
		token = token->next;
	}
	return (token_start);
}
