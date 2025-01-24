/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:36:50 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/12 11:53:59 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_i_helper(int n)
{
	int		len;
	ssize_t	result;

	len = 0;
	if (n <= 9)
	{
		result = write(1, &"0123456789"[n], 1);
		if (result < 0)
			return (0);
		return (result);
	}
	else
	{
		result = ft_print_i_helper(n / 10);
		if (result < 0)
			return (-1);
		len += result;
		result = write(1, &"0123456789"[n % 10], 1);
		if (result < 0)
			return (-1);
		return (len + result);
	}
}

int	ft_print_i(va_list args)
{
	int	n;
	int	result;
	int	len;

	n = va_arg(args, int);
	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	len = 0;
	if (n < 0)
	{
		result = write(1, "-", 1);
		if (result < 0)
			return (-1);
		len += result;
		n *= -1;
	}
	result = ft_print_i_helper(n);
	if (result < 0)
		return (-1);
	return (len + result);
}
