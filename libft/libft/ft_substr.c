/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:37:53 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:46:55 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const unsigned long	s_len = ft_strlen(s);
	char				*new_str;
	size_t				i;

	if (s == NULL || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (s_len <= start + len)
		new_str = malloc(sizeof(char) * (s_len - start + 1));
	else
		new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
