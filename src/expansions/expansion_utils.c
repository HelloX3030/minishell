/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/26 11:46:03 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char *get_var_end(char *str)
{
	if (ft_isdigit(*str))
		return (str + 1);
	while (ft_isalpha(*str) || *str == '_')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (str);
}

char *get_var_value(char **str_pos, t_minishell *ms,
					t_quote_type quote_type)
{
	char *var_end;
	char *var_name;
	char *var_value;

	(void)quote_type;
	if (**str_pos == '?')
		return ((*str_pos)++, ft_itoa(ms->status));
	var_end = get_var_end(*str_pos);
	if (var_end == *str_pos)
		return (ft_strdup("$"));
	var_name = ft_strndup(*str_pos, var_end);
	if (!var_name)
		return (NULL);
	var_value = get_env_value(ms->env, var_name);
	free(var_name);
	if (!var_value)
		return (ft_strdup(""));
	*str_pos = var_end;
	if (quote_type == QUOTE_DOUBLE)
		return (ft_strdup(var_value));
	return (ft_collapse_whitespace(var_value));
}
