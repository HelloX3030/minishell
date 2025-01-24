/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:08:21 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/12 11:54:19 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_x_helper(unsigned int n)
{
	int		len;
	ssize_t	result;

	len = 0;
	if (n < 16)
	{
		result = write(1, &"0123456789abcdef"[n], 1);
		if (result < 0)
			return (-1);
		else
			return (len + 1);
	}
	else
	{
		result = ft_print_x_helper(n / 16);
		if (result < 0)
			return (-1);
		else
			len += result;
		result = write(1, &"0123456789abcdef"[n % 16], 1);
		if (result < 0)
			return (-1);
		else
			return (len + result);
	}
}

int	ft_print_x(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_x_helper(n));
}
