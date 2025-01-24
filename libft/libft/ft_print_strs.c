/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:33 by lseeger           #+#    #+#             */
/*   Updated: 2024/12/03 15:04:35 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_strs(char **str, int insertion)
{
	int			i;
	const int	start_insertion = insertion;

	i = 0;
	while (str[i])
	{
		while (insertion)
		{
			write(1, "\t", 1);
			insertion--;
		}
		write(1, "<", 1);
		write(1, str[i], ft_strlen(str[i]));
		write(1, ">\n", 2);
		i++;
		insertion = start_insertion;
	}
}
