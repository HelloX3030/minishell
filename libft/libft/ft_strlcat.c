/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:47:10 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:45:49 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dest_len = ft_strlen(dst);
	const size_t	src_len = ft_strlen(src);
	size_t			i;
	size_t			j;

	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && (i + j) < (size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = 0;
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	const char		*src = "ABC";
// 	const size_t	dst_size = 20;
// 	char			*dst;

// 	dst = malloc(sizeof(char) * dst_size);
// 	ft_strlcpy(dst, "Moin", dst_size);
// 	printf("%s + %s: ", dst, src);
// 	ft_strlcat(dst, src, dst_size);
// 	printf("%s\n", dst);
// 	free(dst);
// 	return (0);
// }
