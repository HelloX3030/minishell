/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:26:29 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/12 17:29:27 by lseeger          ###   ########.fr       */
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

// static int	append_var(char **start, char **end, char **result, t_env *env)
// {
// 	char	*tmp;
// 	int		result_len;

// 	result_len = ft_strlen(*result);
// 	tmp = malloc(result_len + *end - *start + 1);
// 	if (!tmp)
// 		return (EXIT_FAILURE);
// 	ft_strlcpy(tmp, *result, result_len + 1);
// 	ft_strlcpy(tmp + result_len, *start, *end - *start + 1);
// 	tmp[result_len + *end - *start] = 0;
// 	free(*result);
// 	*result = tmp;
// 	*start = *end;
// 	(void)env;
// 	return (EXIT_SUCCESS);
// }

// static int	join_end(char *start, char *end, char **result)
// {
// 	char	*tmp;
// 	int		result_len;

// 	result_len = ft_strlen(*result);
// 	tmp = malloc(result_len + end - start + 1);
// 	if (!tmp)
// 		return (EXIT_FAILURE);
// 	ft_strlcpy(tmp, *result, result_len + 1);
// 	ft_strlcpy(tmp + result_len, start, end - start + 1);
// 	tmp[result_len + end - start] = 0;
// 	free(*result);
// 	*result = tmp;
// 	return (EXIT_SUCCESS);
// }

int	expand_env(char **str, t_env *env)
{
	// char	*start;
	// char	*end;
	// char	*result;
	// if (!str || !*str)
	// 	return (EXIT_SUCCESS);
	// start = *str;
	// end = *str;
	// result = ft_strdup("");
	// while (*end)
	// {
	// 	if (*end == '$')
	// 		if (append_var(&start, &end, &result, env) == EXIT_FAILURE)
	// 			return (free(result), EXIT_FAILURE);
	// 	end++;
	// }
	// if (join_end(start, end, &result) == EXIT_FAILURE)
	// 	return (free(result), EXIT_FAILURE);
	// free(*str);
	// *str = result;
	(void)str;
	(void)env;
	return (EXIT_SUCCESS);
}
