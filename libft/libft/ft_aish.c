/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:14:34 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/04 13:04:24 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_aish(char *str)
{
	if (!str)
		return (false);
	if (*str != '0')
		return (false);
	str++;
	if (*str != 'x' && *str != 'X')
		return (false);
	str++;
	while (*str)
	{
		if (!ft_in_charset(*str, "0123456789abcdefABCDEF"))
			return (false);
		str++;
	}
	return (true);
}
