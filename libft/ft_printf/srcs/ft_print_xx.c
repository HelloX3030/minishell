/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:13:54 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/12 11:54:26 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_xx_helper(unsigned int n)
{
	int		len;
	ssize_t	result;

	len = 0;
	if (n < 16)
	{
		result = write(1, &"0123456789ABCDEF"[n], 1);
		if (result < 0)
			return (-1);
		else
			return (len + result);
	}
	else
	{
		result = ft_print_xx_helper(n / 16);
		if (result < 0)
			return (-1);
		else
			len += result;
		result = write(1, &"0123456789ABCDEF"[n % 16], 1);
		if (result < 0)
			return (-1);
		else
			return (len + result);
	}
}

int	ft_print_xx(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_print_xx_helper(n));
}
