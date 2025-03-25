/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 15:06:17 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static char	*handle_dollar(char *str_pos, int len, t_minishell *ms,
				t_quote_type quote_type);
static char	*handle_wildcard(char *str_pos, int len, t_minishell *ms,
				t_quote_type quote_type);

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

static char	*handle_normal(char *str_pos, int len, t_minishell *ms,
		t_quote_type quote_type)
{
	char	*result;
	int		i;

	i = 0;
	while (str_pos[i])
	{
		handle_quote(str_pos[i], &quote_type);
		if ((str_pos[i] == '$' && quote_type != QUOTE_SINGLE)
			|| (str_pos[i] == '*' && quote_type == QUOTE_NONE))
			break ;
		i++;
	}
	if (!str_pos[i])
		result = ft_create_terminated_str(len + i);
	else if (str_pos[i] == '$' && quote_type != QUOTE_SINGLE)
		result = handle_dollar(str_pos + i, len + i, ms, quote_type);
	else
		result = handle_wildcard(str_pos + i, len + i, ms, quote_type);
	if (!result)
		return (NULL);
	ft_memcpy(result + len, str_pos, i);
	return (result);
}

static char	*handle_dollar(char *str_pos, int len, t_minishell *ms,
		t_quote_type quote_type)
{
	char	*result;
	char	*var_value;
	int		var_len;

	str_pos++;
	var_value = get_var_value(&str_pos, ms, quote_type);
	if (!var_value)
		return (NULL);
	var_len = ft_strlen(var_value);
	if (*str_pos == '$')
		result = handle_dollar(str_pos, len + var_len, ms, quote_type);
	else if (*str_pos == '*' && quote_type == QUOTE_NONE)
		result = handle_wildcard(str_pos, len + var_len, ms, quote_type);
	else if (*str_pos)
		result = handle_normal(str_pos, len + var_len, ms, quote_type);
	else
		result = ft_create_terminated_str(len + var_len);
	if (!result)
		return (NULL);
	ft_memcpy(result + len, var_value, var_len);
	free(var_value);
	return (result);
}

char	*handle_wildcard(char *str_pos, int len, t_minishell *ms,
		t_quote_type quote_type)
{
	char	*result;

	(void)ms;
	(void)quote_type;
	// placeholder for wildcard handling
	str_pos++;
	result = ft_create_terminated_str(len + 1);
	if (!result)
		return (NULL);
	result[len] = '@';
	return (result);
}

int	expand_env(char **str, t_minishell *ms)
{
	char	*result;

	if (!str || !*str)
		return (EXIT_SUCCESS);
	if (**str == '$')
		result = handle_dollar(*str, 0, ms, QUOTE_NONE);
	else if (**str == '*')
		result = handle_wildcard(*str, 0, ms, QUOTE_NONE);
	else
		result = handle_normal(*str, 0, ms, QUOTE_NONE);
	if (!result)
		return (EXIT_FAILURE);
	free(*str);
	*str = result;
	return (EXIT_SUCCESS);
}
