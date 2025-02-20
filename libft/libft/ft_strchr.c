/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:30:52 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/20 17:33:18 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	needle = (char)c;
	int			i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == needle)
			return ((char *)(&s[i]));
	}
	if (s[i] == needle)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_skip_charset(char *str, char *charset)
{
	while (*str && ft_strchr(charset, *str))
		str++;
	return (str);
}
