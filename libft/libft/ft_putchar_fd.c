/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:05:48 by hello_x           #+#    #+#             */
/*   Updated: 2025/02/04 13:22:14 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}

char	*ft_get_insertion(int insertion)
{
	const int	count = insertion * INSERTION_SIZE;
	int			i;
	char		*str;

	str = malloc(count + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = 0;
	return (str);
}
