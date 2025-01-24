/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_charackter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:10:06 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/03 15:15:57 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_c(char *str, char *set)
{
	char	*src;
	char	*dst;

	if (!str || !set)
		return ;
	src = str;
	dst = str;
	while (*src)
	{
		if (!ft_in_charset(*src, set))
		{
			*dst = *src;
			dst++;
		}
		src++;
	}
	*dst = 0;
}
