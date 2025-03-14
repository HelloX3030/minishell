/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_qutes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:01:11 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/14 12:49:59 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	get_len_quoted_part(const char quote_type, char **str, int *len)
{
	char	*next;

	next = ft_strchr(*str + 1, quote_type);
	if (!next)
	{
		*len += ft_strlen(*str);
		return (EXIT_FAILURE);
	}
	*len += next - *str - 1;
	*str = next;
	return (EXIT_SUCCESS);
}

/*
		it should actually never happen that ft_strchr(str + 1, '\''); or
		ft_strchr(str + 1, '"'); returns NULL, because the quotes are always
		closed, when not the tokenization would have failed
*/
static int	len_without_quotes(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			if (get_len_quoted_part('\'', &str, &len) == EXIT_FAILURE)
				return (len);
		}
		else if (*str == '\"')
		{
			if (get_len_quoted_part('\"', &str, &len) == EXIT_FAILURE)
				return (len);
		}
		else
			len++;
		str++;
	}
	return (len);
}

static void	copy_quote_part(char **new_pos, char **str_pos,
		const char quote_type)
{
	char	*next;

	next = ft_strchr(*str_pos + 1, quote_type);
	if (!next)
	{
		while (**str_pos)
			*(*new_pos)++ = *(*str_pos)++;
	}
	else
	{
		(*str_pos)++;
		while (*str_pos != next)
			*(*new_pos)++ = *(*str_pos)++;
		(*str_pos)++;
	}
}

int	remove_quotes(char **str)
{
	char	*new;
	char	*new_pos;
	char	*str_pos;

	if (!str || !*str)
		return (EXIT_SUCCESS);
	new = malloc(len_without_quotes(*str) + 1);
	if (!new)
		return (EXIT_FAILURE);
	new_pos = new;
	str_pos = *str;
	while (*str_pos)
	{
		if (*str_pos == '\'')
			copy_quote_part(&new_pos, &str_pos, '\'');
		else if (*str_pos == '\"')
			copy_quote_part(&new_pos, &str_pos, '\"');
		else
			*new_pos++ = *str_pos++;
	}
	*new_pos = 0;
	free(*str);
	*str = new;
	return (EXIT_SUCCESS);
}
