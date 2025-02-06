/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:30:43 by hello_x           #+#    #+#             */
/*   Updated: 2025/02/05 14:06:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*new_str;
	const int	s_len = ft_strlen(s);

	new_str = malloc(sizeof(char) * (s_len) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, s_len + 1);
	return (new_str);
}

char	*ft_strdupn(char *src, char *next)
{
	const int	dest_len = next - src;
	char		*dest;
	int			i;

	dest = malloc(dest_len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
