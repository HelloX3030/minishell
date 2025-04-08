/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:29:52 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/08 15:22:25 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_token_type(t_token_type type)
{
	if (type == TOKEN_WORD)
		ft_putstr("TOKEN_WORD");
	else if (type == TOKEN_GROUP)
		ft_putstr("TOKEN_GROUP");
	else if (type == TOKEN_OPERATOR)
		ft_putstr("TOKEN_OPERATOR");
	else if (type == TOKEN_END)
		ft_putstr("TOKEN_END");
	else if (type == TOKEN_UNMATCHED_QUOTES)
		ft_putstr("TOKEN_UNMATCHED_QUOTES");
	else
		ft_putstr("UNKNOWN");
}
