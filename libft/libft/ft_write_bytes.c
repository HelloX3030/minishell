/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:22:39 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/16 16:45:43 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write_byte(char byte)
{
	int		i;
	char	num;

	i = 0;
	while (i < 8)
	{
		num = ((byte >> (7 - i)) & 1) + '0';
		write(1, &num, 1);
		i++;
	}
}

void	ft_write_bytes(char *bytes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_write_byte(bytes[i]);
		write(1, " ", 1);
		i++;
	}
}
