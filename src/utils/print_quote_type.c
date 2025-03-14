/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_quote_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:41:40 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/13 15:41:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_quote_type(t_quote_type type)
{
	if (type == QUOTE_NONE)
		printf("QUOTE_NONE\n");
	else if (type == QUOTE_SINGLE)
		printf("QUOTE_SINGLE\n");
	else if (type == QUOTE_DOUBLE)
		printf("QUOTE_DOUBLE\n");
	else
		printf("unknown quote type\n");
}
