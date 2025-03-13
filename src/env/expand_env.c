/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/13 17:51:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
		if ((str_pos[i] == '$' && quote_type != QUOTE_SINGLE)
			|| (str_pos[i] == '*' && quote_type == QUOTE_NONE))
			break ;
		i++;
	}
	if (!str_pos[i])
		result = ft_create_terminated_str(len + i);
	else if (str_pos[i] == '$' && quote_type != QUOTE_SINGLE)
		result = handle_dollar(str_pos + i, len + i, env, quote_type);
	else if (str_pos[i] == '*' && quote_type == QUOTE_NONE)
		result = handle_wildcard(str_pos + i, len + i, env, quote_type);
	if (!result)
		return (NULL);
	ft_memcpy(result + len, str_pos, i);
	return (result);
}

static char	*get_var_value(char **str_pos, t_env *env)
{
	char	*var_end;
	char	*var_name;
	char	*var_value;

	var_end = get_var_end(*str_pos);
	var_name = ft_strndup(*str_pos, var_end);
	if (!var_name)
		return (NULL);
	var_value = get_env_value(env, var_name);
	if (!var_value)
	{
		var_value = ft_strdup("");
		if (!var_value)
			return (free(var_name), NULL);
	}
	free(var_name);
	*str_pos = var_end;
	return (var_value);
}

static char	*handle_dollar(char *str_pos, int len, t_env *env,
		t_quote_type quote_type)
{
	char	*result;
	char	*var_value;

	str_pos++;
	var_value = get_var_value(&str_pos, env);
	if (!var_value)
		return (NULL);
	if (*str_pos == '$')
		result = handle_dollar(str_pos, len + 1, env, quote_type);
	else if (*str_pos)
		result = handle_normal(str_pos, len + 1, env, quote_type);
	else
		result = ft_create_terminated_str(len + 1);
	if (!result)
		return (NULL);
	return (result);
}

int	expand_env(char **str, t_env *env)
{
	char	*result;

	if (!str || !*str)
		return (EXIT_SUCCESS);
	if (**str == '$')
		result = handle_dollar(*str, 0, env, QUOTE_NONE);
	else if (**str == '*')
		result = handle_wildcard(*str, 0, env, QUOTE_NONE);
	else
		result = handle_normal(*str, 0, env, QUOTE_NONE);
	if (!result)
		return (EXIT_FAILURE);
	free(*str);
	*str = result;
	return (EXIT_SUCCESS);
}
