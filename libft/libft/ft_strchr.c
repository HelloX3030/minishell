/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:30:52 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/14 17:45:26 by lseeger          ###   ########.fr       */
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
