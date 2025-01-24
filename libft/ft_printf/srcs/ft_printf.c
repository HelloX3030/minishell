/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:41:34 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/12 11:53:24 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_next_specifier(const char *s)
{
	char	*dif;

	dif = ft_strchr(s, '%');
	if (dif == NULL)
		return (ft_strlen(s));
	else
		return (dif - s);
}

int	print_specifier(const char *s, va_list args)
{
	if (s[1] == 'c')
		return (ft_print_c(args));
	else if (s[1] == 's')
		return (ft_print_s(args));
	else if (s[1] == 'p')
		return (ft_print_p(args));
	else if (s[1] == 'i' || s[1] == 'd')
		return (ft_print_i(args));
	else if (s[1] == 'u')
		return (ft_print_u(args));
	else if (s[1] == 'x')
		return (ft_print_x(args));
	else if (s[1] == 'X')
		return (ft_print_xx(args));
	else if (s[1] == '%')
		return (ft_print_per());
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		dif;
	int		result;

	va_start(args, s);
	len = 0;
	while (*s)
	{
		dif = get_next_specifier(s);
		result = print_l(s, dif);
		if (result < 0)
			return (va_end(args), -1);
		len += result;
		s += dif;
		if (*s == '%')
		{
			result = print_specifier(s, args);
			if (result < 0)
				return (va_end(args), -1);
			len += result;
			s += 2;
		}
	}
	return (va_end(args), len);
}
