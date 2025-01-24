/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:24:42 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:42:59 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr = (unsigned char *)s1;
	const unsigned char	*s2_ptr = (unsigned char *)s2;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return ((unsigned char)s1_ptr[i] - (unsigned char)s2_ptr[i]);
		i++;
	}
	return (0);
}
