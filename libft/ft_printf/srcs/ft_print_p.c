/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:41:22 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/07 15:36:49 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_long_hex_helper(uintptr_t n)
{
	int		len;
	ssize_t	result;

	len = 0;
	if (n < 16)
	{
		result = write(1, &"0123456789abcdef"[n], 1);
		if (result < 0)
			return (-1);
		return (len + result);
	}
	else
	{
		result = ft_print_long_hex_helper(n / 16);
		if (result < 0)
			return (-1);
		len += result;
		result = write(1, &"0123456789abcdef"[n % 16], 1);
		if (result < 0)
			return (-1);
		return (len + result);
	}
}

static int	ft_print_long_hex(uintptr_t n)
{
	ssize_t	result;

	result = write(1, "0x", 2);
	if (result < 0)
		return (-1);
	return (ft_print_long_hex_helper(n) + result);
}

int	ft_print_p(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_print_long_hex((uintptr_t)ptr));
}
