/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/13 16:38:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static char	*handle_dollar(char *str_pos, int len, t_env *env,
				t_quote_type quote_type);

static char	*handle_end(int len)
{
	char	*result;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	return (result);
}

static void	handle_quote(char c, t_quote_type *quote_type)
{
	if (c == '\"')
	{
		if (*quote_type == QUOTE_DOUBLE)
			*quote_type = QUOTE_NONE;
		else if (*quote_type == QUOTE_NONE)
			*quote_type = QUOTE_DOUBLE;
	}
	else if (c == '\'')
	{
		if (*quote_type == QUOTE_SINGLE)
			*quote_type = QUOTE_NONE;
		else if (*quote_type == QUOTE_NONE)
			*quote_type = QUOTE_SINGLE;
	}
}

static char	*handle_normal(char *str_pos, int len, t_env *env,
		t_quote_type quote_type)
{
	char	*result;
	int		i;

	i = 0;
	while (str_pos[i])
	{
		handle_quote(str_pos[i], &quote_type);
		if (str_pos[i] == '$' && quote_type != QUOTE_SINGLE)
		{
			result = handle_dollar(str_pos + i, len + i, env, quote_type);
			if (!result)
				return (NULL);
			ft_memcpy(result + len, str_pos, i);
			return (result);
		}
		i++;
	}
	result = handle_end(len + i);
	if (!result)
		return (NULL);
	ft_memcpy(result + len, str_pos, i);
	return (result);
}

// static char	*get_key_end(char *str)
// {
// 	if (ft_isdigit(*str))
// 		return (str + 1);
// 	while (ft_isalpha(*str) || *str == '_')
// 		str++;
// 	while (ft_isdigit(*str))
// 		str++;
// 	return (str);
// }

static char	*handle_dollar(char *str_pos, int len, t_env *env,
		t_quote_type quote_type)
{
	char	*result;

	// placeholder
	(void)env;
	str_pos++;
	if (*str_pos == '$')
		result = handle_dollar(str_pos, len + 1, env, quote_type);
	else if (*str_pos)
		result = handle_normal(str_pos, len + 1, env, quote_type);
	else
		result = handle_end(len + 1);
	if (!result)
		return (NULL);
	result[len] = '@';
	return (result);
}

int	expand_env(char **str, t_env *env)
{
	char	*result;

	if (!str || !*str)
		return (EXIT_SUCCESS);
	if (**str == '$')
		result = handle_dollar(*str, 0, env, QUOTE_NONE);
	else
		result = handle_normal(*str, 0, env, QUOTE_NONE);
	if (!result)
		return (EXIT_FAILURE);
	free(*str);
	*str = result;
	return (EXIT_SUCCESS);
}
