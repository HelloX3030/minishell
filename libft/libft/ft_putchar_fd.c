/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:05:48 by hello_x           #+#    #+#             */
/*   Updated: 2025/04/08 15:16:31 by lseeger          ###   ########.fr       */
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

void	ft_write_insertion(int insertion)
{
	while (insertion--)
		write(STDOUT_FILENO, "\t", 1);
}
