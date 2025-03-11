/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/11 18:06:14 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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

// static int	append_var(char **result, char *key, char *key_end, t_env *env)
// {
// 	// t_env	*tmp;
// 	// key_end = get_key_end(tmp + 1);
// 	// if (key_end != tmp + 1)
// 	// {
// 	// 	if (append_var(&result, tmp + 1, key_end, env) == EXIT_FAILURE)
// 	// 		return (EXIT_FAILURE);
// 	// 	tmp = key_end;
// 	// }
// 	// tmp = env;
// 	// while (tmp)
// 	// {
// 	// 	if (ft_strcmp(tmp->key, key) == 0)
// 	// 	{
// 	// 		*result = ft_strjoin(*result, tmp->value);
// 	// 		if (!*result)
// 	// 			return (EXIT_FAILURE);
// 	// 		return (EXIT_SUCCESS);
// 	// 	}
// 	// 	tmp = tmp->next;
// 	// }
// 	// return (EXIT_FAILURE);
// 	(void)result;
// 	(void)key;
// 	(void)key_end;
// 	(void)env;
// 	return (EXIT_SUCCESS);
// }

static int	join_str(char **start, char **end, char **result)
{
	char	*tmp;
	int		result_len;

	result_len = ft_strlen(*result);
	tmp = malloc(result_len + *end - *start + 1);
	if (!tmp)
		return (EXIT_FAILURE);
	ft_strlcpy(tmp, *result, result_len + 1);
	ft_strlcpy(tmp + result_len, *start, *end - *start + 1);
	tmp[result_len + *end - *start] = 0;
	free(*result);
	*result = tmp;
	*start = *end;
	return (EXIT_SUCCESS);
}

int	expand_env(char **str, t_env *env)
{
	char	*start;
	char	*end;
	char	*result;

	if (!str || !*str)
		return (EXIT_SUCCESS);
	start = *str;
	end = *str;
	result = ft_strdup("");
	while (*end)
	{
		if (*end == '$')
		{
			if (join_str(&start, &end, &result) == EXIT_FAILURE)
				return (free(result), EXIT_FAILURE);
			// if (append_var(&result, tmp + 1, get_key_end(tmp + 1),
			// 		env) == EXIT_FAILURE)
			// 	return (EXIT_FAILURE);
			(void)env;
		}
		end++;
	}
	// join end
	free(*str);
	*str = result;
	return (EXIT_SUCCESS);
}
