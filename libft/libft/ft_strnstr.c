/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:32:21 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:46:35 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const size_t	needle_len = ft_strlen(needle);
	size_t			i;
	size_t			j;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			j++;
			if (j >= needle_len)
			{
				if (i + j > len)
					return (NULL);
				else
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*haystack = "Morgen Moin Moin";
// 	const char	*needle = "Moin";
// 	const char	*found = ft_strnstr(haystack, needle, 100);

// 	printf("%s, %s: %s\n", haystack, needle, found);
// 	return (0);
// }
