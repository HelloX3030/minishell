/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:46:01 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/14 11:48:41 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	needle = (const char)c;
	char		*str;

	str = (char *)s;
	while (*str)
		str++;
	while (str >= s)
	{
		if (*str == needle)
			return (str);
		str--;
	}
	return (NULL);
}
