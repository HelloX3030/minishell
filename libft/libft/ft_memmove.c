/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:42:45 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/14 17:43:16 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	forward_cpy(unsigned char *dst, const unsigned char *src,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	backward_cpy(unsigned char *dst, const unsigned char *src,
		size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		--i;
		dst[i] = src[i];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src || len <= 0)
		return (dst);
	if (dst > src)
		backward_cpy(dst, src, len);
	else
		forward_cpy(dst, src, len);
	return (dst);
}
