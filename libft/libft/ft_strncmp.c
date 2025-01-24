/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:12:15 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/14 17:46:29 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>

// int	main(void)
// {
// 	char	*big;
// 	char	*little;

// 	big = "abcdef";
// 	little = "abcdefghijklmnop";
// 	ft_putnbr_fd(ft_strncmp(big, little, 6), 1);
// 	printf("\n");
// 	ft_putnbr_fd(strncmp(big, little, 6), 1);
// 	printf("\n");
// 	return (0);
// }
