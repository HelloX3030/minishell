/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:47:45 by hello_x           #+#    #+#             */
/*   Updated: 2025/03/27 16:57:24 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const int	len1 = ft_strlen(s1);
	const int	len2 = ft_strlen(s2);
	char		*new_str;
	int			i;
	int			j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len2)
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	return (new_str);
}

int	ft_strjoin_inplace(char **s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(*s1, s2);
	if (!new_str)
		return (EXIT_FAILURE);
	free(*s1);
	*s1 = new_str;
	return (EXIT_SUCCESS);
}

void	ft_replace_char(char *str, char old, char new)
{
	while (*str)
	{
		if (*str == old)
			*str = new;
		str++;
	}
}

char	*ft_collapse_whitespace(const char *str)
{
	char	**split;
	char	*result;
	int		i;

	split = ft_split_charset(str, " \t");
	if (!split)
		return (NULL);
	if (!split[0])
		return (ft_free_strs(split), ft_strdup(""));
	result = ft_strdup(split[0]);
	if (!result)
		return (ft_free_strs(split), NULL);
	i = 1;
	while (split[i])
	{
		if (ft_strjoin_inplace(&result, " ") == EXIT_FAILURE)
			return (ft_free_strs(split), free(result), NULL);
		if (ft_strjoin_inplace(&result, split[i]) == EXIT_FAILURE)
			return (ft_free_strs(split), free(result), NULL);
		i++;
	}
	return (ft_free_strs(split), result);
}
