/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_quote_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:41:40 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 12:52:10 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_quote_type(t_quote_type type)
{
	if (type == QUOTE_NONE)
		ft_putstr("QUOTE_NONE\n");
	else if (type == QUOTE_SINGLE)
		ft_putstr("QUOTE_SINGLE\n");
	else if (type == QUOTE_DOUBLE)
		ft_putstr("QUOTE_DOUBLE\n");
	else
		ft_putstr("UNKNOWN QUOTE TYPE\n");
}
