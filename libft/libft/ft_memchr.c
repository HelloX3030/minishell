/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:38:24 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/14 18:07:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr = (unsigned char *)s;
	const unsigned char	c_test = (unsigned char)c;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == c_test)
			return ((void *)(&s_ptr[i]));
		i++;
	}
	return (NULL);
}
