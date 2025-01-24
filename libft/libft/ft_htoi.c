/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:30 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 16:46:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_htoi(char *str)
{
	unsigned int	num;

	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strlen(str) >= 2 && *str == '0' && (*(str + 1) == 'x' || *(str
				+ 1) == 'X'))
		str += 2;
	while (*str && ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
			|| (*str >= 'A' && *str <= 'F')))
	{
		num *= 16;
		if (*str >= '0' && *str <= '9')
			num += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			num += *str - 'a' + 10;
		else
			num += *str - 'A' + 10;
		str++;
	}
	return (num);
}
