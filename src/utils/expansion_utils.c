/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/21 10:59:10 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get_var_end(char *str)
{
	if (ft_isdigit(*str))
		return (str + 1);
	while (ft_isalpha(*str) || *str == '_')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (str);
}

char	*create_terminated_str(int len)
{
	char	*result;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	return (result);
}

int match_pattern(char *pattern, char *filename)
{
	if (*pattern == '\0' && *filename == '\0')
		return (1);

	if (*pattern == '*')
	{
		while (*(pattern + 1) == '*')
			pattern++;	
		if (*(pattern + 1) == '\0')
			return (1);
		while (*filename != '\0')
		{
			if (match_pattern(pattern + 1, filename))
				return (1);
			filename++;
		}
		return (match_pattern(pattern + 1, filename));
	}
	if (*pattern == *filename || (*pattern == '?' && *filename != '\0'))
		return (match_pattern(pattern + 1, filename + 1));
	return (0);
}